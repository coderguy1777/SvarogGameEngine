#pragma once
#ifndef SHADER_DEFS_H
#define SHADER_DEFS_H
#define GLSL_V(N) "#version\t" #N ";\n"
#define GLSL_CORE_V(N) "#version\t" #N "\tcore" ";\n"
#define UF_LONG(X) "uniform long\t" #X ";\n"
#define UF_SHORT(X) "uniform short\t" #X ";\n"
#define UF_FLOAT(X) "uniform float\t" #X ";\n"
#define UF_INT(X) "uniform int\t" #X ";\n"
#define UF_DOUBLE(X) "uniform double\t" #X ";\n"
#define LAYOUT_VEC2(X) "layout (location=0) in vec2\t" #X ";\n"
#define LAYOUT_VEC3(X) "layout (location=0) in vec3\t" #X ";\n"
#define LAYOUT_VEC4(X) "layout (location=0) in vec4\t" #X ";\n"
#define LAYOUT_MAT2(X) "layout (location=0) in mat2\t" #X ";\n"
#define LAYOUT_MAT3(X) "layout (location=0) in mat3\t" #X ";\n"
#define LAYOUT_MAT4(X) "layout (location=0) in mat4\t" #X ";\n"
#define UF_VEC4(N, X, Y, Z, W) "uniform vec4" #N"("#X"," #Y"," #Z"," #W");\n"
#define OUT_VEC4(N) "out vec4" #N ";\n"
#define GLSL_VEC4_2(X, Y) vec4(X, Y);
#define GLSL_VEC3(N, X, Y, Z) vec3 N(X, Y, Z);
#define GLSL_VEC2(N, X, Y) vec2 N(X, Y);
#define GLSL_MAT2(X, N) mat2 X(N);
#define GLSL_MAT3(Y, N) mat3 Y(N);
#define GLSL_MAT4(Z, N) mat4 Z(N);
#endif