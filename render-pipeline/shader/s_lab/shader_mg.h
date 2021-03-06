#pragma once
#ifndef SHADER_MG_H
#define SHADER_MG_H
#include <fstream>
#include <stack>
#include <ostream>
#include "core/ds-classes/ArrayList.h"
#include "core/String.h"
#include "render-pipeline/shader/s_lab/svarog_material.h"
class SvarogMaterial;
class ShaderManager {
    private:
        static ShaderManager* shader_manager;
        ArrayList<ShaderProgram>*shader_mats = new ArrayList<ShaderProgram>();
        std::stack<SvarogMaterial>material_li;
        ShaderManager(){}
    public: 
        ~ShaderManager() {}
        static ShaderManager* getShaderManager();
        void pass_code(VertexShader vert_mat, FragmentShader frag_mat);
        void add_new_material(SvarogMaterial m_mat);
        void render_materials();
        SvarogMaterial get_material(const char* m_name) const;

};

#endif