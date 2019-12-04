/*

OpenGLES loader generated tool at 2019-12-04T00:06:30.5774120Z

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

#include <GLES/OpenGLES.h>

#include <cassert>
#include <dlfcn.h>
#if defined(__APPLE__)
#include <CoreFoundation/CoreFoundation.h>
#endif

namespace impl {
#if defined(__APPLE__)
gles::ProcAddress getProcAddress(const char *name) {
	static auto bundle = CFBundleGetBundleWithIdentifier(CFSTR("com.apple.opengles"));
	assert(bundle != NULL);
	
	CFRetain(bundle);
	static auto bundleURL = CFBundleCopyBundleURL(bundle);

	auto procname = CFStringCreateWithCString(kCFAllocatorDefault, name, kCFStringEncodingASCII);
	auto symbol = CFBundleGetFunctionPointerForName(bundle, procname);
	CFRelease(procname);
	return reinterpret_cast<gles::ProcAddress>(symbol);
}
#elif defined(__ANDROID__)
gles::ProcAddress getProcAddress(const char *name) {
	static auto library = dlopen("libGLESv1_CM.so", RTLD_LAZY);
	static auto library2 = dlopen("libGLESv2.so", RTLD_LAZY);
	// libGLESv3.so
	assert(library != nullptr);
	assert(library2 != nullptr);

	auto symbol = dlsym(library, name);
	if (!symbol)
		symbol = dlsym(library2, name);
	return reinterpret_cast<gles::ProcAddress>(symbol);
}
#endif
}

namespace gles {
GetProcAddress getProcAddress = nullptr;

void initialize(const GetProcAddress &resolver) {
	if (resolver == nullptr)
		getProcAddress = impl::getProcAddress;
	else
		getProcAddress = resolver;
}

void glAlphaFunc(GLenum func, GLfloat ref) {
	static const auto glAlphaFunc_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfloat)>(getProcAddress("glAlphaFunc"));
	assert(glAlphaFunc_ != nullptr);
	return glAlphaFunc_(func, ref);
}
void glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
	static const auto glClearColor_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat, GLfloat, GLfloat, GLfloat)>(getProcAddress("glClearColor"));
	assert(glClearColor_ != nullptr);
	return glClearColor_(red, green, blue, alpha);
}
void glClearDepthf(GLfloat d) {
	static const auto glClearDepthf_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat)>(getProcAddress("glClearDepthf"));
	assert(glClearDepthf_ != nullptr);
	return glClearDepthf_(d);
}
void glClipPlanef(GLenum p, GLfloat const  * eqn) {
	static const auto glClipPlanef_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfloat const  *)>(getProcAddress("glClipPlanef"));
	assert(glClipPlanef_ != nullptr);
	return glClipPlanef_(p, eqn);
}
void glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
	static const auto glColor4f_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat, GLfloat, GLfloat, GLfloat)>(getProcAddress("glColor4f"));
	assert(glColor4f_ != nullptr);
	return glColor4f_(red, green, blue, alpha);
}
void glDepthRangef(GLfloat n, GLfloat f) {
	static const auto glDepthRangef_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat, GLfloat)>(getProcAddress("glDepthRangef"));
	assert(glDepthRangef_ != nullptr);
	return glDepthRangef_(n, f);
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
void glFrustumf(GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f) {
	static const auto glFrustumf_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat)>(getProcAddress("glFrustumf"));
	assert(glFrustumf_ != nullptr);
	return glFrustumf_(l, r, b, t, n, f);
}
void glGetClipPlanef(GLenum plane, GLfloat * equation) {
	static const auto glGetClipPlanef_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfloat *)>(getProcAddress("glGetClipPlanef"));
	assert(glGetClipPlanef_ != nullptr);
	return glGetClipPlanef_(plane, equation);
}
void glGetFloatv(GLenum pname, GLfloat * data) {
	static const auto glGetFloatv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfloat *)>(getProcAddress("glGetFloatv"));
	assert(glGetFloatv_ != nullptr);
	return glGetFloatv_(pname, data);
}
void glGetLightfv(GLenum light, GLenum pname, GLfloat * params) {
	static const auto glGetLightfv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfloat *)>(getProcAddress("glGetLightfv"));
	assert(glGetLightfv_ != nullptr);
	return glGetLightfv_(light, pname, params);
}
void glGetMaterialfv(GLenum face, GLenum pname, GLfloat * params) {
	static const auto glGetMaterialfv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfloat *)>(getProcAddress("glGetMaterialfv"));
	assert(glGetMaterialfv_ != nullptr);
	return glGetMaterialfv_(face, pname, params);
}
void glGetTexEnvfv(GLenum target, GLenum pname, GLfloat * params) {
	static const auto glGetTexEnvfv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfloat *)>(getProcAddress("glGetTexEnvfv"));
	assert(glGetTexEnvfv_ != nullptr);
	return glGetTexEnvfv_(target, pname, params);
}
void glGetTexParameterfv(GLenum target, GLenum pname, GLfloat * params) {
	static const auto glGetTexParameterfv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfloat *)>(getProcAddress("glGetTexParameterfv"));
	assert(glGetTexParameterfv_ != nullptr);
	return glGetTexParameterfv_(target, pname, params);
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
void glLineWidth(GLfloat width) {
	static const auto glLineWidth_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat)>(getProcAddress("glLineWidth"));
	assert(glLineWidth_ != nullptr);
	return glLineWidth_(width);
}
void glLoadMatrixf(GLfloat const  * m) {
	static const auto glLoadMatrixf_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat const  *)>(getProcAddress("glLoadMatrixf"));
	assert(glLoadMatrixf_ != nullptr);
	return glLoadMatrixf_(m);
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
void glMultMatrixf(GLfloat const  * m) {
	static const auto glMultMatrixf_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat const  *)>(getProcAddress("glMultMatrixf"));
	assert(glMultMatrixf_ != nullptr);
	return glMultMatrixf_(m);
}
void glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) {
	static const auto glMultiTexCoord4f_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfloat, GLfloat, GLfloat, GLfloat)>(getProcAddress("glMultiTexCoord4f"));
	assert(glMultiTexCoord4f_ != nullptr);
	return glMultiTexCoord4f_(target, s, t, r, q);
}
void glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz) {
	static const auto glNormal3f_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat, GLfloat, GLfloat)>(getProcAddress("glNormal3f"));
	assert(glNormal3f_ != nullptr);
	return glNormal3f_(nx, ny, nz);
}
void glOrthof(GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f) {
	static const auto glOrthof_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat)>(getProcAddress("glOrthof"));
	assert(glOrthof_ != nullptr);
	return glOrthof_(l, r, b, t, n, f);
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
void glPointSize(GLfloat size) {
	static const auto glPointSize_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat)>(getProcAddress("glPointSize"));
	assert(glPointSize_ != nullptr);
	return glPointSize_(size);
}
void glPolygonOffset(GLfloat factor, GLfloat units) {
	static const auto glPolygonOffset_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat, GLfloat)>(getProcAddress("glPolygonOffset"));
	assert(glPolygonOffset_ != nullptr);
	return glPolygonOffset_(factor, units);
}
void glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z) {
	static const auto glRotatef_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat, GLfloat, GLfloat, GLfloat)>(getProcAddress("glRotatef"));
	assert(glRotatef_ != nullptr);
	return glRotatef_(angle, x, y, z);
}
void glScalef(GLfloat x, GLfloat y, GLfloat z) {
	static const auto glScalef_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat, GLfloat, GLfloat)>(getProcAddress("glScalef"));
	assert(glScalef_ != nullptr);
	return glScalef_(x, y, z);
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
void glTranslatef(GLfloat x, GLfloat y, GLfloat z) {
	static const auto glTranslatef_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat, GLfloat, GLfloat)>(getProcAddress("glTranslatef"));
	assert(glTranslatef_ != nullptr);
	return glTranslatef_(x, y, z);
}
void glActiveTexture(GLenum texture) {
	static const auto glActiveTexture_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glActiveTexture"));
	assert(glActiveTexture_ != nullptr);
	return glActiveTexture_(texture);
}
void glAlphaFuncx(GLenum func, GLfixed ref) {
	static const auto glAlphaFuncx_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfixed)>(getProcAddress("glAlphaFuncx"));
	assert(glAlphaFuncx_ != nullptr);
	return glAlphaFuncx_(func, ref);
}
void glBindBuffer(GLenum target, GLuint buffer) {
	static const auto glBindBuffer_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint)>(getProcAddress("glBindBuffer"));
	assert(glBindBuffer_ != nullptr);
	return glBindBuffer_(target, buffer);
}
void glBindTexture(GLenum target, GLuint texture) {
	static const auto glBindTexture_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint)>(getProcAddress("glBindTexture"));
	assert(glBindTexture_ != nullptr);
	return glBindTexture_(target, texture);
}
void glBlendFunc(GLenum sfactor, GLenum dfactor) {
	static const auto glBlendFunc_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum)>(getProcAddress("glBlendFunc"));
	assert(glBlendFunc_ != nullptr);
	return glBlendFunc_(sfactor, dfactor);
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
void glClear(GLbitfield mask) {
	static const auto glClear_ = reinterpret_cast<void(GL_APIENTRYP)(GLbitfield)>(getProcAddress("glClear"));
	assert(glClear_ != nullptr);
	return glClear_(mask);
}
void glClearColorx(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha) {
	static const auto glClearColorx_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed, GLfixed, GLfixed, GLfixed)>(getProcAddress("glClearColorx"));
	assert(glClearColorx_ != nullptr);
	return glClearColorx_(red, green, blue, alpha);
}
void glClearDepthx(GLfixed depth) {
	static const auto glClearDepthx_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed)>(getProcAddress("glClearDepthx"));
	assert(glClearDepthx_ != nullptr);
	return glClearDepthx_(depth);
}
void glClearStencil(GLint s) {
	static const auto glClearStencil_ = reinterpret_cast<void(GL_APIENTRYP)(GLint)>(getProcAddress("glClearStencil"));
	assert(glClearStencil_ != nullptr);
	return glClearStencil_(s);
}
void glClientActiveTexture(GLenum texture) {
	static const auto glClientActiveTexture_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glClientActiveTexture"));
	assert(glClientActiveTexture_ != nullptr);
	return glClientActiveTexture_(texture);
}
void glClipPlanex(GLenum plane, GLfixed const  * equation) {
	static const auto glClipPlanex_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfixed const  *)>(getProcAddress("glClipPlanex"));
	assert(glClipPlanex_ != nullptr);
	return glClipPlanex_(plane, equation);
}
void glColor4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha) {
	static const auto glColor4ub_ = reinterpret_cast<void(GL_APIENTRYP)(GLubyte, GLubyte, GLubyte, GLubyte)>(getProcAddress("glColor4ub"));
	assert(glColor4ub_ != nullptr);
	return glColor4ub_(red, green, blue, alpha);
}
void glColor4x(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha) {
	static const auto glColor4x_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed, GLfixed, GLfixed, GLfixed)>(getProcAddress("glColor4x"));
	assert(glColor4x_ != nullptr);
	return glColor4x_(red, green, blue, alpha);
}
void glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) {
	static const auto glColorMask_ = reinterpret_cast<void(GL_APIENTRYP)(GLboolean, GLboolean, GLboolean, GLboolean)>(getProcAddress("glColorMask"));
	assert(glColorMask_ != nullptr);
	return glColorMask_(red, green, blue, alpha);
}
void glColorPointer(GLint size, GLenum type, GLsizei stride, const void * pointer) {
	static const auto glColorPointer_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLenum, GLsizei, const void *)>(getProcAddress("glColorPointer"));
	assert(glColorPointer_ != nullptr);
	return glColorPointer_(size, type, stride, pointer);
}
void glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void * data) {
	static const auto glCompressedTexImage2D_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const void *)>(getProcAddress("glCompressedTexImage2D"));
	assert(glCompressedTexImage2D_ != nullptr);
	return glCompressedTexImage2D_(target, level, internalformat, width, height, border, imageSize, data);
}
void glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * data) {
	static const auto glCompressedTexSubImage2D_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const void *)>(getProcAddress("glCompressedTexSubImage2D"));
	assert(glCompressedTexSubImage2D_ != nullptr);
	return glCompressedTexSubImage2D_(target, level, xoffset, yoffset, width, height, format, imageSize, data);
}
void glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) {
	static const auto glCopyTexImage2D_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint)>(getProcAddress("glCopyTexImage2D"));
	assert(glCopyTexImage2D_ != nullptr);
	return glCopyTexImage2D_(target, level, internalformat, x, y, width, height, border);
}
void glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
	static const auto glCopyTexSubImage2D_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei)>(getProcAddress("glCopyTexSubImage2D"));
	assert(glCopyTexSubImage2D_ != nullptr);
	return glCopyTexSubImage2D_(target, level, xoffset, yoffset, x, y, width, height);
}
void glCullFace(GLenum mode) {
	static const auto glCullFace_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glCullFace"));
	assert(glCullFace_ != nullptr);
	return glCullFace_(mode);
}
void glDeleteBuffers(GLsizei n, GLuint const  * buffers) {
	static const auto glDeleteBuffers_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint const  *)>(getProcAddress("glDeleteBuffers"));
	assert(glDeleteBuffers_ != nullptr);
	return glDeleteBuffers_(n, buffers);
}
void glDeleteTextures(GLsizei n, GLuint const  * textures) {
	static const auto glDeleteTextures_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint const  *)>(getProcAddress("glDeleteTextures"));
	assert(glDeleteTextures_ != nullptr);
	return glDeleteTextures_(n, textures);
}
void glDepthFunc(GLenum func) {
	static const auto glDepthFunc_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glDepthFunc"));
	assert(glDepthFunc_ != nullptr);
	return glDepthFunc_(func);
}
void glDepthMask(GLboolean flag) {
	static const auto glDepthMask_ = reinterpret_cast<void(GL_APIENTRYP)(GLboolean)>(getProcAddress("glDepthMask"));
	assert(glDepthMask_ != nullptr);
	return glDepthMask_(flag);
}
void glDepthRangex(GLfixed n, GLfixed f) {
	static const auto glDepthRangex_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed, GLfixed)>(getProcAddress("glDepthRangex"));
	assert(glDepthRangex_ != nullptr);
	return glDepthRangex_(n, f);
}
void glDisable(GLenum cap) {
	static const auto glDisable_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glDisable"));
	assert(glDisable_ != nullptr);
	return glDisable_(cap);
}
void glDisableClientState(GLenum array) {
	static const auto glDisableClientState_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glDisableClientState"));
	assert(glDisableClientState_ != nullptr);
	return glDisableClientState_(array);
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
void glEnable(GLenum cap) {
	static const auto glEnable_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glEnable"));
	assert(glEnable_ != nullptr);
	return glEnable_(cap);
}
void glEnableClientState(GLenum array) {
	static const auto glEnableClientState_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glEnableClientState"));
	assert(glEnableClientState_ != nullptr);
	return glEnableClientState_(array);
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
void glFogx(GLenum pname, GLfixed param) {
	static const auto glFogx_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfixed)>(getProcAddress("glFogx"));
	assert(glFogx_ != nullptr);
	return glFogx_(pname, param);
}
void glFogxv(GLenum pname, GLfixed const  * param) {
	static const auto glFogxv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfixed const  *)>(getProcAddress("glFogxv"));
	assert(glFogxv_ != nullptr);
	return glFogxv_(pname, param);
}
void glFrontFace(GLenum mode) {
	static const auto glFrontFace_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glFrontFace"));
	assert(glFrontFace_ != nullptr);
	return glFrontFace_(mode);
}
void glFrustumx(GLfixed l, GLfixed r, GLfixed b, GLfixed t, GLfixed n, GLfixed f) {
	static const auto glFrustumx_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed, GLfixed, GLfixed, GLfixed, GLfixed, GLfixed)>(getProcAddress("glFrustumx"));
	assert(glFrustumx_ != nullptr);
	return glFrustumx_(l, r, b, t, n, f);
}
void glGetBooleanv(GLenum pname, GLboolean * data) {
	static const auto glGetBooleanv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLboolean *)>(getProcAddress("glGetBooleanv"));
	assert(glGetBooleanv_ != nullptr);
	return glGetBooleanv_(pname, data);
}
void glGetBufferParameteriv(GLenum target, GLenum pname, GLint * params) {
	static const auto glGetBufferParameteriv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint *)>(getProcAddress("glGetBufferParameteriv"));
	assert(glGetBufferParameteriv_ != nullptr);
	return glGetBufferParameteriv_(target, pname, params);
}
void glGetClipPlanex(GLenum plane, GLfixed * equation) {
	static const auto glGetClipPlanex_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfixed *)>(getProcAddress("glGetClipPlanex"));
	assert(glGetClipPlanex_ != nullptr);
	return glGetClipPlanex_(plane, equation);
}
void glGenBuffers(GLsizei n, GLuint * buffers) {
	static const auto glGenBuffers_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint *)>(getProcAddress("glGenBuffers"));
	assert(glGenBuffers_ != nullptr);
	return glGenBuffers_(n, buffers);
}
void glGenTextures(GLsizei n, GLuint * textures) {
	static const auto glGenTextures_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint *)>(getProcAddress("glGenTextures"));
	assert(glGenTextures_ != nullptr);
	return glGenTextures_(n, textures);
}
GLenum glGetError() {
	static const auto glGetError_ = reinterpret_cast<GLenum(GL_APIENTRYP)()>(getProcAddress("glGetError"));
	assert(glGetError_ != nullptr);
	return glGetError_();
}
void glGetFixedv(GLenum pname, GLfixed * params) {
	static const auto glGetFixedv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfixed *)>(getProcAddress("glGetFixedv"));
	assert(glGetFixedv_ != nullptr);
	return glGetFixedv_(pname, params);
}
void glGetIntegerv(GLenum pname, GLint * data) {
	static const auto glGetIntegerv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint *)>(getProcAddress("glGetIntegerv"));
	assert(glGetIntegerv_ != nullptr);
	return glGetIntegerv_(pname, data);
}
void glGetLightxv(GLenum light, GLenum pname, GLfixed * params) {
	static const auto glGetLightxv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfixed *)>(getProcAddress("glGetLightxv"));
	assert(glGetLightxv_ != nullptr);
	return glGetLightxv_(light, pname, params);
}
void glGetMaterialxv(GLenum face, GLenum pname, GLfixed * params) {
	static const auto glGetMaterialxv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfixed *)>(getProcAddress("glGetMaterialxv"));
	assert(glGetMaterialxv_ != nullptr);
	return glGetMaterialxv_(face, pname, params);
}
void glGetPointerv(GLenum pname, void ** params) {
	static const auto glGetPointerv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, void **)>(getProcAddress("glGetPointerv"));
	assert(glGetPointerv_ != nullptr);
	return glGetPointerv_(pname, params);
}
GLubyte const  * glGetString(GLenum name) {
	static const auto glGetString_ = reinterpret_cast<GLubyte const  *(GL_APIENTRYP)(GLenum)>(getProcAddress("glGetString"));
	assert(glGetString_ != nullptr);
	return glGetString_(name);
}
void glGetTexEnviv(GLenum target, GLenum pname, GLint * params) {
	static const auto glGetTexEnviv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint *)>(getProcAddress("glGetTexEnviv"));
	assert(glGetTexEnviv_ != nullptr);
	return glGetTexEnviv_(target, pname, params);
}
void glGetTexEnvxv(GLenum target, GLenum pname, GLfixed * params) {
	static const auto glGetTexEnvxv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfixed *)>(getProcAddress("glGetTexEnvxv"));
	assert(glGetTexEnvxv_ != nullptr);
	return glGetTexEnvxv_(target, pname, params);
}
void glGetTexParameteriv(GLenum target, GLenum pname, GLint * params) {
	static const auto glGetTexParameteriv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint *)>(getProcAddress("glGetTexParameteriv"));
	assert(glGetTexParameteriv_ != nullptr);
	return glGetTexParameteriv_(target, pname, params);
}
void glGetTexParameterxv(GLenum target, GLenum pname, GLfixed * params) {
	static const auto glGetTexParameterxv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfixed *)>(getProcAddress("glGetTexParameterxv"));
	assert(glGetTexParameterxv_ != nullptr);
	return glGetTexParameterxv_(target, pname, params);
}
void glHint(GLenum target, GLenum mode) {
	static const auto glHint_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum)>(getProcAddress("glHint"));
	assert(glHint_ != nullptr);
	return glHint_(target, mode);
}
GLboolean glIsBuffer(GLuint buffer) {
	static const auto glIsBuffer_ = reinterpret_cast<GLboolean(GL_APIENTRYP)(GLuint)>(getProcAddress("glIsBuffer"));
	assert(glIsBuffer_ != nullptr);
	return glIsBuffer_(buffer);
}
GLboolean glIsEnabled(GLenum cap) {
	static const auto glIsEnabled_ = reinterpret_cast<GLboolean(GL_APIENTRYP)(GLenum)>(getProcAddress("glIsEnabled"));
	assert(glIsEnabled_ != nullptr);
	return glIsEnabled_(cap);
}
GLboolean glIsTexture(GLuint texture) {
	static const auto glIsTexture_ = reinterpret_cast<GLboolean(GL_APIENTRYP)(GLuint)>(getProcAddress("glIsTexture"));
	assert(glIsTexture_ != nullptr);
	return glIsTexture_(texture);
}
void glLightModelx(GLenum pname, GLfixed param) {
	static const auto glLightModelx_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfixed)>(getProcAddress("glLightModelx"));
	assert(glLightModelx_ != nullptr);
	return glLightModelx_(pname, param);
}
void glLightModelxv(GLenum pname, GLfixed const  * param) {
	static const auto glLightModelxv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfixed const  *)>(getProcAddress("glLightModelxv"));
	assert(glLightModelxv_ != nullptr);
	return glLightModelxv_(pname, param);
}
void glLightx(GLenum light, GLenum pname, GLfixed param) {
	static const auto glLightx_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfixed)>(getProcAddress("glLightx"));
	assert(glLightx_ != nullptr);
	return glLightx_(light, pname, param);
}
void glLightxv(GLenum light, GLenum pname, GLfixed const  * params) {
	static const auto glLightxv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfixed const  *)>(getProcAddress("glLightxv"));
	assert(glLightxv_ != nullptr);
	return glLightxv_(light, pname, params);
}
void glLineWidthx(GLfixed width) {
	static const auto glLineWidthx_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed)>(getProcAddress("glLineWidthx"));
	assert(glLineWidthx_ != nullptr);
	return glLineWidthx_(width);
}
void glLoadIdentity() {
	static const auto glLoadIdentity_ = reinterpret_cast<void(GL_APIENTRYP)()>(getProcAddress("glLoadIdentity"));
	assert(glLoadIdentity_ != nullptr);
	return glLoadIdentity_();
}
void glLoadMatrixx(GLfixed const  * m) {
	static const auto glLoadMatrixx_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed const  *)>(getProcAddress("glLoadMatrixx"));
	assert(glLoadMatrixx_ != nullptr);
	return glLoadMatrixx_(m);
}
void glLogicOp(GLenum opcode) {
	static const auto glLogicOp_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glLogicOp"));
	assert(glLogicOp_ != nullptr);
	return glLogicOp_(opcode);
}
void glMaterialx(GLenum face, GLenum pname, GLfixed param) {
	static const auto glMaterialx_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfixed)>(getProcAddress("glMaterialx"));
	assert(glMaterialx_ != nullptr);
	return glMaterialx_(face, pname, param);
}
void glMaterialxv(GLenum face, GLenum pname, GLfixed const  * param) {
	static const auto glMaterialxv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfixed const  *)>(getProcAddress("glMaterialxv"));
	assert(glMaterialxv_ != nullptr);
	return glMaterialxv_(face, pname, param);
}
void glMatrixMode(GLenum mode) {
	static const auto glMatrixMode_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glMatrixMode"));
	assert(glMatrixMode_ != nullptr);
	return glMatrixMode_(mode);
}
void glMultMatrixx(GLfixed const  * m) {
	static const auto glMultMatrixx_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed const  *)>(getProcAddress("glMultMatrixx"));
	assert(glMultMatrixx_ != nullptr);
	return glMultMatrixx_(m);
}
void glMultiTexCoord4x(GLenum texture, GLfixed s, GLfixed t, GLfixed r, GLfixed q) {
	static const auto glMultiTexCoord4x_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfixed, GLfixed, GLfixed, GLfixed)>(getProcAddress("glMultiTexCoord4x"));
	assert(glMultiTexCoord4x_ != nullptr);
	return glMultiTexCoord4x_(texture, s, t, r, q);
}
void glNormal3x(GLfixed nx, GLfixed ny, GLfixed nz) {
	static const auto glNormal3x_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed, GLfixed, GLfixed)>(getProcAddress("glNormal3x"));
	assert(glNormal3x_ != nullptr);
	return glNormal3x_(nx, ny, nz);
}
void glNormalPointer(GLenum type, GLsizei stride, const void * pointer) {
	static const auto glNormalPointer_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, const void *)>(getProcAddress("glNormalPointer"));
	assert(glNormalPointer_ != nullptr);
	return glNormalPointer_(type, stride, pointer);
}
void glOrthox(GLfixed l, GLfixed r, GLfixed b, GLfixed t, GLfixed n, GLfixed f) {
	static const auto glOrthox_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed, GLfixed, GLfixed, GLfixed, GLfixed, GLfixed)>(getProcAddress("glOrthox"));
	assert(glOrthox_ != nullptr);
	return glOrthox_(l, r, b, t, n, f);
}
void glPixelStorei(GLenum pname, GLint param) {
	static const auto glPixelStorei_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint)>(getProcAddress("glPixelStorei"));
	assert(glPixelStorei_ != nullptr);
	return glPixelStorei_(pname, param);
}
void glPointParameterx(GLenum pname, GLfixed param) {
	static const auto glPointParameterx_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfixed)>(getProcAddress("glPointParameterx"));
	assert(glPointParameterx_ != nullptr);
	return glPointParameterx_(pname, param);
}
void glPointParameterxv(GLenum pname, GLfixed const  * params) {
	static const auto glPointParameterxv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLfixed const  *)>(getProcAddress("glPointParameterxv"));
	assert(glPointParameterxv_ != nullptr);
	return glPointParameterxv_(pname, params);
}
void glPointSizex(GLfixed size) {
	static const auto glPointSizex_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed)>(getProcAddress("glPointSizex"));
	assert(glPointSizex_ != nullptr);
	return glPointSizex_(size);
}
void glPolygonOffsetx(GLfixed factor, GLfixed units) {
	static const auto glPolygonOffsetx_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed, GLfixed)>(getProcAddress("glPolygonOffsetx"));
	assert(glPolygonOffsetx_ != nullptr);
	return glPolygonOffsetx_(factor, units);
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
void glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void * pixels) {
	static const auto glReadPixels_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, void *)>(getProcAddress("glReadPixels"));
	assert(glReadPixels_ != nullptr);
	return glReadPixels_(x, y, width, height, format, type, pixels);
}
void glRotatex(GLfixed angle, GLfixed x, GLfixed y, GLfixed z) {
	static const auto glRotatex_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed, GLfixed, GLfixed, GLfixed)>(getProcAddress("glRotatex"));
	assert(glRotatex_ != nullptr);
	return glRotatex_(angle, x, y, z);
}
void glSampleCoverage(GLfloat value, GLboolean invert) {
	static const auto glSampleCoverage_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat, GLboolean)>(getProcAddress("glSampleCoverage"));
	assert(glSampleCoverage_ != nullptr);
	return glSampleCoverage_(value, invert);
}
void glSampleCoveragex(GLclampx value, GLboolean invert) {
	static const auto glSampleCoveragex_ = reinterpret_cast<void(GL_APIENTRYP)(GLclampx, GLboolean)>(getProcAddress("glSampleCoveragex"));
	assert(glSampleCoveragex_ != nullptr);
	return glSampleCoveragex_(value, invert);
}
void glScalex(GLfixed x, GLfixed y, GLfixed z) {
	static const auto glScalex_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed, GLfixed, GLfixed)>(getProcAddress("glScalex"));
	assert(glScalex_ != nullptr);
	return glScalex_(x, y, z);
}
void glScissor(GLint x, GLint y, GLsizei width, GLsizei height) {
	static const auto glScissor_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLint, GLsizei, GLsizei)>(getProcAddress("glScissor"));
	assert(glScissor_ != nullptr);
	return glScissor_(x, y, width, height);
}
void glShadeModel(GLenum mode) {
	static const auto glShadeModel_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glShadeModel"));
	assert(glShadeModel_ != nullptr);
	return glShadeModel_(mode);
}
void glStencilFunc(GLenum func, GLint ref, GLuint mask) {
	static const auto glStencilFunc_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLuint)>(getProcAddress("glStencilFunc"));
	assert(glStencilFunc_ != nullptr);
	return glStencilFunc_(func, ref, mask);
}
void glStencilMask(GLuint mask) {
	static const auto glStencilMask_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint)>(getProcAddress("glStencilMask"));
	assert(glStencilMask_ != nullptr);
	return glStencilMask_(mask);
}
void glStencilOp(GLenum fail, GLenum zfail, GLenum zpass) {
	static const auto glStencilOp_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum)>(getProcAddress("glStencilOp"));
	assert(glStencilOp_ != nullptr);
	return glStencilOp_(fail, zfail, zpass);
}
void glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const void * pointer) {
	static const auto glTexCoordPointer_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLenum, GLsizei, const void *)>(getProcAddress("glTexCoordPointer"));
	assert(glTexCoordPointer_ != nullptr);
	return glTexCoordPointer_(size, type, stride, pointer);
}
void glTexEnvi(GLenum target, GLenum pname, GLint param) {
	static const auto glTexEnvi_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint)>(getProcAddress("glTexEnvi"));
	assert(glTexEnvi_ != nullptr);
	return glTexEnvi_(target, pname, param);
}
void glTexEnvx(GLenum target, GLenum pname, GLfixed param) {
	static const auto glTexEnvx_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfixed)>(getProcAddress("glTexEnvx"));
	assert(glTexEnvx_ != nullptr);
	return glTexEnvx_(target, pname, param);
}
void glTexEnviv(GLenum target, GLenum pname, GLint const  * params) {
	static const auto glTexEnviv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint const  *)>(getProcAddress("glTexEnviv"));
	assert(glTexEnviv_ != nullptr);
	return glTexEnviv_(target, pname, params);
}
void glTexEnvxv(GLenum target, GLenum pname, GLfixed const  * params) {
	static const auto glTexEnvxv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfixed const  *)>(getProcAddress("glTexEnvxv"));
	assert(glTexEnvxv_ != nullptr);
	return glTexEnvxv_(target, pname, params);
}
void glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void * pixels) {
	static const auto glTexImage2D_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const void *)>(getProcAddress("glTexImage2D"));
	assert(glTexImage2D_ != nullptr);
	return glTexImage2D_(target, level, internalformat, width, height, border, format, type, pixels);
}
void glTexParameteri(GLenum target, GLenum pname, GLint param) {
	static const auto glTexParameteri_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint)>(getProcAddress("glTexParameteri"));
	assert(glTexParameteri_ != nullptr);
	return glTexParameteri_(target, pname, param);
}
void glTexParameterx(GLenum target, GLenum pname, GLfixed param) {
	static const auto glTexParameterx_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfixed)>(getProcAddress("glTexParameterx"));
	assert(glTexParameterx_ != nullptr);
	return glTexParameterx_(target, pname, param);
}
void glTexParameteriv(GLenum target, GLenum pname, GLint const  * params) {
	static const auto glTexParameteriv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint const  *)>(getProcAddress("glTexParameteriv"));
	assert(glTexParameteriv_ != nullptr);
	return glTexParameteriv_(target, pname, params);
}
void glTexParameterxv(GLenum target, GLenum pname, GLfixed const  * params) {
	static const auto glTexParameterxv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfixed const  *)>(getProcAddress("glTexParameterxv"));
	assert(glTexParameterxv_ != nullptr);
	return glTexParameterxv_(target, pname, params);
}
void glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels) {
	static const auto glTexSubImage2D_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const void *)>(getProcAddress("glTexSubImage2D"));
	assert(glTexSubImage2D_ != nullptr);
	return glTexSubImage2D_(target, level, xoffset, yoffset, width, height, format, type, pixels);
}
void glTranslatex(GLfixed x, GLfixed y, GLfixed z) {
	static const auto glTranslatex_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed, GLfixed, GLfixed)>(getProcAddress("glTranslatex"));
	assert(glTranslatex_ != nullptr);
	return glTranslatex_(x, y, z);
}
void glVertexPointer(GLint size, GLenum type, GLsizei stride, const void * pointer) {
	static const auto glVertexPointer_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLenum, GLsizei, const void *)>(getProcAddress("glVertexPointer"));
	assert(glVertexPointer_ != nullptr);
	return glVertexPointer_(size, type, stride, pointer);
}
void glViewport(GLint x, GLint y, GLsizei width, GLsizei height) {
	static const auto glViewport_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLint, GLsizei, GLsizei)>(getProcAddress("glViewport"));
	assert(glViewport_ != nullptr);
	return glViewport_(x, y, width, height);
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
void glBindFramebuffer(GLenum target, GLuint framebuffer) {
	static const auto glBindFramebuffer_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint)>(getProcAddress("glBindFramebuffer"));
	assert(glBindFramebuffer_ != nullptr);
	return glBindFramebuffer_(target, framebuffer);
}
void glBindRenderbuffer(GLenum target, GLuint renderbuffer) {
	static const auto glBindRenderbuffer_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint)>(getProcAddress("glBindRenderbuffer"));
	assert(glBindRenderbuffer_ != nullptr);
	return glBindRenderbuffer_(target, renderbuffer);
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
void glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha) {
	static const auto glBlendEquationSeparate_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum)>(getProcAddress("glBlendEquationSeparate"));
	assert(glBlendEquationSeparate_ != nullptr);
	return glBlendEquationSeparate_(modeRGB, modeAlpha);
}
void glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) {
	static const auto glBlendFuncSeparate_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLenum)>(getProcAddress("glBlendFuncSeparate"));
	assert(glBlendFuncSeparate_ != nullptr);
	return glBlendFuncSeparate_(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
}
GLenum glCheckFramebufferStatus(GLenum target) {
	static const auto glCheckFramebufferStatus_ = reinterpret_cast<GLenum(GL_APIENTRYP)(GLenum)>(getProcAddress("glCheckFramebufferStatus"));
	assert(glCheckFramebufferStatus_ != nullptr);
	return glCheckFramebufferStatus_(target);
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
void glDeleteFramebuffers(GLsizei n, GLuint const  * framebuffers) {
	static const auto glDeleteFramebuffers_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint const  *)>(getProcAddress("glDeleteFramebuffers"));
	assert(glDeleteFramebuffers_ != nullptr);
	return glDeleteFramebuffers_(n, framebuffers);
}
void glDeleteProgram(GLuint program) {
	static const auto glDeleteProgram_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint)>(getProcAddress("glDeleteProgram"));
	assert(glDeleteProgram_ != nullptr);
	return glDeleteProgram_(program);
}
void glDeleteRenderbuffers(GLsizei n, GLuint const  * renderbuffers) {
	static const auto glDeleteRenderbuffers_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint const  *)>(getProcAddress("glDeleteRenderbuffers"));
	assert(glDeleteRenderbuffers_ != nullptr);
	return glDeleteRenderbuffers_(n, renderbuffers);
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
void glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) {
	static const auto glFramebufferRenderbuffer_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLuint)>(getProcAddress("glFramebufferRenderbuffer"));
	assert(glFramebufferRenderbuffer_ != nullptr);
	return glFramebufferRenderbuffer_(target, attachment, renderbuffertarget, renderbuffer);
}
void glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {
	static const auto glFramebufferTexture2D_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLuint, GLint)>(getProcAddress("glFramebufferTexture2D"));
	assert(glFramebufferTexture2D_ != nullptr);
	return glFramebufferTexture2D_(target, attachment, textarget, texture, level);
}
void glGenerateMipmap(GLenum target) {
	static const auto glGenerateMipmap_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glGenerateMipmap"));
	assert(glGenerateMipmap_ != nullptr);
	return glGenerateMipmap_(target);
}
void glGenFramebuffers(GLsizei n, GLuint * framebuffers) {
	static const auto glGenFramebuffers_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint *)>(getProcAddress("glGenFramebuffers"));
	assert(glGenFramebuffers_ != nullptr);
	return glGenFramebuffers_(n, framebuffers);
}
void glGenRenderbuffers(GLsizei n, GLuint * renderbuffers) {
	static const auto glGenRenderbuffers_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint *)>(getProcAddress("glGenRenderbuffers"));
	assert(glGenRenderbuffers_ != nullptr);
	return glGenRenderbuffers_(n, renderbuffers);
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
void glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint * params) {
	static const auto glGetFramebufferAttachmentParameteriv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLint *)>(getProcAddress("glGetFramebufferAttachmentParameteriv"));
	assert(glGetFramebufferAttachmentParameteriv_ != nullptr);
	return glGetFramebufferAttachmentParameteriv_(target, attachment, pname, params);
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
void glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint * params) {
	static const auto glGetRenderbufferParameteriv_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint *)>(getProcAddress("glGetRenderbufferParameteriv"));
	assert(glGetRenderbufferParameteriv_ != nullptr);
	return glGetRenderbufferParameteriv_(target, pname, params);
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
void glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint * range, GLint * precision) {
	static const auto glGetShaderPrecisionFormat_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint *, GLint *)>(getProcAddress("glGetShaderPrecisionFormat"));
	assert(glGetShaderPrecisionFormat_ != nullptr);
	return glGetShaderPrecisionFormat_(shadertype, precisiontype, range, precision);
}
void glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * source) {
	static const auto glGetShaderSource_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLsizei, GLsizei *, GLchar *)>(getProcAddress("glGetShaderSource"));
	assert(glGetShaderSource_ != nullptr);
	return glGetShaderSource_(shader, bufSize, length, source);
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
GLint glGetUniformLocation(GLuint program, GLchar const  * name) {
	static const auto glGetUniformLocation_ = reinterpret_cast<GLint(GL_APIENTRYP)(GLuint, GLchar const  *)>(getProcAddress("glGetUniformLocation"));
	assert(glGetUniformLocation_ != nullptr);
	return glGetUniformLocation_(program, name);
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
GLboolean glIsFramebuffer(GLuint framebuffer) {
	static const auto glIsFramebuffer_ = reinterpret_cast<GLboolean(GL_APIENTRYP)(GLuint)>(getProcAddress("glIsFramebuffer"));
	assert(glIsFramebuffer_ != nullptr);
	return glIsFramebuffer_(framebuffer);
}
GLboolean glIsProgram(GLuint program) {
	static const auto glIsProgram_ = reinterpret_cast<GLboolean(GL_APIENTRYP)(GLuint)>(getProcAddress("glIsProgram"));
	assert(glIsProgram_ != nullptr);
	return glIsProgram_(program);
}
GLboolean glIsRenderbuffer(GLuint renderbuffer) {
	static const auto glIsRenderbuffer_ = reinterpret_cast<GLboolean(GL_APIENTRYP)(GLuint)>(getProcAddress("glIsRenderbuffer"));
	assert(glIsRenderbuffer_ != nullptr);
	return glIsRenderbuffer_(renderbuffer);
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
void glReleaseShaderCompiler() {
	static const auto glReleaseShaderCompiler_ = reinterpret_cast<void(GL_APIENTRYP)()>(getProcAddress("glReleaseShaderCompiler"));
	assert(glReleaseShaderCompiler_ != nullptr);
	return glReleaseShaderCompiler_();
}
void glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) {
	static const auto glRenderbufferStorage_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLsizei, GLsizei)>(getProcAddress("glRenderbufferStorage"));
	assert(glRenderbufferStorage_ != nullptr);
	return glRenderbufferStorage_(target, internalformat, width, height);
}
void glShaderBinary(GLsizei count, GLuint const  * shaders, GLenum binaryformat, const void * binary, GLsizei length) {
	static const auto glShaderBinary_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint const  *, GLenum, const void *, GLsizei)>(getProcAddress("glShaderBinary"));
	assert(glShaderBinary_ != nullptr);
	return glShaderBinary_(count, shaders, binaryformat, binary, length);
}
void glShaderSource(GLuint shader, GLsizei count, GLchar const  *const* string, GLint const  * length) {
	static const auto glShaderSource_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLsizei, GLchar const  *const*, GLint const  *)>(getProcAddress("glShaderSource"));
	assert(glShaderSource_ != nullptr);
	return glShaderSource_(shader, count, string, length);
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
void glStencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass) {
	static const auto glStencilOpSeparate_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLenum)>(getProcAddress("glStencilOpSeparate"));
	assert(glStencilOpSeparate_ != nullptr);
	return glStencilOpSeparate_(face, sfail, dpfail, dppass);
}
void glUniform1f(GLint location, GLfloat v0) {
	static const auto glUniform1f_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLfloat)>(getProcAddress("glUniform1f"));
	assert(glUniform1f_ != nullptr);
	return glUniform1f_(location, v0);
}
void glUniform1fv(GLint location, GLsizei count, GLfloat const  * value) {
	static const auto glUniform1fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLfloat const  *)>(getProcAddress("glUniform1fv"));
	assert(glUniform1fv_ != nullptr);
	return glUniform1fv_(location, count, value);
}
void glUniform1i(GLint location, GLint v0) {
	static const auto glUniform1i_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLint)>(getProcAddress("glUniform1i"));
	assert(glUniform1i_ != nullptr);
	return glUniform1i_(location, v0);
}
void glUniform1iv(GLint location, GLsizei count, GLint const  * value) {
	static const auto glUniform1iv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLint const  *)>(getProcAddress("glUniform1iv"));
	assert(glUniform1iv_ != nullptr);
	return glUniform1iv_(location, count, value);
}
void glUniform2f(GLint location, GLfloat v0, GLfloat v1) {
	static const auto glUniform2f_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLfloat, GLfloat)>(getProcAddress("glUniform2f"));
	assert(glUniform2f_ != nullptr);
	return glUniform2f_(location, v0, v1);
}
void glUniform2fv(GLint location, GLsizei count, GLfloat const  * value) {
	static const auto glUniform2fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLfloat const  *)>(getProcAddress("glUniform2fv"));
	assert(glUniform2fv_ != nullptr);
	return glUniform2fv_(location, count, value);
}
void glUniform2i(GLint location, GLint v0, GLint v1) {
	static const auto glUniform2i_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLint, GLint)>(getProcAddress("glUniform2i"));
	assert(glUniform2i_ != nullptr);
	return glUniform2i_(location, v0, v1);
}
void glUniform2iv(GLint location, GLsizei count, GLint const  * value) {
	static const auto glUniform2iv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLint const  *)>(getProcAddress("glUniform2iv"));
	assert(glUniform2iv_ != nullptr);
	return glUniform2iv_(location, count, value);
}
void glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) {
	static const auto glUniform3f_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLfloat, GLfloat, GLfloat)>(getProcAddress("glUniform3f"));
	assert(glUniform3f_ != nullptr);
	return glUniform3f_(location, v0, v1, v2);
}
void glUniform3fv(GLint location, GLsizei count, GLfloat const  * value) {
	static const auto glUniform3fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLfloat const  *)>(getProcAddress("glUniform3fv"));
	assert(glUniform3fv_ != nullptr);
	return glUniform3fv_(location, count, value);
}
void glUniform3i(GLint location, GLint v0, GLint v1, GLint v2) {
	static const auto glUniform3i_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLint, GLint, GLint)>(getProcAddress("glUniform3i"));
	assert(glUniform3i_ != nullptr);
	return glUniform3i_(location, v0, v1, v2);
}
void glUniform3iv(GLint location, GLsizei count, GLint const  * value) {
	static const auto glUniform3iv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLint const  *)>(getProcAddress("glUniform3iv"));
	assert(glUniform3iv_ != nullptr);
	return glUniform3iv_(location, count, value);
}
void glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {
	static const auto glUniform4f_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLfloat, GLfloat, GLfloat, GLfloat)>(getProcAddress("glUniform4f"));
	assert(glUniform4f_ != nullptr);
	return glUniform4f_(location, v0, v1, v2, v3);
}
void glUniform4fv(GLint location, GLsizei count, GLfloat const  * value) {
	static const auto glUniform4fv_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLsizei, GLfloat const  *)>(getProcAddress("glUniform4fv"));
	assert(glUniform4fv_ != nullptr);
	return glUniform4fv_(location, count, value);
}
void glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) {
	static const auto glUniform4i_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLint, GLint, GLint, GLint)>(getProcAddress("glUniform4i"));
	assert(glUniform4i_ != nullptr);
	return glUniform4i_(location, v0, v1, v2, v3);
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
void glUseProgram(GLuint program) {
	static const auto glUseProgram_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint)>(getProcAddress("glUseProgram"));
	assert(glUseProgram_ != nullptr);
	return glUseProgram_(program);
}
void glValidateProgram(GLuint program) {
	static const auto glValidateProgram_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint)>(getProcAddress("glValidateProgram"));
	assert(glValidateProgram_ != nullptr);
	return glValidateProgram_(program);
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
void glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void * pointer) {
	static const auto glVertexAttribPointer_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLenum, GLboolean, GLsizei, const void *)>(getProcAddress("glVertexAttribPointer"));
	assert(glVertexAttribPointer_ != nullptr);
	return glVertexAttribPointer_(index, size, type, normalized, stride, pointer);
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
void glDrawArraysInstancedBaseInstanceEXT(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance) {
	static const auto glDrawArraysInstancedBaseInstanceEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLsizei, GLsizei, GLuint)>(getProcAddress("glDrawArraysInstancedBaseInstanceEXT"));
	assert(glDrawArraysInstancedBaseInstanceEXT_ != nullptr);
	return glDrawArraysInstancedBaseInstanceEXT_(mode, first, count, instancecount, baseinstance);
}
void glDrawElementsInstancedBaseInstanceEXT(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLuint baseinstance) {
	static const auto glDrawElementsInstancedBaseInstanceEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, GLenum, const void *, GLsizei, GLuint)>(getProcAddress("glDrawElementsInstancedBaseInstanceEXT"));
	assert(glDrawElementsInstancedBaseInstanceEXT_ != nullptr);
	return glDrawElementsInstancedBaseInstanceEXT_(mode, count, type, indices, instancecount, baseinstance);
}
void glDrawElementsInstancedBaseVertexBaseInstanceEXT(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance) {
	static const auto glDrawElementsInstancedBaseVertexBaseInstanceEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, GLenum, const void *, GLsizei, GLint, GLuint)>(getProcAddress("glDrawElementsInstancedBaseVertexBaseInstanceEXT"));
	assert(glDrawElementsInstancedBaseVertexBaseInstanceEXT_ != nullptr);
	return glDrawElementsInstancedBaseVertexBaseInstanceEXT_(mode, count, type, indices, instancecount, basevertex, baseinstance);
}
void glBindFragDataLocationIndexedEXT(GLuint program, GLuint colorNumber, GLuint index, GLchar const  * name) {
	static const auto glBindFragDataLocationIndexedEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLuint, GLchar const  *)>(getProcAddress("glBindFragDataLocationIndexedEXT"));
	assert(glBindFragDataLocationIndexedEXT_ != nullptr);
	return glBindFragDataLocationIndexedEXT_(program, colorNumber, index, name);
}
void glBindFragDataLocationEXT(GLuint program, GLuint color, GLchar const  * name) {
	static const auto glBindFragDataLocationEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint, GLchar const  *)>(getProcAddress("glBindFragDataLocationEXT"));
	assert(glBindFragDataLocationEXT_ != nullptr);
	return glBindFragDataLocationEXT_(program, color, name);
}
GLint glGetProgramResourceLocationIndexEXT(GLuint program, GLenum programInterface, GLchar const  * name) {
	static const auto glGetProgramResourceLocationIndexEXT_ = reinterpret_cast<GLint(GL_APIENTRYP)(GLuint, GLenum, GLchar const  *)>(getProcAddress("glGetProgramResourceLocationIndexEXT"));
	assert(glGetProgramResourceLocationIndexEXT_ != nullptr);
	return glGetProgramResourceLocationIndexEXT_(program, programInterface, name);
}
GLint glGetFragDataIndexEXT(GLuint program, GLchar const  * name) {
	static const auto glGetFragDataIndexEXT_ = reinterpret_cast<GLint(GL_APIENTRYP)(GLuint, GLchar const  *)>(getProcAddress("glGetFragDataIndexEXT"));
	assert(glGetFragDataIndexEXT_ != nullptr);
	return glGetFragDataIndexEXT_(program, name);
}
void glBlendEquationEXT(GLenum mode) {
	static const auto glBlendEquationEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glBlendEquationEXT"));
	assert(glBlendEquationEXT_ != nullptr);
	return glBlendEquationEXT_(mode);
}
void glBufferStorageEXT(GLenum target, GLsizeiptr size, const void * data, GLbitfield flags) {
	static const auto glBufferStorageEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizeiptr, const void *, GLbitfield)>(getProcAddress("glBufferStorageEXT"));
	assert(glBufferStorageEXT_ != nullptr);
	return glBufferStorageEXT_(target, size, data, flags);
}
void glClearTexImageEXT(GLuint texture, GLint level, GLenum format, GLenum type, const void * data) {
	static const auto glClearTexImageEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLenum, GLenum, const void *)>(getProcAddress("glClearTexImageEXT"));
	assert(glClearTexImageEXT_ != nullptr);
	return glClearTexImageEXT_(texture, level, format, type, data);
}
void glClearTexSubImageEXT(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * data) {
	static const auto glClearTexSubImageEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const void *)>(getProcAddress("glClearTexSubImageEXT"));
	assert(glClearTexSubImageEXT_ != nullptr);
	return glClearTexSubImageEXT_(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, data);
}
void glClipControlEXT(GLenum origin, GLenum depth) {
	static const auto glClipControlEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum)>(getProcAddress("glClipControlEXT"));
	assert(glClipControlEXT_ != nullptr);
	return glClipControlEXT_(origin, depth);
}
void glCopyImageSubDataEXT(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth) {
	static const auto glCopyImageSubDataEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint, GLint, GLint, GLint, GLuint, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei)>(getProcAddress("glCopyImageSubDataEXT"));
	assert(glCopyImageSubDataEXT_ != nullptr);
	return glCopyImageSubDataEXT_(srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth);
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
void glDiscardFramebufferEXT(GLenum target, GLsizei numAttachments, GLenum const  * attachments) {
	static const auto glDiscardFramebufferEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, GLenum const  *)>(getProcAddress("glDiscardFramebufferEXT"));
	assert(glDiscardFramebufferEXT_ != nullptr);
	return glDiscardFramebufferEXT_(target, numAttachments, attachments);
}
void glGenQueriesEXT(GLsizei n, GLuint * ids) {
	static const auto glGenQueriesEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint *)>(getProcAddress("glGenQueriesEXT"));
	assert(glGenQueriesEXT_ != nullptr);
	return glGenQueriesEXT_(n, ids);
}
void glDeleteQueriesEXT(GLsizei n, GLuint const  * ids) {
	static const auto glDeleteQueriesEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint const  *)>(getProcAddress("glDeleteQueriesEXT"));
	assert(glDeleteQueriesEXT_ != nullptr);
	return glDeleteQueriesEXT_(n, ids);
}
GLboolean glIsQueryEXT(GLuint id) {
	static const auto glIsQueryEXT_ = reinterpret_cast<GLboolean(GL_APIENTRYP)(GLuint)>(getProcAddress("glIsQueryEXT"));
	assert(glIsQueryEXT_ != nullptr);
	return glIsQueryEXT_(id);
}
void glBeginQueryEXT(GLenum target, GLuint id) {
	static const auto glBeginQueryEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint)>(getProcAddress("glBeginQueryEXT"));
	assert(glBeginQueryEXT_ != nullptr);
	return glBeginQueryEXT_(target, id);
}
void glEndQueryEXT(GLenum target) {
	static const auto glEndQueryEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glEndQueryEXT"));
	assert(glEndQueryEXT_ != nullptr);
	return glEndQueryEXT_(target);
}
void glQueryCounterEXT(GLuint id, GLenum target) {
	static const auto glQueryCounterEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum)>(getProcAddress("glQueryCounterEXT"));
	assert(glQueryCounterEXT_ != nullptr);
	return glQueryCounterEXT_(id, target);
}
void glGetQueryivEXT(GLenum target, GLenum pname, GLint * params) {
	static const auto glGetQueryivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint *)>(getProcAddress("glGetQueryivEXT"));
	assert(glGetQueryivEXT_ != nullptr);
	return glGetQueryivEXT_(target, pname, params);
}
void glGetQueryObjectivEXT(GLuint id, GLenum pname, GLint * params) {
	static const auto glGetQueryObjectivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint *)>(getProcAddress("glGetQueryObjectivEXT"));
	assert(glGetQueryObjectivEXT_ != nullptr);
	return glGetQueryObjectivEXT_(id, pname, params);
}
void glGetQueryObjectuivEXT(GLuint id, GLenum pname, GLuint * params) {
	static const auto glGetQueryObjectuivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLuint *)>(getProcAddress("glGetQueryObjectuivEXT"));
	assert(glGetQueryObjectuivEXT_ != nullptr);
	return glGetQueryObjectuivEXT_(id, pname, params);
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
void glGetInteger64vEXT(GLenum pname, GLint64 * data) {
	static const auto glGetInteger64vEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint64 *)>(getProcAddress("glGetInteger64vEXT"));
	assert(glGetInteger64vEXT_ != nullptr);
	return glGetInteger64vEXT_(pname, data);
}
void glDrawBuffersEXT(GLsizei n, GLenum const  * bufs) {
	static const auto glDrawBuffersEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLenum const  *)>(getProcAddress("glDrawBuffersEXT"));
	assert(glDrawBuffersEXT_ != nullptr);
	return glDrawBuffersEXT_(n, bufs);
}
void glEnableiEXT(GLenum target, GLuint index) {
	static const auto glEnableiEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint)>(getProcAddress("glEnableiEXT"));
	assert(glEnableiEXT_ != nullptr);
	return glEnableiEXT_(target, index);
}
void glDisableiEXT(GLenum target, GLuint index) {
	static const auto glDisableiEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint)>(getProcAddress("glDisableiEXT"));
	assert(glDisableiEXT_ != nullptr);
	return glDisableiEXT_(target, index);
}
void glBlendEquationiEXT(GLuint buf, GLenum mode) {
	static const auto glBlendEquationiEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum)>(getProcAddress("glBlendEquationiEXT"));
	assert(glBlendEquationiEXT_ != nullptr);
	return glBlendEquationiEXT_(buf, mode);
}
void glBlendEquationSeparateiEXT(GLuint buf, GLenum modeRGB, GLenum modeAlpha) {
	static const auto glBlendEquationSeparateiEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLenum)>(getProcAddress("glBlendEquationSeparateiEXT"));
	assert(glBlendEquationSeparateiEXT_ != nullptr);
	return glBlendEquationSeparateiEXT_(buf, modeRGB, modeAlpha);
}
void glBlendFunciEXT(GLuint buf, GLenum src, GLenum dst) {
	static const auto glBlendFunciEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLenum)>(getProcAddress("glBlendFunciEXT"));
	assert(glBlendFunciEXT_ != nullptr);
	return glBlendFunciEXT_(buf, src, dst);
}
void glBlendFuncSeparateiEXT(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) {
	static const auto glBlendFuncSeparateiEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLenum, GLenum, GLenum)>(getProcAddress("glBlendFuncSeparateiEXT"));
	assert(glBlendFuncSeparateiEXT_ != nullptr);
	return glBlendFuncSeparateiEXT_(buf, srcRGB, dstRGB, srcAlpha, dstAlpha);
}
void glColorMaskiEXT(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a) {
	static const auto glColorMaskiEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLboolean, GLboolean, GLboolean, GLboolean)>(getProcAddress("glColorMaskiEXT"));
	assert(glColorMaskiEXT_ != nullptr);
	return glColorMaskiEXT_(index, r, g, b, a);
}
GLboolean glIsEnablediEXT(GLenum target, GLuint index) {
	static const auto glIsEnablediEXT_ = reinterpret_cast<GLboolean(GL_APIENTRYP)(GLenum, GLuint)>(getProcAddress("glIsEnablediEXT"));
	assert(glIsEnablediEXT_ != nullptr);
	return glIsEnablediEXT_(target, index);
}
void glDrawElementsBaseVertexEXT(GLenum mode, GLsizei count, GLenum type, const void * indices, GLint basevertex) {
	static const auto glDrawElementsBaseVertexEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, GLenum, const void *, GLint)>(getProcAddress("glDrawElementsBaseVertexEXT"));
	assert(glDrawElementsBaseVertexEXT_ != nullptr);
	return glDrawElementsBaseVertexEXT_(mode, count, type, indices, basevertex);
}
void glDrawRangeElementsBaseVertexEXT(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices, GLint basevertex) {
	static const auto glDrawRangeElementsBaseVertexEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint, GLuint, GLsizei, GLenum, const void *, GLint)>(getProcAddress("glDrawRangeElementsBaseVertexEXT"));
	assert(glDrawRangeElementsBaseVertexEXT_ != nullptr);
	return glDrawRangeElementsBaseVertexEXT_(mode, start, end, count, type, indices, basevertex);
}
void glDrawElementsInstancedBaseVertexEXT(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex) {
	static const auto glDrawElementsInstancedBaseVertexEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, GLenum, const void *, GLsizei, GLint)>(getProcAddress("glDrawElementsInstancedBaseVertexEXT"));
	assert(glDrawElementsInstancedBaseVertexEXT_ != nullptr);
	return glDrawElementsInstancedBaseVertexEXT_(mode, count, type, indices, instancecount, basevertex);
}
void glMultiDrawElementsBaseVertexEXT(GLenum mode, GLsizei const  * count, GLenum type, const void *const* indices, GLsizei primcount, GLint const  * basevertex) {
	static const auto glMultiDrawElementsBaseVertexEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei const  *, GLenum, const void *const*, GLsizei, GLint const  *)>(getProcAddress("glMultiDrawElementsBaseVertexEXT"));
	assert(glMultiDrawElementsBaseVertexEXT_ != nullptr);
	return glMultiDrawElementsBaseVertexEXT_(mode, count, type, indices, primcount, basevertex);
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
void glDrawTransformFeedbackEXT(GLenum mode, GLuint id) {
	static const auto glDrawTransformFeedbackEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint)>(getProcAddress("glDrawTransformFeedbackEXT"));
	assert(glDrawTransformFeedbackEXT_ != nullptr);
	return glDrawTransformFeedbackEXT_(mode, id);
}
void glDrawTransformFeedbackInstancedEXT(GLenum mode, GLuint id, GLsizei instancecount) {
	static const auto glDrawTransformFeedbackInstancedEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint, GLsizei)>(getProcAddress("glDrawTransformFeedbackInstancedEXT"));
	assert(glDrawTransformFeedbackInstancedEXT_ != nullptr);
	return glDrawTransformFeedbackInstancedEXT_(mode, id, instancecount);
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
void glFramebufferTextureEXT(GLenum target, GLenum attachment, GLuint texture, GLint level) {
	static const auto glFramebufferTextureEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLuint, GLint)>(getProcAddress("glFramebufferTextureEXT"));
	assert(glFramebufferTextureEXT_ != nullptr);
	return glFramebufferTextureEXT_(target, attachment, texture, level);
}
void glVertexAttribDivisorEXT(GLuint index, GLuint divisor) {
	static const auto glVertexAttribDivisorEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLuint)>(getProcAddress("glVertexAttribDivisorEXT"));
	assert(glVertexAttribDivisorEXT_ != nullptr);
	return glVertexAttribDivisorEXT_(index, divisor);
}
void * glMapBufferRangeEXT(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access) {
	static const auto glMapBufferRangeEXT_ = reinterpret_cast<void *(GL_APIENTRYP)(GLenum, GLintptr, GLsizeiptr, GLbitfield)>(getProcAddress("glMapBufferRangeEXT"));
	assert(glMapBufferRangeEXT_ != nullptr);
	return glMapBufferRangeEXT_(target, offset, length, access);
}
void glFlushMappedBufferRangeEXT(GLenum target, GLintptr offset, GLsizeiptr length) {
	static const auto glFlushMappedBufferRangeEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLintptr, GLsizeiptr)>(getProcAddress("glFlushMappedBufferRangeEXT"));
	assert(glFlushMappedBufferRangeEXT_ != nullptr);
	return glFlushMappedBufferRangeEXT_(target, offset, length);
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
void glMultiDrawArraysIndirectEXT(GLenum mode, const void * indirect, GLsizei drawcount, GLsizei stride) {
	static const auto glMultiDrawArraysIndirectEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, const void *, GLsizei, GLsizei)>(getProcAddress("glMultiDrawArraysIndirectEXT"));
	assert(glMultiDrawArraysIndirectEXT_ != nullptr);
	return glMultiDrawArraysIndirectEXT_(mode, indirect, drawcount, stride);
}
void glMultiDrawElementsIndirectEXT(GLenum mode, GLenum type, const void * indirect, GLsizei drawcount, GLsizei stride) {
	static const auto glMultiDrawElementsIndirectEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, const void *, GLsizei, GLsizei)>(getProcAddress("glMultiDrawElementsIndirectEXT"));
	assert(glMultiDrawElementsIndirectEXT_ != nullptr);
	return glMultiDrawElementsIndirectEXT_(mode, type, indirect, drawcount, stride);
}
void glRenderbufferStorageMultisampleEXT(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) {
	static const auto glRenderbufferStorageMultisampleEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, GLenum, GLsizei, GLsizei)>(getProcAddress("glRenderbufferStorageMultisampleEXT"));
	assert(glRenderbufferStorageMultisampleEXT_ != nullptr);
	return glRenderbufferStorageMultisampleEXT_(target, samples, internalformat, width, height);
}
void glFramebufferTexture2DMultisampleEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLsizei samples) {
	static const auto glFramebufferTexture2DMultisampleEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLuint, GLint, GLsizei)>(getProcAddress("glFramebufferTexture2DMultisampleEXT"));
	assert(glFramebufferTexture2DMultisampleEXT_ != nullptr);
	return glFramebufferTexture2DMultisampleEXT_(target, attachment, textarget, texture, level, samples);
}
void glReadBufferIndexedEXT(GLenum src, GLint index) {
	static const auto glReadBufferIndexedEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint)>(getProcAddress("glReadBufferIndexedEXT"));
	assert(glReadBufferIndexedEXT_ != nullptr);
	return glReadBufferIndexedEXT_(src, index);
}
void glDrawBuffersIndexedEXT(GLint n, GLenum const  * location, GLint const  * indices) {
	static const auto glDrawBuffersIndexedEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLenum const  *, GLint const  *)>(getProcAddress("glDrawBuffersIndexedEXT"));
	assert(glDrawBuffersIndexedEXT_ != nullptr);
	return glDrawBuffersIndexedEXT_(n, location, indices);
}
void glGetIntegeri_vEXT(GLenum target, GLuint index, GLint * data) {
	static const auto glGetIntegeri_vEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint, GLint *)>(getProcAddress("glGetIntegeri_vEXT"));
	assert(glGetIntegeri_vEXT_ != nullptr);
	return glGetIntegeri_vEXT_(target, index, data);
}
void glPolygonOffsetClampEXT(GLfloat factor, GLfloat units, GLfloat clamp) {
	static const auto glPolygonOffsetClampEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat, GLfloat, GLfloat)>(getProcAddress("glPolygonOffsetClampEXT"));
	assert(glPolygonOffsetClampEXT_ != nullptr);
	return glPolygonOffsetClampEXT_(factor, units, clamp);
}
void glPrimitiveBoundingBoxEXT(GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat minW, GLfloat maxX, GLfloat maxY, GLfloat maxZ, GLfloat maxW) {
	static const auto glPrimitiveBoundingBoxEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat)>(getProcAddress("glPrimitiveBoundingBoxEXT"));
	assert(glPrimitiveBoundingBoxEXT_ != nullptr);
	return glPrimitiveBoundingBoxEXT_(minX, minY, minZ, minW, maxX, maxY, maxZ, maxW);
}
void glRasterSamplesEXT(GLuint samples, GLboolean fixedsamplelocations) {
	static const auto glRasterSamplesEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLboolean)>(getProcAddress("glRasterSamplesEXT"));
	assert(glRasterSamplesEXT_ != nullptr);
	return glRasterSamplesEXT_(samples, fixedsamplelocations);
}
GLenum glGetGraphicsResetStatusEXT() {
	static const auto glGetGraphicsResetStatusEXT_ = reinterpret_cast<GLenum(GL_APIENTRYP)()>(getProcAddress("glGetGraphicsResetStatusEXT"));
	assert(glGetGraphicsResetStatusEXT_ != nullptr);
	return glGetGraphicsResetStatusEXT_();
}
void glReadnPixelsEXT(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void * data) {
	static const auto glReadnPixelsEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, GLsizei, void *)>(getProcAddress("glReadnPixelsEXT"));
	assert(glReadnPixelsEXT_ != nullptr);
	return glReadnPixelsEXT_(x, y, width, height, format, type, bufSize, data);
}
void glGetnUniformfvEXT(GLuint program, GLint location, GLsizei bufSize, GLfloat * params) {
	static const auto glGetnUniformfvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLfloat *)>(getProcAddress("glGetnUniformfvEXT"));
	assert(glGetnUniformfvEXT_ != nullptr);
	return glGetnUniformfvEXT_(program, location, bufSize, params);
}
void glGetnUniformivEXT(GLuint program, GLint location, GLsizei bufSize, GLint * params) {
	static const auto glGetnUniformivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLint *)>(getProcAddress("glGetnUniformivEXT"));
	assert(glGetnUniformivEXT_ != nullptr);
	return glGetnUniformivEXT_(program, location, bufSize, params);
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
void glProgramParameteriEXT(GLuint program, GLenum pname, GLint value) {
	static const auto glProgramParameteriEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint)>(getProcAddress("glProgramParameteriEXT"));
	assert(glProgramParameteriEXT_ != nullptr);
	return glProgramParameteriEXT_(program, pname, value);
}
void glProgramUniform1fEXT(GLuint program, GLint location, GLfloat v0) {
	static const auto glProgramUniform1fEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLfloat)>(getProcAddress("glProgramUniform1fEXT"));
	assert(glProgramUniform1fEXT_ != nullptr);
	return glProgramUniform1fEXT_(program, location, v0);
}
void glProgramUniform1fvEXT(GLuint program, GLint location, GLsizei count, GLfloat const  * value) {
	static const auto glProgramUniform1fvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLfloat const  *)>(getProcAddress("glProgramUniform1fvEXT"));
	assert(glProgramUniform1fvEXT_ != nullptr);
	return glProgramUniform1fvEXT_(program, location, count, value);
}
void glProgramUniform1iEXT(GLuint program, GLint location, GLint v0) {
	static const auto glProgramUniform1iEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLint)>(getProcAddress("glProgramUniform1iEXT"));
	assert(glProgramUniform1iEXT_ != nullptr);
	return glProgramUniform1iEXT_(program, location, v0);
}
void glProgramUniform1ivEXT(GLuint program, GLint location, GLsizei count, GLint const  * value) {
	static const auto glProgramUniform1ivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLint const  *)>(getProcAddress("glProgramUniform1ivEXT"));
	assert(glProgramUniform1ivEXT_ != nullptr);
	return glProgramUniform1ivEXT_(program, location, count, value);
}
void glProgramUniform2fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1) {
	static const auto glProgramUniform2fEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLfloat, GLfloat)>(getProcAddress("glProgramUniform2fEXT"));
	assert(glProgramUniform2fEXT_ != nullptr);
	return glProgramUniform2fEXT_(program, location, v0, v1);
}
void glProgramUniform2fvEXT(GLuint program, GLint location, GLsizei count, GLfloat const  * value) {
	static const auto glProgramUniform2fvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLfloat const  *)>(getProcAddress("glProgramUniform2fvEXT"));
	assert(glProgramUniform2fvEXT_ != nullptr);
	return glProgramUniform2fvEXT_(program, location, count, value);
}
void glProgramUniform2iEXT(GLuint program, GLint location, GLint v0, GLint v1) {
	static const auto glProgramUniform2iEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLint, GLint)>(getProcAddress("glProgramUniform2iEXT"));
	assert(glProgramUniform2iEXT_ != nullptr);
	return glProgramUniform2iEXT_(program, location, v0, v1);
}
void glProgramUniform2ivEXT(GLuint program, GLint location, GLsizei count, GLint const  * value) {
	static const auto glProgramUniform2ivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLint const  *)>(getProcAddress("glProgramUniform2ivEXT"));
	assert(glProgramUniform2ivEXT_ != nullptr);
	return glProgramUniform2ivEXT_(program, location, count, value);
}
void glProgramUniform3fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2) {
	static const auto glProgramUniform3fEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLfloat, GLfloat, GLfloat)>(getProcAddress("glProgramUniform3fEXT"));
	assert(glProgramUniform3fEXT_ != nullptr);
	return glProgramUniform3fEXT_(program, location, v0, v1, v2);
}
void glProgramUniform3fvEXT(GLuint program, GLint location, GLsizei count, GLfloat const  * value) {
	static const auto glProgramUniform3fvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLfloat const  *)>(getProcAddress("glProgramUniform3fvEXT"));
	assert(glProgramUniform3fvEXT_ != nullptr);
	return glProgramUniform3fvEXT_(program, location, count, value);
}
void glProgramUniform3iEXT(GLuint program, GLint location, GLint v0, GLint v1, GLint v2) {
	static const auto glProgramUniform3iEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLint, GLint, GLint)>(getProcAddress("glProgramUniform3iEXT"));
	assert(glProgramUniform3iEXT_ != nullptr);
	return glProgramUniform3iEXT_(program, location, v0, v1, v2);
}
void glProgramUniform3ivEXT(GLuint program, GLint location, GLsizei count, GLint const  * value) {
	static const auto glProgramUniform3ivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLint const  *)>(getProcAddress("glProgramUniform3ivEXT"));
	assert(glProgramUniform3ivEXT_ != nullptr);
	return glProgramUniform3ivEXT_(program, location, count, value);
}
void glProgramUniform4fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {
	static const auto glProgramUniform4fEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLfloat, GLfloat, GLfloat, GLfloat)>(getProcAddress("glProgramUniform4fEXT"));
	assert(glProgramUniform4fEXT_ != nullptr);
	return glProgramUniform4fEXT_(program, location, v0, v1, v2, v3);
}
void glProgramUniform4fvEXT(GLuint program, GLint location, GLsizei count, GLfloat const  * value) {
	static const auto glProgramUniform4fvEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLsizei, GLfloat const  *)>(getProcAddress("glProgramUniform4fvEXT"));
	assert(glProgramUniform4fvEXT_ != nullptr);
	return glProgramUniform4fvEXT_(program, location, count, value);
}
void glProgramUniform4iEXT(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3) {
	static const auto glProgramUniform4iEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLint, GLint, GLint, GLint)>(getProcAddress("glProgramUniform4iEXT"));
	assert(glProgramUniform4iEXT_ != nullptr);
	return glProgramUniform4iEXT_(program, location, v0, v1, v2, v3);
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
void glFramebufferFetchBarrierEXT() {
	static const auto glFramebufferFetchBarrierEXT_ = reinterpret_cast<void(GL_APIENTRYP)()>(getProcAddress("glFramebufferFetchBarrierEXT"));
	assert(glFramebufferFetchBarrierEXT_ != nullptr);
	return glFramebufferFetchBarrierEXT_();
}
void glFramebufferPixelLocalStorageSizeEXT(GLuint target, GLsizei size) {
	static const auto glFramebufferPixelLocalStorageSizeEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLsizei)>(getProcAddress("glFramebufferPixelLocalStorageSizeEXT"));
	assert(glFramebufferPixelLocalStorageSizeEXT_ != nullptr);
	return glFramebufferPixelLocalStorageSizeEXT_(target, size);
}
GLsizei glGetFramebufferPixelLocalStorageSizeEXT(GLuint target) {
	static const auto glGetFramebufferPixelLocalStorageSizeEXT_ = reinterpret_cast<GLsizei(GL_APIENTRYP)(GLuint)>(getProcAddress("glGetFramebufferPixelLocalStorageSizeEXT"));
	assert(glGetFramebufferPixelLocalStorageSizeEXT_ != nullptr);
	return glGetFramebufferPixelLocalStorageSizeEXT_(target);
}
void glClearPixelLocalStorageuiEXT(GLsizei offset, GLsizei n, GLuint const  * values) {
	static const auto glClearPixelLocalStorageuiEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLsizei, GLuint const  *)>(getProcAddress("glClearPixelLocalStorageuiEXT"));
	assert(glClearPixelLocalStorageuiEXT_ != nullptr);
	return glClearPixelLocalStorageuiEXT_(offset, n, values);
}
void glTexPageCommitmentEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit) {
	static const auto glTexPageCommitmentEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLboolean)>(getProcAddress("glTexPageCommitmentEXT"));
	assert(glTexPageCommitmentEXT_ != nullptr);
	return glTexPageCommitmentEXT_(target, level, xoffset, yoffset, zoffset, width, height, depth, commit);
}
void glPatchParameteriEXT(GLenum pname, GLint value) {
	static const auto glPatchParameteriEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint)>(getProcAddress("glPatchParameteriEXT"));
	assert(glPatchParameteriEXT_ != nullptr);
	return glPatchParameteriEXT_(pname, value);
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
void glSamplerParameterIivEXT(GLuint sampler, GLenum pname, GLint const  * param) {
	static const auto glSamplerParameterIivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint const  *)>(getProcAddress("glSamplerParameterIivEXT"));
	assert(glSamplerParameterIivEXT_ != nullptr);
	return glSamplerParameterIivEXT_(sampler, pname, param);
}
void glSamplerParameterIuivEXT(GLuint sampler, GLenum pname, GLuint const  * param) {
	static const auto glSamplerParameterIuivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLuint const  *)>(getProcAddress("glSamplerParameterIuivEXT"));
	assert(glSamplerParameterIuivEXT_ != nullptr);
	return glSamplerParameterIuivEXT_(sampler, pname, param);
}
void glGetSamplerParameterIivEXT(GLuint sampler, GLenum pname, GLint * params) {
	static const auto glGetSamplerParameterIivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint *)>(getProcAddress("glGetSamplerParameterIivEXT"));
	assert(glGetSamplerParameterIivEXT_ != nullptr);
	return glGetSamplerParameterIivEXT_(sampler, pname, params);
}
void glGetSamplerParameterIuivEXT(GLuint sampler, GLenum pname, GLuint * params) {
	static const auto glGetSamplerParameterIuivEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLuint *)>(getProcAddress("glGetSamplerParameterIuivEXT"));
	assert(glGetSamplerParameterIuivEXT_ != nullptr);
	return glGetSamplerParameterIuivEXT_(sampler, pname, params);
}
void glTexBufferEXT(GLenum target, GLenum internalformat, GLuint buffer) {
	static const auto glTexBufferEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLuint)>(getProcAddress("glTexBufferEXT"));
	assert(glTexBufferEXT_ != nullptr);
	return glTexBufferEXT_(target, internalformat, buffer);
}
void glTexBufferRangeEXT(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size) {
	static const auto glTexBufferRangeEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLuint, GLintptr, GLsizeiptr)>(getProcAddress("glTexBufferRangeEXT"));
	assert(glTexBufferRangeEXT_ != nullptr);
	return glTexBufferRangeEXT_(target, internalformat, buffer, offset, size);
}
void glTexStorage1DEXT(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width) {
	static const auto glTexStorage1DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, GLenum, GLsizei)>(getProcAddress("glTexStorage1DEXT"));
	assert(glTexStorage1DEXT_ != nullptr);
	return glTexStorage1DEXT_(target, levels, internalformat, width);
}
void glTexStorage2DEXT(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) {
	static const auto glTexStorage2DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, GLenum, GLsizei, GLsizei)>(getProcAddress("glTexStorage2DEXT"));
	assert(glTexStorage2DEXT_ != nullptr);
	return glTexStorage2DEXT_(target, levels, internalformat, width, height);
}
void glTexStorage3DEXT(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) {
	static const auto glTexStorage3DEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei)>(getProcAddress("glTexStorage3DEXT"));
	assert(glTexStorage3DEXT_ != nullptr);
	return glTexStorage3DEXT_(target, levels, internalformat, width, height, depth);
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
void glTextureViewEXT(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers) {
	static const auto glTextureViewEXT_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLuint, GLenum, GLuint, GLuint, GLuint, GLuint)>(getProcAddress("glTextureViewEXT"));
	assert(glTextureViewEXT_ != nullptr);
	return glTextureViewEXT_(texture, target, origtexture, internalformat, minlevel, numlevels, minlayer, numlayers);
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
void glEGLImageTargetTexture2DOES(GLenum target, GLeglImageOES image) {
	static const auto glEGLImageTargetTexture2DOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLeglImageOES)>(getProcAddress("glEGLImageTargetTexture2DOES"));
	assert(glEGLImageTargetTexture2DOES_ != nullptr);
	return glEGLImageTargetTexture2DOES_(target, image);
}
void glEGLImageTargetRenderbufferStorageOES(GLenum target, GLeglImageOES image) {
	static const auto glEGLImageTargetRenderbufferStorageOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLeglImageOES)>(getProcAddress("glEGLImageTargetRenderbufferStorageOES"));
	assert(glEGLImageTargetRenderbufferStorageOES_ != nullptr);
	return glEGLImageTargetRenderbufferStorageOES_(target, image);
}
void glBlendEquationSeparateOES(GLenum modeRGB, GLenum modeAlpha) {
	static const auto glBlendEquationSeparateOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum)>(getProcAddress("glBlendEquationSeparateOES"));
	assert(glBlendEquationSeparateOES_ != nullptr);
	return glBlendEquationSeparateOES_(modeRGB, modeAlpha);
}
void glBlendFuncSeparateOES(GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) {
	static const auto glBlendFuncSeparateOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLenum)>(getProcAddress("glBlendFuncSeparateOES"));
	assert(glBlendFuncSeparateOES_ != nullptr);
	return glBlendFuncSeparateOES_(srcRGB, dstRGB, srcAlpha, dstAlpha);
}
void glBlendEquationOES(GLenum mode) {
	static const auto glBlendEquationOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glBlendEquationOES"));
	assert(glBlendEquationOES_ != nullptr);
	return glBlendEquationOES_(mode);
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
void glCopyImageSubDataOES(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth) {
	static const auto glCopyImageSubDataOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint, GLint, GLint, GLint, GLuint, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei)>(getProcAddress("glCopyImageSubDataOES"));
	assert(glCopyImageSubDataOES_ != nullptr);
	return glCopyImageSubDataOES_(srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth);
}
void glEnableiOES(GLenum target, GLuint index) {
	static const auto glEnableiOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint)>(getProcAddress("glEnableiOES"));
	assert(glEnableiOES_ != nullptr);
	return glEnableiOES_(target, index);
}
void glDisableiOES(GLenum target, GLuint index) {
	static const auto glDisableiOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint)>(getProcAddress("glDisableiOES"));
	assert(glDisableiOES_ != nullptr);
	return glDisableiOES_(target, index);
}
void glBlendEquationiOES(GLuint buf, GLenum mode) {
	static const auto glBlendEquationiOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum)>(getProcAddress("glBlendEquationiOES"));
	assert(glBlendEquationiOES_ != nullptr);
	return glBlendEquationiOES_(buf, mode);
}
void glBlendEquationSeparateiOES(GLuint buf, GLenum modeRGB, GLenum modeAlpha) {
	static const auto glBlendEquationSeparateiOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLenum)>(getProcAddress("glBlendEquationSeparateiOES"));
	assert(glBlendEquationSeparateiOES_ != nullptr);
	return glBlendEquationSeparateiOES_(buf, modeRGB, modeAlpha);
}
void glBlendFunciOES(GLuint buf, GLenum src, GLenum dst) {
	static const auto glBlendFunciOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLenum)>(getProcAddress("glBlendFunciOES"));
	assert(glBlendFunciOES_ != nullptr);
	return glBlendFunciOES_(buf, src, dst);
}
void glBlendFuncSeparateiOES(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) {
	static const auto glBlendFuncSeparateiOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLenum, GLenum, GLenum)>(getProcAddress("glBlendFuncSeparateiOES"));
	assert(glBlendFuncSeparateiOES_ != nullptr);
	return glBlendFuncSeparateiOES_(buf, srcRGB, dstRGB, srcAlpha, dstAlpha);
}
void glColorMaskiOES(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a) {
	static const auto glColorMaskiOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLboolean, GLboolean, GLboolean, GLboolean)>(getProcAddress("glColorMaskiOES"));
	assert(glColorMaskiOES_ != nullptr);
	return glColorMaskiOES_(index, r, g, b, a);
}
GLboolean glIsEnablediOES(GLenum target, GLuint index) {
	static const auto glIsEnablediOES_ = reinterpret_cast<GLboolean(GL_APIENTRYP)(GLenum, GLuint)>(getProcAddress("glIsEnablediOES"));
	assert(glIsEnablediOES_ != nullptr);
	return glIsEnablediOES_(target, index);
}
void glDrawElementsBaseVertexOES(GLenum mode, GLsizei count, GLenum type, const void * indices, GLint basevertex) {
	static const auto glDrawElementsBaseVertexOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, GLenum, const void *, GLint)>(getProcAddress("glDrawElementsBaseVertexOES"));
	assert(glDrawElementsBaseVertexOES_ != nullptr);
	return glDrawElementsBaseVertexOES_(mode, count, type, indices, basevertex);
}
void glDrawRangeElementsBaseVertexOES(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices, GLint basevertex) {
	static const auto glDrawRangeElementsBaseVertexOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint, GLuint, GLsizei, GLenum, const void *, GLint)>(getProcAddress("glDrawRangeElementsBaseVertexOES"));
	assert(glDrawRangeElementsBaseVertexOES_ != nullptr);
	return glDrawRangeElementsBaseVertexOES_(mode, start, end, count, type, indices, basevertex);
}
void glDrawElementsInstancedBaseVertexOES(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex) {
	static const auto glDrawElementsInstancedBaseVertexOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, GLenum, const void *, GLsizei, GLint)>(getProcAddress("glDrawElementsInstancedBaseVertexOES"));
	assert(glDrawElementsInstancedBaseVertexOES_ != nullptr);
	return glDrawElementsInstancedBaseVertexOES_(mode, count, type, indices, instancecount, basevertex);
}
void glDrawTexsOES(GLshort x, GLshort y, GLshort z, GLshort width, GLshort height) {
	static const auto glDrawTexsOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLshort, GLshort, GLshort, GLshort, GLshort)>(getProcAddress("glDrawTexsOES"));
	assert(glDrawTexsOES_ != nullptr);
	return glDrawTexsOES_(x, y, z, width, height);
}
void glDrawTexiOES(GLint x, GLint y, GLint z, GLint width, GLint height) {
	static const auto glDrawTexiOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLint, GLint, GLint, GLint)>(getProcAddress("glDrawTexiOES"));
	assert(glDrawTexiOES_ != nullptr);
	return glDrawTexiOES_(x, y, z, width, height);
}
void glDrawTexxOES(GLfixed x, GLfixed y, GLfixed z, GLfixed width, GLfixed height) {
	static const auto glDrawTexxOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed, GLfixed, GLfixed, GLfixed, GLfixed)>(getProcAddress("glDrawTexxOES"));
	assert(glDrawTexxOES_ != nullptr);
	return glDrawTexxOES_(x, y, z, width, height);
}
void glDrawTexsvOES(GLshort const  * coords) {
	static const auto glDrawTexsvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLshort const  *)>(getProcAddress("glDrawTexsvOES"));
	assert(glDrawTexsvOES_ != nullptr);
	return glDrawTexsvOES_(coords);
}
void glDrawTexivOES(GLint const  * coords) {
	static const auto glDrawTexivOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLint const  *)>(getProcAddress("glDrawTexivOES"));
	assert(glDrawTexivOES_ != nullptr);
	return glDrawTexivOES_(coords);
}
void glDrawTexxvOES(GLfixed const  * coords) {
	static const auto glDrawTexxvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfixed const  *)>(getProcAddress("glDrawTexxvOES"));
	assert(glDrawTexxvOES_ != nullptr);
	return glDrawTexxvOES_(coords);
}
void glDrawTexfOES(GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height) {
	static const auto glDrawTexfOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat)>(getProcAddress("glDrawTexfOES"));
	assert(glDrawTexfOES_ != nullptr);
	return glDrawTexfOES_(x, y, z, width, height);
}
void glDrawTexfvOES(GLfloat const  * coords) {
	static const auto glDrawTexfvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat const  *)>(getProcAddress("glDrawTexfvOES"));
	assert(glDrawTexfvOES_ != nullptr);
	return glDrawTexfvOES_(coords);
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
GLboolean glIsRenderbufferOES(GLuint renderbuffer) {
	static const auto glIsRenderbufferOES_ = reinterpret_cast<GLboolean(GL_APIENTRYP)(GLuint)>(getProcAddress("glIsRenderbufferOES"));
	assert(glIsRenderbufferOES_ != nullptr);
	return glIsRenderbufferOES_(renderbuffer);
}
void glBindRenderbufferOES(GLenum target, GLuint renderbuffer) {
	static const auto glBindRenderbufferOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint)>(getProcAddress("glBindRenderbufferOES"));
	assert(glBindRenderbufferOES_ != nullptr);
	return glBindRenderbufferOES_(target, renderbuffer);
}
void glDeleteRenderbuffersOES(GLsizei n, GLuint const  * renderbuffers) {
	static const auto glDeleteRenderbuffersOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint const  *)>(getProcAddress("glDeleteRenderbuffersOES"));
	assert(glDeleteRenderbuffersOES_ != nullptr);
	return glDeleteRenderbuffersOES_(n, renderbuffers);
}
void glGenRenderbuffersOES(GLsizei n, GLuint * renderbuffers) {
	static const auto glGenRenderbuffersOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint *)>(getProcAddress("glGenRenderbuffersOES"));
	assert(glGenRenderbuffersOES_ != nullptr);
	return glGenRenderbuffersOES_(n, renderbuffers);
}
void glRenderbufferStorageOES(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) {
	static const auto glRenderbufferStorageOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLsizei, GLsizei)>(getProcAddress("glRenderbufferStorageOES"));
	assert(glRenderbufferStorageOES_ != nullptr);
	return glRenderbufferStorageOES_(target, internalformat, width, height);
}
void glGetRenderbufferParameterivOES(GLenum target, GLenum pname, GLint * params) {
	static const auto glGetRenderbufferParameterivOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint *)>(getProcAddress("glGetRenderbufferParameterivOES"));
	assert(glGetRenderbufferParameterivOES_ != nullptr);
	return glGetRenderbufferParameterivOES_(target, pname, params);
}
GLboolean glIsFramebufferOES(GLuint framebuffer) {
	static const auto glIsFramebufferOES_ = reinterpret_cast<GLboolean(GL_APIENTRYP)(GLuint)>(getProcAddress("glIsFramebufferOES"));
	assert(glIsFramebufferOES_ != nullptr);
	return glIsFramebufferOES_(framebuffer);
}
void glBindFramebufferOES(GLenum target, GLuint framebuffer) {
	static const auto glBindFramebufferOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint)>(getProcAddress("glBindFramebufferOES"));
	assert(glBindFramebufferOES_ != nullptr);
	return glBindFramebufferOES_(target, framebuffer);
}
void glDeleteFramebuffersOES(GLsizei n, GLuint const  * framebuffers) {
	static const auto glDeleteFramebuffersOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint const  *)>(getProcAddress("glDeleteFramebuffersOES"));
	assert(glDeleteFramebuffersOES_ != nullptr);
	return glDeleteFramebuffersOES_(n, framebuffers);
}
void glGenFramebuffersOES(GLsizei n, GLuint * framebuffers) {
	static const auto glGenFramebuffersOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint *)>(getProcAddress("glGenFramebuffersOES"));
	assert(glGenFramebuffersOES_ != nullptr);
	return glGenFramebuffersOES_(n, framebuffers);
}
GLenum glCheckFramebufferStatusOES(GLenum target) {
	static const auto glCheckFramebufferStatusOES_ = reinterpret_cast<GLenum(GL_APIENTRYP)(GLenum)>(getProcAddress("glCheckFramebufferStatusOES"));
	assert(glCheckFramebufferStatusOES_ != nullptr);
	return glCheckFramebufferStatusOES_(target);
}
void glFramebufferRenderbufferOES(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) {
	static const auto glFramebufferRenderbufferOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLuint)>(getProcAddress("glFramebufferRenderbufferOES"));
	assert(glFramebufferRenderbufferOES_ != nullptr);
	return glFramebufferRenderbufferOES_(target, attachment, renderbuffertarget, renderbuffer);
}
void glFramebufferTexture2DOES(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {
	static const auto glFramebufferTexture2DOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLuint, GLint)>(getProcAddress("glFramebufferTexture2DOES"));
	assert(glFramebufferTexture2DOES_ != nullptr);
	return glFramebufferTexture2DOES_(target, attachment, textarget, texture, level);
}
void glGetFramebufferAttachmentParameterivOES(GLenum target, GLenum attachment, GLenum pname, GLint * params) {
	static const auto glGetFramebufferAttachmentParameterivOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLint *)>(getProcAddress("glGetFramebufferAttachmentParameterivOES"));
	assert(glGetFramebufferAttachmentParameterivOES_ != nullptr);
	return glGetFramebufferAttachmentParameterivOES_(target, attachment, pname, params);
}
void glGenerateMipmapOES(GLenum target) {
	static const auto glGenerateMipmapOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum)>(getProcAddress("glGenerateMipmapOES"));
	assert(glGenerateMipmapOES_ != nullptr);
	return glGenerateMipmapOES_(target);
}
void glFramebufferTextureOES(GLenum target, GLenum attachment, GLuint texture, GLint level) {
	static const auto glFramebufferTextureOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLuint, GLint)>(getProcAddress("glFramebufferTextureOES"));
	assert(glFramebufferTextureOES_ != nullptr);
	return glFramebufferTextureOES_(target, attachment, texture, level);
}
void glGetProgramBinaryOES(GLuint program, GLsizei bufSize, GLsizei * length, GLenum * binaryFormat, void * binary) {
	static const auto glGetProgramBinaryOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLsizei, GLsizei *, GLenum *, void *)>(getProcAddress("glGetProgramBinaryOES"));
	assert(glGetProgramBinaryOES_ != nullptr);
	return glGetProgramBinaryOES_(program, bufSize, length, binaryFormat, binary);
}
void glProgramBinaryOES(GLuint program, GLenum binaryFormat, const void * binary, GLint length) {
	static const auto glProgramBinaryOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, const void *, GLint)>(getProcAddress("glProgramBinaryOES"));
	assert(glProgramBinaryOES_ != nullptr);
	return glProgramBinaryOES_(program, binaryFormat, binary, length);
}
void * glMapBufferOES(GLenum target, GLenum access) {
	static const auto glMapBufferOES_ = reinterpret_cast<void *(GL_APIENTRYP)(GLenum, GLenum)>(getProcAddress("glMapBufferOES"));
	assert(glMapBufferOES_ != nullptr);
	return glMapBufferOES_(target, access);
}
GLboolean glUnmapBufferOES(GLenum target) {
	static const auto glUnmapBufferOES_ = reinterpret_cast<GLboolean(GL_APIENTRYP)(GLenum)>(getProcAddress("glUnmapBufferOES"));
	assert(glUnmapBufferOES_ != nullptr);
	return glUnmapBufferOES_(target);
}
void glGetBufferPointervOES(GLenum target, GLenum pname, void ** params) {
	static const auto glGetBufferPointervOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, void **)>(getProcAddress("glGetBufferPointervOES"));
	assert(glGetBufferPointervOES_ != nullptr);
	return glGetBufferPointervOES_(target, pname, params);
}
void glCurrentPaletteMatrixOES(GLuint matrixpaletteindex) {
	static const auto glCurrentPaletteMatrixOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint)>(getProcAddress("glCurrentPaletteMatrixOES"));
	assert(glCurrentPaletteMatrixOES_ != nullptr);
	return glCurrentPaletteMatrixOES_(matrixpaletteindex);
}
void glLoadPaletteFromModelViewMatrixOES() {
	static const auto glLoadPaletteFromModelViewMatrixOES_ = reinterpret_cast<void(GL_APIENTRYP)()>(getProcAddress("glLoadPaletteFromModelViewMatrixOES"));
	assert(glLoadPaletteFromModelViewMatrixOES_ != nullptr);
	return glLoadPaletteFromModelViewMatrixOES_();
}
void glMatrixIndexPointerOES(GLint size, GLenum type, GLsizei stride, const void * pointer) {
	static const auto glMatrixIndexPointerOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLenum, GLsizei, const void *)>(getProcAddress("glMatrixIndexPointerOES"));
	assert(glMatrixIndexPointerOES_ != nullptr);
	return glMatrixIndexPointerOES_(size, type, stride, pointer);
}
void glWeightPointerOES(GLint size, GLenum type, GLsizei stride, const void * pointer) {
	static const auto glWeightPointerOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLint, GLenum, GLsizei, const void *)>(getProcAddress("glWeightPointerOES"));
	assert(glWeightPointerOES_ != nullptr);
	return glWeightPointerOES_(size, type, stride, pointer);
}
void glPointSizePointerOES(GLenum type, GLsizei stride, const void * pointer) {
	static const auto glPointSizePointerOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, const void *)>(getProcAddress("glPointSizePointerOES"));
	assert(glPointSizePointerOES_ != nullptr);
	return glPointSizePointerOES_(type, stride, pointer);
}
void glPrimitiveBoundingBoxOES(GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat minW, GLfloat maxX, GLfloat maxY, GLfloat maxZ, GLfloat maxW) {
	static const auto glPrimitiveBoundingBoxOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat)>(getProcAddress("glPrimitiveBoundingBoxOES"));
	assert(glPrimitiveBoundingBoxOES_ != nullptr);
	return glPrimitiveBoundingBoxOES_(minX, minY, minZ, minW, maxX, maxY, maxZ, maxW);
}
GLbitfield glQueryMatrixxOES(GLfixed * mantissa, GLint * exponent) {
	static const auto glQueryMatrixxOES_ = reinterpret_cast<GLbitfield(GL_APIENTRYP)(GLfixed *, GLint *)>(getProcAddress("glQueryMatrixxOES"));
	assert(glQueryMatrixxOES_ != nullptr);
	return glQueryMatrixxOES_(mantissa, exponent);
}
void glMinSampleShadingOES(GLfloat value) {
	static const auto glMinSampleShadingOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLfloat)>(getProcAddress("glMinSampleShadingOES"));
	assert(glMinSampleShadingOES_ != nullptr);
	return glMinSampleShadingOES_(value);
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
void glPatchParameteriOES(GLenum pname, GLint value) {
	static const auto glPatchParameteriOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint)>(getProcAddress("glPatchParameteriOES"));
	assert(glPatchParameteriOES_ != nullptr);
	return glPatchParameteriOES_(pname, value);
}
void glTexImage3DOES(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void * pixels) {
	static const auto glTexImage3DOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const void *)>(getProcAddress("glTexImage3DOES"));
	assert(glTexImage3DOES_ != nullptr);
	return glTexImage3DOES_(target, level, internalformat, width, height, depth, border, format, type, pixels);
}
void glTexSubImage3DOES(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels) {
	static const auto glTexSubImage3DOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const void *)>(getProcAddress("glTexSubImage3DOES"));
	assert(glTexSubImage3DOES_ != nullptr);
	return glTexSubImage3DOES_(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}
void glCopyTexSubImage3DOES(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
	static const auto glCopyTexSubImage3DOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei)>(getProcAddress("glCopyTexSubImage3DOES"));
	assert(glCopyTexSubImage3DOES_ != nullptr);
	return glCopyTexSubImage3DOES_(target, level, xoffset, yoffset, zoffset, x, y, width, height);
}
void glCompressedTexImage3DOES(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void * data) {
	static const auto glCompressedTexImage3DOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLsizei, const void *)>(getProcAddress("glCompressedTexImage3DOES"));
	assert(glCompressedTexImage3DOES_ != nullptr);
	return glCompressedTexImage3DOES_(target, level, internalformat, width, height, depth, border, imageSize, data);
}
void glCompressedTexSubImage3DOES(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * data) {
	static const auto glCompressedTexSubImage3DOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const void *)>(getProcAddress("glCompressedTexSubImage3DOES"));
	assert(glCompressedTexSubImage3DOES_ != nullptr);
	return glCompressedTexSubImage3DOES_(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
}
void glFramebufferTexture3DOES(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset) {
	static const auto glFramebufferTexture3DOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLenum, GLuint, GLint, GLint)>(getProcAddress("glFramebufferTexture3DOES"));
	assert(glFramebufferTexture3DOES_ != nullptr);
	return glFramebufferTexture3DOES_(target, attachment, textarget, texture, level, zoffset);
}
void glTexParameterIivOES(GLenum target, GLenum pname, GLint const  * params) {
	static const auto glTexParameterIivOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint const  *)>(getProcAddress("glTexParameterIivOES"));
	assert(glTexParameterIivOES_ != nullptr);
	return glTexParameterIivOES_(target, pname, params);
}
void glTexParameterIuivOES(GLenum target, GLenum pname, GLuint const  * params) {
	static const auto glTexParameterIuivOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLuint const  *)>(getProcAddress("glTexParameterIuivOES"));
	assert(glTexParameterIuivOES_ != nullptr);
	return glTexParameterIuivOES_(target, pname, params);
}
void glGetTexParameterIivOES(GLenum target, GLenum pname, GLint * params) {
	static const auto glGetTexParameterIivOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint *)>(getProcAddress("glGetTexParameterIivOES"));
	assert(glGetTexParameterIivOES_ != nullptr);
	return glGetTexParameterIivOES_(target, pname, params);
}
void glGetTexParameterIuivOES(GLenum target, GLenum pname, GLuint * params) {
	static const auto glGetTexParameterIuivOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLuint *)>(getProcAddress("glGetTexParameterIuivOES"));
	assert(glGetTexParameterIuivOES_ != nullptr);
	return glGetTexParameterIuivOES_(target, pname, params);
}
void glSamplerParameterIivOES(GLuint sampler, GLenum pname, GLint const  * param) {
	static const auto glSamplerParameterIivOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint const  *)>(getProcAddress("glSamplerParameterIivOES"));
	assert(glSamplerParameterIivOES_ != nullptr);
	return glSamplerParameterIivOES_(sampler, pname, param);
}
void glSamplerParameterIuivOES(GLuint sampler, GLenum pname, GLuint const  * param) {
	static const auto glSamplerParameterIuivOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLuint const  *)>(getProcAddress("glSamplerParameterIuivOES"));
	assert(glSamplerParameterIuivOES_ != nullptr);
	return glSamplerParameterIuivOES_(sampler, pname, param);
}
void glGetSamplerParameterIivOES(GLuint sampler, GLenum pname, GLint * params) {
	static const auto glGetSamplerParameterIivOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLint *)>(getProcAddress("glGetSamplerParameterIivOES"));
	assert(glGetSamplerParameterIivOES_ != nullptr);
	return glGetSamplerParameterIivOES_(sampler, pname, params);
}
void glGetSamplerParameterIuivOES(GLuint sampler, GLenum pname, GLuint * params) {
	static const auto glGetSamplerParameterIuivOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLuint *)>(getProcAddress("glGetSamplerParameterIuivOES"));
	assert(glGetSamplerParameterIuivOES_ != nullptr);
	return glGetSamplerParameterIuivOES_(sampler, pname, params);
}
void glTexBufferOES(GLenum target, GLenum internalformat, GLuint buffer) {
	static const auto glTexBufferOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLuint)>(getProcAddress("glTexBufferOES"));
	assert(glTexBufferOES_ != nullptr);
	return glTexBufferOES_(target, internalformat, buffer);
}
void glTexBufferRangeOES(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size) {
	static const auto glTexBufferRangeOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLuint, GLintptr, GLsizeiptr)>(getProcAddress("glTexBufferRangeOES"));
	assert(glTexBufferRangeOES_ != nullptr);
	return glTexBufferRangeOES_(target, internalformat, buffer, offset, size);
}
void glTexGenfOES(GLenum coord, GLenum pname, GLfloat param) {
	static const auto glTexGenfOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfloat)>(getProcAddress("glTexGenfOES"));
	assert(glTexGenfOES_ != nullptr);
	return glTexGenfOES_(coord, pname, param);
}
void glTexGenfvOES(GLenum coord, GLenum pname, GLfloat const  * params) {
	static const auto glTexGenfvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfloat const  *)>(getProcAddress("glTexGenfvOES"));
	assert(glTexGenfvOES_ != nullptr);
	return glTexGenfvOES_(coord, pname, params);
}
void glTexGeniOES(GLenum coord, GLenum pname, GLint param) {
	static const auto glTexGeniOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint)>(getProcAddress("glTexGeniOES"));
	assert(glTexGeniOES_ != nullptr);
	return glTexGeniOES_(coord, pname, param);
}
void glTexGenivOES(GLenum coord, GLenum pname, GLint const  * params) {
	static const auto glTexGenivOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint const  *)>(getProcAddress("glTexGenivOES"));
	assert(glTexGenivOES_ != nullptr);
	return glTexGenivOES_(coord, pname, params);
}
void glGetTexGenfvOES(GLenum coord, GLenum pname, GLfloat * params) {
	static const auto glGetTexGenfvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLfloat *)>(getProcAddress("glGetTexGenfvOES"));
	assert(glGetTexGenfvOES_ != nullptr);
	return glGetTexGenfvOES_(coord, pname, params);
}
void glGetTexGenivOES(GLenum coord, GLenum pname, GLint * params) {
	static const auto glGetTexGenivOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLenum, GLint *)>(getProcAddress("glGetTexGenivOES"));
	assert(glGetTexGenivOES_ != nullptr);
	return glGetTexGenivOES_(coord, pname, params);
}
void glTexStorage3DMultisampleOES(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) {
	static const auto glTexStorage3DMultisampleOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei, GLboolean)>(getProcAddress("glTexStorage3DMultisampleOES"));
	assert(glTexStorage3DMultisampleOES_ != nullptr);
	return glTexStorage3DMultisampleOES_(target, samples, internalformat, width, height, depth, fixedsamplelocations);
}
void glTextureViewOES(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers) {
	static const auto glTextureViewOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLenum, GLuint, GLenum, GLuint, GLuint, GLuint, GLuint)>(getProcAddress("glTextureViewOES"));
	assert(glTextureViewOES_ != nullptr);
	return glTextureViewOES_(texture, target, origtexture, internalformat, minlevel, numlevels, minlayer, numlayers);
}
void glBindVertexArrayOES(GLuint array) {
	static const auto glBindVertexArrayOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint)>(getProcAddress("glBindVertexArrayOES"));
	assert(glBindVertexArrayOES_ != nullptr);
	return glBindVertexArrayOES_(array);
}
void glDeleteVertexArraysOES(GLsizei n, GLuint const  * arrays) {
	static const auto glDeleteVertexArraysOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint const  *)>(getProcAddress("glDeleteVertexArraysOES"));
	assert(glDeleteVertexArraysOES_ != nullptr);
	return glDeleteVertexArraysOES_(n, arrays);
}
void glGenVertexArraysOES(GLsizei n, GLuint * arrays) {
	static const auto glGenVertexArraysOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLsizei, GLuint *)>(getProcAddress("glGenVertexArraysOES"));
	assert(glGenVertexArraysOES_ != nullptr);
	return glGenVertexArraysOES_(n, arrays);
}
GLboolean glIsVertexArrayOES(GLuint array) {
	static const auto glIsVertexArrayOES_ = reinterpret_cast<GLboolean(GL_APIENTRYP)(GLuint)>(getProcAddress("glIsVertexArrayOES"));
	assert(glIsVertexArrayOES_ != nullptr);
	return glIsVertexArrayOES_(array);
}
void glViewportArrayvOES(GLuint first, GLsizei count, GLfloat const  * v) {
	static const auto glViewportArrayvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLsizei, GLfloat const  *)>(getProcAddress("glViewportArrayvOES"));
	assert(glViewportArrayvOES_ != nullptr);
	return glViewportArrayvOES_(first, count, v);
}
void glViewportIndexedfOES(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h) {
	static const auto glViewportIndexedfOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat)>(getProcAddress("glViewportIndexedfOES"));
	assert(glViewportIndexedfOES_ != nullptr);
	return glViewportIndexedfOES_(index, x, y, w, h);
}
void glViewportIndexedfvOES(GLuint index, GLfloat const  * v) {
	static const auto glViewportIndexedfvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLfloat const  *)>(getProcAddress("glViewportIndexedfvOES"));
	assert(glViewportIndexedfvOES_ != nullptr);
	return glViewportIndexedfvOES_(index, v);
}
void glScissorArrayvOES(GLuint first, GLsizei count, GLint const  * v) {
	static const auto glScissorArrayvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLsizei, GLint const  *)>(getProcAddress("glScissorArrayvOES"));
	assert(glScissorArrayvOES_ != nullptr);
	return glScissorArrayvOES_(first, count, v);
}
void glScissorIndexedOES(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height) {
	static const auto glScissorIndexedOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint, GLint, GLsizei, GLsizei)>(getProcAddress("glScissorIndexedOES"));
	assert(glScissorIndexedOES_ != nullptr);
	return glScissorIndexedOES_(index, left, bottom, width, height);
}
void glScissorIndexedvOES(GLuint index, GLint const  * v) {
	static const auto glScissorIndexedvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLint const  *)>(getProcAddress("glScissorIndexedvOES"));
	assert(glScissorIndexedvOES_ != nullptr);
	return glScissorIndexedvOES_(index, v);
}
void glDepthRangeArrayfvOES(GLuint first, GLsizei count, GLfloat const  * v) {
	static const auto glDepthRangeArrayfvOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLsizei, GLfloat const  *)>(getProcAddress("glDepthRangeArrayfvOES"));
	assert(glDepthRangeArrayfvOES_ != nullptr);
	return glDepthRangeArrayfvOES_(first, count, v);
}
void glDepthRangeIndexedfOES(GLuint index, GLfloat n, GLfloat f) {
	static const auto glDepthRangeIndexedfOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLuint, GLfloat, GLfloat)>(getProcAddress("glDepthRangeIndexedfOES"));
	assert(glDepthRangeIndexedfOES_ != nullptr);
	return glDepthRangeIndexedfOES_(index, n, f);
}
void glGetFloati_vOES(GLenum target, GLuint index, GLfloat * data) {
	static const auto glGetFloati_vOES_ = reinterpret_cast<void(GL_APIENTRYP)(GLenum, GLuint, GLfloat *)>(getProcAddress("glGetFloati_vOES"));
	assert(glGetFloati_vOES_ != nullptr);
	return glGetFloati_vOES_(target, index, data);
}

}
