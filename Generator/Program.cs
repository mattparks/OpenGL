using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Xml.Serialization;

namespace Generator {
	class Program {
		static void Main(string[] args) {
			Download();

			Registry registry;
			using (var file = new FileStream("xml/gl.xml", FileMode.Open)) {
				var serializer = new XmlSerializer(typeof(Registry));
				registry = (Registry)serializer.Deserialize(file);
			}

			Process(registry, "gl", 1.0, 3.0);
		}

		static void Process(Registry registry, string api, double min, double max) {
			var featureSet = new RegistryFeature { Api = api, Number = max };
			foreach (var feature in registry.Features.Where(f => f.Api == api && f.Number >= min && f.Number <= max)) {
				featureSet.Requires.AddRange(feature.Requires);
				featureSet.Removes.AddRange(feature.Removes);
				// Use the last feature name as the combined name.
				featureSet.Name = feature.Name;
			}

			foreach (var groups in registry.Groups) {
				foreach (var group in groups.Groups) {
					Console.WriteLine($"enum {group.Name} {{");

					foreach (var @enum in group.Enums) {
						Console.WriteLine($"\t{@enum.Name},");
					}

					Console.WriteLine($"}}");
				}
			}

			foreach (var enums in registry.Enums) {
				foreach (var @enum in enums.Enums) {
					if (featureSet.Requires.Any(r => r.Enums.Any(i => i.Name == @enum.Name))) {
						Console.WriteLine($"#define {@enum.Name} {@enum.Value}");
						if (!string.IsNullOrEmpty(@enum.Alias))
							Console.WriteLine($"#define {@enum.Alias} {@enum.Name}");
					}
				}
			}

			foreach (var commands in registry.Commands) {
				foreach (var command in commands.Commands) {
					if (featureSet.Requires.Any(r => r.Commands.Any(i => i.Name == command.Prototype.Name))) {
						var procName = $"PFN{command.Prototype.Name.ToUpper()}PROC";
						Console.Write($"typedef {command.Prototype.GlType()}(APIENTRYP {procName})(");
						Console.Write(string.Join(", ", command.Params.Select(x =>
							$"{x.GlType()}{x.Name}")
						));
						Console.Write(");\n");
						Console.WriteLine($"GLAPI {procName} impl_{command.Prototype.Name};");
						Console.WriteLine($"#define {command.Prototype.Name} impl_{command.Prototype.Name}");
					}
				}
			}
		}

		static void Download() {
			using var client = new WebClient();

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
