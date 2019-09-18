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

void FragmentShader::set_code(const char* code) {
    s_code.shader_code = code;
}

const char* FragmentShader::get_code() const {
    return s_code.shader_code;
}

unsigned int FragmentShader::get_initstate() const {
    return flags.shader_type;
}

void FragmentShader::compile_shader() {
    shader_f = glCreateShader(GL_FRAGMENT_SHADER);
    bool code_check = (get_code() != "") ? true : false;
    if(code_check) {
        spdlog::info("ERROR, NO FRAG_SHADER CODE.");
        s_code.success_state = 0;
    } else if(!code_check) {
        const char* code = get_code();
        glShaderSource(shader_f, 1, &code, nullptr);
        glCompileShader(shader_f);
        s_code.success_state = 1;
        int success;
        char info[512];
        glGetShaderiv(shader_f, GL_COMPILE_STATUS, &success);
        if(success) {
            glGetShaderInfoLog(shader_f, 512, NULL, info);
            spdlog::info("Shader name: {}", (static_cast<SHADER_TYPE>(get_initstate()) == SHADER_TYPE::FRAG_SHADER) ? static_cast<const char*>("Vertex shader") : 
            static_cast<const char*>("ERROR: SHADER_TYPE_INVALID."));

        } else if(!success) {

        }
    }
}

unsigned int FragmentShader::get_shader_id() {
    return shader_f;
}

FragmentShader::~FragmentShader() {
    glDeleteShader(shader_f);
}