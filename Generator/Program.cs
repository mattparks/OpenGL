using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Text.RegularExpressions;
using System.Xml.Serialization;

namespace Generator {
	internal class Program {
		private class Api {
			public readonly string Name;
			public readonly double Version;

			public Api(string name, double version) {
				Name = name;
				Version = version;
			}
		}

		private static void Main(string[] args) {
			Download();

			Registry glRegistry;
			using (var file = new StreamReader("xml/gl.xml")) {
				var serializer = new XmlSerializer(typeof(Registry));
				glRegistry = (Registry)serializer.Deserialize(file);
			}
			Process(glRegistry, "gl", "OpenGL", new List<Api> {
				new Api("gl", 3.0)
			});
			Process(glRegistry, "gles", "OpenGLES", new List<Api> {
				new Api("gles1", 1.0),
				new Api("gles2", 2.0)
			});
		}

		private static void Process(Registry registry, string shortname, string outName, IReadOnlyCollection<Api> apis) {
			var strings = new Dictionary<string, string> {
				{ "GENERATOR", $"{outName} loader generated tool at {DateTime.UtcNow:yyyy-MM-ddTHH:mm:ss.fffffffZ}" },
				{ "LICENSE", registry.Comment },
				{ "HEADER_FILE", $"{shortname.ToUpper()}/{outName}.h" },
				{ "SOURCE_FILE", $"{outName}.cpp" }
			};

			string typeDefs = "";
			foreach (var type in registry.Types.SelectMany(types => types.Types)) {
				if (type.Text.Count == 1) {
					// Struct declarations.
					typeDefs += $"{type.Name}{type.Text[0]}\n";
				} else if (type.Text.Count == 2) {
					// Typedef types.
					typeDefs += $"{type.Text[0]}{type.Name}{type.Text[1]}\n";
				} else if (type.Text.Count == 3) {
					// Typedef functions.
					var apiEntry = type.ApiEntry != null ? "GL_APIENTRY" : "";
					typeDefs += $"{type.Text[0]}{apiEntry}{type.Text[1]}{type.Name}{type.Text[2]}\n";
				} else {
					throw new ArgumentException();
				}
			}
			strings.Add("GL_TYPEDEFS", typeDefs);

			string commandsAndEnums = "";
			string commandsPFN = "";
			var usedSymbols = new List<string>();
			var addFromRequires = new Action<string, List<RegistryRequires>>((parentName, parentRequires) => {
				commandsAndEnums += $"#ifndef {parentName}\n#define {parentName} 1\n";

				foreach (var enumName in parentRequires.SelectMany(rs => rs.EnumNames.Where(r => !usedSymbols.Contains(r.Name)))) {
					var @enum = registry.Find(enumName);
					commandsAndEnums += $"constexpr GLenum {@enum.Name} = {@enum.Value};\n";

					usedSymbols.Add(enumName.Name);
				}

				foreach (var commandName in parentRequires.SelectMany(rs => rs.CommandNames.Where(c => !usedSymbols.Contains(c.Name)))) {
					var command = registry.Find(commandName);
					var name = command.Prototype.Name;
					//var nameGL = name.StartsWith("gl") ? name.Substring(2) : name;
					var returnType = GlType(command.Prototype);
					var paramsString = string.Join(", ", command.Params.Select(param =>
						$"{GlType(param)} {param.Name}")
					);
					commandsAndEnums += $"{returnType} {name}({paramsString});\n";

					var paramTypes = string.Join(", ", command.Params.Select(GlType));
					var paramNames = string.Join(", ", command.Params.Select(param => param.Name));
					commandsPFN += $"{returnType} {name}({paramsString}) {{\n";
					commandsPFN += $"\tstatic const auto {name}_ = reinterpret_cast<{returnType}(GL_APIENTRYP)({paramTypes})>(getProcAddress(\"{name}\"));\n";
					commandsPFN += $"\tassert({name}_ != nullptr);\n";
					commandsPFN += $"\treturn {name}_({paramNames});\n}}\n";

					usedSymbols.Add(commandName.Name);
				}

				commandsAndEnums += $"#endif /* {parentName} */\n";
			});

			foreach (var feature in registry.Features.Where(f => apis.Any(api => f.Api == api.Name && f.Number <= api.Version))) {
				addFromRequires(feature.Name, feature.Requires);
			}
			var allowedExtensions = new Regex("GL_(ARB|EXT|OES)\\w*");
			foreach (var extension in registry.Extensions.SelectMany(es => es.Extensions.Where(e => allowedExtensions.IsMatch(e.Name) && 
				apis.Select(a => a.Name).Intersect(e.Supported.Split('|')).Any()))) {
				addFromRequires(extension.Name, extension.Requires);
			}
			strings.Add("GL_ENUMS_COMMANDS", commandsAndEnums);
			strings.Add("GL_COMMANDS_PFN", commandsPFN);

			Directory.CreateDirectory("../../../Out/include/" + shortname.ToUpper());
			Directory.CreateDirectory("../../../Out/src");
			Output($"../../Files/{shortname}.h.in", $"../../../Out/include/{strings["HEADER_FILE"]}", strings);
			Output($"../../Files/{shortname}.cpp.in", $"../../../Out/src/{strings["SOURCE_FILE"]}", strings);
		}

		private static void Output(string inPath, string outPath, IReadOnlyDictionary<string, string> strings) {
			var input = new StreamReader(inPath);
			
			using (var output = new StreamWriter(outPath)) {
				string line;
				while ((line = input.ReadLine()) != null) {
					output.WriteLine(Regex.Replace(line, @"\$\{(.*?)\}",
						match => strings.TryGetValue(match.Groups[1].Value, out string value) ? value : match.Value
					));
				}
			}
		}

		private static string GlType(RegistryCommands.Command.Proto proto) {
			var type = string.Join("", proto.Text).Trim();
			if (!string.IsNullOrEmpty(proto.PointerType))
				type = type.Insert(0, proto.PointerType.Trim() + (type.Length == 0 ? "" : " "));
			return type;
		}

		private static string GlType(RegistryCommands.Command.Param param) {
			var type = string.Join("", param.Text).Trim();
			if (!string.IsNullOrEmpty(param.PointerType))
				type = type.Insert(0, param.PointerType.Trim() + (type.Length == 0 ? "" : " "));
			return type;
		}

		private static void Download() {
            using (var client = new WebClient()) { 
                Directory.CreateDirectory("xml");
                if (!File.Exists("xml/egl.xml"))
                    client.DownloadFile("https://raw.githubusercontent.com/KhronosGroup/EGL-Registry/master/api/egl.xml", "xml/egl.xml");
                if (!File.Exists("xml/gl.xml"))
                    client.DownloadFile("https://raw.githubusercontent.com/KhronosGroup/OpenGL-Registry/master/xml/gl.xml", "xml/gl.xml");
                if (!File.Exists("xml/glx.xml"))
                    client.DownloadFile("https://raw.githubusercontent.com/KhronosGroup/OpenGL-Registry/master/xml/glx.xml", "xml/glx.xml");
                if (!File.Exists("xml/wgl.xml"))
                    client.DownloadFile("https://raw.githubusercontent.com/KhronosGroup/OpenGL-Registry/master/xml/wgl.xml", "xml/wgl.xml");

                Directory.CreateDirectory("include/KHR");
                if (!File.Exists("include/KHR/khrplatform.h"))
                    client.DownloadFile("https://raw.githubusercontent.com/KhronosGroup/EGL-Registry/master/api/KHR/khrplatform.h", "include/KHR/khrplatform.h");
            }
        }
	}

}
