#include "shader_gen.h"
ShaderGeneration::ShaderGeneration() {

}

VertexShader ShaderGeneration::get_mat_vert() const {
    mat_shader_prg.get_vert_shader();
}

FragmentShader ShaderGeneration::get_mat_frag() const {
    mat_shader_prg.get_frag_shader();
}

void ShaderGeneration::add_to_manager() {
    
}