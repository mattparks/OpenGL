using System.Collections.Generic;
using System.Xml.Serialization;

namespace Generator {
	[XmlRoot("registry", Namespace = "", IsNullable = false)]
	public class Registry {
		[XmlElement("comment")]
		public string Comment { get; set; }

		[XmlElement("types")]
		public List<RegistryTypes> Types { get; set; }

		[XmlElement("groups")]
		public List<RegistryGroups> Groups { get; set; }

		[XmlElement("enums")]
		public List<RegistryEnums> Enums { get; set; }

		[XmlElement("commands")]
		public List<RegistryCommands> Commands { get; set; }

		[XmlElement("feature")]
		public List<RegistryFeature> Features { get; set; }

		[XmlElement("extensions")]
		public List<RegistryExtensions> Extensions { get; set; }
	}

	public class RegistryTypes {
		[XmlType(Namespace = "RegistryTypes")]
		public class Type {
			[XmlText]
			public List<string> Text { get; set; }

			[XmlElement("apientry")]
			public object ApiEntry { get; set; }

			[XmlAttribute("name")]
			public string Name { get; set; }

			[XmlAttribute("requires")]
			public string Requires { get; set; }
		}

		[XmlElement("type")]
		public List<Type> Types { get; set; }
	}

	public class RegistryGroups {
		[XmlType(Namespace = "RegistryGroups")]
		public class Group {
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

		[XmlElement("group")]
		public List<Group> Groups { get; set; }
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
		public class Command {
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

		[XmlElement("command")]
		public List<Command> Commands { get; set; }

		[XmlAttribute("namespace")]
		public string Namespace { get; set; }
	}

	public class RegistryFeature {
		[XmlElement("require")]
		public List<RegistryRequires> Requires { get; set; } = new List<RegistryRequires>();

		[XmlElement("remove")]
		public List<RegistryRequires> Removes { get; set; } = new List<RegistryRequires>();

		[XmlAttribute("api")]
		public string Api { get; set; }

		[XmlAttribute("name")]
		public string Name { get; set; }

		[XmlAttribute("number")]
		public double Number { get; set; }
	}

	public class RegistryExtensions {
		public class Extension {
			[XmlElement("require")]
			public List<RegistryRequires> Requires { get; set; }

			[XmlAttribute("name")]
			public string Name { get; set; }

			[XmlAttribute("supported")]
			public string Supported { get; set; }
		}

		[XmlElement("extension")]
		public List<Extension> Extensions { get; set; }
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
