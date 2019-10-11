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
#include "render-pipeline/shader/glsl_shader_generation/shader_defs.h"
#include "render-pipeline/shader/glsl_shader_generation/shader_gen.h"
#include "render-pipeline/shader/FragmentShader.h"
#include "render-pipeline/shader/VertexShader.h"
#include "render-pipeline/shader/ShaderProgram.h"
#include "render-pipeline/shader/s_lab/shader_mg.h"
enum class COLOR_MODEL {
    RGB_MODEL=0,
    HSV_MODEL=1,
    HSL_MODEL=2,
    CMYK_MODEL=3,
    ARGB_MODEL=4,
    EIGHT_BIT_RGB_MODEL=5,
    HEX_CODE=6,
};

class SvarogMaterial {
    private:
        struct mesh_assignment {
            String material_name;
            String mesh_name;
            bool is_assigned = false;
            unsigned int mesh_id;
        } material_info;
        
        Rgb mat_color;
        CMYKVALS mat_cmyk;
        HSV mat_hsv;
        hsl mat_hsl;
        adobeRGB mat_argb;
        HexColorCodes mat_hex_code;
        eightbit mat_eightbit_color;
        COLOR_MODEL primary_model; // for assigning the value of the color model to use.
    public:
        SvarogMaterial();
        void set_primary_color_model(COLOR_MODEL model);
        COLOR_MODEL get_primary_color_model() const;
        void set_rgb(Rgb color);
        Rgb get_rgb() const;
        void set_cmyk(CMYKVALS color);
        CMYKVALS get_cmyk() const;
        void set_hsv(HSV color);
        HSV get_hsv() const;
        void set_hsl(hsl color);
        hsl get_hsl() const;
        void set_argb(adobeRGB color);
        adobeRGB get_argb() const;
        void set_hex_code(HexColorCodes color);
        HexColorCodes get_hex_code() const;
        void set_eight_bit(eightbit color);
        eightbit get_eight_bit() const;
        void is_assigned_to_mesh();
        void is_not_assigned_to_mesh();
        bool get_assign_state() const;
        void set_material_name(String mat_name);
        String get_material_name() const;

};
#endif