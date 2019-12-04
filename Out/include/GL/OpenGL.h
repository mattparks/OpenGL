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

#pragma once

#include <functional>

#ifdef __gl_h_
#error OpenGL header already included, remove this include
#endif
#define __gl_h_

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

namespace gl {
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
void initialize(const GetProcAddress &resolver);

#ifndef GL_VERSION_1_0
#define GL_VERSION_1_0 1
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
constexpr GLenum GL_QUADS = 0x0007;
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
constexpr GLenum GL_NONE = 0;
constexpr GLenum GL_FRONT_LEFT = 0x0400;
constexpr GLenum GL_FRONT_RIGHT = 0x0401;
constexpr GLenum GL_BACK_LEFT = 0x0402;
constexpr GLenum GL_BACK_RIGHT = 0x0403;
constexpr GLenum GL_FRONT = 0x0404;
constexpr GLenum GL_BACK = 0x0405;
constexpr GLenum GL_LEFT = 0x0406;
constexpr GLenum GL_RIGHT = 0x0407;
constexpr GLenum GL_FRONT_AND_BACK = 0x0408;
constexpr GLenum GL_NO_ERROR = 0;
constexpr GLenum GL_INVALID_ENUM = 0x0500;
constexpr GLenum GL_INVALID_VALUE = 0x0501;
constexpr GLenum GL_INVALID_OPERATION = 0x0502;
constexpr GLenum GL_OUT_OF_MEMORY = 0x0505;
constexpr GLenum GL_CW = 0x0900;
constexpr GLenum GL_CCW = 0x0901;
constexpr GLenum GL_POINT_SIZE = 0x0B11;
constexpr GLenum GL_POINT_SIZE_RANGE = 0x0B12;
constexpr GLenum GL_POINT_SIZE_GRANULARITY = 0x0B13;
constexpr GLenum GL_LINE_SMOOTH = 0x0B20;
constexpr GLenum GL_LINE_WIDTH = 0x0B21;
constexpr GLenum GL_LINE_WIDTH_RANGE = 0x0B22;
constexpr GLenum GL_LINE_WIDTH_GRANULARITY = 0x0B23;
constexpr GLenum GL_POLYGON_MODE = 0x0B40;
constexpr GLenum GL_POLYGON_SMOOTH = 0x0B41;
constexpr GLenum GL_CULL_FACE = 0x0B44;
constexpr GLenum GL_CULL_FACE_MODE = 0x0B45;
constexpr GLenum GL_FRONT_FACE = 0x0B46;
constexpr GLenum GL_DEPTH_RANGE = 0x0B70;
constexpr GLenum GL_DEPTH_TEST = 0x0B71;
constexpr GLenum GL_DEPTH_WRITEMASK = 0x0B72;
constexpr GLenum GL_DEPTH_CLEAR_VALUE = 0x0B73;
constexpr GLenum GL_DEPTH_FUNC = 0x0B74;
constexpr GLenum GL_STENCIL_TEST = 0x0B90;
constexpr GLenum GL_STENCIL_CLEAR_VALUE = 0x0B91;
constexpr GLenum GL_STENCIL_FUNC = 0x0B92;
constexpr GLenum GL_STENCIL_VALUE_MASK = 0x0B93;
constexpr GLenum GL_STENCIL_FAIL = 0x0B94;
constexpr GLenum GL_STENCIL_PASS_DEPTH_FAIL = 0x0B95;
constexpr GLenum GL_STENCIL_PASS_DEPTH_PASS = 0x0B96;
constexpr GLenum GL_STENCIL_REF = 0x0B97;
constexpr GLenum GL_STENCIL_WRITEMASK = 0x0B98;
constexpr GLenum GL_VIEWPORT = 0x0BA2;
constexpr GLenum GL_DITHER = 0x0BD0;
constexpr GLenum GL_BLEND_DST = 0x0BE0;
constexpr GLenum GL_BLEND_SRC = 0x0BE1;
constexpr GLenum GL_BLEND = 0x0BE2;
constexpr GLenum GL_LOGIC_OP_MODE = 0x0BF0;
constexpr GLenum GL_DRAW_BUFFER = 0x0C01;
constexpr GLenum GL_READ_BUFFER = 0x0C02;
constexpr GLenum GL_SCISSOR_BOX = 0x0C10;
constexpr GLenum GL_SCISSOR_TEST = 0x0C11;
constexpr GLenum GL_COLOR_CLEAR_VALUE = 0x0C22;
constexpr GLenum GL_COLOR_WRITEMASK = 0x0C23;
constexpr GLenum GL_DOUBLEBUFFER = 0x0C32;
constexpr GLenum GL_STEREO = 0x0C33;
constexpr GLenum GL_LINE_SMOOTH_HINT = 0x0C52;
constexpr GLenum GL_POLYGON_SMOOTH_HINT = 0x0C53;
constexpr GLenum GL_UNPACK_SWAP_BYTES = 0x0CF0;
constexpr GLenum GL_UNPACK_LSB_FIRST = 0x0CF1;
constexpr GLenum GL_UNPACK_ROW_LENGTH = 0x0CF2;
constexpr GLenum GL_UNPACK_SKIP_ROWS = 0x0CF3;
constexpr GLenum GL_UNPACK_SKIP_PIXELS = 0x0CF4;
constexpr GLenum GL_UNPACK_ALIGNMENT = 0x0CF5;
constexpr GLenum GL_PACK_SWAP_BYTES = 0x0D00;
constexpr GLenum GL_PACK_LSB_FIRST = 0x0D01;
constexpr GLenum GL_PACK_ROW_LENGTH = 0x0D02;
constexpr GLenum GL_PACK_SKIP_ROWS = 0x0D03;
constexpr GLenum GL_PACK_SKIP_PIXELS = 0x0D04;
constexpr GLenum GL_PACK_ALIGNMENT = 0x0D05;
constexpr GLenum GL_MAX_TEXTURE_SIZE = 0x0D33;
constexpr GLenum GL_MAX_VIEWPORT_DIMS = 0x0D3A;
constexpr GLenum GL_SUBPIXEL_BITS = 0x0D50;
constexpr GLenum GL_TEXTURE_1D = 0x0DE0;
constexpr GLenum GL_TEXTURE_2D = 0x0DE1;
constexpr GLenum GL_TEXTURE_WIDTH = 0x1000;
constexpr GLenum GL_TEXTURE_HEIGHT = 0x1001;
constexpr GLenum GL_TEXTURE_BORDER_COLOR = 0x1004;
constexpr GLenum GL_DONT_CARE = 0x1100;
constexpr GLenum GL_FASTEST = 0x1101;
constexpr GLenum GL_NICEST = 0x1102;
constexpr GLenum GL_BYTE = 0x1400;
constexpr GLenum GL_UNSIGNED_BYTE = 0x1401;
constexpr GLenum GL_SHORT = 0x1402;
constexpr GLenum GL_UNSIGNED_SHORT = 0x1403;
constexpr GLenum GL_INT = 0x1404;
constexpr GLenum GL_UNSIGNED_INT = 0x1405;
constexpr GLenum GL_FLOAT = 0x1406;
constexpr GLenum GL_STACK_OVERFLOW = 0x0503;
constexpr GLenum GL_STACK_UNDERFLOW = 0x0504;
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
constexpr GLenum GL_TEXTURE = 0x1702;
constexpr GLenum GL_COLOR = 0x1800;
constexpr GLenum GL_DEPTH = 0x1801;
constexpr GLenum GL_STENCIL = 0x1802;
constexpr GLenum GL_STENCIL_INDEX = 0x1901;
constexpr GLenum GL_DEPTH_COMPONENT = 0x1902;
constexpr GLenum GL_RED = 0x1903;
constexpr GLenum GL_GREEN = 0x1904;
constexpr GLenum GL_BLUE = 0x1905;
constexpr GLenum GL_ALPHA = 0x1906;
constexpr GLenum GL_RGB = 0x1907;
constexpr GLenum GL_RGBA = 0x1908;
constexpr GLenum GL_POINT = 0x1B00;
constexpr GLenum GL_LINE = 0x1B01;
constexpr GLenum GL_FILL = 0x1B02;
constexpr GLenum GL_KEEP = 0x1E00;
constexpr GLenum GL_REPLACE = 0x1E01;
constexpr GLenum GL_INCR = 0x1E02;
constexpr GLenum GL_DECR = 0x1E03;
constexpr GLenum GL_VENDOR = 0x1F00;
constexpr GLenum GL_RENDERER = 0x1F01;
constexpr GLenum GL_VERSION = 0x1F02;
constexpr GLenum GL_EXTENSIONS = 0x1F03;
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
constexpr GLenum GL_REPEAT = 0x2901;
constexpr GLenum GL_CURRENT_BIT = 0x00000001;
constexpr GLenum GL_POINT_BIT = 0x00000002;
constexpr GLenum GL_LINE_BIT = 0x00000004;
constexpr GLenum GL_POLYGON_BIT = 0x00000008;
constexpr GLenum GL_POLYGON_STIPPLE_BIT = 0x00000010;
constexpr GLenum GL_PIXEL_MODE_BIT = 0x00000020;
constexpr GLenum GL_LIGHTING_BIT = 0x00000040;
constexpr GLenum GL_FOG_BIT = 0x00000080;
constexpr GLenum GL_ACCUM_BUFFER_BIT = 0x00000200;
constexpr GLenum GL_VIEWPORT_BIT = 0x00000800;
constexpr GLenum GL_TRANSFORM_BIT = 0x00001000;
constexpr GLenum GL_ENABLE_BIT = 0x00002000;
constexpr GLenum GL_HINT_BIT = 0x00008000;
constexpr GLenum GL_EVAL_BIT = 0x00010000;
constexpr GLenum GL_LIST_BIT = 0x00020000;
constexpr GLenum GL_TEXTURE_BIT = 0x00040000;
constexpr GLenum GL_SCISSOR_BIT = 0x00080000;
constexpr GLenum GL_ALL_ATTRIB_BITS = 0xFFFFFFFF;
constexpr GLenum GL_QUAD_STRIP = 0x0008;
constexpr GLenum GL_POLYGON = 0x0009;
constexpr GLenum GL_ACCUM = 0x0100;
constexpr GLenum GL_LOAD = 0x0101;
constexpr GLenum GL_RETURN = 0x0102;
constexpr GLenum GL_MULT = 0x0103;
constexpr GLenum GL_ADD = 0x0104;
constexpr GLenum GL_AUX0 = 0x0409;
constexpr GLenum GL_AUX1 = 0x040A;
constexpr GLenum GL_AUX2 = 0x040B;
constexpr GLenum GL_AUX3 = 0x040C;
constexpr GLenum GL_2D = 0x0600;
constexpr GLenum GL_3D = 0x0601;
constexpr GLenum GL_3D_COLOR = 0x0602;
constexpr GLenum GL_3D_COLOR_TEXTURE = 0x0603;
constexpr GLenum GL_4D_COLOR_TEXTURE = 0x0604;
constexpr GLenum GL_PASS_THROUGH_TOKEN = 0x0700;
constexpr GLenum GL_POINT_TOKEN = 0x0701;
constexpr GLenum GL_LINE_TOKEN = 0x0702;
constexpr GLenum GL_POLYGON_TOKEN = 0x0703;
constexpr GLenum GL_BITMAP_TOKEN = 0x0704;
constexpr GLenum GL_DRAW_PIXEL_TOKEN = 0x0705;
constexpr GLenum GL_COPY_PIXEL_TOKEN = 0x0706;
constexpr GLenum GL_LINE_RESET_TOKEN = 0x0707;
constexpr GLenum GL_EXP = 0x0800;
constexpr GLenum GL_EXP2 = 0x0801;
constexpr GLenum GL_COEFF = 0x0A00;
constexpr GLenum GL_ORDER = 0x0A01;
constexpr GLenum GL_DOMAIN = 0x0A02;
constexpr GLenum GL_PIXEL_MAP_I_TO_I = 0x0C70;
constexpr GLenum GL_PIXEL_MAP_S_TO_S = 0x0C71;
constexpr GLenum GL_PIXEL_MAP_I_TO_R = 0x0C72;
constexpr GLenum GL_PIXEL_MAP_I_TO_G = 0x0C73;
constexpr GLenum GL_PIXEL_MAP_I_TO_B = 0x0C74;
constexpr GLenum GL_PIXEL_MAP_I_TO_A = 0x0C75;
constexpr GLenum GL_PIXEL_MAP_R_TO_R = 0x0C76;
constexpr GLenum GL_PIXEL_MAP_G_TO_G = 0x0C77;
constexpr GLenum GL_PIXEL_MAP_B_TO_B = 0x0C78;
constexpr GLenum GL_PIXEL_MAP_A_TO_A = 0x0C79;
constexpr GLenum GL_CURRENT_COLOR = 0x0B00;
constexpr GLenum GL_CURRENT_INDEX = 0x0B01;
constexpr GLenum GL_CURRENT_NORMAL = 0x0B02;
constexpr GLenum GL_CURRENT_TEXTURE_COORDS = 0x0B03;
constexpr GLenum GL_CURRENT_RASTER_COLOR = 0x0B04;
constexpr GLenum GL_CURRENT_RASTER_INDEX = 0x0B05;
constexpr GLenum GL_CURRENT_RASTER_TEXTURE_COORDS = 0x0B06;
constexpr GLenum GL_CURRENT_RASTER_POSITION = 0x0B07;
constexpr GLenum GL_CURRENT_RASTER_POSITION_VALID = 0x0B08;
constexpr GLenum GL_CURRENT_RASTER_DISTANCE = 0x0B09;
constexpr GLenum GL_POINT_SMOOTH = 0x0B10;
constexpr GLenum GL_LINE_STIPPLE = 0x0B24;
constexpr GLenum GL_LINE_STIPPLE_PATTERN = 0x0B25;
constexpr GLenum GL_LINE_STIPPLE_REPEAT = 0x0B26;
constexpr GLenum GL_LIST_MODE = 0x0B30;
constexpr GLenum GL_MAX_LIST_NESTING = 0x0B31;
constexpr GLenum GL_LIST_BASE = 0x0B32;
constexpr GLenum GL_LIST_INDEX = 0x0B33;
constexpr GLenum GL_POLYGON_STIPPLE = 0x0B42;
constexpr GLenum GL_EDGE_FLAG = 0x0B43;
constexpr GLenum GL_LIGHTING = 0x0B50;
constexpr GLenum GL_LIGHT_MODEL_LOCAL_VIEWER = 0x0B51;
constexpr GLenum GL_LIGHT_MODEL_TWO_SIDE = 0x0B52;
constexpr GLenum GL_LIGHT_MODEL_AMBIENT = 0x0B53;
constexpr GLenum GL_SHADE_MODEL = 0x0B54;
constexpr GLenum GL_COLOR_MATERIAL_FACE = 0x0B55;
constexpr GLenum GL_COLOR_MATERIAL_PARAMETER = 0x0B56;
constexpr GLenum GL_COLOR_MATERIAL = 0x0B57;
constexpr GLenum GL_FOG = 0x0B60;
constexpr GLenum GL_FOG_INDEX = 0x0B61;
constexpr GLenum GL_FOG_DENSITY = 0x0B62;
constexpr GLenum GL_FOG_START = 0x0B63;
constexpr GLenum GL_FOG_END = 0x0B64;
constexpr GLenum GL_FOG_MODE = 0x0B65;
constexpr GLenum GL_FOG_COLOR = 0x0B66;
constexpr GLenum GL_ACCUM_CLEAR_VALUE = 0x0B80;
constexpr GLenum GL_MATRIX_MODE = 0x0BA0;
constexpr GLenum GL_NORMALIZE = 0x0BA1;
constexpr GLenum GL_MODELVIEW_STACK_DEPTH = 0x0BA3;
constexpr GLenum GL_PROJECTION_STACK_DEPTH = 0x0BA4;
constexpr GLenum GL_TEXTURE_STACK_DEPTH = 0x0BA5;
constexpr GLenum GL_MODELVIEW_MATRIX = 0x0BA6;
constexpr GLenum GL_PROJECTION_MATRIX = 0x0BA7;
constexpr GLenum GL_TEXTURE_MATRIX = 0x0BA8;
constexpr GLenum GL_ATTRIB_STACK_DEPTH = 0x0BB0;
constexpr GLenum GL_ALPHA_TEST = 0x0BC0;
constexpr GLenum GL_ALPHA_TEST_FUNC = 0x0BC1;
constexpr GLenum GL_ALPHA_TEST_REF = 0x0BC2;
constexpr GLenum GL_LOGIC_OP = 0x0BF1;
constexpr GLenum GL_AUX_BUFFERS = 0x0C00;
constexpr GLenum GL_INDEX_CLEAR_VALUE = 0x0C20;
constexpr GLenum GL_INDEX_WRITEMASK = 0x0C21;
constexpr GLenum GL_INDEX_MODE = 0x0C30;
constexpr GLenum GL_RGBA_MODE = 0x0C31;
constexpr GLenum GL_RENDER_MODE = 0x0C40;
constexpr GLenum GL_PERSPECTIVE_CORRECTION_HINT = 0x0C50;
constexpr GLenum GL_POINT_SMOOTH_HINT = 0x0C51;
constexpr GLenum GL_FOG_HINT = 0x0C54;
constexpr GLenum GL_TEXTURE_GEN_S = 0x0C60;
constexpr GLenum GL_TEXTURE_GEN_T = 0x0C61;
constexpr GLenum GL_TEXTURE_GEN_R = 0x0C62;
constexpr GLenum GL_TEXTURE_GEN_Q = 0x0C63;
constexpr GLenum GL_PIXEL_MAP_I_TO_I_SIZE = 0x0CB0;
constexpr GLenum GL_PIXEL_MAP_S_TO_S_SIZE = 0x0CB1;
constexpr GLenum GL_PIXEL_MAP_I_TO_R_SIZE = 0x0CB2;
constexpr GLenum GL_PIXEL_MAP_I_TO_G_SIZE = 0x0CB3;
constexpr GLenum GL_PIXEL_MAP_I_TO_B_SIZE = 0x0CB4;
constexpr GLenum GL_PIXEL_MAP_I_TO_A_SIZE = 0x0CB5;
constexpr GLenum GL_PIXEL_MAP_R_TO_R_SIZE = 0x0CB6;
constexpr GLenum GL_PIXEL_MAP_G_TO_G_SIZE = 0x0CB7;
constexpr GLenum GL_PIXEL_MAP_B_TO_B_SIZE = 0x0CB8;
constexpr GLenum GL_PIXEL_MAP_A_TO_A_SIZE = 0x0CB9;
constexpr GLenum GL_MAP_COLOR = 0x0D10;
constexpr GLenum GL_MAP_STENCIL = 0x0D11;
constexpr GLenum GL_INDEX_SHIFT = 0x0D12;
constexpr GLenum GL_INDEX_OFFSET = 0x0D13;
constexpr GLenum GL_RED_SCALE = 0x0D14;
constexpr GLenum GL_RED_BIAS = 0x0D15;
constexpr GLenum GL_ZOOM_X = 0x0D16;
constexpr GLenum GL_ZOOM_Y = 0x0D17;
constexpr GLenum GL_GREEN_SCALE = 0x0D18;
constexpr GLenum GL_GREEN_BIAS = 0x0D19;
constexpr GLenum GL_BLUE_SCALE = 0x0D1A;
constexpr GLenum GL_BLUE_BIAS = 0x0D1B;
constexpr GLenum GL_ALPHA_SCALE = 0x0D1C;
constexpr GLenum GL_ALPHA_BIAS = 0x0D1D;
constexpr GLenum GL_DEPTH_SCALE = 0x0D1E;
constexpr GLenum GL_DEPTH_BIAS = 0x0D1F;
constexpr GLenum GL_MAX_EVAL_ORDER = 0x0D30;
constexpr GLenum GL_MAX_LIGHTS = 0x0D31;
constexpr GLenum GL_MAX_CLIP_PLANES = 0x0D32;
constexpr GLenum GL_MAX_PIXEL_MAP_TABLE = 0x0D34;
constexpr GLenum GL_MAX_ATTRIB_STACK_DEPTH = 0x0D35;
constexpr GLenum GL_MAX_MODELVIEW_STACK_DEPTH = 0x0D36;
constexpr GLenum GL_MAX_NAME_STACK_DEPTH = 0x0D37;
constexpr GLenum GL_MAX_PROJECTION_STACK_DEPTH = 0x0D38;
constexpr GLenum GL_MAX_TEXTURE_STACK_DEPTH = 0x0D39;
constexpr GLenum GL_INDEX_BITS = 0x0D51;
constexpr GLenum GL_RED_BITS = 0x0D52;
constexpr GLenum GL_GREEN_BITS = 0x0D53;
constexpr GLenum GL_BLUE_BITS = 0x0D54;
constexpr GLenum GL_ALPHA_BITS = 0x0D55;
constexpr GLenum GL_DEPTH_BITS = 0x0D56;
constexpr GLenum GL_STENCIL_BITS = 0x0D57;
constexpr GLenum GL_ACCUM_RED_BITS = 0x0D58;
constexpr GLenum GL_ACCUM_GREEN_BITS = 0x0D59;
constexpr GLenum GL_ACCUM_BLUE_BITS = 0x0D5A;
constexpr GLenum GL_ACCUM_ALPHA_BITS = 0x0D5B;
constexpr GLenum GL_NAME_STACK_DEPTH = 0x0D70;
constexpr GLenum GL_AUTO_NORMAL = 0x0D80;
constexpr GLenum GL_MAP1_COLOR_4 = 0x0D90;
constexpr GLenum GL_MAP1_INDEX = 0x0D91;
constexpr GLenum GL_MAP1_NORMAL = 0x0D92;
constexpr GLenum GL_MAP1_TEXTURE_COORD_1 = 0x0D93;
constexpr GLenum GL_MAP1_TEXTURE_COORD_2 = 0x0D94;
constexpr GLenum GL_MAP1_TEXTURE_COORD_3 = 0x0D95;
constexpr GLenum GL_MAP1_TEXTURE_COORD_4 = 0x0D96;
constexpr GLenum GL_MAP1_VERTEX_3 = 0x0D97;
constexpr GLenum GL_MAP1_VERTEX_4 = 0x0D98;
constexpr GLenum GL_MAP2_COLOR_4 = 0x0DB0;
constexpr GLenum GL_MAP2_INDEX = 0x0DB1;
constexpr GLenum GL_MAP2_NORMAL = 0x0DB2;
constexpr GLenum GL_MAP2_TEXTURE_COORD_1 = 0x0DB3;
constexpr GLenum GL_MAP2_TEXTURE_COORD_2 = 0x0DB4;
constexpr GLenum GL_MAP2_TEXTURE_COORD_3 = 0x0DB5;
constexpr GLenum GL_MAP2_TEXTURE_COORD_4 = 0x0DB6;
constexpr GLenum GL_MAP2_VERTEX_3 = 0x0DB7;
constexpr GLenum GL_MAP2_VERTEX_4 = 0x0DB8;
constexpr GLenum GL_MAP1_GRID_DOMAIN = 0x0DD0;
constexpr GLenum GL_MAP1_GRID_SEGMENTS = 0x0DD1;
constexpr GLenum GL_MAP2_GRID_DOMAIN = 0x0DD2;
constexpr GLenum GL_MAP2_GRID_SEGMENTS = 0x0DD3;
constexpr GLenum GL_TEXTURE_COMPONENTS = 0x1003;
constexpr GLenum GL_TEXTURE_BORDER = 0x1005;
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
constexpr GLenum GL_COMPILE = 0x1300;
constexpr GLenum GL_COMPILE_AND_EXECUTE = 0x1301;
constexpr GLenum GL_2_BYTES = 0x1407;
constexpr GLenum GL_3_BYTES = 0x1408;
constexpr GLenum GL_4_BYTES = 0x1409;
constexpr GLenum GL_EMISSION = 0x1600;
constexpr GLenum GL_SHININESS = 0x1601;
constexpr GLenum GL_AMBIENT_AND_DIFFUSE = 0x1602;
constexpr GLenum GL_COLOR_INDEXES = 0x1603;
constexpr GLenum GL_MODELVIEW = 0x1700;
constexpr GLenum GL_PROJECTION = 0x1701;
constexpr GLenum GL_COLOR_INDEX = 0x1900;
constexpr GLenum GL_LUMINANCE = 0x1909;
constexpr GLenum GL_LUMINANCE_ALPHA = 0x190A;
constexpr GLenum GL_BITMAP = 0x1A00;
constexpr GLenum GL_RENDER = 0x1C00;
constexpr GLenum GL_FEEDBACK = 0x1C01;
constexpr GLenum GL_SELECT = 0x1C02;
constexpr GLenum GL_FLAT = 0x1D00;
constexpr GLenum GL_SMOOTH = 0x1D01;
constexpr GLenum GL_S = 0x2000;
constexpr GLenum GL_T = 0x2001;
constexpr GLenum GL_R = 0x2002;
constexpr GLenum GL_Q = 0x2003;
constexpr GLenum GL_MODULATE = 0x2100;
constexpr GLenum GL_DECAL = 0x2101;
constexpr GLenum GL_TEXTURE_ENV_MODE = 0x2200;
constexpr GLenum GL_TEXTURE_ENV_COLOR = 0x2201;
constexpr GLenum GL_TEXTURE_ENV = 0x2300;
constexpr GLenum GL_EYE_LINEAR = 0x2400;
constexpr GLenum GL_OBJECT_LINEAR = 0x2401;
constexpr GLenum GL_SPHERE_MAP = 0x2402;
constexpr GLenum GL_TEXTURE_GEN_MODE = 0x2500;
constexpr GLenum GL_OBJECT_PLANE = 0x2501;
constexpr GLenum GL_EYE_PLANE = 0x2502;
constexpr GLenum GL_CLAMP = 0x2900;
constexpr GLenum GL_CLIP_PLANE0 = 0x3000;
constexpr GLenum GL_CLIP_PLANE1 = 0x3001;
constexpr GLenum GL_CLIP_PLANE2 = 0x3002;
constexpr GLenum GL_CLIP_PLANE3 = 0x3003;
constexpr GLenum GL_CLIP_PLANE4 = 0x3004;
constexpr GLenum GL_CLIP_PLANE5 = 0x3005;
constexpr GLenum GL_LIGHT0 = 0x4000;
constexpr GLenum GL_LIGHT1 = 0x4001;
constexpr GLenum GL_LIGHT2 = 0x4002;
constexpr GLenum GL_LIGHT3 = 0x4003;
constexpr GLenum GL_LIGHT4 = 0x4004;
constexpr GLenum GL_LIGHT5 = 0x4005;
constexpr GLenum GL_LIGHT6 = 0x4006;
constexpr GLenum GL_LIGHT7 = 0x4007;
void glCullFace(GLenum mode);
void glFrontFace(GLenum mode);
void glHint(GLenum target, GLenum mode);
void glLineWidth(GLfloat width);
void glPointSize(GLfloat size);
void glPolygonMode(GLenum face, GLenum mode);
void glScissor(GLint x, GLint y, GLsizei width, GLsizei height);
void glTexParameterf(GLenum target, GLenum pname, GLfloat param);
void glTexParameterfv(GLenum target, GLenum pname, GLfloat const  * params);
void glTexParameteri(GLenum target, GLenum pname, GLint param);
void glTexParameteriv(GLenum target, GLenum pname, GLint const  * params);
void glTexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void * pixels);
void glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void * pixels);
void glDrawBuffer(GLenum buf);
void glClear(GLbitfield mask);
void glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
void glClearStencil(GLint s);
void glClearDepth(GLdouble depth);
void glStencilMask(GLuint mask);
void glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
void glDepthMask(GLboolean flag);
void glDisable(GLenum cap);
void glEnable(GLenum cap);
void glFinish();
void glFlush();
void glBlendFunc(GLenum sfactor, GLenum dfactor);
void glLogicOp(GLenum opcode);
void glStencilFunc(GLenum func, GLint ref, GLuint mask);
void glStencilOp(GLenum fail, GLenum zfail, GLenum zpass);
void glDepthFunc(GLenum func);
void glPixelStoref(GLenum pname, GLfloat param);
void glPixelStorei(GLenum pname, GLint param);
void glReadBuffer(GLenum src);
void glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void * pixels);
void glGetBooleanv(GLenum pname, GLboolean * data);
void glGetDoublev(GLenum pname, GLdouble * data);
GLenum glGetError();
void glGetFloatv(GLenum pname, GLfloat * data);
void glGetIntegerv(GLenum pname, GLint * data);
GLubyte const  * glGetString(GLenum name);
void glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, void * pixels);
void glGetTexParameterfv(GLenum target, GLenum pname, GLfloat * params);
void glGetTexParameteriv(GLenum target, GLenum pname, GLint * params);
void glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat * params);
void glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint * params);
GLboolean glIsEnabled(GLenum cap);
void glDepthRange(GLdouble n, GLdouble f);
void glViewport(GLint x, GLint y, GLsizei width, GLsizei height);
void glNewList(GLuint list, GLenum mode);
void glEndList();
void glCallList(GLuint list);
void glCallLists(GLsizei n, GLenum type, const void * lists);
void glDeleteLists(GLuint list, GLsizei range);
GLuint glGenLists(GLsizei range);
void glListBase(GLuint base);
void glBegin(GLenum mode);
void glBitmap(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, GLubyte const  * bitmap);
void glColor3b(GLbyte red, GLbyte green, GLbyte blue);
void glColor3bv(GLbyte const  * v);
void glColor3d(GLdouble red, GLdouble green, GLdouble blue);
void glColor3dv(GLdouble const  * v);
void glColor3f(GLfloat red, GLfloat green, GLfloat blue);
void glColor3fv(GLfloat const  * v);
void glColor3i(GLint red, GLint green, GLint blue);
void glColor3iv(GLint const  * v);
void glColor3s(GLshort red, GLshort green, GLshort blue);
void glColor3sv(GLshort const  * v);
void glColor3ub(GLubyte red, GLubyte green, GLubyte blue);
void glColor3ubv(GLubyte const  * v);
void glColor3ui(GLuint red, GLuint green, GLuint blue);
void glColor3uiv(GLuint const  * v);
void glColor3us(GLushort red, GLushort green, GLushort blue);
void glColor3usv(GLushort const  * v);
void glColor4b(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha);
void glColor4bv(GLbyte const  * v);
void glColor4d(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha);
void glColor4dv(GLdouble const  * v);
void glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
void glColor4fv(GLfloat const  * v);
void glColor4i(GLint red, GLint green, GLint blue, GLint alpha);
void glColor4iv(GLint const  * v);
void glColor4s(GLshort red, GLshort green, GLshort blue, GLshort alpha);
void glColor4sv(GLshort const  * v);
void glColor4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
void glColor4ubv(GLubyte const  * v);
void glColor4ui(GLuint red, GLuint green, GLuint blue, GLuint alpha);
void glColor4uiv(GLuint const  * v);
void glColor4us(GLushort red, GLushort green, GLushort blue, GLushort alpha);
void glColor4usv(GLushort const  * v);
void glEdgeFlag(GLboolean flag);
void glEdgeFlagv(GLboolean const  * flag);
void glEnd();
void glIndexd(GLdouble c);
void glIndexdv(GLdouble const  * c);
void glIndexf(GLfloat c);
void glIndexfv(GLfloat const  * c);
void glIndexi(GLint c);
void glIndexiv(GLint const  * c);
void glIndexs(GLshort c);
void glIndexsv(GLshort const  * c);
void glNormal3b(GLbyte nx, GLbyte ny, GLbyte nz);
void glNormal3bv(GLbyte const  * v);
void glNormal3d(GLdouble nx, GLdouble ny, GLdouble nz);
void glNormal3dv(GLdouble const  * v);
void glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz);
void glNormal3fv(GLfloat const  * v);
void glNormal3i(GLint nx, GLint ny, GLint nz);
void glNormal3iv(GLint const  * v);
void glNormal3s(GLshort nx, GLshort ny, GLshort nz);
void glNormal3sv(GLshort const  * v);
void glRasterPos2d(GLdouble x, GLdouble y);
void glRasterPos2dv(GLdouble const  * v);
void glRasterPos2f(GLfloat x, GLfloat y);
void glRasterPos2fv(GLfloat const  * v);
void glRasterPos2i(GLint x, GLint y);
void glRasterPos2iv(GLint const  * v);
void glRasterPos2s(GLshort x, GLshort y);
void glRasterPos2sv(GLshort const  * v);
void glRasterPos3d(GLdouble x, GLdouble y, GLdouble z);
void glRasterPos3dv(GLdouble const  * v);
void glRasterPos3f(GLfloat x, GLfloat y, GLfloat z);
void glRasterPos3fv(GLfloat const  * v);
void glRasterPos3i(GLint x, GLint y, GLint z);
void glRasterPos3iv(GLint const  * v);
void glRasterPos3s(GLshort x, GLshort y, GLshort z);
void glRasterPos3sv(GLshort const  * v);
void glRasterPos4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void glRasterPos4dv(GLdouble const  * v);
void glRasterPos4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void glRasterPos4fv(GLfloat const  * v);
void glRasterPos4i(GLint x, GLint y, GLint z, GLint w);
void glRasterPos4iv(GLint const  * v);
void glRasterPos4s(GLshort x, GLshort y, GLshort z, GLshort w);
void glRasterPos4sv(GLshort const  * v);
void glRectd(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2);
void glRectdv(GLdouble const  * v1, GLdouble const  * v2);
void glRectf(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
void glRectfv(GLfloat const  * v1, GLfloat const  * v2);
void glRecti(GLint x1, GLint y1, GLint x2, GLint y2);
void glRectiv(GLint const  * v1, GLint const  * v2);
void glRects(GLshort x1, GLshort y1, GLshort x2, GLshort y2);
void glRectsv(GLshort const  * v1, GLshort const  * v2);
void glTexCoord1d(GLdouble s);
void glTexCoord1dv(GLdouble const  * v);
void glTexCoord1f(GLfloat s);
void glTexCoord1fv(GLfloat const  * v);
void glTexCoord1i(GLint s);
void glTexCoord1iv(GLint const  * v);
void glTexCoord1s(GLshort s);
void glTexCoord1sv(GLshort const  * v);
void glTexCoord2d(GLdouble s, GLdouble t);
void glTexCoord2dv(GLdouble const  * v);
void glTexCoord2f(GLfloat s, GLfloat t);
void glTexCoord2fv(GLfloat const  * v);
void glTexCoord2i(GLint s, GLint t);
void glTexCoord2iv(GLint const  * v);
void glTexCoord2s(GLshort s, GLshort t);
void glTexCoord2sv(GLshort const  * v);
void glTexCoord3d(GLdouble s, GLdouble t, GLdouble r);
void glTexCoord3dv(GLdouble const  * v);
void glTexCoord3f(GLfloat s, GLfloat t, GLfloat r);
void glTexCoord3fv(GLfloat const  * v);
void glTexCoord3i(GLint s, GLint t, GLint r);
void glTexCoord3iv(GLint const  * v);
void glTexCoord3s(GLshort s, GLshort t, GLshort r);
void glTexCoord3sv(GLshort const  * v);
void glTexCoord4d(GLdouble s, GLdouble t, GLdouble r, GLdouble q);
void glTexCoord4dv(GLdouble const  * v);
void glTexCoord4f(GLfloat s, GLfloat t, GLfloat r, GLfloat q);
void glTexCoord4fv(GLfloat const  * v);
void glTexCoord4i(GLint s, GLint t, GLint r, GLint q);
void glTexCoord4iv(GLint const  * v);
void glTexCoord4s(GLshort s, GLshort t, GLshort r, GLshort q);
void glTexCoord4sv(GLshort const  * v);
void glVertex2d(GLdouble x, GLdouble y);
void glVertex2dv(GLdouble const  * v);
void glVertex2f(GLfloat x, GLfloat y);
void glVertex2fv(GLfloat const  * v);
void glVertex2i(GLint x, GLint y);
void glVertex2iv(GLint const  * v);
void glVertex2s(GLshort x, GLshort y);
void glVertex2sv(GLshort const  * v);
void glVertex3d(GLdouble x, GLdouble y, GLdouble z);
void glVertex3dv(GLdouble const  * v);
void glVertex3f(GLfloat x, GLfloat y, GLfloat z);
void glVertex3fv(GLfloat const  * v);
void glVertex3i(GLint x, GLint y, GLint z);
void glVertex3iv(GLint const  * v);
void glVertex3s(GLshort x, GLshort y, GLshort z);
void glVertex3sv(GLshort const  * v);
void glVertex4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void glVertex4dv(GLdouble const  * v);
void glVertex4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void glVertex4fv(GLfloat const  * v);
void glVertex4i(GLint x, GLint y, GLint z, GLint w);
void glVertex4iv(GLint const  * v);
void glVertex4s(GLshort x, GLshort y, GLshort z, GLshort w);
void glVertex4sv(GLshort const  * v);
void glClipPlane(GLenum plane, GLdouble const  * equation);
void glColorMaterial(GLenum face, GLenum mode);
void glFogf(GLenum pname, GLfloat param);
void glFogfv(GLenum pname, GLfloat const  * params);
void glFogi(GLenum pname, GLint param);
void glFogiv(GLenum pname, GLint const  * params);
void glLightf(GLenum light, GLenum pname, GLfloat param);
void glLightfv(GLenum light, GLenum pname, GLfloat const  * params);
void glLighti(GLenum light, GLenum pname, GLint param);
void glLightiv(GLenum light, GLenum pname, GLint const  * params);
void glLightModelf(GLenum pname, GLfloat param);
void glLightModelfv(GLenum pname, GLfloat const  * params);
void glLightModeli(GLenum pname, GLint param);
void glLightModeliv(GLenum pname, GLint const  * params);
void glLineStipple(GLint factor, GLushort pattern);
void glMaterialf(GLenum face, GLenum pname, GLfloat param);
void glMaterialfv(GLenum face, GLenum pname, GLfloat const  * params);
void glMateriali(GLenum face, GLenum pname, GLint param);
void glMaterialiv(GLenum face, GLenum pname, GLint const  * params);
void glPolygonStipple(GLubyte const  * mask);
void glShadeModel(GLenum mode);
void glTexEnvf(GLenum target, GLenum pname, GLfloat param);
void glTexEnvfv(GLenum target, GLenum pname, GLfloat const  * params);
void glTexEnvi(GLenum target, GLenum pname, GLint param);
void glTexEnviv(GLenum target, GLenum pname, GLint const  * params);
void glTexGend(GLenum coord, GLenum pname, GLdouble param);
void glTexGendv(GLenum coord, GLenum pname, GLdouble const  * params);
void glTexGenf(GLenum coord, GLenum pname, GLfloat param);
void glTexGenfv(GLenum coord, GLenum pname, GLfloat const  * params);
void glTexGeni(GLenum coord, GLenum pname, GLint param);
void glTexGeniv(GLenum coord, GLenum pname, GLint const  * params);
void glFeedbackBuffer(GLsizei size, GLenum type, GLfloat * buffer);
void glSelectBuffer(GLsizei size, GLuint * buffer);
GLint glRenderMode(GLenum mode);
void glInitNames();
void glLoadName(GLuint name);
void glPassThrough(GLfloat token);
void glPopName();
void glPushName(GLuint name);
void glClearAccum(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
void glClearIndex(GLfloat c);
void glIndexMask(GLuint mask);
void glAccum(GLenum op, GLfloat value);
void glPopAttrib();
void glPushAttrib(GLbitfield mask);
void glMap1d(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, GLdouble const  * points);
void glMap1f(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, GLfloat const  * points);
void glMap2d(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, GLdouble const  * points);
void glMap2f(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, GLfloat const  * points);
void glMapGrid1d(GLint un, GLdouble u1, GLdouble u2);
void glMapGrid1f(GLint un, GLfloat u1, GLfloat u2);
void glMapGrid2d(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2);
void glMapGrid2f(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2);
void glEvalCoord1d(GLdouble u);
void glEvalCoord1dv(GLdouble const  * u);
void glEvalCoord1f(GLfloat u);
void glEvalCoord1fv(GLfloat const  * u);
void glEvalCoord2d(GLdouble u, GLdouble v);
void glEvalCoord2dv(GLdouble const  * u);
void glEvalCoord2f(GLfloat u, GLfloat v);
void glEvalCoord2fv(GLfloat const  * u);
void glEvalMesh1(GLenum mode, GLint i1, GLint i2);
void glEvalPoint1(GLint i);
void glEvalMesh2(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2);
void glEvalPoint2(GLint i, GLint j);
void glAlphaFunc(GLenum func, GLfloat ref);
void glPixelZoom(GLfloat xfactor, GLfloat yfactor);
void glPixelTransferf(GLenum pname, GLfloat param);
void glPixelTransferi(GLenum pname, GLint param);
void glPixelMapfv(GLenum map, GLsizei mapsize, GLfloat const  * values);
void glPixelMapuiv(GLenum map, GLsizei mapsize, GLuint const  * values);
void glPixelMapusv(GLenum map, GLsizei mapsize, GLushort const  * values);
void glCopyPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type);
void glDrawPixels(GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels);
void glGetClipPlane(GLenum plane, GLdouble * equation);
void glGetLightfv(GLenum light, GLenum pname, GLfloat * params);
void glGetLightiv(GLenum light, GLenum pname, GLint * params);
void glGetMapdv(GLenum target, GLenum query, GLdouble * v);
void glGetMapfv(GLenum target, GLenum query, GLfloat * v);
void glGetMapiv(GLenum target, GLenum query, GLint * v);
void glGetMaterialfv(GLenum face, GLenum pname, GLfloat * params);
void glGetMaterialiv(GLenum face, GLenum pname, GLint * params);
void glGetPixelMapfv(GLenum map, GLfloat * values);
void glGetPixelMapuiv(GLenum map, GLuint * values);
void glGetPixelMapusv(GLenum map, GLushort * values);
void glGetPolygonStipple(GLubyte * mask);
void glGetTexEnvfv(GLenum target, GLenum pname, GLfloat * params);
void glGetTexEnviv(GLenum target, GLenum pname, GLint * params);
void glGetTexGendv(GLenum coord, GLenum pname, GLdouble * params);
void glGetTexGenfv(GLenum coord, GLenum pname, GLfloat * params);
void glGetTexGeniv(GLenum coord, GLenum pname, GLint * params);
GLboolean glIsList(GLuint list);
void glFrustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
void glLoadIdentity();
void glLoadMatrixf(GLfloat const  * m);
void glLoadMatrixd(GLdouble const  * m);
void glMatrixMode(GLenum mode);
void glMultMatrixf(GLfloat const  * m);
void glMultMatrixd(GLdouble const  * m);
void glOrtho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
void glPopMatrix();
void glPushMatrix();
void glRotated(GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
void glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
void glScaled(GLdouble x, GLdouble y, GLdouble z);
void glScalef(GLfloat x, GLfloat y, GLfloat z);
void glTranslated(GLdouble x, GLdouble y, GLdouble z);
void glTranslatef(GLfloat x, GLfloat y, GLfloat z);
#endif /* GL_VERSION_1_0 */
#ifndef GL_VERSION_1_1
#define GL_VERSION_1_1 1
constexpr GLenum GL_COLOR_LOGIC_OP = 0x0BF2;
constexpr GLenum GL_POLYGON_OFFSET_UNITS = 0x2A00;
constexpr GLenum GL_POLYGON_OFFSET_POINT = 0x2A01;
constexpr GLenum GL_POLYGON_OFFSET_LINE = 0x2A02;
constexpr GLenum GL_POLYGON_OFFSET_FILL = 0x8037;
constexpr GLenum GL_POLYGON_OFFSET_FACTOR = 0x8038;
constexpr GLenum GL_TEXTURE_BINDING_1D = 0x8068;
constexpr GLenum GL_TEXTURE_BINDING_2D = 0x8069;
constexpr GLenum GL_TEXTURE_INTERNAL_FORMAT = 0x1003;
constexpr GLenum GL_TEXTURE_RED_SIZE = 0x805C;
constexpr GLenum GL_TEXTURE_GREEN_SIZE = 0x805D;
constexpr GLenum GL_TEXTURE_BLUE_SIZE = 0x805E;
constexpr GLenum GL_TEXTURE_ALPHA_SIZE = 0x805F;
constexpr GLenum GL_DOUBLE = 0x140A;
constexpr GLenum GL_PROXY_TEXTURE_1D = 0x8063;
constexpr GLenum GL_PROXY_TEXTURE_2D = 0x8064;
constexpr GLenum GL_R3_G3_B2 = 0x2A10;
constexpr GLenum GL_RGB4 = 0x804F;
constexpr GLenum GL_RGB5 = 0x8050;
constexpr GLenum GL_RGB8 = 0x8051;
constexpr GLenum GL_RGB10 = 0x8052;
constexpr GLenum GL_RGB12 = 0x8053;
constexpr GLenum GL_RGB16 = 0x8054;
constexpr GLenum GL_RGBA2 = 0x8055;
constexpr GLenum GL_RGBA4 = 0x8056;
constexpr GLenum GL_RGB5_A1 = 0x8057;
constexpr GLenum GL_RGBA8 = 0x8058;
constexpr GLenum GL_RGB10_A2 = 0x8059;
constexpr GLenum GL_RGBA12 = 0x805A;
constexpr GLenum GL_RGBA16 = 0x805B;
constexpr GLenum GL_CLIENT_PIXEL_STORE_BIT = 0x00000001;
constexpr GLenum GL_CLIENT_VERTEX_ARRAY_BIT = 0x00000002;
constexpr GLenum GL_CLIENT_ALL_ATTRIB_BITS = 0xFFFFFFFF;
constexpr GLenum GL_VERTEX_ARRAY_POINTER = 0x808E;
constexpr GLenum GL_NORMAL_ARRAY_POINTER = 0x808F;
constexpr GLenum GL_COLOR_ARRAY_POINTER = 0x8090;
constexpr GLenum GL_INDEX_ARRAY_POINTER = 0x8091;
constexpr GLenum GL_TEXTURE_COORD_ARRAY_POINTER = 0x8092;
constexpr GLenum GL_EDGE_FLAG_ARRAY_POINTER = 0x8093;
constexpr GLenum GL_FEEDBACK_BUFFER_POINTER = 0x0DF0;
constexpr GLenum GL_SELECTION_BUFFER_POINTER = 0x0DF3;
constexpr GLenum GL_CLIENT_ATTRIB_STACK_DEPTH = 0x0BB1;
constexpr GLenum GL_INDEX_LOGIC_OP = 0x0BF1;
constexpr GLenum GL_MAX_CLIENT_ATTRIB_STACK_DEPTH = 0x0D3B;
constexpr GLenum GL_FEEDBACK_BUFFER_SIZE = 0x0DF1;
constexpr GLenum GL_FEEDBACK_BUFFER_TYPE = 0x0DF2;
constexpr GLenum GL_SELECTION_BUFFER_SIZE = 0x0DF4;
constexpr GLenum GL_VERTEX_ARRAY = 0x8074;
constexpr GLenum GL_NORMAL_ARRAY = 0x8075;
constexpr GLenum GL_COLOR_ARRAY = 0x8076;
constexpr GLenum GL_INDEX_ARRAY = 0x8077;
constexpr GLenum GL_TEXTURE_COORD_ARRAY = 0x8078;
constexpr GLenum GL_EDGE_FLAG_ARRAY = 0x8079;
constexpr GLenum GL_VERTEX_ARRAY_SIZE = 0x807A;
constexpr GLenum GL_VERTEX_ARRAY_TYPE = 0x807B;
constexpr GLenum GL_VERTEX_ARRAY_STRIDE = 0x807C;
constexpr GLenum GL_NORMAL_ARRAY_TYPE = 0x807E;
constexpr GLenum GL_NORMAL_ARRAY_STRIDE = 0x807F;
constexpr GLenum GL_COLOR_ARRAY_SIZE = 0x8081;
constexpr GLenum GL_COLOR_ARRAY_TYPE = 0x8082;
constexpr GLenum GL_COLOR_ARRAY_STRIDE = 0x8083;
constexpr GLenum GL_INDEX_ARRAY_TYPE = 0x8085;
constexpr GLenum GL_INDEX_ARRAY_STRIDE = 0x8086;
constexpr GLenum GL_TEXTURE_COORD_ARRAY_SIZE = 0x8088;
constexpr GLenum GL_TEXTURE_COORD_ARRAY_TYPE = 0x8089;
constexpr GLenum GL_TEXTURE_COORD_ARRAY_STRIDE = 0x808A;
constexpr GLenum GL_EDGE_FLAG_ARRAY_STRIDE = 0x808C;
constexpr GLenum GL_TEXTURE_LUMINANCE_SIZE = 0x8060;
constexpr GLenum GL_TEXTURE_INTENSITY_SIZE = 0x8061;
constexpr GLenum GL_TEXTURE_PRIORITY = 0x8066;
constexpr GLenum GL_TEXTURE_RESIDENT = 0x8067;
constexpr GLenum GL_ALPHA4 = 0x803B;
constexpr GLenum GL_ALPHA8 = 0x803C;
constexpr GLenum GL_ALPHA12 = 0x803D;
constexpr GLenum GL_ALPHA16 = 0x803E;
constexpr GLenum GL_LUMINANCE4 = 0x803F;
constexpr GLenum GL_LUMINANCE8 = 0x8040;
constexpr GLenum GL_LUMINANCE12 = 0x8041;
constexpr GLenum GL_LUMINANCE16 = 0x8042;
constexpr GLenum GL_LUMINANCE4_ALPHA4 = 0x8043;
constexpr GLenum GL_LUMINANCE6_ALPHA2 = 0x8044;
constexpr GLenum GL_LUMINANCE8_ALPHA8 = 0x8045;
constexpr GLenum GL_LUMINANCE12_ALPHA4 = 0x8046;
constexpr GLenum GL_LUMINANCE12_ALPHA12 = 0x8047;
constexpr GLenum GL_LUMINANCE16_ALPHA16 = 0x8048;
constexpr GLenum GL_INTENSITY = 0x8049;
constexpr GLenum GL_INTENSITY4 = 0x804A;
constexpr GLenum GL_INTENSITY8 = 0x804B;
constexpr GLenum GL_INTENSITY12 = 0x804C;
constexpr GLenum GL_INTENSITY16 = 0x804D;
constexpr GLenum GL_V2F = 0x2A20;
constexpr GLenum GL_V3F = 0x2A21;
constexpr GLenum GL_C4UB_V2F = 0x2A22;
constexpr GLenum GL_C4UB_V3F = 0x2A23;
constexpr GLenum GL_C3F_V3F = 0x2A24;
constexpr GLenum GL_N3F_V3F = 0x2A25;
constexpr GLenum GL_C4F_N3F_V3F = 0x2A26;
constexpr GLenum GL_T2F_V3F = 0x2A27;
constexpr GLenum GL_T4F_V4F = 0x2A28;
constexpr GLenum GL_T2F_C4UB_V3F = 0x2A29;
constexpr GLenum GL_T2F_C3F_V3F = 0x2A2A;
constexpr GLenum GL_T2F_N3F_V3F = 0x2A2B;
constexpr GLenum GL_T2F_C4F_N3F_V3F = 0x2A2C;
constexpr GLenum GL_T4F_C4F_N3F_V4F = 0x2A2D;
void glDrawArrays(GLenum mode, GLint first, GLsizei count);
void glDrawElements(GLenum mode, GLsizei count, GLenum type, const void * indices);
void glGetPointerv(GLenum pname, void ** params);
void glPolygonOffset(GLfloat factor, GLfloat units);
void glCopyTexImage1D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
void glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
void glCopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
void glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
void glTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void * pixels);
void glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels);
void glBindTexture(GLenum target, GLuint texture);
void glDeleteTextures(GLsizei n, GLuint const  * textures);
void glGenTextures(GLsizei n, GLuint * textures);
GLboolean glIsTexture(GLuint texture);
void glArrayElement(GLint i);
void glColorPointer(GLint size, GLenum type, GLsizei stride, const void * pointer);
void glDisableClientState(GLenum array);
void glEdgeFlagPointer(GLsizei stride, const void * pointer);
void glEnableClientState(GLenum array);
void glIndexPointer(GLenum type, GLsizei stride, const void * pointer);
void glInterleavedArrays(GLenum format, GLsizei stride, const void * pointer);
void glNormalPointer(GLenum type, GLsizei stride, const void * pointer);
void glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const void * pointer);
void glVertexPointer(GLint size, GLenum type, GLsizei stride, const void * pointer);
GLboolean glAreTexturesResident(GLsizei n, GLuint const  * textures, GLboolean * residences);
void glPrioritizeTextures(GLsizei n, GLuint const  * textures, GLfloat const  * priorities);
void glIndexub(GLubyte c);
void glIndexubv(GLubyte const  * c);
void glPopClientAttrib();
void glPushClientAttrib(GLbitfield mask);
#endif /* GL_VERSION_1_1 */
#ifndef GL_VERSION_1_2
#define GL_VERSION_1_2 1
constexpr GLenum GL_UNSIGNED_BYTE_3_3_2 = 0x8032;
constexpr GLenum GL_UNSIGNED_SHORT_4_4_4_4 = 0x8033;
constexpr GLenum GL_UNSIGNED_SHORT_5_5_5_1 = 0x8034;
constexpr GLenum GL_UNSIGNED_INT_8_8_8_8 = 0x8035;
constexpr GLenum GL_UNSIGNED_INT_10_10_10_2 = 0x8036;
constexpr GLenum GL_TEXTURE_BINDING_3D = 0x806A;
constexpr GLenum GL_PACK_SKIP_IMAGES = 0x806B;
constexpr GLenum GL_PACK_IMAGE_HEIGHT = 0x806C;
constexpr GLenum GL_UNPACK_SKIP_IMAGES = 0x806D;
constexpr GLenum GL_UNPACK_IMAGE_HEIGHT = 0x806E;
constexpr GLenum GL_TEXTURE_3D = 0x806F;
constexpr GLenum GL_PROXY_TEXTURE_3D = 0x8070;
constexpr GLenum GL_TEXTURE_DEPTH = 0x8071;
constexpr GLenum GL_TEXTURE_WRAP_R = 0x8072;
constexpr GLenum GL_MAX_3D_TEXTURE_SIZE = 0x8073;
constexpr GLenum GL_UNSIGNED_BYTE_2_3_3_REV = 0x8362;
constexpr GLenum GL_UNSIGNED_SHORT_5_6_5 = 0x8363;
constexpr GLenum GL_UNSIGNED_SHORT_5_6_5_REV = 0x8364;
constexpr GLenum GL_UNSIGNED_SHORT_4_4_4_4_REV = 0x8365;
constexpr GLenum GL_UNSIGNED_SHORT_1_5_5_5_REV = 0x8366;
constexpr GLenum GL_UNSIGNED_INT_8_8_8_8_REV = 0x8367;
constexpr GLenum GL_UNSIGNED_INT_2_10_10_10_REV = 0x8368;
constexpr GLenum GL_BGR = 0x80E0;
constexpr GLenum GL_BGRA = 0x80E1;
constexpr GLenum GL_MAX_ELEMENTS_VERTICES = 0x80E8;
constexpr GLenum GL_MAX_ELEMENTS_INDICES = 0x80E9;
constexpr GLenum GL_CLAMP_TO_EDGE = 0x812F;
constexpr GLenum GL_TEXTURE_MIN_LOD = 0x813A;
constexpr GLenum GL_TEXTURE_MAX_LOD = 0x813B;
constexpr GLenum GL_TEXTURE_BASE_LEVEL = 0x813C;
constexpr GLenum GL_TEXTURE_MAX_LEVEL = 0x813D;
constexpr GLenum GL_SMOOTH_POINT_SIZE_RANGE = 0x0B12;
constexpr GLenum GL_SMOOTH_POINT_SIZE_GRANULARITY = 0x0B13;
constexpr GLenum GL_SMOOTH_LINE_WIDTH_RANGE = 0x0B22;
constexpr GLenum GL_SMOOTH_LINE_WIDTH_GRANULARITY = 0x0B23;
constexpr GLenum GL_ALIASED_LINE_WIDTH_RANGE = 0x846E;
constexpr GLenum GL_RESCALE_NORMAL = 0x803A;
constexpr GLenum GL_LIGHT_MODEL_COLOR_CONTROL = 0x81F8;
constexpr GLenum GL_SINGLE_COLOR = 0x81F9;
constexpr GLenum GL_SEPARATE_SPECULAR_COLOR = 0x81FA;
constexpr GLenum GL_ALIASED_POINT_SIZE_RANGE = 0x846D;
void glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices);
void glTexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void * pixels);
void glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels);
void glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#endif /* GL_VERSION_1_2 */
#ifndef GL_VERSION_1_3
#define GL_VERSION_1_3 1
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
constexpr GLenum GL_MULTISAMPLE = 0x809D;
constexpr GLenum GL_SAMPLE_ALPHA_TO_COVERAGE = 0x809E;
constexpr GLenum GL_SAMPLE_ALPHA_TO_ONE = 0x809F;
constexpr GLenum GL_SAMPLE_COVERAGE = 0x80A0;
constexpr GLenum GL_SAMPLE_BUFFERS = 0x80A8;
constexpr GLenum GL_SAMPLES = 0x80A9;
constexpr GLenum GL_SAMPLE_COVERAGE_VALUE = 0x80AA;
constexpr GLenum GL_SAMPLE_COVERAGE_INVERT = 0x80AB;
constexpr GLenum GL_TEXTURE_CUBE_MAP = 0x8513;
constexpr GLenum GL_TEXTURE_BINDING_CUBE_MAP = 0x8514;
constexpr GLenum GL_TEXTURE_CUBE_MAP_POSITIVE_X = 0x8515;
constexpr GLenum GL_TEXTURE_CUBE_MAP_NEGATIVE_X = 0x8516;
constexpr GLenum GL_TEXTURE_CUBE_MAP_POSITIVE_Y = 0x8517;
constexpr GLenum GL_TEXTURE_CUBE_MAP_NEGATIVE_Y = 0x8518;
constexpr GLenum GL_TEXTURE_CUBE_MAP_POSITIVE_Z = 0x8519;
constexpr GLenum GL_TEXTURE_CUBE_MAP_NEGATIVE_Z = 0x851A;
constexpr GLenum GL_PROXY_TEXTURE_CUBE_MAP = 0x851B;
constexpr GLenum GL_MAX_CUBE_MAP_TEXTURE_SIZE = 0x851C;
constexpr GLenum GL_COMPRESSED_RGB = 0x84ED;
constexpr GLenum GL_COMPRESSED_RGBA = 0x84EE;
constexpr GLenum GL_TEXTURE_COMPRESSION_HINT = 0x84EF;
constexpr GLenum GL_TEXTURE_COMPRESSED_IMAGE_SIZE = 0x86A0;
constexpr GLenum GL_TEXTURE_COMPRESSED = 0x86A1;
constexpr GLenum GL_NUM_COMPRESSED_TEXTURE_FORMATS = 0x86A2;
constexpr GLenum GL_COMPRESSED_TEXTURE_FORMATS = 0x86A3;
constexpr GLenum GL_CLAMP_TO_BORDER = 0x812D;
constexpr GLenum GL_CLIENT_ACTIVE_TEXTURE = 0x84E1;
constexpr GLenum GL_MAX_TEXTURE_UNITS = 0x84E2;
constexpr GLenum GL_TRANSPOSE_MODELVIEW_MATRIX = 0x84E3;
constexpr GLenum GL_TRANSPOSE_PROJECTION_MATRIX = 0x84E4;
constexpr GLenum GL_TRANSPOSE_TEXTURE_MATRIX = 0x84E5;
constexpr GLenum GL_TRANSPOSE_COLOR_MATRIX = 0x84E6;
constexpr GLenum GL_MULTISAMPLE_BIT = 0x20000000;
constexpr GLenum GL_NORMAL_MAP = 0x8511;
constexpr GLenum GL_REFLECTION_MAP = 0x8512;
constexpr GLenum GL_COMPRESSED_ALPHA = 0x84E9;
constexpr GLenum GL_COMPRESSED_LUMINANCE = 0x84EA;
constexpr GLenum GL_COMPRESSED_LUMINANCE_ALPHA = 0x84EB;
constexpr GLenum GL_COMPRESSED_INTENSITY = 0x84EC;
constexpr GLenum GL_COMBINE = 0x8570;
constexpr GLenum GL_COMBINE_RGB = 0x8571;
constexpr GLenum GL_COMBINE_ALPHA = 0x8572;
constexpr GLenum GL_SOURCE0_RGB = 0x8580;
constexpr GLenum GL_SOURCE1_RGB = 0x8581;
constexpr GLenum GL_SOURCE2_RGB = 0x8582;
constexpr GLenum GL_SOURCE0_ALPHA = 0x8588;
constexpr GLenum GL_SOURCE1_ALPHA = 0x8589;
constexpr GLenum GL_SOURCE2_ALPHA = 0x858A;
constexpr GLenum GL_OPERAND0_RGB = 0x8590;
constexpr GLenum GL_OPERAND1_RGB = 0x8591;
constexpr GLenum GL_OPERAND2_RGB = 0x8592;
constexpr GLenum GL_OPERAND0_ALPHA = 0x8598;
constexpr GLenum GL_OPERAND1_ALPHA = 0x8599;
constexpr GLenum GL_OPERAND2_ALPHA = 0x859A;
constexpr GLenum GL_RGB_SCALE = 0x8573;
constexpr GLenum GL_ADD_SIGNED = 0x8574;
constexpr GLenum GL_INTERPOLATE = 0x8575;
constexpr GLenum GL_SUBTRACT = 0x84E7;
constexpr GLenum GL_CONSTANT = 0x8576;
constexpr GLenum GL_PRIMARY_COLOR = 0x8577;
constexpr GLenum GL_PREVIOUS = 0x8578;
constexpr GLenum GL_DOT3_RGB = 0x86AE;
constexpr GLenum GL_DOT3_RGBA = 0x86AF;
void glActiveTexture(GLenum texture);
void glSampleCoverage(GLfloat value, GLboolean invert);
void glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void * data);
void glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void * data);
void glCompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void * data);
void glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * data);
void glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * data);
void glCompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * data);
void glGetCompressedTexImage(GLenum target, GLint level, void * img);
void glClientActiveTexture(GLenum texture);
void glMultiTexCoord1d(GLenum target, GLdouble s);
void glMultiTexCoord1dv(GLenum target, GLdouble const  * v);
void glMultiTexCoord1f(GLenum target, GLfloat s);
void glMultiTexCoord1fv(GLenum target, GLfloat const  * v);
void glMultiTexCoord1i(GLenum target, GLint s);
void glMultiTexCoord1iv(GLenum target, GLint const  * v);
void glMultiTexCoord1s(GLenum target, GLshort s);
void glMultiTexCoord1sv(GLenum target, GLshort const  * v);
void glMultiTexCoord2d(GLenum target, GLdouble s, GLdouble t);
void glMultiTexCoord2dv(GLenum target, GLdouble const  * v);
void glMultiTexCoord2f(GLenum target, GLfloat s, GLfloat t);
void glMultiTexCoord2fv(GLenum target, GLfloat const  * v);
void glMultiTexCoord2i(GLenum target, GLint s, GLint t);
void glMultiTexCoord2iv(GLenum target, GLint const  * v);
void glMultiTexCoord2s(GLenum target, GLshort s, GLshort t);
void glMultiTexCoord2sv(GLenum target, GLshort const  * v);
void glMultiTexCoord3d(GLenum target, GLdouble s, GLdouble t, GLdouble r);
void glMultiTexCoord3dv(GLenum target, GLdouble const  * v);
void glMultiTexCoord3f(GLenum target, GLfloat s, GLfloat t, GLfloat r);
void glMultiTexCoord3fv(GLenum target, GLfloat const  * v);
void glMultiTexCoord3i(GLenum target, GLint s, GLint t, GLint r);
void glMultiTexCoord3iv(GLenum target, GLint const  * v);
void glMultiTexCoord3s(GLenum target, GLshort s, GLshort t, GLshort r);
void glMultiTexCoord3sv(GLenum target, GLshort const  * v);
void glMultiTexCoord4d(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
void glMultiTexCoord4dv(GLenum target, GLdouble const  * v);
void glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
void glMultiTexCoord4fv(GLenum target, GLfloat const  * v);
void glMultiTexCoord4i(GLenum target, GLint s, GLint t, GLint r, GLint q);
void glMultiTexCoord4iv(GLenum target, GLint const  * v);
void glMultiTexCoord4s(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
void glMultiTexCoord4sv(GLenum target, GLshort const  * v);
void glLoadTransposeMatrixf(GLfloat const  * m);
void glLoadTransposeMatrixd(GLdouble const  * m);
void glMultTransposeMatrixf(GLfloat const  * m);
void glMultTransposeMatrixd(GLdouble const  * m);
#endif /* GL_VERSION_1_3 */
#ifndef GL_VERSION_1_4
#define GL_VERSION_1_4 1
constexpr GLenum GL_BLEND_DST_RGB = 0x80C8;
constexpr GLenum GL_BLEND_SRC_RGB = 0x80C9;
constexpr GLenum GL_BLEND_DST_ALPHA = 0x80CA;
constexpr GLenum GL_BLEND_SRC_ALPHA = 0x80CB;
constexpr GLenum GL_POINT_FADE_THRESHOLD_SIZE = 0x8128;
constexpr GLenum GL_DEPTH_COMPONENT16 = 0x81A5;
constexpr GLenum GL_DEPTH_COMPONENT24 = 0x81A6;
constexpr GLenum GL_DEPTH_COMPONENT32 = 0x81A7;
constexpr GLenum GL_MIRRORED_REPEAT = 0x8370;
constexpr GLenum GL_MAX_TEXTURE_LOD_BIAS = 0x84FD;
constexpr GLenum GL_TEXTURE_LOD_BIAS = 0x8501;
constexpr GLenum GL_INCR_WRAP = 0x8507;
constexpr GLenum GL_DECR_WRAP = 0x8508;
constexpr GLenum GL_TEXTURE_DEPTH_SIZE = 0x884A;
constexpr GLenum GL_TEXTURE_COMPARE_MODE = 0x884C;
constexpr GLenum GL_TEXTURE_COMPARE_FUNC = 0x884D;
constexpr GLenum GL_POINT_SIZE_MIN = 0x8126;
constexpr GLenum GL_POINT_SIZE_MAX = 0x8127;
constexpr GLenum GL_POINT_DISTANCE_ATTENUATION = 0x8129;
constexpr GLenum GL_GENERATE_MIPMAP = 0x8191;
constexpr GLenum GL_GENERATE_MIPMAP_HINT = 0x8192;
constexpr GLenum GL_FOG_COORDINATE_SOURCE = 0x8450;
constexpr GLenum GL_FOG_COORDINATE = 0x8451;
constexpr GLenum GL_FRAGMENT_DEPTH = 0x8452;
constexpr GLenum GL_CURRENT_FOG_COORDINATE = 0x8453;
constexpr GLenum GL_FOG_COORDINATE_ARRAY_TYPE = 0x8454;
constexpr GLenum GL_FOG_COORDINATE_ARRAY_STRIDE = 0x8455;
constexpr GLenum GL_FOG_COORDINATE_ARRAY_POINTER = 0x8456;
constexpr GLenum GL_FOG_COORDINATE_ARRAY = 0x8457;
constexpr GLenum GL_COLOR_SUM = 0x8458;
constexpr GLenum GL_CURRENT_SECONDARY_COLOR = 0x8459;
constexpr GLenum GL_SECONDARY_COLOR_ARRAY_SIZE = 0x845A;
constexpr GLenum GL_SECONDARY_COLOR_ARRAY_TYPE = 0x845B;
constexpr GLenum GL_SECONDARY_COLOR_ARRAY_STRIDE = 0x845C;
constexpr GLenum GL_SECONDARY_COLOR_ARRAY_POINTER = 0x845D;
constexpr GLenum GL_SECONDARY_COLOR_ARRAY = 0x845E;
constexpr GLenum GL_TEXTURE_FILTER_CONTROL = 0x8500;
constexpr GLenum GL_DEPTH_TEXTURE_MODE = 0x884B;
constexpr GLenum GL_COMPARE_R_TO_TEXTURE = 0x884E;
constexpr GLenum GL_BLEND_COLOR = 0x8005;
constexpr GLenum GL_BLEND_EQUATION = 0x8009;
constexpr GLenum GL_CONSTANT_COLOR = 0x8001;
constexpr GLenum GL_ONE_MINUS_CONSTANT_COLOR = 0x8002;
constexpr GLenum GL_CONSTANT_ALPHA = 0x8003;
constexpr GLenum GL_ONE_MINUS_CONSTANT_ALPHA = 0x8004;
constexpr GLenum GL_FUNC_ADD = 0x8006;
constexpr GLenum GL_FUNC_REVERSE_SUBTRACT = 0x800B;
constexpr GLenum GL_FUNC_SUBTRACT = 0x800A;
constexpr GLenum GL_MIN = 0x8007;
constexpr GLenum GL_MAX = 0x8008;
void glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
void glMultiDrawArrays(GLenum mode, GLint const  * first, GLsizei const  * count, GLsizei drawcount);
void glMultiDrawElements(GLenum mode, GLsizei const  * count, GLenum type, const void *const* indices, GLsizei drawcount);
void glPointParameterf(GLenum pname, GLfloat param);
void glPointParameterfv(GLenum pname, GLfloat const  * params);
void glPointParameteri(GLenum pname, GLint param);
void glPointParameteriv(GLenum pname, GLint const  * params);
void glFogCoordf(GLfloat coord);
void glFogCoordfv(GLfloat const  * coord);
void glFogCoordd(GLdouble coord);
void glFogCoorddv(GLdouble const  * coord);
void glFogCoordPointer(GLenum type, GLsizei stride, const void * pointer);
void glSecondaryColor3b(GLbyte red, GLbyte green, GLbyte blue);
void glSecondaryColor3bv(GLbyte const  * v);
void glSecondaryColor3d(GLdouble red, GLdouble green, GLdouble blue);
void glSecondaryColor3dv(GLdouble const  * v);
void glSecondaryColor3f(GLfloat red, GLfloat green, GLfloat blue);
void glSecondaryColor3fv(GLfloat const  * v);
void glSecondaryColor3i(GLint red, GLint green, GLint blue);
void glSecondaryColor3iv(GLint const  * v);
void glSecondaryColor3s(GLshort red, GLshort green, GLshort blue);
void glSecondaryColor3sv(GLshort const  * v);
void glSecondaryColor3ub(GLubyte red, GLubyte green, GLubyte blue);
void glSecondaryColor3ubv(GLubyte const  * v);
void glSecondaryColor3ui(GLuint red, GLuint green, GLuint blue);
void glSecondaryColor3uiv(GLuint const  * v);
void glSecondaryColor3us(GLushort red, GLushort green, GLushort blue);
void glSecondaryColor3usv(GLushort const  * v);
void glSecondaryColorPointer(GLint size, GLenum type, GLsizei stride, const void * pointer);
void glWindowPos2d(GLdouble x, GLdouble y);
void glWindowPos2dv(GLdouble const  * v);
void glWindowPos2f(GLfloat x, GLfloat y);
void glWindowPos2fv(GLfloat const  * v);
void glWindowPos2i(GLint x, GLint y);
void glWindowPos2iv(GLint const  * v);
void glWindowPos2s(GLshort x, GLshort y);
void glWindowPos2sv(GLshort const  * v);
void glWindowPos3d(GLdouble x, GLdouble y, GLdouble z);
void glWindowPos3dv(GLdouble const  * v);
void glWindowPos3f(GLfloat x, GLfloat y, GLfloat z);
void glWindowPos3fv(GLfloat const  * v);
void glWindowPos3i(GLint x, GLint y, GLint z);
void glWindowPos3iv(GLint const  * v);
void glWindowPos3s(GLshort x, GLshort y, GLshort z);
void glWindowPos3sv(GLshort const  * v);
void glBlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
void glBlendEquation(GLenum mode);
#endif /* GL_VERSION_1_4 */
#ifndef GL_VERSION_1_5
#define GL_VERSION_1_5 1
constexpr GLenum GL_BUFFER_SIZE = 0x8764;
constexpr GLenum GL_BUFFER_USAGE = 0x8765;
constexpr GLenum GL_QUERY_COUNTER_BITS = 0x8864;
constexpr GLenum GL_CURRENT_QUERY = 0x8865;
constexpr GLenum GL_QUERY_RESULT = 0x8866;
constexpr GLenum GL_QUERY_RESULT_AVAILABLE = 0x8867;
constexpr GLenum GL_ARRAY_BUFFER = 0x8892;
constexpr GLenum GL_ELEMENT_ARRAY_BUFFER = 0x8893;
constexpr GLenum GL_ARRAY_BUFFER_BINDING = 0x8894;
constexpr GLenum GL_ELEMENT_ARRAY_BUFFER_BINDING = 0x8895;
constexpr GLenum GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING = 0x889F;
constexpr GLenum GL_READ_ONLY = 0x88B8;
constexpr GLenum GL_WRITE_ONLY = 0x88B9;
constexpr GLenum GL_READ_WRITE = 0x88BA;
constexpr GLenum GL_BUFFER_ACCESS = 0x88BB;
constexpr GLenum GL_BUFFER_MAPPED = 0x88BC;
constexpr GLenum GL_BUFFER_MAP_POINTER = 0x88BD;
constexpr GLenum GL_STREAM_DRAW = 0x88E0;
constexpr GLenum GL_STREAM_READ = 0x88E1;
constexpr GLenum GL_STREAM_COPY = 0x88E2;
constexpr GLenum GL_STATIC_DRAW = 0x88E4;
constexpr GLenum GL_STATIC_READ = 0x88E5;
constexpr GLenum GL_STATIC_COPY = 0x88E6;
constexpr GLenum GL_DYNAMIC_DRAW = 0x88E8;
constexpr GLenum GL_DYNAMIC_READ = 0x88E9;
constexpr GLenum GL_DYNAMIC_COPY = 0x88EA;
constexpr GLenum GL_SAMPLES_PASSED = 0x8914;
constexpr GLenum GL_SRC1_ALPHA = 0x8589;
constexpr GLenum GL_VERTEX_ARRAY_BUFFER_BINDING = 0x8896;
constexpr GLenum GL_NORMAL_ARRAY_BUFFER_BINDING = 0x8897;
constexpr GLenum GL_COLOR_ARRAY_BUFFER_BINDING = 0x8898;
constexpr GLenum GL_INDEX_ARRAY_BUFFER_BINDING = 0x8899;
constexpr GLenum GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING = 0x889A;
constexpr GLenum GL_EDGE_FLAG_ARRAY_BUFFER_BINDING = 0x889B;
constexpr GLenum GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING = 0x889C;
constexpr GLenum GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING = 0x889D;
constexpr GLenum GL_WEIGHT_ARRAY_BUFFER_BINDING = 0x889E;
constexpr GLenum GL_FOG_COORD_SRC = 0x8450;
constexpr GLenum GL_FOG_COORD = 0x8451;
constexpr GLenum GL_CURRENT_FOG_COORD = 0x8453;
constexpr GLenum GL_FOG_COORD_ARRAY_TYPE = 0x8454;
constexpr GLenum GL_FOG_COORD_ARRAY_STRIDE = 0x8455;
constexpr GLenum GL_FOG_COORD_ARRAY_POINTER = 0x8456;
constexpr GLenum GL_FOG_COORD_ARRAY = 0x8457;
constexpr GLenum GL_FOG_COORD_ARRAY_BUFFER_BINDING = 0x889D;
constexpr GLenum GL_SRC0_RGB = 0x8580;
constexpr GLenum GL_SRC1_RGB = 0x8581;
constexpr GLenum GL_SRC2_RGB = 0x8582;
constexpr GLenum GL_SRC0_ALPHA = 0x8588;
constexpr GLenum GL_SRC2_ALPHA = 0x858A;
void glGenQueries(GLsizei n, GLuint * ids);
void glDeleteQueries(GLsizei n, GLuint const  * ids);
GLboolean glIsQuery(GLuint id);
void glBeginQuery(GLenum target, GLuint id);
void glEndQuery(GLenum target);
void glGetQueryiv(GLenum target, GLenum pname, GLint * params);
void glGetQueryObjectiv(GLuint id, GLenum pname, GLint * params);
void glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint * params);
void glBindBuffer(GLenum target, GLuint buffer);
void glDeleteBuffers(GLsizei n, GLuint const  * buffers);
void glGenBuffers(GLsizei n, GLuint * buffers);
GLboolean glIsBuffer(GLuint buffer);
void glBufferData(GLenum target, GLsizeiptr size, const void * data, GLenum usage);
void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const void * data);
void glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, void * data);
void * glMapBuffer(GLenum target, GLenum access);
GLboolean glUnmapBuffer(GLenum target);
void glGetBufferParameteriv(GLenum target, GLenum pname, GLint * params);
void glGetBufferPointerv(GLenum target, GLenum pname, void ** params);
#endif /* GL_VERSION_1_5 */
#ifndef GL_VERSION_2_0
#define GL_VERSION_2_0 1
constexpr GLenum GL_BLEND_EQUATION_RGB = 0x8009;
constexpr GLenum GL_VERTEX_ATTRIB_ARRAY_ENABLED = 0x8622;
constexpr GLenum GL_VERTEX_ATTRIB_ARRAY_SIZE = 0x8623;
constexpr GLenum GL_VERTEX_ATTRIB_ARRAY_STRIDE = 0x8624;
constexpr GLenum GL_VERTEX_ATTRIB_ARRAY_TYPE = 0x8625;
constexpr GLenum GL_CURRENT_VERTEX_ATTRIB = 0x8626;
constexpr GLenum GL_VERTEX_PROGRAM_POINT_SIZE = 0x8642;
constexpr GLenum GL_VERTEX_ATTRIB_ARRAY_POINTER = 0x8645;
constexpr GLenum GL_STENCIL_BACK_FUNC = 0x8800;
constexpr GLenum GL_STENCIL_BACK_FAIL = 0x8801;
constexpr GLenum GL_STENCIL_BACK_PASS_DEPTH_FAIL = 0x8802;
constexpr GLenum GL_STENCIL_BACK_PASS_DEPTH_PASS = 0x8803;
constexpr GLenum GL_MAX_DRAW_BUFFERS = 0x8824;
constexpr GLenum GL_DRAW_BUFFER0 = 0x8825;
constexpr GLenum GL_DRAW_BUFFER1 = 0x8826;
constexpr GLenum GL_DRAW_BUFFER2 = 0x8827;
constexpr GLenum GL_DRAW_BUFFER3 = 0x8828;
constexpr GLenum GL_DRAW_BUFFER4 = 0x8829;
constexpr GLenum GL_DRAW_BUFFER5 = 0x882A;
constexpr GLenum GL_DRAW_BUFFER6 = 0x882B;
constexpr GLenum GL_DRAW_BUFFER7 = 0x882C;
constexpr GLenum GL_DRAW_BUFFER8 = 0x882D;
constexpr GLenum GL_DRAW_BUFFER9 = 0x882E;
constexpr GLenum GL_DRAW_BUFFER10 = 0x882F;
constexpr GLenum GL_DRAW_BUFFER11 = 0x8830;
constexpr GLenum GL_DRAW_BUFFER12 = 0x8831;
constexpr GLenum GL_DRAW_BUFFER13 = 0x8832;
constexpr GLenum GL_DRAW_BUFFER14 = 0x8833;
constexpr GLenum GL_DRAW_BUFFER15 = 0x8834;
constexpr GLenum GL_BLEND_EQUATION_ALPHA = 0x883D;
constexpr GLenum GL_MAX_VERTEX_ATTRIBS = 0x8869;
constexpr GLenum GL_VERTEX_ATTRIB_ARRAY_NORMALIZED = 0x886A;
constexpr GLenum GL_MAX_TEXTURE_IMAGE_UNITS = 0x8872;
constexpr GLenum GL_FRAGMENT_SHADER = 0x8B30;
constexpr GLenum GL_VERTEX_SHADER = 0x8B31;
constexpr GLenum GL_MAX_FRAGMENT_UNIFORM_COMPONENTS = 0x8B49;
constexpr GLenum GL_MAX_VERTEX_UNIFORM_COMPONENTS = 0x8B4A;
constexpr GLenum GL_MAX_VARYING_FLOATS = 0x8B4B;
constexpr GLenum GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS = 0x8B4C;
constexpr GLenum GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS = 0x8B4D;
constexpr GLenum GL_SHADER_TYPE = 0x8B4F;
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
constexpr GLenum GL_SAMPLER_1D = 0x8B5D;
constexpr GLenum GL_SAMPLER_2D = 0x8B5E;
constexpr GLenum GL_SAMPLER_3D = 0x8B5F;
constexpr GLenum GL_SAMPLER_CUBE = 0x8B60;
constexpr GLenum GL_SAMPLER_1D_SHADOW = 0x8B61;
constexpr GLenum GL_SAMPLER_2D_SHADOW = 0x8B62;
constexpr GLenum GL_DELETE_STATUS = 0x8B80;
constexpr GLenum GL_COMPILE_STATUS = 0x8B81;
constexpr GLenum GL_LINK_STATUS = 0x8B82;
constexpr GLenum GL_VALIDATE_STATUS = 0x8B83;
constexpr GLenum GL_INFO_LOG_LENGTH = 0x8B84;
constexpr GLenum GL_ATTACHED_SHADERS = 0x8B85;
constexpr GLenum GL_ACTIVE_UNIFORMS = 0x8B86;
constexpr GLenum GL_ACTIVE_UNIFORM_MAX_LENGTH = 0x8B87;
constexpr GLenum GL_SHADER_SOURCE_LENGTH = 0x8B88;
constexpr GLenum GL_ACTIVE_ATTRIBUTES = 0x8B89;
constexpr GLenum GL_ACTIVE_ATTRIBUTE_MAX_LENGTH = 0x8B8A;
constexpr GLenum GL_FRAGMENT_SHADER_DERIVATIVE_HINT = 0x8B8B;
constexpr GLenum GL_SHADING_LANGUAGE_VERSION = 0x8B8C;
constexpr GLenum GL_CURRENT_PROGRAM = 0x8B8D;
constexpr GLenum GL_POINT_SPRITE_COORD_ORIGIN = 0x8CA0;
constexpr GLenum GL_LOWER_LEFT = 0x8CA1;
constexpr GLenum GL_UPPER_LEFT = 0x8CA2;
constexpr GLenum GL_STENCIL_BACK_REF = 0x8CA3;
constexpr GLenum GL_STENCIL_BACK_VALUE_MASK = 0x8CA4;
constexpr GLenum GL_STENCIL_BACK_WRITEMASK = 0x8CA5;
constexpr GLenum GL_VERTEX_PROGRAM_TWO_SIDE = 0x8643;
constexpr GLenum GL_POINT_SPRITE = 0x8861;
constexpr GLenum GL_COORD_REPLACE = 0x8862;
constexpr GLenum GL_MAX_TEXTURE_COORDS = 0x8871;
void glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha);
void glDrawBuffers(GLsizei n, GLenum const  * bufs);
void glStencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
void glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask);
void glStencilMaskSeparate(GLenum face, GLuint mask);
void glAttachShader(GLuint program, GLuint shader);
void glBindAttribLocation(GLuint program, GLuint index, GLchar const  * name);
void glCompileShader(GLuint shader);
GLuint glCreateProgram();
GLuint glCreateShader(GLenum type);
void glDeleteProgram(GLuint program);
void glDeleteShader(GLuint shader);
void glDetachShader(GLuint program, GLuint shader);
void glDisableVertexAttribArray(GLuint index);
void glEnableVertexAttribArray(GLuint index);
void glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name);
void glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name);
void glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei * count, GLuint * shaders);
GLint glGetAttribLocation(GLuint program, GLchar const  * name);
void glGetProgramiv(GLuint program, GLenum pname, GLint * params);
void glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei * length, GLchar * infoLog);
void glGetShaderiv(GLuint shader, GLenum pname, GLint * params);
void glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * infoLog);
void glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * source);
GLint glGetUniformLocation(GLuint program, GLchar const  * name);
void glGetUniformfv(GLuint program, GLint location, GLfloat * params);
void glGetUniformiv(GLuint program, GLint location, GLint * params);
void glGetVertexAttribdv(GLuint index, GLenum pname, GLdouble * params);
void glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat * params);
void glGetVertexAttribiv(GLuint index, GLenum pname, GLint * params);
void glGetVertexAttribPointerv(GLuint index, GLenum pname, void ** pointer);
GLboolean glIsProgram(GLuint program);
GLboolean glIsShader(GLuint shader);
void glLinkProgram(GLuint program);
void glShaderSource(GLuint shader, GLsizei count, GLchar const  *const* string, GLint const  * length);
void glUseProgram(GLuint program);
void glUniform1f(GLint location, GLfloat v0);
void glUniform2f(GLint location, GLfloat v0, GLfloat v1);
void glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
void glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
void glUniform1i(GLint location, GLint v0);
void glUniform2i(GLint location, GLint v0, GLint v1);
void glUniform3i(GLint location, GLint v0, GLint v1, GLint v2);
void glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
void glUniform1fv(GLint location, GLsizei count, GLfloat const  * value);
void glUniform2fv(GLint location, GLsizei count, GLfloat const  * value);
void glUniform3fv(GLint location, GLsizei count, GLfloat const  * value);
void glUniform4fv(GLint location, GLsizei count, GLfloat const  * value);
void glUniform1iv(GLint location, GLsizei count, GLint const  * value);
void glUniform2iv(GLint location, GLsizei count, GLint const  * value);
void glUniform3iv(GLint location, GLsizei count, GLint const  * value);
void glUniform4iv(GLint location, GLsizei count, GLint const  * value);
void glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value);
void glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value);
void glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value);
void glValidateProgram(GLuint program);
void glVertexAttrib1d(GLuint index, GLdouble x);
void glVertexAttrib1dv(GLuint index, GLdouble const  * v);
void glVertexAttrib1f(GLuint index, GLfloat x);
void glVertexAttrib1fv(GLuint index, GLfloat const  * v);
void glVertexAttrib1s(GLuint index, GLshort x);
void glVertexAttrib1sv(GLuint index, GLshort const  * v);
void glVertexAttrib2d(GLuint index, GLdouble x, GLdouble y);
void glVertexAttrib2dv(GLuint index, GLdouble const  * v);
void glVertexAttrib2f(GLuint index, GLfloat x, GLfloat y);
void glVertexAttrib2fv(GLuint index, GLfloat const  * v);
void glVertexAttrib2s(GLuint index, GLshort x, GLshort y);
void glVertexAttrib2sv(GLuint index, GLshort const  * v);
void glVertexAttrib3d(GLuint index, GLdouble x, GLdouble y, GLdouble z);
void glVertexAttrib3dv(GLuint index, GLdouble const  * v);
void glVertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z);
void glVertexAttrib3fv(GLuint index, GLfloat const  * v);
void glVertexAttrib3s(GLuint index, GLshort x, GLshort y, GLshort z);
void glVertexAttrib3sv(GLuint index, GLshort const  * v);
void glVertexAttrib4Nbv(GLuint index, GLbyte const  * v);
void glVertexAttrib4Niv(GLuint index, GLint const  * v);
void glVertexAttrib4Nsv(GLuint index, GLshort const  * v);
void glVertexAttrib4Nub(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
void glVertexAttrib4Nubv(GLuint index, GLubyte const  * v);
void glVertexAttrib4Nuiv(GLuint index, GLuint const  * v);
void glVertexAttrib4Nusv(GLuint index, GLushort const  * v);
void glVertexAttrib4bv(GLuint index, GLbyte const  * v);
void glVertexAttrib4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void glVertexAttrib4dv(GLuint index, GLdouble const  * v);
void glVertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void glVertexAttrib4fv(GLuint index, GLfloat const  * v);
void glVertexAttrib4iv(GLuint index, GLint const  * v);
void glVertexAttrib4s(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
void glVertexAttrib4sv(GLuint index, GLshort const  * v);
void glVertexAttrib4ubv(GLuint index, GLubyte const  * v);
void glVertexAttrib4uiv(GLuint index, GLuint const  * v);
void glVertexAttrib4usv(GLuint index, GLushort const  * v);
void glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void * pointer);
#endif /* GL_VERSION_2_0 */
#ifndef GL_VERSION_2_1
#define GL_VERSION_2_1 1
constexpr GLenum GL_PIXEL_PACK_BUFFER = 0x88EB;
constexpr GLenum GL_PIXEL_UNPACK_BUFFER = 0x88EC;
constexpr GLenum GL_PIXEL_PACK_BUFFER_BINDING = 0x88ED;
constexpr GLenum GL_PIXEL_UNPACK_BUFFER_BINDING = 0x88EF;
constexpr GLenum GL_FLOAT_MAT2x3 = 0x8B65;
constexpr GLenum GL_FLOAT_MAT2x4 = 0x8B66;
constexpr GLenum GL_FLOAT_MAT3x2 = 0x8B67;
constexpr GLenum GL_FLOAT_MAT3x4 = 0x8B68;
constexpr GLenum GL_FLOAT_MAT4x2 = 0x8B69;
constexpr GLenum GL_FLOAT_MAT4x3 = 0x8B6A;
constexpr GLenum GL_SRGB = 0x8C40;
constexpr GLenum GL_SRGB8 = 0x8C41;
constexpr GLenum GL_SRGB_ALPHA = 0x8C42;
constexpr GLenum GL_SRGB8_ALPHA8 = 0x8C43;
constexpr GLenum GL_COMPRESSED_SRGB = 0x8C48;
constexpr GLenum GL_COMPRESSED_SRGB_ALPHA = 0x8C49;
constexpr GLenum GL_CURRENT_RASTER_SECONDARY_COLOR = 0x845F;
constexpr GLenum GL_SLUMINANCE_ALPHA = 0x8C44;
constexpr GLenum GL_SLUMINANCE8_ALPHA8 = 0x8C45;
constexpr GLenum GL_SLUMINANCE = 0x8C46;
constexpr GLenum GL_SLUMINANCE8 = 0x8C47;
constexpr GLenum GL_COMPRESSED_SLUMINANCE = 0x8C4A;
constexpr GLenum GL_COMPRESSED_SLUMINANCE_ALPHA = 0x8C4B;
void glUniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value);
void glUniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value);
void glUniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value);
void glUniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value);
void glUniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value);
void glUniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value);
#endif /* GL_VERSION_2_1 */
#ifndef GL_VERSION_3_0
#define GL_VERSION_3_0 1
constexpr GLenum GL_COMPARE_REF_TO_TEXTURE = 0x884E;
constexpr GLenum GL_CLIP_DISTANCE0 = 0x3000;
constexpr GLenum GL_CLIP_DISTANCE1 = 0x3001;
constexpr GLenum GL_CLIP_DISTANCE2 = 0x3002;
constexpr GLenum GL_CLIP_DISTANCE3 = 0x3003;
constexpr GLenum GL_CLIP_DISTANCE4 = 0x3004;
constexpr GLenum GL_CLIP_DISTANCE5 = 0x3005;
constexpr GLenum GL_CLIP_DISTANCE6 = 0x3006;
constexpr GLenum GL_CLIP_DISTANCE7 = 0x3007;
constexpr GLenum GL_MAX_CLIP_DISTANCES = 0x0D32;
constexpr GLenum GL_MAJOR_VERSION = 0x821B;
constexpr GLenum GL_MINOR_VERSION = 0x821C;
constexpr GLenum GL_NUM_EXTENSIONS = 0x821D;
constexpr GLenum GL_CONTEXT_FLAGS = 0x821E;
constexpr GLenum GL_COMPRESSED_RED = 0x8225;
constexpr GLenum GL_COMPRESSED_RG = 0x8226;
constexpr GLenum GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT = 0x00000001;
constexpr GLenum GL_RGBA32F = 0x8814;
constexpr GLenum GL_RGB32F = 0x8815;
constexpr GLenum GL_RGBA16F = 0x881A;
constexpr GLenum GL_RGB16F = 0x881B;
constexpr GLenum GL_VERTEX_ATTRIB_ARRAY_INTEGER = 0x88FD;
constexpr GLenum GL_MAX_ARRAY_TEXTURE_LAYERS = 0x88FF;
constexpr GLenum GL_MIN_PROGRAM_TEXEL_OFFSET = 0x8904;
constexpr GLenum GL_MAX_PROGRAM_TEXEL_OFFSET = 0x8905;
constexpr GLenum GL_CLAMP_READ_COLOR = 0x891C;
constexpr GLenum GL_FIXED_ONLY = 0x891D;
constexpr GLenum GL_MAX_VARYING_COMPONENTS = 0x8B4B;
constexpr GLenum GL_TEXTURE_1D_ARRAY = 0x8C18;
constexpr GLenum GL_PROXY_TEXTURE_1D_ARRAY = 0x8C19;
constexpr GLenum GL_TEXTURE_2D_ARRAY = 0x8C1A;
constexpr GLenum GL_PROXY_TEXTURE_2D_ARRAY = 0x8C1B;
constexpr GLenum GL_TEXTURE_BINDING_1D_ARRAY = 0x8C1C;
constexpr GLenum GL_TEXTURE_BINDING_2D_ARRAY = 0x8C1D;
constexpr GLenum GL_R11F_G11F_B10F = 0x8C3A;
constexpr GLenum GL_UNSIGNED_INT_10F_11F_11F_REV = 0x8C3B;
constexpr GLenum GL_RGB9_E5 = 0x8C3D;
constexpr GLenum GL_UNSIGNED_INT_5_9_9_9_REV = 0x8C3E;
constexpr GLenum GL_TEXTURE_SHARED_SIZE = 0x8C3F;
constexpr GLenum GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH = 0x8C76;
constexpr GLenum GL_TRANSFORM_FEEDBACK_BUFFER_MODE = 0x8C7F;
constexpr GLenum GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS = 0x8C80;
constexpr GLenum GL_TRANSFORM_FEEDBACK_VARYINGS = 0x8C83;
constexpr GLenum GL_TRANSFORM_FEEDBACK_BUFFER_START = 0x8C84;
constexpr GLenum GL_TRANSFORM_FEEDBACK_BUFFER_SIZE = 0x8C85;
constexpr GLenum GL_PRIMITIVES_GENERATED = 0x8C87;
constexpr GLenum GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN = 0x8C88;
constexpr GLenum GL_RASTERIZER_DISCARD = 0x8C89;
constexpr GLenum GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS = 0x8C8A;
constexpr GLenum GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS = 0x8C8B;
constexpr GLenum GL_INTERLEAVED_ATTRIBS = 0x8C8C;
constexpr GLenum GL_SEPARATE_ATTRIBS = 0x8C8D;
constexpr GLenum GL_TRANSFORM_FEEDBACK_BUFFER = 0x8C8E;
constexpr GLenum GL_TRANSFORM_FEEDBACK_BUFFER_BINDING = 0x8C8F;
constexpr GLenum GL_RGBA32UI = 0x8D70;
constexpr GLenum GL_RGB32UI = 0x8D71;
constexpr GLenum GL_RGBA16UI = 0x8D76;
constexpr GLenum GL_RGB16UI = 0x8D77;
constexpr GLenum GL_RGBA8UI = 0x8D7C;
constexpr GLenum GL_RGB8UI = 0x8D7D;
constexpr GLenum GL_RGBA32I = 0x8D82;
constexpr GLenum GL_RGB32I = 0x8D83;
constexpr GLenum GL_RGBA16I = 0x8D88;
constexpr GLenum GL_RGB16I = 0x8D89;
constexpr GLenum GL_RGBA8I = 0x8D8E;
constexpr GLenum GL_RGB8I = 0x8D8F;
constexpr GLenum GL_RED_INTEGER = 0x8D94;
constexpr GLenum GL_GREEN_INTEGER = 0x8D95;
constexpr GLenum GL_BLUE_INTEGER = 0x8D96;
constexpr GLenum GL_RGB_INTEGER = 0x8D98;
constexpr GLenum GL_RGBA_INTEGER = 0x8D99;
constexpr GLenum GL_BGR_INTEGER = 0x8D9A;
constexpr GLenum GL_BGRA_INTEGER = 0x8D9B;
constexpr GLenum GL_SAMPLER_1D_ARRAY = 0x8DC0;
constexpr GLenum GL_SAMPLER_2D_ARRAY = 0x8DC1;
constexpr GLenum GL_SAMPLER_1D_ARRAY_SHADOW = 0x8DC3;
constexpr GLenum GL_SAMPLER_2D_ARRAY_SHADOW = 0x8DC4;
constexpr GLenum GL_SAMPLER_CUBE_SHADOW = 0x8DC5;
constexpr GLenum GL_UNSIGNED_INT_VEC2 = 0x8DC6;
constexpr GLenum GL_UNSIGNED_INT_VEC3 = 0x8DC7;
constexpr GLenum GL_UNSIGNED_INT_VEC4 = 0x8DC8;
constexpr GLenum GL_INT_SAMPLER_1D = 0x8DC9;
constexpr GLenum GL_INT_SAMPLER_2D = 0x8DCA;
constexpr GLenum GL_INT_SAMPLER_3D = 0x8DCB;
constexpr GLenum GL_INT_SAMPLER_CUBE = 0x8DCC;
constexpr GLenum GL_INT_SAMPLER_1D_ARRAY = 0x8DCE;
constexpr GLenum GL_INT_SAMPLER_2D_ARRAY = 0x8DCF;
constexpr GLenum GL_UNSIGNED_INT_SAMPLER_1D = 0x8DD1;
constexpr GLenum GL_UNSIGNED_INT_SAMPLER_2D = 0x8DD2;
constexpr GLenum GL_UNSIGNED_INT_SAMPLER_3D = 0x8DD3;
constexpr GLenum GL_UNSIGNED_INT_SAMPLER_CUBE = 0x8DD4;
constexpr GLenum GL_UNSIGNED_INT_SAMPLER_1D_ARRAY = 0x8DD6;
constexpr GLenum GL_UNSIGNED_INT_SAMPLER_2D_ARRAY = 0x8DD7;
constexpr GLenum GL_QUERY_WAIT = 0x8E13;
constexpr GLenum GL_QUERY_NO_WAIT = 0x8E14;
constexpr GLenum GL_QUERY_BY_REGION_WAIT = 0x8E15;
constexpr GLenum GL_QUERY_BY_REGION_NO_WAIT = 0x8E16;
constexpr GLenum GL_BUFFER_ACCESS_FLAGS = 0x911F;
constexpr GLenum GL_BUFFER_MAP_LENGTH = 0x9120;
constexpr GLenum GL_BUFFER_MAP_OFFSET = 0x9121;
constexpr GLenum GL_DEPTH_COMPONENT32F = 0x8CAC;
constexpr GLenum GL_DEPTH32F_STENCIL8 = 0x8CAD;
constexpr GLenum GL_FLOAT_32_UNSIGNED_INT_24_8_REV = 0x8DAD;
constexpr GLenum GL_INVALID_FRAMEBUFFER_OPERATION = 0x0506;
constexpr GLenum GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING = 0x8210;
constexpr GLenum GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE = 0x8211;
constexpr GLenum GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE = 0x8212;
constexpr GLenum GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE = 0x8213;
constexpr GLenum GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE = 0x8214;
constexpr GLenum GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE = 0x8215;
constexpr GLenum GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE = 0x8216;
constexpr GLenum GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE = 0x8217;
constexpr GLenum GL_FRAMEBUFFER_DEFAULT = 0x8218;
constexpr GLenum GL_FRAMEBUFFER_UNDEFINED = 0x8219;
constexpr GLenum GL_DEPTH_STENCIL_ATTACHMENT = 0x821A;
constexpr GLenum GL_MAX_RENDERBUFFER_SIZE = 0x84E8;
constexpr GLenum GL_DEPTH_STENCIL = 0x84F9;
constexpr GLenum GL_UNSIGNED_INT_24_8 = 0x84FA;
constexpr GLenum GL_DEPTH24_STENCIL8 = 0x88F0;
constexpr GLenum GL_TEXTURE_STENCIL_SIZE = 0x88F1;
constexpr GLenum GL_TEXTURE_RED_TYPE = 0x8C10;
constexpr GLenum GL_TEXTURE_GREEN_TYPE = 0x8C11;
constexpr GLenum GL_TEXTURE_BLUE_TYPE = 0x8C12;
constexpr GLenum GL_TEXTURE_ALPHA_TYPE = 0x8C13;
constexpr GLenum GL_TEXTURE_DEPTH_TYPE = 0x8C16;
constexpr GLenum GL_UNSIGNED_NORMALIZED = 0x8C17;
constexpr GLenum GL_FRAMEBUFFER_BINDING = 0x8CA6;
constexpr GLenum GL_DRAW_FRAMEBUFFER_BINDING = 0x8CA6;
constexpr GLenum GL_RENDERBUFFER_BINDING = 0x8CA7;
constexpr GLenum GL_READ_FRAMEBUFFER = 0x8CA8;
constexpr GLenum GL_DRAW_FRAMEBUFFER = 0x8CA9;
constexpr GLenum GL_READ_FRAMEBUFFER_BINDING = 0x8CAA;
constexpr GLenum GL_RENDERBUFFER_SAMPLES = 0x8CAB;
constexpr GLenum GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE = 0x8CD0;
constexpr GLenum GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME = 0x8CD1;
constexpr GLenum GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL = 0x8CD2;
constexpr GLenum GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE = 0x8CD3;
constexpr GLenum GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER = 0x8CD4;
constexpr GLenum GL_FRAMEBUFFER_COMPLETE = 0x8CD5;
constexpr GLenum GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT = 0x8CD6;
constexpr GLenum GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT = 0x8CD7;
constexpr GLenum GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER = 0x8CDB;
constexpr GLenum GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER = 0x8CDC;
constexpr GLenum GL_FRAMEBUFFER_UNSUPPORTED = 0x8CDD;
constexpr GLenum GL_MAX_COLOR_ATTACHMENTS = 0x8CDF;
constexpr GLenum GL_COLOR_ATTACHMENT0 = 0x8CE0;
constexpr GLenum GL_COLOR_ATTACHMENT1 = 0x8CE1;
constexpr GLenum GL_COLOR_ATTACHMENT2 = 0x8CE2;
constexpr GLenum GL_COLOR_ATTACHMENT3 = 0x8CE3;
constexpr GLenum GL_COLOR_ATTACHMENT4 = 0x8CE4;
constexpr GLenum GL_COLOR_ATTACHMENT5 = 0x8CE5;
constexpr GLenum GL_COLOR_ATTACHMENT6 = 0x8CE6;
constexpr GLenum GL_COLOR_ATTACHMENT7 = 0x8CE7;
constexpr GLenum GL_COLOR_ATTACHMENT8 = 0x8CE8;
constexpr GLenum GL_COLOR_ATTACHMENT9 = 0x8CE9;
constexpr GLenum GL_COLOR_ATTACHMENT10 = 0x8CEA;
constexpr GLenum GL_COLOR_ATTACHMENT11 = 0x8CEB;
constexpr GLenum GL_COLOR_ATTACHMENT12 = 0x8CEC;
constexpr GLenum GL_COLOR_ATTACHMENT13 = 0x8CED;
constexpr GLenum GL_COLOR_ATTACHMENT14 = 0x8CEE;
constexpr GLenum GL_COLOR_ATTACHMENT15 = 0x8CEF;
constexpr GLenum GL_COLOR_ATTACHMENT16 = 0x8CF0;
constexpr GLenum GL_COLOR_ATTACHMENT17 = 0x8CF1;
constexpr GLenum GL_COLOR_ATTACHMENT18 = 0x8CF2;
constexpr GLenum GL_COLOR_ATTACHMENT19 = 0x8CF3;
constexpr GLenum GL_COLOR_ATTACHMENT20 = 0x8CF4;
constexpr GLenum GL_COLOR_ATTACHMENT21 = 0x8CF5;
constexpr GLenum GL_COLOR_ATTACHMENT22 = 0x8CF6;
constexpr GLenum GL_COLOR_ATTACHMENT23 = 0x8CF7;
constexpr GLenum GL_COLOR_ATTACHMENT24 = 0x8CF8;
constexpr GLenum GL_COLOR_ATTACHMENT25 = 0x8CF9;
constexpr GLenum GL_COLOR_ATTACHMENT26 = 0x8CFA;
constexpr GLenum GL_COLOR_ATTACHMENT27 = 0x8CFB;
constexpr GLenum GL_COLOR_ATTACHMENT28 = 0x8CFC;
constexpr GLenum GL_COLOR_ATTACHMENT29 = 0x8CFD;
constexpr GLenum GL_COLOR_ATTACHMENT30 = 0x8CFE;
constexpr GLenum GL_COLOR_ATTACHMENT31 = 0x8CFF;
constexpr GLenum GL_DEPTH_ATTACHMENT = 0x8D00;
constexpr GLenum GL_STENCIL_ATTACHMENT = 0x8D20;
constexpr GLenum GL_FRAMEBUFFER = 0x8D40;
constexpr GLenum GL_RENDERBUFFER = 0x8D41;
constexpr GLenum GL_RENDERBUFFER_WIDTH = 0x8D42;
constexpr GLenum GL_RENDERBUFFER_HEIGHT = 0x8D43;
constexpr GLenum GL_RENDERBUFFER_INTERNAL_FORMAT = 0x8D44;
constexpr GLenum GL_STENCIL_INDEX1 = 0x8D46;
constexpr GLenum GL_STENCIL_INDEX4 = 0x8D47;
constexpr GLenum GL_STENCIL_INDEX8 = 0x8D48;
constexpr GLenum GL_STENCIL_INDEX16 = 0x8D49;
constexpr GLenum GL_RENDERBUFFER_RED_SIZE = 0x8D50;
constexpr GLenum GL_RENDERBUFFER_GREEN_SIZE = 0x8D51;
constexpr GLenum GL_RENDERBUFFER_BLUE_SIZE = 0x8D52;
constexpr GLenum GL_RENDERBUFFER_ALPHA_SIZE = 0x8D53;
constexpr GLenum GL_RENDERBUFFER_DEPTH_SIZE = 0x8D54;
constexpr GLenum GL_RENDERBUFFER_STENCIL_SIZE = 0x8D55;
constexpr GLenum GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE = 0x8D56;
constexpr GLenum GL_MAX_SAMPLES = 0x8D57;
constexpr GLenum GL_INDEX = 0x8222;
constexpr GLenum GL_TEXTURE_LUMINANCE_TYPE = 0x8C14;
constexpr GLenum GL_TEXTURE_INTENSITY_TYPE = 0x8C15;
constexpr GLenum GL_FRAMEBUFFER_SRGB = 0x8DB9;
constexpr GLenum GL_HALF_FLOAT = 0x140B;
constexpr GLenum GL_MAP_READ_BIT = 0x0001;
constexpr GLenum GL_MAP_WRITE_BIT = 0x0002;
constexpr GLenum GL_MAP_INVALIDATE_RANGE_BIT = 0x0004;
constexpr GLenum GL_MAP_INVALIDATE_BUFFER_BIT = 0x0008;
constexpr GLenum GL_MAP_FLUSH_EXPLICIT_BIT = 0x0010;
constexpr GLenum GL_MAP_UNSYNCHRONIZED_BIT = 0x0020;
constexpr GLenum GL_COMPRESSED_RED_RGTC1 = 0x8DBB;
constexpr GLenum GL_COMPRESSED_SIGNED_RED_RGTC1 = 0x8DBC;
constexpr GLenum GL_COMPRESSED_RG_RGTC2 = 0x8DBD;
constexpr GLenum GL_COMPRESSED_SIGNED_RG_RGTC2 = 0x8DBE;
constexpr GLenum GL_RG = 0x8227;
constexpr GLenum GL_RG_INTEGER = 0x8228;
constexpr GLenum GL_R8 = 0x8229;
constexpr GLenum GL_R16 = 0x822A;
constexpr GLenum GL_RG8 = 0x822B;
constexpr GLenum GL_RG16 = 0x822C;
constexpr GLenum GL_R16F = 0x822D;
constexpr GLenum GL_R32F = 0x822E;
constexpr GLenum GL_RG16F = 0x822F;
constexpr GLenum GL_RG32F = 0x8230;
constexpr GLenum GL_R8I = 0x8231;
constexpr GLenum GL_R8UI = 0x8232;
constexpr GLenum GL_R16I = 0x8233;
constexpr GLenum GL_R16UI = 0x8234;
constexpr GLenum GL_R32I = 0x8235;
constexpr GLenum GL_R32UI = 0x8236;
constexpr GLenum GL_RG8I = 0x8237;
constexpr GLenum GL_RG8UI = 0x8238;
constexpr GLenum GL_RG16I = 0x8239;
constexpr GLenum GL_RG16UI = 0x823A;
constexpr GLenum GL_RG32I = 0x823B;
constexpr GLenum GL_RG32UI = 0x823C;
constexpr GLenum GL_VERTEX_ARRAY_BINDING = 0x85B5;
constexpr GLenum GL_CLAMP_VERTEX_COLOR = 0x891A;
constexpr GLenum GL_CLAMP_FRAGMENT_COLOR = 0x891B;
constexpr GLenum GL_ALPHA_INTEGER = 0x8D97;
void glColorMaski(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
void glGetBooleani_v(GLenum target, GLuint index, GLboolean * data);
void glGetIntegeri_v(GLenum target, GLuint index, GLint * data);
void glEnablei(GLenum target, GLuint index);
void glDisablei(GLenum target, GLuint index);
GLboolean glIsEnabledi(GLenum target, GLuint index);
void glBeginTransformFeedback(GLenum primitiveMode);
void glEndTransformFeedback();
void glBindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
void glBindBufferBase(GLenum target, GLuint index, GLuint buffer);
void glTransformFeedbackVaryings(GLuint program, GLsizei count, GLchar const  *const* varyings, GLenum bufferMode);
void glGetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLsizei * size, GLenum * type, GLchar * name);
void glClampColor(GLenum target, GLenum clamp);
void glBeginConditionalRender(GLuint id, GLenum mode);
void glEndConditionalRender();
void glVertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void * pointer);
void glGetVertexAttribIiv(GLuint index, GLenum pname, GLint * params);
void glGetVertexAttribIuiv(GLuint index, GLenum pname, GLuint * params);
void glVertexAttribI1i(GLuint index, GLint x);
void glVertexAttribI2i(GLuint index, GLint x, GLint y);
void glVertexAttribI3i(GLuint index, GLint x, GLint y, GLint z);
void glVertexAttribI4i(GLuint index, GLint x, GLint y, GLint z, GLint w);
void glVertexAttribI1ui(GLuint index, GLuint x);
void glVertexAttribI2ui(GLuint index, GLuint x, GLuint y);
void glVertexAttribI3ui(GLuint index, GLuint x, GLuint y, GLuint z);
void glVertexAttribI4ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
void glVertexAttribI1iv(GLuint index, GLint const  * v);
void glVertexAttribI2iv(GLuint index, GLint const  * v);
void glVertexAttribI3iv(GLuint index, GLint const  * v);
void glVertexAttribI4iv(GLuint index, GLint const  * v);
void glVertexAttribI1uiv(GLuint index, GLuint const  * v);
void glVertexAttribI2uiv(GLuint index, GLuint const  * v);
void glVertexAttribI3uiv(GLuint index, GLuint const  * v);
void glVertexAttribI4uiv(GLuint index, GLuint const  * v);
void glVertexAttribI4bv(GLuint index, GLbyte const  * v);
void glVertexAttribI4sv(GLuint index, GLshort const  * v);
void glVertexAttribI4ubv(GLuint index, GLubyte const  * v);
void glVertexAttribI4usv(GLuint index, GLushort const  * v);
void glGetUniformuiv(GLuint program, GLint location, GLuint * params);
void glBindFragDataLocation(GLuint program, GLuint color, GLchar const  * name);
GLint glGetFragDataLocation(GLuint program, GLchar const  * name);
void glUniform1ui(GLint location, GLuint v0);
void glUniform2ui(GLint location, GLuint v0, GLuint v1);
void glUniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2);
void glUniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
void glUniform1uiv(GLint location, GLsizei count, GLuint const  * value);
void glUniform2uiv(GLint location, GLsizei count, GLuint const  * value);
void glUniform3uiv(GLint location, GLsizei count, GLuint const  * value);
void glUniform4uiv(GLint location, GLsizei count, GLuint const  * value);
void glTexParameterIiv(GLenum target, GLenum pname, GLint const  * params);
void glTexParameterIuiv(GLenum target, GLenum pname, GLuint const  * params);
void glGetTexParameterIiv(GLenum target, GLenum pname, GLint * params);
void glGetTexParameterIuiv(GLenum target, GLenum pname, GLuint * params);
void glClearBufferiv(GLenum buffer, GLint drawbuffer, GLint const  * value);
void glClearBufferuiv(GLenum buffer, GLint drawbuffer, GLuint const  * value);
void glClearBufferfv(GLenum buffer, GLint drawbuffer, GLfloat const  * value);
void glClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
GLubyte const  * glGetStringi(GLenum name, GLuint index);
GLboolean glIsRenderbuffer(GLuint renderbuffer);
void glBindRenderbuffer(GLenum target, GLuint renderbuffer);
void glDeleteRenderbuffers(GLsizei n, GLuint const  * renderbuffers);
void glGenRenderbuffers(GLsizei n, GLuint * renderbuffers);
void glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
void glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint * params);
GLboolean glIsFramebuffer(GLuint framebuffer);
void glBindFramebuffer(GLenum target, GLuint framebuffer);
void glDeleteFramebuffers(GLsizei n, GLuint const  * framebuffers);
void glGenFramebuffers(GLsizei n, GLuint * framebuffers);
GLenum glCheckFramebufferStatus(GLenum target);
void glFramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
void glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
void glFramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
void glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
void glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint * params);
void glGenerateMipmap(GLenum target);
void glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
void glRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
void glFramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
void * glMapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
void glFlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length);
void glBindVertexArray(GLuint array);
void glDeleteVertexArrays(GLsizei n, GLuint const  * arrays);
void glGenVertexArrays(GLsizei n, GLuint * arrays);
GLboolean glIsVertexArray(GLuint array);
#endif /* GL_VERSION_3_0 */
#ifndef GL_ARB_ES2_compatibility
#define GL_ARB_ES2_compatibility 1
constexpr GLenum GL_FIXED = 0x140C;
constexpr GLenum GL_IMPLEMENTATION_COLOR_READ_TYPE = 0x8B9A;
constexpr GLenum GL_IMPLEMENTATION_COLOR_READ_FORMAT = 0x8B9B;
constexpr GLenum GL_LOW_FLOAT = 0x8DF0;
constexpr GLenum GL_MEDIUM_FLOAT = 0x8DF1;
constexpr GLenum GL_HIGH_FLOAT = 0x8DF2;
constexpr GLenum GL_LOW_INT = 0x8DF3;
constexpr GLenum GL_MEDIUM_INT = 0x8DF4;
constexpr GLenum GL_HIGH_INT = 0x8DF5;
constexpr GLenum GL_SHADER_COMPILER = 0x8DFA;
constexpr GLenum GL_SHADER_BINARY_FORMATS = 0x8DF8;
constexpr GLenum GL_NUM_SHADER_BINARY_FORMATS = 0x8DF9;
constexpr GLenum GL_MAX_VERTEX_UNIFORM_VECTORS = 0x8DFB;
constexpr GLenum GL_MAX_VARYING_VECTORS = 0x8DFC;
constexpr GLenum GL_MAX_FRAGMENT_UNIFORM_VECTORS = 0x8DFD;
constexpr GLenum GL_RGB565 = 0x8D62;
void glReleaseShaderCompiler();
void glShaderBinary(GLsizei count, GLuint const  * shaders, GLenum binaryformat, const void * binary, GLsizei length);
void glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint * range, GLint * precision);
void glDepthRangef(GLfloat n, GLfloat f);
void glClearDepthf(GLfloat d);
#endif /* GL_ARB_ES2_compatibility */
#ifndef GL_ARB_ES3_1_compatibility
#define GL_ARB_ES3_1_compatibility 1
void glMemoryBarrierByRegion(GLbitfield barriers);
#endif /* GL_ARB_ES3_1_compatibility */
#ifndef GL_ARB_ES3_2_compatibility
#define GL_ARB_ES3_2_compatibility 1
constexpr GLenum GL_PRIMITIVE_BOUNDING_BOX_ARB = 0x92BE;
constexpr GLenum GL_MULTISAMPLE_LINE_WIDTH_RANGE_ARB = 0x9381;
constexpr GLenum GL_MULTISAMPLE_LINE_WIDTH_GRANULARITY_ARB = 0x9382;
void glPrimitiveBoundingBoxARB(GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat minW, GLfloat maxX, GLfloat maxY, GLfloat maxZ, GLfloat maxW);
#endif /* GL_ARB_ES3_2_compatibility */
#ifndef GL_ARB_ES3_compatibility
#define GL_ARB_ES3_compatibility 1
constexpr GLenum GL_COMPRESSED_RGB8_ETC2 = 0x9274;
constexpr GLenum GL_COMPRESSED_SRGB8_ETC2 = 0x9275;
constexpr GLenum GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2 = 0x9276;
constexpr GLenum GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2 = 0x9277;
constexpr GLenum GL_COMPRESSED_RGBA8_ETC2_EAC = 0x9278;
constexpr GLenum GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC = 0x9279;
constexpr GLenum GL_COMPRESSED_R11_EAC = 0x9270;
constexpr GLenum GL_COMPRESSED_SIGNED_R11_EAC = 0x9271;
constexpr GLenum GL_COMPRESSED_RG11_EAC = 0x9272;
constexpr GLenum GL_COMPRESSED_SIGNED_RG11_EAC = 0x9273;
constexpr GLenum GL_PRIMITIVE_RESTART_FIXED_INDEX = 0x8D69;
constexpr GLenum GL_ANY_SAMPLES_PASSED_CONSERVATIVE = 0x8D6A;
constexpr GLenum GL_MAX_ELEMENT_INDEX = 0x8D6B;
#endif /* GL_ARB_ES3_compatibility */
#ifndef GL_ARB_arrays_of_arrays
#define GL_ARB_arrays_of_arrays 1
#endif /* GL_ARB_arrays_of_arrays */
#ifndef GL_ARB_base_instance
#define GL_ARB_base_instance 1
void glDrawArraysInstancedBaseInstance(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
void glDrawElementsInstancedBaseInstance(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLuint baseinstance);
void glDrawElementsInstancedBaseVertexBaseInstance(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
#endif /* GL_ARB_base_instance */
#ifndef GL_ARB_bindless_texture
#define GL_ARB_bindless_texture 1
constexpr GLenum GL_UNSIGNED_INT64_ARB = 0x140F;
GLuint64 glGetTextureHandleARB(GLuint texture);
GLuint64 glGetTextureSamplerHandleARB(GLuint texture, GLuint sampler);
void glMakeTextureHandleResidentARB(GLuint64 handle);
void glMakeTextureHandleNonResidentARB(GLuint64 handle);
GLuint64 glGetImageHandleARB(GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format);
void glMakeImageHandleResidentARB(GLuint64 handle, GLenum access);
void glMakeImageHandleNonResidentARB(GLuint64 handle);
void glUniformHandleui64ARB(GLint location, GLuint64 value);
void glUniformHandleui64vARB(GLint location, GLsizei count, GLuint64 const  * value);
void glProgramUniformHandleui64ARB(GLuint program, GLint location, GLuint64 value);
void glProgramUniformHandleui64vARB(GLuint program, GLint location, GLsizei count, GLuint64 const  * values);
GLboolean glIsTextureHandleResidentARB(GLuint64 handle);
GLboolean glIsImageHandleResidentARB(GLuint64 handle);
void glVertexAttribL1ui64ARB(GLuint index, GLuint64EXT x);
void glVertexAttribL1ui64vARB(GLuint index, GLuint64EXT const  * v);
void glGetVertexAttribLui64vARB(GLuint index, GLenum pname, GLuint64EXT * params);
#endif /* GL_ARB_bindless_texture */
#ifndef GL_ARB_blend_func_extended
#define GL_ARB_blend_func_extended 1
constexpr GLenum GL_SRC1_COLOR = 0x88F9;
constexpr GLenum GL_ONE_MINUS_SRC1_COLOR = 0x88FA;
constexpr GLenum GL_ONE_MINUS_SRC1_ALPHA = 0x88FB;
constexpr GLenum GL_MAX_DUAL_SOURCE_DRAW_BUFFERS = 0x88FC;
void glBindFragDataLocationIndexed(GLuint program, GLuint colorNumber, GLuint index, GLchar const  * name);
GLint glGetFragDataIndex(GLuint program, GLchar const  * name);
#endif /* GL_ARB_blend_func_extended */
#ifndef GL_ARB_buffer_storage
#define GL_ARB_buffer_storage 1
constexpr GLenum GL_MAP_PERSISTENT_BIT = 0x0040;
constexpr GLenum GL_MAP_COHERENT_BIT = 0x0080;
constexpr GLenum GL_DYNAMIC_STORAGE_BIT = 0x0100;
constexpr GLenum GL_CLIENT_STORAGE_BIT = 0x0200;
constexpr GLenum GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT = 0x00004000;
constexpr GLenum GL_BUFFER_IMMUTABLE_STORAGE = 0x821F;
constexpr GLenum GL_BUFFER_STORAGE_FLAGS = 0x8220;
void glBufferStorage(GLenum target, GLsizeiptr size, const void * data, GLbitfield flags);
#endif /* GL_ARB_buffer_storage */
#ifndef GL_ARB_cl_event
#define GL_ARB_cl_event 1
constexpr GLenum GL_SYNC_CL_EVENT_ARB = 0x8240;
constexpr GLenum GL_SYNC_CL_EVENT_COMPLETE_ARB = 0x8241;
GLsync glCreateSyncFromCLeventARB(struct _cl_context * context, struct _cl_event * event, GLbitfield flags);
#endif /* GL_ARB_cl_event */
#ifndef GL_ARB_clear_buffer_object
#define GL_ARB_clear_buffer_object 1
void glClearBufferData(GLenum target, GLenum internalformat, GLenum format, GLenum type, const void * data);
void glClearBufferSubData(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void * data);
#endif /* GL_ARB_clear_buffer_object */
#ifndef GL_ARB_clear_texture
#define GL_ARB_clear_texture 1
constexpr GLenum GL_CLEAR_TEXTURE = 0x9365;
void glClearTexImage(GLuint texture, GLint level, GLenum format, GLenum type, const void * data);
void glClearTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * data);
#endif /* GL_ARB_clear_texture */
#ifndef GL_ARB_clip_control
#define GL_ARB_clip_control 1
constexpr GLenum GL_NEGATIVE_ONE_TO_ONE = 0x935E;
constexpr GLenum GL_ZERO_TO_ONE = 0x935F;
constexpr GLenum GL_CLIP_ORIGIN = 0x935C;
constexpr GLenum GL_CLIP_DEPTH_MODE = 0x935D;
void glClipControl(GLenum origin, GLenum depth);
#endif /* GL_ARB_clip_control */
#ifndef GL_ARB_color_buffer_float
#define GL_ARB_color_buffer_float 1
constexpr GLenum GL_RGBA_FLOAT_MODE_ARB = 0x8820;
constexpr GLenum GL_CLAMP_VERTEX_COLOR_ARB = 0x891A;
constexpr GLenum GL_CLAMP_FRAGMENT_COLOR_ARB = 0x891B;
constexpr GLenum GL_CLAMP_READ_COLOR_ARB = 0x891C;
constexpr GLenum GL_FIXED_ONLY_ARB = 0x891D;
void glClampColorARB(GLenum target, GLenum clamp);
#endif /* GL_ARB_color_buffer_float */
#ifndef GL_ARB_compatibility
#define GL_ARB_compatibility 1
#endif /* GL_ARB_compatibility */
#ifndef GL_ARB_compressed_texture_pixel_storage
#define GL_ARB_compressed_texture_pixel_storage 1
constexpr GLenum GL_UNPACK_COMPRESSED_BLOCK_WIDTH = 0x9127;
constexpr GLenum GL_UNPACK_COMPRESSED_BLOCK_HEIGHT = 0x9128;
constexpr GLenum GL_UNPACK_COMPRESSED_BLOCK_DEPTH = 0x9129;
constexpr GLenum GL_UNPACK_COMPRESSED_BLOCK_SIZE = 0x912A;
constexpr GLenum GL_PACK_COMPRESSED_BLOCK_WIDTH = 0x912B;
constexpr GLenum GL_PACK_COMPRESSED_BLOCK_HEIGHT = 0x912C;
constexpr GLenum GL_PACK_COMPRESSED_BLOCK_DEPTH = 0x912D;
constexpr GLenum GL_PACK_COMPRESSED_BLOCK_SIZE = 0x912E;
#endif /* GL_ARB_compressed_texture_pixel_storage */
#ifndef GL_ARB_compute_shader
#define GL_ARB_compute_shader 1
constexpr GLenum GL_COMPUTE_SHADER = 0x91B9;
constexpr GLenum GL_MAX_COMPUTE_UNIFORM_BLOCKS = 0x91BB;
constexpr GLenum GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS = 0x91BC;
constexpr GLenum GL_MAX_COMPUTE_IMAGE_UNIFORMS = 0x91BD;
constexpr GLenum GL_MAX_COMPUTE_SHARED_MEMORY_SIZE = 0x8262;
constexpr GLenum GL_MAX_COMPUTE_UNIFORM_COMPONENTS = 0x8263;
constexpr GLenum GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS = 0x8264;
constexpr GLenum GL_MAX_COMPUTE_ATOMIC_COUNTERS = 0x8265;
constexpr GLenum GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS = 0x8266;
constexpr GLenum GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS = 0x90EB;
constexpr GLenum GL_MAX_COMPUTE_WORK_GROUP_COUNT = 0x91BE;
constexpr GLenum GL_MAX_COMPUTE_WORK_GROUP_SIZE = 0x91BF;
constexpr GLenum GL_COMPUTE_WORK_GROUP_SIZE = 0x8267;
constexpr GLenum GL_UNIFORM_BLOCK_REFERENCED_BY_COMPUTE_SHADER = 0x90EC;
constexpr GLenum GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_COMPUTE_SHADER = 0x90ED;
constexpr GLenum GL_DISPATCH_INDIRECT_BUFFER = 0x90EE;
constexpr GLenum GL_DISPATCH_INDIRECT_BUFFER_BINDING = 0x90EF;
constexpr GLenum GL_COMPUTE_SHADER_BIT = 0x00000020;
void glDispatchCompute(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
void glDispatchComputeIndirect(GLintptr indirect);
#endif /* GL_ARB_compute_shader */
#ifndef GL_ARB_compute_variable_group_size
#define GL_ARB_compute_variable_group_size 1
constexpr GLenum GL_MAX_COMPUTE_VARIABLE_GROUP_INVOCATIONS_ARB = 0x9344;
constexpr GLenum GL_MAX_COMPUTE_FIXED_GROUP_INVOCATIONS_ARB = 0x90EB;
constexpr GLenum GL_MAX_COMPUTE_VARIABLE_GROUP_SIZE_ARB = 0x9345;
constexpr GLenum GL_MAX_COMPUTE_FIXED_GROUP_SIZE_ARB = 0x91BF;
void glDispatchComputeGroupSizeARB(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z, GLuint group_size_x, GLuint group_size_y, GLuint group_size_z);
#endif /* GL_ARB_compute_variable_group_size */
#ifndef GL_ARB_conditional_render_inverted
#define GL_ARB_conditional_render_inverted 1
constexpr GLenum GL_QUERY_WAIT_INVERTED = 0x8E17;
constexpr GLenum GL_QUERY_NO_WAIT_INVERTED = 0x8E18;
constexpr GLenum GL_QUERY_BY_REGION_WAIT_INVERTED = 0x8E19;
constexpr GLenum GL_QUERY_BY_REGION_NO_WAIT_INVERTED = 0x8E1A;
#endif /* GL_ARB_conditional_render_inverted */
#ifndef GL_ARB_conservative_depth
#define GL_ARB_conservative_depth 1
#endif /* GL_ARB_conservative_depth */
#ifndef GL_ARB_copy_buffer
#define GL_ARB_copy_buffer 1
constexpr GLenum GL_COPY_READ_BUFFER = 0x8F36;
constexpr GLenum GL_COPY_WRITE_BUFFER = 0x8F37;
void glCopyBufferSubData(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
#endif /* GL_ARB_copy_buffer */
#ifndef GL_ARB_copy_image
#define GL_ARB_copy_image 1
void glCopyImageSubData(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
#endif /* GL_ARB_copy_image */
#ifndef GL_ARB_cull_distance
#define GL_ARB_cull_distance 1
constexpr GLenum GL_MAX_CULL_DISTANCES = 0x82F9;
constexpr GLenum GL_MAX_COMBINED_CLIP_AND_CULL_DISTANCES = 0x82FA;
#endif /* GL_ARB_cull_distance */
#ifndef GL_ARB_debug_output
#define GL_ARB_debug_output 1
constexpr GLenum GL_DEBUG_OUTPUT_SYNCHRONOUS_ARB = 0x8242;
constexpr GLenum GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH_ARB = 0x8243;
constexpr GLenum GL_DEBUG_CALLBACK_FUNCTION_ARB = 0x8244;
constexpr GLenum GL_DEBUG_CALLBACK_USER_PARAM_ARB = 0x8245;
constexpr GLenum GL_DEBUG_SOURCE_API_ARB = 0x8246;
constexpr GLenum GL_DEBUG_SOURCE_WINDOW_SYSTEM_ARB = 0x8247;
constexpr GLenum GL_DEBUG_SOURCE_SHADER_COMPILER_ARB = 0x8248;
constexpr GLenum GL_DEBUG_SOURCE_THIRD_PARTY_ARB = 0x8249;
constexpr GLenum GL_DEBUG_SOURCE_APPLICATION_ARB = 0x824A;
constexpr GLenum GL_DEBUG_SOURCE_OTHER_ARB = 0x824B;
constexpr GLenum GL_DEBUG_TYPE_ERROR_ARB = 0x824C;
constexpr GLenum GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR_ARB = 0x824D;
constexpr GLenum GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR_ARB = 0x824E;
constexpr GLenum GL_DEBUG_TYPE_PORTABILITY_ARB = 0x824F;
constexpr GLenum GL_DEBUG_TYPE_PERFORMANCE_ARB = 0x8250;
constexpr GLenum GL_DEBUG_TYPE_OTHER_ARB = 0x8251;
constexpr GLenum GL_MAX_DEBUG_MESSAGE_LENGTH_ARB = 0x9143;
constexpr GLenum GL_MAX_DEBUG_LOGGED_MESSAGES_ARB = 0x9144;
constexpr GLenum GL_DEBUG_LOGGED_MESSAGES_ARB = 0x9145;
constexpr GLenum GL_DEBUG_SEVERITY_HIGH_ARB = 0x9146;
constexpr GLenum GL_DEBUG_SEVERITY_MEDIUM_ARB = 0x9147;
constexpr GLenum GL_DEBUG_SEVERITY_LOW_ARB = 0x9148;
void glDebugMessageControlARB(GLenum source, GLenum type, GLenum severity, GLsizei count, GLuint const  * ids, GLboolean enabled);
void glDebugMessageInsertARB(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, GLchar const  * buf);
void glDebugMessageCallbackARB(GLDEBUGPROCARB callback, const void * userParam);
GLuint glGetDebugMessageLogARB(GLuint count, GLsizei bufSize, GLenum * sources, GLenum * types, GLuint * ids, GLenum * severities, GLsizei * lengths, GLchar * messageLog);
#endif /* GL_ARB_debug_output */
#ifndef GL_ARB_depth_buffer_float
#define GL_ARB_depth_buffer_float 1
#endif /* GL_ARB_depth_buffer_float */
#ifndef GL_ARB_depth_clamp
#define GL_ARB_depth_clamp 1
constexpr GLenum GL_DEPTH_CLAMP = 0x864F;
#endif /* GL_ARB_depth_clamp */
#ifndef GL_ARB_depth_texture
#define GL_ARB_depth_texture 1
constexpr GLenum GL_DEPTH_COMPONENT16_ARB = 0x81A5;
constexpr GLenum GL_DEPTH_COMPONENT24_ARB = 0x81A6;
constexpr GLenum GL_DEPTH_COMPONENT32_ARB = 0x81A7;
constexpr GLenum GL_TEXTURE_DEPTH_SIZE_ARB = 0x884A;
constexpr GLenum GL_DEPTH_TEXTURE_MODE_ARB = 0x884B;
#endif /* GL_ARB_depth_texture */
#ifndef GL_ARB_derivative_control
#define GL_ARB_derivative_control 1
#endif /* GL_ARB_derivative_control */
#ifndef GL_ARB_direct_state_access
#define GL_ARB_direct_state_access 1
constexpr GLenum GL_TEXTURE_TARGET = 0x1006;
constexpr GLenum GL_QUERY_TARGET = 0x82EA;
constexpr GLenum GL_TEXTURE_BINDING_2D_MULTISAMPLE = 0x9104;
constexpr GLenum GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY = 0x9105;
constexpr GLenum GL_TEXTURE_BINDING_BUFFER = 0x8C2C;
constexpr GLenum GL_TEXTURE_BINDING_CUBE_MAP_ARRAY = 0x900A;
constexpr GLenum GL_TEXTURE_BINDING_RECTANGLE = 0x84F6;
void glCreateTransformFeedbacks(GLsizei n, GLuint * ids);
void glTransformFeedbackBufferBase(GLuint xfb, GLuint index, GLuint buffer);
void glTransformFeedbackBufferRange(GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
void glGetTransformFeedbackiv(GLuint xfb, GLenum pname, GLint * param);
void glGetTransformFeedbacki_v(GLuint xfb, GLenum pname, GLuint index, GLint * param);
void glGetTransformFeedbacki64_v(GLuint xfb, GLenum pname, GLuint index, GLint64 * param);
void glCreateBuffers(GLsizei n, GLuint * buffers);
void glNamedBufferStorage(GLuint buffer, GLsizeiptr size, const void * data, GLbitfield flags);
void glNamedBufferData(GLuint buffer, GLsizeiptr size, const void * data, GLenum usage);
void glNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, const void * data);
void glCopyNamedBufferSubData(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
void glClearNamedBufferData(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void * data);
void glClearNamedBufferSubData(GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void * data);
void * glMapNamedBuffer(GLuint buffer, GLenum access);
void * glMapNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
GLboolean glUnmapNamedBuffer(GLuint buffer);
void glFlushMappedNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length);
void glGetNamedBufferParameteriv(GLuint buffer, GLenum pname, GLint * params);
void glGetNamedBufferParameteri64v(GLuint buffer, GLenum pname, GLint64 * params);
void glGetNamedBufferPointerv(GLuint buffer, GLenum pname, void ** params);
void glGetNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, void * data);
void glCreateFramebuffers(GLsizei n, GLuint * framebuffers);
void glNamedFramebufferRenderbuffer(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
void glNamedFramebufferParameteri(GLuint framebuffer, GLenum pname, GLint param);
void glNamedFramebufferTexture(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
void glNamedFramebufferTextureLayer(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
void glNamedFramebufferDrawBuffer(GLuint framebuffer, GLenum buf);
void glNamedFramebufferDrawBuffers(GLuint framebuffer, GLsizei n, GLenum const  * bufs);
void glNamedFramebufferReadBuffer(GLuint framebuffer, GLenum src);
void glInvalidateNamedFramebufferData(GLuint framebuffer, GLsizei numAttachments, GLenum const  * attachments);
void glInvalidateNamedFramebufferSubData(GLuint framebuffer, GLsizei numAttachments, GLenum const  * attachments, GLint x, GLint y, GLsizei width, GLsizei height);
void glClearNamedFramebufferiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLint const  * value);
void glClearNamedFramebufferuiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLuint const  * value);
void glClearNamedFramebufferfv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat const  * value);
void glClearNamedFramebufferfi(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
void glBlitNamedFramebuffer(GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
GLenum glCheckNamedFramebufferStatus(GLuint framebuffer, GLenum target);
void glGetNamedFramebufferParameteriv(GLuint framebuffer, GLenum pname, GLint * param);
void glGetNamedFramebufferAttachmentParameteriv(GLuint framebuffer, GLenum attachment, GLenum pname, GLint * params);
void glCreateRenderbuffers(GLsizei n, GLuint * renderbuffers);
void glNamedRenderbufferStorage(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
void glNamedRenderbufferStorageMultisample(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
void glGetNamedRenderbufferParameteriv(GLuint renderbuffer, GLenum pname, GLint * params);
void glCreateTextures(GLenum target, GLsizei n, GLuint * textures);
void glTextureBuffer(GLuint texture, GLenum internalformat, GLuint buffer);
void glTextureBufferRange(GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
void glTextureStorage1D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width);
void glTextureStorage2D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
void glTextureStorage3D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
void glTextureStorage2DMultisample(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
void glTextureStorage3DMultisample(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
void glTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void * pixels);
void glTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels);
void glTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels);
void glCompressedTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * data);
void glCompressedTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * data);
void glCompressedTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * data);
void glCopyTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
void glCopyTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
void glCopyTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
void glTextureParameterf(GLuint texture, GLenum pname, GLfloat param);
void glTextureParameterfv(GLuint texture, GLenum pname, GLfloat const  * param);
void glTextureParameteri(GLuint texture, GLenum pname, GLint param);
void glTextureParameterIiv(GLuint texture, GLenum pname, GLint const  * params);
void glTextureParameterIuiv(GLuint texture, GLenum pname, GLuint const  * params);
void glTextureParameteriv(GLuint texture, GLenum pname, GLint const  * param);
void glGenerateTextureMipmap(GLuint texture);
void glBindTextureUnit(GLuint unit, GLuint texture);
void glGetTextureImage(GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void * pixels);
void glGetCompressedTextureImage(GLuint texture, GLint level, GLsizei bufSize, void * pixels);
void glGetTextureLevelParameterfv(GLuint texture, GLint level, GLenum pname, GLfloat * params);
void glGetTextureLevelParameteriv(GLuint texture, GLint level, GLenum pname, GLint * params);
void glGetTextureParameterfv(GLuint texture, GLenum pname, GLfloat * params);
void glGetTextureParameterIiv(GLuint texture, GLenum pname, GLint * params);
void glGetTextureParameterIuiv(GLuint texture, GLenum pname, GLuint * params);
void glGetTextureParameteriv(GLuint texture, GLenum pname, GLint * params);
void glCreateVertexArrays(GLsizei n, GLuint * arrays);
void glDisableVertexArrayAttrib(GLuint vaobj, GLuint index);
void glEnableVertexArrayAttrib(GLuint vaobj, GLuint index);
void glVertexArrayElementBuffer(GLuint vaobj, GLuint buffer);
void glVertexArrayVertexBuffer(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
void glVertexArrayVertexBuffers(GLuint vaobj, GLuint first, GLsizei count, GLuint const  * buffers, GLintptr const  * offsets, GLsizei const  * strides);
void glVertexArrayAttribBinding(GLuint vaobj, GLuint attribindex, GLuint bindingindex);
void glVertexArrayAttribFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
void glVertexArrayAttribIFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
void glVertexArrayAttribLFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
void glVertexArrayBindingDivisor(GLuint vaobj, GLuint bindingindex, GLuint divisor);
void glGetVertexArrayiv(GLuint vaobj, GLenum pname, GLint * param);
void glGetVertexArrayIndexediv(GLuint vaobj, GLuint index, GLenum pname, GLint * param);
void glGetVertexArrayIndexed64iv(GLuint vaobj, GLuint index, GLenum pname, GLint64 * param);
void glCreateSamplers(GLsizei n, GLuint * samplers);
void glCreateProgramPipelines(GLsizei n, GLuint * pipelines);
void glCreateQueries(GLenum target, GLsizei n, GLuint * ids);
void glGetQueryBufferObjecti64v(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
void glGetQueryBufferObjectiv(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
void glGetQueryBufferObjectui64v(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
void glGetQueryBufferObjectuiv(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
#endif /* GL_ARB_direct_state_access */
#ifndef GL_ARB_draw_buffers
#define GL_ARB_draw_buffers 1
constexpr GLenum GL_MAX_DRAW_BUFFERS_ARB = 0x8824;
constexpr GLenum GL_DRAW_BUFFER0_ARB = 0x8825;
constexpr GLenum GL_DRAW_BUFFER1_ARB = 0x8826;
constexpr GLenum GL_DRAW_BUFFER2_ARB = 0x8827;
constexpr GLenum GL_DRAW_BUFFER3_ARB = 0x8828;
constexpr GLenum GL_DRAW_BUFFER4_ARB = 0x8829;
constexpr GLenum GL_DRAW_BUFFER5_ARB = 0x882A;
constexpr GLenum GL_DRAW_BUFFER6_ARB = 0x882B;
constexpr GLenum GL_DRAW_BUFFER7_ARB = 0x882C;
constexpr GLenum GL_DRAW_BUFFER8_ARB = 0x882D;
constexpr GLenum GL_DRAW_BUFFER9_ARB = 0x882E;
constexpr GLenum GL_DRAW_BUFFER10_ARB = 0x882F;
constexpr GLenum GL_DRAW_BUFFER11_ARB = 0x8830;
constexpr GLenum GL_DRAW_BUFFER12_ARB = 0x8831;
constexpr GLenum GL_DRAW_BUFFER13_ARB = 0x8832;
constexpr GLenum GL_DRAW_BUFFER14_ARB = 0x8833;
constexpr GLenum GL_DRAW_BUFFER15_ARB = 0x8834;
void glDrawBuffersARB(GLsizei n, GLenum const  * bufs);
#endif /* GL_ARB_draw_buffers */
#ifndef GL_ARB_draw_buffers_blend
#define GL_ARB_draw_buffers_blend 1
void glBlendEquationiARB(GLuint buf, GLenum mode);
void glBlendEquationSeparateiARB(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
void glBlendFunciARB(GLuint buf, GLenum src, GLenum dst);
void glBlendFuncSeparateiARB(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
#endif /* GL_ARB_draw_buffers_blend */
#ifndef GL_ARB_draw_elements_base_vertex
#define GL_ARB_draw_elements_base_vertex 1
void glDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, const void * indices, GLint basevertex);
void glDrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices, GLint basevertex);
void glDrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex);
void glMultiDrawElementsBaseVertex(GLenum mode, GLsizei const  * count, GLenum type, const void *const* indices, GLsizei drawcount, GLint const  * basevertex);
#endif /* GL_ARB_draw_elements_base_vertex */
#ifndef GL_ARB_draw_indirect
#define GL_ARB_draw_indirect 1
constexpr GLenum GL_DRAW_INDIRECT_BUFFER = 0x8F3F;
constexpr GLenum GL_DRAW_INDIRECT_BUFFER_BINDING = 0x8F43;
void glDrawArraysIndirect(GLenum mode, const void * indirect);
void glDrawElementsIndirect(GLenum mode, GLenum type, const void * indirect);
#endif /* GL_ARB_draw_indirect */
#ifndef GL_ARB_draw_instanced
#define GL_ARB_draw_instanced 1
void glDrawArraysInstancedARB(GLenum mode, GLint first, GLsizei count, GLsizei primcount);
void glDrawElementsInstancedARB(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei primcount);
#endif /* GL_ARB_draw_instanced */
#ifndef GL_ARB_enhanced_layouts
#define GL_ARB_enhanced_layouts 1
constexpr GLenum GL_LOCATION_COMPONENT = 0x934A;
constexpr GLenum GL_TRANSFORM_FEEDBACK_BUFFER_INDEX = 0x934B;
constexpr GLenum GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE = 0x934C;
#endif /* GL_ARB_enhanced_layouts */
#ifndef GL_ARB_explicit_attrib_location
#define GL_ARB_explicit_attrib_location 1
#endif /* GL_ARB_explicit_attrib_location */
#ifndef GL_ARB_explicit_uniform_location
#define GL_ARB_explicit_uniform_location 1
constexpr GLenum GL_MAX_UNIFORM_LOCATIONS = 0x826E;
#endif /* GL_ARB_explicit_uniform_location */
#ifndef GL_ARB_fragment_coord_conventions
#define GL_ARB_fragment_coord_conventions 1
#endif /* GL_ARB_fragment_coord_conventions */
#ifndef GL_ARB_fragment_layer_viewport
#define GL_ARB_fragment_layer_viewport 1
#endif /* GL_ARB_fragment_layer_viewport */
#ifndef GL_ARB_fragment_program
#define GL_ARB_fragment_program 1
constexpr GLenum GL_FRAGMENT_PROGRAM_ARB = 0x8804;
constexpr GLenum GL_PROGRAM_FORMAT_ASCII_ARB = 0x8875;
constexpr GLenum GL_PROGRAM_LENGTH_ARB = 0x8627;
constexpr GLenum GL_PROGRAM_FORMAT_ARB = 0x8876;
constexpr GLenum GL_PROGRAM_BINDING_ARB = 0x8677;
constexpr GLenum GL_PROGRAM_INSTRUCTIONS_ARB = 0x88A0;
constexpr GLenum GL_MAX_PROGRAM_INSTRUCTIONS_ARB = 0x88A1;
constexpr GLenum GL_PROGRAM_NATIVE_INSTRUCTIONS_ARB = 0x88A2;
constexpr GLenum GL_MAX_PROGRAM_NATIVE_INSTRUCTIONS_ARB = 0x88A3;
constexpr GLenum GL_PROGRAM_TEMPORARIES_ARB = 0x88A4;
constexpr GLenum GL_MAX_PROGRAM_TEMPORARIES_ARB = 0x88A5;
constexpr GLenum GL_PROGRAM_NATIVE_TEMPORARIES_ARB = 0x88A6;
constexpr GLenum GL_MAX_PROGRAM_NATIVE_TEMPORARIES_ARB = 0x88A7;
constexpr GLenum GL_PROGRAM_PARAMETERS_ARB = 0x88A8;
constexpr GLenum GL_MAX_PROGRAM_PARAMETERS_ARB = 0x88A9;
constexpr GLenum GL_PROGRAM_NATIVE_PARAMETERS_ARB = 0x88AA;
constexpr GLenum GL_MAX_PROGRAM_NATIVE_PARAMETERS_ARB = 0x88AB;
constexpr GLenum GL_PROGRAM_ATTRIBS_ARB = 0x88AC;
constexpr GLenum GL_MAX_PROGRAM_ATTRIBS_ARB = 0x88AD;
constexpr GLenum GL_PROGRAM_NATIVE_ATTRIBS_ARB = 0x88AE;
constexpr GLenum GL_MAX_PROGRAM_NATIVE_ATTRIBS_ARB = 0x88AF;
constexpr GLenum GL_MAX_PROGRAM_LOCAL_PARAMETERS_ARB = 0x88B4;
constexpr GLenum GL_MAX_PROGRAM_ENV_PARAMETERS_ARB = 0x88B5;
constexpr GLenum GL_PROGRAM_UNDER_NATIVE_LIMITS_ARB = 0x88B6;
constexpr GLenum GL_PROGRAM_ALU_INSTRUCTIONS_ARB = 0x8805;
constexpr GLenum GL_PROGRAM_TEX_INSTRUCTIONS_ARB = 0x8806;
constexpr GLenum GL_PROGRAM_TEX_INDIRECTIONS_ARB = 0x8807;
constexpr GLenum GL_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB = 0x8808;
constexpr GLenum GL_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB = 0x8809;
constexpr GLenum GL_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB = 0x880A;
constexpr GLenum GL_MAX_PROGRAM_ALU_INSTRUCTIONS_ARB = 0x880B;
constexpr GLenum GL_MAX_PROGRAM_TEX_INSTRUCTIONS_ARB = 0x880C;
constexpr GLenum GL_MAX_PROGRAM_TEX_INDIRECTIONS_ARB = 0x880D;
constexpr GLenum GL_MAX_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB = 0x880E;
constexpr GLenum GL_MAX_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB = 0x880F;
constexpr GLenum GL_MAX_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB = 0x8810;
constexpr GLenum GL_PROGRAM_STRING_ARB = 0x8628;
constexpr GLenum GL_PROGRAM_ERROR_POSITION_ARB = 0x864B;
constexpr GLenum GL_CURRENT_MATRIX_ARB = 0x8641;
constexpr GLenum GL_TRANSPOSE_CURRENT_MATRIX_ARB = 0x88B7;
constexpr GLenum GL_CURRENT_MATRIX_STACK_DEPTH_ARB = 0x8640;
constexpr GLenum GL_MAX_PROGRAM_MATRICES_ARB = 0x862F;
constexpr GLenum GL_MAX_PROGRAM_MATRIX_STACK_DEPTH_ARB = 0x862E;
constexpr GLenum GL_MAX_TEXTURE_COORDS_ARB = 0x8871;
constexpr GLenum GL_MAX_TEXTURE_IMAGE_UNITS_ARB = 0x8872;
constexpr GLenum GL_PROGRAM_ERROR_STRING_ARB = 0x8874;
constexpr GLenum GL_MATRIX0_ARB = 0x88C0;
constexpr GLenum GL_MATRIX1_ARB = 0x88C1;
constexpr GLenum GL_MATRIX2_ARB = 0x88C2;
constexpr GLenum GL_MATRIX3_ARB = 0x88C3;
constexpr GLenum GL_MATRIX4_ARB = 0x88C4;
constexpr GLenum GL_MATRIX5_ARB = 0x88C5;
constexpr GLenum GL_MATRIX6_ARB = 0x88C6;
constexpr GLenum GL_MATRIX7_ARB = 0x88C7;
constexpr GLenum GL_MATRIX8_ARB = 0x88C8;
constexpr GLenum GL_MATRIX9_ARB = 0x88C9;
constexpr GLenum GL_MATRIX10_ARB = 0x88CA;
constexpr GLenum GL_MATRIX11_ARB = 0x88CB;
constexpr GLenum GL_MATRIX12_ARB = 0x88CC;
constexpr GLenum GL_MATRIX13_ARB = 0x88CD;
constexpr GLenum GL_MATRIX14_ARB = 0x88CE;
constexpr GLenum GL_MATRIX15_ARB = 0x88CF;
constexpr GLenum GL_MATRIX16_ARB = 0x88D0;
constexpr GLenum GL_MATRIX17_ARB = 0x88D1;
constexpr GLenum GL_MATRIX18_ARB = 0x88D2;
constexpr GLenum GL_MATRIX19_ARB = 0x88D3;
constexpr GLenum GL_MATRIX20_ARB = 0x88D4;
constexpr GLenum GL_MATRIX21_ARB = 0x88D5;
constexpr GLenum GL_MATRIX22_ARB = 0x88D6;
constexpr GLenum GL_MATRIX23_ARB = 0x88D7;
constexpr GLenum GL_MATRIX24_ARB = 0x88D8;
constexpr GLenum GL_MATRIX25_ARB = 0x88D9;
constexpr GLenum GL_MATRIX26_ARB = 0x88DA;
constexpr GLenum GL_MATRIX27_ARB = 0x88DB;
constexpr GLenum GL_MATRIX28_ARB = 0x88DC;
constexpr GLenum GL_MATRIX29_ARB = 0x88DD;
constexpr GLenum GL_MATRIX30_ARB = 0x88DE;
constexpr GLenum GL_MATRIX31_ARB = 0x88DF;
void glProgramStringARB(GLenum target, GLenum format, GLsizei len, const void * string);
void glBindProgramARB(GLenum target, GLuint program);
void glDeleteProgramsARB(GLsizei n, GLuint const  * programs);
void glGenProgramsARB(GLsizei n, GLuint * programs);
void glProgramEnvParameter4dARB(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void glProgramEnvParameter4dvARB(GLenum target, GLuint index, GLdouble const  * params);
void glProgramEnvParameter4fARB(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void glProgramEnvParameter4fvARB(GLenum target, GLuint index, GLfloat const  * params);
void glProgramLocalParameter4dARB(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void glProgramLocalParameter4dvARB(GLenum target, GLuint index, GLdouble const  * params);
void glProgramLocalParameter4fARB(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void glProgramLocalParameter4fvARB(GLenum target, GLuint index, GLfloat const  * params);
void glGetProgramEnvParameterdvARB(GLenum target, GLuint index, GLdouble * params);
void glGetProgramEnvParameterfvARB(GLenum target, GLuint index, GLfloat * params);
void glGetProgramLocalParameterdvARB(GLenum target, GLuint index, GLdouble * params);
void glGetProgramLocalParameterfvARB(GLenum target, GLuint index, GLfloat * params);
void glGetProgramivARB(GLenum target, GLenum pname, GLint * params);
void glGetProgramStringARB(GLenum target, GLenum pname, void * string);
GLboolean glIsProgramARB(GLuint program);
#endif /* GL_ARB_fragment_program */
#ifndef GL_ARB_fragment_program_shadow
#define GL_ARB_fragment_program_shadow 1
#endif /* GL_ARB_fragment_program_shadow */
#ifndef GL_ARB_fragment_shader
#define GL_ARB_fragment_shader 1
constexpr GLenum GL_FRAGMENT_SHADER_ARB = 0x8B30;
constexpr GLenum GL_MAX_FRAGMENT_UNIFORM_COMPONENTS_ARB = 0x8B49;
constexpr GLenum GL_FRAGMENT_SHADER_DERIVATIVE_HINT_ARB = 0x8B8B;
#endif /* GL_ARB_fragment_shader */
#ifndef GL_ARB_fragment_shader_interlock
#define GL_ARB_fragment_shader_interlock 1
#endif /* GL_ARB_fragment_shader_interlock */
#ifndef GL_ARB_framebuffer_no_attachments
#define GL_ARB_framebuffer_no_attachments 1
constexpr GLenum GL_FRAMEBUFFER_DEFAULT_WIDTH = 0x9310;
constexpr GLenum GL_FRAMEBUFFER_DEFAULT_HEIGHT = 0x9311;
constexpr GLenum GL_FRAMEBUFFER_DEFAULT_LAYERS = 0x9312;
constexpr GLenum GL_FRAMEBUFFER_DEFAULT_SAMPLES = 0x9313;
constexpr GLenum GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS = 0x9314;
constexpr GLenum GL_MAX_FRAMEBUFFER_WIDTH = 0x9315;
constexpr GLenum GL_MAX_FRAMEBUFFER_HEIGHT = 0x9316;
constexpr GLenum GL_MAX_FRAMEBUFFER_LAYERS = 0x9317;
constexpr GLenum GL_MAX_FRAMEBUFFER_SAMPLES = 0x9318;
void glFramebufferParameteri(GLenum target, GLenum pname, GLint param);
void glGetFramebufferParameteriv(GLenum target, GLenum pname, GLint * params);
#endif /* GL_ARB_framebuffer_no_attachments */
#ifndef GL_ARB_framebuffer_object
#define GL_ARB_framebuffer_object 1
#endif /* GL_ARB_framebuffer_object */
#ifndef GL_ARB_framebuffer_sRGB
#define GL_ARB_framebuffer_sRGB 1
#endif /* GL_ARB_framebuffer_sRGB */
#ifndef GL_ARB_geometry_shader4
#define GL_ARB_geometry_shader4 1
constexpr GLenum GL_LINES_ADJACENCY_ARB = 0x000A;
constexpr GLenum GL_LINE_STRIP_ADJACENCY_ARB = 0x000B;
constexpr GLenum GL_TRIANGLES_ADJACENCY_ARB = 0x000C;
constexpr GLenum GL_TRIANGLE_STRIP_ADJACENCY_ARB = 0x000D;
constexpr GLenum GL_PROGRAM_POINT_SIZE_ARB = 0x8642;
constexpr GLenum GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_ARB = 0x8C29;
constexpr GLenum GL_FRAMEBUFFER_ATTACHMENT_LAYERED_ARB = 0x8DA7;
constexpr GLenum GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_ARB = 0x8DA8;
constexpr GLenum GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_ARB = 0x8DA9;
constexpr GLenum GL_GEOMETRY_SHADER_ARB = 0x8DD9;
constexpr GLenum GL_GEOMETRY_VERTICES_OUT_ARB = 0x8DDA;
constexpr GLenum GL_GEOMETRY_INPUT_TYPE_ARB = 0x8DDB;
constexpr GLenum GL_GEOMETRY_OUTPUT_TYPE_ARB = 0x8DDC;
constexpr GLenum GL_MAX_GEOMETRY_VARYING_COMPONENTS_ARB = 0x8DDD;
constexpr GLenum GL_MAX_VERTEX_VARYING_COMPONENTS_ARB = 0x8DDE;
constexpr GLenum GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_ARB = 0x8DDF;
constexpr GLenum GL_MAX_GEOMETRY_OUTPUT_VERTICES_ARB = 0x8DE0;
constexpr GLenum GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_ARB = 0x8DE1;
void glProgramParameteriARB(GLuint program, GLenum pname, GLint value);
void glFramebufferTextureARB(GLenum target, GLenum attachment, GLuint texture, GLint level);
void glFramebufferTextureLayerARB(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
void glFramebufferTextureFaceARB(GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face);
#endif /* GL_ARB_geometry_shader4 */
#ifndef GL_ARB_get_program_binary
#define GL_ARB_get_program_binary 1
constexpr GLenum GL_PROGRAM_BINARY_RETRIEVABLE_HINT = 0x8257;
constexpr GLenum GL_PROGRAM_BINARY_LENGTH = 0x8741;
constexpr GLenum GL_NUM_PROGRAM_BINARY_FORMATS = 0x87FE;
constexpr GLenum GL_PROGRAM_BINARY_FORMATS = 0x87FF;
void glGetProgramBinary(GLuint program, GLsizei bufSize, GLsizei * length, GLenum * binaryFormat, void * binary);
void glProgramBinary(GLuint program, GLenum binaryFormat, const void * binary, GLsizei length);
void glProgramParameteri(GLuint program, GLenum pname, GLint value);
#endif /* GL_ARB_get_program_binary */
#ifndef GL_ARB_get_texture_sub_image
#define GL_ARB_get_texture_sub_image 1
void glGetTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void * pixels);
void glGetCompressedTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void * pixels);
#endif /* GL_ARB_get_texture_sub_image */
#ifndef GL_ARB_gl_spirv
#define GL_ARB_gl_spirv 1
constexpr GLenum GL_SHADER_BINARY_FORMAT_SPIR_V_ARB = 0x9551;
constexpr GLenum GL_SPIR_V_BINARY_ARB = 0x9552;
void glSpecializeShaderARB(GLuint shader, GLchar const  * pEntryPoint, GLuint numSpecializationConstants, GLuint const  * pConstantIndex, GLuint const  * pConstantValue);
#endif /* GL_ARB_gl_spirv */
#ifndef GL_ARB_gpu_shader5
#define GL_ARB_gpu_shader5 1
constexpr GLenum GL_GEOMETRY_SHADER_INVOCATIONS = 0x887F;
constexpr GLenum GL_MAX_GEOMETRY_SHADER_INVOCATIONS = 0x8E5A;
constexpr GLenum GL_MIN_FRAGMENT_INTERPOLATION_OFFSET = 0x8E5B;
constexpr GLenum GL_MAX_FRAGMENT_INTERPOLATION_OFFSET = 0x8E5C;
constexpr GLenum GL_FRAGMENT_INTERPOLATION_OFFSET_BITS = 0x8E5D;
constexpr GLenum GL_MAX_VERTEX_STREAMS = 0x8E71;
#endif /* GL_ARB_gpu_shader5 */
#ifndef GL_ARB_gpu_shader_fp64
#define GL_ARB_gpu_shader_fp64 1
constexpr GLenum GL_DOUBLE_VEC2 = 0x8FFC;
constexpr GLenum GL_DOUBLE_VEC3 = 0x8FFD;
constexpr GLenum GL_DOUBLE_VEC4 = 0x8FFE;
constexpr GLenum GL_DOUBLE_MAT2 = 0x8F46;
constexpr GLenum GL_DOUBLE_MAT3 = 0x8F47;
constexpr GLenum GL_DOUBLE_MAT4 = 0x8F48;
constexpr GLenum GL_DOUBLE_MAT2x3 = 0x8F49;
constexpr GLenum GL_DOUBLE_MAT2x4 = 0x8F4A;
constexpr GLenum GL_DOUBLE_MAT3x2 = 0x8F4B;
constexpr GLenum GL_DOUBLE_MAT3x4 = 0x8F4C;
constexpr GLenum GL_DOUBLE_MAT4x2 = 0x8F4D;
constexpr GLenum GL_DOUBLE_MAT4x3 = 0x8F4E;
void glUniform1d(GLint location, GLdouble x);
void glUniform2d(GLint location, GLdouble x, GLdouble y);
void glUniform3d(GLint location, GLdouble x, GLdouble y, GLdouble z);
void glUniform4d(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void glUniform1dv(GLint location, GLsizei count, GLdouble const  * value);
void glUniform2dv(GLint location, GLsizei count, GLdouble const  * value);
void glUniform3dv(GLint location, GLsizei count, GLdouble const  * value);
void glUniform4dv(GLint location, GLsizei count, GLdouble const  * value);
void glUniformMatrix2dv(GLint location, GLsizei count, GLboolean transpose, GLdouble const  * value);
void glUniformMatrix3dv(GLint location, GLsizei count, GLboolean transpose, GLdouble const  * value);
void glUniformMatrix4dv(GLint location, GLsizei count, GLboolean transpose, GLdouble const  * value);
void glUniformMatrix2x3dv(GLint location, GLsizei count, GLboolean transpose, GLdouble const  * value);
void glUniformMatrix2x4dv(GLint location, GLsizei count, GLboolean transpose, GLdouble const  * value);
void glUniformMatrix3x2dv(GLint location, GLsizei count, GLboolean transpose, GLdouble const  * value);
void glUniformMatrix3x4dv(GLint location, GLsizei count, GLboolean transpose, GLdouble const  * value);
void glUniformMatrix4x2dv(GLint location, GLsizei count, GLboolean transpose, GLdouble const  * value);
void glUniformMatrix4x3dv(GLint location, GLsizei count, GLboolean transpose, GLdouble const  * value);
void glGetUniformdv(GLuint program, GLint location, GLdouble * params);
#endif /* GL_ARB_gpu_shader_fp64 */
#ifndef GL_ARB_gpu_shader_int64
#define GL_ARB_gpu_shader_int64 1
constexpr GLenum GL_INT64_ARB = 0x140E;
constexpr GLenum GL_INT64_VEC2_ARB = 0x8FE9;
constexpr GLenum GL_INT64_VEC3_ARB = 0x8FEA;
constexpr GLenum GL_INT64_VEC4_ARB = 0x8FEB;
constexpr GLenum GL_UNSIGNED_INT64_VEC2_ARB = 0x8FF5;
constexpr GLenum GL_UNSIGNED_INT64_VEC3_ARB = 0x8FF6;
constexpr GLenum GL_UNSIGNED_INT64_VEC4_ARB = 0x8FF7;
void glUniform1i64ARB(GLint location, GLint64 x);
void glUniform2i64ARB(GLint location, GLint64 x, GLint64 y);
void glUniform3i64ARB(GLint location, GLint64 x, GLint64 y, GLint64 z);
void glUniform4i64ARB(GLint location, GLint64 x, GLint64 y, GLint64 z, GLint64 w);
void glUniform1i64vARB(GLint location, GLsizei count, GLint64 const  * value);
void glUniform2i64vARB(GLint location, GLsizei count, GLint64 const  * value);
void glUniform3i64vARB(GLint location, GLsizei count, GLint64 const  * value);
void glUniform4i64vARB(GLint location, GLsizei count, GLint64 const  * value);
void glUniform1ui64ARB(GLint location, GLuint64 x);
void glUniform2ui64ARB(GLint location, GLuint64 x, GLuint64 y);
void glUniform3ui64ARB(GLint location, GLuint64 x, GLuint64 y, GLuint64 z);
void glUniform4ui64ARB(GLint location, GLuint64 x, GLuint64 y, GLuint64 z, GLuint64 w);
void glUniform1ui64vARB(GLint location, GLsizei count, GLuint64 const  * value);
void glUniform2ui64vARB(GLint location, GLsizei count, GLuint64 const  * value);
void glUniform3ui64vARB(GLint location, GLsizei count, GLuint64 const  * value);
void glUniform4ui64vARB(GLint location, GLsizei count, GLuint64 const  * value);
void glGetUniformi64vARB(GLuint program, GLint location, GLint64 * params);
void glGetUniformui64vARB(GLuint program, GLint location, GLuint64 * params);
void glGetnUniformi64vARB(GLuint program, GLint location, GLsizei bufSize, GLint64 * params);
void glGetnUniformui64vARB(GLuint program, GLint location, GLsizei bufSize, GLuint64 * params);
void glProgramUniform1i64ARB(GLuint program, GLint location, GLint64 x);
void glProgramUniform2i64ARB(GLuint program, GLint location, GLint64 x, GLint64 y);
void glProgramUniform3i64ARB(GLuint program, GLint location, GLint64 x, GLint64 y, GLint64 z);
void glProgramUniform4i64ARB(GLuint program, GLint location, GLint64 x, GLint64 y, GLint64 z, GLint64 w);
void glProgramUniform1i64vARB(GLuint program, GLint location, GLsizei count, GLint64 const  * value);
void glProgramUniform2i64vARB(GLuint program, GLint location, GLsizei count, GLint64 const  * value);
void glProgramUniform3i64vARB(GLuint program, GLint location, GLsizei count, GLint64 const  * value);
void glProgramUniform4i64vARB(GLuint program, GLint location, GLsizei count, GLint64 const  * value);
void glProgramUniform1ui64ARB(GLuint program, GLint location, GLuint64 x);
void glProgramUniform2ui64ARB(GLuint program, GLint location, GLuint64 x, GLuint64 y);
void glProgramUniform3ui64ARB(GLuint program, GLint location, GLuint64 x, GLuint64 y, GLuint64 z);
void glProgramUniform4ui64ARB(GLuint program, GLint location, GLuint64 x, GLuint64 y, GLuint64 z, GLuint64 w);
void glProgramUniform1ui64vARB(GLuint program, GLint location, GLsizei count, GLuint64 const  * value);
void glProgramUniform2ui64vARB(GLuint program, GLint location, GLsizei count, GLuint64 const  * value);
void glProgramUniform3ui64vARB(GLuint program, GLint location, GLsizei count, GLuint64 const  * value);
void glProgramUniform4ui64vARB(GLuint program, GLint location, GLsizei count, GLuint64 const  * value);
#endif /* GL_ARB_gpu_shader_int64 */
#ifndef GL_ARB_half_float_pixel
#define GL_ARB_half_float_pixel 1
constexpr GLenum GL_HALF_FLOAT_ARB = 0x140B;
#endif /* GL_ARB_half_float_pixel */
#ifndef GL_ARB_half_float_vertex
#define GL_ARB_half_float_vertex 1
#endif /* GL_ARB_half_float_vertex */
#ifndef GL_ARB_imaging
#define GL_ARB_imaging 1
constexpr GLenum GL_CONVOLUTION_1D = 0x8010;
constexpr GLenum GL_CONVOLUTION_2D = 0x8011;
constexpr GLenum GL_SEPARABLE_2D = 0x8012;
constexpr GLenum GL_CONVOLUTION_BORDER_MODE = 0x8013;
constexpr GLenum GL_CONVOLUTION_FILTER_SCALE = 0x8014;
constexpr GLenum GL_CONVOLUTION_FILTER_BIAS = 0x8015;
constexpr GLenum GL_REDUCE = 0x8016;
constexpr GLenum GL_CONVOLUTION_FORMAT = 0x8017;
constexpr GLenum GL_CONVOLUTION_WIDTH = 0x8018;
constexpr GLenum GL_CONVOLUTION_HEIGHT = 0x8019;
constexpr GLenum GL_MAX_CONVOLUTION_WIDTH = 0x801A;
constexpr GLenum GL_MAX_CONVOLUTION_HEIGHT = 0x801B;
constexpr GLenum GL_POST_CONVOLUTION_RED_SCALE = 0x801C;
constexpr GLenum GL_POST_CONVOLUTION_GREEN_SCALE = 0x801D;
constexpr GLenum GL_POST_CONVOLUTION_BLUE_SCALE = 0x801E;
constexpr GLenum GL_POST_CONVOLUTION_ALPHA_SCALE = 0x801F;
constexpr GLenum GL_POST_CONVOLUTION_RED_BIAS = 0x8020;
constexpr GLenum GL_POST_CONVOLUTION_GREEN_BIAS = 0x8021;
constexpr GLenum GL_POST_CONVOLUTION_BLUE_BIAS = 0x8022;
constexpr GLenum GL_POST_CONVOLUTION_ALPHA_BIAS = 0x8023;
constexpr GLenum GL_HISTOGRAM = 0x8024;
constexpr GLenum GL_PROXY_HISTOGRAM = 0x8025;
constexpr GLenum GL_HISTOGRAM_WIDTH = 0x8026;
constexpr GLenum GL_HISTOGRAM_FORMAT = 0x8027;
constexpr GLenum GL_HISTOGRAM_RED_SIZE = 0x8028;
constexpr GLenum GL_HISTOGRAM_GREEN_SIZE = 0x8029;
constexpr GLenum GL_HISTOGRAM_BLUE_SIZE = 0x802A;
constexpr GLenum GL_HISTOGRAM_ALPHA_SIZE = 0x802B;
constexpr GLenum GL_HISTOGRAM_LUMINANCE_SIZE = 0x802C;
constexpr GLenum GL_HISTOGRAM_SINK = 0x802D;
constexpr GLenum GL_MINMAX = 0x802E;
constexpr GLenum GL_MINMAX_FORMAT = 0x802F;
constexpr GLenum GL_MINMAX_SINK = 0x8030;
constexpr GLenum GL_TABLE_TOO_LARGE = 0x8031;
constexpr GLenum GL_COLOR_MATRIX = 0x80B1;
constexpr GLenum GL_COLOR_MATRIX_STACK_DEPTH = 0x80B2;
constexpr GLenum GL_MAX_COLOR_MATRIX_STACK_DEPTH = 0x80B3;
constexpr GLenum GL_POST_COLOR_MATRIX_RED_SCALE = 0x80B4;
constexpr GLenum GL_POST_COLOR_MATRIX_GREEN_SCALE = 0x80B5;
constexpr GLenum GL_POST_COLOR_MATRIX_BLUE_SCALE = 0x80B6;
constexpr GLenum GL_POST_COLOR_MATRIX_ALPHA_SCALE = 0x80B7;
constexpr GLenum GL_POST_COLOR_MATRIX_RED_BIAS = 0x80B8;
constexpr GLenum GL_POST_COLOR_MATRIX_GREEN_BIAS = 0x80B9;
constexpr GLenum GL_POST_COLOR_MATRIX_BLUE_BIAS = 0x80BA;
constexpr GLenum GL_POST_COLOR_MATRIX_ALPHA_BIAS = 0x80BB;
constexpr GLenum GL_COLOR_TABLE = 0x80D0;
constexpr GLenum GL_POST_CONVOLUTION_COLOR_TABLE = 0x80D1;
constexpr GLenum GL_POST_COLOR_MATRIX_COLOR_TABLE = 0x80D2;
constexpr GLenum GL_PROXY_COLOR_TABLE = 0x80D3;
constexpr GLenum GL_PROXY_POST_CONVOLUTION_COLOR_TABLE = 0x80D4;
constexpr GLenum GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE = 0x80D5;
constexpr GLenum GL_COLOR_TABLE_SCALE = 0x80D6;
constexpr GLenum GL_COLOR_TABLE_BIAS = 0x80D7;
constexpr GLenum GL_COLOR_TABLE_FORMAT = 0x80D8;
constexpr GLenum GL_COLOR_TABLE_WIDTH = 0x80D9;
constexpr GLenum GL_COLOR_TABLE_RED_SIZE = 0x80DA;
constexpr GLenum GL_COLOR_TABLE_GREEN_SIZE = 0x80DB;
constexpr GLenum GL_COLOR_TABLE_BLUE_SIZE = 0x80DC;
constexpr GLenum GL_COLOR_TABLE_ALPHA_SIZE = 0x80DD;
constexpr GLenum GL_COLOR_TABLE_LUMINANCE_SIZE = 0x80DE;
constexpr GLenum GL_COLOR_TABLE_INTENSITY_SIZE = 0x80DF;
constexpr GLenum GL_CONSTANT_BORDER = 0x8151;
constexpr GLenum GL_REPLICATE_BORDER = 0x8153;
constexpr GLenum GL_CONVOLUTION_BORDER_COLOR = 0x8154;
void glColorTable(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void * table);
void glColorTableParameterfv(GLenum target, GLenum pname, GLfloat const  * params);
void glColorTableParameteriv(GLenum target, GLenum pname, GLint const  * params);
void glCopyColorTable(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
void glGetColorTable(GLenum target, GLenum format, GLenum type, void * table);
void glGetColorTableParameterfv(GLenum target, GLenum pname, GLfloat * params);
void glGetColorTableParameteriv(GLenum target, GLenum pname, GLint * params);
void glColorSubTable(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const void * data);
void glCopyColorSubTable(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width);
void glConvolutionFilter1D(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void * image);
void glConvolutionFilter2D(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * image);
void glConvolutionParameterf(GLenum target, GLenum pname, GLfloat params);
void glConvolutionParameterfv(GLenum target, GLenum pname, GLfloat const  * params);
void glConvolutionParameteri(GLenum target, GLenum pname, GLint params);
void glConvolutionParameteriv(GLenum target, GLenum pname, GLint const  * params);
void glCopyConvolutionFilter1D(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
void glCopyConvolutionFilter2D(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height);
void glGetConvolutionFilter(GLenum target, GLenum format, GLenum type, void * image);
void glGetConvolutionParameterfv(GLenum target, GLenum pname, GLfloat * params);
void glGetConvolutionParameteriv(GLenum target, GLenum pname, GLint * params);
void glGetSeparableFilter(GLenum target, GLenum format, GLenum type, void * row, void * column, void * span);
void glSeparableFilter2D(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * row, const void * column);
void glGetHistogram(GLenum target, GLboolean reset, GLenum format, GLenum type, void * values);
void glGetHistogramParameterfv(GLenum target, GLenum pname, GLfloat * params);
void glGetHistogramParameteriv(GLenum target, GLenum pname, GLint * params);
void glGetMinmax(GLenum target, GLboolean reset, GLenum format, GLenum type, void * values);
void glGetMinmaxParameterfv(GLenum target, GLenum pname, GLfloat * params);
void glGetMinmaxParameteriv(GLenum target, GLenum pname, GLint * params);
void glHistogram(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink);
void glMinmax(GLenum target, GLenum internalformat, GLboolean sink);
void glResetHistogram(GLenum target);
void glResetMinmax(GLenum target);
#endif /* GL_ARB_imaging */
#ifndef GL_ARB_indirect_parameters
#define GL_ARB_indirect_parameters 1
constexpr GLenum GL_PARAMETER_BUFFER_ARB = 0x80EE;
constexpr GLenum GL_PARAMETER_BUFFER_BINDING_ARB = 0x80EF;
void glMultiDrawArraysIndirectCountARB(GLenum mode, const void * indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
void glMultiDrawElementsIndirectCountARB(GLenum mode, GLenum type, const void * indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
#endif /* GL_ARB_indirect_parameters */
#ifndef GL_ARB_instanced_arrays
#define GL_ARB_instanced_arrays 1
constexpr GLenum GL_VERTEX_ATTRIB_ARRAY_DIVISOR_ARB = 0x88FE;
void glVertexAttribDivisorARB(GLuint index, GLuint divisor);
#endif /* GL_ARB_instanced_arrays */
#ifndef GL_ARB_internalformat_query
#define GL_ARB_internalformat_query 1
constexpr GLenum GL_NUM_SAMPLE_COUNTS = 0x9380;
void glGetInternalformativ(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint * params);
#endif /* GL_ARB_internalformat_query */
#ifndef GL_ARB_internalformat_query2
#define GL_ARB_internalformat_query2 1
constexpr GLenum GL_IMAGE_FORMAT_COMPATIBILITY_TYPE = 0x90C7;
constexpr GLenum GL_TEXTURE_CUBE_MAP_ARRAY = 0x9009;
constexpr GLenum GL_TEXTURE_RECTANGLE = 0x84F5;
constexpr GLenum GL_TEXTURE_BUFFER = 0x8C2A;
constexpr GLenum GL_TEXTURE_2D_MULTISAMPLE = 0x9100;
constexpr GLenum GL_TEXTURE_2D_MULTISAMPLE_ARRAY = 0x9102;
constexpr GLenum GL_INTERNALFORMAT_SUPPORTED = 0x826F;
constexpr GLenum GL_INTERNALFORMAT_PREFERRED = 0x8270;
constexpr GLenum GL_INTERNALFORMAT_RED_SIZE = 0x8271;
constexpr GLenum GL_INTERNALFORMAT_GREEN_SIZE = 0x8272;
constexpr GLenum GL_INTERNALFORMAT_BLUE_SIZE = 0x8273;
constexpr GLenum GL_INTERNALFORMAT_ALPHA_SIZE = 0x8274;
constexpr GLenum GL_INTERNALFORMAT_DEPTH_SIZE = 0x8275;
constexpr GLenum GL_INTERNALFORMAT_STENCIL_SIZE = 0x8276;
constexpr GLenum GL_INTERNALFORMAT_SHARED_SIZE = 0x8277;
constexpr GLenum GL_INTERNALFORMAT_RED_TYPE = 0x8278;
constexpr GLenum GL_INTERNALFORMAT_GREEN_TYPE = 0x8279;
constexpr GLenum GL_INTERNALFORMAT_BLUE_TYPE = 0x827A;
constexpr GLenum GL_INTERNALFORMAT_ALPHA_TYPE = 0x827B;
constexpr GLenum GL_INTERNALFORMAT_DEPTH_TYPE = 0x827C;
constexpr GLenum GL_INTERNALFORMAT_STENCIL_TYPE = 0x827D;
constexpr GLenum GL_MAX_WIDTH = 0x827E;
constexpr GLenum GL_MAX_HEIGHT = 0x827F;
constexpr GLenum GL_MAX_DEPTH = 0x8280;
constexpr GLenum GL_MAX_LAYERS = 0x8281;
constexpr GLenum GL_MAX_COMBINED_DIMENSIONS = 0x8282;
constexpr GLenum GL_COLOR_COMPONENTS = 0x8283;
constexpr GLenum GL_DEPTH_COMPONENTS = 0x8284;
constexpr GLenum GL_STENCIL_COMPONENTS = 0x8285;
constexpr GLenum GL_COLOR_RENDERABLE = 0x8286;
constexpr GLenum GL_DEPTH_RENDERABLE = 0x8287;
constexpr GLenum GL_STENCIL_RENDERABLE = 0x8288;
constexpr GLenum GL_FRAMEBUFFER_RENDERABLE = 0x8289;
constexpr GLenum GL_FRAMEBUFFER_RENDERABLE_LAYERED = 0x828A;
constexpr GLenum GL_FRAMEBUFFER_BLEND = 0x828B;
constexpr GLenum GL_READ_PIXELS = 0x828C;
constexpr GLenum GL_READ_PIXELS_FORMAT = 0x828D;
constexpr GLenum GL_READ_PIXELS_TYPE = 0x828E;
constexpr GLenum GL_TEXTURE_IMAGE_FORMAT = 0x828F;
constexpr GLenum GL_TEXTURE_IMAGE_TYPE = 0x8290;
constexpr GLenum GL_GET_TEXTURE_IMAGE_FORMAT = 0x8291;
constexpr GLenum GL_GET_TEXTURE_IMAGE_TYPE = 0x8292;
constexpr GLenum GL_MIPMAP = 0x8293;
constexpr GLenum GL_MANUAL_GENERATE_MIPMAP = 0x8294;
constexpr GLenum GL_AUTO_GENERATE_MIPMAP = 0x8295;
constexpr GLenum GL_COLOR_ENCODING = 0x8296;
constexpr GLenum GL_SRGB_READ = 0x8297;
constexpr GLenum GL_SRGB_WRITE = 0x8298;
constexpr GLenum GL_SRGB_DECODE_ARB = 0x8299;
constexpr GLenum GL_FILTER = 0x829A;
constexpr GLenum GL_VERTEX_TEXTURE = 0x829B;
constexpr GLenum GL_TESS_CONTROL_TEXTURE = 0x829C;
constexpr GLenum GL_TESS_EVALUATION_TEXTURE = 0x829D;
constexpr GLenum GL_GEOMETRY_TEXTURE = 0x829E;
constexpr GLenum GL_FRAGMENT_TEXTURE = 0x829F;
constexpr GLenum GL_COMPUTE_TEXTURE = 0x82A0;
constexpr GLenum GL_TEXTURE_SHADOW = 0x82A1;
constexpr GLenum GL_TEXTURE_GATHER = 0x82A2;
constexpr GLenum GL_TEXTURE_GATHER_SHADOW = 0x82A3;
constexpr GLenum GL_SHADER_IMAGE_LOAD = 0x82A4;
constexpr GLenum GL_SHADER_IMAGE_STORE = 0x82A5;
constexpr GLenum GL_SHADER_IMAGE_ATOMIC = 0x82A6;
constexpr GLenum GL_IMAGE_TEXEL_SIZE = 0x82A7;
constexpr GLenum GL_IMAGE_COMPATIBILITY_CLASS = 0x82A8;
constexpr GLenum GL_IMAGE_PIXEL_FORMAT = 0x82A9;
constexpr GLenum GL_IMAGE_PIXEL_TYPE = 0x82AA;
constexpr GLenum GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST = 0x82AC;
constexpr GLenum GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST = 0x82AD;
constexpr GLenum GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE = 0x82AE;
constexpr GLenum GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE = 0x82AF;
constexpr GLenum GL_TEXTURE_COMPRESSED_BLOCK_WIDTH = 0x82B1;
constexpr GLenum GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT = 0x82B2;
constexpr GLenum GL_TEXTURE_COMPRESSED_BLOCK_SIZE = 0x82B3;
constexpr GLenum GL_CLEAR_BUFFER = 0x82B4;
constexpr GLenum GL_TEXTURE_VIEW = 0x82B5;
constexpr GLenum GL_VIEW_COMPATIBILITY_CLASS = 0x82B6;
constexpr GLenum GL_FULL_SUPPORT = 0x82B7;
constexpr GLenum GL_CAVEAT_SUPPORT = 0x82B8;
constexpr GLenum GL_IMAGE_CLASS_4_X_32 = 0x82B9;
constexpr GLenum GL_IMAGE_CLASS_2_X_32 = 0x82BA;
constexpr GLenum GL_IMAGE_CLASS_1_X_32 = 0x82BB;
constexpr GLenum GL_IMAGE_CLASS_4_X_16 = 0x82BC;
constexpr GLenum GL_IMAGE_CLASS_2_X_16 = 0x82BD;
constexpr GLenum GL_IMAGE_CLASS_1_X_16 = 0x82BE;
constexpr GLenum GL_IMAGE_CLASS_4_X_8 = 0x82BF;
constexpr GLenum GL_IMAGE_CLASS_2_X_8 = 0x82C0;
constexpr GLenum GL_IMAGE_CLASS_1_X_8 = 0x82C1;
constexpr GLenum GL_IMAGE_CLASS_11_11_10 = 0x82C2;
constexpr GLenum GL_IMAGE_CLASS_10_10_10_2 = 0x82C3;
constexpr GLenum GL_VIEW_CLASS_128_BITS = 0x82C4;
constexpr GLenum GL_VIEW_CLASS_96_BITS = 0x82C5;
constexpr GLenum GL_VIEW_CLASS_64_BITS = 0x82C6;
constexpr GLenum GL_VIEW_CLASS_48_BITS = 0x82C7;
constexpr GLenum GL_VIEW_CLASS_32_BITS = 0x82C8;
constexpr GLenum GL_VIEW_CLASS_24_BITS = 0x82C9;
constexpr GLenum GL_VIEW_CLASS_16_BITS = 0x82CA;
constexpr GLenum GL_VIEW_CLASS_8_BITS = 0x82CB;
constexpr GLenum GL_VIEW_CLASS_S3TC_DXT1_RGB = 0x82CC;
constexpr GLenum GL_VIEW_CLASS_S3TC_DXT1_RGBA = 0x82CD;
constexpr GLenum GL_VIEW_CLASS_S3TC_DXT3_RGBA = 0x82CE;
constexpr GLenum GL_VIEW_CLASS_S3TC_DXT5_RGBA = 0x82CF;
constexpr GLenum GL_VIEW_CLASS_RGTC1_RED = 0x82D0;
constexpr GLenum GL_VIEW_CLASS_RGTC2_RG = 0x82D1;
constexpr GLenum GL_VIEW_CLASS_BPTC_UNORM = 0x82D2;
constexpr GLenum GL_VIEW_CLASS_BPTC_FLOAT = 0x82D3;
constexpr GLenum GL_VIEW_CLASS_EAC_R11 = 0x9383;
constexpr GLenum GL_VIEW_CLASS_EAC_RG11 = 0x9384;
constexpr GLenum GL_VIEW_CLASS_ETC2_RGB = 0x9385;
constexpr GLenum GL_VIEW_CLASS_ETC2_RGBA = 0x9386;
constexpr GLenum GL_VIEW_CLASS_ETC2_EAC_RGBA = 0x9387;
constexpr GLenum GL_VIEW_CLASS_ASTC_4x4_RGBA = 0x9388;
constexpr GLenum GL_VIEW_CLASS_ASTC_5x4_RGBA = 0x9389;
constexpr GLenum GL_VIEW_CLASS_ASTC_5x5_RGBA = 0x938A;
constexpr GLenum GL_VIEW_CLASS_ASTC_6x5_RGBA = 0x938B;
constexpr GLenum GL_VIEW_CLASS_ASTC_6x6_RGBA = 0x938C;
constexpr GLenum GL_VIEW_CLASS_ASTC_8x5_RGBA = 0x938D;
constexpr GLenum GL_VIEW_CLASS_ASTC_8x6_RGBA = 0x938E;
constexpr GLenum GL_VIEW_CLASS_ASTC_8x8_RGBA = 0x938F;
constexpr GLenum GL_VIEW_CLASS_ASTC_10x5_RGBA = 0x9390;
constexpr GLenum GL_VIEW_CLASS_ASTC_10x6_RGBA = 0x9391;
constexpr GLenum GL_VIEW_CLASS_ASTC_10x8_RGBA = 0x9392;
constexpr GLenum GL_VIEW_CLASS_ASTC_10x10_RGBA = 0x9393;
constexpr GLenum GL_VIEW_CLASS_ASTC_12x10_RGBA = 0x9394;
constexpr GLenum GL_VIEW_CLASS_ASTC_12x12_RGBA = 0x9395;
void glGetInternalformati64v(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint64 * params);
#endif /* GL_ARB_internalformat_query2 */
#ifndef GL_ARB_invalidate_subdata
#define GL_ARB_invalidate_subdata 1
void glInvalidateTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);
void glInvalidateTexImage(GLuint texture, GLint level);
void glInvalidateBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr length);
void glInvalidateBufferData(GLuint buffer);
void glInvalidateFramebuffer(GLenum target, GLsizei numAttachments, GLenum const  * attachments);
void glInvalidateSubFramebuffer(GLenum target, GLsizei numAttachments, GLenum const  * attachments, GLint x, GLint y, GLsizei width, GLsizei height);
#endif /* GL_ARB_invalidate_subdata */
#ifndef GL_ARB_map_buffer_alignment
#define GL_ARB_map_buffer_alignment 1
constexpr GLenum GL_MIN_MAP_BUFFER_ALIGNMENT = 0x90BC;
#endif /* GL_ARB_map_buffer_alignment */
#ifndef GL_ARB_map_buffer_range
#define GL_ARB_map_buffer_range 1
#endif /* GL_ARB_map_buffer_range */
#ifndef GL_ARB_matrix_palette
#define GL_ARB_matrix_palette 1
constexpr GLenum GL_MATRIX_PALETTE_ARB = 0x8840;
constexpr GLenum GL_MAX_MATRIX_PALETTE_STACK_DEPTH_ARB = 0x8841;
constexpr GLenum GL_MAX_PALETTE_MATRICES_ARB = 0x8842;
constexpr GLenum GL_CURRENT_PALETTE_MATRIX_ARB = 0x8843;
constexpr GLenum GL_MATRIX_INDEX_ARRAY_ARB = 0x8844;
constexpr GLenum GL_CURRENT_MATRIX_INDEX_ARB = 0x8845;
constexpr GLenum GL_MATRIX_INDEX_ARRAY_SIZE_ARB = 0x8846;
constexpr GLenum GL_MATRIX_INDEX_ARRAY_TYPE_ARB = 0x8847;
constexpr GLenum GL_MATRIX_INDEX_ARRAY_STRIDE_ARB = 0x8848;
constexpr GLenum GL_MATRIX_INDEX_ARRAY_POINTER_ARB = 0x8849;
void glCurrentPaletteMatrixARB(GLint index);
void glMatrixIndexubvARB(GLint size, GLubyte const  * indices);
void glMatrixIndexusvARB(GLint size, GLushort const  * indices);
void glMatrixIndexuivARB(GLint size, GLuint const  * indices);
void glMatrixIndexPointerARB(GLint size, GLenum type, GLsizei stride, const void * pointer);
#endif /* GL_ARB_matrix_palette */
#ifndef GL_ARB_multi_bind
#define GL_ARB_multi_bind 1
void glBindBuffersBase(GLenum target, GLuint first, GLsizei count, GLuint const  * buffers);
void glBindBuffersRange(GLenum target, GLuint first, GLsizei count, GLuint const  * buffers, GLintptr const  * offsets, GLsizeiptr const  * sizes);
void glBindTextures(GLuint first, GLsizei count, GLuint const  * textures);
void glBindSamplers(GLuint first, GLsizei count, GLuint const  * samplers);
void glBindImageTextures(GLuint first, GLsizei count, GLuint const  * textures);
void glBindVertexBuffers(GLuint first, GLsizei count, GLuint const  * buffers, GLintptr const  * offsets, GLsizei const  * strides);
#endif /* GL_ARB_multi_bind */
#ifndef GL_ARB_multi_draw_indirect
#define GL_ARB_multi_draw_indirect 1
void glMultiDrawArraysIndirect(GLenum mode, const void * indirect, GLsizei drawcount, GLsizei stride);
void glMultiDrawElementsIndirect(GLenum mode, GLenum type, const void * indirect, GLsizei drawcount, GLsizei stride);
#endif /* GL_ARB_multi_draw_indirect */
#ifndef GL_ARB_multisample
#define GL_ARB_multisample 1
constexpr GLenum GL_MULTISAMPLE_ARB = 0x809D;
constexpr GLenum GL_SAMPLE_ALPHA_TO_COVERAGE_ARB = 0x809E;
constexpr GLenum GL_SAMPLE_ALPHA_TO_ONE_ARB = 0x809F;
constexpr GLenum GL_SAMPLE_COVERAGE_ARB = 0x80A0;
constexpr GLenum GL_SAMPLE_BUFFERS_ARB = 0x80A8;
constexpr GLenum GL_SAMPLES_ARB = 0x80A9;
constexpr GLenum GL_SAMPLE_COVERAGE_VALUE_ARB = 0x80AA;
constexpr GLenum GL_SAMPLE_COVERAGE_INVERT_ARB = 0x80AB;
constexpr GLenum GL_MULTISAMPLE_BIT_ARB = 0x20000000;
void glSampleCoverageARB(GLfloat value, GLboolean invert);
#endif /* GL_ARB_multisample */
#ifndef GL_ARB_multitexture
#define GL_ARB_multitexture 1
constexpr GLenum GL_TEXTURE0_ARB = 0x84C0;
constexpr GLenum GL_TEXTURE1_ARB = 0x84C1;
constexpr GLenum GL_TEXTURE2_ARB = 0x84C2;
constexpr GLenum GL_TEXTURE3_ARB = 0x84C3;
constexpr GLenum GL_TEXTURE4_ARB = 0x84C4;
constexpr GLenum GL_TEXTURE5_ARB = 0x84C5;
constexpr GLenum GL_TEXTURE6_ARB = 0x84C6;
constexpr GLenum GL_TEXTURE7_ARB = 0x84C7;
constexpr GLenum GL_TEXTURE8_ARB = 0x84C8;
constexpr GLenum GL_TEXTURE9_ARB = 0x84C9;
constexpr GLenum GL_TEXTURE10_ARB = 0x84CA;
constexpr GLenum GL_TEXTURE11_ARB = 0x84CB;
constexpr GLenum GL_TEXTURE12_ARB = 0x84CC;
constexpr GLenum GL_TEXTURE13_ARB = 0x84CD;
constexpr GLenum GL_TEXTURE14_ARB = 0x84CE;
constexpr GLenum GL_TEXTURE15_ARB = 0x84CF;
constexpr GLenum GL_TEXTURE16_ARB = 0x84D0;
constexpr GLenum GL_TEXTURE17_ARB = 0x84D1;
constexpr GLenum GL_TEXTURE18_ARB = 0x84D2;
constexpr GLenum GL_TEXTURE19_ARB = 0x84D3;
constexpr GLenum GL_TEXTURE20_ARB = 0x84D4;
constexpr GLenum GL_TEXTURE21_ARB = 0x84D5;
constexpr GLenum GL_TEXTURE22_ARB = 0x84D6;
constexpr GLenum GL_TEXTURE23_ARB = 0x84D7;
constexpr GLenum GL_TEXTURE24_ARB = 0x84D8;
constexpr GLenum GL_TEXTURE25_ARB = 0x84D9;
constexpr GLenum GL_TEXTURE26_ARB = 0x84DA;
constexpr GLenum GL_TEXTURE27_ARB = 0x84DB;
constexpr GLenum GL_TEXTURE28_ARB = 0x84DC;
constexpr GLenum GL_TEXTURE29_ARB = 0x84DD;
constexpr GLenum GL_TEXTURE30_ARB = 0x84DE;
constexpr GLenum GL_TEXTURE31_ARB = 0x84DF;
constexpr GLenum GL_ACTIVE_TEXTURE_ARB = 0x84E0;
constexpr GLenum GL_CLIENT_ACTIVE_TEXTURE_ARB = 0x84E1;
constexpr GLenum GL_MAX_TEXTURE_UNITS_ARB = 0x84E2;
void glActiveTextureARB(GLenum texture);
void glClientActiveTextureARB(GLenum texture);
void glMultiTexCoord1dARB(GLenum target, GLdouble s);
void glMultiTexCoord1dvARB(GLenum target, GLdouble const  * v);
void glMultiTexCoord1fARB(GLenum target, GLfloat s);
void glMultiTexCoord1fvARB(GLenum target, GLfloat const  * v);
void glMultiTexCoord1iARB(GLenum target, GLint s);
void glMultiTexCoord1ivARB(GLenum target, GLint const  * v);
void glMultiTexCoord1sARB(GLenum target, GLshort s);
void glMultiTexCoord1svARB(GLenum target, GLshort const  * v);
void glMultiTexCoord2dARB(GLenum target, GLdouble s, GLdouble t);
void glMultiTexCoord2dvARB(GLenum target, GLdouble const  * v);
void glMultiTexCoord2fARB(GLenum target, GLfloat s, GLfloat t);
void glMultiTexCoord2fvARB(GLenum target, GLfloat const  * v);
void glMultiTexCoord2iARB(GLenum target, GLint s, GLint t);
void glMultiTexCoord2ivARB(GLenum target, GLint const  * v);
void glMultiTexCoord2sARB(GLenum target, GLshort s, GLshort t);
void glMultiTexCoord2svARB(GLenum target, GLshort const  * v);
void glMultiTexCoord3dARB(GLenum target, GLdouble s, GLdouble t, GLdouble r);
void glMultiTexCoord3dvARB(GLenum target, GLdouble const  * v);
void glMultiTexCoord3fARB(GLenum target, GLfloat s, GLfloat t, GLfloat r);
void glMultiTexCoord3fvARB(GLenum target, GLfloat const  * v);
void glMultiTexCoord3iARB(GLenum target, GLint s, GLint t, GLint r);
void glMultiTexCoord3ivARB(GLenum target, GLint const  * v);
void glMultiTexCoord3sARB(GLenum target, GLshort s, GLshort t, GLshort r);
void glMultiTexCoord3svARB(GLenum target, GLshort const  * v);
void glMultiTexCoord4dARB(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
void glMultiTexCoord4dvARB(GLenum target, GLdouble const  * v);
void glMultiTexCoord4fARB(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
void glMultiTexCoord4fvARB(GLenum target, GLfloat const  * v);
void glMultiTexCoord4iARB(GLenum target, GLint s, GLint t, GLint r, GLint q);
void glMultiTexCoord4ivARB(GLenum target, GLint const  * v);
void glMultiTexCoord4sARB(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
void glMultiTexCoord4svARB(GLenum target, GLshort const  * v);
#endif /* GL_ARB_multitexture */
#ifndef GL_ARB_occlusion_query
#define GL_ARB_occlusion_query 1
constexpr GLenum GL_QUERY_COUNTER_BITS_ARB = 0x8864;
constexpr GLenum GL_CURRENT_QUERY_ARB = 0x8865;
constexpr GLenum GL_QUERY_RESULT_ARB = 0x8866;
constexpr GLenum GL_QUERY_RESULT_AVAILABLE_ARB = 0x8867;
constexpr GLenum GL_SAMPLES_PASSED_ARB = 0x8914;
void glGenQueriesARB(GLsizei n, GLuint * ids);
void glDeleteQueriesARB(GLsizei n, GLuint const  * ids);
GLboolean glIsQueryARB(GLuint id);
void glBeginQueryARB(GLenum target, GLuint id);
void glEndQueryARB(GLenum target);
void glGetQueryivARB(GLenum target, GLenum pname, GLint * params);
void glGetQueryObjectivARB(GLuint id, GLenum pname, GLint * params);
void glGetQueryObjectuivARB(GLuint id, GLenum pname, GLuint * params);
#endif /* GL_ARB_occlusion_query */
#ifndef GL_ARB_occlusion_query2
#define GL_ARB_occlusion_query2 1
constexpr GLenum GL_ANY_SAMPLES_PASSED = 0x8C2F;
#endif /* GL_ARB_occlusion_query2 */
#ifndef GL_ARB_parallel_shader_compile
#define GL_ARB_parallel_shader_compile 1
constexpr GLenum GL_MAX_SHADER_COMPILER_THREADS_ARB = 0x91B0;
constexpr GLenum GL_COMPLETION_STATUS_ARB = 0x91B1;
void glMaxShaderCompilerThreadsARB(GLuint count);
#endif /* GL_ARB_parallel_shader_compile */
#ifndef GL_ARB_pipeline_statistics_query
#define GL_ARB_pipeline_statistics_query 1
constexpr GLenum GL_VERTICES_SUBMITTED_ARB = 0x82EE;
constexpr GLenum GL_PRIMITIVES_SUBMITTED_ARB = 0x82EF;
constexpr GLenum GL_VERTEX_SHADER_INVOCATIONS_ARB = 0x82F0;
constexpr GLenum GL_TESS_CONTROL_SHADER_PATCHES_ARB = 0x82F1;
constexpr GLenum GL_TESS_EVALUATION_SHADER_INVOCATIONS_ARB = 0x82F2;
constexpr GLenum GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED_ARB = 0x82F3;
constexpr GLenum GL_FRAGMENT_SHADER_INVOCATIONS_ARB = 0x82F4;
constexpr GLenum GL_COMPUTE_SHADER_INVOCATIONS_ARB = 0x82F5;
constexpr GLenum GL_CLIPPING_INPUT_PRIMITIVES_ARB = 0x82F6;
constexpr GLenum GL_CLIPPING_OUTPUT_PRIMITIVES_ARB = 0x82F7;
#endif /* GL_ARB_pipeline_statistics_query */
#ifndef GL_ARB_pixel_buffer_object
#define GL_ARB_pixel_buffer_object 1
constexpr GLenum GL_PIXEL_PACK_BUFFER_ARB = 0x88EB;
constexpr GLenum GL_PIXEL_UNPACK_BUFFER_ARB = 0x88EC;
constexpr GLenum GL_PIXEL_PACK_BUFFER_BINDING_ARB = 0x88ED;
constexpr GLenum GL_PIXEL_UNPACK_BUFFER_BINDING_ARB = 0x88EF;
#endif /* GL_ARB_pixel_buffer_object */
#ifndef GL_ARB_point_parameters
#define GL_ARB_point_parameters 1
constexpr GLenum GL_POINT_SIZE_MIN_ARB = 0x8126;
constexpr GLenum GL_POINT_SIZE_MAX_ARB = 0x8127;
constexpr GLenum GL_POINT_FADE_THRESHOLD_SIZE_ARB = 0x8128;
constexpr GLenum GL_POINT_DISTANCE_ATTENUATION_ARB = 0x8129;
void glPointParameterfARB(GLenum pname, GLfloat param);
void glPointParameterfvARB(GLenum pname, GLfloat const  * params);
#endif /* GL_ARB_point_parameters */
#ifndef GL_ARB_point_sprite
#define GL_ARB_point_sprite 1
constexpr GLenum GL_POINT_SPRITE_ARB = 0x8861;
constexpr GLenum GL_COORD_REPLACE_ARB = 0x8862;
#endif /* GL_ARB_point_sprite */
#ifndef GL_ARB_polygon_offset_clamp
#define GL_ARB_polygon_offset_clamp 1
constexpr GLenum GL_POLYGON_OFFSET_CLAMP = 0x8E1B;
void glPolygonOffsetClamp(GLfloat factor, GLfloat units, GLfloat clamp);
#endif /* GL_ARB_polygon_offset_clamp */
#ifndef GL_ARB_post_depth_coverage
#define GL_ARB_post_depth_coverage 1
#endif /* GL_ARB_post_depth_coverage */
#ifndef GL_ARB_program_interface_query
#define GL_ARB_program_interface_query 1
constexpr GLenum GL_UNIFORM = 0x92E1;
constexpr GLenum GL_UNIFORM_BLOCK = 0x92E2;
constexpr GLenum GL_PROGRAM_INPUT = 0x92E3;
constexpr GLenum GL_PROGRAM_OUTPUT = 0x92E4;
constexpr GLenum GL_BUFFER_VARIABLE = 0x92E5;
constexpr GLenum GL_SHADER_STORAGE_BLOCK = 0x92E6;
constexpr GLenum GL_ATOMIC_COUNTER_BUFFER = 0x92C0;
constexpr GLenum GL_VERTEX_SUBROUTINE = 0x92E8;
constexpr GLenum GL_TESS_CONTROL_SUBROUTINE = 0x92E9;
constexpr GLenum GL_TESS_EVALUATION_SUBROUTINE = 0x92EA;
constexpr GLenum GL_GEOMETRY_SUBROUTINE = 0x92EB;
constexpr GLenum GL_FRAGMENT_SUBROUTINE = 0x92EC;
constexpr GLenum GL_COMPUTE_SUBROUTINE = 0x92ED;
constexpr GLenum GL_VERTEX_SUBROUTINE_UNIFORM = 0x92EE;
constexpr GLenum GL_TESS_CONTROL_SUBROUTINE_UNIFORM = 0x92EF;
constexpr GLenum GL_TESS_EVALUATION_SUBROUTINE_UNIFORM = 0x92F0;
constexpr GLenum GL_GEOMETRY_SUBROUTINE_UNIFORM = 0x92F1;
constexpr GLenum GL_FRAGMENT_SUBROUTINE_UNIFORM = 0x92F2;
constexpr GLenum GL_COMPUTE_SUBROUTINE_UNIFORM = 0x92F3;
constexpr GLenum GL_TRANSFORM_FEEDBACK_VARYING = 0x92F4;
constexpr GLenum GL_ACTIVE_RESOURCES = 0x92F5;
constexpr GLenum GL_MAX_NAME_LENGTH = 0x92F6;
constexpr GLenum GL_MAX_NUM_ACTIVE_VARIABLES = 0x92F7;
constexpr GLenum GL_MAX_NUM_COMPATIBLE_SUBROUTINES = 0x92F8;
constexpr GLenum GL_NAME_LENGTH = 0x92F9;
constexpr GLenum GL_TYPE = 0x92FA;
constexpr GLenum GL_ARRAY_SIZE = 0x92FB;
constexpr GLenum GL_OFFSET = 0x92FC;
constexpr GLenum GL_BLOCK_INDEX = 0x92FD;
constexpr GLenum GL_ARRAY_STRIDE = 0x92FE;
constexpr GLenum GL_MATRIX_STRIDE = 0x92FF;
constexpr GLenum GL_IS_ROW_MAJOR = 0x9300;
constexpr GLenum GL_ATOMIC_COUNTER_BUFFER_INDEX = 0x9301;
constexpr GLenum GL_BUFFER_BINDING = 0x9302;
constexpr GLenum GL_BUFFER_DATA_SIZE = 0x9303;
constexpr GLenum GL_NUM_ACTIVE_VARIABLES = 0x9304;
constexpr GLenum GL_ACTIVE_VARIABLES = 0x9305;
constexpr GLenum GL_REFERENCED_BY_VERTEX_SHADER = 0x9306;
constexpr GLenum GL_REFERENCED_BY_TESS_CONTROL_SHADER = 0x9307;
constexpr GLenum GL_REFERENCED_BY_TESS_EVALUATION_SHADER = 0x9308;
constexpr GLenum GL_REFERENCED_BY_GEOMETRY_SHADER = 0x9309;
constexpr GLenum GL_REFERENCED_BY_FRAGMENT_SHADER = 0x930A;
constexpr GLenum GL_REFERENCED_BY_COMPUTE_SHADER = 0x930B;
constexpr GLenum GL_TOP_LEVEL_ARRAY_SIZE = 0x930C;
constexpr GLenum GL_TOP_LEVEL_ARRAY_STRIDE = 0x930D;
constexpr GLenum GL_LOCATION = 0x930E;
constexpr GLenum GL_LOCATION_INDEX = 0x930F;
constexpr GLenum GL_IS_PER_PATCH = 0x92E7;
constexpr GLenum GL_NUM_COMPATIBLE_SUBROUTINES = 0x8E4A;
constexpr GLenum GL_COMPATIBLE_SUBROUTINES = 0x8E4B;
void glGetProgramInterfaceiv(GLuint program, GLenum programInterface, GLenum pname, GLint * params);
GLuint glGetProgramResourceIndex(GLuint program, GLenum programInterface, GLchar const  * name);
void glGetProgramResourceName(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei * length, GLchar * name);
void glGetProgramResourceiv(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, GLenum const  * props, GLsizei count, GLsizei * length, GLint * params);
GLint glGetProgramResourceLocation(GLuint program, GLenum programInterface, GLchar const  * name);
GLint glGetProgramResourceLocationIndex(GLuint program, GLenum programInterface, GLchar const  * name);
#endif /* GL_ARB_program_interface_query */
#ifndef GL_ARB_provoking_vertex
#define GL_ARB_provoking_vertex 1
constexpr GLenum GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION = 0x8E4C;
constexpr GLenum GL_FIRST_VERTEX_CONVENTION = 0x8E4D;
constexpr GLenum GL_LAST_VERTEX_CONVENTION = 0x8E4E;
constexpr GLenum GL_PROVOKING_VERTEX = 0x8E4F;
void glProvokingVertex(GLenum mode);
#endif /* GL_ARB_provoking_vertex */
#ifndef GL_ARB_query_buffer_object
#define GL_ARB_query_buffer_object 1
constexpr GLenum GL_QUERY_BUFFER = 0x9192;
constexpr GLenum GL_QUERY_BUFFER_BARRIER_BIT = 0x00008000;
constexpr GLenum GL_QUERY_BUFFER_BINDING = 0x9193;
constexpr GLenum GL_QUERY_RESULT_NO_WAIT = 0x9194;
#endif /* GL_ARB_query_buffer_object */
#ifndef GL_ARB_robust_buffer_access_behavior
#define GL_ARB_robust_buffer_access_behavior 1
#endif /* GL_ARB_robust_buffer_access_behavior */
#ifndef GL_ARB_robustness
#define GL_ARB_robustness 1
constexpr GLenum GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT_ARB = 0x00000004;
constexpr GLenum GL_LOSE_CONTEXT_ON_RESET_ARB = 0x8252;
constexpr GLenum GL_GUILTY_CONTEXT_RESET_ARB = 0x8253;
constexpr GLenum GL_INNOCENT_CONTEXT_RESET_ARB = 0x8254;
constexpr GLenum GL_UNKNOWN_CONTEXT_RESET_ARB = 0x8255;
constexpr GLenum GL_RESET_NOTIFICATION_STRATEGY_ARB = 0x8256;
constexpr GLenum GL_NO_RESET_NOTIFICATION_ARB = 0x8261;
GLenum glGetGraphicsResetStatusARB();
void glGetnTexImageARB(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void * img);
void glReadnPixelsARB(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void * data);
void glGetnCompressedTexImageARB(GLenum target, GLint lod, GLsizei bufSize, void * img);
void glGetnUniformfvARB(GLuint program, GLint location, GLsizei bufSize, GLfloat * params);
void glGetnUniformivARB(GLuint program, GLint location, GLsizei bufSize, GLint * params);
void glGetnUniformuivARB(GLuint program, GLint location, GLsizei bufSize, GLuint * params);
void glGetnUniformdvARB(GLuint program, GLint location, GLsizei bufSize, GLdouble * params);
void glGetnMapdvARB(GLenum target, GLenum query, GLsizei bufSize, GLdouble * v);
void glGetnMapfvARB(GLenum target, GLenum query, GLsizei bufSize, GLfloat * v);
void glGetnMapivARB(GLenum target, GLenum query, GLsizei bufSize, GLint * v);
void glGetnPixelMapfvARB(GLenum map, GLsizei bufSize, GLfloat * values);
void glGetnPixelMapuivARB(GLenum map, GLsizei bufSize, GLuint * values);
void glGetnPixelMapusvARB(GLenum map, GLsizei bufSize, GLushort * values);
void glGetnPolygonStippleARB(GLsizei bufSize, GLubyte * pattern);
void glGetnColorTableARB(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void * table);
void glGetnConvolutionFilterARB(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void * image);
void glGetnSeparableFilterARB(GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, void * row, GLsizei columnBufSize, void * column, void * span);
void glGetnHistogramARB(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void * values);
void glGetnMinmaxARB(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void * values);
#endif /* GL_ARB_robustness */
#ifndef GL_ARB_robustness_isolation
#define GL_ARB_robustness_isolation 1
#endif /* GL_ARB_robustness_isolation */
#ifndef GL_ARB_sample_locations
#define GL_ARB_sample_locations 1
constexpr GLenum GL_SAMPLE_LOCATION_SUBPIXEL_BITS_ARB = 0x933D;
constexpr GLenum GL_SAMPLE_LOCATION_PIXEL_GRID_WIDTH_ARB = 0x933E;
constexpr GLenum GL_SAMPLE_LOCATION_PIXEL_GRID_HEIGHT_ARB = 0x933F;
constexpr GLenum GL_PROGRAMMABLE_SAMPLE_LOCATION_TABLE_SIZE_ARB = 0x9340;
constexpr GLenum GL_SAMPLE_LOCATION_ARB = 0x8E50;
constexpr GLenum GL_PROGRAMMABLE_SAMPLE_LOCATION_ARB = 0x9341;
constexpr GLenum GL_FRAMEBUFFER_PROGRAMMABLE_SAMPLE_LOCATIONS_ARB = 0x9342;
constexpr GLenum GL_FRAMEBUFFER_SAMPLE_LOCATION_PIXEL_GRID_ARB = 0x9343;
void glFramebufferSampleLocationsfvARB(GLenum target, GLuint start, GLsizei count, GLfloat const  * v);
void glNamedFramebufferSampleLocationsfvARB(GLuint framebuffer, GLuint start, GLsizei count, GLfloat const  * v);
void glEvaluateDepthValuesARB();
#endif /* GL_ARB_sample_locations */
#ifndef GL_ARB_sample_shading
#define GL_ARB_sample_shading 1
constexpr GLenum GL_SAMPLE_SHADING_ARB = 0x8C36;
constexpr GLenum GL_MIN_SAMPLE_SHADING_VALUE_ARB = 0x8C37;
void glMinSampleShadingARB(GLfloat value);
#endif /* GL_ARB_sample_shading */
#ifndef GL_ARB_sampler_objects
#define GL_ARB_sampler_objects 1
constexpr GLenum GL_SAMPLER_BINDING = 0x8919;
void glGenSamplers(GLsizei count, GLuint * samplers);
void glDeleteSamplers(GLsizei count, GLuint const  * samplers);
GLboolean glIsSampler(GLuint sampler);
void glBindSampler(GLuint unit, GLuint sampler);
void glSamplerParameteri(GLuint sampler, GLenum pname, GLint param);
void glSamplerParameteriv(GLuint sampler, GLenum pname, GLint const  * param);
void glSamplerParameterf(GLuint sampler, GLenum pname, GLfloat param);
void glSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat const  * param);
void glSamplerParameterIiv(GLuint sampler, GLenum pname, GLint const  * param);
void glSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint const  * param);
void glGetSamplerParameteriv(GLuint sampler, GLenum pname, GLint * params);
void glGetSamplerParameterIiv(GLuint sampler, GLenum pname, GLint * params);
void glGetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat * params);
void glGetSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint * params);
#endif /* GL_ARB_sampler_objects */
#ifndef GL_ARB_seamless_cube_map
#define GL_ARB_seamless_cube_map 1
constexpr GLenum GL_TEXTURE_CUBE_MAP_SEAMLESS = 0x884F;
#endif /* GL_ARB_seamless_cube_map */
#ifndef GL_ARB_seamless_cubemap_per_texture
#define GL_ARB_seamless_cubemap_per_texture 1
#endif /* GL_ARB_seamless_cubemap_per_texture */
#ifndef GL_ARB_separate_shader_objects
#define GL_ARB_separate_shader_objects 1
constexpr GLenum GL_VERTEX_SHADER_BIT = 0x00000001;
constexpr GLenum GL_FRAGMENT_SHADER_BIT = 0x00000002;
constexpr GLenum GL_GEOMETRY_SHADER_BIT = 0x00000004;
constexpr GLenum GL_TESS_CONTROL_SHADER_BIT = 0x00000008;
constexpr GLenum GL_TESS_EVALUATION_SHADER_BIT = 0x00000010;
constexpr GLenum GL_ALL_SHADER_BITS = 0xFFFFFFFF;
constexpr GLenum GL_PROGRAM_SEPARABLE = 0x8258;
constexpr GLenum GL_ACTIVE_PROGRAM = 0x8259;
constexpr GLenum GL_PROGRAM_PIPELINE_BINDING = 0x825A;
void glUseProgramStages(GLuint pipeline, GLbitfield stages, GLuint program);
void glActiveShaderProgram(GLuint pipeline, GLuint program);
GLuint glCreateShaderProgramv(GLenum type, GLsizei count, GLchar const  *const* strings);
void glBindProgramPipeline(GLuint pipeline);
void glDeleteProgramPipelines(GLsizei n, GLuint const  * pipelines);
void glGenProgramPipelines(GLsizei n, GLuint * pipelines);
GLboolean glIsProgramPipeline(GLuint pipeline);
void glGetProgramPipelineiv(GLuint pipeline, GLenum pname, GLint * params);
void glProgramUniform1i(GLuint program, GLint location, GLint v0);
void glProgramUniform1iv(GLuint program, GLint location, GLsizei count, GLint const  * value);
void glProgramUniform1f(GLuint program, GLint location, GLfloat v0);
void glProgramUniform1fv(GLuint program, GLint location, GLsizei count, GLfloat const  * value);
void glProgramUniform1d(GLuint program, GLint location, GLdouble v0);
void glProgramUniform1dv(GLuint program, GLint location, GLsizei count, GLdouble const  * value);
void glProgramUniform1ui(GLuint program, GLint location, GLuint v0);
void glProgramUniform1uiv(GLuint program, GLint location, GLsizei count, GLuint const  * value);
void glProgramUniform2i(GLuint program, GLint location, GLint v0, GLint v1);
void glProgramUniform2iv(GLuint program, GLint location, GLsizei count, GLint const  * value);
void glProgramUniform2f(GLuint program, GLint location, GLfloat v0, GLfloat v1);
void glProgramUniform2fv(GLuint program, GLint location, GLsizei count, GLfloat const  * value);
void glProgramUniform2d(GLuint program, GLint location, GLdouble v0, GLdouble v1);
void glProgramUniform2dv(GLuint program, GLint location, GLsizei count, GLdouble const  * value);
void glProgramUniform2ui(GLuint program, GLint location, GLuint v0, GLuint v1);
void glProgramUniform2uiv(GLuint program, GLint location, GLsizei count, GLuint const  * value);
void glProgramUniform3i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
void glProgramUniform3iv(GLuint program, GLint location, GLsizei count, GLint const  * value);
void glProgramUniform3f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
void glProgramUniform3fv(GLuint program, GLint location, GLsizei count, GLfloat const  * value);
void glProgramUniform3d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2);
void glProgramUniform3dv(GLuint program, GLint location, GLsizei count, GLdouble const  * value);
void glProgramUniform3ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
void glProgramUniform3uiv(GLuint program, GLint location, GLsizei count, GLuint const  * value);
void glProgramUniform4i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
void glProgramUniform4iv(GLuint program, GLint location, GLsizei count, GLint const  * value);
void glProgramUniform4f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
void glProgramUniform4fv(GLuint program, GLint location, GLsizei count, GLfloat const  * value);
void glProgramUniform4d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
void glProgramUniform4dv(GLuint program, GLint location, GLsizei count, GLdouble const  * value);
void glProgramUniform4ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
void glProgramUniform4uiv(GLuint program, GLint location, GLsizei count, GLuint const  * value);
void glProgramUniformMatrix2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value);
void glProgramUniformMatrix3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value);
void glProgramUniformMatrix4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value);
void glProgramUniformMatrix2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble const  * value);
void glProgramUniformMatrix3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble const  * value);
void glProgramUniformMatrix4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble const  * value);
void glProgramUniformMatrix2x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value);
void glProgramUniformMatrix3x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value);
void glProgramUniformMatrix2x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value);
void glProgramUniformMatrix4x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value);
void glProgramUniformMatrix3x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value);
void glProgramUniformMatrix4x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value);
void glProgramUniformMatrix2x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble const  * value);
void glProgramUniformMatrix3x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble const  * value);
void glProgramUniformMatrix2x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble const  * value);
void glProgramUniformMatrix4x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble const  * value);
void glProgramUniformMatrix3x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble const  * value);
void glProgramUniformMatrix4x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble const  * value);
void glValidateProgramPipeline(GLuint pipeline);
void glGetProgramPipelineInfoLog(GLuint pipeline, GLsizei bufSize, GLsizei * length, GLchar * infoLog);
#endif /* GL_ARB_separate_shader_objects */
#ifndef GL_ARB_shader_atomic_counter_ops
#define GL_ARB_shader_atomic_counter_ops 1
#endif /* GL_ARB_shader_atomic_counter_ops */
#ifndef GL_ARB_shader_atomic_counters
#define GL_ARB_shader_atomic_counters 1
constexpr GLenum GL_ATOMIC_COUNTER_BUFFER_BINDING = 0x92C1;
constexpr GLenum GL_ATOMIC_COUNTER_BUFFER_START = 0x92C2;
constexpr GLenum GL_ATOMIC_COUNTER_BUFFER_SIZE = 0x92C3;
constexpr GLenum GL_ATOMIC_COUNTER_BUFFER_DATA_SIZE = 0x92C4;
constexpr GLenum GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTERS = 0x92C5;
constexpr GLenum GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTER_INDICES = 0x92C6;
constexpr GLenum GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_VERTEX_SHADER = 0x92C7;
constexpr GLenum GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_CONTROL_SHADER = 0x92C8;
constexpr GLenum GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_EVALUATION_SHADER = 0x92C9;
constexpr GLenum GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_GEOMETRY_SHADER = 0x92CA;
constexpr GLenum GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_FRAGMENT_SHADER = 0x92CB;
constexpr GLenum GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS = 0x92CC;
constexpr GLenum GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS = 0x92CD;
constexpr GLenum GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS = 0x92CE;
constexpr GLenum GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS = 0x92CF;
constexpr GLenum GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS = 0x92D0;
constexpr GLenum GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS = 0x92D1;
constexpr GLenum GL_MAX_VERTEX_ATOMIC_COUNTERS = 0x92D2;
constexpr GLenum GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS = 0x92D3;
constexpr GLenum GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS = 0x92D4;
constexpr GLenum GL_MAX_GEOMETRY_ATOMIC_COUNTERS = 0x92D5;
constexpr GLenum GL_MAX_FRAGMENT_ATOMIC_COUNTERS = 0x92D6;
constexpr GLenum GL_MAX_COMBINED_ATOMIC_COUNTERS = 0x92D7;
constexpr GLenum GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE = 0x92D8;
constexpr GLenum GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS = 0x92DC;
constexpr GLenum GL_ACTIVE_ATOMIC_COUNTER_BUFFERS = 0x92D9;
constexpr GLenum GL_UNIFORM_ATOMIC_COUNTER_BUFFER_INDEX = 0x92DA;
constexpr GLenum GL_UNSIGNED_INT_ATOMIC_COUNTER = 0x92DB;
void glGetActiveAtomicCounterBufferiv(GLuint program, GLuint bufferIndex, GLenum pname, GLint * params);
#endif /* GL_ARB_shader_atomic_counters */
#ifndef GL_ARB_shader_ballot
#define GL_ARB_shader_ballot 1
#endif /* GL_ARB_shader_ballot */
#ifndef GL_ARB_shader_bit_encoding
#define GL_ARB_shader_bit_encoding 1
#endif /* GL_ARB_shader_bit_encoding */
#ifndef GL_ARB_shader_clock
#define GL_ARB_shader_clock 1
#endif /* GL_ARB_shader_clock */
#ifndef GL_ARB_shader_draw_parameters
#define GL_ARB_shader_draw_parameters 1
#endif /* GL_ARB_shader_draw_parameters */
#ifndef GL_ARB_shader_group_vote
#define GL_ARB_shader_group_vote 1
#endif /* GL_ARB_shader_group_vote */
#ifndef GL_ARB_shader_image_load_store
#define GL_ARB_shader_image_load_store 1
constexpr GLenum GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT = 0x00000001;
constexpr GLenum GL_ELEMENT_ARRAY_BARRIER_BIT = 0x00000002;
constexpr GLenum GL_UNIFORM_BARRIER_BIT = 0x00000004;
constexpr GLenum GL_TEXTURE_FETCH_BARRIER_BIT = 0x00000008;
constexpr GLenum GL_SHADER_IMAGE_ACCESS_BARRIER_BIT = 0x00000020;
constexpr GLenum GL_COMMAND_BARRIER_BIT = 0x00000040;
constexpr GLenum GL_PIXEL_BUFFER_BARRIER_BIT = 0x00000080;
constexpr GLenum GL_TEXTURE_UPDATE_BARRIER_BIT = 0x00000100;
constexpr GLenum GL_BUFFER_UPDATE_BARRIER_BIT = 0x00000200;
constexpr GLenum GL_FRAMEBUFFER_BARRIER_BIT = 0x00000400;
constexpr GLenum GL_TRANSFORM_FEEDBACK_BARRIER_BIT = 0x00000800;
constexpr GLenum GL_ATOMIC_COUNTER_BARRIER_BIT = 0x00001000;
constexpr GLenum GL_ALL_BARRIER_BITS = 0xFFFFFFFF;
constexpr GLenum GL_MAX_IMAGE_UNITS = 0x8F38;
constexpr GLenum GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS = 0x8F39;
constexpr GLenum GL_IMAGE_BINDING_NAME = 0x8F3A;
constexpr GLenum GL_IMAGE_BINDING_LEVEL = 0x8F3B;
constexpr GLenum GL_IMAGE_BINDING_LAYERED = 0x8F3C;
constexpr GLenum GL_IMAGE_BINDING_LAYER = 0x8F3D;
constexpr GLenum GL_IMAGE_BINDING_ACCESS = 0x8F3E;
constexpr GLenum GL_IMAGE_1D = 0x904C;
constexpr GLenum GL_IMAGE_2D = 0x904D;
constexpr GLenum GL_IMAGE_3D = 0x904E;
constexpr GLenum GL_IMAGE_2D_RECT = 0x904F;
constexpr GLenum GL_IMAGE_CUBE = 0x9050;
constexpr GLenum GL_IMAGE_BUFFER = 0x9051;
constexpr GLenum GL_IMAGE_1D_ARRAY = 0x9052;
constexpr GLenum GL_IMAGE_2D_ARRAY = 0x9053;
constexpr GLenum GL_IMAGE_CUBE_MAP_ARRAY = 0x9054;
constexpr GLenum GL_IMAGE_2D_MULTISAMPLE = 0x9055;
constexpr GLenum GL_IMAGE_2D_MULTISAMPLE_ARRAY = 0x9056;
constexpr GLenum GL_INT_IMAGE_1D = 0x9057;
constexpr GLenum GL_INT_IMAGE_2D = 0x9058;
constexpr GLenum GL_INT_IMAGE_3D = 0x9059;
constexpr GLenum GL_INT_IMAGE_2D_RECT = 0x905A;
constexpr GLenum GL_INT_IMAGE_CUBE = 0x905B;
constexpr GLenum GL_INT_IMAGE_BUFFER = 0x905C;
constexpr GLenum GL_INT_IMAGE_1D_ARRAY = 0x905D;
constexpr GLenum GL_INT_IMAGE_2D_ARRAY = 0x905E;
constexpr GLenum GL_INT_IMAGE_CUBE_MAP_ARRAY = 0x905F;
constexpr GLenum GL_INT_IMAGE_2D_MULTISAMPLE = 0x9060;
constexpr GLenum GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY = 0x9061;
constexpr GLenum GL_UNSIGNED_INT_IMAGE_1D = 0x9062;
constexpr GLenum GL_UNSIGNED_INT_IMAGE_2D = 0x9063;
constexpr GLenum GL_UNSIGNED_INT_IMAGE_3D = 0x9064;
constexpr GLenum GL_UNSIGNED_INT_IMAGE_2D_RECT = 0x9065;
constexpr GLenum GL_UNSIGNED_INT_IMAGE_CUBE = 0x9066;
constexpr GLenum GL_UNSIGNED_INT_IMAGE_BUFFER = 0x9067;
constexpr GLenum GL_UNSIGNED_INT_IMAGE_1D_ARRAY = 0x9068;
constexpr GLenum GL_UNSIGNED_INT_IMAGE_2D_ARRAY = 0x9069;
constexpr GLenum GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY = 0x906A;
constexpr GLenum GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE = 0x906B;
constexpr GLenum GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY = 0x906C;
constexpr GLenum GL_MAX_IMAGE_SAMPLES = 0x906D;
constexpr GLenum GL_IMAGE_BINDING_FORMAT = 0x906E;
constexpr GLenum GL_IMAGE_FORMAT_COMPATIBILITY_BY_SIZE = 0x90C8;
constexpr GLenum GL_IMAGE_FORMAT_COMPATIBILITY_BY_CLASS = 0x90C9;
constexpr GLenum GL_MAX_VERTEX_IMAGE_UNIFORMS = 0x90CA;
constexpr GLenum GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS = 0x90CB;
constexpr GLenum GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS = 0x90CC;
constexpr GLenum GL_MAX_GEOMETRY_IMAGE_UNIFORMS = 0x90CD;
constexpr GLenum GL_MAX_FRAGMENT_IMAGE_UNIFORMS = 0x90CE;
constexpr GLenum GL_MAX_COMBINED_IMAGE_UNIFORMS = 0x90CF;
void glBindImageTexture(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
void glMemoryBarrier(GLbitfield barriers);
#endif /* GL_ARB_shader_image_load_store */
#ifndef GL_ARB_shader_image_size
#define GL_ARB_shader_image_size 1
#endif /* GL_ARB_shader_image_size */
#ifndef GL_ARB_shader_objects
#define GL_ARB_shader_objects 1
constexpr GLenum GL_PROGRAM_OBJECT_ARB = 0x8B40;
constexpr GLenum GL_SHADER_OBJECT_ARB = 0x8B48;
constexpr GLenum GL_OBJECT_TYPE_ARB = 0x8B4E;
constexpr GLenum GL_OBJECT_SUBTYPE_ARB = 0x8B4F;
constexpr GLenum GL_FLOAT_VEC2_ARB = 0x8B50;
constexpr GLenum GL_FLOAT_VEC3_ARB = 0x8B51;
constexpr GLenum GL_FLOAT_VEC4_ARB = 0x8B52;
constexpr GLenum GL_INT_VEC2_ARB = 0x8B53;
constexpr GLenum GL_INT_VEC3_ARB = 0x8B54;
constexpr GLenum GL_INT_VEC4_ARB = 0x8B55;
constexpr GLenum GL_BOOL_ARB = 0x8B56;
constexpr GLenum GL_BOOL_VEC2_ARB = 0x8B57;
constexpr GLenum GL_BOOL_VEC3_ARB = 0x8B58;
constexpr GLenum GL_BOOL_VEC4_ARB = 0x8B59;
constexpr GLenum GL_FLOAT_MAT2_ARB = 0x8B5A;
constexpr GLenum GL_FLOAT_MAT3_ARB = 0x8B5B;
constexpr GLenum GL_FLOAT_MAT4_ARB = 0x8B5C;
constexpr GLenum GL_SAMPLER_1D_ARB = 0x8B5D;
constexpr GLenum GL_SAMPLER_2D_ARB = 0x8B5E;
constexpr GLenum GL_SAMPLER_3D_ARB = 0x8B5F;
constexpr GLenum GL_SAMPLER_CUBE_ARB = 0x8B60;
constexpr GLenum GL_SAMPLER_1D_SHADOW_ARB = 0x8B61;
constexpr GLenum GL_SAMPLER_2D_SHADOW_ARB = 0x8B62;
constexpr GLenum GL_SAMPLER_2D_RECT_ARB = 0x8B63;
constexpr GLenum GL_SAMPLER_2D_RECT_SHADOW_ARB = 0x8B64;
constexpr GLenum GL_OBJECT_DELETE_STATUS_ARB = 0x8B80;
constexpr GLenum GL_OBJECT_COMPILE_STATUS_ARB = 0x8B81;
constexpr GLenum GL_OBJECT_LINK_STATUS_ARB = 0x8B82;
constexpr GLenum GL_OBJECT_VALIDATE_STATUS_ARB = 0x8B83;
constexpr GLenum GL_OBJECT_INFO_LOG_LENGTH_ARB = 0x8B84;
constexpr GLenum GL_OBJECT_ATTACHED_OBJECTS_ARB = 0x8B85;
constexpr GLenum GL_OBJECT_ACTIVE_UNIFORMS_ARB = 0x8B86;
constexpr GLenum GL_OBJECT_ACTIVE_UNIFORM_MAX_LENGTH_ARB = 0x8B87;
constexpr GLenum GL_OBJECT_SHADER_SOURCE_LENGTH_ARB = 0x8B88;
void glDeleteObjectARB(GLhandleARB obj);
GLhandleARB glGetHandleARB(GLenum pname);
void glDetachObjectARB(GLhandleARB containerObj, GLhandleARB attachedObj);
GLhandleARB glCreateShaderObjectARB(GLenum shaderType);
void glShaderSourceARB(GLhandleARB shaderObj, GLsizei count, GLcharARB const  ** string, GLint const  * length);
void glCompileShaderARB(GLhandleARB shaderObj);
GLhandleARB glCreateProgramObjectARB();
void glAttachObjectARB(GLhandleARB containerObj, GLhandleARB obj);
void glLinkProgramARB(GLhandleARB programObj);
void glUseProgramObjectARB(GLhandleARB programObj);
void glValidateProgramARB(GLhandleARB programObj);
void glUniform1fARB(GLint location, GLfloat v0);
void glUniform2fARB(GLint location, GLfloat v0, GLfloat v1);
void glUniform3fARB(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
void glUniform4fARB(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
void glUniform1iARB(GLint location, GLint v0);
void glUniform2iARB(GLint location, GLint v0, GLint v1);
void glUniform3iARB(GLint location, GLint v0, GLint v1, GLint v2);
void glUniform4iARB(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
void glUniform1fvARB(GLint location, GLsizei count, GLfloat const  * value);
void glUniform2fvARB(GLint location, GLsizei count, GLfloat const  * value);
void glUniform3fvARB(GLint location, GLsizei count, GLfloat const  * value);
void glUniform4fvARB(GLint location, GLsizei count, GLfloat const  * value);
void glUniform1ivARB(GLint location, GLsizei count, GLint const  * value);
void glUniform2ivARB(GLint location, GLsizei count, GLint const  * value);
void glUniform3ivARB(GLint location, GLsizei count, GLint const  * value);
void glUniform4ivARB(GLint location, GLsizei count, GLint const  * value);
void glUniformMatrix2fvARB(GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value);
void glUniformMatrix3fvARB(GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value);
void glUniformMatrix4fvARB(GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value);
void glGetObjectParameterfvARB(GLhandleARB obj, GLenum pname, GLfloat * params);
void glGetObjectParameterivARB(GLhandleARB obj, GLenum pname, GLint * params);
void glGetInfoLogARB(GLhandleARB obj, GLsizei maxLength, GLsizei * length, GLcharARB * infoLog);
void glGetAttachedObjectsARB(GLhandleARB containerObj, GLsizei maxCount, GLsizei * count, GLhandleARB * obj);
GLint glGetUniformLocationARB(GLhandleARB programObj, GLcharARB const  * name);
void glGetActiveUniformARB(GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei * length, GLint * size, GLenum * type, GLcharARB * name);
void glGetUniformfvARB(GLhandleARB programObj, GLint location, GLfloat * params);
void glGetUniformivARB(GLhandleARB programObj, GLint location, GLint * params);
void glGetShaderSourceARB(GLhandleARB obj, GLsizei maxLength, GLsizei * length, GLcharARB * source);
#endif /* GL_ARB_shader_objects */
#ifndef GL_ARB_shader_precision
#define GL_ARB_shader_precision 1
#endif /* GL_ARB_shader_precision */
#ifndef GL_ARB_shader_stencil_export
#define GL_ARB_shader_stencil_export 1
#endif /* GL_ARB_shader_stencil_export */
#ifndef GL_ARB_shader_storage_buffer_object
#define GL_ARB_shader_storage_buffer_object 1
constexpr GLenum GL_SHADER_STORAGE_BUFFER = 0x90D2;
constexpr GLenum GL_SHADER_STORAGE_BUFFER_BINDING = 0x90D3;
constexpr GLenum GL_SHADER_STORAGE_BUFFER_START = 0x90D4;
constexpr GLenum GL_SHADER_STORAGE_BUFFER_SIZE = 0x90D5;
constexpr GLenum GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS = 0x90D6;
constexpr GLenum GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS = 0x90D7;
constexpr GLenum GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS = 0x90D8;
constexpr GLenum GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS = 0x90D9;
constexpr GLenum GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS = 0x90DA;
constexpr GLenum GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS = 0x90DB;
constexpr GLenum GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS = 0x90DC;
constexpr GLenum GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS = 0x90DD;
constexpr GLenum GL_MAX_SHADER_STORAGE_BLOCK_SIZE = 0x90DE;
constexpr GLenum GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT = 0x90DF;
constexpr GLenum GL_SHADER_STORAGE_BARRIER_BIT = 0x00002000;
constexpr GLenum GL_MAX_COMBINED_SHADER_OUTPUT_RESOURCES = 0x8F39;
void glShaderStorageBlockBinding(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
#endif /* GL_ARB_shader_storage_buffer_object */
#ifndef GL_ARB_shader_subroutine
#define GL_ARB_shader_subroutine 1
constexpr GLenum GL_ACTIVE_SUBROUTINES = 0x8DE5;
constexpr GLenum GL_ACTIVE_SUBROUTINE_UNIFORMS = 0x8DE6;
constexpr GLenum GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS = 0x8E47;
constexpr GLenum GL_ACTIVE_SUBROUTINE_MAX_LENGTH = 0x8E48;
constexpr GLenum GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH = 0x8E49;
constexpr GLenum GL_MAX_SUBROUTINES = 0x8DE7;
constexpr GLenum GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS = 0x8DE8;
constexpr GLenum GL_UNIFORM_SIZE = 0x8A38;
constexpr GLenum GL_UNIFORM_NAME_LENGTH = 0x8A39;
GLint glGetSubroutineUniformLocation(GLuint program, GLenum shadertype, GLchar const  * name);
GLuint glGetSubroutineIndex(GLuint program, GLenum shadertype, GLchar const  * name);
void glGetActiveSubroutineUniformiv(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint * values);
void glGetActiveSubroutineUniformName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei * length, GLchar * name);
void glGetActiveSubroutineName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei * length, GLchar * name);
void glUniformSubroutinesuiv(GLenum shadertype, GLsizei count, GLuint const  * indices);
void glGetUniformSubroutineuiv(GLenum shadertype, GLint location, GLuint * params);
void glGetProgramStageiv(GLuint program, GLenum shadertype, GLenum pname, GLint * values);
#endif /* GL_ARB_shader_subroutine */
#ifndef GL_ARB_shader_texture_image_samples
#define GL_ARB_shader_texture_image_samples 1
#endif /* GL_ARB_shader_texture_image_samples */
#ifndef GL_ARB_shader_texture_lod
#define GL_ARB_shader_texture_lod 1
#endif /* GL_ARB_shader_texture_lod */
#ifndef GL_ARB_shader_viewport_layer_array
#define GL_ARB_shader_viewport_layer_array 1
#endif /* GL_ARB_shader_viewport_layer_array */
#ifndef GL_ARB_shading_language_100
#define GL_ARB_shading_language_100 1
constexpr GLenum GL_SHADING_LANGUAGE_VERSION_ARB = 0x8B8C;
#endif /* GL_ARB_shading_language_100 */
#ifndef GL_ARB_shading_language_420pack
#define GL_ARB_shading_language_420pack 1
#endif /* GL_ARB_shading_language_420pack */
#ifndef GL_ARB_shading_language_include
#define GL_ARB_shading_language_include 1
constexpr GLenum GL_SHADER_INCLUDE_ARB = 0x8DAE;
constexpr GLenum GL_NAMED_STRING_LENGTH_ARB = 0x8DE9;
constexpr GLenum GL_NAMED_STRING_TYPE_ARB = 0x8DEA;
void glNamedStringARB(GLenum type, GLint namelen, GLchar const  * name, GLint stringlen, GLchar const  * string);
void glDeleteNamedStringARB(GLint namelen, GLchar const  * name);
void glCompileShaderIncludeARB(GLuint shader, GLsizei count, GLchar const  *const* path, GLint const  * length);
GLboolean glIsNamedStringARB(GLint namelen, GLchar const  * name);
void glGetNamedStringARB(GLint namelen, GLchar const  * name, GLsizei bufSize, GLint * stringlen, GLchar * string);
void glGetNamedStringivARB(GLint namelen, GLchar const  * name, GLenum pname, GLint * params);
#endif /* GL_ARB_shading_language_include */
#ifndef GL_ARB_shading_language_packing
#define GL_ARB_shading_language_packing 1
#endif /* GL_ARB_shading_language_packing */
#ifndef GL_ARB_shadow
#define GL_ARB_shadow 1
constexpr GLenum GL_TEXTURE_COMPARE_MODE_ARB = 0x884C;
constexpr GLenum GL_TEXTURE_COMPARE_FUNC_ARB = 0x884D;
constexpr GLenum GL_COMPARE_R_TO_TEXTURE_ARB = 0x884E;
#endif /* GL_ARB_shadow */
#ifndef GL_ARB_shadow_ambient
#define GL_ARB_shadow_ambient 1
constexpr GLenum GL_TEXTURE_COMPARE_FAIL_VALUE_ARB = 0x80BF;
#endif /* GL_ARB_shadow_ambient */
#ifndef GL_ARB_sparse_buffer
#define GL_ARB_sparse_buffer 1
constexpr GLenum GL_SPARSE_STORAGE_BIT_ARB = 0x0400;
constexpr GLenum GL_SPARSE_BUFFER_PAGE_SIZE_ARB = 0x82F8;
void glBufferPageCommitmentARB(GLenum target, GLintptr offset, GLsizeiptr size, GLboolean commit);
void glNamedBufferPageCommitmentEXT(GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit);
void glNamedBufferPageCommitmentARB(GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit);
#endif /* GL_ARB_sparse_buffer */
#ifndef GL_ARB_sparse_texture
#define GL_ARB_sparse_texture 1
constexpr GLenum GL_TEXTURE_SPARSE_ARB = 0x91A6;
constexpr GLenum GL_VIRTUAL_PAGE_SIZE_INDEX_ARB = 0x91A7;
constexpr GLenum GL_NUM_SPARSE_LEVELS_ARB = 0x91AA;
constexpr GLenum GL_NUM_VIRTUAL_PAGE_SIZES_ARB = 0x91A8;
constexpr GLenum GL_VIRTUAL_PAGE_SIZE_X_ARB = 0x9195;
constexpr GLenum GL_VIRTUAL_PAGE_SIZE_Y_ARB = 0x9196;
constexpr GLenum GL_VIRTUAL_PAGE_SIZE_Z_ARB = 0x9197;
constexpr GLenum GL_MAX_SPARSE_TEXTURE_SIZE_ARB = 0x9198;
constexpr GLenum GL_MAX_SPARSE_3D_TEXTURE_SIZE_ARB = 0x9199;
constexpr GLenum GL_MAX_SPARSE_ARRAY_TEXTURE_LAYERS_ARB = 0x919A;
constexpr GLenum GL_SPARSE_TEXTURE_FULL_ARRAY_CUBE_MIPMAPS_ARB = 0x91A9;
void glTexPageCommitmentARB(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit);
#endif /* GL_ARB_sparse_texture */
#ifndef GL_ARB_sparse_texture2
#define GL_ARB_sparse_texture2 1
#endif /* GL_ARB_sparse_texture2 */
#ifndef GL_ARB_sparse_texture_clamp
#define GL_ARB_sparse_texture_clamp 1
#endif /* GL_ARB_sparse_texture_clamp */
#ifndef GL_ARB_spirv_extensions
#define GL_ARB_spirv_extensions 1
constexpr GLenum GL_SPIR_V_EXTENSIONS = 0x9553;
constexpr GLenum GL_NUM_SPIR_V_EXTENSIONS = 0x9554;
#endif /* GL_ARB_spirv_extensions */
#ifndef GL_ARB_stencil_texturing
#define GL_ARB_stencil_texturing 1
constexpr GLenum GL_DEPTH_STENCIL_TEXTURE_MODE = 0x90EA;
#endif /* GL_ARB_stencil_texturing */
#ifndef GL_ARB_sync
#define GL_ARB_sync 1
constexpr GLenum GL_MAX_SERVER_WAIT_TIMEOUT = 0x9111;
constexpr GLenum GL_OBJECT_TYPE = 0x9112;
constexpr GLenum GL_SYNC_CONDITION = 0x9113;
constexpr GLenum GL_SYNC_STATUS = 0x9114;
constexpr GLenum GL_SYNC_FLAGS = 0x9115;
constexpr GLenum GL_SYNC_FENCE = 0x9116;
constexpr GLenum GL_SYNC_GPU_COMMANDS_COMPLETE = 0x9117;
constexpr GLenum GL_UNSIGNALED = 0x9118;
constexpr GLenum GL_SIGNALED = 0x9119;
constexpr GLenum GL_ALREADY_SIGNALED = 0x911A;
constexpr GLenum GL_TIMEOUT_EXPIRED = 0x911B;
constexpr GLenum GL_CONDITION_SATISFIED = 0x911C;
constexpr GLenum GL_WAIT_FAILED = 0x911D;
constexpr GLenum GL_SYNC_FLUSH_COMMANDS_BIT = 0x00000001;
constexpr GLenum GL_TIMEOUT_IGNORED = 0xFFFFFFFFFFFFFFFF;
GLsync glFenceSync(GLenum condition, GLbitfield flags);
GLboolean glIsSync(GLsync sync);
void glDeleteSync(GLsync sync);
GLenum glClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout);
void glWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout);
void glGetInteger64v(GLenum pname, GLint64 * data);
void glGetSynciv(GLsync sync, GLenum pname, GLsizei count, GLsizei * length, GLint * values);
#endif /* GL_ARB_sync */
#ifndef GL_ARB_tessellation_shader
#define GL_ARB_tessellation_shader 1
constexpr GLenum GL_PATCHES = 0x000E;
constexpr GLenum GL_PATCH_VERTICES = 0x8E72;
constexpr GLenum GL_PATCH_DEFAULT_INNER_LEVEL = 0x8E73;
constexpr GLenum GL_PATCH_DEFAULT_OUTER_LEVEL = 0x8E74;
constexpr GLenum GL_TESS_CONTROL_OUTPUT_VERTICES = 0x8E75;
constexpr GLenum GL_TESS_GEN_MODE = 0x8E76;
constexpr GLenum GL_TESS_GEN_SPACING = 0x8E77;
constexpr GLenum GL_TESS_GEN_VERTEX_ORDER = 0x8E78;
constexpr GLenum GL_TESS_GEN_POINT_MODE = 0x8E79;
constexpr GLenum GL_ISOLINES = 0x8E7A;
constexpr GLenum GL_FRACTIONAL_ODD = 0x8E7B;
constexpr GLenum GL_FRACTIONAL_EVEN = 0x8E7C;
constexpr GLenum GL_MAX_PATCH_VERTICES = 0x8E7D;
constexpr GLenum GL_MAX_TESS_GEN_LEVEL = 0x8E7E;
constexpr GLenum GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS = 0x8E7F;
constexpr GLenum GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS = 0x8E80;
constexpr GLenum GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS = 0x8E81;
constexpr GLenum GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS = 0x8E82;
constexpr GLenum GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS = 0x8E83;
constexpr GLenum GL_MAX_TESS_PATCH_COMPONENTS = 0x8E84;
constexpr GLenum GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS = 0x8E85;
constexpr GLenum GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS = 0x8E86;
constexpr GLenum GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS = 0x8E89;
constexpr GLenum GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS = 0x8E8A;
constexpr GLenum GL_MAX_TESS_CONTROL_INPUT_COMPONENTS = 0x886C;
constexpr GLenum GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS = 0x886D;
constexpr GLenum GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS = 0x8E1E;
constexpr GLenum GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS = 0x8E1F;
constexpr GLenum GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER = 0x84F0;
constexpr GLenum GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER = 0x84F1;
constexpr GLenum GL_TESS_EVALUATION_SHADER = 0x8E87;
constexpr GLenum GL_TESS_CONTROL_SHADER = 0x8E88;
void glPatchParameteri(GLenum pname, GLint value);
void glPatchParameterfv(GLenum pname, GLfloat const  * values);
#endif /* GL_ARB_tessellation_shader */
#ifndef GL_ARB_texture_barrier
#define GL_ARB_texture_barrier 1
void glTextureBarrier();
#endif /* GL_ARB_texture_barrier */
#ifndef GL_ARB_texture_border_clamp
#define GL_ARB_texture_border_clamp 1
constexpr GLenum GL_CLAMP_TO_BORDER_ARB = 0x812D;
#endif /* GL_ARB_texture_border_clamp */
#ifndef GL_ARB_texture_buffer_object
#define GL_ARB_texture_buffer_object 1
constexpr GLenum GL_TEXTURE_BUFFER_ARB = 0x8C2A;
constexpr GLenum GL_MAX_TEXTURE_BUFFER_SIZE_ARB = 0x8C2B;
constexpr GLenum GL_TEXTURE_BINDING_BUFFER_ARB = 0x8C2C;
constexpr GLenum GL_TEXTURE_BUFFER_DATA_STORE_BINDING_ARB = 0x8C2D;
constexpr GLenum GL_TEXTURE_BUFFER_FORMAT_ARB = 0x8C2E;
void glTexBufferARB(GLenum target, GLenum internalformat, GLuint buffer);
#endif /* GL_ARB_texture_buffer_object */
#ifndef GL_ARB_texture_buffer_object_rgb32
#define GL_ARB_texture_buffer_object_rgb32 1
#endif /* GL_ARB_texture_buffer_object_rgb32 */
#ifndef GL_ARB_texture_buffer_range
#define GL_ARB_texture_buffer_range 1
constexpr GLenum GL_TEXTURE_BUFFER_OFFSET = 0x919D;
constexpr GLenum GL_TEXTURE_BUFFER_SIZE = 0x919E;
constexpr GLenum GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT = 0x919F;
void glTexBufferRange(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
#endif /* GL_ARB_texture_buffer_range */
#ifndef GL_ARB_texture_compression
#define GL_ARB_texture_compression 1
constexpr GLenum GL_COMPRESSED_ALPHA_ARB = 0x84E9;
constexpr GLenum GL_COMPRESSED_LUMINANCE_ARB = 0x84EA;
constexpr GLenum GL_COMPRESSED_LUMINANCE_ALPHA_ARB = 0x84EB;
constexpr GLenum GL_COMPRESSED_INTENSITY_ARB = 0x84EC;
constexpr GLenum GL_COMPRESSED_RGB_ARB = 0x84ED;
constexpr GLenum GL_COMPRESSED_RGBA_ARB = 0x84EE;
constexpr GLenum GL_TEXTURE_COMPRESSION_HINT_ARB = 0x84EF;
constexpr GLenum GL_TEXTURE_COMPRESSED_IMAGE_SIZE_ARB = 0x86A0;
constexpr GLenum GL_TEXTURE_COMPRESSED_ARB = 0x86A1;
constexpr GLenum GL_NUM_COMPRESSED_TEXTURE_FORMATS_ARB = 0x86A2;
constexpr GLenum GL_COMPRESSED_TEXTURE_FORMATS_ARB = 0x86A3;
void glCompressedTexImage3DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void * data);
void glCompressedTexImage2DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void * data);
void glCompressedTexImage1DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void * data);
void glCompressedTexSubImage3DARB(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * data);
void glCompressedTexSubImage2DARB(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * data);
void glCompressedTexSubImage1DARB(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * data);
void glGetCompressedTexImageARB(GLenum target, GLint level, void * img);
#endif /* GL_ARB_texture_compression */
#ifndef GL_ARB_texture_compression_bptc
#define GL_ARB_texture_compression_bptc 1
constexpr GLenum GL_COMPRESSED_RGBA_BPTC_UNORM_ARB = 0x8E8C;
constexpr GLenum GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM_ARB = 0x8E8D;
constexpr GLenum GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT_ARB = 0x8E8E;
constexpr GLenum GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT_ARB = 0x8E8F;
#endif /* GL_ARB_texture_compression_bptc */
#ifndef GL_ARB_texture_compression_rgtc
#define GL_ARB_texture_compression_rgtc 1
#endif /* GL_ARB_texture_compression_rgtc */
#ifndef GL_ARB_texture_cube_map
#define GL_ARB_texture_cube_map 1
constexpr GLenum GL_NORMAL_MAP_ARB = 0x8511;
constexpr GLenum GL_REFLECTION_MAP_ARB = 0x8512;
constexpr GLenum GL_TEXTURE_CUBE_MAP_ARB = 0x8513;
constexpr GLenum GL_TEXTURE_BINDING_CUBE_MAP_ARB = 0x8514;
constexpr GLenum GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB = 0x8515;
constexpr GLenum GL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB = 0x8516;
constexpr GLenum GL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB = 0x8517;
constexpr GLenum GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB = 0x8518;
constexpr GLenum GL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB = 0x8519;
constexpr GLenum GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB = 0x851A;
constexpr GLenum GL_PROXY_TEXTURE_CUBE_MAP_ARB = 0x851B;
constexpr GLenum GL_MAX_CUBE_MAP_TEXTURE_SIZE_ARB = 0x851C;
#endif /* GL_ARB_texture_cube_map */
#ifndef GL_ARB_texture_cube_map_array
#define GL_ARB_texture_cube_map_array 1
constexpr GLenum GL_TEXTURE_CUBE_MAP_ARRAY_ARB = 0x9009;
constexpr GLenum GL_TEXTURE_BINDING_CUBE_MAP_ARRAY_ARB = 0x900A;
constexpr GLenum GL_PROXY_TEXTURE_CUBE_MAP_ARRAY_ARB = 0x900B;
constexpr GLenum GL_SAMPLER_CUBE_MAP_ARRAY_ARB = 0x900C;
constexpr GLenum GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW_ARB = 0x900D;
constexpr GLenum GL_INT_SAMPLER_CUBE_MAP_ARRAY_ARB = 0x900E;
constexpr GLenum GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY_ARB = 0x900F;
#endif /* GL_ARB_texture_cube_map_array */
#ifndef GL_ARB_texture_env_add
#define GL_ARB_texture_env_add 1
#endif /* GL_ARB_texture_env_add */
#ifndef GL_ARB_texture_env_combine
#define GL_ARB_texture_env_combine 1
constexpr GLenum GL_COMBINE_ARB = 0x8570;
constexpr GLenum GL_COMBINE_RGB_ARB = 0x8571;
constexpr GLenum GL_COMBINE_ALPHA_ARB = 0x8572;
constexpr GLenum GL_SOURCE0_RGB_ARB = 0x8580;
constexpr GLenum GL_SOURCE1_RGB_ARB = 0x8581;
constexpr GLenum GL_SOURCE2_RGB_ARB = 0x8582;
constexpr GLenum GL_SOURCE0_ALPHA_ARB = 0x8588;
constexpr GLenum GL_SOURCE1_ALPHA_ARB = 0x8589;
constexpr GLenum GL_SOURCE2_ALPHA_ARB = 0x858A;
constexpr GLenum GL_OPERAND0_RGB_ARB = 0x8590;
constexpr GLenum GL_OPERAND1_RGB_ARB = 0x8591;
constexpr GLenum GL_OPERAND2_RGB_ARB = 0x8592;
constexpr GLenum GL_OPERAND0_ALPHA_ARB = 0x8598;
constexpr GLenum GL_OPERAND1_ALPHA_ARB = 0x8599;
constexpr GLenum GL_OPERAND2_ALPHA_ARB = 0x859A;
constexpr GLenum GL_RGB_SCALE_ARB = 0x8573;
constexpr GLenum GL_ADD_SIGNED_ARB = 0x8574;
constexpr GLenum GL_INTERPOLATE_ARB = 0x8575;
constexpr GLenum GL_SUBTRACT_ARB = 0x84E7;
constexpr GLenum GL_CONSTANT_ARB = 0x8576;
constexpr GLenum GL_PRIMARY_COLOR_ARB = 0x8577;
constexpr GLenum GL_PREVIOUS_ARB = 0x8578;
#endif /* GL_ARB_texture_env_combine */
#ifndef GL_ARB_texture_env_crossbar
#define GL_ARB_texture_env_crossbar 1
#endif /* GL_ARB_texture_env_crossbar */
#ifndef GL_ARB_texture_env_dot3
#define GL_ARB_texture_env_dot3 1
constexpr GLenum GL_DOT3_RGB_ARB = 0x86AE;
constexpr GLenum GL_DOT3_RGBA_ARB = 0x86AF;
#endif /* GL_ARB_texture_env_dot3 */
#ifndef GL_ARB_texture_filter_anisotropic
#define GL_ARB_texture_filter_anisotropic 1
constexpr GLenum GL_TEXTURE_MAX_ANISOTROPY = 0x84FE;
constexpr GLenum GL_MAX_TEXTURE_MAX_ANISOTROPY = 0x84FF;
#endif /* GL_ARB_texture_filter_anisotropic */
#ifndef GL_ARB_texture_filter_minmax
#define GL_ARB_texture_filter_minmax 1
constexpr GLenum GL_TEXTURE_REDUCTION_MODE_ARB = 0x9366;
constexpr GLenum GL_WEIGHTED_AVERAGE_ARB = 0x9367;
#endif /* GL_ARB_texture_filter_minmax */
#ifndef GL_ARB_texture_float
#define GL_ARB_texture_float 1
constexpr GLenum GL_TEXTURE_RED_TYPE_ARB = 0x8C10;
constexpr GLenum GL_TEXTURE_GREEN_TYPE_ARB = 0x8C11;
constexpr GLenum GL_TEXTURE_BLUE_TYPE_ARB = 0x8C12;
constexpr GLenum GL_TEXTURE_ALPHA_TYPE_ARB = 0x8C13;
constexpr GLenum GL_TEXTURE_LUMINANCE_TYPE_ARB = 0x8C14;
constexpr GLenum GL_TEXTURE_INTENSITY_TYPE_ARB = 0x8C15;
constexpr GLenum GL_TEXTURE_DEPTH_TYPE_ARB = 0x8C16;
constexpr GLenum GL_UNSIGNED_NORMALIZED_ARB = 0x8C17;
constexpr GLenum GL_RGBA32F_ARB = 0x8814;
constexpr GLenum GL_RGB32F_ARB = 0x8815;
constexpr GLenum GL_ALPHA32F_ARB = 0x8816;
constexpr GLenum GL_INTENSITY32F_ARB = 0x8817;
constexpr GLenum GL_LUMINANCE32F_ARB = 0x8818;
constexpr GLenum GL_LUMINANCE_ALPHA32F_ARB = 0x8819;
constexpr GLenum GL_RGBA16F_ARB = 0x881A;
constexpr GLenum GL_RGB16F_ARB = 0x881B;
constexpr GLenum GL_ALPHA16F_ARB = 0x881C;
constexpr GLenum GL_INTENSITY16F_ARB = 0x881D;
constexpr GLenum GL_LUMINANCE16F_ARB = 0x881E;
constexpr GLenum GL_LUMINANCE_ALPHA16F_ARB = 0x881F;
#endif /* GL_ARB_texture_float */
#ifndef GL_ARB_texture_gather
#define GL_ARB_texture_gather 1
constexpr GLenum GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET_ARB = 0x8E5E;
constexpr GLenum GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET_ARB = 0x8E5F;
constexpr GLenum GL_MAX_PROGRAM_TEXTURE_GATHER_COMPONENTS_ARB = 0x8F9F;
#endif /* GL_ARB_texture_gather */
#ifndef GL_ARB_texture_mirror_clamp_to_edge
#define GL_ARB_texture_mirror_clamp_to_edge 1
constexpr GLenum GL_MIRROR_CLAMP_TO_EDGE = 0x8743;
#endif /* GL_ARB_texture_mirror_clamp_to_edge */
#ifndef GL_ARB_texture_mirrored_repeat
#define GL_ARB_texture_mirrored_repeat 1
constexpr GLenum GL_MIRRORED_REPEAT_ARB = 0x8370;
#endif /* GL_ARB_texture_mirrored_repeat */
#ifndef GL_ARB_texture_multisample
#define GL_ARB_texture_multisample 1
constexpr GLenum GL_SAMPLE_POSITION = 0x8E50;
constexpr GLenum GL_SAMPLE_MASK = 0x8E51;
constexpr GLenum GL_SAMPLE_MASK_VALUE = 0x8E52;
constexpr GLenum GL_MAX_SAMPLE_MASK_WORDS = 0x8E59;
constexpr GLenum GL_PROXY_TEXTURE_2D_MULTISAMPLE = 0x9101;
constexpr GLenum GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY = 0x9103;
constexpr GLenum GL_TEXTURE_SAMPLES = 0x9106;
constexpr GLenum GL_TEXTURE_FIXED_SAMPLE_LOCATIONS = 0x9107;
constexpr GLenum GL_SAMPLER_2D_MULTISAMPLE = 0x9108;
constexpr GLenum GL_INT_SAMPLER_2D_MULTISAMPLE = 0x9109;
constexpr GLenum GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE = 0x910A;
constexpr GLenum GL_SAMPLER_2D_MULTISAMPLE_ARRAY = 0x910B;
constexpr GLenum GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY = 0x910C;
constexpr GLenum GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY = 0x910D;
constexpr GLenum GL_MAX_COLOR_TEXTURE_SAMPLES = 0x910E;
constexpr GLenum GL_MAX_DEPTH_TEXTURE_SAMPLES = 0x910F;
constexpr GLenum GL_MAX_INTEGER_SAMPLES = 0x9110;
void glTexImage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
void glTexImage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
void glGetMultisamplefv(GLenum pname, GLuint index, GLfloat * val);
void glSampleMaski(GLuint maskNumber, GLbitfield mask);
#endif /* GL_ARB_texture_multisample */
#ifndef GL_ARB_texture_non_power_of_two
#define GL_ARB_texture_non_power_of_two 1
#endif /* GL_ARB_texture_non_power_of_two */
#ifndef GL_ARB_texture_query_levels
#define GL_ARB_texture_query_levels 1
#endif /* GL_ARB_texture_query_levels */
#ifndef GL_ARB_texture_query_lod
#define GL_ARB_texture_query_lod 1
#endif /* GL_ARB_texture_query_lod */
#ifndef GL_ARB_texture_rectangle
#define GL_ARB_texture_rectangle 1
constexpr GLenum GL_TEXTURE_RECTANGLE_ARB = 0x84F5;
constexpr GLenum GL_TEXTURE_BINDING_RECTANGLE_ARB = 0x84F6;
constexpr GLenum GL_PROXY_TEXTURE_RECTANGLE_ARB = 0x84F7;
constexpr GLenum GL_MAX_RECTANGLE_TEXTURE_SIZE_ARB = 0x84F8;
#endif /* GL_ARB_texture_rectangle */
#ifndef GL_ARB_texture_rg
#define GL_ARB_texture_rg 1
#endif /* GL_ARB_texture_rg */
#ifndef GL_ARB_texture_rgb10_a2ui
#define GL_ARB_texture_rgb10_a2ui 1
constexpr GLenum GL_RGB10_A2UI = 0x906F;
#endif /* GL_ARB_texture_rgb10_a2ui */
#ifndef GL_ARB_texture_stencil8
#define GL_ARB_texture_stencil8 1
#endif /* GL_ARB_texture_stencil8 */
#ifndef GL_ARB_texture_storage
#define GL_ARB_texture_storage 1
constexpr GLenum GL_TEXTURE_IMMUTABLE_FORMAT = 0x912F;
void glTexStorage1D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
void glTexStorage2D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
void glTexStorage3D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
#endif /* GL_ARB_texture_storage */
#ifndef GL_ARB_texture_storage_multisample
#define GL_ARB_texture_storage_multisample 1
void glTexStorage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
void glTexStorage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
#endif /* GL_ARB_texture_storage_multisample */
#ifndef GL_ARB_texture_swizzle
#define GL_ARB_texture_swizzle 1
constexpr GLenum GL_TEXTURE_SWIZZLE_R = 0x8E42;
constexpr GLenum GL_TEXTURE_SWIZZLE_G = 0x8E43;
constexpr GLenum GL_TEXTURE_SWIZZLE_B = 0x8E44;
constexpr GLenum GL_TEXTURE_SWIZZLE_A = 0x8E45;
constexpr GLenum GL_TEXTURE_SWIZZLE_RGBA = 0x8E46;
#endif /* GL_ARB_texture_swizzle */
#ifndef GL_ARB_texture_view
#define GL_ARB_texture_view 1
constexpr GLenum GL_TEXTURE_VIEW_MIN_LEVEL = 0x82DB;
constexpr GLenum GL_TEXTURE_VIEW_NUM_LEVELS = 0x82DC;
constexpr GLenum GL_TEXTURE_VIEW_MIN_LAYER = 0x82DD;
constexpr GLenum GL_TEXTURE_VIEW_NUM_LAYERS = 0x82DE;
constexpr GLenum GL_TEXTURE_IMMUTABLE_LEVELS = 0x82DF;
void glTextureView(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
#endif /* GL_ARB_texture_view */
#ifndef GL_ARB_timer_query
#define GL_ARB_timer_query 1
constexpr GLenum GL_TIME_ELAPSED = 0x88BF;
constexpr GLenum GL_TIMESTAMP = 0x8E28;
void glQueryCounter(GLuint id, GLenum target);
void glGetQueryObjecti64v(GLuint id, GLenum pname, GLint64 * params);
void glGetQueryObjectui64v(GLuint id, GLenum pname, GLuint64 * params);
#endif /* GL_ARB_timer_query */
#ifndef GL_ARB_transform_feedback2
#define GL_ARB_transform_feedback2 1
constexpr GLenum GL_TRANSFORM_FEEDBACK = 0x8E22;
constexpr GLenum GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED = 0x8E23;
constexpr GLenum GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE = 0x8E24;
constexpr GLenum GL_TRANSFORM_FEEDBACK_BINDING = 0x8E25;
void glBindTransformFeedback(GLenum target, GLuint id);
void glDeleteTransformFeedbacks(GLsizei n, GLuint const  * ids);
void glGenTransformFeedbacks(GLsizei n, GLuint * ids);
GLboolean glIsTransformFeedback(GLuint id);
void glPauseTransformFeedback();
void glResumeTransformFeedback();
void glDrawTransformFeedback(GLenum mode, GLuint id);
#endif /* GL_ARB_transform_feedback2 */
#ifndef GL_ARB_transform_feedback3
#define GL_ARB_transform_feedback3 1
constexpr GLenum GL_MAX_TRANSFORM_FEEDBACK_BUFFERS = 0x8E70;
void glDrawTransformFeedbackStream(GLenum mode, GLuint id, GLuint stream);
void glBeginQueryIndexed(GLenum target, GLuint index, GLuint id);
void glEndQueryIndexed(GLenum target, GLuint index);
void glGetQueryIndexediv(GLenum target, GLuint index, GLenum pname, GLint * params);
#endif /* GL_ARB_transform_feedback3 */
#ifndef GL_ARB_transform_feedback_instanced
#define GL_ARB_transform_feedback_instanced 1
void glDrawTransformFeedbackInstanced(GLenum mode, GLuint id, GLsizei instancecount);
void glDrawTransformFeedbackStreamInstanced(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount);
#endif /* GL_ARB_transform_feedback_instanced */
#ifndef GL_ARB_transform_feedback_overflow_query
#define GL_ARB_transform_feedback_overflow_query 1
constexpr GLenum GL_TRANSFORM_FEEDBACK_OVERFLOW_ARB = 0x82EC;
constexpr GLenum GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW_ARB = 0x82ED;
#endif /* GL_ARB_transform_feedback_overflow_query */
#ifndef GL_ARB_transpose_matrix
#define GL_ARB_transpose_matrix 1
constexpr GLenum GL_TRANSPOSE_MODELVIEW_MATRIX_ARB = 0x84E3;
constexpr GLenum GL_TRANSPOSE_PROJECTION_MATRIX_ARB = 0x84E4;
constexpr GLenum GL_TRANSPOSE_TEXTURE_MATRIX_ARB = 0x84E5;
constexpr GLenum GL_TRANSPOSE_COLOR_MATRIX_ARB = 0x84E6;
void glLoadTransposeMatrixfARB(GLfloat const  * m);
void glLoadTransposeMatrixdARB(GLdouble const  * m);
void glMultTransposeMatrixfARB(GLfloat const  * m);
void glMultTransposeMatrixdARB(GLdouble const  * m);
#endif /* GL_ARB_transpose_matrix */
#ifndef GL_ARB_uniform_buffer_object
#define GL_ARB_uniform_buffer_object 1
constexpr GLenum GL_UNIFORM_BUFFER = 0x8A11;
constexpr GLenum GL_UNIFORM_BUFFER_BINDING = 0x8A28;
constexpr GLenum GL_UNIFORM_BUFFER_START = 0x8A29;
constexpr GLenum GL_UNIFORM_BUFFER_SIZE = 0x8A2A;
constexpr GLenum GL_MAX_VERTEX_UNIFORM_BLOCKS = 0x8A2B;
constexpr GLenum GL_MAX_GEOMETRY_UNIFORM_BLOCKS = 0x8A2C;
constexpr GLenum GL_MAX_FRAGMENT_UNIFORM_BLOCKS = 0x8A2D;
constexpr GLenum GL_MAX_COMBINED_UNIFORM_BLOCKS = 0x8A2E;
constexpr GLenum GL_MAX_UNIFORM_BUFFER_BINDINGS = 0x8A2F;
constexpr GLenum GL_MAX_UNIFORM_BLOCK_SIZE = 0x8A30;
constexpr GLenum GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS = 0x8A31;
constexpr GLenum GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS = 0x8A32;
constexpr GLenum GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS = 0x8A33;
constexpr GLenum GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT = 0x8A34;
constexpr GLenum GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH = 0x8A35;
constexpr GLenum GL_ACTIVE_UNIFORM_BLOCKS = 0x8A36;
constexpr GLenum GL_UNIFORM_TYPE = 0x8A37;
constexpr GLenum GL_UNIFORM_BLOCK_INDEX = 0x8A3A;
constexpr GLenum GL_UNIFORM_OFFSET = 0x8A3B;
constexpr GLenum GL_UNIFORM_ARRAY_STRIDE = 0x8A3C;
constexpr GLenum GL_UNIFORM_MATRIX_STRIDE = 0x8A3D;
constexpr GLenum GL_UNIFORM_IS_ROW_MAJOR = 0x8A3E;
constexpr GLenum GL_UNIFORM_BLOCK_BINDING = 0x8A3F;
constexpr GLenum GL_UNIFORM_BLOCK_DATA_SIZE = 0x8A40;
constexpr GLenum GL_UNIFORM_BLOCK_NAME_LENGTH = 0x8A41;
constexpr GLenum GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS = 0x8A42;
constexpr GLenum GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES = 0x8A43;
constexpr GLenum GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER = 0x8A44;
constexpr GLenum GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER = 0x8A45;
constexpr GLenum GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER = 0x8A46;
constexpr GLenum GL_INVALID_INDEX = 0xFFFFFFFF;
void glGetUniformIndices(GLuint program, GLsizei uniformCount, GLchar const  *const* uniformNames, GLuint * uniformIndices);
void glGetActiveUniformsiv(GLuint program, GLsizei uniformCount, GLuint const  * uniformIndices, GLenum pname, GLint * params);
void glGetActiveUniformName(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei * length, GLchar * uniformName);
GLuint glGetUniformBlockIndex(GLuint program, GLchar const  * uniformBlockName);
void glGetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint * params);
void glGetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei * length, GLchar * uniformBlockName);
void glUniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
#endif /* GL_ARB_uniform_buffer_object */
#ifndef GL_ARB_vertex_array_bgra
#define GL_ARB_vertex_array_bgra 1
#endif /* GL_ARB_vertex_array_bgra */
#ifndef GL_ARB_vertex_array_object
#define GL_ARB_vertex_array_object 1
#endif /* GL_ARB_vertex_array_object */
#ifndef GL_ARB_vertex_attrib_64bit
#define GL_ARB_vertex_attrib_64bit 1
void glVertexAttribL1d(GLuint index, GLdouble x);
void glVertexAttribL2d(GLuint index, GLdouble x, GLdouble y);
void glVertexAttribL3d(GLuint index, GLdouble x, GLdouble y, GLdouble z);
void glVertexAttribL4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void glVertexAttribL1dv(GLuint index, GLdouble const  * v);
void glVertexAttribL2dv(GLuint index, GLdouble const  * v);
void glVertexAttribL3dv(GLuint index, GLdouble const  * v);
void glVertexAttribL4dv(GLuint index, GLdouble const  * v);
void glVertexAttribLPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void * pointer);
void glGetVertexAttribLdv(GLuint index, GLenum pname, GLdouble * params);
#endif /* GL_ARB_vertex_attrib_64bit */
#ifndef GL_ARB_vertex_attrib_binding
#define GL_ARB_vertex_attrib_binding 1
constexpr GLenum GL_VERTEX_ATTRIB_BINDING = 0x82D4;
constexpr GLenum GL_VERTEX_ATTRIB_RELATIVE_OFFSET = 0x82D5;
constexpr GLenum GL_VERTEX_BINDING_DIVISOR = 0x82D6;
constexpr GLenum GL_VERTEX_BINDING_OFFSET = 0x82D7;
constexpr GLenum GL_VERTEX_BINDING_STRIDE = 0x82D8;
constexpr GLenum GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET = 0x82D9;
constexpr GLenum GL_MAX_VERTEX_ATTRIB_BINDINGS = 0x82DA;
void glBindVertexBuffer(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
void glVertexAttribFormat(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
void glVertexAttribIFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
void glVertexAttribLFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
void glVertexAttribBinding(GLuint attribindex, GLuint bindingindex);
void glVertexBindingDivisor(GLuint bindingindex, GLuint divisor);
#endif /* GL_ARB_vertex_attrib_binding */
#ifndef GL_ARB_vertex_blend
#define GL_ARB_vertex_blend 1
constexpr GLenum GL_MAX_VERTEX_UNITS_ARB = 0x86A4;
constexpr GLenum GL_ACTIVE_VERTEX_UNITS_ARB = 0x86A5;
constexpr GLenum GL_WEIGHT_SUM_UNITY_ARB = 0x86A6;
constexpr GLenum GL_VERTEX_BLEND_ARB = 0x86A7;
constexpr GLenum GL_CURRENT_WEIGHT_ARB = 0x86A8;
constexpr GLenum GL_WEIGHT_ARRAY_TYPE_ARB = 0x86A9;
constexpr GLenum GL_WEIGHT_ARRAY_STRIDE_ARB = 0x86AA;
constexpr GLenum GL_WEIGHT_ARRAY_SIZE_ARB = 0x86AB;
constexpr GLenum GL_WEIGHT_ARRAY_POINTER_ARB = 0x86AC;
constexpr GLenum GL_WEIGHT_ARRAY_ARB = 0x86AD;
constexpr GLenum GL_MODELVIEW0_ARB = 0x1700;
constexpr GLenum GL_MODELVIEW1_ARB = 0x850A;
constexpr GLenum GL_MODELVIEW2_ARB = 0x8722;
constexpr GLenum GL_MODELVIEW3_ARB = 0x8723;
constexpr GLenum GL_MODELVIEW4_ARB = 0x8724;
constexpr GLenum GL_MODELVIEW5_ARB = 0x8725;
constexpr GLenum GL_MODELVIEW6_ARB = 0x8726;
constexpr GLenum GL_MODELVIEW7_ARB = 0x8727;
constexpr GLenum GL_MODELVIEW8_ARB = 0x8728;
constexpr GLenum GL_MODELVIEW9_ARB = 0x8729;
constexpr GLenum GL_MODELVIEW10_ARB = 0x872A;
constexpr GLenum GL_MODELVIEW11_ARB = 0x872B;
constexpr GLenum GL_MODELVIEW12_ARB = 0x872C;
constexpr GLenum GL_MODELVIEW13_ARB = 0x872D;
constexpr GLenum GL_MODELVIEW14_ARB = 0x872E;
constexpr GLenum GL_MODELVIEW15_ARB = 0x872F;
constexpr GLenum GL_MODELVIEW16_ARB = 0x8730;
constexpr GLenum GL_MODELVIEW17_ARB = 0x8731;
constexpr GLenum GL_MODELVIEW18_ARB = 0x8732;
constexpr GLenum GL_MODELVIEW19_ARB = 0x8733;
constexpr GLenum GL_MODELVIEW20_ARB = 0x8734;
constexpr GLenum GL_MODELVIEW21_ARB = 0x8735;
constexpr GLenum GL_MODELVIEW22_ARB = 0x8736;
constexpr GLenum GL_MODELVIEW23_ARB = 0x8737;
constexpr GLenum GL_MODELVIEW24_ARB = 0x8738;
constexpr GLenum GL_MODELVIEW25_ARB = 0x8739;
constexpr GLenum GL_MODELVIEW26_ARB = 0x873A;
constexpr GLenum GL_MODELVIEW27_ARB = 0x873B;
constexpr GLenum GL_MODELVIEW28_ARB = 0x873C;
constexpr GLenum GL_MODELVIEW29_ARB = 0x873D;
constexpr GLenum GL_MODELVIEW30_ARB = 0x873E;
constexpr GLenum GL_MODELVIEW31_ARB = 0x873F;
void glWeightbvARB(GLint size, GLbyte const  * weights);
void glWeightsvARB(GLint size, GLshort const  * weights);
void glWeightivARB(GLint size, GLint const  * weights);
void glWeightfvARB(GLint size, GLfloat const  * weights);
void glWeightdvARB(GLint size, GLdouble const  * weights);
void glWeightubvARB(GLint size, GLubyte const  * weights);
void glWeightusvARB(GLint size, GLushort const  * weights);
void glWeightuivARB(GLint size, GLuint const  * weights);
void glWeightPointerARB(GLint size, GLenum type, GLsizei stride, const void * pointer);
void glVertexBlendARB(GLint count);
#endif /* GL_ARB_vertex_blend */
#ifndef GL_ARB_vertex_buffer_object
#define GL_ARB_vertex_buffer_object 1
constexpr GLenum GL_BUFFER_SIZE_ARB = 0x8764;
constexpr GLenum GL_BUFFER_USAGE_ARB = 0x8765;
constexpr GLenum GL_ARRAY_BUFFER_ARB = 0x8892;
constexpr GLenum GL_ELEMENT_ARRAY_BUFFER_ARB = 0x8893;
constexpr GLenum GL_ARRAY_BUFFER_BINDING_ARB = 0x8894;
constexpr GLenum GL_ELEMENT_ARRAY_BUFFER_BINDING_ARB = 0x8895;
constexpr GLenum GL_VERTEX_ARRAY_BUFFER_BINDING_ARB = 0x8896;
constexpr GLenum GL_NORMAL_ARRAY_BUFFER_BINDING_ARB = 0x8897;
constexpr GLenum GL_COLOR_ARRAY_BUFFER_BINDING_ARB = 0x8898;
constexpr GLenum GL_INDEX_ARRAY_BUFFER_BINDING_ARB = 0x8899;
constexpr GLenum GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING_ARB = 0x889A;
constexpr GLenum GL_EDGE_FLAG_ARRAY_BUFFER_BINDING_ARB = 0x889B;
constexpr GLenum GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING_ARB = 0x889C;
constexpr GLenum GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING_ARB = 0x889D;
constexpr GLenum GL_WEIGHT_ARRAY_BUFFER_BINDING_ARB = 0x889E;
constexpr GLenum GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING_ARB = 0x889F;
constexpr GLenum GL_READ_ONLY_ARB = 0x88B8;
constexpr GLenum GL_WRITE_ONLY_ARB = 0x88B9;
constexpr GLenum GL_READ_WRITE_ARB = 0x88BA;
constexpr GLenum GL_BUFFER_ACCESS_ARB = 0x88BB;
constexpr GLenum GL_BUFFER_MAPPED_ARB = 0x88BC;
constexpr GLenum GL_BUFFER_MAP_POINTER_ARB = 0x88BD;
constexpr GLenum GL_STREAM_DRAW_ARB = 0x88E0;
constexpr GLenum GL_STREAM_READ_ARB = 0x88E1;
constexpr GLenum GL_STREAM_COPY_ARB = 0x88E2;
constexpr GLenum GL_STATIC_DRAW_ARB = 0x88E4;
constexpr GLenum GL_STATIC_READ_ARB = 0x88E5;
constexpr GLenum GL_STATIC_COPY_ARB = 0x88E6;
constexpr GLenum GL_DYNAMIC_DRAW_ARB = 0x88E8;
constexpr GLenum GL_DYNAMIC_READ_ARB = 0x88E9;
constexpr GLenum GL_DYNAMIC_COPY_ARB = 0x88EA;
void glBindBufferARB(GLenum target, GLuint buffer);
void glDeleteBuffersARB(GLsizei n, GLuint const  * buffers);
void glGenBuffersARB(GLsizei n, GLuint * buffers);
GLboolean glIsBufferARB(GLuint buffer);
void glBufferDataARB(GLenum target, GLsizeiptrARB size, const void * data, GLenum usage);
void glBufferSubDataARB(GLenum target, GLintptrARB offset, GLsizeiptrARB size, const void * data);
void glGetBufferSubDataARB(GLenum target, GLintptrARB offset, GLsizeiptrARB size, void * data);
void * glMapBufferARB(GLenum target, GLenum access);
GLboolean glUnmapBufferARB(GLenum target);
void glGetBufferParameterivARB(GLenum target, GLenum pname, GLint * params);
void glGetBufferPointervARB(GLenum target, GLenum pname, void ** params);
#endif /* GL_ARB_vertex_buffer_object */
#ifndef GL_ARB_vertex_program
#define GL_ARB_vertex_program 1
constexpr GLenum GL_COLOR_SUM_ARB = 0x8458;
constexpr GLenum GL_VERTEX_PROGRAM_ARB = 0x8620;
constexpr GLenum GL_VERTEX_ATTRIB_ARRAY_ENABLED_ARB = 0x8622;
constexpr GLenum GL_VERTEX_ATTRIB_ARRAY_SIZE_ARB = 0x8623;
constexpr GLenum GL_VERTEX_ATTRIB_ARRAY_STRIDE_ARB = 0x8624;
constexpr GLenum GL_VERTEX_ATTRIB_ARRAY_TYPE_ARB = 0x8625;
constexpr GLenum GL_CURRENT_VERTEX_ATTRIB_ARB = 0x8626;
constexpr GLenum GL_VERTEX_PROGRAM_POINT_SIZE_ARB = 0x8642;
constexpr GLenum GL_VERTEX_PROGRAM_TWO_SIDE_ARB = 0x8643;
constexpr GLenum GL_VERTEX_ATTRIB_ARRAY_POINTER_ARB = 0x8645;
constexpr GLenum GL_MAX_VERTEX_ATTRIBS_ARB = 0x8869;
constexpr GLenum GL_VERTEX_ATTRIB_ARRAY_NORMALIZED_ARB = 0x886A;
constexpr GLenum GL_PROGRAM_ADDRESS_REGISTERS_ARB = 0x88B0;
constexpr GLenum GL_MAX_PROGRAM_ADDRESS_REGISTERS_ARB = 0x88B1;
constexpr GLenum GL_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB = 0x88B2;
constexpr GLenum GL_MAX_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB = 0x88B3;
void glVertexAttrib1dARB(GLuint index, GLdouble x);
void glVertexAttrib1dvARB(GLuint index, GLdouble const  * v);
void glVertexAttrib1fARB(GLuint index, GLfloat x);
void glVertexAttrib1fvARB(GLuint index, GLfloat const  * v);
void glVertexAttrib1sARB(GLuint index, GLshort x);
void glVertexAttrib1svARB(GLuint index, GLshort const  * v);
void glVertexAttrib2dARB(GLuint index, GLdouble x, GLdouble y);
void glVertexAttrib2dvARB(GLuint index, GLdouble const  * v);
void glVertexAttrib2fARB(GLuint index, GLfloat x, GLfloat y);
void glVertexAttrib2fvARB(GLuint index, GLfloat const  * v);
void glVertexAttrib2sARB(GLuint index, GLshort x, GLshort y);
void glVertexAttrib2svARB(GLuint index, GLshort const  * v);
void glVertexAttrib3dARB(GLuint index, GLdouble x, GLdouble y, GLdouble z);
void glVertexAttrib3dvARB(GLuint index, GLdouble const  * v);
void glVertexAttrib3fARB(GLuint index, GLfloat x, GLfloat y, GLfloat z);
void glVertexAttrib3fvARB(GLuint index, GLfloat const  * v);
void glVertexAttrib3sARB(GLuint index, GLshort x, GLshort y, GLshort z);
void glVertexAttrib3svARB(GLuint index, GLshort const  * v);
void glVertexAttrib4NbvARB(GLuint index, GLbyte const  * v);
void glVertexAttrib4NivARB(GLuint index, GLint const  * v);
void glVertexAttrib4NsvARB(GLuint index, GLshort const  * v);
void glVertexAttrib4NubARB(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
void glVertexAttrib4NubvARB(GLuint index, GLubyte const  * v);
void glVertexAttrib4NuivARB(GLuint index, GLuint const  * v);
void glVertexAttrib4NusvARB(GLuint index, GLushort const  * v);
void glVertexAttrib4bvARB(GLuint index, GLbyte const  * v);
void glVertexAttrib4dARB(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void glVertexAttrib4dvARB(GLuint index, GLdouble const  * v);
void glVertexAttrib4fARB(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void glVertexAttrib4fvARB(GLuint index, GLfloat const  * v);
void glVertexAttrib4ivARB(GLuint index, GLint const  * v);
void glVertexAttrib4sARB(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
void glVertexAttrib4svARB(GLuint index, GLshort const  * v);
void glVertexAttrib4ubvARB(GLuint index, GLubyte const  * v);
void glVertexAttrib4uivARB(GLuint index, GLuint const  * v);
void glVertexAttrib4usvARB(GLuint index, GLushort const  * v);
void glVertexAttribPointerARB(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void * pointer);
void glEnableVertexAttribArrayARB(GLuint index);
void glDisableVertexAttribArrayARB(GLuint index);
void glGetVertexAttribdvARB(GLuint index, GLenum pname, GLdouble * params);
void glGetVertexAttribfvARB(GLuint index, GLenum pname, GLfloat * params);
void glGetVertexAttribivARB(GLuint index, GLenum pname, GLint * params);
void glGetVertexAttribPointervARB(GLuint index, GLenum pname, void ** pointer);
#endif /* GL_ARB_vertex_program */
#ifndef GL_ARB_vertex_shader
#define GL_ARB_vertex_shader 1
constexpr GLenum GL_VERTEX_SHADER_ARB = 0x8B31;
constexpr GLenum GL_MAX_VERTEX_UNIFORM_COMPONENTS_ARB = 0x8B4A;
constexpr GLenum GL_MAX_VARYING_FLOATS_ARB = 0x8B4B;
constexpr GLenum GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS_ARB = 0x8B4C;
constexpr GLenum GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS_ARB = 0x8B4D;
constexpr GLenum GL_OBJECT_ACTIVE_ATTRIBUTES_ARB = 0x8B89;
constexpr GLenum GL_OBJECT_ACTIVE_ATTRIBUTE_MAX_LENGTH_ARB = 0x8B8A;
void glBindAttribLocationARB(GLhandleARB programObj, GLuint index, GLcharARB const  * name);
void glGetActiveAttribARB(GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei * length, GLint * size, GLenum * type, GLcharARB * name);
GLint glGetAttribLocationARB(GLhandleARB programObj, GLcharARB const  * name);
#endif /* GL_ARB_vertex_shader */
#ifndef GL_ARB_vertex_type_10f_11f_11f_rev
#define GL_ARB_vertex_type_10f_11f_11f_rev 1
#endif /* GL_ARB_vertex_type_10f_11f_11f_rev */
#ifndef GL_ARB_vertex_type_2_10_10_10_rev
#define GL_ARB_vertex_type_2_10_10_10_rev 1
constexpr GLenum GL_INT_2_10_10_10_REV = 0x8D9F;
void glVertexAttribP1ui(GLuint index, GLenum type, GLboolean normalized, GLuint value);
void glVertexAttribP1uiv(GLuint index, GLenum type, GLboolean normalized, GLuint const  * value);
void glVertexAttribP2ui(GLuint index, GLenum type, GLboolean normalized, GLuint value);
void glVertexAttribP2uiv(GLuint index, GLenum type, GLboolean normalized, GLuint const  * value);
void glVertexAttribP3ui(GLuint index, GLenum type, GLboolean normalized, GLuint value);
void glVertexAttribP3uiv(GLuint index, GLenum type, GLboolean normalized, GLuint const  * value);
void glVertexAttribP4ui(GLuint index, GLenum type, GLboolean normalized, GLuint value);
void glVertexAttribP4uiv(GLuint index, GLenum type, GLboolean normalized, GLuint const  * value);
void glVertexP2ui(GLenum type, GLuint value);
void glVertexP2uiv(GLenum type, GLuint const  * value);
void glVertexP3ui(GLenum type, GLuint value);
void glVertexP3uiv(GLenum type, GLuint const  * value);
void glVertexP4ui(GLenum type, GLuint value);
void glVertexP4uiv(GLenum type, GLuint const  * value);
void glTexCoordP1ui(GLenum type, GLuint coords);
void glTexCoordP1uiv(GLenum type, GLuint const  * coords);
void glTexCoordP2ui(GLenum type, GLuint coords);
void glTexCoordP2uiv(GLenum type, GLuint const  * coords);
void glTexCoordP3ui(GLenum type, GLuint coords);
void glTexCoordP3uiv(GLenum type, GLuint const  * coords);
void glTexCoordP4ui(GLenum type, GLuint coords);
void glTexCoordP4uiv(GLenum type, GLuint const  * coords);
void glMultiTexCoordP1ui(GLenum texture, GLenum type, GLuint coords);
void glMultiTexCoordP1uiv(GLenum texture, GLenum type, GLuint const  * coords);
void glMultiTexCoordP2ui(GLenum texture, GLenum type, GLuint coords);
void glMultiTexCoordP2uiv(GLenum texture, GLenum type, GLuint const  * coords);
void glMultiTexCoordP3ui(GLenum texture, GLenum type, GLuint coords);
void glMultiTexCoordP3uiv(GLenum texture, GLenum type, GLuint const  * coords);
void glMultiTexCoordP4ui(GLenum texture, GLenum type, GLuint coords);
void glMultiTexCoordP4uiv(GLenum texture, GLenum type, GLuint const  * coords);
void glNormalP3ui(GLenum type, GLuint coords);
void glNormalP3uiv(GLenum type, GLuint const  * coords);
void glColorP3ui(GLenum type, GLuint color);
void glColorP3uiv(GLenum type, GLuint const  * color);
void glColorP4ui(GLenum type, GLuint color);
void glColorP4uiv(GLenum type, GLuint const  * color);
void glSecondaryColorP3ui(GLenum type, GLuint color);
void glSecondaryColorP3uiv(GLenum type, GLuint const  * color);
#endif /* GL_ARB_vertex_type_2_10_10_10_rev */
#ifndef GL_ARB_viewport_array
#define GL_ARB_viewport_array 1
constexpr GLenum GL_MAX_VIEWPORTS = 0x825B;
constexpr GLenum GL_VIEWPORT_SUBPIXEL_BITS = 0x825C;
constexpr GLenum GL_VIEWPORT_BOUNDS_RANGE = 0x825D;
constexpr GLenum GL_LAYER_PROVOKING_VERTEX = 0x825E;
constexpr GLenum GL_VIEWPORT_INDEX_PROVOKING_VERTEX = 0x825F;
constexpr GLenum GL_UNDEFINED_VERTEX = 0x8260;
void glViewportArrayv(GLuint first, GLsizei count, GLfloat const  * v);
void glViewportIndexedf(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
void glViewportIndexedfv(GLuint index, GLfloat const  * v);
void glScissorArrayv(GLuint first, GLsizei count, GLint const  * v);
void glScissorIndexed(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
void glScissorIndexedv(GLuint index, GLint const  * v);
void glDepthRangeArrayv(GLuint first, GLsizei count, GLdouble const  * v);
void glDepthRangeIndexed(GLuint index, GLdouble n, GLdouble f);
void glGetFloati_v(GLenum target, GLuint index, GLfloat * data);
void glGetDoublei_v(GLenum target, GLuint index, GLdouble * data);
#endif /* GL_ARB_viewport_array */
#ifndef GL_ARB_window_pos
#define GL_ARB_window_pos 1
void glWindowPos2dARB(GLdouble x, GLdouble y);
void glWindowPos2dvARB(GLdouble const  * v);
void glWindowPos2fARB(GLfloat x, GLfloat y);
void glWindowPos2fvARB(GLfloat const  * v);
void glWindowPos2iARB(GLint x, GLint y);
void glWindowPos2ivARB(GLint const  * v);
void glWindowPos2sARB(GLshort x, GLshort y);
void glWindowPos2svARB(GLshort const  * v);
void glWindowPos3dARB(GLdouble x, GLdouble y, GLdouble z);
void glWindowPos3dvARB(GLdouble const  * v);
void glWindowPos3fARB(GLfloat x, GLfloat y, GLfloat z);
void glWindowPos3fvARB(GLfloat const  * v);
void glWindowPos3iARB(GLint x, GLint y, GLint z);
void glWindowPos3ivARB(GLint const  * v);
void glWindowPos3sARB(GLshort x, GLshort y, GLshort z);
void glWindowPos3svARB(GLshort const  * v);
#endif /* GL_ARB_window_pos */
#ifndef GL_EXT_422_pixels
#define GL_EXT_422_pixels 1
constexpr GLenum GL_422_EXT = 0x80CC;
constexpr GLenum GL_422_REV_EXT = 0x80CD;
constexpr GLenum GL_422_AVERAGE_EXT = 0x80CE;
constexpr GLenum GL_422_REV_AVERAGE_EXT = 0x80CF;
#endif /* GL_EXT_422_pixels */
#ifndef GL_EXT_EGL_image_storage
#define GL_EXT_EGL_image_storage 1
void glEGLImageTargetTexStorageEXT(GLenum target, GLeglImageOES image, GLint const * attrib_list);
void glEGLImageTargetTextureStorageEXT(GLuint texture, GLeglImageOES image, GLint const * attrib_list);
#endif /* GL_EXT_EGL_image_storage */
#ifndef GL_EXT_EGL_sync
#define GL_EXT_EGL_sync 1
#endif /* GL_EXT_EGL_sync */
#ifndef GL_EXT_abgr
#define GL_EXT_abgr 1
constexpr GLenum GL_ABGR_EXT = 0x8000;
#endif /* GL_EXT_abgr */
#ifndef GL_EXT_bgra
#define GL_EXT_bgra 1
constexpr GLenum GL_BGR_EXT = 0x80E0;
constexpr GLenum GL_BGRA_EXT = 0x80E1;
#endif /* GL_EXT_bgra */
#ifndef GL_EXT_bindable_uniform
#define GL_EXT_bindable_uniform 1
constexpr GLenum GL_MAX_VERTEX_BINDABLE_UNIFORMS_EXT = 0x8DE2;
constexpr GLenum GL_MAX_FRAGMENT_BINDABLE_UNIFORMS_EXT = 0x8DE3;
constexpr GLenum GL_MAX_GEOMETRY_BINDABLE_UNIFORMS_EXT = 0x8DE4;
constexpr GLenum GL_MAX_BINDABLE_UNIFORM_SIZE_EXT = 0x8DED;
constexpr GLenum GL_UNIFORM_BUFFER_EXT = 0x8DEE;
constexpr GLenum GL_UNIFORM_BUFFER_BINDING_EXT = 0x8DEF;
void glUniformBufferEXT(GLuint program, GLint location, GLuint buffer);
GLint glGetUniformBufferSizeEXT(GLuint program, GLint location);
GLintptr glGetUniformOffsetEXT(GLuint program, GLint location);
#endif /* GL_EXT_bindable_uniform */
#ifndef GL_EXT_blend_color
#define GL_EXT_blend_color 1
constexpr GLenum GL_CONSTANT_COLOR_EXT = 0x8001;
constexpr GLenum GL_ONE_MINUS_CONSTANT_COLOR_EXT = 0x8002;
constexpr GLenum GL_CONSTANT_ALPHA_EXT = 0x8003;
constexpr GLenum GL_ONE_MINUS_CONSTANT_ALPHA_EXT = 0x8004;
constexpr GLenum GL_BLEND_COLOR_EXT = 0x8005;
void glBlendColorEXT(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
#endif /* GL_EXT_blend_color */
#ifndef GL_EXT_blend_equation_separate
#define GL_EXT_blend_equation_separate 1
constexpr GLenum GL_BLEND_EQUATION_RGB_EXT = 0x8009;
constexpr GLenum GL_BLEND_EQUATION_ALPHA_EXT = 0x883D;
void glBlendEquationSeparateEXT(GLenum modeRGB, GLenum modeAlpha);
#endif /* GL_EXT_blend_equation_separate */
#ifndef GL_EXT_blend_func_separate
#define GL_EXT_blend_func_separate 1
constexpr GLenum GL_BLEND_DST_RGB_EXT = 0x80C8;
constexpr GLenum GL_BLEND_SRC_RGB_EXT = 0x80C9;
constexpr GLenum GL_BLEND_DST_ALPHA_EXT = 0x80CA;
constexpr GLenum GL_BLEND_SRC_ALPHA_EXT = 0x80CB;
void glBlendFuncSeparateEXT(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
#endif /* GL_EXT_blend_func_separate */
#ifndef GL_EXT_blend_logic_op
#define GL_EXT_blend_logic_op 1
#endif /* GL_EXT_blend_logic_op */
#ifndef GL_EXT_blend_minmax
#define GL_EXT_blend_minmax 1
constexpr GLenum GL_MIN_EXT = 0x8007;
constexpr GLenum GL_MAX_EXT = 0x8008;
constexpr GLenum GL_FUNC_ADD_EXT = 0x8006;
constexpr GLenum GL_BLEND_EQUATION_EXT = 0x8009;
void glBlendEquationEXT(GLenum mode);
#endif /* GL_EXT_blend_minmax */
#ifndef GL_EXT_blend_subtract
#define GL_EXT_blend_subtract 1
constexpr GLenum GL_FUNC_SUBTRACT_EXT = 0x800A;
constexpr GLenum GL_FUNC_REVERSE_SUBTRACT_EXT = 0x800B;
#endif /* GL_EXT_blend_subtract */
#ifndef GL_EXT_clip_volume_hint
#define GL_EXT_clip_volume_hint 1
constexpr GLenum GL_CLIP_VOLUME_CLIPPING_HINT_EXT = 0x80F0;
#endif /* GL_EXT_clip_volume_hint */
#ifndef GL_EXT_cmyka
#define GL_EXT_cmyka 1
constexpr GLenum GL_CMYK_EXT = 0x800C;
constexpr GLenum GL_CMYKA_EXT = 0x800D;
constexpr GLenum GL_PACK_CMYK_HINT_EXT = 0x800E;
constexpr GLenum GL_UNPACK_CMYK_HINT_EXT = 0x800F;
#endif /* GL_EXT_cmyka */
#ifndef GL_EXT_color_subtable
#define GL_EXT_color_subtable 1
void glColorSubTableEXT(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const void * data);
void glCopyColorSubTableEXT(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width);
#endif /* GL_EXT_color_subtable */
#ifndef GL_EXT_compiled_vertex_array
#define GL_EXT_compiled_vertex_array 1
constexpr GLenum GL_ARRAY_ELEMENT_LOCK_FIRST_EXT = 0x81A8;
constexpr GLenum GL_ARRAY_ELEMENT_LOCK_COUNT_EXT = 0x81A9;
void glLockArraysEXT(GLint first, GLsizei count);
void glUnlockArraysEXT();
#endif /* GL_EXT_compiled_vertex_array */
#ifndef GL_EXT_convolution
#define GL_EXT_convolution 1
constexpr GLenum GL_CONVOLUTION_1D_EXT = 0x8010;
constexpr GLenum GL_CONVOLUTION_2D_EXT = 0x8011;
constexpr GLenum GL_SEPARABLE_2D_EXT = 0x8012;
constexpr GLenum GL_CONVOLUTION_BORDER_MODE_EXT = 0x8013;
constexpr GLenum GL_CONVOLUTION_FILTER_SCALE_EXT = 0x8014;
constexpr GLenum GL_CONVOLUTION_FILTER_BIAS_EXT = 0x8015;
constexpr GLenum GL_REDUCE_EXT = 0x8016;
constexpr GLenum GL_CONVOLUTION_FORMAT_EXT = 0x8017;
constexpr GLenum GL_CONVOLUTION_WIDTH_EXT = 0x8018;
constexpr GLenum GL_CONVOLUTION_HEIGHT_EXT = 0x8019;
constexpr GLenum GL_MAX_CONVOLUTION_WIDTH_EXT = 0x801A;
constexpr GLenum GL_MAX_CONVOLUTION_HEIGHT_EXT = 0x801B;
constexpr GLenum GL_POST_CONVOLUTION_RED_SCALE_EXT = 0x801C;
constexpr GLenum GL_POST_CONVOLUTION_GREEN_SCALE_EXT = 0x801D;
constexpr GLenum GL_POST_CONVOLUTION_BLUE_SCALE_EXT = 0x801E;
constexpr GLenum GL_POST_CONVOLUTION_ALPHA_SCALE_EXT = 0x801F;
constexpr GLenum GL_POST_CONVOLUTION_RED_BIAS_EXT = 0x8020;
constexpr GLenum GL_POST_CONVOLUTION_GREEN_BIAS_EXT = 0x8021;
constexpr GLenum GL_POST_CONVOLUTION_BLUE_BIAS_EXT = 0x8022;
constexpr GLenum GL_POST_CONVOLUTION_ALPHA_BIAS_EXT = 0x8023;
void glConvolutionFilter1DEXT(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void * image);
void glConvolutionFilter2DEXT(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * image);
void glConvolutionParameterfEXT(GLenum target, GLenum pname, GLfloat params);
void glConvolutionParameterfvEXT(GLenum target, GLenum pname, GLfloat const  * params);
void glConvolutionParameteriEXT(GLenum target, GLenum pname, GLint params);
void glConvolutionParameterivEXT(GLenum target, GLenum pname, GLint const  * params);
void glCopyConvolutionFilter1DEXT(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
void glCopyConvolutionFilter2DEXT(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height);
void glGetConvolutionFilterEXT(GLenum target, GLenum format, GLenum type, void * image);
void glGetConvolutionParameterfvEXT(GLenum target, GLenum pname, GLfloat * params);
void glGetConvolutionParameterivEXT(GLenum target, GLenum pname, GLint * params);
void glGetSeparableFilterEXT(GLenum target, GLenum format, GLenum type, void * row, void * column, void * span);
void glSeparableFilter2DEXT(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * row, const void * column);
#endif /* GL_EXT_convolution */
#ifndef GL_EXT_coordinate_frame
#define GL_EXT_coordinate_frame 1
constexpr GLenum GL_TANGENT_ARRAY_EXT = 0x8439;
constexpr GLenum GL_BINORMAL_ARRAY_EXT = 0x843A;
constexpr GLenum GL_CURRENT_TANGENT_EXT = 0x843B;
constexpr GLenum GL_CURRENT_BINORMAL_EXT = 0x843C;
constexpr GLenum GL_TANGENT_ARRAY_TYPE_EXT = 0x843E;
constexpr GLenum GL_TANGENT_ARRAY_STRIDE_EXT = 0x843F;
constexpr GLenum GL_BINORMAL_ARRAY_TYPE_EXT = 0x8440;
constexpr GLenum GL_BINORMAL_ARRAY_STRIDE_EXT = 0x8441;
constexpr GLenum GL_TANGENT_ARRAY_POINTER_EXT = 0x8442;
constexpr GLenum GL_BINORMAL_ARRAY_POINTER_EXT = 0x8443;
constexpr GLenum GL_MAP1_TANGENT_EXT = 0x8444;
constexpr GLenum GL_MAP2_TANGENT_EXT = 0x8445;
constexpr GLenum GL_MAP1_BINORMAL_EXT = 0x8446;
constexpr GLenum GL_MAP2_BINORMAL_EXT = 0x8447;
void glTangent3bEXT(GLbyte tx, GLbyte ty, GLbyte tz);
void glTangent3bvEXT(GLbyte const  * v);
void glTangent3dEXT(GLdouble tx, GLdouble ty, GLdouble tz);
void glTangent3dvEXT(GLdouble const  * v);
void glTangent3fEXT(GLfloat tx, GLfloat ty, GLfloat tz);
void glTangent3fvEXT(GLfloat const  * v);
void glTangent3iEXT(GLint tx, GLint ty, GLint tz);
void glTangent3ivEXT(GLint const  * v);
void glTangent3sEXT(GLshort tx, GLshort ty, GLshort tz);
void glTangent3svEXT(GLshort const  * v);
void glBinormal3bEXT(GLbyte bx, GLbyte by, GLbyte bz);
void glBinormal3bvEXT(GLbyte const  * v);
void glBinormal3dEXT(GLdouble bx, GLdouble by, GLdouble bz);
void glBinormal3dvEXT(GLdouble const  * v);
void glBinormal3fEXT(GLfloat bx, GLfloat by, GLfloat bz);
void glBinormal3fvEXT(GLfloat const  * v);
void glBinormal3iEXT(GLint bx, GLint by, GLint bz);
void glBinormal3ivEXT(GLint const  * v);
void glBinormal3sEXT(GLshort bx, GLshort by, GLshort bz);
void glBinormal3svEXT(GLshort const  * v);
void glTangentPointerEXT(GLenum type, GLsizei stride, const void * pointer);
void glBinormalPointerEXT(GLenum type, GLsizei stride, const void * pointer);
#endif /* GL_EXT_coordinate_frame */
#ifndef GL_EXT_copy_texture
#define GL_EXT_copy_texture 1
void glCopyTexImage1DEXT(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
void glCopyTexImage2DEXT(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
void glCopyTexSubImage1DEXT(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
void glCopyTexSubImage2DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
void glCopyTexSubImage3DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#endif /* GL_EXT_copy_texture */
#ifndef GL_EXT_cull_vertex
#define GL_EXT_cull_vertex 1
constexpr GLenum GL_CULL_VERTEX_EXT = 0x81AA;
constexpr GLenum GL_CULL_VERTEX_EYE_POSITION_EXT = 0x81AB;
constexpr GLenum GL_CULL_VERTEX_OBJECT_POSITION_EXT = 0x81AC;
void glCullParameterdvEXT(GLenum pname, GLdouble * params);
void glCullParameterfvEXT(GLenum pname, GLfloat * params);
#endif /* GL_EXT_cull_vertex */
#ifndef GL_EXT_debug_label
#define GL_EXT_debug_label 1
constexpr GLenum GL_PROGRAM_PIPELINE_OBJECT_EXT = 0x8A4F;
constexpr GLenum GL_PROGRAM_OBJECT_EXT = 0x8B40;
constexpr GLenum GL_SHADER_OBJECT_EXT = 0x8B48;
constexpr GLenum GL_BUFFER_OBJECT_EXT = 0x9151;
constexpr GLenum GL_QUERY_OBJECT_EXT = 0x9153;
constexpr GLenum GL_VERTEX_ARRAY_OBJECT_EXT = 0x9154;
constexpr GLenum GL_SAMPLER = 0x82E6;
void glLabelObjectEXT(GLenum type, GLuint object, GLsizei length, GLchar const  * label);
void glGetObjectLabelEXT(GLenum type, GLuint object, GLsizei bufSize, GLsizei * length, GLchar * label);
#endif /* GL_EXT_debug_label */
#ifndef GL_EXT_debug_marker
#define GL_EXT_debug_marker 1
void glInsertEventMarkerEXT(GLsizei length, GLchar const  * marker);
void glPushGroupMarkerEXT(GLsizei length, GLchar const  * marker);
void glPopGroupMarkerEXT();
#endif /* GL_EXT_debug_marker */
#ifndef GL_EXT_depth_bounds_test
#define GL_EXT_depth_bounds_test 1
constexpr GLenum GL_DEPTH_BOUNDS_TEST_EXT = 0x8890;
constexpr GLenum GL_DEPTH_BOUNDS_EXT = 0x8891;
void glDepthBoundsEXT(GLclampd zmin, GLclampd zmax);
#endif /* GL_EXT_depth_bounds_test */
#ifndef GL_EXT_direct_state_access
#define GL_EXT_direct_state_access 1
constexpr GLenum GL_PROGRAM_MATRIX_EXT = 0x8E2D;
constexpr GLenum GL_TRANSPOSE_PROGRAM_MATRIX_EXT = 0x8E2E;
constexpr GLenum GL_PROGRAM_MATRIX_STACK_DEPTH_EXT = 0x8E2F;
void glMatrixLoadfEXT(GLenum mode, GLfloat const  * m);
void glMatrixLoaddEXT(GLenum mode, GLdouble const  * m);
void glMatrixMultfEXT(GLenum mode, GLfloat const  * m);
void glMatrixMultdEXT(GLenum mode, GLdouble const  * m);
void glMatrixLoadIdentityEXT(GLenum mode);
void glMatrixRotatefEXT(GLenum mode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
void glMatrixRotatedEXT(GLenum mode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
void glMatrixScalefEXT(GLenum mode, GLfloat x, GLfloat y, GLfloat z);
void glMatrixScaledEXT(GLenum mode, GLdouble x, GLdouble y, GLdouble z);
void glMatrixTranslatefEXT(GLenum mode, GLfloat x, GLfloat y, GLfloat z);
void glMatrixTranslatedEXT(GLenum mode, GLdouble x, GLdouble y, GLdouble z);
void glMatrixFrustumEXT(GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
void glMatrixOrthoEXT(GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
void glMatrixPopEXT(GLenum mode);
void glMatrixPushEXT(GLenum mode);
void glClientAttribDefaultEXT(GLbitfield mask);
void glPushClientAttribDefaultEXT(GLbitfield mask);
void glTextureParameterfEXT(GLuint texture, GLenum target, GLenum pname, GLfloat param);
void glTextureParameterfvEXT(GLuint texture, GLenum target, GLenum pname, GLfloat const  * params);
void glTextureParameteriEXT(GLuint texture, GLenum target, GLenum pname, GLint param);
void glTextureParameterivEXT(GLuint texture, GLenum target, GLenum pname, GLint const  * params);
void glTextureImage1DEXT(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void * pixels);
void glTextureImage2DEXT(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void * pixels);
void glTextureSubImage1DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void * pixels);
void glTextureSubImage2DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels);
void glCopyTextureImage1DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
void glCopyTextureImage2DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
void glCopyTextureSubImage1DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
void glCopyTextureSubImage2DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
void glGetTextureImageEXT(GLuint texture, GLenum target, GLint level, GLenum format, GLenum type, void * pixels);
void glGetTextureParameterfvEXT(GLuint texture, GLenum target, GLenum pname, GLfloat * params);
void glGetTextureParameterivEXT(GLuint texture, GLenum target, GLenum pname, GLint * params);
void glGetTextureLevelParameterfvEXT(GLuint texture, GLenum target, GLint level, GLenum pname, GLfloat * params);
void glGetTextureLevelParameterivEXT(GLuint texture, GLenum target, GLint level, GLenum pname, GLint * params);
void glTextureImage3DEXT(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void * pixels);
void glTextureSubImage3DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels);
void glCopyTextureSubImage3DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
void glBindMultiTextureEXT(GLenum texunit, GLenum target, GLuint texture);
void glMultiTexCoordPointerEXT(GLenum texunit, GLint size, GLenum type, GLsizei stride, const void * pointer);
void glMultiTexEnvfEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat param);
void glMultiTexEnvfvEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat const  * params);
void glMultiTexEnviEXT(GLenum texunit, GLenum target, GLenum pname, GLint param);
void glMultiTexEnvivEXT(GLenum texunit, GLenum target, GLenum pname, GLint const  * params);
void glMultiTexGendEXT(GLenum texunit, GLenum coord, GLenum pname, GLdouble param);
void glMultiTexGendvEXT(GLenum texunit, GLenum coord, GLenum pname, GLdouble const  * params);
void glMultiTexGenfEXT(GLenum texunit, GLenum coord, GLenum pname, GLfloat param);
void glMultiTexGenfvEXT(GLenum texunit, GLenum coord, GLenum pname, GLfloat const  * params);
void glMultiTexGeniEXT(GLenum texunit, GLenum coord, GLenum pname, GLint param);
void glMultiTexGenivEXT(GLenum texunit, GLenum coord, GLenum pname, GLint const  * params);
void glGetMultiTexEnvfvEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat * params);
void glGetMultiTexEnvivEXT(GLenum texunit, GLenum target, GLenum pname, GLint * params);
void glGetMultiTexGendvEXT(GLenum texunit, GLenum coord, GLenum pname, GLdouble * params);
void glGetMultiTexGenfvEXT(GLenum texunit, GLenum coord, GLenum pname, GLfloat * params);
void glGetMultiTexGenivEXT(GLenum texunit, GLenum coord, GLenum pname, GLint * params);
void glMultiTexParameteriEXT(GLenum texunit, GLenum target, GLenum pname, GLint param);
void glMultiTexParameterivEXT(GLenum texunit, GLenum target, GLenum pname, GLint const  * params);
void glMultiTexParameterfEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat param);
void glMultiTexParameterfvEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat const  * params);
void glMultiTexImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void * pixels);
void glMultiTexImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void * pixels);
void glMultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void * pixels);
void glMultiTexSubImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels);
void glCopyMultiTexImage1DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
void glCopyMultiTexImage2DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
void glCopyMultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
void glCopyMultiTexSubImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
void glGetMultiTexImageEXT(GLenum texunit, GLenum target, GLint level, GLenum format, GLenum type, void * pixels);
void glGetMultiTexParameterfvEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat * params);
void glGetMultiTexParameterivEXT(GLenum texunit, GLenum target, GLenum pname, GLint * params);
void glGetMultiTexLevelParameterfvEXT(GLenum texunit, GLenum target, GLint level, GLenum pname, GLfloat * params);
void glGetMultiTexLevelParameterivEXT(GLenum texunit, GLenum target, GLint level, GLenum pname, GLint * params);
void glMultiTexImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void * pixels);
void glMultiTexSubImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels);
void glCopyMultiTexSubImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
void glEnableClientStateIndexedEXT(GLenum array, GLuint index);
void glDisableClientStateIndexedEXT(GLenum array, GLuint index);
void glGetFloatIndexedvEXT(GLenum target, GLuint index, GLfloat * data);
void glGetDoubleIndexedvEXT(GLenum target, GLuint index, GLdouble * data);
void glGetPointerIndexedvEXT(GLenum target, GLuint index, void ** data);
void glEnableIndexedEXT(GLenum target, GLuint index);
void glDisableIndexedEXT(GLenum target, GLuint index);
GLboolean glIsEnabledIndexedEXT(GLenum target, GLuint index);
void glGetIntegerIndexedvEXT(GLenum target, GLuint index, GLint * data);
void glGetBooleanIndexedvEXT(GLenum target, GLuint index, GLboolean * data);
void glCompressedTextureImage3DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void * bits);
void glCompressedTextureImage2DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void * bits);
void glCompressedTextureImage1DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void * bits);
void glCompressedTextureSubImage3DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * bits);
void glCompressedTextureSubImage2DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * bits);
void glCompressedTextureSubImage1DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * bits);
void glGetCompressedTextureImageEXT(GLuint texture, GLenum target, GLint lod, void * img);
void glCompressedMultiTexImage3DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void * bits);
void glCompressedMultiTexImage2DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void * bits);
void glCompressedMultiTexImage1DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void * bits);
void glCompressedMultiTexSubImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * bits);
void glCompressedMultiTexSubImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * bits);
void glCompressedMultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * bits);
void glGetCompressedMultiTexImageEXT(GLenum texunit, GLenum target, GLint lod, void * img);
void glMatrixLoadTransposefEXT(GLenum mode, GLfloat const  * m);
void glMatrixLoadTransposedEXT(GLenum mode, GLdouble const  * m);
void glMatrixMultTransposefEXT(GLenum mode, GLfloat const  * m);
void glMatrixMultTransposedEXT(GLenum mode, GLdouble const  * m);
void glNamedBufferDataEXT(GLuint buffer, GLsizeiptr size, const void * data, GLenum usage);
void glNamedBufferSubDataEXT(GLuint buffer, GLintptr offset, GLsizeiptr size, const void * data);
void * glMapNamedBufferEXT(GLuint buffer, GLenum access);
GLboolean glUnmapNamedBufferEXT(GLuint buffer);
void glGetNamedBufferParameterivEXT(GLuint buffer, GLenum pname, GLint * params);
void glGetNamedBufferPointervEXT(GLuint buffer, GLenum pname, void ** params);
void glGetNamedBufferSubDataEXT(GLuint buffer, GLintptr offset, GLsizeiptr size, void * data);
void glProgramUniform1fEXT(GLuint program, GLint location, GLfloat v0);
void glProgramUniform2fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1);
void glProgramUniform3fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
void glProgramUniform4fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
void glProgramUniform1iEXT(GLuint program, GLint location, GLint v0);
void glProgramUniform2iEXT(GLuint program, GLint location, GLint v0, GLint v1);
void glProgramUniform3iEXT(GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
void glProgramUniform4iEXT(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
void glProgramUniform1fvEXT(GLuint program, GLint location, GLsizei count, GLfloat const  * value);
void glProgramUniform2fvEXT(GLuint program, GLint location, GLsizei count, GLfloat const  * value);
void glProgramUniform3fvEXT(GLuint program, GLint location, GLsizei count, GLfloat const  * value);
void glProgramUniform4fvEXT(GLuint program, GLint location, GLsizei count, GLfloat const  * value);
void glProgramUniform1ivEXT(GLuint program, GLint location, GLsizei count, GLint const  * value);
void glProgramUniform2ivEXT(GLuint program, GLint location, GLsizei count, GLint const  * value);
void glProgramUniform3ivEXT(GLuint program, GLint location, GLsizei count, GLint const  * value);
void glProgramUniform4ivEXT(GLuint program, GLint location, GLsizei count, GLint const  * value);
void glProgramUniformMatrix2fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value);
void glProgramUniformMatrix3fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value);
void glProgramUniformMatrix4fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value);
void glProgramUniformMatrix2x3fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value);
void glProgramUniformMatrix3x2fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value);
void glProgramUniformMatrix2x4fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value);
void glProgramUniformMatrix4x2fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value);
void glProgramUniformMatrix3x4fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value);
void glProgramUniformMatrix4x3fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const  * value);
void glTextureBufferEXT(GLuint texture, GLenum target, GLenum internalformat, GLuint buffer);
void glMultiTexBufferEXT(GLenum texunit, GLenum target, GLenum internalformat, GLuint buffer);
void glTextureParameterIivEXT(GLuint texture, GLenum target, GLenum pname, GLint const  * params);
void glTextureParameterIuivEXT(GLuint texture, GLenum target, GLenum pname, GLuint const  * params);
void glGetTextureParameterIivEXT(GLuint texture, GLenum target, GLenum pname, GLint * params);
void glGetTextureParameterIuivEXT(GLuint texture, GLenum target, GLenum pname, GLuint * params);
void glMultiTexParameterIivEXT(GLenum texunit, GLenum target, GLenum pname, GLint const  * params);
void glMultiTexParameterIuivEXT(GLenum texunit, GLenum target, GLenum pname, GLuint const  * params);
void glGetMultiTexParameterIivEXT(GLenum texunit, GLenum target, GLenum pname, GLint * params);
void glGetMultiTexParameterIuivEXT(GLenum texunit, GLenum target, GLenum pname, GLuint * params);
void glProgramUniform1uiEXT(GLuint program, GLint location, GLuint v0);
void glProgramUniform2uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1);
void glProgramUniform3uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
void glProgramUniform4uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
void glProgramUniform1uivEXT(GLuint program, GLint location, GLsizei count, GLuint const  * value);
void glProgramUniform2uivEXT(GLuint program, GLint location, GLsizei count, GLuint const  * value);
void glProgramUniform3uivEXT(GLuint program, GLint location, GLsizei count, GLuint const  * value);
void glProgramUniform4uivEXT(GLuint program, GLint location, GLsizei count, GLuint const  * value);
void glNamedProgramLocalParameters4fvEXT(GLuint program, GLenum target, GLuint index, GLsizei count, GLfloat const  * params);
void glNamedProgramLocalParameterI4iEXT(GLuint program, GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
void glNamedProgramLocalParameterI4ivEXT(GLuint program, GLenum target, GLuint index, GLint const  * params);
void glNamedProgramLocalParametersI4ivEXT(GLuint program, GLenum target, GLuint index, GLsizei count, GLint const  * params);
void glNamedProgramLocalParameterI4uiEXT(GLuint program, GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
void glNamedProgramLocalParameterI4uivEXT(GLuint program, GLenum target, GLuint index, GLuint const  * params);
void glNamedProgramLocalParametersI4uivEXT(GLuint program, GLenum target, GLuint index, GLsizei count, GLuint const  * params);
void glGetNamedProgramLocalParameterIivEXT(GLuint program, GLenum target, GLuint index, GLint * params);
void glGetNamedProgramLocalParameterIuivEXT(GLuint program, GLenum target, GLuint index, GLuint * params);
void glEnableClientStateiEXT(GLenum array, GLuint index);
void glDisableClientStateiEXT(GLenum array, GLuint index);
void glGetFloati_vEXT(GLenum pname, GLuint index, GLfloat * params);
void glGetDoublei_vEXT(GLenum pname, GLuint index, GLdouble * params);
void glGetPointeri_vEXT(GLenum pname, GLuint index, void ** params);
void glNamedProgramStringEXT(GLuint program, GLenum target, GLenum format, GLsizei len, const void * string);
void glNamedProgramLocalParameter4dEXT(GLuint program, GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void glNamedProgramLocalParameter4dvEXT(GLuint program, GLenum target, GLuint index, GLdouble const  * params);
void glNamedProgramLocalParameter4fEXT(GLuint program, GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void glNamedProgramLocalParameter4fvEXT(GLuint program, GLenum target, GLuint index, GLfloat const  * params);
void glGetNamedProgramLocalParameterdvEXT(GLuint program, GLenum target, GLuint index, GLdouble * params);
void glGetNamedProgramLocalParameterfvEXT(GLuint program, GLenum target, GLuint index, GLfloat * params);
void glGetNamedProgramivEXT(GLuint program, GLenum target, GLenum pname, GLint * params);
void glGetNamedProgramStringEXT(GLuint program, GLenum target, GLenum pname, void * string);
void glNamedRenderbufferStorageEXT(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
void glGetNamedRenderbufferParameterivEXT(GLuint renderbuffer, GLenum pname, GLint * params);
void glNamedRenderbufferStorageMultisampleEXT(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
void glNamedRenderbufferStorageMultisampleCoverageEXT(GLuint renderbuffer, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height);
GLenum glCheckNamedFramebufferStatusEXT(GLuint framebuffer, GLenum target);
void glNamedFramebufferTexture1DEXT(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
void glNamedFramebufferTexture2DEXT(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
void glNamedFramebufferTexture3DEXT(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
void glNamedFramebufferRenderbufferEXT(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
void glGetNamedFramebufferAttachmentParameterivEXT(GLuint framebuffer, GLenum attachment, GLenum pname, GLint * params);
void glGenerateTextureMipmapEXT(GLuint texture, GLenum target);
void glGenerateMultiTexMipmapEXT(GLenum texunit, GLenum target);
void glFramebufferDrawBufferEXT(GLuint framebuffer, GLenum mode);
void glFramebufferDrawBuffersEXT(GLuint framebuffer, GLsizei n, GLenum const  * bufs);
void glFramebufferReadBufferEXT(GLuint framebuffer, GLenum mode);
void glGetFramebufferParameterivEXT(GLuint framebuffer, GLenum pname, GLint * params);
void glNamedCopyBufferSubDataEXT(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
void glNamedFramebufferTextureEXT(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
void glNamedFramebufferTextureLayerEXT(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
void glNamedFramebufferTextureFaceEXT(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLenum face);
void glTextureRenderbufferEXT(GLuint texture, GLenum target, GLuint renderbuffer);
void glMultiTexRenderbufferEXT(GLenum texunit, GLenum target, GLuint renderbuffer);
void glVertexArrayVertexOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
void glVertexArrayColorOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
void glVertexArrayEdgeFlagOffsetEXT(GLuint vaobj, GLuint buffer, GLsizei stride, GLintptr offset);
void glVertexArrayIndexOffsetEXT(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
void glVertexArrayNormalOffsetEXT(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
void glVertexArrayTexCoordOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
void glVertexArrayMultiTexCoordOffsetEXT(GLuint vaobj, GLuint buffer, GLenum texunit, GLint size, GLenum type, GLsizei stride, GLintptr offset);
void glVertexArrayFogCoordOffsetEXT(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
void glVertexArraySecondaryColorOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
void glVertexArrayVertexAttribOffsetEXT(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLintptr offset);
void glVertexArrayVertexAttribIOffsetEXT(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset);
void glEnableVertexArrayEXT(GLuint vaobj, GLenum array);
void glDisableVertexArrayEXT(GLuint vaobj, GLenum array);
void glEnableVertexArrayAttribEXT(GLuint vaobj, GLuint index);
void glDisableVertexArrayAttribEXT(GLuint vaobj, GLuint index);
void glGetVertexArrayIntegervEXT(GLuint vaobj, GLenum pname, GLint * param);
void glGetVertexArrayPointervEXT(GLuint vaobj, GLenum pname, void ** param);
void glGetVertexArrayIntegeri_vEXT(GLuint vaobj, GLuint index, GLenum pname, GLint * param);
void glGetVertexArrayPointeri_vEXT(GLuint vaobj, GLuint index, GLenum pname, void ** param);
void * glMapNamedBufferRangeEXT(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
void glFlushMappedNamedBufferRangeEXT(GLuint buffer, GLintptr offset, GLsizeiptr length);
void glNamedBufferStorageEXT(GLuint buffer, GLsizeiptr size, const void * data, GLbitfield flags);
void glClearNamedBufferDataEXT(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void * data);
void glClearNamedBufferSubDataEXT(GLuint buffer, GLenum internalformat, GLsizeiptr offset, GLsizeiptr size, GLenum format, GLenum type, const void * data);
void glNamedFramebufferParameteriEXT(GLuint framebuffer, GLenum pname, GLint param);
void glGetNamedFramebufferParameterivEXT(GLuint framebuffer, GLenum pname, GLint * params);
void glProgramUniform1dEXT(GLuint program, GLint location, GLdouble x);
void glProgramUniform2dEXT(GLuint program, GLint location, GLdouble x, GLdouble y);
void glProgramUniform3dEXT(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z);
void glProgramUniform4dEXT(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void glProgramUniform1dvEXT(GLuint program, GLint location, GLsizei count, GLdouble const  * value);
void glProgramUniform2dvEXT(GLuint program, GLint location, GLsizei count, GLdouble const  * value);
void glProgramUniform3dvEXT(GLuint program, GLint location, GLsizei count, GLdouble const  * value);
void glProgramUniform4dvEXT(GLuint program, GLint location, GLsizei count, GLdouble const  * value);
void glProgramUniformMatrix2dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble const  * value);
void glProgramUniformMatrix3dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble const  * value);
void glProgramUniformMatrix4dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble const  * value);
void glProgramUniformMatrix2x3dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble const  * value);
void glProgramUniformMatrix2x4dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble const  * value);
void glProgramUniformMatrix3x2dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble const  * value);
void glProgramUniformMatrix3x4dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble const  * value);
void glProgramUniformMatrix4x2dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble const  * value);
void glProgramUniformMatrix4x3dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble const  * value);
void glTextureBufferRangeEXT(GLuint texture, GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
void glTextureStorage1DEXT(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
void glTextureStorage2DEXT(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
void glTextureStorage3DEXT(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
void glTextureStorage2DMultisampleEXT(GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
void glTextureStorage3DMultisampleEXT(GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
void glVertexArrayBindVertexBufferEXT(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
void glVertexArrayVertexAttribFormatEXT(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
void glVertexArrayVertexAttribIFormatEXT(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
void glVertexArrayVertexAttribLFormatEXT(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
void glVertexArrayVertexAttribBindingEXT(GLuint vaobj, GLuint attribindex, GLuint bindingindex);
void glVertexArrayVertexBindingDivisorEXT(GLuint vaobj, GLuint bindingindex, GLuint divisor);
void glVertexArrayVertexAttribLOffsetEXT(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset);
void glTexturePageCommitmentEXT(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit);
void glVertexArrayVertexAttribDivisorEXT(GLuint vaobj, GLuint index, GLuint divisor);
#endif /* GL_EXT_direct_state_access */
#ifndef GL_EXT_draw_buffers2
#define GL_EXT_draw_buffers2 1
void glColorMaskIndexedEXT(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
#endif /* GL_EXT_draw_buffers2 */
#ifndef GL_EXT_draw_instanced
#define GL_EXT_draw_instanced 1
void glDrawArraysInstancedEXT(GLenum mode, GLint start, GLsizei count, GLsizei primcount);
void glDrawElementsInstancedEXT(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei primcount);
#endif /* GL_EXT_draw_instanced */
#ifndef GL_EXT_draw_range_elements
#define GL_EXT_draw_range_elements 1
constexpr GLenum GL_MAX_ELEMENTS_VERTICES_EXT = 0x80E8;
constexpr GLenum GL_MAX_ELEMENTS_INDICES_EXT = 0x80E9;
void glDrawRangeElementsEXT(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices);
#endif /* GL_EXT_draw_range_elements */
#ifndef GL_EXT_external_buffer
#define GL_EXT_external_buffer 1
void glBufferStorageExternalEXT(GLenum target, GLintptr offset, GLsizeiptr size, GLeglClientBufferEXT clientBuffer, GLbitfield flags);
void glNamedBufferStorageExternalEXT(GLuint buffer, GLintptr offset, GLsizeiptr size, GLeglClientBufferEXT clientBuffer, GLbitfield flags);
#endif /* GL_EXT_external_buffer */
#ifndef GL_EXT_fog_coord
#define GL_EXT_fog_coord 1
constexpr GLenum GL_FOG_COORDINATE_SOURCE_EXT = 0x8450;
constexpr GLenum GL_FOG_COORDINATE_EXT = 0x8451;
constexpr GLenum GL_FRAGMENT_DEPTH_EXT = 0x8452;
constexpr GLenum GL_CURRENT_FOG_COORDINATE_EXT = 0x8453;
constexpr GLenum GL_FOG_COORDINATE_ARRAY_TYPE_EXT = 0x8454;
constexpr GLenum GL_FOG_COORDINATE_ARRAY_STRIDE_EXT = 0x8455;
constexpr GLenum GL_FOG_COORDINATE_ARRAY_POINTER_EXT = 0x8456;
constexpr GLenum GL_FOG_COORDINATE_ARRAY_EXT = 0x8457;
void glFogCoordfEXT(GLfloat coord);
void glFogCoordfvEXT(GLfloat const  * coord);
void glFogCoorddEXT(GLdouble coord);
void glFogCoorddvEXT(GLdouble const  * coord);
void glFogCoordPointerEXT(GLenum type, GLsizei stride, const void * pointer);
#endif /* GL_EXT_fog_coord */
#ifndef GL_EXT_framebuffer_blit
#define GL_EXT_framebuffer_blit 1
constexpr GLenum GL_READ_FRAMEBUFFER_EXT = 0x8CA8;
constexpr GLenum GL_DRAW_FRAMEBUFFER_EXT = 0x8CA9;
constexpr GLenum GL_DRAW_FRAMEBUFFER_BINDING_EXT = 0x8CA6;
constexpr GLenum GL_READ_FRAMEBUFFER_BINDING_EXT = 0x8CAA;
void glBlitFramebufferEXT(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
#endif /* GL_EXT_framebuffer_blit */
#ifndef GL_EXT_framebuffer_multisample
#define GL_EXT_framebuffer_multisample 1
constexpr GLenum GL_RENDERBUFFER_SAMPLES_EXT = 0x8CAB;
constexpr GLenum GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE_EXT = 0x8D56;
constexpr GLenum GL_MAX_SAMPLES_EXT = 0x8D57;
void glRenderbufferStorageMultisampleEXT(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
#endif /* GL_EXT_framebuffer_multisample */
#ifndef GL_EXT_framebuffer_multisample_blit_scaled
#define GL_EXT_framebuffer_multisample_blit_scaled 1
constexpr GLenum GL_SCALED_RESOLVE_FASTEST_EXT = 0x90BA;
constexpr GLenum GL_SCALED_RESOLVE_NICEST_EXT = 0x90BB;
#endif /* GL_EXT_framebuffer_multisample_blit_scaled */
#ifndef GL_EXT_framebuffer_object
#define GL_EXT_framebuffer_object 1
constexpr GLenum GL_INVALID_FRAMEBUFFER_OPERATION_EXT = 0x0506;
constexpr GLenum GL_MAX_RENDERBUFFER_SIZE_EXT = 0x84E8;
constexpr GLenum GL_FRAMEBUFFER_BINDING_EXT = 0x8CA6;
constexpr GLenum GL_RENDERBUFFER_BINDING_EXT = 0x8CA7;
constexpr GLenum GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE_EXT = 0x8CD0;
constexpr GLenum GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME_EXT = 0x8CD1;
constexpr GLenum GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL_EXT = 0x8CD2;
constexpr GLenum GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE_EXT = 0x8CD3;
constexpr GLenum GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_3D_ZOFFSET_EXT = 0x8CD4;
constexpr GLenum GL_FRAMEBUFFER_COMPLETE_EXT = 0x8CD5;
constexpr GLenum GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT_EXT = 0x8CD6;
constexpr GLenum GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT_EXT = 0x8CD7;
constexpr GLenum GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS_EXT = 0x8CD9;
constexpr GLenum GL_FRAMEBUFFER_INCOMPLETE_FORMATS_EXT = 0x8CDA;
constexpr GLenum GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER_EXT = 0x8CDB;
constexpr GLenum GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER_EXT = 0x8CDC;
constexpr GLenum GL_FRAMEBUFFER_UNSUPPORTED_EXT = 0x8CDD;
constexpr GLenum GL_MAX_COLOR_ATTACHMENTS_EXT = 0x8CDF;
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
constexpr GLenum GL_DEPTH_ATTACHMENT_EXT = 0x8D00;
constexpr GLenum GL_STENCIL_ATTACHMENT_EXT = 0x8D20;
constexpr GLenum GL_FRAMEBUFFER_EXT = 0x8D40;
constexpr GLenum GL_RENDERBUFFER_EXT = 0x8D41;
constexpr GLenum GL_RENDERBUFFER_WIDTH_EXT = 0x8D42;
constexpr GLenum GL_RENDERBUFFER_HEIGHT_EXT = 0x8D43;
constexpr GLenum GL_RENDERBUFFER_INTERNAL_FORMAT_EXT = 0x8D44;
constexpr GLenum GL_STENCIL_INDEX1_EXT = 0x8D46;
constexpr GLenum GL_STENCIL_INDEX4_EXT = 0x8D47;
constexpr GLenum GL_STENCIL_INDEX8_EXT = 0x8D48;
constexpr GLenum GL_STENCIL_INDEX16_EXT = 0x8D49;
constexpr GLenum GL_RENDERBUFFER_RED_SIZE_EXT = 0x8D50;
constexpr GLenum GL_RENDERBUFFER_GREEN_SIZE_EXT = 0x8D51;
constexpr GLenum GL_RENDERBUFFER_BLUE_SIZE_EXT = 0x8D52;
constexpr GLenum GL_RENDERBUFFER_ALPHA_SIZE_EXT = 0x8D53;
constexpr GLenum GL_RENDERBUFFER_DEPTH_SIZE_EXT = 0x8D54;
constexpr GLenum GL_RENDERBUFFER_STENCIL_SIZE_EXT = 0x8D55;
GLboolean glIsRenderbufferEXT(GLuint renderbuffer);
void glBindRenderbufferEXT(GLenum target, GLuint renderbuffer);
void glDeleteRenderbuffersEXT(GLsizei n, GLuint const  * renderbuffers);
void glGenRenderbuffersEXT(GLsizei n, GLuint * renderbuffers);
void glRenderbufferStorageEXT(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
void glGetRenderbufferParameterivEXT(GLenum target, GLenum pname, GLint * params);
GLboolean glIsFramebufferEXT(GLuint framebuffer);
void glBindFramebufferEXT(GLenum target, GLuint framebuffer);
void glDeleteFramebuffersEXT(GLsizei n, GLuint const  * framebuffers);
void glGenFramebuffersEXT(GLsizei n, GLuint * framebuffers);
GLenum glCheckFramebufferStatusEXT(GLenum target);
void glFramebufferTexture1DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
void glFramebufferTexture2DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
void glFramebufferTexture3DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
void glFramebufferRenderbufferEXT(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
void glGetFramebufferAttachmentParameterivEXT(GLenum target, GLenum attachment, GLenum pname, GLint * params);
void glGenerateMipmapEXT(GLenum target);
#endif /* GL_EXT_framebuffer_object */
#ifndef GL_EXT_framebuffer_sRGB
#define GL_EXT_framebuffer_sRGB 1
constexpr GLenum GL_FRAMEBUFFER_SRGB_EXT = 0x8DB9;
constexpr GLenum GL_FRAMEBUFFER_SRGB_CAPABLE_EXT = 0x8DBA;
#endif /* GL_EXT_framebuffer_sRGB */
#ifndef GL_EXT_geometry_shader4
#define GL_EXT_geometry_shader4 1
constexpr GLenum GL_GEOMETRY_SHADER_EXT = 0x8DD9;
constexpr GLenum GL_GEOMETRY_VERTICES_OUT_EXT = 0x8DDA;
constexpr GLenum GL_GEOMETRY_INPUT_TYPE_EXT = 0x8DDB;
constexpr GLenum GL_GEOMETRY_OUTPUT_TYPE_EXT = 0x8DDC;
constexpr GLenum GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_EXT = 0x8C29;
constexpr GLenum GL_MAX_GEOMETRY_VARYING_COMPONENTS_EXT = 0x8DDD;
constexpr GLenum GL_MAX_VERTEX_VARYING_COMPONENTS_EXT = 0x8DDE;
constexpr GLenum GL_MAX_VARYING_COMPONENTS_EXT = 0x8B4B;
constexpr GLenum GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_EXT = 0x8DDF;
constexpr GLenum GL_MAX_GEOMETRY_OUTPUT_VERTICES_EXT = 0x8DE0;
constexpr GLenum GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_EXT = 0x8DE1;
constexpr GLenum GL_LINES_ADJACENCY_EXT = 0x000A;
constexpr GLenum GL_LINE_STRIP_ADJACENCY_EXT = 0x000B;
constexpr GLenum GL_TRIANGLES_ADJACENCY_EXT = 0x000C;
constexpr GLenum GL_TRIANGLE_STRIP_ADJACENCY_EXT = 0x000D;
constexpr GLenum GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_EXT = 0x8DA8;
constexpr GLenum GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_EXT = 0x8DA9;
constexpr GLenum GL_FRAMEBUFFER_ATTACHMENT_LAYERED_EXT = 0x8DA7;
constexpr GLenum GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER_EXT = 0x8CD4;
constexpr GLenum GL_PROGRAM_POINT_SIZE_EXT = 0x8642;
void glProgramParameteriEXT(GLuint program, GLenum pname, GLint value);
#endif /* GL_EXT_geometry_shader4 */
#ifndef GL_EXT_gpu_program_parameters
#define GL_EXT_gpu_program_parameters 1
void glProgramEnvParameters4fvEXT(GLenum target, GLuint index, GLsizei count, GLfloat const  * params);
void glProgramLocalParameters4fvEXT(GLenum target, GLuint index, GLsizei count, GLfloat const  * params);
#endif /* GL_EXT_gpu_program_parameters */
#ifndef GL_EXT_gpu_shader4
#define GL_EXT_gpu_shader4 1
constexpr GLenum GL_VERTEX_ATTRIB_ARRAY_INTEGER_EXT = 0x88FD;
constexpr GLenum GL_SAMPLER_1D_ARRAY_EXT = 0x8DC0;
constexpr GLenum GL_SAMPLER_2D_ARRAY_EXT = 0x8DC1;
constexpr GLenum GL_SAMPLER_BUFFER_EXT = 0x8DC2;
constexpr GLenum GL_SAMPLER_1D_ARRAY_SHADOW_EXT = 0x8DC3;
constexpr GLenum GL_SAMPLER_2D_ARRAY_SHADOW_EXT = 0x8DC4;
constexpr GLenum GL_SAMPLER_CUBE_SHADOW_EXT = 0x8DC5;
constexpr GLenum GL_UNSIGNED_INT_VEC2_EXT = 0x8DC6;
constexpr GLenum GL_UNSIGNED_INT_VEC3_EXT = 0x8DC7;
constexpr GLenum GL_UNSIGNED_INT_VEC4_EXT = 0x8DC8;
constexpr GLenum GL_INT_SAMPLER_1D_EXT = 0x8DC9;
constexpr GLenum GL_INT_SAMPLER_2D_EXT = 0x8DCA;
constexpr GLenum GL_INT_SAMPLER_3D_EXT = 0x8DCB;
constexpr GLenum GL_INT_SAMPLER_CUBE_EXT = 0x8DCC;
constexpr GLenum GL_INT_SAMPLER_2D_RECT_EXT = 0x8DCD;
constexpr GLenum GL_INT_SAMPLER_1D_ARRAY_EXT = 0x8DCE;
constexpr GLenum GL_INT_SAMPLER_2D_ARRAY_EXT = 0x8DCF;
constexpr GLenum GL_INT_SAMPLER_BUFFER_EXT = 0x8DD0;
constexpr GLenum GL_UNSIGNED_INT_SAMPLER_1D_EXT = 0x8DD1;
constexpr GLenum GL_UNSIGNED_INT_SAMPLER_2D_EXT = 0x8DD2;
constexpr GLenum GL_UNSIGNED_INT_SAMPLER_3D_EXT = 0x8DD3;
constexpr GLenum GL_UNSIGNED_INT_SAMPLER_CUBE_EXT = 0x8DD4;
constexpr GLenum GL_UNSIGNED_INT_SAMPLER_2D_RECT_EXT = 0x8DD5;
constexpr GLenum GL_UNSIGNED_INT_SAMPLER_1D_ARRAY_EXT = 0x8DD6;
constexpr GLenum GL_UNSIGNED_INT_SAMPLER_2D_ARRAY_EXT = 0x8DD7;
constexpr GLenum GL_UNSIGNED_INT_SAMPLER_BUFFER_EXT = 0x8DD8;
constexpr GLenum GL_MIN_PROGRAM_TEXEL_OFFSET_EXT = 0x8904;
constexpr GLenum GL_MAX_PROGRAM_TEXEL_OFFSET_EXT = 0x8905;
void glGetUniformuivEXT(GLuint program, GLint location, GLuint * params);
void glBindFragDataLocationEXT(GLuint program, GLuint color, GLchar const  * name);
GLint glGetFragDataLocationEXT(GLuint program, GLchar const  * name);
void glUniform1uiEXT(GLint location, GLuint v0);
void glUniform2uiEXT(GLint location, GLuint v0, GLuint v1);
void glUniform3uiEXT(GLint location, GLuint v0, GLuint v1, GLuint v2);
void glUniform4uiEXT(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
void glUniform1uivEXT(GLint location, GLsizei count, GLuint const  * value);
void glUniform2uivEXT(GLint location, GLsizei count, GLuint const  * value);
void glUniform3uivEXT(GLint location, GLsizei count, GLuint const  * value);
void glUniform4uivEXT(GLint location, GLsizei count, GLuint const  * value);
#endif /* GL_EXT_gpu_shader4 */
#ifndef GL_EXT_histogram
#define GL_EXT_histogram 1
constexpr GLenum GL_HISTOGRAM_EXT = 0x8024;
constexpr GLenum GL_PROXY_HISTOGRAM_EXT = 0x8025;
constexpr GLenum GL_HISTOGRAM_WIDTH_EXT = 0x8026;
constexpr GLenum GL_HISTOGRAM_FORMAT_EXT = 0x8027;
constexpr GLenum GL_HISTOGRAM_RED_SIZE_EXT = 0x8028;
constexpr GLenum GL_HISTOGRAM_GREEN_SIZE_EXT = 0x8029;
constexpr GLenum GL_HISTOGRAM_BLUE_SIZE_EXT = 0x802A;
constexpr GLenum GL_HISTOGRAM_ALPHA_SIZE_EXT = 0x802B;
constexpr GLenum GL_HISTOGRAM_LUMINANCE_SIZE_EXT = 0x802C;
constexpr GLenum GL_HISTOGRAM_SINK_EXT = 0x802D;
constexpr GLenum GL_MINMAX_EXT = 0x802E;
constexpr GLenum GL_MINMAX_FORMAT_EXT = 0x802F;
constexpr GLenum GL_MINMAX_SINK_EXT = 0x8030;
constexpr GLenum GL_TABLE_TOO_LARGE_EXT = 0x8031;
void glGetHistogramEXT(GLenum target, GLboolean reset, GLenum format, GLenum type, void * values);
void glGetHistogramParameterfvEXT(GLenum target, GLenum pname, GLfloat * params);
void glGetHistogramParameterivEXT(GLenum target, GLenum pname, GLint * params);
void glGetMinmaxEXT(GLenum target, GLboolean reset, GLenum format, GLenum type, void * values);
void glGetMinmaxParameterfvEXT(GLenum target, GLenum pname, GLfloat * params);
void glGetMinmaxParameterivEXT(GLenum target, GLenum pname, GLint * params);
void glHistogramEXT(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink);
void glMinmaxEXT(GLenum target, GLenum internalformat, GLboolean sink);
void glResetHistogramEXT(GLenum target);
void glResetMinmaxEXT(GLenum target);
#endif /* GL_EXT_histogram */
#ifndef GL_EXT_index_array_formats
#define GL_EXT_index_array_formats 1
constexpr GLenum GL_IUI_V2F_EXT = 0x81AD;
constexpr GLenum GL_IUI_V3F_EXT = 0x81AE;
constexpr GLenum GL_IUI_N3F_V2F_EXT = 0x81AF;
constexpr GLenum GL_IUI_N3F_V3F_EXT = 0x81B0;
constexpr GLenum GL_T2F_IUI_V2F_EXT = 0x81B1;
constexpr GLenum GL_T2F_IUI_V3F_EXT = 0x81B2;
constexpr GLenum GL_T2F_IUI_N3F_V2F_EXT = 0x81B3;
constexpr GLenum GL_T2F_IUI_N3F_V3F_EXT = 0x81B4;
#endif /* GL_EXT_index_array_formats */
#ifndef GL_EXT_index_func
#define GL_EXT_index_func 1
constexpr GLenum GL_INDEX_TEST_EXT = 0x81B5;
constexpr GLenum GL_INDEX_TEST_FUNC_EXT = 0x81B6;
constexpr GLenum GL_INDEX_TEST_REF_EXT = 0x81B7;
void glIndexFuncEXT(GLenum func, GLclampf ref);
#endif /* GL_EXT_index_func */
#ifndef GL_EXT_index_material
#define GL_EXT_index_material 1
constexpr GLenum GL_INDEX_MATERIAL_EXT = 0x81B8;
constexpr GLenum GL_INDEX_MATERIAL_PARAMETER_EXT = 0x81B9;
constexpr GLenum GL_INDEX_MATERIAL_FACE_EXT = 0x81BA;
void glIndexMaterialEXT(GLenum face, GLenum mode);
#endif /* GL_EXT_index_material */
#ifndef GL_EXT_index_texture
#define GL_EXT_index_texture 1
#endif /* GL_EXT_index_texture */
#ifndef GL_EXT_light_texture
#define GL_EXT_light_texture 1
constexpr GLenum GL_FRAGMENT_MATERIAL_EXT = 0x8349;
constexpr GLenum GL_FRAGMENT_NORMAL_EXT = 0x834A;
constexpr GLenum GL_FRAGMENT_COLOR_EXT = 0x834C;
constexpr GLenum GL_ATTENUATION_EXT = 0x834D;
constexpr GLenum GL_SHADOW_ATTENUATION_EXT = 0x834E;
constexpr GLenum GL_TEXTURE_APPLICATION_MODE_EXT = 0x834F;
constexpr GLenum GL_TEXTURE_LIGHT_EXT = 0x8350;
constexpr GLenum GL_TEXTURE_MATERIAL_FACE_EXT = 0x8351;
constexpr GLenum GL_TEXTURE_MATERIAL_PARAMETER_EXT = 0x8352;
void glApplyTextureEXT(GLenum mode);
void glTextureLightEXT(GLenum pname);
void glTextureMaterialEXT(GLenum face, GLenum mode);
#endif /* GL_EXT_light_texture */
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
#ifndef GL_EXT_misc_attribute
#define GL_EXT_misc_attribute 1
#endif /* GL_EXT_misc_attribute */
#ifndef GL_EXT_multi_draw_arrays
#define GL_EXT_multi_draw_arrays 1
void glMultiDrawArraysEXT(GLenum mode, GLint const  * first, GLsizei const  * count, GLsizei primcount);
void glMultiDrawElementsEXT(GLenum mode, GLsizei const  * count, GLenum type, const void *const* indices, GLsizei primcount);
#endif /* GL_EXT_multi_draw_arrays */
#ifndef GL_EXT_multisample
#define GL_EXT_multisample 1
constexpr GLenum GL_MULTISAMPLE_EXT = 0x809D;
constexpr GLenum GL_SAMPLE_ALPHA_TO_MASK_EXT = 0x809E;
constexpr GLenum GL_SAMPLE_ALPHA_TO_ONE_EXT = 0x809F;
constexpr GLenum GL_SAMPLE_MASK_EXT = 0x80A0;
constexpr GLenum GL_1PASS_EXT = 0x80A1;
constexpr GLenum GL_2PASS_0_EXT = 0x80A2;
constexpr GLenum GL_2PASS_1_EXT = 0x80A3;
constexpr GLenum GL_4PASS_0_EXT = 0x80A4;
constexpr GLenum GL_4PASS_1_EXT = 0x80A5;
constexpr GLenum GL_4PASS_2_EXT = 0x80A6;
constexpr GLenum GL_4PASS_3_EXT = 0x80A7;
constexpr GLenum GL_SAMPLE_BUFFERS_EXT = 0x80A8;
constexpr GLenum GL_SAMPLES_EXT = 0x80A9;
constexpr GLenum GL_SAMPLE_MASK_VALUE_EXT = 0x80AA;
constexpr GLenum GL_SAMPLE_MASK_INVERT_EXT = 0x80AB;
constexpr GLenum GL_SAMPLE_PATTERN_EXT = 0x80AC;
constexpr GLenum GL_MULTISAMPLE_BIT_EXT = 0x20000000;
void glSampleMaskEXT(GLclampf value, GLboolean invert);
void glSamplePatternEXT(GLenum pattern);
#endif /* GL_EXT_multisample */
#ifndef GL_EXT_multiview_tessellation_geometry_shader
#define GL_EXT_multiview_tessellation_geometry_shader 1
#endif /* GL_EXT_multiview_tessellation_geometry_shader */
#ifndef GL_EXT_multiview_texture_multisample
#define GL_EXT_multiview_texture_multisample 1
#endif /* GL_EXT_multiview_texture_multisample */
#ifndef GL_EXT_multiview_timer_query
#define GL_EXT_multiview_timer_query 1
#endif /* GL_EXT_multiview_timer_query */
#ifndef GL_EXT_packed_depth_stencil
#define GL_EXT_packed_depth_stencil 1
constexpr GLenum GL_DEPTH_STENCIL_EXT = 0x84F9;
constexpr GLenum GL_UNSIGNED_INT_24_8_EXT = 0x84FA;
constexpr GLenum GL_DEPTH24_STENCIL8_EXT = 0x88F0;
constexpr GLenum GL_TEXTURE_STENCIL_SIZE_EXT = 0x88F1;
#endif /* GL_EXT_packed_depth_stencil */
#ifndef GL_EXT_packed_float
#define GL_EXT_packed_float 1
constexpr GLenum GL_R11F_G11F_B10F_EXT = 0x8C3A;
constexpr GLenum GL_UNSIGNED_INT_10F_11F_11F_REV_EXT = 0x8C3B;
constexpr GLenum GL_RGBA_SIGNED_COMPONENTS_EXT = 0x8C3C;
#endif /* GL_EXT_packed_float */
#ifndef GL_EXT_packed_pixels
#define GL_EXT_packed_pixels 1
constexpr GLenum GL_UNSIGNED_BYTE_3_3_2_EXT = 0x8032;
constexpr GLenum GL_UNSIGNED_SHORT_4_4_4_4_EXT = 0x8033;
constexpr GLenum GL_UNSIGNED_SHORT_5_5_5_1_EXT = 0x8034;
constexpr GLenum GL_UNSIGNED_INT_8_8_8_8_EXT = 0x8035;
constexpr GLenum GL_UNSIGNED_INT_10_10_10_2_EXT = 0x8036;
#endif /* GL_EXT_packed_pixels */
#ifndef GL_EXT_paletted_texture
#define GL_EXT_paletted_texture 1
constexpr GLenum GL_COLOR_INDEX1_EXT = 0x80E2;
constexpr GLenum GL_COLOR_INDEX2_EXT = 0x80E3;
constexpr GLenum GL_COLOR_INDEX4_EXT = 0x80E4;
constexpr GLenum GL_COLOR_INDEX8_EXT = 0x80E5;
constexpr GLenum GL_COLOR_INDEX12_EXT = 0x80E6;
constexpr GLenum GL_COLOR_INDEX16_EXT = 0x80E7;
constexpr GLenum GL_TEXTURE_INDEX_SIZE_EXT = 0x80ED;
void glColorTableEXT(GLenum target, GLenum internalFormat, GLsizei width, GLenum format, GLenum type, const void * table);
void glGetColorTableEXT(GLenum target, GLenum format, GLenum type, void * data);
void glGetColorTableParameterivEXT(GLenum target, GLenum pname, GLint * params);
void glGetColorTableParameterfvEXT(GLenum target, GLenum pname, GLfloat * params);
#endif /* GL_EXT_paletted_texture */
#ifndef GL_EXT_pixel_buffer_object
#define GL_EXT_pixel_buffer_object 1
constexpr GLenum GL_PIXEL_PACK_BUFFER_EXT = 0x88EB;
constexpr GLenum GL_PIXEL_UNPACK_BUFFER_EXT = 0x88EC;
constexpr GLenum GL_PIXEL_PACK_BUFFER_BINDING_EXT = 0x88ED;
constexpr GLenum GL_PIXEL_UNPACK_BUFFER_BINDING_EXT = 0x88EF;
#endif /* GL_EXT_pixel_buffer_object */
#ifndef GL_EXT_pixel_transform
#define GL_EXT_pixel_transform 1
constexpr GLenum GL_PIXEL_TRANSFORM_2D_EXT = 0x8330;
constexpr GLenum GL_PIXEL_MAG_FILTER_EXT = 0x8331;
constexpr GLenum GL_PIXEL_MIN_FILTER_EXT = 0x8332;
constexpr GLenum GL_PIXEL_CUBIC_WEIGHT_EXT = 0x8333;
constexpr GLenum GL_CUBIC_EXT = 0x8334;
constexpr GLenum GL_AVERAGE_EXT = 0x8335;
constexpr GLenum GL_PIXEL_TRANSFORM_2D_STACK_DEPTH_EXT = 0x8336;
constexpr GLenum GL_MAX_PIXEL_TRANSFORM_2D_STACK_DEPTH_EXT = 0x8337;
constexpr GLenum GL_PIXEL_TRANSFORM_2D_MATRIX_EXT = 0x8338;
void glPixelTransformParameteriEXT(GLenum target, GLenum pname, GLint param);
void glPixelTransformParameterfEXT(GLenum target, GLenum pname, GLfloat param);
void glPixelTransformParameterivEXT(GLenum target, GLenum pname, GLint const  * params);
void glPixelTransformParameterfvEXT(GLenum target, GLenum pname, GLfloat const  * params);
void glGetPixelTransformParameterivEXT(GLenum target, GLenum pname, GLint * params);
void glGetPixelTransformParameterfvEXT(GLenum target, GLenum pname, GLfloat * params);
#endif /* GL_EXT_pixel_transform */
#ifndef GL_EXT_pixel_transform_color_table
#define GL_EXT_pixel_transform_color_table 1
#endif /* GL_EXT_pixel_transform_color_table */
#ifndef GL_EXT_point_parameters
#define GL_EXT_point_parameters 1
constexpr GLenum GL_POINT_SIZE_MIN_EXT = 0x8126;
constexpr GLenum GL_POINT_SIZE_MAX_EXT = 0x8127;
constexpr GLenum GL_POINT_FADE_THRESHOLD_SIZE_EXT = 0x8128;
constexpr GLenum GL_DISTANCE_ATTENUATION_EXT = 0x8129;
void glPointParameterfEXT(GLenum pname, GLfloat param);
void glPointParameterfvEXT(GLenum pname, GLfloat const  * params);
#endif /* GL_EXT_point_parameters */
#ifndef GL_EXT_polygon_offset
#define GL_EXT_polygon_offset 1
constexpr GLenum GL_POLYGON_OFFSET_EXT = 0x8037;
constexpr GLenum GL_POLYGON_OFFSET_FACTOR_EXT = 0x8038;
constexpr GLenum GL_POLYGON_OFFSET_BIAS_EXT = 0x8039;
void glPolygonOffsetEXT(GLfloat factor, GLfloat bias);
#endif /* GL_EXT_polygon_offset */
#ifndef GL_EXT_polygon_offset_clamp
#define GL_EXT_polygon_offset_clamp 1
constexpr GLenum GL_POLYGON_OFFSET_CLAMP_EXT = 0x8E1B;
void glPolygonOffsetClampEXT(GLfloat factor, GLfloat units, GLfloat clamp);
#endif /* GL_EXT_polygon_offset_clamp */
#ifndef GL_EXT_post_depth_coverage
#define GL_EXT_post_depth_coverage 1
#endif /* GL_EXT_post_depth_coverage */
#ifndef GL_EXT_provoking_vertex
#define GL_EXT_provoking_vertex 1
constexpr GLenum GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION_EXT = 0x8E4C;
constexpr GLenum GL_FIRST_VERTEX_CONVENTION_EXT = 0x8E4D;
constexpr GLenum GL_LAST_VERTEX_CONVENTION_EXT = 0x8E4E;
constexpr GLenum GL_PROVOKING_VERTEX_EXT = 0x8E4F;
void glProvokingVertexEXT(GLenum mode);
#endif /* GL_EXT_provoking_vertex */
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
#ifndef GL_EXT_rescale_normal
#define GL_EXT_rescale_normal 1
constexpr GLenum GL_RESCALE_NORMAL_EXT = 0x803A;
#endif /* GL_EXT_rescale_normal */
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
#ifndef GL_EXT_secondary_color
#define GL_EXT_secondary_color 1
constexpr GLenum GL_COLOR_SUM_EXT = 0x8458;
constexpr GLenum GL_CURRENT_SECONDARY_COLOR_EXT = 0x8459;
constexpr GLenum GL_SECONDARY_COLOR_ARRAY_SIZE_EXT = 0x845A;
constexpr GLenum GL_SECONDARY_COLOR_ARRAY_TYPE_EXT = 0x845B;
constexpr GLenum GL_SECONDARY_COLOR_ARRAY_STRIDE_EXT = 0x845C;
constexpr GLenum GL_SECONDARY_COLOR_ARRAY_POINTER_EXT = 0x845D;
constexpr GLenum GL_SECONDARY_COLOR_ARRAY_EXT = 0x845E;
void glSecondaryColor3bEXT(GLbyte red, GLbyte green, GLbyte blue);
void glSecondaryColor3bvEXT(GLbyte const  * v);
void glSecondaryColor3dEXT(GLdouble red, GLdouble green, GLdouble blue);
void glSecondaryColor3dvEXT(GLdouble const  * v);
void glSecondaryColor3fEXT(GLfloat red, GLfloat green, GLfloat blue);
void glSecondaryColor3fvEXT(GLfloat const  * v);
void glSecondaryColor3iEXT(GLint red, GLint green, GLint blue);
void glSecondaryColor3ivEXT(GLint const  * v);
void glSecondaryColor3sEXT(GLshort red, GLshort green, GLshort blue);
void glSecondaryColor3svEXT(GLshort const  * v);
void glSecondaryColor3ubEXT(GLubyte red, GLubyte green, GLubyte blue);
void glSecondaryColor3ubvEXT(GLubyte const  * v);
void glSecondaryColor3uiEXT(GLuint red, GLuint green, GLuint blue);
void glSecondaryColor3uivEXT(GLuint const  * v);
void glSecondaryColor3usEXT(GLushort red, GLushort green, GLushort blue);
void glSecondaryColor3usvEXT(GLushort const  * v);
void glSecondaryColorPointerEXT(GLint size, GLenum type, GLsizei stride, const void * pointer);
#endif /* GL_EXT_secondary_color */
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
void glUseProgramStagesEXT(GLuint pipeline, GLbitfield stages, GLuint program);
void glValidateProgramPipelineEXT(GLuint pipeline);
#endif /* GL_EXT_separate_shader_objects */
#ifndef GL_EXT_separate_specular_color
#define GL_EXT_separate_specular_color 1
constexpr GLenum GL_LIGHT_MODEL_COLOR_CONTROL_EXT = 0x81F8;
constexpr GLenum GL_SINGLE_COLOR_EXT = 0x81F9;
constexpr GLenum GL_SEPARATE_SPECULAR_COLOR_EXT = 0x81FA;
#endif /* GL_EXT_separate_specular_color */
#ifndef GL_EXT_shader_framebuffer_fetch
#define GL_EXT_shader_framebuffer_fetch 1
constexpr GLenum GL_FRAGMENT_SHADER_DISCARDS_SAMPLES_EXT = 0x8A52;
#endif /* GL_EXT_shader_framebuffer_fetch */
#ifndef GL_EXT_shader_framebuffer_fetch_non_coherent
#define GL_EXT_shader_framebuffer_fetch_non_coherent 1
void glFramebufferFetchBarrierEXT();
#endif /* GL_EXT_shader_framebuffer_fetch_non_coherent */
#ifndef GL_EXT_shader_image_load_formatted
#define GL_EXT_shader_image_load_formatted 1
#endif /* GL_EXT_shader_image_load_formatted */
#ifndef GL_EXT_shader_image_load_store
#define GL_EXT_shader_image_load_store 1
constexpr GLenum GL_MAX_IMAGE_UNITS_EXT = 0x8F38;
constexpr GLenum GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS_EXT = 0x8F39;
constexpr GLenum GL_IMAGE_BINDING_NAME_EXT = 0x8F3A;
constexpr GLenum GL_IMAGE_BINDING_LEVEL_EXT = 0x8F3B;
constexpr GLenum GL_IMAGE_BINDING_LAYERED_EXT = 0x8F3C;
constexpr GLenum GL_IMAGE_BINDING_LAYER_EXT = 0x8F3D;
constexpr GLenum GL_IMAGE_BINDING_ACCESS_EXT = 0x8F3E;
constexpr GLenum GL_IMAGE_1D_EXT = 0x904C;
constexpr GLenum GL_IMAGE_2D_EXT = 0x904D;
constexpr GLenum GL_IMAGE_3D_EXT = 0x904E;
constexpr GLenum GL_IMAGE_2D_RECT_EXT = 0x904F;
constexpr GLenum GL_IMAGE_CUBE_EXT = 0x9050;
constexpr GLenum GL_IMAGE_BUFFER_EXT = 0x9051;
constexpr GLenum GL_IMAGE_1D_ARRAY_EXT = 0x9052;
constexpr GLenum GL_IMAGE_2D_ARRAY_EXT = 0x9053;
constexpr GLenum GL_IMAGE_CUBE_MAP_ARRAY_EXT = 0x9054;
constexpr GLenum GL_IMAGE_2D_MULTISAMPLE_EXT = 0x9055;
constexpr GLenum GL_IMAGE_2D_MULTISAMPLE_ARRAY_EXT = 0x9056;
constexpr GLenum GL_INT_IMAGE_1D_EXT = 0x9057;
constexpr GLenum GL_INT_IMAGE_2D_EXT = 0x9058;
constexpr GLenum GL_INT_IMAGE_3D_EXT = 0x9059;
constexpr GLenum GL_INT_IMAGE_2D_RECT_EXT = 0x905A;
constexpr GLenum GL_INT_IMAGE_CUBE_EXT = 0x905B;
constexpr GLenum GL_INT_IMAGE_BUFFER_EXT = 0x905C;
constexpr GLenum GL_INT_IMAGE_1D_ARRAY_EXT = 0x905D;
constexpr GLenum GL_INT_IMAGE_2D_ARRAY_EXT = 0x905E;
constexpr GLenum GL_INT_IMAGE_CUBE_MAP_ARRAY_EXT = 0x905F;
constexpr GLenum GL_INT_IMAGE_2D_MULTISAMPLE_EXT = 0x9060;
constexpr GLenum GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY_EXT = 0x9061;
constexpr GLenum GL_UNSIGNED_INT_IMAGE_1D_EXT = 0x9062;
constexpr GLenum GL_UNSIGNED_INT_IMAGE_2D_EXT = 0x9063;
constexpr GLenum GL_UNSIGNED_INT_IMAGE_3D_EXT = 0x9064;
constexpr GLenum GL_UNSIGNED_INT_IMAGE_2D_RECT_EXT = 0x9065;
constexpr GLenum GL_UNSIGNED_INT_IMAGE_CUBE_EXT = 0x9066;
constexpr GLenum GL_UNSIGNED_INT_IMAGE_BUFFER_EXT = 0x9067;
constexpr GLenum GL_UNSIGNED_INT_IMAGE_1D_ARRAY_EXT = 0x9068;
constexpr GLenum GL_UNSIGNED_INT_IMAGE_2D_ARRAY_EXT = 0x9069;
constexpr GLenum GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY_EXT = 0x906A;
constexpr GLenum GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_EXT = 0x906B;
constexpr GLenum GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY_EXT = 0x906C;
constexpr GLenum GL_MAX_IMAGE_SAMPLES_EXT = 0x906D;
constexpr GLenum GL_IMAGE_BINDING_FORMAT_EXT = 0x906E;
constexpr GLenum GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT_EXT = 0x00000001;
constexpr GLenum GL_ELEMENT_ARRAY_BARRIER_BIT_EXT = 0x00000002;
constexpr GLenum GL_UNIFORM_BARRIER_BIT_EXT = 0x00000004;
constexpr GLenum GL_TEXTURE_FETCH_BARRIER_BIT_EXT = 0x00000008;
constexpr GLenum GL_SHADER_IMAGE_ACCESS_BARRIER_BIT_EXT = 0x00000020;
constexpr GLenum GL_COMMAND_BARRIER_BIT_EXT = 0x00000040;
constexpr GLenum GL_PIXEL_BUFFER_BARRIER_BIT_EXT = 0x00000080;
constexpr GLenum GL_TEXTURE_UPDATE_BARRIER_BIT_EXT = 0x00000100;
constexpr GLenum GL_BUFFER_UPDATE_BARRIER_BIT_EXT = 0x00000200;
constexpr GLenum GL_FRAMEBUFFER_BARRIER_BIT_EXT = 0x00000400;
constexpr GLenum GL_TRANSFORM_FEEDBACK_BARRIER_BIT_EXT = 0x00000800;
constexpr GLenum GL_ATOMIC_COUNTER_BARRIER_BIT_EXT = 0x00001000;
constexpr GLenum GL_ALL_BARRIER_BITS_EXT = 0xFFFFFFFF;
void glBindImageTextureEXT(GLuint index, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLint format);
void glMemoryBarrierEXT(GLbitfield barriers);
#endif /* GL_EXT_shader_image_load_store */
#ifndef GL_EXT_shader_integer_mix
#define GL_EXT_shader_integer_mix 1
#endif /* GL_EXT_shader_integer_mix */
#ifndef GL_EXT_shadow_funcs
#define GL_EXT_shadow_funcs 1
#endif /* GL_EXT_shadow_funcs */
#ifndef GL_EXT_shared_texture_palette
#define GL_EXT_shared_texture_palette 1
constexpr GLenum GL_SHARED_TEXTURE_PALETTE_EXT = 0x81FB;
#endif /* GL_EXT_shared_texture_palette */
#ifndef GL_EXT_sparse_texture2
#define GL_EXT_sparse_texture2 1
#endif /* GL_EXT_sparse_texture2 */
#ifndef GL_EXT_stencil_clear_tag
#define GL_EXT_stencil_clear_tag 1
constexpr GLenum GL_STENCIL_TAG_BITS_EXT = 0x88F2;
constexpr GLenum GL_STENCIL_CLEAR_TAG_VALUE_EXT = 0x88F3;
void glStencilClearTagEXT(GLsizei stencilTagBits, GLuint stencilClearTag);
#endif /* GL_EXT_stencil_clear_tag */
#ifndef GL_EXT_stencil_two_side
#define GL_EXT_stencil_two_side 1
constexpr GLenum GL_STENCIL_TEST_TWO_SIDE_EXT = 0x8910;
constexpr GLenum GL_ACTIVE_STENCIL_FACE_EXT = 0x8911;
void glActiveStencilFaceEXT(GLenum face);
#endif /* GL_EXT_stencil_two_side */
#ifndef GL_EXT_stencil_wrap
#define GL_EXT_stencil_wrap 1
constexpr GLenum GL_INCR_WRAP_EXT = 0x8507;
constexpr GLenum GL_DECR_WRAP_EXT = 0x8508;
#endif /* GL_EXT_stencil_wrap */
#ifndef GL_EXT_subtexture
#define GL_EXT_subtexture 1
void glTexSubImage1DEXT(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void * pixels);
void glTexSubImage2DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels);
#endif /* GL_EXT_subtexture */
#ifndef GL_EXT_texture
#define GL_EXT_texture 1
constexpr GLenum GL_ALPHA4_EXT = 0x803B;
constexpr GLenum GL_ALPHA8_EXT = 0x803C;
constexpr GLenum GL_ALPHA12_EXT = 0x803D;
constexpr GLenum GL_ALPHA16_EXT = 0x803E;
constexpr GLenum GL_LUMINANCE4_EXT = 0x803F;
constexpr GLenum GL_LUMINANCE8_EXT = 0x8040;
constexpr GLenum GL_LUMINANCE12_EXT = 0x8041;
constexpr GLenum GL_LUMINANCE16_EXT = 0x8042;
constexpr GLenum GL_LUMINANCE4_ALPHA4_EXT = 0x8043;
constexpr GLenum GL_LUMINANCE6_ALPHA2_EXT = 0x8044;
constexpr GLenum GL_LUMINANCE8_ALPHA8_EXT = 0x8045;
constexpr GLenum GL_LUMINANCE12_ALPHA4_EXT = 0x8046;
constexpr GLenum GL_LUMINANCE12_ALPHA12_EXT = 0x8047;
constexpr GLenum GL_LUMINANCE16_ALPHA16_EXT = 0x8048;
constexpr GLenum GL_INTENSITY_EXT = 0x8049;
constexpr GLenum GL_INTENSITY4_EXT = 0x804A;
constexpr GLenum GL_INTENSITY8_EXT = 0x804B;
constexpr GLenum GL_INTENSITY12_EXT = 0x804C;
constexpr GLenum GL_INTENSITY16_EXT = 0x804D;
constexpr GLenum GL_RGB2_EXT = 0x804E;
constexpr GLenum GL_RGB4_EXT = 0x804F;
constexpr GLenum GL_RGB5_EXT = 0x8050;
constexpr GLenum GL_RGB8_EXT = 0x8051;
constexpr GLenum GL_RGB10_EXT = 0x8052;
constexpr GLenum GL_RGB12_EXT = 0x8053;
constexpr GLenum GL_RGB16_EXT = 0x8054;
constexpr GLenum GL_RGBA2_EXT = 0x8055;
constexpr GLenum GL_RGBA4_EXT = 0x8056;
constexpr GLenum GL_RGB5_A1_EXT = 0x8057;
constexpr GLenum GL_RGBA8_EXT = 0x8058;
constexpr GLenum GL_RGB10_A2_EXT = 0x8059;
constexpr GLenum GL_RGBA12_EXT = 0x805A;
constexpr GLenum GL_RGBA16_EXT = 0x805B;
constexpr GLenum GL_TEXTURE_RED_SIZE_EXT = 0x805C;
constexpr GLenum GL_TEXTURE_GREEN_SIZE_EXT = 0x805D;
constexpr GLenum GL_TEXTURE_BLUE_SIZE_EXT = 0x805E;
constexpr GLenum GL_TEXTURE_ALPHA_SIZE_EXT = 0x805F;
constexpr GLenum GL_TEXTURE_LUMINANCE_SIZE_EXT = 0x8060;
constexpr GLenum GL_TEXTURE_INTENSITY_SIZE_EXT = 0x8061;
constexpr GLenum GL_REPLACE_EXT = 0x8062;
constexpr GLenum GL_PROXY_TEXTURE_1D_EXT = 0x8063;
constexpr GLenum GL_PROXY_TEXTURE_2D_EXT = 0x8064;
constexpr GLenum GL_TEXTURE_TOO_LARGE_EXT = 0x8065;
#endif /* GL_EXT_texture */
#ifndef GL_EXT_texture3D
#define GL_EXT_texture3D 1
constexpr GLenum GL_PACK_SKIP_IMAGES_EXT = 0x806B;
constexpr GLenum GL_PACK_IMAGE_HEIGHT_EXT = 0x806C;
constexpr GLenum GL_UNPACK_SKIP_IMAGES_EXT = 0x806D;
constexpr GLenum GL_UNPACK_IMAGE_HEIGHT_EXT = 0x806E;
constexpr GLenum GL_TEXTURE_3D_EXT = 0x806F;
constexpr GLenum GL_PROXY_TEXTURE_3D_EXT = 0x8070;
constexpr GLenum GL_TEXTURE_DEPTH_EXT = 0x8071;
constexpr GLenum GL_TEXTURE_WRAP_R_EXT = 0x8072;
constexpr GLenum GL_MAX_3D_TEXTURE_SIZE_EXT = 0x8073;
void glTexImage3DEXT(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void * pixels);
void glTexSubImage3DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels);
#endif /* GL_EXT_texture3D */
#ifndef GL_EXT_texture_array
#define GL_EXT_texture_array 1
constexpr GLenum GL_TEXTURE_1D_ARRAY_EXT = 0x8C18;
constexpr GLenum GL_PROXY_TEXTURE_1D_ARRAY_EXT = 0x8C19;
constexpr GLenum GL_TEXTURE_2D_ARRAY_EXT = 0x8C1A;
constexpr GLenum GL_PROXY_TEXTURE_2D_ARRAY_EXT = 0x8C1B;
constexpr GLenum GL_TEXTURE_BINDING_1D_ARRAY_EXT = 0x8C1C;
constexpr GLenum GL_TEXTURE_BINDING_2D_ARRAY_EXT = 0x8C1D;
constexpr GLenum GL_MAX_ARRAY_TEXTURE_LAYERS_EXT = 0x88FF;
constexpr GLenum GL_COMPARE_REF_DEPTH_TO_TEXTURE_EXT = 0x884E;
void glFramebufferTextureLayerEXT(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
#endif /* GL_EXT_texture_array */
#ifndef GL_EXT_texture_buffer_object
#define GL_EXT_texture_buffer_object 1
constexpr GLenum GL_TEXTURE_BUFFER_EXT = 0x8C2A;
constexpr GLenum GL_MAX_TEXTURE_BUFFER_SIZE_EXT = 0x8C2B;
constexpr GLenum GL_TEXTURE_BINDING_BUFFER_EXT = 0x8C2C;
constexpr GLenum GL_TEXTURE_BUFFER_DATA_STORE_BINDING_EXT = 0x8C2D;
constexpr GLenum GL_TEXTURE_BUFFER_FORMAT_EXT = 0x8C2E;
void glTexBufferEXT(GLenum target, GLenum internalformat, GLuint buffer);
#endif /* GL_EXT_texture_buffer_object */
#ifndef GL_EXT_texture_compression_latc
#define GL_EXT_texture_compression_latc 1
constexpr GLenum GL_COMPRESSED_LUMINANCE_LATC1_EXT = 0x8C70;
constexpr GLenum GL_COMPRESSED_SIGNED_LUMINANCE_LATC1_EXT = 0x8C71;
constexpr GLenum GL_COMPRESSED_LUMINANCE_ALPHA_LATC2_EXT = 0x8C72;
constexpr GLenum GL_COMPRESSED_SIGNED_LUMINANCE_ALPHA_LATC2_EXT = 0x8C73;
#endif /* GL_EXT_texture_compression_latc */
#ifndef GL_EXT_texture_compression_rgtc
#define GL_EXT_texture_compression_rgtc 1
constexpr GLenum GL_COMPRESSED_RED_RGTC1_EXT = 0x8DBB;
constexpr GLenum GL_COMPRESSED_SIGNED_RED_RGTC1_EXT = 0x8DBC;
constexpr GLenum GL_COMPRESSED_RED_GREEN_RGTC2_EXT = 0x8DBD;
constexpr GLenum GL_COMPRESSED_SIGNED_RED_GREEN_RGTC2_EXT = 0x8DBE;
#endif /* GL_EXT_texture_compression_rgtc */
#ifndef GL_EXT_texture_compression_s3tc
#define GL_EXT_texture_compression_s3tc 1
constexpr GLenum GL_COMPRESSED_RGB_S3TC_DXT1_EXT = 0x83F0;
constexpr GLenum GL_COMPRESSED_RGBA_S3TC_DXT1_EXT = 0x83F1;
constexpr GLenum GL_COMPRESSED_RGBA_S3TC_DXT3_EXT = 0x83F2;
constexpr GLenum GL_COMPRESSED_RGBA_S3TC_DXT5_EXT = 0x83F3;
#endif /* GL_EXT_texture_compression_s3tc */
#ifndef GL_EXT_texture_cube_map
#define GL_EXT_texture_cube_map 1
constexpr GLenum GL_NORMAL_MAP_EXT = 0x8511;
constexpr GLenum GL_REFLECTION_MAP_EXT = 0x8512;
constexpr GLenum GL_TEXTURE_CUBE_MAP_EXT = 0x8513;
constexpr GLenum GL_TEXTURE_BINDING_CUBE_MAP_EXT = 0x8514;
constexpr GLenum GL_TEXTURE_CUBE_MAP_POSITIVE_X_EXT = 0x8515;
constexpr GLenum GL_TEXTURE_CUBE_MAP_NEGATIVE_X_EXT = 0x8516;
constexpr GLenum GL_TEXTURE_CUBE_MAP_POSITIVE_Y_EXT = 0x8517;
constexpr GLenum GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_EXT = 0x8518;
constexpr GLenum GL_TEXTURE_CUBE_MAP_POSITIVE_Z_EXT = 0x8519;
constexpr GLenum GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_EXT = 0x851A;
constexpr GLenum GL_PROXY_TEXTURE_CUBE_MAP_EXT = 0x851B;
constexpr GLenum GL_MAX_CUBE_MAP_TEXTURE_SIZE_EXT = 0x851C;
#endif /* GL_EXT_texture_cube_map */
#ifndef GL_EXT_texture_env_add
#define GL_EXT_texture_env_add 1
#endif /* GL_EXT_texture_env_add */
#ifndef GL_EXT_texture_env_combine
#define GL_EXT_texture_env_combine 1
constexpr GLenum GL_COMBINE_EXT = 0x8570;
constexpr GLenum GL_COMBINE_RGB_EXT = 0x8571;
constexpr GLenum GL_COMBINE_ALPHA_EXT = 0x8572;
constexpr GLenum GL_RGB_SCALE_EXT = 0x8573;
constexpr GLenum GL_ADD_SIGNED_EXT = 0x8574;
constexpr GLenum GL_INTERPOLATE_EXT = 0x8575;
constexpr GLenum GL_CONSTANT_EXT = 0x8576;
constexpr GLenum GL_PRIMARY_COLOR_EXT = 0x8577;
constexpr GLenum GL_PREVIOUS_EXT = 0x8578;
constexpr GLenum GL_SOURCE0_RGB_EXT = 0x8580;
constexpr GLenum GL_SOURCE1_RGB_EXT = 0x8581;
constexpr GLenum GL_SOURCE2_RGB_EXT = 0x8582;
constexpr GLenum GL_SOURCE0_ALPHA_EXT = 0x8588;
constexpr GLenum GL_SOURCE1_ALPHA_EXT = 0x8589;
constexpr GLenum GL_SOURCE2_ALPHA_EXT = 0x858A;
constexpr GLenum GL_OPERAND0_RGB_EXT = 0x8590;
constexpr GLenum GL_OPERAND1_RGB_EXT = 0x8591;
constexpr GLenum GL_OPERAND2_RGB_EXT = 0x8592;
constexpr GLenum GL_OPERAND0_ALPHA_EXT = 0x8598;
constexpr GLenum GL_OPERAND1_ALPHA_EXT = 0x8599;
constexpr GLenum GL_OPERAND2_ALPHA_EXT = 0x859A;
#endif /* GL_EXT_texture_env_combine */
#ifndef GL_EXT_texture_env_dot3
#define GL_EXT_texture_env_dot3 1
constexpr GLenum GL_DOT3_RGB_EXT = 0x8740;
constexpr GLenum GL_DOT3_RGBA_EXT = 0x8741;
#endif /* GL_EXT_texture_env_dot3 */
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
#ifndef GL_EXT_texture_integer
#define GL_EXT_texture_integer 1
constexpr GLenum GL_RGBA32UI_EXT = 0x8D70;
constexpr GLenum GL_RGB32UI_EXT = 0x8D71;
constexpr GLenum GL_ALPHA32UI_EXT = 0x8D72;
constexpr GLenum GL_INTENSITY32UI_EXT = 0x8D73;
constexpr GLenum GL_LUMINANCE32UI_EXT = 0x8D74;
constexpr GLenum GL_LUMINANCE_ALPHA32UI_EXT = 0x8D75;
constexpr GLenum GL_RGBA16UI_EXT = 0x8D76;
constexpr GLenum GL_RGB16UI_EXT = 0x8D77;
constexpr GLenum GL_ALPHA16UI_EXT = 0x8D78;
constexpr GLenum GL_INTENSITY16UI_EXT = 0x8D79;
constexpr GLenum GL_LUMINANCE16UI_EXT = 0x8D7A;
constexpr GLenum GL_LUMINANCE_ALPHA16UI_EXT = 0x8D7B;
constexpr GLenum GL_RGBA8UI_EXT = 0x8D7C;
constexpr GLenum GL_RGB8UI_EXT = 0x8D7D;
constexpr GLenum GL_ALPHA8UI_EXT = 0x8D7E;
constexpr GLenum GL_INTENSITY8UI_EXT = 0x8D7F;
constexpr GLenum GL_LUMINANCE8UI_EXT = 0x8D80;
constexpr GLenum GL_LUMINANCE_ALPHA8UI_EXT = 0x8D81;
constexpr GLenum GL_RGBA32I_EXT = 0x8D82;
constexpr GLenum GL_RGB32I_EXT = 0x8D83;
constexpr GLenum GL_ALPHA32I_EXT = 0x8D84;
constexpr GLenum GL_INTENSITY32I_EXT = 0x8D85;
constexpr GLenum GL_LUMINANCE32I_EXT = 0x8D86;
constexpr GLenum GL_LUMINANCE_ALPHA32I_EXT = 0x8D87;
constexpr GLenum GL_RGBA16I_EXT = 0x8D88;
constexpr GLenum GL_RGB16I_EXT = 0x8D89;
constexpr GLenum GL_ALPHA16I_EXT = 0x8D8A;
constexpr GLenum GL_INTENSITY16I_EXT = 0x8D8B;
constexpr GLenum GL_LUMINANCE16I_EXT = 0x8D8C;
constexpr GLenum GL_LUMINANCE_ALPHA16I_EXT = 0x8D8D;
constexpr GLenum GL_RGBA8I_EXT = 0x8D8E;
constexpr GLenum GL_RGB8I_EXT = 0x8D8F;
constexpr GLenum GL_ALPHA8I_EXT = 0x8D90;
constexpr GLenum GL_INTENSITY8I_EXT = 0x8D91;
constexpr GLenum GL_LUMINANCE8I_EXT = 0x8D92;
constexpr GLenum GL_LUMINANCE_ALPHA8I_EXT = 0x8D93;
constexpr GLenum GL_RED_INTEGER_EXT = 0x8D94;
constexpr GLenum GL_GREEN_INTEGER_EXT = 0x8D95;
constexpr GLenum GL_BLUE_INTEGER_EXT = 0x8D96;
constexpr GLenum GL_ALPHA_INTEGER_EXT = 0x8D97;
constexpr GLenum GL_RGB_INTEGER_EXT = 0x8D98;
constexpr GLenum GL_RGBA_INTEGER_EXT = 0x8D99;
constexpr GLenum GL_BGR_INTEGER_EXT = 0x8D9A;
constexpr GLenum GL_BGRA_INTEGER_EXT = 0x8D9B;
constexpr GLenum GL_LUMINANCE_INTEGER_EXT = 0x8D9C;
constexpr GLenum GL_LUMINANCE_ALPHA_INTEGER_EXT = 0x8D9D;
constexpr GLenum GL_RGBA_INTEGER_MODE_EXT = 0x8D9E;
void glTexParameterIivEXT(GLenum target, GLenum pname, GLint const  * params);
void glTexParameterIuivEXT(GLenum target, GLenum pname, GLuint const  * params);
void glGetTexParameterIivEXT(GLenum target, GLenum pname, GLint * params);
void glGetTexParameterIuivEXT(GLenum target, GLenum pname, GLuint * params);
void glClearColorIiEXT(GLint red, GLint green, GLint blue, GLint alpha);
void glClearColorIuiEXT(GLuint red, GLuint green, GLuint blue, GLuint alpha);
#endif /* GL_EXT_texture_integer */
#ifndef GL_EXT_texture_lod_bias
#define GL_EXT_texture_lod_bias 1
constexpr GLenum GL_MAX_TEXTURE_LOD_BIAS_EXT = 0x84FD;
constexpr GLenum GL_TEXTURE_FILTER_CONTROL_EXT = 0x8500;
constexpr GLenum GL_TEXTURE_LOD_BIAS_EXT = 0x8501;
#endif /* GL_EXT_texture_lod_bias */
#ifndef GL_EXT_texture_mirror_clamp
#define GL_EXT_texture_mirror_clamp 1
constexpr GLenum GL_MIRROR_CLAMP_EXT = 0x8742;
constexpr GLenum GL_MIRROR_CLAMP_TO_EDGE_EXT = 0x8743;
constexpr GLenum GL_MIRROR_CLAMP_TO_BORDER_EXT = 0x8912;
#endif /* GL_EXT_texture_mirror_clamp */
#ifndef GL_EXT_texture_object
#define GL_EXT_texture_object 1
constexpr GLenum GL_TEXTURE_PRIORITY_EXT = 0x8066;
constexpr GLenum GL_TEXTURE_RESIDENT_EXT = 0x8067;
constexpr GLenum GL_TEXTURE_1D_BINDING_EXT = 0x8068;
constexpr GLenum GL_TEXTURE_2D_BINDING_EXT = 0x8069;
constexpr GLenum GL_TEXTURE_3D_BINDING_EXT = 0x806A;
GLboolean glAreTexturesResidentEXT(GLsizei n, GLuint const  * textures, GLboolean * residences);
void glBindTextureEXT(GLenum target, GLuint texture);
void glDeleteTexturesEXT(GLsizei n, GLuint const  * textures);
void glGenTexturesEXT(GLsizei n, GLuint * textures);
GLboolean glIsTextureEXT(GLuint texture);
void glPrioritizeTexturesEXT(GLsizei n, GLuint const  * textures, GLclampf const  * priorities);
#endif /* GL_EXT_texture_object */
#ifndef GL_EXT_texture_perturb_normal
#define GL_EXT_texture_perturb_normal 1
constexpr GLenum GL_PERTURB_EXT = 0x85AE;
constexpr GLenum GL_TEXTURE_NORMAL_EXT = 0x85AF;
void glTextureNormalEXT(GLenum mode);
#endif /* GL_EXT_texture_perturb_normal */
#ifndef GL_EXT_texture_sRGB
#define GL_EXT_texture_sRGB 1
constexpr GLenum GL_SRGB_EXT = 0x8C40;
constexpr GLenum GL_SRGB8_EXT = 0x8C41;
constexpr GLenum GL_SRGB_ALPHA_EXT = 0x8C42;
constexpr GLenum GL_SRGB8_ALPHA8_EXT = 0x8C43;
constexpr GLenum GL_SLUMINANCE_ALPHA_EXT = 0x8C44;
constexpr GLenum GL_SLUMINANCE8_ALPHA8_EXT = 0x8C45;
constexpr GLenum GL_SLUMINANCE_EXT = 0x8C46;
constexpr GLenum GL_SLUMINANCE8_EXT = 0x8C47;
constexpr GLenum GL_COMPRESSED_SRGB_EXT = 0x8C48;
constexpr GLenum GL_COMPRESSED_SRGB_ALPHA_EXT = 0x8C49;
constexpr GLenum GL_COMPRESSED_SLUMINANCE_EXT = 0x8C4A;
constexpr GLenum GL_COMPRESSED_SLUMINANCE_ALPHA_EXT = 0x8C4B;
constexpr GLenum GL_COMPRESSED_SRGB_S3TC_DXT1_EXT = 0x8C4C;
constexpr GLenum GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT1_EXT = 0x8C4D;
constexpr GLenum GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT3_EXT = 0x8C4E;
constexpr GLenum GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT5_EXT = 0x8C4F;
#endif /* GL_EXT_texture_sRGB */
#ifndef GL_EXT_texture_sRGB_R8
#define GL_EXT_texture_sRGB_R8 1
constexpr GLenum GL_SR8_EXT = 0x8FBD;
#endif /* GL_EXT_texture_sRGB_R8 */
#ifndef GL_EXT_texture_sRGB_decode
#define GL_EXT_texture_sRGB_decode 1
constexpr GLenum GL_TEXTURE_SRGB_DECODE_EXT = 0x8A48;
constexpr GLenum GL_DECODE_EXT = 0x8A49;
constexpr GLenum GL_SKIP_DECODE_EXT = 0x8A4A;
#endif /* GL_EXT_texture_sRGB_decode */
#ifndef GL_EXT_texture_shared_exponent
#define GL_EXT_texture_shared_exponent 1
constexpr GLenum GL_RGB9_E5_EXT = 0x8C3D;
constexpr GLenum GL_UNSIGNED_INT_5_9_9_9_REV_EXT = 0x8C3E;
constexpr GLenum GL_TEXTURE_SHARED_SIZE_EXT = 0x8C3F;
#endif /* GL_EXT_texture_shared_exponent */
#ifndef GL_EXT_texture_snorm
#define GL_EXT_texture_snorm 1
constexpr GLenum GL_ALPHA_SNORM = 0x9010;
constexpr GLenum GL_LUMINANCE_SNORM = 0x9011;
constexpr GLenum GL_LUMINANCE_ALPHA_SNORM = 0x9012;
constexpr GLenum GL_INTENSITY_SNORM = 0x9013;
constexpr GLenum GL_ALPHA8_SNORM = 0x9014;
constexpr GLenum GL_LUMINANCE8_SNORM = 0x9015;
constexpr GLenum GL_LUMINANCE8_ALPHA8_SNORM = 0x9016;
constexpr GLenum GL_INTENSITY8_SNORM = 0x9017;
constexpr GLenum GL_ALPHA16_SNORM = 0x9018;
constexpr GLenum GL_LUMINANCE16_SNORM = 0x9019;
constexpr GLenum GL_LUMINANCE16_ALPHA16_SNORM = 0x901A;
constexpr GLenum GL_INTENSITY16_SNORM = 0x901B;
constexpr GLenum GL_RED_SNORM = 0x8F90;
constexpr GLenum GL_RG_SNORM = 0x8F91;
constexpr GLenum GL_RGB_SNORM = 0x8F92;
constexpr GLenum GL_RGBA_SNORM = 0x8F93;
constexpr GLenum GL_R8_SNORM = 0x8F94;
constexpr GLenum GL_RG8_SNORM = 0x8F95;
constexpr GLenum GL_RGB8_SNORM = 0x8F96;
constexpr GLenum GL_RGBA8_SNORM = 0x8F97;
constexpr GLenum GL_R16_SNORM = 0x8F98;
constexpr GLenum GL_RG16_SNORM = 0x8F99;
constexpr GLenum GL_RGB16_SNORM = 0x8F9A;
constexpr GLenum GL_RGBA16_SNORM = 0x8F9B;
constexpr GLenum GL_SIGNED_NORMALIZED = 0x8F9C;
#endif /* GL_EXT_texture_snorm */
#ifndef GL_EXT_texture_swizzle
#define GL_EXT_texture_swizzle 1
constexpr GLenum GL_TEXTURE_SWIZZLE_R_EXT = 0x8E42;
constexpr GLenum GL_TEXTURE_SWIZZLE_G_EXT = 0x8E43;
constexpr GLenum GL_TEXTURE_SWIZZLE_B_EXT = 0x8E44;
constexpr GLenum GL_TEXTURE_SWIZZLE_A_EXT = 0x8E45;
constexpr GLenum GL_TEXTURE_SWIZZLE_RGBA_EXT = 0x8E46;
#endif /* GL_EXT_texture_swizzle */
#ifndef GL_EXT_timer_query
#define GL_EXT_timer_query 1
constexpr GLenum GL_TIME_ELAPSED_EXT = 0x88BF;
void glGetQueryObjecti64vEXT(GLuint id, GLenum pname, GLint64 * params);
void glGetQueryObjectui64vEXT(GLuint id, GLenum pname, GLuint64 * params);
#endif /* GL_EXT_timer_query */
#ifndef GL_EXT_transform_feedback
#define GL_EXT_transform_feedback 1
constexpr GLenum GL_TRANSFORM_FEEDBACK_BUFFER_EXT = 0x8C8E;
constexpr GLenum GL_TRANSFORM_FEEDBACK_BUFFER_START_EXT = 0x8C84;
constexpr GLenum GL_TRANSFORM_FEEDBACK_BUFFER_SIZE_EXT = 0x8C85;
constexpr GLenum GL_TRANSFORM_FEEDBACK_BUFFER_BINDING_EXT = 0x8C8F;
constexpr GLenum GL_INTERLEAVED_ATTRIBS_EXT = 0x8C8C;
constexpr GLenum GL_SEPARATE_ATTRIBS_EXT = 0x8C8D;
constexpr GLenum GL_PRIMITIVES_GENERATED_EXT = 0x8C87;
constexpr GLenum GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN_EXT = 0x8C88;
constexpr GLenum GL_RASTERIZER_DISCARD_EXT = 0x8C89;
constexpr GLenum GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS_EXT = 0x8C8A;
constexpr GLenum GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS_EXT = 0x8C8B;
constexpr GLenum GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS_EXT = 0x8C80;
constexpr GLenum GL_TRANSFORM_FEEDBACK_VARYINGS_EXT = 0x8C83;
constexpr GLenum GL_TRANSFORM_FEEDBACK_BUFFER_MODE_EXT = 0x8C7F;
constexpr GLenum GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH_EXT = 0x8C76;
void glBeginTransformFeedbackEXT(GLenum primitiveMode);
void glEndTransformFeedbackEXT();
void glBindBufferRangeEXT(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
void glBindBufferOffsetEXT(GLenum target, GLuint index, GLuint buffer, GLintptr offset);
void glBindBufferBaseEXT(GLenum target, GLuint index, GLuint buffer);
void glTransformFeedbackVaryingsEXT(GLuint program, GLsizei count, GLchar const  *const* varyings, GLenum bufferMode);
void glGetTransformFeedbackVaryingEXT(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLsizei * size, GLenum * type, GLchar * name);
#endif /* GL_EXT_transform_feedback */
#ifndef GL_EXT_vertex_array
#define GL_EXT_vertex_array 1
constexpr GLenum GL_VERTEX_ARRAY_EXT = 0x8074;
constexpr GLenum GL_NORMAL_ARRAY_EXT = 0x8075;
constexpr GLenum GL_COLOR_ARRAY_EXT = 0x8076;
constexpr GLenum GL_INDEX_ARRAY_EXT = 0x8077;
constexpr GLenum GL_TEXTURE_COORD_ARRAY_EXT = 0x8078;
constexpr GLenum GL_EDGE_FLAG_ARRAY_EXT = 0x8079;
constexpr GLenum GL_VERTEX_ARRAY_SIZE_EXT = 0x807A;
constexpr GLenum GL_VERTEX_ARRAY_TYPE_EXT = 0x807B;
constexpr GLenum GL_VERTEX_ARRAY_STRIDE_EXT = 0x807C;
constexpr GLenum GL_VERTEX_ARRAY_COUNT_EXT = 0x807D;
constexpr GLenum GL_NORMAL_ARRAY_TYPE_EXT = 0x807E;
constexpr GLenum GL_NORMAL_ARRAY_STRIDE_EXT = 0x807F;
constexpr GLenum GL_NORMAL_ARRAY_COUNT_EXT = 0x8080;
constexpr GLenum GL_COLOR_ARRAY_SIZE_EXT = 0x8081;
constexpr GLenum GL_COLOR_ARRAY_TYPE_EXT = 0x8082;
constexpr GLenum GL_COLOR_ARRAY_STRIDE_EXT = 0x8083;
constexpr GLenum GL_COLOR_ARRAY_COUNT_EXT = 0x8084;
constexpr GLenum GL_INDEX_ARRAY_TYPE_EXT = 0x8085;
constexpr GLenum GL_INDEX_ARRAY_STRIDE_EXT = 0x8086;
constexpr GLenum GL_INDEX_ARRAY_COUNT_EXT = 0x8087;
constexpr GLenum GL_TEXTURE_COORD_ARRAY_SIZE_EXT = 0x8088;
constexpr GLenum GL_TEXTURE_COORD_ARRAY_TYPE_EXT = 0x8089;
constexpr GLenum GL_TEXTURE_COORD_ARRAY_STRIDE_EXT = 0x808A;
constexpr GLenum GL_TEXTURE_COORD_ARRAY_COUNT_EXT = 0x808B;
constexpr GLenum GL_EDGE_FLAG_ARRAY_STRIDE_EXT = 0x808C;
constexpr GLenum GL_EDGE_FLAG_ARRAY_COUNT_EXT = 0x808D;
constexpr GLenum GL_VERTEX_ARRAY_POINTER_EXT = 0x808E;
constexpr GLenum GL_NORMAL_ARRAY_POINTER_EXT = 0x808F;
constexpr GLenum GL_COLOR_ARRAY_POINTER_EXT = 0x8090;
constexpr GLenum GL_INDEX_ARRAY_POINTER_EXT = 0x8091;
constexpr GLenum GL_TEXTURE_COORD_ARRAY_POINTER_EXT = 0x8092;
constexpr GLenum GL_EDGE_FLAG_ARRAY_POINTER_EXT = 0x8093;
void glArrayElementEXT(GLint i);
void glColorPointerEXT(GLint size, GLenum type, GLsizei stride, GLsizei count, const void * pointer);
void glDrawArraysEXT(GLenum mode, GLint first, GLsizei count);
void glEdgeFlagPointerEXT(GLsizei stride, GLsizei count, GLboolean const  * pointer);
void glGetPointervEXT(GLenum pname, void ** params);
void glIndexPointerEXT(GLenum type, GLsizei stride, GLsizei count, const void * pointer);
void glNormalPointerEXT(GLenum type, GLsizei stride, GLsizei count, const void * pointer);
void glTexCoordPointerEXT(GLint size, GLenum type, GLsizei stride, GLsizei count, const void * pointer);
void glVertexPointerEXT(GLint size, GLenum type, GLsizei stride, GLsizei count, const void * pointer);
#endif /* GL_EXT_vertex_array */
#ifndef GL_EXT_vertex_array_bgra
#define GL_EXT_vertex_array_bgra 1
#endif /* GL_EXT_vertex_array_bgra */
#ifndef GL_EXT_vertex_attrib_64bit
#define GL_EXT_vertex_attrib_64bit 1
constexpr GLenum GL_DOUBLE_VEC2_EXT = 0x8FFC;
constexpr GLenum GL_DOUBLE_VEC3_EXT = 0x8FFD;
constexpr GLenum GL_DOUBLE_VEC4_EXT = 0x8FFE;
constexpr GLenum GL_DOUBLE_MAT2_EXT = 0x8F46;
constexpr GLenum GL_DOUBLE_MAT3_EXT = 0x8F47;
constexpr GLenum GL_DOUBLE_MAT4_EXT = 0x8F48;
constexpr GLenum GL_DOUBLE_MAT2x3_EXT = 0x8F49;
constexpr GLenum GL_DOUBLE_MAT2x4_EXT = 0x8F4A;
constexpr GLenum GL_DOUBLE_MAT3x2_EXT = 0x8F4B;
constexpr GLenum GL_DOUBLE_MAT3x4_EXT = 0x8F4C;
constexpr GLenum GL_DOUBLE_MAT4x2_EXT = 0x8F4D;
constexpr GLenum GL_DOUBLE_MAT4x3_EXT = 0x8F4E;
void glVertexAttribL1dEXT(GLuint index, GLdouble x);
void glVertexAttribL2dEXT(GLuint index, GLdouble x, GLdouble y);
void glVertexAttribL3dEXT(GLuint index, GLdouble x, GLdouble y, GLdouble z);
void glVertexAttribL4dEXT(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void glVertexAttribL1dvEXT(GLuint index, GLdouble const  * v);
void glVertexAttribL2dvEXT(GLuint index, GLdouble const  * v);
void glVertexAttribL3dvEXT(GLuint index, GLdouble const  * v);
void glVertexAttribL4dvEXT(GLuint index, GLdouble const  * v);
void glVertexAttribLPointerEXT(GLuint index, GLint size, GLenum type, GLsizei stride, const void * pointer);
void glGetVertexAttribLdvEXT(GLuint index, GLenum pname, GLdouble * params);
#endif /* GL_EXT_vertex_attrib_64bit */
#ifndef GL_EXT_vertex_shader
#define GL_EXT_vertex_shader 1
constexpr GLenum GL_VERTEX_SHADER_EXT = 0x8780;
constexpr GLenum GL_VERTEX_SHADER_BINDING_EXT = 0x8781;
constexpr GLenum GL_OP_INDEX_EXT = 0x8782;
constexpr GLenum GL_OP_NEGATE_EXT = 0x8783;
constexpr GLenum GL_OP_DOT3_EXT = 0x8784;
constexpr GLenum GL_OP_DOT4_EXT = 0x8785;
constexpr GLenum GL_OP_MUL_EXT = 0x8786;
constexpr GLenum GL_OP_ADD_EXT = 0x8787;
constexpr GLenum GL_OP_MADD_EXT = 0x8788;
constexpr GLenum GL_OP_FRAC_EXT = 0x8789;
constexpr GLenum GL_OP_MAX_EXT = 0x878A;
constexpr GLenum GL_OP_MIN_EXT = 0x878B;
constexpr GLenum GL_OP_SET_GE_EXT = 0x878C;
constexpr GLenum GL_OP_SET_LT_EXT = 0x878D;
constexpr GLenum GL_OP_CLAMP_EXT = 0x878E;
constexpr GLenum GL_OP_FLOOR_EXT = 0x878F;
constexpr GLenum GL_OP_ROUND_EXT = 0x8790;
constexpr GLenum GL_OP_EXP_BASE_2_EXT = 0x8791;
constexpr GLenum GL_OP_LOG_BASE_2_EXT = 0x8792;
constexpr GLenum GL_OP_POWER_EXT = 0x8793;
constexpr GLenum GL_OP_RECIP_EXT = 0x8794;
constexpr GLenum GL_OP_RECIP_SQRT_EXT = 0x8795;
constexpr GLenum GL_OP_SUB_EXT = 0x8796;
constexpr GLenum GL_OP_CROSS_PRODUCT_EXT = 0x8797;
constexpr GLenum GL_OP_MULTIPLY_MATRIX_EXT = 0x8798;
constexpr GLenum GL_OP_MOV_EXT = 0x8799;
constexpr GLenum GL_OUTPUT_VERTEX_EXT = 0x879A;
constexpr GLenum GL_OUTPUT_COLOR0_EXT = 0x879B;
constexpr GLenum GL_OUTPUT_COLOR1_EXT = 0x879C;
constexpr GLenum GL_OUTPUT_TEXTURE_COORD0_EXT = 0x879D;
constexpr GLenum GL_OUTPUT_TEXTURE_COORD1_EXT = 0x879E;
constexpr GLenum GL_OUTPUT_TEXTURE_COORD2_EXT = 0x879F;
constexpr GLenum GL_OUTPUT_TEXTURE_COORD3_EXT = 0x87A0;
constexpr GLenum GL_OUTPUT_TEXTURE_COORD4_EXT = 0x87A1;
constexpr GLenum GL_OUTPUT_TEXTURE_COORD5_EXT = 0x87A2;
constexpr GLenum GL_OUTPUT_TEXTURE_COORD6_EXT = 0x87A3;
constexpr GLenum GL_OUTPUT_TEXTURE_COORD7_EXT = 0x87A4;
constexpr GLenum GL_OUTPUT_TEXTURE_COORD8_EXT = 0x87A5;
constexpr GLenum GL_OUTPUT_TEXTURE_COORD9_EXT = 0x87A6;
constexpr GLenum GL_OUTPUT_TEXTURE_COORD10_EXT = 0x87A7;
constexpr GLenum GL_OUTPUT_TEXTURE_COORD11_EXT = 0x87A8;
constexpr GLenum GL_OUTPUT_TEXTURE_COORD12_EXT = 0x87A9;
constexpr GLenum GL_OUTPUT_TEXTURE_COORD13_EXT = 0x87AA;
constexpr GLenum GL_OUTPUT_TEXTURE_COORD14_EXT = 0x87AB;
constexpr GLenum GL_OUTPUT_TEXTURE_COORD15_EXT = 0x87AC;
constexpr GLenum GL_OUTPUT_TEXTURE_COORD16_EXT = 0x87AD;
constexpr GLenum GL_OUTPUT_TEXTURE_COORD17_EXT = 0x87AE;
constexpr GLenum GL_OUTPUT_TEXTURE_COORD18_EXT = 0x87AF;
constexpr GLenum GL_OUTPUT_TEXTURE_COORD19_EXT = 0x87B0;
constexpr GLenum GL_OUTPUT_TEXTURE_COORD20_EXT = 0x87B1;
constexpr GLenum GL_OUTPUT_TEXTURE_COORD21_EXT = 0x87B2;
constexpr GLenum GL_OUTPUT_TEXTURE_COORD22_EXT = 0x87B3;
constexpr GLenum GL_OUTPUT_TEXTURE_COORD23_EXT = 0x87B4;
constexpr GLenum GL_OUTPUT_TEXTURE_COORD24_EXT = 0x87B5;
constexpr GLenum GL_OUTPUT_TEXTURE_COORD25_EXT = 0x87B6;
constexpr GLenum GL_OUTPUT_TEXTURE_COORD26_EXT = 0x87B7;
constexpr GLenum GL_OUTPUT_TEXTURE_COORD27_EXT = 0x87B8;
constexpr GLenum GL_OUTPUT_TEXTURE_COORD28_EXT = 0x87B9;
constexpr GLenum GL_OUTPUT_TEXTURE_COORD29_EXT = 0x87BA;
constexpr GLenum GL_OUTPUT_TEXTURE_COORD30_EXT = 0x87BB;
constexpr GLenum GL_OUTPUT_TEXTURE_COORD31_EXT = 0x87BC;
constexpr GLenum GL_OUTPUT_FOG_EXT = 0x87BD;
constexpr GLenum GL_SCALAR_EXT = 0x87BE;
constexpr GLenum GL_VECTOR_EXT = 0x87BF;
constexpr GLenum GL_MATRIX_EXT = 0x87C0;
constexpr GLenum GL_VARIANT_EXT = 0x87C1;
constexpr GLenum GL_INVARIANT_EXT = 0x87C2;
constexpr GLenum GL_LOCAL_CONSTANT_EXT = 0x87C3;
constexpr GLenum GL_LOCAL_EXT = 0x87C4;
constexpr GLenum GL_MAX_VERTEX_SHADER_INSTRUCTIONS_EXT = 0x87C5;
constexpr GLenum GL_MAX_VERTEX_SHADER_VARIANTS_EXT = 0x87C6;
constexpr GLenum GL_MAX_VERTEX_SHADER_INVARIANTS_EXT = 0x87C7;
constexpr GLenum GL_MAX_VERTEX_SHADER_LOCAL_CONSTANTS_EXT = 0x87C8;
constexpr GLenum GL_MAX_VERTEX_SHADER_LOCALS_EXT = 0x87C9;
constexpr GLenum GL_MAX_OPTIMIZED_VERTEX_SHADER_INSTRUCTIONS_EXT = 0x87CA;
constexpr GLenum GL_MAX_OPTIMIZED_VERTEX_SHADER_VARIANTS_EXT = 0x87CB;
constexpr GLenum GL_MAX_OPTIMIZED_VERTEX_SHADER_LOCAL_CONSTANTS_EXT = 0x87CC;
constexpr GLenum GL_MAX_OPTIMIZED_VERTEX_SHADER_INVARIANTS_EXT = 0x87CD;
constexpr GLenum GL_MAX_OPTIMIZED_VERTEX_SHADER_LOCALS_EXT = 0x87CE;
constexpr GLenum GL_VERTEX_SHADER_INSTRUCTIONS_EXT = 0x87CF;
constexpr GLenum GL_VERTEX_SHADER_VARIANTS_EXT = 0x87D0;
constexpr GLenum GL_VERTEX_SHADER_INVARIANTS_EXT = 0x87D1;
constexpr GLenum GL_VERTEX_SHADER_LOCAL_CONSTANTS_EXT = 0x87D2;
constexpr GLenum GL_VERTEX_SHADER_LOCALS_EXT = 0x87D3;
constexpr GLenum GL_VERTEX_SHADER_OPTIMIZED_EXT = 0x87D4;
constexpr GLenum GL_X_EXT = 0x87D5;
constexpr GLenum GL_Y_EXT = 0x87D6;
constexpr GLenum GL_Z_EXT = 0x87D7;
constexpr GLenum GL_W_EXT = 0x87D8;
constexpr GLenum GL_NEGATIVE_X_EXT = 0x87D9;
constexpr GLenum GL_NEGATIVE_Y_EXT = 0x87DA;
constexpr GLenum GL_NEGATIVE_Z_EXT = 0x87DB;
constexpr GLenum GL_NEGATIVE_W_EXT = 0x87DC;
constexpr GLenum GL_ZERO_EXT = 0x87DD;
constexpr GLenum GL_ONE_EXT = 0x87DE;
constexpr GLenum GL_NEGATIVE_ONE_EXT = 0x87DF;
constexpr GLenum GL_NORMALIZED_RANGE_EXT = 0x87E0;
constexpr GLenum GL_FULL_RANGE_EXT = 0x87E1;
constexpr GLenum GL_CURRENT_VERTEX_EXT = 0x87E2;
constexpr GLenum GL_MVP_MATRIX_EXT = 0x87E3;
constexpr GLenum GL_VARIANT_VALUE_EXT = 0x87E4;
constexpr GLenum GL_VARIANT_DATATYPE_EXT = 0x87E5;
constexpr GLenum GL_VARIANT_ARRAY_STRIDE_EXT = 0x87E6;
constexpr GLenum GL_VARIANT_ARRAY_TYPE_EXT = 0x87E7;
constexpr GLenum GL_VARIANT_ARRAY_EXT = 0x87E8;
constexpr GLenum GL_VARIANT_ARRAY_POINTER_EXT = 0x87E9;
constexpr GLenum GL_INVARIANT_VALUE_EXT = 0x87EA;
constexpr GLenum GL_INVARIANT_DATATYPE_EXT = 0x87EB;
constexpr GLenum GL_LOCAL_CONSTANT_VALUE_EXT = 0x87EC;
constexpr GLenum GL_LOCAL_CONSTANT_DATATYPE_EXT = 0x87ED;
void glBeginVertexShaderEXT();
void glEndVertexShaderEXT();
void glBindVertexShaderEXT(GLuint id);
GLuint glGenVertexShadersEXT(GLuint range);
void glDeleteVertexShaderEXT(GLuint id);
void glShaderOp1EXT(GLenum op, GLuint res, GLuint arg1);
void glShaderOp2EXT(GLenum op, GLuint res, GLuint arg1, GLuint arg2);
void glShaderOp3EXT(GLenum op, GLuint res, GLuint arg1, GLuint arg2, GLuint arg3);
void glSwizzleEXT(GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW);
void glWriteMaskEXT(GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW);
void glInsertComponentEXT(GLuint res, GLuint src, GLuint num);
void glExtractComponentEXT(GLuint res, GLuint src, GLuint num);
GLuint glGenSymbolsEXT(GLenum datatype, GLenum storagetype, GLenum range, GLuint components);
void glSetInvariantEXT(GLuint id, GLenum type, const void * addr);
void glSetLocalConstantEXT(GLuint id, GLenum type, const void * addr);
void glVariantbvEXT(GLuint id, GLbyte const  * addr);
void glVariantsvEXT(GLuint id, GLshort const  * addr);
void glVariantivEXT(GLuint id, GLint const  * addr);
void glVariantfvEXT(GLuint id, GLfloat const  * addr);
void glVariantdvEXT(GLuint id, GLdouble const  * addr);
void glVariantubvEXT(GLuint id, GLubyte const  * addr);
void glVariantusvEXT(GLuint id, GLushort const  * addr);
void glVariantuivEXT(GLuint id, GLuint const  * addr);
void glVariantPointerEXT(GLuint id, GLenum type, GLuint stride, const void * addr);
void glEnableVariantClientStateEXT(GLuint id);
void glDisableVariantClientStateEXT(GLuint id);
GLuint glBindLightParameterEXT(GLenum light, GLenum value);
GLuint glBindMaterialParameterEXT(GLenum face, GLenum value);
GLuint glBindTexGenParameterEXT(GLenum unit, GLenum coord, GLenum value);
GLuint glBindTextureUnitParameterEXT(GLenum unit, GLenum value);
GLuint glBindParameterEXT(GLenum value);
GLboolean glIsVariantEnabledEXT(GLuint id, GLenum cap);
void glGetVariantBooleanvEXT(GLuint id, GLenum value, GLboolean * data);
void glGetVariantIntegervEXT(GLuint id, GLenum value, GLint * data);
void glGetVariantFloatvEXT(GLuint id, GLenum value, GLfloat * data);
void glGetVariantPointervEXT(GLuint id, GLenum value, void ** data);
void glGetInvariantBooleanvEXT(GLuint id, GLenum value, GLboolean * data);
void glGetInvariantIntegervEXT(GLuint id, GLenum value, GLint * data);
void glGetInvariantFloatvEXT(GLuint id, GLenum value, GLfloat * data);
void glGetLocalConstantBooleanvEXT(GLuint id, GLenum value, GLboolean * data);
void glGetLocalConstantIntegervEXT(GLuint id, GLenum value, GLint * data);
void glGetLocalConstantFloatvEXT(GLuint id, GLenum value, GLfloat * data);
#endif /* GL_EXT_vertex_shader */
#ifndef GL_EXT_vertex_weighting
#define GL_EXT_vertex_weighting 1
constexpr GLenum GL_MODELVIEW0_STACK_DEPTH_EXT = 0x0BA3;
constexpr GLenum GL_MODELVIEW1_STACK_DEPTH_EXT = 0x8502;
constexpr GLenum GL_MODELVIEW0_MATRIX_EXT = 0x0BA6;
constexpr GLenum GL_MODELVIEW1_MATRIX_EXT = 0x8506;
constexpr GLenum GL_VERTEX_WEIGHTING_EXT = 0x8509;
constexpr GLenum GL_MODELVIEW0_EXT = 0x1700;
constexpr GLenum GL_MODELVIEW1_EXT = 0x850A;
constexpr GLenum GL_CURRENT_VERTEX_WEIGHT_EXT = 0x850B;
constexpr GLenum GL_VERTEX_WEIGHT_ARRAY_EXT = 0x850C;
constexpr GLenum GL_VERTEX_WEIGHT_ARRAY_SIZE_EXT = 0x850D;
constexpr GLenum GL_VERTEX_WEIGHT_ARRAY_TYPE_EXT = 0x850E;
constexpr GLenum GL_VERTEX_WEIGHT_ARRAY_STRIDE_EXT = 0x850F;
constexpr GLenum GL_VERTEX_WEIGHT_ARRAY_POINTER_EXT = 0x8510;
void glVertexWeightfEXT(GLfloat weight);
void glVertexWeightfvEXT(GLfloat const  * weight);
void glVertexWeightPointerEXT(GLint size, GLenum type, GLsizei stride, const void * pointer);
#endif /* GL_EXT_vertex_weighting */
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
#ifndef GL_EXT_x11_sync_object
#define GL_EXT_x11_sync_object 1
constexpr GLenum GL_SYNC_X11_FENCE_EXT = 0x90E1;
GLsync glImportSyncEXT(GLenum external_sync_type, GLintptr external_sync, GLbitfield flags);
#endif /* GL_EXT_x11_sync_object */
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
#ifndef GL_OES_query_matrix
#define GL_OES_query_matrix 1
GLbitfield glQueryMatrixxOES(GLfixed * mantissa, GLint * exponent);
#endif /* GL_OES_query_matrix */
#ifndef GL_OES_read_format
#define GL_OES_read_format 1
constexpr GLenum GL_IMPLEMENTATION_COLOR_READ_TYPE_OES = 0x8B9A;
constexpr GLenum GL_IMPLEMENTATION_COLOR_READ_FORMAT_OES = 0x8B9B;
#endif /* GL_OES_read_format */
#ifndef GL_OES_single_precision
#define GL_OES_single_precision 1
void glClearDepthfOES(GLclampf depth);
void glClipPlanefOES(GLenum plane, GLfloat const  * equation);
void glDepthRangefOES(GLclampf n, GLclampf f);
void glFrustumfOES(GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f);
void glGetClipPlanefOES(GLenum plane, GLfloat * equation);
void glOrthofOES(GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f);
#endif /* GL_OES_single_precision */
#ifndef GL_EXT_texture_shadow_lod
#define GL_EXT_texture_shadow_lod 1
#endif /* GL_EXT_texture_shadow_lod */

}
