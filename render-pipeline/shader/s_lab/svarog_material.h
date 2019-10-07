#pragma once
#ifndef SVAROG_MATERIAL_H
#define SVAROG_MATERIAL_H
#include<cmath>
#include "spdlog/spdlog.h"
#include "gl_libs.h"
#include "render-pipeline/shader/glsl_shader_generation/shader_defs.h"
#include "render-pipeline/shader/glsl_shader_generation/shader_gen.h"
#include "main/color/Color.h"
#include "main/color/HSV.h"
#include "main/color/htmlcolors.h"
#include "main/color/hsl.h"
#include "main/color/htmlcolors.h"
#include "main/color/cmyk.h"
#include "render-pipeline/shader/FragmentShader.h"
#include "render-pipeline/shader/VertexShader.h"
#include "render-pipeline/shader/ShaderProgram.h"

struct MatShader {
    VertexShader vert_shader;
    FragmentShader frag_shader;
};

class SvarogMaterial {
    private:
        Rgb color_test;
        MatShader shader_prg;
        float tst;
        ShaderProgram mat_prg;

    public: 
        /* 
            TODO: change methods up for given value, set by method, and then changed by glUniform*
            to add modified value, and modify it for the material, in real time. do this
            for all mesh class values, and materials.
        */ 
        SvarogMaterial(Rgb c) {
            color_test.redval = c.redval;
            color_test.greenval = c.greenval;
            color_test.blueval = c.blueval;
            shader_prg.vert_shader.init_state(2);
            shader_prg.vert_shader.set_use_state();
            shader_prg.frag_shader.init_state(1);
            shader_prg.frag_shader.set_use_state();
        }
        void add_code();
        VertexShader get_vert() const;
        FragmentShader get_frag() const;
        void write_shader();
        void run();
        Rgb get_color() const;
        float diffuse_tst();
        void set_float(float r);
};


#endif