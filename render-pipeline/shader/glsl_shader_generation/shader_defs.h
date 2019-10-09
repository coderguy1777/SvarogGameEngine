#pragma once
#ifndef SHADER_DEFS_H
#define SHADER_DEFS_H
#define GLSL_V(N) "#version\t" #N ";"
#define GLSL_CORE_V(N) "#version\t" #N "\tcore" ";"
#define UF_LONG(X) "uniform long\t" #X ";"
#define UF_SHORT(X) "uniform short\t" #X ";"
#define UF_FLOAT(X) "uniform float\t" #X ";"
#define UF_INT(X) "uniform int\t" #X ";"
#define UF_DOUBLE(X) "uniform double\t" #X ";"
#define LAYOUT_VEC2(X) "layout (location=0) in vec2\t" #X ";"
#define LAYOUT_VEC3(X) "layout (location=0) in vec3\t" #X ";"
#define LAYOUT_VEC4(X) "layout (location=0) in vec4\t" #X ";"
#define LAYOUT_MAT2(X) "layout (location=0) in mat2\t" #X ";"
#define LAYOUT_MAT3(X) "layout (location=0) in mat3\t" #X ";"
#define LAYOUT_MAT4(X) "layout (location=0) in mat4\t" #X ";"
#define UF_VEC4(N, X, Y, Z, W) "uniform vec4" #N"("#X"," #Y"," #Z"," #W");"
#define GLSL_VEC4_2(X, Y) vec4(X, Y);
#define GLSL_VEC3(N, X, Y, Z) vec3 N(X, Y, Z);
#define GLSL_VEC2(N, X, Y) vec2 N(X, Y);
#define GLSL_MAT2(X, N) mat2 X(N);
#define GLSL_MAT3(Y, N) mat3 Y(N);
#define GLSL_MAT4(Z, N) mat4 Z(N);
#include<string>

struct shader_attrib {
    unsigned int shader_program;
    std::string name;
};

struct uniform_1f {
    shader_attrib float_id;
    float value;
};

struct uniform_2f {
    shader_attrib float2_id;
    float vals[2];
};

struct uniform_3f {
    shader_attrib float3_id;
    float vals[3];
};

struct uniform_4f {
    shader_attrib float4_id;
    float vals[4];
};

struct uniform_1int {
    shader_attrib int_id;
    int value;
};

struct uniform_2int {
    shader_attrib int2_id;
    int vals[2];
};

struct uniform_3int {
    shader_attrib int3_id;
    int vals[3];
};

struct uniform_4int {
    shader_attrib int4_id;
    int vals[4];
};

#endif