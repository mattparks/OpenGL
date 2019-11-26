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
			var combinedFeature = new RegistryFeature {
				api = api,
				number = max,
				require = new List<RegistryFeatureRequire>(),
				remove = new List<RegistryFeatureRemove>()
			};
			foreach (var feature in registry.feature.Where(f => f.api == api && f.number >= min && f.number <= max)) {
				combinedFeature.require.AddRange(feature.require);
				combinedFeature.remove.AddRange(feature.remove);
				// Use the last feature name as the combined name.
				combinedFeature.name = feature.name;
			}

			// TODO: This can be simplified:

			var enums = new List<object>();
			combinedFeature.require.ForEach(r => enums.AddRange(r.items.FindAll(i => i is RegistryFeatureRequireEnum)));
			foreach (RegistryFeatureRequireEnum @enum in enums) {
				RegistryEnumsEnum enumsEnum = null;
				registry.enums.ForEach(e => e.items.OfType<RegistryEnumsEnum>().ForEach(i => {
					if (i.name == @enum.name)
						enumsEnum = i;
				}));
				Console.WriteLine($"#define {@enum.name} {enumsEnum?.value}");
			}

			var commands = new List<object>();
			combinedFeature.require.ForEach(r => commands.AddRange(r.items.FindAll(i => i is RegistryFeatureRequireCommand)));
			foreach (RegistryFeatureRequireCommand command in commands) {
				RegistryCommandsCommand commandsCommand = null;
				registry.commands.ForEach(e => e.command.ForEach(i => {
					// Command can only have one func proto.
					if (i.items.OfType<RegistryCommandsCommandProto>().FirstOrDefault()?.name == command.name)
						commandsCommand = i;
				}));
				var commandProto = commandsCommand.items.OfType<RegistryCommandsCommandProto>().FirstOrDefault();
				if (commandProto == null) 
					continue;

				var procName = $"PFN{commandProto.name.ToUpper()}PROC";
				Console.Write($"typedef {commandProto.GLType()}(APIENTRYP {procName})(");
				Console.Write(string.Join(", ", commandsCommand.items.OfType<RegistryCommandsCommandParam>().Select(x => 
					$"{x.GLType()}{x.name}")
				));
				Console.Write(");\n");
				Console.WriteLine($"GLAPI {procName} impl_{commandProto.name};");
				Console.WriteLine($"#define {commandProto.name} impl_{commandProto.name};");
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
