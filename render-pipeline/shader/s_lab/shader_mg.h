#pragma once
#ifndef SHADER_MG_H
#define SHADER_MG_H
#include <fstream>
#include <ostream>
#include "core/ds-classes/ArrayList.h"
#include "svarog_material.h"
#include "render-pipeline/shader/VertexShader.h"
#include "render-pipeline/shader/FragmentShader.h"
#include "core/String.h"
#include "render-pipeline/shader/glsl_shader_generation/shader_defs.h"

// TODO: fix map bug with hash errors.
struct VertShaderPair {
    VertexShader vert_s;
    unsigned int shader_id;
};

struct FragShaderPair {
    FragmentShader frag_s;
    unsigned int shader_id;
};

class ShaderManager {
    private:
        static ShaderManager* shader_mg;
        ArrayList<VertShaderPair>vert_li;
        ArrayList<FragShaderPair>frag_li;
    public: 
        static ShaderManager* getShaderManager();
        void insert_mat(SvarogMaterial mat);

};

#endif