using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Xml.Serialization;

namespace Generator {
	[XmlRoot("registry", IsNullable = false)]
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

		[XmlElement("feature", IsNullable = false)]
		public RegistryFeatureKeyedCollection Features { get; set; }

		[XmlElement("extensions")]
		public List<RegistryExtensions> Extensions { get; set; }

#region Methods

		// Not the fastest data access methods, but it's clean and very expandable.
		
		public RegistryEnums.Enum Find(RegistryRequires.EnumName enumName) {
			return Enums.SelectMany(enums => enums.Enums).FirstOrDefault(@enum => @enum.Name == enumName.Name);
		}

		public RegistryGroups.Group Find(string groupName) {
			return Groups.SelectMany(groups => groups.Groups).FirstOrDefault(group => group.Name == groupName);
		}

		public RegistryCommands.Command Find(RegistryRequires.CommandName commandName) {
			return Commands.SelectMany(commands => commands.Commands).FirstOrDefault(command => command.Prototype.Name == commandName.Name);
		}

#endregion
	}

	public class RegistryTypes {
		public class Type {
			[XmlText]
			public List<string> Text { get; set; }

			[XmlElement("apientry")]
			public object ApiEntry { get; set; }

			[XmlAttribute("name")]
			public string Tag { get; set; }

			[XmlElement("name")]
			public string Name { get; set; }

			[XmlAttribute("requires")]
			public string Requires { get; set; }

			[XmlElement("comment")]
			public string Comment { get; set; }
		}

		[XmlElement("type")]
		public List<Type> Types { get; set; }
	}

	public class RegistryGroups {
		public class Group {
			[XmlElement("enum")]
			public List<RegistryRequires.EnumName> EnumNames { get; set; }

			[XmlAttribute("name")]
			public string Name { get; set; }

			[XmlElement("comment")]
			public string Comment { get; set; }
		}

		public class GroupKeyedCollection : KeyedCollection<string, Group> {
			protected override string GetKeyForItem(Group item) => item.Name;
		}

		[XmlElement("group", IsNullable = false)]
		public GroupKeyedCollection Groups { get; set; }
	}

	public class RegistryEnums {
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

			[XmlElement("comment")]
			public string Comment { get; set; }
		}

		public class EnumKeyedCollection : KeyedCollection<string, Enum> {
			protected override string GetKeyForItem(Enum item) => item.Name;
		}

		public class Unused {
			[XmlAttribute("start")]
			public string Start { get; set; }

			[XmlAttribute("end")]
			public string End { get; set; }

			[XmlAttribute("vendor")]
			public string Vendor { get; set; }

			[XmlElement("comment")]
			public string Comment { get; set; }
		}

		[XmlElement("enum", IsNullable = false)]
		public EnumKeyedCollection Enums { get; set; }

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

		[XmlElement("comment")]
		public string Comment { get; set; }
	}

	public class RegistryCommands {
		public class Command {
			public class Proto {
				[XmlText]
				public List<string> Text { get; set; }

				[XmlAttribute("group")]
				public string GroupName { get; set; }

				[XmlElement("ptype")]
				public string PointerType { get; set; }

				[XmlElement("name")]
				public string Name { get; set; }
			}

			public class Param {
				[XmlText]
				public List<string> Text { get; set; }

				[XmlAttribute("group")]
				public string GroupName { get; set; }

				[XmlAttribute("len")]
				public string Length { get; set; }

				[XmlElement("ptype")]
				public string PointerType { get; set; }

				[XmlElement("name")]
				public string Name { get; set; }
			}

			public class Glx {
				[XmlAttribute("type")]
				public string Type { get; set; }

				[XmlAttribute("opcode")]
				public ushort OpCode { get; set; }

				[XmlAttribute("name")]
				public string Name { get; set; }

				[XmlElement("comment")]
				public string Comment { get; set; }
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

			[XmlElement("comment")]
			public string Comment { get; set; }
		}

		public class CommandKeyedCollection : KeyedCollection<string, Command> {
			protected override string GetKeyForItem(Command item) => item.Prototype.Name;
		}

		[XmlElement("command", IsNullable = false)]
		public CommandKeyedCollection Commands { get; set; }

		[XmlAttribute("namespace")]
		public string Namespace { get; set; }
	}

	public class RegistryFeature {
		[XmlElement("require", IsNullable = false)]
		public List<RegistryRequires> Requires { get; set; }

		[XmlElement("remove", IsNullable = false)]
		public List<RegistryRequires> Removes { get; set; }

		[XmlAttribute("api")]
		public string Api { get; set; }

		[XmlAttribute("name")]
		public string Name { get; set; }

		[XmlAttribute("number")]
		public double Number { get; set; }
	}

	public class RegistryFeatureKeyedCollection : KeyedCollection<string, RegistryFeature> {
		protected override string GetKeyForItem(RegistryFeature item) => item.Name;
	}

	public class RegistryExtensions {
		public class Extension {
			[XmlElement("require")]
			public List<RegistryRequires> Requires { get; set; }

			[XmlAttribute("name")]
			public string Name { get; set; }

			[XmlAttribute("supported")]
			public string Supported { get; set; }

			[XmlElement("comment")]
			public string Comment { get; set; }
		}

		public class ExtensionKeyedCollection : KeyedCollection<string, Extension> {
			protected override string GetKeyForItem(Extension item) => item.Name;
		}

		[XmlElement("extension", IsNullable = false)]
		public ExtensionKeyedCollection Extensions { get; set; } 
	}

	public class RegistryRequires {
		public class EnumName {
			[XmlAttribute("name")]
			public string Name { get; set; }

			[XmlElement("comment")]
			public string Comment { get; set; }
		}

		public class CommandName {
			[XmlAttribute("name")]
			public string Name { get; set; }

			[XmlElement("comment")]
			public string Comment { get; set; }
		}

		public class TypeName {
			[XmlAttribute("name")]
			public string Name { get; set; }

			[XmlElement("comment")]
			public string Comment { get; set; }
		}

		[XmlElement("enum")]
		public List<EnumName> EnumNames { get; set; }

		[XmlElement("command")]
		public List<CommandName> CommandNames { get; set; }

		[XmlElement("type")]
		public List<TypeName> TypeNames { get; set; }

		[XmlAttribute("profile")]
		public string Profile { get; set; }

		[XmlAttribute("api")]
		public string Api { get; set; }

		[XmlElement("comment")]
		public string Comment { get; set; }
	}
}
