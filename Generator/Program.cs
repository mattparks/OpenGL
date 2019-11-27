﻿using System;
using System.Collections.Generic;
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

			Process(registry, "gl", 1.0, 4.6);
			//Process(registry, "gles1", 1.0);
		}

		private static void Process(Registry registry, string api, double min, double max) {
			var strings = new Dictionary<string, string> {
				{ "LOWERNAME", "opengl" },
				{ "GENERATOR", $"// OpenGL loader generated by Matthew A's tool at {DateTime.UtcNow:yyyy-MM-ddTHH:mm:ss.fffffffZ}" },
				{ "LICENCE", $"/*\n{registry.Comment}\n*/" },
				{ "HEADER_BODY", "" }
			};

			foreach (var feature in registry.Features.Where(f => f.Api == api && f.Number >= min && f.Number <= max)) {
				//string section = $"#ifndef {feature.Name}\n#define {feature.Name} 1";
				string section = $"#ifdef {feature.Name}\n";
				foreach (var enumName in feature.Requires.SelectMany(requires => requires.EnumNames)) {
					var @enum = registry.Find(enumName);
					section += $"#define {@enum.Name} {@enum.Value}\n";
				}

				section += "\n";
				foreach (var commandName in feature.Requires.SelectMany(requires => requires.CommandNames)) {
					var command = registry.Find(commandName);
					var procName = $"PFN{command.Prototype.Name.ToUpper()}PROC";
					var paramsString = string.Join(", ", command.Params.Select(param =>
						$"{GlType(param)} {param.Name}")
					);
					section += $"typedef {GlType(command.Prototype)}(APIENTRYP {procName})({paramsString});\n";
					section += $"GLAPI {procName} impl_{command.Prototype.Name};\n";
					section += $"#define {command.Prototype.Name} impl_{command.Prototype.Name}\n";
				}

				section += $"#endif /* {feature.Name} */\n\n";
				strings["HEADER_BODY"] += section;
			}

			Output("../../../header.template", "OpenGL.h", strings);
			Output("../../../source.template", "OpenGL.cpp", strings);
		}

		private static void Output(string inPath, string outPath, IReadOnlyDictionary<string, string> strings) {
			using var input = new StreamReader(inPath);
			using var output = new StreamWriter(outPath);
			
			string line;
			while ((line = input.ReadLine()?.Trim()) != null) {
				var splitLine = line.Split("%%");
				if (line.Split("%%").Length - 1 == 2) {
					// Write what came before the first token
					output.Write(splitLine[0]);
					// Write the replacement to the tokens and the key.
					if (strings.ContainsKey(splitLine[1])) {
						output.Write(strings[splitLine[1]]);
					} else {
						// If we don't have a replacement we write the key back into the file.
						output.Write(splitLine[1]);
						Console.WriteLine($"Invalid generator key: {splitLine[1]}");
					}
					// Write what came after the token.
					output.WriteLine(splitLine[2]);
				} else {
					output.WriteLine(line);
				}
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
