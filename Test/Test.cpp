#include <iostream>

#include "GL/OpenGL.h"
using namespace gl;

int main() {
	initialize(nullptr);
	
	auto majorVersion = 0;
	auto minorVersion = 0;
	glGetIntegerv(GL_MAJOR_VERSION, &majorVersion);
	glGetIntegerv(GL_MINOR_VERSION, &minorVersion);
	auto version = glGetString(GL_VERSION);

	int numExtensions = 0;
	glGetIntegerv(GL_NUM_EXTENSIONS, &numExtensions);
	auto extensions = glGetString(GL_EXTENSIONS);
	return 0;
}
