#pragma once
#ifndef SVAROG_MATERIAL_H
#define SVAROG_MATERIAL_H
#include<cmath>
#include "spdlog/spdlog.h"
#include "gl_libs.h"
#include "main/color/Color.h"
#include "main/color/HSV.h"
#include "main/color/htmlcolors.h"
#include "main/color/hsl.h"
#include "main/color/htmlcolors.h"
#include "main/color/cmyk.h"
#include "render-pipeline/mesh/svarog_renderobj.h"
#include "render-pipeline/shader/glsl_shader_generation/shader_defs.h"
#include "render-pipeline/shader/glsl_shader_generation/shader_gen.h"
#include "render-pipeline/shader/FragmentShader.h"
#include "render-pipeline/shader/VertexShader.h"
#include "render-pipeline/shader/ShaderProgram.h"
#include "render-pipeline/shader/s_lab/shader_mg.h"
enum class COLOR_MODEL {
    RGB_MODEL,
    HSV_MODEL,
    HSL_MODEL,
    CMYK_MODEL,
    ARGB_MODEL,
    EIGHT_BIT_RGB_MODEL,
    HEX_CODE,
};

/*
    TODO: 
        rewrite svarog material class to have more parameters and leave selection tasks to be done in the shader editor itself.
        this will allow for more dynamic editing of materials when it comes to a given mesh in this case.
*/ 
class SvarogMaterial {
    private:
        std::string material_name;
        bool is_assigned_to_mesh;
        float color_values[4];
        float specular;
        float roughness;
        float metallic_scale; // for determining how metallic the mesh will look in game.
        VertexShader mat_vert_shader;
        FragmentShader mat_frag_shader;
        ShaderProgram* material_program;
        COLOR_MODEL primary_model;

    public:
        SvarogMaterial();
        COLOR_MODEL get_primary_color_model() const;
        void set_material_specular(float spec_val);
        void set_material_roughness(float rough_pct);
        void set_material_metallic_value(float metallic_pct);
        void set_color_values(float c_vals[4]);
        void set_material_name(char* mat_name);
        void set_mesh(SvarogShape mesh_val);
        void set_primary_color_model(COLOR_MODEL model);
};
#endif