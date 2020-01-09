#include "shader_mg.h"
ShaderManager* ShaderManager::getShaderManager() {
    if(!shader_manager) {
        shader_manager = new ShaderManager;
    }
    return shader_manager;
}

void ShaderManager::pass_code(VertexShader vert_pt, FragmentShader frag_pt) {
    if(vert_pt.get_code() == "" || frag_pt.get_code() == "") {
        spdlog::error("NO SHADER CODE PASSED");
    } else {
        spdlog::warn("SHADER CODE PASSED");
    }

    ShaderProgram new_prg;
    vert_pt.compile_shader();
    frag_pt.compile_shader();
    spdlog::info(vert_pt.get_code());
    new_prg.bind_shaders(vert_pt, frag_pt);
    shader_mats->add(new_prg);
    new_prg.use();
}

void ShaderManager::add_new_material(SvarogMaterial m_material) {
    if(material_li.size() == 0) {
        material_li.emplace(m_material);
    } else {
        material_li.push(m_material);
    }
}

void ShaderManager::modify_material_color(const char* m_name, float values[4]) {
    while(!material_li.empty() && material_li.size() != 0) {
        auto m_material = material_li.top();
        if(m_material.get_material_name() == m_name) {
            m_material.set_color_values(values);
            break;
        } else {
            material_li.pop();
        }
    }
}

SvarogMaterial ShaderManager::get_material(const char* m_name) const {
    auto m_material = material_li.top();
    while(!material_li.empty() && material_li.size() != 0) {
        if(m_material.get_material_name() == m_name) {
            break;
        } else {
            continue;
        }
    }
    return m_material;
}
ShaderManager *ShaderManager::shader_manager = 0;