using System;
using System.IO;
using System.Linq;
using System.Net;
using System.Xml.Serialization;

namespace Generator {
	internal class Program {
		private static void Main(string[] args) {
			Download();

			Registry registry;
			using (var file = new FileStream("xml/gl.xml", FileMode.Open)) {
				var serializer = new XmlSerializer(typeof(Registry));
				registry = (Registry)serializer.Deserialize(file);
			}

			Process(registry, "gl", 1.0, 3.0);
			//Process(registry, "gles1", 1.0);
		}

		private static void Process(Registry registry, string api, double min, double max) {
			var enums = new RegistryEnums.EnumKeyedCollection();
			var commands = new RegistryCommands.CommandKeyedCollection();

			foreach (var feature in registry.Features.Where(f => f.Api == api && f.Number >= min && f.Number <= max)) {
				foreach (var enumName in feature.Requires.SelectMany(requires => requires.EnumNames)) {
					enums.Add(registry.Find(enumName));
				}
				foreach (var commandName in feature.Requires.SelectMany(requires => requires.CommandNames)) {
					commands.Add(registry.Find(commandName));
				}
			}

			Print(registry, enums, commands);
		}

		private static void Process(Registry registry, string api, double version) {
			var enums = new RegistryEnums.EnumKeyedCollection();
			var commands = new RegistryCommands.CommandKeyedCollection();

			var feature = registry.Features.Find(x => x.Api == api && x.Number == version);
			foreach (var enumName in feature.Requires.SelectMany(requires => requires.EnumNames)) {
				enums.Add(registry.Find(enumName));
			}
			foreach (var commandName in feature.Requires.SelectMany(requires => requires.CommandNames)) {
				commands.Add(registry.Find(commandName));
			}

			Print(registry, enums, commands);
		}

		private static void Print(Registry registry, RegistryEnums.EnumKeyedCollection enums, RegistryCommands.CommandKeyedCollection commands) {
			foreach (var @enum in enums) {
				Console.WriteLine($"#define {@enum.Name} {@enum.Value}");
			}
			foreach (var command in commands) {
				var procName = $"PFN{command.Prototype.Name.ToUpper()}PROC";
				var paramsString = string.Join(", ", command.Params.Select(param =>
					$"{GlType(param)} {param.Name}")
				);
				Console.WriteLine($"\ntypedef {GlType(command.Prototype)}(APIENTRYP {procName})({paramsString});");
				Console.WriteLine($"GLAPI {procName} impl_{command.Prototype.Name};");
				Console.WriteLine($"#define {command.Prototype.Name} impl_{command.Prototype.Name}");
			}
		}

		private static string GlType(RegistryCommands.Command.Proto proto) {
			return !string.IsNullOrEmpty(proto.PointerType) ? proto.PointerType : proto.Text[0];
		}

		private static string GlType(RegistryCommands.Command.Param param) {
			return !string.IsNullOrEmpty(param.PointerType) ? param.PointerType : param.Text[0];
		}

		private static void Download() {
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
