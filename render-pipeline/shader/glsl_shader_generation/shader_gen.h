#pragma once
#ifndef SHADER_GEN_H
#define SHADER_GEN_H
#include "shader_defs.h"
#include <ostream>
#include <sstream>
#include <fstream>
#include <string>
#include "core/ds-classes/Stack.h"
#include "core/ds-classes/Array.h"
#include "render-pipeline/shader/VertexShader.h"
#include "render-pipeline/shader/FragmentShader.h"
#include "render-pipeline/shader/glsl_shader_generation/shader_defs.h"
#include "render-pipeline/shader/s_lab/svarog_material.h"
#include "main/enginewindow/enginewindow.h"
#define SHADER_DIR "/home/jordan/Documents/SvarogGameEngine/builds/shaders/"
#define MESH_ASSIGNED
#define DEFAULT_VERTEX_SHADER
#define DEFAULT_FRAGMENT_SHADER

class SvarogMaterial;
class ShaderGeneration {
    private:
        ShaderGeneration() {

        }

        struct shader_program_code {
            const char* vertex_code;
            const char* fragment_code;
        } mat_shader_code;

        struct shader_program_shaders {
            VertexShader material_vert_shader;
            FragmentShader material_frag_shader;
        } mat_shader_prg;

        ArrayList<const char*>vertex_shader_code;
        ArrayList<const char*>fragment_shader_code;
        ArrayList<SvarogMaterial>*generation_queue = new ArrayList<SvarogMaterial>();
        static ShaderGeneration* shader_gen_instance;
    public:
        static ShaderGeneration* generateShaderCode();
        VertexShader get_mat_vert() const;
        FragmentShader get_mat_frag() const;
        void add_vert_code(const char* code);
        void add_frag_code(const char* code);
        void make_shaders();
        void send_shaders();
        const char* get_vertex_code() const;
        const char* get_fragment_code() const;
        void input_mat(SvarogMaterial to_compile);
};

#endif