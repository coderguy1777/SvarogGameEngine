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
    protected: 
        void write_material_code();
    private:
        Rgb color_test;
        MatShader shader_prg;
        ShaderProgram mat_prg;

    public: 
        /* 
            TODO: change methods up for given value, set by method, and then changed by glUniform*
            to add modified value, and modify it for the material, in real time. do this
            for all mesh class values, and materials.
        */ 
        SvarogMaterial() {
    
        }
        VertexShader get_vert() const;
        FragmentShader get_frag() const;
        void write_shader();
        void run();
        Rgb get_color() const;
};


#endif