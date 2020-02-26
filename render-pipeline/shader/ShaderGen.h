#include<ostream>
#include<fstream>
#include<iostream>
#include<sstream>
#include<string>
#include "ShaderProgram.h"

namespace PremadeShaders {
    static ShaderProgram shaderOne() {
        std::ifstream vert, frag;
        std::string vert_shader, frag_shader;
        vert.exceptions(std::ifstream::failbit);
        frag.exceptions(std::ifstream::failbit);

        try {
            vert.open("/home/jordan/Documents/SvarogGameEngine/render-pipeline/shader/engine_shader/mainvertex_shader.glsl");
            frag.open("/home/jordan/Documents/SvarogGameEngine/render-pipeline/shader/engine_shader/mainfragment_shader.glsl");
            std::stringstream m_vert, m_frag;
            m_vert << vert.rdbuf();
            m_frag << frag.rdbuf();
            vert.close();
            frag.close();
            vert_shader = m_vert.str();
            frag_shader = m_frag.str();
        } catch (ifstream::failure e) {
            std::cout << e.what() << '\n';
        }


        const char* vert_s = vert_shader.c_str();
        const char* frag_s = frag_shader.c_str();
        VertexShader vert_m;
        vert_m.set_code(vert_s);
        vert_m.set_use_state();
        vert_m.compile_shader();
        FragmentShader frag_m; 
        frag_m.set_code(frag_s);
        frag_m.set_use_state();
        frag_m.compile_shader();
        ShaderProgram test_prg;
        test_prg.bind_shaders(vert_m, frag_m);
        return test_prg;
    }
}