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

#pragma once

#include <functional>

#ifdef __gl_h_
#error OpenGL ES 1 header already included, remove this include
#endif
#define __gl_h_

#ifdef __gl2_h_
#error OpenGL ES 2 header already included, remove this include
#endif
#define __gl2_h_

#ifdef __gl3_h_
#error OpenGL ES 3 header already included, remove this include
#endif
#define __gl3_h_

#ifdef _WIN32
#define GL_APIENTRY __stdcall
#endif

#ifndef GL_APIENTRY
#define GL_APIENTRY
#endif
#ifndef GL_APIENTRYP
#define GL_APIENTRYP GL_APIENTRY *
#endif
#ifndef GL_APICALL
#define GL_APICALL extern
#endif

namespace gles {
/* SECTION: GL type definitions. */
#include <KHR/khrplatform.h>
typedef unsigned int GLenum;
typedef unsigned char GLboolean;
typedef unsigned int GLbitfield;
typedef void GLvoid;
typedef khronos_int8_t GLbyte;
typedef khronos_uint8_t GLubyte;
typedef khronos_int16_t GLshort;
typedef khronos_uint16_t GLushort;
typedef int GLint;
typedef unsigned int GLuint;
typedef khronos_int32_t GLclampx;
typedef int GLsizei;
typedef khronos_float_t GLfloat;
typedef khronos_float_t GLclampf;
typedef double GLdouble;
typedef double GLclampd;
typedef void *GLeglClientBufferEXT;
typedef void *GLeglImageOES;
typedef char GLchar;
typedef char GLcharARB;
#ifdef __APPLE__
typedef void *GLhandleARB;
#else
typedef unsigned int GLhandleARB;
#endif
typedef khronos_uint16_t GLhalf;
typedef khronos_uint16_t GLhalfARB;
typedef khronos_int32_t GLfixed;
typedef khronos_intptr_t GLintptr;
typedef khronos_intptr_t GLintptrARB;
typedef khronos_ssize_t GLsizeiptr;
typedef khronos_ssize_t GLsizeiptrARB;
typedef khronos_int64_t GLint64;
typedef khronos_int64_t GLint64EXT;
typedef khronos_uint64_t GLuint64;
typedef khronos_uint64_t GLuint64EXT;
typedef struct __GLsync *GLsync;
struct _cl_context;
struct _cl_event;
typedef void (GL_APIENTRY *GLDEBUGPROC)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,const void *userParam);
typedef void (GL_APIENTRY *GLDEBUGPROCARB)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,const void *userParam);
typedef void (GL_APIENTRY *GLDEBUGPROCKHR)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,const void *userParam);
typedef void (GL_APIENTRY *GLDEBUGPROCAMD)(GLuint id,GLenum category,GLenum severity,GLsizei length,const GLchar *message,void *userParam);
typedef unsigned short GLhalfNV;
typedef GLintptr GLvdpauSurfaceNV;
typedef void (GL_APIENTRY *GLVULKANPROCNV)(void);


/**
 * The generic pointer to an OpenGL function.
 */
using ProcAddress = void(*)();

/**
 * The signature for the getProcAddress function.
 */
using GetProcAddress = std::function<ProcAddress(const char*)>;

/**
 * Initalizes functions for the active OpenGL context.
 * @param resolver
 */
void initialize(const GetProcAddress &resolver = nullptr);

/**
 * Gets a pointer to a OpenGL function.
 * @param name The function name.
 * @return The function pointer.
 */
ProcAddress getProcAddress(const char *name);

/**
 * Gets a OpenGL function matching a calling signature.
 * @tparam R The functions return type.
 * @tparam Args The function call parameters.
 * @param name The function name.
 * @return The function.
 */
template<typename R, typename ...Params>
auto getFunction(const char *name) {
    return reinterpret_cast<R(GL_APIENTRYP)(Params...)>(getProcAddress(name));
}

