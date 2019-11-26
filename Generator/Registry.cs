using System.Collections.Generic;
using System.Xml.Serialization;

namespace Generator {
	[XmlRoot("registry", Namespace = "", IsNullable = false)]
	public class Registry {
		[XmlArrayItem("type")]
		public List<RegistryType> Types { get; set; }

		[XmlArrayItem("group")]
		public List<RegistryGroup> Groups { get; set; }

		[XmlElement("enums")]
		public List<RegistryEnums> Enums { get; set; }

		[XmlElement("commands")]
		public List<RegistryCommands> Commands { get; set; }

		[XmlElement("feature")]
		public List<RegistryFeature> Features { get; set; }

		[XmlArrayItem("extension")]
		public List<RegistryExtension> Extensions { get; set; }

		[XmlAttribute("comment")]
		public string Comment { get; set; }
	}

	public class RegistryType {
		[XmlText]
		public List<string> Text { get; set; }

		[XmlElement("apientry")]
		public object ApiEntry { get; set; }

		[XmlAttribute("name")]
		public string Name { get; set; }

		[XmlAttribute("requires")]
		public string Requires { get; set; }
	}

	public class RegistryGroup {
		[XmlType(Namespace = "RegistryGroup")]
		public class Enum {
			[XmlAttribute("name")]
			public string Name { get; set; }
		}

		[XmlElement("enum")]
		public List<Enum> Enums { get; set; }

		[XmlAttribute("name")]
		public string Name { get; set; }
	}

	public class RegistryEnums {
		[XmlType(Namespace = "RegistryEnums")]
		public class Enum {
			[XmlAttribute("value")]
			public string Value { get; set; }

			[XmlAttribute("name")]
			public string Name { get; set; }

			[XmlAttribute("alias")]
			public string Alias { get; set; }

			[XmlAttribute("type")]
			public string Type { get; set; }

			[XmlAttribute("api")]
			public string Api { get; set; }
		}

		[XmlType(Namespace = "RegistryEnums")]
		public class Unused {
			[XmlAttribute("start")]
			public string Start { get; set; }

			[XmlAttribute("end")]
			public string End { get; set; }

			[XmlAttribute("vendor")]
			public string Vendor { get; set; }
		}

		[XmlElement("enum")]
		public List<Enum> Enums { get; set; }

		[XmlElement("unused")]
		public List<Unused> NotUsed { get; set; }

		[XmlAttribute("namespace")]
		public string Namespace { get; set; }

		[XmlAttribute("group")]
		public string Group { get; set; }

		[XmlAttribute("type")]
		public string Type { get; set; }

		[XmlAttribute("vendor")]
		public string Vendor { get; set; }

		[XmlAttribute("start")]
		public string Start { get; set; }

		[XmlAttribute("end")]
		public string End { get; set; }
	}

	public class RegistryCommands {
		[XmlElement("command")]
		public List<RegistryCommandsCommand> Command { get; set; }

		[XmlAttribute("namespace")]
		public string Namespace { get; set; }
	}

	public class RegistryCommandsCommand {
		public class Proto {
			[XmlText]
			public List<string> Text { get; set; }

			[XmlAttribute("group")]
			public string Group { get; set; }

			[XmlElement("ptype")]
			public string PointerType { get; set; }

			[XmlElement("name")]
			public string Name { get; set; }

			public string GlType() {
				return !string.IsNullOrEmpty(PointerType) ? PointerType + " " : Text[0];
			}
		}

		public class Param {
			[XmlText]
			public List<string> Text { get; set; }

			[XmlAttribute("group")]
			public string Group { get; set; }

			[XmlAttribute("len")]
			public string Length { get; set; }

			[XmlElement("ptype")]
			public string PointerType { get; set; }

			[XmlElement("name")]
			public string Name { get; set; }

			public string GlType() {
				return !string.IsNullOrEmpty(PointerType) ? PointerType + " " : Text[0];
			}
		}

		public class Glx {
			[XmlAttribute("type")]
			public string Type { get; set; }

			[XmlAttribute("opcode")]
			public ushort OpCode { get; set; }

			[XmlAttribute("name")]
			public string Name { get; set; }
		}

		public class Alias {
			[XmlAttribute("name")]
			public string Name { get; set; }
		}

		public class Vecequiv {
			[XmlAttribute("name")]
			public string Name { get; set; }
		}

		[XmlElement("proto")]
		public Proto Prototype { get; set; }

		[XmlElement("param")]
		public List<Param> Params { get; set; }

		[XmlElement("glx")]
		public List<Glx> Glxs { get; set; }

		[XmlElement("alias")]
		public List<Alias> Aliases { get; set; }

		[XmlElement("vecequiv")]
		public Vecequiv VectorEquiv { get; set; }
	}

	public class RegistryFeature {
		[XmlElement("require")]
		public List<RegistryRequires> Requires { get; set; }

		[XmlElement("remove")]
		public List<RegistryRequires> Removes { get; set; }

		[XmlAttribute("api")]
		public string Api { get; set; }

		[XmlAttribute("name")]
		public string Name { get; set; }

		[XmlAttribute("number")]
		public double Number { get; set; }
	}

	public class RegistryExtension {
		[XmlElement("require")]
		public List<RegistryRequires> Requires { get; set; }

		[XmlAttribute("name")]
		public string Name { get; set; }

		[XmlAttribute("supported")]
		public string Supported { get; set; }
	}

	public class RegistryRequires {
		[XmlType(Namespace = "RegistryRequires")]
		public class Enum {
			[XmlAttribute("name")]
			public string Name { get; set; }
		}

		[XmlType(Namespace = "RegistryRequires")]
		public class Command {
			[XmlAttribute("name")]
			public string Name { get; set; }
		}

		[XmlType(Namespace = "RegistryRequires")]
		public class Type {
			[XmlAttribute("name")]
			public string Name { get; set; }
		}

		[XmlElement("enum")]
		public List<Enum> Enums { get; set; }

		[XmlElement("command")]
		public List<Command> Commands { get; set; }

		[XmlElement("type")]
		public List<Type> Types { get; set; }

		[XmlAttribute("profile")]
		public string Profile { get; set; }

		[XmlAttribute("api")]
		public string Api { get; set; }
	}
}
