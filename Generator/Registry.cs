using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Xml.Serialization;

// A Xml structure that represents The Khronos XML API Registry (2014/06/16):
// https://github.com/KhronosGroup/OpenGL-Registry/blob/master/xml/readme.pdf

// C#-ified the API Registry docs as best as I could and added links to C# classes.

namespace Generator {
	/// <summary>
	/// Contains the entire definition of one or more related APIs.
	/// </summary>
	[XmlRoot("registry", IsNullable = false)]
	public class Registry {
		/// <summary>
		/// Contains arbitrary text, such as a copyright statement.
		/// </summary>
		[XmlElement("comment")]
		public string Comment { get; set; }

		/// <summary>
		/// Defines API types. Usually only one tag is used.
		/// </summary>
		[XmlElement("types")]
		public List<RegistryTypes> Types { get; set; }

		/// <summary>
		/// Defines named groups of tokens for possible parameter validation in API bindings
		/// for languages other than C. Usually only one tag is used.
		/// </summary>
		[XmlElement("groups")]
		public List<RegistryGroups> Groups { get; set; }

		/// <summary>
		/// Defines API enumerants (tokens). Usually multiple tags are used.
		/// </summary>
		[XmlElement("enums")]
		public List<RegistryEnums> Enums { get; set; }

		/// <summary>
		/// Defines API commands (functions). Usually only one tag is used.
		/// </summary>
		[XmlElement("commands")]
		public List<RegistryCommands> Commands { get; set; }

		/// <summary>
		/// Defines API feature interfaces(API versions, more or less). One tag per feature set.
		/// </summary>
		[XmlElement("feature", IsNullable = false)]
		public RegistryFeatureKeyedCollection Features { get; set; }

		/// <summary>
		/// Defines API extension interfaces.Usually only one tag is used, wrapping many extensions.
		/// </summary>
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

	/// <summary>
	/// Contains individual type tags describing each of the derived types used in the API.
	/// Contains legal C code, with attributes or embedded tags denoting the type name.
	/// </summary>
	public class RegistryTypes {
		public class Type {
			/// <summary>
			/// Another type name this type requires to complete its definition.
			/// </summary>
			[XmlAttribute("requires")]
			public string Requires { get; set; }

			/// <summary>
			/// Name of this type (if not defined in the tag body).
			/// </summary>
			[XmlAttribute("name")]
			public string Name1 { get; set; }

			/// <summary>
			/// An API name (feature) which specializes this definition of the named type,
			/// so that the same API types may have different definitions for e.g. GL ES and GL.
			/// </summary>
			[XmlAttribute("api")]
			public string Api { get; set; }

			/// <summary>
			/// Arbitrary string (unused).
			/// </summary>
			[XmlAttribute("comment")]
			public string Comment { get; set; }

			/// <summary>
			/// Contains text which is legal C code for a type declaration.
			/// </summary>
			[XmlText]
			public List<string> Text { get; set; }

			/// <summary>
			/// Insert a platform calling convention macro here during header generation, used mostly for function pointer types.
			/// </summary>
			[XmlElement("apientry")]
			public object ApiEntry { get; set; }

			/// <summary>
			/// Contains the name of this type (if not defined in the tag attributes).
			/// </summary>
			[XmlElement("name")]
			public string Name { get; set; }
		}

		[XmlElement("type")]
		public List<Type> Types { get; set; }
	}

	/// <summary>
	/// Contains individual groups describing some of the group annotations used for return and parameter types.
	/// 
	/// <br/>
	/// 
	/// If a <see cref="RegistryCommands.Command.Proto"/> or <see cref="RegistryCommands.Command.Param"/> has a
	/// group attribute defined, and that attribute matches a group name, then the return type or
	/// parameter type is considered to be constrained to values defined by the corresponding group.
	/// C language bindings do not attempt to enforce this constraint in any way, but other language bindings may try to do so.
	/// </summary>
	public class RegistryGroups {
		/// <summary>
		/// Defines a single group annotation.
		/// </summary>
		public class Group {
			/// <summary>
			/// Group name, an arbitrary string for grouping a set
			/// of enums together within a broader namespace.
			/// </summary>
			[XmlAttribute("name")]
			public string Name { get; set; }

