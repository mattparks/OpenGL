using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Xml.Serialization;

namespace Generator {
	[Serializable]
	[DesignerCategory("code")]
	[XmlType(AnonymousType = true)]
	[XmlRoot("registry", Namespace = "", IsNullable = false)]
	public class Registry {
		public string comment { get; set; }

		[XmlArrayItem("type", IsNullable = false)]
		public List<RegistryType> types { get; set; }

		[XmlArrayItem("group", IsNullable = false)]
		public List<RegistryGroup> groups { get; set; }

		[XmlElement("enums")]
		public List<RegistryEnums> enums { get; set; }

		[XmlElement("commands")]
		public List<RegistryCommands> commands { get; set; }

		[XmlElement("feature")]
		public List<RegistryFeature> feature { get; set; }

		[XmlArrayItem("extension", IsNullable = false)]
		public List<RegistryExtension> extensions { get; set; }
	}

	[Serializable]
	[DesignerCategory("code")]
	[XmlType("registryType", AnonymousType = true)]
	public class RegistryType {
		public object apientry { get; set; }

		public string name { get; set; }

		[XmlText]
		public List<string> text { get; set; }

		[XmlAttribute("name")]
		public string name1 { get; set; }

		[XmlAttribute]
		public string comment { get; set; }

		[XmlAttribute]
		public string requires { get; set; }
	}

	[Serializable]
	[DesignerCategory("code")]
	[XmlType("registryGroup", AnonymousType = true)]
	public class RegistryGroup {
		[XmlElement("enum")]
		public List<RegistryGroupEnum> @enum { get; set; }

		[XmlAttribute]
		public string name { get; set; }

		[XmlAttribute]
		public string comment { get; set; }
	}

	[Serializable]
	[DesignerCategory("code")]
	[XmlType("registryGroupEnum", AnonymousType = true)]
	public class RegistryGroupEnum {
		[XmlAttribute]
		public string name { get; set; }
	}

	[Serializable]
	[DesignerCategory("code")]
	[XmlType("registryEnums", AnonymousType = true)]
	public class RegistryEnums {
		[XmlElement("enum", typeof(RegistryEnumsEnum))]
		[XmlElement("unused", typeof(RegistryEnumsUnused))]
		public List<object> items { get; set; }

		[XmlAttribute]
		public string @namespace { get; set; }

		[XmlAttribute]
		public string group { get; set; }

		[XmlAttribute]
		public string type { get; set; }

		[XmlAttribute]
		public string comment { get; set; }

		[XmlAttribute]
		public string vendor { get; set; }

		[XmlAttribute]
		public string start { get; set; }

		[XmlAttribute]
		public string end { get; set; }
	}

	[Serializable]
	[DesignerCategory("code")]
	[XmlType("registryEnumsEnum", AnonymousType = true)]
	public class RegistryEnumsEnum {
		[XmlAttribute]
		public string value { get; set; }

		[XmlAttribute]
		public string name { get; set; }

		[XmlAttribute]
		public string comment { get; set; }

		[XmlAttribute]
		public string alias { get; set; }

		[XmlAttribute]
		public string type { get; set; }

		[XmlAttribute]
		public string api { get; set; }
	}

	[Serializable]
	[DesignerCategory("code")]
	[XmlType("registryEnumsUnused", AnonymousType = true)]
	public class RegistryEnumsUnused {
		[XmlAttribute]
		public string start { get; set; }

		[XmlAttribute]
		public string end { get; set; }

		[XmlAttribute]
		public string comment { get; set; }

		[XmlAttribute]
		public string vendor { get; set; }
	}

	[Serializable]
	[DesignerCategory("code")]
	[XmlType("registryCommands", AnonymousType = true)]
	public class RegistryCommands {
		[XmlElement("command")]
		public List<RegistryCommandsCommand> command { get; set; }

		[XmlAttribute]
		public string @namespace { get; set; }
	}

	[Serializable]
	[DesignerCategory("code")]
	[XmlType("registryCommandsCommand", AnonymousType = true)]
	public class RegistryCommandsCommand {
		[XmlElement("alias", typeof(RegistryCommandsCommandAlias))]
		[XmlElement("glx", typeof(RegistryCommandsCommandGlx))]
		[XmlElement("param", typeof(RegistryCommandsCommandParam))]
		[XmlElement("proto", typeof(RegistryCommandsCommandProto))]
		[XmlElement("vecequiv", typeof(RegistryCommandsCommandVecequiv))]
		public List<object> items { get; set; }

		[XmlAttribute]
		public string comment { get; set; }
	}

	[Serializable]
	[DesignerCategory("code")]
	[XmlType("registryCommandsCommandAlias", AnonymousType = true)]
	public class RegistryCommandsCommandAlias {
		[XmlAttribute]
		public string name { get; set; }
	}

	[Serializable]
	[DesignerCategory("code")]
	[XmlType("registryCommandsCommandGlx", AnonymousType = true)]
	public class RegistryCommandsCommandGlx {
		[XmlAttribute]
		public string type { get; set; }

		[XmlAttribute]
		public ushort opcode { get; set; }

		[XmlAttribute]
		public string name { get; set; }

		[XmlAttribute]
		public string comment { get; set; }
	}

	[Serializable]
	[DesignerCategory("code")]
	[XmlType("registryCommandsCommandParam", AnonymousType = true)]
	public class RegistryCommandsCommandParam {
		public string ptype { get; set; }

		public string name { get; set; }

		[XmlText]
		public List<string> text { get; set; }

		[XmlAttribute]
		public string group { get; set; }

		[XmlAttribute]
		public string len { get; set; }

