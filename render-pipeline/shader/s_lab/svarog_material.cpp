#include "svarog_material.h"
SvarogMaterial::SvarogMaterial() {
    material_program = new ShaderProgram();
    material_program->bind_shaders(mat_vert_shader, mat_frag_shader);
}

void SvarogMaterial::set_primary_color_model(COLOR_MODEL model) {
    primary_model = model;
}

COLOR_MODEL SvarogMaterial::get_primary_color_model() const {
    return primary_model;
}

void SvarogMaterial::set_color_values(float c_vals[4]) {

}

void SvarogMaterial::set_material_metallic_value(float metallic_pct) {

}

void SvarogMaterial::set_material_name(char* name) {

}

void SvarogMaterial::set_material_roughness(float roughness_value) {

}

void SvarogMaterial::set_material_specular(float spec_val) {

}