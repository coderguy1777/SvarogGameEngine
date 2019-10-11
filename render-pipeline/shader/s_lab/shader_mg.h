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

struct mesh_assignment {
    String mesh_name;
    unsigned int mesh_id;
    ShaderProgram mesh_material;
};
class ShaderManager {
    private:
        static ShaderManager* shader_manager;
        ArrayList<mesh_assignment>renderable_materials; // for storing all renderable materials for meshes.
        ShaderManager(){}
    public: 
        ~ShaderManager() {}
        static ShaderManager* getShaderManager();
        void test(SvarogMaterial a);
        void compile_vertex();
        void compile_fragment();
};

#endif