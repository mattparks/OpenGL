/*

OpenGL loader generated tool at 2019-12-04T00:06:22.5285910Z

------------------------------------------------------------------------

Copyright (c) 2013-2019 The Khronos Group Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

------------------------------------------------------------------------

This file, gl.xml, is the OpenGL and OpenGL API Registry. The canonical
version of the registry, together with documentation, schema, and Python
generator scripts used to generate C header files for OpenGL and OpenGL ES,
can always be found in the Khronos Registry at
        https://github.com/KhronosGroup/OpenGL-Registry
    
*/

#include <GL/OpenGL.h>

#include <cassert>
#ifdef _WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN 1
#endif
#ifndef UNICODE
#define UNICODE 1
#endif
#include <Windows.h>
#include <tchar.h>
#else
#include <dlfcn.h>
#endif

namespace impl {
#ifdef _WIN32
#pragma comment(lib, "opengl32.lib")

gl::ProcAddress getProcAddress(const char *name) {
	static auto module = LoadLibrary(L"OPENGL32.DLL");

	// Prevent static linking of opengl32
	static auto wglGetProcAddress_ = reinterpret_cast<void *(GL_APIENTRYP)(const char *)>((uintptr_t) ::GetProcAddress(module, "wglGetProcAddress"));
	assert(wglGetProcAddress_ != nullptr);

	auto procAddress = wglGetProcAddress_(name);
	if (procAddress != nullptr) {
		return reinterpret_cast<gl::ProcAddress>(procAddress);
	}

	procAddress = (void *) ::GetProcAddress(module, name);
	return reinterpret_cast<gl::ProcAddress>(procAddress);
}
#else
void *LoadLibraryGL() {
#ifdef __APPLE__
	static const char *NAMES[] = {
		"../Frameworks/OpenGL.framework/OpenGL",
		"/Library/Frameworks/OpenGL.framework/OpenGL",
		"/System/Library/Frameworks/OpenGL.framework/OpenGL",
		"/System/Library/Frameworks/OpenGL.framework/Versions/Current/OpenGL"
	};
#else
	static const char *NAMES[] = {"libGL.so.1", "libGL.so"};
#endif
    for (unsigned int i = 0; i < (sizeof(NAMES) / sizeof(NAMES[0])); i++) {
		if (auto libGL = dlopen(NAMES[i], RTLD_NOW | RTLD_GLOBAL); libGL) {
			return libGL;
        }
    }
	return nullptr;
}

gl::ProcAddress getProcAddress(const char *name) {
	static auto library = LoadLibraryGL();
	assert(library != nullptr);

	void *procAddress = nullptr;
#if !defined(__APPLE__) && !defined(__HAIKU__)
	static auto glXGetProcAddress_ = reinterpret_cast<void *(GL_APIENTRYP)(const char *)>(dlsym(library, "glXGetProcAddressARB"));
	
	if (glXGetProcAddress_)
		procAddress = glXGetProcAddress_(name);
#endif
	if (!procAddress)
		procAddress = dlsym(library, name);
	return reinterpret_cast<gl::ProcAddress>(procAddress);
}
#endif
}

namespace gl {
GetProcAddress getProcAddress = nullptr;

void initialize(const GetProcAddress &resolver) {
	if (resolver == nullptr)
		getProcAddress = impl::getProcAddress;
	else
		getProcAddress = resolver;
}

void glCullFace(GLenum mode) {
	static const auto glCullFace_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glCullFace"));
	assert(glCullFace_ != nullptr);
	return glCullFace_(mode);
}
void glFrontFace(GLenum mode) {
	static const auto glFrontFace_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glFrontFace"));
	assert(glFrontFace_ != nullptr);
	return glFrontFace_(mode);
}
void glHint(GLenum target, GLenum mode) {
	static const auto glHint_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum)>(getProcAddress("glHint"));
	assert(glHint_ != nullptr);
	return glHint_(target, mode);
}
void glLineWidth(GLfloat width) {
	static const auto glLineWidth_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat)>(getProcAddress("glLineWidth"));
	assert(glLineWidth_ != nullptr);
	return glLineWidth_(width);
}
void glPointSize(GLfloat size) {
	static const auto glPointSize_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat)>(getProcAddress("glPointSize"));
	assert(glPointSize_ != nullptr);
	return glPointSize_(size);
}
void glPolygonMode(GLenum face, GLenum mode) {
	static const auto glPolygonMode_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum)>(getProcAddress("glPolygonMode"));
	assert(glPolygonMode_ != nullptr);
	return glPolygonMode_(face, mode);
}
void glScissor(GLint x, GLint y, GLsizei width, GLsizei height) {
	static const auto glScissor_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLint, GLsizei, GLsizei)>(getProcAddress("glScissor"));
	assert(glScissor_ != nullptr);
	return glScissor_(x, y, width, height);
}
void glTexParameterf(GLenum target, GLenum pname, GLfloat param) {
	static const auto glTexParameterf_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfloat)>(getProcAddress("glTexParameterf"));
	assert(glTexParameterf_ != nullptr);
	return glTexParameterf_(target, pname, param);
}
void glTexParameterfv(GLenum target, GLenum pname, GLfloat const  * params) {
	static const auto glTexParameterfv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfloat const  *)>(getProcAddress("glTexParameterfv"));
	assert(glTexParameterfv_ != nullptr);
	return glTexParameterfv_(target, pname, params);
}
void glTexParameteri(GLenum target, GLenum pname, GLint param) {
	static const auto glTexParameteri_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint)>(getProcAddress("glTexParameteri"));
	assert(glTexParameteri_ != nullptr);
	return glTexParameteri_(target, pname, param);
}
void glTexParameteriv(GLenum target, GLenum pname, GLint const  * params) {
	static const auto glTexParameteriv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint const  *)>(getProcAddress("glTexParameteriv"));
	assert(glTexParameteriv_ != nullptr);
	return glTexParameteriv_(target, pname, params);
}
void glTexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void * pixels) {
	static const auto glTexImage1D_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLint, GLsizei, GLint, GLenum, GLenum, const void *)>(getProcAddress("glTexImage1D"));
	assert(glTexImage1D_ != nullptr);
	return glTexImage1D_(target, level, internalformat, width, border, format, type, pixels);
}
void glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void * pixels) {
	static const auto glTexImage2D_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const void *)>(getProcAddress("glTexImage2D"));
	assert(glTexImage2D_ != nullptr);
	return glTexImage2D_(target, level, internalformat, width, height, border, format, type, pixels);
}
void glDrawBuffer(GLenum buf) {
	static const auto glDrawBuffer_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glDrawBuffer"));
	assert(glDrawBuffer_ != nullptr);
	return glDrawBuffer_(buf);
}
void glClear(GLbitfield mask) {
	static const auto glClear_ = reinterpret_cast<void(GL_APIENTRYP)(GLbitfield)>(getProcAddress("glClear"));
	assert(glClear_ != nullptr);
	return glClear_(mask);
}
void glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
	static const auto glClearColor_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat, GLfloat, GLfloat, GLfloat)>(getProcAddress("glClearColor"));
	assert(glClearColor_ != nullptr);
	return glClearColor_(red, green, blue, alpha);
}
void glClearStencil(GLint s) {
	static const auto glClearStencil_ = reinterpret_cast<void(GL_APIENTRYP)(GLint)>(getProcAddress("glClearStencil"));
	assert(glClearStencil_ != nullptr);
	return glClearStencil_(s);
}
void glClearDepth(GLdouble depth) {
	static const auto glClearDepth_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble)>(getProcAddress("glClearDepth"));
	assert(glClearDepth_ != nullptr);
	return glClearDepth_(depth);
}
void glStencilMask(GLuint mask) {
	static const auto glStencilMask_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint)>(getProcAddress("glStencilMask"));
	assert(glStencilMask_ != nullptr);
	return glStencilMask_(mask);
}
void glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) {
	static const auto glColorMask_ = reinterpret_cast<void(GL_APIENTRYP)(GLboolean, GLboolean, GLboolean, GLboolean)>(getProcAddress("glColorMask"));
	assert(glColorMask_ != nullptr);
	return glColorMask_(red, green, blue, alpha);
}
void glDepthMask(GLboolean flag) {
	static const auto glDepthMask_ = reinterpret_cast<void(GL_APIENTRYP)(GLboolean)>(getProcAddress("glDepthMask"));
	assert(glDepthMask_ != nullptr);
	return glDepthMask_(flag);
}
void glDisable(GLenum cap) {
	static const auto glDisable_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glDisable"));
	assert(glDisable_ != nullptr);
	return glDisable_(cap);
}
void glEnable(GLenum cap) {
	static const auto glEnable_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glEnable"));
	assert(glEnable_ != nullptr);
	return glEnable_(cap);
}
void glFinish() {
	static const auto glFinish_ = reinterpret_cast<void(GL_APIENTRYP)()>(getProcAddress("glFinish"));
	assert(glFinish_ != nullptr);
	return glFinish_();
}
void glFlush() {
	static const auto glFlush_ = reinterpret_cast<void(GL_APIENTRYP)()>(getProcAddress("glFlush"));
	assert(glFlush_ != nullptr);
	return glFlush_();
}
void glBlendFunc(GLenum sfactor, GLenum dfactor) {
	static const auto glBlendFunc_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum)>(getProcAddress("glBlendFunc"));
	assert(glBlendFunc_ != nullptr);
	return glBlendFunc_(sfactor, dfactor);
}
void glLogicOp(GLenum opcode) {
	static const auto glLogicOp_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glLogicOp"));
	assert(glLogicOp_ != nullptr);
	return glLogicOp_(opcode);
}
void glStencilFunc(GLenum func, GLint ref, GLuint mask) {
	static const auto glStencilFunc_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLuint)>(getProcAddress("glStencilFunc"));
	assert(glStencilFunc_ != nullptr);
	return glStencilFunc_(func, ref, mask);
}
void glStencilOp(GLenum fail, GLenum zfail, GLenum zpass) {
	static const auto glStencilOp_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum)>(getProcAddress("glStencilOp"));
	assert(glStencilOp_ != nullptr);
	return glStencilOp_(fail, zfail, zpass);
}
void glDepthFunc(GLenum func) {
	static const auto glDepthFunc_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glDepthFunc"));
	assert(glDepthFunc_ != nullptr);
	return glDepthFunc_(func);
}
void glPixelStoref(GLenum pname, GLfloat param) {
	static const auto glPixelStoref_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfloat)>(getProcAddress("glPixelStoref"));
	assert(glPixelStoref_ != nullptr);
	return glPixelStoref_(pname, param);
}
void glPixelStorei(GLenum pname, GLint param) {
	static const auto glPixelStorei_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint)>(getProcAddress("glPixelStorei"));
	assert(glPixelStorei_ != nullptr);
	return glPixelStorei_(pname, param);
}
void glReadBuffer(GLenum src) {
	static const auto glReadBuffer_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glReadBuffer"));
	assert(glReadBuffer_ != nullptr);
	return glReadBuffer_(src);
}
void glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void * pixels) {
	static const auto glReadPixels_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, void *)>(getProcAddress("glReadPixels"));
	assert(glReadPixels_ != nullptr);
	return glReadPixels_(x, y, width, height, format, type, pixels);
}
void glGetBooleanv(GLenum pname, GLboolean * data) {
	static const auto glGetBooleanv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLboolean *)>(getProcAddress("glGetBooleanv"));
	assert(glGetBooleanv_ != nullptr);
	return glGetBooleanv_(pname, data);
}
void glGetDoublev(GLenum pname, GLdouble * data) {
	static const auto glGetDoublev_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLdouble *)>(getProcAddress("glGetDoublev"));
	assert(glGetDoublev_ != nullptr);
	return glGetDoublev_(pname, data);
}
GLenum glGetError() {
	static const auto glGetError_ = reinterpret_cast<GLenum(GL_APIENTRYP)()>(getProcAddress("glGetError"));
	assert(glGetError_ != nullptr);
	return glGetError_();
}
void glGetFloatv(GLenum pname, GLfloat * data) {
	static const auto glGetFloatv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfloat *)>(getProcAddress("glGetFloatv"));
	assert(glGetFloatv_ != nullptr);
	return glGetFloatv_(pname, data);
}
void glGetIntegerv(GLenum pname, GLint * data) {
	static const auto glGetIntegerv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint *)>(getProcAddress("glGetIntegerv"));
	assert(glGetIntegerv_ != nullptr);
	return glGetIntegerv_(pname, data);
}
GLubyte const  * glGetString(GLenum name) {
	static const auto glGetString_ = reinterpret_cast<GLubyte const  *(GL_APIENTRYP)(GLenum)>(getProcAddress("glGetString"));
	assert(glGetString_ != nullptr);
	return glGetString_(name);
}
void glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, void * pixels) {
	static const auto glGetTexImage_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLenum, GLenum, void *)>(getProcAddress("glGetTexImage"));
	assert(glGetTexImage_ != nullptr);
	return glGetTexImage_(target, level, format, type, pixels);
}
void glGetTexParameterfv(GLenum target, GLenum pname, GLfloat * params) {
	static const auto glGetTexParameterfv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfloat *)>(getProcAddress("glGetTexParameterfv"));
	assert(glGetTexParameterfv_ != nullptr);
	return glGetTexParameterfv_(target, pname, params);
}
void glGetTexParameteriv(GLenum target, GLenum pname, GLint * params) {
	static const auto glGetTexParameteriv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint *)>(getProcAddress("glGetTexParameteriv"));
	assert(glGetTexParameteriv_ != nullptr);
	return glGetTexParameteriv_(target, pname, params);
}
void glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat * params) {
	static const auto glGetTexLevelParameterfv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLenum, GLfloat *)>(getProcAddress("glGetTexLevelParameterfv"));
	assert(glGetTexLevelParameterfv_ != nullptr);
	return glGetTexLevelParameterfv_(target, level, pname, params);
}
void glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint * params) {
	static const auto glGetTexLevelParameteriv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLenum, GLint *)>(getProcAddress("glGetTexLevelParameteriv"));
	assert(glGetTexLevelParameteriv_ != nullptr);
	return glGetTexLevelParameteriv_(target, level, pname, params);
}
GLboolean glIsEnabled(GLenum cap) {
	static const auto glIsEnabled_ = reinterpret_cast<GLboolean(GL_APIENTRYP)(GLenum)>(getProcAddress("glIsEnabled"));
	assert(glIsEnabled_ != nullptr);
	return glIsEnabled_(cap);
}
void glDepthRange(GLdouble n, GLdouble f) {
	static const auto glDepthRange_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble, GLdouble)>(getProcAddress("glDepthRange"));
	assert(glDepthRange_ != nullptr);
	return glDepthRange_(n, f);
}
void glViewport(GLint x, GLint y, GLsizei width, GLsizei height) {
	static const auto glViewport_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLint, GLsizei, GLsizei)>(getProcAddress("glViewport"));
	assert(glViewport_ != nullptr);
	return glViewport_(x, y, width, height);
}
void glNewList(GLuint list, GLenum mode) {
	static const auto glNewList_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum)>(getProcAddress("glNewList"));
	assert(glNewList_ != nullptr);
	return glNewList_(list, mode);
}
void glEndList() {
	static const auto glEndList_ = reinterpret_cast<void(GL_APIENTRYP)()>(getProcAddress("glEndList"));
	assert(glEndList_ != nullptr);
	return glEndList_();
}
void glCallList(GLuint list) {
	static const auto glCallList_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint)>(getProcAddress("glCallList"));
	assert(glCallList_ != nullptr);
	return glCallList_(list);
}
void glCallLists(GLsizei n, GLenum type, const void * lists) {
	static const auto glCallLists_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLenum, const void *)>(getProcAddress("glCallLists"));
	assert(glCallLists_ != nullptr);
	return glCallLists_(n, type, lists);
}
void glDeleteLists(GLuint list, GLsizei range) {
	static const auto glDeleteLists_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLsizei)>(getProcAddress("glDeleteLists"));
	assert(glDeleteLists_ != nullptr);
	return glDeleteLists_(list, range);
}
GLuint glGenLists(GLsizei range) {
	static const auto glGenLists_ = reinterpret_cast<GLuint(GL_APIENTRYP)(GLsizei)>(getProcAddress("glGenLists"));
	assert(glGenLists_ != nullptr);
	return glGenLists_(range);
}
void glListBase(GLuint base) {
	static const auto glListBase_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint)>(getProcAddress("glListBase"));
	assert(glListBase_ != nullptr);
	return glListBase_(base);
}
void glBegin(GLenum mode) {
	static const auto glBegin_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glBegin"));
	assert(glBegin_ != nullptr);
	return glBegin_(mode);
}
void glBitmap(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, GLubyte const  * bitmap) {
	static const auto glBitmap_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLsizei, GLfloat, GLfloat, GLfloat, GLfloat, GLubyte const  *)>(getProcAddress("glBitmap"));
	assert(glBitmap_ != nullptr);
	return glBitmap_(width, height, xorig, yorig, xmove, ymove, bitmap);
}
void glColor3b(GLbyte red, GLbyte green, GLbyte blue) {
	static const auto glColor3b_ = reinterpret_cast<void(GL_APIENTRYP)(GLbyte, GLbyte, GLbyte)>(getProcAddress("glColor3b"));
	assert(glColor3b_ != nullptr);
	return glColor3b_(red, green, blue);
}
void glColor3bv(GLbyte const  * v) {
	static const auto glColor3bv_ = reinterpret_cast<void(GL_APIENTRYP)(GLbyte const  *)>(getProcAddress("glColor3bv"));
	assert(glColor3bv_ != nullptr);
	return glColor3bv_(v);
}
void glColor3d(GLdouble red, GLdouble green, GLdouble blue) {
	static const auto glColor3d_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble, GLdouble, GLdouble)>(getProcAddress("glColor3d"));
	assert(glColor3d_ != nullptr);
	return glColor3d_(red, green, blue);
}
void glColor3dv(GLdouble const  * v) {
	static const auto glColor3dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble const  *)>(getProcAddress("glColor3dv"));
	assert(glColor3dv_ != nullptr);
	return glColor3dv_(v);
}
void glColor3f(GLfloat red, GLfloat green, GLfloat blue) {
	static const auto glColor3f_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat, GLfloat, GLfloat)>(getProcAddress("glColor3f"));
	assert(glColor3f_ != nullptr);
	return glColor3f_(red, green, blue);
}
void glColor3fv(GLfloat const  * v) {
	static const auto glColor3fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat const  *)>(getProcAddress("glColor3fv"));
	assert(glColor3fv_ != nullptr);
	return glColor3fv_(v);
}
void glColor3i(GLint red, GLint green, GLint blue) {
	static const auto glColor3i_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLint, GLint)>(getProcAddress("glColor3i"));
	assert(glColor3i_ != nullptr);
	return glColor3i_(red, green, blue);
}
void glColor3iv(GLint const  * v) {
	static const auto glColor3iv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint const  *)>(getProcAddress("glColor3iv"));
	assert(glColor3iv_ != nullptr);
	return glColor3iv_(v);
}
void glColor3s(GLshort red, GLshort green, GLshort blue) {
	static const auto glColor3s_ = reinterpret_cast<void(GL_APIENTRYP)(GLshort, GLshort, GLshort)>(getProcAddress("glColor3s"));
	assert(glColor3s_ != nullptr);
	return glColor3s_(red, green, blue);
}
void glColor3sv(GLshort const  * v) {
	static const auto glColor3sv_ = reinterpret_cast<void(GL_APIENTRYP)(GLshort const  *)>(getProcAddress("glColor3sv"));
	assert(glColor3sv_ != nullptr);
	return glColor3sv_(v);
}
void glColor3ub(GLubyte red, GLubyte green, GLubyte blue) {
	static const auto glColor3ub_ = reinterpret_cast<void(GL_APIENTRYP)(GLubyte, GLubyte, GLubyte)>(getProcAddress("glColor3ub"));
	assert(glColor3ub_ != nullptr);
	return glColor3ub_(red, green, blue);
}
void glColor3ubv(GLubyte const  * v) {
	static const auto glColor3ubv_ = reinterpret_cast<void(GL_APIENTRYP)(GLubyte const  *)>(getProcAddress("glColor3ubv"));
	assert(glColor3ubv_ != nullptr);
	return glColor3ubv_(v);
}
void glColor3ui(GLuint red, GLuint green, GLuint blue) {
	static const auto glColor3ui_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLuint)>(getProcAddress("glColor3ui"));
	assert(glColor3ui_ != nullptr);
	return glColor3ui_(red, green, blue);
}
void glColor3uiv(GLuint const  * v) {
	static const auto glColor3uiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint const  *)>(getProcAddress("glColor3uiv"));
	assert(glColor3uiv_ != nullptr);
	return glColor3uiv_(v);
}
void glColor3us(GLushort red, GLushort green, GLushort blue) {
	static const auto glColor3us_ = reinterpret_cast<void(GL_APIENTRYP)(GLushort, GLushort, GLushort)>(getProcAddress("glColor3us"));
	assert(glColor3us_ != nullptr);
	return glColor3us_(red, green, blue);
}
void glColor3usv(GLushort const  * v) {
	static const auto glColor3usv_ = reinterpret_cast<void(GL_APIENTRYP)(GLushort const  *)>(getProcAddress("glColor3usv"));
	assert(glColor3usv_ != nullptr);
	return glColor3usv_(v);
}
void glColor4b(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha) {
	static const auto glColor4b_ = reinterpret_cast<void(GL_APIENTRYP)(GLbyte, GLbyte, GLbyte, GLbyte)>(getProcAddress("glColor4b"));
	assert(glColor4b_ != nullptr);
	return glColor4b_(red, green, blue, alpha);
}
void glColor4bv(GLbyte const  * v) {
	static const auto glColor4bv_ = reinterpret_cast<void(GL_APIENTRYP)(GLbyte const  *)>(getProcAddress("glColor4bv"));
	assert(glColor4bv_ != nullptr);
	return glColor4bv_(v);
}
void glColor4d(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha) {
	static const auto glColor4d_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble, GLdouble, GLdouble, GLdouble)>(getProcAddress("glColor4d"));
	assert(glColor4d_ != nullptr);
	return glColor4d_(red, green, blue, alpha);
}
void glColor4dv(GLdouble const  * v) {
	static const auto glColor4dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble const  *)>(getProcAddress("glColor4dv"));
	assert(glColor4dv_ != nullptr);
	return glColor4dv_(v);
}
void glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
	static const auto glColor4f_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat, GLfloat, GLfloat, GLfloat)>(getProcAddress("glColor4f"));
	assert(glColor4f_ != nullptr);
	return glColor4f_(red, green, blue, alpha);
}
void glColor4fv(GLfloat const  * v) {
	static const auto glColor4fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat const  *)>(getProcAddress("glColor4fv"));
	assert(glColor4fv_ != nullptr);
	return glColor4fv_(v);
}
void glColor4i(GLint red, GLint green, GLint blue, GLint alpha) {
	static const auto glColor4i_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLint, GLint, GLint)>(getProcAddress("glColor4i"));
	assert(glColor4i_ != nullptr);
	return glColor4i_(red, green, blue, alpha);
}
void glColor4iv(GLint const  * v) {
	static const auto glColor4iv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint const  *)>(getProcAddress("glColor4iv"));
	assert(glColor4iv_ != nullptr);
	return glColor4iv_(v);
}
void glColor4s(GLshort red, GLshort green, GLshort blue, GLshort alpha) {
	static const auto glColor4s_ = reinterpret_cast<void(GL_APIENTRYP)(GLshort, GLshort, GLshort, GLshort)>(getProcAddress("glColor4s"));
	assert(glColor4s_ != nullptr);
	return glColor4s_(red, green, blue, alpha);
}
void glColor4sv(GLshort const  * v) {
	static const auto glColor4sv_ = reinterpret_cast<void(GL_APIENTRYP)(GLshort const  *)>(getProcAddress("glColor4sv"));
	assert(glColor4sv_ != nullptr);
	return glColor4sv_(v);
}
void glColor4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha) {
	static const auto glColor4ub_ = reinterpret_cast<void(GL_APIENTRYP)(GLubyte, GLubyte, GLubyte, GLubyte)>(getProcAddress("glColor4ub"));
	assert(glColor4ub_ != nullptr);
	return glColor4ub_(red, green, blue, alpha);
}
void glColor4ubv(GLubyte const  * v) {
	static const auto glColor4ubv_ = reinterpret_cast<void(GL_APIENTRYP)(GLubyte const  *)>(getProcAddress("glColor4ubv"));
	assert(glColor4ubv_ != nullptr);
	return glColor4ubv_(v);
}
void glColor4ui(GLuint red, GLuint green, GLuint blue, GLuint alpha) {
	static const auto glColor4ui_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLuint, GLuint)>(getProcAddress("glColor4ui"));
	assert(glColor4ui_ != nullptr);
	return glColor4ui_(red, green, blue, alpha);
}
void glColor4uiv(GLuint const  * v) {
	static const auto glColor4uiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint const  *)>(getProcAddress("glColor4uiv"));
	assert(glColor4uiv_ != nullptr);
	return glColor4uiv_(v);
}
void glColor4us(GLushort red, GLushort green, GLushort blue, GLushort alpha) {
	static const auto glColor4us_ = reinterpret_cast<void(GL_APIENTRYP)(GLushort, GLushort, GLushort, GLushort)>(getProcAddress("glColor4us"));
	assert(glColor4us_ != nullptr);
	return glColor4us_(red, green, blue, alpha);
}
void glColor4usv(GLushort const  * v) {
	static const auto glColor4usv_ = reinterpret_cast<void(GL_APIENTRYP)(GLushort const  *)>(getProcAddress("glColor4usv"));
	assert(glColor4usv_ != nullptr);
	return glColor4usv_(v);
}
void glEdgeFlag(GLboolean flag) {
	static const auto glEdgeFlag_ = reinterpret_cast<void(GL_APIENTRYP)(GLboolean)>(getProcAddress("glEdgeFlag"));
	assert(glEdgeFlag_ != nullptr);
	return glEdgeFlag_(flag);
}
void glEdgeFlagv(GLboolean const  * flag) {
	static const auto glEdgeFlagv_ = reinterpret_cast<void(GL_APIENTRYP)(GLboolean const  *)>(getProcAddress("glEdgeFlagv"));
	assert(glEdgeFlagv_ != nullptr);
	return glEdgeFlagv_(flag);
}
void glEnd() {
	static const auto glEnd_ = reinterpret_cast<void(GL_APIENTRYP)()>(getProcAddress("glEnd"));
	assert(glEnd_ != nullptr);
	return glEnd_();
}
void glIndexd(GLdouble c) {
	static const auto glIndexd_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble)>(getProcAddress("glIndexd"));
	assert(glIndexd_ != nullptr);
	return glIndexd_(c);
}
void glIndexdv(GLdouble const  * c) {
	static const auto glIndexdv_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble const  *)>(getProcAddress("glIndexdv"));
	assert(glIndexdv_ != nullptr);
	return glIndexdv_(c);
}
void glIndexf(GLfloat c) {
	static const auto glIndexf_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat)>(getProcAddress("glIndexf"));
	assert(glIndexf_ != nullptr);
	return glIndexf_(c);
}
void glIndexfv(GLfloat const  * c) {
	static const auto glIndexfv_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat const  *)>(getProcAddress("glIndexfv"));
	assert(glIndexfv_ != nullptr);
	return glIndexfv_(c);
}
void glIndexi(GLint c) {
	static const auto glIndexi_ = reinterpret_cast<void(GL_APIENTRYP)(GLint)>(getProcAddress("glIndexi"));
	assert(glIndexi_ != nullptr);
	return glIndexi_(c);
}
void glIndexiv(GLint const  * c) {
	static const auto glIndexiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint const  *)>(getProcAddress("glIndexiv"));
	assert(glIndexiv_ != nullptr);
	return glIndexiv_(c);
}
void glIndexs(GLshort c) {
	static const auto glIndexs_ = reinterpret_cast<void(GL_APIENTRYP)(GLshort)>(getProcAddress("glIndexs"));
	assert(glIndexs_ != nullptr);
	return glIndexs_(c);
}
void glIndexsv(GLshort const  * c) {
	static const auto glIndexsv_ = reinterpret_cast<void(GL_APIENTRYP)(GLshort const  *)>(getProcAddress("glIndexsv"));
	assert(glIndexsv_ != nullptr);
	return glIndexsv_(c);
}
void glNormal3b(GLbyte nx, GLbyte ny, GLbyte nz) {
	static const auto glNormal3b_ = reinterpret_cast<void(GL_APIENTRYP)(GLbyte, GLbyte, GLbyte)>(getProcAddress("glNormal3b"));
	assert(glNormal3b_ != nullptr);
	return glNormal3b_(nx, ny, nz);
}
void glNormal3bv(GLbyte const  * v) {
	static const auto glNormal3bv_ = reinterpret_cast<void(GL_APIENTRYP)(GLbyte const  *)>(getProcAddress("glNormal3bv"));
	assert(glNormal3bv_ != nullptr);
	return glNormal3bv_(v);
}
void glNormal3d(GLdouble nx, GLdouble ny, GLdouble nz) {
	static const auto glNormal3d_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble, GLdouble, GLdouble)>(getProcAddress("glNormal3d"));
	assert(glNormal3d_ != nullptr);
	return glNormal3d_(nx, ny, nz);
}
void glNormal3dv(GLdouble const  * v) {
	static const auto glNormal3dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble const  *)>(getProcAddress("glNormal3dv"));
	assert(glNormal3dv_ != nullptr);
	return glNormal3dv_(v);
}
void glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz) {
	static const auto glNormal3f_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat, GLfloat, GLfloat)>(getProcAddress("glNormal3f"));
	assert(glNormal3f_ != nullptr);
	return glNormal3f_(nx, ny, nz);
}
void glNormal3fv(GLfloat const  * v) {
	static const auto glNormal3fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat const  *)>(getProcAddress("glNormal3fv"));
	assert(glNormal3fv_ != nullptr);
	return glNormal3fv_(v);
}
void glNormal3i(GLint nx, GLint ny, GLint nz) {
	static const auto glNormal3i_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLint, GLint)>(getProcAddress("glNormal3i"));
	assert(glNormal3i_ != nullptr);
	return glNormal3i_(nx, ny, nz);
}
void glNormal3iv(GLint const  * v) {
	static const auto glNormal3iv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint const  *)>(getProcAddress("glNormal3iv"));
	assert(glNormal3iv_ != nullptr);
	return glNormal3iv_(v);
}
void glNormal3s(GLshort nx, GLshort ny, GLshort nz) {
	static const auto glNormal3s_ = reinterpret_cast<void(GL_APIENTRYP)(GLshort, GLshort, GLshort)>(getProcAddress("glNormal3s"));
	assert(glNormal3s_ != nullptr);
	return glNormal3s_(nx, ny, nz);
}
void glNormal3sv(GLshort const  * v) {
	static const auto glNormal3sv_ = reinterpret_cast<void(GL_APIENTRYP)(GLshort const  *)>(getProcAddress("glNormal3sv"));
	assert(glNormal3sv_ != nullptr);
	return glNormal3sv_(v);
}
void glRasterPos2d(GLdouble x, GLdouble y) {
	static const auto glRasterPos2d_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble, GLdouble)>(getProcAddress("glRasterPos2d"));
	assert(glRasterPos2d_ != nullptr);
	return glRasterPos2d_(x, y);
}
void glRasterPos2dv(GLdouble const  * v) {
	static const auto glRasterPos2dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble const  *)>(getProcAddress("glRasterPos2dv"));
	assert(glRasterPos2dv_ != nullptr);
	return glRasterPos2dv_(v);
}
void glRasterPos2f(GLfloat x, GLfloat y) {
	static const auto glRasterPos2f_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat, GLfloat)>(getProcAddress("glRasterPos2f"));
	assert(glRasterPos2f_ != nullptr);
	return glRasterPos2f_(x, y);
}
void glRasterPos2fv(GLfloat const  * v) {
	static const auto glRasterPos2fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat const  *)>(getProcAddress("glRasterPos2fv"));
	assert(glRasterPos2fv_ != nullptr);
	return glRasterPos2fv_(v);
}
void glRasterPos2i(GLint x, GLint y) {
	static const auto glRasterPos2i_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLint)>(getProcAddress("glRasterPos2i"));
	assert(glRasterPos2i_ != nullptr);
	return glRasterPos2i_(x, y);
}
void glRasterPos2iv(GLint const  * v) {
	static const auto glRasterPos2iv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint const  *)>(getProcAddress("glRasterPos2iv"));
	assert(glRasterPos2iv_ != nullptr);
	return glRasterPos2iv_(v);
}
void glRasterPos2s(GLshort x, GLshort y) {
	static const auto glRasterPos2s_ = reinterpret_cast<void(GL_APIENTRYP)(GLshort, GLshort)>(getProcAddress("glRasterPos2s"));
	assert(glRasterPos2s_ != nullptr);
	return glRasterPos2s_(x, y);
}
void glRasterPos2sv(GLshort const  * v) {
	static const auto glRasterPos2sv_ = reinterpret_cast<void(GL_APIENTRYP)(GLshort const  *)>(getProcAddress("glRasterPos2sv"));
	assert(glRasterPos2sv_ != nullptr);
	return glRasterPos2sv_(v);
}
void glRasterPos3d(GLdouble x, GLdouble y, GLdouble z) {
	static const auto glRasterPos3d_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble, GLdouble, GLdouble)>(getProcAddress("glRasterPos3d"));
	assert(glRasterPos3d_ != nullptr);
	return glRasterPos3d_(x, y, z);
}
void glRasterPos3dv(GLdouble const  * v) {
	static const auto glRasterPos3dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble const  *)>(getProcAddress("glRasterPos3dv"));
	assert(glRasterPos3dv_ != nullptr);
	return glRasterPos3dv_(v);
}
void glRasterPos3f(GLfloat x, GLfloat y, GLfloat z) {
	static const auto glRasterPos3f_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat, GLfloat, GLfloat)>(getProcAddress("glRasterPos3f"));
	assert(glRasterPos3f_ != nullptr);
	return glRasterPos3f_(x, y, z);
}
void glRasterPos3fv(GLfloat const  * v) {
	static const auto glRasterPos3fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat const  *)>(getProcAddress("glRasterPos3fv"));
	assert(glRasterPos3fv_ != nullptr);
	return glRasterPos3fv_(v);
}
void glRasterPos3i(GLint x, GLint y, GLint z) {
	static const auto glRasterPos3i_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLint, GLint)>(getProcAddress("glRasterPos3i"));
	assert(glRasterPos3i_ != nullptr);
	return glRasterPos3i_(x, y, z);
}
void glRasterPos3iv(GLint const  * v) {
	static const auto glRasterPos3iv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint const  *)>(getProcAddress("glRasterPos3iv"));
	assert(glRasterPos3iv_ != nullptr);
	return glRasterPos3iv_(v);
}
void glRasterPos3s(GLshort x, GLshort y, GLshort z) {
	static const auto glRasterPos3s_ = reinterpret_cast<void(GL_APIENTRYP)(GLshort, GLshort, GLshort)>(getProcAddress("glRasterPos3s"));
	assert(glRasterPos3s_ != nullptr);
	return glRasterPos3s_(x, y, z);
}
void glRasterPos3sv(GLshort const  * v) {
	static const auto glRasterPos3sv_ = reinterpret_cast<void(GL_APIENTRYP)(GLshort const  *)>(getProcAddress("glRasterPos3sv"));
	assert(glRasterPos3sv_ != nullptr);
	return glRasterPos3sv_(v);
}
void glRasterPos4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
	static const auto glRasterPos4d_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble, GLdouble, GLdouble, GLdouble)>(getProcAddress("glRasterPos4d"));
	assert(glRasterPos4d_ != nullptr);
	return glRasterPos4d_(x, y, z, w);
}
void glRasterPos4dv(GLdouble const  * v) {
	static const auto glRasterPos4dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble const  *)>(getProcAddress("glRasterPos4dv"));
	assert(glRasterPos4dv_ != nullptr);
	return glRasterPos4dv_(v);
}
void glRasterPos4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
	static const auto glRasterPos4f_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat, GLfloat, GLfloat, GLfloat)>(getProcAddress("glRasterPos4f"));
	assert(glRasterPos4f_ != nullptr);
	return glRasterPos4f_(x, y, z, w);
}
void glRasterPos4fv(GLfloat const  * v) {
	static const auto glRasterPos4fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat const  *)>(getProcAddress("glRasterPos4fv"));
	assert(glRasterPos4fv_ != nullptr);
	return glRasterPos4fv_(v);
}
void glRasterPos4i(GLint x, GLint y, GLint z, GLint w) {
	static const auto glRasterPos4i_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLint, GLint, GLint)>(getProcAddress("glRasterPos4i"));
	assert(glRasterPos4i_ != nullptr);
	return glRasterPos4i_(x, y, z, w);
}
void glRasterPos4iv(GLint const  * v) {
	static const auto glRasterPos4iv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint const  *)>(getProcAddress("glRasterPos4iv"));
	assert(glRasterPos4iv_ != nullptr);
	return glRasterPos4iv_(v);
}
void glRasterPos4s(GLshort x, GLshort y, GLshort z, GLshort w) {
	static const auto glRasterPos4s_ = reinterpret_cast<void(GL_APIENTRYP)(GLshort, GLshort, GLshort, GLshort)>(getProcAddress("glRasterPos4s"));
	assert(glRasterPos4s_ != nullptr);
	return glRasterPos4s_(x, y, z, w);
}
void glRasterPos4sv(GLshort const  * v) {
	static const auto glRasterPos4sv_ = reinterpret_cast<void(GL_APIENTRYP)(GLshort const  *)>(getProcAddress("glRasterPos4sv"));
	assert(glRasterPos4sv_ != nullptr);
	return glRasterPos4sv_(v);
}
void glRectd(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2) {
	static const auto glRectd_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble, GLdouble, GLdouble, GLdouble)>(getProcAddress("glRectd"));
	assert(glRectd_ != nullptr);
	return glRectd_(x1, y1, x2, y2);
}
void glRectdv(GLdouble const  * v1, GLdouble const  * v2) {
	static const auto glRectdv_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble const  *, GLdouble const  *)>(getProcAddress("glRectdv"));
	assert(glRectdv_ != nullptr);
	return glRectdv_(v1, v2);
}
void glRectf(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2) {
	static const auto glRectf_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat, GLfloat, GLfloat, GLfloat)>(getProcAddress("glRectf"));
	assert(glRectf_ != nullptr);
	return glRectf_(x1, y1, x2, y2);
}
void glRectfv(GLfloat const  * v1, GLfloat const  * v2) {
	static const auto glRectfv_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat const  *, GLfloat const  *)>(getProcAddress("glRectfv"));
	assert(glRectfv_ != nullptr);
	return glRectfv_(v1, v2);
}
void glRecti(GLint x1, GLint y1, GLint x2, GLint y2) {
	static const auto glRecti_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLint, GLint, GLint)>(getProcAddress("glRecti"));
	assert(glRecti_ != nullptr);
	return glRecti_(x1, y1, x2, y2);
}
void glRectiv(GLint const  * v1, GLint const  * v2) {
	static const auto glRectiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint const  *, GLint const  *)>(getProcAddress("glRectiv"));
	assert(glRectiv_ != nullptr);
	return glRectiv_(v1, v2);
}
void glRects(GLshort x1, GLshort y1, GLshort x2, GLshort y2) {
	static const auto glRects_ = reinterpret_cast<void(GL_APIENTRYP)(GLshort, GLshort, GLshort, GLshort)>(getProcAddress("glRects"));
	assert(glRects_ != nullptr);
	return glRects_(x1, y1, x2, y2);
}
void glRectsv(GLshort const  * v1, GLshort const  * v2) {
	static const auto glRectsv_ = reinterpret_cast<void(GL_APIENTRYP)(GLshort const  *, GLshort const  *)>(getProcAddress("glRectsv"));
	assert(glRectsv_ != nullptr);
	return glRectsv_(v1, v2);
}
void glTexCoord1d(GLdouble s) {
	static const auto glTexCoord1d_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble)>(getProcAddress("glTexCoord1d"));
	assert(glTexCoord1d_ != nullptr);
	return glTexCoord1d_(s);
}
void glTexCoord1dv(GLdouble const  * v) {
	static const auto glTexCoord1dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble const  *)>(getProcAddress("glTexCoord1dv"));
	assert(glTexCoord1dv_ != nullptr);
	return glTexCoord1dv_(v);
}
void glTexCoord1f(GLfloat s) {
	static const auto glTexCoord1f_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat)>(getProcAddress("glTexCoord1f"));
	assert(glTexCoord1f_ != nullptr);
	return glTexCoord1f_(s);
}
void glTexCoord1fv(GLfloat const  * v) {
	static const auto glTexCoord1fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat const  *)>(getProcAddress("glTexCoord1fv"));
	assert(glTexCoord1fv_ != nullptr);
	return glTexCoord1fv_(v);
}
void glTexCoord1i(GLint s) {
	static const auto glTexCoord1i_ = reinterpret_cast<void(GL_APIENTRYP)(GLint)>(getProcAddress("glTexCoord1i"));
	assert(glTexCoord1i_ != nullptr);
	return glTexCoord1i_(s);
}
void glTexCoord1iv(GLint const  * v) {
	static const auto glTexCoord1iv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint const  *)>(getProcAddress("glTexCoord1iv"));
	assert(glTexCoord1iv_ != nullptr);
	return glTexCoord1iv_(v);
}
void glTexCoord1s(GLshort s) {
	static const auto glTexCoord1s_ = reinterpret_cast<void(GL_APIENTRYP)(GLshort)>(getProcAddress("glTexCoord1s"));
	assert(glTexCoord1s_ != nullptr);
	return glTexCoord1s_(s);
}
void glTexCoord1sv(GLshort const  * v) {
	static const auto glTexCoord1sv_ = reinterpret_cast<void(GL_APIENTRYP)(GLshort const  *)>(getProcAddress("glTexCoord1sv"));
	assert(glTexCoord1sv_ != nullptr);
	return glTexCoord1sv_(v);
}
void glTexCoord2d(GLdouble s, GLdouble t) {
	static const auto glTexCoord2d_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble, GLdouble)>(getProcAddress("glTexCoord2d"));
	assert(glTexCoord2d_ != nullptr);
	return glTexCoord2d_(s, t);
}
void glTexCoord2dv(GLdouble const  * v) {
	static const auto glTexCoord2dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble const  *)>(getProcAddress("glTexCoord2dv"));
	assert(glTexCoord2dv_ != nullptr);
	return glTexCoord2dv_(v);
}
void glTexCoord2f(GLfloat s, GLfloat t) {
	static const auto glTexCoord2f_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat, GLfloat)>(getProcAddress("glTexCoord2f"));
	assert(glTexCoord2f_ != nullptr);
	return glTexCoord2f_(s, t);
}
void glTexCoord2fv(GLfloat const  * v) {
	static const auto glTexCoord2fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat const  *)>(getProcAddress("glTexCoord2fv"));
	assert(glTexCoord2fv_ != nullptr);
	return glTexCoord2fv_(v);
}
void glTexCoord2i(GLint s, GLint t) {
	static const auto glTexCoord2i_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLint)>(getProcAddress("glTexCoord2i"));
	assert(glTexCoord2i_ != nullptr);
	return glTexCoord2i_(s, t);
}
void glTexCoord2iv(GLint const  * v) {
	static const auto glTexCoord2iv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint const  *)>(getProcAddress("glTexCoord2iv"));
	assert(glTexCoord2iv_ != nullptr);
	return glTexCoord2iv_(v);
}
void glTexCoord2s(GLshort s, GLshort t) {
	static const auto glTexCoord2s_ = reinterpret_cast<void(GL_APIENTRYP)(GLshort, GLshort)>(getProcAddress("glTexCoord2s"));
	assert(glTexCoord2s_ != nullptr);
	return glTexCoord2s_(s, t);
}
void glTexCoord2sv(GLshort const  * v) {
	static const auto glTexCoord2sv_ = reinterpret_cast<void(GL_APIENTRYP)(GLshort const  *)>(getProcAddress("glTexCoord2sv"));
	assert(glTexCoord2sv_ != nullptr);
	return glTexCoord2sv_(v);
}
void glTexCoord3d(GLdouble s, GLdouble t, GLdouble r) {
	static const auto glTexCoord3d_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble, GLdouble, GLdouble)>(getProcAddress("glTexCoord3d"));
	assert(glTexCoord3d_ != nullptr);
	return glTexCoord3d_(s, t, r);
}
void glTexCoord3dv(GLdouble const  * v) {
	static const auto glTexCoord3dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble const  *)>(getProcAddress("glTexCoord3dv"));
	assert(glTexCoord3dv_ != nullptr);
	return glTexCoord3dv_(v);
}
void glTexCoord3f(GLfloat s, GLfloat t, GLfloat r) {
	static const auto glTexCoord3f_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat, GLfloat, GLfloat)>(getProcAddress("glTexCoord3f"));
	assert(glTexCoord3f_ != nullptr);
	return glTexCoord3f_(s, t, r);
}
void glTexCoord3fv(GLfloat const  * v) {
	static const auto glTexCoord3fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat const  *)>(getProcAddress("glTexCoord3fv"));
	assert(glTexCoord3fv_ != nullptr);
	return glTexCoord3fv_(v);
}
void glTexCoord3i(GLint s, GLint t, GLint r) {
	static const auto glTexCoord3i_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLint, GLint)>(getProcAddress("glTexCoord3i"));
	assert(glTexCoord3i_ != nullptr);
	return glTexCoord3i_(s, t, r);
}
void glTexCoord3iv(GLint const  * v) {
	static const auto glTexCoord3iv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint const  *)>(getProcAddress("glTexCoord3iv"));
	assert(glTexCoord3iv_ != nullptr);
	return glTexCoord3iv_(v);
}
void glTexCoord3s(GLshort s, GLshort t, GLshort r) {
	static const auto glTexCoord3s_ = reinterpret_cast<void(GL_APIENTRYP)(GLshort, GLshort, GLshort)>(getProcAddress("glTexCoord3s"));
	assert(glTexCoord3s_ != nullptr);
	return glTexCoord3s_(s, t, r);
}
void glTexCoord3sv(GLshort const  * v) {
	static const auto glTexCoord3sv_ = reinterpret_cast<void(GL_APIENTRYP)(GLshort const  *)>(getProcAddress("glTexCoord3sv"));
	assert(glTexCoord3sv_ != nullptr);
	return glTexCoord3sv_(v);
}
void glTexCoord4d(GLdouble s, GLdouble t, GLdouble r, GLdouble q) {
	static const auto glTexCoord4d_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble, GLdouble, GLdouble, GLdouble)>(getProcAddress("glTexCoord4d"));
	assert(glTexCoord4d_ != nullptr);
	return glTexCoord4d_(s, t, r, q);
}
void glTexCoord4dv(GLdouble const  * v) {
	static const auto glTexCoord4dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble const  *)>(getProcAddress("glTexCoord4dv"));
	assert(glTexCoord4dv_ != nullptr);
	return glTexCoord4dv_(v);
}
void glTexCoord4f(GLfloat s, GLfloat t, GLfloat r, GLfloat q) {
	static const auto glTexCoord4f_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat, GLfloat, GLfloat, GLfloat)>(getProcAddress("glTexCoord4f"));
	assert(glTexCoord4f_ != nullptr);
	return glTexCoord4f_(s, t, r, q);
}
void glTexCoord4fv(GLfloat const  * v) {
	static const auto glTexCoord4fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat const  *)>(getProcAddress("glTexCoord4fv"));
	assert(glTexCoord4fv_ != nullptr);
	return glTexCoord4fv_(v);
}
void glTexCoord4i(GLint s, GLint t, GLint r, GLint q) {
	static const auto glTexCoord4i_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLint, GLint, GLint)>(getProcAddress("glTexCoord4i"));
	assert(glTexCoord4i_ != nullptr);
	return glTexCoord4i_(s, t, r, q);
}
void glTexCoord4iv(GLint const  * v) {
	static const auto glTexCoord4iv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint const  *)>(getProcAddress("glTexCoord4iv"));
	assert(glTexCoord4iv_ != nullptr);
	return glTexCoord4iv_(v);
}
void glTexCoord4s(GLshort s, GLshort t, GLshort r, GLshort q) {
	static const auto glTexCoord4s_ = reinterpret_cast<void(GL_APIENTRYP)(GLshort, GLshort, GLshort, GLshort)>(getProcAddress("glTexCoord4s"));
	assert(glTexCoord4s_ != nullptr);
	return glTexCoord4s_(s, t, r, q);
}
void glTexCoord4sv(GLshort const  * v) {
	static const auto glTexCoord4sv_ = reinterpret_cast<void(GL_APIENTRYP)(GLshort const  *)>(getProcAddress("glTexCoord4sv"));
	assert(glTexCoord4sv_ != nullptr);
	return glTexCoord4sv_(v);
}
void glVertex2d(GLdouble x, GLdouble y) {
	static const auto glVertex2d_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble, GLdouble)>(getProcAddress("glVertex2d"));
	assert(glVertex2d_ != nullptr);
	return glVertex2d_(x, y);
}
void glVertex2dv(GLdouble const  * v) {
	static const auto glVertex2dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble const  *)>(getProcAddress("glVertex2dv"));
	assert(glVertex2dv_ != nullptr);
	return glVertex2dv_(v);
}
void glVertex2f(GLfloat x, GLfloat y) {
	static const auto glVertex2f_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat, GLfloat)>(getProcAddress("glVertex2f"));
	assert(glVertex2f_ != nullptr);
	return glVertex2f_(x, y);
}
void glVertex2fv(GLfloat const  * v) {
	static const auto glVertex2fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat const  *)>(getProcAddress("glVertex2fv"));
	assert(glVertex2fv_ != nullptr);
	return glVertex2fv_(v);
}
void glVertex2i(GLint x, GLint y) {
	static const auto glVertex2i_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLint)>(getProcAddress("glVertex2i"));
	assert(glVertex2i_ != nullptr);
	return glVertex2i_(x, y);
}
void glVertex2iv(GLint const  * v) {
	static const auto glVertex2iv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint const  *)>(getProcAddress("glVertex2iv"));
	assert(glVertex2iv_ != nullptr);
	return glVertex2iv_(v);
}
void glVertex2s(GLshort x, GLshort y) {
	static const auto glVertex2s_ = reinterpret_cast<void(GL_APIENTRYP)(GLshort, GLshort)>(getProcAddress("glVertex2s"));
	assert(glVertex2s_ != nullptr);
	return glVertex2s_(x, y);
}
void glVertex2sv(GLshort const  * v) {
	static const auto glVertex2sv_ = reinterpret_cast<void(GL_APIENTRYP)(GLshort const  *)>(getProcAddress("glVertex2sv"));
	assert(glVertex2sv_ != nullptr);
	return glVertex2sv_(v);
}
void glVertex3d(GLdouble x, GLdouble y, GLdouble z) {
	static const auto glVertex3d_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble, GLdouble, GLdouble)>(getProcAddress("glVertex3d"));
	assert(glVertex3d_ != nullptr);
	return glVertex3d_(x, y, z);
}
void glVertex3dv(GLdouble const  * v) {
	static const auto glVertex3dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble const  *)>(getProcAddress("glVertex3dv"));
	assert(glVertex3dv_ != nullptr);
	return glVertex3dv_(v);
}
void glVertex3f(GLfloat x, GLfloat y, GLfloat z) {
	static const auto glVertex3f_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat, GLfloat, GLfloat)>(getProcAddress("glVertex3f"));
	assert(glVertex3f_ != nullptr);
	return glVertex3f_(x, y, z);
}
void glVertex3fv(GLfloat const  * v) {
	static const auto glVertex3fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat const  *)>(getProcAddress("glVertex3fv"));
	assert(glVertex3fv_ != nullptr);
	return glVertex3fv_(v);
}
void glVertex3i(GLint x, GLint y, GLint z) {
	static const auto glVertex3i_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLint, GLint)>(getProcAddress("glVertex3i"));
	assert(glVertex3i_ != nullptr);
	return glVertex3i_(x, y, z);
}
void glVertex3iv(GLint const  * v) {
	static const auto glVertex3iv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint const  *)>(getProcAddress("glVertex3iv"));
	assert(glVertex3iv_ != nullptr);
	return glVertex3iv_(v);
}
void glVertex3s(GLshort x, GLshort y, GLshort z) {
	static const auto glVertex3s_ = reinterpret_cast<void(GL_APIENTRYP)(GLshort, GLshort, GLshort)>(getProcAddress("glVertex3s"));
	assert(glVertex3s_ != nullptr);
	return glVertex3s_(x, y, z);
}
void glVertex3sv(GLshort const  * v) {
	static const auto glVertex3sv_ = reinterpret_cast<void(GL_APIENTRYP)(GLshort const  *)>(getProcAddress("glVertex3sv"));
	assert(glVertex3sv_ != nullptr);
	return glVertex3sv_(v);
}
void glVertex4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
	static const auto glVertex4d_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble, GLdouble, GLdouble, GLdouble)>(getProcAddress("glVertex4d"));
	assert(glVertex4d_ != nullptr);
	return glVertex4d_(x, y, z, w);
}
void glVertex4dv(GLdouble const  * v) {
	static const auto glVertex4dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble const  *)>(getProcAddress("glVertex4dv"));
	assert(glVertex4dv_ != nullptr);
	return glVertex4dv_(v);
}
void glVertex4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
	static const auto glVertex4f_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat, GLfloat, GLfloat, GLfloat)>(getProcAddress("glVertex4f"));
	assert(glVertex4f_ != nullptr);
	return glVertex4f_(x, y, z, w);
}
void glVertex4fv(GLfloat const  * v) {
	static const auto glVertex4fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat const  *)>(getProcAddress("glVertex4fv"));
	assert(glVertex4fv_ != nullptr);
	return glVertex4fv_(v);
}
void glVertex4i(GLint x, GLint y, GLint z, GLint w) {
	static const auto glVertex4i_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLint, GLint, GLint)>(getProcAddress("glVertex4i"));
	assert(glVertex4i_ != nullptr);
	return glVertex4i_(x, y, z, w);
}
void glVertex4iv(GLint const  * v) {
	static const auto glVertex4iv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint const  *)>(getProcAddress("glVertex4iv"));
	assert(glVertex4iv_ != nullptr);
	return glVertex4iv_(v);
}
void glVertex4s(GLshort x, GLshort y, GLshort z, GLshort w) {
	static const auto glVertex4s_ = reinterpret_cast<void(GL_APIENTRYP)(GLshort, GLshort, GLshort, GLshort)>(getProcAddress("glVertex4s"));
	assert(glVertex4s_ != nullptr);
	return glVertex4s_(x, y, z, w);
}
void glVertex4sv(GLshort const  * v) {
	static const auto glVertex4sv_ = reinterpret_cast<void(GL_APIENTRYP)(GLshort const  *)>(getProcAddress("glVertex4sv"));
	assert(glVertex4sv_ != nullptr);
	return glVertex4sv_(v);
}
void glClipPlane(GLenum plane, GLdouble const  * equation) {
	static const auto glClipPlane_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLdouble const  *)>(getProcAddress("glClipPlane"));
	assert(glClipPlane_ != nullptr);
	return glClipPlane_(plane, equation);
}
void glColorMaterial(GLenum face, GLenum mode) {
	static const auto glColorMaterial_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum)>(getProcAddress("glColorMaterial"));
	assert(glColorMaterial_ != nullptr);
	return glColorMaterial_(face, mode);
}
void glFogf(GLenum pname, GLfloat param) {
	static const auto glFogf_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfloat)>(getProcAddress("glFogf"));
	assert(glFogf_ != nullptr);
	return glFogf_(pname, param);
}
void glFogfv(GLenum pname, GLfloat const  * params) {
	static const auto glFogfv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfloat const  *)>(getProcAddress("glFogfv"));
	assert(glFogfv_ != nullptr);
	return glFogfv_(pname, params);
}
void glFogi(GLenum pname, GLint param) {
	static const auto glFogi_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint)>(getProcAddress("glFogi"));
	assert(glFogi_ != nullptr);
	return glFogi_(pname, param);
}
void glFogiv(GLenum pname, GLint const  * params) {
	static const auto glFogiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint const  *)>(getProcAddress("glFogiv"));
	assert(glFogiv_ != nullptr);
	return glFogiv_(pname, params);
}
void glLightf(GLenum light, GLenum pname, GLfloat param) {
	static const auto glLightf_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfloat)>(getProcAddress("glLightf"));
	assert(glLightf_ != nullptr);
	return glLightf_(light, pname, param);
}
void glLightfv(GLenum light, GLenum pname, GLfloat const  * params) {
	static const auto glLightfv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfloat const  *)>(getProcAddress("glLightfv"));
	assert(glLightfv_ != nullptr);
	return glLightfv_(light, pname, params);
}
void glLighti(GLenum light, GLenum pname, GLint param) {
	static const auto glLighti_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint)>(getProcAddress("glLighti"));
	assert(glLighti_ != nullptr);
	return glLighti_(light, pname, param);
}
void glLightiv(GLenum light, GLenum pname, GLint const  * params) {
	static const auto glLightiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint const  *)>(getProcAddress("glLightiv"));
	assert(glLightiv_ != nullptr);
	return glLightiv_(light, pname, params);
}
void glLightModelf(GLenum pname, GLfloat param) {
	static const auto glLightModelf_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfloat)>(getProcAddress("glLightModelf"));
	assert(glLightModelf_ != nullptr);
	return glLightModelf_(pname, param);
}
void glLightModelfv(GLenum pname, GLfloat const  * params) {
	static const auto glLightModelfv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfloat const  *)>(getProcAddress("glLightModelfv"));
	assert(glLightModelfv_ != nullptr);
	return glLightModelfv_(pname, params);
}
void glLightModeli(GLenum pname, GLint param) {
	static const auto glLightModeli_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint)>(getProcAddress("glLightModeli"));
	assert(glLightModeli_ != nullptr);
	return glLightModeli_(pname, param);
}
void glLightModeliv(GLenum pname, GLint const  * params) {
	static const auto glLightModeliv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint const  *)>(getProcAddress("glLightModeliv"));
	assert(glLightModeliv_ != nullptr);
	return glLightModeliv_(pname, params);
}
void glLineStipple(GLint factor, GLushort pattern) {
	static const auto glLineStipple_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLushort)>(getProcAddress("glLineStipple"));
	assert(glLineStipple_ != nullptr);
	return glLineStipple_(factor, pattern);
}
void glMaterialf(GLenum face, GLenum pname, GLfloat param) {
	static const auto glMaterialf_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfloat)>(getProcAddress("glMaterialf"));
	assert(glMaterialf_ != nullptr);
	return glMaterialf_(face, pname, param);
}
void glMaterialfv(GLenum face, GLenum pname, GLfloat const  * params) {
	static const auto glMaterialfv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfloat const  *)>(getProcAddress("glMaterialfv"));
	assert(glMaterialfv_ != nullptr);
	return glMaterialfv_(face, pname, params);
}
void glMateriali(GLenum face, GLenum pname, GLint param) {
	static const auto glMateriali_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint)>(getProcAddress("glMateriali"));
	assert(glMateriali_ != nullptr);
	return glMateriali_(face, pname, param);
}
void glMaterialiv(GLenum face, GLenum pname, GLint const  * params) {
	static const auto glMaterialiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint const  *)>(getProcAddress("glMaterialiv"));
	assert(glMaterialiv_ != nullptr);
	return glMaterialiv_(face, pname, params);
}
void glPolygonStipple(GLubyte const  * mask) {
	static const auto glPolygonStipple_ = reinterpret_cast<void(GL_APIENTRYP)(GLubyte const  *)>(getProcAddress("glPolygonStipple"));
	assert(glPolygonStipple_ != nullptr);
	return glPolygonStipple_(mask);
}
void glShadeModel(GLenum mode) {
	static const auto glShadeModel_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glShadeModel"));
	assert(glShadeModel_ != nullptr);
	return glShadeModel_(mode);
}
void glTexEnvf(GLenum target, GLenum pname, GLfloat param) {
	static const auto glTexEnvf_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfloat)>(getProcAddress("glTexEnvf"));
	assert(glTexEnvf_ != nullptr);
	return glTexEnvf_(target, pname, param);
}
void glTexEnvfv(GLenum target, GLenum pname, GLfloat const  * params) {
	static const auto glTexEnvfv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfloat const  *)>(getProcAddress("glTexEnvfv"));
	assert(glTexEnvfv_ != nullptr);
	return glTexEnvfv_(target, pname, params);
}
void glTexEnvi(GLenum target, GLenum pname, GLint param) {
	static const auto glTexEnvi_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint)>(getProcAddress("glTexEnvi"));
	assert(glTexEnvi_ != nullptr);
	return glTexEnvi_(target, pname, param);
}
void glTexEnviv(GLenum target, GLenum pname, GLint const  * params) {
	static const auto glTexEnviv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint const  *)>(getProcAddress("glTexEnviv"));
	assert(glTexEnviv_ != nullptr);
	return glTexEnviv_(target, pname, params);
}
void glTexGend(GLenum coord, GLenum pname, GLdouble param) {
	static const auto glTexGend_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLdouble)>(getProcAddress("glTexGend"));
	assert(glTexGend_ != nullptr);
	return glTexGend_(coord, pname, param);
}
void glTexGendv(GLenum coord, GLenum pname, GLdouble const  * params) {
	static const auto glTexGendv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLdouble const  *)>(getProcAddress("glTexGendv"));
	assert(glTexGendv_ != nullptr);
	return glTexGendv_(coord, pname, params);
}
void glTexGenf(GLenum coord, GLenum pname, GLfloat param) {
	static const auto glTexGenf_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfloat)>(getProcAddress("glTexGenf"));
	assert(glTexGenf_ != nullptr);
	return glTexGenf_(coord, pname, param);
}
void glTexGenfv(GLenum coord, GLenum pname, GLfloat const  * params) {
	static const auto glTexGenfv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfloat const  *)>(getProcAddress("glTexGenfv"));
	assert(glTexGenfv_ != nullptr);
	return glTexGenfv_(coord, pname, params);
}
void glTexGeni(GLenum coord, GLenum pname, GLint param) {
	static const auto glTexGeni_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint)>(getProcAddress("glTexGeni"));
	assert(glTexGeni_ != nullptr);
	return glTexGeni_(coord, pname, param);
}
void glTexGeniv(GLenum coord, GLenum pname, GLint const  * params) {
	static const auto glTexGeniv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint const  *)>(getProcAddress("glTexGeniv"));
	assert(glTexGeniv_ != nullptr);
	return glTexGeniv_(coord, pname, params);
}
void glFeedbackBuffer(GLsizei size, GLenum type, GLfloat * buffer) {
	static const auto glFeedbackBuffer_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLenum, GLfloat *)>(getProcAddress("glFeedbackBuffer"));
	assert(glFeedbackBuffer_ != nullptr);
	return glFeedbackBuffer_(size, type, buffer);
}
void glSelectBuffer(GLsizei size, GLuint * buffer) {
	static const auto glSelectBuffer_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint *)>(getProcAddress("glSelectBuffer"));
	assert(glSelectBuffer_ != nullptr);
	return glSelectBuffer_(size, buffer);
}
GLint glRenderMode(GLenum mode) {
	static const auto glRenderMode_ = reinterpret_cast<GLint(GL_APIENTRYP)(GLenum)>(getProcAddress("glRenderMode"));
	assert(glRenderMode_ != nullptr);
	return glRenderMode_(mode);
}
void glInitNames() {
	static const auto glInitNames_ = reinterpret_cast<void(GL_APIENTRYP)()>(getProcAddress("glInitNames"));
	assert(glInitNames_ != nullptr);
	return glInitNames_();
}
void glLoadName(GLuint name) {
	static const auto glLoadName_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint)>(getProcAddress("glLoadName"));
	assert(glLoadName_ != nullptr);
	return glLoadName_(name);
}
void glPassThrough(GLfloat token) {
	static const auto glPassThrough_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat)>(getProcAddress("glPassThrough"));
	assert(glPassThrough_ != nullptr);
	return glPassThrough_(token);
}
void glPopName() {
	static const auto glPopName_ = reinterpret_cast<void(GL_APIENTRYP)()>(getProcAddress("glPopName"));
	assert(glPopName_ != nullptr);
	return glPopName_();
}
void glPushName(GLuint name) {
	static const auto glPushName_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint)>(getProcAddress("glPushName"));
	assert(glPushName_ != nullptr);
	return glPushName_(name);
}
void glClearAccum(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
	static const auto glClearAccum_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat, GLfloat, GLfloat, GLfloat)>(getProcAddress("glClearAccum"));
	assert(glClearAccum_ != nullptr);
	return glClearAccum_(red, green, blue, alpha);
}
void glClearIndex(GLfloat c) {
	static const auto glClearIndex_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat)>(getProcAddress("glClearIndex"));
	assert(glClearIndex_ != nullptr);
	return glClearIndex_(c);
}
void glIndexMask(GLuint mask) {
	static const auto glIndexMask_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint)>(getProcAddress("glIndexMask"));
	assert(glIndexMask_ != nullptr);
	return glIndexMask_(mask);
}
void glAccum(GLenum op, GLfloat value) {
	static const auto glAccum_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfloat)>(getProcAddress("glAccum"));
	assert(glAccum_ != nullptr);
	return glAccum_(op, value);
}
void glPopAttrib() {
	static const auto glPopAttrib_ = reinterpret_cast<void(GL_APIENTRYP)()>(getProcAddress("glPopAttrib"));
	assert(glPopAttrib_ != nullptr);
	return glPopAttrib_();
}
void glPushAttrib(GLbitfield mask) {
	static const auto glPushAttrib_ = reinterpret_cast<void(GL_APIENTRYP)(GLbitfield)>(getProcAddress("glPushAttrib"));
	assert(glPushAttrib_ != nullptr);
	return glPushAttrib_(mask);
}
void glMap1d(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, GLdouble const  * points) {
	static const auto glMap1d_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLdouble, GLdouble, GLint, GLint, GLdouble const  *)>(getProcAddress("glMap1d"));
	assert(glMap1d_ != nullptr);
	return glMap1d_(target, u1, u2, stride, order, points);
}
void glMap1f(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, GLfloat const  * points) {
	static const auto glMap1f_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfloat, GLfloat, GLint, GLint, GLfloat const  *)>(getProcAddress("glMap1f"));
	assert(glMap1f_ != nullptr);
	return glMap1f_(target, u1, u2, stride, order, points);
}
void glMap2d(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, GLdouble const  * points) {
	static const auto glMap2d_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLdouble, GLdouble, GLint, GLint, GLdouble, GLdouble, GLint, GLint, GLdouble const  *)>(getProcAddress("glMap2d"));
	assert(glMap2d_ != nullptr);
	return glMap2d_(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
}
void glMap2f(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, GLfloat const  * points) {
	static const auto glMap2f_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfloat, GLfloat, GLint, GLint, GLfloat, GLfloat, GLint, GLint, GLfloat const  *)>(getProcAddress("glMap2f"));
	assert(glMap2f_ != nullptr);
	return glMap2f_(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
}
void glMapGrid1d(GLint un, GLdouble u1, GLdouble u2) {
	static const auto glMapGrid1d_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLdouble, GLdouble)>(getProcAddress("glMapGrid1d"));
	assert(glMapGrid1d_ != nullptr);
	return glMapGrid1d_(un, u1, u2);
}
void glMapGrid1f(GLint un, GLfloat u1, GLfloat u2) {
	static const auto glMapGrid1f_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLfloat, GLfloat)>(getProcAddress("glMapGrid1f"));
	assert(glMapGrid1f_ != nullptr);
	return glMapGrid1f_(un, u1, u2);
}
void glMapGrid2d(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2) {
	static const auto glMapGrid2d_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLdouble, GLdouble, GLint, GLdouble, GLdouble)>(getProcAddress("glMapGrid2d"));
	assert(glMapGrid2d_ != nullptr);
	return glMapGrid2d_(un, u1, u2, vn, v1, v2);
}
void glMapGrid2f(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2) {
	static const auto glMapGrid2f_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLfloat, GLfloat, GLint, GLfloat, GLfloat)>(getProcAddress("glMapGrid2f"));
	assert(glMapGrid2f_ != nullptr);
	return glMapGrid2f_(un, u1, u2, vn, v1, v2);
}
void glEvalCoord1d(GLdouble u) {
	static const auto glEvalCoord1d_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble)>(getProcAddress("glEvalCoord1d"));
	assert(glEvalCoord1d_ != nullptr);
	return glEvalCoord1d_(u);
}
void glEvalCoord1dv(GLdouble const  * u) {
	static const auto glEvalCoord1dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble const  *)>(getProcAddress("glEvalCoord1dv"));
	assert(glEvalCoord1dv_ != nullptr);
	return glEvalCoord1dv_(u);
}
void glEvalCoord1f(GLfloat u) {
	static const auto glEvalCoord1f_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat)>(getProcAddress("glEvalCoord1f"));
	assert(glEvalCoord1f_ != nullptr);
	return glEvalCoord1f_(u);
}
void glEvalCoord1fv(GLfloat const  * u) {
	static const auto glEvalCoord1fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat const  *)>(getProcAddress("glEvalCoord1fv"));
	assert(glEvalCoord1fv_ != nullptr);
	return glEvalCoord1fv_(u);
}
void glEvalCoord2d(GLdouble u, GLdouble v) {
	static const auto glEvalCoord2d_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble, GLdouble)>(getProcAddress("glEvalCoord2d"));
	assert(glEvalCoord2d_ != nullptr);
	return glEvalCoord2d_(u, v);
}
void glEvalCoord2dv(GLdouble const  * u) {
	static const auto glEvalCoord2dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble const  *)>(getProcAddress("glEvalCoord2dv"));
	assert(glEvalCoord2dv_ != nullptr);
	return glEvalCoord2dv_(u);
}
void glEvalCoord2f(GLfloat u, GLfloat v) {
	static const auto glEvalCoord2f_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat, GLfloat)>(getProcAddress("glEvalCoord2f"));
	assert(glEvalCoord2f_ != nullptr);
	return glEvalCoord2f_(u, v);
}
void glEvalCoord2fv(GLfloat const  * u) {
	static const auto glEvalCoord2fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat const  *)>(getProcAddress("glEvalCoord2fv"));
	assert(glEvalCoord2fv_ != nullptr);
	return glEvalCoord2fv_(u);
}
void glEvalMesh1(GLenum mode, GLint i1, GLint i2) {
	static const auto glEvalMesh1_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLint)>(getProcAddress("glEvalMesh1"));
	assert(glEvalMesh1_ != nullptr);
	return glEvalMesh1_(mode, i1, i2);
}
void glEvalPoint1(GLint i) {
	static const auto glEvalPoint1_ = reinterpret_cast<void(GL_APIENTRYP)(GLint)>(getProcAddress("glEvalPoint1"));
	assert(glEvalPoint1_ != nullptr);
	return glEvalPoint1_(i);
}
void glEvalMesh2(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2) {
	static const auto glEvalMesh2_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLint, GLint, GLint)>(getProcAddress("glEvalMesh2"));
	assert(glEvalMesh2_ != nullptr);
	return glEvalMesh2_(mode, i1, i2, j1, j2);
}
void glEvalPoint2(GLint i, GLint j) {
	static const auto glEvalPoint2_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLint)>(getProcAddress("glEvalPoint2"));
	assert(glEvalPoint2_ != nullptr);
	return glEvalPoint2_(i, j);
}
void glAlphaFunc(GLenum func, GLfloat ref) {
	static const auto glAlphaFunc_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfloat)>(getProcAddress("glAlphaFunc"));
	assert(glAlphaFunc_ != nullptr);
	return glAlphaFunc_(func, ref);
}
void glPixelZoom(GLfloat xfactor, GLfloat yfactor) {
	static const auto glPixelZoom_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat, GLfloat)>(getProcAddress("glPixelZoom"));
	assert(glPixelZoom_ != nullptr);
	return glPixelZoom_(xfactor, yfactor);
}
void glPixelTransferf(GLenum pname, GLfloat param) {
	static const auto glPixelTransferf_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfloat)>(getProcAddress("glPixelTransferf"));
	assert(glPixelTransferf_ != nullptr);
	return glPixelTransferf_(pname, param);
}
void glPixelTransferi(GLenum pname, GLint param) {
	static const auto glPixelTransferi_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint)>(getProcAddress("glPixelTransferi"));
	assert(glPixelTransferi_ != nullptr);
	return glPixelTransferi_(pname, param);
}
void glPixelMapfv(GLenum map, GLsizei mapsize, GLfloat const  * values) {
	static const auto glPixelMapfv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, GLfloat const  *)>(getProcAddress("glPixelMapfv"));
	assert(glPixelMapfv_ != nullptr);
	return glPixelMapfv_(map, mapsize, values);
}
void glPixelMapuiv(GLenum map, GLsizei mapsize, GLuint const  * values) {
	static const auto glPixelMapuiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, GLuint const  *)>(getProcAddress("glPixelMapuiv"));
	assert(glPixelMapuiv_ != nullptr);
	return glPixelMapuiv_(map, mapsize, values);
}
void glPixelMapusv(GLenum map, GLsizei mapsize, GLushort const  * values) {
	static const auto glPixelMapusv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, GLushort const  *)>(getProcAddress("glPixelMapusv"));
	assert(glPixelMapusv_ != nullptr);
	return glPixelMapusv_(map, mapsize, values);
}
void glCopyPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type) {
	static const auto glCopyPixels_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLint, GLsizei, GLsizei, GLenum)>(getProcAddress("glCopyPixels"));
	assert(glCopyPixels_ != nullptr);
	return glCopyPixels_(x, y, width, height, type);
}
void glDrawPixels(GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels) {
	static const auto glDrawPixels_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLsizei, GLenum, GLenum, const void *)>(getProcAddress("glDrawPixels"));
	assert(glDrawPixels_ != nullptr);
	return glDrawPixels_(width, height, format, type, pixels);
}
void glGetClipPlane(GLenum plane, GLdouble * equation) {
	static const auto glGetClipPlane_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLdouble *)>(getProcAddress("glGetClipPlane"));
	assert(glGetClipPlane_ != nullptr);
	return glGetClipPlane_(plane, equation);
}
void glGetLightfv(GLenum light, GLenum pname, GLfloat * params) {
	static const auto glGetLightfv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfloat *)>(getProcAddress("glGetLightfv"));
	assert(glGetLightfv_ != nullptr);
	return glGetLightfv_(light, pname, params);
}
void glGetLightiv(GLenum light, GLenum pname, GLint * params) {
	static const auto glGetLightiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint *)>(getProcAddress("glGetLightiv"));
	assert(glGetLightiv_ != nullptr);
	return glGetLightiv_(light, pname, params);
}
void glGetMapdv(GLenum target, GLenum query, GLdouble * v) {
	static const auto glGetMapdv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLdouble *)>(getProcAddress("glGetMapdv"));
	assert(glGetMapdv_ != nullptr);
	return glGetMapdv_(target, query, v);
}
void glGetMapfv(GLenum target, GLenum query, GLfloat * v) {
	static const auto glGetMapfv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfloat *)>(getProcAddress("glGetMapfv"));
	assert(glGetMapfv_ != nullptr);
	return glGetMapfv_(target, query, v);
}
void glGetMapiv(GLenum target, GLenum query, GLint * v) {
	static const auto glGetMapiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint *)>(getProcAddress("glGetMapiv"));
	assert(glGetMapiv_ != nullptr);
	return glGetMapiv_(target, query, v);
}
void glGetMaterialfv(GLenum face, GLenum pname, GLfloat * params) {
	static const auto glGetMaterialfv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfloat *)>(getProcAddress("glGetMaterialfv"));
	assert(glGetMaterialfv_ != nullptr);
	return glGetMaterialfv_(face, pname, params);
}
void glGetMaterialiv(GLenum face, GLenum pname, GLint * params) {
	static const auto glGetMaterialiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint *)>(getProcAddress("glGetMaterialiv"));
	assert(glGetMaterialiv_ != nullptr);
	return glGetMaterialiv_(face, pname, params);
}
void glGetPixelMapfv(GLenum map, GLfloat * values) {
	static const auto glGetPixelMapfv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfloat *)>(getProcAddress("glGetPixelMapfv"));
	assert(glGetPixelMapfv_ != nullptr);
	return glGetPixelMapfv_(map, values);
}
void glGetPixelMapuiv(GLenum map, GLuint * values) {
	static const auto glGetPixelMapuiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint *)>(getProcAddress("glGetPixelMapuiv"));
	assert(glGetPixelMapuiv_ != nullptr);
	return glGetPixelMapuiv_(map, values);
}
void glGetPixelMapusv(GLenum map, GLushort * values) {
	static const auto glGetPixelMapusv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLushort *)>(getProcAddress("glGetPixelMapusv"));
	assert(glGetPixelMapusv_ != nullptr);
	return glGetPixelMapusv_(map, values);
}
void glGetPolygonStipple(GLubyte * mask) {
	static const auto glGetPolygonStipple_ = reinterpret_cast<void(GL_APIENTRYP)(GLubyte *)>(getProcAddress("glGetPolygonStipple"));
	assert(glGetPolygonStipple_ != nullptr);
	return glGetPolygonStipple_(mask);
}
void glGetTexEnvfv(GLenum target, GLenum pname, GLfloat * params) {
	static const auto glGetTexEnvfv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfloat *)>(getProcAddress("glGetTexEnvfv"));
	assert(glGetTexEnvfv_ != nullptr);
	return glGetTexEnvfv_(target, pname, params);
}
void glGetTexEnviv(GLenum target, GLenum pname, GLint * params) {
	static const auto glGetTexEnviv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint *)>(getProcAddress("glGetTexEnviv"));
	assert(glGetTexEnviv_ != nullptr);
	return glGetTexEnviv_(target, pname, params);
}
void glGetTexGendv(GLenum coord, GLenum pname, GLdouble * params) {
	static const auto glGetTexGendv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLdouble *)>(getProcAddress("glGetTexGendv"));
	assert(glGetTexGendv_ != nullptr);
	return glGetTexGendv_(coord, pname, params);
}
void glGetTexGenfv(GLenum coord, GLenum pname, GLfloat * params) {
	static const auto glGetTexGenfv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfloat *)>(getProcAddress("glGetTexGenfv"));
	assert(glGetTexGenfv_ != nullptr);
	return glGetTexGenfv_(coord, pname, params);
}
void glGetTexGeniv(GLenum coord, GLenum pname, GLint * params) {
	static const auto glGetTexGeniv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint *)>(getProcAddress("glGetTexGeniv"));
	assert(glGetTexGeniv_ != nullptr);
	return glGetTexGeniv_(coord, pname, params);
}
GLboolean glIsList(GLuint list) {
	static const auto glIsList_ = reinterpret_cast<GLboolean(GL_APIENTRYP)(GLuint)>(getProcAddress("glIsList"));
	assert(glIsList_ != nullptr);
	return glIsList_(list);
}
void glFrustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar) {
	static const auto glFrustum_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble)>(getProcAddress("glFrustum"));
	assert(glFrustum_ != nullptr);
	return glFrustum_(left, right, bottom, top, zNear, zFar);
}
void glLoadIdentity() {
	static const auto glLoadIdentity_ = reinterpret_cast<void(GL_APIENTRYP)()>(getProcAddress("glLoadIdentity"));
	assert(glLoadIdentity_ != nullptr);
	return glLoadIdentity_();
}
void glLoadMatrixf(GLfloat const  * m) {
	static const auto glLoadMatrixf_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat const  *)>(getProcAddress("glLoadMatrixf"));
	assert(glLoadMatrixf_ != nullptr);
	return glLoadMatrixf_(m);
}
void glLoadMatrixd(GLdouble const  * m) {
	static const auto glLoadMatrixd_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble const  *)>(getProcAddress("glLoadMatrixd"));
	assert(glLoadMatrixd_ != nullptr);
	return glLoadMatrixd_(m);
}
void glMatrixMode(GLenum mode) {
	static const auto glMatrixMode_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glMatrixMode"));
	assert(glMatrixMode_ != nullptr);
	return glMatrixMode_(mode);
}
void glMultMatrixf(GLfloat const  * m) {
	static const auto glMultMatrixf_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat const  *)>(getProcAddress("glMultMatrixf"));
	assert(glMultMatrixf_ != nullptr);
	return glMultMatrixf_(m);
}
void glMultMatrixd(GLdouble const  * m) {
	static const auto glMultMatrixd_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble const  *)>(getProcAddress("glMultMatrixd"));
	assert(glMultMatrixd_ != nullptr);
	return glMultMatrixd_(m);
}
void glOrtho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar) {
	static const auto glOrtho_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble)>(getProcAddress("glOrtho"));
	assert(glOrtho_ != nullptr);
	return glOrtho_(left, right, bottom, top, zNear, zFar);
}
void glPopMatrix() {
	static const auto glPopMatrix_ = reinterpret_cast<void(GL_APIENTRYP)()>(getProcAddress("glPopMatrix"));
	assert(glPopMatrix_ != nullptr);
	return glPopMatrix_();
}
void glPushMatrix() {
	static const auto glPushMatrix_ = reinterpret_cast<void(GL_APIENTRYP)()>(getProcAddress("glPushMatrix"));
	assert(glPushMatrix_ != nullptr);
	return glPushMatrix_();
}
void glRotated(GLdouble angle, GLdouble x, GLdouble y, GLdouble z) {
	static const auto glRotated_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble, GLdouble, GLdouble, GLdouble)>(getProcAddress("glRotated"));
	assert(glRotated_ != nullptr);
	return glRotated_(angle, x, y, z);
}
void glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z) {
	static const auto glRotatef_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat, GLfloat, GLfloat, GLfloat)>(getProcAddress("glRotatef"));
	assert(glRotatef_ != nullptr);
	return glRotatef_(angle, x, y, z);
}
void glScaled(GLdouble x, GLdouble y, GLdouble z) {
	static const auto glScaled_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble, GLdouble, GLdouble)>(getProcAddress("glScaled"));
	assert(glScaled_ != nullptr);
	return glScaled_(x, y, z);
}
void glScalef(GLfloat x, GLfloat y, GLfloat z) {
	static const auto glScalef_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat, GLfloat, GLfloat)>(getProcAddress("glScalef"));
	assert(glScalef_ != nullptr);
	return glScalef_(x, y, z);
}
void glTranslated(GLdouble x, GLdouble y, GLdouble z) {
	static const auto glTranslated_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble, GLdouble, GLdouble)>(getProcAddress("glTranslated"));
	assert(glTranslated_ != nullptr);
	return glTranslated_(x, y, z);
}
void glTranslatef(GLfloat x, GLfloat y, GLfloat z) {
	static const auto glTranslatef_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat, GLfloat, GLfloat)>(getProcAddress("glTranslatef"));
	assert(glTranslatef_ != nullptr);
	return glTranslatef_(x, y, z);
}
void glDrawArrays(GLenum mode, GLint first, GLsizei count) {
	static const auto glDrawArrays_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLsizei)>(getProcAddress("glDrawArrays"));
	assert(glDrawArrays_ != nullptr);
	return glDrawArrays_(mode, first, count);
}
void glDrawElements(GLenum mode, GLsizei count, GLenum type, const void * indices) {
	static const auto glDrawElements_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, GLenum, const void *)>(getProcAddress("glDrawElements"));
	assert(glDrawElements_ != nullptr);
	return glDrawElements_(mode, count, type, indices);
}
void glGetPointerv(GLenum pname, void ** params) {
	static const auto glGetPointerv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, void **)>(getProcAddress("glGetPointerv"));
	assert(glGetPointerv_ != nullptr);
	return glGetPointerv_(pname, params);
}
void glPolygonOffset(GLfloat factor, GLfloat units) {
	static const auto glPolygonOffset_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat, GLfloat)>(getProcAddress("glPolygonOffset"));
	assert(glPolygonOffset_ != nullptr);
	return glPolygonOffset_(factor, units);
}
void glCopyTexImage1D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) {
	static const auto glCopyTexImage1D_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLint)>(getProcAddress("glCopyTexImage1D"));
	assert(glCopyTexImage1D_ != nullptr);
	return glCopyTexImage1D_(target, level, internalformat, x, y, width, border);
}
void glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) {
	static const auto glCopyTexImage2D_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint)>(getProcAddress("glCopyTexImage2D"));
	assert(glCopyTexImage2D_ != nullptr);
	return glCopyTexImage2D_(target, level, internalformat, x, y, width, height, border);
}
void glCopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) {
	static const auto glCopyTexSubImage1D_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLint, GLint, GLint, GLsizei)>(getProcAddress("glCopyTexSubImage1D"));
	assert(glCopyTexSubImage1D_ != nullptr);
	return glCopyTexSubImage1D_(target, level, xoffset, x, y, width);
}
void glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
	static const auto glCopyTexSubImage2D_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei)>(getProcAddress("glCopyTexSubImage2D"));
	assert(glCopyTexSubImage2D_ != nullptr);
	return glCopyTexSubImage2D_(target, level, xoffset, yoffset, x, y, width, height);
}
void glTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void * pixels) {
	static const auto glTexSubImage1D_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLint, GLsizei, GLenum, GLenum, const void *)>(getProcAddress("glTexSubImage1D"));
	assert(glTexSubImage1D_ != nullptr);
	return glTexSubImage1D_(target, level, xoffset, width, format, type, pixels);
}
void glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels) {
	static const auto glTexSubImage2D_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const void *)>(getProcAddress("glTexSubImage2D"));
	assert(glTexSubImage2D_ != nullptr);
	return glTexSubImage2D_(target, level, xoffset, yoffset, width, height, format, type, pixels);
}
void glBindTexture(GLenum target, GLuint texture) {
	static const auto glBindTexture_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint)>(getProcAddress("glBindTexture"));
	assert(glBindTexture_ != nullptr);
	return glBindTexture_(target, texture);
}
void glDeleteTextures(GLsizei n, GLuint const  * textures) {
	static const auto glDeleteTextures_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint const  *)>(getProcAddress("glDeleteTextures"));
	assert(glDeleteTextures_ != nullptr);
	return glDeleteTextures_(n, textures);
}
void glGenTextures(GLsizei n, GLuint * textures) {
	static const auto glGenTextures_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint *)>(getProcAddress("glGenTextures"));
	assert(glGenTextures_ != nullptr);
	return glGenTextures_(n, textures);
}
GLboolean glIsTexture(GLuint texture) {
	static const auto glIsTexture_ = reinterpret_cast<GLboolean(GL_APIENTRYP)(GLuint)>(getProcAddress("glIsTexture"));
	assert(glIsTexture_ != nullptr);
	return glIsTexture_(texture);
}
void glArrayElement(GLint i) {
	static const auto glArrayElement_ = reinterpret_cast<void(GL_APIENTRYP)(GLint)>(getProcAddress("glArrayElement"));
	assert(glArrayElement_ != nullptr);
	return glArrayElement_(i);
}
void glColorPointer(GLint size, GLenum type, GLsizei stride, const void * pointer) {
	static const auto glColorPointer_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLenum, GLsizei, const void *)>(getProcAddress("glColorPointer"));
	assert(glColorPointer_ != nullptr);
	return glColorPointer_(size, type, stride, pointer);
}
void glDisableClientState(GLenum array) {
	static const auto glDisableClientState_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glDisableClientState"));
	assert(glDisableClientState_ != nullptr);
	return glDisableClientState_(array);
}
void glEdgeFlagPointer(GLsizei stride, const void * pointer) {
	static const auto glEdgeFlagPointer_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, const void *)>(getProcAddress("glEdgeFlagPointer"));
	assert(glEdgeFlagPointer_ != nullptr);
	return glEdgeFlagPointer_(stride, pointer);
}
void glEnableClientState(GLenum array) {
	static const auto glEnableClientState_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glEnableClientState"));
	assert(glEnableClientState_ != nullptr);
	return glEnableClientState_(array);
}
void glIndexPointer(GLenum type, GLsizei stride, const void * pointer) {
	static const auto glIndexPointer_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, const void *)>(getProcAddress("glIndexPointer"));
	assert(glIndexPointer_ != nullptr);
	return glIndexPointer_(type, stride, pointer);
}
void glInterleavedArrays(GLenum format, GLsizei stride, const void * pointer) {
	static const auto glInterleavedArrays_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, const void *)>(getProcAddress("glInterleavedArrays"));
	assert(glInterleavedArrays_ != nullptr);
	return glInterleavedArrays_(format, stride, pointer);
}
void glNormalPointer(GLenum type, GLsizei stride, const void * pointer) {
	static const auto glNormalPointer_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, const void *)>(getProcAddress("glNormalPointer"));
	assert(glNormalPointer_ != nullptr);
	return glNormalPointer_(type, stride, pointer);
}
void glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const void * pointer) {
	static const auto glTexCoordPointer_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLenum, GLsizei, const void *)>(getProcAddress("glTexCoordPointer"));
	assert(glTexCoordPointer_ != nullptr);
	return glTexCoordPointer_(size, type, stride, pointer);
}
void glVertexPointer(GLint size, GLenum type, GLsizei stride, const void * pointer) {
	static const auto glVertexPointer_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLenum, GLsizei, const void *)>(getProcAddress("glVertexPointer"));
	assert(glVertexPointer_ != nullptr);
	return glVertexPointer_(size, type, stride, pointer);
}
GLboolean glAreTexturesResident(GLsizei n, GLuint const  * textures, GLboolean * residences) {
	static const auto glAreTexturesResident_ = reinterpret_cast<GLboolean(GL_APIENTRYP)(GLsizei, GLuint const  *, GLboolean *)>(getProcAddress("glAreTexturesResident"));
	assert(glAreTexturesResident_ != nullptr);
	return glAreTexturesResident_(n, textures, residences);
}
void glPrioritizeTextures(GLsizei n, GLuint const  * textures, GLfloat const  * priorities) {
	static const auto glPrioritizeTextures_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint const  *, GLfloat const  *)>(getProcAddress("glPrioritizeTextures"));
	assert(glPrioritizeTextures_ != nullptr);
	return glPrioritizeTextures_(n, textures, priorities);
}
void glIndexub(GLubyte c) {
	static const auto glIndexub_ = reinterpret_cast<void(GL_APIENTRYP)(GLubyte)>(getProcAddress("glIndexub"));
	assert(glIndexub_ != nullptr);
	return glIndexub_(c);
}
void glIndexubv(GLubyte const  * c) {
	static const auto glIndexubv_ = reinterpret_cast<void(GL_APIENTRYP)(GLubyte const  *)>(getProcAddress("glIndexubv"));
	assert(glIndexubv_ != nullptr);
	return glIndexubv_(c);
}
void glPopClientAttrib() {
	static const auto glPopClientAttrib_ = reinterpret_cast<void(GL_APIENTRYP)()>(getProcAddress("glPopClientAttrib"));
	assert(glPopClientAttrib_ != nullptr);
	return glPopClientAttrib_();
}
void glPushClientAttrib(GLbitfield mask) {
	static const auto glPushClientAttrib_ = reinterpret_cast<void(GL_APIENTRYP)(GLbitfield)>(getProcAddress("glPushClientAttrib"));
	assert(glPushClientAttrib_ != nullptr);
	return glPushClientAttrib_(mask);
}
void glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices) {
	static const auto glDrawRangeElements_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint, GLuint, GLsizei, GLenum, const void *)>(getProcAddress("glDrawRangeElements"));
	assert(glDrawRangeElements_ != nullptr);
	return glDrawRangeElements_(mode, start, end, count, type, indices);
}
void glTexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void * pixels) {
	static const auto glTexImage3D_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLint, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const void *)>(getProcAddress("glTexImage3D"));
	assert(glTexImage3D_ != nullptr);
	return glTexImage3D_(target, level, internalformat, width, height, depth, border, format, type, pixels);
}
void glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels) {
	static const auto glTexSubImage3D_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const void *)>(getProcAddress("glTexSubImage3D"));
	assert(glTexSubImage3D_ != nullptr);
	return glTexSubImage3D_(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}
void glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
	static const auto glCopyTexSubImage3D_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei)>(getProcAddress("glCopyTexSubImage3D"));
	assert(glCopyTexSubImage3D_ != nullptr);
	return glCopyTexSubImage3D_(target, level, xoffset, yoffset, zoffset, x, y, width, height);
}
void glActiveTexture(GLenum texture) {
	static const auto glActiveTexture_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glActiveTexture"));
	assert(glActiveTexture_ != nullptr);
	return glActiveTexture_(texture);
}
void glSampleCoverage(GLfloat value, GLboolean invert) {
	static const auto glSampleCoverage_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat, GLboolean)>(getProcAddress("glSampleCoverage"));
	assert(glSampleCoverage_ != nullptr);
	return glSampleCoverage_(value, invert);
}
void glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void * data) {
	static const auto glCompressedTexImage3D_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLsizei, const void *)>(getProcAddress("glCompressedTexImage3D"));
	assert(glCompressedTexImage3D_ != nullptr);
	return glCompressedTexImage3D_(target, level, internalformat, width, height, depth, border, imageSize, data);
}
void glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void * data) {
	static const auto glCompressedTexImage2D_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const void *)>(getProcAddress("glCompressedTexImage2D"));
	assert(glCompressedTexImage2D_ != nullptr);
	return glCompressedTexImage2D_(target, level, internalformat, width, height, border, imageSize, data);
}
void glCompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void * data) {
	static const auto glCompressedTexImage1D_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLenum, GLsizei, GLint, GLsizei, const void *)>(getProcAddress("glCompressedTexImage1D"));
	assert(glCompressedTexImage1D_ != nullptr);
	return glCompressedTexImage1D_(target, level, internalformat, width, border, imageSize, data);
}
void glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * data) {
	static const auto glCompressedTexSubImage3D_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const void *)>(getProcAddress("glCompressedTexSubImage3D"));
	assert(glCompressedTexSubImage3D_ != nullptr);
	return glCompressedTexSubImage3D_(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
}
void glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * data) {
	static const auto glCompressedTexSubImage2D_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const void *)>(getProcAddress("glCompressedTexSubImage2D"));
	assert(glCompressedTexSubImage2D_ != nullptr);
	return glCompressedTexSubImage2D_(target, level, xoffset, yoffset, width, height, format, imageSize, data);
}
void glCompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * data) {
	static const auto glCompressedTexSubImage1D_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLint, GLsizei, GLenum, GLsizei, const void *)>(getProcAddress("glCompressedTexSubImage1D"));
	assert(glCompressedTexSubImage1D_ != nullptr);
	return glCompressedTexSubImage1D_(target, level, xoffset, width, format, imageSize, data);
}
void glGetCompressedTexImage(GLenum target, GLint level, void * img) {
	static const auto glGetCompressedTexImage_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, void *)>(getProcAddress("glGetCompressedTexImage"));
	assert(glGetCompressedTexImage_ != nullptr);
	return glGetCompressedTexImage_(target, level, img);
}
void glClientActiveTexture(GLenum texture) {
	static const auto glClientActiveTexture_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glClientActiveTexture"));
	assert(glClientActiveTexture_ != nullptr);
	return glClientActiveTexture_(texture);
}
void glMultiTexCoord1d(GLenum target, GLdouble s) {
	static const auto glMultiTexCoord1d_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLdouble)>(getProcAddress("glMultiTexCoord1d"));
	assert(glMultiTexCoord1d_ != nullptr);
	return glMultiTexCoord1d_(target, s);
}
void glMultiTexCoord1dv(GLenum target, GLdouble const  * v) {
	static const auto glMultiTexCoord1dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLdouble const  *)>(getProcAddress("glMultiTexCoord1dv"));
	assert(glMultiTexCoord1dv_ != nullptr);
	return glMultiTexCoord1dv_(target, v);
}
void glMultiTexCoord1f(GLenum target, GLfloat s) {
	static const auto glMultiTexCoord1f_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfloat)>(getProcAddress("glMultiTexCoord1f"));
	assert(glMultiTexCoord1f_ != nullptr);
	return glMultiTexCoord1f_(target, s);
}
void glMultiTexCoord1fv(GLenum target, GLfloat const  * v) {
	static const auto glMultiTexCoord1fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfloat const  *)>(getProcAddress("glMultiTexCoord1fv"));
	assert(glMultiTexCoord1fv_ != nullptr);
	return glMultiTexCoord1fv_(target, v);
}
void glMultiTexCoord1i(GLenum target, GLint s) {
	static const auto glMultiTexCoord1i_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint)>(getProcAddress("glMultiTexCoord1i"));
	assert(glMultiTexCoord1i_ != nullptr);
	return glMultiTexCoord1i_(target, s);
}
void glMultiTexCoord1iv(GLenum target, GLint const  * v) {
	static const auto glMultiTexCoord1iv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint const  *)>(getProcAddress("glMultiTexCoord1iv"));
	assert(glMultiTexCoord1iv_ != nullptr);
	return glMultiTexCoord1iv_(target, v);
}
void glMultiTexCoord1s(GLenum target, GLshort s) {
	static const auto glMultiTexCoord1s_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLshort)>(getProcAddress("glMultiTexCoord1s"));
	assert(glMultiTexCoord1s_ != nullptr);
	return glMultiTexCoord1s_(target, s);
}
void glMultiTexCoord1sv(GLenum target, GLshort const  * v) {
	static const auto glMultiTexCoord1sv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLshort const  *)>(getProcAddress("glMultiTexCoord1sv"));
	assert(glMultiTexCoord1sv_ != nullptr);
	return glMultiTexCoord1sv_(target, v);
}
void glMultiTexCoord2d(GLenum target, GLdouble s, GLdouble t) {
	static const auto glMultiTexCoord2d_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLdouble, GLdouble)>(getProcAddress("glMultiTexCoord2d"));
	assert(glMultiTexCoord2d_ != nullptr);
	return glMultiTexCoord2d_(target, s, t);
}
void glMultiTexCoord2dv(GLenum target, GLdouble const  * v) {
	static const auto glMultiTexCoord2dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLdouble const  *)>(getProcAddress("glMultiTexCoord2dv"));
	assert(glMultiTexCoord2dv_ != nullptr);
	return glMultiTexCoord2dv_(target, v);
}
void glMultiTexCoord2f(GLenum target, GLfloat s, GLfloat t) {
	static const auto glMultiTexCoord2f_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfloat, GLfloat)>(getProcAddress("glMultiTexCoord2f"));
	assert(glMultiTexCoord2f_ != nullptr);
	return glMultiTexCoord2f_(target, s, t);
}
void glMultiTexCoord2fv(GLenum target, GLfloat const  * v) {
	static const auto glMultiTexCoord2fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfloat const  *)>(getProcAddress("glMultiTexCoord2fv"));
	assert(glMultiTexCoord2fv_ != nullptr);
	return glMultiTexCoord2fv_(target, v);
}
void glMultiTexCoord2i(GLenum target, GLint s, GLint t) {
	static const auto glMultiTexCoord2i_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLint)>(getProcAddress("glMultiTexCoord2i"));
	assert(glMultiTexCoord2i_ != nullptr);
	return glMultiTexCoord2i_(target, s, t);
}
void glMultiTexCoord2iv(GLenum target, GLint const  * v) {
	static const auto glMultiTexCoord2iv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint const  *)>(getProcAddress("glMultiTexCoord2iv"));
	assert(glMultiTexCoord2iv_ != nullptr);
	return glMultiTexCoord2iv_(target, v);
}
void glMultiTexCoord2s(GLenum target, GLshort s, GLshort t) {
	static const auto glMultiTexCoord2s_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLshort, GLshort)>(getProcAddress("glMultiTexCoord2s"));
	assert(glMultiTexCoord2s_ != nullptr);
	return glMultiTexCoord2s_(target, s, t);
}
void glMultiTexCoord2sv(GLenum target, GLshort const  * v) {
	static const auto glMultiTexCoord2sv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLshort const  *)>(getProcAddress("glMultiTexCoord2sv"));
	assert(glMultiTexCoord2sv_ != nullptr);
	return glMultiTexCoord2sv_(target, v);
}
void glMultiTexCoord3d(GLenum target, GLdouble s, GLdouble t, GLdouble r) {
	static const auto glMultiTexCoord3d_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLdouble, GLdouble, GLdouble)>(getProcAddress("glMultiTexCoord3d"));
	assert(glMultiTexCoord3d_ != nullptr);
	return glMultiTexCoord3d_(target, s, t, r);
}
void glMultiTexCoord3dv(GLenum target, GLdouble const  * v) {
	static const auto glMultiTexCoord3dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLdouble const  *)>(getProcAddress("glMultiTexCoord3dv"));
	assert(glMultiTexCoord3dv_ != nullptr);
	return glMultiTexCoord3dv_(target, v);
}
void glMultiTexCoord3f(GLenum target, GLfloat s, GLfloat t, GLfloat r) {
	static const auto glMultiTexCoord3f_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfloat, GLfloat, GLfloat)>(getProcAddress("glMultiTexCoord3f"));
	assert(glMultiTexCoord3f_ != nullptr);
	return glMultiTexCoord3f_(target, s, t, r);
}
void glMultiTexCoord3fv(GLenum target, GLfloat const  * v) {
	static const auto glMultiTexCoord3fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfloat const  *)>(getProcAddress("glMultiTexCoord3fv"));
	assert(glMultiTexCoord3fv_ != nullptr);
	return glMultiTexCoord3fv_(target, v);
}
void glMultiTexCoord3i(GLenum target, GLint s, GLint t, GLint r) {
	static const auto glMultiTexCoord3i_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLint, GLint)>(getProcAddress("glMultiTexCoord3i"));
	assert(glMultiTexCoord3i_ != nullptr);
	return glMultiTexCoord3i_(target, s, t, r);
}
void glMultiTexCoord3iv(GLenum target, GLint const  * v) {
	static const auto glMultiTexCoord3iv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint const  *)>(getProcAddress("glMultiTexCoord3iv"));
	assert(glMultiTexCoord3iv_ != nullptr);
	return glMultiTexCoord3iv_(target, v);
}
void glMultiTexCoord3s(GLenum target, GLshort s, GLshort t, GLshort r) {
	static const auto glMultiTexCoord3s_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLshort, GLshort, GLshort)>(getProcAddress("glMultiTexCoord3s"));
	assert(glMultiTexCoord3s_ != nullptr);
	return glMultiTexCoord3s_(target, s, t, r);
}
void glMultiTexCoord3sv(GLenum target, GLshort const  * v) {
	static const auto glMultiTexCoord3sv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLshort const  *)>(getProcAddress("glMultiTexCoord3sv"));
	assert(glMultiTexCoord3sv_ != nullptr);
	return glMultiTexCoord3sv_(target, v);
}
void glMultiTexCoord4d(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q) {
	static const auto glMultiTexCoord4d_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLdouble, GLdouble, GLdouble, GLdouble)>(getProcAddress("glMultiTexCoord4d"));
	assert(glMultiTexCoord4d_ != nullptr);
	return glMultiTexCoord4d_(target, s, t, r, q);
}
void glMultiTexCoord4dv(GLenum target, GLdouble const  * v) {
	static const auto glMultiTexCoord4dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLdouble const  *)>(getProcAddress("glMultiTexCoord4dv"));
	assert(glMultiTexCoord4dv_ != nullptr);
	return glMultiTexCoord4dv_(target, v);
}
void glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) {
	static const auto glMultiTexCoord4f_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfloat, GLfloat, GLfloat, GLfloat)>(getProcAddress("glMultiTexCoord4f"));
	assert(glMultiTexCoord4f_ != nullptr);
	return glMultiTexCoord4f_(target, s, t, r, q);
}
void glMultiTexCoord4fv(GLenum target, GLfloat const  * v) {
	static const auto glMultiTexCoord4fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfloat const  *)>(getProcAddress("glMultiTexCoord4fv"));
	assert(glMultiTexCoord4fv_ != nullptr);
	return glMultiTexCoord4fv_(target, v);
}
void glMultiTexCoord4i(GLenum target, GLint s, GLint t, GLint r, GLint q) {
	static const auto glMultiTexCoord4i_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLint, GLint, GLint)>(getProcAddress("glMultiTexCoord4i"));
	assert(glMultiTexCoord4i_ != nullptr);
	return glMultiTexCoord4i_(target, s, t, r, q);
}
void glMultiTexCoord4iv(GLenum target, GLint const  * v) {
	static const auto glMultiTexCoord4iv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint const  *)>(getProcAddress("glMultiTexCoord4iv"));
	assert(glMultiTexCoord4iv_ != nullptr);
	return glMultiTexCoord4iv_(target, v);
}
void glMultiTexCoord4s(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q) {
	static const auto glMultiTexCoord4s_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLshort, GLshort, GLshort, GLshort)>(getProcAddress("glMultiTexCoord4s"));
	assert(glMultiTexCoord4s_ != nullptr);
	return glMultiTexCoord4s_(target, s, t, r, q);
}
void glMultiTexCoord4sv(GLenum target, GLshort const  * v) {
	static const auto glMultiTexCoord4sv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLshort const  *)>(getProcAddress("glMultiTexCoord4sv"));
	assert(glMultiTexCoord4sv_ != nullptr);
	return glMultiTexCoord4sv_(target, v);
}
void glLoadTransposeMatrixf(GLfloat const  * m) {
	static const auto glLoadTransposeMatrixf_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat const  *)>(getProcAddress("glLoadTransposeMatrixf"));
	assert(glLoadTransposeMatrixf_ != nullptr);
	return glLoadTransposeMatrixf_(m);
}
void glLoadTransposeMatrixd(GLdouble const  * m) {
	static const auto glLoadTransposeMatrixd_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble const  *)>(getProcAddress("glLoadTransposeMatrixd"));
	assert(glLoadTransposeMatrixd_ != nullptr);
	return glLoadTransposeMatrixd_(m);
}
void glMultTransposeMatrixf(GLfloat const  * m) {
	static const auto glMultTransposeMatrixf_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat const  *)>(getProcAddress("glMultTransposeMatrixf"));
	assert(glMultTransposeMatrixf_ != nullptr);
	return glMultTransposeMatrixf_(m);
}
void glMultTransposeMatrixd(GLdouble const  * m) {
	static const auto glMultTransposeMatrixd_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble const  *)>(getProcAddress("glMultTransposeMatrixd"));
	assert(glMultTransposeMatrixd_ != nullptr);
	return glMultTransposeMatrixd_(m);
}
void glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) {
	static const auto glBlendFuncSeparate_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLenum)>(getProcAddress("glBlendFuncSeparate"));
	assert(glBlendFuncSeparate_ != nullptr);
	return glBlendFuncSeparate_(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
}
void glMultiDrawArrays(GLenum mode, GLint const  * first, GLsizei const  * count, GLsizei drawcount) {
	static const auto glMultiDrawArrays_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint const  *, GLsizei const  *, GLsizei)>(getProcAddress("glMultiDrawArrays"));
	assert(glMultiDrawArrays_ != nullptr);
	return glMultiDrawArrays_(mode, first, count, drawcount);
}
void glMultiDrawElements(GLenum mode, GLsizei const  * count, GLenum type, const void *const* indices, GLsizei drawcount) {
	static const auto glMultiDrawElements_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei const  *, GLenum, const void *const*, GLsizei)>(getProcAddress("glMultiDrawElements"));
	assert(glMultiDrawElements_ != nullptr);
	return glMultiDrawElements_(mode, count, type, indices, drawcount);
}
void glPointParameterf(GLenum pname, GLfloat param) {
	static const auto glPointParameterf_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfloat)>(getProcAddress("glPointParameterf"));
	assert(glPointParameterf_ != nullptr);
	return glPointParameterf_(pname, param);
}
void glPointParameterfv(GLenum pname, GLfloat const  * params) {
	static const auto glPointParameterfv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfloat const  *)>(getProcAddress("glPointParameterfv"));
	assert(glPointParameterfv_ != nullptr);
	return glPointParameterfv_(pname, params);
}
void glPointParameteri(GLenum pname, GLint param) {
	static const auto glPointParameteri_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint)>(getProcAddress("glPointParameteri"));
	assert(glPointParameteri_ != nullptr);
	return glPointParameteri_(pname, param);
}
void glPointParameteriv(GLenum pname, GLint const  * params) {
	static const auto glPointParameteriv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint const  *)>(getProcAddress("glPointParameteriv"));
	assert(glPointParameteriv_ != nullptr);
	return glPointParameteriv_(pname, params);
}
void glFogCoordf(GLfloat coord) {
	static const auto glFogCoordf_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat)>(getProcAddress("glFogCoordf"));
	assert(glFogCoordf_ != nullptr);
	return glFogCoordf_(coord);
}
void glFogCoordfv(GLfloat const  * coord) {
	static const auto glFogCoordfv_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat const  *)>(getProcAddress("glFogCoordfv"));
	assert(glFogCoordfv_ != nullptr);
	return glFogCoordfv_(coord);
}
void glFogCoordd(GLdouble coord) {
	static const auto glFogCoordd_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble)>(getProcAddress("glFogCoordd"));
	assert(glFogCoordd_ != nullptr);
	return glFogCoordd_(coord);
}
void glFogCoorddv(GLdouble const  * coord) {
	static const auto glFogCoorddv_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble const  *)>(getProcAddress("glFogCoorddv"));
	assert(glFogCoorddv_ != nullptr);
	return glFogCoorddv_(coord);
}
void glFogCoordPointer(GLenum type, GLsizei stride, const void * pointer) {
	static const auto glFogCoordPointer_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, const void *)>(getProcAddress("glFogCoordPointer"));
	assert(glFogCoordPointer_ != nullptr);
	return glFogCoordPointer_(type, stride, pointer);
}
void glSecondaryColor3b(GLbyte red, GLbyte green, GLbyte blue) {
	static const auto glSecondaryColor3b_ = reinterpret_cast<void(GL_APIENTRYP)(GLbyte, GLbyte, GLbyte)>(getProcAddress("glSecondaryColor3b"));
	assert(glSecondaryColor3b_ != nullptr);
	return glSecondaryColor3b_(red, green, blue);
}
void glSecondaryColor3bv(GLbyte const  * v) {
	static const auto glSecondaryColor3bv_ = reinterpret_cast<void(GL_APIENTRYP)(GLbyte const  *)>(getProcAddress("glSecondaryColor3bv"));
	assert(glSecondaryColor3bv_ != nullptr);
	return glSecondaryColor3bv_(v);
}
void glSecondaryColor3d(GLdouble red, GLdouble green, GLdouble blue) {
	static const auto glSecondaryColor3d_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble, GLdouble, GLdouble)>(getProcAddress("glSecondaryColor3d"));
	assert(glSecondaryColor3d_ != nullptr);
	return glSecondaryColor3d_(red, green, blue);
}
void glSecondaryColor3dv(GLdouble const  * v) {
	static const auto glSecondaryColor3dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble const  *)>(getProcAddress("glSecondaryColor3dv"));
	assert(glSecondaryColor3dv_ != nullptr);
	return glSecondaryColor3dv_(v);
}
void glSecondaryColor3f(GLfloat red, GLfloat green, GLfloat blue) {
	static const auto glSecondaryColor3f_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat, GLfloat, GLfloat)>(getProcAddress("glSecondaryColor3f"));
	assert(glSecondaryColor3f_ != nullptr);
	return glSecondaryColor3f_(red, green, blue);
}
void glSecondaryColor3fv(GLfloat const  * v) {
	static const auto glSecondaryColor3fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat const  *)>(getProcAddress("glSecondaryColor3fv"));
	assert(glSecondaryColor3fv_ != nullptr);
	return glSecondaryColor3fv_(v);
}
void glSecondaryColor3i(GLint red, GLint green, GLint blue) {
	static const auto glSecondaryColor3i_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLint, GLint)>(getProcAddress("glSecondaryColor3i"));
	assert(glSecondaryColor3i_ != nullptr);
	return glSecondaryColor3i_(red, green, blue);
}
void glSecondaryColor3iv(GLint const  * v) {
	static const auto glSecondaryColor3iv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint const  *)>(getProcAddress("glSecondaryColor3iv"));
	assert(glSecondaryColor3iv_ != nullptr);
	return glSecondaryColor3iv_(v);
}
void glSecondaryColor3s(GLshort red, GLshort green, GLshort blue) {
	static const auto glSecondaryColor3s_ = reinterpret_cast<void(GL_APIENTRYP)(GLshort, GLshort, GLshort)>(getProcAddress("glSecondaryColor3s"));
	assert(glSecondaryColor3s_ != nullptr);
	return glSecondaryColor3s_(red, green, blue);
}
void glSecondaryColor3sv(GLshort const  * v) {
	static const auto glSecondaryColor3sv_ = reinterpret_cast<void(GL_APIENTRYP)(GLshort const  *)>(getProcAddress("glSecondaryColor3sv"));
	assert(glSecondaryColor3sv_ != nullptr);
	return glSecondaryColor3sv_(v);
}
void glSecondaryColor3ub(GLubyte red, GLubyte green, GLubyte blue) {
	static const auto glSecondaryColor3ub_ = reinterpret_cast<void(GL_APIENTRYP)(GLubyte, GLubyte, GLubyte)>(getProcAddress("glSecondaryColor3ub"));
	assert(glSecondaryColor3ub_ != nullptr);
	return glSecondaryColor3ub_(red, green, blue);
}
void glSecondaryColor3ubv(GLubyte const  * v) {
	static const auto glSecondaryColor3ubv_ = reinterpret_cast<void(GL_APIENTRYP)(GLubyte const  *)>(getProcAddress("glSecondaryColor3ubv"));
	assert(glSecondaryColor3ubv_ != nullptr);
	return glSecondaryColor3ubv_(v);
}
void glSecondaryColor3ui(GLuint red, GLuint green, GLuint blue) {
	static const auto glSecondaryColor3ui_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLuint)>(getProcAddress("glSecondaryColor3ui"));
	assert(glSecondaryColor3ui_ != nullptr);
	return glSecondaryColor3ui_(red, green, blue);
}
void glSecondaryColor3uiv(GLuint const  * v) {
	static const auto glSecondaryColor3uiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint const  *)>(getProcAddress("glSecondaryColor3uiv"));
	assert(glSecondaryColor3uiv_ != nullptr);
	return glSecondaryColor3uiv_(v);
}
void glSecondaryColor3us(GLushort red, GLushort green, GLushort blue) {
	static const auto glSecondaryColor3us_ = reinterpret_cast<void(GL_APIENTRYP)(GLushort, GLushort, GLushort)>(getProcAddress("glSecondaryColor3us"));
	assert(glSecondaryColor3us_ != nullptr);
	return glSecondaryColor3us_(red, green, blue);
}
void glSecondaryColor3usv(GLushort const  * v) {
	static const auto glSecondaryColor3usv_ = reinterpret_cast<void(GL_APIENTRYP)(GLushort const  *)>(getProcAddress("glSecondaryColor3usv"));
	assert(glSecondaryColor3usv_ != nullptr);
	return glSecondaryColor3usv_(v);
}
void glSecondaryColorPointer(GLint size, GLenum type, GLsizei stride, const void * pointer) {
	static const auto glSecondaryColorPointer_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLenum, GLsizei, const void *)>(getProcAddress("glSecondaryColorPointer"));
	assert(glSecondaryColorPointer_ != nullptr);
	return glSecondaryColorPointer_(size, type, stride, pointer);
}
void glWindowPos2d(GLdouble x, GLdouble y) {
	static const auto glWindowPos2d_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble, GLdouble)>(getProcAddress("glWindowPos2d"));
	assert(glWindowPos2d_ != nullptr);
	return glWindowPos2d_(x, y);
}
void glWindowPos2dv(GLdouble const  * v) {
	static const auto glWindowPos2dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble const  *)>(getProcAddress("glWindowPos2dv"));
	assert(glWindowPos2dv_ != nullptr);
	return glWindowPos2dv_(v);
}
void glWindowPos2f(GLfloat x, GLfloat y) {
	static const auto glWindowPos2f_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat, GLfloat)>(getProcAddress("glWindowPos2f"));
	assert(glWindowPos2f_ != nullptr);
	return glWindowPos2f_(x, y);
}
void glWindowPos2fv(GLfloat const  * v) {
	static const auto glWindowPos2fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat const  *)>(getProcAddress("glWindowPos2fv"));
	assert(glWindowPos2fv_ != nullptr);
	return glWindowPos2fv_(v);
}
void glWindowPos2i(GLint x, GLint y) {
	static const auto glWindowPos2i_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLint)>(getProcAddress("glWindowPos2i"));
	assert(glWindowPos2i_ != nullptr);
	return glWindowPos2i_(x, y);
}
void glWindowPos2iv(GLint const  * v) {
	static const auto glWindowPos2iv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint const  *)>(getProcAddress("glWindowPos2iv"));
	assert(glWindowPos2iv_ != nullptr);
	return glWindowPos2iv_(v);
}
void glWindowPos2s(GLshort x, GLshort y) {
	static const auto glWindowPos2s_ = reinterpret_cast<void(GL_APIENTRYP)(GLshort, GLshort)>(getProcAddress("glWindowPos2s"));
	assert(glWindowPos2s_ != nullptr);
	return glWindowPos2s_(x, y);
}
void glWindowPos2sv(GLshort const  * v) {
	static const auto glWindowPos2sv_ = reinterpret_cast<void(GL_APIENTRYP)(GLshort const  *)>(getProcAddress("glWindowPos2sv"));
	assert(glWindowPos2sv_ != nullptr);
	return glWindowPos2sv_(v);
}
void glWindowPos3d(GLdouble x, GLdouble y, GLdouble z) {
	static const auto glWindowPos3d_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble, GLdouble, GLdouble)>(getProcAddress("glWindowPos3d"));
	assert(glWindowPos3d_ != nullptr);
	return glWindowPos3d_(x, y, z);
}
void glWindowPos3dv(GLdouble const  * v) {
	static const auto glWindowPos3dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble const  *)>(getProcAddress("glWindowPos3dv"));
	assert(glWindowPos3dv_ != nullptr);
	return glWindowPos3dv_(v);
}
void glWindowPos3f(GLfloat x, GLfloat y, GLfloat z) {
	static const auto glWindowPos3f_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat, GLfloat, GLfloat)>(getProcAddress("glWindowPos3f"));
	assert(glWindowPos3f_ != nullptr);
	return glWindowPos3f_(x, y, z);
}
void glWindowPos3fv(GLfloat const  * v) {
	static const auto glWindowPos3fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat const  *)>(getProcAddress("glWindowPos3fv"));
	assert(glWindowPos3fv_ != nullptr);
	return glWindowPos3fv_(v);
}
void glWindowPos3i(GLint x, GLint y, GLint z) {
	static const auto glWindowPos3i_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLint, GLint)>(getProcAddress("glWindowPos3i"));
	assert(glWindowPos3i_ != nullptr);
	return glWindowPos3i_(x, y, z);
}
void glWindowPos3iv(GLint const  * v) {
	static const auto glWindowPos3iv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint const  *)>(getProcAddress("glWindowPos3iv"));
	assert(glWindowPos3iv_ != nullptr);
	return glWindowPos3iv_(v);
}
void glWindowPos3s(GLshort x, GLshort y, GLshort z) {
	static const auto glWindowPos3s_ = reinterpret_cast<void(GL_APIENTRYP)(GLshort, GLshort, GLshort)>(getProcAddress("glWindowPos3s"));
	assert(glWindowPos3s_ != nullptr);
	return glWindowPos3s_(x, y, z);
}
void glWindowPos3sv(GLshort const  * v) {
	static const auto glWindowPos3sv_ = reinterpret_cast<void(GL_APIENTRYP)(GLshort const  *)>(getProcAddress("glWindowPos3sv"));
	assert(glWindowPos3sv_ != nullptr);
	return glWindowPos3sv_(v);
}
void glBlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
	static const auto glBlendColor_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat, GLfloat, GLfloat, GLfloat)>(getProcAddress("glBlendColor"));
	assert(glBlendColor_ != nullptr);
	return glBlendColor_(red, green, blue, alpha);
}
void glBlendEquation(GLenum mode) {
	static const auto glBlendEquation_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glBlendEquation"));
	assert(glBlendEquation_ != nullptr);
	return glBlendEquation_(mode);
}
void glGenQueries(GLsizei n, GLuint * ids) {
	static const auto glGenQueries_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint *)>(getProcAddress("glGenQueries"));
	assert(glGenQueries_ != nullptr);
	return glGenQueries_(n, ids);
}
void glDeleteQueries(GLsizei n, GLuint const  * ids) {
	static const auto glDeleteQueries_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint const  *)>(getProcAddress("glDeleteQueries"));
	assert(glDeleteQueries_ != nullptr);
	return glDeleteQueries_(n, ids);
}
GLboolean glIsQuery(GLuint id) {
	static const auto glIsQuery_ = reinterpret_cast<GLboolean(GL_APIENTRYP)(GLuint)>(getProcAddress("glIsQuery"));
	assert(glIsQuery_ != nullptr);
	return glIsQuery_(id);
}
void glBeginQuery(GLenum target, GLuint id) {
	static const auto glBeginQuery_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint)>(getProcAddress("glBeginQuery"));
	assert(glBeginQuery_ != nullptr);
	return glBeginQuery_(target, id);
}
void glEndQuery(GLenum target) {
	static const auto glEndQuery_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glEndQuery"));
	assert(glEndQuery_ != nullptr);
	return glEndQuery_(target);
}
void glGetQueryiv(GLenum target, GLenum pname, GLint * params) {
	static const auto glGetQueryiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint *)>(getProcAddress("glGetQueryiv"));
	assert(glGetQueryiv_ != nullptr);
	return glGetQueryiv_(target, pname, params);
}
void glGetQueryObjectiv(GLuint id, GLenum pname, GLint * params) {
	static const auto glGetQueryObjectiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint *)>(getProcAddress("glGetQueryObjectiv"));
	assert(glGetQueryObjectiv_ != nullptr);
	return glGetQueryObjectiv_(id, pname, params);
}
void glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint * params) {
	static const auto glGetQueryObjectuiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLuint *)>(getProcAddress("glGetQueryObjectuiv"));
	assert(glGetQueryObjectuiv_ != nullptr);
	return glGetQueryObjectuiv_(id, pname, params);
}
void glBindBuffer(GLenum target, GLuint buffer) {
	static const auto glBindBuffer_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint)>(getProcAddress("glBindBuffer"));
	assert(glBindBuffer_ != nullptr);
	return glBindBuffer_(target, buffer);
}
void glDeleteBuffers(GLsizei n, GLuint const  * buffers) {
	static const auto glDeleteBuffers_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint const  *)>(getProcAddress("glDeleteBuffers"));
	assert(glDeleteBuffers_ != nullptr);
	return glDeleteBuffers_(n, buffers);
}
void glGenBuffers(GLsizei n, GLuint * buffers) {
	static const auto glGenBuffers_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint *)>(getProcAddress("glGenBuffers"));
	assert(glGenBuffers_ != nullptr);
	return glGenBuffers_(n, buffers);
}
GLboolean glIsBuffer(GLuint buffer) {
	static const auto glIsBuffer_ = reinterpret_cast<GLboolean(GL_APIENTRYP)(GLuint)>(getProcAddress("glIsBuffer"));
	assert(glIsBuffer_ != nullptr);
	return glIsBuffer_(buffer);
}
void glBufferData(GLenum target, GLsizeiptr size, const void * data, GLenum usage) {
	static const auto glBufferData_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizeiptr, const void *, GLenum)>(getProcAddress("glBufferData"));
	assert(glBufferData_ != nullptr);
	return glBufferData_(target, size, data, usage);
}
void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const void * data) {
	static const auto glBufferSubData_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLintptr, GLsizeiptr, const void *)>(getProcAddress("glBufferSubData"));
	assert(glBufferSubData_ != nullptr);
	return glBufferSubData_(target, offset, size, data);
}
void glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, void * data) {
	static const auto glGetBufferSubData_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLintptr, GLsizeiptr, void *)>(getProcAddress("glGetBufferSubData"));
	assert(glGetBufferSubData_ != nullptr);
	return glGetBufferSubData_(target, offset, size, data);
}
void * glMapBuffer(GLenum target, GLenum access) {
	static const auto glMapBuffer_ = reinterpret_cast<void *(GL_APIENTRYP)(GLenum, GLenum)>(getProcAddress("glMapBuffer"));
	assert(glMapBuffer_ != nullptr);
	return glMapBuffer_(target, access);
}
GLboolean glUnmapBuffer(GLenum target) {
	static const auto glUnmapBuffer_ = reinterpret_cast<GLboolean(GL_APIENTRYP)(GLenum)>(getProcAddress("glUnmapBuffer"));
	assert(glUnmapBuffer_ != nullptr);
	return glUnmapBuffer_(target);
}
void glGetBufferParameteriv(GLenum target, GLenum pname, GLint * params) {
	static const auto glGetBufferParameteriv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint *)>(getProcAddress("glGetBufferParameteriv"));
	assert(glGetBufferParameteriv_ != nullptr);
	return glGetBufferParameteriv_(target, pname, params);
}
void glGetBufferPointerv(GLenum target, GLenum pname, void ** params) {
	static const auto glGetBufferPointerv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, void **)>(getProcAddress("glGetBufferPointerv"));
	assert(glGetBufferPointerv_ != nullptr);
	return glGetBufferPointerv_(target, pname, params);
}
void glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha) {
	static const auto glBlendEquationSeparate_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum)>(getProcAddress("glBlendEquationSeparate"));
	assert(glBlendEquationSeparate_ != nullptr);
	return glBlendEquationSeparate_(modeRGB, modeAlpha);
}
void glDrawBuffers(GLsizei n, GLenum const  * bufs) {
	static const auto glDrawBuffers_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLenum const  *)>(getProcAddress("glDrawBuffers"));
	assert(glDrawBuffers_ != nullptr);
	return glDrawBuffers_(n, bufs);
}
void glStencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass) {
	static const auto glStencilOpSeparate_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLenum)>(getProcAddress("glStencilOpSeparate"));
	assert(glStencilOpSeparate_ != nullptr);
	return glStencilOpSeparate_(face, sfail, dpfail, dppass);
}
void glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask) {
	static const auto glStencilFuncSeparate_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint, GLuint)>(getProcAddress("glStencilFuncSeparate"));
	assert(glStencilFuncSeparate_ != nullptr);
	return glStencilFuncSeparate_(face, func, ref, mask);
}
void glStencilMaskSeparate(GLenum face, GLuint mask) {
	static const auto glStencilMaskSeparate_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint)>(getProcAddress("glStencilMaskSeparate"));
	assert(glStencilMaskSeparate_ != nullptr);
	return glStencilMaskSeparate_(face, mask);
}
void glAttachShader(GLuint program, GLuint shader) {
	static const auto glAttachShader_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint)>(getProcAddress("glAttachShader"));
	assert(glAttachShader_ != nullptr);
	return glAttachShader_(program, shader);
}
void glBindAttribLocation(GLuint program, GLuint index, GLchar const  * name) {
	static const auto glBindAttribLocation_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLchar const  *)>(getProcAddress("glBindAttribLocation"));
	assert(glBindAttribLocation_ != nullptr);
	return glBindAttribLocation_(program, index, name);
}
void glCompileShader(GLuint shader) {
	static const auto glCompileShader_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint)>(getProcAddress("glCompileShader"));
	assert(glCompileShader_ != nullptr);
	return glCompileShader_(shader);
}
GLuint glCreateProgram() {
	static const auto glCreateProgram_ = reinterpret_cast<GLuint(GL_APIENTRYP)()>(getProcAddress("glCreateProgram"));
	assert(glCreateProgram_ != nullptr);
	return glCreateProgram_();
}
GLuint glCreateShader(GLenum type) {
	static const auto glCreateShader_ = reinterpret_cast<GLuint(GL_APIENTRYP)(GLenum)>(getProcAddress("glCreateShader"));
	assert(glCreateShader_ != nullptr);
	return glCreateShader_(type);
}
void glDeleteProgram(GLuint program) {
	static const auto glDeleteProgram_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint)>(getProcAddress("glDeleteProgram"));
	assert(glDeleteProgram_ != nullptr);
	return glDeleteProgram_(program);
}
void glDeleteShader(GLuint shader) {
	static const auto glDeleteShader_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint)>(getProcAddress("glDeleteShader"));
	assert(glDeleteShader_ != nullptr);
	return glDeleteShader_(shader);
}
void glDetachShader(GLuint program, GLuint shader) {
	static const auto glDetachShader_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint)>(getProcAddress("glDetachShader"));
	assert(glDetachShader_ != nullptr);
	return glDetachShader_(program, shader);
}
void glDisableVertexAttribArray(GLuint index) {
	static const auto glDisableVertexAttribArray_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint)>(getProcAddress("glDisableVertexAttribArray"));
	assert(glDisableVertexAttribArray_ != nullptr);
	return glDisableVertexAttribArray_(index);
}
void glEnableVertexAttribArray(GLuint index) {
	static const auto glEnableVertexAttribArray_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint)>(getProcAddress("glEnableVertexAttribArray"));
	assert(glEnableVertexAttribArray_ != nullptr);
	return glEnableVertexAttribArray_(index);
}
void glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name) {
	static const auto glGetActiveAttrib_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLchar *)>(getProcAddress("glGetActiveAttrib"));
	assert(glGetActiveAttrib_ != nullptr);
	return glGetActiveAttrib_(program, index, bufSize, length, size, type, name);
}
void glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name) {
	static const auto glGetActiveUniform_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLchar *)>(getProcAddress("glGetActiveUniform"));
	assert(glGetActiveUniform_ != nullptr);
	return glGetActiveUniform_(program, index, bufSize, length, size, type, name);
}
void glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei * count, GLuint * shaders) {
	static const auto glGetAttachedShaders_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLsizei, GLsizei *, GLuint *)>(getProcAddress("glGetAttachedShaders"));
	assert(glGetAttachedShaders_ != nullptr);
	return glGetAttachedShaders_(program, maxCount, count, shaders);
}
GLint glGetAttribLocation(GLuint program, GLchar const  * name) {
	static const auto glGetAttribLocation_ = reinterpret_cast<GLint(GL_APIENTRYP)(GLuint, GLchar const  *)>(getProcAddress("glGetAttribLocation"));
	assert(glGetAttribLocation_ != nullptr);
	return glGetAttribLocation_(program, name);
}
void glGetProgramiv(GLuint program, GLenum pname, GLint * params) {
	static const auto glGetProgramiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint *)>(getProcAddress("glGetProgramiv"));
	assert(glGetProgramiv_ != nullptr);
	return glGetProgramiv_(program, pname, params);
}
void glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei * length, GLchar * infoLog) {
	static const auto glGetProgramInfoLog_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLsizei, GLsizei *, GLchar *)>(getProcAddress("glGetProgramInfoLog"));
	assert(glGetProgramInfoLog_ != nullptr);
	return glGetProgramInfoLog_(program, bufSize, length, infoLog);
}
void glGetShaderiv(GLuint shader, GLenum pname, GLint * params) {
	static const auto glGetShaderiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint *)>(getProcAddress("glGetShaderiv"));
	assert(glGetShaderiv_ != nullptr);
	return glGetShaderiv_(shader, pname, params);
}
void glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * infoLog) {
	static const auto glGetShaderInfoLog_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLsizei, GLsizei *, GLchar *)>(getProcAddress("glGetShaderInfoLog"));
	assert(glGetShaderInfoLog_ != nullptr);
	return glGetShaderInfoLog_(shader, bufSize, length, infoLog);
}
void glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * source) {
	static const auto glGetShaderSource_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLsizei, GLsizei *, GLchar *)>(getProcAddress("glGetShaderSource"));
	assert(glGetShaderSource_ != nullptr);
	return glGetShaderSource_(shader, bufSize, length, source);
}
GLint glGetUniformLocation(GLuint program, GLchar const  * name) {
	static const auto glGetUniformLocation_ = reinterpret_cast<GLint(GL_APIENTRYP)(GLuint, GLchar const  *)>(getProcAddress("glGetUniformLocation"));
	assert(glGetUniformLocation_ != nullptr);
	return glGetUniformLocation_(program, name);
}
void glGetUniformfv(GLuint program, GLint location, GLfloat * params) {
	static const auto glGetUniformfv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLfloat *)>(getProcAddress("glGetUniformfv"));
	assert(glGetUniformfv_ != nullptr);
	return glGetUniformfv_(program, location, params);
}
void glGetUniformiv(GLuint program, GLint location, GLint * params) {
	static const auto glGetUniformiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLint *)>(getProcAddress("glGetUniformiv"));
	assert(glGetUniformiv_ != nullptr);
	return glGetUniformiv_(program, location, params);
}
void glGetVertexAttribdv(GLuint index, GLenum pname, GLdouble * params) {
	static const auto glGetVertexAttribdv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLdouble *)>(getProcAddress("glGetVertexAttribdv"));
	assert(glGetVertexAttribdv_ != nullptr);
	return glGetVertexAttribdv_(index, pname, params);
}
void glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat * params) {
	static const auto glGetVertexAttribfv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLfloat *)>(getProcAddress("glGetVertexAttribfv"));
	assert(glGetVertexAttribfv_ != nullptr);
	return glGetVertexAttribfv_(index, pname, params);
}
void glGetVertexAttribiv(GLuint index, GLenum pname, GLint * params) {
	static const auto glGetVertexAttribiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint *)>(getProcAddress("glGetVertexAttribiv"));
	assert(glGetVertexAttribiv_ != nullptr);
	return glGetVertexAttribiv_(index, pname, params);
}
void glGetVertexAttribPointerv(GLuint index, GLenum pname, void ** pointer) {
	static const auto glGetVertexAttribPointerv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, void **)>(getProcAddress("glGetVertexAttribPointerv"));
	assert(glGetVertexAttribPointerv_ != nullptr);
	return glGetVertexAttribPointerv_(index, pname, pointer);
}
GLboolean glIsProgram(GLuint program) {
	static const auto glIsProgram_ = reinterpret_cast<GLboolean(GL_APIENTRYP)(GLuint)>(getProcAddress("glIsProgram"));
	assert(glIsProgram_ != nullptr);
	return glIsProgram_(program);
}
GLboolean glIsShader(GLuint shader) {
	static const auto glIsShader_ = reinterpret_cast<GLboolean(GL_APIENTRYP)(GLuint)>(getProcAddress("glIsShader"));
	assert(glIsShader_ != nullptr);
	return glIsShader_(shader);
}
void glLinkProgram(GLuint program) {
	static const auto glLinkProgram_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint)>(getProcAddress("glLinkProgram"));
	assert(glLinkProgram_ != nullptr);
	return glLinkProgram_(program);
}
void glShaderSource(GLuint shader, GLsizei count, GLchar const  *const* string, GLint const  * length) {
	static const auto glShaderSource_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLsizei, GLchar const  *const*, GLint const  *)>(getProcAddress("glShaderSource"));
	assert(glShaderSource_ != nullptr);
	return glShaderSource_(shader, count, string, length);
}
void glUseProgram(GLuint program) {
	static const auto glUseProgram_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint)>(getProcAddress("glUseProgram"));
	assert(glUseProgram_ != nullptr);
	return glUseProgram_(program);
}
void glUniform1f(GLint location, GLfloat v0) {
	static const auto glUniform1f_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLfloat)>(getProcAddress("glUniform1f"));
	assert(glUniform1f_ != nullptr);
	return glUniform1f_(location, v0);
}
void glUniform2f(GLint location, GLfloat v0, GLfloat v1) {
	static const auto glUniform2f_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLfloat, GLfloat)>(getProcAddress("glUniform2f"));
	assert(glUniform2f_ != nullptr);
	return glUniform2f_(location, v0, v1);
}
void glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) {
	static const auto glUniform3f_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLfloat, GLfloat, GLfloat)>(getProcAddress("glUniform3f"));
	assert(glUniform3f_ != nullptr);
	return glUniform3f_(location, v0, v1, v2);
}
void glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {
	static const auto glUniform4f_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLfloat, GLfloat, GLfloat, GLfloat)>(getProcAddress("glUniform4f"));
	assert(glUniform4f_ != nullptr);
	return glUniform4f_(location, v0, v1, v2, v3);
}
void glUniform1i(GLint location, GLint v0) {
	static const auto glUniform1i_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLint)>(getProcAddress("glUniform1i"));
	assert(glUniform1i_ != nullptr);
	return glUniform1i_(location, v0);
}
void glUniform2i(GLint location, GLint v0, GLint v1) {
	static const auto glUniform2i_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLint, GLint)>(getProcAddress("glUniform2i"));
	assert(glUniform2i_ != nullptr);
	return glUniform2i_(location, v0, v1);
}
void glUniform3i(GLint location, GLint v0, GLint v1, GLint v2) {
	static const auto glUniform3i_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLint, GLint, GLint)>(getProcAddress("glUniform3i"));
	assert(glUniform3i_ != nullptr);
	return glUniform3i_(location, v0, v1, v2);
}
void glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) {
	static const auto glUniform4i_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLint, GLint, GLint, GLint)>(getProcAddress("glUniform4i"));
	assert(glUniform4i_ != nullptr);
	return glUniform4i_(location, v0, v1, v2, v3);
}
void glUniform1fv(GLint location, GLsizei count, GLfloat const  * value) {
	static const auto glUniform1fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLfloat const  *)>(getProcAddress("glUniform1fv"));
	assert(glUniform1fv_ != nullptr);
	return glUniform1fv_(location, count, value);
}
void glUniform2fv(GLint location, GLsizei count, GLfloat const  * value) {
	static const auto glUniform2fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLfloat const  *)>(getProcAddress("glUniform2fv"));
	assert(glUniform2fv_ != nullptr);
	return glUniform2fv_(location, count, value);
}
void glUniform3fv(GLint location, GLsizei count, GLfloat const  * value) {
	static const auto glUniform3fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLfloat const  *)>(getProcAddress("glUniform3fv"));
	assert(glUniform3fv_ != nullptr);
	return glUniform3fv_(location, count, value);
}
void glUniform4fv(GLint location, GLsizei count, GLfloat const  * value) {
	static const auto glUniform4fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLfloat const  *)>(getProcAddress("glUniform4fv"));
	assert(glUniform4fv_ != nullptr);
	return glUniform4fv_(location, count, value);
}
void glUniform1iv(GLint location, GLsizei count, GLint const  * value) {
	static const auto glUniform1iv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLint const  *)>(getProcAddress("glUniform1iv"));
	assert(glUniform1iv_ != nullptr);
	return glUniform1iv_(location, count, value);
}
void glUniform2iv(GLint location, GLsizei count, GLint const  * value) {
	static const auto glUniform2iv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLint const  *)>(getProcAddress("glUniform2iv"));
	assert(glUniform2iv_ != nullptr);
	return glUniform2iv_(location, count, value);
}
void glUniform3iv(GLint location, GLsizei count, GLint const  * value) {
	static const auto glUniform3iv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLint const  *)>(getProcAddress("glUniform3iv"));
	assert(glUniform3iv_ != nullptr);
	return glUniform3iv_(location, count, value);
}
void glUniform4iv(GLint location, GLsizei count, GLint const  * value) {
	static const auto glUniform4iv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLint const  *)>(getProcAddress("glUniform4iv"));
	assert(glUniform4iv_ != nullptr);
	return glUniform4iv_(location, count, value);
}
void glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value) {
	static const auto glUniformMatrix2fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLboolean, GLfloat const  *)>(getProcAddress("glUniformMatrix2fv"));
	assert(glUniformMatrix2fv_ != nullptr);
	return glUniformMatrix2fv_(location, count, transpose, value);
}
void glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value) {
	static const auto glUniformMatrix3fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLboolean, GLfloat const  *)>(getProcAddress("glUniformMatrix3fv"));
	assert(glUniformMatrix3fv_ != nullptr);
	return glUniformMatrix3fv_(location, count, transpose, value);
}
void glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value) {
	static const auto glUniformMatrix4fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLboolean, GLfloat const  *)>(getProcAddress("glUniformMatrix4fv"));
	assert(glUniformMatrix4fv_ != nullptr);
	return glUniformMatrix4fv_(location, count, transpose, value);
}
void glValidateProgram(GLuint program) {
	static const auto glValidateProgram_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint)>(getProcAddress("glValidateProgram"));
	assert(glValidateProgram_ != nullptr);
	return glValidateProgram_(program);
}
void glVertexAttrib1d(GLuint index, GLdouble x) {
	static const auto glVertexAttrib1d_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLdouble)>(getProcAddress("glVertexAttrib1d"));
	assert(glVertexAttrib1d_ != nullptr);
	return glVertexAttrib1d_(index, x);
}
void glVertexAttrib1dv(GLuint index, GLdouble const  * v) {
	static const auto glVertexAttrib1dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLdouble const  *)>(getProcAddress("glVertexAttrib1dv"));
	assert(glVertexAttrib1dv_ != nullptr);
	return glVertexAttrib1dv_(index, v);
}
void glVertexAttrib1f(GLuint index, GLfloat x) {
	static const auto glVertexAttrib1f_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLfloat)>(getProcAddress("glVertexAttrib1f"));
	assert(glVertexAttrib1f_ != nullptr);
	return glVertexAttrib1f_(index, x);
}
void glVertexAttrib1fv(GLuint index, GLfloat const  * v) {
	static const auto glVertexAttrib1fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLfloat const  *)>(getProcAddress("glVertexAttrib1fv"));
	assert(glVertexAttrib1fv_ != nullptr);
	return glVertexAttrib1fv_(index, v);
}
void glVertexAttrib1s(GLuint index, GLshort x) {
	static const auto glVertexAttrib1s_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLshort)>(getProcAddress("glVertexAttrib1s"));
	assert(glVertexAttrib1s_ != nullptr);
	return glVertexAttrib1s_(index, x);
}
void glVertexAttrib1sv(GLuint index, GLshort const  * v) {
	static const auto glVertexAttrib1sv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLshort const  *)>(getProcAddress("glVertexAttrib1sv"));
	assert(glVertexAttrib1sv_ != nullptr);
	return glVertexAttrib1sv_(index, v);
}
void glVertexAttrib2d(GLuint index, GLdouble x, GLdouble y) {
	static const auto glVertexAttrib2d_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLdouble, GLdouble)>(getProcAddress("glVertexAttrib2d"));
	assert(glVertexAttrib2d_ != nullptr);
	return glVertexAttrib2d_(index, x, y);
}
void glVertexAttrib2dv(GLuint index, GLdouble const  * v) {
	static const auto glVertexAttrib2dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLdouble const  *)>(getProcAddress("glVertexAttrib2dv"));
	assert(glVertexAttrib2dv_ != nullptr);
	return glVertexAttrib2dv_(index, v);
}
void glVertexAttrib2f(GLuint index, GLfloat x, GLfloat y) {
	static const auto glVertexAttrib2f_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLfloat, GLfloat)>(getProcAddress("glVertexAttrib2f"));
	assert(glVertexAttrib2f_ != nullptr);
	return glVertexAttrib2f_(index, x, y);
}
void glVertexAttrib2fv(GLuint index, GLfloat const  * v) {
	static const auto glVertexAttrib2fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLfloat const  *)>(getProcAddress("glVertexAttrib2fv"));
	assert(glVertexAttrib2fv_ != nullptr);
	return glVertexAttrib2fv_(index, v);
}
void glVertexAttrib2s(GLuint index, GLshort x, GLshort y) {
	static const auto glVertexAttrib2s_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLshort, GLshort)>(getProcAddress("glVertexAttrib2s"));
	assert(glVertexAttrib2s_ != nullptr);
	return glVertexAttrib2s_(index, x, y);
}
void glVertexAttrib2sv(GLuint index, GLshort const  * v) {
	static const auto glVertexAttrib2sv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLshort const  *)>(getProcAddress("glVertexAttrib2sv"));
	assert(glVertexAttrib2sv_ != nullptr);
	return glVertexAttrib2sv_(index, v);
}
void glVertexAttrib3d(GLuint index, GLdouble x, GLdouble y, GLdouble z) {
	static const auto glVertexAttrib3d_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLdouble, GLdouble, GLdouble)>(getProcAddress("glVertexAttrib3d"));
	assert(glVertexAttrib3d_ != nullptr);
	return glVertexAttrib3d_(index, x, y, z);
}
void glVertexAttrib3dv(GLuint index, GLdouble const  * v) {
	static const auto glVertexAttrib3dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLdouble const  *)>(getProcAddress("glVertexAttrib3dv"));
	assert(glVertexAttrib3dv_ != nullptr);
	return glVertexAttrib3dv_(index, v);
}
void glVertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z) {
	static const auto glVertexAttrib3f_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLfloat, GLfloat, GLfloat)>(getProcAddress("glVertexAttrib3f"));
	assert(glVertexAttrib3f_ != nullptr);
	return glVertexAttrib3f_(index, x, y, z);
}
void glVertexAttrib3fv(GLuint index, GLfloat const  * v) {
	static const auto glVertexAttrib3fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLfloat const  *)>(getProcAddress("glVertexAttrib3fv"));
	assert(glVertexAttrib3fv_ != nullptr);
	return glVertexAttrib3fv_(index, v);
}
void glVertexAttrib3s(GLuint index, GLshort x, GLshort y, GLshort z) {
	static const auto glVertexAttrib3s_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLshort, GLshort, GLshort)>(getProcAddress("glVertexAttrib3s"));
	assert(glVertexAttrib3s_ != nullptr);
	return glVertexAttrib3s_(index, x, y, z);
}
void glVertexAttrib3sv(GLuint index, GLshort const  * v) {
	static const auto glVertexAttrib3sv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLshort const  *)>(getProcAddress("glVertexAttrib3sv"));
	assert(glVertexAttrib3sv_ != nullptr);
	return glVertexAttrib3sv_(index, v);
}
void glVertexAttrib4Nbv(GLuint index, GLbyte const  * v) {
	static const auto glVertexAttrib4Nbv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLbyte const  *)>(getProcAddress("glVertexAttrib4Nbv"));
	assert(glVertexAttrib4Nbv_ != nullptr);
	return glVertexAttrib4Nbv_(index, v);
}
void glVertexAttrib4Niv(GLuint index, GLint const  * v) {
	static const auto glVertexAttrib4Niv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint const  *)>(getProcAddress("glVertexAttrib4Niv"));
	assert(glVertexAttrib4Niv_ != nullptr);
	return glVertexAttrib4Niv_(index, v);
}
void glVertexAttrib4Nsv(GLuint index, GLshort const  * v) {
	static const auto glVertexAttrib4Nsv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLshort const  *)>(getProcAddress("glVertexAttrib4Nsv"));
	assert(glVertexAttrib4Nsv_ != nullptr);
	return glVertexAttrib4Nsv_(index, v);
}
void glVertexAttrib4Nub(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w) {
	static const auto glVertexAttrib4Nub_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLubyte, GLubyte, GLubyte, GLubyte)>(getProcAddress("glVertexAttrib4Nub"));
	assert(glVertexAttrib4Nub_ != nullptr);
	return glVertexAttrib4Nub_(index, x, y, z, w);
}
void glVertexAttrib4Nubv(GLuint index, GLubyte const  * v) {
	static const auto glVertexAttrib4Nubv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLubyte const  *)>(getProcAddress("glVertexAttrib4Nubv"));
	assert(glVertexAttrib4Nubv_ != nullptr);
	return glVertexAttrib4Nubv_(index, v);
}
void glVertexAttrib4Nuiv(GLuint index, GLuint const  * v) {
	static const auto glVertexAttrib4Nuiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint const  *)>(getProcAddress("glVertexAttrib4Nuiv"));
	assert(glVertexAttrib4Nuiv_ != nullptr);
	return glVertexAttrib4Nuiv_(index, v);
}
void glVertexAttrib4Nusv(GLuint index, GLushort const  * v) {
	static const auto glVertexAttrib4Nusv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLushort const  *)>(getProcAddress("glVertexAttrib4Nusv"));
	assert(glVertexAttrib4Nusv_ != nullptr);
	return glVertexAttrib4Nusv_(index, v);
}
void glVertexAttrib4bv(GLuint index, GLbyte const  * v) {
	static const auto glVertexAttrib4bv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLbyte const  *)>(getProcAddress("glVertexAttrib4bv"));
	assert(glVertexAttrib4bv_ != nullptr);
	return glVertexAttrib4bv_(index, v);
}
void glVertexAttrib4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
	static const auto glVertexAttrib4d_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLdouble, GLdouble, GLdouble, GLdouble)>(getProcAddress("glVertexAttrib4d"));
	assert(glVertexAttrib4d_ != nullptr);
	return glVertexAttrib4d_(index, x, y, z, w);
}
void glVertexAttrib4dv(GLuint index, GLdouble const  * v) {
	static const auto glVertexAttrib4dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLdouble const  *)>(getProcAddress("glVertexAttrib4dv"));
	assert(glVertexAttrib4dv_ != nullptr);
	return glVertexAttrib4dv_(index, v);
}
void glVertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
	static const auto glVertexAttrib4f_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat)>(getProcAddress("glVertexAttrib4f"));
	assert(glVertexAttrib4f_ != nullptr);
	return glVertexAttrib4f_(index, x, y, z, w);
}
void glVertexAttrib4fv(GLuint index, GLfloat const  * v) {
	static const auto glVertexAttrib4fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLfloat const  *)>(getProcAddress("glVertexAttrib4fv"));
	assert(glVertexAttrib4fv_ != nullptr);
	return glVertexAttrib4fv_(index, v);
}
void glVertexAttrib4iv(GLuint index, GLint const  * v) {
	static const auto glVertexAttrib4iv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint const  *)>(getProcAddress("glVertexAttrib4iv"));
	assert(glVertexAttrib4iv_ != nullptr);
	return glVertexAttrib4iv_(index, v);
}
void glVertexAttrib4s(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w) {
	static const auto glVertexAttrib4s_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLshort, GLshort, GLshort, GLshort)>(getProcAddress("glVertexAttrib4s"));
	assert(glVertexAttrib4s_ != nullptr);
	return glVertexAttrib4s_(index, x, y, z, w);
}
void glVertexAttrib4sv(GLuint index, GLshort const  * v) {
	static const auto glVertexAttrib4sv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLshort const  *)>(getProcAddress("glVertexAttrib4sv"));
	assert(glVertexAttrib4sv_ != nullptr);
	return glVertexAttrib4sv_(index, v);
}
void glVertexAttrib4ubv(GLuint index, GLubyte const  * v) {
	static const auto glVertexAttrib4ubv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLubyte const  *)>(getProcAddress("glVertexAttrib4ubv"));
	assert(glVertexAttrib4ubv_ != nullptr);
	return glVertexAttrib4ubv_(index, v);
}
void glVertexAttrib4uiv(GLuint index, GLuint const  * v) {
	static const auto glVertexAttrib4uiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint const  *)>(getProcAddress("glVertexAttrib4uiv"));
	assert(glVertexAttrib4uiv_ != nullptr);
	return glVertexAttrib4uiv_(index, v);
}
void glVertexAttrib4usv(GLuint index, GLushort const  * v) {
	static const auto glVertexAttrib4usv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLushort const  *)>(getProcAddress("glVertexAttrib4usv"));
	assert(glVertexAttrib4usv_ != nullptr);
	return glVertexAttrib4usv_(index, v);
}
void glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void * pointer) {
	static const auto glVertexAttribPointer_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLenum, GLboolean, GLsizei, const void *)>(getProcAddress("glVertexAttribPointer"));
	assert(glVertexAttribPointer_ != nullptr);
	return glVertexAttribPointer_(index, size, type, normalized, stride, pointer);
}
void glUniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value) {
	static const auto glUniformMatrix2x3fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLboolean, GLfloat const  *)>(getProcAddress("glUniformMatrix2x3fv"));
	assert(glUniformMatrix2x3fv_ != nullptr);
	return glUniformMatrix2x3fv_(location, count, transpose, value);
}
void glUniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value) {
	static const auto glUniformMatrix3x2fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLboolean, GLfloat const  *)>(getProcAddress("glUniformMatrix3x2fv"));
	assert(glUniformMatrix3x2fv_ != nullptr);
	return glUniformMatrix3x2fv_(location, count, transpose, value);
}
void glUniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value) {
	static const auto glUniformMatrix2x4fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLboolean, GLfloat const  *)>(getProcAddress("glUniformMatrix2x4fv"));
	assert(glUniformMatrix2x4fv_ != nullptr);
	return glUniformMatrix2x4fv_(location, count, transpose, value);
}
void glUniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value) {
	static const auto glUniformMatrix4x2fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLboolean, GLfloat const  *)>(getProcAddress("glUniformMatrix4x2fv"));
	assert(glUniformMatrix4x2fv_ != nullptr);
	return glUniformMatrix4x2fv_(location, count, transpose, value);
}
void glUniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value) {
	static const auto glUniformMatrix3x4fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLboolean, GLfloat const  *)>(getProcAddress("glUniformMatrix3x4fv"));
	assert(glUniformMatrix3x4fv_ != nullptr);
	return glUniformMatrix3x4fv_(location, count, transpose, value);
}
void glUniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value) {
	static const auto glUniformMatrix4x3fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLboolean, GLfloat const  *)>(getProcAddress("glUniformMatrix4x3fv"));
	assert(glUniformMatrix4x3fv_ != nullptr);
	return glUniformMatrix4x3fv_(location, count, transpose, value);
}
void glColorMaski(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a) {
	static const auto glColorMaski_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLboolean, GLboolean, GLboolean, GLboolean)>(getProcAddress("glColorMaski"));
	assert(glColorMaski_ != nullptr);
	return glColorMaski_(index, r, g, b, a);
}
void glGetBooleani_v(GLenum target, GLuint index, GLboolean * data) {
	static const auto glGetBooleani_v_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint, GLboolean *)>(getProcAddress("glGetBooleani_v"));
	assert(glGetBooleani_v_ != nullptr);
	return glGetBooleani_v_(target, index, data);
}
void glGetIntegeri_v(GLenum target, GLuint index, GLint * data) {
	static const auto glGetIntegeri_v_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint, GLint *)>(getProcAddress("glGetIntegeri_v"));
	assert(glGetIntegeri_v_ != nullptr);
	return glGetIntegeri_v_(target, index, data);
}
void glEnablei(GLenum target, GLuint index) {
	static const auto glEnablei_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint)>(getProcAddress("glEnablei"));
	assert(glEnablei_ != nullptr);
	return glEnablei_(target, index);
}
void glDisablei(GLenum target, GLuint index) {
	static const auto glDisablei_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint)>(getProcAddress("glDisablei"));
	assert(glDisablei_ != nullptr);
	return glDisablei_(target, index);
}
GLboolean glIsEnabledi(GLenum target, GLuint index) {
	static const auto glIsEnabledi_ = reinterpret_cast<GLboolean(GL_APIENTRYP)(GLenum, GLuint)>(getProcAddress("glIsEnabledi"));
	assert(glIsEnabledi_ != nullptr);
	return glIsEnabledi_(target, index);
}
void glBeginTransformFeedback(GLenum primitiveMode) {
	static const auto glBeginTransformFeedback_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glBeginTransformFeedback"));
	assert(glBeginTransformFeedback_ != nullptr);
	return glBeginTransformFeedback_(primitiveMode);
}
void glEndTransformFeedback() {
	static const auto glEndTransformFeedback_ = reinterpret_cast<void(GL_APIENTRYP)()>(getProcAddress("glEndTransformFeedback"));
	assert(glEndTransformFeedback_ != nullptr);
	return glEndTransformFeedback_();
}
void glBindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) {
	static const auto glBindBufferRange_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint, GLuint, GLintptr, GLsizeiptr)>(getProcAddress("glBindBufferRange"));
	assert(glBindBufferRange_ != nullptr);
	return glBindBufferRange_(target, index, buffer, offset, size);
}
void glBindBufferBase(GLenum target, GLuint index, GLuint buffer) {
	static const auto glBindBufferBase_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint, GLuint)>(getProcAddress("glBindBufferBase"));
	assert(glBindBufferBase_ != nullptr);
	return glBindBufferBase_(target, index, buffer);
}
void glTransformFeedbackVaryings(GLuint program, GLsizei count, GLchar const  *const* varyings, GLenum bufferMode) {
	static const auto glTransformFeedbackVaryings_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLsizei, GLchar const  *const*, GLenum)>(getProcAddress("glTransformFeedbackVaryings"));
	assert(glTransformFeedbackVaryings_ != nullptr);
	return glTransformFeedbackVaryings_(program, count, varyings, bufferMode);
}
void glGetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLsizei * size, GLenum * type, GLchar * name) {
	static const auto glGetTransformFeedbackVarying_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLsizei, GLsizei *, GLsizei *, GLenum *, GLchar *)>(getProcAddress("glGetTransformFeedbackVarying"));
	assert(glGetTransformFeedbackVarying_ != nullptr);
	return glGetTransformFeedbackVarying_(program, index, bufSize, length, size, type, name);
}
void glClampColor(GLenum target, GLenum clamp) {
	static const auto glClampColor_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum)>(getProcAddress("glClampColor"));
	assert(glClampColor_ != nullptr);
	return glClampColor_(target, clamp);
}
void glBeginConditionalRender(GLuint id, GLenum mode) {
	static const auto glBeginConditionalRender_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum)>(getProcAddress("glBeginConditionalRender"));
	assert(glBeginConditionalRender_ != nullptr);
	return glBeginConditionalRender_(id, mode);
}
void glEndConditionalRender() {
	static const auto glEndConditionalRender_ = reinterpret_cast<void(GL_APIENTRYP)()>(getProcAddress("glEndConditionalRender"));
	assert(glEndConditionalRender_ != nullptr);
	return glEndConditionalRender_();
}
void glVertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void * pointer) {
	static const auto glVertexAttribIPointer_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLenum, GLsizei, const void *)>(getProcAddress("glVertexAttribIPointer"));
	assert(glVertexAttribIPointer_ != nullptr);
	return glVertexAttribIPointer_(index, size, type, stride, pointer);
}
void glGetVertexAttribIiv(GLuint index, GLenum pname, GLint * params) {
	static const auto glGetVertexAttribIiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint *)>(getProcAddress("glGetVertexAttribIiv"));
	assert(glGetVertexAttribIiv_ != nullptr);
	return glGetVertexAttribIiv_(index, pname, params);
}
void glGetVertexAttribIuiv(GLuint index, GLenum pname, GLuint * params) {
	static const auto glGetVertexAttribIuiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLuint *)>(getProcAddress("glGetVertexAttribIuiv"));
	assert(glGetVertexAttribIuiv_ != nullptr);
	return glGetVertexAttribIuiv_(index, pname, params);
}
void glVertexAttribI1i(GLuint index, GLint x) {
	static const auto glVertexAttribI1i_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint)>(getProcAddress("glVertexAttribI1i"));
	assert(glVertexAttribI1i_ != nullptr);
	return glVertexAttribI1i_(index, x);
}
void glVertexAttribI2i(GLuint index, GLint x, GLint y) {
	static const auto glVertexAttribI2i_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLint)>(getProcAddress("glVertexAttribI2i"));
	assert(glVertexAttribI2i_ != nullptr);
	return glVertexAttribI2i_(index, x, y);
}
void glVertexAttribI3i(GLuint index, GLint x, GLint y, GLint z) {
	static const auto glVertexAttribI3i_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLint, GLint)>(getProcAddress("glVertexAttribI3i"));
	assert(glVertexAttribI3i_ != nullptr);
	return glVertexAttribI3i_(index, x, y, z);
}
void glVertexAttribI4i(GLuint index, GLint x, GLint y, GLint z, GLint w) {
	static const auto glVertexAttribI4i_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLint, GLint, GLint)>(getProcAddress("glVertexAttribI4i"));
	assert(glVertexAttribI4i_ != nullptr);
	return glVertexAttribI4i_(index, x, y, z, w);
}
void glVertexAttribI1ui(GLuint index, GLuint x) {
	static const auto glVertexAttribI1ui_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint)>(getProcAddress("glVertexAttribI1ui"));
	assert(glVertexAttribI1ui_ != nullptr);
	return glVertexAttribI1ui_(index, x);
}
void glVertexAttribI2ui(GLuint index, GLuint x, GLuint y) {
	static const auto glVertexAttribI2ui_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLuint)>(getProcAddress("glVertexAttribI2ui"));
	assert(glVertexAttribI2ui_ != nullptr);
	return glVertexAttribI2ui_(index, x, y);
}
void glVertexAttribI3ui(GLuint index, GLuint x, GLuint y, GLuint z) {
	static const auto glVertexAttribI3ui_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLuint, GLuint)>(getProcAddress("glVertexAttribI3ui"));
	assert(glVertexAttribI3ui_ != nullptr);
	return glVertexAttribI3ui_(index, x, y, z);
}
void glVertexAttribI4ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) {
	static const auto glVertexAttribI4ui_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLuint, GLuint, GLuint)>(getProcAddress("glVertexAttribI4ui"));
	assert(glVertexAttribI4ui_ != nullptr);
	return glVertexAttribI4ui_(index, x, y, z, w);
}
void glVertexAttribI1iv(GLuint index, GLint const  * v) {
	static const auto glVertexAttribI1iv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint const  *)>(getProcAddress("glVertexAttribI1iv"));
	assert(glVertexAttribI1iv_ != nullptr);
	return glVertexAttribI1iv_(index, v);
}
void glVertexAttribI2iv(GLuint index, GLint const  * v) {
	static const auto glVertexAttribI2iv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint const  *)>(getProcAddress("glVertexAttribI2iv"));
	assert(glVertexAttribI2iv_ != nullptr);
	return glVertexAttribI2iv_(index, v);
}
void glVertexAttribI3iv(GLuint index, GLint const  * v) {
	static const auto glVertexAttribI3iv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint const  *)>(getProcAddress("glVertexAttribI3iv"));
	assert(glVertexAttribI3iv_ != nullptr);
	return glVertexAttribI3iv_(index, v);
}
void glVertexAttribI4iv(GLuint index, GLint const  * v) {
	static const auto glVertexAttribI4iv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint const  *)>(getProcAddress("glVertexAttribI4iv"));
	assert(glVertexAttribI4iv_ != nullptr);
	return glVertexAttribI4iv_(index, v);
}
void glVertexAttribI1uiv(GLuint index, GLuint const  * v) {
	static const auto glVertexAttribI1uiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint const  *)>(getProcAddress("glVertexAttribI1uiv"));
	assert(glVertexAttribI1uiv_ != nullptr);
	return glVertexAttribI1uiv_(index, v);
}
void glVertexAttribI2uiv(GLuint index, GLuint const  * v) {
	static const auto glVertexAttribI2uiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint const  *)>(getProcAddress("glVertexAttribI2uiv"));
	assert(glVertexAttribI2uiv_ != nullptr);
	return glVertexAttribI2uiv_(index, v);
}
void glVertexAttribI3uiv(GLuint index, GLuint const  * v) {
	static const auto glVertexAttribI3uiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint const  *)>(getProcAddress("glVertexAttribI3uiv"));
	assert(glVertexAttribI3uiv_ != nullptr);
	return glVertexAttribI3uiv_(index, v);
}
void glVertexAttribI4uiv(GLuint index, GLuint const  * v) {
	static const auto glVertexAttribI4uiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint const  *)>(getProcAddress("glVertexAttribI4uiv"));
	assert(glVertexAttribI4uiv_ != nullptr);
	return glVertexAttribI4uiv_(index, v);
}
void glVertexAttribI4bv(GLuint index, GLbyte const  * v) {
	static const auto glVertexAttribI4bv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLbyte const  *)>(getProcAddress("glVertexAttribI4bv"));
	assert(glVertexAttribI4bv_ != nullptr);
	return glVertexAttribI4bv_(index, v);
}
void glVertexAttribI4sv(GLuint index, GLshort const  * v) {
	static const auto glVertexAttribI4sv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLshort const  *)>(getProcAddress("glVertexAttribI4sv"));
	assert(glVertexAttribI4sv_ != nullptr);
	return glVertexAttribI4sv_(index, v);
}
void glVertexAttribI4ubv(GLuint index, GLubyte const  * v) {
	static const auto glVertexAttribI4ubv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLubyte const  *)>(getProcAddress("glVertexAttribI4ubv"));
	assert(glVertexAttribI4ubv_ != nullptr);
	return glVertexAttribI4ubv_(index, v);
}
void glVertexAttribI4usv(GLuint index, GLushort const  * v) {
	static const auto glVertexAttribI4usv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLushort const  *)>(getProcAddress("glVertexAttribI4usv"));
	assert(glVertexAttribI4usv_ != nullptr);
	return glVertexAttribI4usv_(index, v);
}
void glGetUniformuiv(GLuint program, GLint location, GLuint * params) {
	static const auto glGetUniformuiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLuint *)>(getProcAddress("glGetUniformuiv"));
	assert(glGetUniformuiv_ != nullptr);
	return glGetUniformuiv_(program, location, params);
}
void glBindFragDataLocation(GLuint program, GLuint color, GLchar const  * name) {
	static const auto glBindFragDataLocation_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLchar const  *)>(getProcAddress("glBindFragDataLocation"));
	assert(glBindFragDataLocation_ != nullptr);
	return glBindFragDataLocation_(program, color, name);
}
GLint glGetFragDataLocation(GLuint program, GLchar const  * name) {
	static const auto glGetFragDataLocation_ = reinterpret_cast<GLint(GL_APIENTRYP)(GLuint, GLchar const  *)>(getProcAddress("glGetFragDataLocation"));
	assert(glGetFragDataLocation_ != nullptr);
	return glGetFragDataLocation_(program, name);
}
void glUniform1ui(GLint location, GLuint v0) {
	static const auto glUniform1ui_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLuint)>(getProcAddress("glUniform1ui"));
	assert(glUniform1ui_ != nullptr);
	return glUniform1ui_(location, v0);
}
void glUniform2ui(GLint location, GLuint v0, GLuint v1) {
	static const auto glUniform2ui_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLuint, GLuint)>(getProcAddress("glUniform2ui"));
	assert(glUniform2ui_ != nullptr);
	return glUniform2ui_(location, v0, v1);
}
void glUniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2) {
	static const auto glUniform3ui_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLuint, GLuint, GLuint)>(getProcAddress("glUniform3ui"));
	assert(glUniform3ui_ != nullptr);
	return glUniform3ui_(location, v0, v1, v2);
}
void glUniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) {
	static const auto glUniform4ui_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLuint, GLuint, GLuint, GLuint)>(getProcAddress("glUniform4ui"));
	assert(glUniform4ui_ != nullptr);
	return glUniform4ui_(location, v0, v1, v2, v3);
}
void glUniform1uiv(GLint location, GLsizei count, GLuint const  * value) {
	static const auto glUniform1uiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLuint const  *)>(getProcAddress("glUniform1uiv"));
	assert(glUniform1uiv_ != nullptr);
	return glUniform1uiv_(location, count, value);
}
void glUniform2uiv(GLint location, GLsizei count, GLuint const  * value) {
	static const auto glUniform2uiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLuint const  *)>(getProcAddress("glUniform2uiv"));
	assert(glUniform2uiv_ != nullptr);
	return glUniform2uiv_(location, count, value);
}
void glUniform3uiv(GLint location, GLsizei count, GLuint const  * value) {
	static const auto glUniform3uiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLuint const  *)>(getProcAddress("glUniform3uiv"));
	assert(glUniform3uiv_ != nullptr);
	return glUniform3uiv_(location, count, value);
}
void glUniform4uiv(GLint location, GLsizei count, GLuint const  * value) {
	static const auto glUniform4uiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLuint const  *)>(getProcAddress("glUniform4uiv"));
	assert(glUniform4uiv_ != nullptr);
	return glUniform4uiv_(location, count, value);
}
void glTexParameterIiv(GLenum target, GLenum pname, GLint const  * params) {
	static const auto glTexParameterIiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint const  *)>(getProcAddress("glTexParameterIiv"));
	assert(glTexParameterIiv_ != nullptr);
	return glTexParameterIiv_(target, pname, params);
}
void glTexParameterIuiv(GLenum target, GLenum pname, GLuint const  * params) {
	static const auto glTexParameterIuiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLuint const  *)>(getProcAddress("glTexParameterIuiv"));
	assert(glTexParameterIuiv_ != nullptr);
	return glTexParameterIuiv_(target, pname, params);
}
void glGetTexParameterIiv(GLenum target, GLenum pname, GLint * params) {
	static const auto glGetTexParameterIiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint *)>(getProcAddress("glGetTexParameterIiv"));
	assert(glGetTexParameterIiv_ != nullptr);
	return glGetTexParameterIiv_(target, pname, params);
}
void glGetTexParameterIuiv(GLenum target, GLenum pname, GLuint * params) {
	static const auto glGetTexParameterIuiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLuint *)>(getProcAddress("glGetTexParameterIuiv"));
	assert(glGetTexParameterIuiv_ != nullptr);
	return glGetTexParameterIuiv_(target, pname, params);
}
void glClearBufferiv(GLenum buffer, GLint drawbuffer, GLint const  * value) {
	static const auto glClearBufferiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLint const  *)>(getProcAddress("glClearBufferiv"));
	assert(glClearBufferiv_ != nullptr);
	return glClearBufferiv_(buffer, drawbuffer, value);
}
void glClearBufferuiv(GLenum buffer, GLint drawbuffer, GLuint const  * value) {
	static const auto glClearBufferuiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLuint const  *)>(getProcAddress("glClearBufferuiv"));
	assert(glClearBufferuiv_ != nullptr);
	return glClearBufferuiv_(buffer, drawbuffer, value);
}
void glClearBufferfv(GLenum buffer, GLint drawbuffer, GLfloat const  * value) {
	static const auto glClearBufferfv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLfloat const  *)>(getProcAddress("glClearBufferfv"));
	assert(glClearBufferfv_ != nullptr);
	return glClearBufferfv_(buffer, drawbuffer, value);
}
void glClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil) {
	static const auto glClearBufferfi_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLfloat, GLint)>(getProcAddress("glClearBufferfi"));
	assert(glClearBufferfi_ != nullptr);
	return glClearBufferfi_(buffer, drawbuffer, depth, stencil);
}
GLubyte const  * glGetStringi(GLenum name, GLuint index) {
	static const auto glGetStringi_ = reinterpret_cast<GLubyte const  *(GL_APIENTRYP)(GLenum, GLuint)>(getProcAddress("glGetStringi"));
	assert(glGetStringi_ != nullptr);
	return glGetStringi_(name, index);
}
GLboolean glIsRenderbuffer(GLuint renderbuffer) {
	static const auto glIsRenderbuffer_ = reinterpret_cast<GLboolean(GL_APIENTRYP)(GLuint)>(getProcAddress("glIsRenderbuffer"));
	assert(glIsRenderbuffer_ != nullptr);
	return glIsRenderbuffer_(renderbuffer);
}
void glBindRenderbuffer(GLenum target, GLuint renderbuffer) {
	static const auto glBindRenderbuffer_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint)>(getProcAddress("glBindRenderbuffer"));
	assert(glBindRenderbuffer_ != nullptr);
	return glBindRenderbuffer_(target, renderbuffer);
}
void glDeleteRenderbuffers(GLsizei n, GLuint const  * renderbuffers) {
	static const auto glDeleteRenderbuffers_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint const  *)>(getProcAddress("glDeleteRenderbuffers"));
	assert(glDeleteRenderbuffers_ != nullptr);
	return glDeleteRenderbuffers_(n, renderbuffers);
}
void glGenRenderbuffers(GLsizei n, GLuint * renderbuffers) {
	static const auto glGenRenderbuffers_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint *)>(getProcAddress("glGenRenderbuffers"));
	assert(glGenRenderbuffers_ != nullptr);
	return glGenRenderbuffers_(n, renderbuffers);
}
void glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) {
	static const auto glRenderbufferStorage_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLsizei, GLsizei)>(getProcAddress("glRenderbufferStorage"));
	assert(glRenderbufferStorage_ != nullptr);
	return glRenderbufferStorage_(target, internalformat, width, height);
}
void glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint * params) {
	static const auto glGetRenderbufferParameteriv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint *)>(getProcAddress("glGetRenderbufferParameteriv"));
	assert(glGetRenderbufferParameteriv_ != nullptr);
	return glGetRenderbufferParameteriv_(target, pname, params);
}
GLboolean glIsFramebuffer(GLuint framebuffer) {
	static const auto glIsFramebuffer_ = reinterpret_cast<GLboolean(GL_APIENTRYP)(GLuint)>(getProcAddress("glIsFramebuffer"));
	assert(glIsFramebuffer_ != nullptr);
	return glIsFramebuffer_(framebuffer);
}
void glBindFramebuffer(GLenum target, GLuint framebuffer) {
	static const auto glBindFramebuffer_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint)>(getProcAddress("glBindFramebuffer"));
	assert(glBindFramebuffer_ != nullptr);
	return glBindFramebuffer_(target, framebuffer);
}
void glDeleteFramebuffers(GLsizei n, GLuint const  * framebuffers) {
	static const auto glDeleteFramebuffers_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint const  *)>(getProcAddress("glDeleteFramebuffers"));
	assert(glDeleteFramebuffers_ != nullptr);
	return glDeleteFramebuffers_(n, framebuffers);
}
void glGenFramebuffers(GLsizei n, GLuint * framebuffers) {
	static const auto glGenFramebuffers_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint *)>(getProcAddress("glGenFramebuffers"));
	assert(glGenFramebuffers_ != nullptr);
	return glGenFramebuffers_(n, framebuffers);
}
GLenum glCheckFramebufferStatus(GLenum target) {
	static const auto glCheckFramebufferStatus_ = reinterpret_cast<GLenum(GL_APIENTRYP)(GLenum)>(getProcAddress("glCheckFramebufferStatus"));
	assert(glCheckFramebufferStatus_ != nullptr);
	return glCheckFramebufferStatus_(target);
}
void glFramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {
	static const auto glFramebufferTexture1D_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLuint, GLint)>(getProcAddress("glFramebufferTexture1D"));
	assert(glFramebufferTexture1D_ != nullptr);
	return glFramebufferTexture1D_(target, attachment, textarget, texture, level);
}
void glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {
	static const auto glFramebufferTexture2D_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLuint, GLint)>(getProcAddress("glFramebufferTexture2D"));
	assert(glFramebufferTexture2D_ != nullptr);
	return glFramebufferTexture2D_(target, attachment, textarget, texture, level);
}
void glFramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset) {
	static const auto glFramebufferTexture3D_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLuint, GLint, GLint)>(getProcAddress("glFramebufferTexture3D"));
	assert(glFramebufferTexture3D_ != nullptr);
	return glFramebufferTexture3D_(target, attachment, textarget, texture, level, zoffset);
}
void glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) {
	static const auto glFramebufferRenderbuffer_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLuint)>(getProcAddress("glFramebufferRenderbuffer"));
	assert(glFramebufferRenderbuffer_ != nullptr);
	return glFramebufferRenderbuffer_(target, attachment, renderbuffertarget, renderbuffer);
}
void glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint * params) {
	static const auto glGetFramebufferAttachmentParameteriv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLint *)>(getProcAddress("glGetFramebufferAttachmentParameteriv"));
	assert(glGetFramebufferAttachmentParameteriv_ != nullptr);
	return glGetFramebufferAttachmentParameteriv_(target, attachment, pname, params);
}
void glGenerateMipmap(GLenum target) {
	static const auto glGenerateMipmap_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glGenerateMipmap"));
	assert(glGenerateMipmap_ != nullptr);
	return glGenerateMipmap_(target);
}
void glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) {
	static const auto glBlitFramebuffer_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLbitfield, GLenum)>(getProcAddress("glBlitFramebuffer"));
	assert(glBlitFramebuffer_ != nullptr);
	return glBlitFramebuffer_(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}
void glRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) {
	static const auto glRenderbufferStorageMultisample_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, GLenum, GLsizei, GLsizei)>(getProcAddress("glRenderbufferStorageMultisample"));
	assert(glRenderbufferStorageMultisample_ != nullptr);
	return glRenderbufferStorageMultisample_(target, samples, internalformat, width, height);
}
void glFramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) {
	static const auto glFramebufferTextureLayer_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLuint, GLint, GLint)>(getProcAddress("glFramebufferTextureLayer"));
	assert(glFramebufferTextureLayer_ != nullptr);
	return glFramebufferTextureLayer_(target, attachment, texture, level, layer);
}
void * glMapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access) {
	static const auto glMapBufferRange_ = reinterpret_cast<void *(GL_APIENTRYP)(GLenum, GLintptr, GLsizeiptr, GLbitfield)>(getProcAddress("glMapBufferRange"));
	assert(glMapBufferRange_ != nullptr);
	return glMapBufferRange_(target, offset, length, access);
}
void glFlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length) {
	static const auto glFlushMappedBufferRange_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLintptr, GLsizeiptr)>(getProcAddress("glFlushMappedBufferRange"));
	assert(glFlushMappedBufferRange_ != nullptr);
	return glFlushMappedBufferRange_(target, offset, length);
}
void glBindVertexArray(GLuint array) {
	static const auto glBindVertexArray_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint)>(getProcAddress("glBindVertexArray"));
	assert(glBindVertexArray_ != nullptr);
	return glBindVertexArray_(array);
}
void glDeleteVertexArrays(GLsizei n, GLuint const  * arrays) {
	static const auto glDeleteVertexArrays_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint const  *)>(getProcAddress("glDeleteVertexArrays"));
	assert(glDeleteVertexArrays_ != nullptr);
	return glDeleteVertexArrays_(n, arrays);
}
void glGenVertexArrays(GLsizei n, GLuint * arrays) {
	static const auto glGenVertexArrays_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint *)>(getProcAddress("glGenVertexArrays"));
	assert(glGenVertexArrays_ != nullptr);
	return glGenVertexArrays_(n, arrays);
}
GLboolean glIsVertexArray(GLuint array) {
	static const auto glIsVertexArray_ = reinterpret_cast<GLboolean(GL_APIENTRYP)(GLuint)>(getProcAddress("glIsVertexArray"));
	assert(glIsVertexArray_ != nullptr);
	return glIsVertexArray_(array);
}
void glReleaseShaderCompiler() {
	static const auto glReleaseShaderCompiler_ = reinterpret_cast<void(GL_APIENTRYP)()>(getProcAddress("glReleaseShaderCompiler"));
	assert(glReleaseShaderCompiler_ != nullptr);
	return glReleaseShaderCompiler_();
}
void glShaderBinary(GLsizei count, GLuint const  * shaders, GLenum binaryformat, const void * binary, GLsizei length) {
	static const auto glShaderBinary_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint const  *, GLenum, const void *, GLsizei)>(getProcAddress("glShaderBinary"));
	assert(glShaderBinary_ != nullptr);
	return glShaderBinary_(count, shaders, binaryformat, binary, length);
}
void glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint * range, GLint * precision) {
	static const auto glGetShaderPrecisionFormat_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint *, GLint *)>(getProcAddress("glGetShaderPrecisionFormat"));
	assert(glGetShaderPrecisionFormat_ != nullptr);
	return glGetShaderPrecisionFormat_(shadertype, precisiontype, range, precision);
}
void glDepthRangef(GLfloat n, GLfloat f) {
	static const auto glDepthRangef_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat, GLfloat)>(getProcAddress("glDepthRangef"));
	assert(glDepthRangef_ != nullptr);
	return glDepthRangef_(n, f);
}
void glClearDepthf(GLfloat d) {
	static const auto glClearDepthf_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat)>(getProcAddress("glClearDepthf"));
	assert(glClearDepthf_ != nullptr);
	return glClearDepthf_(d);
}
void glMemoryBarrierByRegion(GLbitfield barriers) {
	static const auto glMemoryBarrierByRegion_ = reinterpret_cast<void(GL_APIENTRYP)(GLbitfield)>(getProcAddress("glMemoryBarrierByRegion"));
	assert(glMemoryBarrierByRegion_ != nullptr);
	return glMemoryBarrierByRegion_(barriers);
}
void glPrimitiveBoundingBoxARB(GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat minW, GLfloat maxX, GLfloat maxY, GLfloat maxZ, GLfloat maxW) {
	static const auto glPrimitiveBoundingBoxARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat)>(getProcAddress("glPrimitiveBoundingBoxARB"));
	assert(glPrimitiveBoundingBoxARB_ != nullptr);
	return glPrimitiveBoundingBoxARB_(minX, minY, minZ, minW, maxX, maxY, maxZ, maxW);
}
void glDrawArraysInstancedBaseInstance(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance) {
	static const auto glDrawArraysInstancedBaseInstance_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLsizei, GLsizei, GLuint)>(getProcAddress("glDrawArraysInstancedBaseInstance"));
	assert(glDrawArraysInstancedBaseInstance_ != nullptr);
	return glDrawArraysInstancedBaseInstance_(mode, first, count, instancecount, baseinstance);
}
void glDrawElementsInstancedBaseInstance(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLuint baseinstance) {
	static const auto glDrawElementsInstancedBaseInstance_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, GLenum, const void *, GLsizei, GLuint)>(getProcAddress("glDrawElementsInstancedBaseInstance"));
	assert(glDrawElementsInstancedBaseInstance_ != nullptr);
	return glDrawElementsInstancedBaseInstance_(mode, count, type, indices, instancecount, baseinstance);
}
void glDrawElementsInstancedBaseVertexBaseInstance(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance) {
	static const auto glDrawElementsInstancedBaseVertexBaseInstance_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, GLenum, const void *, GLsizei, GLint, GLuint)>(getProcAddress("glDrawElementsInstancedBaseVertexBaseInstance"));
	assert(glDrawElementsInstancedBaseVertexBaseInstance_ != nullptr);
	return glDrawElementsInstancedBaseVertexBaseInstance_(mode, count, type, indices, instancecount, basevertex, baseinstance);
}
GLuint64 glGetTextureHandleARB(GLuint texture) {
	static const auto glGetTextureHandleARB_ = reinterpret_cast<GLuint64(GL_APIENTRYP)(GLuint)>(getProcAddress("glGetTextureHandleARB"));
	assert(glGetTextureHandleARB_ != nullptr);
	return glGetTextureHandleARB_(texture);
}
GLuint64 glGetTextureSamplerHandleARB(GLuint texture, GLuint sampler) {
	static const auto glGetTextureSamplerHandleARB_ = reinterpret_cast<GLuint64(GL_APIENTRYP)(GLuint, GLuint)>(getProcAddress("glGetTextureSamplerHandleARB"));
	assert(glGetTextureSamplerHandleARB_ != nullptr);
	return glGetTextureSamplerHandleARB_(texture, sampler);
}
void glMakeTextureHandleResidentARB(GLuint64 handle) {
	static const auto glMakeTextureHandleResidentARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint64)>(getProcAddress("glMakeTextureHandleResidentARB"));
	assert(glMakeTextureHandleResidentARB_ != nullptr);
	return glMakeTextureHandleResidentARB_(handle);
}
void glMakeTextureHandleNonResidentARB(GLuint64 handle) {
	static const auto glMakeTextureHandleNonResidentARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint64)>(getProcAddress("glMakeTextureHandleNonResidentARB"));
	assert(glMakeTextureHandleNonResidentARB_ != nullptr);
	return glMakeTextureHandleNonResidentARB_(handle);
}
GLuint64 glGetImageHandleARB(GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format) {
	static const auto glGetImageHandleARB_ = reinterpret_cast<GLuint64(GL_APIENTRYP)(GLuint, GLint, GLboolean, GLint, GLenum)>(getProcAddress("glGetImageHandleARB"));
	assert(glGetImageHandleARB_ != nullptr);
	return glGetImageHandleARB_(texture, level, layered, layer, format);
}
void glMakeImageHandleResidentARB(GLuint64 handle, GLenum access) {
	static const auto glMakeImageHandleResidentARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint64, GLenum)>(getProcAddress("glMakeImageHandleResidentARB"));
	assert(glMakeImageHandleResidentARB_ != nullptr);
	return glMakeImageHandleResidentARB_(handle, access);
}
void glMakeImageHandleNonResidentARB(GLuint64 handle) {
	static const auto glMakeImageHandleNonResidentARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint64)>(getProcAddress("glMakeImageHandleNonResidentARB"));
	assert(glMakeImageHandleNonResidentARB_ != nullptr);
	return glMakeImageHandleNonResidentARB_(handle);
}
void glUniformHandleui64ARB(GLint location, GLuint64 value) {
	static const auto glUniformHandleui64ARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLuint64)>(getProcAddress("glUniformHandleui64ARB"));
	assert(glUniformHandleui64ARB_ != nullptr);
	return glUniformHandleui64ARB_(location, value);
}
void glUniformHandleui64vARB(GLint location, GLsizei count, GLuint64 const  * value) {
	static const auto glUniformHandleui64vARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLuint64 const  *)>(getProcAddress("glUniformHandleui64vARB"));
	assert(glUniformHandleui64vARB_ != nullptr);
	return glUniformHandleui64vARB_(location, count, value);
}
void glProgramUniformHandleui64ARB(GLuint program, GLint location, GLuint64 value) {
	static const auto glProgramUniformHandleui64ARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLuint64)>(getProcAddress("glProgramUniformHandleui64ARB"));
	assert(glProgramUniformHandleui64ARB_ != nullptr);
	return glProgramUniformHandleui64ARB_(program, location, value);
}
void glProgramUniformHandleui64vARB(GLuint program, GLint location, GLsizei count, GLuint64 const  * values) {
	static const auto glProgramUniformHandleui64vARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLuint64 const  *)>(getProcAddress("glProgramUniformHandleui64vARB"));
	assert(glProgramUniformHandleui64vARB_ != nullptr);
	return glProgramUniformHandleui64vARB_(program, location, count, values);
}
GLboolean glIsTextureHandleResidentARB(GLuint64 handle) {
	static const auto glIsTextureHandleResidentARB_ = reinterpret_cast<GLboolean(GL_APIENTRYP)(GLuint64)>(getProcAddress("glIsTextureHandleResidentARB"));
	assert(glIsTextureHandleResidentARB_ != nullptr);
	return glIsTextureHandleResidentARB_(handle);
}
GLboolean glIsImageHandleResidentARB(GLuint64 handle) {
	static const auto glIsImageHandleResidentARB_ = reinterpret_cast<GLboolean(GL_APIENTRYP)(GLuint64)>(getProcAddress("glIsImageHandleResidentARB"));
	assert(glIsImageHandleResidentARB_ != nullptr);
	return glIsImageHandleResidentARB_(handle);
}
void glVertexAttribL1ui64ARB(GLuint index, GLuint64EXT x) {
	static const auto glVertexAttribL1ui64ARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint64EXT)>(getProcAddress("glVertexAttribL1ui64ARB"));
	assert(glVertexAttribL1ui64ARB_ != nullptr);
	return glVertexAttribL1ui64ARB_(index, x);
}
void glVertexAttribL1ui64vARB(GLuint index, GLuint64EXT const  * v) {
	static const auto glVertexAttribL1ui64vARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint64EXT const  *)>(getProcAddress("glVertexAttribL1ui64vARB"));
	assert(glVertexAttribL1ui64vARB_ != nullptr);
	return glVertexAttribL1ui64vARB_(index, v);
}
void glGetVertexAttribLui64vARB(GLuint index, GLenum pname, GLuint64EXT * params) {
	static const auto glGetVertexAttribLui64vARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLuint64EXT *)>(getProcAddress("glGetVertexAttribLui64vARB"));
	assert(glGetVertexAttribLui64vARB_ != nullptr);
	return glGetVertexAttribLui64vARB_(index, pname, params);
}
void glBindFragDataLocationIndexed(GLuint program, GLuint colorNumber, GLuint index, GLchar const  * name) {
	static const auto glBindFragDataLocationIndexed_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLuint, GLchar const  *)>(getProcAddress("glBindFragDataLocationIndexed"));
	assert(glBindFragDataLocationIndexed_ != nullptr);
	return glBindFragDataLocationIndexed_(program, colorNumber, index, name);
}
GLint glGetFragDataIndex(GLuint program, GLchar const  * name) {
	static const auto glGetFragDataIndex_ = reinterpret_cast<GLint(GL_APIENTRYP)(GLuint, GLchar const  *)>(getProcAddress("glGetFragDataIndex"));
	assert(glGetFragDataIndex_ != nullptr);
	return glGetFragDataIndex_(program, name);
}
void glBufferStorage(GLenum target, GLsizeiptr size, const void * data, GLbitfield flags) {
	static const auto glBufferStorage_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizeiptr, const void *, GLbitfield)>(getProcAddress("glBufferStorage"));
	assert(glBufferStorage_ != nullptr);
	return glBufferStorage_(target, size, data, flags);
}
GLsync glCreateSyncFromCLeventARB(struct _cl_context * context, struct _cl_event * event, GLbitfield flags) {
	static const auto glCreateSyncFromCLeventARB_ = reinterpret_cast<GLsync(GL_APIENTRYP)(struct _cl_context *, struct _cl_event *, GLbitfield)>(getProcAddress("glCreateSyncFromCLeventARB"));
	assert(glCreateSyncFromCLeventARB_ != nullptr);
	return glCreateSyncFromCLeventARB_(context, event, flags);
}
void glClearBufferData(GLenum target, GLenum internalformat, GLenum format, GLenum type, const void * data) {
	static const auto glClearBufferData_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLenum, const void *)>(getProcAddress("glClearBufferData"));
	assert(glClearBufferData_ != nullptr);
	return glClearBufferData_(target, internalformat, format, type, data);
}
void glClearBufferSubData(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void * data) {
	static const auto glClearBufferSubData_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLintptr, GLsizeiptr, GLenum, GLenum, const void *)>(getProcAddress("glClearBufferSubData"));
	assert(glClearBufferSubData_ != nullptr);
	return glClearBufferSubData_(target, internalformat, offset, size, format, type, data);
}
void glClearTexImage(GLuint texture, GLint level, GLenum format, GLenum type, const void * data) {
	static const auto glClearTexImage_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLenum, GLenum, const void *)>(getProcAddress("glClearTexImage"));
	assert(glClearTexImage_ != nullptr);
	return glClearTexImage_(texture, level, format, type, data);
}
void glClearTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * data) {
	static const auto glClearTexSubImage_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const void *)>(getProcAddress("glClearTexSubImage"));
	assert(glClearTexSubImage_ != nullptr);
	return glClearTexSubImage_(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, data);
}
void glClipControl(GLenum origin, GLenum depth) {
	static const auto glClipControl_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum)>(getProcAddress("glClipControl"));
	assert(glClipControl_ != nullptr);
	return glClipControl_(origin, depth);
}
void glClampColorARB(GLenum target, GLenum clamp) {
	static const auto glClampColorARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum)>(getProcAddress("glClampColorARB"));
	assert(glClampColorARB_ != nullptr);
	return glClampColorARB_(target, clamp);
}
void glDispatchCompute(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z) {
	static const auto glDispatchCompute_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLuint)>(getProcAddress("glDispatchCompute"));
	assert(glDispatchCompute_ != nullptr);
	return glDispatchCompute_(num_groups_x, num_groups_y, num_groups_z);
}
void glDispatchComputeIndirect(GLintptr indirect) {
	static const auto glDispatchComputeIndirect_ = reinterpret_cast<void(GL_APIENTRYP)(GLintptr)>(getProcAddress("glDispatchComputeIndirect"));
	assert(glDispatchComputeIndirect_ != nullptr);
	return glDispatchComputeIndirect_(indirect);
}
void glDispatchComputeGroupSizeARB(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z, GLuint group_size_x, GLuint group_size_y, GLuint group_size_z) {
	static const auto glDispatchComputeGroupSizeARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLuint, GLuint, GLuint, GLuint)>(getProcAddress("glDispatchComputeGroupSizeARB"));
	assert(glDispatchComputeGroupSizeARB_ != nullptr);
	return glDispatchComputeGroupSizeARB_(num_groups_x, num_groups_y, num_groups_z, group_size_x, group_size_y, group_size_z);
}
void glCopyBufferSubData(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) {
	static const auto glCopyBufferSubData_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLintptr, GLintptr, GLsizeiptr)>(getProcAddress("glCopyBufferSubData"));
	assert(glCopyBufferSubData_ != nullptr);
	return glCopyBufferSubData_(readTarget, writeTarget, readOffset, writeOffset, size);
}
void glCopyImageSubData(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth) {
	static const auto glCopyImageSubData_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint, GLint, GLint, GLint, GLuint, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei)>(getProcAddress("glCopyImageSubData"));
	assert(glCopyImageSubData_ != nullptr);
	return glCopyImageSubData_(srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth);
}
void glDebugMessageControlARB(GLenum source, GLenum type, GLenum severity, GLsizei count, GLuint const  * ids, GLboolean enabled) {
	static const auto glDebugMessageControlARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLsizei, GLuint const  *, GLboolean)>(getProcAddress("glDebugMessageControlARB"));
	assert(glDebugMessageControlARB_ != nullptr);
	return glDebugMessageControlARB_(source, type, severity, count, ids, enabled);
}
void glDebugMessageInsertARB(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, GLchar const  * buf) {
	static const auto glDebugMessageInsertARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLuint, GLenum, GLsizei, GLchar const  *)>(getProcAddress("glDebugMessageInsertARB"));
	assert(glDebugMessageInsertARB_ != nullptr);
	return glDebugMessageInsertARB_(source, type, id, severity, length, buf);
}
void glDebugMessageCallbackARB(GLDEBUGPROCARB callback, const void * userParam) {
	static const auto glDebugMessageCallbackARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLDEBUGPROCARB, const void *)>(getProcAddress("glDebugMessageCallbackARB"));
	assert(glDebugMessageCallbackARB_ != nullptr);
	return glDebugMessageCallbackARB_(callback, userParam);
}
GLuint glGetDebugMessageLogARB(GLuint count, GLsizei bufSize, GLenum * sources, GLenum * types, GLuint * ids, GLenum * severities, GLsizei * lengths, GLchar * messageLog) {
	static const auto glGetDebugMessageLogARB_ = reinterpret_cast<GLuint(GL_APIENTRYP)(GLuint, GLsizei, GLenum *, GLenum *, GLuint *, GLenum *, GLsizei *, GLchar *)>(getProcAddress("glGetDebugMessageLogARB"));
	assert(glGetDebugMessageLogARB_ != nullptr);
	return glGetDebugMessageLogARB_(count, bufSize, sources, types, ids, severities, lengths, messageLog);
}
void glCreateTransformFeedbacks(GLsizei n, GLuint * ids) {
	static const auto glCreateTransformFeedbacks_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint *)>(getProcAddress("glCreateTransformFeedbacks"));
	assert(glCreateTransformFeedbacks_ != nullptr);
	return glCreateTransformFeedbacks_(n, ids);
}
void glTransformFeedbackBufferBase(GLuint xfb, GLuint index, GLuint buffer) {
	static const auto glTransformFeedbackBufferBase_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLuint)>(getProcAddress("glTransformFeedbackBufferBase"));
	assert(glTransformFeedbackBufferBase_ != nullptr);
	return glTransformFeedbackBufferBase_(xfb, index, buffer);
}
void glTransformFeedbackBufferRange(GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) {
	static const auto glTransformFeedbackBufferRange_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLuint, GLintptr, GLsizeiptr)>(getProcAddress("glTransformFeedbackBufferRange"));
	assert(glTransformFeedbackBufferRange_ != nullptr);
	return glTransformFeedbackBufferRange_(xfb, index, buffer, offset, size);
}
void glGetTransformFeedbackiv(GLuint xfb, GLenum pname, GLint * param) {
	static const auto glGetTransformFeedbackiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint *)>(getProcAddress("glGetTransformFeedbackiv"));
	assert(glGetTransformFeedbackiv_ != nullptr);
	return glGetTransformFeedbackiv_(xfb, pname, param);
}
void glGetTransformFeedbacki_v(GLuint xfb, GLenum pname, GLuint index, GLint * param) {
	static const auto glGetTransformFeedbacki_v_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLuint, GLint *)>(getProcAddress("glGetTransformFeedbacki_v"));
	assert(glGetTransformFeedbacki_v_ != nullptr);
	return glGetTransformFeedbacki_v_(xfb, pname, index, param);
}
void glGetTransformFeedbacki64_v(GLuint xfb, GLenum pname, GLuint index, GLint64 * param) {
	static const auto glGetTransformFeedbacki64_v_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLuint, GLint64 *)>(getProcAddress("glGetTransformFeedbacki64_v"));
	assert(glGetTransformFeedbacki64_v_ != nullptr);
	return glGetTransformFeedbacki64_v_(xfb, pname, index, param);
}
void glCreateBuffers(GLsizei n, GLuint * buffers) {
	static const auto glCreateBuffers_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint *)>(getProcAddress("glCreateBuffers"));
	assert(glCreateBuffers_ != nullptr);
	return glCreateBuffers_(n, buffers);
}
void glNamedBufferStorage(GLuint buffer, GLsizeiptr size, const void * data, GLbitfield flags) {
	static const auto glNamedBufferStorage_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLsizeiptr, const void *, GLbitfield)>(getProcAddress("glNamedBufferStorage"));
	assert(glNamedBufferStorage_ != nullptr);
	return glNamedBufferStorage_(buffer, size, data, flags);
}
void glNamedBufferData(GLuint buffer, GLsizeiptr size, const void * data, GLenum usage) {
	static const auto glNamedBufferData_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLsizeiptr, const void *, GLenum)>(getProcAddress("glNamedBufferData"));
	assert(glNamedBufferData_ != nullptr);
	return glNamedBufferData_(buffer, size, data, usage);
}
void glNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, const void * data) {
	static const auto glNamedBufferSubData_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLintptr, GLsizeiptr, const void *)>(getProcAddress("glNamedBufferSubData"));
	assert(glNamedBufferSubData_ != nullptr);
	return glNamedBufferSubData_(buffer, offset, size, data);
}
void glCopyNamedBufferSubData(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) {
	static const auto glCopyNamedBufferSubData_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLintptr, GLintptr, GLsizeiptr)>(getProcAddress("glCopyNamedBufferSubData"));
	assert(glCopyNamedBufferSubData_ != nullptr);
	return glCopyNamedBufferSubData_(readBuffer, writeBuffer, readOffset, writeOffset, size);
}
void glClearNamedBufferData(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void * data) {
	static const auto glClearNamedBufferData_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLenum, GLenum, const void *)>(getProcAddress("glClearNamedBufferData"));
	assert(glClearNamedBufferData_ != nullptr);
	return glClearNamedBufferData_(buffer, internalformat, format, type, data);
}
void glClearNamedBufferSubData(GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void * data) {
	static const auto glClearNamedBufferSubData_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLintptr, GLsizeiptr, GLenum, GLenum, const void *)>(getProcAddress("glClearNamedBufferSubData"));
	assert(glClearNamedBufferSubData_ != nullptr);
	return glClearNamedBufferSubData_(buffer, internalformat, offset, size, format, type, data);
}
void * glMapNamedBuffer(GLuint buffer, GLenum access) {
	static const auto glMapNamedBuffer_ = reinterpret_cast<void *(GL_APIENTRYP)(GLuint, GLenum)>(getProcAddress("glMapNamedBuffer"));
	assert(glMapNamedBuffer_ != nullptr);
	return glMapNamedBuffer_(buffer, access);
}
void * glMapNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access) {
	static const auto glMapNamedBufferRange_ = reinterpret_cast<void *(GL_APIENTRYP)(GLuint, GLintptr, GLsizeiptr, GLbitfield)>(getProcAddress("glMapNamedBufferRange"));
	assert(glMapNamedBufferRange_ != nullptr);
	return glMapNamedBufferRange_(buffer, offset, length, access);
}
GLboolean glUnmapNamedBuffer(GLuint buffer) {
	static const auto glUnmapNamedBuffer_ = reinterpret_cast<GLboolean(GL_APIENTRYP)(GLuint)>(getProcAddress("glUnmapNamedBuffer"));
	assert(glUnmapNamedBuffer_ != nullptr);
	return glUnmapNamedBuffer_(buffer);
}
void glFlushMappedNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length) {
	static const auto glFlushMappedNamedBufferRange_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLintptr, GLsizeiptr)>(getProcAddress("glFlushMappedNamedBufferRange"));
	assert(glFlushMappedNamedBufferRange_ != nullptr);
	return glFlushMappedNamedBufferRange_(buffer, offset, length);
}
void glGetNamedBufferParameteriv(GLuint buffer, GLenum pname, GLint * params) {
	static const auto glGetNamedBufferParameteriv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint *)>(getProcAddress("glGetNamedBufferParameteriv"));
	assert(glGetNamedBufferParameteriv_ != nullptr);
	return glGetNamedBufferParameteriv_(buffer, pname, params);
}
void glGetNamedBufferParameteri64v(GLuint buffer, GLenum pname, GLint64 * params) {
	static const auto glGetNamedBufferParameteri64v_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint64 *)>(getProcAddress("glGetNamedBufferParameteri64v"));
	assert(glGetNamedBufferParameteri64v_ != nullptr);
	return glGetNamedBufferParameteri64v_(buffer, pname, params);
}
void glGetNamedBufferPointerv(GLuint buffer, GLenum pname, void ** params) {
	static const auto glGetNamedBufferPointerv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, void **)>(getProcAddress("glGetNamedBufferPointerv"));
	assert(glGetNamedBufferPointerv_ != nullptr);
	return glGetNamedBufferPointerv_(buffer, pname, params);
}
void glGetNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, void * data) {
	static const auto glGetNamedBufferSubData_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLintptr, GLsizeiptr, void *)>(getProcAddress("glGetNamedBufferSubData"));
	assert(glGetNamedBufferSubData_ != nullptr);
	return glGetNamedBufferSubData_(buffer, offset, size, data);
}
void glCreateFramebuffers(GLsizei n, GLuint * framebuffers) {
	static const auto glCreateFramebuffers_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint *)>(getProcAddress("glCreateFramebuffers"));
	assert(glCreateFramebuffers_ != nullptr);
	return glCreateFramebuffers_(n, framebuffers);
}
void glNamedFramebufferRenderbuffer(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) {
	static const auto glNamedFramebufferRenderbuffer_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLenum, GLuint)>(getProcAddress("glNamedFramebufferRenderbuffer"));
	assert(glNamedFramebufferRenderbuffer_ != nullptr);
	return glNamedFramebufferRenderbuffer_(framebuffer, attachment, renderbuffertarget, renderbuffer);
}
void glNamedFramebufferParameteri(GLuint framebuffer, GLenum pname, GLint param) {
	static const auto glNamedFramebufferParameteri_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint)>(getProcAddress("glNamedFramebufferParameteri"));
	assert(glNamedFramebufferParameteri_ != nullptr);
	return glNamedFramebufferParameteri_(framebuffer, pname, param);
}
void glNamedFramebufferTexture(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level) {
	static const auto glNamedFramebufferTexture_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLuint, GLint)>(getProcAddress("glNamedFramebufferTexture"));
	assert(glNamedFramebufferTexture_ != nullptr);
	return glNamedFramebufferTexture_(framebuffer, attachment, texture, level);
}
void glNamedFramebufferTextureLayer(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer) {
	static const auto glNamedFramebufferTextureLayer_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLuint, GLint, GLint)>(getProcAddress("glNamedFramebufferTextureLayer"));
	assert(glNamedFramebufferTextureLayer_ != nullptr);
	return glNamedFramebufferTextureLayer_(framebuffer, attachment, texture, level, layer);
}
void glNamedFramebufferDrawBuffer(GLuint framebuffer, GLenum buf) {
	static const auto glNamedFramebufferDrawBuffer_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum)>(getProcAddress("glNamedFramebufferDrawBuffer"));
	assert(glNamedFramebufferDrawBuffer_ != nullptr);
	return glNamedFramebufferDrawBuffer_(framebuffer, buf);
}
void glNamedFramebufferDrawBuffers(GLuint framebuffer, GLsizei n, GLenum const  * bufs) {
	static const auto glNamedFramebufferDrawBuffers_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLsizei, GLenum const  *)>(getProcAddress("glNamedFramebufferDrawBuffers"));
	assert(glNamedFramebufferDrawBuffers_ != nullptr);
	return glNamedFramebufferDrawBuffers_(framebuffer, n, bufs);
}
void glNamedFramebufferReadBuffer(GLuint framebuffer, GLenum src) {
	static const auto glNamedFramebufferReadBuffer_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum)>(getProcAddress("glNamedFramebufferReadBuffer"));
	assert(glNamedFramebufferReadBuffer_ != nullptr);
	return glNamedFramebufferReadBuffer_(framebuffer, src);
}
void glInvalidateNamedFramebufferData(GLuint framebuffer, GLsizei numAttachments, GLenum const  * attachments) {
	static const auto glInvalidateNamedFramebufferData_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLsizei, GLenum const  *)>(getProcAddress("glInvalidateNamedFramebufferData"));
	assert(glInvalidateNamedFramebufferData_ != nullptr);
	return glInvalidateNamedFramebufferData_(framebuffer, numAttachments, attachments);
}
void glInvalidateNamedFramebufferSubData(GLuint framebuffer, GLsizei numAttachments, GLenum const  * attachments, GLint x, GLint y, GLsizei width, GLsizei height) {
	static const auto glInvalidateNamedFramebufferSubData_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLsizei, GLenum const  *, GLint, GLint, GLsizei, GLsizei)>(getProcAddress("glInvalidateNamedFramebufferSubData"));
	assert(glInvalidateNamedFramebufferSubData_ != nullptr);
	return glInvalidateNamedFramebufferSubData_(framebuffer, numAttachments, attachments, x, y, width, height);
}
void glClearNamedFramebufferiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLint const  * value) {
	static const auto glClearNamedFramebufferiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint, GLint const  *)>(getProcAddress("glClearNamedFramebufferiv"));
	assert(glClearNamedFramebufferiv_ != nullptr);
	return glClearNamedFramebufferiv_(framebuffer, buffer, drawbuffer, value);
}
void glClearNamedFramebufferuiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLuint const  * value) {
	static const auto glClearNamedFramebufferuiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint, GLuint const  *)>(getProcAddress("glClearNamedFramebufferuiv"));
	assert(glClearNamedFramebufferuiv_ != nullptr);
	return glClearNamedFramebufferuiv_(framebuffer, buffer, drawbuffer, value);
}
void glClearNamedFramebufferfv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat const  * value) {
	static const auto glClearNamedFramebufferfv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint, GLfloat const  *)>(getProcAddress("glClearNamedFramebufferfv"));
	assert(glClearNamedFramebufferfv_ != nullptr);
	return glClearNamedFramebufferfv_(framebuffer, buffer, drawbuffer, value);
}
void glClearNamedFramebufferfi(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil) {
	static const auto glClearNamedFramebufferfi_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint, GLfloat, GLint)>(getProcAddress("glClearNamedFramebufferfi"));
	assert(glClearNamedFramebufferfi_ != nullptr);
	return glClearNamedFramebufferfi_(framebuffer, buffer, drawbuffer, depth, stencil);
}
void glBlitNamedFramebuffer(GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) {
	static const auto glBlitNamedFramebuffer_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLbitfield, GLenum)>(getProcAddress("glBlitNamedFramebuffer"));
	assert(glBlitNamedFramebuffer_ != nullptr);
	return glBlitNamedFramebuffer_(readFramebuffer, drawFramebuffer, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}
GLenum glCheckNamedFramebufferStatus(GLuint framebuffer, GLenum target) {
	static const auto glCheckNamedFramebufferStatus_ = reinterpret_cast<GLenum(GL_APIENTRYP)(GLuint, GLenum)>(getProcAddress("glCheckNamedFramebufferStatus"));
	assert(glCheckNamedFramebufferStatus_ != nullptr);
	return glCheckNamedFramebufferStatus_(framebuffer, target);
}
void glGetNamedFramebufferParameteriv(GLuint framebuffer, GLenum pname, GLint * param) {
	static const auto glGetNamedFramebufferParameteriv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint *)>(getProcAddress("glGetNamedFramebufferParameteriv"));
	assert(glGetNamedFramebufferParameteriv_ != nullptr);
	return glGetNamedFramebufferParameteriv_(framebuffer, pname, param);
}
void glGetNamedFramebufferAttachmentParameteriv(GLuint framebuffer, GLenum attachment, GLenum pname, GLint * params) {
	static const auto glGetNamedFramebufferAttachmentParameteriv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLenum, GLint *)>(getProcAddress("glGetNamedFramebufferAttachmentParameteriv"));
	assert(glGetNamedFramebufferAttachmentParameteriv_ != nullptr);
	return glGetNamedFramebufferAttachmentParameteriv_(framebuffer, attachment, pname, params);
}
void glCreateRenderbuffers(GLsizei n, GLuint * renderbuffers) {
	static const auto glCreateRenderbuffers_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint *)>(getProcAddress("glCreateRenderbuffers"));
	assert(glCreateRenderbuffers_ != nullptr);
	return glCreateRenderbuffers_(n, renderbuffers);
}
void glNamedRenderbufferStorage(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height) {
	static const auto glNamedRenderbufferStorage_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLsizei, GLsizei)>(getProcAddress("glNamedRenderbufferStorage"));
	assert(glNamedRenderbufferStorage_ != nullptr);
	return glNamedRenderbufferStorage_(renderbuffer, internalformat, width, height);
}
void glNamedRenderbufferStorageMultisample(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) {
	static const auto glNamedRenderbufferStorageMultisample_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLsizei, GLenum, GLsizei, GLsizei)>(getProcAddress("glNamedRenderbufferStorageMultisample"));
	assert(glNamedRenderbufferStorageMultisample_ != nullptr);
	return glNamedRenderbufferStorageMultisample_(renderbuffer, samples, internalformat, width, height);
}
void glGetNamedRenderbufferParameteriv(GLuint renderbuffer, GLenum pname, GLint * params) {
	static const auto glGetNamedRenderbufferParameteriv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint *)>(getProcAddress("glGetNamedRenderbufferParameteriv"));
	assert(glGetNamedRenderbufferParameteriv_ != nullptr);
	return glGetNamedRenderbufferParameteriv_(renderbuffer, pname, params);
}
void glCreateTextures(GLenum target, GLsizei n, GLuint * textures) {
	static const auto glCreateTextures_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, GLuint *)>(getProcAddress("glCreateTextures"));
	assert(glCreateTextures_ != nullptr);
	return glCreateTextures_(target, n, textures);
}
void glTextureBuffer(GLuint texture, GLenum internalformat, GLuint buffer) {
	static const auto glTextureBuffer_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLuint)>(getProcAddress("glTextureBuffer"));
	assert(glTextureBuffer_ != nullptr);
	return glTextureBuffer_(texture, internalformat, buffer);
}
void glTextureBufferRange(GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size) {
	static const auto glTextureBufferRange_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLuint, GLintptr, GLsizeiptr)>(getProcAddress("glTextureBufferRange"));
	assert(glTextureBufferRange_ != nullptr);
	return glTextureBufferRange_(texture, internalformat, buffer, offset, size);
}
void glTextureStorage1D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width) {
	static const auto glTextureStorage1D_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLsizei, GLenum, GLsizei)>(getProcAddress("glTextureStorage1D"));
	assert(glTextureStorage1D_ != nullptr);
	return glTextureStorage1D_(texture, levels, internalformat, width);
}
void glTextureStorage2D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) {
	static const auto glTextureStorage2D_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLsizei, GLenum, GLsizei, GLsizei)>(getProcAddress("glTextureStorage2D"));
	assert(glTextureStorage2D_ != nullptr);
	return glTextureStorage2D_(texture, levels, internalformat, width, height);
}
void glTextureStorage3D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) {
	static const auto glTextureStorage3D_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLsizei, GLenum, GLsizei, GLsizei, GLsizei)>(getProcAddress("glTextureStorage3D"));
	assert(glTextureStorage3D_ != nullptr);
	return glTextureStorage3D_(texture, levels, internalformat, width, height, depth);
}
void glTextureStorage2DMultisample(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) {
	static const auto glTextureStorage2DMultisample_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLsizei, GLenum, GLsizei, GLsizei, GLboolean)>(getProcAddress("glTextureStorage2DMultisample"));
	assert(glTextureStorage2DMultisample_ != nullptr);
	return glTextureStorage2DMultisample_(texture, samples, internalformat, width, height, fixedsamplelocations);
}
void glTextureStorage3DMultisample(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) {
	static const auto glTextureStorage3DMultisample_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLsizei, GLenum, GLsizei, GLsizei, GLsizei, GLboolean)>(getProcAddress("glTextureStorage3DMultisample"));
	assert(glTextureStorage3DMultisample_ != nullptr);
	return glTextureStorage3DMultisample_(texture, samples, internalformat, width, height, depth, fixedsamplelocations);
}
void glTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void * pixels) {
	static const auto glTextureSubImage1D_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLint, GLsizei, GLenum, GLenum, const void *)>(getProcAddress("glTextureSubImage1D"));
	assert(glTextureSubImage1D_ != nullptr);
	return glTextureSubImage1D_(texture, level, xoffset, width, format, type, pixels);
}
void glTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels) {
	static const auto glTextureSubImage2D_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const void *)>(getProcAddress("glTextureSubImage2D"));
	assert(glTextureSubImage2D_ != nullptr);
	return glTextureSubImage2D_(texture, level, xoffset, yoffset, width, height, format, type, pixels);
}
void glTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels) {
	static const auto glTextureSubImage3D_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const void *)>(getProcAddress("glTextureSubImage3D"));
	assert(glTextureSubImage3D_ != nullptr);
	return glTextureSubImage3D_(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}
void glCompressedTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * data) {
	static const auto glCompressedTextureSubImage1D_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLint, GLsizei, GLenum, GLsizei, const void *)>(getProcAddress("glCompressedTextureSubImage1D"));
	assert(glCompressedTextureSubImage1D_ != nullptr);
	return glCompressedTextureSubImage1D_(texture, level, xoffset, width, format, imageSize, data);
}
void glCompressedTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * data) {
	static const auto glCompressedTextureSubImage2D_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const void *)>(getProcAddress("glCompressedTextureSubImage2D"));
	assert(glCompressedTextureSubImage2D_ != nullptr);
	return glCompressedTextureSubImage2D_(texture, level, xoffset, yoffset, width, height, format, imageSize, data);
}
void glCompressedTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * data) {
	static const auto glCompressedTextureSubImage3D_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const void *)>(getProcAddress("glCompressedTextureSubImage3D"));
	assert(glCompressedTextureSubImage3D_ != nullptr);
	return glCompressedTextureSubImage3D_(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
}
void glCopyTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) {
	static const auto glCopyTextureSubImage1D_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLint, GLint, GLint, GLsizei)>(getProcAddress("glCopyTextureSubImage1D"));
	assert(glCopyTextureSubImage1D_ != nullptr);
	return glCopyTextureSubImage1D_(texture, level, xoffset, x, y, width);
}
void glCopyTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
	static const auto glCopyTextureSubImage2D_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei)>(getProcAddress("glCopyTextureSubImage2D"));
	assert(glCopyTextureSubImage2D_ != nullptr);
	return glCopyTextureSubImage2D_(texture, level, xoffset, yoffset, x, y, width, height);
}
void glCopyTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
	static const auto glCopyTextureSubImage3D_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei)>(getProcAddress("glCopyTextureSubImage3D"));
	assert(glCopyTextureSubImage3D_ != nullptr);
	return glCopyTextureSubImage3D_(texture, level, xoffset, yoffset, zoffset, x, y, width, height);
}
void glTextureParameterf(GLuint texture, GLenum pname, GLfloat param) {
	static const auto glTextureParameterf_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLfloat)>(getProcAddress("glTextureParameterf"));
	assert(glTextureParameterf_ != nullptr);
	return glTextureParameterf_(texture, pname, param);
}
void glTextureParameterfv(GLuint texture, GLenum pname, GLfloat const  * param) {
	static const auto glTextureParameterfv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLfloat const  *)>(getProcAddress("glTextureParameterfv"));
	assert(glTextureParameterfv_ != nullptr);
	return glTextureParameterfv_(texture, pname, param);
}
void glTextureParameteri(GLuint texture, GLenum pname, GLint param) {
	static const auto glTextureParameteri_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint)>(getProcAddress("glTextureParameteri"));
	assert(glTextureParameteri_ != nullptr);
	return glTextureParameteri_(texture, pname, param);
}
void glTextureParameterIiv(GLuint texture, GLenum pname, GLint const  * params) {
	static const auto glTextureParameterIiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint const  *)>(getProcAddress("glTextureParameterIiv"));
	assert(glTextureParameterIiv_ != nullptr);
	return glTextureParameterIiv_(texture, pname, params);
}
void glTextureParameterIuiv(GLuint texture, GLenum pname, GLuint const  * params) {
	static const auto glTextureParameterIuiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLuint const  *)>(getProcAddress("glTextureParameterIuiv"));
	assert(glTextureParameterIuiv_ != nullptr);
	return glTextureParameterIuiv_(texture, pname, params);
}
void glTextureParameteriv(GLuint texture, GLenum pname, GLint const  * param) {
	static const auto glTextureParameteriv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint const  *)>(getProcAddress("glTextureParameteriv"));
	assert(glTextureParameteriv_ != nullptr);
	return glTextureParameteriv_(texture, pname, param);
}
void glGenerateTextureMipmap(GLuint texture) {
	static const auto glGenerateTextureMipmap_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint)>(getProcAddress("glGenerateTextureMipmap"));
	assert(glGenerateTextureMipmap_ != nullptr);
	return glGenerateTextureMipmap_(texture);
}
void glBindTextureUnit(GLuint unit, GLuint texture) {
	static const auto glBindTextureUnit_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint)>(getProcAddress("glBindTextureUnit"));
	assert(glBindTextureUnit_ != nullptr);
	return glBindTextureUnit_(unit, texture);
}
void glGetTextureImage(GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void * pixels) {
	static const auto glGetTextureImage_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLenum, GLenum, GLsizei, void *)>(getProcAddress("glGetTextureImage"));
	assert(glGetTextureImage_ != nullptr);
	return glGetTextureImage_(texture, level, format, type, bufSize, pixels);
}
void glGetCompressedTextureImage(GLuint texture, GLint level, GLsizei bufSize, void * pixels) {
	static const auto glGetCompressedTextureImage_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, void *)>(getProcAddress("glGetCompressedTextureImage"));
	assert(glGetCompressedTextureImage_ != nullptr);
	return glGetCompressedTextureImage_(texture, level, bufSize, pixels);
}
void glGetTextureLevelParameterfv(GLuint texture, GLint level, GLenum pname, GLfloat * params) {
	static const auto glGetTextureLevelParameterfv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLenum, GLfloat *)>(getProcAddress("glGetTextureLevelParameterfv"));
	assert(glGetTextureLevelParameterfv_ != nullptr);
	return glGetTextureLevelParameterfv_(texture, level, pname, params);
}
void glGetTextureLevelParameteriv(GLuint texture, GLint level, GLenum pname, GLint * params) {
	static const auto glGetTextureLevelParameteriv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLenum, GLint *)>(getProcAddress("glGetTextureLevelParameteriv"));
	assert(glGetTextureLevelParameteriv_ != nullptr);
	return glGetTextureLevelParameteriv_(texture, level, pname, params);
}
void glGetTextureParameterfv(GLuint texture, GLenum pname, GLfloat * params) {
	static const auto glGetTextureParameterfv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLfloat *)>(getProcAddress("glGetTextureParameterfv"));
	assert(glGetTextureParameterfv_ != nullptr);
	return glGetTextureParameterfv_(texture, pname, params);
}
void glGetTextureParameterIiv(GLuint texture, GLenum pname, GLint * params) {
	static const auto glGetTextureParameterIiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint *)>(getProcAddress("glGetTextureParameterIiv"));
	assert(glGetTextureParameterIiv_ != nullptr);
	return glGetTextureParameterIiv_(texture, pname, params);
}
void glGetTextureParameterIuiv(GLuint texture, GLenum pname, GLuint * params) {
	static const auto glGetTextureParameterIuiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLuint *)>(getProcAddress("glGetTextureParameterIuiv"));
	assert(glGetTextureParameterIuiv_ != nullptr);
	return glGetTextureParameterIuiv_(texture, pname, params);
}
void glGetTextureParameteriv(GLuint texture, GLenum pname, GLint * params) {
	static const auto glGetTextureParameteriv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint *)>(getProcAddress("glGetTextureParameteriv"));
	assert(glGetTextureParameteriv_ != nullptr);
	return glGetTextureParameteriv_(texture, pname, params);
}
void glCreateVertexArrays(GLsizei n, GLuint * arrays) {
	static const auto glCreateVertexArrays_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint *)>(getProcAddress("glCreateVertexArrays"));
	assert(glCreateVertexArrays_ != nullptr);
	return glCreateVertexArrays_(n, arrays);
}
void glDisableVertexArrayAttrib(GLuint vaobj, GLuint index) {
	static const auto glDisableVertexArrayAttrib_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint)>(getProcAddress("glDisableVertexArrayAttrib"));
	assert(glDisableVertexArrayAttrib_ != nullptr);
	return glDisableVertexArrayAttrib_(vaobj, index);
}
void glEnableVertexArrayAttrib(GLuint vaobj, GLuint index) {
	static const auto glEnableVertexArrayAttrib_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint)>(getProcAddress("glEnableVertexArrayAttrib"));
	assert(glEnableVertexArrayAttrib_ != nullptr);
	return glEnableVertexArrayAttrib_(vaobj, index);
}
void glVertexArrayElementBuffer(GLuint vaobj, GLuint buffer) {
	static const auto glVertexArrayElementBuffer_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint)>(getProcAddress("glVertexArrayElementBuffer"));
	assert(glVertexArrayElementBuffer_ != nullptr);
	return glVertexArrayElementBuffer_(vaobj, buffer);
}
void glVertexArrayVertexBuffer(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride) {
	static const auto glVertexArrayVertexBuffer_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLuint, GLintptr, GLsizei)>(getProcAddress("glVertexArrayVertexBuffer"));
	assert(glVertexArrayVertexBuffer_ != nullptr);
	return glVertexArrayVertexBuffer_(vaobj, bindingindex, buffer, offset, stride);
}
void glVertexArrayVertexBuffers(GLuint vaobj, GLuint first, GLsizei count, GLuint const  * buffers, GLintptr const  * offsets, GLsizei const  * strides) {
	static const auto glVertexArrayVertexBuffers_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLsizei, GLuint const  *, GLintptr const  *, GLsizei const  *)>(getProcAddress("glVertexArrayVertexBuffers"));
	assert(glVertexArrayVertexBuffers_ != nullptr);
	return glVertexArrayVertexBuffers_(vaobj, first, count, buffers, offsets, strides);
}
void glVertexArrayAttribBinding(GLuint vaobj, GLuint attribindex, GLuint bindingindex) {
	static const auto glVertexArrayAttribBinding_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLuint)>(getProcAddress("glVertexArrayAttribBinding"));
	assert(glVertexArrayAttribBinding_ != nullptr);
	return glVertexArrayAttribBinding_(vaobj, attribindex, bindingindex);
}
void glVertexArrayAttribFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset) {
	static const auto glVertexArrayAttribFormat_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLint, GLenum, GLboolean, GLuint)>(getProcAddress("glVertexArrayAttribFormat"));
	assert(glVertexArrayAttribFormat_ != nullptr);
	return glVertexArrayAttribFormat_(vaobj, attribindex, size, type, normalized, relativeoffset);
}
void glVertexArrayAttribIFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) {
	static const auto glVertexArrayAttribIFormat_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLint, GLenum, GLuint)>(getProcAddress("glVertexArrayAttribIFormat"));
	assert(glVertexArrayAttribIFormat_ != nullptr);
	return glVertexArrayAttribIFormat_(vaobj, attribindex, size, type, relativeoffset);
}
void glVertexArrayAttribLFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) {
	static const auto glVertexArrayAttribLFormat_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLint, GLenum, GLuint)>(getProcAddress("glVertexArrayAttribLFormat"));
	assert(glVertexArrayAttribLFormat_ != nullptr);
	return glVertexArrayAttribLFormat_(vaobj, attribindex, size, type, relativeoffset);
}
void glVertexArrayBindingDivisor(GLuint vaobj, GLuint bindingindex, GLuint divisor) {
	static const auto glVertexArrayBindingDivisor_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLuint)>(getProcAddress("glVertexArrayBindingDivisor"));
	assert(glVertexArrayBindingDivisor_ != nullptr);
	return glVertexArrayBindingDivisor_(vaobj, bindingindex, divisor);
}
void glGetVertexArrayiv(GLuint vaobj, GLenum pname, GLint * param) {
	static const auto glGetVertexArrayiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint *)>(getProcAddress("glGetVertexArrayiv"));
	assert(glGetVertexArrayiv_ != nullptr);
	return glGetVertexArrayiv_(vaobj, pname, param);
}
void glGetVertexArrayIndexediv(GLuint vaobj, GLuint index, GLenum pname, GLint * param) {
	static const auto glGetVertexArrayIndexediv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLenum, GLint *)>(getProcAddress("glGetVertexArrayIndexediv"));
	assert(glGetVertexArrayIndexediv_ != nullptr);
	return glGetVertexArrayIndexediv_(vaobj, index, pname, param);
}
void glGetVertexArrayIndexed64iv(GLuint vaobj, GLuint index, GLenum pname, GLint64 * param) {
	static const auto glGetVertexArrayIndexed64iv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLenum, GLint64 *)>(getProcAddress("glGetVertexArrayIndexed64iv"));
	assert(glGetVertexArrayIndexed64iv_ != nullptr);
	return glGetVertexArrayIndexed64iv_(vaobj, index, pname, param);
}
void glCreateSamplers(GLsizei n, GLuint * samplers) {
	static const auto glCreateSamplers_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint *)>(getProcAddress("glCreateSamplers"));
	assert(glCreateSamplers_ != nullptr);
	return glCreateSamplers_(n, samplers);
}
void glCreateProgramPipelines(GLsizei n, GLuint * pipelines) {
	static const auto glCreateProgramPipelines_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint *)>(getProcAddress("glCreateProgramPipelines"));
	assert(glCreateProgramPipelines_ != nullptr);
	return glCreateProgramPipelines_(n, pipelines);
}
void glCreateQueries(GLenum target, GLsizei n, GLuint * ids) {
	static const auto glCreateQueries_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, GLuint *)>(getProcAddress("glCreateQueries"));
	assert(glCreateQueries_ != nullptr);
	return glCreateQueries_(target, n, ids);
}
void glGetQueryBufferObjecti64v(GLuint id, GLuint buffer, GLenum pname, GLintptr offset) {
	static const auto glGetQueryBufferObjecti64v_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLenum, GLintptr)>(getProcAddress("glGetQueryBufferObjecti64v"));
	assert(glGetQueryBufferObjecti64v_ != nullptr);
	return glGetQueryBufferObjecti64v_(id, buffer, pname, offset);
}
void glGetQueryBufferObjectiv(GLuint id, GLuint buffer, GLenum pname, GLintptr offset) {
	static const auto glGetQueryBufferObjectiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLenum, GLintptr)>(getProcAddress("glGetQueryBufferObjectiv"));
	assert(glGetQueryBufferObjectiv_ != nullptr);
	return glGetQueryBufferObjectiv_(id, buffer, pname, offset);
}
void glGetQueryBufferObjectui64v(GLuint id, GLuint buffer, GLenum pname, GLintptr offset) {
	static const auto glGetQueryBufferObjectui64v_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLenum, GLintptr)>(getProcAddress("glGetQueryBufferObjectui64v"));
	assert(glGetQueryBufferObjectui64v_ != nullptr);
	return glGetQueryBufferObjectui64v_(id, buffer, pname, offset);
}
void glGetQueryBufferObjectuiv(GLuint id, GLuint buffer, GLenum pname, GLintptr offset) {
	static const auto glGetQueryBufferObjectuiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLenum, GLintptr)>(getProcAddress("glGetQueryBufferObjectuiv"));
	assert(glGetQueryBufferObjectuiv_ != nullptr);
	return glGetQueryBufferObjectuiv_(id, buffer, pname, offset);
}
void glDrawBuffersARB(GLsizei n, GLenum const  * bufs) {
	static const auto glDrawBuffersARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLenum const  *)>(getProcAddress("glDrawBuffersARB"));
	assert(glDrawBuffersARB_ != nullptr);
	return glDrawBuffersARB_(n, bufs);
}
void glBlendEquationiARB(GLuint buf, GLenum mode) {
	static const auto glBlendEquationiARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum)>(getProcAddress("glBlendEquationiARB"));
	assert(glBlendEquationiARB_ != nullptr);
	return glBlendEquationiARB_(buf, mode);
}
void glBlendEquationSeparateiARB(GLuint buf, GLenum modeRGB, GLenum modeAlpha) {
	static const auto glBlendEquationSeparateiARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLenum)>(getProcAddress("glBlendEquationSeparateiARB"));
	assert(glBlendEquationSeparateiARB_ != nullptr);
	return glBlendEquationSeparateiARB_(buf, modeRGB, modeAlpha);
}
void glBlendFunciARB(GLuint buf, GLenum src, GLenum dst) {
	static const auto glBlendFunciARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLenum)>(getProcAddress("glBlendFunciARB"));
	assert(glBlendFunciARB_ != nullptr);
	return glBlendFunciARB_(buf, src, dst);
}
void glBlendFuncSeparateiARB(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) {
	static const auto glBlendFuncSeparateiARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLenum, GLenum, GLenum)>(getProcAddress("glBlendFuncSeparateiARB"));
	assert(glBlendFuncSeparateiARB_ != nullptr);
	return glBlendFuncSeparateiARB_(buf, srcRGB, dstRGB, srcAlpha, dstAlpha);
}
void glDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, const void * indices, GLint basevertex) {
	static const auto glDrawElementsBaseVertex_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, GLenum, const void *, GLint)>(getProcAddress("glDrawElementsBaseVertex"));
	assert(glDrawElementsBaseVertex_ != nullptr);
	return glDrawElementsBaseVertex_(mode, count, type, indices, basevertex);
}
void glDrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices, GLint basevertex) {
	static const auto glDrawRangeElementsBaseVertex_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint, GLuint, GLsizei, GLenum, const void *, GLint)>(getProcAddress("glDrawRangeElementsBaseVertex"));
	assert(glDrawRangeElementsBaseVertex_ != nullptr);
	return glDrawRangeElementsBaseVertex_(mode, start, end, count, type, indices, basevertex);
}
void glDrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex) {
	static const auto glDrawElementsInstancedBaseVertex_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, GLenum, const void *, GLsizei, GLint)>(getProcAddress("glDrawElementsInstancedBaseVertex"));
	assert(glDrawElementsInstancedBaseVertex_ != nullptr);
	return glDrawElementsInstancedBaseVertex_(mode, count, type, indices, instancecount, basevertex);
}
void glMultiDrawElementsBaseVertex(GLenum mode, GLsizei const  * count, GLenum type, const void *const* indices, GLsizei drawcount, GLint const  * basevertex) {
	static const auto glMultiDrawElementsBaseVertex_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei const  *, GLenum, const void *const*, GLsizei, GLint const  *)>(getProcAddress("glMultiDrawElementsBaseVertex"));
	assert(glMultiDrawElementsBaseVertex_ != nullptr);
	return glMultiDrawElementsBaseVertex_(mode, count, type, indices, drawcount, basevertex);
}
void glDrawArraysIndirect(GLenum mode, const void * indirect) {
	static const auto glDrawArraysIndirect_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, const void *)>(getProcAddress("glDrawArraysIndirect"));
	assert(glDrawArraysIndirect_ != nullptr);
	return glDrawArraysIndirect_(mode, indirect);
}
void glDrawElementsIndirect(GLenum mode, GLenum type, const void * indirect) {
	static const auto glDrawElementsIndirect_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, const void *)>(getProcAddress("glDrawElementsIndirect"));
	assert(glDrawElementsIndirect_ != nullptr);
	return glDrawElementsIndirect_(mode, type, indirect);
}
void glDrawArraysInstancedARB(GLenum mode, GLint first, GLsizei count, GLsizei primcount) {
	static const auto glDrawArraysInstancedARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLsizei, GLsizei)>(getProcAddress("glDrawArraysInstancedARB"));
	assert(glDrawArraysInstancedARB_ != nullptr);
	return glDrawArraysInstancedARB_(mode, first, count, primcount);
}
void glDrawElementsInstancedARB(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei primcount) {
	static const auto glDrawElementsInstancedARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, GLenum, const void *, GLsizei)>(getProcAddress("glDrawElementsInstancedARB"));
	assert(glDrawElementsInstancedARB_ != nullptr);
	return glDrawElementsInstancedARB_(mode, count, type, indices, primcount);
}
void glProgramStringARB(GLenum target, GLenum format, GLsizei len, const void * string) {
	static const auto glProgramStringARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLsizei, const void *)>(getProcAddress("glProgramStringARB"));
	assert(glProgramStringARB_ != nullptr);
	return glProgramStringARB_(target, format, len, string);
}
void glBindProgramARB(GLenum target, GLuint program) {
	static const auto glBindProgramARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint)>(getProcAddress("glBindProgramARB"));
	assert(glBindProgramARB_ != nullptr);
	return glBindProgramARB_(target, program);
}
void glDeleteProgramsARB(GLsizei n, GLuint const  * programs) {
	static const auto glDeleteProgramsARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint const  *)>(getProcAddress("glDeleteProgramsARB"));
	assert(glDeleteProgramsARB_ != nullptr);
	return glDeleteProgramsARB_(n, programs);
}
void glGenProgramsARB(GLsizei n, GLuint * programs) {
	static const auto glGenProgramsARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint *)>(getProcAddress("glGenProgramsARB"));
	assert(glGenProgramsARB_ != nullptr);
	return glGenProgramsARB_(n, programs);
}
void glProgramEnvParameter4dARB(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
	static const auto glProgramEnvParameter4dARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint, GLdouble, GLdouble, GLdouble, GLdouble)>(getProcAddress("glProgramEnvParameter4dARB"));
	assert(glProgramEnvParameter4dARB_ != nullptr);
	return glProgramEnvParameter4dARB_(target, index, x, y, z, w);
}
void glProgramEnvParameter4dvARB(GLenum target, GLuint index, GLdouble const  * params) {
	static const auto glProgramEnvParameter4dvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint, GLdouble const  *)>(getProcAddress("glProgramEnvParameter4dvARB"));
	assert(glProgramEnvParameter4dvARB_ != nullptr);
	return glProgramEnvParameter4dvARB_(target, index, params);
}
void glProgramEnvParameter4fARB(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
	static const auto glProgramEnvParameter4fARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint, GLfloat, GLfloat, GLfloat, GLfloat)>(getProcAddress("glProgramEnvParameter4fARB"));
	assert(glProgramEnvParameter4fARB_ != nullptr);
	return glProgramEnvParameter4fARB_(target, index, x, y, z, w);
}
void glProgramEnvParameter4fvARB(GLenum target, GLuint index, GLfloat const  * params) {
	static const auto glProgramEnvParameter4fvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint, GLfloat const  *)>(getProcAddress("glProgramEnvParameter4fvARB"));
	assert(glProgramEnvParameter4fvARB_ != nullptr);
	return glProgramEnvParameter4fvARB_(target, index, params);
}
void glProgramLocalParameter4dARB(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
	static const auto glProgramLocalParameter4dARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint, GLdouble, GLdouble, GLdouble, GLdouble)>(getProcAddress("glProgramLocalParameter4dARB"));
	assert(glProgramLocalParameter4dARB_ != nullptr);
	return glProgramLocalParameter4dARB_(target, index, x, y, z, w);
}
void glProgramLocalParameter4dvARB(GLenum target, GLuint index, GLdouble const  * params) {
	static const auto glProgramLocalParameter4dvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint, GLdouble const  *)>(getProcAddress("glProgramLocalParameter4dvARB"));
	assert(glProgramLocalParameter4dvARB_ != nullptr);
	return glProgramLocalParameter4dvARB_(target, index, params);
}
void glProgramLocalParameter4fARB(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
	static const auto glProgramLocalParameter4fARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint, GLfloat, GLfloat, GLfloat, GLfloat)>(getProcAddress("glProgramLocalParameter4fARB"));
	assert(glProgramLocalParameter4fARB_ != nullptr);
	return glProgramLocalParameter4fARB_(target, index, x, y, z, w);
}
void glProgramLocalParameter4fvARB(GLenum target, GLuint index, GLfloat const  * params) {
	static const auto glProgramLocalParameter4fvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint, GLfloat const  *)>(getProcAddress("glProgramLocalParameter4fvARB"));
	assert(glProgramLocalParameter4fvARB_ != nullptr);
	return glProgramLocalParameter4fvARB_(target, index, params);
}
void glGetProgramEnvParameterdvARB(GLenum target, GLuint index, GLdouble * params) {
	static const auto glGetProgramEnvParameterdvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint, GLdouble *)>(getProcAddress("glGetProgramEnvParameterdvARB"));
	assert(glGetProgramEnvParameterdvARB_ != nullptr);
	return glGetProgramEnvParameterdvARB_(target, index, params);
}
void glGetProgramEnvParameterfvARB(GLenum target, GLuint index, GLfloat * params) {
	static const auto glGetProgramEnvParameterfvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint, GLfloat *)>(getProcAddress("glGetProgramEnvParameterfvARB"));
	assert(glGetProgramEnvParameterfvARB_ != nullptr);
	return glGetProgramEnvParameterfvARB_(target, index, params);
}
void glGetProgramLocalParameterdvARB(GLenum target, GLuint index, GLdouble * params) {
	static const auto glGetProgramLocalParameterdvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint, GLdouble *)>(getProcAddress("glGetProgramLocalParameterdvARB"));
	assert(glGetProgramLocalParameterdvARB_ != nullptr);
	return glGetProgramLocalParameterdvARB_(target, index, params);
}
void glGetProgramLocalParameterfvARB(GLenum target, GLuint index, GLfloat * params) {
	static const auto glGetProgramLocalParameterfvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint, GLfloat *)>(getProcAddress("glGetProgramLocalParameterfvARB"));
	assert(glGetProgramLocalParameterfvARB_ != nullptr);
	return glGetProgramLocalParameterfvARB_(target, index, params);
}
void glGetProgramivARB(GLenum target, GLenum pname, GLint * params) {
	static const auto glGetProgramivARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint *)>(getProcAddress("glGetProgramivARB"));
	assert(glGetProgramivARB_ != nullptr);
	return glGetProgramivARB_(target, pname, params);
}
void glGetProgramStringARB(GLenum target, GLenum pname, void * string) {
	static const auto glGetProgramStringARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, void *)>(getProcAddress("glGetProgramStringARB"));
	assert(glGetProgramStringARB_ != nullptr);
	return glGetProgramStringARB_(target, pname, string);
}
GLboolean glIsProgramARB(GLuint program) {
	static const auto glIsProgramARB_ = reinterpret_cast<GLboolean(GL_APIENTRYP)(GLuint)>(getProcAddress("glIsProgramARB"));
	assert(glIsProgramARB_ != nullptr);
	return glIsProgramARB_(program);
}
void glFramebufferParameteri(GLenum target, GLenum pname, GLint param) {
	static const auto glFramebufferParameteri_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint)>(getProcAddress("glFramebufferParameteri"));
	assert(glFramebufferParameteri_ != nullptr);
	return glFramebufferParameteri_(target, pname, param);
}
void glGetFramebufferParameteriv(GLenum target, GLenum pname, GLint * params) {
	static const auto glGetFramebufferParameteriv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint *)>(getProcAddress("glGetFramebufferParameteriv"));
	assert(glGetFramebufferParameteriv_ != nullptr);
	return glGetFramebufferParameteriv_(target, pname, params);
}
void glProgramParameteriARB(GLuint program, GLenum pname, GLint value) {
	static const auto glProgramParameteriARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint)>(getProcAddress("glProgramParameteriARB"));
	assert(glProgramParameteriARB_ != nullptr);
	return glProgramParameteriARB_(program, pname, value);
}
void glFramebufferTextureARB(GLenum target, GLenum attachment, GLuint texture, GLint level) {
	static const auto glFramebufferTextureARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLuint, GLint)>(getProcAddress("glFramebufferTextureARB"));
	assert(glFramebufferTextureARB_ != nullptr);
	return glFramebufferTextureARB_(target, attachment, texture, level);
}
void glFramebufferTextureLayerARB(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) {
	static const auto glFramebufferTextureLayerARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLuint, GLint, GLint)>(getProcAddress("glFramebufferTextureLayerARB"));
	assert(glFramebufferTextureLayerARB_ != nullptr);
	return glFramebufferTextureLayerARB_(target, attachment, texture, level, layer);
}
void glFramebufferTextureFaceARB(GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face) {
	static const auto glFramebufferTextureFaceARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLuint, GLint, GLenum)>(getProcAddress("glFramebufferTextureFaceARB"));
	assert(glFramebufferTextureFaceARB_ != nullptr);
	return glFramebufferTextureFaceARB_(target, attachment, texture, level, face);
}
void glGetProgramBinary(GLuint program, GLsizei bufSize, GLsizei * length, GLenum * binaryFormat, void * binary) {
	static const auto glGetProgramBinary_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLsizei, GLsizei *, GLenum *, void *)>(getProcAddress("glGetProgramBinary"));
	assert(glGetProgramBinary_ != nullptr);
	return glGetProgramBinary_(program, bufSize, length, binaryFormat, binary);
}
void glProgramBinary(GLuint program, GLenum binaryFormat, const void * binary, GLsizei length) {
	static const auto glProgramBinary_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, const void *, GLsizei)>(getProcAddress("glProgramBinary"));
	assert(glProgramBinary_ != nullptr);
	return glProgramBinary_(program, binaryFormat, binary, length);
}
void glProgramParameteri(GLuint program, GLenum pname, GLint value) {
	static const auto glProgramParameteri_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint)>(getProcAddress("glProgramParameteri"));
	assert(glProgramParameteri_ != nullptr);
	return glProgramParameteri_(program, pname, value);
}
void glGetTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void * pixels) {
	static const auto glGetTextureSubImage_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, GLsizei, void *)>(getProcAddress("glGetTextureSubImage"));
	assert(glGetTextureSubImage_ != nullptr);
	return glGetTextureSubImage_(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, bufSize, pixels);
}
void glGetCompressedTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void * pixels) {
	static const auto glGetCompressedTextureSubImage_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLsizei, void *)>(getProcAddress("glGetCompressedTextureSubImage"));
	assert(glGetCompressedTextureSubImage_ != nullptr);
	return glGetCompressedTextureSubImage_(texture, level, xoffset, yoffset, zoffset, width, height, depth, bufSize, pixels);
}
void glSpecializeShaderARB(GLuint shader, GLchar const  * pEntryPoint, GLuint numSpecializationConstants, GLuint const  * pConstantIndex, GLuint const  * pConstantValue) {
	static const auto glSpecializeShaderARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLchar const  *, GLuint, GLuint const  *, GLuint const  *)>(getProcAddress("glSpecializeShaderARB"));
	assert(glSpecializeShaderARB_ != nullptr);
	return glSpecializeShaderARB_(shader, pEntryPoint, numSpecializationConstants, pConstantIndex, pConstantValue);
}
void glUniform1d(GLint location, GLdouble x) {
	static const auto glUniform1d_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLdouble)>(getProcAddress("glUniform1d"));
	assert(glUniform1d_ != nullptr);
	return glUniform1d_(location, x);
}
void glUniform2d(GLint location, GLdouble x, GLdouble y) {
	static const auto glUniform2d_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLdouble, GLdouble)>(getProcAddress("glUniform2d"));
	assert(glUniform2d_ != nullptr);
	return glUniform2d_(location, x, y);
}
void glUniform3d(GLint location, GLdouble x, GLdouble y, GLdouble z) {
	static const auto glUniform3d_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLdouble, GLdouble, GLdouble)>(getProcAddress("glUniform3d"));
	assert(glUniform3d_ != nullptr);
	return glUniform3d_(location, x, y, z);
}
void glUniform4d(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
	static const auto glUniform4d_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLdouble, GLdouble, GLdouble, GLdouble)>(getProcAddress("glUniform4d"));
	assert(glUniform4d_ != nullptr);
	return glUniform4d_(location, x, y, z, w);
}
void glUniform1dv(GLint location, GLsizei count, GLdouble const  * value) {
	static const auto glUniform1dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLdouble const  *)>(getProcAddress("glUniform1dv"));
	assert(glUniform1dv_ != nullptr);
	return glUniform1dv_(location, count, value);
}
void glUniform2dv(GLint location, GLsizei count, GLdouble const  * value) {
	static const auto glUniform2dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLdouble const  *)>(getProcAddress("glUniform2dv"));
	assert(glUniform2dv_ != nullptr);
	return glUniform2dv_(location, count, value);
}
void glUniform3dv(GLint location, GLsizei count, GLdouble const  * value) {
	static const auto glUniform3dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLdouble const  *)>(getProcAddress("glUniform3dv"));
	assert(glUniform3dv_ != nullptr);
	return glUniform3dv_(location, count, value);
}
void glUniform4dv(GLint location, GLsizei count, GLdouble const  * value) {
	static const auto glUniform4dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLdouble const  *)>(getProcAddress("glUniform4dv"));
	assert(glUniform4dv_ != nullptr);
	return glUniform4dv_(location, count, value);
}
void glUniformMatrix2dv(GLint location, GLsizei count, GLboolean transpose, GLdouble const  * value) {
	static const auto glUniformMatrix2dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLboolean, GLdouble const  *)>(getProcAddress("glUniformMatrix2dv"));
	assert(glUniformMatrix2dv_ != nullptr);
	return glUniformMatrix2dv_(location, count, transpose, value);
}
void glUniformMatrix3dv(GLint location, GLsizei count, GLboolean transpose, GLdouble const  * value) {
	static const auto glUniformMatrix3dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLboolean, GLdouble const  *)>(getProcAddress("glUniformMatrix3dv"));
	assert(glUniformMatrix3dv_ != nullptr);
	return glUniformMatrix3dv_(location, count, transpose, value);
}
void glUniformMatrix4dv(GLint location, GLsizei count, GLboolean transpose, GLdouble const  * value) {
	static const auto glUniformMatrix4dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLboolean, GLdouble const  *)>(getProcAddress("glUniformMatrix4dv"));
	assert(glUniformMatrix4dv_ != nullptr);
	return glUniformMatrix4dv_(location, count, transpose, value);
}
void glUniformMatrix2x3dv(GLint location, GLsizei count, GLboolean transpose, GLdouble const  * value) {
	static const auto glUniformMatrix2x3dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLboolean, GLdouble const  *)>(getProcAddress("glUniformMatrix2x3dv"));
	assert(glUniformMatrix2x3dv_ != nullptr);
	return glUniformMatrix2x3dv_(location, count, transpose, value);
}
void glUniformMatrix2x4dv(GLint location, GLsizei count, GLboolean transpose, GLdouble const  * value) {
	static const auto glUniformMatrix2x4dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLboolean, GLdouble const  *)>(getProcAddress("glUniformMatrix2x4dv"));
	assert(glUniformMatrix2x4dv_ != nullptr);
	return glUniformMatrix2x4dv_(location, count, transpose, value);
}
void glUniformMatrix3x2dv(GLint location, GLsizei count, GLboolean transpose, GLdouble const  * value) {
	static const auto glUniformMatrix3x2dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLboolean, GLdouble const  *)>(getProcAddress("glUniformMatrix3x2dv"));
	assert(glUniformMatrix3x2dv_ != nullptr);
	return glUniformMatrix3x2dv_(location, count, transpose, value);
}
void glUniformMatrix3x4dv(GLint location, GLsizei count, GLboolean transpose, GLdouble const  * value) {
	static const auto glUniformMatrix3x4dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLboolean, GLdouble const  *)>(getProcAddress("glUniformMatrix3x4dv"));
	assert(glUniformMatrix3x4dv_ != nullptr);
	return glUniformMatrix3x4dv_(location, count, transpose, value);
}
void glUniformMatrix4x2dv(GLint location, GLsizei count, GLboolean transpose, GLdouble const  * value) {
	static const auto glUniformMatrix4x2dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLboolean, GLdouble const  *)>(getProcAddress("glUniformMatrix4x2dv"));
	assert(glUniformMatrix4x2dv_ != nullptr);
	return glUniformMatrix4x2dv_(location, count, transpose, value);
}
void glUniformMatrix4x3dv(GLint location, GLsizei count, GLboolean transpose, GLdouble const  * value) {
	static const auto glUniformMatrix4x3dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLboolean, GLdouble const  *)>(getProcAddress("glUniformMatrix4x3dv"));
	assert(glUniformMatrix4x3dv_ != nullptr);
	return glUniformMatrix4x3dv_(location, count, transpose, value);
}
void glGetUniformdv(GLuint program, GLint location, GLdouble * params) {
	static const auto glGetUniformdv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLdouble *)>(getProcAddress("glGetUniformdv"));
	assert(glGetUniformdv_ != nullptr);
	return glGetUniformdv_(program, location, params);
}
void glUniform1i64ARB(GLint location, GLint64 x) {
	static const auto glUniform1i64ARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLint64)>(getProcAddress("glUniform1i64ARB"));
	assert(glUniform1i64ARB_ != nullptr);
	return glUniform1i64ARB_(location, x);
}
void glUniform2i64ARB(GLint location, GLint64 x, GLint64 y) {
	static const auto glUniform2i64ARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLint64, GLint64)>(getProcAddress("glUniform2i64ARB"));
	assert(glUniform2i64ARB_ != nullptr);
	return glUniform2i64ARB_(location, x, y);
}
void glUniform3i64ARB(GLint location, GLint64 x, GLint64 y, GLint64 z) {
	static const auto glUniform3i64ARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLint64, GLint64, GLint64)>(getProcAddress("glUniform3i64ARB"));
	assert(glUniform3i64ARB_ != nullptr);
	return glUniform3i64ARB_(location, x, y, z);
}
void glUniform4i64ARB(GLint location, GLint64 x, GLint64 y, GLint64 z, GLint64 w) {
	static const auto glUniform4i64ARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLint64, GLint64, GLint64, GLint64)>(getProcAddress("glUniform4i64ARB"));
	assert(glUniform4i64ARB_ != nullptr);
	return glUniform4i64ARB_(location, x, y, z, w);
}
void glUniform1i64vARB(GLint location, GLsizei count, GLint64 const  * value) {
	static const auto glUniform1i64vARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLint64 const  *)>(getProcAddress("glUniform1i64vARB"));
	assert(glUniform1i64vARB_ != nullptr);
	return glUniform1i64vARB_(location, count, value);
}
void glUniform2i64vARB(GLint location, GLsizei count, GLint64 const  * value) {
	static const auto glUniform2i64vARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLint64 const  *)>(getProcAddress("glUniform2i64vARB"));
	assert(glUniform2i64vARB_ != nullptr);
	return glUniform2i64vARB_(location, count, value);
}
void glUniform3i64vARB(GLint location, GLsizei count, GLint64 const  * value) {
	static const auto glUniform3i64vARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLint64 const  *)>(getProcAddress("glUniform3i64vARB"));
	assert(glUniform3i64vARB_ != nullptr);
	return glUniform3i64vARB_(location, count, value);
}
void glUniform4i64vARB(GLint location, GLsizei count, GLint64 const  * value) {
	static const auto glUniform4i64vARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLint64 const  *)>(getProcAddress("glUniform4i64vARB"));
	assert(glUniform4i64vARB_ != nullptr);
	return glUniform4i64vARB_(location, count, value);
}
void glUniform1ui64ARB(GLint location, GLuint64 x) {
	static const auto glUniform1ui64ARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLuint64)>(getProcAddress("glUniform1ui64ARB"));
	assert(glUniform1ui64ARB_ != nullptr);
	return glUniform1ui64ARB_(location, x);
}
void glUniform2ui64ARB(GLint location, GLuint64 x, GLuint64 y) {
	static const auto glUniform2ui64ARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLuint64, GLuint64)>(getProcAddress("glUniform2ui64ARB"));
	assert(glUniform2ui64ARB_ != nullptr);
	return glUniform2ui64ARB_(location, x, y);
}
void glUniform3ui64ARB(GLint location, GLuint64 x, GLuint64 y, GLuint64 z) {
	static const auto glUniform3ui64ARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLuint64, GLuint64, GLuint64)>(getProcAddress("glUniform3ui64ARB"));
	assert(glUniform3ui64ARB_ != nullptr);
	return glUniform3ui64ARB_(location, x, y, z);
}
void glUniform4ui64ARB(GLint location, GLuint64 x, GLuint64 y, GLuint64 z, GLuint64 w) {
	static const auto glUniform4ui64ARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLuint64, GLuint64, GLuint64, GLuint64)>(getProcAddress("glUniform4ui64ARB"));
	assert(glUniform4ui64ARB_ != nullptr);
	return glUniform4ui64ARB_(location, x, y, z, w);
}
void glUniform1ui64vARB(GLint location, GLsizei count, GLuint64 const  * value) {
	static const auto glUniform1ui64vARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLuint64 const  *)>(getProcAddress("glUniform1ui64vARB"));
	assert(glUniform1ui64vARB_ != nullptr);
	return glUniform1ui64vARB_(location, count, value);
}
void glUniform2ui64vARB(GLint location, GLsizei count, GLuint64 const  * value) {
	static const auto glUniform2ui64vARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLuint64 const  *)>(getProcAddress("glUniform2ui64vARB"));
	assert(glUniform2ui64vARB_ != nullptr);
	return glUniform2ui64vARB_(location, count, value);
}
void glUniform3ui64vARB(GLint location, GLsizei count, GLuint64 const  * value) {
	static const auto glUniform3ui64vARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLuint64 const  *)>(getProcAddress("glUniform3ui64vARB"));
	assert(glUniform3ui64vARB_ != nullptr);
	return glUniform3ui64vARB_(location, count, value);
}
void glUniform4ui64vARB(GLint location, GLsizei count, GLuint64 const  * value) {
	static const auto glUniform4ui64vARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLuint64 const  *)>(getProcAddress("glUniform4ui64vARB"));
	assert(glUniform4ui64vARB_ != nullptr);
	return glUniform4ui64vARB_(location, count, value);
}
void glGetUniformi64vARB(GLuint program, GLint location, GLint64 * params) {
	static const auto glGetUniformi64vARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLint64 *)>(getProcAddress("glGetUniformi64vARB"));
	assert(glGetUniformi64vARB_ != nullptr);
	return glGetUniformi64vARB_(program, location, params);
}
void glGetUniformui64vARB(GLuint program, GLint location, GLuint64 * params) {
	static const auto glGetUniformui64vARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLuint64 *)>(getProcAddress("glGetUniformui64vARB"));
	assert(glGetUniformui64vARB_ != nullptr);
	return glGetUniformui64vARB_(program, location, params);
}
void glGetnUniformi64vARB(GLuint program, GLint location, GLsizei bufSize, GLint64 * params) {
	static const auto glGetnUniformi64vARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLint64 *)>(getProcAddress("glGetnUniformi64vARB"));
	assert(glGetnUniformi64vARB_ != nullptr);
	return glGetnUniformi64vARB_(program, location, bufSize, params);
}
void glGetnUniformui64vARB(GLuint program, GLint location, GLsizei bufSize, GLuint64 * params) {
	static const auto glGetnUniformui64vARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLuint64 *)>(getProcAddress("glGetnUniformui64vARB"));
	assert(glGetnUniformui64vARB_ != nullptr);
	return glGetnUniformui64vARB_(program, location, bufSize, params);
}
void glProgramUniform1i64ARB(GLuint program, GLint location, GLint64 x) {
	static const auto glProgramUniform1i64ARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLint64)>(getProcAddress("glProgramUniform1i64ARB"));
	assert(glProgramUniform1i64ARB_ != nullptr);
	return glProgramUniform1i64ARB_(program, location, x);
}
void glProgramUniform2i64ARB(GLuint program, GLint location, GLint64 x, GLint64 y) {
	static const auto glProgramUniform2i64ARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLint64, GLint64)>(getProcAddress("glProgramUniform2i64ARB"));
	assert(glProgramUniform2i64ARB_ != nullptr);
	return glProgramUniform2i64ARB_(program, location, x, y);
}
void glProgramUniform3i64ARB(GLuint program, GLint location, GLint64 x, GLint64 y, GLint64 z) {
	static const auto glProgramUniform3i64ARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLint64, GLint64, GLint64)>(getProcAddress("glProgramUniform3i64ARB"));
	assert(glProgramUniform3i64ARB_ != nullptr);
	return glProgramUniform3i64ARB_(program, location, x, y, z);
}
void glProgramUniform4i64ARB(GLuint program, GLint location, GLint64 x, GLint64 y, GLint64 z, GLint64 w) {
	static const auto glProgramUniform4i64ARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLint64, GLint64, GLint64, GLint64)>(getProcAddress("glProgramUniform4i64ARB"));
	assert(glProgramUniform4i64ARB_ != nullptr);
	return glProgramUniform4i64ARB_(program, location, x, y, z, w);
}
void glProgramUniform1i64vARB(GLuint program, GLint location, GLsizei count, GLint64 const  * value) {
	static const auto glProgramUniform1i64vARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLint64 const  *)>(getProcAddress("glProgramUniform1i64vARB"));
	assert(glProgramUniform1i64vARB_ != nullptr);
	return glProgramUniform1i64vARB_(program, location, count, value);
}
void glProgramUniform2i64vARB(GLuint program, GLint location, GLsizei count, GLint64 const  * value) {
	static const auto glProgramUniform2i64vARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLint64 const  *)>(getProcAddress("glProgramUniform2i64vARB"));
	assert(glProgramUniform2i64vARB_ != nullptr);
	return glProgramUniform2i64vARB_(program, location, count, value);
}
void glProgramUniform3i64vARB(GLuint program, GLint location, GLsizei count, GLint64 const  * value) {
	static const auto glProgramUniform3i64vARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLint64 const  *)>(getProcAddress("glProgramUniform3i64vARB"));
	assert(glProgramUniform3i64vARB_ != nullptr);
	return glProgramUniform3i64vARB_(program, location, count, value);
}
void glProgramUniform4i64vARB(GLuint program, GLint location, GLsizei count, GLint64 const  * value) {
	static const auto glProgramUniform4i64vARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLint64 const  *)>(getProcAddress("glProgramUniform4i64vARB"));
	assert(glProgramUniform4i64vARB_ != nullptr);
	return glProgramUniform4i64vARB_(program, location, count, value);
}
void glProgramUniform1ui64ARB(GLuint program, GLint location, GLuint64 x) {
	static const auto glProgramUniform1ui64ARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLuint64)>(getProcAddress("glProgramUniform1ui64ARB"));
	assert(glProgramUniform1ui64ARB_ != nullptr);
	return glProgramUniform1ui64ARB_(program, location, x);
}
void glProgramUniform2ui64ARB(GLuint program, GLint location, GLuint64 x, GLuint64 y) {
	static const auto glProgramUniform2ui64ARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLuint64, GLuint64)>(getProcAddress("glProgramUniform2ui64ARB"));
	assert(glProgramUniform2ui64ARB_ != nullptr);
	return glProgramUniform2ui64ARB_(program, location, x, y);
}
void glProgramUniform3ui64ARB(GLuint program, GLint location, GLuint64 x, GLuint64 y, GLuint64 z) {
	static const auto glProgramUniform3ui64ARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLuint64, GLuint64, GLuint64)>(getProcAddress("glProgramUniform3ui64ARB"));
	assert(glProgramUniform3ui64ARB_ != nullptr);
	return glProgramUniform3ui64ARB_(program, location, x, y, z);
}
void glProgramUniform4ui64ARB(GLuint program, GLint location, GLuint64 x, GLuint64 y, GLuint64 z, GLuint64 w) {
	static const auto glProgramUniform4ui64ARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLuint64, GLuint64, GLuint64, GLuint64)>(getProcAddress("glProgramUniform4ui64ARB"));
	assert(glProgramUniform4ui64ARB_ != nullptr);
	return glProgramUniform4ui64ARB_(program, location, x, y, z, w);
}
void glProgramUniform1ui64vARB(GLuint program, GLint location, GLsizei count, GLuint64 const  * value) {
	static const auto glProgramUniform1ui64vARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLuint64 const  *)>(getProcAddress("glProgramUniform1ui64vARB"));
	assert(glProgramUniform1ui64vARB_ != nullptr);
	return glProgramUniform1ui64vARB_(program, location, count, value);
}
void glProgramUniform2ui64vARB(GLuint program, GLint location, GLsizei count, GLuint64 const  * value) {
	static const auto glProgramUniform2ui64vARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLuint64 const  *)>(getProcAddress("glProgramUniform2ui64vARB"));
	assert(glProgramUniform2ui64vARB_ != nullptr);
	return glProgramUniform2ui64vARB_(program, location, count, value);
}
void glProgramUniform3ui64vARB(GLuint program, GLint location, GLsizei count, GLuint64 const  * value) {
	static const auto glProgramUniform3ui64vARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLuint64 const  *)>(getProcAddress("glProgramUniform3ui64vARB"));
	assert(glProgramUniform3ui64vARB_ != nullptr);
	return glProgramUniform3ui64vARB_(program, location, count, value);
}
void glProgramUniform4ui64vARB(GLuint program, GLint location, GLsizei count, GLuint64 const  * value) {
	static const auto glProgramUniform4ui64vARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLuint64 const  *)>(getProcAddress("glProgramUniform4ui64vARB"));
	assert(glProgramUniform4ui64vARB_ != nullptr);
	return glProgramUniform4ui64vARB_(program, location, count, value);
}
void glColorTable(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void * table) {
	static const auto glColorTable_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLsizei, GLenum, GLenum, const void *)>(getProcAddress("glColorTable"));
	assert(glColorTable_ != nullptr);
	return glColorTable_(target, internalformat, width, format, type, table);
}
void glColorTableParameterfv(GLenum target, GLenum pname, GLfloat const  * params) {
	static const auto glColorTableParameterfv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfloat const  *)>(getProcAddress("glColorTableParameterfv"));
	assert(glColorTableParameterfv_ != nullptr);
	return glColorTableParameterfv_(target, pname, params);
}
void glColorTableParameteriv(GLenum target, GLenum pname, GLint const  * params) {
	static const auto glColorTableParameteriv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint const  *)>(getProcAddress("glColorTableParameteriv"));
	assert(glColorTableParameteriv_ != nullptr);
	return glColorTableParameteriv_(target, pname, params);
}
void glCopyColorTable(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width) {
	static const auto glCopyColorTable_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint, GLint, GLsizei)>(getProcAddress("glCopyColorTable"));
	assert(glCopyColorTable_ != nullptr);
	return glCopyColorTable_(target, internalformat, x, y, width);
}
void glGetColorTable(GLenum target, GLenum format, GLenum type, void * table) {
	static const auto glGetColorTable_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, void *)>(getProcAddress("glGetColorTable"));
	assert(glGetColorTable_ != nullptr);
	return glGetColorTable_(target, format, type, table);
}
void glGetColorTableParameterfv(GLenum target, GLenum pname, GLfloat * params) {
	static const auto glGetColorTableParameterfv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfloat *)>(getProcAddress("glGetColorTableParameterfv"));
	assert(glGetColorTableParameterfv_ != nullptr);
	return glGetColorTableParameterfv_(target, pname, params);
}
void glGetColorTableParameteriv(GLenum target, GLenum pname, GLint * params) {
	static const auto glGetColorTableParameteriv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint *)>(getProcAddress("glGetColorTableParameteriv"));
	assert(glGetColorTableParameteriv_ != nullptr);
	return glGetColorTableParameteriv_(target, pname, params);
}
void glColorSubTable(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const void * data) {
	static const auto glColorSubTable_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, GLsizei, GLenum, GLenum, const void *)>(getProcAddress("glColorSubTable"));
	assert(glColorSubTable_ != nullptr);
	return glColorSubTable_(target, start, count, format, type, data);
}
void glCopyColorSubTable(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width) {
	static const auto glCopyColorSubTable_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, GLint, GLint, GLsizei)>(getProcAddress("glCopyColorSubTable"));
	assert(glCopyColorSubTable_ != nullptr);
	return glCopyColorSubTable_(target, start, x, y, width);
}
void glConvolutionFilter1D(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void * image) {
	static const auto glConvolutionFilter1D_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLsizei, GLenum, GLenum, const void *)>(getProcAddress("glConvolutionFilter1D"));
	assert(glConvolutionFilter1D_ != nullptr);
	return glConvolutionFilter1D_(target, internalformat, width, format, type, image);
}
void glConvolutionFilter2D(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * image) {
	static const auto glConvolutionFilter2D_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const void *)>(getProcAddress("glConvolutionFilter2D"));
	assert(glConvolutionFilter2D_ != nullptr);
	return glConvolutionFilter2D_(target, internalformat, width, height, format, type, image);
}
void glConvolutionParameterf(GLenum target, GLenum pname, GLfloat params) {
	static const auto glConvolutionParameterf_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfloat)>(getProcAddress("glConvolutionParameterf"));
	assert(glConvolutionParameterf_ != nullptr);
	return glConvolutionParameterf_(target, pname, params);
}
void glConvolutionParameterfv(GLenum target, GLenum pname, GLfloat const  * params) {
	static const auto glConvolutionParameterfv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfloat const  *)>(getProcAddress("glConvolutionParameterfv"));
	assert(glConvolutionParameterfv_ != nullptr);
	return glConvolutionParameterfv_(target, pname, params);
}
void glConvolutionParameteri(GLenum target, GLenum pname, GLint params) {
	static const auto glConvolutionParameteri_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint)>(getProcAddress("glConvolutionParameteri"));
	assert(glConvolutionParameteri_ != nullptr);
	return glConvolutionParameteri_(target, pname, params);
}
void glConvolutionParameteriv(GLenum target, GLenum pname, GLint const  * params) {
	static const auto glConvolutionParameteriv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint const  *)>(getProcAddress("glConvolutionParameteriv"));
	assert(glConvolutionParameteriv_ != nullptr);
	return glConvolutionParameteriv_(target, pname, params);
}
void glCopyConvolutionFilter1D(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width) {
	static const auto glCopyConvolutionFilter1D_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint, GLint, GLsizei)>(getProcAddress("glCopyConvolutionFilter1D"));
	assert(glCopyConvolutionFilter1D_ != nullptr);
	return glCopyConvolutionFilter1D_(target, internalformat, x, y, width);
}
void glCopyConvolutionFilter2D(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height) {
	static const auto glCopyConvolutionFilter2D_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint, GLint, GLsizei, GLsizei)>(getProcAddress("glCopyConvolutionFilter2D"));
	assert(glCopyConvolutionFilter2D_ != nullptr);
	return glCopyConvolutionFilter2D_(target, internalformat, x, y, width, height);
}
void glGetConvolutionFilter(GLenum target, GLenum format, GLenum type, void * image) {
	static const auto glGetConvolutionFilter_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, void *)>(getProcAddress("glGetConvolutionFilter"));
	assert(glGetConvolutionFilter_ != nullptr);
	return glGetConvolutionFilter_(target, format, type, image);
}
void glGetConvolutionParameterfv(GLenum target, GLenum pname, GLfloat * params) {
	static const auto glGetConvolutionParameterfv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfloat *)>(getProcAddress("glGetConvolutionParameterfv"));
	assert(glGetConvolutionParameterfv_ != nullptr);
	return glGetConvolutionParameterfv_(target, pname, params);
}
void glGetConvolutionParameteriv(GLenum target, GLenum pname, GLint * params) {
	static const auto glGetConvolutionParameteriv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint *)>(getProcAddress("glGetConvolutionParameteriv"));
	assert(glGetConvolutionParameteriv_ != nullptr);
	return glGetConvolutionParameteriv_(target, pname, params);
}
void glGetSeparableFilter(GLenum target, GLenum format, GLenum type, void * row, void * column, void * span) {
	static const auto glGetSeparableFilter_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, void *, void *, void *)>(getProcAddress("glGetSeparableFilter"));
	assert(glGetSeparableFilter_ != nullptr);
	return glGetSeparableFilter_(target, format, type, row, column, span);
}
void glSeparableFilter2D(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * row, const void * column) {
	static const auto glSeparableFilter2D_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const void *, const void *)>(getProcAddress("glSeparableFilter2D"));
	assert(glSeparableFilter2D_ != nullptr);
	return glSeparableFilter2D_(target, internalformat, width, height, format, type, row, column);
}
void glGetHistogram(GLenum target, GLboolean reset, GLenum format, GLenum type, void * values) {
	static const auto glGetHistogram_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLboolean, GLenum, GLenum, void *)>(getProcAddress("glGetHistogram"));
	assert(glGetHistogram_ != nullptr);
	return glGetHistogram_(target, reset, format, type, values);
}
void glGetHistogramParameterfv(GLenum target, GLenum pname, GLfloat * params) {
	static const auto glGetHistogramParameterfv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfloat *)>(getProcAddress("glGetHistogramParameterfv"));
	assert(glGetHistogramParameterfv_ != nullptr);
	return glGetHistogramParameterfv_(target, pname, params);
}
void glGetHistogramParameteriv(GLenum target, GLenum pname, GLint * params) {
	static const auto glGetHistogramParameteriv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint *)>(getProcAddress("glGetHistogramParameteriv"));
	assert(glGetHistogramParameteriv_ != nullptr);
	return glGetHistogramParameteriv_(target, pname, params);
}
void glGetMinmax(GLenum target, GLboolean reset, GLenum format, GLenum type, void * values) {
	static const auto glGetMinmax_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLboolean, GLenum, GLenum, void *)>(getProcAddress("glGetMinmax"));
	assert(glGetMinmax_ != nullptr);
	return glGetMinmax_(target, reset, format, type, values);
}
void glGetMinmaxParameterfv(GLenum target, GLenum pname, GLfloat * params) {
	static const auto glGetMinmaxParameterfv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfloat *)>(getProcAddress("glGetMinmaxParameterfv"));
	assert(glGetMinmaxParameterfv_ != nullptr);
	return glGetMinmaxParameterfv_(target, pname, params);
}
void glGetMinmaxParameteriv(GLenum target, GLenum pname, GLint * params) {
	static const auto glGetMinmaxParameteriv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint *)>(getProcAddress("glGetMinmaxParameteriv"));
	assert(glGetMinmaxParameteriv_ != nullptr);
	return glGetMinmaxParameteriv_(target, pname, params);
}
void glHistogram(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink) {
	static const auto glHistogram_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, GLenum, GLboolean)>(getProcAddress("glHistogram"));
	assert(glHistogram_ != nullptr);
	return glHistogram_(target, width, internalformat, sink);
}
void glMinmax(GLenum target, GLenum internalformat, GLboolean sink) {
	static const auto glMinmax_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLboolean)>(getProcAddress("glMinmax"));
	assert(glMinmax_ != nullptr);
	return glMinmax_(target, internalformat, sink);
}
void glResetHistogram(GLenum target) {
	static const auto glResetHistogram_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glResetHistogram"));
	assert(glResetHistogram_ != nullptr);
	return glResetHistogram_(target);
}
void glResetMinmax(GLenum target) {
	static const auto glResetMinmax_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glResetMinmax"));
	assert(glResetMinmax_ != nullptr);
	return glResetMinmax_(target);
}
void glMultiDrawArraysIndirectCountARB(GLenum mode, const void * indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride) {
	static const auto glMultiDrawArraysIndirectCountARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, const void *, GLintptr, GLsizei, GLsizei)>(getProcAddress("glMultiDrawArraysIndirectCountARB"));
	assert(glMultiDrawArraysIndirectCountARB_ != nullptr);
	return glMultiDrawArraysIndirectCountARB_(mode, indirect, drawcount, maxdrawcount, stride);
}
void glMultiDrawElementsIndirectCountARB(GLenum mode, GLenum type, const void * indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride) {
	static const auto glMultiDrawElementsIndirectCountARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, const void *, GLintptr, GLsizei, GLsizei)>(getProcAddress("glMultiDrawElementsIndirectCountARB"));
	assert(glMultiDrawElementsIndirectCountARB_ != nullptr);
	return glMultiDrawElementsIndirectCountARB_(mode, type, indirect, drawcount, maxdrawcount, stride);
}
void glVertexAttribDivisorARB(GLuint index, GLuint divisor) {
	static const auto glVertexAttribDivisorARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint)>(getProcAddress("glVertexAttribDivisorARB"));
	assert(glVertexAttribDivisorARB_ != nullptr);
	return glVertexAttribDivisorARB_(index, divisor);
}
void glGetInternalformativ(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint * params) {
	static const auto glGetInternalformativ_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLsizei, GLint *)>(getProcAddress("glGetInternalformativ"));
	assert(glGetInternalformativ_ != nullptr);
	return glGetInternalformativ_(target, internalformat, pname, count, params);
}
void glGetInternalformati64v(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint64 * params) {
	static const auto glGetInternalformati64v_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLsizei, GLint64 *)>(getProcAddress("glGetInternalformati64v"));
	assert(glGetInternalformati64v_ != nullptr);
	return glGetInternalformati64v_(target, internalformat, pname, count, params);
}
void glInvalidateTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth) {
	static const auto glInvalidateTexSubImage_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei)>(getProcAddress("glInvalidateTexSubImage"));
	assert(glInvalidateTexSubImage_ != nullptr);
	return glInvalidateTexSubImage_(texture, level, xoffset, yoffset, zoffset, width, height, depth);
}
void glInvalidateTexImage(GLuint texture, GLint level) {
	static const auto glInvalidateTexImage_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint)>(getProcAddress("glInvalidateTexImage"));
	assert(glInvalidateTexImage_ != nullptr);
	return glInvalidateTexImage_(texture, level);
}
void glInvalidateBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr length) {
	static const auto glInvalidateBufferSubData_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLintptr, GLsizeiptr)>(getProcAddress("glInvalidateBufferSubData"));
	assert(glInvalidateBufferSubData_ != nullptr);
	return glInvalidateBufferSubData_(buffer, offset, length);
}
void glInvalidateBufferData(GLuint buffer) {
	static const auto glInvalidateBufferData_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint)>(getProcAddress("glInvalidateBufferData"));
	assert(glInvalidateBufferData_ != nullptr);
	return glInvalidateBufferData_(buffer);
}
void glInvalidateFramebuffer(GLenum target, GLsizei numAttachments, GLenum const  * attachments) {
	static const auto glInvalidateFramebuffer_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, GLenum const  *)>(getProcAddress("glInvalidateFramebuffer"));
	assert(glInvalidateFramebuffer_ != nullptr);
	return glInvalidateFramebuffer_(target, numAttachments, attachments);
}
void glInvalidateSubFramebuffer(GLenum target, GLsizei numAttachments, GLenum const  * attachments, GLint x, GLint y, GLsizei width, GLsizei height) {
	static const auto glInvalidateSubFramebuffer_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, GLenum const  *, GLint, GLint, GLsizei, GLsizei)>(getProcAddress("glInvalidateSubFramebuffer"));
	assert(glInvalidateSubFramebuffer_ != nullptr);
	return glInvalidateSubFramebuffer_(target, numAttachments, attachments, x, y, width, height);
}
void glCurrentPaletteMatrixARB(GLint index) {
	static const auto glCurrentPaletteMatrixARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint)>(getProcAddress("glCurrentPaletteMatrixARB"));
	assert(glCurrentPaletteMatrixARB_ != nullptr);
	return glCurrentPaletteMatrixARB_(index);
}
void glMatrixIndexubvARB(GLint size, GLubyte const  * indices) {
	static const auto glMatrixIndexubvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLubyte const  *)>(getProcAddress("glMatrixIndexubvARB"));
	assert(glMatrixIndexubvARB_ != nullptr);
	return glMatrixIndexubvARB_(size, indices);
}
void glMatrixIndexusvARB(GLint size, GLushort const  * indices) {
	static const auto glMatrixIndexusvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLushort const  *)>(getProcAddress("glMatrixIndexusvARB"));
	assert(glMatrixIndexusvARB_ != nullptr);
	return glMatrixIndexusvARB_(size, indices);
}
void glMatrixIndexuivARB(GLint size, GLuint const  * indices) {
	static const auto glMatrixIndexuivARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLuint const  *)>(getProcAddress("glMatrixIndexuivARB"));
	assert(glMatrixIndexuivARB_ != nullptr);
	return glMatrixIndexuivARB_(size, indices);
}
void glMatrixIndexPointerARB(GLint size, GLenum type, GLsizei stride, const void * pointer) {
	static const auto glMatrixIndexPointerARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLenum, GLsizei, const void *)>(getProcAddress("glMatrixIndexPointerARB"));
	assert(glMatrixIndexPointerARB_ != nullptr);
	return glMatrixIndexPointerARB_(size, type, stride, pointer);
}
void glBindBuffersBase(GLenum target, GLuint first, GLsizei count, GLuint const  * buffers) {
	static const auto glBindBuffersBase_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint, GLsizei, GLuint const  *)>(getProcAddress("glBindBuffersBase"));
	assert(glBindBuffersBase_ != nullptr);
	return glBindBuffersBase_(target, first, count, buffers);
}
void glBindBuffersRange(GLenum target, GLuint first, GLsizei count, GLuint const  * buffers, GLintptr const  * offsets, GLsizeiptr const  * sizes) {
	static const auto glBindBuffersRange_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint, GLsizei, GLuint const  *, GLintptr const  *, GLsizeiptr const  *)>(getProcAddress("glBindBuffersRange"));
	assert(glBindBuffersRange_ != nullptr);
	return glBindBuffersRange_(target, first, count, buffers, offsets, sizes);
}
void glBindTextures(GLuint first, GLsizei count, GLuint const  * textures) {
	static const auto glBindTextures_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLsizei, GLuint const  *)>(getProcAddress("glBindTextures"));
	assert(glBindTextures_ != nullptr);
	return glBindTextures_(first, count, textures);
}
void glBindSamplers(GLuint first, GLsizei count, GLuint const  * samplers) {
	static const auto glBindSamplers_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLsizei, GLuint const  *)>(getProcAddress("glBindSamplers"));
	assert(glBindSamplers_ != nullptr);
	return glBindSamplers_(first, count, samplers);
}
void glBindImageTextures(GLuint first, GLsizei count, GLuint const  * textures) {
	static const auto glBindImageTextures_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLsizei, GLuint const  *)>(getProcAddress("glBindImageTextures"));
	assert(glBindImageTextures_ != nullptr);
	return glBindImageTextures_(first, count, textures);
}
void glBindVertexBuffers(GLuint first, GLsizei count, GLuint const  * buffers, GLintptr const  * offsets, GLsizei const  * strides) {
	static const auto glBindVertexBuffers_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLsizei, GLuint const  *, GLintptr const  *, GLsizei const  *)>(getProcAddress("glBindVertexBuffers"));
	assert(glBindVertexBuffers_ != nullptr);
	return glBindVertexBuffers_(first, count, buffers, offsets, strides);
}
void glMultiDrawArraysIndirect(GLenum mode, const void * indirect, GLsizei drawcount, GLsizei stride) {
	static const auto glMultiDrawArraysIndirect_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, const void *, GLsizei, GLsizei)>(getProcAddress("glMultiDrawArraysIndirect"));
	assert(glMultiDrawArraysIndirect_ != nullptr);
	return glMultiDrawArraysIndirect_(mode, indirect, drawcount, stride);
}
void glMultiDrawElementsIndirect(GLenum mode, GLenum type, const void * indirect, GLsizei drawcount, GLsizei stride) {
	static const auto glMultiDrawElementsIndirect_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, const void *, GLsizei, GLsizei)>(getProcAddress("glMultiDrawElementsIndirect"));
	assert(glMultiDrawElementsIndirect_ != nullptr);
	return glMultiDrawElementsIndirect_(mode, type, indirect, drawcount, stride);
}
void glSampleCoverageARB(GLfloat value, GLboolean invert) {
	static const auto glSampleCoverageARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat, GLboolean)>(getProcAddress("glSampleCoverageARB"));
	assert(glSampleCoverageARB_ != nullptr);
	return glSampleCoverageARB_(value, invert);
}
void glActiveTextureARB(GLenum texture) {
	static const auto glActiveTextureARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glActiveTextureARB"));
	assert(glActiveTextureARB_ != nullptr);
	return glActiveTextureARB_(texture);
}
void glClientActiveTextureARB(GLenum texture) {
	static const auto glClientActiveTextureARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glClientActiveTextureARB"));
	assert(glClientActiveTextureARB_ != nullptr);
	return glClientActiveTextureARB_(texture);
}
void glMultiTexCoord1dARB(GLenum target, GLdouble s) {
	static const auto glMultiTexCoord1dARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLdouble)>(getProcAddress("glMultiTexCoord1dARB"));
	assert(glMultiTexCoord1dARB_ != nullptr);
	return glMultiTexCoord1dARB_(target, s);
}
void glMultiTexCoord1dvARB(GLenum target, GLdouble const  * v) {
	static const auto glMultiTexCoord1dvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLdouble const  *)>(getProcAddress("glMultiTexCoord1dvARB"));
	assert(glMultiTexCoord1dvARB_ != nullptr);
	return glMultiTexCoord1dvARB_(target, v);
}
void glMultiTexCoord1fARB(GLenum target, GLfloat s) {
	static const auto glMultiTexCoord1fARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfloat)>(getProcAddress("glMultiTexCoord1fARB"));
	assert(glMultiTexCoord1fARB_ != nullptr);
	return glMultiTexCoord1fARB_(target, s);
}
void glMultiTexCoord1fvARB(GLenum target, GLfloat const  * v) {
	static const auto glMultiTexCoord1fvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfloat const  *)>(getProcAddress("glMultiTexCoord1fvARB"));
	assert(glMultiTexCoord1fvARB_ != nullptr);
	return glMultiTexCoord1fvARB_(target, v);
}
void glMultiTexCoord1iARB(GLenum target, GLint s) {
	static const auto glMultiTexCoord1iARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint)>(getProcAddress("glMultiTexCoord1iARB"));
	assert(glMultiTexCoord1iARB_ != nullptr);
	return glMultiTexCoord1iARB_(target, s);
}
void glMultiTexCoord1ivARB(GLenum target, GLint const  * v) {
	static const auto glMultiTexCoord1ivARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint const  *)>(getProcAddress("glMultiTexCoord1ivARB"));
	assert(glMultiTexCoord1ivARB_ != nullptr);
	return glMultiTexCoord1ivARB_(target, v);
}
void glMultiTexCoord1sARB(GLenum target, GLshort s) {
	static const auto glMultiTexCoord1sARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLshort)>(getProcAddress("glMultiTexCoord1sARB"));
	assert(glMultiTexCoord1sARB_ != nullptr);
	return glMultiTexCoord1sARB_(target, s);
}
void glMultiTexCoord1svARB(GLenum target, GLshort const  * v) {
	static const auto glMultiTexCoord1svARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLshort const  *)>(getProcAddress("glMultiTexCoord1svARB"));
	assert(glMultiTexCoord1svARB_ != nullptr);
	return glMultiTexCoord1svARB_(target, v);
}
void glMultiTexCoord2dARB(GLenum target, GLdouble s, GLdouble t) {
	static const auto glMultiTexCoord2dARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLdouble, GLdouble)>(getProcAddress("glMultiTexCoord2dARB"));
	assert(glMultiTexCoord2dARB_ != nullptr);
	return glMultiTexCoord2dARB_(target, s, t);
}
void glMultiTexCoord2dvARB(GLenum target, GLdouble const  * v) {
	static const auto glMultiTexCoord2dvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLdouble const  *)>(getProcAddress("glMultiTexCoord2dvARB"));
	assert(glMultiTexCoord2dvARB_ != nullptr);
	return glMultiTexCoord2dvARB_(target, v);
}
void glMultiTexCoord2fARB(GLenum target, GLfloat s, GLfloat t) {
	static const auto glMultiTexCoord2fARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfloat, GLfloat)>(getProcAddress("glMultiTexCoord2fARB"));
	assert(glMultiTexCoord2fARB_ != nullptr);
	return glMultiTexCoord2fARB_(target, s, t);
}
void glMultiTexCoord2fvARB(GLenum target, GLfloat const  * v) {
	static const auto glMultiTexCoord2fvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfloat const  *)>(getProcAddress("glMultiTexCoord2fvARB"));
	assert(glMultiTexCoord2fvARB_ != nullptr);
	return glMultiTexCoord2fvARB_(target, v);
}
void glMultiTexCoord2iARB(GLenum target, GLint s, GLint t) {
	static const auto glMultiTexCoord2iARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLint)>(getProcAddress("glMultiTexCoord2iARB"));
	assert(glMultiTexCoord2iARB_ != nullptr);
	return glMultiTexCoord2iARB_(target, s, t);
}
void glMultiTexCoord2ivARB(GLenum target, GLint const  * v) {
	static const auto glMultiTexCoord2ivARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint const  *)>(getProcAddress("glMultiTexCoord2ivARB"));
	assert(glMultiTexCoord2ivARB_ != nullptr);
	return glMultiTexCoord2ivARB_(target, v);
}
void glMultiTexCoord2sARB(GLenum target, GLshort s, GLshort t) {
	static const auto glMultiTexCoord2sARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLshort, GLshort)>(getProcAddress("glMultiTexCoord2sARB"));
	assert(glMultiTexCoord2sARB_ != nullptr);
	return glMultiTexCoord2sARB_(target, s, t);
}
void glMultiTexCoord2svARB(GLenum target, GLshort const  * v) {
	static const auto glMultiTexCoord2svARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLshort const  *)>(getProcAddress("glMultiTexCoord2svARB"));
	assert(glMultiTexCoord2svARB_ != nullptr);
	return glMultiTexCoord2svARB_(target, v);
}
void glMultiTexCoord3dARB(GLenum target, GLdouble s, GLdouble t, GLdouble r) {
	static const auto glMultiTexCoord3dARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLdouble, GLdouble, GLdouble)>(getProcAddress("glMultiTexCoord3dARB"));
	assert(glMultiTexCoord3dARB_ != nullptr);
	return glMultiTexCoord3dARB_(target, s, t, r);
}
void glMultiTexCoord3dvARB(GLenum target, GLdouble const  * v) {
	static const auto glMultiTexCoord3dvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLdouble const  *)>(getProcAddress("glMultiTexCoord3dvARB"));
	assert(glMultiTexCoord3dvARB_ != nullptr);
	return glMultiTexCoord3dvARB_(target, v);
}
void glMultiTexCoord3fARB(GLenum target, GLfloat s, GLfloat t, GLfloat r) {
	static const auto glMultiTexCoord3fARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfloat, GLfloat, GLfloat)>(getProcAddress("glMultiTexCoord3fARB"));
	assert(glMultiTexCoord3fARB_ != nullptr);
	return glMultiTexCoord3fARB_(target, s, t, r);
}
void glMultiTexCoord3fvARB(GLenum target, GLfloat const  * v) {
	static const auto glMultiTexCoord3fvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfloat const  *)>(getProcAddress("glMultiTexCoord3fvARB"));
	assert(glMultiTexCoord3fvARB_ != nullptr);
	return glMultiTexCoord3fvARB_(target, v);
}
void glMultiTexCoord3iARB(GLenum target, GLint s, GLint t, GLint r) {
	static const auto glMultiTexCoord3iARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLint, GLint)>(getProcAddress("glMultiTexCoord3iARB"));
	assert(glMultiTexCoord3iARB_ != nullptr);
	return glMultiTexCoord3iARB_(target, s, t, r);
}
void glMultiTexCoord3ivARB(GLenum target, GLint const  * v) {
	static const auto glMultiTexCoord3ivARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint const  *)>(getProcAddress("glMultiTexCoord3ivARB"));
	assert(glMultiTexCoord3ivARB_ != nullptr);
	return glMultiTexCoord3ivARB_(target, v);
}
void glMultiTexCoord3sARB(GLenum target, GLshort s, GLshort t, GLshort r) {
	static const auto glMultiTexCoord3sARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLshort, GLshort, GLshort)>(getProcAddress("glMultiTexCoord3sARB"));
	assert(glMultiTexCoord3sARB_ != nullptr);
	return glMultiTexCoord3sARB_(target, s, t, r);
}
void glMultiTexCoord3svARB(GLenum target, GLshort const  * v) {
	static const auto glMultiTexCoord3svARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLshort const  *)>(getProcAddress("glMultiTexCoord3svARB"));
	assert(glMultiTexCoord3svARB_ != nullptr);
	return glMultiTexCoord3svARB_(target, v);
}
void glMultiTexCoord4dARB(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q) {
	static const auto glMultiTexCoord4dARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLdouble, GLdouble, GLdouble, GLdouble)>(getProcAddress("glMultiTexCoord4dARB"));
	assert(glMultiTexCoord4dARB_ != nullptr);
	return glMultiTexCoord4dARB_(target, s, t, r, q);
}
void glMultiTexCoord4dvARB(GLenum target, GLdouble const  * v) {
	static const auto glMultiTexCoord4dvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLdouble const  *)>(getProcAddress("glMultiTexCoord4dvARB"));
	assert(glMultiTexCoord4dvARB_ != nullptr);
	return glMultiTexCoord4dvARB_(target, v);
}
void glMultiTexCoord4fARB(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) {
	static const auto glMultiTexCoord4fARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfloat, GLfloat, GLfloat, GLfloat)>(getProcAddress("glMultiTexCoord4fARB"));
	assert(glMultiTexCoord4fARB_ != nullptr);
	return glMultiTexCoord4fARB_(target, s, t, r, q);
}
void glMultiTexCoord4fvARB(GLenum target, GLfloat const  * v) {
	static const auto glMultiTexCoord4fvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfloat const  *)>(getProcAddress("glMultiTexCoord4fvARB"));
	assert(glMultiTexCoord4fvARB_ != nullptr);
	return glMultiTexCoord4fvARB_(target, v);
}
void glMultiTexCoord4iARB(GLenum target, GLint s, GLint t, GLint r, GLint q) {
	static const auto glMultiTexCoord4iARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLint, GLint, GLint)>(getProcAddress("glMultiTexCoord4iARB"));
	assert(glMultiTexCoord4iARB_ != nullptr);
	return glMultiTexCoord4iARB_(target, s, t, r, q);
}
void glMultiTexCoord4ivARB(GLenum target, GLint const  * v) {
	static const auto glMultiTexCoord4ivARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint const  *)>(getProcAddress("glMultiTexCoord4ivARB"));
	assert(glMultiTexCoord4ivARB_ != nullptr);
	return glMultiTexCoord4ivARB_(target, v);
}
void glMultiTexCoord4sARB(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q) {
	static const auto glMultiTexCoord4sARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLshort, GLshort, GLshort, GLshort)>(getProcAddress("glMultiTexCoord4sARB"));
	assert(glMultiTexCoord4sARB_ != nullptr);
	return glMultiTexCoord4sARB_(target, s, t, r, q);
}
void glMultiTexCoord4svARB(GLenum target, GLshort const  * v) {
	static const auto glMultiTexCoord4svARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLshort const  *)>(getProcAddress("glMultiTexCoord4svARB"));
	assert(glMultiTexCoord4svARB_ != nullptr);
	return glMultiTexCoord4svARB_(target, v);
}
void glGenQueriesARB(GLsizei n, GLuint * ids) {
	static const auto glGenQueriesARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint *)>(getProcAddress("glGenQueriesARB"));
	assert(glGenQueriesARB_ != nullptr);
	return glGenQueriesARB_(n, ids);
}
void glDeleteQueriesARB(GLsizei n, GLuint const  * ids) {
	static const auto glDeleteQueriesARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint const  *)>(getProcAddress("glDeleteQueriesARB"));
	assert(glDeleteQueriesARB_ != nullptr);
	return glDeleteQueriesARB_(n, ids);
}
GLboolean glIsQueryARB(GLuint id) {
	static const auto glIsQueryARB_ = reinterpret_cast<GLboolean(GL_APIENTRYP)(GLuint)>(getProcAddress("glIsQueryARB"));
	assert(glIsQueryARB_ != nullptr);
	return glIsQueryARB_(id);
}
void glBeginQueryARB(GLenum target, GLuint id) {
	static const auto glBeginQueryARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint)>(getProcAddress("glBeginQueryARB"));
	assert(glBeginQueryARB_ != nullptr);
	return glBeginQueryARB_(target, id);
}
void glEndQueryARB(GLenum target) {
	static const auto glEndQueryARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glEndQueryARB"));
	assert(glEndQueryARB_ != nullptr);
	return glEndQueryARB_(target);
}
void glGetQueryivARB(GLenum target, GLenum pname, GLint * params) {
	static const auto glGetQueryivARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint *)>(getProcAddress("glGetQueryivARB"));
	assert(glGetQueryivARB_ != nullptr);
	return glGetQueryivARB_(target, pname, params);
}
void glGetQueryObjectivARB(GLuint id, GLenum pname, GLint * params) {
	static const auto glGetQueryObjectivARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint *)>(getProcAddress("glGetQueryObjectivARB"));
	assert(glGetQueryObjectivARB_ != nullptr);
	return glGetQueryObjectivARB_(id, pname, params);
}
void glGetQueryObjectuivARB(GLuint id, GLenum pname, GLuint * params) {
	static const auto glGetQueryObjectuivARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLuint *)>(getProcAddress("glGetQueryObjectuivARB"));
	assert(glGetQueryObjectuivARB_ != nullptr);
	return glGetQueryObjectuivARB_(id, pname, params);
}
void glMaxShaderCompilerThreadsARB(GLuint count) {
	static const auto glMaxShaderCompilerThreadsARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint)>(getProcAddress("glMaxShaderCompilerThreadsARB"));
	assert(glMaxShaderCompilerThreadsARB_ != nullptr);
	return glMaxShaderCompilerThreadsARB_(count);
}
void glPointParameterfARB(GLenum pname, GLfloat param) {
	static const auto glPointParameterfARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfloat)>(getProcAddress("glPointParameterfARB"));
	assert(glPointParameterfARB_ != nullptr);
	return glPointParameterfARB_(pname, param);
}
void glPointParameterfvARB(GLenum pname, GLfloat const  * params) {
	static const auto glPointParameterfvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfloat const  *)>(getProcAddress("glPointParameterfvARB"));
	assert(glPointParameterfvARB_ != nullptr);
	return glPointParameterfvARB_(pname, params);
}
void glPolygonOffsetClamp(GLfloat factor, GLfloat units, GLfloat clamp) {
	static const auto glPolygonOffsetClamp_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat, GLfloat, GLfloat)>(getProcAddress("glPolygonOffsetClamp"));
	assert(glPolygonOffsetClamp_ != nullptr);
	return glPolygonOffsetClamp_(factor, units, clamp);
}
void glGetProgramInterfaceiv(GLuint program, GLenum programInterface, GLenum pname, GLint * params) {
	static const auto glGetProgramInterfaceiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLenum, GLint *)>(getProcAddress("glGetProgramInterfaceiv"));
	assert(glGetProgramInterfaceiv_ != nullptr);
	return glGetProgramInterfaceiv_(program, programInterface, pname, params);
}
GLuint glGetProgramResourceIndex(GLuint program, GLenum programInterface, GLchar const  * name) {
	static const auto glGetProgramResourceIndex_ = reinterpret_cast<GLuint(GL_APIENTRYP)(GLuint, GLenum, GLchar const  *)>(getProcAddress("glGetProgramResourceIndex"));
	assert(glGetProgramResourceIndex_ != nullptr);
	return glGetProgramResourceIndex_(program, programInterface, name);
}
void glGetProgramResourceName(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei * length, GLchar * name) {
	static const auto glGetProgramResourceName_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLuint, GLsizei, GLsizei *, GLchar *)>(getProcAddress("glGetProgramResourceName"));
	assert(glGetProgramResourceName_ != nullptr);
	return glGetProgramResourceName_(program, programInterface, index, bufSize, length, name);
}
void glGetProgramResourceiv(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, GLenum const  * props, GLsizei count, GLsizei * length, GLint * params) {
	static const auto glGetProgramResourceiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLuint, GLsizei, GLenum const  *, GLsizei, GLsizei *, GLint *)>(getProcAddress("glGetProgramResourceiv"));
	assert(glGetProgramResourceiv_ != nullptr);
	return glGetProgramResourceiv_(program, programInterface, index, propCount, props, count, length, params);
}
GLint glGetProgramResourceLocation(GLuint program, GLenum programInterface, GLchar const  * name) {
	static const auto glGetProgramResourceLocation_ = reinterpret_cast<GLint(GL_APIENTRYP)(GLuint, GLenum, GLchar const  *)>(getProcAddress("glGetProgramResourceLocation"));
	assert(glGetProgramResourceLocation_ != nullptr);
	return glGetProgramResourceLocation_(program, programInterface, name);
}
GLint glGetProgramResourceLocationIndex(GLuint program, GLenum programInterface, GLchar const  * name) {
	static const auto glGetProgramResourceLocationIndex_ = reinterpret_cast<GLint(GL_APIENTRYP)(GLuint, GLenum, GLchar const  *)>(getProcAddress("glGetProgramResourceLocationIndex"));
	assert(glGetProgramResourceLocationIndex_ != nullptr);
	return glGetProgramResourceLocationIndex_(program, programInterface, name);
}
void glProvokingVertex(GLenum mode) {
	static const auto glProvokingVertex_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glProvokingVertex"));
	assert(glProvokingVertex_ != nullptr);
	return glProvokingVertex_(mode);
}
GLenum glGetGraphicsResetStatusARB() {
	static const auto glGetGraphicsResetStatusARB_ = reinterpret_cast<GLenum(GL_APIENTRYP)()>(getProcAddress("glGetGraphicsResetStatusARB"));
	assert(glGetGraphicsResetStatusARB_ != nullptr);
	return glGetGraphicsResetStatusARB_();
}
void glGetnTexImageARB(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void * img) {
	static const auto glGetnTexImageARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLenum, GLenum, GLsizei, void *)>(getProcAddress("glGetnTexImageARB"));
	assert(glGetnTexImageARB_ != nullptr);
	return glGetnTexImageARB_(target, level, format, type, bufSize, img);
}
void glReadnPixelsARB(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void * data) {
	static const auto glReadnPixelsARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, GLsizei, void *)>(getProcAddress("glReadnPixelsARB"));
	assert(glReadnPixelsARB_ != nullptr);
	return glReadnPixelsARB_(x, y, width, height, format, type, bufSize, data);
}
void glGetnCompressedTexImageARB(GLenum target, GLint lod, GLsizei bufSize, void * img) {
	static const auto glGetnCompressedTexImageARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLsizei, void *)>(getProcAddress("glGetnCompressedTexImageARB"));
	assert(glGetnCompressedTexImageARB_ != nullptr);
	return glGetnCompressedTexImageARB_(target, lod, bufSize, img);
}
void glGetnUniformfvARB(GLuint program, GLint location, GLsizei bufSize, GLfloat * params) {
	static const auto glGetnUniformfvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLfloat *)>(getProcAddress("glGetnUniformfvARB"));
	assert(glGetnUniformfvARB_ != nullptr);
	return glGetnUniformfvARB_(program, location, bufSize, params);
}
void glGetnUniformivARB(GLuint program, GLint location, GLsizei bufSize, GLint * params) {
	static const auto glGetnUniformivARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLint *)>(getProcAddress("glGetnUniformivARB"));
	assert(glGetnUniformivARB_ != nullptr);
	return glGetnUniformivARB_(program, location, bufSize, params);
}
void glGetnUniformuivARB(GLuint program, GLint location, GLsizei bufSize, GLuint * params) {
	static const auto glGetnUniformuivARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLuint *)>(getProcAddress("glGetnUniformuivARB"));
	assert(glGetnUniformuivARB_ != nullptr);
	return glGetnUniformuivARB_(program, location, bufSize, params);
}
void glGetnUniformdvARB(GLuint program, GLint location, GLsizei bufSize, GLdouble * params) {
	static const auto glGetnUniformdvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLdouble *)>(getProcAddress("glGetnUniformdvARB"));
	assert(glGetnUniformdvARB_ != nullptr);
	return glGetnUniformdvARB_(program, location, bufSize, params);
}
void glGetnMapdvARB(GLenum target, GLenum query, GLsizei bufSize, GLdouble * v) {
	static const auto glGetnMapdvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLsizei, GLdouble *)>(getProcAddress("glGetnMapdvARB"));
	assert(glGetnMapdvARB_ != nullptr);
	return glGetnMapdvARB_(target, query, bufSize, v);
}
void glGetnMapfvARB(GLenum target, GLenum query, GLsizei bufSize, GLfloat * v) {
	static const auto glGetnMapfvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLsizei, GLfloat *)>(getProcAddress("glGetnMapfvARB"));
	assert(glGetnMapfvARB_ != nullptr);
	return glGetnMapfvARB_(target, query, bufSize, v);
}
void glGetnMapivARB(GLenum target, GLenum query, GLsizei bufSize, GLint * v) {
	static const auto glGetnMapivARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLsizei, GLint *)>(getProcAddress("glGetnMapivARB"));
	assert(glGetnMapivARB_ != nullptr);
	return glGetnMapivARB_(target, query, bufSize, v);
}
void glGetnPixelMapfvARB(GLenum map, GLsizei bufSize, GLfloat * values) {
	static const auto glGetnPixelMapfvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, GLfloat *)>(getProcAddress("glGetnPixelMapfvARB"));
	assert(glGetnPixelMapfvARB_ != nullptr);
	return glGetnPixelMapfvARB_(map, bufSize, values);
}
void glGetnPixelMapuivARB(GLenum map, GLsizei bufSize, GLuint * values) {
	static const auto glGetnPixelMapuivARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, GLuint *)>(getProcAddress("glGetnPixelMapuivARB"));
	assert(glGetnPixelMapuivARB_ != nullptr);
	return glGetnPixelMapuivARB_(map, bufSize, values);
}
void glGetnPixelMapusvARB(GLenum map, GLsizei bufSize, GLushort * values) {
	static const auto glGetnPixelMapusvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, GLushort *)>(getProcAddress("glGetnPixelMapusvARB"));
	assert(glGetnPixelMapusvARB_ != nullptr);
	return glGetnPixelMapusvARB_(map, bufSize, values);
}
void glGetnPolygonStippleARB(GLsizei bufSize, GLubyte * pattern) {
	static const auto glGetnPolygonStippleARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLubyte *)>(getProcAddress("glGetnPolygonStippleARB"));
	assert(glGetnPolygonStippleARB_ != nullptr);
	return glGetnPolygonStippleARB_(bufSize, pattern);
}
void glGetnColorTableARB(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void * table) {
	static const auto glGetnColorTableARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLsizei, void *)>(getProcAddress("glGetnColorTableARB"));
	assert(glGetnColorTableARB_ != nullptr);
	return glGetnColorTableARB_(target, format, type, bufSize, table);
}
void glGetnConvolutionFilterARB(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void * image) {
	static const auto glGetnConvolutionFilterARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLsizei, void *)>(getProcAddress("glGetnConvolutionFilterARB"));
	assert(glGetnConvolutionFilterARB_ != nullptr);
	return glGetnConvolutionFilterARB_(target, format, type, bufSize, image);
}
void glGetnSeparableFilterARB(GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, void * row, GLsizei columnBufSize, void * column, void * span) {
	static const auto glGetnSeparableFilterARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLsizei, void *, GLsizei, void *, void *)>(getProcAddress("glGetnSeparableFilterARB"));
	assert(glGetnSeparableFilterARB_ != nullptr);
	return glGetnSeparableFilterARB_(target, format, type, rowBufSize, row, columnBufSize, column, span);
}
void glGetnHistogramARB(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void * values) {
	static const auto glGetnHistogramARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLboolean, GLenum, GLenum, GLsizei, void *)>(getProcAddress("glGetnHistogramARB"));
	assert(glGetnHistogramARB_ != nullptr);
	return glGetnHistogramARB_(target, reset, format, type, bufSize, values);
}
void glGetnMinmaxARB(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void * values) {
	static const auto glGetnMinmaxARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLboolean, GLenum, GLenum, GLsizei, void *)>(getProcAddress("glGetnMinmaxARB"));
	assert(glGetnMinmaxARB_ != nullptr);
	return glGetnMinmaxARB_(target, reset, format, type, bufSize, values);
}
void glFramebufferSampleLocationsfvARB(GLenum target, GLuint start, GLsizei count, GLfloat const  * v) {
	static const auto glFramebufferSampleLocationsfvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint, GLsizei, GLfloat const  *)>(getProcAddress("glFramebufferSampleLocationsfvARB"));
	assert(glFramebufferSampleLocationsfvARB_ != nullptr);
	return glFramebufferSampleLocationsfvARB_(target, start, count, v);
}
void glNamedFramebufferSampleLocationsfvARB(GLuint framebuffer, GLuint start, GLsizei count, GLfloat const  * v) {
	static const auto glNamedFramebufferSampleLocationsfvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLsizei, GLfloat const  *)>(getProcAddress("glNamedFramebufferSampleLocationsfvARB"));
	assert(glNamedFramebufferSampleLocationsfvARB_ != nullptr);
	return glNamedFramebufferSampleLocationsfvARB_(framebuffer, start, count, v);
}
void glEvaluateDepthValuesARB() {
	static const auto glEvaluateDepthValuesARB_ = reinterpret_cast<void(GL_APIENTRYP)()>(getProcAddress("glEvaluateDepthValuesARB"));
	assert(glEvaluateDepthValuesARB_ != nullptr);
	return glEvaluateDepthValuesARB_();
}
void glMinSampleShadingARB(GLfloat value) {
	static const auto glMinSampleShadingARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat)>(getProcAddress("glMinSampleShadingARB"));
	assert(glMinSampleShadingARB_ != nullptr);
	return glMinSampleShadingARB_(value);
}
void glGenSamplers(GLsizei count, GLuint * samplers) {
	static const auto glGenSamplers_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint *)>(getProcAddress("glGenSamplers"));
	assert(glGenSamplers_ != nullptr);
	return glGenSamplers_(count, samplers);
}
void glDeleteSamplers(GLsizei count, GLuint const  * samplers) {
	static const auto glDeleteSamplers_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint const  *)>(getProcAddress("glDeleteSamplers"));
	assert(glDeleteSamplers_ != nullptr);
	return glDeleteSamplers_(count, samplers);
}
GLboolean glIsSampler(GLuint sampler) {
	static const auto glIsSampler_ = reinterpret_cast<GLboolean(GL_APIENTRYP)(GLuint)>(getProcAddress("glIsSampler"));
	assert(glIsSampler_ != nullptr);
	return glIsSampler_(sampler);
}
void glBindSampler(GLuint unit, GLuint sampler) {
	static const auto glBindSampler_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint)>(getProcAddress("glBindSampler"));
	assert(glBindSampler_ != nullptr);
	return glBindSampler_(unit, sampler);
}
void glSamplerParameteri(GLuint sampler, GLenum pname, GLint param) {
	static const auto glSamplerParameteri_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint)>(getProcAddress("glSamplerParameteri"));
	assert(glSamplerParameteri_ != nullptr);
	return glSamplerParameteri_(sampler, pname, param);
}
void glSamplerParameteriv(GLuint sampler, GLenum pname, GLint const  * param) {
	static const auto glSamplerParameteriv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint const  *)>(getProcAddress("glSamplerParameteriv"));
	assert(glSamplerParameteriv_ != nullptr);
	return glSamplerParameteriv_(sampler, pname, param);
}
void glSamplerParameterf(GLuint sampler, GLenum pname, GLfloat param) {
	static const auto glSamplerParameterf_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLfloat)>(getProcAddress("glSamplerParameterf"));
	assert(glSamplerParameterf_ != nullptr);
	return glSamplerParameterf_(sampler, pname, param);
}
void glSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat const  * param) {
	static const auto glSamplerParameterfv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLfloat const  *)>(getProcAddress("glSamplerParameterfv"));
	assert(glSamplerParameterfv_ != nullptr);
	return glSamplerParameterfv_(sampler, pname, param);
}
void glSamplerParameterIiv(GLuint sampler, GLenum pname, GLint const  * param) {
	static const auto glSamplerParameterIiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint const  *)>(getProcAddress("glSamplerParameterIiv"));
	assert(glSamplerParameterIiv_ != nullptr);
	return glSamplerParameterIiv_(sampler, pname, param);
}
void glSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint const  * param) {
	static const auto glSamplerParameterIuiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLuint const  *)>(getProcAddress("glSamplerParameterIuiv"));
	assert(glSamplerParameterIuiv_ != nullptr);
	return glSamplerParameterIuiv_(sampler, pname, param);
}
void glGetSamplerParameteriv(GLuint sampler, GLenum pname, GLint * params) {
	static const auto glGetSamplerParameteriv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint *)>(getProcAddress("glGetSamplerParameteriv"));
	assert(glGetSamplerParameteriv_ != nullptr);
	return glGetSamplerParameteriv_(sampler, pname, params);
}
void glGetSamplerParameterIiv(GLuint sampler, GLenum pname, GLint * params) {
	static const auto glGetSamplerParameterIiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint *)>(getProcAddress("glGetSamplerParameterIiv"));
	assert(glGetSamplerParameterIiv_ != nullptr);
	return glGetSamplerParameterIiv_(sampler, pname, params);
}
void glGetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat * params) {
	static const auto glGetSamplerParameterfv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLfloat *)>(getProcAddress("glGetSamplerParameterfv"));
	assert(glGetSamplerParameterfv_ != nullptr);
	return glGetSamplerParameterfv_(sampler, pname, params);
}
void glGetSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint * params) {
	static const auto glGetSamplerParameterIuiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLuint *)>(getProcAddress("glGetSamplerParameterIuiv"));
	assert(glGetSamplerParameterIuiv_ != nullptr);
	return glGetSamplerParameterIuiv_(sampler, pname, params);
}
void glUseProgramStages(GLuint pipeline, GLbitfield stages, GLuint program) {
	static const auto glUseProgramStages_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLbitfield, GLuint)>(getProcAddress("glUseProgramStages"));
	assert(glUseProgramStages_ != nullptr);
	return glUseProgramStages_(pipeline, stages, program);
}
void glActiveShaderProgram(GLuint pipeline, GLuint program) {
	static const auto glActiveShaderProgram_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint)>(getProcAddress("glActiveShaderProgram"));
	assert(glActiveShaderProgram_ != nullptr);
	return glActiveShaderProgram_(pipeline, program);
}
GLuint glCreateShaderProgramv(GLenum type, GLsizei count, GLchar const  *const* strings) {
	static const auto glCreateShaderProgramv_ = reinterpret_cast<GLuint(GL_APIENTRYP)(GLenum, GLsizei, GLchar const  *const*)>(getProcAddress("glCreateShaderProgramv"));
	assert(glCreateShaderProgramv_ != nullptr);
	return glCreateShaderProgramv_(type, count, strings);
}
void glBindProgramPipeline(GLuint pipeline) {
	static const auto glBindProgramPipeline_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint)>(getProcAddress("glBindProgramPipeline"));
	assert(glBindProgramPipeline_ != nullptr);
	return glBindProgramPipeline_(pipeline);
}
void glDeleteProgramPipelines(GLsizei n, GLuint const  * pipelines) {
	static const auto glDeleteProgramPipelines_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint const  *)>(getProcAddress("glDeleteProgramPipelines"));
	assert(glDeleteProgramPipelines_ != nullptr);
	return glDeleteProgramPipelines_(n, pipelines);
}
void glGenProgramPipelines(GLsizei n, GLuint * pipelines) {
	static const auto glGenProgramPipelines_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint *)>(getProcAddress("glGenProgramPipelines"));
	assert(glGenProgramPipelines_ != nullptr);
	return glGenProgramPipelines_(n, pipelines);
}
GLboolean glIsProgramPipeline(GLuint pipeline) {
	static const auto glIsProgramPipeline_ = reinterpret_cast<GLboolean(GL_APIENTRYP)(GLuint)>(getProcAddress("glIsProgramPipeline"));
	assert(glIsProgramPipeline_ != nullptr);
	return glIsProgramPipeline_(pipeline);
}
void glGetProgramPipelineiv(GLuint pipeline, GLenum pname, GLint * params) {
	static const auto glGetProgramPipelineiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint *)>(getProcAddress("glGetProgramPipelineiv"));
	assert(glGetProgramPipelineiv_ != nullptr);
	return glGetProgramPipelineiv_(pipeline, pname, params);
}
void glProgramUniform1i(GLuint program, GLint location, GLint v0) {
	static const auto glProgramUniform1i_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLint)>(getProcAddress("glProgramUniform1i"));
	assert(glProgramUniform1i_ != nullptr);
	return glProgramUniform1i_(program, location, v0);
}
void glProgramUniform1iv(GLuint program, GLint location, GLsizei count, GLint const  * value) {
	static const auto glProgramUniform1iv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLint const  *)>(getProcAddress("glProgramUniform1iv"));
	assert(glProgramUniform1iv_ != nullptr);
	return glProgramUniform1iv_(program, location, count, value);
}
void glProgramUniform1f(GLuint program, GLint location, GLfloat v0) {
	static const auto glProgramUniform1f_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLfloat)>(getProcAddress("glProgramUniform1f"));
	assert(glProgramUniform1f_ != nullptr);
	return glProgramUniform1f_(program, location, v0);
}
void glProgramUniform1fv(GLuint program, GLint location, GLsizei count, GLfloat const  * value) {
	static const auto glProgramUniform1fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLfloat const  *)>(getProcAddress("glProgramUniform1fv"));
	assert(glProgramUniform1fv_ != nullptr);
	return glProgramUniform1fv_(program, location, count, value);
}
void glProgramUniform1d(GLuint program, GLint location, GLdouble v0) {
	static const auto glProgramUniform1d_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLdouble)>(getProcAddress("glProgramUniform1d"));
	assert(glProgramUniform1d_ != nullptr);
	return glProgramUniform1d_(program, location, v0);
}
void glProgramUniform1dv(GLuint program, GLint location, GLsizei count, GLdouble const  * value) {
	static const auto glProgramUniform1dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLdouble const  *)>(getProcAddress("glProgramUniform1dv"));
	assert(glProgramUniform1dv_ != nullptr);
	return glProgramUniform1dv_(program, location, count, value);
}
void glProgramUniform1ui(GLuint program, GLint location, GLuint v0) {
	static const auto glProgramUniform1ui_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLuint)>(getProcAddress("glProgramUniform1ui"));
	assert(glProgramUniform1ui_ != nullptr);
	return glProgramUniform1ui_(program, location, v0);
}
void glProgramUniform1uiv(GLuint program, GLint location, GLsizei count, GLuint const  * value) {
	static const auto glProgramUniform1uiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLuint const  *)>(getProcAddress("glProgramUniform1uiv"));
	assert(glProgramUniform1uiv_ != nullptr);
	return glProgramUniform1uiv_(program, location, count, value);
}
void glProgramUniform2i(GLuint program, GLint location, GLint v0, GLint v1) {
	static const auto glProgramUniform2i_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLint, GLint)>(getProcAddress("glProgramUniform2i"));
	assert(glProgramUniform2i_ != nullptr);
	return glProgramUniform2i_(program, location, v0, v1);
}
void glProgramUniform2iv(GLuint program, GLint location, GLsizei count, GLint const  * value) {
	static const auto glProgramUniform2iv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLint const  *)>(getProcAddress("glProgramUniform2iv"));
	assert(glProgramUniform2iv_ != nullptr);
	return glProgramUniform2iv_(program, location, count, value);
}
void glProgramUniform2f(GLuint program, GLint location, GLfloat v0, GLfloat v1) {
	static const auto glProgramUniform2f_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLfloat, GLfloat)>(getProcAddress("glProgramUniform2f"));
	assert(glProgramUniform2f_ != nullptr);
	return glProgramUniform2f_(program, location, v0, v1);
}
void glProgramUniform2fv(GLuint program, GLint location, GLsizei count, GLfloat const  * value) {
	static const auto glProgramUniform2fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLfloat const  *)>(getProcAddress("glProgramUniform2fv"));
	assert(glProgramUniform2fv_ != nullptr);
	return glProgramUniform2fv_(program, location, count, value);
}
void glProgramUniform2d(GLuint program, GLint location, GLdouble v0, GLdouble v1) {
	static const auto glProgramUniform2d_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLdouble, GLdouble)>(getProcAddress("glProgramUniform2d"));
	assert(glProgramUniform2d_ != nullptr);
	return glProgramUniform2d_(program, location, v0, v1);
}
void glProgramUniform2dv(GLuint program, GLint location, GLsizei count, GLdouble const  * value) {
	static const auto glProgramUniform2dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLdouble const  *)>(getProcAddress("glProgramUniform2dv"));
	assert(glProgramUniform2dv_ != nullptr);
	return glProgramUniform2dv_(program, location, count, value);
}
void glProgramUniform2ui(GLuint program, GLint location, GLuint v0, GLuint v1) {
	static const auto glProgramUniform2ui_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLuint, GLuint)>(getProcAddress("glProgramUniform2ui"));
	assert(glProgramUniform2ui_ != nullptr);
	return glProgramUniform2ui_(program, location, v0, v1);
}
void glProgramUniform2uiv(GLuint program, GLint location, GLsizei count, GLuint const  * value) {
	static const auto glProgramUniform2uiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLuint const  *)>(getProcAddress("glProgramUniform2uiv"));
	assert(glProgramUniform2uiv_ != nullptr);
	return glProgramUniform2uiv_(program, location, count, value);
}
void glProgramUniform3i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2) {
	static const auto glProgramUniform3i_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLint, GLint, GLint)>(getProcAddress("glProgramUniform3i"));
	assert(glProgramUniform3i_ != nullptr);
	return glProgramUniform3i_(program, location, v0, v1, v2);
}
void glProgramUniform3iv(GLuint program, GLint location, GLsizei count, GLint const  * value) {
	static const auto glProgramUniform3iv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLint const  *)>(getProcAddress("glProgramUniform3iv"));
	assert(glProgramUniform3iv_ != nullptr);
	return glProgramUniform3iv_(program, location, count, value);
}
void glProgramUniform3f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2) {
	static const auto glProgramUniform3f_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLfloat, GLfloat, GLfloat)>(getProcAddress("glProgramUniform3f"));
	assert(glProgramUniform3f_ != nullptr);
	return glProgramUniform3f_(program, location, v0, v1, v2);
}
void glProgramUniform3fv(GLuint program, GLint location, GLsizei count, GLfloat const  * value) {
	static const auto glProgramUniform3fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLfloat const  *)>(getProcAddress("glProgramUniform3fv"));
	assert(glProgramUniform3fv_ != nullptr);
	return glProgramUniform3fv_(program, location, count, value);
}
void glProgramUniform3d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2) {
	static const auto glProgramUniform3d_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLdouble, GLdouble, GLdouble)>(getProcAddress("glProgramUniform3d"));
	assert(glProgramUniform3d_ != nullptr);
	return glProgramUniform3d_(program, location, v0, v1, v2);
}
void glProgramUniform3dv(GLuint program, GLint location, GLsizei count, GLdouble const  * value) {
	static const auto glProgramUniform3dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLdouble const  *)>(getProcAddress("glProgramUniform3dv"));
	assert(glProgramUniform3dv_ != nullptr);
	return glProgramUniform3dv_(program, location, count, value);
}
void glProgramUniform3ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2) {
	static const auto glProgramUniform3ui_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLuint, GLuint, GLuint)>(getProcAddress("glProgramUniform3ui"));
	assert(glProgramUniform3ui_ != nullptr);
	return glProgramUniform3ui_(program, location, v0, v1, v2);
}
void glProgramUniform3uiv(GLuint program, GLint location, GLsizei count, GLuint const  * value) {
	static const auto glProgramUniform3uiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLuint const  *)>(getProcAddress("glProgramUniform3uiv"));
	assert(glProgramUniform3uiv_ != nullptr);
	return glProgramUniform3uiv_(program, location, count, value);
}
void glProgramUniform4i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3) {
	static const auto glProgramUniform4i_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLint, GLint, GLint, GLint)>(getProcAddress("glProgramUniform4i"));
	assert(glProgramUniform4i_ != nullptr);
	return glProgramUniform4i_(program, location, v0, v1, v2, v3);
}
void glProgramUniform4iv(GLuint program, GLint location, GLsizei count, GLint const  * value) {
	static const auto glProgramUniform4iv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLint const  *)>(getProcAddress("glProgramUniform4iv"));
	assert(glProgramUniform4iv_ != nullptr);
	return glProgramUniform4iv_(program, location, count, value);
}
void glProgramUniform4f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {
	static const auto glProgramUniform4f_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLfloat, GLfloat, GLfloat, GLfloat)>(getProcAddress("glProgramUniform4f"));
	assert(glProgramUniform4f_ != nullptr);
	return glProgramUniform4f_(program, location, v0, v1, v2, v3);
}
void glProgramUniform4fv(GLuint program, GLint location, GLsizei count, GLfloat const  * value) {
	static const auto glProgramUniform4fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLfloat const  *)>(getProcAddress("glProgramUniform4fv"));
	assert(glProgramUniform4fv_ != nullptr);
	return glProgramUniform4fv_(program, location, count, value);
}
void glProgramUniform4d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3) {
	static const auto glProgramUniform4d_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLdouble, GLdouble, GLdouble, GLdouble)>(getProcAddress("glProgramUniform4d"));
	assert(glProgramUniform4d_ != nullptr);
	return glProgramUniform4d_(program, location, v0, v1, v2, v3);
}
void glProgramUniform4dv(GLuint program, GLint location, GLsizei count, GLdouble const  * value) {
	static const auto glProgramUniform4dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLdouble const  *)>(getProcAddress("glProgramUniform4dv"));
	assert(glProgramUniform4dv_ != nullptr);
	return glProgramUniform4dv_(program, location, count, value);
}
void glProgramUniform4ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) {
	static const auto glProgramUniform4ui_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLuint, GLuint, GLuint, GLuint)>(getProcAddress("glProgramUniform4ui"));
	assert(glProgramUniform4ui_ != nullptr);
	return glProgramUniform4ui_(program, location, v0, v1, v2, v3);
}
void glProgramUniform4uiv(GLuint program, GLint location, GLsizei count, GLuint const  * value) {
	static const auto glProgramUniform4uiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLuint const  *)>(getProcAddress("glProgramUniform4uiv"));
	assert(glProgramUniform4uiv_ != nullptr);
	return glProgramUniform4uiv_(program, location, count, value);
}
void glProgramUniformMatrix2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value) {
	static const auto glProgramUniformMatrix2fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLboolean, GLfloat const  *)>(getProcAddress("glProgramUniformMatrix2fv"));
	assert(glProgramUniformMatrix2fv_ != nullptr);
	return glProgramUniformMatrix2fv_(program, location, count, transpose, value);
}
void glProgramUniformMatrix3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value) {
	static const auto glProgramUniformMatrix3fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLboolean, GLfloat const  *)>(getProcAddress("glProgramUniformMatrix3fv"));
	assert(glProgramUniformMatrix3fv_ != nullptr);
	return glProgramUniformMatrix3fv_(program, location, count, transpose, value);
}
void glProgramUniformMatrix4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value) {
	static const auto glProgramUniformMatrix4fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLboolean, GLfloat const  *)>(getProcAddress("glProgramUniformMatrix4fv"));
	assert(glProgramUniformMatrix4fv_ != nullptr);
	return glProgramUniformMatrix4fv_(program, location, count, transpose, value);
}
void glProgramUniformMatrix2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble const  * value) {
	static const auto glProgramUniformMatrix2dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLboolean, GLdouble const  *)>(getProcAddress("glProgramUniformMatrix2dv"));
	assert(glProgramUniformMatrix2dv_ != nullptr);
	return glProgramUniformMatrix2dv_(program, location, count, transpose, value);
}
void glProgramUniformMatrix3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble const  * value) {
	static const auto glProgramUniformMatrix3dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLboolean, GLdouble const  *)>(getProcAddress("glProgramUniformMatrix3dv"));
	assert(glProgramUniformMatrix3dv_ != nullptr);
	return glProgramUniformMatrix3dv_(program, location, count, transpose, value);
}
void glProgramUniformMatrix4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble const  * value) {
	static const auto glProgramUniformMatrix4dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLboolean, GLdouble const  *)>(getProcAddress("glProgramUniformMatrix4dv"));
	assert(glProgramUniformMatrix4dv_ != nullptr);
	return glProgramUniformMatrix4dv_(program, location, count, transpose, value);
}
void glProgramUniformMatrix2x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value) {
	static const auto glProgramUniformMatrix2x3fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLboolean, GLfloat const  *)>(getProcAddress("glProgramUniformMatrix2x3fv"));
	assert(glProgramUniformMatrix2x3fv_ != nullptr);
	return glProgramUniformMatrix2x3fv_(program, location, count, transpose, value);
}
void glProgramUniformMatrix3x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value) {
	static const auto glProgramUniformMatrix3x2fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLboolean, GLfloat const  *)>(getProcAddress("glProgramUniformMatrix3x2fv"));
	assert(glProgramUniformMatrix3x2fv_ != nullptr);
	return glProgramUniformMatrix3x2fv_(program, location, count, transpose, value);
}
void glProgramUniformMatrix2x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value) {
	static const auto glProgramUniformMatrix2x4fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLboolean, GLfloat const  *)>(getProcAddress("glProgramUniformMatrix2x4fv"));
	assert(glProgramUniformMatrix2x4fv_ != nullptr);
	return glProgramUniformMatrix2x4fv_(program, location, count, transpose, value);
}
void glProgramUniformMatrix4x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value) {
	static const auto glProgramUniformMatrix4x2fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLboolean, GLfloat const  *)>(getProcAddress("glProgramUniformMatrix4x2fv"));
	assert(glProgramUniformMatrix4x2fv_ != nullptr);
	return glProgramUniformMatrix4x2fv_(program, location, count, transpose, value);
}
void glProgramUniformMatrix3x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value) {
	static const auto glProgramUniformMatrix3x4fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLboolean, GLfloat const  *)>(getProcAddress("glProgramUniformMatrix3x4fv"));
	assert(glProgramUniformMatrix3x4fv_ != nullptr);
	return glProgramUniformMatrix3x4fv_(program, location, count, transpose, value);
}
void glProgramUniformMatrix4x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value) {
	static const auto glProgramUniformMatrix4x3fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLboolean, GLfloat const  *)>(getProcAddress("glProgramUniformMatrix4x3fv"));
	assert(glProgramUniformMatrix4x3fv_ != nullptr);
	return glProgramUniformMatrix4x3fv_(program, location, count, transpose, value);
}
void glProgramUniformMatrix2x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble const  * value) {
	static const auto glProgramUniformMatrix2x3dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLboolean, GLdouble const  *)>(getProcAddress("glProgramUniformMatrix2x3dv"));
	assert(glProgramUniformMatrix2x3dv_ != nullptr);
	return glProgramUniformMatrix2x3dv_(program, location, count, transpose, value);
}
void glProgramUniformMatrix3x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble const  * value) {
	static const auto glProgramUniformMatrix3x2dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLboolean, GLdouble const  *)>(getProcAddress("glProgramUniformMatrix3x2dv"));
	assert(glProgramUniformMatrix3x2dv_ != nullptr);
	return glProgramUniformMatrix3x2dv_(program, location, count, transpose, value);
}
void glProgramUniformMatrix2x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble const  * value) {
	static const auto glProgramUniformMatrix2x4dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLboolean, GLdouble const  *)>(getProcAddress("glProgramUniformMatrix2x4dv"));
	assert(glProgramUniformMatrix2x4dv_ != nullptr);
	return glProgramUniformMatrix2x4dv_(program, location, count, transpose, value);
}
void glProgramUniformMatrix4x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble const  * value) {
	static const auto glProgramUniformMatrix4x2dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLboolean, GLdouble const  *)>(getProcAddress("glProgramUniformMatrix4x2dv"));
	assert(glProgramUniformMatrix4x2dv_ != nullptr);
	return glProgramUniformMatrix4x2dv_(program, location, count, transpose, value);
}
void glProgramUniformMatrix3x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble const  * value) {
	static const auto glProgramUniformMatrix3x4dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLboolean, GLdouble const  *)>(getProcAddress("glProgramUniformMatrix3x4dv"));
	assert(glProgramUniformMatrix3x4dv_ != nullptr);
	return glProgramUniformMatrix3x4dv_(program, location, count, transpose, value);
}
void glProgramUniformMatrix4x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble const  * value) {
	static const auto glProgramUniformMatrix4x3dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLboolean, GLdouble const  *)>(getProcAddress("glProgramUniformMatrix4x3dv"));
	assert(glProgramUniformMatrix4x3dv_ != nullptr);
	return glProgramUniformMatrix4x3dv_(program, location, count, transpose, value);
}
void glValidateProgramPipeline(GLuint pipeline) {
	static const auto glValidateProgramPipeline_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint)>(getProcAddress("glValidateProgramPipeline"));
	assert(glValidateProgramPipeline_ != nullptr);
	return glValidateProgramPipeline_(pipeline);
}
void glGetProgramPipelineInfoLog(GLuint pipeline, GLsizei bufSize, GLsizei * length, GLchar * infoLog) {
	static const auto glGetProgramPipelineInfoLog_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLsizei, GLsizei *, GLchar *)>(getProcAddress("glGetProgramPipelineInfoLog"));
	assert(glGetProgramPipelineInfoLog_ != nullptr);
	return glGetProgramPipelineInfoLog_(pipeline, bufSize, length, infoLog);
}
void glGetActiveAtomicCounterBufferiv(GLuint program, GLuint bufferIndex, GLenum pname, GLint * params) {
	static const auto glGetActiveAtomicCounterBufferiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLenum, GLint *)>(getProcAddress("glGetActiveAtomicCounterBufferiv"));
	assert(glGetActiveAtomicCounterBufferiv_ != nullptr);
	return glGetActiveAtomicCounterBufferiv_(program, bufferIndex, pname, params);
}
void glBindImageTexture(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format) {
	static const auto glBindImageTexture_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLint, GLboolean, GLint, GLenum, GLenum)>(getProcAddress("glBindImageTexture"));
	assert(glBindImageTexture_ != nullptr);
	return glBindImageTexture_(unit, texture, level, layered, layer, access, format);
}
void glMemoryBarrier(GLbitfield barriers) {
	static const auto glMemoryBarrier_ = reinterpret_cast<void(GL_APIENTRYP)(GLbitfield)>(getProcAddress("glMemoryBarrier"));
	assert(glMemoryBarrier_ != nullptr);
	return glMemoryBarrier_(barriers);
}
void glDeleteObjectARB(GLhandleARB obj) {
	static const auto glDeleteObjectARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLhandleARB)>(getProcAddress("glDeleteObjectARB"));
	assert(glDeleteObjectARB_ != nullptr);
	return glDeleteObjectARB_(obj);
}
GLhandleARB glGetHandleARB(GLenum pname) {
	static const auto glGetHandleARB_ = reinterpret_cast<GLhandleARB(GL_APIENTRYP)(GLenum)>(getProcAddress("glGetHandleARB"));
	assert(glGetHandleARB_ != nullptr);
	return glGetHandleARB_(pname);
}
void glDetachObjectARB(GLhandleARB containerObj, GLhandleARB attachedObj) {
	static const auto glDetachObjectARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLhandleARB, GLhandleARB)>(getProcAddress("glDetachObjectARB"));
	assert(glDetachObjectARB_ != nullptr);
	return glDetachObjectARB_(containerObj, attachedObj);
}
GLhandleARB glCreateShaderObjectARB(GLenum shaderType) {
	static const auto glCreateShaderObjectARB_ = reinterpret_cast<GLhandleARB(GL_APIENTRYP)(GLenum)>(getProcAddress("glCreateShaderObjectARB"));
	assert(glCreateShaderObjectARB_ != nullptr);
	return glCreateShaderObjectARB_(shaderType);
}
void glShaderSourceARB(GLhandleARB shaderObj, GLsizei count, GLcharARB const  ** string, GLint const  * length) {
	static const auto glShaderSourceARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLhandleARB, GLsizei, GLcharARB const  **, GLint const  *)>(getProcAddress("glShaderSourceARB"));
	assert(glShaderSourceARB_ != nullptr);
	return glShaderSourceARB_(shaderObj, count, string, length);
}
void glCompileShaderARB(GLhandleARB shaderObj) {
	static const auto glCompileShaderARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLhandleARB)>(getProcAddress("glCompileShaderARB"));
	assert(glCompileShaderARB_ != nullptr);
	return glCompileShaderARB_(shaderObj);
}
GLhandleARB glCreateProgramObjectARB() {
	static const auto glCreateProgramObjectARB_ = reinterpret_cast<GLhandleARB(GL_APIENTRYP)()>(getProcAddress("glCreateProgramObjectARB"));
	assert(glCreateProgramObjectARB_ != nullptr);
	return glCreateProgramObjectARB_();
}
void glAttachObjectARB(GLhandleARB containerObj, GLhandleARB obj) {
	static const auto glAttachObjectARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLhandleARB, GLhandleARB)>(getProcAddress("glAttachObjectARB"));
	assert(glAttachObjectARB_ != nullptr);
	return glAttachObjectARB_(containerObj, obj);
}
void glLinkProgramARB(GLhandleARB programObj) {
	static const auto glLinkProgramARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLhandleARB)>(getProcAddress("glLinkProgramARB"));
	assert(glLinkProgramARB_ != nullptr);
	return glLinkProgramARB_(programObj);
}
void glUseProgramObjectARB(GLhandleARB programObj) {
	static const auto glUseProgramObjectARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLhandleARB)>(getProcAddress("glUseProgramObjectARB"));
	assert(glUseProgramObjectARB_ != nullptr);
	return glUseProgramObjectARB_(programObj);
}
void glValidateProgramARB(GLhandleARB programObj) {
	static const auto glValidateProgramARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLhandleARB)>(getProcAddress("glValidateProgramARB"));
	assert(glValidateProgramARB_ != nullptr);
	return glValidateProgramARB_(programObj);
}
void glUniform1fARB(GLint location, GLfloat v0) {
	static const auto glUniform1fARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLfloat)>(getProcAddress("glUniform1fARB"));
	assert(glUniform1fARB_ != nullptr);
	return glUniform1fARB_(location, v0);
}
void glUniform2fARB(GLint location, GLfloat v0, GLfloat v1) {
	static const auto glUniform2fARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLfloat, GLfloat)>(getProcAddress("glUniform2fARB"));
	assert(glUniform2fARB_ != nullptr);
	return glUniform2fARB_(location, v0, v1);
}
void glUniform3fARB(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) {
	static const auto glUniform3fARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLfloat, GLfloat, GLfloat)>(getProcAddress("glUniform3fARB"));
	assert(glUniform3fARB_ != nullptr);
	return glUniform3fARB_(location, v0, v1, v2);
}
void glUniform4fARB(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {
	static const auto glUniform4fARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLfloat, GLfloat, GLfloat, GLfloat)>(getProcAddress("glUniform4fARB"));
	assert(glUniform4fARB_ != nullptr);
	return glUniform4fARB_(location, v0, v1, v2, v3);
}
void glUniform1iARB(GLint location, GLint v0) {
	static const auto glUniform1iARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLint)>(getProcAddress("glUniform1iARB"));
	assert(glUniform1iARB_ != nullptr);
	return glUniform1iARB_(location, v0);
}
void glUniform2iARB(GLint location, GLint v0, GLint v1) {
	static const auto glUniform2iARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLint, GLint)>(getProcAddress("glUniform2iARB"));
	assert(glUniform2iARB_ != nullptr);
	return glUniform2iARB_(location, v0, v1);
}
void glUniform3iARB(GLint location, GLint v0, GLint v1, GLint v2) {
	static const auto glUniform3iARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLint, GLint, GLint)>(getProcAddress("glUniform3iARB"));
	assert(glUniform3iARB_ != nullptr);
	return glUniform3iARB_(location, v0, v1, v2);
}
void glUniform4iARB(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) {
	static const auto glUniform4iARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLint, GLint, GLint, GLint)>(getProcAddress("glUniform4iARB"));
	assert(glUniform4iARB_ != nullptr);
	return glUniform4iARB_(location, v0, v1, v2, v3);
}
void glUniform1fvARB(GLint location, GLsizei count, GLfloat const  * value) {
	static const auto glUniform1fvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLfloat const  *)>(getProcAddress("glUniform1fvARB"));
	assert(glUniform1fvARB_ != nullptr);
	return glUniform1fvARB_(location, count, value);
}
void glUniform2fvARB(GLint location, GLsizei count, GLfloat const  * value) {
	static const auto glUniform2fvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLfloat const  *)>(getProcAddress("glUniform2fvARB"));
	assert(glUniform2fvARB_ != nullptr);
	return glUniform2fvARB_(location, count, value);
}
void glUniform3fvARB(GLint location, GLsizei count, GLfloat const  * value) {
	static const auto glUniform3fvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLfloat const  *)>(getProcAddress("glUniform3fvARB"));
	assert(glUniform3fvARB_ != nullptr);
	return glUniform3fvARB_(location, count, value);
}
void glUniform4fvARB(GLint location, GLsizei count, GLfloat const  * value) {
	static const auto glUniform4fvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLfloat const  *)>(getProcAddress("glUniform4fvARB"));
	assert(glUniform4fvARB_ != nullptr);
	return glUniform4fvARB_(location, count, value);
}
void glUniform1ivARB(GLint location, GLsizei count, GLint const  * value) {
	static const auto glUniform1ivARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLint const  *)>(getProcAddress("glUniform1ivARB"));
	assert(glUniform1ivARB_ != nullptr);
	return glUniform1ivARB_(location, count, value);
}
void glUniform2ivARB(GLint location, GLsizei count, GLint const  * value) {
	static const auto glUniform2ivARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLint const  *)>(getProcAddress("glUniform2ivARB"));
	assert(glUniform2ivARB_ != nullptr);
	return glUniform2ivARB_(location, count, value);
}
void glUniform3ivARB(GLint location, GLsizei count, GLint const  * value) {
	static const auto glUniform3ivARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLint const  *)>(getProcAddress("glUniform3ivARB"));
	assert(glUniform3ivARB_ != nullptr);
	return glUniform3ivARB_(location, count, value);
}
void glUniform4ivARB(GLint location, GLsizei count, GLint const  * value) {
	static const auto glUniform4ivARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLint const  *)>(getProcAddress("glUniform4ivARB"));
	assert(glUniform4ivARB_ != nullptr);
	return glUniform4ivARB_(location, count, value);
}
void glUniformMatrix2fvARB(GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value) {
	static const auto glUniformMatrix2fvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLboolean, GLfloat const  *)>(getProcAddress("glUniformMatrix2fvARB"));
	assert(glUniformMatrix2fvARB_ != nullptr);
	return glUniformMatrix2fvARB_(location, count, transpose, value);
}
void glUniformMatrix3fvARB(GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value) {
	static const auto glUniformMatrix3fvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLboolean, GLfloat const  *)>(getProcAddress("glUniformMatrix3fvARB"));
	assert(glUniformMatrix3fvARB_ != nullptr);
	return glUniformMatrix3fvARB_(location, count, transpose, value);
}
void glUniformMatrix4fvARB(GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value) {
	static const auto glUniformMatrix4fvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLboolean, GLfloat const  *)>(getProcAddress("glUniformMatrix4fvARB"));
	assert(glUniformMatrix4fvARB_ != nullptr);
	return glUniformMatrix4fvARB_(location, count, transpose, value);
}
void glGetObjectParameterfvARB(GLhandleARB obj, GLenum pname, GLfloat * params) {
	static const auto glGetObjectParameterfvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLhandleARB, GLenum, GLfloat *)>(getProcAddress("glGetObjectParameterfvARB"));
	assert(glGetObjectParameterfvARB_ != nullptr);
	return glGetObjectParameterfvARB_(obj, pname, params);
}
void glGetObjectParameterivARB(GLhandleARB obj, GLenum pname, GLint * params) {
	static const auto glGetObjectParameterivARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLhandleARB, GLenum, GLint *)>(getProcAddress("glGetObjectParameterivARB"));
	assert(glGetObjectParameterivARB_ != nullptr);
	return glGetObjectParameterivARB_(obj, pname, params);
}
void glGetInfoLogARB(GLhandleARB obj, GLsizei maxLength, GLsizei * length, GLcharARB * infoLog) {
	static const auto glGetInfoLogARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLhandleARB, GLsizei, GLsizei *, GLcharARB *)>(getProcAddress("glGetInfoLogARB"));
	assert(glGetInfoLogARB_ != nullptr);
	return glGetInfoLogARB_(obj, maxLength, length, infoLog);
}
void glGetAttachedObjectsARB(GLhandleARB containerObj, GLsizei maxCount, GLsizei * count, GLhandleARB * obj) {
	static const auto glGetAttachedObjectsARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLhandleARB, GLsizei, GLsizei *, GLhandleARB *)>(getProcAddress("glGetAttachedObjectsARB"));
	assert(glGetAttachedObjectsARB_ != nullptr);
	return glGetAttachedObjectsARB_(containerObj, maxCount, count, obj);
}
GLint glGetUniformLocationARB(GLhandleARB programObj, GLcharARB const  * name) {
	static const auto glGetUniformLocationARB_ = reinterpret_cast<GLint(GL_APIENTRYP)(GLhandleARB, GLcharARB const  *)>(getProcAddress("glGetUniformLocationARB"));
	assert(glGetUniformLocationARB_ != nullptr);
	return glGetUniformLocationARB_(programObj, name);
}
void glGetActiveUniformARB(GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei * length, GLint * size, GLenum * type, GLcharARB * name) {
	static const auto glGetActiveUniformARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLhandleARB, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLcharARB *)>(getProcAddress("glGetActiveUniformARB"));
	assert(glGetActiveUniformARB_ != nullptr);
	return glGetActiveUniformARB_(programObj, index, maxLength, length, size, type, name);
}
void glGetUniformfvARB(GLhandleARB programObj, GLint location, GLfloat * params) {
	static const auto glGetUniformfvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLhandleARB, GLint, GLfloat *)>(getProcAddress("glGetUniformfvARB"));
	assert(glGetUniformfvARB_ != nullptr);
	return glGetUniformfvARB_(programObj, location, params);
}
void glGetUniformivARB(GLhandleARB programObj, GLint location, GLint * params) {
	static const auto glGetUniformivARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLhandleARB, GLint, GLint *)>(getProcAddress("glGetUniformivARB"));
	assert(glGetUniformivARB_ != nullptr);
	return glGetUniformivARB_(programObj, location, params);
}
void glGetShaderSourceARB(GLhandleARB obj, GLsizei maxLength, GLsizei * length, GLcharARB * source) {
	static const auto glGetShaderSourceARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLhandleARB, GLsizei, GLsizei *, GLcharARB *)>(getProcAddress("glGetShaderSourceARB"));
	assert(glGetShaderSourceARB_ != nullptr);
	return glGetShaderSourceARB_(obj, maxLength, length, source);
}
void glShaderStorageBlockBinding(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding) {
	static const auto glShaderStorageBlockBinding_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLuint)>(getProcAddress("glShaderStorageBlockBinding"));
	assert(glShaderStorageBlockBinding_ != nullptr);
	return glShaderStorageBlockBinding_(program, storageBlockIndex, storageBlockBinding);
}
GLint glGetSubroutineUniformLocation(GLuint program, GLenum shadertype, GLchar const  * name) {
	static const auto glGetSubroutineUniformLocation_ = reinterpret_cast<GLint(GL_APIENTRYP)(GLuint, GLenum, GLchar const  *)>(getProcAddress("glGetSubroutineUniformLocation"));
	assert(glGetSubroutineUniformLocation_ != nullptr);
	return glGetSubroutineUniformLocation_(program, shadertype, name);
}
GLuint glGetSubroutineIndex(GLuint program, GLenum shadertype, GLchar const  * name) {
	static const auto glGetSubroutineIndex_ = reinterpret_cast<GLuint(GL_APIENTRYP)(GLuint, GLenum, GLchar const  *)>(getProcAddress("glGetSubroutineIndex"));
	assert(glGetSubroutineIndex_ != nullptr);
	return glGetSubroutineIndex_(program, shadertype, name);
}
void glGetActiveSubroutineUniformiv(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint * values) {
	static const auto glGetActiveSubroutineUniformiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLuint, GLenum, GLint *)>(getProcAddress("glGetActiveSubroutineUniformiv"));
	assert(glGetActiveSubroutineUniformiv_ != nullptr);
	return glGetActiveSubroutineUniformiv_(program, shadertype, index, pname, values);
}
void glGetActiveSubroutineUniformName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei * length, GLchar * name) {
	static const auto glGetActiveSubroutineUniformName_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLuint, GLsizei, GLsizei *, GLchar *)>(getProcAddress("glGetActiveSubroutineUniformName"));
	assert(glGetActiveSubroutineUniformName_ != nullptr);
	return glGetActiveSubroutineUniformName_(program, shadertype, index, bufSize, length, name);
}
void glGetActiveSubroutineName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei * length, GLchar * name) {
	static const auto glGetActiveSubroutineName_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLuint, GLsizei, GLsizei *, GLchar *)>(getProcAddress("glGetActiveSubroutineName"));
	assert(glGetActiveSubroutineName_ != nullptr);
	return glGetActiveSubroutineName_(program, shadertype, index, bufSize, length, name);
}
void glUniformSubroutinesuiv(GLenum shadertype, GLsizei count, GLuint const  * indices) {
	static const auto glUniformSubroutinesuiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, GLuint const  *)>(getProcAddress("glUniformSubroutinesuiv"));
	assert(glUniformSubroutinesuiv_ != nullptr);
	return glUniformSubroutinesuiv_(shadertype, count, indices);
}
void glGetUniformSubroutineuiv(GLenum shadertype, GLint location, GLuint * params) {
	static const auto glGetUniformSubroutineuiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLuint *)>(getProcAddress("glGetUniformSubroutineuiv"));
	assert(glGetUniformSubroutineuiv_ != nullptr);
	return glGetUniformSubroutineuiv_(shadertype, location, params);
}
void glGetProgramStageiv(GLuint program, GLenum shadertype, GLenum pname, GLint * values) {
	static const auto glGetProgramStageiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLenum, GLint *)>(getProcAddress("glGetProgramStageiv"));
	assert(glGetProgramStageiv_ != nullptr);
	return glGetProgramStageiv_(program, shadertype, pname, values);
}
void glNamedStringARB(GLenum type, GLint namelen, GLchar const  * name, GLint stringlen, GLchar const  * string) {
	static const auto glNamedStringARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLchar const  *, GLint, GLchar const  *)>(getProcAddress("glNamedStringARB"));
	assert(glNamedStringARB_ != nullptr);
	return glNamedStringARB_(type, namelen, name, stringlen, string);
}
void glDeleteNamedStringARB(GLint namelen, GLchar const  * name) {
	static const auto glDeleteNamedStringARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLchar const  *)>(getProcAddress("glDeleteNamedStringARB"));
	assert(glDeleteNamedStringARB_ != nullptr);
	return glDeleteNamedStringARB_(namelen, name);
}
void glCompileShaderIncludeARB(GLuint shader, GLsizei count, GLchar const  *const* path, GLint const  * length) {
	static const auto glCompileShaderIncludeARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLsizei, GLchar const  *const*, GLint const  *)>(getProcAddress("glCompileShaderIncludeARB"));
	assert(glCompileShaderIncludeARB_ != nullptr);
	return glCompileShaderIncludeARB_(shader, count, path, length);
}
GLboolean glIsNamedStringARB(GLint namelen, GLchar const  * name) {
	static const auto glIsNamedStringARB_ = reinterpret_cast<GLboolean(GL_APIENTRYP)(GLint, GLchar const  *)>(getProcAddress("glIsNamedStringARB"));
	assert(glIsNamedStringARB_ != nullptr);
	return glIsNamedStringARB_(namelen, name);
}
void glGetNamedStringARB(GLint namelen, GLchar const  * name, GLsizei bufSize, GLint * stringlen, GLchar * string) {
	static const auto glGetNamedStringARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLchar const  *, GLsizei, GLint *, GLchar *)>(getProcAddress("glGetNamedStringARB"));
	assert(glGetNamedStringARB_ != nullptr);
	return glGetNamedStringARB_(namelen, name, bufSize, stringlen, string);
}
void glGetNamedStringivARB(GLint namelen, GLchar const  * name, GLenum pname, GLint * params) {
	static const auto glGetNamedStringivARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLchar const  *, GLenum, GLint *)>(getProcAddress("glGetNamedStringivARB"));
	assert(glGetNamedStringivARB_ != nullptr);
	return glGetNamedStringivARB_(namelen, name, pname, params);
}
void glBufferPageCommitmentARB(GLenum target, GLintptr offset, GLsizeiptr size, GLboolean commit) {
	static const auto glBufferPageCommitmentARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLintptr, GLsizeiptr, GLboolean)>(getProcAddress("glBufferPageCommitmentARB"));
	assert(glBufferPageCommitmentARB_ != nullptr);
	return glBufferPageCommitmentARB_(target, offset, size, commit);
}
void glNamedBufferPageCommitmentEXT(GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit) {
	static const auto glNamedBufferPageCommitmentEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLintptr, GLsizeiptr, GLboolean)>(getProcAddress("glNamedBufferPageCommitmentEXT"));
	assert(glNamedBufferPageCommitmentEXT_ != nullptr);
	return glNamedBufferPageCommitmentEXT_(buffer, offset, size, commit);
}
void glNamedBufferPageCommitmentARB(GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit) {
	static const auto glNamedBufferPageCommitmentARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLintptr, GLsizeiptr, GLboolean)>(getProcAddress("glNamedBufferPageCommitmentARB"));
	assert(glNamedBufferPageCommitmentARB_ != nullptr);
	return glNamedBufferPageCommitmentARB_(buffer, offset, size, commit);
}
void glTexPageCommitmentARB(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit) {
	static const auto glTexPageCommitmentARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLboolean)>(getProcAddress("glTexPageCommitmentARB"));
	assert(glTexPageCommitmentARB_ != nullptr);
	return glTexPageCommitmentARB_(target, level, xoffset, yoffset, zoffset, width, height, depth, commit);
}
GLsync glFenceSync(GLenum condition, GLbitfield flags) {
	static const auto glFenceSync_ = reinterpret_cast<GLsync(GL_APIENTRYP)(GLenum, GLbitfield)>(getProcAddress("glFenceSync"));
	assert(glFenceSync_ != nullptr);
	return glFenceSync_(condition, flags);
}
GLboolean glIsSync(GLsync sync) {
	static const auto glIsSync_ = reinterpret_cast<GLboolean(GL_APIENTRYP)(GLsync)>(getProcAddress("glIsSync"));
	assert(glIsSync_ != nullptr);
	return glIsSync_(sync);
}
void glDeleteSync(GLsync sync) {
	static const auto glDeleteSync_ = reinterpret_cast<void(GL_APIENTRYP)(GLsync)>(getProcAddress("glDeleteSync"));
	assert(glDeleteSync_ != nullptr);
	return glDeleteSync_(sync);
}
GLenum glClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout) {
	static const auto glClientWaitSync_ = reinterpret_cast<GLenum(GL_APIENTRYP)(GLsync, GLbitfield, GLuint64)>(getProcAddress("glClientWaitSync"));
	assert(glClientWaitSync_ != nullptr);
	return glClientWaitSync_(sync, flags, timeout);
}
void glWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout) {
	static const auto glWaitSync_ = reinterpret_cast<void(GL_APIENTRYP)(GLsync, GLbitfield, GLuint64)>(getProcAddress("glWaitSync"));
	assert(glWaitSync_ != nullptr);
	return glWaitSync_(sync, flags, timeout);
}
void glGetInteger64v(GLenum pname, GLint64 * data) {
	static const auto glGetInteger64v_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint64 *)>(getProcAddress("glGetInteger64v"));
	assert(glGetInteger64v_ != nullptr);
	return glGetInteger64v_(pname, data);
}
void glGetSynciv(GLsync sync, GLenum pname, GLsizei count, GLsizei * length, GLint * values) {
	static const auto glGetSynciv_ = reinterpret_cast<void(GL_APIENTRYP)(GLsync, GLenum, GLsizei, GLsizei *, GLint *)>(getProcAddress("glGetSynciv"));
	assert(glGetSynciv_ != nullptr);
	return glGetSynciv_(sync, pname, count, length, values);
}
void glPatchParameteri(GLenum pname, GLint value) {
	static const auto glPatchParameteri_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint)>(getProcAddress("glPatchParameteri"));
	assert(glPatchParameteri_ != nullptr);
	return glPatchParameteri_(pname, value);
}
void glPatchParameterfv(GLenum pname, GLfloat const  * values) {
	static const auto glPatchParameterfv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfloat const  *)>(getProcAddress("glPatchParameterfv"));
	assert(glPatchParameterfv_ != nullptr);
	return glPatchParameterfv_(pname, values);
}
void glTextureBarrier() {
	static const auto glTextureBarrier_ = reinterpret_cast<void(GL_APIENTRYP)()>(getProcAddress("glTextureBarrier"));
	assert(glTextureBarrier_ != nullptr);
	return glTextureBarrier_();
}
void glTexBufferARB(GLenum target, GLenum internalformat, GLuint buffer) {
	static const auto glTexBufferARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLuint)>(getProcAddress("glTexBufferARB"));
	assert(glTexBufferARB_ != nullptr);
	return glTexBufferARB_(target, internalformat, buffer);
}
void glTexBufferRange(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size) {
	static const auto glTexBufferRange_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLuint, GLintptr, GLsizeiptr)>(getProcAddress("glTexBufferRange"));
	assert(glTexBufferRange_ != nullptr);
	return glTexBufferRange_(target, internalformat, buffer, offset, size);
}
void glCompressedTexImage3DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void * data) {
	static const auto glCompressedTexImage3DARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLsizei, const void *)>(getProcAddress("glCompressedTexImage3DARB"));
	assert(glCompressedTexImage3DARB_ != nullptr);
	return glCompressedTexImage3DARB_(target, level, internalformat, width, height, depth, border, imageSize, data);
}
void glCompressedTexImage2DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void * data) {
	static const auto glCompressedTexImage2DARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const void *)>(getProcAddress("glCompressedTexImage2DARB"));
	assert(glCompressedTexImage2DARB_ != nullptr);
	return glCompressedTexImage2DARB_(target, level, internalformat, width, height, border, imageSize, data);
}
void glCompressedTexImage1DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void * data) {
	static const auto glCompressedTexImage1DARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLenum, GLsizei, GLint, GLsizei, const void *)>(getProcAddress("glCompressedTexImage1DARB"));
	assert(glCompressedTexImage1DARB_ != nullptr);
	return glCompressedTexImage1DARB_(target, level, internalformat, width, border, imageSize, data);
}
void glCompressedTexSubImage3DARB(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * data) {
	static const auto glCompressedTexSubImage3DARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const void *)>(getProcAddress("glCompressedTexSubImage3DARB"));
	assert(glCompressedTexSubImage3DARB_ != nullptr);
	return glCompressedTexSubImage3DARB_(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
}
void glCompressedTexSubImage2DARB(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * data) {
	static const auto glCompressedTexSubImage2DARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const void *)>(getProcAddress("glCompressedTexSubImage2DARB"));
	assert(glCompressedTexSubImage2DARB_ != nullptr);
	return glCompressedTexSubImage2DARB_(target, level, xoffset, yoffset, width, height, format, imageSize, data);
}
void glCompressedTexSubImage1DARB(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * data) {
	static const auto glCompressedTexSubImage1DARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLint, GLsizei, GLenum, GLsizei, const void *)>(getProcAddress("glCompressedTexSubImage1DARB"));
	assert(glCompressedTexSubImage1DARB_ != nullptr);
	return glCompressedTexSubImage1DARB_(target, level, xoffset, width, format, imageSize, data);
}
void glGetCompressedTexImageARB(GLenum target, GLint level, void * img) {
	static const auto glGetCompressedTexImageARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, void *)>(getProcAddress("glGetCompressedTexImageARB"));
	assert(glGetCompressedTexImageARB_ != nullptr);
	return glGetCompressedTexImageARB_(target, level, img);
}
void glTexImage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) {
	static const auto glTexImage2DMultisample_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLboolean)>(getProcAddress("glTexImage2DMultisample"));
	assert(glTexImage2DMultisample_ != nullptr);
	return glTexImage2DMultisample_(target, samples, internalformat, width, height, fixedsamplelocations);
}
void glTexImage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) {
	static const auto glTexImage3DMultisample_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei, GLboolean)>(getProcAddress("glTexImage3DMultisample"));
	assert(glTexImage3DMultisample_ != nullptr);
	return glTexImage3DMultisample_(target, samples, internalformat, width, height, depth, fixedsamplelocations);
}
void glGetMultisamplefv(GLenum pname, GLuint index, GLfloat * val) {
	static const auto glGetMultisamplefv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint, GLfloat *)>(getProcAddress("glGetMultisamplefv"));
	assert(glGetMultisamplefv_ != nullptr);
	return glGetMultisamplefv_(pname, index, val);
}
void glSampleMaski(GLuint maskNumber, GLbitfield mask) {
	static const auto glSampleMaski_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLbitfield)>(getProcAddress("glSampleMaski"));
	assert(glSampleMaski_ != nullptr);
	return glSampleMaski_(maskNumber, mask);
}
void glTexStorage1D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width) {
	static const auto glTexStorage1D_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, GLenum, GLsizei)>(getProcAddress("glTexStorage1D"));
	assert(glTexStorage1D_ != nullptr);
	return glTexStorage1D_(target, levels, internalformat, width);
}
void glTexStorage2D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) {
	static const auto glTexStorage2D_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, GLenum, GLsizei, GLsizei)>(getProcAddress("glTexStorage2D"));
	assert(glTexStorage2D_ != nullptr);
	return glTexStorage2D_(target, levels, internalformat, width, height);
}
void glTexStorage3D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) {
	static const auto glTexStorage3D_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei)>(getProcAddress("glTexStorage3D"));
	assert(glTexStorage3D_ != nullptr);
	return glTexStorage3D_(target, levels, internalformat, width, height, depth);
}
void glTexStorage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) {
	static const auto glTexStorage2DMultisample_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLboolean)>(getProcAddress("glTexStorage2DMultisample"));
	assert(glTexStorage2DMultisample_ != nullptr);
	return glTexStorage2DMultisample_(target, samples, internalformat, width, height, fixedsamplelocations);
}
void glTexStorage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) {
	static const auto glTexStorage3DMultisample_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei, GLboolean)>(getProcAddress("glTexStorage3DMultisample"));
	assert(glTexStorage3DMultisample_ != nullptr);
	return glTexStorage3DMultisample_(target, samples, internalformat, width, height, depth, fixedsamplelocations);
}
void glTextureView(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers) {
	static const auto glTextureView_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLuint, GLenum, GLuint, GLuint, GLuint, GLuint)>(getProcAddress("glTextureView"));
	assert(glTextureView_ != nullptr);
	return glTextureView_(texture, target, origtexture, internalformat, minlevel, numlevels, minlayer, numlayers);
}
void glQueryCounter(GLuint id, GLenum target) {
	static const auto glQueryCounter_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum)>(getProcAddress("glQueryCounter"));
	assert(glQueryCounter_ != nullptr);
	return glQueryCounter_(id, target);
}
void glGetQueryObjecti64v(GLuint id, GLenum pname, GLint64 * params) {
	static const auto glGetQueryObjecti64v_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint64 *)>(getProcAddress("glGetQueryObjecti64v"));
	assert(glGetQueryObjecti64v_ != nullptr);
	return glGetQueryObjecti64v_(id, pname, params);
}
void glGetQueryObjectui64v(GLuint id, GLenum pname, GLuint64 * params) {
	static const auto glGetQueryObjectui64v_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLuint64 *)>(getProcAddress("glGetQueryObjectui64v"));
	assert(glGetQueryObjectui64v_ != nullptr);
	return glGetQueryObjectui64v_(id, pname, params);
}
void glBindTransformFeedback(GLenum target, GLuint id) {
	static const auto glBindTransformFeedback_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint)>(getProcAddress("glBindTransformFeedback"));
	assert(glBindTransformFeedback_ != nullptr);
	return glBindTransformFeedback_(target, id);
}
void glDeleteTransformFeedbacks(GLsizei n, GLuint const  * ids) {
	static const auto glDeleteTransformFeedbacks_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint const  *)>(getProcAddress("glDeleteTransformFeedbacks"));
	assert(glDeleteTransformFeedbacks_ != nullptr);
	return glDeleteTransformFeedbacks_(n, ids);
}
void glGenTransformFeedbacks(GLsizei n, GLuint * ids) {
	static const auto glGenTransformFeedbacks_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint *)>(getProcAddress("glGenTransformFeedbacks"));
	assert(glGenTransformFeedbacks_ != nullptr);
	return glGenTransformFeedbacks_(n, ids);
}
GLboolean glIsTransformFeedback(GLuint id) {
	static const auto glIsTransformFeedback_ = reinterpret_cast<GLboolean(GL_APIENTRYP)(GLuint)>(getProcAddress("glIsTransformFeedback"));
	assert(glIsTransformFeedback_ != nullptr);
	return glIsTransformFeedback_(id);
}
void glPauseTransformFeedback() {
	static const auto glPauseTransformFeedback_ = reinterpret_cast<void(GL_APIENTRYP)()>(getProcAddress("glPauseTransformFeedback"));
	assert(glPauseTransformFeedback_ != nullptr);
	return glPauseTransformFeedback_();
}
void glResumeTransformFeedback() {
	static const auto glResumeTransformFeedback_ = reinterpret_cast<void(GL_APIENTRYP)()>(getProcAddress("glResumeTransformFeedback"));
	assert(glResumeTransformFeedback_ != nullptr);
	return glResumeTransformFeedback_();
}
void glDrawTransformFeedback(GLenum mode, GLuint id) {
	static const auto glDrawTransformFeedback_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint)>(getProcAddress("glDrawTransformFeedback"));
	assert(glDrawTransformFeedback_ != nullptr);
	return glDrawTransformFeedback_(mode, id);
}
void glDrawTransformFeedbackStream(GLenum mode, GLuint id, GLuint stream) {
	static const auto glDrawTransformFeedbackStream_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint, GLuint)>(getProcAddress("glDrawTransformFeedbackStream"));
	assert(glDrawTransformFeedbackStream_ != nullptr);
	return glDrawTransformFeedbackStream_(mode, id, stream);
}
void glBeginQueryIndexed(GLenum target, GLuint index, GLuint id) {
	static const auto glBeginQueryIndexed_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint, GLuint)>(getProcAddress("glBeginQueryIndexed"));
	assert(glBeginQueryIndexed_ != nullptr);
	return glBeginQueryIndexed_(target, index, id);
}
void glEndQueryIndexed(GLenum target, GLuint index) {
	static const auto glEndQueryIndexed_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint)>(getProcAddress("glEndQueryIndexed"));
	assert(glEndQueryIndexed_ != nullptr);
	return glEndQueryIndexed_(target, index);
}
void glGetQueryIndexediv(GLenum target, GLuint index, GLenum pname, GLint * params) {
	static const auto glGetQueryIndexediv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint, GLenum, GLint *)>(getProcAddress("glGetQueryIndexediv"));
	assert(glGetQueryIndexediv_ != nullptr);
	return glGetQueryIndexediv_(target, index, pname, params);
}
void glDrawTransformFeedbackInstanced(GLenum mode, GLuint id, GLsizei instancecount) {
	static const auto glDrawTransformFeedbackInstanced_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint, GLsizei)>(getProcAddress("glDrawTransformFeedbackInstanced"));
	assert(glDrawTransformFeedbackInstanced_ != nullptr);
	return glDrawTransformFeedbackInstanced_(mode, id, instancecount);
}
void glDrawTransformFeedbackStreamInstanced(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount) {
	static const auto glDrawTransformFeedbackStreamInstanced_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint, GLuint, GLsizei)>(getProcAddress("glDrawTransformFeedbackStreamInstanced"));
	assert(glDrawTransformFeedbackStreamInstanced_ != nullptr);
	return glDrawTransformFeedbackStreamInstanced_(mode, id, stream, instancecount);
}
void glLoadTransposeMatrixfARB(GLfloat const  * m) {
	static const auto glLoadTransposeMatrixfARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat const  *)>(getProcAddress("glLoadTransposeMatrixfARB"));
	assert(glLoadTransposeMatrixfARB_ != nullptr);
	return glLoadTransposeMatrixfARB_(m);
}
void glLoadTransposeMatrixdARB(GLdouble const  * m) {
	static const auto glLoadTransposeMatrixdARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble const  *)>(getProcAddress("glLoadTransposeMatrixdARB"));
	assert(glLoadTransposeMatrixdARB_ != nullptr);
	return glLoadTransposeMatrixdARB_(m);
}
void glMultTransposeMatrixfARB(GLfloat const  * m) {
	static const auto glMultTransposeMatrixfARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat const  *)>(getProcAddress("glMultTransposeMatrixfARB"));
	assert(glMultTransposeMatrixfARB_ != nullptr);
	return glMultTransposeMatrixfARB_(m);
}
void glMultTransposeMatrixdARB(GLdouble const  * m) {
	static const auto glMultTransposeMatrixdARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble const  *)>(getProcAddress("glMultTransposeMatrixdARB"));
	assert(glMultTransposeMatrixdARB_ != nullptr);
	return glMultTransposeMatrixdARB_(m);
}
void glGetUniformIndices(GLuint program, GLsizei uniformCount, GLchar const  *const* uniformNames, GLuint * uniformIndices) {
	static const auto glGetUniformIndices_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLsizei, GLchar const  *const*, GLuint *)>(getProcAddress("glGetUniformIndices"));
	assert(glGetUniformIndices_ != nullptr);
	return glGetUniformIndices_(program, uniformCount, uniformNames, uniformIndices);
}
void glGetActiveUniformsiv(GLuint program, GLsizei uniformCount, GLuint const  * uniformIndices, GLenum pname, GLint * params) {
	static const auto glGetActiveUniformsiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLsizei, GLuint const  *, GLenum, GLint *)>(getProcAddress("glGetActiveUniformsiv"));
	assert(glGetActiveUniformsiv_ != nullptr);
	return glGetActiveUniformsiv_(program, uniformCount, uniformIndices, pname, params);
}
void glGetActiveUniformName(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei * length, GLchar * uniformName) {
	static const auto glGetActiveUniformName_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLsizei, GLsizei *, GLchar *)>(getProcAddress("glGetActiveUniformName"));
	assert(glGetActiveUniformName_ != nullptr);
	return glGetActiveUniformName_(program, uniformIndex, bufSize, length, uniformName);
}
GLuint glGetUniformBlockIndex(GLuint program, GLchar const  * uniformBlockName) {
	static const auto glGetUniformBlockIndex_ = reinterpret_cast<GLuint(GL_APIENTRYP)(GLuint, GLchar const  *)>(getProcAddress("glGetUniformBlockIndex"));
	assert(glGetUniformBlockIndex_ != nullptr);
	return glGetUniformBlockIndex_(program, uniformBlockName);
}
void glGetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint * params) {
	static const auto glGetActiveUniformBlockiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLenum, GLint *)>(getProcAddress("glGetActiveUniformBlockiv"));
	assert(glGetActiveUniformBlockiv_ != nullptr);
	return glGetActiveUniformBlockiv_(program, uniformBlockIndex, pname, params);
}
void glGetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei * length, GLchar * uniformBlockName) {
	static const auto glGetActiveUniformBlockName_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLsizei, GLsizei *, GLchar *)>(getProcAddress("glGetActiveUniformBlockName"));
	assert(glGetActiveUniformBlockName_ != nullptr);
	return glGetActiveUniformBlockName_(program, uniformBlockIndex, bufSize, length, uniformBlockName);
}
void glUniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding) {
	static const auto glUniformBlockBinding_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLuint)>(getProcAddress("glUniformBlockBinding"));
	assert(glUniformBlockBinding_ != nullptr);
	return glUniformBlockBinding_(program, uniformBlockIndex, uniformBlockBinding);
}
void glVertexAttribL1d(GLuint index, GLdouble x) {
	static const auto glVertexAttribL1d_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLdouble)>(getProcAddress("glVertexAttribL1d"));
	assert(glVertexAttribL1d_ != nullptr);
	return glVertexAttribL1d_(index, x);
}
void glVertexAttribL2d(GLuint index, GLdouble x, GLdouble y) {
	static const auto glVertexAttribL2d_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLdouble, GLdouble)>(getProcAddress("glVertexAttribL2d"));
	assert(glVertexAttribL2d_ != nullptr);
	return glVertexAttribL2d_(index, x, y);
}
void glVertexAttribL3d(GLuint index, GLdouble x, GLdouble y, GLdouble z) {
	static const auto glVertexAttribL3d_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLdouble, GLdouble, GLdouble)>(getProcAddress("glVertexAttribL3d"));
	assert(glVertexAttribL3d_ != nullptr);
	return glVertexAttribL3d_(index, x, y, z);
}
void glVertexAttribL4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
	static const auto glVertexAttribL4d_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLdouble, GLdouble, GLdouble, GLdouble)>(getProcAddress("glVertexAttribL4d"));
	assert(glVertexAttribL4d_ != nullptr);
	return glVertexAttribL4d_(index, x, y, z, w);
}
void glVertexAttribL1dv(GLuint index, GLdouble const  * v) {
	static const auto glVertexAttribL1dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLdouble const  *)>(getProcAddress("glVertexAttribL1dv"));
	assert(glVertexAttribL1dv_ != nullptr);
	return glVertexAttribL1dv_(index, v);
}
void glVertexAttribL2dv(GLuint index, GLdouble const  * v) {
	static const auto glVertexAttribL2dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLdouble const  *)>(getProcAddress("glVertexAttribL2dv"));
	assert(glVertexAttribL2dv_ != nullptr);
	return glVertexAttribL2dv_(index, v);
}
void glVertexAttribL3dv(GLuint index, GLdouble const  * v) {
	static const auto glVertexAttribL3dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLdouble const  *)>(getProcAddress("glVertexAttribL3dv"));
	assert(glVertexAttribL3dv_ != nullptr);
	return glVertexAttribL3dv_(index, v);
}
void glVertexAttribL4dv(GLuint index, GLdouble const  * v) {
	static const auto glVertexAttribL4dv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLdouble const  *)>(getProcAddress("glVertexAttribL4dv"));
	assert(glVertexAttribL4dv_ != nullptr);
	return glVertexAttribL4dv_(index, v);
}
void glVertexAttribLPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void * pointer) {
	static const auto glVertexAttribLPointer_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLenum, GLsizei, const void *)>(getProcAddress("glVertexAttribLPointer"));
	assert(glVertexAttribLPointer_ != nullptr);
	return glVertexAttribLPointer_(index, size, type, stride, pointer);
}
void glGetVertexAttribLdv(GLuint index, GLenum pname, GLdouble * params) {
	static const auto glGetVertexAttribLdv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLdouble *)>(getProcAddress("glGetVertexAttribLdv"));
	assert(glGetVertexAttribLdv_ != nullptr);
	return glGetVertexAttribLdv_(index, pname, params);
}
void glBindVertexBuffer(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride) {
	static const auto glBindVertexBuffer_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLintptr, GLsizei)>(getProcAddress("glBindVertexBuffer"));
	assert(glBindVertexBuffer_ != nullptr);
	return glBindVertexBuffer_(bindingindex, buffer, offset, stride);
}
void glVertexAttribFormat(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset) {
	static const auto glVertexAttribFormat_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLenum, GLboolean, GLuint)>(getProcAddress("glVertexAttribFormat"));
	assert(glVertexAttribFormat_ != nullptr);
	return glVertexAttribFormat_(attribindex, size, type, normalized, relativeoffset);
}
void glVertexAttribIFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) {
	static const auto glVertexAttribIFormat_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLenum, GLuint)>(getProcAddress("glVertexAttribIFormat"));
	assert(glVertexAttribIFormat_ != nullptr);
	return glVertexAttribIFormat_(attribindex, size, type, relativeoffset);
}
void glVertexAttribLFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) {
	static const auto glVertexAttribLFormat_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLenum, GLuint)>(getProcAddress("glVertexAttribLFormat"));
	assert(glVertexAttribLFormat_ != nullptr);
	return glVertexAttribLFormat_(attribindex, size, type, relativeoffset);
}
void glVertexAttribBinding(GLuint attribindex, GLuint bindingindex) {
	static const auto glVertexAttribBinding_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint)>(getProcAddress("glVertexAttribBinding"));
	assert(glVertexAttribBinding_ != nullptr);
	return glVertexAttribBinding_(attribindex, bindingindex);
}
void glVertexBindingDivisor(GLuint bindingindex, GLuint divisor) {
	static const auto glVertexBindingDivisor_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint)>(getProcAddress("glVertexBindingDivisor"));
	assert(glVertexBindingDivisor_ != nullptr);
	return glVertexBindingDivisor_(bindingindex, divisor);
}
void glWeightbvARB(GLint size, GLbyte const  * weights) {
	static const auto glWeightbvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLbyte const  *)>(getProcAddress("glWeightbvARB"));
	assert(glWeightbvARB_ != nullptr);
	return glWeightbvARB_(size, weights);
}
void glWeightsvARB(GLint size, GLshort const  * weights) {
	static const auto glWeightsvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLshort const  *)>(getProcAddress("glWeightsvARB"));
	assert(glWeightsvARB_ != nullptr);
	return glWeightsvARB_(size, weights);
}
void glWeightivARB(GLint size, GLint const  * weights) {
	static const auto glWeightivARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLint const  *)>(getProcAddress("glWeightivARB"));
	assert(glWeightivARB_ != nullptr);
	return glWeightivARB_(size, weights);
}
void glWeightfvARB(GLint size, GLfloat const  * weights) {
	static const auto glWeightfvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLfloat const  *)>(getProcAddress("glWeightfvARB"));
	assert(glWeightfvARB_ != nullptr);
	return glWeightfvARB_(size, weights);
}
void glWeightdvARB(GLint size, GLdouble const  * weights) {
	static const auto glWeightdvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLdouble const  *)>(getProcAddress("glWeightdvARB"));
	assert(glWeightdvARB_ != nullptr);
	return glWeightdvARB_(size, weights);
}
void glWeightubvARB(GLint size, GLubyte const  * weights) {
	static const auto glWeightubvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLubyte const  *)>(getProcAddress("glWeightubvARB"));
	assert(glWeightubvARB_ != nullptr);
	return glWeightubvARB_(size, weights);
}
void glWeightusvARB(GLint size, GLushort const  * weights) {
	static const auto glWeightusvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLushort const  *)>(getProcAddress("glWeightusvARB"));
	assert(glWeightusvARB_ != nullptr);
	return glWeightusvARB_(size, weights);
}
void glWeightuivARB(GLint size, GLuint const  * weights) {
	static const auto glWeightuivARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLuint const  *)>(getProcAddress("glWeightuivARB"));
	assert(glWeightuivARB_ != nullptr);
	return glWeightuivARB_(size, weights);
}
void glWeightPointerARB(GLint size, GLenum type, GLsizei stride, const void * pointer) {
	static const auto glWeightPointerARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLenum, GLsizei, const void *)>(getProcAddress("glWeightPointerARB"));
	assert(glWeightPointerARB_ != nullptr);
	return glWeightPointerARB_(size, type, stride, pointer);
}
void glVertexBlendARB(GLint count) {
	static const auto glVertexBlendARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint)>(getProcAddress("glVertexBlendARB"));
	assert(glVertexBlendARB_ != nullptr);
	return glVertexBlendARB_(count);
}
void glBindBufferARB(GLenum target, GLuint buffer) {
	static const auto glBindBufferARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint)>(getProcAddress("glBindBufferARB"));
	assert(glBindBufferARB_ != nullptr);
	return glBindBufferARB_(target, buffer);
}
void glDeleteBuffersARB(GLsizei n, GLuint const  * buffers) {
	static const auto glDeleteBuffersARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint const  *)>(getProcAddress("glDeleteBuffersARB"));
	assert(glDeleteBuffersARB_ != nullptr);
	return glDeleteBuffersARB_(n, buffers);
}
void glGenBuffersARB(GLsizei n, GLuint * buffers) {
	static const auto glGenBuffersARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint *)>(getProcAddress("glGenBuffersARB"));
	assert(glGenBuffersARB_ != nullptr);
	return glGenBuffersARB_(n, buffers);
}
GLboolean glIsBufferARB(GLuint buffer) {
	static const auto glIsBufferARB_ = reinterpret_cast<GLboolean(GL_APIENTRYP)(GLuint)>(getProcAddress("glIsBufferARB"));
	assert(glIsBufferARB_ != nullptr);
	return glIsBufferARB_(buffer);
}
void glBufferDataARB(GLenum target, GLsizeiptrARB size, const void * data, GLenum usage) {
	static const auto glBufferDataARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizeiptrARB, const void *, GLenum)>(getProcAddress("glBufferDataARB"));
	assert(glBufferDataARB_ != nullptr);
	return glBufferDataARB_(target, size, data, usage);
}
void glBufferSubDataARB(GLenum target, GLintptrARB offset, GLsizeiptrARB size, const void * data) {
	static const auto glBufferSubDataARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLintptrARB, GLsizeiptrARB, const void *)>(getProcAddress("glBufferSubDataARB"));
	assert(glBufferSubDataARB_ != nullptr);
	return glBufferSubDataARB_(target, offset, size, data);
}
void glGetBufferSubDataARB(GLenum target, GLintptrARB offset, GLsizeiptrARB size, void * data) {
	static const auto glGetBufferSubDataARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLintptrARB, GLsizeiptrARB, void *)>(getProcAddress("glGetBufferSubDataARB"));
	assert(glGetBufferSubDataARB_ != nullptr);
	return glGetBufferSubDataARB_(target, offset, size, data);
}
void * glMapBufferARB(GLenum target, GLenum access) {
	static const auto glMapBufferARB_ = reinterpret_cast<void *(GL_APIENTRYP)(GLenum, GLenum)>(getProcAddress("glMapBufferARB"));
	assert(glMapBufferARB_ != nullptr);
	return glMapBufferARB_(target, access);
}
GLboolean glUnmapBufferARB(GLenum target) {
	static const auto glUnmapBufferARB_ = reinterpret_cast<GLboolean(GL_APIENTRYP)(GLenum)>(getProcAddress("glUnmapBufferARB"));
	assert(glUnmapBufferARB_ != nullptr);
	return glUnmapBufferARB_(target);
}
void glGetBufferParameterivARB(GLenum target, GLenum pname, GLint * params) {
	static const auto glGetBufferParameterivARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint *)>(getProcAddress("glGetBufferParameterivARB"));
	assert(glGetBufferParameterivARB_ != nullptr);
	return glGetBufferParameterivARB_(target, pname, params);
}
void glGetBufferPointervARB(GLenum target, GLenum pname, void ** params) {
	static const auto glGetBufferPointervARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, void **)>(getProcAddress("glGetBufferPointervARB"));
	assert(glGetBufferPointervARB_ != nullptr);
	return glGetBufferPointervARB_(target, pname, params);
}
void glVertexAttrib1dARB(GLuint index, GLdouble x) {
	static const auto glVertexAttrib1dARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLdouble)>(getProcAddress("glVertexAttrib1dARB"));
	assert(glVertexAttrib1dARB_ != nullptr);
	return glVertexAttrib1dARB_(index, x);
}
void glVertexAttrib1dvARB(GLuint index, GLdouble const  * v) {
	static const auto glVertexAttrib1dvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLdouble const  *)>(getProcAddress("glVertexAttrib1dvARB"));
	assert(glVertexAttrib1dvARB_ != nullptr);
	return glVertexAttrib1dvARB_(index, v);
}
void glVertexAttrib1fARB(GLuint index, GLfloat x) {
	static const auto glVertexAttrib1fARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLfloat)>(getProcAddress("glVertexAttrib1fARB"));
	assert(glVertexAttrib1fARB_ != nullptr);
	return glVertexAttrib1fARB_(index, x);
}
void glVertexAttrib1fvARB(GLuint index, GLfloat const  * v) {
	static const auto glVertexAttrib1fvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLfloat const  *)>(getProcAddress("glVertexAttrib1fvARB"));
	assert(glVertexAttrib1fvARB_ != nullptr);
	return glVertexAttrib1fvARB_(index, v);
}
void glVertexAttrib1sARB(GLuint index, GLshort x) {
	static const auto glVertexAttrib1sARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLshort)>(getProcAddress("glVertexAttrib1sARB"));
	assert(glVertexAttrib1sARB_ != nullptr);
	return glVertexAttrib1sARB_(index, x);
}
void glVertexAttrib1svARB(GLuint index, GLshort const  * v) {
	static const auto glVertexAttrib1svARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLshort const  *)>(getProcAddress("glVertexAttrib1svARB"));
	assert(glVertexAttrib1svARB_ != nullptr);
	return glVertexAttrib1svARB_(index, v);
}
void glVertexAttrib2dARB(GLuint index, GLdouble x, GLdouble y) {
	static const auto glVertexAttrib2dARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLdouble, GLdouble)>(getProcAddress("glVertexAttrib2dARB"));
	assert(glVertexAttrib2dARB_ != nullptr);
	return glVertexAttrib2dARB_(index, x, y);
}
void glVertexAttrib2dvARB(GLuint index, GLdouble const  * v) {
	static const auto glVertexAttrib2dvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLdouble const  *)>(getProcAddress("glVertexAttrib2dvARB"));
	assert(glVertexAttrib2dvARB_ != nullptr);
	return glVertexAttrib2dvARB_(index, v);
}
void glVertexAttrib2fARB(GLuint index, GLfloat x, GLfloat y) {
	static const auto glVertexAttrib2fARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLfloat, GLfloat)>(getProcAddress("glVertexAttrib2fARB"));
	assert(glVertexAttrib2fARB_ != nullptr);
	return glVertexAttrib2fARB_(index, x, y);
}
void glVertexAttrib2fvARB(GLuint index, GLfloat const  * v) {
	static const auto glVertexAttrib2fvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLfloat const  *)>(getProcAddress("glVertexAttrib2fvARB"));
	assert(glVertexAttrib2fvARB_ != nullptr);
	return glVertexAttrib2fvARB_(index, v);
}
void glVertexAttrib2sARB(GLuint index, GLshort x, GLshort y) {
	static const auto glVertexAttrib2sARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLshort, GLshort)>(getProcAddress("glVertexAttrib2sARB"));
	assert(glVertexAttrib2sARB_ != nullptr);
	return glVertexAttrib2sARB_(index, x, y);
}
void glVertexAttrib2svARB(GLuint index, GLshort const  * v) {
	static const auto glVertexAttrib2svARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLshort const  *)>(getProcAddress("glVertexAttrib2svARB"));
	assert(glVertexAttrib2svARB_ != nullptr);
	return glVertexAttrib2svARB_(index, v);
}
void glVertexAttrib3dARB(GLuint index, GLdouble x, GLdouble y, GLdouble z) {
	static const auto glVertexAttrib3dARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLdouble, GLdouble, GLdouble)>(getProcAddress("glVertexAttrib3dARB"));
	assert(glVertexAttrib3dARB_ != nullptr);
	return glVertexAttrib3dARB_(index, x, y, z);
}
void glVertexAttrib3dvARB(GLuint index, GLdouble const  * v) {
	static const auto glVertexAttrib3dvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLdouble const  *)>(getProcAddress("glVertexAttrib3dvARB"));
	assert(glVertexAttrib3dvARB_ != nullptr);
	return glVertexAttrib3dvARB_(index, v);
}
void glVertexAttrib3fARB(GLuint index, GLfloat x, GLfloat y, GLfloat z) {
	static const auto glVertexAttrib3fARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLfloat, GLfloat, GLfloat)>(getProcAddress("glVertexAttrib3fARB"));
	assert(glVertexAttrib3fARB_ != nullptr);
	return glVertexAttrib3fARB_(index, x, y, z);
}
void glVertexAttrib3fvARB(GLuint index, GLfloat const  * v) {
	static const auto glVertexAttrib3fvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLfloat const  *)>(getProcAddress("glVertexAttrib3fvARB"));
	assert(glVertexAttrib3fvARB_ != nullptr);
	return glVertexAttrib3fvARB_(index, v);
}
void glVertexAttrib3sARB(GLuint index, GLshort x, GLshort y, GLshort z) {
	static const auto glVertexAttrib3sARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLshort, GLshort, GLshort)>(getProcAddress("glVertexAttrib3sARB"));
	assert(glVertexAttrib3sARB_ != nullptr);
	return glVertexAttrib3sARB_(index, x, y, z);
}
void glVertexAttrib3svARB(GLuint index, GLshort const  * v) {
	static const auto glVertexAttrib3svARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLshort const  *)>(getProcAddress("glVertexAttrib3svARB"));
	assert(glVertexAttrib3svARB_ != nullptr);
	return glVertexAttrib3svARB_(index, v);
}
void glVertexAttrib4NbvARB(GLuint index, GLbyte const  * v) {
	static const auto glVertexAttrib4NbvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLbyte const  *)>(getProcAddress("glVertexAttrib4NbvARB"));
	assert(glVertexAttrib4NbvARB_ != nullptr);
	return glVertexAttrib4NbvARB_(index, v);
}
void glVertexAttrib4NivARB(GLuint index, GLint const  * v) {
	static const auto glVertexAttrib4NivARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint const  *)>(getProcAddress("glVertexAttrib4NivARB"));
	assert(glVertexAttrib4NivARB_ != nullptr);
	return glVertexAttrib4NivARB_(index, v);
}
void glVertexAttrib4NsvARB(GLuint index, GLshort const  * v) {
	static const auto glVertexAttrib4NsvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLshort const  *)>(getProcAddress("glVertexAttrib4NsvARB"));
	assert(glVertexAttrib4NsvARB_ != nullptr);
	return glVertexAttrib4NsvARB_(index, v);
}
void glVertexAttrib4NubARB(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w) {
	static const auto glVertexAttrib4NubARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLubyte, GLubyte, GLubyte, GLubyte)>(getProcAddress("glVertexAttrib4NubARB"));
	assert(glVertexAttrib4NubARB_ != nullptr);
	return glVertexAttrib4NubARB_(index, x, y, z, w);
}
void glVertexAttrib4NubvARB(GLuint index, GLubyte const  * v) {
	static const auto glVertexAttrib4NubvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLubyte const  *)>(getProcAddress("glVertexAttrib4NubvARB"));
	assert(glVertexAttrib4NubvARB_ != nullptr);
	return glVertexAttrib4NubvARB_(index, v);
}
void glVertexAttrib4NuivARB(GLuint index, GLuint const  * v) {
	static const auto glVertexAttrib4NuivARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint const  *)>(getProcAddress("glVertexAttrib4NuivARB"));
	assert(glVertexAttrib4NuivARB_ != nullptr);
	return glVertexAttrib4NuivARB_(index, v);
}
void glVertexAttrib4NusvARB(GLuint index, GLushort const  * v) {
	static const auto glVertexAttrib4NusvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLushort const  *)>(getProcAddress("glVertexAttrib4NusvARB"));
	assert(glVertexAttrib4NusvARB_ != nullptr);
	return glVertexAttrib4NusvARB_(index, v);
}
void glVertexAttrib4bvARB(GLuint index, GLbyte const  * v) {
	static const auto glVertexAttrib4bvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLbyte const  *)>(getProcAddress("glVertexAttrib4bvARB"));
	assert(glVertexAttrib4bvARB_ != nullptr);
	return glVertexAttrib4bvARB_(index, v);
}
void glVertexAttrib4dARB(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
	static const auto glVertexAttrib4dARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLdouble, GLdouble, GLdouble, GLdouble)>(getProcAddress("glVertexAttrib4dARB"));
	assert(glVertexAttrib4dARB_ != nullptr);
	return glVertexAttrib4dARB_(index, x, y, z, w);
}
void glVertexAttrib4dvARB(GLuint index, GLdouble const  * v) {
	static const auto glVertexAttrib4dvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLdouble const  *)>(getProcAddress("glVertexAttrib4dvARB"));
	assert(glVertexAttrib4dvARB_ != nullptr);
	return glVertexAttrib4dvARB_(index, v);
}
void glVertexAttrib4fARB(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
	static const auto glVertexAttrib4fARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat)>(getProcAddress("glVertexAttrib4fARB"));
	assert(glVertexAttrib4fARB_ != nullptr);
	return glVertexAttrib4fARB_(index, x, y, z, w);
}
void glVertexAttrib4fvARB(GLuint index, GLfloat const  * v) {
	static const auto glVertexAttrib4fvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLfloat const  *)>(getProcAddress("glVertexAttrib4fvARB"));
	assert(glVertexAttrib4fvARB_ != nullptr);
	return glVertexAttrib4fvARB_(index, v);
}
void glVertexAttrib4ivARB(GLuint index, GLint const  * v) {
	static const auto glVertexAttrib4ivARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint const  *)>(getProcAddress("glVertexAttrib4ivARB"));
	assert(glVertexAttrib4ivARB_ != nullptr);
	return glVertexAttrib4ivARB_(index, v);
}
void glVertexAttrib4sARB(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w) {
	static const auto glVertexAttrib4sARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLshort, GLshort, GLshort, GLshort)>(getProcAddress("glVertexAttrib4sARB"));
	assert(glVertexAttrib4sARB_ != nullptr);
	return glVertexAttrib4sARB_(index, x, y, z, w);
}
void glVertexAttrib4svARB(GLuint index, GLshort const  * v) {
	static const auto glVertexAttrib4svARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLshort const  *)>(getProcAddress("glVertexAttrib4svARB"));
	assert(glVertexAttrib4svARB_ != nullptr);
	return glVertexAttrib4svARB_(index, v);
}
void glVertexAttrib4ubvARB(GLuint index, GLubyte const  * v) {
	static const auto glVertexAttrib4ubvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLubyte const  *)>(getProcAddress("glVertexAttrib4ubvARB"));
	assert(glVertexAttrib4ubvARB_ != nullptr);
	return glVertexAttrib4ubvARB_(index, v);
}
void glVertexAttrib4uivARB(GLuint index, GLuint const  * v) {
	static const auto glVertexAttrib4uivARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint const  *)>(getProcAddress("glVertexAttrib4uivARB"));
	assert(glVertexAttrib4uivARB_ != nullptr);
	return glVertexAttrib4uivARB_(index, v);
}
void glVertexAttrib4usvARB(GLuint index, GLushort const  * v) {
	static const auto glVertexAttrib4usvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLushort const  *)>(getProcAddress("glVertexAttrib4usvARB"));
	assert(glVertexAttrib4usvARB_ != nullptr);
	return glVertexAttrib4usvARB_(index, v);
}
void glVertexAttribPointerARB(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void * pointer) {
	static const auto glVertexAttribPointerARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLenum, GLboolean, GLsizei, const void *)>(getProcAddress("glVertexAttribPointerARB"));
	assert(glVertexAttribPointerARB_ != nullptr);
	return glVertexAttribPointerARB_(index, size, type, normalized, stride, pointer);
}
void glEnableVertexAttribArrayARB(GLuint index) {
	static const auto glEnableVertexAttribArrayARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint)>(getProcAddress("glEnableVertexAttribArrayARB"));
	assert(glEnableVertexAttribArrayARB_ != nullptr);
	return glEnableVertexAttribArrayARB_(index);
}
void glDisableVertexAttribArrayARB(GLuint index) {
	static const auto glDisableVertexAttribArrayARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint)>(getProcAddress("glDisableVertexAttribArrayARB"));
	assert(glDisableVertexAttribArrayARB_ != nullptr);
	return glDisableVertexAttribArrayARB_(index);
}
void glGetVertexAttribdvARB(GLuint index, GLenum pname, GLdouble * params) {
	static const auto glGetVertexAttribdvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLdouble *)>(getProcAddress("glGetVertexAttribdvARB"));
	assert(glGetVertexAttribdvARB_ != nullptr);
	return glGetVertexAttribdvARB_(index, pname, params);
}
void glGetVertexAttribfvARB(GLuint index, GLenum pname, GLfloat * params) {
	static const auto glGetVertexAttribfvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLfloat *)>(getProcAddress("glGetVertexAttribfvARB"));
	assert(glGetVertexAttribfvARB_ != nullptr);
	return glGetVertexAttribfvARB_(index, pname, params);
}
void glGetVertexAttribivARB(GLuint index, GLenum pname, GLint * params) {
	static const auto glGetVertexAttribivARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint *)>(getProcAddress("glGetVertexAttribivARB"));
	assert(glGetVertexAttribivARB_ != nullptr);
	return glGetVertexAttribivARB_(index, pname, params);
}
void glGetVertexAttribPointervARB(GLuint index, GLenum pname, void ** pointer) {
	static const auto glGetVertexAttribPointervARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, void **)>(getProcAddress("glGetVertexAttribPointervARB"));
	assert(glGetVertexAttribPointervARB_ != nullptr);
	return glGetVertexAttribPointervARB_(index, pname, pointer);
}
void glBindAttribLocationARB(GLhandleARB programObj, GLuint index, GLcharARB const  * name) {
	static const auto glBindAttribLocationARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLhandleARB, GLuint, GLcharARB const  *)>(getProcAddress("glBindAttribLocationARB"));
	assert(glBindAttribLocationARB_ != nullptr);
	return glBindAttribLocationARB_(programObj, index, name);
}
void glGetActiveAttribARB(GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei * length, GLint * size, GLenum * type, GLcharARB * name) {
	static const auto glGetActiveAttribARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLhandleARB, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLcharARB *)>(getProcAddress("glGetActiveAttribARB"));
	assert(glGetActiveAttribARB_ != nullptr);
	return glGetActiveAttribARB_(programObj, index, maxLength, length, size, type, name);
}
GLint glGetAttribLocationARB(GLhandleARB programObj, GLcharARB const  * name) {
	static const auto glGetAttribLocationARB_ = reinterpret_cast<GLint(GL_APIENTRYP)(GLhandleARB, GLcharARB const  *)>(getProcAddress("glGetAttribLocationARB"));
	assert(glGetAttribLocationARB_ != nullptr);
	return glGetAttribLocationARB_(programObj, name);
}
void glVertexAttribP1ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) {
	static const auto glVertexAttribP1ui_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLboolean, GLuint)>(getProcAddress("glVertexAttribP1ui"));
	assert(glVertexAttribP1ui_ != nullptr);
	return glVertexAttribP1ui_(index, type, normalized, value);
}
void glVertexAttribP1uiv(GLuint index, GLenum type, GLboolean normalized, GLuint const  * value) {
	static const auto glVertexAttribP1uiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLboolean, GLuint const  *)>(getProcAddress("glVertexAttribP1uiv"));
	assert(glVertexAttribP1uiv_ != nullptr);
	return glVertexAttribP1uiv_(index, type, normalized, value);
}
void glVertexAttribP2ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) {
	static const auto glVertexAttribP2ui_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLboolean, GLuint)>(getProcAddress("glVertexAttribP2ui"));
	assert(glVertexAttribP2ui_ != nullptr);
	return glVertexAttribP2ui_(index, type, normalized, value);
}
void glVertexAttribP2uiv(GLuint index, GLenum type, GLboolean normalized, GLuint const  * value) {
	static const auto glVertexAttribP2uiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLboolean, GLuint const  *)>(getProcAddress("glVertexAttribP2uiv"));
	assert(glVertexAttribP2uiv_ != nullptr);
	return glVertexAttribP2uiv_(index, type, normalized, value);
}
void glVertexAttribP3ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) {
	static const auto glVertexAttribP3ui_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLboolean, GLuint)>(getProcAddress("glVertexAttribP3ui"));
	assert(glVertexAttribP3ui_ != nullptr);
	return glVertexAttribP3ui_(index, type, normalized, value);
}
void glVertexAttribP3uiv(GLuint index, GLenum type, GLboolean normalized, GLuint const  * value) {
	static const auto glVertexAttribP3uiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLboolean, GLuint const  *)>(getProcAddress("glVertexAttribP3uiv"));
	assert(glVertexAttribP3uiv_ != nullptr);
	return glVertexAttribP3uiv_(index, type, normalized, value);
}
void glVertexAttribP4ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) {
	static const auto glVertexAttribP4ui_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLboolean, GLuint)>(getProcAddress("glVertexAttribP4ui"));
	assert(glVertexAttribP4ui_ != nullptr);
	return glVertexAttribP4ui_(index, type, normalized, value);
}
void glVertexAttribP4uiv(GLuint index, GLenum type, GLboolean normalized, GLuint const  * value) {
	static const auto glVertexAttribP4uiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLboolean, GLuint const  *)>(getProcAddress("glVertexAttribP4uiv"));
	assert(glVertexAttribP4uiv_ != nullptr);
	return glVertexAttribP4uiv_(index, type, normalized, value);
}
void glVertexP2ui(GLenum type, GLuint value) {
	static const auto glVertexP2ui_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint)>(getProcAddress("glVertexP2ui"));
	assert(glVertexP2ui_ != nullptr);
	return glVertexP2ui_(type, value);
}
void glVertexP2uiv(GLenum type, GLuint const  * value) {
	static const auto glVertexP2uiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint const  *)>(getProcAddress("glVertexP2uiv"));
	assert(glVertexP2uiv_ != nullptr);
	return glVertexP2uiv_(type, value);
}
void glVertexP3ui(GLenum type, GLuint value) {
	static const auto glVertexP3ui_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint)>(getProcAddress("glVertexP3ui"));
	assert(glVertexP3ui_ != nullptr);
	return glVertexP3ui_(type, value);
}
void glVertexP3uiv(GLenum type, GLuint const  * value) {
	static const auto glVertexP3uiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint const  *)>(getProcAddress("glVertexP3uiv"));
	assert(glVertexP3uiv_ != nullptr);
	return glVertexP3uiv_(type, value);
}
void glVertexP4ui(GLenum type, GLuint value) {
	static const auto glVertexP4ui_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint)>(getProcAddress("glVertexP4ui"));
	assert(glVertexP4ui_ != nullptr);
	return glVertexP4ui_(type, value);
}
void glVertexP4uiv(GLenum type, GLuint const  * value) {
	static const auto glVertexP4uiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint const  *)>(getProcAddress("glVertexP4uiv"));
	assert(glVertexP4uiv_ != nullptr);
	return glVertexP4uiv_(type, value);
}
void glTexCoordP1ui(GLenum type, GLuint coords) {
	static const auto glTexCoordP1ui_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint)>(getProcAddress("glTexCoordP1ui"));
	assert(glTexCoordP1ui_ != nullptr);
	return glTexCoordP1ui_(type, coords);
}
void glTexCoordP1uiv(GLenum type, GLuint const  * coords) {
	static const auto glTexCoordP1uiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint const  *)>(getProcAddress("glTexCoordP1uiv"));
	assert(glTexCoordP1uiv_ != nullptr);
	return glTexCoordP1uiv_(type, coords);
}
void glTexCoordP2ui(GLenum type, GLuint coords) {
	static const auto glTexCoordP2ui_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint)>(getProcAddress("glTexCoordP2ui"));
	assert(glTexCoordP2ui_ != nullptr);
	return glTexCoordP2ui_(type, coords);
}
void glTexCoordP2uiv(GLenum type, GLuint const  * coords) {
	static const auto glTexCoordP2uiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint const  *)>(getProcAddress("glTexCoordP2uiv"));
	assert(glTexCoordP2uiv_ != nullptr);
	return glTexCoordP2uiv_(type, coords);
}
void glTexCoordP3ui(GLenum type, GLuint coords) {
	static const auto glTexCoordP3ui_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint)>(getProcAddress("glTexCoordP3ui"));
	assert(glTexCoordP3ui_ != nullptr);
	return glTexCoordP3ui_(type, coords);
}
void glTexCoordP3uiv(GLenum type, GLuint const  * coords) {
	static const auto glTexCoordP3uiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint const  *)>(getProcAddress("glTexCoordP3uiv"));
	assert(glTexCoordP3uiv_ != nullptr);
	return glTexCoordP3uiv_(type, coords);
}
void glTexCoordP4ui(GLenum type, GLuint coords) {
	static const auto glTexCoordP4ui_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint)>(getProcAddress("glTexCoordP4ui"));
	assert(glTexCoordP4ui_ != nullptr);
	return glTexCoordP4ui_(type, coords);
}
void glTexCoordP4uiv(GLenum type, GLuint const  * coords) {
	static const auto glTexCoordP4uiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint const  *)>(getProcAddress("glTexCoordP4uiv"));
	assert(glTexCoordP4uiv_ != nullptr);
	return glTexCoordP4uiv_(type, coords);
}
void glMultiTexCoordP1ui(GLenum texture, GLenum type, GLuint coords) {
	static const auto glMultiTexCoordP1ui_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLuint)>(getProcAddress("glMultiTexCoordP1ui"));
	assert(glMultiTexCoordP1ui_ != nullptr);
	return glMultiTexCoordP1ui_(texture, type, coords);
}
void glMultiTexCoordP1uiv(GLenum texture, GLenum type, GLuint const  * coords) {
	static const auto glMultiTexCoordP1uiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLuint const  *)>(getProcAddress("glMultiTexCoordP1uiv"));
	assert(glMultiTexCoordP1uiv_ != nullptr);
	return glMultiTexCoordP1uiv_(texture, type, coords);
}
void glMultiTexCoordP2ui(GLenum texture, GLenum type, GLuint coords) {
	static const auto glMultiTexCoordP2ui_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLuint)>(getProcAddress("glMultiTexCoordP2ui"));
	assert(glMultiTexCoordP2ui_ != nullptr);
	return glMultiTexCoordP2ui_(texture, type, coords);
}
void glMultiTexCoordP2uiv(GLenum texture, GLenum type, GLuint const  * coords) {
	static const auto glMultiTexCoordP2uiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLuint const  *)>(getProcAddress("glMultiTexCoordP2uiv"));
	assert(glMultiTexCoordP2uiv_ != nullptr);
	return glMultiTexCoordP2uiv_(texture, type, coords);
}
void glMultiTexCoordP3ui(GLenum texture, GLenum type, GLuint coords) {
	static const auto glMultiTexCoordP3ui_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLuint)>(getProcAddress("glMultiTexCoordP3ui"));
	assert(glMultiTexCoordP3ui_ != nullptr);
	return glMultiTexCoordP3ui_(texture, type, coords);
}
void glMultiTexCoordP3uiv(GLenum texture, GLenum type, GLuint const  * coords) {
	static const auto glMultiTexCoordP3uiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLuint const  *)>(getProcAddress("glMultiTexCoordP3uiv"));
	assert(glMultiTexCoordP3uiv_ != nullptr);
	return glMultiTexCoordP3uiv_(texture, type, coords);
}
void glMultiTexCoordP4ui(GLenum texture, GLenum type, GLuint coords) {
	static const auto glMultiTexCoordP4ui_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLuint)>(getProcAddress("glMultiTexCoordP4ui"));
	assert(glMultiTexCoordP4ui_ != nullptr);
	return glMultiTexCoordP4ui_(texture, type, coords);
}
void glMultiTexCoordP4uiv(GLenum texture, GLenum type, GLuint const  * coords) {
	static const auto glMultiTexCoordP4uiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLuint const  *)>(getProcAddress("glMultiTexCoordP4uiv"));
	assert(glMultiTexCoordP4uiv_ != nullptr);
	return glMultiTexCoordP4uiv_(texture, type, coords);
}
void glNormalP3ui(GLenum type, GLuint coords) {
	static const auto glNormalP3ui_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint)>(getProcAddress("glNormalP3ui"));
	assert(glNormalP3ui_ != nullptr);
	return glNormalP3ui_(type, coords);
}
void glNormalP3uiv(GLenum type, GLuint const  * coords) {
	static const auto glNormalP3uiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint const  *)>(getProcAddress("glNormalP3uiv"));
	assert(glNormalP3uiv_ != nullptr);
	return glNormalP3uiv_(type, coords);
}
void glColorP3ui(GLenum type, GLuint color) {
	static const auto glColorP3ui_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint)>(getProcAddress("glColorP3ui"));
	assert(glColorP3ui_ != nullptr);
	return glColorP3ui_(type, color);
}
void glColorP3uiv(GLenum type, GLuint const  * color) {
	static const auto glColorP3uiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint const  *)>(getProcAddress("glColorP3uiv"));
	assert(glColorP3uiv_ != nullptr);
	return glColorP3uiv_(type, color);
}
void glColorP4ui(GLenum type, GLuint color) {
	static const auto glColorP4ui_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint)>(getProcAddress("glColorP4ui"));
	assert(glColorP4ui_ != nullptr);
	return glColorP4ui_(type, color);
}
void glColorP4uiv(GLenum type, GLuint const  * color) {
	static const auto glColorP4uiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint const  *)>(getProcAddress("glColorP4uiv"));
	assert(glColorP4uiv_ != nullptr);
	return glColorP4uiv_(type, color);
}
void glSecondaryColorP3ui(GLenum type, GLuint color) {
	static const auto glSecondaryColorP3ui_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint)>(getProcAddress("glSecondaryColorP3ui"));
	assert(glSecondaryColorP3ui_ != nullptr);
	return glSecondaryColorP3ui_(type, color);
}
void glSecondaryColorP3uiv(GLenum type, GLuint const  * color) {
	static const auto glSecondaryColorP3uiv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint const  *)>(getProcAddress("glSecondaryColorP3uiv"));
	assert(glSecondaryColorP3uiv_ != nullptr);
	return glSecondaryColorP3uiv_(type, color);
}
void glViewportArrayv(GLuint first, GLsizei count, GLfloat const  * v) {
	static const auto glViewportArrayv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLsizei, GLfloat const  *)>(getProcAddress("glViewportArrayv"));
	assert(glViewportArrayv_ != nullptr);
	return glViewportArrayv_(first, count, v);
}
void glViewportIndexedf(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h) {
	static const auto glViewportIndexedf_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat)>(getProcAddress("glViewportIndexedf"));
	assert(glViewportIndexedf_ != nullptr);
	return glViewportIndexedf_(index, x, y, w, h);
}
void glViewportIndexedfv(GLuint index, GLfloat const  * v) {
	static const auto glViewportIndexedfv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLfloat const  *)>(getProcAddress("glViewportIndexedfv"));
	assert(glViewportIndexedfv_ != nullptr);
	return glViewportIndexedfv_(index, v);
}
void glScissorArrayv(GLuint first, GLsizei count, GLint const  * v) {
	static const auto glScissorArrayv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLsizei, GLint const  *)>(getProcAddress("glScissorArrayv"));
	assert(glScissorArrayv_ != nullptr);
	return glScissorArrayv_(first, count, v);
}
void glScissorIndexed(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height) {
	static const auto glScissorIndexed_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLint, GLsizei, GLsizei)>(getProcAddress("glScissorIndexed"));
	assert(glScissorIndexed_ != nullptr);
	return glScissorIndexed_(index, left, bottom, width, height);
}
void glScissorIndexedv(GLuint index, GLint const  * v) {
	static const auto glScissorIndexedv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint const  *)>(getProcAddress("glScissorIndexedv"));
	assert(glScissorIndexedv_ != nullptr);
	return glScissorIndexedv_(index, v);
}
void glDepthRangeArrayv(GLuint first, GLsizei count, GLdouble const  * v) {
	static const auto glDepthRangeArrayv_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLsizei, GLdouble const  *)>(getProcAddress("glDepthRangeArrayv"));
	assert(glDepthRangeArrayv_ != nullptr);
	return glDepthRangeArrayv_(first, count, v);
}
void glDepthRangeIndexed(GLuint index, GLdouble n, GLdouble f) {
	static const auto glDepthRangeIndexed_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLdouble, GLdouble)>(getProcAddress("glDepthRangeIndexed"));
	assert(glDepthRangeIndexed_ != nullptr);
	return glDepthRangeIndexed_(index, n, f);
}
void glGetFloati_v(GLenum target, GLuint index, GLfloat * data) {
	static const auto glGetFloati_v_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint, GLfloat *)>(getProcAddress("glGetFloati_v"));
	assert(glGetFloati_v_ != nullptr);
	return glGetFloati_v_(target, index, data);
}
void glGetDoublei_v(GLenum target, GLuint index, GLdouble * data) {
	static const auto glGetDoublei_v_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint, GLdouble *)>(getProcAddress("glGetDoublei_v"));
	assert(glGetDoublei_v_ != nullptr);
	return glGetDoublei_v_(target, index, data);
}
void glWindowPos2dARB(GLdouble x, GLdouble y) {
	static const auto glWindowPos2dARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble, GLdouble)>(getProcAddress("glWindowPos2dARB"));
	assert(glWindowPos2dARB_ != nullptr);
	return glWindowPos2dARB_(x, y);
}
void glWindowPos2dvARB(GLdouble const  * v) {
	static const auto glWindowPos2dvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble const  *)>(getProcAddress("glWindowPos2dvARB"));
	assert(glWindowPos2dvARB_ != nullptr);
	return glWindowPos2dvARB_(v);
}
void glWindowPos2fARB(GLfloat x, GLfloat y) {
	static const auto glWindowPos2fARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat, GLfloat)>(getProcAddress("glWindowPos2fARB"));
	assert(glWindowPos2fARB_ != nullptr);
	return glWindowPos2fARB_(x, y);
}
void glWindowPos2fvARB(GLfloat const  * v) {
	static const auto glWindowPos2fvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat const  *)>(getProcAddress("glWindowPos2fvARB"));
	assert(glWindowPos2fvARB_ != nullptr);
	return glWindowPos2fvARB_(v);
}
void glWindowPos2iARB(GLint x, GLint y) {
	static const auto glWindowPos2iARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLint)>(getProcAddress("glWindowPos2iARB"));
	assert(glWindowPos2iARB_ != nullptr);
	return glWindowPos2iARB_(x, y);
}
void glWindowPos2ivARB(GLint const  * v) {
	static const auto glWindowPos2ivARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint const  *)>(getProcAddress("glWindowPos2ivARB"));
	assert(glWindowPos2ivARB_ != nullptr);
	return glWindowPos2ivARB_(v);
}
void glWindowPos2sARB(GLshort x, GLshort y) {
	static const auto glWindowPos2sARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLshort, GLshort)>(getProcAddress("glWindowPos2sARB"));
	assert(glWindowPos2sARB_ != nullptr);
	return glWindowPos2sARB_(x, y);
}
void glWindowPos2svARB(GLshort const  * v) {
	static const auto glWindowPos2svARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLshort const  *)>(getProcAddress("glWindowPos2svARB"));
	assert(glWindowPos2svARB_ != nullptr);
	return glWindowPos2svARB_(v);
}
void glWindowPos3dARB(GLdouble x, GLdouble y, GLdouble z) {
	static const auto glWindowPos3dARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble, GLdouble, GLdouble)>(getProcAddress("glWindowPos3dARB"));
	assert(glWindowPos3dARB_ != nullptr);
	return glWindowPos3dARB_(x, y, z);
}
void glWindowPos3dvARB(GLdouble const  * v) {
	static const auto glWindowPos3dvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble const  *)>(getProcAddress("glWindowPos3dvARB"));
	assert(glWindowPos3dvARB_ != nullptr);
	return glWindowPos3dvARB_(v);
}
void glWindowPos3fARB(GLfloat x, GLfloat y, GLfloat z) {
	static const auto glWindowPos3fARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat, GLfloat, GLfloat)>(getProcAddress("glWindowPos3fARB"));
	assert(glWindowPos3fARB_ != nullptr);
	return glWindowPos3fARB_(x, y, z);
}
void glWindowPos3fvARB(GLfloat const  * v) {
	static const auto glWindowPos3fvARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat const  *)>(getProcAddress("glWindowPos3fvARB"));
	assert(glWindowPos3fvARB_ != nullptr);
	return glWindowPos3fvARB_(v);
}
void glWindowPos3iARB(GLint x, GLint y, GLint z) {
	static const auto glWindowPos3iARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLint, GLint)>(getProcAddress("glWindowPos3iARB"));
	assert(glWindowPos3iARB_ != nullptr);
	return glWindowPos3iARB_(x, y, z);
}
void glWindowPos3ivARB(GLint const  * v) {
	static const auto glWindowPos3ivARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLint const  *)>(getProcAddress("glWindowPos3ivARB"));
	assert(glWindowPos3ivARB_ != nullptr);
	return glWindowPos3ivARB_(v);
}
void glWindowPos3sARB(GLshort x, GLshort y, GLshort z) {
	static const auto glWindowPos3sARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLshort, GLshort, GLshort)>(getProcAddress("glWindowPos3sARB"));
	assert(glWindowPos3sARB_ != nullptr);
	return glWindowPos3sARB_(x, y, z);
}
void glWindowPos3svARB(GLshort const  * v) {
	static const auto glWindowPos3svARB_ = reinterpret_cast<void(GL_APIENTRYP)(GLshort const  *)>(getProcAddress("glWindowPos3svARB"));
	assert(glWindowPos3svARB_ != nullptr);
	return glWindowPos3svARB_(v);
}
void glEGLImageTargetTexStorageEXT(GLenum target, GLeglImageOES image, GLint const * attrib_list) {
	static const auto glEGLImageTargetTexStorageEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLeglImageOES, GLint const *)>(getProcAddress("glEGLImageTargetTexStorageEXT"));
	assert(glEGLImageTargetTexStorageEXT_ != nullptr);
	return glEGLImageTargetTexStorageEXT_(target, image, attrib_list);
}
void glEGLImageTargetTextureStorageEXT(GLuint texture, GLeglImageOES image, GLint const * attrib_list) {
	static const auto glEGLImageTargetTextureStorageEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLeglImageOES, GLint const *)>(getProcAddress("glEGLImageTargetTextureStorageEXT"));
	assert(glEGLImageTargetTextureStorageEXT_ != nullptr);
	return glEGLImageTargetTextureStorageEXT_(texture, image, attrib_list);
}
void glUniformBufferEXT(GLuint program, GLint location, GLuint buffer) {
	static const auto glUniformBufferEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLuint)>(getProcAddress("glUniformBufferEXT"));
	assert(glUniformBufferEXT_ != nullptr);
	return glUniformBufferEXT_(program, location, buffer);
}
GLint glGetUniformBufferSizeEXT(GLuint program, GLint location) {
	static const auto glGetUniformBufferSizeEXT_ = reinterpret_cast<GLint(GL_APIENTRYP)(GLuint, GLint)>(getProcAddress("glGetUniformBufferSizeEXT"));
	assert(glGetUniformBufferSizeEXT_ != nullptr);
	return glGetUniformBufferSizeEXT_(program, location);
}
GLintptr glGetUniformOffsetEXT(GLuint program, GLint location) {
	static const auto glGetUniformOffsetEXT_ = reinterpret_cast<GLintptr(GL_APIENTRYP)(GLuint, GLint)>(getProcAddress("glGetUniformOffsetEXT"));
	assert(glGetUniformOffsetEXT_ != nullptr);
	return glGetUniformOffsetEXT_(program, location);
}
void glBlendColorEXT(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
	static const auto glBlendColorEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat, GLfloat, GLfloat, GLfloat)>(getProcAddress("glBlendColorEXT"));
	assert(glBlendColorEXT_ != nullptr);
	return glBlendColorEXT_(red, green, blue, alpha);
}
void glBlendEquationSeparateEXT(GLenum modeRGB, GLenum modeAlpha) {
	static const auto glBlendEquationSeparateEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum)>(getProcAddress("glBlendEquationSeparateEXT"));
	assert(glBlendEquationSeparateEXT_ != nullptr);
	return glBlendEquationSeparateEXT_(modeRGB, modeAlpha);
}
void glBlendFuncSeparateEXT(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) {
	static const auto glBlendFuncSeparateEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLenum)>(getProcAddress("glBlendFuncSeparateEXT"));
	assert(glBlendFuncSeparateEXT_ != nullptr);
	return glBlendFuncSeparateEXT_(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
}
void glBlendEquationEXT(GLenum mode) {
	static const auto glBlendEquationEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glBlendEquationEXT"));
	assert(glBlendEquationEXT_ != nullptr);
	return glBlendEquationEXT_(mode);
}
void glColorSubTableEXT(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const void * data) {
	static const auto glColorSubTableEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, GLsizei, GLenum, GLenum, const void *)>(getProcAddress("glColorSubTableEXT"));
	assert(glColorSubTableEXT_ != nullptr);
	return glColorSubTableEXT_(target, start, count, format, type, data);
}
void glCopyColorSubTableEXT(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width) {
	static const auto glCopyColorSubTableEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, GLint, GLint, GLsizei)>(getProcAddress("glCopyColorSubTableEXT"));
	assert(glCopyColorSubTableEXT_ != nullptr);
	return glCopyColorSubTableEXT_(target, start, x, y, width);
}
void glLockArraysEXT(GLint first, GLsizei count) {
	static const auto glLockArraysEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei)>(getProcAddress("glLockArraysEXT"));
	assert(glLockArraysEXT_ != nullptr);
	return glLockArraysEXT_(first, count);
}
void glUnlockArraysEXT() {
	static const auto glUnlockArraysEXT_ = reinterpret_cast<void(GL_APIENTRYP)()>(getProcAddress("glUnlockArraysEXT"));
	assert(glUnlockArraysEXT_ != nullptr);
	return glUnlockArraysEXT_();
}
void glConvolutionFilter1DEXT(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void * image) {
	static const auto glConvolutionFilter1DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLsizei, GLenum, GLenum, const void *)>(getProcAddress("glConvolutionFilter1DEXT"));
	assert(glConvolutionFilter1DEXT_ != nullptr);
	return glConvolutionFilter1DEXT_(target, internalformat, width, format, type, image);
}
void glConvolutionFilter2DEXT(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * image) {
	static const auto glConvolutionFilter2DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const void *)>(getProcAddress("glConvolutionFilter2DEXT"));
	assert(glConvolutionFilter2DEXT_ != nullptr);
	return glConvolutionFilter2DEXT_(target, internalformat, width, height, format, type, image);
}
void glConvolutionParameterfEXT(GLenum target, GLenum pname, GLfloat params) {
	static const auto glConvolutionParameterfEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfloat)>(getProcAddress("glConvolutionParameterfEXT"));
	assert(glConvolutionParameterfEXT_ != nullptr);
	return glConvolutionParameterfEXT_(target, pname, params);
}
void glConvolutionParameterfvEXT(GLenum target, GLenum pname, GLfloat const  * params) {
	static const auto glConvolutionParameterfvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfloat const  *)>(getProcAddress("glConvolutionParameterfvEXT"));
	assert(glConvolutionParameterfvEXT_ != nullptr);
	return glConvolutionParameterfvEXT_(target, pname, params);
}
void glConvolutionParameteriEXT(GLenum target, GLenum pname, GLint params) {
	static const auto glConvolutionParameteriEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint)>(getProcAddress("glConvolutionParameteriEXT"));
	assert(glConvolutionParameteriEXT_ != nullptr);
	return glConvolutionParameteriEXT_(target, pname, params);
}
void glConvolutionParameterivEXT(GLenum target, GLenum pname, GLint const  * params) {
	static const auto glConvolutionParameterivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint const  *)>(getProcAddress("glConvolutionParameterivEXT"));
	assert(glConvolutionParameterivEXT_ != nullptr);
	return glConvolutionParameterivEXT_(target, pname, params);
}
void glCopyConvolutionFilter1DEXT(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width) {
	static const auto glCopyConvolutionFilter1DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint, GLint, GLsizei)>(getProcAddress("glCopyConvolutionFilter1DEXT"));
	assert(glCopyConvolutionFilter1DEXT_ != nullptr);
	return glCopyConvolutionFilter1DEXT_(target, internalformat, x, y, width);
}
void glCopyConvolutionFilter2DEXT(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height) {
	static const auto glCopyConvolutionFilter2DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint, GLint, GLsizei, GLsizei)>(getProcAddress("glCopyConvolutionFilter2DEXT"));
	assert(glCopyConvolutionFilter2DEXT_ != nullptr);
	return glCopyConvolutionFilter2DEXT_(target, internalformat, x, y, width, height);
}
void glGetConvolutionFilterEXT(GLenum target, GLenum format, GLenum type, void * image) {
	static const auto glGetConvolutionFilterEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, void *)>(getProcAddress("glGetConvolutionFilterEXT"));
	assert(glGetConvolutionFilterEXT_ != nullptr);
	return glGetConvolutionFilterEXT_(target, format, type, image);
}
void glGetConvolutionParameterfvEXT(GLenum target, GLenum pname, GLfloat * params) {
	static const auto glGetConvolutionParameterfvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfloat *)>(getProcAddress("glGetConvolutionParameterfvEXT"));
	assert(glGetConvolutionParameterfvEXT_ != nullptr);
	return glGetConvolutionParameterfvEXT_(target, pname, params);
}
void glGetConvolutionParameterivEXT(GLenum target, GLenum pname, GLint * params) {
	static const auto glGetConvolutionParameterivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint *)>(getProcAddress("glGetConvolutionParameterivEXT"));
	assert(glGetConvolutionParameterivEXT_ != nullptr);
	return glGetConvolutionParameterivEXT_(target, pname, params);
}
void glGetSeparableFilterEXT(GLenum target, GLenum format, GLenum type, void * row, void * column, void * span) {
	static const auto glGetSeparableFilterEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, void *, void *, void *)>(getProcAddress("glGetSeparableFilterEXT"));
	assert(glGetSeparableFilterEXT_ != nullptr);
	return glGetSeparableFilterEXT_(target, format, type, row, column, span);
}
void glSeparableFilter2DEXT(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * row, const void * column) {
	static const auto glSeparableFilter2DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const void *, const void *)>(getProcAddress("glSeparableFilter2DEXT"));
	assert(glSeparableFilter2DEXT_ != nullptr);
	return glSeparableFilter2DEXT_(target, internalformat, width, height, format, type, row, column);
}
void glTangent3bEXT(GLbyte tx, GLbyte ty, GLbyte tz) {
	static const auto glTangent3bEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLbyte, GLbyte, GLbyte)>(getProcAddress("glTangent3bEXT"));
	assert(glTangent3bEXT_ != nullptr);
	return glTangent3bEXT_(tx, ty, tz);
}
void glTangent3bvEXT(GLbyte const  * v) {
	static const auto glTangent3bvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLbyte const  *)>(getProcAddress("glTangent3bvEXT"));
	assert(glTangent3bvEXT_ != nullptr);
	return glTangent3bvEXT_(v);
}
void glTangent3dEXT(GLdouble tx, GLdouble ty, GLdouble tz) {
	static const auto glTangent3dEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble, GLdouble, GLdouble)>(getProcAddress("glTangent3dEXT"));
	assert(glTangent3dEXT_ != nullptr);
	return glTangent3dEXT_(tx, ty, tz);
}
void glTangent3dvEXT(GLdouble const  * v) {
	static const auto glTangent3dvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble const  *)>(getProcAddress("glTangent3dvEXT"));
	assert(glTangent3dvEXT_ != nullptr);
	return glTangent3dvEXT_(v);
}
void glTangent3fEXT(GLfloat tx, GLfloat ty, GLfloat tz) {
	static const auto glTangent3fEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat, GLfloat, GLfloat)>(getProcAddress("glTangent3fEXT"));
	assert(glTangent3fEXT_ != nullptr);
	return glTangent3fEXT_(tx, ty, tz);
}
void glTangent3fvEXT(GLfloat const  * v) {
	static const auto glTangent3fvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat const  *)>(getProcAddress("glTangent3fvEXT"));
	assert(glTangent3fvEXT_ != nullptr);
	return glTangent3fvEXT_(v);
}
void glTangent3iEXT(GLint tx, GLint ty, GLint tz) {
	static const auto glTangent3iEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLint, GLint)>(getProcAddress("glTangent3iEXT"));
	assert(glTangent3iEXT_ != nullptr);
	return glTangent3iEXT_(tx, ty, tz);
}
void glTangent3ivEXT(GLint const  * v) {
	static const auto glTangent3ivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLint const  *)>(getProcAddress("glTangent3ivEXT"));
	assert(glTangent3ivEXT_ != nullptr);
	return glTangent3ivEXT_(v);
}
void glTangent3sEXT(GLshort tx, GLshort ty, GLshort tz) {
	static const auto glTangent3sEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLshort, GLshort, GLshort)>(getProcAddress("glTangent3sEXT"));
	assert(glTangent3sEXT_ != nullptr);
	return glTangent3sEXT_(tx, ty, tz);
}
void glTangent3svEXT(GLshort const  * v) {
	static const auto glTangent3svEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLshort const  *)>(getProcAddress("glTangent3svEXT"));
	assert(glTangent3svEXT_ != nullptr);
	return glTangent3svEXT_(v);
}
void glBinormal3bEXT(GLbyte bx, GLbyte by, GLbyte bz) {
	static const auto glBinormal3bEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLbyte, GLbyte, GLbyte)>(getProcAddress("glBinormal3bEXT"));
	assert(glBinormal3bEXT_ != nullptr);
	return glBinormal3bEXT_(bx, by, bz);
}
void glBinormal3bvEXT(GLbyte const  * v) {
	static const auto glBinormal3bvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLbyte const  *)>(getProcAddress("glBinormal3bvEXT"));
	assert(glBinormal3bvEXT_ != nullptr);
	return glBinormal3bvEXT_(v);
}
void glBinormal3dEXT(GLdouble bx, GLdouble by, GLdouble bz) {
	static const auto glBinormal3dEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble, GLdouble, GLdouble)>(getProcAddress("glBinormal3dEXT"));
	assert(glBinormal3dEXT_ != nullptr);
	return glBinormal3dEXT_(bx, by, bz);
}
void glBinormal3dvEXT(GLdouble const  * v) {
	static const auto glBinormal3dvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble const  *)>(getProcAddress("glBinormal3dvEXT"));
	assert(glBinormal3dvEXT_ != nullptr);
	return glBinormal3dvEXT_(v);
}
void glBinormal3fEXT(GLfloat bx, GLfloat by, GLfloat bz) {
	static const auto glBinormal3fEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat, GLfloat, GLfloat)>(getProcAddress("glBinormal3fEXT"));
	assert(glBinormal3fEXT_ != nullptr);
	return glBinormal3fEXT_(bx, by, bz);
}
void glBinormal3fvEXT(GLfloat const  * v) {
	static const auto glBinormal3fvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat const  *)>(getProcAddress("glBinormal3fvEXT"));
	assert(glBinormal3fvEXT_ != nullptr);
	return glBinormal3fvEXT_(v);
}
void glBinormal3iEXT(GLint bx, GLint by, GLint bz) {
	static const auto glBinormal3iEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLint, GLint)>(getProcAddress("glBinormal3iEXT"));
	assert(glBinormal3iEXT_ != nullptr);
	return glBinormal3iEXT_(bx, by, bz);
}
void glBinormal3ivEXT(GLint const  * v) {
	static const auto glBinormal3ivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLint const  *)>(getProcAddress("glBinormal3ivEXT"));
	assert(glBinormal3ivEXT_ != nullptr);
	return glBinormal3ivEXT_(v);
}
void glBinormal3sEXT(GLshort bx, GLshort by, GLshort bz) {
	static const auto glBinormal3sEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLshort, GLshort, GLshort)>(getProcAddress("glBinormal3sEXT"));
	assert(glBinormal3sEXT_ != nullptr);
	return glBinormal3sEXT_(bx, by, bz);
}
void glBinormal3svEXT(GLshort const  * v) {
	static const auto glBinormal3svEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLshort const  *)>(getProcAddress("glBinormal3svEXT"));
	assert(glBinormal3svEXT_ != nullptr);
	return glBinormal3svEXT_(v);
}
void glTangentPointerEXT(GLenum type, GLsizei stride, const void * pointer) {
	static const auto glTangentPointerEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, const void *)>(getProcAddress("glTangentPointerEXT"));
	assert(glTangentPointerEXT_ != nullptr);
	return glTangentPointerEXT_(type, stride, pointer);
}
void glBinormalPointerEXT(GLenum type, GLsizei stride, const void * pointer) {
	static const auto glBinormalPointerEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, const void *)>(getProcAddress("glBinormalPointerEXT"));
	assert(glBinormalPointerEXT_ != nullptr);
	return glBinormalPointerEXT_(type, stride, pointer);
}
void glCopyTexImage1DEXT(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) {
	static const auto glCopyTexImage1DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLint)>(getProcAddress("glCopyTexImage1DEXT"));
	assert(glCopyTexImage1DEXT_ != nullptr);
	return glCopyTexImage1DEXT_(target, level, internalformat, x, y, width, border);
}
void glCopyTexImage2DEXT(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) {
	static const auto glCopyTexImage2DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint)>(getProcAddress("glCopyTexImage2DEXT"));
	assert(glCopyTexImage2DEXT_ != nullptr);
	return glCopyTexImage2DEXT_(target, level, internalformat, x, y, width, height, border);
}
void glCopyTexSubImage1DEXT(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) {
	static const auto glCopyTexSubImage1DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLint, GLint, GLint, GLsizei)>(getProcAddress("glCopyTexSubImage1DEXT"));
	assert(glCopyTexSubImage1DEXT_ != nullptr);
	return glCopyTexSubImage1DEXT_(target, level, xoffset, x, y, width);
}
void glCopyTexSubImage2DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
	static const auto glCopyTexSubImage2DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei)>(getProcAddress("glCopyTexSubImage2DEXT"));
	assert(glCopyTexSubImage2DEXT_ != nullptr);
	return glCopyTexSubImage2DEXT_(target, level, xoffset, yoffset, x, y, width, height);
}
void glCopyTexSubImage3DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
	static const auto glCopyTexSubImage3DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei)>(getProcAddress("glCopyTexSubImage3DEXT"));
	assert(glCopyTexSubImage3DEXT_ != nullptr);
	return glCopyTexSubImage3DEXT_(target, level, xoffset, yoffset, zoffset, x, y, width, height);
}
void glCullParameterdvEXT(GLenum pname, GLdouble * params) {
	static const auto glCullParameterdvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLdouble *)>(getProcAddress("glCullParameterdvEXT"));
	assert(glCullParameterdvEXT_ != nullptr);
	return glCullParameterdvEXT_(pname, params);
}
void glCullParameterfvEXT(GLenum pname, GLfloat * params) {
	static const auto glCullParameterfvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfloat *)>(getProcAddress("glCullParameterfvEXT"));
	assert(glCullParameterfvEXT_ != nullptr);
	return glCullParameterfvEXT_(pname, params);
}
void glLabelObjectEXT(GLenum type, GLuint object, GLsizei length, GLchar const  * label) {
	static const auto glLabelObjectEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint, GLsizei, GLchar const  *)>(getProcAddress("glLabelObjectEXT"));
	assert(glLabelObjectEXT_ != nullptr);
	return glLabelObjectEXT_(type, object, length, label);
}
void glGetObjectLabelEXT(GLenum type, GLuint object, GLsizei bufSize, GLsizei * length, GLchar * label) {
	static const auto glGetObjectLabelEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint, GLsizei, GLsizei *, GLchar *)>(getProcAddress("glGetObjectLabelEXT"));
	assert(glGetObjectLabelEXT_ != nullptr);
	return glGetObjectLabelEXT_(type, object, bufSize, length, label);
}
void glInsertEventMarkerEXT(GLsizei length, GLchar const  * marker) {
	static const auto glInsertEventMarkerEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLchar const  *)>(getProcAddress("glInsertEventMarkerEXT"));
	assert(glInsertEventMarkerEXT_ != nullptr);
	return glInsertEventMarkerEXT_(length, marker);
}
void glPushGroupMarkerEXT(GLsizei length, GLchar const  * marker) {
	static const auto glPushGroupMarkerEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLchar const  *)>(getProcAddress("glPushGroupMarkerEXT"));
	assert(glPushGroupMarkerEXT_ != nullptr);
	return glPushGroupMarkerEXT_(length, marker);
}
void glPopGroupMarkerEXT() {
	static const auto glPopGroupMarkerEXT_ = reinterpret_cast<void(GL_APIENTRYP)()>(getProcAddress("glPopGroupMarkerEXT"));
	assert(glPopGroupMarkerEXT_ != nullptr);
	return glPopGroupMarkerEXT_();
}
void glDepthBoundsEXT(GLclampd zmin, GLclampd zmax) {
	static const auto glDepthBoundsEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLclampd, GLclampd)>(getProcAddress("glDepthBoundsEXT"));
	assert(glDepthBoundsEXT_ != nullptr);
	return glDepthBoundsEXT_(zmin, zmax);
}
void glMatrixLoadfEXT(GLenum mode, GLfloat const  * m) {
	static const auto glMatrixLoadfEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfloat const  *)>(getProcAddress("glMatrixLoadfEXT"));
	assert(glMatrixLoadfEXT_ != nullptr);
	return glMatrixLoadfEXT_(mode, m);
}
void glMatrixLoaddEXT(GLenum mode, GLdouble const  * m) {
	static const auto glMatrixLoaddEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLdouble const  *)>(getProcAddress("glMatrixLoaddEXT"));
	assert(glMatrixLoaddEXT_ != nullptr);
	return glMatrixLoaddEXT_(mode, m);
}
void glMatrixMultfEXT(GLenum mode, GLfloat const  * m) {
	static const auto glMatrixMultfEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfloat const  *)>(getProcAddress("glMatrixMultfEXT"));
	assert(glMatrixMultfEXT_ != nullptr);
	return glMatrixMultfEXT_(mode, m);
}
void glMatrixMultdEXT(GLenum mode, GLdouble const  * m) {
	static const auto glMatrixMultdEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLdouble const  *)>(getProcAddress("glMatrixMultdEXT"));
	assert(glMatrixMultdEXT_ != nullptr);
	return glMatrixMultdEXT_(mode, m);
}
void glMatrixLoadIdentityEXT(GLenum mode) {
	static const auto glMatrixLoadIdentityEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glMatrixLoadIdentityEXT"));
	assert(glMatrixLoadIdentityEXT_ != nullptr);
	return glMatrixLoadIdentityEXT_(mode);
}
void glMatrixRotatefEXT(GLenum mode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z) {
	static const auto glMatrixRotatefEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfloat, GLfloat, GLfloat, GLfloat)>(getProcAddress("glMatrixRotatefEXT"));
	assert(glMatrixRotatefEXT_ != nullptr);
	return glMatrixRotatefEXT_(mode, angle, x, y, z);
}
void glMatrixRotatedEXT(GLenum mode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z) {
	static const auto glMatrixRotatedEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLdouble, GLdouble, GLdouble, GLdouble)>(getProcAddress("glMatrixRotatedEXT"));
	assert(glMatrixRotatedEXT_ != nullptr);
	return glMatrixRotatedEXT_(mode, angle, x, y, z);
}
void glMatrixScalefEXT(GLenum mode, GLfloat x, GLfloat y, GLfloat z) {
	static const auto glMatrixScalefEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfloat, GLfloat, GLfloat)>(getProcAddress("glMatrixScalefEXT"));
	assert(glMatrixScalefEXT_ != nullptr);
	return glMatrixScalefEXT_(mode, x, y, z);
}
void glMatrixScaledEXT(GLenum mode, GLdouble x, GLdouble y, GLdouble z) {
	static const auto glMatrixScaledEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLdouble, GLdouble, GLdouble)>(getProcAddress("glMatrixScaledEXT"));
	assert(glMatrixScaledEXT_ != nullptr);
	return glMatrixScaledEXT_(mode, x, y, z);
}
void glMatrixTranslatefEXT(GLenum mode, GLfloat x, GLfloat y, GLfloat z) {
	static const auto glMatrixTranslatefEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfloat, GLfloat, GLfloat)>(getProcAddress("glMatrixTranslatefEXT"));
	assert(glMatrixTranslatefEXT_ != nullptr);
	return glMatrixTranslatefEXT_(mode, x, y, z);
}
void glMatrixTranslatedEXT(GLenum mode, GLdouble x, GLdouble y, GLdouble z) {
	static const auto glMatrixTranslatedEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLdouble, GLdouble, GLdouble)>(getProcAddress("glMatrixTranslatedEXT"));
	assert(glMatrixTranslatedEXT_ != nullptr);
	return glMatrixTranslatedEXT_(mode, x, y, z);
}
void glMatrixFrustumEXT(GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar) {
	static const auto glMatrixFrustumEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble)>(getProcAddress("glMatrixFrustumEXT"));
	assert(glMatrixFrustumEXT_ != nullptr);
	return glMatrixFrustumEXT_(mode, left, right, bottom, top, zNear, zFar);
}
void glMatrixOrthoEXT(GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar) {
	static const auto glMatrixOrthoEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble)>(getProcAddress("glMatrixOrthoEXT"));
	assert(glMatrixOrthoEXT_ != nullptr);
	return glMatrixOrthoEXT_(mode, left, right, bottom, top, zNear, zFar);
}
void glMatrixPopEXT(GLenum mode) {
	static const auto glMatrixPopEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glMatrixPopEXT"));
	assert(glMatrixPopEXT_ != nullptr);
	return glMatrixPopEXT_(mode);
}
void glMatrixPushEXT(GLenum mode) {
	static const auto glMatrixPushEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glMatrixPushEXT"));
	assert(glMatrixPushEXT_ != nullptr);
	return glMatrixPushEXT_(mode);
}
void glClientAttribDefaultEXT(GLbitfield mask) {
	static const auto glClientAttribDefaultEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLbitfield)>(getProcAddress("glClientAttribDefaultEXT"));
	assert(glClientAttribDefaultEXT_ != nullptr);
	return glClientAttribDefaultEXT_(mask);
}
void glPushClientAttribDefaultEXT(GLbitfield mask) {
	static const auto glPushClientAttribDefaultEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLbitfield)>(getProcAddress("glPushClientAttribDefaultEXT"));
	assert(glPushClientAttribDefaultEXT_ != nullptr);
	return glPushClientAttribDefaultEXT_(mask);
}
void glTextureParameterfEXT(GLuint texture, GLenum target, GLenum pname, GLfloat param) {
	static const auto glTextureParameterfEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLenum, GLfloat)>(getProcAddress("glTextureParameterfEXT"));
	assert(glTextureParameterfEXT_ != nullptr);
	return glTextureParameterfEXT_(texture, target, pname, param);
}
void glTextureParameterfvEXT(GLuint texture, GLenum target, GLenum pname, GLfloat const  * params) {
	static const auto glTextureParameterfvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLenum, GLfloat const  *)>(getProcAddress("glTextureParameterfvEXT"));
	assert(glTextureParameterfvEXT_ != nullptr);
	return glTextureParameterfvEXT_(texture, target, pname, params);
}
void glTextureParameteriEXT(GLuint texture, GLenum target, GLenum pname, GLint param) {
	static const auto glTextureParameteriEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLenum, GLint)>(getProcAddress("glTextureParameteriEXT"));
	assert(glTextureParameteriEXT_ != nullptr);
	return glTextureParameteriEXT_(texture, target, pname, param);
}
void glTextureParameterivEXT(GLuint texture, GLenum target, GLenum pname, GLint const  * params) {
	static const auto glTextureParameterivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLenum, GLint const  *)>(getProcAddress("glTextureParameterivEXT"));
	assert(glTextureParameterivEXT_ != nullptr);
	return glTextureParameterivEXT_(texture, target, pname, params);
}
void glTextureImage1DEXT(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void * pixels) {
	static const auto glTextureImage1DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint, GLint, GLsizei, GLint, GLenum, GLenum, const void *)>(getProcAddress("glTextureImage1DEXT"));
	assert(glTextureImage1DEXT_ != nullptr);
	return glTextureImage1DEXT_(texture, target, level, internalformat, width, border, format, type, pixels);
}
void glTextureImage2DEXT(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void * pixels) {
	static const auto glTextureImage2DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const void *)>(getProcAddress("glTextureImage2DEXT"));
	assert(glTextureImage2DEXT_ != nullptr);
	return glTextureImage2DEXT_(texture, target, level, internalformat, width, height, border, format, type, pixels);
}
void glTextureSubImage1DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void * pixels) {
	static const auto glTextureSubImage1DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint, GLint, GLsizei, GLenum, GLenum, const void *)>(getProcAddress("glTextureSubImage1DEXT"));
	assert(glTextureSubImage1DEXT_ != nullptr);
	return glTextureSubImage1DEXT_(texture, target, level, xoffset, width, format, type, pixels);
}
void glTextureSubImage2DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels) {
	static const auto glTextureSubImage2DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const void *)>(getProcAddress("glTextureSubImage2DEXT"));
	assert(glTextureSubImage2DEXT_ != nullptr);
	return glTextureSubImage2DEXT_(texture, target, level, xoffset, yoffset, width, height, format, type, pixels);
}
void glCopyTextureImage1DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) {
	static const auto glCopyTextureImage1DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLint)>(getProcAddress("glCopyTextureImage1DEXT"));
	assert(glCopyTextureImage1DEXT_ != nullptr);
	return glCopyTextureImage1DEXT_(texture, target, level, internalformat, x, y, width, border);
}
void glCopyTextureImage2DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) {
	static const auto glCopyTextureImage2DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint)>(getProcAddress("glCopyTextureImage2DEXT"));
	assert(glCopyTextureImage2DEXT_ != nullptr);
	return glCopyTextureImage2DEXT_(texture, target, level, internalformat, x, y, width, height, border);
}
void glCopyTextureSubImage1DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) {
	static const auto glCopyTextureSubImage1DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint, GLint, GLint, GLint, GLsizei)>(getProcAddress("glCopyTextureSubImage1DEXT"));
	assert(glCopyTextureSubImage1DEXT_ != nullptr);
	return glCopyTextureSubImage1DEXT_(texture, target, level, xoffset, x, y, width);
}
void glCopyTextureSubImage2DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
	static const auto glCopyTextureSubImage2DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei)>(getProcAddress("glCopyTextureSubImage2DEXT"));
	assert(glCopyTextureSubImage2DEXT_ != nullptr);
	return glCopyTextureSubImage2DEXT_(texture, target, level, xoffset, yoffset, x, y, width, height);
}
void glGetTextureImageEXT(GLuint texture, GLenum target, GLint level, GLenum format, GLenum type, void * pixels) {
	static const auto glGetTextureImageEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint, GLenum, GLenum, void *)>(getProcAddress("glGetTextureImageEXT"));
	assert(glGetTextureImageEXT_ != nullptr);
	return glGetTextureImageEXT_(texture, target, level, format, type, pixels);
}
void glGetTextureParameterfvEXT(GLuint texture, GLenum target, GLenum pname, GLfloat * params) {
	static const auto glGetTextureParameterfvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLenum, GLfloat *)>(getProcAddress("glGetTextureParameterfvEXT"));
	assert(glGetTextureParameterfvEXT_ != nullptr);
	return glGetTextureParameterfvEXT_(texture, target, pname, params);
}
void glGetTextureParameterivEXT(GLuint texture, GLenum target, GLenum pname, GLint * params) {
	static const auto glGetTextureParameterivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLenum, GLint *)>(getProcAddress("glGetTextureParameterivEXT"));
	assert(glGetTextureParameterivEXT_ != nullptr);
	return glGetTextureParameterivEXT_(texture, target, pname, params);
}
void glGetTextureLevelParameterfvEXT(GLuint texture, GLenum target, GLint level, GLenum pname, GLfloat * params) {
	static const auto glGetTextureLevelParameterfvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint, GLenum, GLfloat *)>(getProcAddress("glGetTextureLevelParameterfvEXT"));
	assert(glGetTextureLevelParameterfvEXT_ != nullptr);
	return glGetTextureLevelParameterfvEXT_(texture, target, level, pname, params);
}
void glGetTextureLevelParameterivEXT(GLuint texture, GLenum target, GLint level, GLenum pname, GLint * params) {
	static const auto glGetTextureLevelParameterivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint, GLenum, GLint *)>(getProcAddress("glGetTextureLevelParameterivEXT"));
	assert(glGetTextureLevelParameterivEXT_ != nullptr);
	return glGetTextureLevelParameterivEXT_(texture, target, level, pname, params);
}
void glTextureImage3DEXT(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void * pixels) {
	static const auto glTextureImage3DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint, GLint, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const void *)>(getProcAddress("glTextureImage3DEXT"));
	assert(glTextureImage3DEXT_ != nullptr);
	return glTextureImage3DEXT_(texture, target, level, internalformat, width, height, depth, border, format, type, pixels);
}
void glTextureSubImage3DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels) {
	static const auto glTextureSubImage3DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const void *)>(getProcAddress("glTextureSubImage3DEXT"));
	assert(glTextureSubImage3DEXT_ != nullptr);
	return glTextureSubImage3DEXT_(texture, target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}
void glCopyTextureSubImage3DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
	static const auto glCopyTextureSubImage3DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei)>(getProcAddress("glCopyTextureSubImage3DEXT"));
	assert(glCopyTextureSubImage3DEXT_ != nullptr);
	return glCopyTextureSubImage3DEXT_(texture, target, level, xoffset, yoffset, zoffset, x, y, width, height);
}
void glBindMultiTextureEXT(GLenum texunit, GLenum target, GLuint texture) {
	static const auto glBindMultiTextureEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLuint)>(getProcAddress("glBindMultiTextureEXT"));
	assert(glBindMultiTextureEXT_ != nullptr);
	return glBindMultiTextureEXT_(texunit, target, texture);
}
void glMultiTexCoordPointerEXT(GLenum texunit, GLint size, GLenum type, GLsizei stride, const void * pointer) {
	static const auto glMultiTexCoordPointerEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLenum, GLsizei, const void *)>(getProcAddress("glMultiTexCoordPointerEXT"));
	assert(glMultiTexCoordPointerEXT_ != nullptr);
	return glMultiTexCoordPointerEXT_(texunit, size, type, stride, pointer);
}
void glMultiTexEnvfEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat param) {
	static const auto glMultiTexEnvfEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLfloat)>(getProcAddress("glMultiTexEnvfEXT"));
	assert(glMultiTexEnvfEXT_ != nullptr);
	return glMultiTexEnvfEXT_(texunit, target, pname, param);
}
void glMultiTexEnvfvEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat const  * params) {
	static const auto glMultiTexEnvfvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLfloat const  *)>(getProcAddress("glMultiTexEnvfvEXT"));
	assert(glMultiTexEnvfvEXT_ != nullptr);
	return glMultiTexEnvfvEXT_(texunit, target, pname, params);
}
void glMultiTexEnviEXT(GLenum texunit, GLenum target, GLenum pname, GLint param) {
	static const auto glMultiTexEnviEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLint)>(getProcAddress("glMultiTexEnviEXT"));
	assert(glMultiTexEnviEXT_ != nullptr);
	return glMultiTexEnviEXT_(texunit, target, pname, param);
}
void glMultiTexEnvivEXT(GLenum texunit, GLenum target, GLenum pname, GLint const  * params) {
	static const auto glMultiTexEnvivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLint const  *)>(getProcAddress("glMultiTexEnvivEXT"));
	assert(glMultiTexEnvivEXT_ != nullptr);
	return glMultiTexEnvivEXT_(texunit, target, pname, params);
}
void glMultiTexGendEXT(GLenum texunit, GLenum coord, GLenum pname, GLdouble param) {
	static const auto glMultiTexGendEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLdouble)>(getProcAddress("glMultiTexGendEXT"));
	assert(glMultiTexGendEXT_ != nullptr);
	return glMultiTexGendEXT_(texunit, coord, pname, param);
}
void glMultiTexGendvEXT(GLenum texunit, GLenum coord, GLenum pname, GLdouble const  * params) {
	static const auto glMultiTexGendvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLdouble const  *)>(getProcAddress("glMultiTexGendvEXT"));
	assert(glMultiTexGendvEXT_ != nullptr);
	return glMultiTexGendvEXT_(texunit, coord, pname, params);
}
void glMultiTexGenfEXT(GLenum texunit, GLenum coord, GLenum pname, GLfloat param) {
	static const auto glMultiTexGenfEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLfloat)>(getProcAddress("glMultiTexGenfEXT"));
	assert(glMultiTexGenfEXT_ != nullptr);
	return glMultiTexGenfEXT_(texunit, coord, pname, param);
}
void glMultiTexGenfvEXT(GLenum texunit, GLenum coord, GLenum pname, GLfloat const  * params) {
	static const auto glMultiTexGenfvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLfloat const  *)>(getProcAddress("glMultiTexGenfvEXT"));
	assert(glMultiTexGenfvEXT_ != nullptr);
	return glMultiTexGenfvEXT_(texunit, coord, pname, params);
}
void glMultiTexGeniEXT(GLenum texunit, GLenum coord, GLenum pname, GLint param) {
	static const auto glMultiTexGeniEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLint)>(getProcAddress("glMultiTexGeniEXT"));
	assert(glMultiTexGeniEXT_ != nullptr);
	return glMultiTexGeniEXT_(texunit, coord, pname, param);
}
void glMultiTexGenivEXT(GLenum texunit, GLenum coord, GLenum pname, GLint const  * params) {
	static const auto glMultiTexGenivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLint const  *)>(getProcAddress("glMultiTexGenivEXT"));
	assert(glMultiTexGenivEXT_ != nullptr);
	return glMultiTexGenivEXT_(texunit, coord, pname, params);
}
void glGetMultiTexEnvfvEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat * params) {
	static const auto glGetMultiTexEnvfvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLfloat *)>(getProcAddress("glGetMultiTexEnvfvEXT"));
	assert(glGetMultiTexEnvfvEXT_ != nullptr);
	return glGetMultiTexEnvfvEXT_(texunit, target, pname, params);
}
void glGetMultiTexEnvivEXT(GLenum texunit, GLenum target, GLenum pname, GLint * params) {
	static const auto glGetMultiTexEnvivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLint *)>(getProcAddress("glGetMultiTexEnvivEXT"));
	assert(glGetMultiTexEnvivEXT_ != nullptr);
	return glGetMultiTexEnvivEXT_(texunit, target, pname, params);
}
void glGetMultiTexGendvEXT(GLenum texunit, GLenum coord, GLenum pname, GLdouble * params) {
	static const auto glGetMultiTexGendvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLdouble *)>(getProcAddress("glGetMultiTexGendvEXT"));
	assert(glGetMultiTexGendvEXT_ != nullptr);
	return glGetMultiTexGendvEXT_(texunit, coord, pname, params);
}
void glGetMultiTexGenfvEXT(GLenum texunit, GLenum coord, GLenum pname, GLfloat * params) {
	static const auto glGetMultiTexGenfvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLfloat *)>(getProcAddress("glGetMultiTexGenfvEXT"));
	assert(glGetMultiTexGenfvEXT_ != nullptr);
	return glGetMultiTexGenfvEXT_(texunit, coord, pname, params);
}
void glGetMultiTexGenivEXT(GLenum texunit, GLenum coord, GLenum pname, GLint * params) {
	static const auto glGetMultiTexGenivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLint *)>(getProcAddress("glGetMultiTexGenivEXT"));
	assert(glGetMultiTexGenivEXT_ != nullptr);
	return glGetMultiTexGenivEXT_(texunit, coord, pname, params);
}
void glMultiTexParameteriEXT(GLenum texunit, GLenum target, GLenum pname, GLint param) {
	static const auto glMultiTexParameteriEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLint)>(getProcAddress("glMultiTexParameteriEXT"));
	assert(glMultiTexParameteriEXT_ != nullptr);
	return glMultiTexParameteriEXT_(texunit, target, pname, param);
}
void glMultiTexParameterivEXT(GLenum texunit, GLenum target, GLenum pname, GLint const  * params) {
	static const auto glMultiTexParameterivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLint const  *)>(getProcAddress("glMultiTexParameterivEXT"));
	assert(glMultiTexParameterivEXT_ != nullptr);
	return glMultiTexParameterivEXT_(texunit, target, pname, params);
}
void glMultiTexParameterfEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat param) {
	static const auto glMultiTexParameterfEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLfloat)>(getProcAddress("glMultiTexParameterfEXT"));
	assert(glMultiTexParameterfEXT_ != nullptr);
	return glMultiTexParameterfEXT_(texunit, target, pname, param);
}
void glMultiTexParameterfvEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat const  * params) {
	static const auto glMultiTexParameterfvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLfloat const  *)>(getProcAddress("glMultiTexParameterfvEXT"));
	assert(glMultiTexParameterfvEXT_ != nullptr);
	return glMultiTexParameterfvEXT_(texunit, target, pname, params);
}
void glMultiTexImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void * pixels) {
	static const auto glMultiTexImage1DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint, GLint, GLsizei, GLint, GLenum, GLenum, const void *)>(getProcAddress("glMultiTexImage1DEXT"));
	assert(glMultiTexImage1DEXT_ != nullptr);
	return glMultiTexImage1DEXT_(texunit, target, level, internalformat, width, border, format, type, pixels);
}
void glMultiTexImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void * pixels) {
	static const auto glMultiTexImage2DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const void *)>(getProcAddress("glMultiTexImage2DEXT"));
	assert(glMultiTexImage2DEXT_ != nullptr);
	return glMultiTexImage2DEXT_(texunit, target, level, internalformat, width, height, border, format, type, pixels);
}
void glMultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void * pixels) {
	static const auto glMultiTexSubImage1DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint, GLint, GLsizei, GLenum, GLenum, const void *)>(getProcAddress("glMultiTexSubImage1DEXT"));
	assert(glMultiTexSubImage1DEXT_ != nullptr);
	return glMultiTexSubImage1DEXT_(texunit, target, level, xoffset, width, format, type, pixels);
}
void glMultiTexSubImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels) {
	static const auto glMultiTexSubImage2DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const void *)>(getProcAddress("glMultiTexSubImage2DEXT"));
	assert(glMultiTexSubImage2DEXT_ != nullptr);
	return glMultiTexSubImage2DEXT_(texunit, target, level, xoffset, yoffset, width, height, format, type, pixels);
}
void glCopyMultiTexImage1DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) {
	static const auto glCopyMultiTexImage1DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLint)>(getProcAddress("glCopyMultiTexImage1DEXT"));
	assert(glCopyMultiTexImage1DEXT_ != nullptr);
	return glCopyMultiTexImage1DEXT_(texunit, target, level, internalformat, x, y, width, border);
}
void glCopyMultiTexImage2DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) {
	static const auto glCopyMultiTexImage2DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint)>(getProcAddress("glCopyMultiTexImage2DEXT"));
	assert(glCopyMultiTexImage2DEXT_ != nullptr);
	return glCopyMultiTexImage2DEXT_(texunit, target, level, internalformat, x, y, width, height, border);
}
void glCopyMultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) {
	static const auto glCopyMultiTexSubImage1DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint, GLint, GLint, GLint, GLsizei)>(getProcAddress("glCopyMultiTexSubImage1DEXT"));
	assert(glCopyMultiTexSubImage1DEXT_ != nullptr);
	return glCopyMultiTexSubImage1DEXT_(texunit, target, level, xoffset, x, y, width);
}
void glCopyMultiTexSubImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
	static const auto glCopyMultiTexSubImage2DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei)>(getProcAddress("glCopyMultiTexSubImage2DEXT"));
	assert(glCopyMultiTexSubImage2DEXT_ != nullptr);
	return glCopyMultiTexSubImage2DEXT_(texunit, target, level, xoffset, yoffset, x, y, width, height);
}
void glGetMultiTexImageEXT(GLenum texunit, GLenum target, GLint level, GLenum format, GLenum type, void * pixels) {
	static const auto glGetMultiTexImageEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint, GLenum, GLenum, void *)>(getProcAddress("glGetMultiTexImageEXT"));
	assert(glGetMultiTexImageEXT_ != nullptr);
	return glGetMultiTexImageEXT_(texunit, target, level, format, type, pixels);
}
void glGetMultiTexParameterfvEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat * params) {
	static const auto glGetMultiTexParameterfvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLfloat *)>(getProcAddress("glGetMultiTexParameterfvEXT"));
	assert(glGetMultiTexParameterfvEXT_ != nullptr);
	return glGetMultiTexParameterfvEXT_(texunit, target, pname, params);
}
void glGetMultiTexParameterivEXT(GLenum texunit, GLenum target, GLenum pname, GLint * params) {
	static const auto glGetMultiTexParameterivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLint *)>(getProcAddress("glGetMultiTexParameterivEXT"));
	assert(glGetMultiTexParameterivEXT_ != nullptr);
	return glGetMultiTexParameterivEXT_(texunit, target, pname, params);
}
void glGetMultiTexLevelParameterfvEXT(GLenum texunit, GLenum target, GLint level, GLenum pname, GLfloat * params) {
	static const auto glGetMultiTexLevelParameterfvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint, GLenum, GLfloat *)>(getProcAddress("glGetMultiTexLevelParameterfvEXT"));
	assert(glGetMultiTexLevelParameterfvEXT_ != nullptr);
	return glGetMultiTexLevelParameterfvEXT_(texunit, target, level, pname, params);
}
void glGetMultiTexLevelParameterivEXT(GLenum texunit, GLenum target, GLint level, GLenum pname, GLint * params) {
	static const auto glGetMultiTexLevelParameterivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint, GLenum, GLint *)>(getProcAddress("glGetMultiTexLevelParameterivEXT"));
	assert(glGetMultiTexLevelParameterivEXT_ != nullptr);
	return glGetMultiTexLevelParameterivEXT_(texunit, target, level, pname, params);
}
void glMultiTexImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void * pixels) {
	static const auto glMultiTexImage3DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint, GLint, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const void *)>(getProcAddress("glMultiTexImage3DEXT"));
	assert(glMultiTexImage3DEXT_ != nullptr);
	return glMultiTexImage3DEXT_(texunit, target, level, internalformat, width, height, depth, border, format, type, pixels);
}
void glMultiTexSubImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels) {
	static const auto glMultiTexSubImage3DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const void *)>(getProcAddress("glMultiTexSubImage3DEXT"));
	assert(glMultiTexSubImage3DEXT_ != nullptr);
	return glMultiTexSubImage3DEXT_(texunit, target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}
void glCopyMultiTexSubImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
	static const auto glCopyMultiTexSubImage3DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei)>(getProcAddress("glCopyMultiTexSubImage3DEXT"));
	assert(glCopyMultiTexSubImage3DEXT_ != nullptr);
	return glCopyMultiTexSubImage3DEXT_(texunit, target, level, xoffset, yoffset, zoffset, x, y, width, height);
}
void glEnableClientStateIndexedEXT(GLenum array, GLuint index) {
	static const auto glEnableClientStateIndexedEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint)>(getProcAddress("glEnableClientStateIndexedEXT"));
	assert(glEnableClientStateIndexedEXT_ != nullptr);
	return glEnableClientStateIndexedEXT_(array, index);
}
void glDisableClientStateIndexedEXT(GLenum array, GLuint index) {
	static const auto glDisableClientStateIndexedEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint)>(getProcAddress("glDisableClientStateIndexedEXT"));
	assert(glDisableClientStateIndexedEXT_ != nullptr);
	return glDisableClientStateIndexedEXT_(array, index);
}
void glGetFloatIndexedvEXT(GLenum target, GLuint index, GLfloat * data) {
	static const auto glGetFloatIndexedvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint, GLfloat *)>(getProcAddress("glGetFloatIndexedvEXT"));
	assert(glGetFloatIndexedvEXT_ != nullptr);
	return glGetFloatIndexedvEXT_(target, index, data);
}
void glGetDoubleIndexedvEXT(GLenum target, GLuint index, GLdouble * data) {
	static const auto glGetDoubleIndexedvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint, GLdouble *)>(getProcAddress("glGetDoubleIndexedvEXT"));
	assert(glGetDoubleIndexedvEXT_ != nullptr);
	return glGetDoubleIndexedvEXT_(target, index, data);
}
void glGetPointerIndexedvEXT(GLenum target, GLuint index, void ** data) {
	static const auto glGetPointerIndexedvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint, void **)>(getProcAddress("glGetPointerIndexedvEXT"));
	assert(glGetPointerIndexedvEXT_ != nullptr);
	return glGetPointerIndexedvEXT_(target, index, data);
}
void glEnableIndexedEXT(GLenum target, GLuint index) {
	static const auto glEnableIndexedEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint)>(getProcAddress("glEnableIndexedEXT"));
	assert(glEnableIndexedEXT_ != nullptr);
	return glEnableIndexedEXT_(target, index);
}
void glDisableIndexedEXT(GLenum target, GLuint index) {
	static const auto glDisableIndexedEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint)>(getProcAddress("glDisableIndexedEXT"));
	assert(glDisableIndexedEXT_ != nullptr);
	return glDisableIndexedEXT_(target, index);
}
GLboolean glIsEnabledIndexedEXT(GLenum target, GLuint index) {
	static const auto glIsEnabledIndexedEXT_ = reinterpret_cast<GLboolean(GL_APIENTRYP)(GLenum, GLuint)>(getProcAddress("glIsEnabledIndexedEXT"));
	assert(glIsEnabledIndexedEXT_ != nullptr);
	return glIsEnabledIndexedEXT_(target, index);
}
void glGetIntegerIndexedvEXT(GLenum target, GLuint index, GLint * data) {
	static const auto glGetIntegerIndexedvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint, GLint *)>(getProcAddress("glGetIntegerIndexedvEXT"));
	assert(glGetIntegerIndexedvEXT_ != nullptr);
	return glGetIntegerIndexedvEXT_(target, index, data);
}
void glGetBooleanIndexedvEXT(GLenum target, GLuint index, GLboolean * data) {
	static const auto glGetBooleanIndexedvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint, GLboolean *)>(getProcAddress("glGetBooleanIndexedvEXT"));
	assert(glGetBooleanIndexedvEXT_ != nullptr);
	return glGetBooleanIndexedvEXT_(target, index, data);
}
void glCompressedTextureImage3DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void * bits) {
	static const auto glCompressedTextureImage3DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLsizei, const void *)>(getProcAddress("glCompressedTextureImage3DEXT"));
	assert(glCompressedTextureImage3DEXT_ != nullptr);
	return glCompressedTextureImage3DEXT_(texture, target, level, internalformat, width, height, depth, border, imageSize, bits);
}
void glCompressedTextureImage2DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void * bits) {
	static const auto glCompressedTextureImage2DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const void *)>(getProcAddress("glCompressedTextureImage2DEXT"));
	assert(glCompressedTextureImage2DEXT_ != nullptr);
	return glCompressedTextureImage2DEXT_(texture, target, level, internalformat, width, height, border, imageSize, bits);
}
void glCompressedTextureImage1DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void * bits) {
	static const auto glCompressedTextureImage1DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint, GLenum, GLsizei, GLint, GLsizei, const void *)>(getProcAddress("glCompressedTextureImage1DEXT"));
	assert(glCompressedTextureImage1DEXT_ != nullptr);
	return glCompressedTextureImage1DEXT_(texture, target, level, internalformat, width, border, imageSize, bits);
}
void glCompressedTextureSubImage3DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * bits) {
	static const auto glCompressedTextureSubImage3DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const void *)>(getProcAddress("glCompressedTextureSubImage3DEXT"));
	assert(glCompressedTextureSubImage3DEXT_ != nullptr);
	return glCompressedTextureSubImage3DEXT_(texture, target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, bits);
}
void glCompressedTextureSubImage2DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * bits) {
	static const auto glCompressedTextureSubImage2DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const void *)>(getProcAddress("glCompressedTextureSubImage2DEXT"));
	assert(glCompressedTextureSubImage2DEXT_ != nullptr);
	return glCompressedTextureSubImage2DEXT_(texture, target, level, xoffset, yoffset, width, height, format, imageSize, bits);
}
void glCompressedTextureSubImage1DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * bits) {
	static const auto glCompressedTextureSubImage1DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint, GLint, GLsizei, GLenum, GLsizei, const void *)>(getProcAddress("glCompressedTextureSubImage1DEXT"));
	assert(glCompressedTextureSubImage1DEXT_ != nullptr);
	return glCompressedTextureSubImage1DEXT_(texture, target, level, xoffset, width, format, imageSize, bits);
}
void glGetCompressedTextureImageEXT(GLuint texture, GLenum target, GLint lod, void * img) {
	static const auto glGetCompressedTextureImageEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint, void *)>(getProcAddress("glGetCompressedTextureImageEXT"));
	assert(glGetCompressedTextureImageEXT_ != nullptr);
	return glGetCompressedTextureImageEXT_(texture, target, lod, img);
}
void glCompressedMultiTexImage3DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void * bits) {
	static const auto glCompressedMultiTexImage3DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLsizei, const void *)>(getProcAddress("glCompressedMultiTexImage3DEXT"));
	assert(glCompressedMultiTexImage3DEXT_ != nullptr);
	return glCompressedMultiTexImage3DEXT_(texunit, target, level, internalformat, width, height, depth, border, imageSize, bits);
}
void glCompressedMultiTexImage2DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void * bits) {
	static const auto glCompressedMultiTexImage2DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const void *)>(getProcAddress("glCompressedMultiTexImage2DEXT"));
	assert(glCompressedMultiTexImage2DEXT_ != nullptr);
	return glCompressedMultiTexImage2DEXT_(texunit, target, level, internalformat, width, height, border, imageSize, bits);
}
void glCompressedMultiTexImage1DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void * bits) {
	static const auto glCompressedMultiTexImage1DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint, GLenum, GLsizei, GLint, GLsizei, const void *)>(getProcAddress("glCompressedMultiTexImage1DEXT"));
	assert(glCompressedMultiTexImage1DEXT_ != nullptr);
	return glCompressedMultiTexImage1DEXT_(texunit, target, level, internalformat, width, border, imageSize, bits);
}
void glCompressedMultiTexSubImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * bits) {
	static const auto glCompressedMultiTexSubImage3DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const void *)>(getProcAddress("glCompressedMultiTexSubImage3DEXT"));
	assert(glCompressedMultiTexSubImage3DEXT_ != nullptr);
	return glCompressedMultiTexSubImage3DEXT_(texunit, target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, bits);
}
void glCompressedMultiTexSubImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * bits) {
	static const auto glCompressedMultiTexSubImage2DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const void *)>(getProcAddress("glCompressedMultiTexSubImage2DEXT"));
	assert(glCompressedMultiTexSubImage2DEXT_ != nullptr);
	return glCompressedMultiTexSubImage2DEXT_(texunit, target, level, xoffset, yoffset, width, height, format, imageSize, bits);
}
void glCompressedMultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * bits) {
	static const auto glCompressedMultiTexSubImage1DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint, GLint, GLsizei, GLenum, GLsizei, const void *)>(getProcAddress("glCompressedMultiTexSubImage1DEXT"));
	assert(glCompressedMultiTexSubImage1DEXT_ != nullptr);
	return glCompressedMultiTexSubImage1DEXT_(texunit, target, level, xoffset, width, format, imageSize, bits);
}
void glGetCompressedMultiTexImageEXT(GLenum texunit, GLenum target, GLint lod, void * img) {
	static const auto glGetCompressedMultiTexImageEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint, void *)>(getProcAddress("glGetCompressedMultiTexImageEXT"));
	assert(glGetCompressedMultiTexImageEXT_ != nullptr);
	return glGetCompressedMultiTexImageEXT_(texunit, target, lod, img);
}
void glMatrixLoadTransposefEXT(GLenum mode, GLfloat const  * m) {
	static const auto glMatrixLoadTransposefEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfloat const  *)>(getProcAddress("glMatrixLoadTransposefEXT"));
	assert(glMatrixLoadTransposefEXT_ != nullptr);
	return glMatrixLoadTransposefEXT_(mode, m);
}
void glMatrixLoadTransposedEXT(GLenum mode, GLdouble const  * m) {
	static const auto glMatrixLoadTransposedEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLdouble const  *)>(getProcAddress("glMatrixLoadTransposedEXT"));
	assert(glMatrixLoadTransposedEXT_ != nullptr);
	return glMatrixLoadTransposedEXT_(mode, m);
}
void glMatrixMultTransposefEXT(GLenum mode, GLfloat const  * m) {
	static const auto glMatrixMultTransposefEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfloat const  *)>(getProcAddress("glMatrixMultTransposefEXT"));
	assert(glMatrixMultTransposefEXT_ != nullptr);
	return glMatrixMultTransposefEXT_(mode, m);
}
void glMatrixMultTransposedEXT(GLenum mode, GLdouble const  * m) {
	static const auto glMatrixMultTransposedEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLdouble const  *)>(getProcAddress("glMatrixMultTransposedEXT"));
	assert(glMatrixMultTransposedEXT_ != nullptr);
	return glMatrixMultTransposedEXT_(mode, m);
}
void glNamedBufferDataEXT(GLuint buffer, GLsizeiptr size, const void * data, GLenum usage) {
	static const auto glNamedBufferDataEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLsizeiptr, const void *, GLenum)>(getProcAddress("glNamedBufferDataEXT"));
	assert(glNamedBufferDataEXT_ != nullptr);
	return glNamedBufferDataEXT_(buffer, size, data, usage);
}
void glNamedBufferSubDataEXT(GLuint buffer, GLintptr offset, GLsizeiptr size, const void * data) {
	static const auto glNamedBufferSubDataEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLintptr, GLsizeiptr, const void *)>(getProcAddress("glNamedBufferSubDataEXT"));
	assert(glNamedBufferSubDataEXT_ != nullptr);
	return glNamedBufferSubDataEXT_(buffer, offset, size, data);
}
void * glMapNamedBufferEXT(GLuint buffer, GLenum access) {
	static const auto glMapNamedBufferEXT_ = reinterpret_cast<void *(GL_APIENTRYP)(GLuint, GLenum)>(getProcAddress("glMapNamedBufferEXT"));
	assert(glMapNamedBufferEXT_ != nullptr);
	return glMapNamedBufferEXT_(buffer, access);
}
GLboolean glUnmapNamedBufferEXT(GLuint buffer) {
	static const auto glUnmapNamedBufferEXT_ = reinterpret_cast<GLboolean(GL_APIENTRYP)(GLuint)>(getProcAddress("glUnmapNamedBufferEXT"));
	assert(glUnmapNamedBufferEXT_ != nullptr);
	return glUnmapNamedBufferEXT_(buffer);
}
void glGetNamedBufferParameterivEXT(GLuint buffer, GLenum pname, GLint * params) {
	static const auto glGetNamedBufferParameterivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint *)>(getProcAddress("glGetNamedBufferParameterivEXT"));
	assert(glGetNamedBufferParameterivEXT_ != nullptr);
	return glGetNamedBufferParameterivEXT_(buffer, pname, params);
}
void glGetNamedBufferPointervEXT(GLuint buffer, GLenum pname, void ** params) {
	static const auto glGetNamedBufferPointervEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, void **)>(getProcAddress("glGetNamedBufferPointervEXT"));
	assert(glGetNamedBufferPointervEXT_ != nullptr);
	return glGetNamedBufferPointervEXT_(buffer, pname, params);
}
void glGetNamedBufferSubDataEXT(GLuint buffer, GLintptr offset, GLsizeiptr size, void * data) {
	static const auto glGetNamedBufferSubDataEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLintptr, GLsizeiptr, void *)>(getProcAddress("glGetNamedBufferSubDataEXT"));
	assert(glGetNamedBufferSubDataEXT_ != nullptr);
	return glGetNamedBufferSubDataEXT_(buffer, offset, size, data);
}
void glProgramUniform1fEXT(GLuint program, GLint location, GLfloat v0) {
	static const auto glProgramUniform1fEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLfloat)>(getProcAddress("glProgramUniform1fEXT"));
	assert(glProgramUniform1fEXT_ != nullptr);
	return glProgramUniform1fEXT_(program, location, v0);
}
void glProgramUniform2fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1) {
	static const auto glProgramUniform2fEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLfloat, GLfloat)>(getProcAddress("glProgramUniform2fEXT"));
	assert(glProgramUniform2fEXT_ != nullptr);
	return glProgramUniform2fEXT_(program, location, v0, v1);
}
void glProgramUniform3fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2) {
	static const auto glProgramUniform3fEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLfloat, GLfloat, GLfloat)>(getProcAddress("glProgramUniform3fEXT"));
	assert(glProgramUniform3fEXT_ != nullptr);
	return glProgramUniform3fEXT_(program, location, v0, v1, v2);
}
void glProgramUniform4fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {
	static const auto glProgramUniform4fEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLfloat, GLfloat, GLfloat, GLfloat)>(getProcAddress("glProgramUniform4fEXT"));
	assert(glProgramUniform4fEXT_ != nullptr);
	return glProgramUniform4fEXT_(program, location, v0, v1, v2, v3);
}
void glProgramUniform1iEXT(GLuint program, GLint location, GLint v0) {
	static const auto glProgramUniform1iEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLint)>(getProcAddress("glProgramUniform1iEXT"));
	assert(glProgramUniform1iEXT_ != nullptr);
	return glProgramUniform1iEXT_(program, location, v0);
}
void glProgramUniform2iEXT(GLuint program, GLint location, GLint v0, GLint v1) {
	static const auto glProgramUniform2iEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLint, GLint)>(getProcAddress("glProgramUniform2iEXT"));
	assert(glProgramUniform2iEXT_ != nullptr);
	return glProgramUniform2iEXT_(program, location, v0, v1);
}
void glProgramUniform3iEXT(GLuint program, GLint location, GLint v0, GLint v1, GLint v2) {
	static const auto glProgramUniform3iEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLint, GLint, GLint)>(getProcAddress("glProgramUniform3iEXT"));
	assert(glProgramUniform3iEXT_ != nullptr);
	return glProgramUniform3iEXT_(program, location, v0, v1, v2);
}
void glProgramUniform4iEXT(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3) {
	static const auto glProgramUniform4iEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLint, GLint, GLint, GLint)>(getProcAddress("glProgramUniform4iEXT"));
	assert(glProgramUniform4iEXT_ != nullptr);
	return glProgramUniform4iEXT_(program, location, v0, v1, v2, v3);
}
void glProgramUniform1fvEXT(GLuint program, GLint location, GLsizei count, GLfloat const  * value) {
	static const auto glProgramUniform1fvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLfloat const  *)>(getProcAddress("glProgramUniform1fvEXT"));
	assert(glProgramUniform1fvEXT_ != nullptr);
	return glProgramUniform1fvEXT_(program, location, count, value);
}
void glProgramUniform2fvEXT(GLuint program, GLint location, GLsizei count, GLfloat const  * value) {
	static const auto glProgramUniform2fvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLfloat const  *)>(getProcAddress("glProgramUniform2fvEXT"));
	assert(glProgramUniform2fvEXT_ != nullptr);
	return glProgramUniform2fvEXT_(program, location, count, value);
}
void glProgramUniform3fvEXT(GLuint program, GLint location, GLsizei count, GLfloat const  * value) {
	static const auto glProgramUniform3fvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLfloat const  *)>(getProcAddress("glProgramUniform3fvEXT"));
	assert(glProgramUniform3fvEXT_ != nullptr);
	return glProgramUniform3fvEXT_(program, location, count, value);
}
void glProgramUniform4fvEXT(GLuint program, GLint location, GLsizei count, GLfloat const  * value) {
	static const auto glProgramUniform4fvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLfloat const  *)>(getProcAddress("glProgramUniform4fvEXT"));
	assert(glProgramUniform4fvEXT_ != nullptr);
	return glProgramUniform4fvEXT_(program, location, count, value);
}
void glProgramUniform1ivEXT(GLuint program, GLint location, GLsizei count, GLint const  * value) {
	static const auto glProgramUniform1ivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLint const  *)>(getProcAddress("glProgramUniform1ivEXT"));
	assert(glProgramUniform1ivEXT_ != nullptr);
	return glProgramUniform1ivEXT_(program, location, count, value);
}
void glProgramUniform2ivEXT(GLuint program, GLint location, GLsizei count, GLint const  * value) {
	static const auto glProgramUniform2ivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLint const  *)>(getProcAddress("glProgramUniform2ivEXT"));
	assert(glProgramUniform2ivEXT_ != nullptr);
	return glProgramUniform2ivEXT_(program, location, count, value);
}
void glProgramUniform3ivEXT(GLuint program, GLint location, GLsizei count, GLint const  * value) {
	static const auto glProgramUniform3ivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLint const  *)>(getProcAddress("glProgramUniform3ivEXT"));
	assert(glProgramUniform3ivEXT_ != nullptr);
	return glProgramUniform3ivEXT_(program, location, count, value);
}
void glProgramUniform4ivEXT(GLuint program, GLint location, GLsizei count, GLint const  * value) {
	static const auto glProgramUniform4ivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLint const  *)>(getProcAddress("glProgramUniform4ivEXT"));
	assert(glProgramUniform4ivEXT_ != nullptr);
	return glProgramUniform4ivEXT_(program, location, count, value);
}
void glProgramUniformMatrix2fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value) {
	static const auto glProgramUniformMatrix2fvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLboolean, GLfloat const  *)>(getProcAddress("glProgramUniformMatrix2fvEXT"));
	assert(glProgramUniformMatrix2fvEXT_ != nullptr);
	return glProgramUniformMatrix2fvEXT_(program, location, count, transpose, value);
}
void glProgramUniformMatrix3fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value) {
	static const auto glProgramUniformMatrix3fvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLboolean, GLfloat const  *)>(getProcAddress("glProgramUniformMatrix3fvEXT"));
	assert(glProgramUniformMatrix3fvEXT_ != nullptr);
	return glProgramUniformMatrix3fvEXT_(program, location, count, transpose, value);
}
void glProgramUniformMatrix4fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value) {
	static const auto glProgramUniformMatrix4fvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLboolean, GLfloat const  *)>(getProcAddress("glProgramUniformMatrix4fvEXT"));
	assert(glProgramUniformMatrix4fvEXT_ != nullptr);
	return glProgramUniformMatrix4fvEXT_(program, location, count, transpose, value);
}
void glProgramUniformMatrix2x3fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value) {
	static const auto glProgramUniformMatrix2x3fvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLboolean, GLfloat const  *)>(getProcAddress("glProgramUniformMatrix2x3fvEXT"));
	assert(glProgramUniformMatrix2x3fvEXT_ != nullptr);
	return glProgramUniformMatrix2x3fvEXT_(program, location, count, transpose, value);
}
void glProgramUniformMatrix3x2fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value) {
	static const auto glProgramUniformMatrix3x2fvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLboolean, GLfloat const  *)>(getProcAddress("glProgramUniformMatrix3x2fvEXT"));
	assert(glProgramUniformMatrix3x2fvEXT_ != nullptr);
	return glProgramUniformMatrix3x2fvEXT_(program, location, count, transpose, value);
}
void glProgramUniformMatrix2x4fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value) {
	static const auto glProgramUniformMatrix2x4fvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLboolean, GLfloat const  *)>(getProcAddress("glProgramUniformMatrix2x4fvEXT"));
	assert(glProgramUniformMatrix2x4fvEXT_ != nullptr);
	return glProgramUniformMatrix2x4fvEXT_(program, location, count, transpose, value);
}
void glProgramUniformMatrix4x2fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value) {
	static const auto glProgramUniformMatrix4x2fvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLboolean, GLfloat const  *)>(getProcAddress("glProgramUniformMatrix4x2fvEXT"));
	assert(glProgramUniformMatrix4x2fvEXT_ != nullptr);
	return glProgramUniformMatrix4x2fvEXT_(program, location, count, transpose, value);
}
void glProgramUniformMatrix3x4fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value) {
	static const auto glProgramUniformMatrix3x4fvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLboolean, GLfloat const  *)>(getProcAddress("glProgramUniformMatrix3x4fvEXT"));
	assert(glProgramUniformMatrix3x4fvEXT_ != nullptr);
	return glProgramUniformMatrix3x4fvEXT_(program, location, count, transpose, value);
}
void glProgramUniformMatrix4x3fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value) {
	static const auto glProgramUniformMatrix4x3fvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLboolean, GLfloat const  *)>(getProcAddress("glProgramUniformMatrix4x3fvEXT"));
	assert(glProgramUniformMatrix4x3fvEXT_ != nullptr);
	return glProgramUniformMatrix4x3fvEXT_(program, location, count, transpose, value);
}
void glTextureBufferEXT(GLuint texture, GLenum target, GLenum internalformat, GLuint buffer) {
	static const auto glTextureBufferEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLenum, GLuint)>(getProcAddress("glTextureBufferEXT"));
	assert(glTextureBufferEXT_ != nullptr);
	return glTextureBufferEXT_(texture, target, internalformat, buffer);
}
void glMultiTexBufferEXT(GLenum texunit, GLenum target, GLenum internalformat, GLuint buffer) {
	static const auto glMultiTexBufferEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLuint)>(getProcAddress("glMultiTexBufferEXT"));
	assert(glMultiTexBufferEXT_ != nullptr);
	return glMultiTexBufferEXT_(texunit, target, internalformat, buffer);
}
void glTextureParameterIivEXT(GLuint texture, GLenum target, GLenum pname, GLint const  * params) {
	static const auto glTextureParameterIivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLenum, GLint const  *)>(getProcAddress("glTextureParameterIivEXT"));
	assert(glTextureParameterIivEXT_ != nullptr);
	return glTextureParameterIivEXT_(texture, target, pname, params);
}
void glTextureParameterIuivEXT(GLuint texture, GLenum target, GLenum pname, GLuint const  * params) {
	static const auto glTextureParameterIuivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLenum, GLuint const  *)>(getProcAddress("glTextureParameterIuivEXT"));
	assert(glTextureParameterIuivEXT_ != nullptr);
	return glTextureParameterIuivEXT_(texture, target, pname, params);
}
void glGetTextureParameterIivEXT(GLuint texture, GLenum target, GLenum pname, GLint * params) {
	static const auto glGetTextureParameterIivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLenum, GLint *)>(getProcAddress("glGetTextureParameterIivEXT"));
	assert(glGetTextureParameterIivEXT_ != nullptr);
	return glGetTextureParameterIivEXT_(texture, target, pname, params);
}
void glGetTextureParameterIuivEXT(GLuint texture, GLenum target, GLenum pname, GLuint * params) {
	static const auto glGetTextureParameterIuivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLenum, GLuint *)>(getProcAddress("glGetTextureParameterIuivEXT"));
	assert(glGetTextureParameterIuivEXT_ != nullptr);
	return glGetTextureParameterIuivEXT_(texture, target, pname, params);
}
void glMultiTexParameterIivEXT(GLenum texunit, GLenum target, GLenum pname, GLint const  * params) {
	static const auto glMultiTexParameterIivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLint const  *)>(getProcAddress("glMultiTexParameterIivEXT"));
	assert(glMultiTexParameterIivEXT_ != nullptr);
	return glMultiTexParameterIivEXT_(texunit, target, pname, params);
}
void glMultiTexParameterIuivEXT(GLenum texunit, GLenum target, GLenum pname, GLuint const  * params) {
	static const auto glMultiTexParameterIuivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLuint const  *)>(getProcAddress("glMultiTexParameterIuivEXT"));
	assert(glMultiTexParameterIuivEXT_ != nullptr);
	return glMultiTexParameterIuivEXT_(texunit, target, pname, params);
}
void glGetMultiTexParameterIivEXT(GLenum texunit, GLenum target, GLenum pname, GLint * params) {
	static const auto glGetMultiTexParameterIivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLint *)>(getProcAddress("glGetMultiTexParameterIivEXT"));
	assert(glGetMultiTexParameterIivEXT_ != nullptr);
	return glGetMultiTexParameterIivEXT_(texunit, target, pname, params);
}
void glGetMultiTexParameterIuivEXT(GLenum texunit, GLenum target, GLenum pname, GLuint * params) {
	static const auto glGetMultiTexParameterIuivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLuint *)>(getProcAddress("glGetMultiTexParameterIuivEXT"));
	assert(glGetMultiTexParameterIuivEXT_ != nullptr);
	return glGetMultiTexParameterIuivEXT_(texunit, target, pname, params);
}
void glProgramUniform1uiEXT(GLuint program, GLint location, GLuint v0) {
	static const auto glProgramUniform1uiEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLuint)>(getProcAddress("glProgramUniform1uiEXT"));
	assert(glProgramUniform1uiEXT_ != nullptr);
	return glProgramUniform1uiEXT_(program, location, v0);
}
void glProgramUniform2uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1) {
	static const auto glProgramUniform2uiEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLuint, GLuint)>(getProcAddress("glProgramUniform2uiEXT"));
	assert(glProgramUniform2uiEXT_ != nullptr);
	return glProgramUniform2uiEXT_(program, location, v0, v1);
}
void glProgramUniform3uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2) {
	static const auto glProgramUniform3uiEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLuint, GLuint, GLuint)>(getProcAddress("glProgramUniform3uiEXT"));
	assert(glProgramUniform3uiEXT_ != nullptr);
	return glProgramUniform3uiEXT_(program, location, v0, v1, v2);
}
void glProgramUniform4uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) {
	static const auto glProgramUniform4uiEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLuint, GLuint, GLuint, GLuint)>(getProcAddress("glProgramUniform4uiEXT"));
	assert(glProgramUniform4uiEXT_ != nullptr);
	return glProgramUniform4uiEXT_(program, location, v0, v1, v2, v3);
}
void glProgramUniform1uivEXT(GLuint program, GLint location, GLsizei count, GLuint const  * value) {
	static const auto glProgramUniform1uivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLuint const  *)>(getProcAddress("glProgramUniform1uivEXT"));
	assert(glProgramUniform1uivEXT_ != nullptr);
	return glProgramUniform1uivEXT_(program, location, count, value);
}
void glProgramUniform2uivEXT(GLuint program, GLint location, GLsizei count, GLuint const  * value) {
	static const auto glProgramUniform2uivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLuint const  *)>(getProcAddress("glProgramUniform2uivEXT"));
	assert(glProgramUniform2uivEXT_ != nullptr);
	return glProgramUniform2uivEXT_(program, location, count, value);
}
void glProgramUniform3uivEXT(GLuint program, GLint location, GLsizei count, GLuint const  * value) {
	static const auto glProgramUniform3uivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLuint const  *)>(getProcAddress("glProgramUniform3uivEXT"));
	assert(glProgramUniform3uivEXT_ != nullptr);
	return glProgramUniform3uivEXT_(program, location, count, value);
}
void glProgramUniform4uivEXT(GLuint program, GLint location, GLsizei count, GLuint const  * value) {
	static const auto glProgramUniform4uivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLuint const  *)>(getProcAddress("glProgramUniform4uivEXT"));
	assert(glProgramUniform4uivEXT_ != nullptr);
	return glProgramUniform4uivEXT_(program, location, count, value);
}
void glNamedProgramLocalParameters4fvEXT(GLuint program, GLenum target, GLuint index, GLsizei count, GLfloat const  * params) {
	static const auto glNamedProgramLocalParameters4fvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLuint, GLsizei, GLfloat const  *)>(getProcAddress("glNamedProgramLocalParameters4fvEXT"));
	assert(glNamedProgramLocalParameters4fvEXT_ != nullptr);
	return glNamedProgramLocalParameters4fvEXT_(program, target, index, count, params);
}
void glNamedProgramLocalParameterI4iEXT(GLuint program, GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w) {
	static const auto glNamedProgramLocalParameterI4iEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLuint, GLint, GLint, GLint, GLint)>(getProcAddress("glNamedProgramLocalParameterI4iEXT"));
	assert(glNamedProgramLocalParameterI4iEXT_ != nullptr);
	return glNamedProgramLocalParameterI4iEXT_(program, target, index, x, y, z, w);
}
void glNamedProgramLocalParameterI4ivEXT(GLuint program, GLenum target, GLuint index, GLint const  * params) {
	static const auto glNamedProgramLocalParameterI4ivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLuint, GLint const  *)>(getProcAddress("glNamedProgramLocalParameterI4ivEXT"));
	assert(glNamedProgramLocalParameterI4ivEXT_ != nullptr);
	return glNamedProgramLocalParameterI4ivEXT_(program, target, index, params);
}
void glNamedProgramLocalParametersI4ivEXT(GLuint program, GLenum target, GLuint index, GLsizei count, GLint const  * params) {
	static const auto glNamedProgramLocalParametersI4ivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLuint, GLsizei, GLint const  *)>(getProcAddress("glNamedProgramLocalParametersI4ivEXT"));
	assert(glNamedProgramLocalParametersI4ivEXT_ != nullptr);
	return glNamedProgramLocalParametersI4ivEXT_(program, target, index, count, params);
}
void glNamedProgramLocalParameterI4uiEXT(GLuint program, GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) {
	static const auto glNamedProgramLocalParameterI4uiEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLuint, GLuint, GLuint, GLuint, GLuint)>(getProcAddress("glNamedProgramLocalParameterI4uiEXT"));
	assert(glNamedProgramLocalParameterI4uiEXT_ != nullptr);
	return glNamedProgramLocalParameterI4uiEXT_(program, target, index, x, y, z, w);
}
void glNamedProgramLocalParameterI4uivEXT(GLuint program, GLenum target, GLuint index, GLuint const  * params) {
	static const auto glNamedProgramLocalParameterI4uivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLuint, GLuint const  *)>(getProcAddress("glNamedProgramLocalParameterI4uivEXT"));
	assert(glNamedProgramLocalParameterI4uivEXT_ != nullptr);
	return glNamedProgramLocalParameterI4uivEXT_(program, target, index, params);
}
void glNamedProgramLocalParametersI4uivEXT(GLuint program, GLenum target, GLuint index, GLsizei count, GLuint const  * params) {
	static const auto glNamedProgramLocalParametersI4uivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLuint, GLsizei, GLuint const  *)>(getProcAddress("glNamedProgramLocalParametersI4uivEXT"));
	assert(glNamedProgramLocalParametersI4uivEXT_ != nullptr);
	return glNamedProgramLocalParametersI4uivEXT_(program, target, index, count, params);
}
void glGetNamedProgramLocalParameterIivEXT(GLuint program, GLenum target, GLuint index, GLint * params) {
	static const auto glGetNamedProgramLocalParameterIivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLuint, GLint *)>(getProcAddress("glGetNamedProgramLocalParameterIivEXT"));
	assert(glGetNamedProgramLocalParameterIivEXT_ != nullptr);
	return glGetNamedProgramLocalParameterIivEXT_(program, target, index, params);
}
void glGetNamedProgramLocalParameterIuivEXT(GLuint program, GLenum target, GLuint index, GLuint * params) {
	static const auto glGetNamedProgramLocalParameterIuivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLuint, GLuint *)>(getProcAddress("glGetNamedProgramLocalParameterIuivEXT"));
	assert(glGetNamedProgramLocalParameterIuivEXT_ != nullptr);
	return glGetNamedProgramLocalParameterIuivEXT_(program, target, index, params);
}
void glEnableClientStateiEXT(GLenum array, GLuint index) {
	static const auto glEnableClientStateiEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint)>(getProcAddress("glEnableClientStateiEXT"));
	assert(glEnableClientStateiEXT_ != nullptr);
	return glEnableClientStateiEXT_(array, index);
}
void glDisableClientStateiEXT(GLenum array, GLuint index) {
	static const auto glDisableClientStateiEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint)>(getProcAddress("glDisableClientStateiEXT"));
	assert(glDisableClientStateiEXT_ != nullptr);
	return glDisableClientStateiEXT_(array, index);
}
void glGetFloati_vEXT(GLenum pname, GLuint index, GLfloat * params) {
	static const auto glGetFloati_vEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint, GLfloat *)>(getProcAddress("glGetFloati_vEXT"));
	assert(glGetFloati_vEXT_ != nullptr);
	return glGetFloati_vEXT_(pname, index, params);
}
void glGetDoublei_vEXT(GLenum pname, GLuint index, GLdouble * params) {
	static const auto glGetDoublei_vEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint, GLdouble *)>(getProcAddress("glGetDoublei_vEXT"));
	assert(glGetDoublei_vEXT_ != nullptr);
	return glGetDoublei_vEXT_(pname, index, params);
}
void glGetPointeri_vEXT(GLenum pname, GLuint index, void ** params) {
	static const auto glGetPointeri_vEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint, void **)>(getProcAddress("glGetPointeri_vEXT"));
	assert(glGetPointeri_vEXT_ != nullptr);
	return glGetPointeri_vEXT_(pname, index, params);
}
void glNamedProgramStringEXT(GLuint program, GLenum target, GLenum format, GLsizei len, const void * string) {
	static const auto glNamedProgramStringEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLenum, GLsizei, const void *)>(getProcAddress("glNamedProgramStringEXT"));
	assert(glNamedProgramStringEXT_ != nullptr);
	return glNamedProgramStringEXT_(program, target, format, len, string);
}
void glNamedProgramLocalParameter4dEXT(GLuint program, GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
	static const auto glNamedProgramLocalParameter4dEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLuint, GLdouble, GLdouble, GLdouble, GLdouble)>(getProcAddress("glNamedProgramLocalParameter4dEXT"));
	assert(glNamedProgramLocalParameter4dEXT_ != nullptr);
	return glNamedProgramLocalParameter4dEXT_(program, target, index, x, y, z, w);
}
void glNamedProgramLocalParameter4dvEXT(GLuint program, GLenum target, GLuint index, GLdouble const  * params) {
	static const auto glNamedProgramLocalParameter4dvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLuint, GLdouble const  *)>(getProcAddress("glNamedProgramLocalParameter4dvEXT"));
	assert(glNamedProgramLocalParameter4dvEXT_ != nullptr);
	return glNamedProgramLocalParameter4dvEXT_(program, target, index, params);
}
void glNamedProgramLocalParameter4fEXT(GLuint program, GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
	static const auto glNamedProgramLocalParameter4fEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLuint, GLfloat, GLfloat, GLfloat, GLfloat)>(getProcAddress("glNamedProgramLocalParameter4fEXT"));
	assert(glNamedProgramLocalParameter4fEXT_ != nullptr);
	return glNamedProgramLocalParameter4fEXT_(program, target, index, x, y, z, w);
}
void glNamedProgramLocalParameter4fvEXT(GLuint program, GLenum target, GLuint index, GLfloat const  * params) {
	static const auto glNamedProgramLocalParameter4fvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLuint, GLfloat const  *)>(getProcAddress("glNamedProgramLocalParameter4fvEXT"));
	assert(glNamedProgramLocalParameter4fvEXT_ != nullptr);
	return glNamedProgramLocalParameter4fvEXT_(program, target, index, params);
}
void glGetNamedProgramLocalParameterdvEXT(GLuint program, GLenum target, GLuint index, GLdouble * params) {
	static const auto glGetNamedProgramLocalParameterdvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLuint, GLdouble *)>(getProcAddress("glGetNamedProgramLocalParameterdvEXT"));
	assert(glGetNamedProgramLocalParameterdvEXT_ != nullptr);
	return glGetNamedProgramLocalParameterdvEXT_(program, target, index, params);
}
void glGetNamedProgramLocalParameterfvEXT(GLuint program, GLenum target, GLuint index, GLfloat * params) {
	static const auto glGetNamedProgramLocalParameterfvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLuint, GLfloat *)>(getProcAddress("glGetNamedProgramLocalParameterfvEXT"));
	assert(glGetNamedProgramLocalParameterfvEXT_ != nullptr);
	return glGetNamedProgramLocalParameterfvEXT_(program, target, index, params);
}
void glGetNamedProgramivEXT(GLuint program, GLenum target, GLenum pname, GLint * params) {
	static const auto glGetNamedProgramivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLenum, GLint *)>(getProcAddress("glGetNamedProgramivEXT"));
	assert(glGetNamedProgramivEXT_ != nullptr);
	return glGetNamedProgramivEXT_(program, target, pname, params);
}
void glGetNamedProgramStringEXT(GLuint program, GLenum target, GLenum pname, void * string) {
	static const auto glGetNamedProgramStringEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLenum, void *)>(getProcAddress("glGetNamedProgramStringEXT"));
	assert(glGetNamedProgramStringEXT_ != nullptr);
	return glGetNamedProgramStringEXT_(program, target, pname, string);
}
void glNamedRenderbufferStorageEXT(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height) {
	static const auto glNamedRenderbufferStorageEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLsizei, GLsizei)>(getProcAddress("glNamedRenderbufferStorageEXT"));
	assert(glNamedRenderbufferStorageEXT_ != nullptr);
	return glNamedRenderbufferStorageEXT_(renderbuffer, internalformat, width, height);
}
void glGetNamedRenderbufferParameterivEXT(GLuint renderbuffer, GLenum pname, GLint * params) {
	static const auto glGetNamedRenderbufferParameterivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint *)>(getProcAddress("glGetNamedRenderbufferParameterivEXT"));
	assert(glGetNamedRenderbufferParameterivEXT_ != nullptr);
	return glGetNamedRenderbufferParameterivEXT_(renderbuffer, pname, params);
}
void glNamedRenderbufferStorageMultisampleEXT(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) {
	static const auto glNamedRenderbufferStorageMultisampleEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLsizei, GLenum, GLsizei, GLsizei)>(getProcAddress("glNamedRenderbufferStorageMultisampleEXT"));
	assert(glNamedRenderbufferStorageMultisampleEXT_ != nullptr);
	return glNamedRenderbufferStorageMultisampleEXT_(renderbuffer, samples, internalformat, width, height);
}
void glNamedRenderbufferStorageMultisampleCoverageEXT(GLuint renderbuffer, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height) {
	static const auto glNamedRenderbufferStorageMultisampleCoverageEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLsizei, GLsizei, GLenum, GLsizei, GLsizei)>(getProcAddress("glNamedRenderbufferStorageMultisampleCoverageEXT"));
	assert(glNamedRenderbufferStorageMultisampleCoverageEXT_ != nullptr);
	return glNamedRenderbufferStorageMultisampleCoverageEXT_(renderbuffer, coverageSamples, colorSamples, internalformat, width, height);
}
GLenum glCheckNamedFramebufferStatusEXT(GLuint framebuffer, GLenum target) {
	static const auto glCheckNamedFramebufferStatusEXT_ = reinterpret_cast<GLenum(GL_APIENTRYP)(GLuint, GLenum)>(getProcAddress("glCheckNamedFramebufferStatusEXT"));
	assert(glCheckNamedFramebufferStatusEXT_ != nullptr);
	return glCheckNamedFramebufferStatusEXT_(framebuffer, target);
}
void glNamedFramebufferTexture1DEXT(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {
	static const auto glNamedFramebufferTexture1DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLenum, GLuint, GLint)>(getProcAddress("glNamedFramebufferTexture1DEXT"));
	assert(glNamedFramebufferTexture1DEXT_ != nullptr);
	return glNamedFramebufferTexture1DEXT_(framebuffer, attachment, textarget, texture, level);
}
void glNamedFramebufferTexture2DEXT(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {
	static const auto glNamedFramebufferTexture2DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLenum, GLuint, GLint)>(getProcAddress("glNamedFramebufferTexture2DEXT"));
	assert(glNamedFramebufferTexture2DEXT_ != nullptr);
	return glNamedFramebufferTexture2DEXT_(framebuffer, attachment, textarget, texture, level);
}
void glNamedFramebufferTexture3DEXT(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset) {
	static const auto glNamedFramebufferTexture3DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLenum, GLuint, GLint, GLint)>(getProcAddress("glNamedFramebufferTexture3DEXT"));
	assert(glNamedFramebufferTexture3DEXT_ != nullptr);
	return glNamedFramebufferTexture3DEXT_(framebuffer, attachment, textarget, texture, level, zoffset);
}
void glNamedFramebufferRenderbufferEXT(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) {
	static const auto glNamedFramebufferRenderbufferEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLenum, GLuint)>(getProcAddress("glNamedFramebufferRenderbufferEXT"));
	assert(glNamedFramebufferRenderbufferEXT_ != nullptr);
	return glNamedFramebufferRenderbufferEXT_(framebuffer, attachment, renderbuffertarget, renderbuffer);
}
void glGetNamedFramebufferAttachmentParameterivEXT(GLuint framebuffer, GLenum attachment, GLenum pname, GLint * params) {
	static const auto glGetNamedFramebufferAttachmentParameterivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLenum, GLint *)>(getProcAddress("glGetNamedFramebufferAttachmentParameterivEXT"));
	assert(glGetNamedFramebufferAttachmentParameterivEXT_ != nullptr);
	return glGetNamedFramebufferAttachmentParameterivEXT_(framebuffer, attachment, pname, params);
}
void glGenerateTextureMipmapEXT(GLuint texture, GLenum target) {
	static const auto glGenerateTextureMipmapEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum)>(getProcAddress("glGenerateTextureMipmapEXT"));
	assert(glGenerateTextureMipmapEXT_ != nullptr);
	return glGenerateTextureMipmapEXT_(texture, target);
}
void glGenerateMultiTexMipmapEXT(GLenum texunit, GLenum target) {
	static const auto glGenerateMultiTexMipmapEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum)>(getProcAddress("glGenerateMultiTexMipmapEXT"));
	assert(glGenerateMultiTexMipmapEXT_ != nullptr);
	return glGenerateMultiTexMipmapEXT_(texunit, target);
}
void glFramebufferDrawBufferEXT(GLuint framebuffer, GLenum mode) {
	static const auto glFramebufferDrawBufferEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum)>(getProcAddress("glFramebufferDrawBufferEXT"));
	assert(glFramebufferDrawBufferEXT_ != nullptr);
	return glFramebufferDrawBufferEXT_(framebuffer, mode);
}
void glFramebufferDrawBuffersEXT(GLuint framebuffer, GLsizei n, GLenum const  * bufs) {
	static const auto glFramebufferDrawBuffersEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLsizei, GLenum const  *)>(getProcAddress("glFramebufferDrawBuffersEXT"));
	assert(glFramebufferDrawBuffersEXT_ != nullptr);
	return glFramebufferDrawBuffersEXT_(framebuffer, n, bufs);
}
void glFramebufferReadBufferEXT(GLuint framebuffer, GLenum mode) {
	static const auto glFramebufferReadBufferEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum)>(getProcAddress("glFramebufferReadBufferEXT"));
	assert(glFramebufferReadBufferEXT_ != nullptr);
	return glFramebufferReadBufferEXT_(framebuffer, mode);
}
void glGetFramebufferParameterivEXT(GLuint framebuffer, GLenum pname, GLint * params) {
	static const auto glGetFramebufferParameterivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint *)>(getProcAddress("glGetFramebufferParameterivEXT"));
	assert(glGetFramebufferParameterivEXT_ != nullptr);
	return glGetFramebufferParameterivEXT_(framebuffer, pname, params);
}
void glNamedCopyBufferSubDataEXT(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) {
	static const auto glNamedCopyBufferSubDataEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLintptr, GLintptr, GLsizeiptr)>(getProcAddress("glNamedCopyBufferSubDataEXT"));
	assert(glNamedCopyBufferSubDataEXT_ != nullptr);
	return glNamedCopyBufferSubDataEXT_(readBuffer, writeBuffer, readOffset, writeOffset, size);
}
void glNamedFramebufferTextureEXT(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level) {
	static const auto glNamedFramebufferTextureEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLuint, GLint)>(getProcAddress("glNamedFramebufferTextureEXT"));
	assert(glNamedFramebufferTextureEXT_ != nullptr);
	return glNamedFramebufferTextureEXT_(framebuffer, attachment, texture, level);
}
void glNamedFramebufferTextureLayerEXT(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer) {
	static const auto glNamedFramebufferTextureLayerEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLuint, GLint, GLint)>(getProcAddress("glNamedFramebufferTextureLayerEXT"));
	assert(glNamedFramebufferTextureLayerEXT_ != nullptr);
	return glNamedFramebufferTextureLayerEXT_(framebuffer, attachment, texture, level, layer);
}
void glNamedFramebufferTextureFaceEXT(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLenum face) {
	static const auto glNamedFramebufferTextureFaceEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLuint, GLint, GLenum)>(getProcAddress("glNamedFramebufferTextureFaceEXT"));
	assert(glNamedFramebufferTextureFaceEXT_ != nullptr);
	return glNamedFramebufferTextureFaceEXT_(framebuffer, attachment, texture, level, face);
}
void glTextureRenderbufferEXT(GLuint texture, GLenum target, GLuint renderbuffer) {
	static const auto glTextureRenderbufferEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLuint)>(getProcAddress("glTextureRenderbufferEXT"));
	assert(glTextureRenderbufferEXT_ != nullptr);
	return glTextureRenderbufferEXT_(texture, target, renderbuffer);
}
void glMultiTexRenderbufferEXT(GLenum texunit, GLenum target, GLuint renderbuffer) {
	static const auto glMultiTexRenderbufferEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLuint)>(getProcAddress("glMultiTexRenderbufferEXT"));
	assert(glMultiTexRenderbufferEXT_ != nullptr);
	return glMultiTexRenderbufferEXT_(texunit, target, renderbuffer);
}
void glVertexArrayVertexOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset) {
	static const auto glVertexArrayVertexOffsetEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLint, GLenum, GLsizei, GLintptr)>(getProcAddress("glVertexArrayVertexOffsetEXT"));
	assert(glVertexArrayVertexOffsetEXT_ != nullptr);
	return glVertexArrayVertexOffsetEXT_(vaobj, buffer, size, type, stride, offset);
}
void glVertexArrayColorOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset) {
	static const auto glVertexArrayColorOffsetEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLint, GLenum, GLsizei, GLintptr)>(getProcAddress("glVertexArrayColorOffsetEXT"));
	assert(glVertexArrayColorOffsetEXT_ != nullptr);
	return glVertexArrayColorOffsetEXT_(vaobj, buffer, size, type, stride, offset);
}
void glVertexArrayEdgeFlagOffsetEXT(GLuint vaobj, GLuint buffer, GLsizei stride, GLintptr offset) {
	static const auto glVertexArrayEdgeFlagOffsetEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLsizei, GLintptr)>(getProcAddress("glVertexArrayEdgeFlagOffsetEXT"));
	assert(glVertexArrayEdgeFlagOffsetEXT_ != nullptr);
	return glVertexArrayEdgeFlagOffsetEXT_(vaobj, buffer, stride, offset);
}
void glVertexArrayIndexOffsetEXT(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset) {
	static const auto glVertexArrayIndexOffsetEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLenum, GLsizei, GLintptr)>(getProcAddress("glVertexArrayIndexOffsetEXT"));
	assert(glVertexArrayIndexOffsetEXT_ != nullptr);
	return glVertexArrayIndexOffsetEXT_(vaobj, buffer, type, stride, offset);
}
void glVertexArrayNormalOffsetEXT(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset) {
	static const auto glVertexArrayNormalOffsetEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLenum, GLsizei, GLintptr)>(getProcAddress("glVertexArrayNormalOffsetEXT"));
	assert(glVertexArrayNormalOffsetEXT_ != nullptr);
	return glVertexArrayNormalOffsetEXT_(vaobj, buffer, type, stride, offset);
}
void glVertexArrayTexCoordOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset) {
	static const auto glVertexArrayTexCoordOffsetEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLint, GLenum, GLsizei, GLintptr)>(getProcAddress("glVertexArrayTexCoordOffsetEXT"));
	assert(glVertexArrayTexCoordOffsetEXT_ != nullptr);
	return glVertexArrayTexCoordOffsetEXT_(vaobj, buffer, size, type, stride, offset);
}
void glVertexArrayMultiTexCoordOffsetEXT(GLuint vaobj, GLuint buffer, GLenum texunit, GLint size, GLenum type, GLsizei stride, GLintptr offset) {
	static const auto glVertexArrayMultiTexCoordOffsetEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLenum, GLint, GLenum, GLsizei, GLintptr)>(getProcAddress("glVertexArrayMultiTexCoordOffsetEXT"));
	assert(glVertexArrayMultiTexCoordOffsetEXT_ != nullptr);
	return glVertexArrayMultiTexCoordOffsetEXT_(vaobj, buffer, texunit, size, type, stride, offset);
}
void glVertexArrayFogCoordOffsetEXT(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset) {
	static const auto glVertexArrayFogCoordOffsetEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLenum, GLsizei, GLintptr)>(getProcAddress("glVertexArrayFogCoordOffsetEXT"));
	assert(glVertexArrayFogCoordOffsetEXT_ != nullptr);
	return glVertexArrayFogCoordOffsetEXT_(vaobj, buffer, type, stride, offset);
}
void glVertexArraySecondaryColorOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset) {
	static const auto glVertexArraySecondaryColorOffsetEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLint, GLenum, GLsizei, GLintptr)>(getProcAddress("glVertexArraySecondaryColorOffsetEXT"));
	assert(glVertexArraySecondaryColorOffsetEXT_ != nullptr);
	return glVertexArraySecondaryColorOffsetEXT_(vaobj, buffer, size, type, stride, offset);
}
void glVertexArrayVertexAttribOffsetEXT(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLintptr offset) {
	static const auto glVertexArrayVertexAttribOffsetEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLuint, GLint, GLenum, GLboolean, GLsizei, GLintptr)>(getProcAddress("glVertexArrayVertexAttribOffsetEXT"));
	assert(glVertexArrayVertexAttribOffsetEXT_ != nullptr);
	return glVertexArrayVertexAttribOffsetEXT_(vaobj, buffer, index, size, type, normalized, stride, offset);
}
void glVertexArrayVertexAttribIOffsetEXT(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset) {
	static const auto glVertexArrayVertexAttribIOffsetEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLuint, GLint, GLenum, GLsizei, GLintptr)>(getProcAddress("glVertexArrayVertexAttribIOffsetEXT"));
	assert(glVertexArrayVertexAttribIOffsetEXT_ != nullptr);
	return glVertexArrayVertexAttribIOffsetEXT_(vaobj, buffer, index, size, type, stride, offset);
}
void glEnableVertexArrayEXT(GLuint vaobj, GLenum array) {
	static const auto glEnableVertexArrayEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum)>(getProcAddress("glEnableVertexArrayEXT"));
	assert(glEnableVertexArrayEXT_ != nullptr);
	return glEnableVertexArrayEXT_(vaobj, array);
}
void glDisableVertexArrayEXT(GLuint vaobj, GLenum array) {
	static const auto glDisableVertexArrayEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum)>(getProcAddress("glDisableVertexArrayEXT"));
	assert(glDisableVertexArrayEXT_ != nullptr);
	return glDisableVertexArrayEXT_(vaobj, array);
}
void glEnableVertexArrayAttribEXT(GLuint vaobj, GLuint index) {
	static const auto glEnableVertexArrayAttribEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint)>(getProcAddress("glEnableVertexArrayAttribEXT"));
	assert(glEnableVertexArrayAttribEXT_ != nullptr);
	return glEnableVertexArrayAttribEXT_(vaobj, index);
}
void glDisableVertexArrayAttribEXT(GLuint vaobj, GLuint index) {
	static const auto glDisableVertexArrayAttribEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint)>(getProcAddress("glDisableVertexArrayAttribEXT"));
	assert(glDisableVertexArrayAttribEXT_ != nullptr);
	return glDisableVertexArrayAttribEXT_(vaobj, index);
}
void glGetVertexArrayIntegervEXT(GLuint vaobj, GLenum pname, GLint * param) {
	static const auto glGetVertexArrayIntegervEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint *)>(getProcAddress("glGetVertexArrayIntegervEXT"));
	assert(glGetVertexArrayIntegervEXT_ != nullptr);
	return glGetVertexArrayIntegervEXT_(vaobj, pname, param);
}
void glGetVertexArrayPointervEXT(GLuint vaobj, GLenum pname, void ** param) {
	static const auto glGetVertexArrayPointervEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, void **)>(getProcAddress("glGetVertexArrayPointervEXT"));
	assert(glGetVertexArrayPointervEXT_ != nullptr);
	return glGetVertexArrayPointervEXT_(vaobj, pname, param);
}
void glGetVertexArrayIntegeri_vEXT(GLuint vaobj, GLuint index, GLenum pname, GLint * param) {
	static const auto glGetVertexArrayIntegeri_vEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLenum, GLint *)>(getProcAddress("glGetVertexArrayIntegeri_vEXT"));
	assert(glGetVertexArrayIntegeri_vEXT_ != nullptr);
	return glGetVertexArrayIntegeri_vEXT_(vaobj, index, pname, param);
}
void glGetVertexArrayPointeri_vEXT(GLuint vaobj, GLuint index, GLenum pname, void ** param) {
	static const auto glGetVertexArrayPointeri_vEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLenum, void **)>(getProcAddress("glGetVertexArrayPointeri_vEXT"));
	assert(glGetVertexArrayPointeri_vEXT_ != nullptr);
	return glGetVertexArrayPointeri_vEXT_(vaobj, index, pname, param);
}
void * glMapNamedBufferRangeEXT(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access) {
	static const auto glMapNamedBufferRangeEXT_ = reinterpret_cast<void *(GL_APIENTRYP)(GLuint, GLintptr, GLsizeiptr, GLbitfield)>(getProcAddress("glMapNamedBufferRangeEXT"));
	assert(glMapNamedBufferRangeEXT_ != nullptr);
	return glMapNamedBufferRangeEXT_(buffer, offset, length, access);
}
void glFlushMappedNamedBufferRangeEXT(GLuint buffer, GLintptr offset, GLsizeiptr length) {
	static const auto glFlushMappedNamedBufferRangeEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLintptr, GLsizeiptr)>(getProcAddress("glFlushMappedNamedBufferRangeEXT"));
	assert(glFlushMappedNamedBufferRangeEXT_ != nullptr);
	return glFlushMappedNamedBufferRangeEXT_(buffer, offset, length);
}
void glNamedBufferStorageEXT(GLuint buffer, GLsizeiptr size, const void * data, GLbitfield flags) {
	static const auto glNamedBufferStorageEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLsizeiptr, const void *, GLbitfield)>(getProcAddress("glNamedBufferStorageEXT"));
	assert(glNamedBufferStorageEXT_ != nullptr);
	return glNamedBufferStorageEXT_(buffer, size, data, flags);
}
void glClearNamedBufferDataEXT(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void * data) {
	static const auto glClearNamedBufferDataEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLenum, GLenum, const void *)>(getProcAddress("glClearNamedBufferDataEXT"));
	assert(glClearNamedBufferDataEXT_ != nullptr);
	return glClearNamedBufferDataEXT_(buffer, internalformat, format, type, data);
}
void glClearNamedBufferSubDataEXT(GLuint buffer, GLenum internalformat, GLsizeiptr offset, GLsizeiptr size, GLenum format, GLenum type, const void * data) {
	static const auto glClearNamedBufferSubDataEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLsizeiptr, GLsizeiptr, GLenum, GLenum, const void *)>(getProcAddress("glClearNamedBufferSubDataEXT"));
	assert(glClearNamedBufferSubDataEXT_ != nullptr);
	return glClearNamedBufferSubDataEXT_(buffer, internalformat, offset, size, format, type, data);
}
void glNamedFramebufferParameteriEXT(GLuint framebuffer, GLenum pname, GLint param) {
	static const auto glNamedFramebufferParameteriEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint)>(getProcAddress("glNamedFramebufferParameteriEXT"));
	assert(glNamedFramebufferParameteriEXT_ != nullptr);
	return glNamedFramebufferParameteriEXT_(framebuffer, pname, param);
}
void glGetNamedFramebufferParameterivEXT(GLuint framebuffer, GLenum pname, GLint * params) {
	static const auto glGetNamedFramebufferParameterivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint *)>(getProcAddress("glGetNamedFramebufferParameterivEXT"));
	assert(glGetNamedFramebufferParameterivEXT_ != nullptr);
	return glGetNamedFramebufferParameterivEXT_(framebuffer, pname, params);
}
void glProgramUniform1dEXT(GLuint program, GLint location, GLdouble x) {
	static const auto glProgramUniform1dEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLdouble)>(getProcAddress("glProgramUniform1dEXT"));
	assert(glProgramUniform1dEXT_ != nullptr);
	return glProgramUniform1dEXT_(program, location, x);
}
void glProgramUniform2dEXT(GLuint program, GLint location, GLdouble x, GLdouble y) {
	static const auto glProgramUniform2dEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLdouble, GLdouble)>(getProcAddress("glProgramUniform2dEXT"));
	assert(glProgramUniform2dEXT_ != nullptr);
	return glProgramUniform2dEXT_(program, location, x, y);
}
void glProgramUniform3dEXT(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z) {
	static const auto glProgramUniform3dEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLdouble, GLdouble, GLdouble)>(getProcAddress("glProgramUniform3dEXT"));
	assert(glProgramUniform3dEXT_ != nullptr);
	return glProgramUniform3dEXT_(program, location, x, y, z);
}
void glProgramUniform4dEXT(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
	static const auto glProgramUniform4dEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLdouble, GLdouble, GLdouble, GLdouble)>(getProcAddress("glProgramUniform4dEXT"));
	assert(glProgramUniform4dEXT_ != nullptr);
	return glProgramUniform4dEXT_(program, location, x, y, z, w);
}
void glProgramUniform1dvEXT(GLuint program, GLint location, GLsizei count, GLdouble const  * value) {
	static const auto glProgramUniform1dvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLdouble const  *)>(getProcAddress("glProgramUniform1dvEXT"));
	assert(glProgramUniform1dvEXT_ != nullptr);
	return glProgramUniform1dvEXT_(program, location, count, value);
}
void glProgramUniform2dvEXT(GLuint program, GLint location, GLsizei count, GLdouble const  * value) {
	static const auto glProgramUniform2dvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLdouble const  *)>(getProcAddress("glProgramUniform2dvEXT"));
	assert(glProgramUniform2dvEXT_ != nullptr);
	return glProgramUniform2dvEXT_(program, location, count, value);
}
void glProgramUniform3dvEXT(GLuint program, GLint location, GLsizei count, GLdouble const  * value) {
	static const auto glProgramUniform3dvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLdouble const  *)>(getProcAddress("glProgramUniform3dvEXT"));
	assert(glProgramUniform3dvEXT_ != nullptr);
	return glProgramUniform3dvEXT_(program, location, count, value);
}
void glProgramUniform4dvEXT(GLuint program, GLint location, GLsizei count, GLdouble const  * value) {
	static const auto glProgramUniform4dvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLdouble const  *)>(getProcAddress("glProgramUniform4dvEXT"));
	assert(glProgramUniform4dvEXT_ != nullptr);
	return glProgramUniform4dvEXT_(program, location, count, value);
}
void glProgramUniformMatrix2dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble const  * value) {
	static const auto glProgramUniformMatrix2dvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLboolean, GLdouble const  *)>(getProcAddress("glProgramUniformMatrix2dvEXT"));
	assert(glProgramUniformMatrix2dvEXT_ != nullptr);
	return glProgramUniformMatrix2dvEXT_(program, location, count, transpose, value);
}
void glProgramUniformMatrix3dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble const  * value) {
	static const auto glProgramUniformMatrix3dvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLboolean, GLdouble const  *)>(getProcAddress("glProgramUniformMatrix3dvEXT"));
	assert(glProgramUniformMatrix3dvEXT_ != nullptr);
	return glProgramUniformMatrix3dvEXT_(program, location, count, transpose, value);
}
void glProgramUniformMatrix4dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble const  * value) {
	static const auto glProgramUniformMatrix4dvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLboolean, GLdouble const  *)>(getProcAddress("glProgramUniformMatrix4dvEXT"));
	assert(glProgramUniformMatrix4dvEXT_ != nullptr);
	return glProgramUniformMatrix4dvEXT_(program, location, count, transpose, value);
}
void glProgramUniformMatrix2x3dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble const  * value) {
	static const auto glProgramUniformMatrix2x3dvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLboolean, GLdouble const  *)>(getProcAddress("glProgramUniformMatrix2x3dvEXT"));
	assert(glProgramUniformMatrix2x3dvEXT_ != nullptr);
	return glProgramUniformMatrix2x3dvEXT_(program, location, count, transpose, value);
}
void glProgramUniformMatrix2x4dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble const  * value) {
	static const auto glProgramUniformMatrix2x4dvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLboolean, GLdouble const  *)>(getProcAddress("glProgramUniformMatrix2x4dvEXT"));
	assert(glProgramUniformMatrix2x4dvEXT_ != nullptr);
	return glProgramUniformMatrix2x4dvEXT_(program, location, count, transpose, value);
}
void glProgramUniformMatrix3x2dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble const  * value) {
	static const auto glProgramUniformMatrix3x2dvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLboolean, GLdouble const  *)>(getProcAddress("glProgramUniformMatrix3x2dvEXT"));
	assert(glProgramUniformMatrix3x2dvEXT_ != nullptr);
	return glProgramUniformMatrix3x2dvEXT_(program, location, count, transpose, value);
}
void glProgramUniformMatrix3x4dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble const  * value) {
	static const auto glProgramUniformMatrix3x4dvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLboolean, GLdouble const  *)>(getProcAddress("glProgramUniformMatrix3x4dvEXT"));
	assert(glProgramUniformMatrix3x4dvEXT_ != nullptr);
	return glProgramUniformMatrix3x4dvEXT_(program, location, count, transpose, value);
}
void glProgramUniformMatrix4x2dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble const  * value) {
	static const auto glProgramUniformMatrix4x2dvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLboolean, GLdouble const  *)>(getProcAddress("glProgramUniformMatrix4x2dvEXT"));
	assert(glProgramUniformMatrix4x2dvEXT_ != nullptr);
	return glProgramUniformMatrix4x2dvEXT_(program, location, count, transpose, value);
}
void glProgramUniformMatrix4x3dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble const  * value) {
	static const auto glProgramUniformMatrix4x3dvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLboolean, GLdouble const  *)>(getProcAddress("glProgramUniformMatrix4x3dvEXT"));
	assert(glProgramUniformMatrix4x3dvEXT_ != nullptr);
	return glProgramUniformMatrix4x3dvEXT_(program, location, count, transpose, value);
}
void glTextureBufferRangeEXT(GLuint texture, GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size) {
	static const auto glTextureBufferRangeEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLenum, GLuint, GLintptr, GLsizeiptr)>(getProcAddress("glTextureBufferRangeEXT"));
	assert(glTextureBufferRangeEXT_ != nullptr);
	return glTextureBufferRangeEXT_(texture, target, internalformat, buffer, offset, size);
}
void glTextureStorage1DEXT(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width) {
	static const auto glTextureStorage1DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLsizei, GLenum, GLsizei)>(getProcAddress("glTextureStorage1DEXT"));
	assert(glTextureStorage1DEXT_ != nullptr);
	return glTextureStorage1DEXT_(texture, target, levels, internalformat, width);
}
void glTextureStorage2DEXT(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) {
	static const auto glTextureStorage2DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLsizei, GLenum, GLsizei, GLsizei)>(getProcAddress("glTextureStorage2DEXT"));
	assert(glTextureStorage2DEXT_ != nullptr);
	return glTextureStorage2DEXT_(texture, target, levels, internalformat, width, height);
}
void glTextureStorage3DEXT(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) {
	static const auto glTextureStorage3DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei)>(getProcAddress("glTextureStorage3DEXT"));
	assert(glTextureStorage3DEXT_ != nullptr);
	return glTextureStorage3DEXT_(texture, target, levels, internalformat, width, height, depth);
}
void glTextureStorage2DMultisampleEXT(GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) {
	static const auto glTextureStorage2DMultisampleEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLboolean)>(getProcAddress("glTextureStorage2DMultisampleEXT"));
	assert(glTextureStorage2DMultisampleEXT_ != nullptr);
	return glTextureStorage2DMultisampleEXT_(texture, target, samples, internalformat, width, height, fixedsamplelocations);
}
void glTextureStorage3DMultisampleEXT(GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) {
	static const auto glTextureStorage3DMultisampleEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei, GLboolean)>(getProcAddress("glTextureStorage3DMultisampleEXT"));
	assert(glTextureStorage3DMultisampleEXT_ != nullptr);
	return glTextureStorage3DMultisampleEXT_(texture, target, samples, internalformat, width, height, depth, fixedsamplelocations);
}
void glVertexArrayBindVertexBufferEXT(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride) {
	static const auto glVertexArrayBindVertexBufferEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLuint, GLintptr, GLsizei)>(getProcAddress("glVertexArrayBindVertexBufferEXT"));
	assert(glVertexArrayBindVertexBufferEXT_ != nullptr);
	return glVertexArrayBindVertexBufferEXT_(vaobj, bindingindex, buffer, offset, stride);
}
void glVertexArrayVertexAttribFormatEXT(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset) {
	static const auto glVertexArrayVertexAttribFormatEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLint, GLenum, GLboolean, GLuint)>(getProcAddress("glVertexArrayVertexAttribFormatEXT"));
	assert(glVertexArrayVertexAttribFormatEXT_ != nullptr);
	return glVertexArrayVertexAttribFormatEXT_(vaobj, attribindex, size, type, normalized, relativeoffset);
}
void glVertexArrayVertexAttribIFormatEXT(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) {
	static const auto glVertexArrayVertexAttribIFormatEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLint, GLenum, GLuint)>(getProcAddress("glVertexArrayVertexAttribIFormatEXT"));
	assert(glVertexArrayVertexAttribIFormatEXT_ != nullptr);
	return glVertexArrayVertexAttribIFormatEXT_(vaobj, attribindex, size, type, relativeoffset);
}
void glVertexArrayVertexAttribLFormatEXT(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) {
	static const auto glVertexArrayVertexAttribLFormatEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLint, GLenum, GLuint)>(getProcAddress("glVertexArrayVertexAttribLFormatEXT"));
	assert(glVertexArrayVertexAttribLFormatEXT_ != nullptr);
	return glVertexArrayVertexAttribLFormatEXT_(vaobj, attribindex, size, type, relativeoffset);
}
void glVertexArrayVertexAttribBindingEXT(GLuint vaobj, GLuint attribindex, GLuint bindingindex) {
	static const auto glVertexArrayVertexAttribBindingEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLuint)>(getProcAddress("glVertexArrayVertexAttribBindingEXT"));
	assert(glVertexArrayVertexAttribBindingEXT_ != nullptr);
	return glVertexArrayVertexAttribBindingEXT_(vaobj, attribindex, bindingindex);
}
void glVertexArrayVertexBindingDivisorEXT(GLuint vaobj, GLuint bindingindex, GLuint divisor) {
	static const auto glVertexArrayVertexBindingDivisorEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLuint)>(getProcAddress("glVertexArrayVertexBindingDivisorEXT"));
	assert(glVertexArrayVertexBindingDivisorEXT_ != nullptr);
	return glVertexArrayVertexBindingDivisorEXT_(vaobj, bindingindex, divisor);
}
void glVertexArrayVertexAttribLOffsetEXT(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset) {
	static const auto glVertexArrayVertexAttribLOffsetEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLuint, GLint, GLenum, GLsizei, GLintptr)>(getProcAddress("glVertexArrayVertexAttribLOffsetEXT"));
	assert(glVertexArrayVertexAttribLOffsetEXT_ != nullptr);
	return glVertexArrayVertexAttribLOffsetEXT_(vaobj, buffer, index, size, type, stride, offset);
}
void glTexturePageCommitmentEXT(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit) {
	static const auto glTexturePageCommitmentEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLboolean)>(getProcAddress("glTexturePageCommitmentEXT"));
	assert(glTexturePageCommitmentEXT_ != nullptr);
	return glTexturePageCommitmentEXT_(texture, level, xoffset, yoffset, zoffset, width, height, depth, commit);
}
void glVertexArrayVertexAttribDivisorEXT(GLuint vaobj, GLuint index, GLuint divisor) {
	static const auto glVertexArrayVertexAttribDivisorEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLuint)>(getProcAddress("glVertexArrayVertexAttribDivisorEXT"));
	assert(glVertexArrayVertexAttribDivisorEXT_ != nullptr);
	return glVertexArrayVertexAttribDivisorEXT_(vaobj, index, divisor);
}
void glColorMaskIndexedEXT(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a) {
	static const auto glColorMaskIndexedEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLboolean, GLboolean, GLboolean, GLboolean)>(getProcAddress("glColorMaskIndexedEXT"));
	assert(glColorMaskIndexedEXT_ != nullptr);
	return glColorMaskIndexedEXT_(index, r, g, b, a);
}
void glDrawArraysInstancedEXT(GLenum mode, GLint start, GLsizei count, GLsizei primcount) {
	static const auto glDrawArraysInstancedEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLsizei, GLsizei)>(getProcAddress("glDrawArraysInstancedEXT"));
	assert(glDrawArraysInstancedEXT_ != nullptr);
	return glDrawArraysInstancedEXT_(mode, start, count, primcount);
}
void glDrawElementsInstancedEXT(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei primcount) {
	static const auto glDrawElementsInstancedEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, GLenum, const void *, GLsizei)>(getProcAddress("glDrawElementsInstancedEXT"));
	assert(glDrawElementsInstancedEXT_ != nullptr);
	return glDrawElementsInstancedEXT_(mode, count, type, indices, primcount);
}
void glDrawRangeElementsEXT(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices) {
	static const auto glDrawRangeElementsEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint, GLuint, GLsizei, GLenum, const void *)>(getProcAddress("glDrawRangeElementsEXT"));
	assert(glDrawRangeElementsEXT_ != nullptr);
	return glDrawRangeElementsEXT_(mode, start, end, count, type, indices);
}
void glBufferStorageExternalEXT(GLenum target, GLintptr offset, GLsizeiptr size, GLeglClientBufferEXT clientBuffer, GLbitfield flags) {
	static const auto glBufferStorageExternalEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLintptr, GLsizeiptr, GLeglClientBufferEXT, GLbitfield)>(getProcAddress("glBufferStorageExternalEXT"));
	assert(glBufferStorageExternalEXT_ != nullptr);
	return glBufferStorageExternalEXT_(target, offset, size, clientBuffer, flags);
}
void glNamedBufferStorageExternalEXT(GLuint buffer, GLintptr offset, GLsizeiptr size, GLeglClientBufferEXT clientBuffer, GLbitfield flags) {
	static const auto glNamedBufferStorageExternalEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLintptr, GLsizeiptr, GLeglClientBufferEXT, GLbitfield)>(getProcAddress("glNamedBufferStorageExternalEXT"));
	assert(glNamedBufferStorageExternalEXT_ != nullptr);
	return glNamedBufferStorageExternalEXT_(buffer, offset, size, clientBuffer, flags);
}
void glFogCoordfEXT(GLfloat coord) {
	static const auto glFogCoordfEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat)>(getProcAddress("glFogCoordfEXT"));
	assert(glFogCoordfEXT_ != nullptr);
	return glFogCoordfEXT_(coord);
}
void glFogCoordfvEXT(GLfloat const  * coord) {
	static const auto glFogCoordfvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat const  *)>(getProcAddress("glFogCoordfvEXT"));
	assert(glFogCoordfvEXT_ != nullptr);
	return glFogCoordfvEXT_(coord);
}
void glFogCoorddEXT(GLdouble coord) {
	static const auto glFogCoorddEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble)>(getProcAddress("glFogCoorddEXT"));
	assert(glFogCoorddEXT_ != nullptr);
	return glFogCoorddEXT_(coord);
}
void glFogCoorddvEXT(GLdouble const  * coord) {
	static const auto glFogCoorddvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble const  *)>(getProcAddress("glFogCoorddvEXT"));
	assert(glFogCoorddvEXT_ != nullptr);
	return glFogCoorddvEXT_(coord);
}
void glFogCoordPointerEXT(GLenum type, GLsizei stride, const void * pointer) {
	static const auto glFogCoordPointerEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, const void *)>(getProcAddress("glFogCoordPointerEXT"));
	assert(glFogCoordPointerEXT_ != nullptr);
	return glFogCoordPointerEXT_(type, stride, pointer);
}
void glBlitFramebufferEXT(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) {
	static const auto glBlitFramebufferEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLbitfield, GLenum)>(getProcAddress("glBlitFramebufferEXT"));
	assert(glBlitFramebufferEXT_ != nullptr);
	return glBlitFramebufferEXT_(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}
void glRenderbufferStorageMultisampleEXT(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) {
	static const auto glRenderbufferStorageMultisampleEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, GLenum, GLsizei, GLsizei)>(getProcAddress("glRenderbufferStorageMultisampleEXT"));
	assert(glRenderbufferStorageMultisampleEXT_ != nullptr);
	return glRenderbufferStorageMultisampleEXT_(target, samples, internalformat, width, height);
}
GLboolean glIsRenderbufferEXT(GLuint renderbuffer) {
	static const auto glIsRenderbufferEXT_ = reinterpret_cast<GLboolean(GL_APIENTRYP)(GLuint)>(getProcAddress("glIsRenderbufferEXT"));
	assert(glIsRenderbufferEXT_ != nullptr);
	return glIsRenderbufferEXT_(renderbuffer);
}
void glBindRenderbufferEXT(GLenum target, GLuint renderbuffer) {
	static const auto glBindRenderbufferEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint)>(getProcAddress("glBindRenderbufferEXT"));
	assert(glBindRenderbufferEXT_ != nullptr);
	return glBindRenderbufferEXT_(target, renderbuffer);
}
void glDeleteRenderbuffersEXT(GLsizei n, GLuint const  * renderbuffers) {
	static const auto glDeleteRenderbuffersEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint const  *)>(getProcAddress("glDeleteRenderbuffersEXT"));
	assert(glDeleteRenderbuffersEXT_ != nullptr);
	return glDeleteRenderbuffersEXT_(n, renderbuffers);
}
void glGenRenderbuffersEXT(GLsizei n, GLuint * renderbuffers) {
	static const auto glGenRenderbuffersEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint *)>(getProcAddress("glGenRenderbuffersEXT"));
	assert(glGenRenderbuffersEXT_ != nullptr);
	return glGenRenderbuffersEXT_(n, renderbuffers);
}
void glRenderbufferStorageEXT(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) {
	static const auto glRenderbufferStorageEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLsizei, GLsizei)>(getProcAddress("glRenderbufferStorageEXT"));
	assert(glRenderbufferStorageEXT_ != nullptr);
	return glRenderbufferStorageEXT_(target, internalformat, width, height);
}
void glGetRenderbufferParameterivEXT(GLenum target, GLenum pname, GLint * params) {
	static const auto glGetRenderbufferParameterivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint *)>(getProcAddress("glGetRenderbufferParameterivEXT"));
	assert(glGetRenderbufferParameterivEXT_ != nullptr);
	return glGetRenderbufferParameterivEXT_(target, pname, params);
}
GLboolean glIsFramebufferEXT(GLuint framebuffer) {
	static const auto glIsFramebufferEXT_ = reinterpret_cast<GLboolean(GL_APIENTRYP)(GLuint)>(getProcAddress("glIsFramebufferEXT"));
	assert(glIsFramebufferEXT_ != nullptr);
	return glIsFramebufferEXT_(framebuffer);
}
void glBindFramebufferEXT(GLenum target, GLuint framebuffer) {
	static const auto glBindFramebufferEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint)>(getProcAddress("glBindFramebufferEXT"));
	assert(glBindFramebufferEXT_ != nullptr);
	return glBindFramebufferEXT_(target, framebuffer);
}
void glDeleteFramebuffersEXT(GLsizei n, GLuint const  * framebuffers) {
	static const auto glDeleteFramebuffersEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint const  *)>(getProcAddress("glDeleteFramebuffersEXT"));
	assert(glDeleteFramebuffersEXT_ != nullptr);
	return glDeleteFramebuffersEXT_(n, framebuffers);
}
void glGenFramebuffersEXT(GLsizei n, GLuint * framebuffers) {
	static const auto glGenFramebuffersEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint *)>(getProcAddress("glGenFramebuffersEXT"));
	assert(glGenFramebuffersEXT_ != nullptr);
	return glGenFramebuffersEXT_(n, framebuffers);
}
GLenum glCheckFramebufferStatusEXT(GLenum target) {
	static const auto glCheckFramebufferStatusEXT_ = reinterpret_cast<GLenum(GL_APIENTRYP)(GLenum)>(getProcAddress("glCheckFramebufferStatusEXT"));
	assert(glCheckFramebufferStatusEXT_ != nullptr);
	return glCheckFramebufferStatusEXT_(target);
}
void glFramebufferTexture1DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {
	static const auto glFramebufferTexture1DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLuint, GLint)>(getProcAddress("glFramebufferTexture1DEXT"));
	assert(glFramebufferTexture1DEXT_ != nullptr);
	return glFramebufferTexture1DEXT_(target, attachment, textarget, texture, level);
}
void glFramebufferTexture2DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {
	static const auto glFramebufferTexture2DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLuint, GLint)>(getProcAddress("glFramebufferTexture2DEXT"));
	assert(glFramebufferTexture2DEXT_ != nullptr);
	return glFramebufferTexture2DEXT_(target, attachment, textarget, texture, level);
}
void glFramebufferTexture3DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset) {
	static const auto glFramebufferTexture3DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLuint, GLint, GLint)>(getProcAddress("glFramebufferTexture3DEXT"));
	assert(glFramebufferTexture3DEXT_ != nullptr);
	return glFramebufferTexture3DEXT_(target, attachment, textarget, texture, level, zoffset);
}
void glFramebufferRenderbufferEXT(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) {
	static const auto glFramebufferRenderbufferEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLuint)>(getProcAddress("glFramebufferRenderbufferEXT"));
	assert(glFramebufferRenderbufferEXT_ != nullptr);
	return glFramebufferRenderbufferEXT_(target, attachment, renderbuffertarget, renderbuffer);
}
void glGetFramebufferAttachmentParameterivEXT(GLenum target, GLenum attachment, GLenum pname, GLint * params) {
	static const auto glGetFramebufferAttachmentParameterivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLint *)>(getProcAddress("glGetFramebufferAttachmentParameterivEXT"));
	assert(glGetFramebufferAttachmentParameterivEXT_ != nullptr);
	return glGetFramebufferAttachmentParameterivEXT_(target, attachment, pname, params);
}
void glGenerateMipmapEXT(GLenum target) {
	static const auto glGenerateMipmapEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glGenerateMipmapEXT"));
	assert(glGenerateMipmapEXT_ != nullptr);
	return glGenerateMipmapEXT_(target);
}
void glProgramParameteriEXT(GLuint program, GLenum pname, GLint value) {
	static const auto glProgramParameteriEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint)>(getProcAddress("glProgramParameteriEXT"));
	assert(glProgramParameteriEXT_ != nullptr);
	return glProgramParameteriEXT_(program, pname, value);
}
void glProgramEnvParameters4fvEXT(GLenum target, GLuint index, GLsizei count, GLfloat const  * params) {
	static const auto glProgramEnvParameters4fvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint, GLsizei, GLfloat const  *)>(getProcAddress("glProgramEnvParameters4fvEXT"));
	assert(glProgramEnvParameters4fvEXT_ != nullptr);
	return glProgramEnvParameters4fvEXT_(target, index, count, params);
}
void glProgramLocalParameters4fvEXT(GLenum target, GLuint index, GLsizei count, GLfloat const  * params) {
	static const auto glProgramLocalParameters4fvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint, GLsizei, GLfloat const  *)>(getProcAddress("glProgramLocalParameters4fvEXT"));
	assert(glProgramLocalParameters4fvEXT_ != nullptr);
	return glProgramLocalParameters4fvEXT_(target, index, count, params);
}
void glGetUniformuivEXT(GLuint program, GLint location, GLuint * params) {
	static const auto glGetUniformuivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLuint *)>(getProcAddress("glGetUniformuivEXT"));
	assert(glGetUniformuivEXT_ != nullptr);
	return glGetUniformuivEXT_(program, location, params);
}
void glBindFragDataLocationEXT(GLuint program, GLuint color, GLchar const  * name) {
	static const auto glBindFragDataLocationEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLchar const  *)>(getProcAddress("glBindFragDataLocationEXT"));
	assert(glBindFragDataLocationEXT_ != nullptr);
	return glBindFragDataLocationEXT_(program, color, name);
}
GLint glGetFragDataLocationEXT(GLuint program, GLchar const  * name) {
	static const auto glGetFragDataLocationEXT_ = reinterpret_cast<GLint(GL_APIENTRYP)(GLuint, GLchar const  *)>(getProcAddress("glGetFragDataLocationEXT"));
	assert(glGetFragDataLocationEXT_ != nullptr);
	return glGetFragDataLocationEXT_(program, name);
}
void glUniform1uiEXT(GLint location, GLuint v0) {
	static const auto glUniform1uiEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLuint)>(getProcAddress("glUniform1uiEXT"));
	assert(glUniform1uiEXT_ != nullptr);
	return glUniform1uiEXT_(location, v0);
}
void glUniform2uiEXT(GLint location, GLuint v0, GLuint v1) {
	static const auto glUniform2uiEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLuint, GLuint)>(getProcAddress("glUniform2uiEXT"));
	assert(glUniform2uiEXT_ != nullptr);
	return glUniform2uiEXT_(location, v0, v1);
}
void glUniform3uiEXT(GLint location, GLuint v0, GLuint v1, GLuint v2) {
	static const auto glUniform3uiEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLuint, GLuint, GLuint)>(getProcAddress("glUniform3uiEXT"));
	assert(glUniform3uiEXT_ != nullptr);
	return glUniform3uiEXT_(location, v0, v1, v2);
}
void glUniform4uiEXT(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) {
	static const auto glUniform4uiEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLuint, GLuint, GLuint, GLuint)>(getProcAddress("glUniform4uiEXT"));
	assert(glUniform4uiEXT_ != nullptr);
	return glUniform4uiEXT_(location, v0, v1, v2, v3);
}
void glUniform1uivEXT(GLint location, GLsizei count, GLuint const  * value) {
	static const auto glUniform1uivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLuint const  *)>(getProcAddress("glUniform1uivEXT"));
	assert(glUniform1uivEXT_ != nullptr);
	return glUniform1uivEXT_(location, count, value);
}
void glUniform2uivEXT(GLint location, GLsizei count, GLuint const  * value) {
	static const auto glUniform2uivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLuint const  *)>(getProcAddress("glUniform2uivEXT"));
	assert(glUniform2uivEXT_ != nullptr);
	return glUniform2uivEXT_(location, count, value);
}
void glUniform3uivEXT(GLint location, GLsizei count, GLuint const  * value) {
	static const auto glUniform3uivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLuint const  *)>(getProcAddress("glUniform3uivEXT"));
	assert(glUniform3uivEXT_ != nullptr);
	return glUniform3uivEXT_(location, count, value);
}
void glUniform4uivEXT(GLint location, GLsizei count, GLuint const  * value) {
	static const auto glUniform4uivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLuint const  *)>(getProcAddress("glUniform4uivEXT"));
	assert(glUniform4uivEXT_ != nullptr);
	return glUniform4uivEXT_(location, count, value);
}
void glGetHistogramEXT(GLenum target, GLboolean reset, GLenum format, GLenum type, void * values) {
	static const auto glGetHistogramEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLboolean, GLenum, GLenum, void *)>(getProcAddress("glGetHistogramEXT"));
	assert(glGetHistogramEXT_ != nullptr);
	return glGetHistogramEXT_(target, reset, format, type, values);
}
void glGetHistogramParameterfvEXT(GLenum target, GLenum pname, GLfloat * params) {
	static const auto glGetHistogramParameterfvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfloat *)>(getProcAddress("glGetHistogramParameterfvEXT"));
	assert(glGetHistogramParameterfvEXT_ != nullptr);
	return glGetHistogramParameterfvEXT_(target, pname, params);
}
void glGetHistogramParameterivEXT(GLenum target, GLenum pname, GLint * params) {
	static const auto glGetHistogramParameterivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint *)>(getProcAddress("glGetHistogramParameterivEXT"));
	assert(glGetHistogramParameterivEXT_ != nullptr);
	return glGetHistogramParameterivEXT_(target, pname, params);
}
void glGetMinmaxEXT(GLenum target, GLboolean reset, GLenum format, GLenum type, void * values) {
	static const auto glGetMinmaxEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLboolean, GLenum, GLenum, void *)>(getProcAddress("glGetMinmaxEXT"));
	assert(glGetMinmaxEXT_ != nullptr);
	return glGetMinmaxEXT_(target, reset, format, type, values);
}
void glGetMinmaxParameterfvEXT(GLenum target, GLenum pname, GLfloat * params) {
	static const auto glGetMinmaxParameterfvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfloat *)>(getProcAddress("glGetMinmaxParameterfvEXT"));
	assert(glGetMinmaxParameterfvEXT_ != nullptr);
	return glGetMinmaxParameterfvEXT_(target, pname, params);
}
void glGetMinmaxParameterivEXT(GLenum target, GLenum pname, GLint * params) {
	static const auto glGetMinmaxParameterivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint *)>(getProcAddress("glGetMinmaxParameterivEXT"));
	assert(glGetMinmaxParameterivEXT_ != nullptr);
	return glGetMinmaxParameterivEXT_(target, pname, params);
}
void glHistogramEXT(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink) {
	static const auto glHistogramEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, GLenum, GLboolean)>(getProcAddress("glHistogramEXT"));
	assert(glHistogramEXT_ != nullptr);
	return glHistogramEXT_(target, width, internalformat, sink);
}
void glMinmaxEXT(GLenum target, GLenum internalformat, GLboolean sink) {
	static const auto glMinmaxEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLboolean)>(getProcAddress("glMinmaxEXT"));
	assert(glMinmaxEXT_ != nullptr);
	return glMinmaxEXT_(target, internalformat, sink);
}
void glResetHistogramEXT(GLenum target) {
	static const auto glResetHistogramEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glResetHistogramEXT"));
	assert(glResetHistogramEXT_ != nullptr);
	return glResetHistogramEXT_(target);
}
void glResetMinmaxEXT(GLenum target) {
	static const auto glResetMinmaxEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glResetMinmaxEXT"));
	assert(glResetMinmaxEXT_ != nullptr);
	return glResetMinmaxEXT_(target);
}
void glIndexFuncEXT(GLenum func, GLclampf ref) {
	static const auto glIndexFuncEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLclampf)>(getProcAddress("glIndexFuncEXT"));
	assert(glIndexFuncEXT_ != nullptr);
	return glIndexFuncEXT_(func, ref);
}
void glIndexMaterialEXT(GLenum face, GLenum mode) {
	static const auto glIndexMaterialEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum)>(getProcAddress("glIndexMaterialEXT"));
	assert(glIndexMaterialEXT_ != nullptr);
	return glIndexMaterialEXT_(face, mode);
}
void glApplyTextureEXT(GLenum mode) {
	static const auto glApplyTextureEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glApplyTextureEXT"));
	assert(glApplyTextureEXT_ != nullptr);
	return glApplyTextureEXT_(mode);
}
void glTextureLightEXT(GLenum pname) {
	static const auto glTextureLightEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glTextureLightEXT"));
	assert(glTextureLightEXT_ != nullptr);
	return glTextureLightEXT_(pname);
}
void glTextureMaterialEXT(GLenum face, GLenum mode) {
	static const auto glTextureMaterialEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum)>(getProcAddress("glTextureMaterialEXT"));
	assert(glTextureMaterialEXT_ != nullptr);
	return glTextureMaterialEXT_(face, mode);
}
void glGetUnsignedBytevEXT(GLenum pname, GLubyte * data) {
	static const auto glGetUnsignedBytevEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLubyte *)>(getProcAddress("glGetUnsignedBytevEXT"));
	assert(glGetUnsignedBytevEXT_ != nullptr);
	return glGetUnsignedBytevEXT_(pname, data);
}
void glGetUnsignedBytei_vEXT(GLenum target, GLuint index, GLubyte * data) {
	static const auto glGetUnsignedBytei_vEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint, GLubyte *)>(getProcAddress("glGetUnsignedBytei_vEXT"));
	assert(glGetUnsignedBytei_vEXT_ != nullptr);
	return glGetUnsignedBytei_vEXT_(target, index, data);
}
void glDeleteMemoryObjectsEXT(GLsizei n, GLuint const  * memoryObjects) {
	static const auto glDeleteMemoryObjectsEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint const  *)>(getProcAddress("glDeleteMemoryObjectsEXT"));
	assert(glDeleteMemoryObjectsEXT_ != nullptr);
	return glDeleteMemoryObjectsEXT_(n, memoryObjects);
}
GLboolean glIsMemoryObjectEXT(GLuint memoryObject) {
	static const auto glIsMemoryObjectEXT_ = reinterpret_cast<GLboolean(GL_APIENTRYP)(GLuint)>(getProcAddress("glIsMemoryObjectEXT"));
	assert(glIsMemoryObjectEXT_ != nullptr);
	return glIsMemoryObjectEXT_(memoryObject);
}
void glCreateMemoryObjectsEXT(GLsizei n, GLuint * memoryObjects) {
	static const auto glCreateMemoryObjectsEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint *)>(getProcAddress("glCreateMemoryObjectsEXT"));
	assert(glCreateMemoryObjectsEXT_ != nullptr);
	return glCreateMemoryObjectsEXT_(n, memoryObjects);
}
void glMemoryObjectParameterivEXT(GLuint memoryObject, GLenum pname, GLint const  * params) {
	static const auto glMemoryObjectParameterivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint const  *)>(getProcAddress("glMemoryObjectParameterivEXT"));
	assert(glMemoryObjectParameterivEXT_ != nullptr);
	return glMemoryObjectParameterivEXT_(memoryObject, pname, params);
}
void glGetMemoryObjectParameterivEXT(GLuint memoryObject, GLenum pname, GLint * params) {
	static const auto glGetMemoryObjectParameterivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint *)>(getProcAddress("glGetMemoryObjectParameterivEXT"));
	assert(glGetMemoryObjectParameterivEXT_ != nullptr);
	return glGetMemoryObjectParameterivEXT_(memoryObject, pname, params);
}
void glTexStorageMem2DEXT(GLenum target, GLsizei levels, GLenum internalFormat, GLsizei width, GLsizei height, GLuint memory, GLuint64 offset) {
	static const auto glTexStorageMem2DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLuint, GLuint64)>(getProcAddress("glTexStorageMem2DEXT"));
	assert(glTexStorageMem2DEXT_ != nullptr);
	return glTexStorageMem2DEXT_(target, levels, internalFormat, width, height, memory, offset);
}
void glTexStorageMem2DMultisampleEXT(GLenum target, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations, GLuint memory, GLuint64 offset) {
	static const auto glTexStorageMem2DMultisampleEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLboolean, GLuint, GLuint64)>(getProcAddress("glTexStorageMem2DMultisampleEXT"));
	assert(glTexStorageMem2DMultisampleEXT_ != nullptr);
	return glTexStorageMem2DMultisampleEXT_(target, samples, internalFormat, width, height, fixedSampleLocations, memory, offset);
}
void glTexStorageMem3DEXT(GLenum target, GLsizei levels, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLuint memory, GLuint64 offset) {
	static const auto glTexStorageMem3DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei, GLuint, GLuint64)>(getProcAddress("glTexStorageMem3DEXT"));
	assert(glTexStorageMem3DEXT_ != nullptr);
	return glTexStorageMem3DEXT_(target, levels, internalFormat, width, height, depth, memory, offset);
}
void glTexStorageMem3DMultisampleEXT(GLenum target, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations, GLuint memory, GLuint64 offset) {
	static const auto glTexStorageMem3DMultisampleEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei, GLboolean, GLuint, GLuint64)>(getProcAddress("glTexStorageMem3DMultisampleEXT"));
	assert(glTexStorageMem3DMultisampleEXT_ != nullptr);
	return glTexStorageMem3DMultisampleEXT_(target, samples, internalFormat, width, height, depth, fixedSampleLocations, memory, offset);
}
void glBufferStorageMemEXT(GLenum target, GLsizeiptr size, GLuint memory, GLuint64 offset) {
	static const auto glBufferStorageMemEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizeiptr, GLuint, GLuint64)>(getProcAddress("glBufferStorageMemEXT"));
	assert(glBufferStorageMemEXT_ != nullptr);
	return glBufferStorageMemEXT_(target, size, memory, offset);
}
void glTextureStorageMem2DEXT(GLuint texture, GLsizei levels, GLenum internalFormat, GLsizei width, GLsizei height, GLuint memory, GLuint64 offset) {
	static const auto glTextureStorageMem2DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLsizei, GLenum, GLsizei, GLsizei, GLuint, GLuint64)>(getProcAddress("glTextureStorageMem2DEXT"));
	assert(glTextureStorageMem2DEXT_ != nullptr);
	return glTextureStorageMem2DEXT_(texture, levels, internalFormat, width, height, memory, offset);
}
void glTextureStorageMem2DMultisampleEXT(GLuint texture, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations, GLuint memory, GLuint64 offset) {
	static const auto glTextureStorageMem2DMultisampleEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLsizei, GLenum, GLsizei, GLsizei, GLboolean, GLuint, GLuint64)>(getProcAddress("glTextureStorageMem2DMultisampleEXT"));
	assert(glTextureStorageMem2DMultisampleEXT_ != nullptr);
	return glTextureStorageMem2DMultisampleEXT_(texture, samples, internalFormat, width, height, fixedSampleLocations, memory, offset);
}
void glTextureStorageMem3DEXT(GLuint texture, GLsizei levels, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLuint memory, GLuint64 offset) {
	static const auto glTextureStorageMem3DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLsizei, GLenum, GLsizei, GLsizei, GLsizei, GLuint, GLuint64)>(getProcAddress("glTextureStorageMem3DEXT"));
	assert(glTextureStorageMem3DEXT_ != nullptr);
	return glTextureStorageMem3DEXT_(texture, levels, internalFormat, width, height, depth, memory, offset);
}
void glTextureStorageMem3DMultisampleEXT(GLuint texture, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations, GLuint memory, GLuint64 offset) {
	static const auto glTextureStorageMem3DMultisampleEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLsizei, GLenum, GLsizei, GLsizei, GLsizei, GLboolean, GLuint, GLuint64)>(getProcAddress("glTextureStorageMem3DMultisampleEXT"));
	assert(glTextureStorageMem3DMultisampleEXT_ != nullptr);
	return glTextureStorageMem3DMultisampleEXT_(texture, samples, internalFormat, width, height, depth, fixedSampleLocations, memory, offset);
}
void glNamedBufferStorageMemEXT(GLuint buffer, GLsizeiptr size, GLuint memory, GLuint64 offset) {
	static const auto glNamedBufferStorageMemEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLsizeiptr, GLuint, GLuint64)>(getProcAddress("glNamedBufferStorageMemEXT"));
	assert(glNamedBufferStorageMemEXT_ != nullptr);
	return glNamedBufferStorageMemEXT_(buffer, size, memory, offset);
}
void glTexStorageMem1DEXT(GLenum target, GLsizei levels, GLenum internalFormat, GLsizei width, GLuint memory, GLuint64 offset) {
	static const auto glTexStorageMem1DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, GLenum, GLsizei, GLuint, GLuint64)>(getProcAddress("glTexStorageMem1DEXT"));
	assert(glTexStorageMem1DEXT_ != nullptr);
	return glTexStorageMem1DEXT_(target, levels, internalFormat, width, memory, offset);
}
void glTextureStorageMem1DEXT(GLuint texture, GLsizei levels, GLenum internalFormat, GLsizei width, GLuint memory, GLuint64 offset) {
	static const auto glTextureStorageMem1DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLsizei, GLenum, GLsizei, GLuint, GLuint64)>(getProcAddress("glTextureStorageMem1DEXT"));
	assert(glTextureStorageMem1DEXT_ != nullptr);
	return glTextureStorageMem1DEXT_(texture, levels, internalFormat, width, memory, offset);
}
void glImportMemoryFdEXT(GLuint memory, GLuint64 size, GLenum handleType, GLint fd) {
	static const auto glImportMemoryFdEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint64, GLenum, GLint)>(getProcAddress("glImportMemoryFdEXT"));
	assert(glImportMemoryFdEXT_ != nullptr);
	return glImportMemoryFdEXT_(memory, size, handleType, fd);
}
void glImportMemoryWin32HandleEXT(GLuint memory, GLuint64 size, GLenum handleType, void * handle) {
	static const auto glImportMemoryWin32HandleEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint64, GLenum, void *)>(getProcAddress("glImportMemoryWin32HandleEXT"));
	assert(glImportMemoryWin32HandleEXT_ != nullptr);
	return glImportMemoryWin32HandleEXT_(memory, size, handleType, handle);
}
void glImportMemoryWin32NameEXT(GLuint memory, GLuint64 size, GLenum handleType, const void * name) {
	static const auto glImportMemoryWin32NameEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint64, GLenum, const void *)>(getProcAddress("glImportMemoryWin32NameEXT"));
	assert(glImportMemoryWin32NameEXT_ != nullptr);
	return glImportMemoryWin32NameEXT_(memory, size, handleType, name);
}
void glMultiDrawArraysEXT(GLenum mode, GLint const  * first, GLsizei const  * count, GLsizei primcount) {
	static const auto glMultiDrawArraysEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint const  *, GLsizei const  *, GLsizei)>(getProcAddress("glMultiDrawArraysEXT"));
	assert(glMultiDrawArraysEXT_ != nullptr);
	return glMultiDrawArraysEXT_(mode, first, count, primcount);
}
void glMultiDrawElementsEXT(GLenum mode, GLsizei const  * count, GLenum type, const void *const* indices, GLsizei primcount) {
	static const auto glMultiDrawElementsEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei const  *, GLenum, const void *const*, GLsizei)>(getProcAddress("glMultiDrawElementsEXT"));
	assert(glMultiDrawElementsEXT_ != nullptr);
	return glMultiDrawElementsEXT_(mode, count, type, indices, primcount);
}
void glSampleMaskEXT(GLclampf value, GLboolean invert) {
	static const auto glSampleMaskEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLclampf, GLboolean)>(getProcAddress("glSampleMaskEXT"));
	assert(glSampleMaskEXT_ != nullptr);
	return glSampleMaskEXT_(value, invert);
}
void glSamplePatternEXT(GLenum pattern) {
	static const auto glSamplePatternEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glSamplePatternEXT"));
	assert(glSamplePatternEXT_ != nullptr);
	return glSamplePatternEXT_(pattern);
}
void glColorTableEXT(GLenum target, GLenum internalFormat, GLsizei width, GLenum format, GLenum type, const void * table) {
	static const auto glColorTableEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLsizei, GLenum, GLenum, const void *)>(getProcAddress("glColorTableEXT"));
	assert(glColorTableEXT_ != nullptr);
	return glColorTableEXT_(target, internalFormat, width, format, type, table);
}
void glGetColorTableEXT(GLenum target, GLenum format, GLenum type, void * data) {
	static const auto glGetColorTableEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, void *)>(getProcAddress("glGetColorTableEXT"));
	assert(glGetColorTableEXT_ != nullptr);
	return glGetColorTableEXT_(target, format, type, data);
}
void glGetColorTableParameterivEXT(GLenum target, GLenum pname, GLint * params) {
	static const auto glGetColorTableParameterivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint *)>(getProcAddress("glGetColorTableParameterivEXT"));
	assert(glGetColorTableParameterivEXT_ != nullptr);
	return glGetColorTableParameterivEXT_(target, pname, params);
}
void glGetColorTableParameterfvEXT(GLenum target, GLenum pname, GLfloat * params) {
	static const auto glGetColorTableParameterfvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfloat *)>(getProcAddress("glGetColorTableParameterfvEXT"));
	assert(glGetColorTableParameterfvEXT_ != nullptr);
	return glGetColorTableParameterfvEXT_(target, pname, params);
}
void glPixelTransformParameteriEXT(GLenum target, GLenum pname, GLint param) {
	static const auto glPixelTransformParameteriEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint)>(getProcAddress("glPixelTransformParameteriEXT"));
	assert(glPixelTransformParameteriEXT_ != nullptr);
	return glPixelTransformParameteriEXT_(target, pname, param);
}
void glPixelTransformParameterfEXT(GLenum target, GLenum pname, GLfloat param) {
	static const auto glPixelTransformParameterfEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfloat)>(getProcAddress("glPixelTransformParameterfEXT"));
	assert(glPixelTransformParameterfEXT_ != nullptr);
	return glPixelTransformParameterfEXT_(target, pname, param);
}
void glPixelTransformParameterivEXT(GLenum target, GLenum pname, GLint const  * params) {
	static const auto glPixelTransformParameterivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint const  *)>(getProcAddress("glPixelTransformParameterivEXT"));
	assert(glPixelTransformParameterivEXT_ != nullptr);
	return glPixelTransformParameterivEXT_(target, pname, params);
}
void glPixelTransformParameterfvEXT(GLenum target, GLenum pname, GLfloat const  * params) {
	static const auto glPixelTransformParameterfvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfloat const  *)>(getProcAddress("glPixelTransformParameterfvEXT"));
	assert(glPixelTransformParameterfvEXT_ != nullptr);
	return glPixelTransformParameterfvEXT_(target, pname, params);
}
void glGetPixelTransformParameterivEXT(GLenum target, GLenum pname, GLint * params) {
	static const auto glGetPixelTransformParameterivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint *)>(getProcAddress("glGetPixelTransformParameterivEXT"));
	assert(glGetPixelTransformParameterivEXT_ != nullptr);
	return glGetPixelTransformParameterivEXT_(target, pname, params);
}
void glGetPixelTransformParameterfvEXT(GLenum target, GLenum pname, GLfloat * params) {
	static const auto glGetPixelTransformParameterfvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfloat *)>(getProcAddress("glGetPixelTransformParameterfvEXT"));
	assert(glGetPixelTransformParameterfvEXT_ != nullptr);
	return glGetPixelTransformParameterfvEXT_(target, pname, params);
}
void glPointParameterfEXT(GLenum pname, GLfloat param) {
	static const auto glPointParameterfEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfloat)>(getProcAddress("glPointParameterfEXT"));
	assert(glPointParameterfEXT_ != nullptr);
	return glPointParameterfEXT_(pname, param);
}
void glPointParameterfvEXT(GLenum pname, GLfloat const  * params) {
	static const auto glPointParameterfvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfloat const  *)>(getProcAddress("glPointParameterfvEXT"));
	assert(glPointParameterfvEXT_ != nullptr);
	return glPointParameterfvEXT_(pname, params);
}
void glPolygonOffsetEXT(GLfloat factor, GLfloat bias) {
	static const auto glPolygonOffsetEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat, GLfloat)>(getProcAddress("glPolygonOffsetEXT"));
	assert(glPolygonOffsetEXT_ != nullptr);
	return glPolygonOffsetEXT_(factor, bias);
}
void glPolygonOffsetClampEXT(GLfloat factor, GLfloat units, GLfloat clamp) {
	static const auto glPolygonOffsetClampEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat, GLfloat, GLfloat)>(getProcAddress("glPolygonOffsetClampEXT"));
	assert(glPolygonOffsetClampEXT_ != nullptr);
	return glPolygonOffsetClampEXT_(factor, units, clamp);
}
void glProvokingVertexEXT(GLenum mode) {
	static const auto glProvokingVertexEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glProvokingVertexEXT"));
	assert(glProvokingVertexEXT_ != nullptr);
	return glProvokingVertexEXT_(mode);
}
void glRasterSamplesEXT(GLuint samples, GLboolean fixedsamplelocations) {
	static const auto glRasterSamplesEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLboolean)>(getProcAddress("glRasterSamplesEXT"));
	assert(glRasterSamplesEXT_ != nullptr);
	return glRasterSamplesEXT_(samples, fixedsamplelocations);
}
void glGenSemaphoresEXT(GLsizei n, GLuint * semaphores) {
	static const auto glGenSemaphoresEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint *)>(getProcAddress("glGenSemaphoresEXT"));
	assert(glGenSemaphoresEXT_ != nullptr);
	return glGenSemaphoresEXT_(n, semaphores);
}
void glDeleteSemaphoresEXT(GLsizei n, GLuint const  * semaphores) {
	static const auto glDeleteSemaphoresEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint const  *)>(getProcAddress("glDeleteSemaphoresEXT"));
	assert(glDeleteSemaphoresEXT_ != nullptr);
	return glDeleteSemaphoresEXT_(n, semaphores);
}
GLboolean glIsSemaphoreEXT(GLuint semaphore) {
	static const auto glIsSemaphoreEXT_ = reinterpret_cast<GLboolean(GL_APIENTRYP)(GLuint)>(getProcAddress("glIsSemaphoreEXT"));
	assert(glIsSemaphoreEXT_ != nullptr);
	return glIsSemaphoreEXT_(semaphore);
}
void glSemaphoreParameterui64vEXT(GLuint semaphore, GLenum pname, GLuint64 const  * params) {
	static const auto glSemaphoreParameterui64vEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLuint64 const  *)>(getProcAddress("glSemaphoreParameterui64vEXT"));
	assert(glSemaphoreParameterui64vEXT_ != nullptr);
	return glSemaphoreParameterui64vEXT_(semaphore, pname, params);
}
void glGetSemaphoreParameterui64vEXT(GLuint semaphore, GLenum pname, GLuint64 * params) {
	static const auto glGetSemaphoreParameterui64vEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLuint64 *)>(getProcAddress("glGetSemaphoreParameterui64vEXT"));
	assert(glGetSemaphoreParameterui64vEXT_ != nullptr);
	return glGetSemaphoreParameterui64vEXT_(semaphore, pname, params);
}
void glWaitSemaphoreEXT(GLuint semaphore, GLuint numBufferBarriers, GLuint const  * buffers, GLuint numTextureBarriers, GLuint const  * textures, GLenum const  * srcLayouts) {
	static const auto glWaitSemaphoreEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLuint const  *, GLuint, GLuint const  *, GLenum const  *)>(getProcAddress("glWaitSemaphoreEXT"));
	assert(glWaitSemaphoreEXT_ != nullptr);
	return glWaitSemaphoreEXT_(semaphore, numBufferBarriers, buffers, numTextureBarriers, textures, srcLayouts);
}
void glSignalSemaphoreEXT(GLuint semaphore, GLuint numBufferBarriers, GLuint const  * buffers, GLuint numTextureBarriers, GLuint const  * textures, GLenum const  * dstLayouts) {
	static const auto glSignalSemaphoreEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLuint const  *, GLuint, GLuint const  *, GLenum const  *)>(getProcAddress("glSignalSemaphoreEXT"));
	assert(glSignalSemaphoreEXT_ != nullptr);
	return glSignalSemaphoreEXT_(semaphore, numBufferBarriers, buffers, numTextureBarriers, textures, dstLayouts);
}
void glImportSemaphoreFdEXT(GLuint semaphore, GLenum handleType, GLint fd) {
	static const auto glImportSemaphoreFdEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint)>(getProcAddress("glImportSemaphoreFdEXT"));
	assert(glImportSemaphoreFdEXT_ != nullptr);
	return glImportSemaphoreFdEXT_(semaphore, handleType, fd);
}
void glImportSemaphoreWin32HandleEXT(GLuint semaphore, GLenum handleType, void * handle) {
	static const auto glImportSemaphoreWin32HandleEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, void *)>(getProcAddress("glImportSemaphoreWin32HandleEXT"));
	assert(glImportSemaphoreWin32HandleEXT_ != nullptr);
	return glImportSemaphoreWin32HandleEXT_(semaphore, handleType, handle);
}
void glImportSemaphoreWin32NameEXT(GLuint semaphore, GLenum handleType, const void * name) {
	static const auto glImportSemaphoreWin32NameEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, const void *)>(getProcAddress("glImportSemaphoreWin32NameEXT"));
	assert(glImportSemaphoreWin32NameEXT_ != nullptr);
	return glImportSemaphoreWin32NameEXT_(semaphore, handleType, name);
}
void glSecondaryColor3bEXT(GLbyte red, GLbyte green, GLbyte blue) {
	static const auto glSecondaryColor3bEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLbyte, GLbyte, GLbyte)>(getProcAddress("glSecondaryColor3bEXT"));
	assert(glSecondaryColor3bEXT_ != nullptr);
	return glSecondaryColor3bEXT_(red, green, blue);
}
void glSecondaryColor3bvEXT(GLbyte const  * v) {
	static const auto glSecondaryColor3bvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLbyte const  *)>(getProcAddress("glSecondaryColor3bvEXT"));
	assert(glSecondaryColor3bvEXT_ != nullptr);
	return glSecondaryColor3bvEXT_(v);
}
void glSecondaryColor3dEXT(GLdouble red, GLdouble green, GLdouble blue) {
	static const auto glSecondaryColor3dEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble, GLdouble, GLdouble)>(getProcAddress("glSecondaryColor3dEXT"));
	assert(glSecondaryColor3dEXT_ != nullptr);
	return glSecondaryColor3dEXT_(red, green, blue);
}
void glSecondaryColor3dvEXT(GLdouble const  * v) {
	static const auto glSecondaryColor3dvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLdouble const  *)>(getProcAddress("glSecondaryColor3dvEXT"));
	assert(glSecondaryColor3dvEXT_ != nullptr);
	return glSecondaryColor3dvEXT_(v);
}
void glSecondaryColor3fEXT(GLfloat red, GLfloat green, GLfloat blue) {
	static const auto glSecondaryColor3fEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat, GLfloat, GLfloat)>(getProcAddress("glSecondaryColor3fEXT"));
	assert(glSecondaryColor3fEXT_ != nullptr);
	return glSecondaryColor3fEXT_(red, green, blue);
}
void glSecondaryColor3fvEXT(GLfloat const  * v) {
	static const auto glSecondaryColor3fvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat const  *)>(getProcAddress("glSecondaryColor3fvEXT"));
	assert(glSecondaryColor3fvEXT_ != nullptr);
	return glSecondaryColor3fvEXT_(v);
}
void glSecondaryColor3iEXT(GLint red, GLint green, GLint blue) {
	static const auto glSecondaryColor3iEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLint, GLint)>(getProcAddress("glSecondaryColor3iEXT"));
	assert(glSecondaryColor3iEXT_ != nullptr);
	return glSecondaryColor3iEXT_(red, green, blue);
}
void glSecondaryColor3ivEXT(GLint const  * v) {
	static const auto glSecondaryColor3ivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLint const  *)>(getProcAddress("glSecondaryColor3ivEXT"));
	assert(glSecondaryColor3ivEXT_ != nullptr);
	return glSecondaryColor3ivEXT_(v);
}
void glSecondaryColor3sEXT(GLshort red, GLshort green, GLshort blue) {
	static const auto glSecondaryColor3sEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLshort, GLshort, GLshort)>(getProcAddress("glSecondaryColor3sEXT"));
	assert(glSecondaryColor3sEXT_ != nullptr);
	return glSecondaryColor3sEXT_(red, green, blue);
}
void glSecondaryColor3svEXT(GLshort const  * v) {
	static const auto glSecondaryColor3svEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLshort const  *)>(getProcAddress("glSecondaryColor3svEXT"));
	assert(glSecondaryColor3svEXT_ != nullptr);
	return glSecondaryColor3svEXT_(v);
}
void glSecondaryColor3ubEXT(GLubyte red, GLubyte green, GLubyte blue) {
	static const auto glSecondaryColor3ubEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLubyte, GLubyte, GLubyte)>(getProcAddress("glSecondaryColor3ubEXT"));
	assert(glSecondaryColor3ubEXT_ != nullptr);
	return glSecondaryColor3ubEXT_(red, green, blue);
}
void glSecondaryColor3ubvEXT(GLubyte const  * v) {
	static const auto glSecondaryColor3ubvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLubyte const  *)>(getProcAddress("glSecondaryColor3ubvEXT"));
	assert(glSecondaryColor3ubvEXT_ != nullptr);
	return glSecondaryColor3ubvEXT_(v);
}
void glSecondaryColor3uiEXT(GLuint red, GLuint green, GLuint blue) {
	static const auto glSecondaryColor3uiEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLuint)>(getProcAddress("glSecondaryColor3uiEXT"));
	assert(glSecondaryColor3uiEXT_ != nullptr);
	return glSecondaryColor3uiEXT_(red, green, blue);
}
void glSecondaryColor3uivEXT(GLuint const  * v) {
	static const auto glSecondaryColor3uivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint const  *)>(getProcAddress("glSecondaryColor3uivEXT"));
	assert(glSecondaryColor3uivEXT_ != nullptr);
	return glSecondaryColor3uivEXT_(v);
}
void glSecondaryColor3usEXT(GLushort red, GLushort green, GLushort blue) {
	static const auto glSecondaryColor3usEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLushort, GLushort, GLushort)>(getProcAddress("glSecondaryColor3usEXT"));
	assert(glSecondaryColor3usEXT_ != nullptr);
	return glSecondaryColor3usEXT_(red, green, blue);
}
void glSecondaryColor3usvEXT(GLushort const  * v) {
	static const auto glSecondaryColor3usvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLushort const  *)>(getProcAddress("glSecondaryColor3usvEXT"));
	assert(glSecondaryColor3usvEXT_ != nullptr);
	return glSecondaryColor3usvEXT_(v);
}
void glSecondaryColorPointerEXT(GLint size, GLenum type, GLsizei stride, const void * pointer) {
	static const auto glSecondaryColorPointerEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLenum, GLsizei, const void *)>(getProcAddress("glSecondaryColorPointerEXT"));
	assert(glSecondaryColorPointerEXT_ != nullptr);
	return glSecondaryColorPointerEXT_(size, type, stride, pointer);
}
void glUseShaderProgramEXT(GLenum type, GLuint program) {
	static const auto glUseShaderProgramEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint)>(getProcAddress("glUseShaderProgramEXT"));
	assert(glUseShaderProgramEXT_ != nullptr);
	return glUseShaderProgramEXT_(type, program);
}
void glActiveProgramEXT(GLuint program) {
	static const auto glActiveProgramEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint)>(getProcAddress("glActiveProgramEXT"));
	assert(glActiveProgramEXT_ != nullptr);
	return glActiveProgramEXT_(program);
}
GLuint glCreateShaderProgramEXT(GLenum type, GLchar const  * string) {
	static const auto glCreateShaderProgramEXT_ = reinterpret_cast<GLuint(GL_APIENTRYP)(GLenum, GLchar const  *)>(getProcAddress("glCreateShaderProgramEXT"));
	assert(glCreateShaderProgramEXT_ != nullptr);
	return glCreateShaderProgramEXT_(type, string);
}
void glActiveShaderProgramEXT(GLuint pipeline, GLuint program) {
	static const auto glActiveShaderProgramEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint)>(getProcAddress("glActiveShaderProgramEXT"));
	assert(glActiveShaderProgramEXT_ != nullptr);
	return glActiveShaderProgramEXT_(pipeline, program);
}
void glBindProgramPipelineEXT(GLuint pipeline) {
	static const auto glBindProgramPipelineEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint)>(getProcAddress("glBindProgramPipelineEXT"));
	assert(glBindProgramPipelineEXT_ != nullptr);
	return glBindProgramPipelineEXT_(pipeline);
}
GLuint glCreateShaderProgramvEXT(GLenum type, GLsizei count, GLchar const  ** strings) {
	static const auto glCreateShaderProgramvEXT_ = reinterpret_cast<GLuint(GL_APIENTRYP)(GLenum, GLsizei, GLchar const  **)>(getProcAddress("glCreateShaderProgramvEXT"));
	assert(glCreateShaderProgramvEXT_ != nullptr);
	return glCreateShaderProgramvEXT_(type, count, strings);
}
void glDeleteProgramPipelinesEXT(GLsizei n, GLuint const  * pipelines) {
	static const auto glDeleteProgramPipelinesEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint const  *)>(getProcAddress("glDeleteProgramPipelinesEXT"));
	assert(glDeleteProgramPipelinesEXT_ != nullptr);
	return glDeleteProgramPipelinesEXT_(n, pipelines);
}
void glGenProgramPipelinesEXT(GLsizei n, GLuint * pipelines) {
	static const auto glGenProgramPipelinesEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint *)>(getProcAddress("glGenProgramPipelinesEXT"));
	assert(glGenProgramPipelinesEXT_ != nullptr);
	return glGenProgramPipelinesEXT_(n, pipelines);
}
void glGetProgramPipelineInfoLogEXT(GLuint pipeline, GLsizei bufSize, GLsizei * length, GLchar * infoLog) {
	static const auto glGetProgramPipelineInfoLogEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLsizei, GLsizei *, GLchar *)>(getProcAddress("glGetProgramPipelineInfoLogEXT"));
	assert(glGetProgramPipelineInfoLogEXT_ != nullptr);
	return glGetProgramPipelineInfoLogEXT_(pipeline, bufSize, length, infoLog);
}
void glGetProgramPipelineivEXT(GLuint pipeline, GLenum pname, GLint * params) {
	static const auto glGetProgramPipelineivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint *)>(getProcAddress("glGetProgramPipelineivEXT"));
	assert(glGetProgramPipelineivEXT_ != nullptr);
	return glGetProgramPipelineivEXT_(pipeline, pname, params);
}
GLboolean glIsProgramPipelineEXT(GLuint pipeline) {
	static const auto glIsProgramPipelineEXT_ = reinterpret_cast<GLboolean(GL_APIENTRYP)(GLuint)>(getProcAddress("glIsProgramPipelineEXT"));
	assert(glIsProgramPipelineEXT_ != nullptr);
	return glIsProgramPipelineEXT_(pipeline);
}
void glUseProgramStagesEXT(GLuint pipeline, GLbitfield stages, GLuint program) {
	static const auto glUseProgramStagesEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLbitfield, GLuint)>(getProcAddress("glUseProgramStagesEXT"));
	assert(glUseProgramStagesEXT_ != nullptr);
	return glUseProgramStagesEXT_(pipeline, stages, program);
}
void glValidateProgramPipelineEXT(GLuint pipeline) {
	static const auto glValidateProgramPipelineEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint)>(getProcAddress("glValidateProgramPipelineEXT"));
	assert(glValidateProgramPipelineEXT_ != nullptr);
	return glValidateProgramPipelineEXT_(pipeline);
}
void glFramebufferFetchBarrierEXT() {
	static const auto glFramebufferFetchBarrierEXT_ = reinterpret_cast<void(GL_APIENTRYP)()>(getProcAddress("glFramebufferFetchBarrierEXT"));
	assert(glFramebufferFetchBarrierEXT_ != nullptr);
	return glFramebufferFetchBarrierEXT_();
}
void glBindImageTextureEXT(GLuint index, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLint format) {
	static const auto glBindImageTextureEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLint, GLboolean, GLint, GLenum, GLint)>(getProcAddress("glBindImageTextureEXT"));
	assert(glBindImageTextureEXT_ != nullptr);
	return glBindImageTextureEXT_(index, texture, level, layered, layer, access, format);
}
void glMemoryBarrierEXT(GLbitfield barriers) {
	static const auto glMemoryBarrierEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLbitfield)>(getProcAddress("glMemoryBarrierEXT"));
	assert(glMemoryBarrierEXT_ != nullptr);
	return glMemoryBarrierEXT_(barriers);
}
void glStencilClearTagEXT(GLsizei stencilTagBits, GLuint stencilClearTag) {
	static const auto glStencilClearTagEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint)>(getProcAddress("glStencilClearTagEXT"));
	assert(glStencilClearTagEXT_ != nullptr);
	return glStencilClearTagEXT_(stencilTagBits, stencilClearTag);
}
void glActiveStencilFaceEXT(GLenum face) {
	static const auto glActiveStencilFaceEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glActiveStencilFaceEXT"));
	assert(glActiveStencilFaceEXT_ != nullptr);
	return glActiveStencilFaceEXT_(face);
}
void glTexSubImage1DEXT(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void * pixels) {
	static const auto glTexSubImage1DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLint, GLsizei, GLenum, GLenum, const void *)>(getProcAddress("glTexSubImage1DEXT"));
	assert(glTexSubImage1DEXT_ != nullptr);
	return glTexSubImage1DEXT_(target, level, xoffset, width, format, type, pixels);
}
void glTexSubImage2DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels) {
	static const auto glTexSubImage2DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const void *)>(getProcAddress("glTexSubImage2DEXT"));
	assert(glTexSubImage2DEXT_ != nullptr);
	return glTexSubImage2DEXT_(target, level, xoffset, yoffset, width, height, format, type, pixels);
}
void glTexImage3DEXT(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void * pixels) {
	static const auto glTexImage3DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const void *)>(getProcAddress("glTexImage3DEXT"));
	assert(glTexImage3DEXT_ != nullptr);
	return glTexImage3DEXT_(target, level, internalformat, width, height, depth, border, format, type, pixels);
}
void glTexSubImage3DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels) {
	static const auto glTexSubImage3DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const void *)>(getProcAddress("glTexSubImage3DEXT"));
	assert(glTexSubImage3DEXT_ != nullptr);
	return glTexSubImage3DEXT_(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}
void glFramebufferTextureLayerEXT(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) {
	static const auto glFramebufferTextureLayerEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLuint, GLint, GLint)>(getProcAddress("glFramebufferTextureLayerEXT"));
	assert(glFramebufferTextureLayerEXT_ != nullptr);
	return glFramebufferTextureLayerEXT_(target, attachment, texture, level, layer);
}
void glTexBufferEXT(GLenum target, GLenum internalformat, GLuint buffer) {
	static const auto glTexBufferEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLuint)>(getProcAddress("glTexBufferEXT"));
	assert(glTexBufferEXT_ != nullptr);
	return glTexBufferEXT_(target, internalformat, buffer);
}
void glTexParameterIivEXT(GLenum target, GLenum pname, GLint const  * params) {
	static const auto glTexParameterIivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint const  *)>(getProcAddress("glTexParameterIivEXT"));
	assert(glTexParameterIivEXT_ != nullptr);
	return glTexParameterIivEXT_(target, pname, params);
}
void glTexParameterIuivEXT(GLenum target, GLenum pname, GLuint const  * params) {
	static const auto glTexParameterIuivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLuint const  *)>(getProcAddress("glTexParameterIuivEXT"));
	assert(glTexParameterIuivEXT_ != nullptr);
	return glTexParameterIuivEXT_(target, pname, params);
}
void glGetTexParameterIivEXT(GLenum target, GLenum pname, GLint * params) {
	static const auto glGetTexParameterIivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint *)>(getProcAddress("glGetTexParameterIivEXT"));
	assert(glGetTexParameterIivEXT_ != nullptr);
	return glGetTexParameterIivEXT_(target, pname, params);
}
void glGetTexParameterIuivEXT(GLenum target, GLenum pname, GLuint * params) {
	static const auto glGetTexParameterIuivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLuint *)>(getProcAddress("glGetTexParameterIuivEXT"));
	assert(glGetTexParameterIuivEXT_ != nullptr);
	return glGetTexParameterIuivEXT_(target, pname, params);
}
void glClearColorIiEXT(GLint red, GLint green, GLint blue, GLint alpha) {
	static const auto glClearColorIiEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLint, GLint, GLint)>(getProcAddress("glClearColorIiEXT"));
	assert(glClearColorIiEXT_ != nullptr);
	return glClearColorIiEXT_(red, green, blue, alpha);
}
void glClearColorIuiEXT(GLuint red, GLuint green, GLuint blue, GLuint alpha) {
	static const auto glClearColorIuiEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLuint, GLuint)>(getProcAddress("glClearColorIuiEXT"));
	assert(glClearColorIuiEXT_ != nullptr);
	return glClearColorIuiEXT_(red, green, blue, alpha);
}
GLboolean glAreTexturesResidentEXT(GLsizei n, GLuint const  * textures, GLboolean * residences) {
	static const auto glAreTexturesResidentEXT_ = reinterpret_cast<GLboolean(GL_APIENTRYP)(GLsizei, GLuint const  *, GLboolean *)>(getProcAddress("glAreTexturesResidentEXT"));
	assert(glAreTexturesResidentEXT_ != nullptr);
	return glAreTexturesResidentEXT_(n, textures, residences);
}
void glBindTextureEXT(GLenum target, GLuint texture) {
	static const auto glBindTextureEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint)>(getProcAddress("glBindTextureEXT"));
	assert(glBindTextureEXT_ != nullptr);
	return glBindTextureEXT_(target, texture);
}
void glDeleteTexturesEXT(GLsizei n, GLuint const  * textures) {
	static const auto glDeleteTexturesEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint const  *)>(getProcAddress("glDeleteTexturesEXT"));
	assert(glDeleteTexturesEXT_ != nullptr);
	return glDeleteTexturesEXT_(n, textures);
}
void glGenTexturesEXT(GLsizei n, GLuint * textures) {
	static const auto glGenTexturesEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint *)>(getProcAddress("glGenTexturesEXT"));
	assert(glGenTexturesEXT_ != nullptr);
	return glGenTexturesEXT_(n, textures);
}
GLboolean glIsTextureEXT(GLuint texture) {
	static const auto glIsTextureEXT_ = reinterpret_cast<GLboolean(GL_APIENTRYP)(GLuint)>(getProcAddress("glIsTextureEXT"));
	assert(glIsTextureEXT_ != nullptr);
	return glIsTextureEXT_(texture);
}
void glPrioritizeTexturesEXT(GLsizei n, GLuint const  * textures, GLclampf const  * priorities) {
	static const auto glPrioritizeTexturesEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint const  *, GLclampf const  *)>(getProcAddress("glPrioritizeTexturesEXT"));
	assert(glPrioritizeTexturesEXT_ != nullptr);
	return glPrioritizeTexturesEXT_(n, textures, priorities);
}
void glTextureNormalEXT(GLenum mode) {
	static const auto glTextureNormalEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glTextureNormalEXT"));
	assert(glTextureNormalEXT_ != nullptr);
	return glTextureNormalEXT_(mode);
}
void glGetQueryObjecti64vEXT(GLuint id, GLenum pname, GLint64 * params) {
	static const auto glGetQueryObjecti64vEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint64 *)>(getProcAddress("glGetQueryObjecti64vEXT"));
	assert(glGetQueryObjecti64vEXT_ != nullptr);
	return glGetQueryObjecti64vEXT_(id, pname, params);
}
void glGetQueryObjectui64vEXT(GLuint id, GLenum pname, GLuint64 * params) {
	static const auto glGetQueryObjectui64vEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLuint64 *)>(getProcAddress("glGetQueryObjectui64vEXT"));
	assert(glGetQueryObjectui64vEXT_ != nullptr);
	return glGetQueryObjectui64vEXT_(id, pname, params);
}
void glBeginTransformFeedbackEXT(GLenum primitiveMode) {
	static const auto glBeginTransformFeedbackEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glBeginTransformFeedbackEXT"));
	assert(glBeginTransformFeedbackEXT_ != nullptr);
	return glBeginTransformFeedbackEXT_(primitiveMode);
}
void glEndTransformFeedbackEXT() {
	static const auto glEndTransformFeedbackEXT_ = reinterpret_cast<void(GL_APIENTRYP)()>(getProcAddress("glEndTransformFeedbackEXT"));
	assert(glEndTransformFeedbackEXT_ != nullptr);
	return glEndTransformFeedbackEXT_();
}
void glBindBufferRangeEXT(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) {
	static const auto glBindBufferRangeEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint, GLuint, GLintptr, GLsizeiptr)>(getProcAddress("glBindBufferRangeEXT"));
	assert(glBindBufferRangeEXT_ != nullptr);
	return glBindBufferRangeEXT_(target, index, buffer, offset, size);
}
void glBindBufferOffsetEXT(GLenum target, GLuint index, GLuint buffer, GLintptr offset) {
	static const auto glBindBufferOffsetEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint, GLuint, GLintptr)>(getProcAddress("glBindBufferOffsetEXT"));
	assert(glBindBufferOffsetEXT_ != nullptr);
	return glBindBufferOffsetEXT_(target, index, buffer, offset);
}
void glBindBufferBaseEXT(GLenum target, GLuint index, GLuint buffer) {
	static const auto glBindBufferBaseEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint, GLuint)>(getProcAddress("glBindBufferBaseEXT"));
	assert(glBindBufferBaseEXT_ != nullptr);
	return glBindBufferBaseEXT_(target, index, buffer);
}
void glTransformFeedbackVaryingsEXT(GLuint program, GLsizei count, GLchar const  *const* varyings, GLenum bufferMode) {
	static const auto glTransformFeedbackVaryingsEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLsizei, GLchar const  *const*, GLenum)>(getProcAddress("glTransformFeedbackVaryingsEXT"));
	assert(glTransformFeedbackVaryingsEXT_ != nullptr);
	return glTransformFeedbackVaryingsEXT_(program, count, varyings, bufferMode);
}
void glGetTransformFeedbackVaryingEXT(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLsizei * size, GLenum * type, GLchar * name) {
	static const auto glGetTransformFeedbackVaryingEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLsizei, GLsizei *, GLsizei *, GLenum *, GLchar *)>(getProcAddress("glGetTransformFeedbackVaryingEXT"));
	assert(glGetTransformFeedbackVaryingEXT_ != nullptr);
	return glGetTransformFeedbackVaryingEXT_(program, index, bufSize, length, size, type, name);
}
void glArrayElementEXT(GLint i) {
	static const auto glArrayElementEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLint)>(getProcAddress("glArrayElementEXT"));
	assert(glArrayElementEXT_ != nullptr);
	return glArrayElementEXT_(i);
}
void glColorPointerEXT(GLint size, GLenum type, GLsizei stride, GLsizei count, const void * pointer) {
	static const auto glColorPointerEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLenum, GLsizei, GLsizei, const void *)>(getProcAddress("glColorPointerEXT"));
	assert(glColorPointerEXT_ != nullptr);
	return glColorPointerEXT_(size, type, stride, count, pointer);
}
void glDrawArraysEXT(GLenum mode, GLint first, GLsizei count) {
	static const auto glDrawArraysEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLsizei)>(getProcAddress("glDrawArraysEXT"));
	assert(glDrawArraysEXT_ != nullptr);
	return glDrawArraysEXT_(mode, first, count);
}
void glEdgeFlagPointerEXT(GLsizei stride, GLsizei count, GLboolean const  * pointer) {
	static const auto glEdgeFlagPointerEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLsizei, GLboolean const  *)>(getProcAddress("glEdgeFlagPointerEXT"));
	assert(glEdgeFlagPointerEXT_ != nullptr);
	return glEdgeFlagPointerEXT_(stride, count, pointer);
}
void glGetPointervEXT(GLenum pname, void ** params) {
	static const auto glGetPointervEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, void **)>(getProcAddress("glGetPointervEXT"));
	assert(glGetPointervEXT_ != nullptr);
	return glGetPointervEXT_(pname, params);
}
void glIndexPointerEXT(GLenum type, GLsizei stride, GLsizei count, const void * pointer) {
	static const auto glIndexPointerEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, GLsizei, const void *)>(getProcAddress("glIndexPointerEXT"));
	assert(glIndexPointerEXT_ != nullptr);
	return glIndexPointerEXT_(type, stride, count, pointer);
}
void glNormalPointerEXT(GLenum type, GLsizei stride, GLsizei count, const void * pointer) {
	static const auto glNormalPointerEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, GLsizei, const void *)>(getProcAddress("glNormalPointerEXT"));
	assert(glNormalPointerEXT_ != nullptr);
	return glNormalPointerEXT_(type, stride, count, pointer);
}
void glTexCoordPointerEXT(GLint size, GLenum type, GLsizei stride, GLsizei count, const void * pointer) {
	static const auto glTexCoordPointerEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLenum, GLsizei, GLsizei, const void *)>(getProcAddress("glTexCoordPointerEXT"));
	assert(glTexCoordPointerEXT_ != nullptr);
	return glTexCoordPointerEXT_(size, type, stride, count, pointer);
}
void glVertexPointerEXT(GLint size, GLenum type, GLsizei stride, GLsizei count, const void * pointer) {
	static const auto glVertexPointerEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLenum, GLsizei, GLsizei, const void *)>(getProcAddress("glVertexPointerEXT"));
	assert(glVertexPointerEXT_ != nullptr);
	return glVertexPointerEXT_(size, type, stride, count, pointer);
}
void glVertexAttribL1dEXT(GLuint index, GLdouble x) {
	static const auto glVertexAttribL1dEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLdouble)>(getProcAddress("glVertexAttribL1dEXT"));
	assert(glVertexAttribL1dEXT_ != nullptr);
	return glVertexAttribL1dEXT_(index, x);
}
void glVertexAttribL2dEXT(GLuint index, GLdouble x, GLdouble y) {
	static const auto glVertexAttribL2dEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLdouble, GLdouble)>(getProcAddress("glVertexAttribL2dEXT"));
	assert(glVertexAttribL2dEXT_ != nullptr);
	return glVertexAttribL2dEXT_(index, x, y);
}
void glVertexAttribL3dEXT(GLuint index, GLdouble x, GLdouble y, GLdouble z) {
	static const auto glVertexAttribL3dEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLdouble, GLdouble, GLdouble)>(getProcAddress("glVertexAttribL3dEXT"));
	assert(glVertexAttribL3dEXT_ != nullptr);
	return glVertexAttribL3dEXT_(index, x, y, z);
}
void glVertexAttribL4dEXT(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
	static const auto glVertexAttribL4dEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLdouble, GLdouble, GLdouble, GLdouble)>(getProcAddress("glVertexAttribL4dEXT"));
	assert(glVertexAttribL4dEXT_ != nullptr);
	return glVertexAttribL4dEXT_(index, x, y, z, w);
}
void glVertexAttribL1dvEXT(GLuint index, GLdouble const  * v) {
	static const auto glVertexAttribL1dvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLdouble const  *)>(getProcAddress("glVertexAttribL1dvEXT"));
	assert(glVertexAttribL1dvEXT_ != nullptr);
	return glVertexAttribL1dvEXT_(index, v);
}
void glVertexAttribL2dvEXT(GLuint index, GLdouble const  * v) {
	static const auto glVertexAttribL2dvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLdouble const  *)>(getProcAddress("glVertexAttribL2dvEXT"));
	assert(glVertexAttribL2dvEXT_ != nullptr);
	return glVertexAttribL2dvEXT_(index, v);
}
void glVertexAttribL3dvEXT(GLuint index, GLdouble const  * v) {
	static const auto glVertexAttribL3dvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLdouble const  *)>(getProcAddress("glVertexAttribL3dvEXT"));
	assert(glVertexAttribL3dvEXT_ != nullptr);
	return glVertexAttribL3dvEXT_(index, v);
}
void glVertexAttribL4dvEXT(GLuint index, GLdouble const  * v) {
	static const auto glVertexAttribL4dvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLdouble const  *)>(getProcAddress("glVertexAttribL4dvEXT"));
	assert(glVertexAttribL4dvEXT_ != nullptr);
	return glVertexAttribL4dvEXT_(index, v);
}
void glVertexAttribLPointerEXT(GLuint index, GLint size, GLenum type, GLsizei stride, const void * pointer) {
	static const auto glVertexAttribLPointerEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLenum, GLsizei, const void *)>(getProcAddress("glVertexAttribLPointerEXT"));
	assert(glVertexAttribLPointerEXT_ != nullptr);
	return glVertexAttribLPointerEXT_(index, size, type, stride, pointer);
}
void glGetVertexAttribLdvEXT(GLuint index, GLenum pname, GLdouble * params) {
	static const auto glGetVertexAttribLdvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLdouble *)>(getProcAddress("glGetVertexAttribLdvEXT"));
	assert(glGetVertexAttribLdvEXT_ != nullptr);
	return glGetVertexAttribLdvEXT_(index, pname, params);
}
void glBeginVertexShaderEXT() {
	static const auto glBeginVertexShaderEXT_ = reinterpret_cast<void(GL_APIENTRYP)()>(getProcAddress("glBeginVertexShaderEXT"));
	assert(glBeginVertexShaderEXT_ != nullptr);
	return glBeginVertexShaderEXT_();
}
void glEndVertexShaderEXT() {
	static const auto glEndVertexShaderEXT_ = reinterpret_cast<void(GL_APIENTRYP)()>(getProcAddress("glEndVertexShaderEXT"));
	assert(glEndVertexShaderEXT_ != nullptr);
	return glEndVertexShaderEXT_();
}
void glBindVertexShaderEXT(GLuint id) {
	static const auto glBindVertexShaderEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint)>(getProcAddress("glBindVertexShaderEXT"));
	assert(glBindVertexShaderEXT_ != nullptr);
	return glBindVertexShaderEXT_(id);
}
GLuint glGenVertexShadersEXT(GLuint range) {
	static const auto glGenVertexShadersEXT_ = reinterpret_cast<GLuint(GL_APIENTRYP)(GLuint)>(getProcAddress("glGenVertexShadersEXT"));
	assert(glGenVertexShadersEXT_ != nullptr);
	return glGenVertexShadersEXT_(range);
}
void glDeleteVertexShaderEXT(GLuint id) {
	static const auto glDeleteVertexShaderEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint)>(getProcAddress("glDeleteVertexShaderEXT"));
	assert(glDeleteVertexShaderEXT_ != nullptr);
	return glDeleteVertexShaderEXT_(id);
}
void glShaderOp1EXT(GLenum op, GLuint res, GLuint arg1) {
	static const auto glShaderOp1EXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint, GLuint)>(getProcAddress("glShaderOp1EXT"));
	assert(glShaderOp1EXT_ != nullptr);
	return glShaderOp1EXT_(op, res, arg1);
}
void glShaderOp2EXT(GLenum op, GLuint res, GLuint arg1, GLuint arg2) {
	static const auto glShaderOp2EXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint, GLuint, GLuint)>(getProcAddress("glShaderOp2EXT"));
	assert(glShaderOp2EXT_ != nullptr);
	return glShaderOp2EXT_(op, res, arg1, arg2);
}
void glShaderOp3EXT(GLenum op, GLuint res, GLuint arg1, GLuint arg2, GLuint arg3) {
	static const auto glShaderOp3EXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint, GLuint, GLuint, GLuint)>(getProcAddress("glShaderOp3EXT"));
	assert(glShaderOp3EXT_ != nullptr);
	return glShaderOp3EXT_(op, res, arg1, arg2, arg3);
}
void glSwizzleEXT(GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW) {
	static const auto glSwizzleEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLenum, GLenum, GLenum, GLenum)>(getProcAddress("glSwizzleEXT"));
	assert(glSwizzleEXT_ != nullptr);
	return glSwizzleEXT_(res, in, outX, outY, outZ, outW);
}
void glWriteMaskEXT(GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW) {
	static const auto glWriteMaskEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLenum, GLenum, GLenum, GLenum)>(getProcAddress("glWriteMaskEXT"));
	assert(glWriteMaskEXT_ != nullptr);
	return glWriteMaskEXT_(res, in, outX, outY, outZ, outW);
}
void glInsertComponentEXT(GLuint res, GLuint src, GLuint num) {
	static const auto glInsertComponentEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLuint)>(getProcAddress("glInsertComponentEXT"));
	assert(glInsertComponentEXT_ != nullptr);
	return glInsertComponentEXT_(res, src, num);
}
void glExtractComponentEXT(GLuint res, GLuint src, GLuint num) {
	static const auto glExtractComponentEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLuint)>(getProcAddress("glExtractComponentEXT"));
	assert(glExtractComponentEXT_ != nullptr);
	return glExtractComponentEXT_(res, src, num);
}
GLuint glGenSymbolsEXT(GLenum datatype, GLenum storagetype, GLenum range, GLuint components) {
	static const auto glGenSymbolsEXT_ = reinterpret_cast<GLuint(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLuint)>(getProcAddress("glGenSymbolsEXT"));
	assert(glGenSymbolsEXT_ != nullptr);
	return glGenSymbolsEXT_(datatype, storagetype, range, components);
}
void glSetInvariantEXT(GLuint id, GLenum type, const void * addr) {
	static const auto glSetInvariantEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, const void *)>(getProcAddress("glSetInvariantEXT"));
	assert(glSetInvariantEXT_ != nullptr);
	return glSetInvariantEXT_(id, type, addr);
}
void glSetLocalConstantEXT(GLuint id, GLenum type, const void * addr) {
	static const auto glSetLocalConstantEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, const void *)>(getProcAddress("glSetLocalConstantEXT"));
	assert(glSetLocalConstantEXT_ != nullptr);
	return glSetLocalConstantEXT_(id, type, addr);
}
void glVariantbvEXT(GLuint id, GLbyte const  * addr) {
	static const auto glVariantbvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLbyte const  *)>(getProcAddress("glVariantbvEXT"));
	assert(glVariantbvEXT_ != nullptr);
	return glVariantbvEXT_(id, addr);
}
void glVariantsvEXT(GLuint id, GLshort const  * addr) {
	static const auto glVariantsvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLshort const  *)>(getProcAddress("glVariantsvEXT"));
	assert(glVariantsvEXT_ != nullptr);
	return glVariantsvEXT_(id, addr);
}
void glVariantivEXT(GLuint id, GLint const  * addr) {
	static const auto glVariantivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint const  *)>(getProcAddress("glVariantivEXT"));
	assert(glVariantivEXT_ != nullptr);
	return glVariantivEXT_(id, addr);
}
void glVariantfvEXT(GLuint id, GLfloat const  * addr) {
	static const auto glVariantfvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLfloat const  *)>(getProcAddress("glVariantfvEXT"));
	assert(glVariantfvEXT_ != nullptr);
	return glVariantfvEXT_(id, addr);
}
void glVariantdvEXT(GLuint id, GLdouble const  * addr) {
	static const auto glVariantdvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLdouble const  *)>(getProcAddress("glVariantdvEXT"));
	assert(glVariantdvEXT_ != nullptr);
	return glVariantdvEXT_(id, addr);
}
void glVariantubvEXT(GLuint id, GLubyte const  * addr) {
	static const auto glVariantubvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLubyte const  *)>(getProcAddress("glVariantubvEXT"));
	assert(glVariantubvEXT_ != nullptr);
	return glVariantubvEXT_(id, addr);
}
void glVariantusvEXT(GLuint id, GLushort const  * addr) {
	static const auto glVariantusvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLushort const  *)>(getProcAddress("glVariantusvEXT"));
	assert(glVariantusvEXT_ != nullptr);
	return glVariantusvEXT_(id, addr);
}
void glVariantuivEXT(GLuint id, GLuint const  * addr) {
	static const auto glVariantuivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint const  *)>(getProcAddress("glVariantuivEXT"));
	assert(glVariantuivEXT_ != nullptr);
	return glVariantuivEXT_(id, addr);
}
void glVariantPointerEXT(GLuint id, GLenum type, GLuint stride, const void * addr) {
	static const auto glVariantPointerEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLuint, const void *)>(getProcAddress("glVariantPointerEXT"));
	assert(glVariantPointerEXT_ != nullptr);
	return glVariantPointerEXT_(id, type, stride, addr);
}
void glEnableVariantClientStateEXT(GLuint id) {
	static const auto glEnableVariantClientStateEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint)>(getProcAddress("glEnableVariantClientStateEXT"));
	assert(glEnableVariantClientStateEXT_ != nullptr);
	return glEnableVariantClientStateEXT_(id);
}
void glDisableVariantClientStateEXT(GLuint id) {
	static const auto glDisableVariantClientStateEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint)>(getProcAddress("glDisableVariantClientStateEXT"));
	assert(glDisableVariantClientStateEXT_ != nullptr);
	return glDisableVariantClientStateEXT_(id);
}
GLuint glBindLightParameterEXT(GLenum light, GLenum value) {
	static const auto glBindLightParameterEXT_ = reinterpret_cast<GLuint(GL_APIENTRYP)(GLenum, GLenum)>(getProcAddress("glBindLightParameterEXT"));
	assert(glBindLightParameterEXT_ != nullptr);
	return glBindLightParameterEXT_(light, value);
}
GLuint glBindMaterialParameterEXT(GLenum face, GLenum value) {
	static const auto glBindMaterialParameterEXT_ = reinterpret_cast<GLuint(GL_APIENTRYP)(GLenum, GLenum)>(getProcAddress("glBindMaterialParameterEXT"));
	assert(glBindMaterialParameterEXT_ != nullptr);
	return glBindMaterialParameterEXT_(face, value);
}
GLuint glBindTexGenParameterEXT(GLenum unit, GLenum coord, GLenum value) {
	static const auto glBindTexGenParameterEXT_ = reinterpret_cast<GLuint(GL_APIENTRYP)(GLenum, GLenum, GLenum)>(getProcAddress("glBindTexGenParameterEXT"));
	assert(glBindTexGenParameterEXT_ != nullptr);
	return glBindTexGenParameterEXT_(unit, coord, value);
}
GLuint glBindTextureUnitParameterEXT(GLenum unit, GLenum value) {
	static const auto glBindTextureUnitParameterEXT_ = reinterpret_cast<GLuint(GL_APIENTRYP)(GLenum, GLenum)>(getProcAddress("glBindTextureUnitParameterEXT"));
	assert(glBindTextureUnitParameterEXT_ != nullptr);
	return glBindTextureUnitParameterEXT_(unit, value);
}
GLuint glBindParameterEXT(GLenum value) {
	static const auto glBindParameterEXT_ = reinterpret_cast<GLuint(GL_APIENTRYP)(GLenum)>(getProcAddress("glBindParameterEXT"));
	assert(glBindParameterEXT_ != nullptr);
	return glBindParameterEXT_(value);
}
GLboolean glIsVariantEnabledEXT(GLuint id, GLenum cap) {
	static const auto glIsVariantEnabledEXT_ = reinterpret_cast<GLboolean(GL_APIENTRYP)(GLuint, GLenum)>(getProcAddress("glIsVariantEnabledEXT"));
	assert(glIsVariantEnabledEXT_ != nullptr);
	return glIsVariantEnabledEXT_(id, cap);
}
void glGetVariantBooleanvEXT(GLuint id, GLenum value, GLboolean * data) {
	static const auto glGetVariantBooleanvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLboolean *)>(getProcAddress("glGetVariantBooleanvEXT"));
	assert(glGetVariantBooleanvEXT_ != nullptr);
	return glGetVariantBooleanvEXT_(id, value, data);
}
void glGetVariantIntegervEXT(GLuint id, GLenum value, GLint * data) {
	static const auto glGetVariantIntegervEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint *)>(getProcAddress("glGetVariantIntegervEXT"));
	assert(glGetVariantIntegervEXT_ != nullptr);
	return glGetVariantIntegervEXT_(id, value, data);
}
void glGetVariantFloatvEXT(GLuint id, GLenum value, GLfloat * data) {
	static const auto glGetVariantFloatvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLfloat *)>(getProcAddress("glGetVariantFloatvEXT"));
	assert(glGetVariantFloatvEXT_ != nullptr);
	return glGetVariantFloatvEXT_(id, value, data);
}
void glGetVariantPointervEXT(GLuint id, GLenum value, void ** data) {
	static const auto glGetVariantPointervEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, void **)>(getProcAddress("glGetVariantPointervEXT"));
	assert(glGetVariantPointervEXT_ != nullptr);
	return glGetVariantPointervEXT_(id, value, data);
}
void glGetInvariantBooleanvEXT(GLuint id, GLenum value, GLboolean * data) {
	static const auto glGetInvariantBooleanvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLboolean *)>(getProcAddress("glGetInvariantBooleanvEXT"));
	assert(glGetInvariantBooleanvEXT_ != nullptr);
	return glGetInvariantBooleanvEXT_(id, value, data);
}
void glGetInvariantIntegervEXT(GLuint id, GLenum value, GLint * data) {
	static const auto glGetInvariantIntegervEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint *)>(getProcAddress("glGetInvariantIntegervEXT"));
	assert(glGetInvariantIntegervEXT_ != nullptr);
	return glGetInvariantIntegervEXT_(id, value, data);
}
void glGetInvariantFloatvEXT(GLuint id, GLenum value, GLfloat * data) {
	static const auto glGetInvariantFloatvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLfloat *)>(getProcAddress("glGetInvariantFloatvEXT"));
	assert(glGetInvariantFloatvEXT_ != nullptr);
	return glGetInvariantFloatvEXT_(id, value, data);
}
void glGetLocalConstantBooleanvEXT(GLuint id, GLenum value, GLboolean * data) {
	static const auto glGetLocalConstantBooleanvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLboolean *)>(getProcAddress("glGetLocalConstantBooleanvEXT"));
	assert(glGetLocalConstantBooleanvEXT_ != nullptr);
	return glGetLocalConstantBooleanvEXT_(id, value, data);
}
void glGetLocalConstantIntegervEXT(GLuint id, GLenum value, GLint * data) {
	static const auto glGetLocalConstantIntegervEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint *)>(getProcAddress("glGetLocalConstantIntegervEXT"));
	assert(glGetLocalConstantIntegervEXT_ != nullptr);
	return glGetLocalConstantIntegervEXT_(id, value, data);
}
void glGetLocalConstantFloatvEXT(GLuint id, GLenum value, GLfloat * data) {
	static const auto glGetLocalConstantFloatvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLfloat *)>(getProcAddress("glGetLocalConstantFloatvEXT"));
	assert(glGetLocalConstantFloatvEXT_ != nullptr);
	return glGetLocalConstantFloatvEXT_(id, value, data);
}
void glVertexWeightfEXT(GLfloat weight) {
	static const auto glVertexWeightfEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat)>(getProcAddress("glVertexWeightfEXT"));
	assert(glVertexWeightfEXT_ != nullptr);
	return glVertexWeightfEXT_(weight);
}
void glVertexWeightfvEXT(GLfloat const  * weight) {
	static const auto glVertexWeightfvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat const  *)>(getProcAddress("glVertexWeightfvEXT"));
	assert(glVertexWeightfvEXT_ != nullptr);
	return glVertexWeightfvEXT_(weight);
}
void glVertexWeightPointerEXT(GLint size, GLenum type, GLsizei stride, const void * pointer) {
	static const auto glVertexWeightPointerEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLenum, GLsizei, const void *)>(getProcAddress("glVertexWeightPointerEXT"));
	assert(glVertexWeightPointerEXT_ != nullptr);
	return glVertexWeightPointerEXT_(size, type, stride, pointer);
}
GLboolean glAcquireKeyedMutexWin32EXT(GLuint memory, GLuint64 key, GLuint timeout) {
	static const auto glAcquireKeyedMutexWin32EXT_ = reinterpret_cast<GLboolean(GL_APIENTRYP)(GLuint, GLuint64, GLuint)>(getProcAddress("glAcquireKeyedMutexWin32EXT"));
	assert(glAcquireKeyedMutexWin32EXT_ != nullptr);
	return glAcquireKeyedMutexWin32EXT_(memory, key, timeout);
}
GLboolean glReleaseKeyedMutexWin32EXT(GLuint memory, GLuint64 key) {
	static const auto glReleaseKeyedMutexWin32EXT_ = reinterpret_cast<GLboolean(GL_APIENTRYP)(GLuint, GLuint64)>(getProcAddress("glReleaseKeyedMutexWin32EXT"));
	assert(glReleaseKeyedMutexWin32EXT_ != nullptr);
	return glReleaseKeyedMutexWin32EXT_(memory, key);
}
void glWindowRectanglesEXT(GLenum mode, GLsizei count, GLint const  * box) {
	static const auto glWindowRectanglesEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, GLint const  *)>(getProcAddress("glWindowRectanglesEXT"));
	assert(glWindowRectanglesEXT_ != nullptr);
	return glWindowRectanglesEXT_(mode, count, box);
}
GLsync glImportSyncEXT(GLenum external_sync_type, GLintptr external_sync, GLbitfield flags) {
	static const auto glImportSyncEXT_ = reinterpret_cast<GLsync(GL_APIENTRYP)(GLenum, GLintptr, GLbitfield)>(getProcAddress("glImportSyncEXT"));
	assert(glImportSyncEXT_ != nullptr);
	return glImportSyncEXT_(external_sync_type, external_sync, flags);
}
void glMultiTexCoord1bOES(GLenum texture, GLbyte s) {
	static const auto glMultiTexCoord1bOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLbyte)>(getProcAddress("glMultiTexCoord1bOES"));
	assert(glMultiTexCoord1bOES_ != nullptr);
	return glMultiTexCoord1bOES_(texture, s);
}
void glMultiTexCoord1bvOES(GLenum texture, GLbyte const  * coords) {
	static const auto glMultiTexCoord1bvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLbyte const  *)>(getProcAddress("glMultiTexCoord1bvOES"));
	assert(glMultiTexCoord1bvOES_ != nullptr);
	return glMultiTexCoord1bvOES_(texture, coords);
}
void glMultiTexCoord2bOES(GLenum texture, GLbyte s, GLbyte t) {
	static const auto glMultiTexCoord2bOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLbyte, GLbyte)>(getProcAddress("glMultiTexCoord2bOES"));
	assert(glMultiTexCoord2bOES_ != nullptr);
	return glMultiTexCoord2bOES_(texture, s, t);
}
void glMultiTexCoord2bvOES(GLenum texture, GLbyte const  * coords) {
	static const auto glMultiTexCoord2bvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLbyte const  *)>(getProcAddress("glMultiTexCoord2bvOES"));
	assert(glMultiTexCoord2bvOES_ != nullptr);
	return glMultiTexCoord2bvOES_(texture, coords);
}
void glMultiTexCoord3bOES(GLenum texture, GLbyte s, GLbyte t, GLbyte r) {
	static const auto glMultiTexCoord3bOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLbyte, GLbyte, GLbyte)>(getProcAddress("glMultiTexCoord3bOES"));
	assert(glMultiTexCoord3bOES_ != nullptr);
	return glMultiTexCoord3bOES_(texture, s, t, r);
}
void glMultiTexCoord3bvOES(GLenum texture, GLbyte const  * coords) {
	static const auto glMultiTexCoord3bvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLbyte const  *)>(getProcAddress("glMultiTexCoord3bvOES"));
	assert(glMultiTexCoord3bvOES_ != nullptr);
	return glMultiTexCoord3bvOES_(texture, coords);
}
void glMultiTexCoord4bOES(GLenum texture, GLbyte s, GLbyte t, GLbyte r, GLbyte q) {
	static const auto glMultiTexCoord4bOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLbyte, GLbyte, GLbyte, GLbyte)>(getProcAddress("glMultiTexCoord4bOES"));
	assert(glMultiTexCoord4bOES_ != nullptr);
	return glMultiTexCoord4bOES_(texture, s, t, r, q);
}
void glMultiTexCoord4bvOES(GLenum texture, GLbyte const  * coords) {
	static const auto glMultiTexCoord4bvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLbyte const  *)>(getProcAddress("glMultiTexCoord4bvOES"));
	assert(glMultiTexCoord4bvOES_ != nullptr);
	return glMultiTexCoord4bvOES_(texture, coords);
}
void glTexCoord1bOES(GLbyte s) {
	static const auto glTexCoord1bOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLbyte)>(getProcAddress("glTexCoord1bOES"));
	assert(glTexCoord1bOES_ != nullptr);
	return glTexCoord1bOES_(s);
}
void glTexCoord1bvOES(GLbyte const  * coords) {
	static const auto glTexCoord1bvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLbyte const  *)>(getProcAddress("glTexCoord1bvOES"));
	assert(glTexCoord1bvOES_ != nullptr);
	return glTexCoord1bvOES_(coords);
}
void glTexCoord2bOES(GLbyte s, GLbyte t) {
	static const auto glTexCoord2bOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLbyte, GLbyte)>(getProcAddress("glTexCoord2bOES"));
	assert(glTexCoord2bOES_ != nullptr);
	return glTexCoord2bOES_(s, t);
}
void glTexCoord2bvOES(GLbyte const  * coords) {
	static const auto glTexCoord2bvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLbyte const  *)>(getProcAddress("glTexCoord2bvOES"));
	assert(glTexCoord2bvOES_ != nullptr);
	return glTexCoord2bvOES_(coords);
}
void glTexCoord3bOES(GLbyte s, GLbyte t, GLbyte r) {
	static const auto glTexCoord3bOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLbyte, GLbyte, GLbyte)>(getProcAddress("glTexCoord3bOES"));
	assert(glTexCoord3bOES_ != nullptr);
	return glTexCoord3bOES_(s, t, r);
}
void glTexCoord3bvOES(GLbyte const  * coords) {
	static const auto glTexCoord3bvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLbyte const  *)>(getProcAddress("glTexCoord3bvOES"));
	assert(glTexCoord3bvOES_ != nullptr);
	return glTexCoord3bvOES_(coords);
}
void glTexCoord4bOES(GLbyte s, GLbyte t, GLbyte r, GLbyte q) {
	static const auto glTexCoord4bOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLbyte, GLbyte, GLbyte, GLbyte)>(getProcAddress("glTexCoord4bOES"));
	assert(glTexCoord4bOES_ != nullptr);
	return glTexCoord4bOES_(s, t, r, q);
}
void glTexCoord4bvOES(GLbyte const  * coords) {
	static const auto glTexCoord4bvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLbyte const  *)>(getProcAddress("glTexCoord4bvOES"));
	assert(glTexCoord4bvOES_ != nullptr);
	return glTexCoord4bvOES_(coords);
}
void glVertex2bOES(GLbyte x, GLbyte y) {
	static const auto glVertex2bOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLbyte, GLbyte)>(getProcAddress("glVertex2bOES"));
	assert(glVertex2bOES_ != nullptr);
	return glVertex2bOES_(x, y);
}
void glVertex2bvOES(GLbyte const  * coords) {
	static const auto glVertex2bvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLbyte const  *)>(getProcAddress("glVertex2bvOES"));
	assert(glVertex2bvOES_ != nullptr);
	return glVertex2bvOES_(coords);
}
void glVertex3bOES(GLbyte x, GLbyte y, GLbyte z) {
	static const auto glVertex3bOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLbyte, GLbyte, GLbyte)>(getProcAddress("glVertex3bOES"));
	assert(glVertex3bOES_ != nullptr);
	return glVertex3bOES_(x, y, z);
}
void glVertex3bvOES(GLbyte const  * coords) {
	static const auto glVertex3bvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLbyte const  *)>(getProcAddress("glVertex3bvOES"));
	assert(glVertex3bvOES_ != nullptr);
	return glVertex3bvOES_(coords);
}
void glVertex4bOES(GLbyte x, GLbyte y, GLbyte z, GLbyte w) {
	static const auto glVertex4bOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLbyte, GLbyte, GLbyte, GLbyte)>(getProcAddress("glVertex4bOES"));
	assert(glVertex4bOES_ != nullptr);
	return glVertex4bOES_(x, y, z, w);
}
void glVertex4bvOES(GLbyte const  * coords) {
	static const auto glVertex4bvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLbyte const  *)>(getProcAddress("glVertex4bvOES"));
	assert(glVertex4bvOES_ != nullptr);
	return glVertex4bvOES_(coords);
}
void glAlphaFuncxOES(GLenum func, GLfixed ref) {
	static const auto glAlphaFuncxOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfixed)>(getProcAddress("glAlphaFuncxOES"));
	assert(glAlphaFuncxOES_ != nullptr);
	return glAlphaFuncxOES_(func, ref);
}
void glClearColorxOES(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha) {
	static const auto glClearColorxOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed, GLfixed, GLfixed, GLfixed)>(getProcAddress("glClearColorxOES"));
	assert(glClearColorxOES_ != nullptr);
	return glClearColorxOES_(red, green, blue, alpha);
}
void glClearDepthxOES(GLfixed depth) {
	static const auto glClearDepthxOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed)>(getProcAddress("glClearDepthxOES"));
	assert(glClearDepthxOES_ != nullptr);
	return glClearDepthxOES_(depth);
}
void glClipPlanexOES(GLenum plane, GLfixed const  * equation) {
	static const auto glClipPlanexOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfixed const  *)>(getProcAddress("glClipPlanexOES"));
	assert(glClipPlanexOES_ != nullptr);
	return glClipPlanexOES_(plane, equation);
}
void glColor4xOES(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha) {
	static const auto glColor4xOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed, GLfixed, GLfixed, GLfixed)>(getProcAddress("glColor4xOES"));
	assert(glColor4xOES_ != nullptr);
	return glColor4xOES_(red, green, blue, alpha);
}
void glDepthRangexOES(GLfixed n, GLfixed f) {
	static const auto glDepthRangexOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed, GLfixed)>(getProcAddress("glDepthRangexOES"));
	assert(glDepthRangexOES_ != nullptr);
	return glDepthRangexOES_(n, f);
}
void glFogxOES(GLenum pname, GLfixed param) {
	static const auto glFogxOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfixed)>(getProcAddress("glFogxOES"));
	assert(glFogxOES_ != nullptr);
	return glFogxOES_(pname, param);
}
void glFogxvOES(GLenum pname, GLfixed const  * param) {
	static const auto glFogxvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfixed const  *)>(getProcAddress("glFogxvOES"));
	assert(glFogxvOES_ != nullptr);
	return glFogxvOES_(pname, param);
}
void glFrustumxOES(GLfixed l, GLfixed r, GLfixed b, GLfixed t, GLfixed n, GLfixed f) {
	static const auto glFrustumxOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed, GLfixed, GLfixed, GLfixed, GLfixed, GLfixed)>(getProcAddress("glFrustumxOES"));
	assert(glFrustumxOES_ != nullptr);
	return glFrustumxOES_(l, r, b, t, n, f);
}
void glGetClipPlanexOES(GLenum plane, GLfixed * equation) {
	static const auto glGetClipPlanexOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfixed *)>(getProcAddress("glGetClipPlanexOES"));
	assert(glGetClipPlanexOES_ != nullptr);
	return glGetClipPlanexOES_(plane, equation);
}
void glGetFixedvOES(GLenum pname, GLfixed * params) {
	static const auto glGetFixedvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfixed *)>(getProcAddress("glGetFixedvOES"));
	assert(glGetFixedvOES_ != nullptr);
	return glGetFixedvOES_(pname, params);
}
void glGetTexEnvxvOES(GLenum target, GLenum pname, GLfixed * params) {
	static const auto glGetTexEnvxvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfixed *)>(getProcAddress("glGetTexEnvxvOES"));
	assert(glGetTexEnvxvOES_ != nullptr);
	return glGetTexEnvxvOES_(target, pname, params);
}
void glGetTexParameterxvOES(GLenum target, GLenum pname, GLfixed * params) {
	static const auto glGetTexParameterxvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfixed *)>(getProcAddress("glGetTexParameterxvOES"));
	assert(glGetTexParameterxvOES_ != nullptr);
	return glGetTexParameterxvOES_(target, pname, params);
}
void glLightModelxOES(GLenum pname, GLfixed param) {
	static const auto glLightModelxOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfixed)>(getProcAddress("glLightModelxOES"));
	assert(glLightModelxOES_ != nullptr);
	return glLightModelxOES_(pname, param);
}
void glLightModelxvOES(GLenum pname, GLfixed const  * param) {
	static const auto glLightModelxvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfixed const  *)>(getProcAddress("glLightModelxvOES"));
	assert(glLightModelxvOES_ != nullptr);
	return glLightModelxvOES_(pname, param);
}
void glLightxOES(GLenum light, GLenum pname, GLfixed param) {
	static const auto glLightxOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfixed)>(getProcAddress("glLightxOES"));
	assert(glLightxOES_ != nullptr);
	return glLightxOES_(light, pname, param);
}
void glLightxvOES(GLenum light, GLenum pname, GLfixed const  * params) {
	static const auto glLightxvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfixed const  *)>(getProcAddress("glLightxvOES"));
	assert(glLightxvOES_ != nullptr);
	return glLightxvOES_(light, pname, params);
}
void glLineWidthxOES(GLfixed width) {
	static const auto glLineWidthxOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed)>(getProcAddress("glLineWidthxOES"));
	assert(glLineWidthxOES_ != nullptr);
	return glLineWidthxOES_(width);
}
void glLoadMatrixxOES(GLfixed const  * m) {
	static const auto glLoadMatrixxOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed const  *)>(getProcAddress("glLoadMatrixxOES"));
	assert(glLoadMatrixxOES_ != nullptr);
	return glLoadMatrixxOES_(m);
}
void glMaterialxOES(GLenum face, GLenum pname, GLfixed param) {
	static const auto glMaterialxOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfixed)>(getProcAddress("glMaterialxOES"));
	assert(glMaterialxOES_ != nullptr);
	return glMaterialxOES_(face, pname, param);
}
void glMaterialxvOES(GLenum face, GLenum pname, GLfixed const  * param) {
	static const auto glMaterialxvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfixed const  *)>(getProcAddress("glMaterialxvOES"));
	assert(glMaterialxvOES_ != nullptr);
	return glMaterialxvOES_(face, pname, param);
}
void glMultMatrixxOES(GLfixed const  * m) {
	static const auto glMultMatrixxOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed const  *)>(getProcAddress("glMultMatrixxOES"));
	assert(glMultMatrixxOES_ != nullptr);
	return glMultMatrixxOES_(m);
}
void glMultiTexCoord4xOES(GLenum texture, GLfixed s, GLfixed t, GLfixed r, GLfixed q) {
	static const auto glMultiTexCoord4xOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfixed, GLfixed, GLfixed, GLfixed)>(getProcAddress("glMultiTexCoord4xOES"));
	assert(glMultiTexCoord4xOES_ != nullptr);
	return glMultiTexCoord4xOES_(texture, s, t, r, q);
}
void glNormal3xOES(GLfixed nx, GLfixed ny, GLfixed nz) {
	static const auto glNormal3xOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed, GLfixed, GLfixed)>(getProcAddress("glNormal3xOES"));
	assert(glNormal3xOES_ != nullptr);
	return glNormal3xOES_(nx, ny, nz);
}
void glOrthoxOES(GLfixed l, GLfixed r, GLfixed b, GLfixed t, GLfixed n, GLfixed f) {
	static const auto glOrthoxOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed, GLfixed, GLfixed, GLfixed, GLfixed, GLfixed)>(getProcAddress("glOrthoxOES"));
	assert(glOrthoxOES_ != nullptr);
	return glOrthoxOES_(l, r, b, t, n, f);
}
void glPointParameterxvOES(GLenum pname, GLfixed const  * params) {
	static const auto glPointParameterxvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfixed const  *)>(getProcAddress("glPointParameterxvOES"));
	assert(glPointParameterxvOES_ != nullptr);
	return glPointParameterxvOES_(pname, params);
}
void glPointSizexOES(GLfixed size) {
	static const auto glPointSizexOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed)>(getProcAddress("glPointSizexOES"));
	assert(glPointSizexOES_ != nullptr);
	return glPointSizexOES_(size);
}
void glPolygonOffsetxOES(GLfixed factor, GLfixed units) {
	static const auto glPolygonOffsetxOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed, GLfixed)>(getProcAddress("glPolygonOffsetxOES"));
	assert(glPolygonOffsetxOES_ != nullptr);
	return glPolygonOffsetxOES_(factor, units);
}
void glRotatexOES(GLfixed angle, GLfixed x, GLfixed y, GLfixed z) {
	static const auto glRotatexOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed, GLfixed, GLfixed, GLfixed)>(getProcAddress("glRotatexOES"));
	assert(glRotatexOES_ != nullptr);
	return glRotatexOES_(angle, x, y, z);
}
void glScalexOES(GLfixed x, GLfixed y, GLfixed z) {
	static const auto glScalexOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed, GLfixed, GLfixed)>(getProcAddress("glScalexOES"));
	assert(glScalexOES_ != nullptr);
	return glScalexOES_(x, y, z);
}
void glTexEnvxOES(GLenum target, GLenum pname, GLfixed param) {
	static const auto glTexEnvxOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfixed)>(getProcAddress("glTexEnvxOES"));
	assert(glTexEnvxOES_ != nullptr);
	return glTexEnvxOES_(target, pname, param);
}
void glTexEnvxvOES(GLenum target, GLenum pname, GLfixed const  * params) {
	static const auto glTexEnvxvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfixed const  *)>(getProcAddress("glTexEnvxvOES"));
	assert(glTexEnvxvOES_ != nullptr);
	return glTexEnvxvOES_(target, pname, params);
}
void glTexParameterxOES(GLenum target, GLenum pname, GLfixed param) {
	static const auto glTexParameterxOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfixed)>(getProcAddress("glTexParameterxOES"));
	assert(glTexParameterxOES_ != nullptr);
	return glTexParameterxOES_(target, pname, param);
}
void glTexParameterxvOES(GLenum target, GLenum pname, GLfixed const  * params) {
	static const auto glTexParameterxvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfixed const  *)>(getProcAddress("glTexParameterxvOES"));
	assert(glTexParameterxvOES_ != nullptr);
	return glTexParameterxvOES_(target, pname, params);
}
void glTranslatexOES(GLfixed x, GLfixed y, GLfixed z) {
	static const auto glTranslatexOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed, GLfixed, GLfixed)>(getProcAddress("glTranslatexOES"));
	assert(glTranslatexOES_ != nullptr);
	return glTranslatexOES_(x, y, z);
}
void glGetLightxvOES(GLenum light, GLenum pname, GLfixed * params) {
	static const auto glGetLightxvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfixed *)>(getProcAddress("glGetLightxvOES"));
	assert(glGetLightxvOES_ != nullptr);
	return glGetLightxvOES_(light, pname, params);
}
void glGetMaterialxvOES(GLenum face, GLenum pname, GLfixed * params) {
	static const auto glGetMaterialxvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfixed *)>(getProcAddress("glGetMaterialxvOES"));
	assert(glGetMaterialxvOES_ != nullptr);
	return glGetMaterialxvOES_(face, pname, params);
}
void glPointParameterxOES(GLenum pname, GLfixed param) {
	static const auto glPointParameterxOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfixed)>(getProcAddress("glPointParameterxOES"));
	assert(glPointParameterxOES_ != nullptr);
	return glPointParameterxOES_(pname, param);
}
void glSampleCoveragexOES(GLclampx value, GLboolean invert) {
	static const auto glSampleCoveragexOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLclampx, GLboolean)>(getProcAddress("glSampleCoveragexOES"));
	assert(glSampleCoveragexOES_ != nullptr);
	return glSampleCoveragexOES_(value, invert);
}
void glAccumxOES(GLenum op, GLfixed value) {
	static const auto glAccumxOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfixed)>(getProcAddress("glAccumxOES"));
	assert(glAccumxOES_ != nullptr);
	return glAccumxOES_(op, value);
}
void glBitmapxOES(GLsizei width, GLsizei height, GLfixed xorig, GLfixed yorig, GLfixed xmove, GLfixed ymove, GLubyte const  * bitmap) {
	static const auto glBitmapxOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLsizei, GLfixed, GLfixed, GLfixed, GLfixed, GLubyte const  *)>(getProcAddress("glBitmapxOES"));
	assert(glBitmapxOES_ != nullptr);
	return glBitmapxOES_(width, height, xorig, yorig, xmove, ymove, bitmap);
}
void glBlendColorxOES(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha) {
	static const auto glBlendColorxOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed, GLfixed, GLfixed, GLfixed)>(getProcAddress("glBlendColorxOES"));
	assert(glBlendColorxOES_ != nullptr);
	return glBlendColorxOES_(red, green, blue, alpha);
}
void glClearAccumxOES(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha) {
	static const auto glClearAccumxOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed, GLfixed, GLfixed, GLfixed)>(getProcAddress("glClearAccumxOES"));
	assert(glClearAccumxOES_ != nullptr);
	return glClearAccumxOES_(red, green, blue, alpha);
}
void glColor3xOES(GLfixed red, GLfixed green, GLfixed blue) {
	static const auto glColor3xOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed, GLfixed, GLfixed)>(getProcAddress("glColor3xOES"));
	assert(glColor3xOES_ != nullptr);
	return glColor3xOES_(red, green, blue);
}
void glColor3xvOES(GLfixed const  * components) {
	static const auto glColor3xvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed const  *)>(getProcAddress("glColor3xvOES"));
	assert(glColor3xvOES_ != nullptr);
	return glColor3xvOES_(components);
}
void glColor4xvOES(GLfixed const  * components) {
	static const auto glColor4xvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed const  *)>(getProcAddress("glColor4xvOES"));
	assert(glColor4xvOES_ != nullptr);
	return glColor4xvOES_(components);
}
void glConvolutionParameterxOES(GLenum target, GLenum pname, GLfixed param) {
	static const auto glConvolutionParameterxOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfixed)>(getProcAddress("glConvolutionParameterxOES"));
	assert(glConvolutionParameterxOES_ != nullptr);
	return glConvolutionParameterxOES_(target, pname, param);
}
void glConvolutionParameterxvOES(GLenum target, GLenum pname, GLfixed const  * params) {
	static const auto glConvolutionParameterxvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfixed const  *)>(getProcAddress("glConvolutionParameterxvOES"));
	assert(glConvolutionParameterxvOES_ != nullptr);
	return glConvolutionParameterxvOES_(target, pname, params);
}
void glEvalCoord1xOES(GLfixed u) {
	static const auto glEvalCoord1xOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed)>(getProcAddress("glEvalCoord1xOES"));
	assert(glEvalCoord1xOES_ != nullptr);
	return glEvalCoord1xOES_(u);
}
void glEvalCoord1xvOES(GLfixed const  * coords) {
	static const auto glEvalCoord1xvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed const  *)>(getProcAddress("glEvalCoord1xvOES"));
	assert(glEvalCoord1xvOES_ != nullptr);
	return glEvalCoord1xvOES_(coords);
}
void glEvalCoord2xOES(GLfixed u, GLfixed v) {
	static const auto glEvalCoord2xOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed, GLfixed)>(getProcAddress("glEvalCoord2xOES"));
	assert(glEvalCoord2xOES_ != nullptr);
	return glEvalCoord2xOES_(u, v);
}
void glEvalCoord2xvOES(GLfixed const  * coords) {
	static const auto glEvalCoord2xvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed const  *)>(getProcAddress("glEvalCoord2xvOES"));
	assert(glEvalCoord2xvOES_ != nullptr);
	return glEvalCoord2xvOES_(coords);
}
void glFeedbackBufferxOES(GLsizei n, GLenum type, GLfixed const  * buffer) {
	static const auto glFeedbackBufferxOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLenum, GLfixed const  *)>(getProcAddress("glFeedbackBufferxOES"));
	assert(glFeedbackBufferxOES_ != nullptr);
	return glFeedbackBufferxOES_(n, type, buffer);
}
void glGetConvolutionParameterxvOES(GLenum target, GLenum pname, GLfixed * params) {
	static const auto glGetConvolutionParameterxvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfixed *)>(getProcAddress("glGetConvolutionParameterxvOES"));
	assert(glGetConvolutionParameterxvOES_ != nullptr);
	return glGetConvolutionParameterxvOES_(target, pname, params);
}
void glGetHistogramParameterxvOES(GLenum target, GLenum pname, GLfixed * params) {
	static const auto glGetHistogramParameterxvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfixed *)>(getProcAddress("glGetHistogramParameterxvOES"));
	assert(glGetHistogramParameterxvOES_ != nullptr);
	return glGetHistogramParameterxvOES_(target, pname, params);
}
void glGetLightxOES(GLenum light, GLenum pname, GLfixed * params) {
	static const auto glGetLightxOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfixed *)>(getProcAddress("glGetLightxOES"));
	assert(glGetLightxOES_ != nullptr);
	return glGetLightxOES_(light, pname, params);
}
void glGetMapxvOES(GLenum target, GLenum query, GLfixed * v) {
	static const auto glGetMapxvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfixed *)>(getProcAddress("glGetMapxvOES"));
	assert(glGetMapxvOES_ != nullptr);
	return glGetMapxvOES_(target, query, v);
}
void glGetMaterialxOES(GLenum face, GLenum pname, GLfixed param) {
	static const auto glGetMaterialxOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfixed)>(getProcAddress("glGetMaterialxOES"));
	assert(glGetMaterialxOES_ != nullptr);
	return glGetMaterialxOES_(face, pname, param);
}
void glGetPixelMapxv(GLenum map, GLint size, GLfixed * values) {
	static const auto glGetPixelMapxv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLfixed *)>(getProcAddress("glGetPixelMapxv"));
	assert(glGetPixelMapxv_ != nullptr);
	return glGetPixelMapxv_(map, size, values);
}
void glGetTexGenxvOES(GLenum coord, GLenum pname, GLfixed * params) {
	static const auto glGetTexGenxvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfixed *)>(getProcAddress("glGetTexGenxvOES"));
	assert(glGetTexGenxvOES_ != nullptr);
	return glGetTexGenxvOES_(coord, pname, params);
}
void glGetTexLevelParameterxvOES(GLenum target, GLint level, GLenum pname, GLfixed * params) {
	static const auto glGetTexLevelParameterxvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLenum, GLfixed *)>(getProcAddress("glGetTexLevelParameterxvOES"));
	assert(glGetTexLevelParameterxvOES_ != nullptr);
	return glGetTexLevelParameterxvOES_(target, level, pname, params);
}
void glIndexxOES(GLfixed component) {
	static const auto glIndexxOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed)>(getProcAddress("glIndexxOES"));
	assert(glIndexxOES_ != nullptr);
	return glIndexxOES_(component);
}
void glIndexxvOES(GLfixed const  * component) {
	static const auto glIndexxvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed const  *)>(getProcAddress("glIndexxvOES"));
	assert(glIndexxvOES_ != nullptr);
	return glIndexxvOES_(component);
}
void glLoadTransposeMatrixxOES(GLfixed const  * m) {
	static const auto glLoadTransposeMatrixxOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed const  *)>(getProcAddress("glLoadTransposeMatrixxOES"));
	assert(glLoadTransposeMatrixxOES_ != nullptr);
	return glLoadTransposeMatrixxOES_(m);
}
void glMap1xOES(GLenum target, GLfixed u1, GLfixed u2, GLint stride, GLint order, GLfixed points) {
	static const auto glMap1xOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfixed, GLfixed, GLint, GLint, GLfixed)>(getProcAddress("glMap1xOES"));
	assert(glMap1xOES_ != nullptr);
	return glMap1xOES_(target, u1, u2, stride, order, points);
}
void glMap2xOES(GLenum target, GLfixed u1, GLfixed u2, GLint ustride, GLint uorder, GLfixed v1, GLfixed v2, GLint vstride, GLint vorder, GLfixed points) {
	static const auto glMap2xOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfixed, GLfixed, GLint, GLint, GLfixed, GLfixed, GLint, GLint, GLfixed)>(getProcAddress("glMap2xOES"));
	assert(glMap2xOES_ != nullptr);
	return glMap2xOES_(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
}
void glMapGrid1xOES(GLint n, GLfixed u1, GLfixed u2) {
	static const auto glMapGrid1xOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLfixed, GLfixed)>(getProcAddress("glMapGrid1xOES"));
	assert(glMapGrid1xOES_ != nullptr);
	return glMapGrid1xOES_(n, u1, u2);
}
void glMapGrid2xOES(GLint n, GLfixed u1, GLfixed u2, GLfixed v1, GLfixed v2) {
	static const auto glMapGrid2xOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLfixed, GLfixed, GLfixed, GLfixed)>(getProcAddress("glMapGrid2xOES"));
	assert(glMapGrid2xOES_ != nullptr);
	return glMapGrid2xOES_(n, u1, u2, v1, v2);
}
void glMultTransposeMatrixxOES(GLfixed const  * m) {
	static const auto glMultTransposeMatrixxOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed const  *)>(getProcAddress("glMultTransposeMatrixxOES"));
	assert(glMultTransposeMatrixxOES_ != nullptr);
	return glMultTransposeMatrixxOES_(m);
}
void glMultiTexCoord1xOES(GLenum texture, GLfixed s) {
	static const auto glMultiTexCoord1xOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfixed)>(getProcAddress("glMultiTexCoord1xOES"));
	assert(glMultiTexCoord1xOES_ != nullptr);
	return glMultiTexCoord1xOES_(texture, s);
}
void glMultiTexCoord1xvOES(GLenum texture, GLfixed const  * coords) {
	static const auto glMultiTexCoord1xvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfixed const  *)>(getProcAddress("glMultiTexCoord1xvOES"));
	assert(glMultiTexCoord1xvOES_ != nullptr);
	return glMultiTexCoord1xvOES_(texture, coords);
}
void glMultiTexCoord2xOES(GLenum texture, GLfixed s, GLfixed t) {
	static const auto glMultiTexCoord2xOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfixed, GLfixed)>(getProcAddress("glMultiTexCoord2xOES"));
	assert(glMultiTexCoord2xOES_ != nullptr);
	return glMultiTexCoord2xOES_(texture, s, t);
}
void glMultiTexCoord2xvOES(GLenum texture, GLfixed const  * coords) {
	static const auto glMultiTexCoord2xvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfixed const  *)>(getProcAddress("glMultiTexCoord2xvOES"));
	assert(glMultiTexCoord2xvOES_ != nullptr);
	return glMultiTexCoord2xvOES_(texture, coords);
}
void glMultiTexCoord3xOES(GLenum texture, GLfixed s, GLfixed t, GLfixed r) {
	static const auto glMultiTexCoord3xOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfixed, GLfixed, GLfixed)>(getProcAddress("glMultiTexCoord3xOES"));
	assert(glMultiTexCoord3xOES_ != nullptr);
	return glMultiTexCoord3xOES_(texture, s, t, r);
}
void glMultiTexCoord3xvOES(GLenum texture, GLfixed const  * coords) {
	static const auto glMultiTexCoord3xvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfixed const  *)>(getProcAddress("glMultiTexCoord3xvOES"));
	assert(glMultiTexCoord3xvOES_ != nullptr);
	return glMultiTexCoord3xvOES_(texture, coords);
}
void glMultiTexCoord4xvOES(GLenum texture, GLfixed const  * coords) {
	static const auto glMultiTexCoord4xvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfixed const  *)>(getProcAddress("glMultiTexCoord4xvOES"));
	assert(glMultiTexCoord4xvOES_ != nullptr);
	return glMultiTexCoord4xvOES_(texture, coords);
}
void glNormal3xvOES(GLfixed const  * coords) {
	static const auto glNormal3xvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed const  *)>(getProcAddress("glNormal3xvOES"));
	assert(glNormal3xvOES_ != nullptr);
	return glNormal3xvOES_(coords);
}
void glPassThroughxOES(GLfixed token) {
	static const auto glPassThroughxOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed)>(getProcAddress("glPassThroughxOES"));
	assert(glPassThroughxOES_ != nullptr);
	return glPassThroughxOES_(token);
}
void glPixelMapx(GLenum map, GLint size, GLfixed const  * values) {
	static const auto glPixelMapx_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLfixed const  *)>(getProcAddress("glPixelMapx"));
	assert(glPixelMapx_ != nullptr);
	return glPixelMapx_(map, size, values);
}
void glPixelStorex(GLenum pname, GLfixed param) {
	static const auto glPixelStorex_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfixed)>(getProcAddress("glPixelStorex"));
	assert(glPixelStorex_ != nullptr);
	return glPixelStorex_(pname, param);
}
void glPixelTransferxOES(GLenum pname, GLfixed param) {
	static const auto glPixelTransferxOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfixed)>(getProcAddress("glPixelTransferxOES"));
	assert(glPixelTransferxOES_ != nullptr);
	return glPixelTransferxOES_(pname, param);
}
void glPixelZoomxOES(GLfixed xfactor, GLfixed yfactor) {
	static const auto glPixelZoomxOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed, GLfixed)>(getProcAddress("glPixelZoomxOES"));
	assert(glPixelZoomxOES_ != nullptr);
	return glPixelZoomxOES_(xfactor, yfactor);
}
void glPrioritizeTexturesxOES(GLsizei n, GLuint const  * textures, GLfixed const  * priorities) {
	static const auto glPrioritizeTexturesxOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint const  *, GLfixed const  *)>(getProcAddress("glPrioritizeTexturesxOES"));
	assert(glPrioritizeTexturesxOES_ != nullptr);
	return glPrioritizeTexturesxOES_(n, textures, priorities);
}
void glRasterPos2xOES(GLfixed x, GLfixed y) {
	static const auto glRasterPos2xOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed, GLfixed)>(getProcAddress("glRasterPos2xOES"));
	assert(glRasterPos2xOES_ != nullptr);
	return glRasterPos2xOES_(x, y);
}
void glRasterPos2xvOES(GLfixed const  * coords) {
	static const auto glRasterPos2xvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed const  *)>(getProcAddress("glRasterPos2xvOES"));
	assert(glRasterPos2xvOES_ != nullptr);
	return glRasterPos2xvOES_(coords);
}
void glRasterPos3xOES(GLfixed x, GLfixed y, GLfixed z) {
	static const auto glRasterPos3xOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed, GLfixed, GLfixed)>(getProcAddress("glRasterPos3xOES"));
	assert(glRasterPos3xOES_ != nullptr);
	return glRasterPos3xOES_(x, y, z);
}
void glRasterPos3xvOES(GLfixed const  * coords) {
	static const auto glRasterPos3xvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed const  *)>(getProcAddress("glRasterPos3xvOES"));
	assert(glRasterPos3xvOES_ != nullptr);
	return glRasterPos3xvOES_(coords);
}
void glRasterPos4xOES(GLfixed x, GLfixed y, GLfixed z, GLfixed w) {
	static const auto glRasterPos4xOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed, GLfixed, GLfixed, GLfixed)>(getProcAddress("glRasterPos4xOES"));
	assert(glRasterPos4xOES_ != nullptr);
	return glRasterPos4xOES_(x, y, z, w);
}
void glRasterPos4xvOES(GLfixed const  * coords) {
	static const auto glRasterPos4xvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed const  *)>(getProcAddress("glRasterPos4xvOES"));
	assert(glRasterPos4xvOES_ != nullptr);
	return glRasterPos4xvOES_(coords);
}
void glRectxOES(GLfixed x1, GLfixed y1, GLfixed x2, GLfixed y2) {
	static const auto glRectxOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed, GLfixed, GLfixed, GLfixed)>(getProcAddress("glRectxOES"));
	assert(glRectxOES_ != nullptr);
	return glRectxOES_(x1, y1, x2, y2);
}
void glRectxvOES(GLfixed const  * v1, GLfixed const  * v2) {
	static const auto glRectxvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed const  *, GLfixed const  *)>(getProcAddress("glRectxvOES"));
	assert(glRectxvOES_ != nullptr);
	return glRectxvOES_(v1, v2);
}
void glTexCoord1xOES(GLfixed s) {
	static const auto glTexCoord1xOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed)>(getProcAddress("glTexCoord1xOES"));
	assert(glTexCoord1xOES_ != nullptr);
	return glTexCoord1xOES_(s);
}
void glTexCoord1xvOES(GLfixed const  * coords) {
	static const auto glTexCoord1xvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed const  *)>(getProcAddress("glTexCoord1xvOES"));
	assert(glTexCoord1xvOES_ != nullptr);
	return glTexCoord1xvOES_(coords);
}
void glTexCoord2xOES(GLfixed s, GLfixed t) {
	static const auto glTexCoord2xOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed, GLfixed)>(getProcAddress("glTexCoord2xOES"));
	assert(glTexCoord2xOES_ != nullptr);
	return glTexCoord2xOES_(s, t);
}
void glTexCoord2xvOES(GLfixed const  * coords) {
	static const auto glTexCoord2xvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed const  *)>(getProcAddress("glTexCoord2xvOES"));
	assert(glTexCoord2xvOES_ != nullptr);
	return glTexCoord2xvOES_(coords);
}
void glTexCoord3xOES(GLfixed s, GLfixed t, GLfixed r) {
	static const auto glTexCoord3xOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed, GLfixed, GLfixed)>(getProcAddress("glTexCoord3xOES"));
	assert(glTexCoord3xOES_ != nullptr);
	return glTexCoord3xOES_(s, t, r);
}
void glTexCoord3xvOES(GLfixed const  * coords) {
	static const auto glTexCoord3xvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed const  *)>(getProcAddress("glTexCoord3xvOES"));
	assert(glTexCoord3xvOES_ != nullptr);
	return glTexCoord3xvOES_(coords);
}
void glTexCoord4xOES(GLfixed s, GLfixed t, GLfixed r, GLfixed q) {
	static const auto glTexCoord4xOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed, GLfixed, GLfixed, GLfixed)>(getProcAddress("glTexCoord4xOES"));
	assert(glTexCoord4xOES_ != nullptr);
	return glTexCoord4xOES_(s, t, r, q);
}
void glTexCoord4xvOES(GLfixed const  * coords) {
	static const auto glTexCoord4xvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed const  *)>(getProcAddress("glTexCoord4xvOES"));
	assert(glTexCoord4xvOES_ != nullptr);
	return glTexCoord4xvOES_(coords);
}
void glTexGenxOES(GLenum coord, GLenum pname, GLfixed param) {
	static const auto glTexGenxOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfixed)>(getProcAddress("glTexGenxOES"));
	assert(glTexGenxOES_ != nullptr);
	return glTexGenxOES_(coord, pname, param);
}
void glTexGenxvOES(GLenum coord, GLenum pname, GLfixed const  * params) {
	static const auto glTexGenxvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfixed const  *)>(getProcAddress("glTexGenxvOES"));
	assert(glTexGenxvOES_ != nullptr);
	return glTexGenxvOES_(coord, pname, params);
}
void glVertex2xOES(GLfixed x) {
	static const auto glVertex2xOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed)>(getProcAddress("glVertex2xOES"));
	assert(glVertex2xOES_ != nullptr);
	return glVertex2xOES_(x);
}
void glVertex2xvOES(GLfixed const  * coords) {
	static const auto glVertex2xvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed const  *)>(getProcAddress("glVertex2xvOES"));
	assert(glVertex2xvOES_ != nullptr);
	return glVertex2xvOES_(coords);
}
void glVertex3xOES(GLfixed x, GLfixed y) {
	static const auto glVertex3xOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed, GLfixed)>(getProcAddress("glVertex3xOES"));
	assert(glVertex3xOES_ != nullptr);
	return glVertex3xOES_(x, y);
}
void glVertex3xvOES(GLfixed const  * coords) {
	static const auto glVertex3xvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed const  *)>(getProcAddress("glVertex3xvOES"));
	assert(glVertex3xvOES_ != nullptr);
	return glVertex3xvOES_(coords);
}
void glVertex4xOES(GLfixed x, GLfixed y, GLfixed z) {
	static const auto glVertex4xOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed, GLfixed, GLfixed)>(getProcAddress("glVertex4xOES"));
	assert(glVertex4xOES_ != nullptr);
	return glVertex4xOES_(x, y, z);
}
void glVertex4xvOES(GLfixed const  * coords) {
	static const auto glVertex4xvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed const  *)>(getProcAddress("glVertex4xvOES"));
	assert(glVertex4xvOES_ != nullptr);
	return glVertex4xvOES_(coords);
}
GLbitfield glQueryMatrixxOES(GLfixed * mantissa, GLint * exponent) {
	static const auto glQueryMatrixxOES_ = reinterpret_cast<GLbitfield(GL_APIENTRYP)(GLfixed *, GLint *)>(getProcAddress("glQueryMatrixxOES"));
	assert(glQueryMatrixxOES_ != nullptr);
	return glQueryMatrixxOES_(mantissa, exponent);
}
void glClearDepthfOES(GLclampf depth) {
	static const auto glClearDepthfOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLclampf)>(getProcAddress("glClearDepthfOES"));
	assert(glClearDepthfOES_ != nullptr);
	return glClearDepthfOES_(depth);
}
void glClipPlanefOES(GLenum plane, GLfloat const  * equation) {
	static const auto glClipPlanefOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfloat const  *)>(getProcAddress("glClipPlanefOES"));
	assert(glClipPlanefOES_ != nullptr);
	return glClipPlanefOES_(plane, equation);
}
void glDepthRangefOES(GLclampf n, GLclampf f) {
	static const auto glDepthRangefOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLclampf, GLclampf)>(getProcAddress("glDepthRangefOES"));
	assert(glDepthRangefOES_ != nullptr);
	return glDepthRangefOES_(n, f);
}
void glFrustumfOES(GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f) {
	static const auto glFrustumfOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat)>(getProcAddress("glFrustumfOES"));
	assert(glFrustumfOES_ != nullptr);
	return glFrustumfOES_(l, r, b, t, n, f);
}
void glGetClipPlanefOES(GLenum plane, GLfloat * equation) {
	static const auto glGetClipPlanefOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfloat *)>(getProcAddress("glGetClipPlanefOES"));
	assert(glGetClipPlanefOES_ != nullptr);
	return glGetClipPlanefOES_(plane, equation);
}
void glOrthofOES(GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f) {
	static const auto glOrthofOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat)>(getProcAddress("glOrthofOES"));
	assert(glOrthofOES_ != nullptr);
	return glOrthofOES_(l, r, b, t, n, f);
}

}
