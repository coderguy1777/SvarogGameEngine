#include "VertexShader.h"
void VertexShader::set_use_state() {
    flags.is_used = true;
}

bool VertexShader::get_use_state() const {
    return flags.is_used;
}

void VertexShader::init_state(unsigned int state) {
    switch(state) {
        case static_cast<unsigned int>(SHADER_TYPE::FRAG_SHADER):
            flags.shader_type = static_cast<unsigned int>(SHADER_TYPE::FRAG_SHADER);
            break;
        case static_cast<unsigned int>(SHADER_TYPE::VERT_SHADER):
            flags.shader_type = static_cast<unsigned int>(SHADER_TYPE::VERT_SHADER);
            break;
        default:
            flags.shader_type = -1;
            break;
    }
}

unsigned int VertexShader::get_initstate() const {
    return flags.shader_type;
}

unsigned int VertexShader::compile_shader() {
    return 1;
}