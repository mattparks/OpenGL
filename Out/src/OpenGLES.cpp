/*

OpenGLES loader generated tool at 2019-12-04T16:43:28.6691310Z

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
GetProcAddress getProcAddress_ = nullptr;

void initialize(const GetProcAddress &resolver) {
    if (!resolver)
        getProcAddress_ = impl::getProcAddress;
    else
        getProcAddress_ = resolver;
}

ProcAddress getProcAddress(const char *name) {
    assert(getProcAddress_ != nullptr);
    return getProcAddress_(name);
}

void glAlphaFunc(GLenum func, GLfloat ref) {
	static const auto glAlphaFunc_ = getFunction<void, GLenum, GLfloat>("glAlphaFunc");
	assert(glAlphaFunc_ != nullptr);
	return glAlphaFunc_(func, ref);
}
void glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
	static const auto glClearColor_ = getFunction<void, GLfloat, GLfloat, GLfloat, GLfloat>("glClearColor");
	assert(glClearColor_ != nullptr);
	return glClearColor_(red, green, blue, alpha);
}
void glClearDepthf(GLfloat d) {
	static const auto glClearDepthf_ = getFunction<void, GLfloat>("glClearDepthf");
	assert(glClearDepthf_ != nullptr);
	return glClearDepthf_(d);
}
void glClipPlanef(GLenum p, GLfloat const  * eqn) {
	static const auto glClipPlanef_ = getFunction<void, GLenum, GLfloat const  *>("glClipPlanef");
	assert(glClipPlanef_ != nullptr);
	return glClipPlanef_(p, eqn);
}
void glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
	static const auto glColor4f_ = getFunction<void, GLfloat, GLfloat, GLfloat, GLfloat>("glColor4f");
	assert(glColor4f_ != nullptr);
	return glColor4f_(red, green, blue, alpha);
}
void glDepthRangef(GLfloat n, GLfloat f) {
	static const auto glDepthRangef_ = getFunction<void, GLfloat, GLfloat>("glDepthRangef");
	assert(glDepthRangef_ != nullptr);
	return glDepthRangef_(n, f);
}
void glFogf(GLenum pname, GLfloat param) {
	static const auto glFogf_ = getFunction<void, GLenum, GLfloat>("glFogf");
	assert(glFogf_ != nullptr);
	return glFogf_(pname, param);
}
void glFogfv(GLenum pname, GLfloat const  * params) {
	static const auto glFogfv_ = getFunction<void, GLenum, GLfloat const  *>("glFogfv");
	assert(glFogfv_ != nullptr);
	return glFogfv_(pname, params);
}
void glFrustumf(GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f) {
	static const auto glFrustumf_ = getFunction<void, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat>("glFrustumf");
	assert(glFrustumf_ != nullptr);
	return glFrustumf_(l, r, b, t, n, f);
}
void glGetClipPlanef(GLenum plane, GLfloat * equation) {
	static const auto glGetClipPlanef_ = getFunction<void, GLenum, GLfloat *>("glGetClipPlanef");
	assert(glGetClipPlanef_ != nullptr);
	return glGetClipPlanef_(plane, equation);
}
void glGetFloatv(GLenum pname, GLfloat * data) {
	static const auto glGetFloatv_ = getFunction<void, GLenum, GLfloat *>("glGetFloatv");
	assert(glGetFloatv_ != nullptr);
	return glGetFloatv_(pname, data);
}
void glGetLightfv(GLenum light, GLenum pname, GLfloat * params) {
	static const auto glGetLightfv_ = getFunction<void, GLenum, GLenum, GLfloat *>("glGetLightfv");
	assert(glGetLightfv_ != nullptr);
	return glGetLightfv_(light, pname, params);
}
void glGetMaterialfv(GLenum face, GLenum pname, GLfloat * params) {
	static const auto glGetMaterialfv_ = getFunction<void, GLenum, GLenum, GLfloat *>("glGetMaterialfv");
	assert(glGetMaterialfv_ != nullptr);
	return glGetMaterialfv_(face, pname, params);
}
void glGetTexEnvfv(GLenum target, GLenum pname, GLfloat * params) {
	static const auto glGetTexEnvfv_ = getFunction<void, GLenum, GLenum, GLfloat *>("glGetTexEnvfv");
	assert(glGetTexEnvfv_ != nullptr);
	return glGetTexEnvfv_(target, pname, params);
}
void glGetTexParameterfv(GLenum target, GLenum pname, GLfloat * params) {
	static const auto glGetTexParameterfv_ = getFunction<void, GLenum, GLenum, GLfloat *>("glGetTexParameterfv");
	assert(glGetTexParameterfv_ != nullptr);
	return glGetTexParameterfv_(target, pname, params);
}
void glLightModelf(GLenum pname, GLfloat param) {
	static const auto glLightModelf_ = getFunction<void, GLenum, GLfloat>("glLightModelf");
	assert(glLightModelf_ != nullptr);
	return glLightModelf_(pname, param);
}
void glLightModelfv(GLenum pname, GLfloat const  * params) {
	static const auto glLightModelfv_ = getFunction<void, GLenum, GLfloat const  *>("glLightModelfv");
	assert(glLightModelfv_ != nullptr);
	return glLightModelfv_(pname, params);
}
void glLightf(GLenum light, GLenum pname, GLfloat param) {
	static const auto glLightf_ = getFunction<void, GLenum, GLenum, GLfloat>("glLightf");
	assert(glLightf_ != nullptr);
	return glLightf_(light, pname, param);
}
void glLightfv(GLenum light, GLenum pname, GLfloat const  * params) {
	static const auto glLightfv_ = getFunction<void, GLenum, GLenum, GLfloat const  *>("glLightfv");
	assert(glLightfv_ != nullptr);
	return glLightfv_(light, pname, params);
}
void glLineWidth(GLfloat width) {
	static const auto glLineWidth_ = getFunction<void, GLfloat>("glLineWidth");
	assert(glLineWidth_ != nullptr);
	return glLineWidth_(width);
}
void glLoadMatrixf(GLfloat const  * m) {
	static const auto glLoadMatrixf_ = getFunction<void, GLfloat const  *>("glLoadMatrixf");
	assert(glLoadMatrixf_ != nullptr);
	return glLoadMatrixf_(m);
}
void glMaterialf(GLenum face, GLenum pname, GLfloat param) {
	static const auto glMaterialf_ = getFunction<void, GLenum, GLenum, GLfloat>("glMaterialf");
	assert(glMaterialf_ != nullptr);
	return glMaterialf_(face, pname, param);
}
void glMaterialfv(GLenum face, GLenum pname, GLfloat const  * params) {
	static const auto glMaterialfv_ = getFunction<void, GLenum, GLenum, GLfloat const  *>("glMaterialfv");
	assert(glMaterialfv_ != nullptr);
	return glMaterialfv_(face, pname, params);
}
void glMultMatrixf(GLfloat const  * m) {
	static const auto glMultMatrixf_ = getFunction<void, GLfloat const  *>("glMultMatrixf");
	assert(glMultMatrixf_ != nullptr);
	return glMultMatrixf_(m);
}
void glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) {
	static const auto glMultiTexCoord4f_ = getFunction<void, GLenum, GLfloat, GLfloat, GLfloat, GLfloat>("glMultiTexCoord4f");
	assert(glMultiTexCoord4f_ != nullptr);
	return glMultiTexCoord4f_(target, s, t, r, q);
}
void glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz) {
	static const auto glNormal3f_ = getFunction<void, GLfloat, GLfloat, GLfloat>("glNormal3f");
	assert(glNormal3f_ != nullptr);
	return glNormal3f_(nx, ny, nz);
}
void glOrthof(GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f) {
	static const auto glOrthof_ = getFunction<void, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat>("glOrthof");
	assert(glOrthof_ != nullptr);
	return glOrthof_(l, r, b, t, n, f);
}
void glPointParameterf(GLenum pname, GLfloat param) {
	static const auto glPointParameterf_ = getFunction<void, GLenum, GLfloat>("glPointParameterf");
	assert(glPointParameterf_ != nullptr);
	return glPointParameterf_(pname, param);
}
void glPointParameterfv(GLenum pname, GLfloat const  * params) {
	static const auto glPointParameterfv_ = getFunction<void, GLenum, GLfloat const  *>("glPointParameterfv");
	assert(glPointParameterfv_ != nullptr);
	return glPointParameterfv_(pname, params);
}
void glPointSize(GLfloat size) {
	static const auto glPointSize_ = getFunction<void, GLfloat>("glPointSize");
	assert(glPointSize_ != nullptr);
	return glPointSize_(size);
}
void glPolygonOffset(GLfloat factor, GLfloat units) {
	static const auto glPolygonOffset_ = getFunction<void, GLfloat, GLfloat>("glPolygonOffset");
	assert(glPolygonOffset_ != nullptr);
	return glPolygonOffset_(factor, units);
}
void glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z) {
	static const auto glRotatef_ = getFunction<void, GLfloat, GLfloat, GLfloat, GLfloat>("glRotatef");
	assert(glRotatef_ != nullptr);
	return glRotatef_(angle, x, y, z);
}
void glScalef(GLfloat x, GLfloat y, GLfloat z) {
	static const auto glScalef_ = getFunction<void, GLfloat, GLfloat, GLfloat>("glScalef");
	assert(glScalef_ != nullptr);
	return glScalef_(x, y, z);
}
void glTexEnvf(GLenum target, GLenum pname, GLfloat param) {
	static const auto glTexEnvf_ = getFunction<void, GLenum, GLenum, GLfloat>("glTexEnvf");
	assert(glTexEnvf_ != nullptr);
	return glTexEnvf_(target, pname, param);
}
void glTexEnvfv(GLenum target, GLenum pname, GLfloat const  * params) {
	static const auto glTexEnvfv_ = getFunction<void, GLenum, GLenum, GLfloat const  *>("glTexEnvfv");
	assert(glTexEnvfv_ != nullptr);
	return glTexEnvfv_(target, pname, params);
}
void glTexParameterf(GLenum target, GLenum pname, GLfloat param) {
	static const auto glTexParameterf_ = getFunction<void, GLenum, GLenum, GLfloat>("glTexParameterf");
	assert(glTexParameterf_ != nullptr);
	return glTexParameterf_(target, pname, param);
}
void glTexParameterfv(GLenum target, GLenum pname, GLfloat const  * params) {
	static const auto glTexParameterfv_ = getFunction<void, GLenum, GLenum, GLfloat const  *>("glTexParameterfv");
	assert(glTexParameterfv_ != nullptr);
	return glTexParameterfv_(target, pname, params);
}
void glTranslatef(GLfloat x, GLfloat y, GLfloat z) {
	static const auto glTranslatef_ = getFunction<void, GLfloat, GLfloat, GLfloat>("glTranslatef");
	assert(glTranslatef_ != nullptr);
	return glTranslatef_(x, y, z);
}
void glActiveTexture(GLenum texture) {
	static const auto glActiveTexture_ = getFunction<void, GLenum>("glActiveTexture");
	assert(glActiveTexture_ != nullptr);
	return glActiveTexture_(texture);
}
void glAlphaFuncx(GLenum func, GLfixed ref) {
	static const auto glAlphaFuncx_ = getFunction<void, GLenum, GLfixed>("glAlphaFuncx");
	assert(glAlphaFuncx_ != nullptr);
	return glAlphaFuncx_(func, ref);
}
void glBindBuffer(GLenum target, GLuint buffer) {
	static const auto glBindBuffer_ = getFunction<void, GLenum, GLuint>("glBindBuffer");
	assert(glBindBuffer_ != nullptr);
	return glBindBuffer_(target, buffer);
}
void glBindTexture(GLenum target, GLuint texture) {
	static const auto glBindTexture_ = getFunction<void, GLenum, GLuint>("glBindTexture");
	assert(glBindTexture_ != nullptr);
	return glBindTexture_(target, texture);
}
void glBlendFunc(GLenum sfactor, GLenum dfactor) {
	static const auto glBlendFunc_ = getFunction<void, GLenum, GLenum>("glBlendFunc");
	assert(glBlendFunc_ != nullptr);
	return glBlendFunc_(sfactor, dfactor);
}
void glBufferData(GLenum target, GLsizeiptr size, const void * data, GLenum usage) {
	static const auto glBufferData_ = getFunction<void, GLenum, GLsizeiptr, const void *, GLenum>("glBufferData");
	assert(glBufferData_ != nullptr);
	return glBufferData_(target, size, data, usage);
}
void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const void * data) {
	static const auto glBufferSubData_ = getFunction<void, GLenum, GLintptr, GLsizeiptr, const void *>("glBufferSubData");
	assert(glBufferSubData_ != nullptr);
	return glBufferSubData_(target, offset, size, data);
}
void glClear(GLbitfield mask) {
	static const auto glClear_ = getFunction<void, GLbitfield>("glClear");
	assert(glClear_ != nullptr);
	return glClear_(mask);
}
void glClearColorx(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha) {
	static const auto glClearColorx_ = getFunction<void, GLfixed, GLfixed, GLfixed, GLfixed>("glClearColorx");
	assert(glClearColorx_ != nullptr);
	return glClearColorx_(red, green, blue, alpha);
}
void glClearDepthx(GLfixed depth) {
	static const auto glClearDepthx_ = getFunction<void, GLfixed>("glClearDepthx");
	assert(glClearDepthx_ != nullptr);
	return glClearDepthx_(depth);
}
void glClearStencil(GLint s) {
	static const auto glClearStencil_ = getFunction<void, GLint>("glClearStencil");
	assert(glClearStencil_ != nullptr);
	return glClearStencil_(s);
}
void glClientActiveTexture(GLenum texture) {
	static const auto glClientActiveTexture_ = getFunction<void, GLenum>("glClientActiveTexture");
	assert(glClientActiveTexture_ != nullptr);
	return glClientActiveTexture_(texture);
}
void glClipPlanex(GLenum plane, GLfixed const  * equation) {
	static const auto glClipPlanex_ = getFunction<void, GLenum, GLfixed const  *>("glClipPlanex");
	assert(glClipPlanex_ != nullptr);
	return glClipPlanex_(plane, equation);
}
void glColor4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha) {
	static const auto glColor4ub_ = getFunction<void, GLubyte, GLubyte, GLubyte, GLubyte>("glColor4ub");
	assert(glColor4ub_ != nullptr);
	return glColor4ub_(red, green, blue, alpha);
}
void glColor4x(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha) {
	static const auto glColor4x_ = getFunction<void, GLfixed, GLfixed, GLfixed, GLfixed>("glColor4x");
	assert(glColor4x_ != nullptr);
	return glColor4x_(red, green, blue, alpha);
}
void glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) {
	static const auto glColorMask_ = getFunction<void, GLboolean, GLboolean, GLboolean, GLboolean>("glColorMask");
	assert(glColorMask_ != nullptr);
	return glColorMask_(red, green, blue, alpha);
}
void glColorPointer(GLint size, GLenum type, GLsizei stride, const void * pointer) {
	static const auto glColorPointer_ = getFunction<void, GLint, GLenum, GLsizei, const void *>("glColorPointer");
	assert(glColorPointer_ != nullptr);
	return glColorPointer_(size, type, stride, pointer);
}
void glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void * data) {
	static const auto glCompressedTexImage2D_ = getFunction<void, GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const void *>("glCompressedTexImage2D");
	assert(glCompressedTexImage2D_ != nullptr);
	return glCompressedTexImage2D_(target, level, internalformat, width, height, border, imageSize, data);
}
void glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * data) {
	static const auto glCompressedTexSubImage2D_ = getFunction<void, GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const void *>("glCompressedTexSubImage2D");
	assert(glCompressedTexSubImage2D_ != nullptr);
	return glCompressedTexSubImage2D_(target, level, xoffset, yoffset, width, height, format, imageSize, data);
}
void glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) {
	static const auto glCopyTexImage2D_ = getFunction<void, GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint>("glCopyTexImage2D");
	assert(glCopyTexImage2D_ != nullptr);
	return glCopyTexImage2D_(target, level, internalformat, x, y, width, height, border);
}
void glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
	static const auto glCopyTexSubImage2D_ = getFunction<void, GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei>("glCopyTexSubImage2D");
	assert(glCopyTexSubImage2D_ != nullptr);
	return glCopyTexSubImage2D_(target, level, xoffset, yoffset, x, y, width, height);
}
void glCullFace(GLenum mode) {
	static const auto glCullFace_ = getFunction<void, GLenum>("glCullFace");
	assert(glCullFace_ != nullptr);
	return glCullFace_(mode);
}
void glDeleteBuffers(GLsizei n, GLuint const  * buffers) {
	static const auto glDeleteBuffers_ = getFunction<void, GLsizei, GLuint const  *>("glDeleteBuffers");
	assert(glDeleteBuffers_ != nullptr);
	return glDeleteBuffers_(n, buffers);
}
void glDeleteTextures(GLsizei n, GLuint const  * textures) {
	static const auto glDeleteTextures_ = getFunction<void, GLsizei, GLuint const  *>("glDeleteTextures");
	assert(glDeleteTextures_ != nullptr);
	return glDeleteTextures_(n, textures);
}
void glDepthFunc(GLenum func) {
	static const auto glDepthFunc_ = getFunction<void, GLenum>("glDepthFunc");
	assert(glDepthFunc_ != nullptr);
	return glDepthFunc_(func);
}
void glDepthMask(GLboolean flag) {
	static const auto glDepthMask_ = getFunction<void, GLboolean>("glDepthMask");
	assert(glDepthMask_ != nullptr);
	return glDepthMask_(flag);
}
void glDepthRangex(GLfixed n, GLfixed f) {
	static const auto glDepthRangex_ = getFunction<void, GLfixed, GLfixed>("glDepthRangex");
	assert(glDepthRangex_ != nullptr);
	return glDepthRangex_(n, f);
}
void glDisable(GLenum cap) {
	static const auto glDisable_ = getFunction<void, GLenum>("glDisable");
	assert(glDisable_ != nullptr);
	return glDisable_(cap);
}
void glDisableClientState(GLenum array) {
	static const auto glDisableClientState_ = getFunction<void, GLenum>("glDisableClientState");
	assert(glDisableClientState_ != nullptr);
	return glDisableClientState_(array);
}
void glDrawArrays(GLenum mode, GLint first, GLsizei count) {
	static const auto glDrawArrays_ = getFunction<void, GLenum, GLint, GLsizei>("glDrawArrays");
	assert(glDrawArrays_ != nullptr);
	return glDrawArrays_(mode, first, count);
}
void glDrawElements(GLenum mode, GLsizei count, GLenum type, const void * indices) {
	static const auto glDrawElements_ = getFunction<void, GLenum, GLsizei, GLenum, const void *>("glDrawElements");
	assert(glDrawElements_ != nullptr);
	return glDrawElements_(mode, count, type, indices);
}
void glEnable(GLenum cap) {
	static const auto glEnable_ = getFunction<void, GLenum>("glEnable");
	assert(glEnable_ != nullptr);
	return glEnable_(cap);
}
void glEnableClientState(GLenum array) {
	static const auto glEnableClientState_ = getFunction<void, GLenum>("glEnableClientState");
	assert(glEnableClientState_ != nullptr);
	return glEnableClientState_(array);
}
void glFinish() {
	static const auto glFinish_ = getFunction<void>("glFinish");
	assert(glFinish_ != nullptr);
	return glFinish_();
}
void glFlush() {
	static const auto glFlush_ = getFunction<void>("glFlush");
	assert(glFlush_ != nullptr);
	return glFlush_();
}
void glFogx(GLenum pname, GLfixed param) {
	static const auto glFogx_ = getFunction<void, GLenum, GLfixed>("glFogx");
	assert(glFogx_ != nullptr);
	return glFogx_(pname, param);
}
void glFogxv(GLenum pname, GLfixed const  * param) {
	static const auto glFogxv_ = getFunction<void, GLenum, GLfixed const  *>("glFogxv");
	assert(glFogxv_ != nullptr);
	return glFogxv_(pname, param);
}
void glFrontFace(GLenum mode) {
	static const auto glFrontFace_ = getFunction<void, GLenum>("glFrontFace");
	assert(glFrontFace_ != nullptr);
	return glFrontFace_(mode);
}
void glFrustumx(GLfixed l, GLfixed r, GLfixed b, GLfixed t, GLfixed n, GLfixed f) {
	static const auto glFrustumx_ = getFunction<void, GLfixed, GLfixed, GLfixed, GLfixed, GLfixed, GLfixed>("glFrustumx");
	assert(glFrustumx_ != nullptr);
	return glFrustumx_(l, r, b, t, n, f);
}
void glGetBooleanv(GLenum pname, GLboolean * data) {
	static const auto glGetBooleanv_ = getFunction<void, GLenum, GLboolean *>("glGetBooleanv");
	assert(glGetBooleanv_ != nullptr);
	return glGetBooleanv_(pname, data);
}
void glGetBufferParameteriv(GLenum target, GLenum pname, GLint * params) {
	static const auto glGetBufferParameteriv_ = getFunction<void, GLenum, GLenum, GLint *>("glGetBufferParameteriv");
	assert(glGetBufferParameteriv_ != nullptr);
	return glGetBufferParameteriv_(target, pname, params);
}
void glGetClipPlanex(GLenum plane, GLfixed * equation) {
	static const auto glGetClipPlanex_ = getFunction<void, GLenum, GLfixed *>("glGetClipPlanex");
	assert(glGetClipPlanex_ != nullptr);
	return glGetClipPlanex_(plane, equation);
}
void glGenBuffers(GLsizei n, GLuint * buffers) {
	static const auto glGenBuffers_ = getFunction<void, GLsizei, GLuint *>("glGenBuffers");
	assert(glGenBuffers_ != nullptr);
	return glGenBuffers_(n, buffers);
}
void glGenTextures(GLsizei n, GLuint * textures) {
	static const auto glGenTextures_ = getFunction<void, GLsizei, GLuint *>("glGenTextures");
	assert(glGenTextures_ != nullptr);
	return glGenTextures_(n, textures);
}
GLenum glGetError() {
	static const auto glGetError_ = getFunction<GLenum>("glGetError");
	assert(glGetError_ != nullptr);
	return glGetError_();
}
void glGetFixedv(GLenum pname, GLfixed * params) {
	static const auto glGetFixedv_ = getFunction<void, GLenum, GLfixed *>("glGetFixedv");
	assert(glGetFixedv_ != nullptr);
	return glGetFixedv_(pname, params);
}
void glGetIntegerv(GLenum pname, GLint * data) {
	static const auto glGetIntegerv_ = getFunction<void, GLenum, GLint *>("glGetIntegerv");
	assert(glGetIntegerv_ != nullptr);
	return glGetIntegerv_(pname, data);
}
void glGetLightxv(GLenum light, GLenum pname, GLfixed * params) {
	static const auto glGetLightxv_ = getFunction<void, GLenum, GLenum, GLfixed *>("glGetLightxv");
	assert(glGetLightxv_ != nullptr);
	return glGetLightxv_(light, pname, params);
}
void glGetMaterialxv(GLenum face, GLenum pname, GLfixed * params) {
	static const auto glGetMaterialxv_ = getFunction<void, GLenum, GLenum, GLfixed *>("glGetMaterialxv");
	assert(glGetMaterialxv_ != nullptr);
	return glGetMaterialxv_(face, pname, params);
}
void glGetPointerv(GLenum pname, void ** params) {
	static const auto glGetPointerv_ = getFunction<void, GLenum, void **>("glGetPointerv");
	assert(glGetPointerv_ != nullptr);
	return glGetPointerv_(pname, params);
}
GLubyte const  * glGetString(GLenum name) {
	static const auto glGetString_ = getFunction<GLubyte const  *, GLenum>("glGetString");
	assert(glGetString_ != nullptr);
	return glGetString_(name);
}
void glGetTexEnviv(GLenum target, GLenum pname, GLint * params) {
	static const auto glGetTexEnviv_ = getFunction<void, GLenum, GLenum, GLint *>("glGetTexEnviv");
	assert(glGetTexEnviv_ != nullptr);
	return glGetTexEnviv_(target, pname, params);
}
void glGetTexEnvxv(GLenum target, GLenum pname, GLfixed * params) {
	static const auto glGetTexEnvxv_ = getFunction<void, GLenum, GLenum, GLfixed *>("glGetTexEnvxv");
	assert(glGetTexEnvxv_ != nullptr);
	return glGetTexEnvxv_(target, pname, params);
}
void glGetTexParameteriv(GLenum target, GLenum pname, GLint * params) {
	static const auto glGetTexParameteriv_ = getFunction<void, GLenum, GLenum, GLint *>("glGetTexParameteriv");
	assert(glGetTexParameteriv_ != nullptr);
	return glGetTexParameteriv_(target, pname, params);
}
void glGetTexParameterxv(GLenum target, GLenum pname, GLfixed * params) {
	static const auto glGetTexParameterxv_ = getFunction<void, GLenum, GLenum, GLfixed *>("glGetTexParameterxv");
	assert(glGetTexParameterxv_ != nullptr);
	return glGetTexParameterxv_(target, pname, params);
}
void glHint(GLenum target, GLenum mode) {
	static const auto glHint_ = getFunction<void, GLenum, GLenum>("glHint");
	assert(glHint_ != nullptr);
	return glHint_(target, mode);
}
GLboolean glIsBuffer(GLuint buffer) {
	static const auto glIsBuffer_ = getFunction<GLboolean, GLuint>("glIsBuffer");
	assert(glIsBuffer_ != nullptr);
	return glIsBuffer_(buffer);
}
GLboolean glIsEnabled(GLenum cap) {
	static const auto glIsEnabled_ = getFunction<GLboolean, GLenum>("glIsEnabled");
	assert(glIsEnabled_ != nullptr);
	return glIsEnabled_(cap);
}
GLboolean glIsTexture(GLuint texture) {
	static const auto glIsTexture_ = getFunction<GLboolean, GLuint>("glIsTexture");
	assert(glIsTexture_ != nullptr);
	return glIsTexture_(texture);
}
void glLightModelx(GLenum pname, GLfixed param) {
	static const auto glLightModelx_ = getFunction<void, GLenum, GLfixed>("glLightModelx");
	assert(glLightModelx_ != nullptr);
	return glLightModelx_(pname, param);
}
void glLightModelxv(GLenum pname, GLfixed const  * param) {
	static const auto glLightModelxv_ = getFunction<void, GLenum, GLfixed const  *>("glLightModelxv");
	assert(glLightModelxv_ != nullptr);
	return glLightModelxv_(pname, param);
}
void glLightx(GLenum light, GLenum pname, GLfixed param) {
	static const auto glLightx_ = getFunction<void, GLenum, GLenum, GLfixed>("glLightx");
	assert(glLightx_ != nullptr);
	return glLightx_(light, pname, param);
}
void glLightxv(GLenum light, GLenum pname, GLfixed const  * params) {
	static const auto glLightxv_ = getFunction<void, GLenum, GLenum, GLfixed const  *>("glLightxv");
	assert(glLightxv_ != nullptr);
	return glLightxv_(light, pname, params);
}
void glLineWidthx(GLfixed width) {
	static const auto glLineWidthx_ = getFunction<void, GLfixed>("glLineWidthx");
	assert(glLineWidthx_ != nullptr);
	return glLineWidthx_(width);
}
void glLoadIdentity() {
	static const auto glLoadIdentity_ = getFunction<void>("glLoadIdentity");
	assert(glLoadIdentity_ != nullptr);
	return glLoadIdentity_();
}
void glLoadMatrixx(GLfixed const  * m) {
	static const auto glLoadMatrixx_ = getFunction<void, GLfixed const  *>("glLoadMatrixx");
	assert(glLoadMatrixx_ != nullptr);
	return glLoadMatrixx_(m);
}
void glLogicOp(GLenum opcode) {
	static const auto glLogicOp_ = getFunction<void, GLenum>("glLogicOp");
	assert(glLogicOp_ != nullptr);
	return glLogicOp_(opcode);
}
void glMaterialx(GLenum face, GLenum pname, GLfixed param) {
	static const auto glMaterialx_ = getFunction<void, GLenum, GLenum, GLfixed>("glMaterialx");
	assert(glMaterialx_ != nullptr);
	return glMaterialx_(face, pname, param);
}
void glMaterialxv(GLenum face, GLenum pname, GLfixed const  * param) {
	static const auto glMaterialxv_ = getFunction<void, GLenum, GLenum, GLfixed const  *>("glMaterialxv");
	assert(glMaterialxv_ != nullptr);
	return glMaterialxv_(face, pname, param);
}
void glMatrixMode(GLenum mode) {
	static const auto glMatrixMode_ = getFunction<void, GLenum>("glMatrixMode");
	assert(glMatrixMode_ != nullptr);
	return glMatrixMode_(mode);
}
void glMultMatrixx(GLfixed const  * m) {
	static const auto glMultMatrixx_ = getFunction<void, GLfixed const  *>("glMultMatrixx");
	assert(glMultMatrixx_ != nullptr);
	return glMultMatrixx_(m);
}
void glMultiTexCoord4x(GLenum texture, GLfixed s, GLfixed t, GLfixed r, GLfixed q) {
	static const auto glMultiTexCoord4x_ = getFunction<void, GLenum, GLfixed, GLfixed, GLfixed, GLfixed>("glMultiTexCoord4x");
	assert(glMultiTexCoord4x_ != nullptr);
	return glMultiTexCoord4x_(texture, s, t, r, q);
}
void glNormal3x(GLfixed nx, GLfixed ny, GLfixed nz) {
	static const auto glNormal3x_ = getFunction<void, GLfixed, GLfixed, GLfixed>("glNormal3x");
	assert(glNormal3x_ != nullptr);
	return glNormal3x_(nx, ny, nz);
}
void glNormalPointer(GLenum type, GLsizei stride, const void * pointer) {
	static const auto glNormalPointer_ = getFunction<void, GLenum, GLsizei, const void *>("glNormalPointer");
	assert(glNormalPointer_ != nullptr);
	return glNormalPointer_(type, stride, pointer);
}
void glOrthox(GLfixed l, GLfixed r, GLfixed b, GLfixed t, GLfixed n, GLfixed f) {
	static const auto glOrthox_ = getFunction<void, GLfixed, GLfixed, GLfixed, GLfixed, GLfixed, GLfixed>("glOrthox");
	assert(glOrthox_ != nullptr);
	return glOrthox_(l, r, b, t, n, f);
}
void glPixelStorei(GLenum pname, GLint param) {
	static const auto glPixelStorei_ = getFunction<void, GLenum, GLint>("glPixelStorei");
	assert(glPixelStorei_ != nullptr);
	return glPixelStorei_(pname, param);
}
void glPointParameterx(GLenum pname, GLfixed param) {
	static const auto glPointParameterx_ = getFunction<void, GLenum, GLfixed>("glPointParameterx");
	assert(glPointParameterx_ != nullptr);
	return glPointParameterx_(pname, param);
}
void glPointParameterxv(GLenum pname, GLfixed const  * params) {
	static const auto glPointParameterxv_ = getFunction<void, GLenum, GLfixed const  *>("glPointParameterxv");
	assert(glPointParameterxv_ != nullptr);
	return glPointParameterxv_(pname, params);
}
void glPointSizex(GLfixed size) {
	static const auto glPointSizex_ = getFunction<void, GLfixed>("glPointSizex");
	assert(glPointSizex_ != nullptr);
	return glPointSizex_(size);
}
void glPolygonOffsetx(GLfixed factor, GLfixed units) {
	static const auto glPolygonOffsetx_ = getFunction<void, GLfixed, GLfixed>("glPolygonOffsetx");
	assert(glPolygonOffsetx_ != nullptr);
	return glPolygonOffsetx_(factor, units);
}
void glPopMatrix() {
	static const auto glPopMatrix_ = getFunction<void>("glPopMatrix");
	assert(glPopMatrix_ != nullptr);
	return glPopMatrix_();
}
void glPushMatrix() {
	static const auto glPushMatrix_ = getFunction<void>("glPushMatrix");
	assert(glPushMatrix_ != nullptr);
	return glPushMatrix_();
}
void glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void * pixels) {
	static const auto glReadPixels_ = getFunction<void, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, void *>("glReadPixels");
	assert(glReadPixels_ != nullptr);
	return glReadPixels_(x, y, width, height, format, type, pixels);
}
void glRotatex(GLfixed angle, GLfixed x, GLfixed y, GLfixed z) {
	static const auto glRotatex_ = getFunction<void, GLfixed, GLfixed, GLfixed, GLfixed>("glRotatex");
	assert(glRotatex_ != nullptr);
	return glRotatex_(angle, x, y, z);
}
void glSampleCoverage(GLfloat value, GLboolean invert) {
	static const auto glSampleCoverage_ = getFunction<void, GLfloat, GLboolean>("glSampleCoverage");
	assert(glSampleCoverage_ != nullptr);
	return glSampleCoverage_(value, invert);
}
void glSampleCoveragex(GLclampx value, GLboolean invert) {
	static const auto glSampleCoveragex_ = getFunction<void, GLclampx, GLboolean>("glSampleCoveragex");
	assert(glSampleCoveragex_ != nullptr);
	return glSampleCoveragex_(value, invert);
}
void glScalex(GLfixed x, GLfixed y, GLfixed z) {
	static const auto glScalex_ = getFunction<void, GLfixed, GLfixed, GLfixed>("glScalex");
	assert(glScalex_ != nullptr);
	return glScalex_(x, y, z);
}
void glScissor(GLint x, GLint y, GLsizei width, GLsizei height) {
	static const auto glScissor_ = getFunction<void, GLint, GLint, GLsizei, GLsizei>("glScissor");
	assert(glScissor_ != nullptr);
	return glScissor_(x, y, width, height);
}
void glShadeModel(GLenum mode) {
	static const auto glShadeModel_ = getFunction<void, GLenum>("glShadeModel");
	assert(glShadeModel_ != nullptr);
	return glShadeModel_(mode);
}
void glStencilFunc(GLenum func, GLint ref, GLuint mask) {
	static const auto glStencilFunc_ = getFunction<void, GLenum, GLint, GLuint>("glStencilFunc");
	assert(glStencilFunc_ != nullptr);
	return glStencilFunc_(func, ref, mask);
}
void glStencilMask(GLuint mask) {
	static const auto glStencilMask_ = getFunction<void, GLuint>("glStencilMask");
	assert(glStencilMask_ != nullptr);
	return glStencilMask_(mask);
}
void glStencilOp(GLenum fail, GLenum zfail, GLenum zpass) {
	static const auto glStencilOp_ = getFunction<void, GLenum, GLenum, GLenum>("glStencilOp");
	assert(glStencilOp_ != nullptr);
	return glStencilOp_(fail, zfail, zpass);
}
void glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const void * pointer) {
	static const auto glTexCoordPointer_ = getFunction<void, GLint, GLenum, GLsizei, const void *>("glTexCoordPointer");
	assert(glTexCoordPointer_ != nullptr);
	return glTexCoordPointer_(size, type, stride, pointer);
}
void glTexEnvi(GLenum target, GLenum pname, GLint param) {
	static const auto glTexEnvi_ = getFunction<void, GLenum, GLenum, GLint>("glTexEnvi");
	assert(glTexEnvi_ != nullptr);
	return glTexEnvi_(target, pname, param);
}
void glTexEnvx(GLenum target, GLenum pname, GLfixed param) {
	static const auto glTexEnvx_ = getFunction<void, GLenum, GLenum, GLfixed>("glTexEnvx");
	assert(glTexEnvx_ != nullptr);
	return glTexEnvx_(target, pname, param);
}
void glTexEnviv(GLenum target, GLenum pname, GLint const  * params) {
	static const auto glTexEnviv_ = getFunction<void, GLenum, GLenum, GLint const  *>("glTexEnviv");
	assert(glTexEnviv_ != nullptr);
	return glTexEnviv_(target, pname, params);
}
void glTexEnvxv(GLenum target, GLenum pname, GLfixed const  * params) {
	static const auto glTexEnvxv_ = getFunction<void, GLenum, GLenum, GLfixed const  *>("glTexEnvxv");
	assert(glTexEnvxv_ != nullptr);
	return glTexEnvxv_(target, pname, params);
}
void glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void * pixels) {
	static const auto glTexImage2D_ = getFunction<void, GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const void *>("glTexImage2D");
	assert(glTexImage2D_ != nullptr);
	return glTexImage2D_(target, level, internalformat, width, height, border, format, type, pixels);
}
void glTexParameteri(GLenum target, GLenum pname, GLint param) {
	static const auto glTexParameteri_ = getFunction<void, GLenum, GLenum, GLint>("glTexParameteri");
	assert(glTexParameteri_ != nullptr);
	return glTexParameteri_(target, pname, param);
}
void glTexParameterx(GLenum target, GLenum pname, GLfixed param) {
	static const auto glTexParameterx_ = getFunction<void, GLenum, GLenum, GLfixed>("glTexParameterx");
	assert(glTexParameterx_ != nullptr);
	return glTexParameterx_(target, pname, param);
}
void glTexParameteriv(GLenum target, GLenum pname, GLint const  * params) {
	static const auto glTexParameteriv_ = getFunction<void, GLenum, GLenum, GLint const  *>("glTexParameteriv");
	assert(glTexParameteriv_ != nullptr);
	return glTexParameteriv_(target, pname, params);
}
void glTexParameterxv(GLenum target, GLenum pname, GLfixed const  * params) {
	static const auto glTexParameterxv_ = getFunction<void, GLenum, GLenum, GLfixed const  *>("glTexParameterxv");
	assert(glTexParameterxv_ != nullptr);
	return glTexParameterxv_(target, pname, params);
}
void glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels) {
	static const auto glTexSubImage2D_ = getFunction<void, GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const void *>("glTexSubImage2D");
	assert(glTexSubImage2D_ != nullptr);
	return glTexSubImage2D_(target, level, xoffset, yoffset, width, height, format, type, pixels);
}
void glTranslatex(GLfixed x, GLfixed y, GLfixed z) {
	static const auto glTranslatex_ = getFunction<void, GLfixed, GLfixed, GLfixed>("glTranslatex");
	assert(glTranslatex_ != nullptr);
	return glTranslatex_(x, y, z);
}
void glVertexPointer(GLint size, GLenum type, GLsizei stride, const void * pointer) {
	static const auto glVertexPointer_ = getFunction<void, GLint, GLenum, GLsizei, const void *>("glVertexPointer");
	assert(glVertexPointer_ != nullptr);
	return glVertexPointer_(size, type, stride, pointer);
}
void glViewport(GLint x, GLint y, GLsizei width, GLsizei height) {
	static const auto glViewport_ = getFunction<void, GLint, GLint, GLsizei, GLsizei>("glViewport");
	assert(glViewport_ != nullptr);
	return glViewport_(x, y, width, height);
}
void glAttachShader(GLuint program, GLuint shader) {
	static const auto glAttachShader_ = getFunction<void, GLuint, GLuint>("glAttachShader");
	assert(glAttachShader_ != nullptr);
	return glAttachShader_(program, shader);
}
void glBindAttribLocation(GLuint program, GLuint index, GLchar const  * name) {
	static const auto glBindAttribLocation_ = getFunction<void, GLuint, GLuint, GLchar const  *>("glBindAttribLocation");
	assert(glBindAttribLocation_ != nullptr);
	return glBindAttribLocation_(program, index, name);
}
void glBindFramebuffer(GLenum target, GLuint framebuffer) {
	static const auto glBindFramebuffer_ = getFunction<void, GLenum, GLuint>("glBindFramebuffer");
	assert(glBindFramebuffer_ != nullptr);
	return glBindFramebuffer_(target, framebuffer);
}
void glBindRenderbuffer(GLenum target, GLuint renderbuffer) {
	static const auto glBindRenderbuffer_ = getFunction<void, GLenum, GLuint>("glBindRenderbuffer");
	assert(glBindRenderbuffer_ != nullptr);
	return glBindRenderbuffer_(target, renderbuffer);
}
void glBlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
	static const auto glBlendColor_ = getFunction<void, GLfloat, GLfloat, GLfloat, GLfloat>("glBlendColor");
	assert(glBlendColor_ != nullptr);
	return glBlendColor_(red, green, blue, alpha);
}
void glBlendEquation(GLenum mode) {
	static const auto glBlendEquation_ = getFunction<void, GLenum>("glBlendEquation");
	assert(glBlendEquation_ != nullptr);
	return glBlendEquation_(mode);
}
void glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha) {
	static const auto glBlendEquationSeparate_ = getFunction<void, GLenum, GLenum>("glBlendEquationSeparate");
	assert(glBlendEquationSeparate_ != nullptr);
	return glBlendEquationSeparate_(modeRGB, modeAlpha);
}
void glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) {
	static const auto glBlendFuncSeparate_ = getFunction<void, GLenum, GLenum, GLenum, GLenum>("glBlendFuncSeparate");
	assert(glBlendFuncSeparate_ != nullptr);
	return glBlendFuncSeparate_(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
}
GLenum glCheckFramebufferStatus(GLenum target) {
	static const auto glCheckFramebufferStatus_ = getFunction<GLenum, GLenum>("glCheckFramebufferStatus");
	assert(glCheckFramebufferStatus_ != nullptr);
	return glCheckFramebufferStatus_(target);
}
void glCompileShader(GLuint shader) {
	static const auto glCompileShader_ = getFunction<void, GLuint>("glCompileShader");
	assert(glCompileShader_ != nullptr);
	return glCompileShader_(shader);
}
GLuint glCreateProgram() {
	static const auto glCreateProgram_ = getFunction<GLuint>("glCreateProgram");
	assert(glCreateProgram_ != nullptr);
	return glCreateProgram_();
}
GLuint glCreateShader(GLenum type) {
	static const auto glCreateShader_ = getFunction<GLuint, GLenum>("glCreateShader");
	assert(glCreateShader_ != nullptr);
	return glCreateShader_(type);
}
void glDeleteFramebuffers(GLsizei n, GLuint const  * framebuffers) {
	static const auto glDeleteFramebuffers_ = getFunction<void, GLsizei, GLuint const  *>("glDeleteFramebuffers");
	assert(glDeleteFramebuffers_ != nullptr);
	return glDeleteFramebuffers_(n, framebuffers);
}
void glDeleteProgram(GLuint program) {
	static const auto glDeleteProgram_ = getFunction<void, GLuint>("glDeleteProgram");
	assert(glDeleteProgram_ != nullptr);
	return glDeleteProgram_(program);
}
void glDeleteRenderbuffers(GLsizei n, GLuint const  * renderbuffers) {
	static const auto glDeleteRenderbuffers_ = getFunction<void, GLsizei, GLuint const  *>("glDeleteRenderbuffers");
	assert(glDeleteRenderbuffers_ != nullptr);
	return glDeleteRenderbuffers_(n, renderbuffers);
}
void glDeleteShader(GLuint shader) {
	static const auto glDeleteShader_ = getFunction<void, GLuint>("glDeleteShader");
	assert(glDeleteShader_ != nullptr);
	return glDeleteShader_(shader);
}
void glDetachShader(GLuint program, GLuint shader) {
	static const auto glDetachShader_ = getFunction<void, GLuint, GLuint>("glDetachShader");
	assert(glDetachShader_ != nullptr);
	return glDetachShader_(program, shader);
}
void glDisableVertexAttribArray(GLuint index) {
	static const auto glDisableVertexAttribArray_ = getFunction<void, GLuint>("glDisableVertexAttribArray");
	assert(glDisableVertexAttribArray_ != nullptr);
	return glDisableVertexAttribArray_(index);
}
void glEnableVertexAttribArray(GLuint index) {
	static const auto glEnableVertexAttribArray_ = getFunction<void, GLuint>("glEnableVertexAttribArray");
	assert(glEnableVertexAttribArray_ != nullptr);
	return glEnableVertexAttribArray_(index);
}
void glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) {
	static const auto glFramebufferRenderbuffer_ = getFunction<void, GLenum, GLenum, GLenum, GLuint>("glFramebufferRenderbuffer");
	assert(glFramebufferRenderbuffer_ != nullptr);
	return glFramebufferRenderbuffer_(target, attachment, renderbuffertarget, renderbuffer);
}
void glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {
	static const auto glFramebufferTexture2D_ = getFunction<void, GLenum, GLenum, GLenum, GLuint, GLint>("glFramebufferTexture2D");
	assert(glFramebufferTexture2D_ != nullptr);
	return glFramebufferTexture2D_(target, attachment, textarget, texture, level);
}
void glGenerateMipmap(GLenum target) {
	static const auto glGenerateMipmap_ = getFunction<void, GLenum>("glGenerateMipmap");
	assert(glGenerateMipmap_ != nullptr);
	return glGenerateMipmap_(target);
}
void glGenFramebuffers(GLsizei n, GLuint * framebuffers) {
	static const auto glGenFramebuffers_ = getFunction<void, GLsizei, GLuint *>("glGenFramebuffers");
	assert(glGenFramebuffers_ != nullptr);
	return glGenFramebuffers_(n, framebuffers);
}
void glGenRenderbuffers(GLsizei n, GLuint * renderbuffers) {
	static const auto glGenRenderbuffers_ = getFunction<void, GLsizei, GLuint *>("glGenRenderbuffers");
	assert(glGenRenderbuffers_ != nullptr);
	return glGenRenderbuffers_(n, renderbuffers);
}
void glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name) {
	static const auto glGetActiveAttrib_ = getFunction<void, GLuint, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLchar *>("glGetActiveAttrib");
	assert(glGetActiveAttrib_ != nullptr);
	return glGetActiveAttrib_(program, index, bufSize, length, size, type, name);
}
void glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name) {
	static const auto glGetActiveUniform_ = getFunction<void, GLuint, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLchar *>("glGetActiveUniform");
	assert(glGetActiveUniform_ != nullptr);
	return glGetActiveUniform_(program, index, bufSize, length, size, type, name);
}
void glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei * count, GLuint * shaders) {
	static const auto glGetAttachedShaders_ = getFunction<void, GLuint, GLsizei, GLsizei *, GLuint *>("glGetAttachedShaders");
	assert(glGetAttachedShaders_ != nullptr);
	return glGetAttachedShaders_(program, maxCount, count, shaders);
}
GLint glGetAttribLocation(GLuint program, GLchar const  * name) {
	static const auto glGetAttribLocation_ = getFunction<GLint, GLuint, GLchar const  *>("glGetAttribLocation");
	assert(glGetAttribLocation_ != nullptr);
	return glGetAttribLocation_(program, name);
}
void glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint * params) {
	static const auto glGetFramebufferAttachmentParameteriv_ = getFunction<void, GLenum, GLenum, GLenum, GLint *>("glGetFramebufferAttachmentParameteriv");
	assert(glGetFramebufferAttachmentParameteriv_ != nullptr);
	return glGetFramebufferAttachmentParameteriv_(target, attachment, pname, params);
}
void glGetProgramiv(GLuint program, GLenum pname, GLint * params) {
	static const auto glGetProgramiv_ = getFunction<void, GLuint, GLenum, GLint *>("glGetProgramiv");
	assert(glGetProgramiv_ != nullptr);
	return glGetProgramiv_(program, pname, params);
}
void glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei * length, GLchar * infoLog) {
	static const auto glGetProgramInfoLog_ = getFunction<void, GLuint, GLsizei, GLsizei *, GLchar *>("glGetProgramInfoLog");
	assert(glGetProgramInfoLog_ != nullptr);
	return glGetProgramInfoLog_(program, bufSize, length, infoLog);
}
void glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint * params) {
	static const auto glGetRenderbufferParameteriv_ = getFunction<void, GLenum, GLenum, GLint *>("glGetRenderbufferParameteriv");
	assert(glGetRenderbufferParameteriv_ != nullptr);
	return glGetRenderbufferParameteriv_(target, pname, params);
}
void glGetShaderiv(GLuint shader, GLenum pname, GLint * params) {
	static const auto glGetShaderiv_ = getFunction<void, GLuint, GLenum, GLint *>("glGetShaderiv");
	assert(glGetShaderiv_ != nullptr);
	return glGetShaderiv_(shader, pname, params);
}
void glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * infoLog) {
	static const auto glGetShaderInfoLog_ = getFunction<void, GLuint, GLsizei, GLsizei *, GLchar *>("glGetShaderInfoLog");
	assert(glGetShaderInfoLog_ != nullptr);
	return glGetShaderInfoLog_(shader, bufSize, length, infoLog);
}
void glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint * range, GLint * precision) {
	static const auto glGetShaderPrecisionFormat_ = getFunction<void, GLenum, GLenum, GLint *, GLint *>("glGetShaderPrecisionFormat");
	assert(glGetShaderPrecisionFormat_ != nullptr);
	return glGetShaderPrecisionFormat_(shadertype, precisiontype, range, precision);
}
void glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * source) {
	static const auto glGetShaderSource_ = getFunction<void, GLuint, GLsizei, GLsizei *, GLchar *>("glGetShaderSource");
	assert(glGetShaderSource_ != nullptr);
	return glGetShaderSource_(shader, bufSize, length, source);
}
void glGetUniformfv(GLuint program, GLint location, GLfloat * params) {
	static const auto glGetUniformfv_ = getFunction<void, GLuint, GLint, GLfloat *>("glGetUniformfv");
	assert(glGetUniformfv_ != nullptr);
	return glGetUniformfv_(program, location, params);
}
void glGetUniformiv(GLuint program, GLint location, GLint * params) {
	static const auto glGetUniformiv_ = getFunction<void, GLuint, GLint, GLint *>("glGetUniformiv");
	assert(glGetUniformiv_ != nullptr);
	return glGetUniformiv_(program, location, params);
}
GLint glGetUniformLocation(GLuint program, GLchar const  * name) {
	static const auto glGetUniformLocation_ = getFunction<GLint, GLuint, GLchar const  *>("glGetUniformLocation");
	assert(glGetUniformLocation_ != nullptr);
	return glGetUniformLocation_(program, name);
}
void glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat * params) {
	static const auto glGetVertexAttribfv_ = getFunction<void, GLuint, GLenum, GLfloat *>("glGetVertexAttribfv");
	assert(glGetVertexAttribfv_ != nullptr);
	return glGetVertexAttribfv_(index, pname, params);
}
void glGetVertexAttribiv(GLuint index, GLenum pname, GLint * params) {
	static const auto glGetVertexAttribiv_ = getFunction<void, GLuint, GLenum, GLint *>("glGetVertexAttribiv");
	assert(glGetVertexAttribiv_ != nullptr);
	return glGetVertexAttribiv_(index, pname, params);
}
void glGetVertexAttribPointerv(GLuint index, GLenum pname, void ** pointer) {
	static const auto glGetVertexAttribPointerv_ = getFunction<void, GLuint, GLenum, void **>("glGetVertexAttribPointerv");
	assert(glGetVertexAttribPointerv_ != nullptr);
	return glGetVertexAttribPointerv_(index, pname, pointer);
}
GLboolean glIsFramebuffer(GLuint framebuffer) {
	static const auto glIsFramebuffer_ = getFunction<GLboolean, GLuint>("glIsFramebuffer");
	assert(glIsFramebuffer_ != nullptr);
	return glIsFramebuffer_(framebuffer);
}
GLboolean glIsProgram(GLuint program) {
	static const auto glIsProgram_ = getFunction<GLboolean, GLuint>("glIsProgram");
	assert(glIsProgram_ != nullptr);
	return glIsProgram_(program);
}
GLboolean glIsRenderbuffer(GLuint renderbuffer) {
	static const auto glIsRenderbuffer_ = getFunction<GLboolean, GLuint>("glIsRenderbuffer");
	assert(glIsRenderbuffer_ != nullptr);
	return glIsRenderbuffer_(renderbuffer);
}
GLboolean glIsShader(GLuint shader) {
	static const auto glIsShader_ = getFunction<GLboolean, GLuint>("glIsShader");
	assert(glIsShader_ != nullptr);
	return glIsShader_(shader);
}
void glLinkProgram(GLuint program) {
	static const auto glLinkProgram_ = getFunction<void, GLuint>("glLinkProgram");
	assert(glLinkProgram_ != nullptr);
	return glLinkProgram_(program);
}
void glReleaseShaderCompiler() {
	static const auto glReleaseShaderCompiler_ = getFunction<void>("glReleaseShaderCompiler");
	assert(glReleaseShaderCompiler_ != nullptr);
	return glReleaseShaderCompiler_();
}
void glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) {
	static const auto glRenderbufferStorage_ = getFunction<void, GLenum, GLenum, GLsizei, GLsizei>("glRenderbufferStorage");
	assert(glRenderbufferStorage_ != nullptr);
	return glRenderbufferStorage_(target, internalformat, width, height);
}
void glShaderBinary(GLsizei count, GLuint const  * shaders, GLenum binaryformat, const void * binary, GLsizei length) {
	static const auto glShaderBinary_ = getFunction<void, GLsizei, GLuint const  *, GLenum, const void *, GLsizei>("glShaderBinary");
	assert(glShaderBinary_ != nullptr);
	return glShaderBinary_(count, shaders, binaryformat, binary, length);
}
void glShaderSource(GLuint shader, GLsizei count, GLchar const  *const* string, GLint const  * length) {
	static const auto glShaderSource_ = getFunction<void, GLuint, GLsizei, GLchar const  *const*, GLint const  *>("glShaderSource");
	assert(glShaderSource_ != nullptr);
	return glShaderSource_(shader, count, string, length);
}
void glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask) {
	static const auto glStencilFuncSeparate_ = getFunction<void, GLenum, GLenum, GLint, GLuint>("glStencilFuncSeparate");
	assert(glStencilFuncSeparate_ != nullptr);
	return glStencilFuncSeparate_(face, func, ref, mask);
}
void glStencilMaskSeparate(GLenum face, GLuint mask) {
	static const auto glStencilMaskSeparate_ = getFunction<void, GLenum, GLuint>("glStencilMaskSeparate");
	assert(glStencilMaskSeparate_ != nullptr);
	return glStencilMaskSeparate_(face, mask);
}
void glStencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass) {
	static const auto glStencilOpSeparate_ = getFunction<void, GLenum, GLenum, GLenum, GLenum>("glStencilOpSeparate");
	assert(glStencilOpSeparate_ != nullptr);
	return glStencilOpSeparate_(face, sfail, dpfail, dppass);
}
void glUniform1f(GLint location, GLfloat v0) {
	static const auto glUniform1f_ = getFunction<void, GLint, GLfloat>("glUniform1f");
	assert(glUniform1f_ != nullptr);
	return glUniform1f_(location, v0);
}
void glUniform1fv(GLint location, GLsizei count, GLfloat const  * value) {
	static const auto glUniform1fv_ = getFunction<void, GLint, GLsizei, GLfloat const  *>("glUniform1fv");
	assert(glUniform1fv_ != nullptr);
	return glUniform1fv_(location, count, value);
}
void glUniform1i(GLint location, GLint v0) {
	static const auto glUniform1i_ = getFunction<void, GLint, GLint>("glUniform1i");
	assert(glUniform1i_ != nullptr);
	return glUniform1i_(location, v0);
}
void glUniform1iv(GLint location, GLsizei count, GLint const  * value) {
	static const auto glUniform1iv_ = getFunction<void, GLint, GLsizei, GLint const  *>("glUniform1iv");
	assert(glUniform1iv_ != nullptr);
	return glUniform1iv_(location, count, value);
}
void glUniform2f(GLint location, GLfloat v0, GLfloat v1) {
	static const auto glUniform2f_ = getFunction<void, GLint, GLfloat, GLfloat>("glUniform2f");
	assert(glUniform2f_ != nullptr);
	return glUniform2f_(location, v0, v1);
}
void glUniform2fv(GLint location, GLsizei count, GLfloat const  * value) {
	static const auto glUniform2fv_ = getFunction<void, GLint, GLsizei, GLfloat const  *>("glUniform2fv");
	assert(glUniform2fv_ != nullptr);
	return glUniform2fv_(location, count, value);
}
void glUniform2i(GLint location, GLint v0, GLint v1) {
	static const auto glUniform2i_ = getFunction<void, GLint, GLint, GLint>("glUniform2i");
	assert(glUniform2i_ != nullptr);
	return glUniform2i_(location, v0, v1);
}
void glUniform2iv(GLint location, GLsizei count, GLint const  * value) {
	static const auto glUniform2iv_ = getFunction<void, GLint, GLsizei, GLint const  *>("glUniform2iv");
	assert(glUniform2iv_ != nullptr);
	return glUniform2iv_(location, count, value);
}
void glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) {
	static const auto glUniform3f_ = getFunction<void, GLint, GLfloat, GLfloat, GLfloat>("glUniform3f");
	assert(glUniform3f_ != nullptr);
	return glUniform3f_(location, v0, v1, v2);
}
void glUniform3fv(GLint location, GLsizei count, GLfloat const  * value) {
	static const auto glUniform3fv_ = getFunction<void, GLint, GLsizei, GLfloat const  *>("glUniform3fv");
	assert(glUniform3fv_ != nullptr);
	return glUniform3fv_(location, count, value);
}
void glUniform3i(GLint location, GLint v0, GLint v1, GLint v2) {
	static const auto glUniform3i_ = getFunction<void, GLint, GLint, GLint, GLint>("glUniform3i");
	assert(glUniform3i_ != nullptr);
	return glUniform3i_(location, v0, v1, v2);
}
void glUniform3iv(GLint location, GLsizei count, GLint const  * value) {
	static const auto glUniform3iv_ = getFunction<void, GLint, GLsizei, GLint const  *>("glUniform3iv");
	assert(glUniform3iv_ != nullptr);
	return glUniform3iv_(location, count, value);
}
void glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {
	static const auto glUniform4f_ = getFunction<void, GLint, GLfloat, GLfloat, GLfloat, GLfloat>("glUniform4f");
	assert(glUniform4f_ != nullptr);
	return glUniform4f_(location, v0, v1, v2, v3);
}
void glUniform4fv(GLint location, GLsizei count, GLfloat const  * value) {
	static const auto glUniform4fv_ = getFunction<void, GLint, GLsizei, GLfloat const  *>("glUniform4fv");
	assert(glUniform4fv_ != nullptr);
	return glUniform4fv_(location, count, value);
}
void glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) {
	static const auto glUniform4i_ = getFunction<void, GLint, GLint, GLint, GLint, GLint>("glUniform4i");
	assert(glUniform4i_ != nullptr);
	return glUniform4i_(location, v0, v1, v2, v3);
}
void glUniform4iv(GLint location, GLsizei count, GLint const  * value) {
	static const auto glUniform4iv_ = getFunction<void, GLint, GLsizei, GLint const  *>("glUniform4iv");
	assert(glUniform4iv_ != nullptr);
	return glUniform4iv_(location, count, value);
}
void glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value) {
	static const auto glUniformMatrix2fv_ = getFunction<void, GLint, GLsizei, GLboolean, GLfloat const  *>("glUniformMatrix2fv");
	assert(glUniformMatrix2fv_ != nullptr);
	return glUniformMatrix2fv_(location, count, transpose, value);
}
void glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value) {
	static const auto glUniformMatrix3fv_ = getFunction<void, GLint, GLsizei, GLboolean, GLfloat const  *>("glUniformMatrix3fv");
	assert(glUniformMatrix3fv_ != nullptr);
	return glUniformMatrix3fv_(location, count, transpose, value);
}
void glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value) {
	static const auto glUniformMatrix4fv_ = getFunction<void, GLint, GLsizei, GLboolean, GLfloat const  *>("glUniformMatrix4fv");
	assert(glUniformMatrix4fv_ != nullptr);
	return glUniformMatrix4fv_(location, count, transpose, value);
}
void glUseProgram(GLuint program) {
	static const auto glUseProgram_ = getFunction<void, GLuint>("glUseProgram");
	assert(glUseProgram_ != nullptr);
	return glUseProgram_(program);
}
void glValidateProgram(GLuint program) {
	static const auto glValidateProgram_ = getFunction<void, GLuint>("glValidateProgram");
	assert(glValidateProgram_ != nullptr);
	return glValidateProgram_(program);
}
void glVertexAttrib1f(GLuint index, GLfloat x) {
	static const auto glVertexAttrib1f_ = getFunction<void, GLuint, GLfloat>("glVertexAttrib1f");
	assert(glVertexAttrib1f_ != nullptr);
	return glVertexAttrib1f_(index, x);
}
void glVertexAttrib1fv(GLuint index, GLfloat const  * v) {
	static const auto glVertexAttrib1fv_ = getFunction<void, GLuint, GLfloat const  *>("glVertexAttrib1fv");
	assert(glVertexAttrib1fv_ != nullptr);
	return glVertexAttrib1fv_(index, v);
}
void glVertexAttrib2f(GLuint index, GLfloat x, GLfloat y) {
	static const auto glVertexAttrib2f_ = getFunction<void, GLuint, GLfloat, GLfloat>("glVertexAttrib2f");
	assert(glVertexAttrib2f_ != nullptr);
	return glVertexAttrib2f_(index, x, y);
}
void glVertexAttrib2fv(GLuint index, GLfloat const  * v) {
	static const auto glVertexAttrib2fv_ = getFunction<void, GLuint, GLfloat const  *>("glVertexAttrib2fv");
	assert(glVertexAttrib2fv_ != nullptr);
	return glVertexAttrib2fv_(index, v);
}
void glVertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z) {
	static const auto glVertexAttrib3f_ = getFunction<void, GLuint, GLfloat, GLfloat, GLfloat>("glVertexAttrib3f");
	assert(glVertexAttrib3f_ != nullptr);
	return glVertexAttrib3f_(index, x, y, z);
}
void glVertexAttrib3fv(GLuint index, GLfloat const  * v) {
	static const auto glVertexAttrib3fv_ = getFunction<void, GLuint, GLfloat const  *>("glVertexAttrib3fv");
	assert(glVertexAttrib3fv_ != nullptr);
	return glVertexAttrib3fv_(index, v);
}
void glVertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
	static const auto glVertexAttrib4f_ = getFunction<void, GLuint, GLfloat, GLfloat, GLfloat, GLfloat>("glVertexAttrib4f");
	assert(glVertexAttrib4f_ != nullptr);
	return glVertexAttrib4f_(index, x, y, z, w);
}
void glVertexAttrib4fv(GLuint index, GLfloat const  * v) {
	static const auto glVertexAttrib4fv_ = getFunction<void, GLuint, GLfloat const  *>("glVertexAttrib4fv");
	assert(glVertexAttrib4fv_ != nullptr);
	return glVertexAttrib4fv_(index, v);
}
void glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void * pointer) {
	static const auto glVertexAttribPointer_ = getFunction<void, GLuint, GLint, GLenum, GLboolean, GLsizei, const void *>("glVertexAttribPointer");
	assert(glVertexAttribPointer_ != nullptr);
	return glVertexAttribPointer_(index, size, type, normalized, stride, pointer);
}
void glEGLImageTargetTexStorageEXT(GLenum target, GLeglImageOES image, GLint const * attrib_list) {
	static const auto glEGLImageTargetTexStorageEXT_ = getFunction<void, GLenum, GLeglImageOES, GLint const *>("glEGLImageTargetTexStorageEXT");
	assert(glEGLImageTargetTexStorageEXT_ != nullptr);
	return glEGLImageTargetTexStorageEXT_(target, image, attrib_list);
}
void glEGLImageTargetTextureStorageEXT(GLuint texture, GLeglImageOES image, GLint const * attrib_list) {
	static const auto glEGLImageTargetTextureStorageEXT_ = getFunction<void, GLuint, GLeglImageOES, GLint const *>("glEGLImageTargetTextureStorageEXT");
	assert(glEGLImageTargetTextureStorageEXT_ != nullptr);
	return glEGLImageTargetTextureStorageEXT_(texture, image, attrib_list);
}
void glDrawArraysInstancedBaseInstanceEXT(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance) {
	static const auto glDrawArraysInstancedBaseInstanceEXT_ = getFunction<void, GLenum, GLint, GLsizei, GLsizei, GLuint>("glDrawArraysInstancedBaseInstanceEXT");
	assert(glDrawArraysInstancedBaseInstanceEXT_ != nullptr);
	return glDrawArraysInstancedBaseInstanceEXT_(mode, first, count, instancecount, baseinstance);
}
void glDrawElementsInstancedBaseInstanceEXT(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLuint baseinstance) {
	static const auto glDrawElementsInstancedBaseInstanceEXT_ = getFunction<void, GLenum, GLsizei, GLenum, const void *, GLsizei, GLuint>("glDrawElementsInstancedBaseInstanceEXT");
	assert(glDrawElementsInstancedBaseInstanceEXT_ != nullptr);
	return glDrawElementsInstancedBaseInstanceEXT_(mode, count, type, indices, instancecount, baseinstance);
}
void glDrawElementsInstancedBaseVertexBaseInstanceEXT(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance) {
	static const auto glDrawElementsInstancedBaseVertexBaseInstanceEXT_ = getFunction<void, GLenum, GLsizei, GLenum, const void *, GLsizei, GLint, GLuint>("glDrawElementsInstancedBaseVertexBaseInstanceEXT");
	assert(glDrawElementsInstancedBaseVertexBaseInstanceEXT_ != nullptr);
	return glDrawElementsInstancedBaseVertexBaseInstanceEXT_(mode, count, type, indices, instancecount, basevertex, baseinstance);
}
void glBindFragDataLocationIndexedEXT(GLuint program, GLuint colorNumber, GLuint index, GLchar const  * name) {
	static const auto glBindFragDataLocationIndexedEXT_ = getFunction<void, GLuint, GLuint, GLuint, GLchar const  *>("glBindFragDataLocationIndexedEXT");
	assert(glBindFragDataLocationIndexedEXT_ != nullptr);
	return glBindFragDataLocationIndexedEXT_(program, colorNumber, index, name);
}
void glBindFragDataLocationEXT(GLuint program, GLuint color, GLchar const  * name) {
	static const auto glBindFragDataLocationEXT_ = getFunction<void, GLuint, GLuint, GLchar const  *>("glBindFragDataLocationEXT");
	assert(glBindFragDataLocationEXT_ != nullptr);
	return glBindFragDataLocationEXT_(program, color, name);
}
GLint glGetProgramResourceLocationIndexEXT(GLuint program, GLenum programInterface, GLchar const  * name) {
	static const auto glGetProgramResourceLocationIndexEXT_ = getFunction<GLint, GLuint, GLenum, GLchar const  *>("glGetProgramResourceLocationIndexEXT");
	assert(glGetProgramResourceLocationIndexEXT_ != nullptr);
	return glGetProgramResourceLocationIndexEXT_(program, programInterface, name);
}
GLint glGetFragDataIndexEXT(GLuint program, GLchar const  * name) {
	static const auto glGetFragDataIndexEXT_ = getFunction<GLint, GLuint, GLchar const  *>("glGetFragDataIndexEXT");
	assert(glGetFragDataIndexEXT_ != nullptr);
	return glGetFragDataIndexEXT_(program, name);
}
void glBlendEquationEXT(GLenum mode) {
	static const auto glBlendEquationEXT_ = getFunction<void, GLenum>("glBlendEquationEXT");
	assert(glBlendEquationEXT_ != nullptr);
	return glBlendEquationEXT_(mode);
}
void glBufferStorageEXT(GLenum target, GLsizeiptr size, const void * data, GLbitfield flags) {
	static const auto glBufferStorageEXT_ = getFunction<void, GLenum, GLsizeiptr, const void *, GLbitfield>("glBufferStorageEXT");
	assert(glBufferStorageEXT_ != nullptr);
	return glBufferStorageEXT_(target, size, data, flags);
}
void glClearTexImageEXT(GLuint texture, GLint level, GLenum format, GLenum type, const void * data) {
	static const auto glClearTexImageEXT_ = getFunction<void, GLuint, GLint, GLenum, GLenum, const void *>("glClearTexImageEXT");
	assert(glClearTexImageEXT_ != nullptr);
	return glClearTexImageEXT_(texture, level, format, type, data);
}
void glClearTexSubImageEXT(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * data) {
	static const auto glClearTexSubImageEXT_ = getFunction<void, GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const void *>("glClearTexSubImageEXT");
	assert(glClearTexSubImageEXT_ != nullptr);
	return glClearTexSubImageEXT_(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, data);
}
void glClipControlEXT(GLenum origin, GLenum depth) {
	static const auto glClipControlEXT_ = getFunction<void, GLenum, GLenum>("glClipControlEXT");
	assert(glClipControlEXT_ != nullptr);
	return glClipControlEXT_(origin, depth);
}
void glCopyImageSubDataEXT(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth) {
	static const auto glCopyImageSubDataEXT_ = getFunction<void, GLuint, GLenum, GLint, GLint, GLint, GLint, GLuint, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei>("glCopyImageSubDataEXT");
	assert(glCopyImageSubDataEXT_ != nullptr);
	return glCopyImageSubDataEXT_(srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth);
}
void glLabelObjectEXT(GLenum type, GLuint object, GLsizei length, GLchar const  * label) {
	static const auto glLabelObjectEXT_ = getFunction<void, GLenum, GLuint, GLsizei, GLchar const  *>("glLabelObjectEXT");
	assert(glLabelObjectEXT_ != nullptr);
	return glLabelObjectEXT_(type, object, length, label);
}
void glGetObjectLabelEXT(GLenum type, GLuint object, GLsizei bufSize, GLsizei * length, GLchar * label) {
	static const auto glGetObjectLabelEXT_ = getFunction<void, GLenum, GLuint, GLsizei, GLsizei *, GLchar *>("glGetObjectLabelEXT");
	assert(glGetObjectLabelEXT_ != nullptr);
	return glGetObjectLabelEXT_(type, object, bufSize, length, label);
}
void glInsertEventMarkerEXT(GLsizei length, GLchar const  * marker) {
	static const auto glInsertEventMarkerEXT_ = getFunction<void, GLsizei, GLchar const  *>("glInsertEventMarkerEXT");
	assert(glInsertEventMarkerEXT_ != nullptr);
	return glInsertEventMarkerEXT_(length, marker);
}
void glPushGroupMarkerEXT(GLsizei length, GLchar const  * marker) {
	static const auto glPushGroupMarkerEXT_ = getFunction<void, GLsizei, GLchar const  *>("glPushGroupMarkerEXT");
	assert(glPushGroupMarkerEXT_ != nullptr);
	return glPushGroupMarkerEXT_(length, marker);
}
void glPopGroupMarkerEXT() {
	static const auto glPopGroupMarkerEXT_ = getFunction<void>("glPopGroupMarkerEXT");
	assert(glPopGroupMarkerEXT_ != nullptr);
	return glPopGroupMarkerEXT_();
}
void glDiscardFramebufferEXT(GLenum target, GLsizei numAttachments, GLenum const  * attachments) {
	static const auto glDiscardFramebufferEXT_ = getFunction<void, GLenum, GLsizei, GLenum const  *>("glDiscardFramebufferEXT");
	assert(glDiscardFramebufferEXT_ != nullptr);
	return glDiscardFramebufferEXT_(target, numAttachments, attachments);
}
void glGenQueriesEXT(GLsizei n, GLuint * ids) {
	static const auto glGenQueriesEXT_ = getFunction<void, GLsizei, GLuint *>("glGenQueriesEXT");
	assert(glGenQueriesEXT_ != nullptr);
	return glGenQueriesEXT_(n, ids);
}
void glDeleteQueriesEXT(GLsizei n, GLuint const  * ids) {
	static const auto glDeleteQueriesEXT_ = getFunction<void, GLsizei, GLuint const  *>("glDeleteQueriesEXT");
	assert(glDeleteQueriesEXT_ != nullptr);
	return glDeleteQueriesEXT_(n, ids);
}
GLboolean glIsQueryEXT(GLuint id) {
	static const auto glIsQueryEXT_ = getFunction<GLboolean, GLuint>("glIsQueryEXT");
	assert(glIsQueryEXT_ != nullptr);
	return glIsQueryEXT_(id);
}
void glBeginQueryEXT(GLenum target, GLuint id) {
	static const auto glBeginQueryEXT_ = getFunction<void, GLenum, GLuint>("glBeginQueryEXT");
	assert(glBeginQueryEXT_ != nullptr);
	return glBeginQueryEXT_(target, id);
}
void glEndQueryEXT(GLenum target) {
	static const auto glEndQueryEXT_ = getFunction<void, GLenum>("glEndQueryEXT");
	assert(glEndQueryEXT_ != nullptr);
	return glEndQueryEXT_(target);
}
void glQueryCounterEXT(GLuint id, GLenum target) {
	static const auto glQueryCounterEXT_ = getFunction<void, GLuint, GLenum>("glQueryCounterEXT");
	assert(glQueryCounterEXT_ != nullptr);
	return glQueryCounterEXT_(id, target);
}
void glGetQueryivEXT(GLenum target, GLenum pname, GLint * params) {
	static const auto glGetQueryivEXT_ = getFunction<void, GLenum, GLenum, GLint *>("glGetQueryivEXT");
	assert(glGetQueryivEXT_ != nullptr);
	return glGetQueryivEXT_(target, pname, params);
}
void glGetQueryObjectivEXT(GLuint id, GLenum pname, GLint * params) {
	static const auto glGetQueryObjectivEXT_ = getFunction<void, GLuint, GLenum, GLint *>("glGetQueryObjectivEXT");
	assert(glGetQueryObjectivEXT_ != nullptr);
	return glGetQueryObjectivEXT_(id, pname, params);
}
void glGetQueryObjectuivEXT(GLuint id, GLenum pname, GLuint * params) {
	static const auto glGetQueryObjectuivEXT_ = getFunction<void, GLuint, GLenum, GLuint *>("glGetQueryObjectuivEXT");
	assert(glGetQueryObjectuivEXT_ != nullptr);
	return glGetQueryObjectuivEXT_(id, pname, params);
}
void glGetQueryObjecti64vEXT(GLuint id, GLenum pname, GLint64 * params) {
	static const auto glGetQueryObjecti64vEXT_ = getFunction<void, GLuint, GLenum, GLint64 *>("glGetQueryObjecti64vEXT");
	assert(glGetQueryObjecti64vEXT_ != nullptr);
	return glGetQueryObjecti64vEXT_(id, pname, params);
}
void glGetQueryObjectui64vEXT(GLuint id, GLenum pname, GLuint64 * params) {
	static const auto glGetQueryObjectui64vEXT_ = getFunction<void, GLuint, GLenum, GLuint64 *>("glGetQueryObjectui64vEXT");
	assert(glGetQueryObjectui64vEXT_ != nullptr);
	return glGetQueryObjectui64vEXT_(id, pname, params);
}
void glGetInteger64vEXT(GLenum pname, GLint64 * data) {
	static const auto glGetInteger64vEXT_ = getFunction<void, GLenum, GLint64 *>("glGetInteger64vEXT");
	assert(glGetInteger64vEXT_ != nullptr);
	return glGetInteger64vEXT_(pname, data);
}
void glDrawBuffersEXT(GLsizei n, GLenum const  * bufs) {
	static const auto glDrawBuffersEXT_ = getFunction<void, GLsizei, GLenum const  *>("glDrawBuffersEXT");
	assert(glDrawBuffersEXT_ != nullptr);
	return glDrawBuffersEXT_(n, bufs);
}
void glEnableiEXT(GLenum target, GLuint index) {
	static const auto glEnableiEXT_ = getFunction<void, GLenum, GLuint>("glEnableiEXT");
	assert(glEnableiEXT_ != nullptr);
	return glEnableiEXT_(target, index);
}
void glDisableiEXT(GLenum target, GLuint index) {
	static const auto glDisableiEXT_ = getFunction<void, GLenum, GLuint>("glDisableiEXT");
	assert(glDisableiEXT_ != nullptr);
	return glDisableiEXT_(target, index);
}
void glBlendEquationiEXT(GLuint buf, GLenum mode) {
	static const auto glBlendEquationiEXT_ = getFunction<void, GLuint, GLenum>("glBlendEquationiEXT");
	assert(glBlendEquationiEXT_ != nullptr);
	return glBlendEquationiEXT_(buf, mode);
}
void glBlendEquationSeparateiEXT(GLuint buf, GLenum modeRGB, GLenum modeAlpha) {
	static const auto glBlendEquationSeparateiEXT_ = getFunction<void, GLuint, GLenum, GLenum>("glBlendEquationSeparateiEXT");
	assert(glBlendEquationSeparateiEXT_ != nullptr);
	return glBlendEquationSeparateiEXT_(buf, modeRGB, modeAlpha);
}
void glBlendFunciEXT(GLuint buf, GLenum src, GLenum dst) {
	static const auto glBlendFunciEXT_ = getFunction<void, GLuint, GLenum, GLenum>("glBlendFunciEXT");
	assert(glBlendFunciEXT_ != nullptr);
	return glBlendFunciEXT_(buf, src, dst);
}
void glBlendFuncSeparateiEXT(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) {
	static const auto glBlendFuncSeparateiEXT_ = getFunction<void, GLuint, GLenum, GLenum, GLenum, GLenum>("glBlendFuncSeparateiEXT");
	assert(glBlendFuncSeparateiEXT_ != nullptr);
	return glBlendFuncSeparateiEXT_(buf, srcRGB, dstRGB, srcAlpha, dstAlpha);
}
void glColorMaskiEXT(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a) {
	static const auto glColorMaskiEXT_ = getFunction<void, GLuint, GLboolean, GLboolean, GLboolean, GLboolean>("glColorMaskiEXT");
	assert(glColorMaskiEXT_ != nullptr);
	return glColorMaskiEXT_(index, r, g, b, a);
}
GLboolean glIsEnablediEXT(GLenum target, GLuint index) {
	static const auto glIsEnablediEXT_ = getFunction<GLboolean, GLenum, GLuint>("glIsEnablediEXT");
	assert(glIsEnablediEXT_ != nullptr);
	return glIsEnablediEXT_(target, index);
}
void glDrawElementsBaseVertexEXT(GLenum mode, GLsizei count, GLenum type, const void * indices, GLint basevertex) {
	static const auto glDrawElementsBaseVertexEXT_ = getFunction<void, GLenum, GLsizei, GLenum, const void *, GLint>("glDrawElementsBaseVertexEXT");
	assert(glDrawElementsBaseVertexEXT_ != nullptr);
	return glDrawElementsBaseVertexEXT_(mode, count, type, indices, basevertex);
}
void glDrawRangeElementsBaseVertexEXT(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices, GLint basevertex) {
	static const auto glDrawRangeElementsBaseVertexEXT_ = getFunction<void, GLenum, GLuint, GLuint, GLsizei, GLenum, const void *, GLint>("glDrawRangeElementsBaseVertexEXT");
	assert(glDrawRangeElementsBaseVertexEXT_ != nullptr);
	return glDrawRangeElementsBaseVertexEXT_(mode, start, end, count, type, indices, basevertex);
}
void glDrawElementsInstancedBaseVertexEXT(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex) {
	static const auto glDrawElementsInstancedBaseVertexEXT_ = getFunction<void, GLenum, GLsizei, GLenum, const void *, GLsizei, GLint>("glDrawElementsInstancedBaseVertexEXT");
	assert(glDrawElementsInstancedBaseVertexEXT_ != nullptr);
	return glDrawElementsInstancedBaseVertexEXT_(mode, count, type, indices, instancecount, basevertex);
}
void glMultiDrawElementsBaseVertexEXT(GLenum mode, GLsizei const  * count, GLenum type, const void *const* indices, GLsizei primcount, GLint const  * basevertex) {
	static const auto glMultiDrawElementsBaseVertexEXT_ = getFunction<void, GLenum, GLsizei const  *, GLenum, const void *const*, GLsizei, GLint const  *>("glMultiDrawElementsBaseVertexEXT");
	assert(glMultiDrawElementsBaseVertexEXT_ != nullptr);
	return glMultiDrawElementsBaseVertexEXT_(mode, count, type, indices, primcount, basevertex);
}
void glDrawArraysInstancedEXT(GLenum mode, GLint start, GLsizei count, GLsizei primcount) {
	static const auto glDrawArraysInstancedEXT_ = getFunction<void, GLenum, GLint, GLsizei, GLsizei>("glDrawArraysInstancedEXT");
	assert(glDrawArraysInstancedEXT_ != nullptr);
	return glDrawArraysInstancedEXT_(mode, start, count, primcount);
}
void glDrawElementsInstancedEXT(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei primcount) {
	static const auto glDrawElementsInstancedEXT_ = getFunction<void, GLenum, GLsizei, GLenum, const void *, GLsizei>("glDrawElementsInstancedEXT");
	assert(glDrawElementsInstancedEXT_ != nullptr);
	return glDrawElementsInstancedEXT_(mode, count, type, indices, primcount);
}
void glDrawTransformFeedbackEXT(GLenum mode, GLuint id) {
	static const auto glDrawTransformFeedbackEXT_ = getFunction<void, GLenum, GLuint>("glDrawTransformFeedbackEXT");
	assert(glDrawTransformFeedbackEXT_ != nullptr);
	return glDrawTransformFeedbackEXT_(mode, id);
}
void glDrawTransformFeedbackInstancedEXT(GLenum mode, GLuint id, GLsizei instancecount) {
	static const auto glDrawTransformFeedbackInstancedEXT_ = getFunction<void, GLenum, GLuint, GLsizei>("glDrawTransformFeedbackInstancedEXT");
	assert(glDrawTransformFeedbackInstancedEXT_ != nullptr);
	return glDrawTransformFeedbackInstancedEXT_(mode, id, instancecount);
}
void glBufferStorageExternalEXT(GLenum target, GLintptr offset, GLsizeiptr size, GLeglClientBufferEXT clientBuffer, GLbitfield flags) {
	static const auto glBufferStorageExternalEXT_ = getFunction<void, GLenum, GLintptr, GLsizeiptr, GLeglClientBufferEXT, GLbitfield>("glBufferStorageExternalEXT");
	assert(glBufferStorageExternalEXT_ != nullptr);
	return glBufferStorageExternalEXT_(target, offset, size, clientBuffer, flags);
}
void glNamedBufferStorageExternalEXT(GLuint buffer, GLintptr offset, GLsizeiptr size, GLeglClientBufferEXT clientBuffer, GLbitfield flags) {
	static const auto glNamedBufferStorageExternalEXT_ = getFunction<void, GLuint, GLintptr, GLsizeiptr, GLeglClientBufferEXT, GLbitfield>("glNamedBufferStorageExternalEXT");
	assert(glNamedBufferStorageExternalEXT_ != nullptr);
	return glNamedBufferStorageExternalEXT_(buffer, offset, size, clientBuffer, flags);
}
void glFramebufferTextureEXT(GLenum target, GLenum attachment, GLuint texture, GLint level) {
	static const auto glFramebufferTextureEXT_ = getFunction<void, GLenum, GLenum, GLuint, GLint>("glFramebufferTextureEXT");
	assert(glFramebufferTextureEXT_ != nullptr);
	return glFramebufferTextureEXT_(target, attachment, texture, level);
}
void glVertexAttribDivisorEXT(GLuint index, GLuint divisor) {
	static const auto glVertexAttribDivisorEXT_ = getFunction<void, GLuint, GLuint>("glVertexAttribDivisorEXT");
	assert(glVertexAttribDivisorEXT_ != nullptr);
	return glVertexAttribDivisorEXT_(index, divisor);
}
void * glMapBufferRangeEXT(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access) {
	static const auto glMapBufferRangeEXT_ = getFunction<void *, GLenum, GLintptr, GLsizeiptr, GLbitfield>("glMapBufferRangeEXT");
	assert(glMapBufferRangeEXT_ != nullptr);
	return glMapBufferRangeEXT_(target, offset, length, access);
}
void glFlushMappedBufferRangeEXT(GLenum target, GLintptr offset, GLsizeiptr length) {
	static const auto glFlushMappedBufferRangeEXT_ = getFunction<void, GLenum, GLintptr, GLsizeiptr>("glFlushMappedBufferRangeEXT");
	assert(glFlushMappedBufferRangeEXT_ != nullptr);
	return glFlushMappedBufferRangeEXT_(target, offset, length);
}
void glGetUnsignedBytevEXT(GLenum pname, GLubyte * data) {
	static const auto glGetUnsignedBytevEXT_ = getFunction<void, GLenum, GLubyte *>("glGetUnsignedBytevEXT");
	assert(glGetUnsignedBytevEXT_ != nullptr);
	return glGetUnsignedBytevEXT_(pname, data);
}
void glGetUnsignedBytei_vEXT(GLenum target, GLuint index, GLubyte * data) {
	static const auto glGetUnsignedBytei_vEXT_ = getFunction<void, GLenum, GLuint, GLubyte *>("glGetUnsignedBytei_vEXT");
	assert(glGetUnsignedBytei_vEXT_ != nullptr);
	return glGetUnsignedBytei_vEXT_(target, index, data);
}
void glDeleteMemoryObjectsEXT(GLsizei n, GLuint const  * memoryObjects) {
	static const auto glDeleteMemoryObjectsEXT_ = getFunction<void, GLsizei, GLuint const  *>("glDeleteMemoryObjectsEXT");
	assert(glDeleteMemoryObjectsEXT_ != nullptr);
	return glDeleteMemoryObjectsEXT_(n, memoryObjects);
}
GLboolean glIsMemoryObjectEXT(GLuint memoryObject) {
	static const auto glIsMemoryObjectEXT_ = getFunction<GLboolean, GLuint>("glIsMemoryObjectEXT");
	assert(glIsMemoryObjectEXT_ != nullptr);
	return glIsMemoryObjectEXT_(memoryObject);
}
void glCreateMemoryObjectsEXT(GLsizei n, GLuint * memoryObjects) {
	static const auto glCreateMemoryObjectsEXT_ = getFunction<void, GLsizei, GLuint *>("glCreateMemoryObjectsEXT");
	assert(glCreateMemoryObjectsEXT_ != nullptr);
	return glCreateMemoryObjectsEXT_(n, memoryObjects);
}
void glMemoryObjectParameterivEXT(GLuint memoryObject, GLenum pname, GLint const  * params) {
	static const auto glMemoryObjectParameterivEXT_ = getFunction<void, GLuint, GLenum, GLint const  *>("glMemoryObjectParameterivEXT");
	assert(glMemoryObjectParameterivEXT_ != nullptr);
	return glMemoryObjectParameterivEXT_(memoryObject, pname, params);
}
void glGetMemoryObjectParameterivEXT(GLuint memoryObject, GLenum pname, GLint * params) {
	static const auto glGetMemoryObjectParameterivEXT_ = getFunction<void, GLuint, GLenum, GLint *>("glGetMemoryObjectParameterivEXT");
	assert(glGetMemoryObjectParameterivEXT_ != nullptr);
	return glGetMemoryObjectParameterivEXT_(memoryObject, pname, params);
}
void glTexStorageMem2DEXT(GLenum target, GLsizei levels, GLenum internalFormat, GLsizei width, GLsizei height, GLuint memory, GLuint64 offset) {
	static const auto glTexStorageMem2DEXT_ = getFunction<void, GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLuint, GLuint64>("glTexStorageMem2DEXT");
	assert(glTexStorageMem2DEXT_ != nullptr);
	return glTexStorageMem2DEXT_(target, levels, internalFormat, width, height, memory, offset);
}
void glTexStorageMem2DMultisampleEXT(GLenum target, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations, GLuint memory, GLuint64 offset) {
	static const auto glTexStorageMem2DMultisampleEXT_ = getFunction<void, GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLboolean, GLuint, GLuint64>("glTexStorageMem2DMultisampleEXT");
	assert(glTexStorageMem2DMultisampleEXT_ != nullptr);
	return glTexStorageMem2DMultisampleEXT_(target, samples, internalFormat, width, height, fixedSampleLocations, memory, offset);
}
void glTexStorageMem3DEXT(GLenum target, GLsizei levels, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLuint memory, GLuint64 offset) {
	static const auto glTexStorageMem3DEXT_ = getFunction<void, GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei, GLuint, GLuint64>("glTexStorageMem3DEXT");
	assert(glTexStorageMem3DEXT_ != nullptr);
	return glTexStorageMem3DEXT_(target, levels, internalFormat, width, height, depth, memory, offset);
}
void glTexStorageMem3DMultisampleEXT(GLenum target, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations, GLuint memory, GLuint64 offset) {
	static const auto glTexStorageMem3DMultisampleEXT_ = getFunction<void, GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei, GLboolean, GLuint, GLuint64>("glTexStorageMem3DMultisampleEXT");
	assert(glTexStorageMem3DMultisampleEXT_ != nullptr);
	return glTexStorageMem3DMultisampleEXT_(target, samples, internalFormat, width, height, depth, fixedSampleLocations, memory, offset);
}
void glBufferStorageMemEXT(GLenum target, GLsizeiptr size, GLuint memory, GLuint64 offset) {
	static const auto glBufferStorageMemEXT_ = getFunction<void, GLenum, GLsizeiptr, GLuint, GLuint64>("glBufferStorageMemEXT");
	assert(glBufferStorageMemEXT_ != nullptr);
	return glBufferStorageMemEXT_(target, size, memory, offset);
}
void glTextureStorageMem2DEXT(GLuint texture, GLsizei levels, GLenum internalFormat, GLsizei width, GLsizei height, GLuint memory, GLuint64 offset) {
	static const auto glTextureStorageMem2DEXT_ = getFunction<void, GLuint, GLsizei, GLenum, GLsizei, GLsizei, GLuint, GLuint64>("glTextureStorageMem2DEXT");
	assert(glTextureStorageMem2DEXT_ != nullptr);
	return glTextureStorageMem2DEXT_(texture, levels, internalFormat, width, height, memory, offset);
}
void glTextureStorageMem2DMultisampleEXT(GLuint texture, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations, GLuint memory, GLuint64 offset) {
	static const auto glTextureStorageMem2DMultisampleEXT_ = getFunction<void, GLuint, GLsizei, GLenum, GLsizei, GLsizei, GLboolean, GLuint, GLuint64>("glTextureStorageMem2DMultisampleEXT");
	assert(glTextureStorageMem2DMultisampleEXT_ != nullptr);
	return glTextureStorageMem2DMultisampleEXT_(texture, samples, internalFormat, width, height, fixedSampleLocations, memory, offset);
}
void glTextureStorageMem3DEXT(GLuint texture, GLsizei levels, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLuint memory, GLuint64 offset) {
	static const auto glTextureStorageMem3DEXT_ = getFunction<void, GLuint, GLsizei, GLenum, GLsizei, GLsizei, GLsizei, GLuint, GLuint64>("glTextureStorageMem3DEXT");
	assert(glTextureStorageMem3DEXT_ != nullptr);
	return glTextureStorageMem3DEXT_(texture, levels, internalFormat, width, height, depth, memory, offset);
}
void glTextureStorageMem3DMultisampleEXT(GLuint texture, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations, GLuint memory, GLuint64 offset) {
	static const auto glTextureStorageMem3DMultisampleEXT_ = getFunction<void, GLuint, GLsizei, GLenum, GLsizei, GLsizei, GLsizei, GLboolean, GLuint, GLuint64>("glTextureStorageMem3DMultisampleEXT");
	assert(glTextureStorageMem3DMultisampleEXT_ != nullptr);
	return glTextureStorageMem3DMultisampleEXT_(texture, samples, internalFormat, width, height, depth, fixedSampleLocations, memory, offset);
}
void glNamedBufferStorageMemEXT(GLuint buffer, GLsizeiptr size, GLuint memory, GLuint64 offset) {
	static const auto glNamedBufferStorageMemEXT_ = getFunction<void, GLuint, GLsizeiptr, GLuint, GLuint64>("glNamedBufferStorageMemEXT");
	assert(glNamedBufferStorageMemEXT_ != nullptr);
	return glNamedBufferStorageMemEXT_(buffer, size, memory, offset);
}
void glTexStorageMem1DEXT(GLenum target, GLsizei levels, GLenum internalFormat, GLsizei width, GLuint memory, GLuint64 offset) {
	static const auto glTexStorageMem1DEXT_ = getFunction<void, GLenum, GLsizei, GLenum, GLsizei, GLuint, GLuint64>("glTexStorageMem1DEXT");
	assert(glTexStorageMem1DEXT_ != nullptr);
	return glTexStorageMem1DEXT_(target, levels, internalFormat, width, memory, offset);
}
void glTextureStorageMem1DEXT(GLuint texture, GLsizei levels, GLenum internalFormat, GLsizei width, GLuint memory, GLuint64 offset) {
	static const auto glTextureStorageMem1DEXT_ = getFunction<void, GLuint, GLsizei, GLenum, GLsizei, GLuint, GLuint64>("glTextureStorageMem1DEXT");
	assert(glTextureStorageMem1DEXT_ != nullptr);
	return glTextureStorageMem1DEXT_(texture, levels, internalFormat, width, memory, offset);
}
void glImportMemoryFdEXT(GLuint memory, GLuint64 size, GLenum handleType, GLint fd) {
	static const auto glImportMemoryFdEXT_ = getFunction<void, GLuint, GLuint64, GLenum, GLint>("glImportMemoryFdEXT");
	assert(glImportMemoryFdEXT_ != nullptr);
	return glImportMemoryFdEXT_(memory, size, handleType, fd);
}
void glImportMemoryWin32HandleEXT(GLuint memory, GLuint64 size, GLenum handleType, void * handle) {
	static const auto glImportMemoryWin32HandleEXT_ = getFunction<void, GLuint, GLuint64, GLenum, void *>("glImportMemoryWin32HandleEXT");
	assert(glImportMemoryWin32HandleEXT_ != nullptr);
	return glImportMemoryWin32HandleEXT_(memory, size, handleType, handle);
}
void glImportMemoryWin32NameEXT(GLuint memory, GLuint64 size, GLenum handleType, const void * name) {
	static const auto glImportMemoryWin32NameEXT_ = getFunction<void, GLuint, GLuint64, GLenum, const void *>("glImportMemoryWin32NameEXT");
	assert(glImportMemoryWin32NameEXT_ != nullptr);
	return glImportMemoryWin32NameEXT_(memory, size, handleType, name);
}
void glMultiDrawArraysEXT(GLenum mode, GLint const  * first, GLsizei const  * count, GLsizei primcount) {
	static const auto glMultiDrawArraysEXT_ = getFunction<void, GLenum, GLint const  *, GLsizei const  *, GLsizei>("glMultiDrawArraysEXT");
	assert(glMultiDrawArraysEXT_ != nullptr);
	return glMultiDrawArraysEXT_(mode, first, count, primcount);
}
void glMultiDrawElementsEXT(GLenum mode, GLsizei const  * count, GLenum type, const void *const* indices, GLsizei primcount) {
	static const auto glMultiDrawElementsEXT_ = getFunction<void, GLenum, GLsizei const  *, GLenum, const void *const*, GLsizei>("glMultiDrawElementsEXT");
	assert(glMultiDrawElementsEXT_ != nullptr);
	return glMultiDrawElementsEXT_(mode, count, type, indices, primcount);
}
void glMultiDrawArraysIndirectEXT(GLenum mode, const void * indirect, GLsizei drawcount, GLsizei stride) {
	static const auto glMultiDrawArraysIndirectEXT_ = getFunction<void, GLenum, const void *, GLsizei, GLsizei>("glMultiDrawArraysIndirectEXT");
	assert(glMultiDrawArraysIndirectEXT_ != nullptr);
	return glMultiDrawArraysIndirectEXT_(mode, indirect, drawcount, stride);
}
void glMultiDrawElementsIndirectEXT(GLenum mode, GLenum type, const void * indirect, GLsizei drawcount, GLsizei stride) {
	static const auto glMultiDrawElementsIndirectEXT_ = getFunction<void, GLenum, GLenum, const void *, GLsizei, GLsizei>("glMultiDrawElementsIndirectEXT");
	assert(glMultiDrawElementsIndirectEXT_ != nullptr);
	return glMultiDrawElementsIndirectEXT_(mode, type, indirect, drawcount, stride);
}
void glRenderbufferStorageMultisampleEXT(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) {
	static const auto glRenderbufferStorageMultisampleEXT_ = getFunction<void, GLenum, GLsizei, GLenum, GLsizei, GLsizei>("glRenderbufferStorageMultisampleEXT");
	assert(glRenderbufferStorageMultisampleEXT_ != nullptr);
	return glRenderbufferStorageMultisampleEXT_(target, samples, internalformat, width, height);
}
void glFramebufferTexture2DMultisampleEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLsizei samples) {
	static const auto glFramebufferTexture2DMultisampleEXT_ = getFunction<void, GLenum, GLenum, GLenum, GLuint, GLint, GLsizei>("glFramebufferTexture2DMultisampleEXT");
	assert(glFramebufferTexture2DMultisampleEXT_ != nullptr);
	return glFramebufferTexture2DMultisampleEXT_(target, attachment, textarget, texture, level, samples);
}
void glReadBufferIndexedEXT(GLenum src, GLint index) {
	static const auto glReadBufferIndexedEXT_ = getFunction<void, GLenum, GLint>("glReadBufferIndexedEXT");
	assert(glReadBufferIndexedEXT_ != nullptr);
	return glReadBufferIndexedEXT_(src, index);
}
void glDrawBuffersIndexedEXT(GLint n, GLenum const  * location, GLint const  * indices) {
	static const auto glDrawBuffersIndexedEXT_ = getFunction<void, GLint, GLenum const  *, GLint const  *>("glDrawBuffersIndexedEXT");
	assert(glDrawBuffersIndexedEXT_ != nullptr);
	return glDrawBuffersIndexedEXT_(n, location, indices);
}
void glGetIntegeri_vEXT(GLenum target, GLuint index, GLint * data) {
	static const auto glGetIntegeri_vEXT_ = getFunction<void, GLenum, GLuint, GLint *>("glGetIntegeri_vEXT");
	assert(glGetIntegeri_vEXT_ != nullptr);
	return glGetIntegeri_vEXT_(target, index, data);
}
void glPolygonOffsetClampEXT(GLfloat factor, GLfloat units, GLfloat clamp) {
	static const auto glPolygonOffsetClampEXT_ = getFunction<void, GLfloat, GLfloat, GLfloat>("glPolygonOffsetClampEXT");
	assert(glPolygonOffsetClampEXT_ != nullptr);
	return glPolygonOffsetClampEXT_(factor, units, clamp);
}
void glPrimitiveBoundingBoxEXT(GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat minW, GLfloat maxX, GLfloat maxY, GLfloat maxZ, GLfloat maxW) {
	static const auto glPrimitiveBoundingBoxEXT_ = getFunction<void, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat>("glPrimitiveBoundingBoxEXT");
	assert(glPrimitiveBoundingBoxEXT_ != nullptr);
	return glPrimitiveBoundingBoxEXT_(minX, minY, minZ, minW, maxX, maxY, maxZ, maxW);
}
void glRasterSamplesEXT(GLuint samples, GLboolean fixedsamplelocations) {
	static const auto glRasterSamplesEXT_ = getFunction<void, GLuint, GLboolean>("glRasterSamplesEXT");
	assert(glRasterSamplesEXT_ != nullptr);
	return glRasterSamplesEXT_(samples, fixedsamplelocations);
}
GLenum glGetGraphicsResetStatusEXT() {
	static const auto glGetGraphicsResetStatusEXT_ = getFunction<GLenum>("glGetGraphicsResetStatusEXT");
	assert(glGetGraphicsResetStatusEXT_ != nullptr);
	return glGetGraphicsResetStatusEXT_();
}
void glReadnPixelsEXT(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void * data) {
	static const auto glReadnPixelsEXT_ = getFunction<void, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, GLsizei, void *>("glReadnPixelsEXT");
	assert(glReadnPixelsEXT_ != nullptr);
	return glReadnPixelsEXT_(x, y, width, height, format, type, bufSize, data);
}
void glGetnUniformfvEXT(GLuint program, GLint location, GLsizei bufSize, GLfloat * params) {
	static const auto glGetnUniformfvEXT_ = getFunction<void, GLuint, GLint, GLsizei, GLfloat *>("glGetnUniformfvEXT");
	assert(glGetnUniformfvEXT_ != nullptr);
	return glGetnUniformfvEXT_(program, location, bufSize, params);
}
void glGetnUniformivEXT(GLuint program, GLint location, GLsizei bufSize, GLint * params) {
	static const auto glGetnUniformivEXT_ = getFunction<void, GLuint, GLint, GLsizei, GLint *>("glGetnUniformivEXT");
	assert(glGetnUniformivEXT_ != nullptr);
	return glGetnUniformivEXT_(program, location, bufSize, params);
}
void glGenSemaphoresEXT(GLsizei n, GLuint * semaphores) {
	static const auto glGenSemaphoresEXT_ = getFunction<void, GLsizei, GLuint *>("glGenSemaphoresEXT");
	assert(glGenSemaphoresEXT_ != nullptr);
	return glGenSemaphoresEXT_(n, semaphores);
}
void glDeleteSemaphoresEXT(GLsizei n, GLuint const  * semaphores) {
	static const auto glDeleteSemaphoresEXT_ = getFunction<void, GLsizei, GLuint const  *>("glDeleteSemaphoresEXT");
	assert(glDeleteSemaphoresEXT_ != nullptr);
	return glDeleteSemaphoresEXT_(n, semaphores);
}
GLboolean glIsSemaphoreEXT(GLuint semaphore) {
	static const auto glIsSemaphoreEXT_ = getFunction<GLboolean, GLuint>("glIsSemaphoreEXT");
	assert(glIsSemaphoreEXT_ != nullptr);
	return glIsSemaphoreEXT_(semaphore);
}
void glSemaphoreParameterui64vEXT(GLuint semaphore, GLenum pname, GLuint64 const  * params) {
	static const auto glSemaphoreParameterui64vEXT_ = getFunction<void, GLuint, GLenum, GLuint64 const  *>("glSemaphoreParameterui64vEXT");
	assert(glSemaphoreParameterui64vEXT_ != nullptr);
	return glSemaphoreParameterui64vEXT_(semaphore, pname, params);
}
void glGetSemaphoreParameterui64vEXT(GLuint semaphore, GLenum pname, GLuint64 * params) {
	static const auto glGetSemaphoreParameterui64vEXT_ = getFunction<void, GLuint, GLenum, GLuint64 *>("glGetSemaphoreParameterui64vEXT");
	assert(glGetSemaphoreParameterui64vEXT_ != nullptr);
	return glGetSemaphoreParameterui64vEXT_(semaphore, pname, params);
}
void glWaitSemaphoreEXT(GLuint semaphore, GLuint numBufferBarriers, GLuint const  * buffers, GLuint numTextureBarriers, GLuint const  * textures, GLenum const  * srcLayouts) {
	static const auto glWaitSemaphoreEXT_ = getFunction<void, GLuint, GLuint, GLuint const  *, GLuint, GLuint const  *, GLenum const  *>("glWaitSemaphoreEXT");
	assert(glWaitSemaphoreEXT_ != nullptr);
	return glWaitSemaphoreEXT_(semaphore, numBufferBarriers, buffers, numTextureBarriers, textures, srcLayouts);
}
void glSignalSemaphoreEXT(GLuint semaphore, GLuint numBufferBarriers, GLuint const  * buffers, GLuint numTextureBarriers, GLuint const  * textures, GLenum const  * dstLayouts) {
	static const auto glSignalSemaphoreEXT_ = getFunction<void, GLuint, GLuint, GLuint const  *, GLuint, GLuint const  *, GLenum const  *>("glSignalSemaphoreEXT");
	assert(glSignalSemaphoreEXT_ != nullptr);
	return glSignalSemaphoreEXT_(semaphore, numBufferBarriers, buffers, numTextureBarriers, textures, dstLayouts);
}
void glImportSemaphoreFdEXT(GLuint semaphore, GLenum handleType, GLint fd) {
	static const auto glImportSemaphoreFdEXT_ = getFunction<void, GLuint, GLenum, GLint>("glImportSemaphoreFdEXT");
	assert(glImportSemaphoreFdEXT_ != nullptr);
	return glImportSemaphoreFdEXT_(semaphore, handleType, fd);
}
void glImportSemaphoreWin32HandleEXT(GLuint semaphore, GLenum handleType, void * handle) {
	static const auto glImportSemaphoreWin32HandleEXT_ = getFunction<void, GLuint, GLenum, void *>("glImportSemaphoreWin32HandleEXT");
	assert(glImportSemaphoreWin32HandleEXT_ != nullptr);
	return glImportSemaphoreWin32HandleEXT_(semaphore, handleType, handle);
}
void glImportSemaphoreWin32NameEXT(GLuint semaphore, GLenum handleType, const void * name) {
	static const auto glImportSemaphoreWin32NameEXT_ = getFunction<void, GLuint, GLenum, const void *>("glImportSemaphoreWin32NameEXT");
	assert(glImportSemaphoreWin32NameEXT_ != nullptr);
	return glImportSemaphoreWin32NameEXT_(semaphore, handleType, name);
}
void glUseShaderProgramEXT(GLenum type, GLuint program) {
	static const auto glUseShaderProgramEXT_ = getFunction<void, GLenum, GLuint>("glUseShaderProgramEXT");
	assert(glUseShaderProgramEXT_ != nullptr);
	return glUseShaderProgramEXT_(type, program);
}
void glActiveProgramEXT(GLuint program) {
	static const auto glActiveProgramEXT_ = getFunction<void, GLuint>("glActiveProgramEXT");
	assert(glActiveProgramEXT_ != nullptr);
	return glActiveProgramEXT_(program);
}
GLuint glCreateShaderProgramEXT(GLenum type, GLchar const  * string) {
	static const auto glCreateShaderProgramEXT_ = getFunction<GLuint, GLenum, GLchar const  *>("glCreateShaderProgramEXT");
	assert(glCreateShaderProgramEXT_ != nullptr);
	return glCreateShaderProgramEXT_(type, string);
}
void glActiveShaderProgramEXT(GLuint pipeline, GLuint program) {
	static const auto glActiveShaderProgramEXT_ = getFunction<void, GLuint, GLuint>("glActiveShaderProgramEXT");
	assert(glActiveShaderProgramEXT_ != nullptr);
	return glActiveShaderProgramEXT_(pipeline, program);
}
void glBindProgramPipelineEXT(GLuint pipeline) {
	static const auto glBindProgramPipelineEXT_ = getFunction<void, GLuint>("glBindProgramPipelineEXT");
	assert(glBindProgramPipelineEXT_ != nullptr);
	return glBindProgramPipelineEXT_(pipeline);
}
GLuint glCreateShaderProgramvEXT(GLenum type, GLsizei count, GLchar const  ** strings) {
	static const auto glCreateShaderProgramvEXT_ = getFunction<GLuint, GLenum, GLsizei, GLchar const  **>("glCreateShaderProgramvEXT");
	assert(glCreateShaderProgramvEXT_ != nullptr);
	return glCreateShaderProgramvEXT_(type, count, strings);
}
void glDeleteProgramPipelinesEXT(GLsizei n, GLuint const  * pipelines) {
	static const auto glDeleteProgramPipelinesEXT_ = getFunction<void, GLsizei, GLuint const  *>("glDeleteProgramPipelinesEXT");
	assert(glDeleteProgramPipelinesEXT_ != nullptr);
	return glDeleteProgramPipelinesEXT_(n, pipelines);
}
void glGenProgramPipelinesEXT(GLsizei n, GLuint * pipelines) {
	static const auto glGenProgramPipelinesEXT_ = getFunction<void, GLsizei, GLuint *>("glGenProgramPipelinesEXT");
	assert(glGenProgramPipelinesEXT_ != nullptr);
	return glGenProgramPipelinesEXT_(n, pipelines);
}
void glGetProgramPipelineInfoLogEXT(GLuint pipeline, GLsizei bufSize, GLsizei * length, GLchar * infoLog) {
	static const auto glGetProgramPipelineInfoLogEXT_ = getFunction<void, GLuint, GLsizei, GLsizei *, GLchar *>("glGetProgramPipelineInfoLogEXT");
	assert(glGetProgramPipelineInfoLogEXT_ != nullptr);
	return glGetProgramPipelineInfoLogEXT_(pipeline, bufSize, length, infoLog);
}
void glGetProgramPipelineivEXT(GLuint pipeline, GLenum pname, GLint * params) {
	static const auto glGetProgramPipelineivEXT_ = getFunction<void, GLuint, GLenum, GLint *>("glGetProgramPipelineivEXT");
	assert(glGetProgramPipelineivEXT_ != nullptr);
	return glGetProgramPipelineivEXT_(pipeline, pname, params);
}
GLboolean glIsProgramPipelineEXT(GLuint pipeline) {
	static const auto glIsProgramPipelineEXT_ = getFunction<GLboolean, GLuint>("glIsProgramPipelineEXT");
	assert(glIsProgramPipelineEXT_ != nullptr);
	return glIsProgramPipelineEXT_(pipeline);
}
void glProgramParameteriEXT(GLuint program, GLenum pname, GLint value) {
	static const auto glProgramParameteriEXT_ = getFunction<void, GLuint, GLenum, GLint>("glProgramParameteriEXT");
	assert(glProgramParameteriEXT_ != nullptr);
	return glProgramParameteriEXT_(program, pname, value);
}
void glProgramUniform1fEXT(GLuint program, GLint location, GLfloat v0) {
	static const auto glProgramUniform1fEXT_ = getFunction<void, GLuint, GLint, GLfloat>("glProgramUniform1fEXT");
	assert(glProgramUniform1fEXT_ != nullptr);
	return glProgramUniform1fEXT_(program, location, v0);
}
void glProgramUniform1fvEXT(GLuint program, GLint location, GLsizei count, GLfloat const  * value) {
	static const auto glProgramUniform1fvEXT_ = getFunction<void, GLuint, GLint, GLsizei, GLfloat const  *>("glProgramUniform1fvEXT");
	assert(glProgramUniform1fvEXT_ != nullptr);
	return glProgramUniform1fvEXT_(program, location, count, value);
}
void glProgramUniform1iEXT(GLuint program, GLint location, GLint v0) {
	static const auto glProgramUniform1iEXT_ = getFunction<void, GLuint, GLint, GLint>("glProgramUniform1iEXT");
	assert(glProgramUniform1iEXT_ != nullptr);
	return glProgramUniform1iEXT_(program, location, v0);
}
void glProgramUniform1ivEXT(GLuint program, GLint location, GLsizei count, GLint const  * value) {
	static const auto glProgramUniform1ivEXT_ = getFunction<void, GLuint, GLint, GLsizei, GLint const  *>("glProgramUniform1ivEXT");
	assert(glProgramUniform1ivEXT_ != nullptr);
	return glProgramUniform1ivEXT_(program, location, count, value);
}
void glProgramUniform2fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1) {
	static const auto glProgramUniform2fEXT_ = getFunction<void, GLuint, GLint, GLfloat, GLfloat>("glProgramUniform2fEXT");
	assert(glProgramUniform2fEXT_ != nullptr);
	return glProgramUniform2fEXT_(program, location, v0, v1);
}
void glProgramUniform2fvEXT(GLuint program, GLint location, GLsizei count, GLfloat const  * value) {
	static const auto glProgramUniform2fvEXT_ = getFunction<void, GLuint, GLint, GLsizei, GLfloat const  *>("glProgramUniform2fvEXT");
	assert(glProgramUniform2fvEXT_ != nullptr);
	return glProgramUniform2fvEXT_(program, location, count, value);
}
void glProgramUniform2iEXT(GLuint program, GLint location, GLint v0, GLint v1) {
	static const auto glProgramUniform2iEXT_ = getFunction<void, GLuint, GLint, GLint, GLint>("glProgramUniform2iEXT");
	assert(glProgramUniform2iEXT_ != nullptr);
	return glProgramUniform2iEXT_(program, location, v0, v1);
}
void glProgramUniform2ivEXT(GLuint program, GLint location, GLsizei count, GLint const  * value) {
	static const auto glProgramUniform2ivEXT_ = getFunction<void, GLuint, GLint, GLsizei, GLint const  *>("glProgramUniform2ivEXT");
	assert(glProgramUniform2ivEXT_ != nullptr);
	return glProgramUniform2ivEXT_(program, location, count, value);
}
void glProgramUniform3fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2) {
	static const auto glProgramUniform3fEXT_ = getFunction<void, GLuint, GLint, GLfloat, GLfloat, GLfloat>("glProgramUniform3fEXT");
	assert(glProgramUniform3fEXT_ != nullptr);
	return glProgramUniform3fEXT_(program, location, v0, v1, v2);
}
void glProgramUniform3fvEXT(GLuint program, GLint location, GLsizei count, GLfloat const  * value) {
	static const auto glProgramUniform3fvEXT_ = getFunction<void, GLuint, GLint, GLsizei, GLfloat const  *>("glProgramUniform3fvEXT");
	assert(glProgramUniform3fvEXT_ != nullptr);
	return glProgramUniform3fvEXT_(program, location, count, value);
}
void glProgramUniform3iEXT(GLuint program, GLint location, GLint v0, GLint v1, GLint v2) {
	static const auto glProgramUniform3iEXT_ = getFunction<void, GLuint, GLint, GLint, GLint, GLint>("glProgramUniform3iEXT");
	assert(glProgramUniform3iEXT_ != nullptr);
	return glProgramUniform3iEXT_(program, location, v0, v1, v2);
}
void glProgramUniform3ivEXT(GLuint program, GLint location, GLsizei count, GLint const  * value) {
	static const auto glProgramUniform3ivEXT_ = getFunction<void, GLuint, GLint, GLsizei, GLint const  *>("glProgramUniform3ivEXT");
	assert(glProgramUniform3ivEXT_ != nullptr);
	return glProgramUniform3ivEXT_(program, location, count, value);
}
void glProgramUniform4fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {
	static const auto glProgramUniform4fEXT_ = getFunction<void, GLuint, GLint, GLfloat, GLfloat, GLfloat, GLfloat>("glProgramUniform4fEXT");
	assert(glProgramUniform4fEXT_ != nullptr);
	return glProgramUniform4fEXT_(program, location, v0, v1, v2, v3);
}
void glProgramUniform4fvEXT(GLuint program, GLint location, GLsizei count, GLfloat const  * value) {
	static const auto glProgramUniform4fvEXT_ = getFunction<void, GLuint, GLint, GLsizei, GLfloat const  *>("glProgramUniform4fvEXT");
	assert(glProgramUniform4fvEXT_ != nullptr);
	return glProgramUniform4fvEXT_(program, location, count, value);
}
void glProgramUniform4iEXT(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3) {
	static const auto glProgramUniform4iEXT_ = getFunction<void, GLuint, GLint, GLint, GLint, GLint, GLint>("glProgramUniform4iEXT");
	assert(glProgramUniform4iEXT_ != nullptr);
	return glProgramUniform4iEXT_(program, location, v0, v1, v2, v3);
}
void glProgramUniform4ivEXT(GLuint program, GLint location, GLsizei count, GLint const  * value) {
	static const auto glProgramUniform4ivEXT_ = getFunction<void, GLuint, GLint, GLsizei, GLint const  *>("glProgramUniform4ivEXT");
	assert(glProgramUniform4ivEXT_ != nullptr);
	return glProgramUniform4ivEXT_(program, location, count, value);
}
void glProgramUniformMatrix2fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value) {
	static const auto glProgramUniformMatrix2fvEXT_ = getFunction<void, GLuint, GLint, GLsizei, GLboolean, GLfloat const  *>("glProgramUniformMatrix2fvEXT");
	assert(glProgramUniformMatrix2fvEXT_ != nullptr);
	return glProgramUniformMatrix2fvEXT_(program, location, count, transpose, value);
}
void glProgramUniformMatrix3fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value) {
	static const auto glProgramUniformMatrix3fvEXT_ = getFunction<void, GLuint, GLint, GLsizei, GLboolean, GLfloat const  *>("glProgramUniformMatrix3fvEXT");
	assert(glProgramUniformMatrix3fvEXT_ != nullptr);
	return glProgramUniformMatrix3fvEXT_(program, location, count, transpose, value);
}
void glProgramUniformMatrix4fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value) {
	static const auto glProgramUniformMatrix4fvEXT_ = getFunction<void, GLuint, GLint, GLsizei, GLboolean, GLfloat const  *>("glProgramUniformMatrix4fvEXT");
	assert(glProgramUniformMatrix4fvEXT_ != nullptr);
	return glProgramUniformMatrix4fvEXT_(program, location, count, transpose, value);
}
void glUseProgramStagesEXT(GLuint pipeline, GLbitfield stages, GLuint program) {
	static const auto glUseProgramStagesEXT_ = getFunction<void, GLuint, GLbitfield, GLuint>("glUseProgramStagesEXT");
	assert(glUseProgramStagesEXT_ != nullptr);
	return glUseProgramStagesEXT_(pipeline, stages, program);
}
void glValidateProgramPipelineEXT(GLuint pipeline) {
	static const auto glValidateProgramPipelineEXT_ = getFunction<void, GLuint>("glValidateProgramPipelineEXT");
	assert(glValidateProgramPipelineEXT_ != nullptr);
	return glValidateProgramPipelineEXT_(pipeline);
}
void glProgramUniform1uiEXT(GLuint program, GLint location, GLuint v0) {
	static const auto glProgramUniform1uiEXT_ = getFunction<void, GLuint, GLint, GLuint>("glProgramUniform1uiEXT");
	assert(glProgramUniform1uiEXT_ != nullptr);
	return glProgramUniform1uiEXT_(program, location, v0);
}
void glProgramUniform2uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1) {
	static const auto glProgramUniform2uiEXT_ = getFunction<void, GLuint, GLint, GLuint, GLuint>("glProgramUniform2uiEXT");
	assert(glProgramUniform2uiEXT_ != nullptr);
	return glProgramUniform2uiEXT_(program, location, v0, v1);
}
void glProgramUniform3uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2) {
	static const auto glProgramUniform3uiEXT_ = getFunction<void, GLuint, GLint, GLuint, GLuint, GLuint>("glProgramUniform3uiEXT");
	assert(glProgramUniform3uiEXT_ != nullptr);
	return glProgramUniform3uiEXT_(program, location, v0, v1, v2);
}
void glProgramUniform4uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) {
	static const auto glProgramUniform4uiEXT_ = getFunction<void, GLuint, GLint, GLuint, GLuint, GLuint, GLuint>("glProgramUniform4uiEXT");
	assert(glProgramUniform4uiEXT_ != nullptr);
	return glProgramUniform4uiEXT_(program, location, v0, v1, v2, v3);
}
void glProgramUniform1uivEXT(GLuint program, GLint location, GLsizei count, GLuint const  * value) {
	static const auto glProgramUniform1uivEXT_ = getFunction<void, GLuint, GLint, GLsizei, GLuint const  *>("glProgramUniform1uivEXT");
	assert(glProgramUniform1uivEXT_ != nullptr);
	return glProgramUniform1uivEXT_(program, location, count, value);
}
void glProgramUniform2uivEXT(GLuint program, GLint location, GLsizei count, GLuint const  * value) {
	static const auto glProgramUniform2uivEXT_ = getFunction<void, GLuint, GLint, GLsizei, GLuint const  *>("glProgramUniform2uivEXT");
	assert(glProgramUniform2uivEXT_ != nullptr);
	return glProgramUniform2uivEXT_(program, location, count, value);
}
void glProgramUniform3uivEXT(GLuint program, GLint location, GLsizei count, GLuint const  * value) {
	static const auto glProgramUniform3uivEXT_ = getFunction<void, GLuint, GLint, GLsizei, GLuint const  *>("glProgramUniform3uivEXT");
	assert(glProgramUniform3uivEXT_ != nullptr);
	return glProgramUniform3uivEXT_(program, location, count, value);
}
void glProgramUniform4uivEXT(GLuint program, GLint location, GLsizei count, GLuint const  * value) {
	static const auto glProgramUniform4uivEXT_ = getFunction<void, GLuint, GLint, GLsizei, GLuint const  *>("glProgramUniform4uivEXT");
	assert(glProgramUniform4uivEXT_ != nullptr);
	return glProgramUniform4uivEXT_(program, location, count, value);
}
void glProgramUniformMatrix2x3fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value) {
	static const auto glProgramUniformMatrix2x3fvEXT_ = getFunction<void, GLuint, GLint, GLsizei, GLboolean, GLfloat const  *>("glProgramUniformMatrix2x3fvEXT");
	assert(glProgramUniformMatrix2x3fvEXT_ != nullptr);
	return glProgramUniformMatrix2x3fvEXT_(program, location, count, transpose, value);
}
void glProgramUniformMatrix3x2fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value) {
	static const auto glProgramUniformMatrix3x2fvEXT_ = getFunction<void, GLuint, GLint, GLsizei, GLboolean, GLfloat const  *>("glProgramUniformMatrix3x2fvEXT");
	assert(glProgramUniformMatrix3x2fvEXT_ != nullptr);
	return glProgramUniformMatrix3x2fvEXT_(program, location, count, transpose, value);
}
void glProgramUniformMatrix2x4fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value) {
	static const auto glProgramUniformMatrix2x4fvEXT_ = getFunction<void, GLuint, GLint, GLsizei, GLboolean, GLfloat const  *>("glProgramUniformMatrix2x4fvEXT");
	assert(glProgramUniformMatrix2x4fvEXT_ != nullptr);
	return glProgramUniformMatrix2x4fvEXT_(program, location, count, transpose, value);
}
void glProgramUniformMatrix4x2fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value) {
	static const auto glProgramUniformMatrix4x2fvEXT_ = getFunction<void, GLuint, GLint, GLsizei, GLboolean, GLfloat const  *>("glProgramUniformMatrix4x2fvEXT");
	assert(glProgramUniformMatrix4x2fvEXT_ != nullptr);
	return glProgramUniformMatrix4x2fvEXT_(program, location, count, transpose, value);
}
void glProgramUniformMatrix3x4fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value) {
	static const auto glProgramUniformMatrix3x4fvEXT_ = getFunction<void, GLuint, GLint, GLsizei, GLboolean, GLfloat const  *>("glProgramUniformMatrix3x4fvEXT");
	assert(glProgramUniformMatrix3x4fvEXT_ != nullptr);
	return glProgramUniformMatrix3x4fvEXT_(program, location, count, transpose, value);
}
void glProgramUniformMatrix4x3fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value) {
	static const auto glProgramUniformMatrix4x3fvEXT_ = getFunction<void, GLuint, GLint, GLsizei, GLboolean, GLfloat const  *>("glProgramUniformMatrix4x3fvEXT");
	assert(glProgramUniformMatrix4x3fvEXT_ != nullptr);
	return glProgramUniformMatrix4x3fvEXT_(program, location, count, transpose, value);
}
void glFramebufferFetchBarrierEXT() {
	static const auto glFramebufferFetchBarrierEXT_ = getFunction<void>("glFramebufferFetchBarrierEXT");
	assert(glFramebufferFetchBarrierEXT_ != nullptr);
	return glFramebufferFetchBarrierEXT_();
}
void glFramebufferPixelLocalStorageSizeEXT(GLuint target, GLsizei size) {
	static const auto glFramebufferPixelLocalStorageSizeEXT_ = getFunction<void, GLuint, GLsizei>("glFramebufferPixelLocalStorageSizeEXT");
	assert(glFramebufferPixelLocalStorageSizeEXT_ != nullptr);
	return glFramebufferPixelLocalStorageSizeEXT_(target, size);
}
GLsizei glGetFramebufferPixelLocalStorageSizeEXT(GLuint target) {
	static const auto glGetFramebufferPixelLocalStorageSizeEXT_ = getFunction<GLsizei, GLuint>("glGetFramebufferPixelLocalStorageSizeEXT");
	assert(glGetFramebufferPixelLocalStorageSizeEXT_ != nullptr);
	return glGetFramebufferPixelLocalStorageSizeEXT_(target);
}
void glClearPixelLocalStorageuiEXT(GLsizei offset, GLsizei n, GLuint const  * values) {
	static const auto glClearPixelLocalStorageuiEXT_ = getFunction<void, GLsizei, GLsizei, GLuint const  *>("glClearPixelLocalStorageuiEXT");
	assert(glClearPixelLocalStorageuiEXT_ != nullptr);
	return glClearPixelLocalStorageuiEXT_(offset, n, values);
}
void glTexPageCommitmentEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit) {
	static const auto glTexPageCommitmentEXT_ = getFunction<void, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLboolean>("glTexPageCommitmentEXT");
	assert(glTexPageCommitmentEXT_ != nullptr);
	return glTexPageCommitmentEXT_(target, level, xoffset, yoffset, zoffset, width, height, depth, commit);
}
void glPatchParameteriEXT(GLenum pname, GLint value) {
	static const auto glPatchParameteriEXT_ = getFunction<void, GLenum, GLint>("glPatchParameteriEXT");
	assert(glPatchParameteriEXT_ != nullptr);
	return glPatchParameteriEXT_(pname, value);
}
void glTexParameterIivEXT(GLenum target, GLenum pname, GLint const  * params) {
	static const auto glTexParameterIivEXT_ = getFunction<void, GLenum, GLenum, GLint const  *>("glTexParameterIivEXT");
	assert(glTexParameterIivEXT_ != nullptr);
	return glTexParameterIivEXT_(target, pname, params);
}
void glTexParameterIuivEXT(GLenum target, GLenum pname, GLuint const  * params) {
	static const auto glTexParameterIuivEXT_ = getFunction<void, GLenum, GLenum, GLuint const  *>("glTexParameterIuivEXT");
	assert(glTexParameterIuivEXT_ != nullptr);
	return glTexParameterIuivEXT_(target, pname, params);
}
void glGetTexParameterIivEXT(GLenum target, GLenum pname, GLint * params) {
	static const auto glGetTexParameterIivEXT_ = getFunction<void, GLenum, GLenum, GLint *>("glGetTexParameterIivEXT");
	assert(glGetTexParameterIivEXT_ != nullptr);
	return glGetTexParameterIivEXT_(target, pname, params);
}
void glGetTexParameterIuivEXT(GLenum target, GLenum pname, GLuint * params) {
	static const auto glGetTexParameterIuivEXT_ = getFunction<void, GLenum, GLenum, GLuint *>("glGetTexParameterIuivEXT");
	assert(glGetTexParameterIuivEXT_ != nullptr);
	return glGetTexParameterIuivEXT_(target, pname, params);
}
void glSamplerParameterIivEXT(GLuint sampler, GLenum pname, GLint const  * param) {
	static const auto glSamplerParameterIivEXT_ = getFunction<void, GLuint, GLenum, GLint const  *>("glSamplerParameterIivEXT");
	assert(glSamplerParameterIivEXT_ != nullptr);
	return glSamplerParameterIivEXT_(sampler, pname, param);
}
void glSamplerParameterIuivEXT(GLuint sampler, GLenum pname, GLuint const  * param) {
	static const auto glSamplerParameterIuivEXT_ = getFunction<void, GLuint, GLenum, GLuint const  *>("glSamplerParameterIuivEXT");
	assert(glSamplerParameterIuivEXT_ != nullptr);
	return glSamplerParameterIuivEXT_(sampler, pname, param);
}
void glGetSamplerParameterIivEXT(GLuint sampler, GLenum pname, GLint * params) {
	static const auto glGetSamplerParameterIivEXT_ = getFunction<void, GLuint, GLenum, GLint *>("glGetSamplerParameterIivEXT");
	assert(glGetSamplerParameterIivEXT_ != nullptr);
	return glGetSamplerParameterIivEXT_(sampler, pname, params);
}
void glGetSamplerParameterIuivEXT(GLuint sampler, GLenum pname, GLuint * params) {
	static const auto glGetSamplerParameterIuivEXT_ = getFunction<void, GLuint, GLenum, GLuint *>("glGetSamplerParameterIuivEXT");
	assert(glGetSamplerParameterIuivEXT_ != nullptr);
	return glGetSamplerParameterIuivEXT_(sampler, pname, params);
}
void glTexBufferEXT(GLenum target, GLenum internalformat, GLuint buffer) {
	static const auto glTexBufferEXT_ = getFunction<void, GLenum, GLenum, GLuint>("glTexBufferEXT");
	assert(glTexBufferEXT_ != nullptr);
	return glTexBufferEXT_(target, internalformat, buffer);
}
void glTexBufferRangeEXT(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size) {
	static const auto glTexBufferRangeEXT_ = getFunction<void, GLenum, GLenum, GLuint, GLintptr, GLsizeiptr>("glTexBufferRangeEXT");
	assert(glTexBufferRangeEXT_ != nullptr);
	return glTexBufferRangeEXT_(target, internalformat, buffer, offset, size);
}
void glTexStorage1DEXT(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width) {
	static const auto glTexStorage1DEXT_ = getFunction<void, GLenum, GLsizei, GLenum, GLsizei>("glTexStorage1DEXT");
	assert(glTexStorage1DEXT_ != nullptr);
	return glTexStorage1DEXT_(target, levels, internalformat, width);
}
void glTexStorage2DEXT(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) {
	static const auto glTexStorage2DEXT_ = getFunction<void, GLenum, GLsizei, GLenum, GLsizei, GLsizei>("glTexStorage2DEXT");
	assert(glTexStorage2DEXT_ != nullptr);
	return glTexStorage2DEXT_(target, levels, internalformat, width, height);
}
void glTexStorage3DEXT(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) {
	static const auto glTexStorage3DEXT_ = getFunction<void, GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei>("glTexStorage3DEXT");
	assert(glTexStorage3DEXT_ != nullptr);
	return glTexStorage3DEXT_(target, levels, internalformat, width, height, depth);
}
void glTextureStorage1DEXT(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width) {
	static const auto glTextureStorage1DEXT_ = getFunction<void, GLuint, GLenum, GLsizei, GLenum, GLsizei>("glTextureStorage1DEXT");
	assert(glTextureStorage1DEXT_ != nullptr);
	return glTextureStorage1DEXT_(texture, target, levels, internalformat, width);
}
void glTextureStorage2DEXT(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) {
	static const auto glTextureStorage2DEXT_ = getFunction<void, GLuint, GLenum, GLsizei, GLenum, GLsizei, GLsizei>("glTextureStorage2DEXT");
	assert(glTextureStorage2DEXT_ != nullptr);
	return glTextureStorage2DEXT_(texture, target, levels, internalformat, width, height);
}
void glTextureStorage3DEXT(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) {
	static const auto glTextureStorage3DEXT_ = getFunction<void, GLuint, GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei>("glTextureStorage3DEXT");
	assert(glTextureStorage3DEXT_ != nullptr);
	return glTextureStorage3DEXT_(texture, target, levels, internalformat, width, height, depth);
}
void glTextureViewEXT(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers) {
	static const auto glTextureViewEXT_ = getFunction<void, GLuint, GLenum, GLuint, GLenum, GLuint, GLuint, GLuint, GLuint>("glTextureViewEXT");
	assert(glTextureViewEXT_ != nullptr);
	return glTextureViewEXT_(texture, target, origtexture, internalformat, minlevel, numlevels, minlayer, numlayers);
}
GLboolean glAcquireKeyedMutexWin32EXT(GLuint memory, GLuint64 key, GLuint timeout) {
	static const auto glAcquireKeyedMutexWin32EXT_ = getFunction<GLboolean, GLuint, GLuint64, GLuint>("glAcquireKeyedMutexWin32EXT");
	assert(glAcquireKeyedMutexWin32EXT_ != nullptr);
	return glAcquireKeyedMutexWin32EXT_(memory, key, timeout);
}
GLboolean glReleaseKeyedMutexWin32EXT(GLuint memory, GLuint64 key) {
	static const auto glReleaseKeyedMutexWin32EXT_ = getFunction<GLboolean, GLuint, GLuint64>("glReleaseKeyedMutexWin32EXT");
	assert(glReleaseKeyedMutexWin32EXT_ != nullptr);
	return glReleaseKeyedMutexWin32EXT_(memory, key);
}
void glWindowRectanglesEXT(GLenum mode, GLsizei count, GLint const  * box) {
	static const auto glWindowRectanglesEXT_ = getFunction<void, GLenum, GLsizei, GLint const  *>("glWindowRectanglesEXT");
	assert(glWindowRectanglesEXT_ != nullptr);
	return glWindowRectanglesEXT_(mode, count, box);
}
void glEGLImageTargetTexture2DOES(GLenum target, GLeglImageOES image) {
	static const auto glEGLImageTargetTexture2DOES_ = getFunction<void, GLenum, GLeglImageOES>("glEGLImageTargetTexture2DOES");
	assert(glEGLImageTargetTexture2DOES_ != nullptr);
	return glEGLImageTargetTexture2DOES_(target, image);
}
void glEGLImageTargetRenderbufferStorageOES(GLenum target, GLeglImageOES image) {
	static const auto glEGLImageTargetRenderbufferStorageOES_ = getFunction<void, GLenum, GLeglImageOES>("glEGLImageTargetRenderbufferStorageOES");
	assert(glEGLImageTargetRenderbufferStorageOES_ != nullptr);
	return glEGLImageTargetRenderbufferStorageOES_(target, image);
}
void glBlendEquationSeparateOES(GLenum modeRGB, GLenum modeAlpha) {
	static const auto glBlendEquationSeparateOES_ = getFunction<void, GLenum, GLenum>("glBlendEquationSeparateOES");
	assert(glBlendEquationSeparateOES_ != nullptr);
	return glBlendEquationSeparateOES_(modeRGB, modeAlpha);
}
void glBlendFuncSeparateOES(GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) {
	static const auto glBlendFuncSeparateOES_ = getFunction<void, GLenum, GLenum, GLenum, GLenum>("glBlendFuncSeparateOES");
	assert(glBlendFuncSeparateOES_ != nullptr);
	return glBlendFuncSeparateOES_(srcRGB, dstRGB, srcAlpha, dstAlpha);
}
void glBlendEquationOES(GLenum mode) {
	static const auto glBlendEquationOES_ = getFunction<void, GLenum>("glBlendEquationOES");
	assert(glBlendEquationOES_ != nullptr);
	return glBlendEquationOES_(mode);
}
void glMultiTexCoord1bOES(GLenum texture, GLbyte s) {
	static const auto glMultiTexCoord1bOES_ = getFunction<void, GLenum, GLbyte>("glMultiTexCoord1bOES");
	assert(glMultiTexCoord1bOES_ != nullptr);
	return glMultiTexCoord1bOES_(texture, s);
}
void glMultiTexCoord1bvOES(GLenum texture, GLbyte const  * coords) {
	static const auto glMultiTexCoord1bvOES_ = getFunction<void, GLenum, GLbyte const  *>("glMultiTexCoord1bvOES");
	assert(glMultiTexCoord1bvOES_ != nullptr);
	return glMultiTexCoord1bvOES_(texture, coords);
}
void glMultiTexCoord2bOES(GLenum texture, GLbyte s, GLbyte t) {
	static const auto glMultiTexCoord2bOES_ = getFunction<void, GLenum, GLbyte, GLbyte>("glMultiTexCoord2bOES");
	assert(glMultiTexCoord2bOES_ != nullptr);
	return glMultiTexCoord2bOES_(texture, s, t);
}
void glMultiTexCoord2bvOES(GLenum texture, GLbyte const  * coords) {
	static const auto glMultiTexCoord2bvOES_ = getFunction<void, GLenum, GLbyte const  *>("glMultiTexCoord2bvOES");
	assert(glMultiTexCoord2bvOES_ != nullptr);
	return glMultiTexCoord2bvOES_(texture, coords);
}
void glMultiTexCoord3bOES(GLenum texture, GLbyte s, GLbyte t, GLbyte r) {
	static const auto glMultiTexCoord3bOES_ = getFunction<void, GLenum, GLbyte, GLbyte, GLbyte>("glMultiTexCoord3bOES");
	assert(glMultiTexCoord3bOES_ != nullptr);
	return glMultiTexCoord3bOES_(texture, s, t, r);
}
void glMultiTexCoord3bvOES(GLenum texture, GLbyte const  * coords) {
	static const auto glMultiTexCoord3bvOES_ = getFunction<void, GLenum, GLbyte const  *>("glMultiTexCoord3bvOES");
	assert(glMultiTexCoord3bvOES_ != nullptr);
	return glMultiTexCoord3bvOES_(texture, coords);
}
void glMultiTexCoord4bOES(GLenum texture, GLbyte s, GLbyte t, GLbyte r, GLbyte q) {
	static const auto glMultiTexCoord4bOES_ = getFunction<void, GLenum, GLbyte, GLbyte, GLbyte, GLbyte>("glMultiTexCoord4bOES");
	assert(glMultiTexCoord4bOES_ != nullptr);
	return glMultiTexCoord4bOES_(texture, s, t, r, q);
}
void glMultiTexCoord4bvOES(GLenum texture, GLbyte const  * coords) {
	static const auto glMultiTexCoord4bvOES_ = getFunction<void, GLenum, GLbyte const  *>("glMultiTexCoord4bvOES");
	assert(glMultiTexCoord4bvOES_ != nullptr);
	return glMultiTexCoord4bvOES_(texture, coords);
}
void glTexCoord1bOES(GLbyte s) {
	static const auto glTexCoord1bOES_ = getFunction<void, GLbyte>("glTexCoord1bOES");
	assert(glTexCoord1bOES_ != nullptr);
	return glTexCoord1bOES_(s);
}
void glTexCoord1bvOES(GLbyte const  * coords) {
	static const auto glTexCoord1bvOES_ = getFunction<void, GLbyte const  *>("glTexCoord1bvOES");
	assert(glTexCoord1bvOES_ != nullptr);
	return glTexCoord1bvOES_(coords);
}
void glTexCoord2bOES(GLbyte s, GLbyte t) {
	static const auto glTexCoord2bOES_ = getFunction<void, GLbyte, GLbyte>("glTexCoord2bOES");
	assert(glTexCoord2bOES_ != nullptr);
	return glTexCoord2bOES_(s, t);
}
void glTexCoord2bvOES(GLbyte const  * coords) {
	static const auto glTexCoord2bvOES_ = getFunction<void, GLbyte const  *>("glTexCoord2bvOES");
	assert(glTexCoord2bvOES_ != nullptr);
	return glTexCoord2bvOES_(coords);
}
void glTexCoord3bOES(GLbyte s, GLbyte t, GLbyte r) {
	static const auto glTexCoord3bOES_ = getFunction<void, GLbyte, GLbyte, GLbyte>("glTexCoord3bOES");
	assert(glTexCoord3bOES_ != nullptr);
	return glTexCoord3bOES_(s, t, r);
}
void glTexCoord3bvOES(GLbyte const  * coords) {
	static const auto glTexCoord3bvOES_ = getFunction<void, GLbyte const  *>("glTexCoord3bvOES");
	assert(glTexCoord3bvOES_ != nullptr);
	return glTexCoord3bvOES_(coords);
}
void glTexCoord4bOES(GLbyte s, GLbyte t, GLbyte r, GLbyte q) {
	static const auto glTexCoord4bOES_ = getFunction<void, GLbyte, GLbyte, GLbyte, GLbyte>("glTexCoord4bOES");
	assert(glTexCoord4bOES_ != nullptr);
	return glTexCoord4bOES_(s, t, r, q);
}
void glTexCoord4bvOES(GLbyte const  * coords) {
	static const auto glTexCoord4bvOES_ = getFunction<void, GLbyte const  *>("glTexCoord4bvOES");
	assert(glTexCoord4bvOES_ != nullptr);
	return glTexCoord4bvOES_(coords);
}
void glVertex2bOES(GLbyte x, GLbyte y) {
	static const auto glVertex2bOES_ = getFunction<void, GLbyte, GLbyte>("glVertex2bOES");
	assert(glVertex2bOES_ != nullptr);
	return glVertex2bOES_(x, y);
}
void glVertex2bvOES(GLbyte const  * coords) {
	static const auto glVertex2bvOES_ = getFunction<void, GLbyte const  *>("glVertex2bvOES");
	assert(glVertex2bvOES_ != nullptr);
	return glVertex2bvOES_(coords);
}
void glVertex3bOES(GLbyte x, GLbyte y, GLbyte z) {
	static const auto glVertex3bOES_ = getFunction<void, GLbyte, GLbyte, GLbyte>("glVertex3bOES");
	assert(glVertex3bOES_ != nullptr);
	return glVertex3bOES_(x, y, z);
}
void glVertex3bvOES(GLbyte const  * coords) {
	static const auto glVertex3bvOES_ = getFunction<void, GLbyte const  *>("glVertex3bvOES");
	assert(glVertex3bvOES_ != nullptr);
	return glVertex3bvOES_(coords);
}
void glVertex4bOES(GLbyte x, GLbyte y, GLbyte z, GLbyte w) {
	static const auto glVertex4bOES_ = getFunction<void, GLbyte, GLbyte, GLbyte, GLbyte>("glVertex4bOES");
	assert(glVertex4bOES_ != nullptr);
	return glVertex4bOES_(x, y, z, w);
}
void glVertex4bvOES(GLbyte const  * coords) {
	static const auto glVertex4bvOES_ = getFunction<void, GLbyte const  *>("glVertex4bvOES");
	assert(glVertex4bvOES_ != nullptr);
	return glVertex4bvOES_(coords);
}
void glCopyImageSubDataOES(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth) {
	static const auto glCopyImageSubDataOES_ = getFunction<void, GLuint, GLenum, GLint, GLint, GLint, GLint, GLuint, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei>("glCopyImageSubDataOES");
	assert(glCopyImageSubDataOES_ != nullptr);
	return glCopyImageSubDataOES_(srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth);
}
void glEnableiOES(GLenum target, GLuint index) {
	static const auto glEnableiOES_ = getFunction<void, GLenum, GLuint>("glEnableiOES");
	assert(glEnableiOES_ != nullptr);
	return glEnableiOES_(target, index);
}
void glDisableiOES(GLenum target, GLuint index) {
	static const auto glDisableiOES_ = getFunction<void, GLenum, GLuint>("glDisableiOES");
	assert(glDisableiOES_ != nullptr);
	return glDisableiOES_(target, index);
}
void glBlendEquationiOES(GLuint buf, GLenum mode) {
	static const auto glBlendEquationiOES_ = getFunction<void, GLuint, GLenum>("glBlendEquationiOES");
	assert(glBlendEquationiOES_ != nullptr);
	return glBlendEquationiOES_(buf, mode);
}
void glBlendEquationSeparateiOES(GLuint buf, GLenum modeRGB, GLenum modeAlpha) {
	static const auto glBlendEquationSeparateiOES_ = getFunction<void, GLuint, GLenum, GLenum>("glBlendEquationSeparateiOES");
	assert(glBlendEquationSeparateiOES_ != nullptr);
	return glBlendEquationSeparateiOES_(buf, modeRGB, modeAlpha);
}
void glBlendFunciOES(GLuint buf, GLenum src, GLenum dst) {
	static const auto glBlendFunciOES_ = getFunction<void, GLuint, GLenum, GLenum>("glBlendFunciOES");
	assert(glBlendFunciOES_ != nullptr);
	return glBlendFunciOES_(buf, src, dst);
}
void glBlendFuncSeparateiOES(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) {
	static const auto glBlendFuncSeparateiOES_ = getFunction<void, GLuint, GLenum, GLenum, GLenum, GLenum>("glBlendFuncSeparateiOES");
	assert(glBlendFuncSeparateiOES_ != nullptr);
	return glBlendFuncSeparateiOES_(buf, srcRGB, dstRGB, srcAlpha, dstAlpha);
}
void glColorMaskiOES(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a) {
	static const auto glColorMaskiOES_ = getFunction<void, GLuint, GLboolean, GLboolean, GLboolean, GLboolean>("glColorMaskiOES");
	assert(glColorMaskiOES_ != nullptr);
	return glColorMaskiOES_(index, r, g, b, a);
}
GLboolean glIsEnablediOES(GLenum target, GLuint index) {
	static const auto glIsEnablediOES_ = getFunction<GLboolean, GLenum, GLuint>("glIsEnablediOES");
	assert(glIsEnablediOES_ != nullptr);
	return glIsEnablediOES_(target, index);
}
void glDrawElementsBaseVertexOES(GLenum mode, GLsizei count, GLenum type, const void * indices, GLint basevertex) {
	static const auto glDrawElementsBaseVertexOES_ = getFunction<void, GLenum, GLsizei, GLenum, const void *, GLint>("glDrawElementsBaseVertexOES");
	assert(glDrawElementsBaseVertexOES_ != nullptr);
	return glDrawElementsBaseVertexOES_(mode, count, type, indices, basevertex);
}
void glDrawRangeElementsBaseVertexOES(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices, GLint basevertex) {
	static const auto glDrawRangeElementsBaseVertexOES_ = getFunction<void, GLenum, GLuint, GLuint, GLsizei, GLenum, const void *, GLint>("glDrawRangeElementsBaseVertexOES");
	assert(glDrawRangeElementsBaseVertexOES_ != nullptr);
	return glDrawRangeElementsBaseVertexOES_(mode, start, end, count, type, indices, basevertex);
}
void glDrawElementsInstancedBaseVertexOES(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex) {
	static const auto glDrawElementsInstancedBaseVertexOES_ = getFunction<void, GLenum, GLsizei, GLenum, const void *, GLsizei, GLint>("glDrawElementsInstancedBaseVertexOES");
	assert(glDrawElementsInstancedBaseVertexOES_ != nullptr);
	return glDrawElementsInstancedBaseVertexOES_(mode, count, type, indices, instancecount, basevertex);
}
void glDrawTexsOES(GLshort x, GLshort y, GLshort z, GLshort width, GLshort height) {
	static const auto glDrawTexsOES_ = getFunction<void, GLshort, GLshort, GLshort, GLshort, GLshort>("glDrawTexsOES");
	assert(glDrawTexsOES_ != nullptr);
	return glDrawTexsOES_(x, y, z, width, height);
}
void glDrawTexiOES(GLint x, GLint y, GLint z, GLint width, GLint height) {
	static const auto glDrawTexiOES_ = getFunction<void, GLint, GLint, GLint, GLint, GLint>("glDrawTexiOES");
	assert(glDrawTexiOES_ != nullptr);
	return glDrawTexiOES_(x, y, z, width, height);
}
void glDrawTexxOES(GLfixed x, GLfixed y, GLfixed z, GLfixed width, GLfixed height) {
	static const auto glDrawTexxOES_ = getFunction<void, GLfixed, GLfixed, GLfixed, GLfixed, GLfixed>("glDrawTexxOES");
	assert(glDrawTexxOES_ != nullptr);
	return glDrawTexxOES_(x, y, z, width, height);
}
void glDrawTexsvOES(GLshort const  * coords) {
	static const auto glDrawTexsvOES_ = getFunction<void, GLshort const  *>("glDrawTexsvOES");
	assert(glDrawTexsvOES_ != nullptr);
	return glDrawTexsvOES_(coords);
}
void glDrawTexivOES(GLint const  * coords) {
	static const auto glDrawTexivOES_ = getFunction<void, GLint const  *>("glDrawTexivOES");
	assert(glDrawTexivOES_ != nullptr);
	return glDrawTexivOES_(coords);
}
void glDrawTexxvOES(GLfixed const  * coords) {
	static const auto glDrawTexxvOES_ = getFunction<void, GLfixed const  *>("glDrawTexxvOES");
	assert(glDrawTexxvOES_ != nullptr);
	return glDrawTexxvOES_(coords);
}
void glDrawTexfOES(GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height) {
	static const auto glDrawTexfOES_ = getFunction<void, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat>("glDrawTexfOES");
	assert(glDrawTexfOES_ != nullptr);
	return glDrawTexfOES_(x, y, z, width, height);
}
void glDrawTexfvOES(GLfloat const  * coords) {
	static const auto glDrawTexfvOES_ = getFunction<void, GLfloat const  *>("glDrawTexfvOES");
	assert(glDrawTexfvOES_ != nullptr);
	return glDrawTexfvOES_(coords);
}
void glAlphaFuncxOES(GLenum func, GLfixed ref) {
	static const auto glAlphaFuncxOES_ = getFunction<void, GLenum, GLfixed>("glAlphaFuncxOES");
	assert(glAlphaFuncxOES_ != nullptr);
	return glAlphaFuncxOES_(func, ref);
}
void glClearColorxOES(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha) {
	static const auto glClearColorxOES_ = getFunction<void, GLfixed, GLfixed, GLfixed, GLfixed>("glClearColorxOES");
	assert(glClearColorxOES_ != nullptr);
	return glClearColorxOES_(red, green, blue, alpha);
}
void glClearDepthxOES(GLfixed depth) {
	static const auto glClearDepthxOES_ = getFunction<void, GLfixed>("glClearDepthxOES");
	assert(glClearDepthxOES_ != nullptr);
	return glClearDepthxOES_(depth);
}
void glClipPlanexOES(GLenum plane, GLfixed const  * equation) {
	static const auto glClipPlanexOES_ = getFunction<void, GLenum, GLfixed const  *>("glClipPlanexOES");
	assert(glClipPlanexOES_ != nullptr);
	return glClipPlanexOES_(plane, equation);
}
void glColor4xOES(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha) {
	static const auto glColor4xOES_ = getFunction<void, GLfixed, GLfixed, GLfixed, GLfixed>("glColor4xOES");
	assert(glColor4xOES_ != nullptr);
	return glColor4xOES_(red, green, blue, alpha);
}
void glDepthRangexOES(GLfixed n, GLfixed f) {
	static const auto glDepthRangexOES_ = getFunction<void, GLfixed, GLfixed>("glDepthRangexOES");
	assert(glDepthRangexOES_ != nullptr);
	return glDepthRangexOES_(n, f);
}
void glFogxOES(GLenum pname, GLfixed param) {
	static const auto glFogxOES_ = getFunction<void, GLenum, GLfixed>("glFogxOES");
	assert(glFogxOES_ != nullptr);
	return glFogxOES_(pname, param);
}
void glFogxvOES(GLenum pname, GLfixed const  * param) {
	static const auto glFogxvOES_ = getFunction<void, GLenum, GLfixed const  *>("glFogxvOES");
	assert(glFogxvOES_ != nullptr);
	return glFogxvOES_(pname, param);
}
void glFrustumxOES(GLfixed l, GLfixed r, GLfixed b, GLfixed t, GLfixed n, GLfixed f) {
	static const auto glFrustumxOES_ = getFunction<void, GLfixed, GLfixed, GLfixed, GLfixed, GLfixed, GLfixed>("glFrustumxOES");
	assert(glFrustumxOES_ != nullptr);
	return glFrustumxOES_(l, r, b, t, n, f);
}
void glGetClipPlanexOES(GLenum plane, GLfixed * equation) {
	static const auto glGetClipPlanexOES_ = getFunction<void, GLenum, GLfixed *>("glGetClipPlanexOES");
	assert(glGetClipPlanexOES_ != nullptr);
	return glGetClipPlanexOES_(plane, equation);
}
void glGetFixedvOES(GLenum pname, GLfixed * params) {
	static const auto glGetFixedvOES_ = getFunction<void, GLenum, GLfixed *>("glGetFixedvOES");
	assert(glGetFixedvOES_ != nullptr);
	return glGetFixedvOES_(pname, params);
}
void glGetTexEnvxvOES(GLenum target, GLenum pname, GLfixed * params) {
	static const auto glGetTexEnvxvOES_ = getFunction<void, GLenum, GLenum, GLfixed *>("glGetTexEnvxvOES");
	assert(glGetTexEnvxvOES_ != nullptr);
	return glGetTexEnvxvOES_(target, pname, params);
}
void glGetTexParameterxvOES(GLenum target, GLenum pname, GLfixed * params) {
	static const auto glGetTexParameterxvOES_ = getFunction<void, GLenum, GLenum, GLfixed *>("glGetTexParameterxvOES");
	assert(glGetTexParameterxvOES_ != nullptr);
	return glGetTexParameterxvOES_(target, pname, params);
}
void glLightModelxOES(GLenum pname, GLfixed param) {
	static const auto glLightModelxOES_ = getFunction<void, GLenum, GLfixed>("glLightModelxOES");
	assert(glLightModelxOES_ != nullptr);
	return glLightModelxOES_(pname, param);
}
void glLightModelxvOES(GLenum pname, GLfixed const  * param) {
	static const auto glLightModelxvOES_ = getFunction<void, GLenum, GLfixed const  *>("glLightModelxvOES");
	assert(glLightModelxvOES_ != nullptr);
	return glLightModelxvOES_(pname, param);
}
void glLightxOES(GLenum light, GLenum pname, GLfixed param) {
	static const auto glLightxOES_ = getFunction<void, GLenum, GLenum, GLfixed>("glLightxOES");
	assert(glLightxOES_ != nullptr);
	return glLightxOES_(light, pname, param);
}
void glLightxvOES(GLenum light, GLenum pname, GLfixed const  * params) {
	static const auto glLightxvOES_ = getFunction<void, GLenum, GLenum, GLfixed const  *>("glLightxvOES");
	assert(glLightxvOES_ != nullptr);
	return glLightxvOES_(light, pname, params);
}
void glLineWidthxOES(GLfixed width) {
	static const auto glLineWidthxOES_ = getFunction<void, GLfixed>("glLineWidthxOES");
	assert(glLineWidthxOES_ != nullptr);
	return glLineWidthxOES_(width);
}
void glLoadMatrixxOES(GLfixed const  * m) {
	static const auto glLoadMatrixxOES_ = getFunction<void, GLfixed const  *>("glLoadMatrixxOES");
	assert(glLoadMatrixxOES_ != nullptr);
	return glLoadMatrixxOES_(m);
}
void glMaterialxOES(GLenum face, GLenum pname, GLfixed param) {
	static const auto glMaterialxOES_ = getFunction<void, GLenum, GLenum, GLfixed>("glMaterialxOES");
	assert(glMaterialxOES_ != nullptr);
	return glMaterialxOES_(face, pname, param);
}
void glMaterialxvOES(GLenum face, GLenum pname, GLfixed const  * param) {
	static const auto glMaterialxvOES_ = getFunction<void, GLenum, GLenum, GLfixed const  *>("glMaterialxvOES");
	assert(glMaterialxvOES_ != nullptr);
	return glMaterialxvOES_(face, pname, param);
}
void glMultMatrixxOES(GLfixed const  * m) {
	static const auto glMultMatrixxOES_ = getFunction<void, GLfixed const  *>("glMultMatrixxOES");
	assert(glMultMatrixxOES_ != nullptr);
	return glMultMatrixxOES_(m);
}
void glMultiTexCoord4xOES(GLenum texture, GLfixed s, GLfixed t, GLfixed r, GLfixed q) {
	static const auto glMultiTexCoord4xOES_ = getFunction<void, GLenum, GLfixed, GLfixed, GLfixed, GLfixed>("glMultiTexCoord4xOES");
	assert(glMultiTexCoord4xOES_ != nullptr);
	return glMultiTexCoord4xOES_(texture, s, t, r, q);
}
void glNormal3xOES(GLfixed nx, GLfixed ny, GLfixed nz) {
	static const auto glNormal3xOES_ = getFunction<void, GLfixed, GLfixed, GLfixed>("glNormal3xOES");
	assert(glNormal3xOES_ != nullptr);
	return glNormal3xOES_(nx, ny, nz);
}
void glOrthoxOES(GLfixed l, GLfixed r, GLfixed b, GLfixed t, GLfixed n, GLfixed f) {
	static const auto glOrthoxOES_ = getFunction<void, GLfixed, GLfixed, GLfixed, GLfixed, GLfixed, GLfixed>("glOrthoxOES");
	assert(glOrthoxOES_ != nullptr);
	return glOrthoxOES_(l, r, b, t, n, f);
}
void glPointParameterxvOES(GLenum pname, GLfixed const  * params) {
	static const auto glPointParameterxvOES_ = getFunction<void, GLenum, GLfixed const  *>("glPointParameterxvOES");
	assert(glPointParameterxvOES_ != nullptr);
	return glPointParameterxvOES_(pname, params);
}
void glPointSizexOES(GLfixed size) {
	static const auto glPointSizexOES_ = getFunction<void, GLfixed>("glPointSizexOES");
	assert(glPointSizexOES_ != nullptr);
	return glPointSizexOES_(size);
}
void glPolygonOffsetxOES(GLfixed factor, GLfixed units) {
	static const auto glPolygonOffsetxOES_ = getFunction<void, GLfixed, GLfixed>("glPolygonOffsetxOES");
	assert(glPolygonOffsetxOES_ != nullptr);
	return glPolygonOffsetxOES_(factor, units);
}
void glRotatexOES(GLfixed angle, GLfixed x, GLfixed y, GLfixed z) {
	static const auto glRotatexOES_ = getFunction<void, GLfixed, GLfixed, GLfixed, GLfixed>("glRotatexOES");
	assert(glRotatexOES_ != nullptr);
	return glRotatexOES_(angle, x, y, z);
}
void glScalexOES(GLfixed x, GLfixed y, GLfixed z) {
	static const auto glScalexOES_ = getFunction<void, GLfixed, GLfixed, GLfixed>("glScalexOES");
	assert(glScalexOES_ != nullptr);
	return glScalexOES_(x, y, z);
}
void glTexEnvxOES(GLenum target, GLenum pname, GLfixed param) {
	static const auto glTexEnvxOES_ = getFunction<void, GLenum, GLenum, GLfixed>("glTexEnvxOES");
	assert(glTexEnvxOES_ != nullptr);
	return glTexEnvxOES_(target, pname, param);
}
void glTexEnvxvOES(GLenum target, GLenum pname, GLfixed const  * params) {
	static const auto glTexEnvxvOES_ = getFunction<void, GLenum, GLenum, GLfixed const  *>("glTexEnvxvOES");
	assert(glTexEnvxvOES_ != nullptr);
	return glTexEnvxvOES_(target, pname, params);
}
void glTexParameterxOES(GLenum target, GLenum pname, GLfixed param) {
	static const auto glTexParameterxOES_ = getFunction<void, GLenum, GLenum, GLfixed>("glTexParameterxOES");
	assert(glTexParameterxOES_ != nullptr);
	return glTexParameterxOES_(target, pname, param);
}
void glTexParameterxvOES(GLenum target, GLenum pname, GLfixed const  * params) {
	static const auto glTexParameterxvOES_ = getFunction<void, GLenum, GLenum, GLfixed const  *>("glTexParameterxvOES");
	assert(glTexParameterxvOES_ != nullptr);
	return glTexParameterxvOES_(target, pname, params);
}
void glTranslatexOES(GLfixed x, GLfixed y, GLfixed z) {
	static const auto glTranslatexOES_ = getFunction<void, GLfixed, GLfixed, GLfixed>("glTranslatexOES");
	assert(glTranslatexOES_ != nullptr);
	return glTranslatexOES_(x, y, z);
}
void glGetLightxvOES(GLenum light, GLenum pname, GLfixed * params) {
	static const auto glGetLightxvOES_ = getFunction<void, GLenum, GLenum, GLfixed *>("glGetLightxvOES");
	assert(glGetLightxvOES_ != nullptr);
	return glGetLightxvOES_(light, pname, params);
}
void glGetMaterialxvOES(GLenum face, GLenum pname, GLfixed * params) {
	static const auto glGetMaterialxvOES_ = getFunction<void, GLenum, GLenum, GLfixed *>("glGetMaterialxvOES");
	assert(glGetMaterialxvOES_ != nullptr);
	return glGetMaterialxvOES_(face, pname, params);
}
void glPointParameterxOES(GLenum pname, GLfixed param) {
	static const auto glPointParameterxOES_ = getFunction<void, GLenum, GLfixed>("glPointParameterxOES");
	assert(glPointParameterxOES_ != nullptr);
	return glPointParameterxOES_(pname, param);
}
void glSampleCoveragexOES(GLclampx value, GLboolean invert) {
	static const auto glSampleCoveragexOES_ = getFunction<void, GLclampx, GLboolean>("glSampleCoveragexOES");
	assert(glSampleCoveragexOES_ != nullptr);
	return glSampleCoveragexOES_(value, invert);
}
void glAccumxOES(GLenum op, GLfixed value) {
	static const auto glAccumxOES_ = getFunction<void, GLenum, GLfixed>("glAccumxOES");
	assert(glAccumxOES_ != nullptr);
	return glAccumxOES_(op, value);
}
void glBitmapxOES(GLsizei width, GLsizei height, GLfixed xorig, GLfixed yorig, GLfixed xmove, GLfixed ymove, GLubyte const  * bitmap) {
	static const auto glBitmapxOES_ = getFunction<void, GLsizei, GLsizei, GLfixed, GLfixed, GLfixed, GLfixed, GLubyte const  *>("glBitmapxOES");
	assert(glBitmapxOES_ != nullptr);
	return glBitmapxOES_(width, height, xorig, yorig, xmove, ymove, bitmap);
}
void glBlendColorxOES(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha) {
	static const auto glBlendColorxOES_ = getFunction<void, GLfixed, GLfixed, GLfixed, GLfixed>("glBlendColorxOES");
	assert(glBlendColorxOES_ != nullptr);
	return glBlendColorxOES_(red, green, blue, alpha);
}
void glClearAccumxOES(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha) {
	static const auto glClearAccumxOES_ = getFunction<void, GLfixed, GLfixed, GLfixed, GLfixed>("glClearAccumxOES");
	assert(glClearAccumxOES_ != nullptr);
	return glClearAccumxOES_(red, green, blue, alpha);
}
void glColor3xOES(GLfixed red, GLfixed green, GLfixed blue) {
	static const auto glColor3xOES_ = getFunction<void, GLfixed, GLfixed, GLfixed>("glColor3xOES");
	assert(glColor3xOES_ != nullptr);
	return glColor3xOES_(red, green, blue);
}
void glColor3xvOES(GLfixed const  * components) {
	static const auto glColor3xvOES_ = getFunction<void, GLfixed const  *>("glColor3xvOES");
	assert(glColor3xvOES_ != nullptr);
	return glColor3xvOES_(components);
}
void glColor4xvOES(GLfixed const  * components) {
	static const auto glColor4xvOES_ = getFunction<void, GLfixed const  *>("glColor4xvOES");
	assert(glColor4xvOES_ != nullptr);
	return glColor4xvOES_(components);
}
void glConvolutionParameterxOES(GLenum target, GLenum pname, GLfixed param) {
	static const auto glConvolutionParameterxOES_ = getFunction<void, GLenum, GLenum, GLfixed>("glConvolutionParameterxOES");
	assert(glConvolutionParameterxOES_ != nullptr);
	return glConvolutionParameterxOES_(target, pname, param);
}
void glConvolutionParameterxvOES(GLenum target, GLenum pname, GLfixed const  * params) {
	static const auto glConvolutionParameterxvOES_ = getFunction<void, GLenum, GLenum, GLfixed const  *>("glConvolutionParameterxvOES");
	assert(glConvolutionParameterxvOES_ != nullptr);
	return glConvolutionParameterxvOES_(target, pname, params);
}
void glEvalCoord1xOES(GLfixed u) {
	static const auto glEvalCoord1xOES_ = getFunction<void, GLfixed>("glEvalCoord1xOES");
	assert(glEvalCoord1xOES_ != nullptr);
	return glEvalCoord1xOES_(u);
}
void glEvalCoord1xvOES(GLfixed const  * coords) {
	static const auto glEvalCoord1xvOES_ = getFunction<void, GLfixed const  *>("glEvalCoord1xvOES");
	assert(glEvalCoord1xvOES_ != nullptr);
	return glEvalCoord1xvOES_(coords);
}
void glEvalCoord2xOES(GLfixed u, GLfixed v) {
	static const auto glEvalCoord2xOES_ = getFunction<void, GLfixed, GLfixed>("glEvalCoord2xOES");
	assert(glEvalCoord2xOES_ != nullptr);
	return glEvalCoord2xOES_(u, v);
}
void glEvalCoord2xvOES(GLfixed const  * coords) {
	static const auto glEvalCoord2xvOES_ = getFunction<void, GLfixed const  *>("glEvalCoord2xvOES");
	assert(glEvalCoord2xvOES_ != nullptr);
	return glEvalCoord2xvOES_(coords);
}
void glFeedbackBufferxOES(GLsizei n, GLenum type, GLfixed const  * buffer) {
	static const auto glFeedbackBufferxOES_ = getFunction<void, GLsizei, GLenum, GLfixed const  *>("glFeedbackBufferxOES");
	assert(glFeedbackBufferxOES_ != nullptr);
	return glFeedbackBufferxOES_(n, type, buffer);
}
void glGetConvolutionParameterxvOES(GLenum target, GLenum pname, GLfixed * params) {
	static const auto glGetConvolutionParameterxvOES_ = getFunction<void, GLenum, GLenum, GLfixed *>("glGetConvolutionParameterxvOES");
	assert(glGetConvolutionParameterxvOES_ != nullptr);
	return glGetConvolutionParameterxvOES_(target, pname, params);
}
void glGetHistogramParameterxvOES(GLenum target, GLenum pname, GLfixed * params) {
	static const auto glGetHistogramParameterxvOES_ = getFunction<void, GLenum, GLenum, GLfixed *>("glGetHistogramParameterxvOES");
	assert(glGetHistogramParameterxvOES_ != nullptr);
	return glGetHistogramParameterxvOES_(target, pname, params);
}
void glGetLightxOES(GLenum light, GLenum pname, GLfixed * params) {
	static const auto glGetLightxOES_ = getFunction<void, GLenum, GLenum, GLfixed *>("glGetLightxOES");
	assert(glGetLightxOES_ != nullptr);
	return glGetLightxOES_(light, pname, params);
}
void glGetMapxvOES(GLenum target, GLenum query, GLfixed * v) {
	static const auto glGetMapxvOES_ = getFunction<void, GLenum, GLenum, GLfixed *>("glGetMapxvOES");
	assert(glGetMapxvOES_ != nullptr);
	return glGetMapxvOES_(target, query, v);
}
void glGetMaterialxOES(GLenum face, GLenum pname, GLfixed param) {
	static const auto glGetMaterialxOES_ = getFunction<void, GLenum, GLenum, GLfixed>("glGetMaterialxOES");
	assert(glGetMaterialxOES_ != nullptr);
	return glGetMaterialxOES_(face, pname, param);
}
void glGetPixelMapxv(GLenum map, GLint size, GLfixed * values) {
	static const auto glGetPixelMapxv_ = getFunction<void, GLenum, GLint, GLfixed *>("glGetPixelMapxv");
	assert(glGetPixelMapxv_ != nullptr);
	return glGetPixelMapxv_(map, size, values);
}
void glGetTexGenxvOES(GLenum coord, GLenum pname, GLfixed * params) {
	static const auto glGetTexGenxvOES_ = getFunction<void, GLenum, GLenum, GLfixed *>("glGetTexGenxvOES");
	assert(glGetTexGenxvOES_ != nullptr);
	return glGetTexGenxvOES_(coord, pname, params);
}
void glGetTexLevelParameterxvOES(GLenum target, GLint level, GLenum pname, GLfixed * params) {
	static const auto glGetTexLevelParameterxvOES_ = getFunction<void, GLenum, GLint, GLenum, GLfixed *>("glGetTexLevelParameterxvOES");
	assert(glGetTexLevelParameterxvOES_ != nullptr);
	return glGetTexLevelParameterxvOES_(target, level, pname, params);
}
void glIndexxOES(GLfixed component) {
	static const auto glIndexxOES_ = getFunction<void, GLfixed>("glIndexxOES");
	assert(glIndexxOES_ != nullptr);
	return glIndexxOES_(component);
}
void glIndexxvOES(GLfixed const  * component) {
	static const auto glIndexxvOES_ = getFunction<void, GLfixed const  *>("glIndexxvOES");
	assert(glIndexxvOES_ != nullptr);
	return glIndexxvOES_(component);
}
void glLoadTransposeMatrixxOES(GLfixed const  * m) {
	static const auto glLoadTransposeMatrixxOES_ = getFunction<void, GLfixed const  *>("glLoadTransposeMatrixxOES");
	assert(glLoadTransposeMatrixxOES_ != nullptr);
	return glLoadTransposeMatrixxOES_(m);
}
void glMap1xOES(GLenum target, GLfixed u1, GLfixed u2, GLint stride, GLint order, GLfixed points) {
	static const auto glMap1xOES_ = getFunction<void, GLenum, GLfixed, GLfixed, GLint, GLint, GLfixed>("glMap1xOES");
	assert(glMap1xOES_ != nullptr);
	return glMap1xOES_(target, u1, u2, stride, order, points);
}
void glMap2xOES(GLenum target, GLfixed u1, GLfixed u2, GLint ustride, GLint uorder, GLfixed v1, GLfixed v2, GLint vstride, GLint vorder, GLfixed points) {
	static const auto glMap2xOES_ = getFunction<void, GLenum, GLfixed, GLfixed, GLint, GLint, GLfixed, GLfixed, GLint, GLint, GLfixed>("glMap2xOES");
	assert(glMap2xOES_ != nullptr);
	return glMap2xOES_(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
}
void glMapGrid1xOES(GLint n, GLfixed u1, GLfixed u2) {
	static const auto glMapGrid1xOES_ = getFunction<void, GLint, GLfixed, GLfixed>("glMapGrid1xOES");
	assert(glMapGrid1xOES_ != nullptr);
	return glMapGrid1xOES_(n, u1, u2);
}
void glMapGrid2xOES(GLint n, GLfixed u1, GLfixed u2, GLfixed v1, GLfixed v2) {
	static const auto glMapGrid2xOES_ = getFunction<void, GLint, GLfixed, GLfixed, GLfixed, GLfixed>("glMapGrid2xOES");
	assert(glMapGrid2xOES_ != nullptr);
	return glMapGrid2xOES_(n, u1, u2, v1, v2);
}
void glMultTransposeMatrixxOES(GLfixed const  * m) {
	static const auto glMultTransposeMatrixxOES_ = getFunction<void, GLfixed const  *>("glMultTransposeMatrixxOES");
	assert(glMultTransposeMatrixxOES_ != nullptr);
	return glMultTransposeMatrixxOES_(m);
}
void glMultiTexCoord1xOES(GLenum texture, GLfixed s) {
	static const auto glMultiTexCoord1xOES_ = getFunction<void, GLenum, GLfixed>("glMultiTexCoord1xOES");
	assert(glMultiTexCoord1xOES_ != nullptr);
	return glMultiTexCoord1xOES_(texture, s);
}
void glMultiTexCoord1xvOES(GLenum texture, GLfixed const  * coords) {
	static const auto glMultiTexCoord1xvOES_ = getFunction<void, GLenum, GLfixed const  *>("glMultiTexCoord1xvOES");
	assert(glMultiTexCoord1xvOES_ != nullptr);
	return glMultiTexCoord1xvOES_(texture, coords);
}
void glMultiTexCoord2xOES(GLenum texture, GLfixed s, GLfixed t) {
	static const auto glMultiTexCoord2xOES_ = getFunction<void, GLenum, GLfixed, GLfixed>("glMultiTexCoord2xOES");
	assert(glMultiTexCoord2xOES_ != nullptr);
	return glMultiTexCoord2xOES_(texture, s, t);
}
void glMultiTexCoord2xvOES(GLenum texture, GLfixed const  * coords) {
	static const auto glMultiTexCoord2xvOES_ = getFunction<void, GLenum, GLfixed const  *>("glMultiTexCoord2xvOES");
	assert(glMultiTexCoord2xvOES_ != nullptr);
	return glMultiTexCoord2xvOES_(texture, coords);
}
void glMultiTexCoord3xOES(GLenum texture, GLfixed s, GLfixed t, GLfixed r) {
	static const auto glMultiTexCoord3xOES_ = getFunction<void, GLenum, GLfixed, GLfixed, GLfixed>("glMultiTexCoord3xOES");
	assert(glMultiTexCoord3xOES_ != nullptr);
	return glMultiTexCoord3xOES_(texture, s, t, r);
}
void glMultiTexCoord3xvOES(GLenum texture, GLfixed const  * coords) {
	static const auto glMultiTexCoord3xvOES_ = getFunction<void, GLenum, GLfixed const  *>("glMultiTexCoord3xvOES");
	assert(glMultiTexCoord3xvOES_ != nullptr);
	return glMultiTexCoord3xvOES_(texture, coords);
}
void glMultiTexCoord4xvOES(GLenum texture, GLfixed const  * coords) {
	static const auto glMultiTexCoord4xvOES_ = getFunction<void, GLenum, GLfixed const  *>("glMultiTexCoord4xvOES");
	assert(glMultiTexCoord4xvOES_ != nullptr);
	return glMultiTexCoord4xvOES_(texture, coords);
}
void glNormal3xvOES(GLfixed const  * coords) {
	static const auto glNormal3xvOES_ = getFunction<void, GLfixed const  *>("glNormal3xvOES");
	assert(glNormal3xvOES_ != nullptr);
	return glNormal3xvOES_(coords);
}
void glPassThroughxOES(GLfixed token) {
	static const auto glPassThroughxOES_ = getFunction<void, GLfixed>("glPassThroughxOES");
	assert(glPassThroughxOES_ != nullptr);
	return glPassThroughxOES_(token);
}
void glPixelMapx(GLenum map, GLint size, GLfixed const  * values) {
	static const auto glPixelMapx_ = getFunction<void, GLenum, GLint, GLfixed const  *>("glPixelMapx");
	assert(glPixelMapx_ != nullptr);
	return glPixelMapx_(map, size, values);
}
void glPixelStorex(GLenum pname, GLfixed param) {
	static const auto glPixelStorex_ = getFunction<void, GLenum, GLfixed>("glPixelStorex");
	assert(glPixelStorex_ != nullptr);
	return glPixelStorex_(pname, param);
}
void glPixelTransferxOES(GLenum pname, GLfixed param) {
	static const auto glPixelTransferxOES_ = getFunction<void, GLenum, GLfixed>("glPixelTransferxOES");
	assert(glPixelTransferxOES_ != nullptr);
	return glPixelTransferxOES_(pname, param);
}
void glPixelZoomxOES(GLfixed xfactor, GLfixed yfactor) {
	static const auto glPixelZoomxOES_ = getFunction<void, GLfixed, GLfixed>("glPixelZoomxOES");
	assert(glPixelZoomxOES_ != nullptr);
	return glPixelZoomxOES_(xfactor, yfactor);
}
void glPrioritizeTexturesxOES(GLsizei n, GLuint const  * textures, GLfixed const  * priorities) {
	static const auto glPrioritizeTexturesxOES_ = getFunction<void, GLsizei, GLuint const  *, GLfixed const  *>("glPrioritizeTexturesxOES");
	assert(glPrioritizeTexturesxOES_ != nullptr);
	return glPrioritizeTexturesxOES_(n, textures, priorities);
}
void glRasterPos2xOES(GLfixed x, GLfixed y) {
	static const auto glRasterPos2xOES_ = getFunction<void, GLfixed, GLfixed>("glRasterPos2xOES");
	assert(glRasterPos2xOES_ != nullptr);
	return glRasterPos2xOES_(x, y);
}
void glRasterPos2xvOES(GLfixed const  * coords) {
	static const auto glRasterPos2xvOES_ = getFunction<void, GLfixed const  *>("glRasterPos2xvOES");
	assert(glRasterPos2xvOES_ != nullptr);
	return glRasterPos2xvOES_(coords);
}
void glRasterPos3xOES(GLfixed x, GLfixed y, GLfixed z) {
	static const auto glRasterPos3xOES_ = getFunction<void, GLfixed, GLfixed, GLfixed>("glRasterPos3xOES");
	assert(glRasterPos3xOES_ != nullptr);
	return glRasterPos3xOES_(x, y, z);
}
void glRasterPos3xvOES(GLfixed const  * coords) {
	static const auto glRasterPos3xvOES_ = getFunction<void, GLfixed const  *>("glRasterPos3xvOES");
	assert(glRasterPos3xvOES_ != nullptr);
	return glRasterPos3xvOES_(coords);
}
void glRasterPos4xOES(GLfixed x, GLfixed y, GLfixed z, GLfixed w) {
	static const auto glRasterPos4xOES_ = getFunction<void, GLfixed, GLfixed, GLfixed, GLfixed>("glRasterPos4xOES");
	assert(glRasterPos4xOES_ != nullptr);
	return glRasterPos4xOES_(x, y, z, w);
}
void glRasterPos4xvOES(GLfixed const  * coords) {
	static const auto glRasterPos4xvOES_ = getFunction<void, GLfixed const  *>("glRasterPos4xvOES");
	assert(glRasterPos4xvOES_ != nullptr);
	return glRasterPos4xvOES_(coords);
}
void glRectxOES(GLfixed x1, GLfixed y1, GLfixed x2, GLfixed y2) {
	static const auto glRectxOES_ = getFunction<void, GLfixed, GLfixed, GLfixed, GLfixed>("glRectxOES");
	assert(glRectxOES_ != nullptr);
	return glRectxOES_(x1, y1, x2, y2);
}
void glRectxvOES(GLfixed const  * v1, GLfixed const  * v2) {
	static const auto glRectxvOES_ = getFunction<void, GLfixed const  *, GLfixed const  *>("glRectxvOES");
	assert(glRectxvOES_ != nullptr);
	return glRectxvOES_(v1, v2);
}
void glTexCoord1xOES(GLfixed s) {
	static const auto glTexCoord1xOES_ = getFunction<void, GLfixed>("glTexCoord1xOES");
	assert(glTexCoord1xOES_ != nullptr);
	return glTexCoord1xOES_(s);
}
void glTexCoord1xvOES(GLfixed const  * coords) {
	static const auto glTexCoord1xvOES_ = getFunction<void, GLfixed const  *>("glTexCoord1xvOES");
	assert(glTexCoord1xvOES_ != nullptr);
	return glTexCoord1xvOES_(coords);
}
void glTexCoord2xOES(GLfixed s, GLfixed t) {
	static const auto glTexCoord2xOES_ = getFunction<void, GLfixed, GLfixed>("glTexCoord2xOES");
	assert(glTexCoord2xOES_ != nullptr);
	return glTexCoord2xOES_(s, t);
}
void glTexCoord2xvOES(GLfixed const  * coords) {
	static const auto glTexCoord2xvOES_ = getFunction<void, GLfixed const  *>("glTexCoord2xvOES");
	assert(glTexCoord2xvOES_ != nullptr);
	return glTexCoord2xvOES_(coords);
}
void glTexCoord3xOES(GLfixed s, GLfixed t, GLfixed r) {
	static const auto glTexCoord3xOES_ = getFunction<void, GLfixed, GLfixed, GLfixed>("glTexCoord3xOES");
	assert(glTexCoord3xOES_ != nullptr);
	return glTexCoord3xOES_(s, t, r);
}
void glTexCoord3xvOES(GLfixed const  * coords) {
	static const auto glTexCoord3xvOES_ = getFunction<void, GLfixed const  *>("glTexCoord3xvOES");
	assert(glTexCoord3xvOES_ != nullptr);
	return glTexCoord3xvOES_(coords);
}
void glTexCoord4xOES(GLfixed s, GLfixed t, GLfixed r, GLfixed q) {
	static const auto glTexCoord4xOES_ = getFunction<void, GLfixed, GLfixed, GLfixed, GLfixed>("glTexCoord4xOES");
	assert(glTexCoord4xOES_ != nullptr);
	return glTexCoord4xOES_(s, t, r, q);
}
void glTexCoord4xvOES(GLfixed const  * coords) {
	static const auto glTexCoord4xvOES_ = getFunction<void, GLfixed const  *>("glTexCoord4xvOES");
	assert(glTexCoord4xvOES_ != nullptr);
	return glTexCoord4xvOES_(coords);
}
void glTexGenxOES(GLenum coord, GLenum pname, GLfixed param) {
	static const auto glTexGenxOES_ = getFunction<void, GLenum, GLenum, GLfixed>("glTexGenxOES");
	assert(glTexGenxOES_ != nullptr);
	return glTexGenxOES_(coord, pname, param);
}
void glTexGenxvOES(GLenum coord, GLenum pname, GLfixed const  * params) {
	static const auto glTexGenxvOES_ = getFunction<void, GLenum, GLenum, GLfixed const  *>("glTexGenxvOES");
	assert(glTexGenxvOES_ != nullptr);
	return glTexGenxvOES_(coord, pname, params);
}
void glVertex2xOES(GLfixed x) {
	static const auto glVertex2xOES_ = getFunction<void, GLfixed>("glVertex2xOES");
	assert(glVertex2xOES_ != nullptr);
	return glVertex2xOES_(x);
}
void glVertex2xvOES(GLfixed const  * coords) {
	static const auto glVertex2xvOES_ = getFunction<void, GLfixed const  *>("glVertex2xvOES");
	assert(glVertex2xvOES_ != nullptr);
	return glVertex2xvOES_(coords);
}
void glVertex3xOES(GLfixed x, GLfixed y) {
	static const auto glVertex3xOES_ = getFunction<void, GLfixed, GLfixed>("glVertex3xOES");
	assert(glVertex3xOES_ != nullptr);
	return glVertex3xOES_(x, y);
}
void glVertex3xvOES(GLfixed const  * coords) {
	static const auto glVertex3xvOES_ = getFunction<void, GLfixed const  *>("glVertex3xvOES");
	assert(glVertex3xvOES_ != nullptr);
	return glVertex3xvOES_(coords);
}
void glVertex4xOES(GLfixed x, GLfixed y, GLfixed z) {
	static const auto glVertex4xOES_ = getFunction<void, GLfixed, GLfixed, GLfixed>("glVertex4xOES");
	assert(glVertex4xOES_ != nullptr);
	return glVertex4xOES_(x, y, z);
}
void glVertex4xvOES(GLfixed const  * coords) {
	static const auto glVertex4xvOES_ = getFunction<void, GLfixed const  *>("glVertex4xvOES");
	assert(glVertex4xvOES_ != nullptr);
	return glVertex4xvOES_(coords);
}
GLboolean glIsRenderbufferOES(GLuint renderbuffer) {
	static const auto glIsRenderbufferOES_ = getFunction<GLboolean, GLuint>("glIsRenderbufferOES");
	assert(glIsRenderbufferOES_ != nullptr);
	return glIsRenderbufferOES_(renderbuffer);
}
void glBindRenderbufferOES(GLenum target, GLuint renderbuffer) {
	static const auto glBindRenderbufferOES_ = getFunction<void, GLenum, GLuint>("glBindRenderbufferOES");
	assert(glBindRenderbufferOES_ != nullptr);
	return glBindRenderbufferOES_(target, renderbuffer);
}
void glDeleteRenderbuffersOES(GLsizei n, GLuint const  * renderbuffers) {
	static const auto glDeleteRenderbuffersOES_ = getFunction<void, GLsizei, GLuint const  *>("glDeleteRenderbuffersOES");
	assert(glDeleteRenderbuffersOES_ != nullptr);
	return glDeleteRenderbuffersOES_(n, renderbuffers);
}
void glGenRenderbuffersOES(GLsizei n, GLuint * renderbuffers) {
	static const auto glGenRenderbuffersOES_ = getFunction<void, GLsizei, GLuint *>("glGenRenderbuffersOES");
	assert(glGenRenderbuffersOES_ != nullptr);
	return glGenRenderbuffersOES_(n, renderbuffers);
}
void glRenderbufferStorageOES(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) {
	static const auto glRenderbufferStorageOES_ = getFunction<void, GLenum, GLenum, GLsizei, GLsizei>("glRenderbufferStorageOES");
	assert(glRenderbufferStorageOES_ != nullptr);
	return glRenderbufferStorageOES_(target, internalformat, width, height);
}
void glGetRenderbufferParameterivOES(GLenum target, GLenum pname, GLint * params) {
	static const auto glGetRenderbufferParameterivOES_ = getFunction<void, GLenum, GLenum, GLint *>("glGetRenderbufferParameterivOES");
	assert(glGetRenderbufferParameterivOES_ != nullptr);
	return glGetRenderbufferParameterivOES_(target, pname, params);
}
GLboolean glIsFramebufferOES(GLuint framebuffer) {
	static const auto glIsFramebufferOES_ = getFunction<GLboolean, GLuint>("glIsFramebufferOES");
	assert(glIsFramebufferOES_ != nullptr);
	return glIsFramebufferOES_(framebuffer);
}
void glBindFramebufferOES(GLenum target, GLuint framebuffer) {
	static const auto glBindFramebufferOES_ = getFunction<void, GLenum, GLuint>("glBindFramebufferOES");
	assert(glBindFramebufferOES_ != nullptr);
	return glBindFramebufferOES_(target, framebuffer);
}
void glDeleteFramebuffersOES(GLsizei n, GLuint const  * framebuffers) {
	static const auto glDeleteFramebuffersOES_ = getFunction<void, GLsizei, GLuint const  *>("glDeleteFramebuffersOES");
	assert(glDeleteFramebuffersOES_ != nullptr);
	return glDeleteFramebuffersOES_(n, framebuffers);
}
void glGenFramebuffersOES(GLsizei n, GLuint * framebuffers) {
	static const auto glGenFramebuffersOES_ = getFunction<void, GLsizei, GLuint *>("glGenFramebuffersOES");
	assert(glGenFramebuffersOES_ != nullptr);
	return glGenFramebuffersOES_(n, framebuffers);
}
GLenum glCheckFramebufferStatusOES(GLenum target) {
	static const auto glCheckFramebufferStatusOES_ = getFunction<GLenum, GLenum>("glCheckFramebufferStatusOES");
	assert(glCheckFramebufferStatusOES_ != nullptr);
	return glCheckFramebufferStatusOES_(target);
}
void glFramebufferRenderbufferOES(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) {
	static const auto glFramebufferRenderbufferOES_ = getFunction<void, GLenum, GLenum, GLenum, GLuint>("glFramebufferRenderbufferOES");
	assert(glFramebufferRenderbufferOES_ != nullptr);
	return glFramebufferRenderbufferOES_(target, attachment, renderbuffertarget, renderbuffer);
}
void glFramebufferTexture2DOES(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {
	static const auto glFramebufferTexture2DOES_ = getFunction<void, GLenum, GLenum, GLenum, GLuint, GLint>("glFramebufferTexture2DOES");
	assert(glFramebufferTexture2DOES_ != nullptr);
	return glFramebufferTexture2DOES_(target, attachment, textarget, texture, level);
}
void glGetFramebufferAttachmentParameterivOES(GLenum target, GLenum attachment, GLenum pname, GLint * params) {
	static const auto glGetFramebufferAttachmentParameterivOES_ = getFunction<void, GLenum, GLenum, GLenum, GLint *>("glGetFramebufferAttachmentParameterivOES");
	assert(glGetFramebufferAttachmentParameterivOES_ != nullptr);
	return glGetFramebufferAttachmentParameterivOES_(target, attachment, pname, params);
}
void glGenerateMipmapOES(GLenum target) {
	static const auto glGenerateMipmapOES_ = getFunction<void, GLenum>("glGenerateMipmapOES");
	assert(glGenerateMipmapOES_ != nullptr);
	return glGenerateMipmapOES_(target);
}
void glFramebufferTextureOES(GLenum target, GLenum attachment, GLuint texture, GLint level) {
	static const auto glFramebufferTextureOES_ = getFunction<void, GLenum, GLenum, GLuint, GLint>("glFramebufferTextureOES");
	assert(glFramebufferTextureOES_ != nullptr);
	return glFramebufferTextureOES_(target, attachment, texture, level);
}
void glGetProgramBinaryOES(GLuint program, GLsizei bufSize, GLsizei * length, GLenum * binaryFormat, void * binary) {
	static const auto glGetProgramBinaryOES_ = getFunction<void, GLuint, GLsizei, GLsizei *, GLenum *, void *>("glGetProgramBinaryOES");
	assert(glGetProgramBinaryOES_ != nullptr);
	return glGetProgramBinaryOES_(program, bufSize, length, binaryFormat, binary);
}
void glProgramBinaryOES(GLuint program, GLenum binaryFormat, const void * binary, GLint length) {
	static const auto glProgramBinaryOES_ = getFunction<void, GLuint, GLenum, const void *, GLint>("glProgramBinaryOES");
	assert(glProgramBinaryOES_ != nullptr);
	return glProgramBinaryOES_(program, binaryFormat, binary, length);
}
void * glMapBufferOES(GLenum target, GLenum access) {
	static const auto glMapBufferOES_ = getFunction<void *, GLenum, GLenum>("glMapBufferOES");
	assert(glMapBufferOES_ != nullptr);
	return glMapBufferOES_(target, access);
}
GLboolean glUnmapBufferOES(GLenum target) {
	static const auto glUnmapBufferOES_ = getFunction<GLboolean, GLenum>("glUnmapBufferOES");
	assert(glUnmapBufferOES_ != nullptr);
	return glUnmapBufferOES_(target);
}
void glGetBufferPointervOES(GLenum target, GLenum pname, void ** params) {
	static const auto glGetBufferPointervOES_ = getFunction<void, GLenum, GLenum, void **>("glGetBufferPointervOES");
	assert(glGetBufferPointervOES_ != nullptr);
	return glGetBufferPointervOES_(target, pname, params);
}
void glCurrentPaletteMatrixOES(GLuint matrixpaletteindex) {
	static const auto glCurrentPaletteMatrixOES_ = getFunction<void, GLuint>("glCurrentPaletteMatrixOES");
	assert(glCurrentPaletteMatrixOES_ != nullptr);
	return glCurrentPaletteMatrixOES_(matrixpaletteindex);
}
void glLoadPaletteFromModelViewMatrixOES() {
	static const auto glLoadPaletteFromModelViewMatrixOES_ = getFunction<void>("glLoadPaletteFromModelViewMatrixOES");
	assert(glLoadPaletteFromModelViewMatrixOES_ != nullptr);
	return glLoadPaletteFromModelViewMatrixOES_();
}
void glMatrixIndexPointerOES(GLint size, GLenum type, GLsizei stride, const void * pointer) {
	static const auto glMatrixIndexPointerOES_ = getFunction<void, GLint, GLenum, GLsizei, const void *>("glMatrixIndexPointerOES");
	assert(glMatrixIndexPointerOES_ != nullptr);
	return glMatrixIndexPointerOES_(size, type, stride, pointer);
}
void glWeightPointerOES(GLint size, GLenum type, GLsizei stride, const void * pointer) {
	static const auto glWeightPointerOES_ = getFunction<void, GLint, GLenum, GLsizei, const void *>("glWeightPointerOES");
	assert(glWeightPointerOES_ != nullptr);
	return glWeightPointerOES_(size, type, stride, pointer);
}
void glPointSizePointerOES(GLenum type, GLsizei stride, const void * pointer) {
	static const auto glPointSizePointerOES_ = getFunction<void, GLenum, GLsizei, const void *>("glPointSizePointerOES");
	assert(glPointSizePointerOES_ != nullptr);
	return glPointSizePointerOES_(type, stride, pointer);
}
void glPrimitiveBoundingBoxOES(GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat minW, GLfloat maxX, GLfloat maxY, GLfloat maxZ, GLfloat maxW) {
	static const auto glPrimitiveBoundingBoxOES_ = getFunction<void, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat>("glPrimitiveBoundingBoxOES");
	assert(glPrimitiveBoundingBoxOES_ != nullptr);
	return glPrimitiveBoundingBoxOES_(minX, minY, minZ, minW, maxX, maxY, maxZ, maxW);
}
GLbitfield glQueryMatrixxOES(GLfixed * mantissa, GLint * exponent) {
	static const auto glQueryMatrixxOES_ = getFunction<GLbitfield, GLfixed *, GLint *>("glQueryMatrixxOES");
	assert(glQueryMatrixxOES_ != nullptr);
	return glQueryMatrixxOES_(mantissa, exponent);
}
void glMinSampleShadingOES(GLfloat value) {
	static const auto glMinSampleShadingOES_ = getFunction<void, GLfloat>("glMinSampleShadingOES");
	assert(glMinSampleShadingOES_ != nullptr);
	return glMinSampleShadingOES_(value);
}
void glClearDepthfOES(GLclampf depth) {
	static const auto glClearDepthfOES_ = getFunction<void, GLclampf>("glClearDepthfOES");
	assert(glClearDepthfOES_ != nullptr);
	return glClearDepthfOES_(depth);
}
void glClipPlanefOES(GLenum plane, GLfloat const  * equation) {
	static const auto glClipPlanefOES_ = getFunction<void, GLenum, GLfloat const  *>("glClipPlanefOES");
	assert(glClipPlanefOES_ != nullptr);
	return glClipPlanefOES_(plane, equation);
}
void glDepthRangefOES(GLclampf n, GLclampf f) {
	static const auto glDepthRangefOES_ = getFunction<void, GLclampf, GLclampf>("glDepthRangefOES");
	assert(glDepthRangefOES_ != nullptr);
	return glDepthRangefOES_(n, f);
}
void glFrustumfOES(GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f) {
	static const auto glFrustumfOES_ = getFunction<void, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat>("glFrustumfOES");
	assert(glFrustumfOES_ != nullptr);
	return glFrustumfOES_(l, r, b, t, n, f);
}
void glGetClipPlanefOES(GLenum plane, GLfloat * equation) {
	static const auto glGetClipPlanefOES_ = getFunction<void, GLenum, GLfloat *>("glGetClipPlanefOES");
	assert(glGetClipPlanefOES_ != nullptr);
	return glGetClipPlanefOES_(plane, equation);
}
void glOrthofOES(GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f) {
	static const auto glOrthofOES_ = getFunction<void, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat>("glOrthofOES");
	assert(glOrthofOES_ != nullptr);
	return glOrthofOES_(l, r, b, t, n, f);
}
void glPatchParameteriOES(GLenum pname, GLint value) {
	static const auto glPatchParameteriOES_ = getFunction<void, GLenum, GLint>("glPatchParameteriOES");
	assert(glPatchParameteriOES_ != nullptr);
	return glPatchParameteriOES_(pname, value);
}
void glTexImage3DOES(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void * pixels) {
	static const auto glTexImage3DOES_ = getFunction<void, GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const void *>("glTexImage3DOES");
	assert(glTexImage3DOES_ != nullptr);
	return glTexImage3DOES_(target, level, internalformat, width, height, depth, border, format, type, pixels);
}
void glTexSubImage3DOES(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels) {
	static const auto glTexSubImage3DOES_ = getFunction<void, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const void *>("glTexSubImage3DOES");
	assert(glTexSubImage3DOES_ != nullptr);
	return glTexSubImage3DOES_(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}
void glCopyTexSubImage3DOES(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
	static const auto glCopyTexSubImage3DOES_ = getFunction<void, GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei>("glCopyTexSubImage3DOES");
	assert(glCopyTexSubImage3DOES_ != nullptr);
	return glCopyTexSubImage3DOES_(target, level, xoffset, yoffset, zoffset, x, y, width, height);
}
void glCompressedTexImage3DOES(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void * data) {
	static const auto glCompressedTexImage3DOES_ = getFunction<void, GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLsizei, const void *>("glCompressedTexImage3DOES");
	assert(glCompressedTexImage3DOES_ != nullptr);
	return glCompressedTexImage3DOES_(target, level, internalformat, width, height, depth, border, imageSize, data);
}
void glCompressedTexSubImage3DOES(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * data) {
	static const auto glCompressedTexSubImage3DOES_ = getFunction<void, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const void *>("glCompressedTexSubImage3DOES");
	assert(glCompressedTexSubImage3DOES_ != nullptr);
	return glCompressedTexSubImage3DOES_(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
}
void glFramebufferTexture3DOES(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset) {
	static const auto glFramebufferTexture3DOES_ = getFunction<void, GLenum, GLenum, GLenum, GLuint, GLint, GLint>("glFramebufferTexture3DOES");
	assert(glFramebufferTexture3DOES_ != nullptr);
	return glFramebufferTexture3DOES_(target, attachment, textarget, texture, level, zoffset);
}
void glTexParameterIivOES(GLenum target, GLenum pname, GLint const  * params) {
	static const auto glTexParameterIivOES_ = getFunction<void, GLenum, GLenum, GLint const  *>("glTexParameterIivOES");
	assert(glTexParameterIivOES_ != nullptr);
	return glTexParameterIivOES_(target, pname, params);
}
void glTexParameterIuivOES(GLenum target, GLenum pname, GLuint const  * params) {
	static const auto glTexParameterIuivOES_ = getFunction<void, GLenum, GLenum, GLuint const  *>("glTexParameterIuivOES");
	assert(glTexParameterIuivOES_ != nullptr);
	return glTexParameterIuivOES_(target, pname, params);
}
void glGetTexParameterIivOES(GLenum target, GLenum pname, GLint * params) {
	static const auto glGetTexParameterIivOES_ = getFunction<void, GLenum, GLenum, GLint *>("glGetTexParameterIivOES");
	assert(glGetTexParameterIivOES_ != nullptr);
	return glGetTexParameterIivOES_(target, pname, params);
}
void glGetTexParameterIuivOES(GLenum target, GLenum pname, GLuint * params) {
	static const auto glGetTexParameterIuivOES_ = getFunction<void, GLenum, GLenum, GLuint *>("glGetTexParameterIuivOES");
	assert(glGetTexParameterIuivOES_ != nullptr);
	return glGetTexParameterIuivOES_(target, pname, params);
}
void glSamplerParameterIivOES(GLuint sampler, GLenum pname, GLint const  * param) {
	static const auto glSamplerParameterIivOES_ = getFunction<void, GLuint, GLenum, GLint const  *>("glSamplerParameterIivOES");
	assert(glSamplerParameterIivOES_ != nullptr);
	return glSamplerParameterIivOES_(sampler, pname, param);
}
void glSamplerParameterIuivOES(GLuint sampler, GLenum pname, GLuint const  * param) {
	static const auto glSamplerParameterIuivOES_ = getFunction<void, GLuint, GLenum, GLuint const  *>("glSamplerParameterIuivOES");
	assert(glSamplerParameterIuivOES_ != nullptr);
	return glSamplerParameterIuivOES_(sampler, pname, param);
}
void glGetSamplerParameterIivOES(GLuint sampler, GLenum pname, GLint * params) {
	static const auto glGetSamplerParameterIivOES_ = getFunction<void, GLuint, GLenum, GLint *>("glGetSamplerParameterIivOES");
	assert(glGetSamplerParameterIivOES_ != nullptr);
	return glGetSamplerParameterIivOES_(sampler, pname, params);
}
void glGetSamplerParameterIuivOES(GLuint sampler, GLenum pname, GLuint * params) {
	static const auto glGetSamplerParameterIuivOES_ = getFunction<void, GLuint, GLenum, GLuint *>("glGetSamplerParameterIuivOES");
	assert(glGetSamplerParameterIuivOES_ != nullptr);
	return glGetSamplerParameterIuivOES_(sampler, pname, params);
}
void glTexBufferOES(GLenum target, GLenum internalformat, GLuint buffer) {
	static const auto glTexBufferOES_ = getFunction<void, GLenum, GLenum, GLuint>("glTexBufferOES");
	assert(glTexBufferOES_ != nullptr);
	return glTexBufferOES_(target, internalformat, buffer);
}
void glTexBufferRangeOES(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size) {
	static const auto glTexBufferRangeOES_ = getFunction<void, GLenum, GLenum, GLuint, GLintptr, GLsizeiptr>("glTexBufferRangeOES");
	assert(glTexBufferRangeOES_ != nullptr);
	return glTexBufferRangeOES_(target, internalformat, buffer, offset, size);
}
void glTexGenfOES(GLenum coord, GLenum pname, GLfloat param) {
	static const auto glTexGenfOES_ = getFunction<void, GLenum, GLenum, GLfloat>("glTexGenfOES");
	assert(glTexGenfOES_ != nullptr);
	return glTexGenfOES_(coord, pname, param);
}
void glTexGenfvOES(GLenum coord, GLenum pname, GLfloat const  * params) {
	static const auto glTexGenfvOES_ = getFunction<void, GLenum, GLenum, GLfloat const  *>("glTexGenfvOES");
	assert(glTexGenfvOES_ != nullptr);
	return glTexGenfvOES_(coord, pname, params);
}
void glTexGeniOES(GLenum coord, GLenum pname, GLint param) {
	static const auto glTexGeniOES_ = getFunction<void, GLenum, GLenum, GLint>("glTexGeniOES");
	assert(glTexGeniOES_ != nullptr);
	return glTexGeniOES_(coord, pname, param);
}
void glTexGenivOES(GLenum coord, GLenum pname, GLint const  * params) {
	static const auto glTexGenivOES_ = getFunction<void, GLenum, GLenum, GLint const  *>("glTexGenivOES");
	assert(glTexGenivOES_ != nullptr);
	return glTexGenivOES_(coord, pname, params);
}
void glGetTexGenfvOES(GLenum coord, GLenum pname, GLfloat * params) {
	static const auto glGetTexGenfvOES_ = getFunction<void, GLenum, GLenum, GLfloat *>("glGetTexGenfvOES");
	assert(glGetTexGenfvOES_ != nullptr);
	return glGetTexGenfvOES_(coord, pname, params);
}
void glGetTexGenivOES(GLenum coord, GLenum pname, GLint * params) {
	static const auto glGetTexGenivOES_ = getFunction<void, GLenum, GLenum, GLint *>("glGetTexGenivOES");
	assert(glGetTexGenivOES_ != nullptr);
	return glGetTexGenivOES_(coord, pname, params);
}
void glTexStorage3DMultisampleOES(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) {
	static const auto glTexStorage3DMultisampleOES_ = getFunction<void, GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei, GLboolean>("glTexStorage3DMultisampleOES");
	assert(glTexStorage3DMultisampleOES_ != nullptr);
	return glTexStorage3DMultisampleOES_(target, samples, internalformat, width, height, depth, fixedsamplelocations);
}
void glTextureViewOES(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers) {
	static const auto glTextureViewOES_ = getFunction<void, GLuint, GLenum, GLuint, GLenum, GLuint, GLuint, GLuint, GLuint>("glTextureViewOES");
	assert(glTextureViewOES_ != nullptr);
	return glTextureViewOES_(texture, target, origtexture, internalformat, minlevel, numlevels, minlayer, numlayers);
}
void glBindVertexArrayOES(GLuint array) {
	static const auto glBindVertexArrayOES_ = getFunction<void, GLuint>("glBindVertexArrayOES");
	assert(glBindVertexArrayOES_ != nullptr);
	return glBindVertexArrayOES_(array);
}
void glDeleteVertexArraysOES(GLsizei n, GLuint const  * arrays) {
	static const auto glDeleteVertexArraysOES_ = getFunction<void, GLsizei, GLuint const  *>("glDeleteVertexArraysOES");
	assert(glDeleteVertexArraysOES_ != nullptr);
	return glDeleteVertexArraysOES_(n, arrays);
}
void glGenVertexArraysOES(GLsizei n, GLuint * arrays) {
	static const auto glGenVertexArraysOES_ = getFunction<void, GLsizei, GLuint *>("glGenVertexArraysOES");
	assert(glGenVertexArraysOES_ != nullptr);
	return glGenVertexArraysOES_(n, arrays);
}
GLboolean glIsVertexArrayOES(GLuint array) {
	static const auto glIsVertexArrayOES_ = getFunction<GLboolean, GLuint>("glIsVertexArrayOES");
	assert(glIsVertexArrayOES_ != nullptr);
	return glIsVertexArrayOES_(array);
}
void glViewportArrayvOES(GLuint first, GLsizei count, GLfloat const  * v) {
	static const auto glViewportArrayvOES_ = getFunction<void, GLuint, GLsizei, GLfloat const  *>("glViewportArrayvOES");
	assert(glViewportArrayvOES_ != nullptr);
	return glViewportArrayvOES_(first, count, v);
}
void glViewportIndexedfOES(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h) {
	static const auto glViewportIndexedfOES_ = getFunction<void, GLuint, GLfloat, GLfloat, GLfloat, GLfloat>("glViewportIndexedfOES");
	assert(glViewportIndexedfOES_ != nullptr);
	return glViewportIndexedfOES_(index, x, y, w, h);
}
void glViewportIndexedfvOES(GLuint index, GLfloat const  * v) {
	static const auto glViewportIndexedfvOES_ = getFunction<void, GLuint, GLfloat const  *>("glViewportIndexedfvOES");
	assert(glViewportIndexedfvOES_ != nullptr);
	return glViewportIndexedfvOES_(index, v);
}
void glScissorArrayvOES(GLuint first, GLsizei count, GLint const  * v) {
	static const auto glScissorArrayvOES_ = getFunction<void, GLuint, GLsizei, GLint const  *>("glScissorArrayvOES");
	assert(glScissorArrayvOES_ != nullptr);
	return glScissorArrayvOES_(first, count, v);
}
void glScissorIndexedOES(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height) {
	static const auto glScissorIndexedOES_ = getFunction<void, GLuint, GLint, GLint, GLsizei, GLsizei>("glScissorIndexedOES");
	assert(glScissorIndexedOES_ != nullptr);
	return glScissorIndexedOES_(index, left, bottom, width, height);
}
void glScissorIndexedvOES(GLuint index, GLint const  * v) {
	static const auto glScissorIndexedvOES_ = getFunction<void, GLuint, GLint const  *>("glScissorIndexedvOES");
	assert(glScissorIndexedvOES_ != nullptr);
	return glScissorIndexedvOES_(index, v);
}
void glDepthRangeArrayfvOES(GLuint first, GLsizei count, GLfloat const  * v) {
	static const auto glDepthRangeArrayfvOES_ = getFunction<void, GLuint, GLsizei, GLfloat const  *>("glDepthRangeArrayfvOES");
	assert(glDepthRangeArrayfvOES_ != nullptr);
	return glDepthRangeArrayfvOES_(first, count, v);
}
void glDepthRangeIndexedfOES(GLuint index, GLfloat n, GLfloat f) {
	static const auto glDepthRangeIndexedfOES_ = getFunction<void, GLuint, GLfloat, GLfloat>("glDepthRangeIndexedfOES");
	assert(glDepthRangeIndexedfOES_ != nullptr);
	return glDepthRangeIndexedfOES_(index, n, f);
}
void glGetFloati_vOES(GLenum target, GLuint index, GLfloat * data) {
	static const auto glGetFloati_vOES_ = getFunction<void, GLenum, GLuint, GLfloat *>("glGetFloati_vOES");
	assert(glGetFloati_vOES_ != nullptr);
	return glGetFloati_vOES_(target, index, data);
}

}
