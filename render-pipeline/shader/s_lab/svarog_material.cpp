#include "svarog_material.h"
Rgb SvarogMaterial::get_color() const {
    return color_test;
}

VertexShader SvarogMaterial::get_vert()  {
    return shader_prg.vert_shader;
}

FragmentShader SvarogMaterial::get_frag()  {
    return shader_prg.frag_shader;
}

void SvarogMaterial::write_shader(const char* a, const char* b) {
    /* 
    */ 
    shader_prg.vert_shader.set_code(a);
    shader_prg.frag_shader.set_code(b);
    shader_prg.vert_shader.compile_shader();
    shader_prg.frag_shader.compile_shader();
    mat_prg.bind_shaders(get_vert(), get_frag());
}

void SvarogMaterial::run() {
    mat_prg.use();
}