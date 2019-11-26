using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;

namespace OpenGL {
	class Proc {
		public static void LoadProcs(string path, string pattern, ref List<string> procs) {
			var file = new StreamReader(path);
			string line;
			while ((line = file.ReadLine()) != null) {
				var match = Regex.Match(line, pattern);
				if (match.Success)
					procs.Add(match.Groups[1].Value);
			}
		}

		public static string GetProcType(string proc) {
			return "PFN" + proc.ToUpper() + "PROC";
		}

		public static string GetProcSignature(string name, string proc) {
			return name + proc.Substring(2);
		}

		public static void WriteHeader(string path, string name, List<string> procs) {
			var NAME = name.ToUpper();
			using (var file = new StreamWriter($"{path}/{name}.h")) {
				file.Write($@"#ifndef __{name}_h_
#define __{name}_h_

#include <GL/glcorearb.h>

#ifndef __gl_h_
#define __gl_h_
#endif

#ifdef __cplusplus
extern ""C"" {{
#endif

typedef void (* {NAME}glProc) (void);
typedef {NAME}glProc(*{NAME}GetProcAddressProc)(const char* proc);

/* {name} api */
int {name}Init(void);
int {name}Init2({NAME}GetProcAddressProc proc);
int {name}IsSupported(int major, int minor);
{NAME}glProc {name}GetProcAddress(const char* proc);

/* OpenGL functions */
");

				var longestProc = procs.OrderByDescending(s => s.Length).First();

				var externPad = longestProc.Length + 7;
				foreach (var proc in procs) {
					var procType = GetProcType(proc);
					var procSignature = GetProcSignature(name, proc);
					file.Write($"extern {procType}{new string(' ', externPad - procType.Length)} {procSignature};\n");
				}

				var definePad = longestProc.Length + name.Length + 4;
				foreach (var proc in procs) {
					var procSignature = GetProcSignature(name, proc);
					file.Write($"#define {proc}{new string(' ', definePad - procSignature.Length)} {procSignature}\n");
				}

				file.Write($@"
#ifdef __cplusplus
}}
#endif

#endif
");
			}
		}
	}
}
