#pragma once
#ifndef SHADER_MG_H
#define SHADER_MG_H
#include <fstream>
#include <ostream>
#include "core/ds-classes/ArrayList.h"
#include "core/String.h"
#include "render-pipeline/shader/s_lab/svarog_material.h"
#include "render-pipeline/shader/glsl_shader_generation/shader_defs.h"
class SvarogMaterial;
class ShaderManager {
    private:
        static ShaderManager* shader_manager;
        ArrayList<ShaderProgram>*shader_mats = new ArrayList<ShaderProgram>();
        ShaderManager(){}
    public: 
        ~ShaderManager() {}
        static ShaderManager* getShaderManager();
        void pass_code(VertexShader vert_mat, FragmentShader frag_mat);
};

#endif