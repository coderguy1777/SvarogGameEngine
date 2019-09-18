#include "ShaderProgram.h"

void ShaderProgram::set_state(int link_state) {
    sh_prg->link_success = (link_state==1) ? true : false;
}

bool ShaderProgram::get_link_status() const {
    return sh_prg->link_success;
}

void ShaderProgram::bind_shaders() {
    sh_prg->shader_id = glCreateProgram();
    //glAttachShader(sh_prg->shader_id, sh_prg->material_group.vert_sh_1);
    //glAttachShader(sh_prg->shader_id, sh_prg->material_group.frag_sh_2);
}