			/// <summary>
			/// May contain zero or more enums. 
			/// </summary>
			[XmlElement("enum")]
			public List<RegistryRequires.EnumName> EnumNames { get; set; }
		}

		public class GroupKeyedCollection : KeyedCollection<string, Group> {
			protected override string GetKeyForItem(Group item) => item.Name;
		}

		[XmlElement("group", IsNullable = false)]
		public GroupKeyedCollection Groups { get; set; }
	}

	/// <summary>
	/// Contain individuals enums describing each of the token (enumerant) names used in the API.
	/// </summary>
	public class RegistryEnums {
		/// <summary>
		/// Defines a single GL (or other API) token.
		/// </summary>
		public class Enum {
			/// <summary>
			/// Enumerant value, a legal C constant (usually a hexadecimal integer).
			/// </summary>
			[XmlAttribute("value")]
			public string Value { get; set; }

			/// <summary>
			/// Enumerant name, a legal C preprocessor token name.
			/// </summary>
			[XmlAttribute("name")]
			public string Name { get; set; }

			/// <summary>
			/// An API name which specializes this definition of the
			/// named enum, so that different APIs may have different values for
			/// the same token (used to address a few accidental incompatibilities
			/// between GL and GL ES).
			/// </summary>
			[XmlAttribute("api")]
			public string Api { get; set; }

			/// <summary>
			/// Legal C suffix for the value to force it to a
			/// specific type. Currently only <c>u</c> and <c>ull</c> are used,
			/// for <c>unsigned</c> 32- and 64-bit integer values, respectively.
			/// Separated from the <c>value</c> field since this eases parsing and
			/// sorting of values, and is rarely used.
			/// </summary>
			[XmlAttribute("type")]
			public string Type { get; set; }

			/// <summary>
			/// Name of another enumerant this is an alias of, used
			/// where token names have been changed as a result of profile changes
			/// or for consistency purposes. An enumerant alias is simply a
			/// different <see cref="Name"/> for the exact same <see cref="Value"/>. At present,
			/// enumerants which are promoted from extension to core API status
			/// are not tagged as aliases.
			/// </summary>
			[XmlAttribute("alias")]
			public string Alias { get; set; }
		}

		public class EnumKeyedCollection : KeyedCollection<string, Enum> {
			protected override string GetKeyForItem(Enum item) => item.Name;
		}

		/// <summary>
		/// Defines a range of enumerants which is allocated, but not yet assigned to specific enums.
		/// This just tracks the unused values and is not needed for header generation.
		/// </summary>
		public class Unused {
			/// <summary>
			/// Integer defining the start of an unused range of enumerants.
			/// This range should not exceed the range reserved by the surrounding <see cref="Enums"/> tag.
			/// </summary>
			[XmlAttribute("start")]
			public string Start { get; set; }

			/// <summary>
			/// Integer defining the end of an unused range of enumerants.
			/// This range should not exceed the range reserved by the surrounding <see cref="Enums"/> tag.
			/// </summary>
			[XmlAttribute("end")]
			public string End { get; set; }

			/// <summary>
			/// String describing the vendor or purposes to whom a
			/// reserved range of enumerants is allocated. Usually identical to
			/// the <c>vendor</c> attribute of the surrounding <see cref="Enums"/> block.
			/// </summary>
			[XmlAttribute("vendor")]
			public string Vendor { get; set; }

			/// <summary>
			/// Arbitrary string (unused).
			/// </summary>
			[XmlElement("comment")]
			public string Comment { get; set; }
		}

