using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Text.RegularExpressions;

namespace OpenGL {
	class Program {
		static void Main(string[] args) {
			if (Directory.Exists("include"))
				Directory.Delete("include", true);
			Directory.CreateDirectory("include");

			if (Directory.Exists("src"))
				Directory.Delete("src", true);
			Directory.CreateDirectory("src");

			CreateGL();
			CreateGLES(new string[] { "GLES3/gl3.h", "GLES2/gl2ext.h" });
		}

		static void CreateGL() {
			using (var client = new WebClient()) {
				Directory.CreateDirectory("include/GL");
				client.DownloadFile("https://www.khronos.org/registry/OpenGL/api/GL/glcorearb.h", "include/GL/glcorearb.h");
			}

			var procs = new List<string>();
			Proc.LoadProcs("include/GL/glcorearb.h", "GLAPI.*APIENTRY[ ]+([a-zA-Z0-9_]+)", ref procs);

			Proc.WriteHeader("include/GL", "gl3w", procs);
		}

		static void CreateGLES(string[] apis) {
			using (var client = new WebClient()) {
				Directory.CreateDirectory("include/KHR");
				client.DownloadFile("https://www.khronos.org/registry/EGL/api/KHR/khrplatform.h", "include/KHR/khrplatform.h");

			}

			var procs = new List<string>();
			foreach (var api in apis) {
				using (var client = new WebClient()) {
					Directory.CreateDirectory("include/" + Path.GetDirectoryName(api));
					client.DownloadFile("https://www.khronos.org/registry/gles/api/" + api, "include/" + api);
				}
				Proc.LoadProcs("include/" + api, "GL_APICALL.*GL_APIENTRY[ ]+([a-zA-Z0-9_]+)", ref procs);
			}

			Proc.WriteHeader("include/GLES3", "glesw", procs);
		}
	}
}
