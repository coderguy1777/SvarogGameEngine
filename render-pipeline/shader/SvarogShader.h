#pragma once
#ifndef SVAROGSHADER_H
#define SVAROGSHADER_h
#include<glad/glad.h>
enum class SHADER_TYPE {
    FRAG_SHADER = 1,
    VERT_SHADER = 2,
};

struct Shader_Flags {
        bool is_used;
        int compile_state;
        int shader_type;
};

class SvarogShader {
    public: 
        Shader_Flags flags;
        virtual void set_use_state() = 0;
        virtual bool get_use_state() const = 0;
        virtual void init_state(unsigned int state) = 0;
        virtual unsigned int get_initstate() const = 0;
        virtual unsigned int compile_shader() = 0;
};
#endif