		/// <summary>
		/// A string for grouping many different enums together, currently unused but typically
		/// something like <c>GL</c> for all enums in the OpenGL / OpenGL ES shared namespace.
		/// Multiple <see cref="Enums"/> can share the same namespace.
		/// </summary>
		[XmlAttribute("namespace")]
		public string Namespace { get; set; }

		/// <summary>
		/// 
		/// </summary>
		[XmlAttribute("group")]
		public string Group { get; set; }

		/// <summary>
		/// A string describing the data type of the values of
		/// this group of enums, currently unused.The only string used at
		/// present in the is <c>bitmask</c>.
		/// </summary>
		[XmlAttribute("type")]
		public string Type { get; set; }

		/// <summary>
		/// Integers defining the start and end of a reserved range of enumerants for a particular vendor or purpose.
		/// <see cref="Start"/> must be less than or equal to <see cref="End"/>. These fields define formal enumerant allocations within a namespace,
		/// and are made by the Khronos Registrar on request from implementers following the enum allocation policy.
		/// </summary>
		[XmlAttribute("start")]
		public string Start { get; set; }

		/// <summary>
		/// <see cref="Start"/>
		/// </summary>
		[XmlAttribute("end")]
		public string End { get; set; }

		/// <summary>
		/// String describing the vendor or purposes to whom a
		/// reserved range of enumerants is allocated.
		/// </summary>
		[XmlAttribute("vendor")]
		public string Vendor { get; set; }

		/// <summary>
		/// Arbitrary string (unused).
		/// </summary>
		[XmlElement("comment")]
		public string Comment { get; set; }

		/// <summary>
		/// Contains zero or more enums, in arbitrary order (although they are typically ordered by sorting
		/// on enumerant values, to improve human readability).
		/// </summary>
		[XmlElement("enum", IsNullable = false)]
		public EnumKeyedCollection Enums { get; set; }

		/// <summary>
		/// Contains zero or more unuseds, in arbitrary order (although they are typically ordered by sorting
		/// on enumerant values, to improve human readability).
		/// </summary>
		[XmlElement("unused")]
		public List<Unused> NotUsed { get; set; }
	}

	/// <summary>
	/// Contains definitions of each of the functions (commands) used in the API.
	/// </summary>
	public class RegistryCommands {
		/// <summary>
		/// Contains a structured definition of a single API command (function).
		/// </summary>
		public class Command {
			/// <summary>
			/// Defines the return type and name of a command.
			/// </summary>
			public class Proto {
				/// <summary>
				/// Group name, an arbitrary string.
				/// </summary>
				[XmlAttribute("group")]
				public string GroupName { get; set; }

				/// <summary>
				/// Contains legal C code describing the return type and name of a command.
				/// </summary>
				[XmlText]
				public List<string> Text { get; set; }

				/// <summary>
				/// Optional, and contains text which is a
				/// valid type name found in <see cref="RegistryTypes.Type"/> tag, and indicates that this
				/// type must be previously defined for the definition of the command
				/// to succeed. Builtin C types, and any derived types which are
				/// expected to be found in other header files, should not be wrapped
				/// in this tag.
				/// </summary>
				[XmlElement("ptype")]
				public string PointerType { get; set; }

				/// <summary>
				/// Tag is required, and contains the command name being described.
				/// </summary>
				[XmlElement("name")]
				public string Name { get; set; }
			}

			/// <summary>
			/// Defines the type and name of a parameter.
			/// </summary>
			public class Param {
				/// <summary>
				/// Group name, an arbitrary string.
				/// </summary>
				[XmlAttribute("group")]
				public string GroupName { get; set; }

				/// <summary>
				/// Parameter length, either an integer specifying the
				/// number of elements of the parameter <see cref="PointerType"/>, or a complex
				/// string expression with poorly defined syntax, usually representing
				/// a length that is computed as a combination of other command
				/// parameter values, and possibly current GL state as well.
				/// </summary>
				[XmlAttribute("len")]
				public string Length { get; set; }