#ifndef GL_VERSION_ES_CM_1_0
#define GL_VERSION_ES_CM_1_0 1
constexpr GLenum GL_VERSION_ES_CL_1_0 = 1;
constexpr GLenum GL_VERSION_ES_CM_1_1 = 1;
constexpr GLenum GL_VERSION_ES_CL_1_1 = 1;
constexpr GLenum GL_DEPTH_BUFFER_BIT = 0x00000100;
constexpr GLenum GL_STENCIL_BUFFER_BIT = 0x00000400;
constexpr GLenum GL_COLOR_BUFFER_BIT = 0x00004000;
constexpr GLenum GL_FALSE = 0;
constexpr GLenum GL_TRUE = 1;
constexpr GLenum GL_POINTS = 0x0000;
constexpr GLenum GL_LINES = 0x0001;
constexpr GLenum GL_LINE_LOOP = 0x0002;
constexpr GLenum GL_LINE_STRIP = 0x0003;
constexpr GLenum GL_TRIANGLES = 0x0004;
constexpr GLenum GL_TRIANGLE_STRIP = 0x0005;
constexpr GLenum GL_TRIANGLE_FAN = 0x0006;
constexpr GLenum GL_NEVER = 0x0200;
constexpr GLenum GL_LESS = 0x0201;
constexpr GLenum GL_EQUAL = 0x0202;
constexpr GLenum GL_LEQUAL = 0x0203;
constexpr GLenum GL_GREATER = 0x0204;
constexpr GLenum GL_NOTEQUAL = 0x0205;
constexpr GLenum GL_GEQUAL = 0x0206;
constexpr GLenum GL_ALWAYS = 0x0207;
constexpr GLenum GL_ZERO = 0;
constexpr GLenum GL_ONE = 1;
constexpr GLenum GL_SRC_COLOR = 0x0300;
constexpr GLenum GL_ONE_MINUS_SRC_COLOR = 0x0301;
constexpr GLenum GL_SRC_ALPHA = 0x0302;
constexpr GLenum GL_ONE_MINUS_SRC_ALPHA = 0x0303;
constexpr GLenum GL_DST_ALPHA = 0x0304;
constexpr GLenum GL_ONE_MINUS_DST_ALPHA = 0x0305;
constexpr GLenum GL_DST_COLOR = 0x0306;
constexpr GLenum GL_ONE_MINUS_DST_COLOR = 0x0307;
constexpr GLenum GL_SRC_ALPHA_SATURATE = 0x0308;
constexpr GLenum GL_CLIP_PLANE0 = 0x3000;
constexpr GLenum GL_CLIP_PLANE1 = 0x3001;
constexpr GLenum GL_CLIP_PLANE2 = 0x3002;
constexpr GLenum GL_CLIP_PLANE3 = 0x3003;
constexpr GLenum GL_CLIP_PLANE4 = 0x3004;
constexpr GLenum GL_CLIP_PLANE5 = 0x3005;
constexpr GLenum GL_FRONT = 0x0404;
constexpr GLenum GL_BACK = 0x0405;
constexpr GLenum GL_FRONT_AND_BACK = 0x0408;
constexpr GLenum GL_FOG = 0x0B60;
constexpr GLenum GL_LIGHTING = 0x0B50;
constexpr GLenum GL_TEXTURE_2D = 0x0DE1;
constexpr GLenum GL_CULL_FACE = 0x0B44;
constexpr GLenum GL_ALPHA_TEST = 0x0BC0;
constexpr GLenum GL_BLEND = 0x0BE2;
constexpr GLenum GL_COLOR_LOGIC_OP = 0x0BF2;
constexpr GLenum GL_DITHER = 0x0BD0;
constexpr GLenum GL_STENCIL_TEST = 0x0B90;
constexpr GLenum GL_DEPTH_TEST = 0x0B71;
constexpr GLenum GL_POINT_SMOOTH = 0x0B10;
constexpr GLenum GL_LINE_SMOOTH = 0x0B20;
constexpr GLenum GL_SCISSOR_TEST = 0x0C11;
constexpr GLenum GL_COLOR_MATERIAL = 0x0B57;
constexpr GLenum GL_NORMALIZE = 0x0BA1;
constexpr GLenum GL_RESCALE_NORMAL = 0x803A;
constexpr GLenum GL_VERTEX_ARRAY = 0x8074;
constexpr GLenum GL_NORMAL_ARRAY = 0x8075;
constexpr GLenum GL_COLOR_ARRAY = 0x8076;
constexpr GLenum GL_TEXTURE_COORD_ARRAY = 0x8078;
constexpr GLenum GL_MULTISAMPLE = 0x809D;
constexpr GLenum GL_SAMPLE_ALPHA_TO_COVERAGE = 0x809E;
constexpr GLenum GL_SAMPLE_ALPHA_TO_ONE = 0x809F;
constexpr GLenum GL_SAMPLE_COVERAGE = 0x80A0;
constexpr GLenum GL_NO_ERROR = 0;
constexpr GLenum GL_INVALID_ENUM = 0x0500;
constexpr GLenum GL_INVALID_VALUE = 0x0501;
constexpr GLenum GL_INVALID_OPERATION = 0x0502;
constexpr GLenum GL_STACK_OVERFLOW = 0x0503;
constexpr GLenum GL_STACK_UNDERFLOW = 0x0504;
constexpr GLenum GL_OUT_OF_MEMORY = 0x0505;
constexpr GLenum GL_EXP = 0x0800;
constexpr GLenum GL_EXP2 = 0x0801;
constexpr GLenum GL_FOG_DENSITY = 0x0B62;
constexpr GLenum GL_FOG_START = 0x0B63;
constexpr GLenum GL_FOG_END = 0x0B64;
constexpr GLenum GL_FOG_MODE = 0x0B65;
constexpr GLenum GL_FOG_COLOR = 0x0B66;
constexpr GLenum GL_CW = 0x0900;
constexpr GLenum GL_CCW = 0x0901;
constexpr GLenum GL_CURRENT_COLOR = 0x0B00;
constexpr GLenum GL_CURRENT_NORMAL = 0x0B02;
constexpr GLenum GL_CURRENT_TEXTURE_COORDS = 0x0B03;
constexpr GLenum GL_POINT_SIZE = 0x0B11;
constexpr GLenum GL_POINT_SIZE_MIN = 0x8126;
constexpr GLenum GL_POINT_SIZE_MAX = 0x8127;
constexpr GLenum GL_POINT_FADE_THRESHOLD_SIZE = 0x8128;
constexpr GLenum GL_POINT_DISTANCE_ATTENUATION = 0x8129;
constexpr GLenum GL_SMOOTH_POINT_SIZE_RANGE = 0x0B12;
constexpr GLenum GL_LINE_WIDTH = 0x0B21;
constexpr GLenum GL_SMOOTH_LINE_WIDTH_RANGE = 0x0B22;
constexpr GLenum GL_ALIASED_POINT_SIZE_RANGE = 0x846D;
constexpr GLenum GL_ALIASED_LINE_WIDTH_RANGE = 0x846E;
constexpr GLenum GL_CULL_FACE_MODE = 0x0B45;
constexpr GLenum GL_FRONT_FACE = 0x0B46;
constexpr GLenum GL_SHADE_MODEL = 0x0B54;
constexpr GLenum GL_DEPTH_RANGE = 0x0B70;
constexpr GLenum GL_DEPTH_WRITEMASK = 0x0B72;
constexpr GLenum GL_DEPTH_CLEAR_VALUE = 0x0B73;
constexpr GLenum GL_DEPTH_FUNC = 0x0B74;
constexpr GLenum GL_STENCIL_CLEAR_VALUE = 0x0B91;
constexpr GLenum GL_STENCIL_FUNC = 0x0B92;
constexpr GLenum GL_STENCIL_VALUE_MASK = 0x0B93;
constexpr GLenum GL_STENCIL_FAIL = 0x0B94;
constexpr GLenum GL_STENCIL_PASS_DEPTH_FAIL = 0x0B95;
constexpr GLenum GL_STENCIL_PASS_DEPTH_PASS = 0x0B96;
constexpr GLenum GL_STENCIL_REF = 0x0B97;
constexpr GLenum GL_STENCIL_WRITEMASK = 0x0B98;
constexpr GLenum GL_MATRIX_MODE = 0x0BA0;
constexpr GLenum GL_VIEWPORT = 0x0BA2;
constexpr GLenum GL_MODELVIEW_STACK_DEPTH = 0x0BA3;
constexpr GLenum GL_PROJECTION_STACK_DEPTH = 0x0BA4;
constexpr GLenum GL_TEXTURE_STACK_DEPTH = 0x0BA5;
constexpr GLenum GL_MODELVIEW_MATRIX = 0x0BA6;
constexpr GLenum GL_PROJECTION_MATRIX = 0x0BA7;
constexpr GLenum GL_TEXTURE_MATRIX = 0x0BA8;
constexpr GLenum GL_ALPHA_TEST_FUNC = 0x0BC1;
constexpr GLenum GL_ALPHA_TEST_REF = 0x0BC2;
constexpr GLenum GL_BLEND_DST = 0x0BE0;
constexpr GLenum GL_BLEND_SRC = 0x0BE1;
constexpr GLenum GL_LOGIC_OP_MODE = 0x0BF0;
constexpr GLenum GL_SCISSOR_BOX = 0x0C10;
constexpr GLenum GL_COLOR_CLEAR_VALUE = 0x0C22;
constexpr GLenum GL_COLOR_WRITEMASK = 0x0C23;
constexpr GLenum GL_MAX_LIGHTS = 0x0D31;
constexpr GLenum GL_MAX_CLIP_PLANES = 0x0D32;
constexpr GLenum GL_MAX_TEXTURE_SIZE = 0x0D33;
constexpr GLenum GL_MAX_MODELVIEW_STACK_DEPTH = 0x0D36;
constexpr GLenum GL_MAX_PROJECTION_STACK_DEPTH = 0x0D38;
constexpr GLenum GL_MAX_TEXTURE_STACK_DEPTH = 0x0D39;
constexpr GLenum GL_MAX_VIEWPORT_DIMS = 0x0D3A;
constexpr GLenum GL_MAX_TEXTURE_UNITS = 0x84E2;
constexpr GLenum GL_SUBPIXEL_BITS = 0x0D50;
constexpr GLenum GL_RED_BITS = 0x0D52;
constexpr GLenum GL_GREEN_BITS = 0x0D53;
constexpr GLenum GL_BLUE_BITS = 0x0D54;
constexpr GLenum GL_ALPHA_BITS = 0x0D55;
constexpr GLenum GL_DEPTH_BITS = 0x0D56;
constexpr GLenum GL_STENCIL_BITS = 0x0D57;
constexpr GLenum GL_POLYGON_OFFSET_UNITS = 0x2A00;
constexpr GLenum GL_POLYGON_OFFSET_FILL = 0x8037;
constexpr GLenum GL_POLYGON_OFFSET_FACTOR = 0x8038;
constexpr GLenum GL_TEXTURE_BINDING_2D = 0x8069;
constexpr GLenum GL_VERTEX_ARRAY_SIZE = 0x807A;
constexpr GLenum GL_VERTEX_ARRAY_TYPE = 0x807B;
constexpr GLenum GL_VERTEX_ARRAY_STRIDE = 0x807C;
constexpr GLenum GL_NORMAL_ARRAY_TYPE = 0x807E;
constexpr GLenum GL_NORMAL_ARRAY_STRIDE = 0x807F;
constexpr GLenum GL_COLOR_ARRAY_SIZE = 0x8081;
constexpr GLenum GL_COLOR_ARRAY_TYPE = 0x8082;
constexpr GLenum GL_COLOR_ARRAY_STRIDE = 0x8083;
constexpr GLenum GL_TEXTURE_COORD_ARRAY_SIZE = 0x8088;
constexpr GLenum GL_TEXTURE_COORD_ARRAY_TYPE = 0x8089;
constexpr GLenum GL_TEXTURE_COORD_ARRAY_STRIDE = 0x808A;
constexpr GLenum GL_VERTEX_ARRAY_POINTER = 0x808E;
constexpr GLenum GL_NORMAL_ARRAY_POINTER = 0x808F;
constexpr GLenum GL_COLOR_ARRAY_POINTER = 0x8090;
constexpr GLenum GL_TEXTURE_COORD_ARRAY_POINTER = 0x8092;
constexpr GLenum GL_SAMPLE_BUFFERS = 0x80A8;
constexpr GLenum GL_SAMPLES = 0x80A9;
constexpr GLenum GL_SAMPLE_COVERAGE_VALUE = 0x80AA;
constexpr GLenum GL_SAMPLE_COVERAGE_INVERT = 0x80AB;
constexpr GLenum GL_NUM_COMPRESSED_TEXTURE_FORMATS = 0x86A2;
constexpr GLenum GL_COMPRESSED_TEXTURE_FORMATS = 0x86A3;
constexpr GLenum GL_DONT_CARE = 0x1100;
constexpr GLenum GL_FASTEST = 0x1101;
constexpr GLenum GL_NICEST = 0x1102;
constexpr GLenum GL_PERSPECTIVE_CORRECTION_HINT = 0x0C50;
constexpr GLenum GL_POINT_SMOOTH_HINT = 0x0C51;
constexpr GLenum GL_LINE_SMOOTH_HINT = 0x0C52;
constexpr GLenum GL_FOG_HINT = 0x0C54;
constexpr GLenum GL_GENERATE_MIPMAP_HINT = 0x8192;
constexpr GLenum GL_LIGHT_MODEL_AMBIENT = 0x0B53;
constexpr GLenum GL_LIGHT_MODEL_TWO_SIDE = 0x0B52;
constexpr GLenum GL_AMBIENT = 0x1200;
constexpr GLenum GL_DIFFUSE = 0x1201;
constexpr GLenum GL_SPECULAR = 0x1202;
constexpr GLenum GL_POSITION = 0x1203;
constexpr GLenum GL_SPOT_DIRECTION = 0x1204;
constexpr GLenum GL_SPOT_EXPONENT = 0x1205;
constexpr GLenum GL_SPOT_CUTOFF = 0x1206;
constexpr GLenum GL_CONSTANT_ATTENUATION = 0x1207;
constexpr GLenum GL_LINEAR_ATTENUATION = 0x1208;
constexpr GLenum GL_QUADRATIC_ATTENUATION = 0x1209;
constexpr GLenum GL_BYTE = 0x1400;
constexpr GLenum GL_UNSIGNED_BYTE = 0x1401;
constexpr GLenum GL_SHORT = 0x1402;
constexpr GLenum GL_UNSIGNED_SHORT = 0x1403;
constexpr GLenum GL_FLOAT = 0x1406;
constexpr GLenum GL_FIXED = 0x140C;
constexpr GLenum GL_CLEAR = 0x1500;
constexpr GLenum GL_AND = 0x1501;
constexpr GLenum GL_AND_REVERSE = 0x1502;
constexpr GLenum GL_COPY = 0x1503;
constexpr GLenum GL_AND_INVERTED = 0x1504;
constexpr GLenum GL_NOOP = 0x1505;
constexpr GLenum GL_XOR = 0x1506;
constexpr GLenum GL_OR = 0x1507;
constexpr GLenum GL_NOR = 0x1508;
constexpr GLenum GL_EQUIV = 0x1509;
constexpr GLenum GL_INVERT = 0x150A;
constexpr GLenum GL_OR_REVERSE = 0x150B;
constexpr GLenum GL_COPY_INVERTED = 0x150C;
constexpr GLenum GL_OR_INVERTED = 0x150D;
constexpr GLenum GL_NAND = 0x150E;
constexpr GLenum GL_SET = 0x150F;
constexpr GLenum GL_EMISSION = 0x1600;
constexpr GLenum GL_SHININESS = 0x1601;
constexpr GLenum GL_AMBIENT_AND_DIFFUSE = 0x1602;
constexpr GLenum GL_MODELVIEW = 0x1700;
constexpr GLenum GL_PROJECTION = 0x1701;
constexpr GLenum GL_TEXTURE = 0x1702;
constexpr GLenum GL_ALPHA = 0x1906;
constexpr GLenum GL_RGB = 0x1907;
constexpr GLenum GL_RGBA = 0x1908;
constexpr GLenum GL_LUMINANCE = 0x1909;
constexpr GLenum GL_LUMINANCE_ALPHA = 0x190A;
constexpr GLenum GL_UNPACK_ALIGNMENT = 0x0CF5;
constexpr GLenum GL_PACK_ALIGNMENT = 0x0D05;
constexpr GLenum GL_UNSIGNED_SHORT_4_4_4_4 = 0x8033;
constexpr GLenum GL_UNSIGNED_SHORT_5_5_5_1 = 0x8034;
constexpr GLenum GL_UNSIGNED_SHORT_5_6_5 = 0x8363;
constexpr GLenum GL_FLAT = 0x1D00;
constexpr GLenum GL_SMOOTH = 0x1D01;
constexpr GLenum GL_KEEP = 0x1E00;
constexpr GLenum GL_REPLACE = 0x1E01;
constexpr GLenum GL_INCR = 0x1E02;
constexpr GLenum GL_DECR = 0x1E03;
constexpr GLenum GL_VENDOR = 0x1F00;
constexpr GLenum GL_RENDERER = 0x1F01;
constexpr GLenum GL_VERSION = 0x1F02;
constexpr GLenum GL_EXTENSIONS = 0x1F03;
constexpr GLenum GL_MODULATE = 0x2100;
constexpr GLenum GL_DECAL = 0x2101;
constexpr GLenum GL_ADD = 0x0104;
constexpr GLenum GL_TEXTURE_ENV_MODE = 0x2200;
constexpr GLenum GL_TEXTURE_ENV_COLOR = 0x2201;
constexpr GLenum GL_TEXTURE_ENV = 0x2300;
constexpr GLenum GL_NEAREST = 0x2600;
constexpr GLenum GL_LINEAR = 0x2601;
constexpr GLenum GL_NEAREST_MIPMAP_NEAREST = 0x2700;
constexpr GLenum GL_LINEAR_MIPMAP_NEAREST = 0x2701;
constexpr GLenum GL_NEAREST_MIPMAP_LINEAR = 0x2702;
constexpr GLenum GL_LINEAR_MIPMAP_LINEAR = 0x2703;
constexpr GLenum GL_TEXTURE_MAG_FILTER = 0x2800;
constexpr GLenum GL_TEXTURE_MIN_FILTER = 0x2801;
constexpr GLenum GL_TEXTURE_WRAP_S = 0x2802;
constexpr GLenum GL_TEXTURE_WRAP_T = 0x2803;
constexpr GLenum GL_GENERATE_MIPMAP = 0x8191;
constexpr GLenum GL_TEXTURE0 = 0x84C0;
constexpr GLenum GL_TEXTURE1 = 0x84C1;
constexpr GLenum GL_TEXTURE2 = 0x84C2;
constexpr GLenum GL_TEXTURE3 = 0x84C3;
constexpr GLenum GL_TEXTURE4 = 0x84C4;
constexpr GLenum GL_TEXTURE5 = 0x84C5;
constexpr GLenum GL_TEXTURE6 = 0x84C6;
constexpr GLenum GL_TEXTURE7 = 0x84C7;
constexpr GLenum GL_TEXTURE8 = 0x84C8;
constexpr GLenum GL_TEXTURE9 = 0x84C9;
constexpr GLenum GL_TEXTURE10 = 0x84CA;
constexpr GLenum GL_TEXTURE11 = 0x84CB;
constexpr GLenum GL_TEXTURE12 = 0x84CC;
constexpr GLenum GL_TEXTURE13 = 0x84CD;
constexpr GLenum GL_TEXTURE14 = 0x84CE;
constexpr GLenum GL_TEXTURE15 = 0x84CF;
constexpr GLenum GL_TEXTURE16 = 0x84D0;
constexpr GLenum GL_TEXTURE17 = 0x84D1;
constexpr GLenum GL_TEXTURE18 = 0x84D2;
constexpr GLenum GL_TEXTURE19 = 0x84D3;
constexpr GLenum GL_TEXTURE20 = 0x84D4;
constexpr GLenum GL_TEXTURE21 = 0x84D5;
constexpr GLenum GL_TEXTURE22 = 0x84D6;
constexpr GLenum GL_TEXTURE23 = 0x84D7;
constexpr GLenum GL_TEXTURE24 = 0x84D8;
constexpr GLenum GL_TEXTURE25 = 0x84D9;
constexpr GLenum GL_TEXTURE26 = 0x84DA;
constexpr GLenum GL_TEXTURE27 = 0x84DB;
constexpr GLenum GL_TEXTURE28 = 0x84DC;
constexpr GLenum GL_TEXTURE29 = 0x84DD;
constexpr GLenum GL_TEXTURE30 = 0x84DE;
constexpr GLenum GL_TEXTURE31 = 0x84DF;
constexpr GLenum GL_ACTIVE_TEXTURE = 0x84E0;
constexpr GLenum GL_CLIENT_ACTIVE_TEXTURE = 0x84E1;
constexpr GLenum GL_REPEAT = 0x2901;
constexpr GLenum GL_CLAMP_TO_EDGE = 0x812F;
constexpr GLenum GL_LIGHT0 = 0x4000;
constexpr GLenum GL_LIGHT1 = 0x4001;
constexpr GLenum GL_LIGHT2 = 0x4002;
constexpr GLenum GL_LIGHT3 = 0x4003;
constexpr GLenum GL_LIGHT4 = 0x4004;
constexpr GLenum GL_LIGHT5 = 0x4005;
constexpr GLenum GL_LIGHT6 = 0x4006;
constexpr GLenum GL_LIGHT7 = 0x4007;
constexpr GLenum GL_ARRAY_BUFFER = 0x8892;
constexpr GLenum GL_ELEMENT_ARRAY_BUFFER = 0x8893;
constexpr GLenum GL_ARRAY_BUFFER_BINDING = 0x8894;
constexpr GLenum GL_ELEMENT_ARRAY_BUFFER_BINDING = 0x8895;
constexpr GLenum GL_VERTEX_ARRAY_BUFFER_BINDING = 0x8896;
constexpr GLenum GL_NORMAL_ARRAY_BUFFER_BINDING = 0x8897;
constexpr GLenum GL_COLOR_ARRAY_BUFFER_BINDING = 0x8898;
constexpr GLenum GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING = 0x889A;
constexpr GLenum GL_STATIC_DRAW = 0x88E4;
constexpr GLenum GL_DYNAMIC_DRAW = 0x88E8;
constexpr GLenum GL_BUFFER_SIZE = 0x8764;
constexpr GLenum GL_BUFFER_USAGE = 0x8765;
constexpr GLenum GL_SUBTRACT = 0x84E7;
constexpr GLenum GL_COMBINE = 0x8570;
constexpr GLenum GL_COMBINE_RGB = 0x8571;
constexpr GLenum GL_COMBINE_ALPHA = 0x8572;
constexpr GLenum GL_RGB_SCALE = 0x8573;
constexpr GLenum GL_ADD_SIGNED = 0x8574;
constexpr GLenum GL_INTERPOLATE = 0x8575;
constexpr GLenum GL_CONSTANT = 0x8576;
constexpr GLenum GL_PRIMARY_COLOR = 0x8577;
constexpr GLenum GL_PREVIOUS = 0x8578;
constexpr GLenum GL_OPERAND0_RGB = 0x8590;
constexpr GLenum GL_OPERAND1_RGB = 0x8591;
constexpr GLenum GL_OPERAND2_RGB = 0x8592;
constexpr GLenum GL_OPERAND0_ALPHA = 0x8598;
constexpr GLenum GL_OPERAND1_ALPHA = 0x8599;
constexpr GLenum GL_OPERAND2_ALPHA = 0x859A;
constexpr GLenum GL_ALPHA_SCALE = 0x0D1C;
constexpr GLenum GL_SRC0_RGB = 0x8580;
constexpr GLenum GL_SRC1_RGB = 0x8581;
constexpr GLenum GL_SRC2_RGB = 0x8582;
constexpr GLenum GL_SRC0_ALPHA = 0x8588;
constexpr GLenum GL_SRC1_ALPHA = 0x8589;
constexpr GLenum GL_SRC2_ALPHA = 0x858A;
constexpr GLenum GL_DOT3_RGB = 0x86AE;
constexpr GLenum GL_DOT3_RGBA = 0x86AF;
void glAlphaFunc(GLenum func, GLfloat ref);
void glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
void glClearDepthf(GLfloat d);
void glClipPlanef(GLenum p, GLfloat const  * eqn);
void glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
void glDepthRangef(GLfloat n, GLfloat f);
void glFogf(GLenum pname, GLfloat param);
void glFogfv(GLenum pname, GLfloat const  * params);
void glFrustumf(GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f);
void glGetClipPlanef(GLenum plane, GLfloat * equation);
void glGetFloatv(GLenum pname, GLfloat * data);
void glGetLightfv(GLenum light, GLenum pname, GLfloat * params);
void glGetMaterialfv(GLenum face, GLenum pname, GLfloat * params);
void glGetTexEnvfv(GLenum target, GLenum pname, GLfloat * params);
void glGetTexParameterfv(GLenum target, GLenum pname, GLfloat * params);
void glLightModelf(GLenum pname, GLfloat param);
void glLightModelfv(GLenum pname, GLfloat const  * params);
void glLightf(GLenum light, GLenum pname, GLfloat param);
void glLightfv(GLenum light, GLenum pname, GLfloat const  * params);
void glLineWidth(GLfloat width);
void glLoadMatrixf(GLfloat const  * m);
void glMaterialf(GLenum face, GLenum pname, GLfloat param);
void glMaterialfv(GLenum face, GLenum pname, GLfloat const  * params);
void glMultMatrixf(GLfloat const  * m);
void glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
void glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz);
void glOrthof(GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f);
void glPointParameterf(GLenum pname, GLfloat param);
void glPointParameterfv(GLenum pname, GLfloat const  * params);
void glPointSize(GLfloat size);
void glPolygonOffset(GLfloat factor, GLfloat units);
void glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
void glScalef(GLfloat x, GLfloat y, GLfloat z);
void glTexEnvf(GLenum target, GLenum pname, GLfloat param);
void glTexEnvfv(GLenum target, GLenum pname, GLfloat const  * params);
void glTexParameterf(GLenum target, GLenum pname, GLfloat param);
void glTexParameterfv(GLenum target, GLenum pname, GLfloat const  * params);
void glTranslatef(GLfloat x, GLfloat y, GLfloat z);
void glActiveTexture(GLenum texture);
void glAlphaFuncx(GLenum func, GLfixed ref);
void glBindBuffer(GLenum target, GLuint buffer);
void glBindTexture(GLenum target, GLuint texture);
void glBlendFunc(GLenum sfactor, GLenum dfactor);
void glBufferData(GLenum target, GLsizeiptr size, const void * data, GLenum usage);
void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const void * data);
void glClear(GLbitfield mask);
void glClearColorx(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha);
void glClearDepthx(GLfixed depth);
void glClearStencil(GLint s);
void glClientActiveTexture(GLenum texture);
void glClipPlanex(GLenum plane, GLfixed const  * equation);
void glColor4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
void glColor4x(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha);
void glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
void glColorPointer(GLint size, GLenum type, GLsizei stride, const void * pointer);
void glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void * data);
void glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * data);
void glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
void glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
void glCullFace(GLenum mode);
void glDeleteBuffers(GLsizei n, GLuint const  * buffers);
void glDeleteTextures(GLsizei n, GLuint const  * textures);
void glDepthFunc(GLenum func);
void glDepthMask(GLboolean flag);
void glDepthRangex(GLfixed n, GLfixed f);
void glDisable(GLenum cap);
void glDisableClientState(GLenum array);
void glDrawArrays(GLenum mode, GLint first, GLsizei count);
void glDrawElements(GLenum mode, GLsizei count, GLenum type, const void * indices);
void glEnable(GLenum cap);
void glEnableClientState(GLenum array);
void glFinish();
void glFlush();
void glFogx(GLenum pname, GLfixed param);
void glFogxv(GLenum pname, GLfixed const  * param);
void glFrontFace(GLenum mode);
void glFrustumx(GLfixed l, GLfixed r, GLfixed b, GLfixed t, GLfixed n, GLfixed f);
void glGetBooleanv(GLenum pname, GLboolean * data);
void glGetBufferParameteriv(GLenum target, GLenum pname, GLint * params);
void glGetClipPlanex(GLenum plane, GLfixed * equation);
void glGenBuffers(GLsizei n, GLuint * buffers);
void glGenTextures(GLsizei n, GLuint * textures);
GLenum glGetError();
void glGetFixedv(GLenum pname, GLfixed * params);
void glGetIntegerv(GLenum pname, GLint * data);
void glGetLightxv(GLenum light, GLenum pname, GLfixed * params);
void glGetMaterialxv(GLenum face, GLenum pname, GLfixed * params);
void glGetPointerv(GLenum pname, void ** params);
GLubyte const  * glGetString(GLenum name);
void glGetTexEnviv(GLenum target, GLenum pname, GLint * params);
void glGetTexEnvxv(GLenum target, GLenum pname, GLfixed * params);
void glGetTexParameteriv(GLenum target, GLenum pname, GLint * params);
void glGetTexParameterxv(GLenum target, GLenum pname, GLfixed * params);
void glHint(GLenum target, GLenum mode);
GLboolean glIsBuffer(GLuint buffer);
GLboolean glIsEnabled(GLenum cap);
GLboolean glIsTexture(GLuint texture);
void glLightModelx(GLenum pname, GLfixed param);
void glLightModelxv(GLenum pname, GLfixed const  * param);
void glLightx(GLenum light, GLenum pname, GLfixed param);
void glLightxv(GLenum light, GLenum pname, GLfixed const  * params);
void glLineWidthx(GLfixed width);
void glLoadIdentity();
void glLoadMatrixx(GLfixed const  * m);
void glLogicOp(GLenum opcode);
void glMaterialx(GLenum face, GLenum pname, GLfixed param);
void glMaterialxv(GLenum face, GLenum pname, GLfixed const  * param);
void glMatrixMode(GLenum mode);
void glMultMatrixx(GLfixed const  * m);
void glMultiTexCoord4x(GLenum texture, GLfixed s, GLfixed t, GLfixed r, GLfixed q);
void glNormal3x(GLfixed nx, GLfixed ny, GLfixed nz);
void glNormalPointer(GLenum type, GLsizei stride, const void * pointer);
void glOrthox(GLfixed l, GLfixed r, GLfixed b, GLfixed t, GLfixed n, GLfixed f);
void glPixelStorei(GLenum pname, GLint param);
void glPointParameterx(GLenum pname, GLfixed param);
void glPointParameterxv(GLenum pname, GLfixed const  * params);
void glPointSizex(GLfixed size);
void glPolygonOffsetx(GLfixed factor, GLfixed units);
void glPopMatrix();
void glPushMatrix();
void glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void * pixels);
void glRotatex(GLfixed angle, GLfixed x, GLfixed y, GLfixed z);
void glSampleCoverage(GLfloat value, GLboolean invert);
void glSampleCoveragex(GLclampx value, GLboolean invert);
void glScalex(GLfixed x, GLfixed y, GLfixed z);
void glScissor(GLint x, GLint y, GLsizei width, GLsizei height);
void glShadeModel(GLenum mode);
void glStencilFunc(GLenum func, GLint ref, GLuint mask);
void glStencilMask(GLuint mask);
void glStencilOp(GLenum fail, GLenum zfail, GLenum zpass);
void glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const void * pointer);
void glTexEnvi(GLenum target, GLenum pname, GLint param);
void glTexEnvx(GLenum target, GLenum pname, GLfixed param);
void glTexEnviv(GLenum target, GLenum pname, GLint const  * params);
void glTexEnvxv(GLenum target, GLenum pname, GLfixed const  * params);
void glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void * pixels);
void glTexParameteri(GLenum target, GLenum pname, GLint param);
void glTexParameterx(GLenum target, GLenum pname, GLfixed param);
void glTexParameteriv(GLenum target, GLenum pname, GLint const  * params);
void glTexParameterxv(GLenum target, GLenum pname, GLfixed const  * params);
void glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels);
void glTranslatex(GLfixed x, GLfixed y, GLfixed z);
void glVertexPointer(GLint size, GLenum type, GLsizei stride, const void * pointer);
void glViewport(GLint x, GLint y, GLsizei width, GLsizei height);
#endif /* GL_VERSION_ES_CM_1_0 */
#ifndef GL_ES_VERSION_2_0
#define GL_ES_VERSION_2_0 1
constexpr GLenum GL_FUNC_ADD = 0x8006;
constexpr GLenum GL_BLEND_EQUATION = 0x8009;
constexpr GLenum GL_BLEND_EQUATION_RGB = 0x8009;
constexpr GLenum GL_BLEND_EQUATION_ALPHA = 0x883D;
constexpr GLenum GL_FUNC_SUBTRACT = 0x800A;
constexpr GLenum GL_FUNC_REVERSE_SUBTRACT = 0x800B;
constexpr GLenum GL_BLEND_DST_RGB = 0x80C8;
constexpr GLenum GL_BLEND_SRC_RGB = 0x80C9;
constexpr GLenum GL_BLEND_DST_ALPHA = 0x80CA;
constexpr GLenum GL_BLEND_SRC_ALPHA = 0x80CB;
constexpr GLenum GL_CONSTANT_COLOR = 0x8001;
constexpr GLenum GL_ONE_MINUS_CONSTANT_COLOR = 0x8002;
constexpr GLenum GL_CONSTANT_ALPHA = 0x8003;
constexpr GLenum GL_ONE_MINUS_CONSTANT_ALPHA = 0x8004;
constexpr GLenum GL_BLEND_COLOR = 0x8005;
constexpr GLenum GL_STREAM_DRAW = 0x88E0;
constexpr GLenum GL_CURRENT_VERTEX_ATTRIB = 0x8626;
constexpr GLenum GL_STENCIL_BACK_FUNC = 0x8800;
constexpr GLenum GL_STENCIL_BACK_FAIL = 0x8801;
constexpr GLenum GL_STENCIL_BACK_PASS_DEPTH_FAIL = 0x8802;
constexpr GLenum GL_STENCIL_BACK_PASS_DEPTH_PASS = 0x8803;
constexpr GLenum GL_STENCIL_BACK_REF = 0x8CA3;
constexpr GLenum GL_STENCIL_BACK_VALUE_MASK = 0x8CA4;
constexpr GLenum GL_STENCIL_BACK_WRITEMASK = 0x8CA5;
constexpr GLenum GL_INT = 0x1404;
constexpr GLenum GL_UNSIGNED_INT = 0x1405;
constexpr GLenum GL_DEPTH_COMPONENT = 0x1902;
constexpr GLenum GL_FRAGMENT_SHADER = 0x8B30;
constexpr GLenum GL_VERTEX_SHADER = 0x8B31;
constexpr GLenum GL_MAX_VERTEX_ATTRIBS = 0x8869;
constexpr GLenum GL_MAX_VERTEX_UNIFORM_VECTORS = 0x8DFB;
constexpr GLenum GL_MAX_VARYING_VECTORS = 0x8DFC;
constexpr GLenum GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS = 0x8B4D;
constexpr GLenum GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS = 0x8B4C;
constexpr GLenum GL_MAX_TEXTURE_IMAGE_UNITS = 0x8872;
constexpr GLenum GL_MAX_FRAGMENT_UNIFORM_VECTORS = 0x8DFD;
constexpr GLenum GL_SHADER_TYPE = 0x8B4F;
constexpr GLenum GL_DELETE_STATUS = 0x8B80;
constexpr GLenum GL_LINK_STATUS = 0x8B82;
constexpr GLenum GL_VALIDATE_STATUS = 0x8B83;
constexpr GLenum GL_ATTACHED_SHADERS = 0x8B85;
constexpr GLenum GL_ACTIVE_UNIFORMS = 0x8B86;
constexpr GLenum GL_ACTIVE_UNIFORM_MAX_LENGTH = 0x8B87;
constexpr GLenum GL_ACTIVE_ATTRIBUTES = 0x8B89;
constexpr GLenum GL_ACTIVE_ATTRIBUTE_MAX_LENGTH = 0x8B8A;
constexpr GLenum GL_SHADING_LANGUAGE_VERSION = 0x8B8C;
constexpr GLenum GL_CURRENT_PROGRAM = 0x8B8D;
constexpr GLenum GL_INCR_WRAP = 0x8507;
constexpr GLenum GL_DECR_WRAP = 0x8508;
constexpr GLenum GL_TEXTURE_CUBE_MAP = 0x8513;
constexpr GLenum GL_TEXTURE_BINDING_CUBE_MAP = 0x8514;
constexpr GLenum GL_TEXTURE_CUBE_MAP_POSITIVE_X = 0x8515;
constexpr GLenum GL_TEXTURE_CUBE_MAP_NEGATIVE_X = 0x8516;
constexpr GLenum GL_TEXTURE_CUBE_MAP_POSITIVE_Y = 0x8517;
constexpr GLenum GL_TEXTURE_CUBE_MAP_NEGATIVE_Y = 0x8518;
constexpr GLenum GL_TEXTURE_CUBE_MAP_POSITIVE_Z = 0x8519;
constexpr GLenum GL_TEXTURE_CUBE_MAP_NEGATIVE_Z = 0x851A;
constexpr GLenum GL_MAX_CUBE_MAP_TEXTURE_SIZE = 0x851C;
constexpr GLenum GL_MIRRORED_REPEAT = 0x8370;
constexpr GLenum GL_FLOAT_VEC2 = 0x8B50;
constexpr GLenum GL_FLOAT_VEC3 = 0x8B51;
constexpr GLenum GL_FLOAT_VEC4 = 0x8B52;
constexpr GLenum GL_INT_VEC2 = 0x8B53;
constexpr GLenum GL_INT_VEC3 = 0x8B54;
constexpr GLenum GL_INT_VEC4 = 0x8B55;
constexpr GLenum GL_BOOL = 0x8B56;
constexpr GLenum GL_BOOL_VEC2 = 0x8B57;
constexpr GLenum GL_BOOL_VEC3 = 0x8B58;
constexpr GLenum GL_BOOL_VEC4 = 0x8B59;
constexpr GLenum GL_FLOAT_MAT2 = 0x8B5A;
constexpr GLenum GL_FLOAT_MAT3 = 0x8B5B;
constexpr GLenum GL_FLOAT_MAT4 = 0x8B5C;
constexpr GLenum GL_SAMPLER_2D = 0x8B5E;
constexpr GLenum GL_SAMPLER_CUBE = 0x8B60;
constexpr GLenum GL_VERTEX_ATTRIB_ARRAY_ENABLED = 0x8622;
constexpr GLenum GL_VERTEX_ATTRIB_ARRAY_SIZE = 0x8623;
constexpr GLenum GL_VERTEX_ATTRIB_ARRAY_STRIDE = 0x8624;
constexpr GLenum GL_VERTEX_ATTRIB_ARRAY_TYPE = 0x8625;
constexpr GLenum GL_VERTEX_ATTRIB_ARRAY_NORMALIZED = 0x886A;
constexpr GLenum GL_VERTEX_ATTRIB_ARRAY_POINTER = 0x8645;
constexpr GLenum GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING = 0x889F;
constexpr GLenum GL_IMPLEMENTATION_COLOR_READ_TYPE = 0x8B9A;
constexpr GLenum GL_IMPLEMENTATION_COLOR_READ_FORMAT = 0x8B9B;
constexpr GLenum GL_COMPILE_STATUS = 0x8B81;
constexpr GLenum GL_INFO_LOG_LENGTH = 0x8B84;
constexpr GLenum GL_SHADER_SOURCE_LENGTH = 0x8B88;
constexpr GLenum GL_SHADER_COMPILER = 0x8DFA;
constexpr GLenum GL_SHADER_BINARY_FORMATS = 0x8DF8;
constexpr GLenum GL_NUM_SHADER_BINARY_FORMATS = 0x8DF9;
constexpr GLenum GL_LOW_FLOAT = 0x8DF0;
constexpr GLenum GL_MEDIUM_FLOAT = 0x8DF1;
constexpr GLenum GL_HIGH_FLOAT = 0x8DF2;
constexpr GLenum GL_LOW_INT = 0x8DF3;
constexpr GLenum GL_MEDIUM_INT = 0x8DF4;
constexpr GLenum GL_HIGH_INT = 0x8DF5;
constexpr GLenum GL_FRAMEBUFFER = 0x8D40;
constexpr GLenum GL_RENDERBUFFER = 0x8D41;
constexpr GLenum GL_RGBA4 = 0x8056;
constexpr GLenum GL_RGB5_A1 = 0x8057;
constexpr GLenum GL_RGB565 = 0x8D62;
constexpr GLenum GL_DEPTH_COMPONENT16 = 0x81A5;
constexpr GLenum GL_STENCIL_INDEX8 = 0x8D48;
constexpr GLenum GL_RENDERBUFFER_WIDTH = 0x8D42;
constexpr GLenum GL_RENDERBUFFER_HEIGHT = 0x8D43;
constexpr GLenum GL_RENDERBUFFER_INTERNAL_FORMAT = 0x8D44;
constexpr GLenum GL_RENDERBUFFER_RED_SIZE = 0x8D50;
constexpr GLenum GL_RENDERBUFFER_GREEN_SIZE = 0x8D51;
constexpr GLenum GL_RENDERBUFFER_BLUE_SIZE = 0x8D52;
constexpr GLenum GL_RENDERBUFFER_ALPHA_SIZE = 0x8D53;
constexpr GLenum GL_RENDERBUFFER_DEPTH_SIZE = 0x8D54;
constexpr GLenum GL_RENDERBUFFER_STENCIL_SIZE = 0x8D55;
constexpr GLenum GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE = 0x8CD0;
constexpr GLenum GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME = 0x8CD1;
constexpr GLenum GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL = 0x8CD2;
constexpr GLenum GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE = 0x8CD3;
constexpr GLenum GL_COLOR_ATTACHMENT0 = 0x8CE0;
constexpr GLenum GL_DEPTH_ATTACHMENT = 0x8D00;
constexpr GLenum GL_STENCIL_ATTACHMENT = 0x8D20;
constexpr GLenum GL_NONE = 0;
constexpr GLenum GL_FRAMEBUFFER_COMPLETE = 0x8CD5;
constexpr GLenum GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT = 0x8CD6;
constexpr GLenum GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT = 0x8CD7;
constexpr GLenum GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS = 0x8CD9;
constexpr GLenum GL_FRAMEBUFFER_UNSUPPORTED = 0x8CDD;
constexpr GLenum GL_FRAMEBUFFER_BINDING = 0x8CA6;
constexpr GLenum GL_RENDERBUFFER_BINDING = 0x8CA7;
constexpr GLenum GL_MAX_RENDERBUFFER_SIZE = 0x84E8;
constexpr GLenum GL_INVALID_FRAMEBUFFER_OPERATION = 0x0506;
void glAttachShader(GLuint program, GLuint shader);
void glBindAttribLocation(GLuint program, GLuint index, GLchar const  * name);
void glBindFramebuffer(GLenum target, GLuint framebuffer);
void glBindRenderbuffer(GLenum target, GLuint renderbuffer);
void glBlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
void glBlendEquation(GLenum mode);
void glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha);
void glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
GLenum glCheckFramebufferStatus(GLenum target);
void glCompileShader(GLuint shader);
GLuint glCreateProgram();
GLuint glCreateShader(GLenum type);
void glDeleteFramebuffers(GLsizei n, GLuint const  * framebuffers);
void glDeleteProgram(GLuint program);
void glDeleteRenderbuffers(GLsizei n, GLuint const  * renderbuffers);
void glDeleteShader(GLuint shader);
void glDetachShader(GLuint program, GLuint shader);
void glDisableVertexAttribArray(GLuint index);
void glEnableVertexAttribArray(GLuint index);
void glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
void glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
void glGenerateMipmap(GLenum target);
void glGenFramebuffers(GLsizei n, GLuint * framebuffers);
void glGenRenderbuffers(GLsizei n, GLuint * renderbuffers);
void glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name);
void glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name);
void glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei * count, GLuint * shaders);
GLint glGetAttribLocation(GLuint program, GLchar const  * name);
void glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint * params);
void glGetProgramiv(GLuint program, GLenum pname, GLint * params);
void glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei * length, GLchar * infoLog);
void glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint * params);
void glGetShaderiv(GLuint shader, GLenum pname, GLint * params);
void glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * infoLog);
void glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint * range, GLint * precision);
void glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * source);
void glGetUniformfv(GLuint program, GLint location, GLfloat * params);
void glGetUniformiv(GLuint program, GLint location, GLint * params);
GLint glGetUniformLocation(GLuint program, GLchar const  * name);
void glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat * params);
void glGetVertexAttribiv(GLuint index, GLenum pname, GLint * params);
void glGetVertexAttribPointerv(GLuint index, GLenum pname, void ** pointer);
GLboolean glIsFramebuffer(GLuint framebuffer);
GLboolean glIsProgram(GLuint program);
GLboolean glIsRenderbuffer(GLuint renderbuffer);
GLboolean glIsShader(GLuint shader);
void glLinkProgram(GLuint program);
void glReleaseShaderCompiler();
void glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
void glShaderBinary(GLsizei count, GLuint const  * shaders, GLenum binaryformat, const void * binary, GLsizei length);
void glShaderSource(GLuint shader, GLsizei count, GLchar const  *const* string, GLint const  * length);
void glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask);
void glStencilMaskSeparate(GLenum face, GLuint mask);
void glStencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
void glUniform1f(GLint location, GLfloat v0);
void glUniform1fv(GLint location, GLsizei count, GLfloat const  * value);
void glUniform1i(GLint location, GLint v0);
void glUniform1iv(GLint location, GLsizei count, GLint const  * value);
void glUniform2f(GLint location, GLfloat v0, GLfloat v1);
void glUniform2fv(GLint location, GLsizei count, GLfloat const  * value);
void glUniform2i(GLint location, GLint v0, GLint v1);
void glUniform2iv(GLint location, GLsizei count, GLint const  * value);
void glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
void glUniform3fv(GLint location, GLsizei count, GLfloat const  * value);
void glUniform3i(GLint location, GLint v0, GLint v1, GLint v2);
void glUniform3iv(GLint location, GLsizei count, GLint const  * value);
void glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
void glUniform4fv(GLint location, GLsizei count, GLfloat const  * value);
void glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
void glUniform4iv(GLint location, GLsizei count, GLint const  * value);
void glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value);
void glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value);
void glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value);
void glUseProgram(GLuint program);
void glValidateProgram(GLuint program);
void glVertexAttrib1f(GLuint index, GLfloat x);
void glVertexAttrib1fv(GLuint index, GLfloat const  * v);
void glVertexAttrib2f(GLuint index, GLfloat x, GLfloat y);
void glVertexAttrib2fv(GLuint index, GLfloat const  * v);
void glVertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z);
void glVertexAttrib3fv(GLuint index, GLfloat const  * v);
void glVertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void glVertexAttrib4fv(GLuint index, GLfloat const  * v);
void glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void * pointer);
#endif /* GL_ES_VERSION_2_0 */
#ifndef GL_EXT_EGL_image_array
#define GL_EXT_EGL_image_array 1
#endif /* GL_EXT_EGL_image_array */
#ifndef GL_EXT_EGL_image_storage
#define GL_EXT_EGL_image_storage 1
void glEGLImageTargetTexStorageEXT(GLenum target, GLeglImageOES image, GLint const * attrib_list);
void glEGLImageTargetTextureStorageEXT(GLuint texture, GLeglImageOES image, GLint const * attrib_list);
#endif /* GL_EXT_EGL_image_storage */
#ifndef GL_EXT_YUV_target
#define GL_EXT_YUV_target 1
constexpr GLenum GL_SAMPLER_EXTERNAL_2D_Y2Y_EXT = 0x8BE7;
constexpr GLenum GL_TEXTURE_EXTERNAL_OES = 0x8D65;
constexpr GLenum GL_TEXTURE_BINDING_EXTERNAL_OES = 0x8D67;
constexpr GLenum GL_REQUIRED_TEXTURE_IMAGE_UNITS_OES = 0x8D68;
#endif /* GL_EXT_YUV_target */
#ifndef GL_EXT_base_instance
#define GL_EXT_base_instance 1
void glDrawArraysInstancedBaseInstanceEXT(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
void glDrawElementsInstancedBaseInstanceEXT(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLuint baseinstance);
void glDrawElementsInstancedBaseVertexBaseInstanceEXT(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
#endif /* GL_EXT_base_instance */
#ifndef GL_EXT_blend_func_extended
#define GL_EXT_blend_func_extended 1
constexpr GLenum GL_SRC1_COLOR_EXT = 0x88F9;
constexpr GLenum GL_SRC1_ALPHA_EXT = 0x8589;
constexpr GLenum GL_ONE_MINUS_SRC1_COLOR_EXT = 0x88FA;
constexpr GLenum GL_ONE_MINUS_SRC1_ALPHA_EXT = 0x88FB;
constexpr GLenum GL_SRC_ALPHA_SATURATE_EXT = 0x0308;
constexpr GLenum GL_LOCATION_INDEX_EXT = 0x930F;
constexpr GLenum GL_MAX_DUAL_SOURCE_DRAW_BUFFERS_EXT = 0x88FC;
void glBindFragDataLocationIndexedEXT(GLuint program, GLuint colorNumber, GLuint index, GLchar const  * name);
void glBindFragDataLocationEXT(GLuint program, GLuint color, GLchar const  * name);
GLint glGetProgramResourceLocationIndexEXT(GLuint program, GLenum programInterface, GLchar const  * name);
GLint glGetFragDataIndexEXT(GLuint program, GLchar const  * name);
#endif /* GL_EXT_blend_func_extended */
#ifndef GL_EXT_blend_minmax
#define GL_EXT_blend_minmax 1
constexpr GLenum GL_MIN_EXT = 0x8007;
constexpr GLenum GL_MAX_EXT = 0x8008;
constexpr GLenum GL_FUNC_ADD_EXT = 0x8006;
constexpr GLenum GL_BLEND_EQUATION_EXT = 0x8009;
void glBlendEquationEXT(GLenum mode);
#endif /* GL_EXT_blend_minmax */
#ifndef GL_EXT_buffer_storage
#define GL_EXT_buffer_storage 1
constexpr GLenum GL_MAP_READ_BIT = 0x0001;
constexpr GLenum GL_MAP_WRITE_BIT = 0x0002;
constexpr GLenum GL_MAP_PERSISTENT_BIT_EXT = 0x0040;
constexpr GLenum GL_MAP_COHERENT_BIT_EXT = 0x0080;
constexpr GLenum GL_DYNAMIC_STORAGE_BIT_EXT = 0x0100;
constexpr GLenum GL_CLIENT_STORAGE_BIT_EXT = 0x0200;
constexpr GLenum GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT_EXT = 0x00004000;
constexpr GLenum GL_BUFFER_IMMUTABLE_STORAGE_EXT = 0x821F;
constexpr GLenum GL_BUFFER_STORAGE_FLAGS_EXT = 0x8220;
void glBufferStorageEXT(GLenum target, GLsizeiptr size, const void * data, GLbitfield flags);
#endif /* GL_EXT_buffer_storage */
#ifndef GL_EXT_clear_texture
#define GL_EXT_clear_texture 1
void glClearTexImageEXT(GLuint texture, GLint level, GLenum format, GLenum type, const void * data);
void glClearTexSubImageEXT(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * data);
#endif /* GL_EXT_clear_texture */
#ifndef GL_EXT_clip_control
#define GL_EXT_clip_control 1
constexpr GLenum GL_LOWER_LEFT_EXT = 0x8CA1;
constexpr GLenum GL_UPPER_LEFT_EXT = 0x8CA2;
constexpr GLenum GL_NEGATIVE_ONE_TO_ONE_EXT = 0x935E;
constexpr GLenum GL_ZERO_TO_ONE_EXT = 0x935F;
constexpr GLenum GL_CLIP_ORIGIN_EXT = 0x935C;
constexpr GLenum GL_CLIP_DEPTH_MODE_EXT = 0x935D;
void glClipControlEXT(GLenum origin, GLenum depth);
#endif /* GL_EXT_clip_control */
#ifndef GL_EXT_clip_cull_distance
#define GL_EXT_clip_cull_distance 1
constexpr GLenum GL_MAX_CLIP_DISTANCES_EXT = 0x0D32;
constexpr GLenum GL_MAX_CULL_DISTANCES_EXT = 0x82F9;
constexpr GLenum GL_MAX_COMBINED_CLIP_AND_CULL_DISTANCES_EXT = 0x82FA;
constexpr GLenum GL_CLIP_DISTANCE0_EXT = 0x3000;
constexpr GLenum GL_CLIP_DISTANCE1_EXT = 0x3001;
constexpr GLenum GL_CLIP_DISTANCE2_EXT = 0x3002;
constexpr GLenum GL_CLIP_DISTANCE3_EXT = 0x3003;
constexpr GLenum GL_CLIP_DISTANCE4_EXT = 0x3004;
constexpr GLenum GL_CLIP_DISTANCE5_EXT = 0x3005;
constexpr GLenum GL_CLIP_DISTANCE6_EXT = 0x3006;
constexpr GLenum GL_CLIP_DISTANCE7_EXT = 0x3007;
#endif /* GL_EXT_clip_cull_distance */
#ifndef GL_EXT_color_buffer_float
#define GL_EXT_color_buffer_float 1
#endif /* GL_EXT_color_buffer_float */
#ifndef GL_EXT_color_buffer_half_float
#define GL_EXT_color_buffer_half_float 1
constexpr GLenum GL_RGBA16F_EXT = 0x881A;
constexpr GLenum GL_RGB16F_EXT = 0x881B;
constexpr GLenum GL_RG16F_EXT = 0x822F;
constexpr GLenum GL_R16F_EXT = 0x822D;
constexpr GLenum GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE_EXT = 0x8211;
constexpr GLenum GL_UNSIGNED_NORMALIZED_EXT = 0x8C17;
#endif /* GL_EXT_color_buffer_half_float */
#ifndef GL_EXT_conservative_depth
#define GL_EXT_conservative_depth 1
#endif /* GL_EXT_conservative_depth */
#ifndef GL_EXT_copy_image
#define GL_EXT_copy_image 1
void glCopyImageSubDataEXT(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
#endif /* GL_EXT_copy_image */
#ifndef GL_EXT_debug_label
#define GL_EXT_debug_label 1
constexpr GLenum GL_PROGRAM_PIPELINE_OBJECT_EXT = 0x8A4F;
constexpr GLenum GL_PROGRAM_OBJECT_EXT = 0x8B40;
constexpr GLenum GL_SHADER_OBJECT_EXT = 0x8B48;
constexpr GLenum GL_BUFFER_OBJECT_EXT = 0x9151;
constexpr GLenum GL_QUERY_OBJECT_EXT = 0x9153;
constexpr GLenum GL_VERTEX_ARRAY_OBJECT_EXT = 0x9154;
constexpr GLenum GL_SAMPLER = 0x82E6;
constexpr GLenum GL_TRANSFORM_FEEDBACK = 0x8E22;
void glLabelObjectEXT(GLenum type, GLuint object, GLsizei length, GLchar const  * label);
void glGetObjectLabelEXT(GLenum type, GLuint object, GLsizei bufSize, GLsizei * length, GLchar * label);
#endif /* GL_EXT_debug_label */
#ifndef GL_EXT_debug_marker
#define GL_EXT_debug_marker 1
void glInsertEventMarkerEXT(GLsizei length, GLchar const  * marker);
void glPushGroupMarkerEXT(GLsizei length, GLchar const  * marker);
void glPopGroupMarkerEXT();
#endif /* GL_EXT_debug_marker */
#ifndef GL_EXT_depth_clamp
#define GL_EXT_depth_clamp 1
constexpr GLenum GL_DEPTH_CLAMP_EXT = 0x864F;
#endif /* GL_EXT_depth_clamp */
#ifndef GL_EXT_discard_framebuffer
#define GL_EXT_discard_framebuffer 1
constexpr GLenum GL_COLOR_EXT = 0x1800;
constexpr GLenum GL_DEPTH_EXT = 0x1801;
constexpr GLenum GL_STENCIL_EXT = 0x1802;
void glDiscardFramebufferEXT(GLenum target, GLsizei numAttachments, GLenum const  * attachments);
#endif /* GL_EXT_discard_framebuffer */
#ifndef GL_EXT_disjoint_timer_query
#define GL_EXT_disjoint_timer_query 1
constexpr GLenum GL_QUERY_COUNTER_BITS_EXT = 0x8864;
constexpr GLenum GL_CURRENT_QUERY_EXT = 0x8865;
constexpr GLenum GL_QUERY_RESULT_EXT = 0x8866;
constexpr GLenum GL_QUERY_RESULT_AVAILABLE_EXT = 0x8867;
constexpr GLenum GL_TIME_ELAPSED_EXT = 0x88BF;
constexpr GLenum GL_TIMESTAMP_EXT = 0x8E28;
constexpr GLenum GL_GPU_DISJOINT_EXT = 0x8FBB;
void glGenQueriesEXT(GLsizei n, GLuint * ids);
void glDeleteQueriesEXT(GLsizei n, GLuint const  * ids);
GLboolean glIsQueryEXT(GLuint id);
void glBeginQueryEXT(GLenum target, GLuint id);
void glEndQueryEXT(GLenum target);
void glQueryCounterEXT(GLuint id, GLenum target);
void glGetQueryivEXT(GLenum target, GLenum pname, GLint * params);
void glGetQueryObjectivEXT(GLuint id, GLenum pname, GLint * params);
void glGetQueryObjectuivEXT(GLuint id, GLenum pname, GLuint * params);
void glGetQueryObjecti64vEXT(GLuint id, GLenum pname, GLint64 * params);
void glGetQueryObjectui64vEXT(GLuint id, GLenum pname, GLuint64 * params);
void glGetInteger64vEXT(GLenum pname, GLint64 * data);
#endif /* GL_EXT_disjoint_timer_query */
#ifndef GL_EXT_draw_buffers
#define GL_EXT_draw_buffers 1
constexpr GLenum GL_MAX_COLOR_ATTACHMENTS_EXT = 0x8CDF;
constexpr GLenum GL_MAX_DRAW_BUFFERS_EXT = 0x8824;
constexpr GLenum GL_DRAW_BUFFER0_EXT = 0x8825;
constexpr GLenum GL_DRAW_BUFFER1_EXT = 0x8826;
constexpr GLenum GL_DRAW_BUFFER2_EXT = 0x8827;
constexpr GLenum GL_DRAW_BUFFER3_EXT = 0x8828;
constexpr GLenum GL_DRAW_BUFFER4_EXT = 0x8829;
constexpr GLenum GL_DRAW_BUFFER5_EXT = 0x882A;
constexpr GLenum GL_DRAW_BUFFER6_EXT = 0x882B;
constexpr GLenum GL_DRAW_BUFFER7_EXT = 0x882C;
constexpr GLenum GL_DRAW_BUFFER8_EXT = 0x882D;
constexpr GLenum GL_DRAW_BUFFER9_EXT = 0x882E;
constexpr GLenum GL_DRAW_BUFFER10_EXT = 0x882F;
constexpr GLenum GL_DRAW_BUFFER11_EXT = 0x8830;
constexpr GLenum GL_DRAW_BUFFER12_EXT = 0x8831;
constexpr GLenum GL_DRAW_BUFFER13_EXT = 0x8832;
constexpr GLenum GL_DRAW_BUFFER14_EXT = 0x8833;
constexpr GLenum GL_DRAW_BUFFER15_EXT = 0x8834;
constexpr GLenum GL_COLOR_ATTACHMENT0_EXT = 0x8CE0;
constexpr GLenum GL_COLOR_ATTACHMENT1_EXT = 0x8CE1;
constexpr GLenum GL_COLOR_ATTACHMENT2_EXT = 0x8CE2;
constexpr GLenum GL_COLOR_ATTACHMENT3_EXT = 0x8CE3;
constexpr GLenum GL_COLOR_ATTACHMENT4_EXT = 0x8CE4;
constexpr GLenum GL_COLOR_ATTACHMENT5_EXT = 0x8CE5;
constexpr GLenum GL_COLOR_ATTACHMENT6_EXT = 0x8CE6;
constexpr GLenum GL_COLOR_ATTACHMENT7_EXT = 0x8CE7;
constexpr GLenum GL_COLOR_ATTACHMENT8_EXT = 0x8CE8;
constexpr GLenum GL_COLOR_ATTACHMENT9_EXT = 0x8CE9;
constexpr GLenum GL_COLOR_ATTACHMENT10_EXT = 0x8CEA;
constexpr GLenum GL_COLOR_ATTACHMENT11_EXT = 0x8CEB;
constexpr GLenum GL_COLOR_ATTACHMENT12_EXT = 0x8CEC;
constexpr GLenum GL_COLOR_ATTACHMENT13_EXT = 0x8CED;
constexpr GLenum GL_COLOR_ATTACHMENT14_EXT = 0x8CEE;
constexpr GLenum GL_COLOR_ATTACHMENT15_EXT = 0x8CEF;
void glDrawBuffersEXT(GLsizei n, GLenum const  * bufs);
#endif /* GL_EXT_draw_buffers */
#ifndef GL_EXT_draw_buffers_indexed
#define GL_EXT_draw_buffers_indexed 1
constexpr GLenum GL_MIN = 0x8007;
constexpr GLenum GL_MAX = 0x8008;
void glEnableiEXT(GLenum target, GLuint index);
void glDisableiEXT(GLenum target, GLuint index);
void glBlendEquationiEXT(GLuint buf, GLenum mode);
void glBlendEquationSeparateiEXT(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
void glBlendFunciEXT(GLuint buf, GLenum src, GLenum dst);
void glBlendFuncSeparateiEXT(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
void glColorMaskiEXT(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
GLboolean glIsEnablediEXT(GLenum target, GLuint index);
#endif /* GL_EXT_draw_buffers_indexed */
#ifndef GL_EXT_draw_elements_base_vertex
#define GL_EXT_draw_elements_base_vertex 1
void glDrawElementsBaseVertexEXT(GLenum mode, GLsizei count, GLenum type, const void * indices, GLint basevertex);
void glDrawRangeElementsBaseVertexEXT(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices, GLint basevertex);
void glDrawElementsInstancedBaseVertexEXT(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex);
void glMultiDrawElementsBaseVertexEXT(GLenum mode, GLsizei const  * count, GLenum type, const void *const* indices, GLsizei primcount, GLint const  * basevertex);
#endif /* GL_EXT_draw_elements_base_vertex */
#ifndef GL_EXT_draw_instanced
#define GL_EXT_draw_instanced 1
void glDrawArraysInstancedEXT(GLenum mode, GLint start, GLsizei count, GLsizei primcount);
void glDrawElementsInstancedEXT(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei primcount);
#endif /* GL_EXT_draw_instanced */
#ifndef GL_EXT_draw_transform_feedback
#define GL_EXT_draw_transform_feedback 1
void glDrawTransformFeedbackEXT(GLenum mode, GLuint id);
void glDrawTransformFeedbackInstancedEXT(GLenum mode, GLuint id, GLsizei instancecount);
#endif /* GL_EXT_draw_transform_feedback */
#ifndef GL_EXT_external_buffer
#define GL_EXT_external_buffer 1
void glBufferStorageExternalEXT(GLenum target, GLintptr offset, GLsizeiptr size, GLeglClientBufferEXT clientBuffer, GLbitfield flags);
void glNamedBufferStorageExternalEXT(GLuint buffer, GLintptr offset, GLsizeiptr size, GLeglClientBufferEXT clientBuffer, GLbitfield flags);
#endif /* GL_EXT_external_buffer */
#ifndef GL_EXT_float_blend
#define GL_EXT_float_blend 1
#endif /* GL_EXT_float_blend */
#ifndef GL_EXT_geometry_point_size
#define GL_EXT_geometry_point_size 1
#endif /* GL_EXT_geometry_point_size */
#ifndef GL_EXT_geometry_shader
#define GL_EXT_geometry_shader 1
constexpr GLenum GL_GEOMETRY_SHADER_EXT = 0x8DD9;
constexpr GLenum GL_GEOMETRY_SHADER_BIT_EXT = 0x00000004;
constexpr GLenum GL_GEOMETRY_LINKED_VERTICES_OUT_EXT = 0x8916;
constexpr GLenum GL_GEOMETRY_LINKED_INPUT_TYPE_EXT = 0x8917;
constexpr GLenum GL_GEOMETRY_LINKED_OUTPUT_TYPE_EXT = 0x8918;
constexpr GLenum GL_GEOMETRY_SHADER_INVOCATIONS_EXT = 0x887F;
constexpr GLenum GL_LAYER_PROVOKING_VERTEX_EXT = 0x825E;
constexpr GLenum GL_LINES_ADJACENCY_EXT = 0x000A;
constexpr GLenum GL_LINE_STRIP_ADJACENCY_EXT = 0x000B;
constexpr GLenum GL_TRIANGLES_ADJACENCY_EXT = 0x000C;
constexpr GLenum GL_TRIANGLE_STRIP_ADJACENCY_EXT = 0x000D;
constexpr GLenum GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_EXT = 0x8DDF;
constexpr GLenum GL_MAX_GEOMETRY_UNIFORM_BLOCKS_EXT = 0x8A2C;
constexpr GLenum GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS_EXT = 0x8A32;
constexpr GLenum GL_MAX_GEOMETRY_INPUT_COMPONENTS_EXT = 0x9123;
constexpr GLenum GL_MAX_GEOMETRY_OUTPUT_COMPONENTS_EXT = 0x9124;
constexpr GLenum GL_MAX_GEOMETRY_OUTPUT_VERTICES_EXT = 0x8DE0;
constexpr GLenum GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_EXT = 0x8DE1;
constexpr GLenum GL_MAX_GEOMETRY_SHADER_INVOCATIONS_EXT = 0x8E5A;
constexpr GLenum GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_EXT = 0x8C29;
constexpr GLenum GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS_EXT = 0x92CF;
constexpr GLenum GL_MAX_GEOMETRY_ATOMIC_COUNTERS_EXT = 0x92D5;
constexpr GLenum GL_MAX_GEOMETRY_IMAGE_UNIFORMS_EXT = 0x90CD;
constexpr GLenum GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS_EXT = 0x90D7;
constexpr GLenum GL_FIRST_VERTEX_CONVENTION_EXT = 0x8E4D;
constexpr GLenum GL_LAST_VERTEX_CONVENTION_EXT = 0x8E4E;
constexpr GLenum GL_UNDEFINED_VERTEX_EXT = 0x8260;
constexpr GLenum GL_PRIMITIVES_GENERATED_EXT = 0x8C87;
constexpr GLenum GL_FRAMEBUFFER_DEFAULT_LAYERS_EXT = 0x9312;
constexpr GLenum GL_MAX_FRAMEBUFFER_LAYERS_EXT = 0x9317;
constexpr GLenum GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_EXT = 0x8DA8;
constexpr GLenum GL_FRAMEBUFFER_ATTACHMENT_LAYERED_EXT = 0x8DA7;
constexpr GLenum GL_REFERENCED_BY_GEOMETRY_SHADER_EXT = 0x9309;
void glFramebufferTextureEXT(GLenum target, GLenum attachment, GLuint texture, GLint level);
#endif /* GL_EXT_geometry_shader */
#ifndef GL_EXT_gpu_shader5
#define GL_EXT_gpu_shader5 1
#endif /* GL_EXT_gpu_shader5 */
#ifndef GL_EXT_instanced_arrays
#define GL_EXT_instanced_arrays 1
constexpr GLenum GL_VERTEX_ATTRIB_ARRAY_DIVISOR_EXT = 0x88FE;
void glVertexAttribDivisorEXT(GLuint index, GLuint divisor);
#endif /* GL_EXT_instanced_arrays */
#ifndef GL_EXT_map_buffer_range
#define GL_EXT_map_buffer_range 1
constexpr GLenum GL_MAP_READ_BIT_EXT = 0x0001;
constexpr GLenum GL_MAP_WRITE_BIT_EXT = 0x0002;
constexpr GLenum GL_MAP_INVALIDATE_RANGE_BIT_EXT = 0x0004;
constexpr GLenum GL_MAP_INVALIDATE_BUFFER_BIT_EXT = 0x0008;
constexpr GLenum GL_MAP_FLUSH_EXPLICIT_BIT_EXT = 0x0010;
constexpr GLenum GL_MAP_UNSYNCHRONIZED_BIT_EXT = 0x0020;
void * glMapBufferRangeEXT(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
void glFlushMappedBufferRangeEXT(GLenum target, GLintptr offset, GLsizeiptr length);
#endif /* GL_EXT_map_buffer_range */
#ifndef GL_EXT_memory_object
#define GL_EXT_memory_object 1
constexpr GLenum GL_TEXTURE_TILING_EXT = 0x9580;
constexpr GLenum GL_DEDICATED_MEMORY_OBJECT_EXT = 0x9581;
constexpr GLenum GL_PROTECTED_MEMORY_OBJECT_EXT = 0x959B;
constexpr GLenum GL_NUM_TILING_TYPES_EXT = 0x9582;
constexpr GLenum GL_TILING_TYPES_EXT = 0x9583;
constexpr GLenum GL_OPTIMAL_TILING_EXT = 0x9584;
constexpr GLenum GL_LINEAR_TILING_EXT = 0x9585;
constexpr GLenum GL_NUM_DEVICE_UUIDS_EXT = 0x9596;
constexpr GLenum GL_DEVICE_UUID_EXT = 0x9597;
constexpr GLenum GL_DRIVER_UUID_EXT = 0x9598;
constexpr GLenum GL_UUID_SIZE_EXT = 16;
void glGetUnsignedBytevEXT(GLenum pname, GLubyte * data);
void glGetUnsignedBytei_vEXT(GLenum target, GLuint index, GLubyte * data);
void glDeleteMemoryObjectsEXT(GLsizei n, GLuint const  * memoryObjects);
GLboolean glIsMemoryObjectEXT(GLuint memoryObject);
void glCreateMemoryObjectsEXT(GLsizei n, GLuint * memoryObjects);
void glMemoryObjectParameterivEXT(GLuint memoryObject, GLenum pname, GLint const  * params);
void glGetMemoryObjectParameterivEXT(GLuint memoryObject, GLenum pname, GLint * params);
void glTexStorageMem2DEXT(GLenum target, GLsizei levels, GLenum internalFormat, GLsizei width, GLsizei height, GLuint memory, GLuint64 offset);
void glTexStorageMem2DMultisampleEXT(GLenum target, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations, GLuint memory, GLuint64 offset);
void glTexStorageMem3DEXT(GLenum target, GLsizei levels, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLuint memory, GLuint64 offset);
void glTexStorageMem3DMultisampleEXT(GLenum target, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations, GLuint memory, GLuint64 offset);
void glBufferStorageMemEXT(GLenum target, GLsizeiptr size, GLuint memory, GLuint64 offset);
void glTextureStorageMem2DEXT(GLuint texture, GLsizei levels, GLenum internalFormat, GLsizei width, GLsizei height, GLuint memory, GLuint64 offset);
void glTextureStorageMem2DMultisampleEXT(GLuint texture, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations, GLuint memory, GLuint64 offset);
void glTextureStorageMem3DEXT(GLuint texture, GLsizei levels, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLuint memory, GLuint64 offset);
void glTextureStorageMem3DMultisampleEXT(GLuint texture, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations, GLuint memory, GLuint64 offset);
void glNamedBufferStorageMemEXT(GLuint buffer, GLsizeiptr size, GLuint memory, GLuint64 offset);
void glTexStorageMem1DEXT(GLenum target, GLsizei levels, GLenum internalFormat, GLsizei width, GLuint memory, GLuint64 offset);
void glTextureStorageMem1DEXT(GLuint texture, GLsizei levels, GLenum internalFormat, GLsizei width, GLuint memory, GLuint64 offset);
#endif /* GL_EXT_memory_object */
#ifndef GL_EXT_memory_object_fd
#define GL_EXT_memory_object_fd 1
constexpr GLenum GL_HANDLE_TYPE_OPAQUE_FD_EXT = 0x9586;
void glImportMemoryFdEXT(GLuint memory, GLuint64 size, GLenum handleType, GLint fd);
#endif /* GL_EXT_memory_object_fd */
#ifndef GL_EXT_memory_object_win32
#define GL_EXT_memory_object_win32 1
constexpr GLenum GL_HANDLE_TYPE_OPAQUE_WIN32_EXT = 0x9587;
constexpr GLenum GL_HANDLE_TYPE_OPAQUE_WIN32_KMT_EXT = 0x9588;
constexpr GLenum GL_DEVICE_LUID_EXT = 0x9599;
constexpr GLenum GL_DEVICE_NODE_MASK_EXT = 0x959A;
constexpr GLenum GL_LUID_SIZE_EXT = 8;
constexpr GLenum GL_HANDLE_TYPE_D3D12_TILEPOOL_EXT = 0x9589;
constexpr GLenum GL_HANDLE_TYPE_D3D12_RESOURCE_EXT = 0x958A;
constexpr GLenum GL_HANDLE_TYPE_D3D11_IMAGE_EXT = 0x958B;
constexpr GLenum GL_HANDLE_TYPE_D3D11_IMAGE_KMT_EXT = 0x958C;
void glImportMemoryWin32HandleEXT(GLuint memory, GLuint64 size, GLenum handleType, void * handle);
void glImportMemoryWin32NameEXT(GLuint memory, GLuint64 size, GLenum handleType, const void * name);
#endif /* GL_EXT_memory_object_win32 */
#ifndef GL_EXT_multi_draw_arrays
#define GL_EXT_multi_draw_arrays 1
void glMultiDrawArraysEXT(GLenum mode, GLint const  * first, GLsizei const  * count, GLsizei primcount);
void glMultiDrawElementsEXT(GLenum mode, GLsizei const  * count, GLenum type, const void *const* indices, GLsizei primcount);
#endif /* GL_EXT_multi_draw_arrays */
#ifndef GL_EXT_multi_draw_indirect
#define GL_EXT_multi_draw_indirect 1
void glMultiDrawArraysIndirectEXT(GLenum mode, const void * indirect, GLsizei drawcount, GLsizei stride);
void glMultiDrawElementsIndirectEXT(GLenum mode, GLenum type, const void * indirect, GLsizei drawcount, GLsizei stride);
#endif /* GL_EXT_multi_draw_indirect */
#ifndef GL_EXT_multisampled_compatibility
#define GL_EXT_multisampled_compatibility 1
constexpr GLenum GL_MULTISAMPLE_EXT = 0x809D;
constexpr GLenum GL_SAMPLE_ALPHA_TO_ONE_EXT = 0x809F;
#endif /* GL_EXT_multisampled_compatibility */
#ifndef GL_EXT_multisampled_render_to_texture
#define GL_EXT_multisampled_render_to_texture 1
constexpr GLenum GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_SAMPLES_EXT = 0x8D6C;
constexpr GLenum GL_RENDERBUFFER_SAMPLES_EXT = 0x8CAB;
constexpr GLenum GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE_EXT = 0x8D56;
constexpr GLenum GL_MAX_SAMPLES_EXT = 0x8D57;
void glRenderbufferStorageMultisampleEXT(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
void glFramebufferTexture2DMultisampleEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLsizei samples);
#endif /* GL_EXT_multisampled_render_to_texture */
#ifndef GL_EXT_multiview_draw_buffers
#define GL_EXT_multiview_draw_buffers 1
constexpr GLenum GL_COLOR_ATTACHMENT_EXT = 0x90F0;
constexpr GLenum GL_MULTIVIEW_EXT = 0x90F1;
constexpr GLenum GL_DRAW_BUFFER_EXT = 0x0C01;
constexpr GLenum GL_READ_BUFFER_EXT = 0x0C02;
constexpr GLenum GL_MAX_MULTIVIEW_BUFFERS_EXT = 0x90F2;
void glReadBufferIndexedEXT(GLenum src, GLint index);
void glDrawBuffersIndexedEXT(GLint n, GLenum const  * location, GLint const  * indices);
void glGetIntegeri_vEXT(GLenum target, GLuint index, GLint * data);
#endif /* GL_EXT_multiview_draw_buffers */
#ifndef GL_EXT_multiview_tessellation_geometry_shader
#define GL_EXT_multiview_tessellation_geometry_shader 1
#endif /* GL_EXT_multiview_tessellation_geometry_shader */
#ifndef GL_EXT_multiview_texture_multisample
#define GL_EXT_multiview_texture_multisample 1
#endif /* GL_EXT_multiview_texture_multisample */
#ifndef GL_EXT_multiview_timer_query
#define GL_EXT_multiview_timer_query 1
#endif /* GL_EXT_multiview_timer_query */
#ifndef GL_EXT_occlusion_query_boolean
#define GL_EXT_occlusion_query_boolean 1
constexpr GLenum GL_ANY_SAMPLES_PASSED_EXT = 0x8C2F;
constexpr GLenum GL_ANY_SAMPLES_PASSED_CONSERVATIVE_EXT = 0x8D6A;
#endif /* GL_EXT_occlusion_query_boolean */
#ifndef GL_EXT_polygon_offset_clamp
#define GL_EXT_polygon_offset_clamp 1
constexpr GLenum GL_POLYGON_OFFSET_CLAMP_EXT = 0x8E1B;
void glPolygonOffsetClampEXT(GLfloat factor, GLfloat units, GLfloat clamp);
#endif /* GL_EXT_polygon_offset_clamp */
#ifndef GL_EXT_post_depth_coverage
#define GL_EXT_post_depth_coverage 1
#endif /* GL_EXT_post_depth_coverage */
#ifndef GL_EXT_primitive_bounding_box
#define GL_EXT_primitive_bounding_box 1
constexpr GLenum GL_PRIMITIVE_BOUNDING_BOX_EXT = 0x92BE;
void glPrimitiveBoundingBoxEXT(GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat minW, GLfloat maxX, GLfloat maxY, GLfloat maxZ, GLfloat maxW);
#endif /* GL_EXT_primitive_bounding_box */
#ifndef GL_EXT_protected_textures
#define GL_EXT_protected_textures 1
constexpr GLenum GL_CONTEXT_FLAG_PROTECTED_CONTENT_BIT_EXT = 0x00000010;
constexpr GLenum GL_TEXTURE_PROTECTED_EXT = 0x8BFA;
#endif /* GL_EXT_protected_textures */
#ifndef GL_EXT_pvrtc_sRGB
#define GL_EXT_pvrtc_sRGB 1
constexpr GLenum GL_COMPRESSED_SRGB_PVRTC_2BPPV1_EXT = 0x8A54;
constexpr GLenum GL_COMPRESSED_SRGB_PVRTC_4BPPV1_EXT = 0x8A55;
constexpr GLenum GL_COMPRESSED_SRGB_ALPHA_PVRTC_2BPPV1_EXT = 0x8A56;
constexpr GLenum GL_COMPRESSED_SRGB_ALPHA_PVRTC_4BPPV1_EXT = 0x8A57;
constexpr GLenum GL_COMPRESSED_SRGB_ALPHA_PVRTC_2BPPV2_IMG = 0x93F0;
constexpr GLenum GL_COMPRESSED_SRGB_ALPHA_PVRTC_4BPPV2_IMG = 0x93F1;
#endif /* GL_EXT_pvrtc_sRGB */
#ifndef GL_EXT_raster_multisample
#define GL_EXT_raster_multisample 1
constexpr GLenum GL_RASTER_MULTISAMPLE_EXT = 0x9327;
constexpr GLenum GL_RASTER_SAMPLES_EXT = 0x9328;
constexpr GLenum GL_MAX_RASTER_SAMPLES_EXT = 0x9329;
constexpr GLenum GL_RASTER_FIXED_SAMPLE_LOCATIONS_EXT = 0x932A;
constexpr GLenum GL_MULTISAMPLE_RASTERIZATION_ALLOWED_EXT = 0x932B;
constexpr GLenum GL_EFFECTIVE_RASTER_SAMPLES_EXT = 0x932C;
void glRasterSamplesEXT(GLuint samples, GLboolean fixedsamplelocations);
#endif /* GL_EXT_raster_multisample */
#ifndef GL_EXT_read_format_bgra
#define GL_EXT_read_format_bgra 1
constexpr GLenum GL_BGRA_EXT = 0x80E1;
constexpr GLenum GL_UNSIGNED_SHORT_4_4_4_4_REV_EXT = 0x8365;
constexpr GLenum GL_UNSIGNED_SHORT_1_5_5_5_REV_EXT = 0x8366;
#endif /* GL_EXT_read_format_bgra */
#ifndef GL_EXT_render_snorm
#define GL_EXT_render_snorm 1
constexpr GLenum GL_R8_SNORM = 0x8F94;
constexpr GLenum GL_RG8_SNORM = 0x8F95;
constexpr GLenum GL_RGBA8_SNORM = 0x8F97;
constexpr GLenum GL_R16_SNORM_EXT = 0x8F98;
constexpr GLenum GL_RG16_SNORM_EXT = 0x8F99;
constexpr GLenum GL_RGBA16_SNORM_EXT = 0x8F9B;
#endif /* GL_EXT_render_snorm */
#ifndef GL_EXT_robustness
#define GL_EXT_robustness 1
constexpr GLenum GL_GUILTY_CONTEXT_RESET_EXT = 0x8253;
constexpr GLenum GL_INNOCENT_CONTEXT_RESET_EXT = 0x8254;
constexpr GLenum GL_UNKNOWN_CONTEXT_RESET_EXT = 0x8255;
constexpr GLenum GL_CONTEXT_ROBUST_ACCESS_EXT = 0x90F3;
constexpr GLenum GL_RESET_NOTIFICATION_STRATEGY_EXT = 0x8256;
constexpr GLenum GL_LOSE_CONTEXT_ON_RESET_EXT = 0x8252;
constexpr GLenum GL_NO_RESET_NOTIFICATION_EXT = 0x8261;
GLenum glGetGraphicsResetStatusEXT();
void glReadnPixelsEXT(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void * data);
void glGetnUniformfvEXT(GLuint program, GLint location, GLsizei bufSize, GLfloat * params);
void glGetnUniformivEXT(GLuint program, GLint location, GLsizei bufSize, GLint * params);
#endif /* GL_EXT_robustness */
#ifndef GL_EXT_semaphore
#define GL_EXT_semaphore 1
constexpr GLenum GL_LAYOUT_GENERAL_EXT = 0x958D;
constexpr GLenum GL_LAYOUT_COLOR_ATTACHMENT_EXT = 0x958E;
constexpr GLenum GL_LAYOUT_DEPTH_STENCIL_ATTACHMENT_EXT = 0x958F;
constexpr GLenum GL_LAYOUT_DEPTH_STENCIL_READ_ONLY_EXT = 0x9590;
constexpr GLenum GL_LAYOUT_SHADER_READ_ONLY_EXT = 0x9591;
constexpr GLenum GL_LAYOUT_TRANSFER_SRC_EXT = 0x9592;
constexpr GLenum GL_LAYOUT_TRANSFER_DST_EXT = 0x9593;
constexpr GLenum GL_LAYOUT_DEPTH_READ_ONLY_STENCIL_ATTACHMENT_EXT = 0x9530;
constexpr GLenum GL_LAYOUT_DEPTH_ATTACHMENT_STENCIL_READ_ONLY_EXT = 0x9531;
void glGenSemaphoresEXT(GLsizei n, GLuint * semaphores);
void glDeleteSemaphoresEXT(GLsizei n, GLuint const  * semaphores);
GLboolean glIsSemaphoreEXT(GLuint semaphore);
void glSemaphoreParameterui64vEXT(GLuint semaphore, GLenum pname, GLuint64 const  * params);
void glGetSemaphoreParameterui64vEXT(GLuint semaphore, GLenum pname, GLuint64 * params);
void glWaitSemaphoreEXT(GLuint semaphore, GLuint numBufferBarriers, GLuint const  * buffers, GLuint numTextureBarriers, GLuint const  * textures, GLenum const  * srcLayouts);
void glSignalSemaphoreEXT(GLuint semaphore, GLuint numBufferBarriers, GLuint const  * buffers, GLuint numTextureBarriers, GLuint const  * textures, GLenum const  * dstLayouts);
#endif /* GL_EXT_semaphore */
#ifndef GL_EXT_semaphore_fd
#define GL_EXT_semaphore_fd 1
void glImportSemaphoreFdEXT(GLuint semaphore, GLenum handleType, GLint fd);
#endif /* GL_EXT_semaphore_fd */
#ifndef GL_EXT_semaphore_win32
#define GL_EXT_semaphore_win32 1
constexpr GLenum GL_HANDLE_TYPE_D3D12_FENCE_EXT = 0x9594;
constexpr GLenum GL_D3D12_FENCE_VALUE_EXT = 0x9595;
void glImportSemaphoreWin32HandleEXT(GLuint semaphore, GLenum handleType, void * handle);
void glImportSemaphoreWin32NameEXT(GLuint semaphore, GLenum handleType, const void * name);
#endif /* GL_EXT_semaphore_win32 */
#ifndef GL_EXT_sRGB
#define GL_EXT_sRGB 1
constexpr GLenum GL_SRGB_EXT = 0x8C40;
constexpr GLenum GL_SRGB_ALPHA_EXT = 0x8C42;
constexpr GLenum GL_SRGB8_ALPHA8_EXT = 0x8C43;
constexpr GLenum GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING_EXT = 0x8210;
#endif /* GL_EXT_sRGB */
#ifndef GL_EXT_sRGB_write_control
#define GL_EXT_sRGB_write_control 1
constexpr GLenum GL_FRAMEBUFFER_SRGB_EXT = 0x8DB9;
#endif /* GL_EXT_sRGB_write_control */
#ifndef GL_EXT_separate_shader_objects
#define GL_EXT_separate_shader_objects 1
constexpr GLenum GL_ACTIVE_PROGRAM_EXT = 0x8259;
constexpr GLenum GL_VERTEX_SHADER_BIT_EXT = 0x00000001;
constexpr GLenum GL_FRAGMENT_SHADER_BIT_EXT = 0x00000002;
constexpr GLenum GL_ALL_SHADER_BITS_EXT = 0xFFFFFFFF;
constexpr GLenum GL_PROGRAM_SEPARABLE_EXT = 0x8258;
constexpr GLenum GL_PROGRAM_PIPELINE_BINDING_EXT = 0x825A;
void glUseShaderProgramEXT(GLenum type, GLuint program);
void glActiveProgramEXT(GLuint program);
GLuint glCreateShaderProgramEXT(GLenum type, GLchar const  * string);
void glActiveShaderProgramEXT(GLuint pipeline, GLuint program);
void glBindProgramPipelineEXT(GLuint pipeline);
GLuint glCreateShaderProgramvEXT(GLenum type, GLsizei count, GLchar const  ** strings);
void glDeleteProgramPipelinesEXT(GLsizei n, GLuint const  * pipelines);
void glGenProgramPipelinesEXT(GLsizei n, GLuint * pipelines);
void glGetProgramPipelineInfoLogEXT(GLuint pipeline, GLsizei bufSize, GLsizei * length, GLchar * infoLog);
void glGetProgramPipelineivEXT(GLuint pipeline, GLenum pname, GLint * params);
GLboolean glIsProgramPipelineEXT(GLuint pipeline);
void glProgramParameteriEXT(GLuint program, GLenum pname, GLint value);
void glProgramUniform1fEXT(GLuint program, GLint location, GLfloat v0);
void glProgramUniform1fvEXT(GLuint program, GLint location, GLsizei count, GLfloat const  * value);
void glProgramUniform1iEXT(GLuint program, GLint location, GLint v0);
void glProgramUniform1ivEXT(GLuint program, GLint location, GLsizei count, GLint const  * value);
void glProgramUniform2fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1);
void glProgramUniform2fvEXT(GLuint program, GLint location, GLsizei count, GLfloat const  * value);
void glProgramUniform2iEXT(GLuint program, GLint location, GLint v0, GLint v1);
void glProgramUniform2ivEXT(GLuint program, GLint location, GLsizei count, GLint const  * value);
void glProgramUniform3fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
void glProgramUniform3fvEXT(GLuint program, GLint location, GLsizei count, GLfloat const  * value);
void glProgramUniform3iEXT(GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
void glProgramUniform3ivEXT(GLuint program, GLint location, GLsizei count, GLint const  * value);
void glProgramUniform4fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
void glProgramUniform4fvEXT(GLuint program, GLint location, GLsizei count, GLfloat const  * value);
void glProgramUniform4iEXT(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
void glProgramUniform4ivEXT(GLuint program, GLint location, GLsizei count, GLint const  * value);
void glProgramUniformMatrix2fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value);
void glProgramUniformMatrix3fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value);
void glProgramUniformMatrix4fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value);
void glUseProgramStagesEXT(GLuint pipeline, GLbitfield stages, GLuint program);
void glValidateProgramPipelineEXT(GLuint pipeline);
void glProgramUniform1uiEXT(GLuint program, GLint location, GLuint v0);
void glProgramUniform2uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1);
void glProgramUniform3uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
void glProgramUniform4uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
void glProgramUniform1uivEXT(GLuint program, GLint location, GLsizei count, GLuint const  * value);
void glProgramUniform2uivEXT(GLuint program, GLint location, GLsizei count, GLuint const  * value);
void glProgramUniform3uivEXT(GLuint program, GLint location, GLsizei count, GLuint const  * value);
void glProgramUniform4uivEXT(GLuint program, GLint location, GLsizei count, GLuint const  * value);
void glProgramUniformMatrix2x3fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value);
void glProgramUniformMatrix3x2fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value);
void glProgramUniformMatrix2x4fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value);
void glProgramUniformMatrix4x2fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value);
void glProgramUniformMatrix3x4fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value);
void glProgramUniformMatrix4x3fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value);
#endif /* GL_EXT_separate_shader_objects */
#ifndef GL_EXT_shader_framebuffer_fetch
#define GL_EXT_shader_framebuffer_fetch 1
constexpr GLenum GL_FRAGMENT_SHADER_DISCARDS_SAMPLES_EXT = 0x8A52;
#endif /* GL_EXT_shader_framebuffer_fetch */
#ifndef GL_EXT_shader_framebuffer_fetch_non_coherent
#define GL_EXT_shader_framebuffer_fetch_non_coherent 1
void glFramebufferFetchBarrierEXT();
#endif /* GL_EXT_shader_framebuffer_fetch_non_coherent */
#ifndef GL_EXT_shader_group_vote
#define GL_EXT_shader_group_vote 1
#endif /* GL_EXT_shader_group_vote */
#ifndef GL_EXT_shader_implicit_conversions
#define GL_EXT_shader_implicit_conversions 1
#endif /* GL_EXT_shader_implicit_conversions */
#ifndef GL_EXT_shader_integer_mix
#define GL_EXT_shader_integer_mix 1
#endif /* GL_EXT_shader_integer_mix */
#ifndef GL_EXT_shader_io_blocks
#define GL_EXT_shader_io_blocks 1
#endif /* GL_EXT_shader_io_blocks */
#ifndef GL_EXT_shader_non_constant_global_initializers
#define GL_EXT_shader_non_constant_global_initializers 1
#endif /* GL_EXT_shader_non_constant_global_initializers */
#ifndef GL_EXT_shader_pixel_local_storage
#define GL_EXT_shader_pixel_local_storage 1
constexpr GLenum GL_MAX_SHADER_PIXEL_LOCAL_STORAGE_FAST_SIZE_EXT = 0x8F63;
constexpr GLenum GL_MAX_SHADER_PIXEL_LOCAL_STORAGE_SIZE_EXT = 0x8F67;
constexpr GLenum GL_SHADER_PIXEL_LOCAL_STORAGE_EXT = 0x8F64;
#endif /* GL_EXT_shader_pixel_local_storage */
#ifndef GL_EXT_shader_pixel_local_storage2
#define GL_EXT_shader_pixel_local_storage2 1
constexpr GLenum GL_MAX_SHADER_COMBINED_LOCAL_STORAGE_FAST_SIZE_EXT = 0x9650;
constexpr GLenum GL_MAX_SHADER_COMBINED_LOCAL_STORAGE_SIZE_EXT = 0x9651;
constexpr GLenum GL_FRAMEBUFFER_INCOMPLETE_INSUFFICIENT_SHADER_COMBINED_LOCAL_STORAGE_EXT = 0x9652;
void glFramebufferPixelLocalStorageSizeEXT(GLuint target, GLsizei size);
GLsizei glGetFramebufferPixelLocalStorageSizeEXT(GLuint target);
void glClearPixelLocalStorageuiEXT(GLsizei offset, GLsizei n, GLuint const  * values);
#endif /* GL_EXT_shader_pixel_local_storage2 */
#ifndef GL_EXT_shader_texture_lod
#define GL_EXT_shader_texture_lod 1
#endif /* GL_EXT_shader_texture_lod */
#ifndef GL_EXT_shadow_samplers
#define GL_EXT_shadow_samplers 1
constexpr GLenum GL_TEXTURE_COMPARE_MODE_EXT = 0x884C;
constexpr GLenum GL_TEXTURE_COMPARE_FUNC_EXT = 0x884D;
constexpr GLenum GL_COMPARE_REF_TO_TEXTURE_EXT = 0x884E;
constexpr GLenum GL_SAMPLER_2D_SHADOW_EXT = 0x8B62;
#endif /* GL_EXT_shadow_samplers */
#ifndef GL_EXT_sparse_texture
#define GL_EXT_sparse_texture 1
constexpr GLenum GL_TEXTURE_SPARSE_EXT = 0x91A6;
constexpr GLenum GL_VIRTUAL_PAGE_SIZE_INDEX_EXT = 0x91A7;
constexpr GLenum GL_NUM_SPARSE_LEVELS_EXT = 0x91AA;
constexpr GLenum GL_NUM_VIRTUAL_PAGE_SIZES_EXT = 0x91A8;
constexpr GLenum GL_VIRTUAL_PAGE_SIZE_X_EXT = 0x9195;
constexpr GLenum GL_VIRTUAL_PAGE_SIZE_Y_EXT = 0x9196;
constexpr GLenum GL_VIRTUAL_PAGE_SIZE_Z_EXT = 0x9197;
constexpr GLenum GL_TEXTURE_2D_ARRAY = 0x8C1A;
constexpr GLenum GL_TEXTURE_CUBE_MAP_ARRAY_OES = 0x9009;
constexpr GLenum GL_TEXTURE_3D = 0x806F;
constexpr GLenum GL_MAX_SPARSE_TEXTURE_SIZE_EXT = 0x9198;
constexpr GLenum GL_MAX_SPARSE_3D_TEXTURE_SIZE_EXT = 0x9199;
constexpr GLenum GL_MAX_SPARSE_ARRAY_TEXTURE_LAYERS_EXT = 0x919A;
constexpr GLenum GL_SPARSE_TEXTURE_FULL_ARRAY_CUBE_MIPMAPS_EXT = 0x91A9;
void glTexPageCommitmentEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit);
#endif /* GL_EXT_sparse_texture */
#ifndef GL_EXT_sparse_texture2
#define GL_EXT_sparse_texture2 1
#endif /* GL_EXT_sparse_texture2 */
#ifndef GL_EXT_tessellation_point_size
#define GL_EXT_tessellation_point_size 1
#endif /* GL_EXT_tessellation_point_size */
#ifndef GL_EXT_tessellation_shader
#define GL_EXT_tessellation_shader 1
constexpr GLenum GL_PATCHES_EXT = 0x000E;
constexpr GLenum GL_PATCH_VERTICES_EXT = 0x8E72;
constexpr GLenum GL_TESS_CONTROL_OUTPUT_VERTICES_EXT = 0x8E75;
constexpr GLenum GL_TESS_GEN_MODE_EXT = 0x8E76;
constexpr GLenum GL_TESS_GEN_SPACING_EXT = 0x8E77;
constexpr GLenum GL_TESS_GEN_VERTEX_ORDER_EXT = 0x8E78;
constexpr GLenum GL_TESS_GEN_POINT_MODE_EXT = 0x8E79;
constexpr GLenum GL_ISOLINES_EXT = 0x8E7A;
constexpr GLenum GL_QUADS_EXT = 0x0007;
constexpr GLenum GL_FRACTIONAL_ODD_EXT = 0x8E7B;
constexpr GLenum GL_FRACTIONAL_EVEN_EXT = 0x8E7C;
constexpr GLenum GL_MAX_PATCH_VERTICES_EXT = 0x8E7D;
constexpr GLenum GL_MAX_TESS_GEN_LEVEL_EXT = 0x8E7E;
constexpr GLenum GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS_EXT = 0x8E7F;
constexpr GLenum GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS_EXT = 0x8E80;
constexpr GLenum GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS_EXT = 0x8E81;
constexpr GLenum GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS_EXT = 0x8E82;
constexpr GLenum GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS_EXT = 0x8E83;
constexpr GLenum GL_MAX_TESS_PATCH_COMPONENTS_EXT = 0x8E84;
constexpr GLenum GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS_EXT = 0x8E85;
constexpr GLenum GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS_EXT = 0x8E86;
constexpr GLenum GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS_EXT = 0x8E89;
constexpr GLenum GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS_EXT = 0x8E8A;
constexpr GLenum GL_MAX_TESS_CONTROL_INPUT_COMPONENTS_EXT = 0x886C;
constexpr GLenum GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS_EXT = 0x886D;
constexpr GLenum GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS_EXT = 0x8E1E;
constexpr GLenum GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS_EXT = 0x8E1F;
constexpr GLenum GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS_EXT = 0x92CD;
constexpr GLenum GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS_EXT = 0x92CE;
constexpr GLenum GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS_EXT = 0x92D3;
constexpr GLenum GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS_EXT = 0x92D4;
constexpr GLenum GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS_EXT = 0x90CB;
constexpr GLenum GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS_EXT = 0x90CC;
constexpr GLenum GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS_EXT = 0x90D8;
constexpr GLenum GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS_EXT = 0x90D9;
constexpr GLenum GL_PRIMITIVE_RESTART_FOR_PATCHES_SUPPORTED = 0x8221;
constexpr GLenum GL_IS_PER_PATCH_EXT = 0x92E7;
constexpr GLenum GL_REFERENCED_BY_TESS_CONTROL_SHADER_EXT = 0x9307;
constexpr GLenum GL_REFERENCED_BY_TESS_EVALUATION_SHADER_EXT = 0x9308;
constexpr GLenum GL_TESS_CONTROL_SHADER_EXT = 0x8E88;
constexpr GLenum GL_TESS_EVALUATION_SHADER_EXT = 0x8E87;
constexpr GLenum GL_TESS_CONTROL_SHADER_BIT_EXT = 0x00000008;
constexpr GLenum GL_TESS_EVALUATION_SHADER_BIT_EXT = 0x00000010;
void glPatchParameteriEXT(GLenum pname, GLint value);
#endif /* GL_EXT_tessellation_shader */
#ifndef GL_EXT_texture_border_clamp
#define GL_EXT_texture_border_clamp 1
constexpr GLenum GL_TEXTURE_BORDER_COLOR_EXT = 0x1004;
constexpr GLenum GL_CLAMP_TO_BORDER_EXT = 0x812D;
void glTexParameterIivEXT(GLenum target, GLenum pname, GLint const  * params);
void glTexParameterIuivEXT(GLenum target, GLenum pname, GLuint const  * params);
void glGetTexParameterIivEXT(GLenum target, GLenum pname, GLint * params);
void glGetTexParameterIuivEXT(GLenum target, GLenum pname, GLuint * params);
void glSamplerParameterIivEXT(GLuint sampler, GLenum pname, GLint const  * param);
void glSamplerParameterIuivEXT(GLuint sampler, GLenum pname, GLuint const  * param);
void glGetSamplerParameterIivEXT(GLuint sampler, GLenum pname, GLint * params);
void glGetSamplerParameterIuivEXT(GLuint sampler, GLenum pname, GLuint * params);
#endif /* GL_EXT_texture_border_clamp */
#ifndef GL_EXT_texture_buffer
#define GL_EXT_texture_buffer 1
constexpr GLenum GL_TEXTURE_BUFFER_EXT = 0x8C2A;
constexpr GLenum GL_TEXTURE_BUFFER_BINDING_EXT = 0x8C2A;
constexpr GLenum GL_MAX_TEXTURE_BUFFER_SIZE_EXT = 0x8C2B;
constexpr GLenum GL_TEXTURE_BINDING_BUFFER_EXT = 0x8C2C;
constexpr GLenum GL_TEXTURE_BUFFER_DATA_STORE_BINDING_EXT = 0x8C2D;
constexpr GLenum GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT_EXT = 0x919F;
constexpr GLenum GL_SAMPLER_BUFFER_EXT = 0x8DC2;
constexpr GLenum GL_INT_SAMPLER_BUFFER_EXT = 0x8DD0;
constexpr GLenum GL_UNSIGNED_INT_SAMPLER_BUFFER_EXT = 0x8DD8;
constexpr GLenum GL_IMAGE_BUFFER_EXT = 0x9051;
constexpr GLenum GL_INT_IMAGE_BUFFER_EXT = 0x905C;
constexpr GLenum GL_UNSIGNED_INT_IMAGE_BUFFER_EXT = 0x9067;
constexpr GLenum GL_TEXTURE_BUFFER_OFFSET_EXT = 0x919D;
constexpr GLenum GL_TEXTURE_BUFFER_SIZE_EXT = 0x919E;
void glTexBufferEXT(GLenum target, GLenum internalformat, GLuint buffer);
void glTexBufferRangeEXT(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
#endif /* GL_EXT_texture_buffer */
#ifndef GL_EXT_texture_compression_astc_decode_mode
#define GL_EXT_texture_compression_astc_decode_mode 1
constexpr GLenum GL_TEXTURE_ASTC_DECODE_PRECISION_EXT = 0x8F69;
#endif /* GL_EXT_texture_compression_astc_decode_mode */
#ifndef GL_EXT_texture_compression_bptc
#define GL_EXT_texture_compression_bptc 1
constexpr GLenum GL_COMPRESSED_RGBA_BPTC_UNORM_EXT = 0x8E8C;
constexpr GLenum GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM_EXT = 0x8E8D;
constexpr GLenum GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT_EXT = 0x8E8E;
constexpr GLenum GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT_EXT = 0x8E8F;
#endif /* GL_EXT_texture_compression_bptc */
#ifndef GL_EXT_texture_compression_dxt1
#define GL_EXT_texture_compression_dxt1 1
constexpr GLenum GL_COMPRESSED_RGB_S3TC_DXT1_EXT = 0x83F0;
constexpr GLenum GL_COMPRESSED_RGBA_S3TC_DXT1_EXT = 0x83F1;
#endif /* GL_EXT_texture_compression_dxt1 */
#ifndef GL_EXT_texture_compression_rgtc
#define GL_EXT_texture_compression_rgtc 1
constexpr GLenum GL_COMPRESSED_RED_RGTC1_EXT = 0x8DBB;
constexpr GLenum GL_COMPRESSED_SIGNED_RED_RGTC1_EXT = 0x8DBC;
constexpr GLenum GL_COMPRESSED_RED_GREEN_RGTC2_EXT = 0x8DBD;
constexpr GLenum GL_COMPRESSED_SIGNED_RED_GREEN_RGTC2_EXT = 0x8DBE;
#endif /* GL_EXT_texture_compression_rgtc */
#ifndef GL_EXT_texture_compression_s3tc
#define GL_EXT_texture_compression_s3tc 1
constexpr GLenum GL_COMPRESSED_RGBA_S3TC_DXT3_EXT = 0x83F2;
constexpr GLenum GL_COMPRESSED_RGBA_S3TC_DXT5_EXT = 0x83F3;
#endif /* GL_EXT_texture_compression_s3tc */
#ifndef GL_EXT_texture_compression_s3tc_srgb
#define GL_EXT_texture_compression_s3tc_srgb 1
constexpr GLenum GL_COMPRESSED_SRGB_S3TC_DXT1_EXT = 0x8C4C;
constexpr GLenum GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT1_EXT = 0x8C4D;
constexpr GLenum GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT3_EXT = 0x8C4E;
constexpr GLenum GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT5_EXT = 0x8C4F;
#endif /* GL_EXT_texture_compression_s3tc_srgb */
#ifndef GL_EXT_texture_cube_map_array
#define GL_EXT_texture_cube_map_array 1
constexpr GLenum GL_TEXTURE_CUBE_MAP_ARRAY_EXT = 0x9009;
constexpr GLenum GL_TEXTURE_BINDING_CUBE_MAP_ARRAY_EXT = 0x900A;
constexpr GLenum GL_SAMPLER_CUBE_MAP_ARRAY_EXT = 0x900C;
constexpr GLenum GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW_EXT = 0x900D;
constexpr GLenum GL_INT_SAMPLER_CUBE_MAP_ARRAY_EXT = 0x900E;
constexpr GLenum GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY_EXT = 0x900F;
constexpr GLenum GL_IMAGE_CUBE_MAP_ARRAY_EXT = 0x9054;
constexpr GLenum GL_INT_IMAGE_CUBE_MAP_ARRAY_EXT = 0x905F;
constexpr GLenum GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY_EXT = 0x906A;
#endif /* GL_EXT_texture_cube_map_array */
#ifndef GL_EXT_texture_filter_anisotropic
#define GL_EXT_texture_filter_anisotropic 1
constexpr GLenum GL_TEXTURE_MAX_ANISOTROPY_EXT = 0x84FE;
constexpr GLenum GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT = 0x84FF;
#endif /* GL_EXT_texture_filter_anisotropic */
#ifndef GL_EXT_texture_filter_minmax
#define GL_EXT_texture_filter_minmax 1
constexpr GLenum GL_TEXTURE_REDUCTION_MODE_EXT = 0x9366;
constexpr GLenum GL_WEIGHTED_AVERAGE_EXT = 0x9367;
#endif /* GL_EXT_texture_filter_minmax */
#ifndef GL_EXT_texture_format_BGRA8888
#define GL_EXT_texture_format_BGRA8888 1
#endif /* GL_EXT_texture_format_BGRA8888 */
#ifndef GL_EXT_texture_format_sRGB_override
#define GL_EXT_texture_format_sRGB_override 1
constexpr GLenum GL_TEXTURE_FORMAT_SRGB_OVERRIDE_EXT = 0x8FBF;
#endif /* GL_EXT_texture_format_sRGB_override */
#ifndef GL_EXT_texture_lod_bias
#define GL_EXT_texture_lod_bias 1
constexpr GLenum GL_MAX_TEXTURE_LOD_BIAS_EXT = 0x84FD;
constexpr GLenum GL_TEXTURE_FILTER_CONTROL_EXT = 0x8500;
constexpr GLenum GL_TEXTURE_LOD_BIAS_EXT = 0x8501;
#endif /* GL_EXT_texture_lod_bias */
#ifndef GL_EXT_texture_mirror_clamp_to_edge
#define GL_EXT_texture_mirror_clamp_to_edge 1
constexpr GLenum GL_MIRROR_CLAMP_TO_EDGE_EXT = 0x8743;
#endif /* GL_EXT_texture_mirror_clamp_to_edge */
#ifndef GL_EXT_texture_norm16
#define GL_EXT_texture_norm16 1
constexpr GLenum GL_R16_EXT = 0x822A;
constexpr GLenum GL_RG16_EXT = 0x822C;
constexpr GLenum GL_RGBA16_EXT = 0x805B;
constexpr GLenum GL_RGB16_EXT = 0x8054;
constexpr GLenum GL_RGB16_SNORM_EXT = 0x8F9A;
#endif /* GL_EXT_texture_norm16 */
#ifndef GL_EXT_texture_query_lod
#define GL_EXT_texture_query_lod 1
#endif /* GL_EXT_texture_query_lod */
#ifndef GL_EXT_texture_rg
#define GL_EXT_texture_rg 1
constexpr GLenum GL_RED_EXT = 0x1903;
constexpr GLenum GL_RG_EXT = 0x8227;
constexpr GLenum GL_R8_EXT = 0x8229;
constexpr GLenum GL_RG8_EXT = 0x822B;
#endif /* GL_EXT_texture_rg */
#ifndef GL_EXT_texture_sRGB_R8
#define GL_EXT_texture_sRGB_R8 1
constexpr GLenum GL_SR8_EXT = 0x8FBD;
#endif /* GL_EXT_texture_sRGB_R8 */
#ifndef GL_EXT_texture_sRGB_RG8
#define GL_EXT_texture_sRGB_RG8 1
constexpr GLenum GL_SRG8_EXT = 0x8FBE;
#endif /* GL_EXT_texture_sRGB_RG8 */
#ifndef GL_EXT_texture_sRGB_decode
#define GL_EXT_texture_sRGB_decode 1
constexpr GLenum GL_TEXTURE_SRGB_DECODE_EXT = 0x8A48;
constexpr GLenum GL_DECODE_EXT = 0x8A49;
constexpr GLenum GL_SKIP_DECODE_EXT = 0x8A4A;
#endif /* GL_EXT_texture_sRGB_decode */
#ifndef GL_EXT_texture_storage
#define GL_EXT_texture_storage 1
constexpr GLenum GL_TEXTURE_IMMUTABLE_FORMAT_EXT = 0x912F;
constexpr GLenum GL_ALPHA8_EXT = 0x803C;
constexpr GLenum GL_LUMINANCE8_EXT = 0x8040;
constexpr GLenum GL_LUMINANCE8_ALPHA8_EXT = 0x8045;
constexpr GLenum GL_RGBA32F_EXT = 0x8814;
constexpr GLenum GL_RGB32F_EXT = 0x8815;
constexpr GLenum GL_ALPHA32F_EXT = 0x8816;
constexpr GLenum GL_LUMINANCE32F_EXT = 0x8818;
constexpr GLenum GL_LUMINANCE_ALPHA32F_EXT = 0x8819;
constexpr GLenum GL_ALPHA16F_EXT = 0x881C;
constexpr GLenum GL_LUMINANCE16F_EXT = 0x881E;
constexpr GLenum GL_LUMINANCE_ALPHA16F_EXT = 0x881F;
constexpr GLenum GL_RGB10_A2_EXT = 0x8059;
constexpr GLenum GL_RGB10_EXT = 0x8052;
constexpr GLenum GL_BGRA8_EXT = 0x93A1;
constexpr GLenum GL_R32F_EXT = 0x822E;
constexpr GLenum GL_RG32F_EXT = 0x8230;
void glTexStorage1DEXT(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
void glTexStorage2DEXT(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
void glTexStorage3DEXT(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
void glTextureStorage1DEXT(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
void glTextureStorage2DEXT(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
void glTextureStorage3DEXT(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
#endif /* GL_EXT_texture_storage */
#ifndef GL_EXT_texture_type_2_10_10_10_REV
#define GL_EXT_texture_type_2_10_10_10_REV 1
constexpr GLenum GL_UNSIGNED_INT_2_10_10_10_REV_EXT = 0x8368;
#endif /* GL_EXT_texture_type_2_10_10_10_REV */
#ifndef GL_EXT_texture_view
#define GL_EXT_texture_view 1
constexpr GLenum GL_TEXTURE_VIEW_MIN_LEVEL_EXT = 0x82DB;
constexpr GLenum GL_TEXTURE_VIEW_NUM_LEVELS_EXT = 0x82DC;
constexpr GLenum GL_TEXTURE_VIEW_MIN_LAYER_EXT = 0x82DD;
constexpr GLenum GL_TEXTURE_VIEW_NUM_LAYERS_EXT = 0x82DE;
constexpr GLenum GL_TEXTURE_IMMUTABLE_LEVELS = 0x82DF;
void glTextureViewEXT(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
#endif /* GL_EXT_texture_view */
#ifndef GL_EXT_unpack_subimage
#define GL_EXT_unpack_subimage 1
constexpr GLenum GL_UNPACK_ROW_LENGTH_EXT = 0x0CF2;
constexpr GLenum GL_UNPACK_SKIP_ROWS_EXT = 0x0CF3;
constexpr GLenum GL_UNPACK_SKIP_PIXELS_EXT = 0x0CF4;
#endif /* GL_EXT_unpack_subimage */
#ifndef GL_EXT_win32_keyed_mutex
#define GL_EXT_win32_keyed_mutex 1
GLboolean glAcquireKeyedMutexWin32EXT(GLuint memory, GLuint64 key, GLuint timeout);
GLboolean glReleaseKeyedMutexWin32EXT(GLuint memory, GLuint64 key);
#endif /* GL_EXT_win32_keyed_mutex */
#ifndef GL_EXT_window_rectangles
#define GL_EXT_window_rectangles 1
constexpr GLenum GL_INCLUSIVE_EXT = 0x8F10;
constexpr GLenum GL_EXCLUSIVE_EXT = 0x8F11;
constexpr GLenum GL_WINDOW_RECTANGLE_EXT = 0x8F12;
constexpr GLenum GL_WINDOW_RECTANGLE_MODE_EXT = 0x8F13;
constexpr GLenum GL_MAX_WINDOW_RECTANGLES_EXT = 0x8F14;
constexpr GLenum GL_NUM_WINDOW_RECTANGLES_EXT = 0x8F15;
void glWindowRectanglesEXT(GLenum mode, GLsizei count, GLint const  * box);
#endif /* GL_EXT_window_rectangles */
#ifndef GL_OES_EGL_image
#define GL_OES_EGL_image 1
void glEGLImageTargetTexture2DOES(GLenum target, GLeglImageOES image);
void glEGLImageTargetRenderbufferStorageOES(GLenum target, GLeglImageOES image);
#endif /* GL_OES_EGL_image */
#ifndef GL_OES_EGL_image_external
#define GL_OES_EGL_image_external 1
constexpr GLenum GL_SAMPLER_EXTERNAL_OES = 0x8D66;
#endif /* GL_OES_EGL_image_external */
#ifndef GL_OES_EGL_image_external_essl3
#define GL_OES_EGL_image_external_essl3 1
#endif /* GL_OES_EGL_image_external_essl3 */
#ifndef GL_OES_blend_equation_separate
#define GL_OES_blend_equation_separate 1
constexpr GLenum GL_BLEND_EQUATION_RGB_OES = 0x8009;
constexpr GLenum GL_BLEND_EQUATION_ALPHA_OES = 0x883D;
void glBlendEquationSeparateOES(GLenum modeRGB, GLenum modeAlpha);
#endif /* GL_OES_blend_equation_separate */
#ifndef GL_OES_blend_func_separate
#define GL_OES_blend_func_separate 1
constexpr GLenum GL_BLEND_DST_RGB_OES = 0x80C8;
constexpr GLenum GL_BLEND_SRC_RGB_OES = 0x80C9;
constexpr GLenum GL_BLEND_DST_ALPHA_OES = 0x80CA;
constexpr GLenum GL_BLEND_SRC_ALPHA_OES = 0x80CB;
void glBlendFuncSeparateOES(GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
#endif /* GL_OES_blend_func_separate */
#ifndef GL_OES_blend_subtract
#define GL_OES_blend_subtract 1
constexpr GLenum GL_BLEND_EQUATION_OES = 0x8009;
constexpr GLenum GL_FUNC_ADD_OES = 0x8006;
constexpr GLenum GL_FUNC_SUBTRACT_OES = 0x800A;
constexpr GLenum GL_FUNC_REVERSE_SUBTRACT_OES = 0x800B;
void glBlendEquationOES(GLenum mode);
#endif /* GL_OES_blend_subtract */
#ifndef GL_OES_byte_coordinates
#define GL_OES_byte_coordinates 1
void glMultiTexCoord1bOES(GLenum texture, GLbyte s);
void glMultiTexCoord1bvOES(GLenum texture, GLbyte const  * coords);
void glMultiTexCoord2bOES(GLenum texture, GLbyte s, GLbyte t);
void glMultiTexCoord2bvOES(GLenum texture, GLbyte const  * coords);
void glMultiTexCoord3bOES(GLenum texture, GLbyte s, GLbyte t, GLbyte r);
void glMultiTexCoord3bvOES(GLenum texture, GLbyte const  * coords);
void glMultiTexCoord4bOES(GLenum texture, GLbyte s, GLbyte t, GLbyte r, GLbyte q);
void glMultiTexCoord4bvOES(GLenum texture, GLbyte const  * coords);
void glTexCoord1bOES(GLbyte s);
void glTexCoord1bvOES(GLbyte const  * coords);
void glTexCoord2bOES(GLbyte s, GLbyte t);
void glTexCoord2bvOES(GLbyte const  * coords);
void glTexCoord3bOES(GLbyte s, GLbyte t, GLbyte r);
void glTexCoord3bvOES(GLbyte const  * coords);
void glTexCoord4bOES(GLbyte s, GLbyte t, GLbyte r, GLbyte q);
void glTexCoord4bvOES(GLbyte const  * coords);
void glVertex2bOES(GLbyte x, GLbyte y);
void glVertex2bvOES(GLbyte const  * coords);
void glVertex3bOES(GLbyte x, GLbyte y, GLbyte z);
void glVertex3bvOES(GLbyte const  * coords);
void glVertex4bOES(GLbyte x, GLbyte y, GLbyte z, GLbyte w);
void glVertex4bvOES(GLbyte const  * coords);
#endif /* GL_OES_byte_coordinates */
#ifndef GL_OES_compressed_ETC1_RGB8_sub_texture
#define GL_OES_compressed_ETC1_RGB8_sub_texture 1
#endif /* GL_OES_compressed_ETC1_RGB8_sub_texture */
#ifndef GL_OES_compressed_ETC1_RGB8_texture
#define GL_OES_compressed_ETC1_RGB8_texture 1
constexpr GLenum GL_ETC1_RGB8_OES = 0x8D64;
#endif /* GL_OES_compressed_ETC1_RGB8_texture */
#ifndef GL_OES_compressed_paletted_texture
#define GL_OES_compressed_paletted_texture 1
constexpr GLenum GL_PALETTE4_RGB8_OES = 0x8B90;
constexpr GLenum GL_PALETTE4_RGBA8_OES = 0x8B91;
constexpr GLenum GL_PALETTE4_R5_G6_B5_OES = 0x8B92;
constexpr GLenum GL_PALETTE4_RGBA4_OES = 0x8B93;
constexpr GLenum GL_PALETTE4_RGB5_A1_OES = 0x8B94;
constexpr GLenum GL_PALETTE8_RGB8_OES = 0x8B95;
constexpr GLenum GL_PALETTE8_RGBA8_OES = 0x8B96;
constexpr GLenum GL_PALETTE8_R5_G6_B5_OES = 0x8B97;
constexpr GLenum GL_PALETTE8_RGBA4_OES = 0x8B98;
constexpr GLenum GL_PALETTE8_RGB5_A1_OES = 0x8B99;
#endif /* GL_OES_compressed_paletted_texture */
#ifndef GL_OES_copy_image
#define GL_OES_copy_image 1
void glCopyImageSubDataOES(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
#endif /* GL_OES_copy_image */
#ifndef GL_OES_depth24
#define GL_OES_depth24 1
constexpr GLenum GL_DEPTH_COMPONENT24_OES = 0x81A6;
#endif /* GL_OES_depth24 */
#ifndef GL_OES_depth32
#define GL_OES_depth32 1
constexpr GLenum GL_DEPTH_COMPONENT32_OES = 0x81A7;
#endif /* GL_OES_depth32 */
#ifndef GL_OES_depth_texture
#define GL_OES_depth_texture 1
#endif /* GL_OES_depth_texture */
#ifndef GL_OES_draw_buffers_indexed
#define GL_OES_draw_buffers_indexed 1
void glEnableiOES(GLenum target, GLuint index);
void glDisableiOES(GLenum target, GLuint index);
void glBlendEquationiOES(GLuint buf, GLenum mode);
void glBlendEquationSeparateiOES(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
void glBlendFunciOES(GLuint buf, GLenum src, GLenum dst);
void glBlendFuncSeparateiOES(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
void glColorMaskiOES(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
GLboolean glIsEnablediOES(GLenum target, GLuint index);
#endif /* GL_OES_draw_buffers_indexed */
#ifndef GL_OES_draw_elements_base_vertex
#define GL_OES_draw_elements_base_vertex 1
void glDrawElementsBaseVertexOES(GLenum mode, GLsizei count, GLenum type, const void * indices, GLint basevertex);
void glDrawRangeElementsBaseVertexOES(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices, GLint basevertex);
void glDrawElementsInstancedBaseVertexOES(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex);
#endif /* GL_OES_draw_elements_base_vertex */
#ifndef GL_OES_draw_texture
#define GL_OES_draw_texture 1
constexpr GLenum GL_TEXTURE_CROP_RECT_OES = 0x8B9D;
void glDrawTexsOES(GLshort x, GLshort y, GLshort z, GLshort width, GLshort height);
void glDrawTexiOES(GLint x, GLint y, GLint z, GLint width, GLint height);
void glDrawTexxOES(GLfixed x, GLfixed y, GLfixed z, GLfixed width, GLfixed height);
void glDrawTexsvOES(GLshort const  * coords);
void glDrawTexivOES(GLint const  * coords);
void glDrawTexxvOES(GLfixed const  * coords);
void glDrawTexfOES(GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height);
void glDrawTexfvOES(GLfloat const  * coords);
#endif /* GL_OES_draw_texture */
#ifndef GL_OES_element_index_uint
#define GL_OES_element_index_uint 1
#endif /* GL_OES_element_index_uint */
#ifndef GL_OES_extended_matrix_palette
#define GL_OES_extended_matrix_palette 1
#endif /* GL_OES_extended_matrix_palette */
#ifndef GL_OES_fbo_render_mipmap
#define GL_OES_fbo_render_mipmap 1
#endif /* GL_OES_fbo_render_mipmap */
#ifndef GL_OES_fixed_point
#define GL_OES_fixed_point 1
constexpr GLenum GL_FIXED_OES = 0x140C;
void glAlphaFuncxOES(GLenum func, GLfixed ref);
void glClearColorxOES(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha);
void glClearDepthxOES(GLfixed depth);
void glClipPlanexOES(GLenum plane, GLfixed const  * equation);
void glColor4xOES(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha);
void glDepthRangexOES(GLfixed n, GLfixed f);
void glFogxOES(GLenum pname, GLfixed param);
void glFogxvOES(GLenum pname, GLfixed const  * param);
void glFrustumxOES(GLfixed l, GLfixed r, GLfixed b, GLfixed t, GLfixed n, GLfixed f);
void glGetClipPlanexOES(GLenum plane, GLfixed * equation);
void glGetFixedvOES(GLenum pname, GLfixed * params);
void glGetTexEnvxvOES(GLenum target, GLenum pname, GLfixed * params);
void glGetTexParameterxvOES(GLenum target, GLenum pname, GLfixed * params);
void glLightModelxOES(GLenum pname, GLfixed param);
void glLightModelxvOES(GLenum pname, GLfixed const  * param);
void glLightxOES(GLenum light, GLenum pname, GLfixed param);
void glLightxvOES(GLenum light, GLenum pname, GLfixed const  * params);
void glLineWidthxOES(GLfixed width);
void glLoadMatrixxOES(GLfixed const  * m);
void glMaterialxOES(GLenum face, GLenum pname, GLfixed param);
void glMaterialxvOES(GLenum face, GLenum pname, GLfixed const  * param);
void glMultMatrixxOES(GLfixed const  * m);
void glMultiTexCoord4xOES(GLenum texture, GLfixed s, GLfixed t, GLfixed r, GLfixed q);
void glNormal3xOES(GLfixed nx, GLfixed ny, GLfixed nz);
void glOrthoxOES(GLfixed l, GLfixed r, GLfixed b, GLfixed t, GLfixed n, GLfixed f);
void glPointParameterxvOES(GLenum pname, GLfixed const  * params);
void glPointSizexOES(GLfixed size);
void glPolygonOffsetxOES(GLfixed factor, GLfixed units);
void glRotatexOES(GLfixed angle, GLfixed x, GLfixed y, GLfixed z);
void glScalexOES(GLfixed x, GLfixed y, GLfixed z);
void glTexEnvxOES(GLenum target, GLenum pname, GLfixed param);
void glTexEnvxvOES(GLenum target, GLenum pname, GLfixed const  * params);
void glTexParameterxOES(GLenum target, GLenum pname, GLfixed param);
void glTexParameterxvOES(GLenum target, GLenum pname, GLfixed const  * params);
void glTranslatexOES(GLfixed x, GLfixed y, GLfixed z);
void glGetLightxvOES(GLenum light, GLenum pname, GLfixed * params);
void glGetMaterialxvOES(GLenum face, GLenum pname, GLfixed * params);
void glPointParameterxOES(GLenum pname, GLfixed param);
void glSampleCoveragexOES(GLclampx value, GLboolean invert);
void glAccumxOES(GLenum op, GLfixed value);
void glBitmapxOES(GLsizei width, GLsizei height, GLfixed xorig, GLfixed yorig, GLfixed xmove, GLfixed ymove, GLubyte const  * bitmap);
void glBlendColorxOES(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha);
void glClearAccumxOES(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha);
void glColor3xOES(GLfixed red, GLfixed green, GLfixed blue);
void glColor3xvOES(GLfixed const  * components);
void glColor4xvOES(GLfixed const  * components);
void glConvolutionParameterxOES(GLenum target, GLenum pname, GLfixed param);
void glConvolutionParameterxvOES(GLenum target, GLenum pname, GLfixed const  * params);
void glEvalCoord1xOES(GLfixed u);
void glEvalCoord1xvOES(GLfixed const  * coords);
void glEvalCoord2xOES(GLfixed u, GLfixed v);
void glEvalCoord2xvOES(GLfixed const  * coords);
void glFeedbackBufferxOES(GLsizei n, GLenum type, GLfixed const  * buffer);
void glGetConvolutionParameterxvOES(GLenum target, GLenum pname, GLfixed * params);
void glGetHistogramParameterxvOES(GLenum target, GLenum pname, GLfixed * params);
void glGetLightxOES(GLenum light, GLenum pname, GLfixed * params);
void glGetMapxvOES(GLenum target, GLenum query, GLfixed * v);
void glGetMaterialxOES(GLenum face, GLenum pname, GLfixed param);
void glGetPixelMapxv(GLenum map, GLint size, GLfixed * values);
void glGetTexGenxvOES(GLenum coord, GLenum pname, GLfixed * params);
void glGetTexLevelParameterxvOES(GLenum target, GLint level, GLenum pname, GLfixed * params);
void glIndexxOES(GLfixed component);
void glIndexxvOES(GLfixed const  * component);
void glLoadTransposeMatrixxOES(GLfixed const  * m);
void glMap1xOES(GLenum target, GLfixed u1, GLfixed u2, GLint stride, GLint order, GLfixed points);
void glMap2xOES(GLenum target, GLfixed u1, GLfixed u2, GLint ustride, GLint uorder, GLfixed v1, GLfixed v2, GLint vstride, GLint vorder, GLfixed points);
void glMapGrid1xOES(GLint n, GLfixed u1, GLfixed u2);
void glMapGrid2xOES(GLint n, GLfixed u1, GLfixed u2, GLfixed v1, GLfixed v2);
void glMultTransposeMatrixxOES(GLfixed const  * m);
void glMultiTexCoord1xOES(GLenum texture, GLfixed s);
void glMultiTexCoord1xvOES(GLenum texture, GLfixed const  * coords);
void glMultiTexCoord2xOES(GLenum texture, GLfixed s, GLfixed t);
void glMultiTexCoord2xvOES(GLenum texture, GLfixed const  * coords);
void glMultiTexCoord3xOES(GLenum texture, GLfixed s, GLfixed t, GLfixed r);
void glMultiTexCoord3xvOES(GLenum texture, GLfixed const  * coords);
void glMultiTexCoord4xvOES(GLenum texture, GLfixed const  * coords);
void glNormal3xvOES(GLfixed const  * coords);
void glPassThroughxOES(GLfixed token);
void glPixelMapx(GLenum map, GLint size, GLfixed const  * values);
void glPixelStorex(GLenum pname, GLfixed param);
void glPixelTransferxOES(GLenum pname, GLfixed param);
void glPixelZoomxOES(GLfixed xfactor, GLfixed yfactor);
void glPrioritizeTexturesxOES(GLsizei n, GLuint const  * textures, GLfixed const  * priorities);
void glRasterPos2xOES(GLfixed x, GLfixed y);
void glRasterPos2xvOES(GLfixed const  * coords);
void glRasterPos3xOES(GLfixed x, GLfixed y, GLfixed z);
void glRasterPos3xvOES(GLfixed const  * coords);
void glRasterPos4xOES(GLfixed x, GLfixed y, GLfixed z, GLfixed w);
void glRasterPos4xvOES(GLfixed const  * coords);
void glRectxOES(GLfixed x1, GLfixed y1, GLfixed x2, GLfixed y2);
void glRectxvOES(GLfixed const  * v1, GLfixed const  * v2);
void glTexCoord1xOES(GLfixed s);
void glTexCoord1xvOES(GLfixed const  * coords);
void glTexCoord2xOES(GLfixed s, GLfixed t);
void glTexCoord2xvOES(GLfixed const  * coords);
void glTexCoord3xOES(GLfixed s, GLfixed t, GLfixed r);
void glTexCoord3xvOES(GLfixed const  * coords);
void glTexCoord4xOES(GLfixed s, GLfixed t, GLfixed r, GLfixed q);
void glTexCoord4xvOES(GLfixed const  * coords);
void glTexGenxOES(GLenum coord, GLenum pname, GLfixed param);
void glTexGenxvOES(GLenum coord, GLenum pname, GLfixed const  * params);
void glVertex2xOES(GLfixed x);
void glVertex2xvOES(GLfixed const  * coords);
void glVertex3xOES(GLfixed x, GLfixed y);
void glVertex3xvOES(GLfixed const  * coords);
void glVertex4xOES(GLfixed x, GLfixed y, GLfixed z);
void glVertex4xvOES(GLfixed const  * coords);
#endif /* GL_OES_fixed_point */
#ifndef GL_OES_fragment_precision_high
#define GL_OES_fragment_precision_high 1
#endif /* GL_OES_fragment_precision_high */
#ifndef GL_OES_framebuffer_object
#define GL_OES_framebuffer_object 1
constexpr GLenum GL_NONE_OES = 0;
constexpr GLenum GL_FRAMEBUFFER_OES = 0x8D40;
constexpr GLenum GL_RENDERBUFFER_OES = 0x8D41;
constexpr GLenum GL_RGBA4_OES = 0x8056;
constexpr GLenum GL_RGB5_A1_OES = 0x8057;
constexpr GLenum GL_RGB565_OES = 0x8D62;
constexpr GLenum GL_DEPTH_COMPONENT16_OES = 0x81A5;
constexpr GLenum GL_RENDERBUFFER_WIDTH_OES = 0x8D42;
constexpr GLenum GL_RENDERBUFFER_HEIGHT_OES = 0x8D43;
constexpr GLenum GL_RENDERBUFFER_INTERNAL_FORMAT_OES = 0x8D44;
constexpr GLenum GL_RENDERBUFFER_RED_SIZE_OES = 0x8D50;
constexpr GLenum GL_RENDERBUFFER_GREEN_SIZE_OES = 0x8D51;
constexpr GLenum GL_RENDERBUFFER_BLUE_SIZE_OES = 0x8D52;
constexpr GLenum GL_RENDERBUFFER_ALPHA_SIZE_OES = 0x8D53;
constexpr GLenum GL_RENDERBUFFER_DEPTH_SIZE_OES = 0x8D54;
constexpr GLenum GL_RENDERBUFFER_STENCIL_SIZE_OES = 0x8D55;
constexpr GLenum GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE_OES = 0x8CD0;
constexpr GLenum GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME_OES = 0x8CD1;
constexpr GLenum GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL_OES = 0x8CD2;
constexpr GLenum GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE_OES = 0x8CD3;
constexpr GLenum GL_COLOR_ATTACHMENT0_OES = 0x8CE0;
constexpr GLenum GL_DEPTH_ATTACHMENT_OES = 0x8D00;
constexpr GLenum GL_STENCIL_ATTACHMENT_OES = 0x8D20;
constexpr GLenum GL_FRAMEBUFFER_COMPLETE_OES = 0x8CD5;
constexpr GLenum GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT_OES = 0x8CD6;
constexpr GLenum GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT_OES = 0x8CD7;
constexpr GLenum GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS_OES = 0x8CD9;
constexpr GLenum GL_FRAMEBUFFER_INCOMPLETE_FORMATS_OES = 0x8CDA;
constexpr GLenum GL_FRAMEBUFFER_UNSUPPORTED_OES = 0x8CDD;
constexpr GLenum GL_FRAMEBUFFER_BINDING_OES = 0x8CA6;
constexpr GLenum GL_RENDERBUFFER_BINDING_OES = 0x8CA7;
constexpr GLenum GL_MAX_RENDERBUFFER_SIZE_OES = 0x84E8;
constexpr GLenum GL_INVALID_FRAMEBUFFER_OPERATION_OES = 0x0506;
GLboolean glIsRenderbufferOES(GLuint renderbuffer);
void glBindRenderbufferOES(GLenum target, GLuint renderbuffer);
void glDeleteRenderbuffersOES(GLsizei n, GLuint const  * renderbuffers);
void glGenRenderbuffersOES(GLsizei n, GLuint * renderbuffers);
void glRenderbufferStorageOES(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
void glGetRenderbufferParameterivOES(GLenum target, GLenum pname, GLint * params);
GLboolean glIsFramebufferOES(GLuint framebuffer);
void glBindFramebufferOES(GLenum target, GLuint framebuffer);
void glDeleteFramebuffersOES(GLsizei n, GLuint const  * framebuffers);
void glGenFramebuffersOES(GLsizei n, GLuint * framebuffers);
GLenum glCheckFramebufferStatusOES(GLenum target);
void glFramebufferRenderbufferOES(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
void glFramebufferTexture2DOES(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
void glGetFramebufferAttachmentParameterivOES(GLenum target, GLenum attachment, GLenum pname, GLint * params);
void glGenerateMipmapOES(GLenum target);
#endif /* GL_OES_framebuffer_object */
#ifndef GL_OES_geometry_point_size
#define GL_OES_geometry_point_size 1
#endif /* GL_OES_geometry_point_size */
#ifndef GL_OES_geometry_shader
#define GL_OES_geometry_shader 1
constexpr GLenum GL_GEOMETRY_SHADER_OES = 0x8DD9;
constexpr GLenum GL_GEOMETRY_SHADER_BIT_OES = 0x00000004;
constexpr GLenum GL_GEOMETRY_LINKED_VERTICES_OUT_OES = 0x8916;
constexpr GLenum GL_GEOMETRY_LINKED_INPUT_TYPE_OES = 0x8917;
constexpr GLenum GL_GEOMETRY_LINKED_OUTPUT_TYPE_OES = 0x8918;
constexpr GLenum GL_GEOMETRY_SHADER_INVOCATIONS_OES = 0x887F;
constexpr GLenum GL_LAYER_PROVOKING_VERTEX_OES = 0x825E;
constexpr GLenum GL_LINES_ADJACENCY_OES = 0x000A;
constexpr GLenum GL_LINE_STRIP_ADJACENCY_OES = 0x000B;
constexpr GLenum GL_TRIANGLES_ADJACENCY_OES = 0x000C;
constexpr GLenum GL_TRIANGLE_STRIP_ADJACENCY_OES = 0x000D;
constexpr GLenum GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_OES = 0x8DDF;
constexpr GLenum GL_MAX_GEOMETRY_UNIFORM_BLOCKS_OES = 0x8A2C;
constexpr GLenum GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS_OES = 0x8A32;
constexpr GLenum GL_MAX_GEOMETRY_INPUT_COMPONENTS_OES = 0x9123;
constexpr GLenum GL_MAX_GEOMETRY_OUTPUT_COMPONENTS_OES = 0x9124;
constexpr GLenum GL_MAX_GEOMETRY_OUTPUT_VERTICES_OES = 0x8DE0;
constexpr GLenum GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_OES = 0x8DE1;
constexpr GLenum GL_MAX_GEOMETRY_SHADER_INVOCATIONS_OES = 0x8E5A;
constexpr GLenum GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_OES = 0x8C29;
constexpr GLenum GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS_OES = 0x92CF;
constexpr GLenum GL_MAX_GEOMETRY_ATOMIC_COUNTERS_OES = 0x92D5;
constexpr GLenum GL_MAX_GEOMETRY_IMAGE_UNIFORMS_OES = 0x90CD;
constexpr GLenum GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS_OES = 0x90D7;
constexpr GLenum GL_FIRST_VERTEX_CONVENTION_OES = 0x8E4D;
constexpr GLenum GL_LAST_VERTEX_CONVENTION_OES = 0x8E4E;
constexpr GLenum GL_UNDEFINED_VERTEX_OES = 0x8260;
constexpr GLenum GL_PRIMITIVES_GENERATED_OES = 0x8C87;
constexpr GLenum GL_FRAMEBUFFER_DEFAULT_LAYERS_OES = 0x9312;
constexpr GLenum GL_MAX_FRAMEBUFFER_LAYERS_OES = 0x9317;
constexpr GLenum GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_OES = 0x8DA8;
constexpr GLenum GL_FRAMEBUFFER_ATTACHMENT_LAYERED_OES = 0x8DA7;
constexpr GLenum GL_REFERENCED_BY_GEOMETRY_SHADER_OES = 0x9309;
void glFramebufferTextureOES(GLenum target, GLenum attachment, GLuint texture, GLint level);
#endif /* GL_OES_geometry_shader */
#ifndef GL_OES_get_program_binary
#define GL_OES_get_program_binary 1
constexpr GLenum GL_PROGRAM_BINARY_LENGTH_OES = 0x8741;
constexpr GLenum GL_NUM_PROGRAM_BINARY_FORMATS_OES = 0x87FE;
constexpr GLenum GL_PROGRAM_BINARY_FORMATS_OES = 0x87FF;
void glGetProgramBinaryOES(GLuint program, GLsizei bufSize, GLsizei * length, GLenum * binaryFormat, void * binary);
void glProgramBinaryOES(GLuint program, GLenum binaryFormat, const void * binary, GLint length);
#endif /* GL_OES_get_program_binary */
#ifndef GL_OES_gpu_shader5
#define GL_OES_gpu_shader5 1
#endif /* GL_OES_gpu_shader5 */
#ifndef GL_OES_mapbuffer
#define GL_OES_mapbuffer 1
constexpr GLenum GL_WRITE_ONLY_OES = 0x88B9;
constexpr GLenum GL_BUFFER_ACCESS_OES = 0x88BB;
constexpr GLenum GL_BUFFER_MAPPED_OES = 0x88BC;
constexpr GLenum GL_BUFFER_MAP_POINTER_OES = 0x88BD;
void * glMapBufferOES(GLenum target, GLenum access);
GLboolean glUnmapBufferOES(GLenum target);
void glGetBufferPointervOES(GLenum target, GLenum pname, void ** params);
#endif /* GL_OES_mapbuffer */
#ifndef GL_OES_matrix_get
#define GL_OES_matrix_get 1
constexpr GLenum GL_MODELVIEW_MATRIX_FLOAT_AS_INT_BITS_OES = 0x898D;
constexpr GLenum GL_PROJECTION_MATRIX_FLOAT_AS_INT_BITS_OES = 0x898E;
constexpr GLenum GL_TEXTURE_MATRIX_FLOAT_AS_INT_BITS_OES = 0x898F;
#endif /* GL_OES_matrix_get */
#ifndef GL_OES_matrix_palette
#define GL_OES_matrix_palette 1
constexpr GLenum GL_MAX_VERTEX_UNITS_OES = 0x86A4;
constexpr GLenum GL_MAX_PALETTE_MATRICES_OES = 0x8842;
constexpr GLenum GL_MATRIX_PALETTE_OES = 0x8840;
constexpr GLenum GL_MATRIX_INDEX_ARRAY_OES = 0x8844;
constexpr GLenum GL_WEIGHT_ARRAY_OES = 0x86AD;
constexpr GLenum GL_CURRENT_PALETTE_MATRIX_OES = 0x8843;
constexpr GLenum GL_MATRIX_INDEX_ARRAY_SIZE_OES = 0x8846;
constexpr GLenum GL_MATRIX_INDEX_ARRAY_TYPE_OES = 0x8847;
constexpr GLenum GL_MATRIX_INDEX_ARRAY_STRIDE_OES = 0x8848;
constexpr GLenum GL_MATRIX_INDEX_ARRAY_POINTER_OES = 0x8849;
constexpr GLenum GL_MATRIX_INDEX_ARRAY_BUFFER_BINDING_OES = 0x8B9E;
constexpr GLenum GL_WEIGHT_ARRAY_SIZE_OES = 0x86AB;
constexpr GLenum GL_WEIGHT_ARRAY_TYPE_OES = 0x86A9;
constexpr GLenum GL_WEIGHT_ARRAY_STRIDE_OES = 0x86AA;
constexpr GLenum GL_WEIGHT_ARRAY_POINTER_OES = 0x86AC;
constexpr GLenum GL_WEIGHT_ARRAY_BUFFER_BINDING_OES = 0x889E;
void glCurrentPaletteMatrixOES(GLuint matrixpaletteindex);
void glLoadPaletteFromModelViewMatrixOES();
void glMatrixIndexPointerOES(GLint size, GLenum type, GLsizei stride, const void * pointer);
void glWeightPointerOES(GLint size, GLenum type, GLsizei stride, const void * pointer);
#endif /* GL_OES_matrix_palette */
#ifndef GL_OES_packed_depth_stencil
#define GL_OES_packed_depth_stencil 1
constexpr GLenum GL_DEPTH_STENCIL_OES = 0x84F9;
constexpr GLenum GL_UNSIGNED_INT_24_8_OES = 0x84FA;
constexpr GLenum GL_DEPTH24_STENCIL8_OES = 0x88F0;
#endif /* GL_OES_packed_depth_stencil */
#ifndef GL_OES_point_size_array
#define GL_OES_point_size_array 1
constexpr GLenum GL_POINT_SIZE_ARRAY_OES = 0x8B9C;
constexpr GLenum GL_POINT_SIZE_ARRAY_TYPE_OES = 0x898A;
constexpr GLenum GL_POINT_SIZE_ARRAY_STRIDE_OES = 0x898B;
constexpr GLenum GL_POINT_SIZE_ARRAY_POINTER_OES = 0x898C;
constexpr GLenum GL_POINT_SIZE_ARRAY_BUFFER_BINDING_OES = 0x8B9F;
void glPointSizePointerOES(GLenum type, GLsizei stride, const void * pointer);
#endif /* GL_OES_point_size_array */
#ifndef GL_OES_point_sprite
#define GL_OES_point_sprite 1
constexpr GLenum GL_POINT_SPRITE_OES = 0x8861;
constexpr GLenum GL_COORD_REPLACE_OES = 0x8862;
#endif /* GL_OES_point_sprite */
#ifndef GL_OES_primitive_bounding_box
#define GL_OES_primitive_bounding_box 1
constexpr GLenum GL_PRIMITIVE_BOUNDING_BOX_OES = 0x92BE;
void glPrimitiveBoundingBoxOES(GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat minW, GLfloat maxX, GLfloat maxY, GLfloat maxZ, GLfloat maxW);
#endif /* GL_OES_primitive_bounding_box */
#ifndef GL_OES_query_matrix
#define GL_OES_query_matrix 1
GLbitfield glQueryMatrixxOES(GLfixed * mantissa, GLint * exponent);
#endif /* GL_OES_query_matrix */
#ifndef GL_OES_read_format
#define GL_OES_read_format 1
constexpr GLenum GL_IMPLEMENTATION_COLOR_READ_TYPE_OES = 0x8B9A;
constexpr GLenum GL_IMPLEMENTATION_COLOR_READ_FORMAT_OES = 0x8B9B;
#endif /* GL_OES_read_format */
#ifndef GL_OES_required_internalformat
#define GL_OES_required_internalformat 1
constexpr GLenum GL_ALPHA8_OES = 0x803C;
constexpr GLenum GL_LUMINANCE4_ALPHA4_OES = 0x8043;
constexpr GLenum GL_LUMINANCE8_ALPHA8_OES = 0x8045;
constexpr GLenum GL_LUMINANCE8_OES = 0x8040;
constexpr GLenum GL_RGB8_OES = 0x8051;
constexpr GLenum GL_RGBA8_OES = 0x8058;
#endif /* GL_OES_required_internalformat */
#ifndef GL_OES_rgb8_rgba8
#define GL_OES_rgb8_rgba8 1
#endif /* GL_OES_rgb8_rgba8 */
#ifndef GL_OES_sample_shading
#define GL_OES_sample_shading 1
constexpr GLenum GL_SAMPLE_SHADING_OES = 0x8C36;
constexpr GLenum GL_MIN_SAMPLE_SHADING_VALUE_OES = 0x8C37;
void glMinSampleShadingOES(GLfloat value);
#endif /* GL_OES_sample_shading */
#ifndef GL_OES_sample_variables
#define GL_OES_sample_variables 1
#endif /* GL_OES_sample_variables */
#ifndef GL_OES_shader_image_atomic
#define GL_OES_shader_image_atomic 1
#endif /* GL_OES_shader_image_atomic */
#ifndef GL_OES_shader_io_blocks
#define GL_OES_shader_io_blocks 1
#endif /* GL_OES_shader_io_blocks */
#ifndef GL_OES_shader_multisample_interpolation
#define GL_OES_shader_multisample_interpolation 1
constexpr GLenum GL_MIN_FRAGMENT_INTERPOLATION_OFFSET_OES = 0x8E5B;
constexpr GLenum GL_MAX_FRAGMENT_INTERPOLATION_OFFSET_OES = 0x8E5C;
constexpr GLenum GL_FRAGMENT_INTERPOLATION_OFFSET_BITS_OES = 0x8E5D;
#endif /* GL_OES_shader_multisample_interpolation */
#ifndef GL_OES_single_precision
#define GL_OES_single_precision 1
void glClearDepthfOES(GLclampf depth);
void glClipPlanefOES(GLenum plane, GLfloat const  * equation);
void glDepthRangefOES(GLclampf n, GLclampf f);
void glFrustumfOES(GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f);
void glGetClipPlanefOES(GLenum plane, GLfloat * equation);
void glOrthofOES(GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f);
#endif /* GL_OES_single_precision */
#ifndef GL_OES_standard_derivatives
#define GL_OES_standard_derivatives 1
constexpr GLenum GL_FRAGMENT_SHADER_DERIVATIVE_HINT_OES = 0x8B8B;
#endif /* GL_OES_standard_derivatives */
#ifndef GL_OES_stencil1
#define GL_OES_stencil1 1
constexpr GLenum GL_STENCIL_INDEX1_OES = 0x8D46;
#endif /* GL_OES_stencil1 */
#ifndef GL_OES_stencil4
#define GL_OES_stencil4 1
constexpr GLenum GL_STENCIL_INDEX4_OES = 0x8D47;
#endif /* GL_OES_stencil4 */
#ifndef GL_OES_stencil8
#define GL_OES_stencil8 1
constexpr GLenum GL_STENCIL_INDEX8_OES = 0x8D48;
#endif /* GL_OES_stencil8 */
#ifndef GL_OES_stencil_wrap
#define GL_OES_stencil_wrap 1
constexpr GLenum GL_INCR_WRAP_OES = 0x8507;
constexpr GLenum GL_DECR_WRAP_OES = 0x8508;
#endif /* GL_OES_stencil_wrap */
#ifndef GL_OES_surfaceless_context
#define GL_OES_surfaceless_context 1
constexpr GLenum GL_FRAMEBUFFER_UNDEFINED_OES = 0x8219;
#endif /* GL_OES_surfaceless_context */
#ifndef GL_OES_tessellation_point_size
#define GL_OES_tessellation_point_size 1
#endif /* GL_OES_tessellation_point_size */
#ifndef GL_OES_tessellation_shader
#define GL_OES_tessellation_shader 1
constexpr GLenum GL_PATCHES_OES = 0x000E;
constexpr GLenum GL_PATCH_VERTICES_OES = 0x8E72;
constexpr GLenum GL_TESS_CONTROL_OUTPUT_VERTICES_OES = 0x8E75;
constexpr GLenum GL_TESS_GEN_MODE_OES = 0x8E76;
constexpr GLenum GL_TESS_GEN_SPACING_OES = 0x8E77;
constexpr GLenum GL_TESS_GEN_VERTEX_ORDER_OES = 0x8E78;
constexpr GLenum GL_TESS_GEN_POINT_MODE_OES = 0x8E79;
constexpr GLenum GL_ISOLINES_OES = 0x8E7A;
constexpr GLenum GL_QUADS_OES = 0x0007;
constexpr GLenum GL_FRACTIONAL_ODD_OES = 0x8E7B;
constexpr GLenum GL_FRACTIONAL_EVEN_OES = 0x8E7C;
constexpr GLenum GL_MAX_PATCH_VERTICES_OES = 0x8E7D;
constexpr GLenum GL_MAX_TESS_GEN_LEVEL_OES = 0x8E7E;
constexpr GLenum GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS_OES = 0x8E7F;
constexpr GLenum GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS_OES = 0x8E80;
constexpr GLenum GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS_OES = 0x8E81;
constexpr GLenum GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS_OES = 0x8E82;
constexpr GLenum GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS_OES = 0x8E83;
constexpr GLenum GL_MAX_TESS_PATCH_COMPONENTS_OES = 0x8E84;
constexpr GLenum GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS_OES = 0x8E85;
constexpr GLenum GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS_OES = 0x8E86;
constexpr GLenum GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS_OES = 0x8E89;
constexpr GLenum GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS_OES = 0x8E8A;
constexpr GLenum GL_MAX_TESS_CONTROL_INPUT_COMPONENTS_OES = 0x886C;
constexpr GLenum GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS_OES = 0x886D;
constexpr GLenum GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS_OES = 0x8E1E;
constexpr GLenum GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS_OES = 0x8E1F;
constexpr GLenum GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS_OES = 0x92CD;
constexpr GLenum GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS_OES = 0x92CE;
constexpr GLenum GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS_OES = 0x92D3;
constexpr GLenum GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS_OES = 0x92D4;
constexpr GLenum GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS_OES = 0x90CB;
constexpr GLenum GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS_OES = 0x90CC;
constexpr GLenum GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS_OES = 0x90D8;
constexpr GLenum GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS_OES = 0x90D9;
constexpr GLenum GL_PRIMITIVE_RESTART_FOR_PATCHES_SUPPORTED_OES = 0x8221;
constexpr GLenum GL_IS_PER_PATCH_OES = 0x92E7;
constexpr GLenum GL_REFERENCED_BY_TESS_CONTROL_SHADER_OES = 0x9307;
constexpr GLenum GL_REFERENCED_BY_TESS_EVALUATION_SHADER_OES = 0x9308;
constexpr GLenum GL_TESS_CONTROL_SHADER_OES = 0x8E88;
constexpr GLenum GL_TESS_EVALUATION_SHADER_OES = 0x8E87;
constexpr GLenum GL_TESS_CONTROL_SHADER_BIT_OES = 0x00000008;
constexpr GLenum GL_TESS_EVALUATION_SHADER_BIT_OES = 0x00000010;
void glPatchParameteriOES(GLenum pname, GLint value);
#endif /* GL_OES_tessellation_shader */
#ifndef GL_OES_texture_3D
#define GL_OES_texture_3D 1
constexpr GLenum GL_TEXTURE_WRAP_R_OES = 0x8072;
constexpr GLenum GL_TEXTURE_3D_OES = 0x806F;
constexpr GLenum GL_TEXTURE_BINDING_3D_OES = 0x806A;
constexpr GLenum GL_MAX_3D_TEXTURE_SIZE_OES = 0x8073;
constexpr GLenum GL_SAMPLER_3D_OES = 0x8B5F;
constexpr GLenum GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_3D_ZOFFSET_OES = 0x8CD4;
void glTexImage3DOES(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void * pixels);
void glTexSubImage3DOES(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels);
void glCopyTexSubImage3DOES(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
void glCompressedTexImage3DOES(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void * data);
void glCompressedTexSubImage3DOES(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * data);
void glFramebufferTexture3DOES(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
#endif /* GL_OES_texture_3D */
#ifndef GL_OES_texture_border_clamp
#define GL_OES_texture_border_clamp 1
constexpr GLenum GL_TEXTURE_BORDER_COLOR_OES = 0x1004;
constexpr GLenum GL_CLAMP_TO_BORDER_OES = 0x812D;
void glTexParameterIivOES(GLenum target, GLenum pname, GLint const  * params);
void glTexParameterIuivOES(GLenum target, GLenum pname, GLuint const  * params);
void glGetTexParameterIivOES(GLenum target, GLenum pname, GLint * params);
void glGetTexParameterIuivOES(GLenum target, GLenum pname, GLuint * params);
void glSamplerParameterIivOES(GLuint sampler, GLenum pname, GLint const  * param);
void glSamplerParameterIuivOES(GLuint sampler, GLenum pname, GLuint const  * param);
void glGetSamplerParameterIivOES(GLuint sampler, GLenum pname, GLint * params);
void glGetSamplerParameterIuivOES(GLuint sampler, GLenum pname, GLuint * params);
#endif /* GL_OES_texture_border_clamp */
#ifndef GL_OES_texture_buffer
#define GL_OES_texture_buffer 1
constexpr GLenum GL_TEXTURE_BUFFER_OES = 0x8C2A;
constexpr GLenum GL_TEXTURE_BUFFER_BINDING_OES = 0x8C2A;
constexpr GLenum GL_MAX_TEXTURE_BUFFER_SIZE_OES = 0x8C2B;
constexpr GLenum GL_TEXTURE_BINDING_BUFFER_OES = 0x8C2C;
constexpr GLenum GL_TEXTURE_BUFFER_DATA_STORE_BINDING_OES = 0x8C2D;
constexpr GLenum GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT_OES = 0x919F;
constexpr GLenum GL_SAMPLER_BUFFER_OES = 0x8DC2;
constexpr GLenum GL_INT_SAMPLER_BUFFER_OES = 0x8DD0;
constexpr GLenum GL_UNSIGNED_INT_SAMPLER_BUFFER_OES = 0x8DD8;
constexpr GLenum GL_IMAGE_BUFFER_OES = 0x9051;
constexpr GLenum GL_INT_IMAGE_BUFFER_OES = 0x905C;
constexpr GLenum GL_UNSIGNED_INT_IMAGE_BUFFER_OES = 0x9067;
constexpr GLenum GL_TEXTURE_BUFFER_OFFSET_OES = 0x919D;
constexpr GLenum GL_TEXTURE_BUFFER_SIZE_OES = 0x919E;
void glTexBufferOES(GLenum target, GLenum internalformat, GLuint buffer);
void glTexBufferRangeOES(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
#endif /* GL_OES_texture_buffer */
#ifndef GL_OES_texture_compression_astc
#define GL_OES_texture_compression_astc 1
constexpr GLenum GL_COMPRESSED_RGBA_ASTC_4x4_KHR = 0x93B0;
constexpr GLenum GL_COMPRESSED_RGBA_ASTC_5x4_KHR = 0x93B1;
constexpr GLenum GL_COMPRESSED_RGBA_ASTC_5x5_KHR = 0x93B2;
constexpr GLenum GL_COMPRESSED_RGBA_ASTC_6x5_KHR = 0x93B3;
constexpr GLenum GL_COMPRESSED_RGBA_ASTC_6x6_KHR = 0x93B4;
constexpr GLenum GL_COMPRESSED_RGBA_ASTC_8x5_KHR = 0x93B5;
constexpr GLenum GL_COMPRESSED_RGBA_ASTC_8x6_KHR = 0x93B6;
constexpr GLenum GL_COMPRESSED_RGBA_ASTC_8x8_KHR = 0x93B7;
constexpr GLenum GL_COMPRESSED_RGBA_ASTC_10x5_KHR = 0x93B8;
constexpr GLenum GL_COMPRESSED_RGBA_ASTC_10x6_KHR = 0x93B9;
constexpr GLenum GL_COMPRESSED_RGBA_ASTC_10x8_KHR = 0x93BA;
constexpr GLenum GL_COMPRESSED_RGBA_ASTC_10x10_KHR = 0x93BB;
constexpr GLenum GL_COMPRESSED_RGBA_ASTC_12x10_KHR = 0x93BC;
constexpr GLenum GL_COMPRESSED_RGBA_ASTC_12x12_KHR = 0x93BD;
constexpr GLenum GL_COMPRESSED_SRGB8_ALPHA8_ASTC_4x4_KHR = 0x93D0;
constexpr GLenum GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x4_KHR = 0x93D1;
constexpr GLenum GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x5_KHR = 0x93D2;
constexpr GLenum GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x5_KHR = 0x93D3;
constexpr GLenum GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x6_KHR = 0x93D4;
constexpr GLenum GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x5_KHR = 0x93D5;
constexpr GLenum GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x6_KHR = 0x93D6;
constexpr GLenum GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x8_KHR = 0x93D7;
constexpr GLenum GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x5_KHR = 0x93D8;
constexpr GLenum GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x6_KHR = 0x93D9;
constexpr GLenum GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x8_KHR = 0x93DA;
constexpr GLenum GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x10_KHR = 0x93DB;
constexpr GLenum GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x10_KHR = 0x93DC;
constexpr GLenum GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x12_KHR = 0x93DD;
constexpr GLenum GL_COMPRESSED_RGBA_ASTC_3x3x3_OES = 0x93C0;
constexpr GLenum GL_COMPRESSED_RGBA_ASTC_4x3x3_OES = 0x93C1;
constexpr GLenum GL_COMPRESSED_RGBA_ASTC_4x4x3_OES = 0x93C2;
constexpr GLenum GL_COMPRESSED_RGBA_ASTC_4x4x4_OES = 0x93C3;
constexpr GLenum GL_COMPRESSED_RGBA_ASTC_5x4x4_OES = 0x93C4;
constexpr GLenum GL_COMPRESSED_RGBA_ASTC_5x5x4_OES = 0x93C5;
constexpr GLenum GL_COMPRESSED_RGBA_ASTC_5x5x5_OES = 0x93C6;
constexpr GLenum GL_COMPRESSED_RGBA_ASTC_6x5x5_OES = 0x93C7;
constexpr GLenum GL_COMPRESSED_RGBA_ASTC_6x6x5_OES = 0x93C8;
constexpr GLenum GL_COMPRESSED_RGBA_ASTC_6x6x6_OES = 0x93C9;
constexpr GLenum GL_COMPRESSED_SRGB8_ALPHA8_ASTC_3x3x3_OES = 0x93E0;
constexpr GLenum GL_COMPRESSED_SRGB8_ALPHA8_ASTC_4x3x3_OES = 0x93E1;
constexpr GLenum GL_COMPRESSED_SRGB8_ALPHA8_ASTC_4x4x3_OES = 0x93E2;
constexpr GLenum GL_COMPRESSED_SRGB8_ALPHA8_ASTC_4x4x4_OES = 0x93E3;
constexpr GLenum GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x4x4_OES = 0x93E4;
constexpr GLenum GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x5x4_OES = 0x93E5;
constexpr GLenum GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x5x5_OES = 0x93E6;
constexpr GLenum GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x5x5_OES = 0x93E7;
constexpr GLenum GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x6x5_OES = 0x93E8;
constexpr GLenum GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x6x6_OES = 0x93E9;
#endif /* GL_OES_texture_compression_astc */
#ifndef GL_OES_texture_cube_map
#define GL_OES_texture_cube_map 1
constexpr GLenum GL_NORMAL_MAP_OES = 0x8511;
constexpr GLenum GL_REFLECTION_MAP_OES = 0x8512;
constexpr GLenum GL_TEXTURE_CUBE_MAP_OES = 0x8513;
constexpr GLenum GL_TEXTURE_BINDING_CUBE_MAP_OES = 0x8514;
constexpr GLenum GL_TEXTURE_CUBE_MAP_POSITIVE_X_OES = 0x8515;
constexpr GLenum GL_TEXTURE_CUBE_MAP_NEGATIVE_X_OES = 0x8516;
constexpr GLenum GL_TEXTURE_CUBE_MAP_POSITIVE_Y_OES = 0x8517;
constexpr GLenum GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_OES = 0x8518;
constexpr GLenum GL_TEXTURE_CUBE_MAP_POSITIVE_Z_OES = 0x8519;
constexpr GLenum GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_OES = 0x851A;
constexpr GLenum GL_MAX_CUBE_MAP_TEXTURE_SIZE_OES = 0x851C;
constexpr GLenum GL_TEXTURE_GEN_MODE_OES = 0x2500;
constexpr GLenum GL_TEXTURE_GEN_STR_OES = 0x8D60;
void glTexGenfOES(GLenum coord, GLenum pname, GLfloat param);
void glTexGenfvOES(GLenum coord, GLenum pname, GLfloat const  * params);
void glTexGeniOES(GLenum coord, GLenum pname, GLint param);
void glTexGenivOES(GLenum coord, GLenum pname, GLint const  * params);
void glGetTexGenfvOES(GLenum coord, GLenum pname, GLfloat * params);
void glGetTexGenivOES(GLenum coord, GLenum pname, GLint * params);
#endif /* GL_OES_texture_cube_map */
#ifndef GL_OES_texture_cube_map_array
#define GL_OES_texture_cube_map_array 1
constexpr GLenum GL_TEXTURE_BINDING_CUBE_MAP_ARRAY_OES = 0x900A;
constexpr GLenum GL_SAMPLER_CUBE_MAP_ARRAY_OES = 0x900C;
constexpr GLenum GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW_OES = 0x900D;
constexpr GLenum GL_INT_SAMPLER_CUBE_MAP_ARRAY_OES = 0x900E;
constexpr GLenum GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY_OES = 0x900F;
constexpr GLenum GL_IMAGE_CUBE_MAP_ARRAY_OES = 0x9054;
constexpr GLenum GL_INT_IMAGE_CUBE_MAP_ARRAY_OES = 0x905F;
constexpr GLenum GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY_OES = 0x906A;
#endif /* GL_OES_texture_cube_map_array */
#ifndef GL_OES_texture_env_crossbar
#define GL_OES_texture_env_crossbar 1
#endif /* GL_OES_texture_env_crossbar */
#ifndef GL_OES_texture_float
#define GL_OES_texture_float 1
#endif /* GL_OES_texture_float */
#ifndef GL_OES_texture_float_linear
#define GL_OES_texture_float_linear 1
#endif /* GL_OES_texture_float_linear */
#ifndef GL_OES_texture_half_float
#define GL_OES_texture_half_float 1
constexpr GLenum GL_HALF_FLOAT_OES = 0x8D61;
#endif /* GL_OES_texture_half_float */
#ifndef GL_OES_texture_half_float_linear
#define GL_OES_texture_half_float_linear 1
#endif /* GL_OES_texture_half_float_linear */
#ifndef GL_OES_texture_mirrored_repeat
#define GL_OES_texture_mirrored_repeat 1
constexpr GLenum GL_MIRRORED_REPEAT_OES = 0x8370;
#endif /* GL_OES_texture_mirrored_repeat */
#ifndef GL_OES_texture_npot
#define GL_OES_texture_npot 1
#endif /* GL_OES_texture_npot */
#ifndef GL_OES_texture_stencil8
#define GL_OES_texture_stencil8 1
constexpr GLenum GL_STENCIL_INDEX_OES = 0x1901;
#endif /* GL_OES_texture_stencil8 */
#ifndef GL_OES_texture_storage_multisample_2d_array
#define GL_OES_texture_storage_multisample_2d_array 1
constexpr GLenum GL_TEXTURE_2D_MULTISAMPLE_ARRAY_OES = 0x9102;
constexpr GLenum GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY_OES = 0x9105;
constexpr GLenum GL_SAMPLER_2D_MULTISAMPLE_ARRAY_OES = 0x910B;
constexpr GLenum GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY_OES = 0x910C;
constexpr GLenum GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY_OES = 0x910D;
void glTexStorage3DMultisampleOES(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
#endif /* GL_OES_texture_storage_multisample_2d_array */
#ifndef GL_OES_texture_view
#define GL_OES_texture_view 1
constexpr GLenum GL_TEXTURE_VIEW_MIN_LEVEL_OES = 0x82DB;
constexpr GLenum GL_TEXTURE_VIEW_NUM_LEVELS_OES = 0x82DC;
constexpr GLenum GL_TEXTURE_VIEW_MIN_LAYER_OES = 0x82DD;
constexpr GLenum GL_TEXTURE_VIEW_NUM_LAYERS_OES = 0x82DE;
void glTextureViewOES(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
#endif /* GL_OES_texture_view */
#ifndef GL_OES_vertex_array_object
#define GL_OES_vertex_array_object 1
constexpr GLenum GL_VERTEX_ARRAY_BINDING_OES = 0x85B5;
void glBindVertexArrayOES(GLuint array);
void glDeleteVertexArraysOES(GLsizei n, GLuint const  * arrays);
void glGenVertexArraysOES(GLsizei n, GLuint * arrays);
GLboolean glIsVertexArrayOES(GLuint array);
#endif /* GL_OES_vertex_array_object */
#ifndef GL_OES_vertex_half_float
#define GL_OES_vertex_half_float 1
#endif /* GL_OES_vertex_half_float */
#ifndef GL_OES_vertex_type_10_10_10_2
#define GL_OES_vertex_type_10_10_10_2 1
constexpr GLenum GL_UNSIGNED_INT_10_10_10_2_OES = 0x8DF6;
constexpr GLenum GL_INT_10_10_10_2_OES = 0x8DF7;
#endif /* GL_OES_vertex_type_10_10_10_2 */
#ifndef GL_OES_viewport_array
#define GL_OES_viewport_array 1
constexpr GLenum GL_MAX_VIEWPORTS_OES = 0x825B;
constexpr GLenum GL_VIEWPORT_SUBPIXEL_BITS_OES = 0x825C;
constexpr GLenum GL_VIEWPORT_BOUNDS_RANGE_OES = 0x825D;
constexpr GLenum GL_VIEWPORT_INDEX_PROVOKING_VERTEX_OES = 0x825F;
void glViewportArrayvOES(GLuint first, GLsizei count, GLfloat const  * v);
void glViewportIndexedfOES(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
void glViewportIndexedfvOES(GLuint index, GLfloat const  * v);
void glScissorArrayvOES(GLuint first, GLsizei count, GLint const  * v);
void glScissorIndexedOES(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
void glScissorIndexedvOES(GLuint index, GLint const  * v);
void glDepthRangeArrayfvOES(GLuint first, GLsizei count, GLfloat const  * v);
void glDepthRangeIndexedfOES(GLuint index, GLfloat n, GLfloat f);
void glGetFloati_vOES(GLenum target, GLuint index, GLfloat * data);
#endif /* GL_OES_viewport_array */
#ifndef GL_EXT_texture_shadow_lod
#define GL_EXT_texture_shadow_lod 1
#endif /* GL_EXT_texture_shadow_lod */

}
