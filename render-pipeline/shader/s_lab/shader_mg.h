#pragma once
#ifndef SHADER_MG_H
#define SHADER_MG_H
#include <fstream>
#include <ostream>
#include "core/ds-classes/ArrayList.h"
#include "render-pipeline/shader/VertexShader.h"
#include "render-pipeline/shader/FragmentShader.h"
#include "render-pipeline/shader/s_lab/svarog_material.h"
#include "core/String.h"
#include "render-pipeline/shader/glsl_shader_generation/shader_defs.h"
class ShaderManager {
    private:
        static ShaderManager* shader_manager;
        ShaderManager(){}
    public: 
        static ShaderManager* getShaderManager();
        ~ShaderManager() {}
        void compile_vertex();
        void compile_fragment();
};

#endif