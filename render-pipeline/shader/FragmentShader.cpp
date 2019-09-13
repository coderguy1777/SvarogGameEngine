#include "FragmentShader.h"
void FragmentShader::set_use_state() {
    flags.is_used = true;
}

bool FragmentShader::get_use_state() const {
    return flags.is_used;
}

void FragmentShader::init_state(unsigned int state) {
    switch(state) {
        case static_cast<unsigned int>(SHADER_TYPE::FRAG_SHADER):
            flags.shader_type = static_cast<unsigned int>(SHADER_TYPE::FRAG_SHADER);
            break;
        case static_cast<unsigned int>(SHADER_TYPE::VERT_SHADER):
            flags.shader_type = static_cast<unsigned int>(SHADER_TYPE::VERT_SHADER);
            break;
        default:
            flags.shader_type = 0;
            break;
    }
}

unsigned int FragmentShader::get_initstate() const {
    return flags.shader_type;
}

unsigned int FragmentShader::compile_shader() {
    return 1;
}