#include "svarog_material.h"
Rgb SvarogMaterial::get_color() const {
    return color_test;
}

void SvarogMaterial::add_code() {
    vert_code.add(GLSL_V);
    vert_code.add("layout (location=0) vec3 aPos");
    vert_code.add("void main()");
    vert_code.add("{");
    vert_code.add("gl_Position=vec4(aPos, 1.0);");
    vert_code.add("}");
    frag_code.add(GLSL_V);
    frag_code.add("out vec4 frag_color;");
    frag_code.add("uniform vec4 float_tst;");
    frag_code.add("uniform float time;");
    frag_code.add("uniform float r, g, b;");
    frag_code.add("uniform float time2;");
    frag_code.add("void main()");
    frag_code.add("{");
    frag_code.add(" frag_color=vec4(1.0, 0.5, 1.0, 1.0);");
    frag_code.add("}");
}

void SvarogMaterial::write_shader() {
    const char* a[vert_code.size()];
    const char* b[frag_code.size()];
    for(unsigned int i = 0; i < vert_code.size(); i++) {
        a[i] = vert_code.get(i) + '\n';
    }

    for(unsigned int j = 0; j < frag_code.size(); j++) {
       b[j] = frag_code.get(j) + '\n'; 

    }
        const char* shader_tst_1 = "#version 400\n"
        "layout (location = 0) in vec3 aPos;\n"
        "void main()\n"
        "{\n"
        "   gl_Position=vec4(aPos, 1.0);\n"
        "}\n\0";
    
    const char* shader_tst_2 ="#version 400\n"
        "out vec4 frag_color;\n"
        "uniform vec4 float_tst;\n"
        "uniform float time;\n"
        "uniform float r, g, b;\n"
        "float time_2;\n"
        "void main()\n"
        "{\n"
        "   frag_color = vec4(r, g, b, 1.0);\n"
        "}\n\0";
    shader_prg.vert_shader.set_code(shader_tst_1);
    shader_prg.frag_shader.set_code(shader_tst_2);
    glGetError();
    shader_prg.mat_prg.bind_shaders(shader_prg.vert_shader, shader_prg.frag_shader);
    run();
}

void SvarogMaterial::run() {
    shader_prg.mat_prg.use();
}