using System;
using System.IO;
using System.Linq;
using System.Net;
using System.Xml.Serialization;

namespace Generator {
	class FeatureSet {
		public RegistryEnums.EnumKeyedCollection Enums { get; set; } = new RegistryEnums.EnumKeyedCollection();
		public RegistryCommands.CommandKeyedCollection Commands { get; set; } = new RegistryCommands.CommandKeyedCollection();

		public void AppendFeature(Registry registry, RegistryFeature feature) {
			foreach (var enums in registry.Enums) {
				foreach (var @enum in enums.Enums) {
					if (feature.Requires.Any(r => r.EnumNames.Any(i => i.Name == @enum.Name))) {
						Enums.Add(@enum);
					}
				}
			}

			foreach (var commands in registry.Commands) {
				foreach (var command in commands.Commands) {
					if (feature.Requires.Any(r => r.CommandNames.Any(i => i.Name == command.Prototype.Name))) {
						Commands.Add(command);
					}
				}
			}
		}
	}

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
			var featureSet = new FeatureSet();
			foreach (var feature in registry.Features.Where(f => f.Api == api && f.Number >= min && f.Number <= max)) {
				featureSet.AppendFeature(registry, feature);
			}
			Process(featureSet);
		}

		static void Process(Registry registry, string api, double version) {
			var featureSet = new FeatureSet();
			var feature = registry.Features.Find(x => x.Api == api && x.Number == version);
			featureSet.AppendFeature(registry, feature);
			Process(featureSet);

		}

		static void Process(FeatureSet featureSet) {
			foreach (var @enum in featureSet.Enums) {
				Console.WriteLine($"#define {@enum.Name} {@enum.Value}");
			}
			foreach (var command in featureSet.Commands) {
				var procName = $"PFN{command.Prototype.Name.ToUpper()}PROC";
				var paramsString = string.Join(", ", command.Params.Select(param =>
					$"{param.GlType()} {param.Name}")
				);
				Console.WriteLine($"\ntypedef {command.Prototype.GlType()}(APIENTRYP {procName})({paramsString});");
				Console.WriteLine($"GLAPI {procName} impl_{command.Prototype.Name};");
				Console.WriteLine($"#define {command.Prototype.Name} impl_{command.Prototype.Name}");
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
