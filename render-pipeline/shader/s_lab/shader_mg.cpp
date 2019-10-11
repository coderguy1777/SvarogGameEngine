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

void ShaderManager::render_tst() {
    shader_mats->get(0).use();
}

bool ShaderManager::works() {
    if(shader_mats->get(0).get_link_status()) {
        spdlog::warn("COMPILED");
    } 
    return (shader_mats->get(0).get_link_status());
}
ShaderManager *ShaderManager::shader_manager = 0;