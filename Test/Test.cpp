#include <iostream>

#include <GL/OpenGL.h>

int main() {
	std::cout << glInit() << "\n";
	std::cout << (strstr(reinterpret_cast<const char *>(glGetString(GL_EXTENSIONS)), "GL_EXT_framebuffer_object") != nullptr);
	auto ptr = glGetString(GL_EXTENSIONS);
	std::cout << "Hello World!\n";
	return 0;
}
