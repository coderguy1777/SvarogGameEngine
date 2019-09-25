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

void ShaderGeneration::write_file() {
    ofstream file_stream(SHADER_DIR + get_file_n());
    if(!file_stream) {
        throw std::invalid_argument("SHADER_GEN_ERROR");
        exit(0);
    }

    bool write_shader = (get_write_state() == true) ? true : false;
    if(write_shader) {
        spdlog::info("Writing shader");
        for(unsigned int i = 0; i < shader_output->size(); i++) {
            file_stream << shader_output->get(i) << '\n';
        }
        success = 1;
        spdlog::info("Shader written...");
        file_stream.close();
    } else if(!write_shader) {
        spdlog::error("WRITE ATTEMPT WHEN F, ENDING WRITE.");
        success = 0;
        file_stream.close();
    }
}

void ShaderGeneration::add_to_output(const char* shader_line) {
    shader_output->add(shader_line);
}

int ShaderGeneration::get_success() const {
    return success;
}