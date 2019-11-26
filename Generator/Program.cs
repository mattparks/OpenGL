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
				Api = api,
				Number = max,
				Requires = new List<RegistryRequires>(),
				Removes = new List<RegistryRequires>()
			};
			foreach (var feature in registry.Features.Where(f => f.Api == api && f.Number >= min && f.Number <= max)) {
				combinedFeature.Requires.AddRange(feature.Requires);
				combinedFeature.Removes.AddRange(feature.Removes);
				// Use the last feature name as the combined name.
				combinedFeature.Name = feature.Name;
			}

			// TODO: This can be simplified:

			var enums = new List<RegistryRequires.Enum>();
			combinedFeature.Requires.ForEach(r => enums.AddRange(r.Enums));
			foreach (var @enum in enums) {
				RegistryEnums.Enum enumsEnum = null;
				registry.Enums.ForEach(e => e.Enums.ForEach(i => {
					if (i.Name == @enum.Name)
						enumsEnum = i;
				}));
				Console.WriteLine($"#define {@enum.Name} {enumsEnum?.Value}");
			}

			var commands = new List<RegistryRequires.Command>();
			combinedFeature.Requires.ForEach(r => commands.AddRange(r.Commands));
			foreach (var command in commands) {
				RegistryCommandsCommand commandsCommand = null;
				registry.Commands.ForEach(e => e.Command.ForEach(i => {
					// Command can only have one func proto.
					if (i.Prototype.Name == command.Name)
						commandsCommand = i;
				}));

				var commandProto = commandsCommand?.Prototype;
				if (commandProto != null) {
					var procName = $"PFN{commandProto.Name.ToUpper()}PROC";
					Console.Write($"typedef {commandProto.GlType()}(APIENTRYP {procName})(");
					Console.Write(string.Join(", ", commandsCommand.Params.Select(x =>
						$"{x.GlType()}{x.Name}")
					));
					Console.Write(");\n");
					Console.WriteLine($"GLAPI {procName} impl_{commandProto.Name};");
					Console.WriteLine($"#define {commandProto.Name} impl_{commandProto.Name};");
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
