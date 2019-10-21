#include "svarog_material.h"
SvarogMaterial::SvarogMaterial() {
    spdlog::info("Works");
}

void SvarogMaterial::set_primary_color_model(COLOR_MODEL model) {
    primary_model = model;
}

COLOR_MODEL SvarogMaterial::get_primary_color_model() const {
    return primary_model;
}

void SvarogMaterial::set_rgb(Rgb color) {
    mat_color = color;
}

Rgb SvarogMaterial::get_rgb() const {
    return mat_color;
}

void SvarogMaterial::set_cmyk(CMYKVALS color) {
    mat_cmyk = color;
}

CMYKVALS SvarogMaterial::get_cmyk() const {
    return mat_cmyk;
}

void SvarogMaterial::set_hsv(HSV color) {
    mat_hsv = color;
}

HSV SvarogMaterial::get_hsv() const {
    return mat_hsv;
}

void SvarogMaterial::set_hsl(hsl color) {
    mat_hsl = color;
}

hsl SvarogMaterial::get_hsl() const {
    return mat_hsl;
}

void SvarogMaterial::set_argb(adobeRGB color) {
    mat_argb = color;
}


adobeRGB SvarogMaterial::get_argb() const {
    return mat_argb;
}

void SvarogMaterial::set_hex_code(HexColorCodes color) {
    mat_hex_code = color;
}

void SvarogMaterial::set_eight_bit(eightbit color) {
    mat_eightbit_color = color;
}

eightbit SvarogMaterial::get_eight_bit() const {
    return mat_eightbit_color;
}

void SvarogMaterial::is_assigned_to_mesh() {
    material_info.is_assigned = true;
}

void SvarogMaterial::is_not_assigned_to_mesh() {
    material_info.is_assigned = false;
}

bool SvarogMaterial::get_assign_state() const {
    return (material_info.mat_shape != NULL);
}

void SvarogMaterial::set_material_name(String mat_name) {
    material_info.material_name = mat_name;
}

String SvarogMaterial::get_material_name() const {
    return material_info.material_name;
}