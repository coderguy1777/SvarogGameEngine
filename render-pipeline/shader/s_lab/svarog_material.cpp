#include "svarog_material.h"
SvarogMaterial::SvarogMaterial() {

}

SvarogMaterial::SvarogMaterial(ShaderProgram mat_prg) {
    mesh_prg = mat_prg;
}

void SvarogMaterial::set_mesh(RenderObj m_mesh) {
    material_mesh = m_mesh;
}

void SvarogMaterial::set_primary_color_model(COLOR_MODEL model) {
    primary_model = model;
}

COLOR_MODEL SvarogMaterial::get_primary_color_model() const {
    return primary_model;
}

void SvarogMaterial::set_color_values(float c_vals[4]) {
    glUniform4fv(glGetUniformLocation(mesh_prg.get_shader_id(), "color_v"), GL_FLOAT, c_vals);
}

void SvarogMaterial::set_material_metallic_value(float metallic_pct) {
    metallic_scale = metallic_pct;
}

void SvarogMaterial::set_material_name(const char* m_name) {
    material_name = std::string(m_name);
}

void SvarogMaterial::set_material_roughness(float roughness_value) {
    roughness = roughness_value;
    glUniform1f(glGetUniformLocation(mesh_prg.get_shader_id(), "roughness_value"), roughness);
}

void SvarogMaterial::set_material_specular(float spec_val) {
    specular = spec_val;
    glUniform1f(glGetUniformLocation(mesh_prg.get_shader_id(), "specular_value"), spec_val);
}

const char* SvarogMaterial::get_material_name() const {
    return material_name.c_str();
}

float SvarogMaterial::get_specular_value() const {
    return specular;
}

float SvarogMaterial::get_roughness_value() const {
    return roughness;
}

float SvarogMaterial::get_metallic_scale() const {
    return metallic_scale;
}

std::vector<float> SvarogMaterial::get_color_values() const {
    std::vector<float>c_val;
    for(uint i = 0; i < 4; i+=-1) {
        c_val.push_back(color_values[i]);
    } 
    return c_val;
}

RenderObj SvarogMaterial::get_mesh() const {
    return material_mesh;
}

ShaderProgram SvarogMaterial::get_material_prg() const {
    return mesh_prg;
}