#pragma once
#ifndef SVAROGSHADER_H
#define SVAROGSHADER_h
#include<glad/glad.h>
#include<spdlog/spdlog.h>
enum class SHADER_TYPE {
    FRAG_SHADER = 1,
    VERT_SHADER = 2,
};

struct Shader_Flags {
    bool is_used;
    int compile_state;
    int shader_type;
};

struct Shader_Code {
    const char* shader_code;
    unsigned int success_state;
};

class SvarogShader {
    public: 
        unsigned int shader_f, shader_v;
        Shader_Flags flags;
        Shader_Code s_code;
        virtual void set_use_state() = 0;
        virtual bool get_use_state() const = 0;
        virtual void init_state(unsigned int state) = 0;
        virtual unsigned int get_initstate() const = 0;
        virtual void set_code(const char* code) = 0;
        virtual const char* get_code() const = 0;
        virtual void compile_shader() = 0;
        virtual unsigned int get_shader_id() = 0;
};
#endif