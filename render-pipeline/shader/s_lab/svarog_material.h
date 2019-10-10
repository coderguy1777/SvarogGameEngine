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
#include "render-pipeline/shader/s_lab/shader_mg.h"

struct ShaderParts {
    VertexShader vert_shader;
    FragmentShader frag_shader;
};

enum class COLOR_MODEL {
    RGB_MODEL=0,
    HSV_MODEL=1,
    HSL_MODEL=2,
    CMYK_MODEL=3,
    ARGB_MODEL=4,
    EIGHT_BIT_RGB_MODEL=5
};

class SvarogMaterial {
    private:

    public:
};


#endif