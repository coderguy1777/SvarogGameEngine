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

void VertexShader::set_code(const char* code) {
    s_code.shader_code = code;
}

const char* VertexShader::get_code() const {
    return s_code.shader_code;
}

unsigned int VertexShader::get_initstate() const {
    return flags.shader_type;
}

void VertexShader::compile_shader() {
    shader_v = glCreateShader(GL_VERTEX_SHADER);
    bool code_check = (get_code() != "") ? true : false;
    if(code_check) {
        spdlog::info("ERROR, NO SHADER CODE SPECIFIED.");
        exit(0);
        s_code.success_state = 0;
    } else if(!code_check) {
        const char* code = get_code();
        glShaderSource(shader_v, 1, &code, nullptr);
        glCompileShader(shader_v);
        s_code.success_state = 1;
    }
}