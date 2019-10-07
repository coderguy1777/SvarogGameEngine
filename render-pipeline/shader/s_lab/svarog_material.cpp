#include "svarog_material.h"
Rgb SvarogMaterial::get_color() const {
    return color_test;
}

VertexShader SvarogMaterial::get_vert() const {
    return shader_prg.vert_shader;
}

FragmentShader SvarogMaterial::get_frag() const {
    return shader_prg.frag_shader;
}

float SvarogMaterial::diffuse_tst() {
    return tst;
}

void SvarogMaterial::write_shader() {
    const char* shader_tst_1 = "#version 400\n"
        "layout (location = 0) in vec3 aPos;\n"
        "void main()\n"
        "{\n"
        "   gl_Position=vec4(aPos, 1.0);\n"
        "}\n\0";
    
    const char* shader_tst_2 ="#version 400\n"
        "out vec4 frag_color;\n"
        "uniform float r;\n"
        "void main()\n"
        "{\n"
        "   frag_color = vec4(r, 0.5, 1.0, 1.0);\n"
        "}\n\0";
    shader_prg.vert_shader.set_code(shader_tst_1);
    shader_prg.frag_shader.set_code(shader_tst_2);
    shader_prg.vert_shader.compile_shader();
    shader_prg.frag_shader.compile_shader();
    glGetError();
    mat_prg.bind_shaders(get_vert(), get_frag());
}

void SvarogMaterial::set_float(float  r) {
    tst =  r;
}
void SvarogMaterial::run() {
    mat_prg.use();
    glUniform1f(glGetAttribLocation(mat_prg.get_shader_id(), "r"), diffuse_tst());

}