				/// <summary>
				/// Constains legal C code describing the type and name of a function parameter.
				/// </summary>
				[XmlText]
				public List<string> Text { get; set; }

				/// <summary>
				/// Optional, and contains text which is a
				/// valid type name found in <see cref="RegistryTypes.Type"/> tag, and indicates that this
				/// type must be previously defined for the definition of the command
				/// to succeed. Builtin C types, and any derived types which are
				/// expected to be found in other header files, should not be wrapped
				/// in this tag.
				/// </summary>
				[XmlElement("ptype")]
				public string PointerType { get; set; }

				/// <summary>
				/// Tag is required, and contains the command name being described.
				/// </summary>
				[XmlElement("name")]
				public string Name { get; set; }
			}

			/// <summary>
			/// A command alias describes the case where there are two function
			/// names which resolve to the same client library code, so (for
			/// example) the case where a command is promoted but is also given
			/// different GLX protocol would not be an alias in this sense.
			/// </summary>
			public class Alias {
				/// <summary>
				/// The name of another command this command is an alias of,
				/// used when promoting a function from extension to ARB or ARB to API status.
				/// </summary>
				[XmlAttribute("name")]
				public string Name { get; set; }
			}

			/// <summary>
			/// For example, the vector equivalent of
			/// <c>glVertex3f</c> is <c>glVertex3fv</c>.
			/// </summary>
			public class Vecequiv {
				/// <summary>
				/// The name of another command which is the vector equivalent of this command.
				/// </summary>
				[XmlAttribute("name")]
				public string Name { get; set; }
			}

			/// <summary>
			/// Many GL commands don't have GLX protocol defined,
			/// and other APIs such as EGL and WGL don't use GLX at all.
			/// </summary>
			public class Glx {
				[XmlAttribute("name")]
				public string Name { get; set; }

				[XmlAttribute("type")]
				public string Type { get; set; }

				[XmlAttribute("opcode")]
				public ushort OpCode { get; set; }

				/// <summary>
				/// Arbitrary string (unused).
				/// </summary>
				[XmlAttribute("comment")]
				public string Comment { get; set; }
			}

			/// <summary>
			/// Arbitrary string (unused).
			/// </summary>
			[XmlAttribute("comment")]
			public string Comment { get; set; }

			/// <summary>
			/// Must be the first element, and is a tag defining the C
			/// function prototype of a command as described below, up to the
			/// function name but not including function parameters.
			/// </summary>
			[XmlElement("proto")]
			public Proto Prototype { get; set; }

			/// <summary>
			/// Elements for each command parameter follow, defining
			/// its name and type, as described below. If a command takes no
			/// arguments, it has no params.
			/// </summary>
			[XmlElement("param")]
			public List<Param> Params { get; set; }

			/// <summary>
			/// Defines command aliases for this command.
			/// </summary>
			[XmlElement("alias")]
			public List<Alias> Aliases { get; set; }

			/// <summary>
			/// Defines vector equivalents for this command.
			/// </summary>
			[XmlElement("vecequiv")]
			public Vecequiv VectorEquiv { get; set; }

			/// <summary>
			/// Defines GLX protocol information for this command, as
			/// described below. Many GL commands don't have GLX protocol defined,
			/// and other APIs such as EGL and WGL don't use GLX at all.
			/// </summary>
			[XmlElement("glx")]
			public List<Glx> Glxs { get; set; }
		}

		public class CommandKeyedCollection : KeyedCollection<string, Command> {
			protected override string GetKeyForItem(Command item) => item.Prototype.Name;
		}

		/// <summary>
		/// A string defining the namespace in which commands live,
		/// currently unused but typically something like <c>GL</c>.
		/// </summary>
		[XmlAttribute("namespace")]
		public string Namespace { get; set; }

		/// <summary>
		/// Each commands block contains zero or more commands, in
		/// arbitrary order (although they are typically ordered by sorting on the
		/// command name, to improve human readability).
		/// </summary>
		[XmlElement("command", IsNullable = false)]
		public CommandKeyedCollection Commands { get; set; }
	}

