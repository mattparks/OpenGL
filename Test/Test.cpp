#include <iostream>

#include <GL/OpenGL.h>
using namespace ogl;

int main() {
	std::cout << oglInit() << "\n";
	auto result = reinterpret_cast<const char *>(glGetString(GL_EXTENSIONS));
	std::cout << (strstr(result, "GL_EXT_framebuffer_object") != nullptr);
	std::cout << "Hello World!\n";
	return 0;
}
