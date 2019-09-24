#pragma once
#ifndef SHADER_GEN_H
#define SHADER_GEN_H
#include "shader_defs.h"
#include <ostream>
#include <fstream>
#include "core/ds-classes/ArrayList.h"
#define SHADER_DIR "/home/jordan/Documents/SvarogGameEngine/builds/shaders/"
struct Shader_File_Attributes {
    std::string file_name;
    unsigned int MAX_SIZE;
    unsigned int shader_type;
    bool write_shader;
};

class ShaderGeneration {
    private:
        Shader_File_Attributes* file_info;
        int success;
    public:
        ShaderGeneration(std::string f_name, unsigned int size_m, unsigned int shader_type, bool is_writable);
        ShaderGeneration();
        std::string get_file_n() const;
        unsigned int get_size_max() const;
        unsigned int get_mat_type() const;
        int get_success() const;
        bool get_write_state() const;    
        void write_file(ArrayList<const char*>file_tst);    
};

#endif