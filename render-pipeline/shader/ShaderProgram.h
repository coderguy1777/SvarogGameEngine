#pragma once
#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H
#include "render-pipeline/gl_libs.h"
#include "VertexShader.h"
#include "FragmentShader.h"
#include "math/vec3.h"

struct shader_group {
    VertexShader vert_sh_1;
    FragmentShader frag_sh_2;
};

struct shader_program {
    bool link_success;
    shader_group material_group;
    unsigned int shader_id;
};

class ShaderProgram {
    private:
        shader_program* sh_prg;

    public:
        ShaderProgram() {
            sh_prg = new shader_program();
        }
        
        void set_state(int link_state);
        bool get_link_status() const;
        void bind_shaders(VertexShader vert, FragmentShader frag);
        unsigned int get_shader_id() const;
        void use();

};

#endif