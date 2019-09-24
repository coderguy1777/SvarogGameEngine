#include "shader_gen.h"

ShaderGeneration::ShaderGeneration() {
    file_info = new Shader_File_Attributes();
}

ShaderGeneration::ShaderGeneration(std::string fname, unsigned int size_m, unsigned int shader_type, bool is_writable) {
    file_info = new Shader_File_Attributes();
    file_info->file_name = fname;
    file_info->MAX_SIZE = size_m;
    file_info->shader_type = shader_type;
    file_info->write_shader = is_writable;
}

std::string ShaderGeneration::get_file_n() const {
    return file_info->file_name;
}

unsigned int ShaderGeneration::get_size_max() const {
    return file_info->MAX_SIZE;
}

unsigned int ShaderGeneration::get_mat_type() const {
    return file_info->shader_type;
}

bool ShaderGeneration::get_write_state() const {
    return file_info->write_shader;
}