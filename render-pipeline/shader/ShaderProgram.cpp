#include "ShaderProgram.h"
void ShaderProgram::set_state(int link_state) {
    sh_prg->link_success = (link_state==1) ? true : false;
}

bool ShaderProgram::get_link_status() const {
    return sh_prg->link_success;
}

void ShaderProgram::bind_shaders(VertexShader vert, FragmentShader frag) {
    sh_prg->material_group.vert_sh_1 = vert;
    sh_prg->material_group.frag_sh_2 = frag;
    sh_prg->shader_id = glCreateProgram();
    glAttachShader(sh_prg->shader_id, sh_prg->material_group.vert_sh_1.get_shader_id());
    glAttachShader(sh_prg->shader_id, sh_prg->material_group.frag_sh_2.get_shader_id());
    glLinkProgram(sh_prg->shader_id);
    glUseProgram(sh_prg->shader_id);
            spdlog::info("Shader program success....");
        set_state(1);
        spdlog::info("Continuing shader compiling...");
}

unsigned int ShaderProgram::get_shader_id() const {
    bool is_compiled = (get_link_status() == true) ? true : false;
    return (is_compiled) ? sh_prg->shader_id : 0;
}

void ShaderProgram::use() {
    glUseProgram(sh_prg->shader_id);
}
