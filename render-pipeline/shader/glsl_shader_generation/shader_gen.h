#pragma once
#ifndef SHADER_GEN_H
#define SHADER_GEN_H
#include "shader_defs.h"
#include <ostream>
#include <fstream>
#include "core/ds-classes/ArrayList.h"
#include "render-pipeline/shader/VertexShader.h"
#include "render-pipeline/shader/FragmentShader.h"
#define SHADER_DIR "/home/jordan/Documents/SvarogGameEngine/builds/shaders/"
#define MESH_ASSIGNED
#define DEFAULT_VERTEX_SHADER
#define DEFAULT_FRAGMENT_SHADER

class ShaderGeneration {
    private:
        struct shader_program_shaders {
            VertexShader material_vert_shader;
            FragmentShader material_frag_shader;
            VertexShader get_vert_shader() const {
                return material_vert_shader;
            }

            FragmentShader get_frag_shader() const {
                return material_frag_shader;
            }
        } mat_shader_prg;
        
    public:
        ShaderGeneration();

        VertexShader get_mat_vert() const;
        FragmentShader get_mat_frag() const;
        void add_to_manager();
};

#endif