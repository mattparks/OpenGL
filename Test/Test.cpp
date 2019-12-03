#include <iostream>

#include "GL/OpenGL.h"
#include <GLFW/glfw3.h>

using namespace gl;

void error(int errnum, const char *errmsg) {
	std::cerr << errnum << ": " << errmsg << std::endl;
}

int main() {
	glfwSetErrorCallback(error);

	if (!glfwInit())
		return 1;

	glfwDefaultWindowHints();

	auto window = glfwCreateWindow(640, 480, "", nullptr, nullptr);
	if (!window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	initialize(glfwGetProcAddress);
	
	auto majorVersion = 0;
	auto minorVersion = 0;
	glGetIntegerv(GL_MAJOR_VERSION, &majorVersion);
	glGetIntegerv(GL_MINOR_VERSION, &minorVersion);
	auto version = glGetString(GL_VERSION);
	auto vendor = glGetString(GL_VENDOR);
	auto renderer = glGetString(GL_RENDERER);

	int numExtensions = 0;
	glGetIntegerv(GL_NUM_EXTENSIONS, &numExtensions);
	auto extensions = glGetString(GL_EXTENSIONS);
	
	return 0;
}