	/// <summary>
	/// API features are described in individual features. A feature
	/// is the set of interfaces(enumerants and commands) defined by a
	/// particular API and version, such as OpenGL 4.0 or OpenGL ES 3.0, and
	/// includes all API profiles of that version.
	/// </summary>
	public class RegistryFeature {
		/// <summary>
		/// API name this feature is for, such as <c>gl</c> or <c>gles2</c>.
		/// </summary>
		[XmlAttribute("api")]
		public string Api { get; set; }

		/// <summary>
		/// Version name, used as the C preprocessor token under
		/// which the version's interfaces are protected against multiple
		/// inclusion. Example: <c>GL_VERSION_4_2</c>.
		/// </summary>
		[XmlAttribute("name")]
		public string Name { get; set; }

		/// <summary>
		/// An additional preprocessor token used to protect a feature definition.
		/// Usually another feature or extension <see cref="Name"/>. Rarely used, for odd circumstances
		/// where the definition of a feature or extension requires another to be defined first.
		/// </summary>
		[XmlAttribute("protect")]
		public string Protect { get; set; }

		/// <summary>
		/// Feature version number, usually a string
		/// interpreted as $majorNumber.minorNumber$. Example: <c>4.2</c>.
		/// </summary>
		[XmlAttribute("number")]
		public double Number { get; set; }

		/// <summary>
		/// Arbitrary string (unused).
		/// </summary>
		[XmlAttribute("comment")]
		public string Comment { get; set; }

		/// <summary>
		/// Zero or more requires, in arbitrary order. Each tag describes a
		/// set of interfaces that is respectively required for this feature.
		/// </summary>
		[XmlElement("require", IsNullable = false)]
		public List<RegistryRequires> Requires { get; set; }

		/// <summary>
		/// Zero or more removes, in arbitrary order. Each tag describes a
		/// set of interfaces that is removed from this feature.
		/// </summary>
		[XmlElement("remove", IsNullable = false)]
		public List<RegistryRequires> Removes { get; set; }
	}

	public class RegistryFeatureKeyedCollection : KeyedCollection<string, RegistryFeature> {
		protected override string GetKeyForItem(RegistryFeature item) => item.Name;
	}

	/// <summary>
	/// Contains definitions of each of the extenions which are defined for the API.
	/// </summary>
	public class RegistryExtensions {
		/// <summary>
		/// API extensions are described in individual extensions. An
		/// extension is the set of interfaces defined by a particular API extension
		/// specification, such as <c>ARB_multitexture</c>. Similar to <see cref="RegistryFeature"/>,
		/// but instead of having <c>version</c> and <c>profile</c> attributes, instead has a <see cref="Supported"/> attribute,
		/// which describes the set of API names which the extension can potentially be implemented against.
		/// </summary>
		public class Extension {
			/// <summary>
			/// A regular expression, with an implicit <c>\^{}</c> and <c>\$</c> bracketing it,
			/// which should match the api of a set of features.
			/// </summary>
			[XmlAttribute("supported")]
			public string Supported { get; set; }

			/// <summary>
			/// An additional preprocessor token used to protect an extension definition.
			/// Usually another feature or extension name. Rarely used, for odd circumstances
			/// where the definition of an extension requires another to be defined first.
			/// </summary>
			[XmlAttribute("protect")]
			public string Protect { get; set; }

			/// <summary>
			/// 
			/// </summary>
			[XmlAttribute("name")]
			public string Name { get; set; }

			/// <summary>
			/// Arbitrary string (unused).
			/// </summary>
			[XmlAttribute("comment")]
			public string Comment { get; set; }

			/// <summary>
			/// Zero or more requires, in arbitrary order. Each tag describes a
			/// set of interfaces that are required for this extension.
			/// </summary>
			[XmlElement("require")]
			public List<RegistryRequires> Requires { get; set; }