		public string GLType() {
			return !string.IsNullOrEmpty(ptype) ? ptype + " " : text[0];
		}
	}

	[Serializable]
	[DesignerCategory("code")]
	[XmlType("registryCommandsCommandProto", AnonymousType = true)]
	public class RegistryCommandsCommandProto {
		public string ptype { get; set; }

		public string name { get; set; }

		[XmlText]
		public List<string> text { get; set; }

		[XmlAttribute]
		public string group { get; set; }

		public string GLType() {
			return !string.IsNullOrEmpty(ptype) ? ptype + " " : text[0];
		}
	}

	[Serializable]
	[DesignerCategory("code")]
	[XmlType("registryCommandsCommandVecequiv", AnonymousType = true)]
	public class RegistryCommandsCommandVecequiv {
		[XmlAttribute]
		public string name { get; set; }
	}

	[Serializable]
	[DesignerCategory("code")]
	[XmlType("registryFeature", AnonymousType = true)]
	public class RegistryFeature {
		[XmlElement("require")]
		public List<RegistryFeatureRequire> require { get; set; }

		[XmlElement("remove")]
		public List<RegistryFeatureRemove> remove { get; set; }

		[XmlAttribute]
		public string api { get; set; }

		[XmlAttribute]
		public string name { get; set; }

		[XmlAttribute]
		public double number { get; set; }
	}

	[Serializable]
	[DesignerCategory("code")]
	[XmlType("registryFeatureRequire", AnonymousType = true)]
	public class RegistryFeatureRequire {
		[XmlElement("command", typeof(RegistryFeatureRequireCommand))]
		[XmlElement("enum", typeof(RegistryFeatureRequireEnum))]
		[XmlElement("type", typeof(RegistryFeatureRequireType))]
		public List<object> items { get; set; }

		[XmlAttribute]
		public string comment { get; set; }

		[XmlAttribute]
		public string profile { get; set; }
	}

	[Serializable]
	[DesignerCategory("code")]
	[XmlType("registryFeatureRequireCommand", AnonymousType = true)]
	public class RegistryFeatureRequireCommand {
		[XmlAttribute]
		public string name { get; set; }
	}

	[Serializable]
	[DesignerCategory("code")]
	[XmlType("registryFeatureRequireEnum", AnonymousType = true)]
	public class RegistryFeatureRequireEnum {
		[XmlAttribute]
		public string name { get; set; }

		[XmlAttribute]
		public string comment { get; set; }
	}

	[Serializable]
	[DesignerCategory("code")]
	[XmlType("registryFeatureRequireType", AnonymousType = true)]
	public class RegistryFeatureRequireType {
		[XmlAttribute]
		public string name { get; set; }

		[XmlAttribute]
		public string comment { get; set; }
	}

	[Serializable]
	[DesignerCategory("code")]
	[XmlType("registryFeatureRemove", AnonymousType = true)]
	public class RegistryFeatureRemove {
		[XmlElement("enum")]
		public List<RegistryFeatureRemoveEnum> @enum { get; set; }

		[XmlElement("command")]
		public List<RegistryFeatureRemoveCommand> command { get; set; }

		[XmlAttribute]
		public string profile { get; set; }

		[XmlAttribute]
		public string comment { get; set; }
	}

	[Serializable]
	[DesignerCategory("code")]
	[XmlType("registryFeatureRemoveEnum", AnonymousType = true)]
	public class RegistryFeatureRemoveEnum {
		[XmlAttribute]
		public string name { get; set; }
	}

	[Serializable]
	[DesignerCategory("code")]
	[XmlType("registryFeatureRemoveCommand", AnonymousType = true)]
	public class RegistryFeatureRemoveCommand {
		[XmlAttribute]
		public string name { get; set; }
	}

	[Serializable]
	[DesignerCategory("code")]
	[XmlType("registryExtension", AnonymousType = true)]
	public class RegistryExtension {
		[XmlElement("require")]
		public List<RegistryExtensionRequire> require { get; set; }

		[XmlAttribute]
		public string name { get; set; }

		[XmlAttribute]
		public string supported { get; set; }

		[XmlAttribute]
		public string comment { get; set; }
	}

	[Serializable]
	[DesignerCategory("code")]
	[XmlType("registryExtensionRequire", AnonymousType = true)]
	public class RegistryExtensionRequire {
		[XmlElement("command", typeof(RegistryExtensionRequireCommand))]
		[XmlElement("enum", typeof(RegistryExtensionRequireEnum))]
		[XmlElement("type", typeof(RegistryExtensionRequireType))]
		public List<object> items { get; set; }

		[XmlAttribute]
		public string comment { get; set; }

		[XmlAttribute]
		public string api { get; set; }

		[XmlAttribute]
		public string profile { get; set; }
	}

	[Serializable]
	[DesignerCategory("code")]
	[XmlType("registryExtensionRequireCommand", AnonymousType = true)]
	public class RegistryExtensionRequireCommand {
		[XmlAttribute]
		public string name { get; set; }

		[XmlAttribute]
		public string comment { get; set; }
	}

	[Serializable]
	[DesignerCategory("code")]
	[XmlType("registryExtensionRequireEnum", AnonymousType = true)]
	public class RegistryExtensionRequireEnum {
		[XmlAttribute]
		public string name { get; set; }


		[XmlAttribute]
		public string comment { get; set; }
	}

	[Serializable]
	[DesignerCategory("code")]
	[XmlType("registryExtensionRequireType", AnonymousType = true)]
	public class RegistryExtensionRequireType {
		[XmlAttribute]
		public string name { get; set; }
	}
}
