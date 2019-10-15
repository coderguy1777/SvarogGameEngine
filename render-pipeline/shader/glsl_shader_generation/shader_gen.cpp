#include "shader_gen.h"
VertexShader ShaderGeneration::get_mat_vert() const {
    return mat_shader_prg.material_vert_shader;
}

FragmentShader ShaderGeneration::get_mat_frag() const {
    return mat_shader_prg.material_frag_shader;
}

const char* ShaderGeneration::get_vertex_code() const {
    return mat_shader_code.vertex_code;
}

const char* ShaderGeneration::get_fragment_code() const {
    return mat_shader_code.fragment_code;
}

ShaderGeneration* ShaderGeneration::generateShaderCode() {
    if(!shader_gen_instance) {
        shader_gen_instance = new ShaderGeneration;
    }
    return shader_gen_instance;
}

void ShaderGeneration::input_mat(SvarogMaterial to_compile) {
    generation_queue->add(to_compile);
}

void ShaderGeneration::make_shaders() {
    SvarogMaterial curr_shader = generation_queue->get(0);
    if(curr_shader.get_primary_color_model() == COLOR_MODEL::RGB_MODEL) {

    } else if(curr_shader.get_primary_color_model() == COLOR_MODEL::HSV_MODEL) {

    }
}

void ShaderGeneration::send_shaders() {
    std::string code_a, code_b;
    vertex_shader_code.add("#version 400\n");
    vertex_shader_code.add("#IFDEF\n");
    fragment_shader_code.add("#version 400\n");
    for(unsigned int i = 0; i < vertex_shader_code.size(); i++) { 
        code_a += vertex_shader_code.get(i);
    }
    mat_shader_code.vertex_code = code_a.c_str();
    
    for(unsigned int j = 0; j < fragment_shader_code.size(); j++) {
        code_b += fragment_shader_code.get(j);
    }
    mat_shader_code.fragment_code = code_b.c_str();
    SVAROG_CLASS_DEBUG("SvarogMaterial", code_a.c_str());

    mat_shader_prg.material_vert_shader.set_code(mat_shader_code.vertex_code);
    mat_shader_prg.material_frag_shader.set_code(mat_shader_code.fragment_code);
    ShaderManager::getShaderManager()->pass_code(mat_shader_prg.material_vert_shader, mat_shader_prg.material_frag_shader);
}
ShaderGeneration* ShaderGeneration::shader_gen_instance = 0;