			/// <summary>
			/// Zero or more removes, in arbitrary order. Each tag describes a
			/// set of interfaces that are removed from this extension.
			/// </summary>
			public List<RegistryRequires> Removes { get; set; }
		}

		public class ExtensionKeyedCollection : KeyedCollection<string, Extension> {
			protected override string GetKeyForItem(Extension item) => item.Name;
		}

		/// <summary>
		/// Contains zero or more extensions, each describing an API extension, in arbitrary order
		/// (although they are typically ordered by sorting on the extension name, to improve human readability).
		/// </summary>
		[XmlElement("extension", IsNullable = false)]
		public ExtensionKeyedCollection Extensions { get; set; } 
	}

	/// <summary>
	/// Defines a set of interfaces (types, enumerants and commands) required by a feature or extension.
	/// A remove block defines a set of interfaces removed by a feature
	/// (this is primarily useful for the OpenGL core profile, which removed many interfaces -
	/// extensions should never remove interfaces, although this usage is allowed by the schema).
	/// Except for the tag name and behavior, the contents of require and remove tags are identical.
	/// </summary>
	public class RegistryRequires {
		public class CommandName {
			/// <summary>
			/// Name of the command (required).
			/// </summary>
			[XmlAttribute("name")]
			public string Name { get; set; }

			/// <summary>
			/// Arbitrary string (optional and unused).
			/// </summary>
			[XmlElement("comment")]
			public string Comment { get; set; }
		}

		/// <summary>
		/// May contain only a <see cref="Name"/> attribute, which should correspond to a
		/// <see cref="RegistryEnums.Enum"/> definition in an enums block.
		/// </summary>
		public class EnumName {
			/// <summary>
			/// Name of the enumerant (required).
			/// </summary>
			[XmlAttribute("name")]
			public string Name { get; set; }

			/// <summary>
			/// Arbitrary string (optional and unused).
			/// </summary>
			[XmlElement("comment")]
			public string Comment { get; set; }
		}

		public class TypeName {
			/// <summary>
			/// Name of the type (required).
			/// </summary>
			[XmlAttribute("name")]
			public string Name { get; set; }

			/// <summary>
			/// Arbitrary string (optional and unused).
			/// </summary>
			[XmlElement("comment")]
			public string Comment { get; set; }
		}

		/// <summary>
		/// String name of an API profile. Interfaces in the
		/// tag are only required(or removed) if the specified profile is
		/// being generated.If not specified, interfaces are required (or
		/// removed) for all API profiles.
		/// </summary>
		[XmlAttribute("profile")]
		public string Profile { get; set; }

		/// <summary>
		/// Arbitrary string (unused).
		/// </summary>
		[XmlElement("comment")]
		public string Comment { get; set; }

		/// <summary>
		/// An API name. Interfaces in the tag are only required (or removed)
		/// if the specified API is being generated. If not specified,
		/// interfaces are required (or removed) for all APIs.
		/// 
		/// This attribute is only supported inside extensions,
		/// since features already define a specific API.
		/// </summary>
		[XmlAttribute("api")]
		public string Api { get; set; }

		/// <summary>
		/// Specifies an required (or removed) command.
		/// </summary>
		[XmlElement("command")]
		public List<CommandName> CommandNames { get; set; }

		/// <summary>
		/// Specifies an required (or removed) enumerant.
		/// </summary>
		[XmlElement("enum")]
		public List<EnumName> EnumNames { get; set; }

		/// <summary>
		/// Specifies a required (or removed) type.
		/// Most types are picked up implicitly by using
		/// the <see cref="RegistryCommands.Command.Proto.PointerType"/> of commands,
		/// but in a few cases, additional types need to be specified explicitly (it is unlikely
		/// that a type would ever be removed, although this usage is allowed by the schema).
		/// </summary>
		[XmlElement("type")]
		public List<TypeName> TypeNames { get; set; }
	}
}
