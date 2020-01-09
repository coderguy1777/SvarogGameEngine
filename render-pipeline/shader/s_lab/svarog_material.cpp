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
    for(uint i = 0; i < 4; i++) {
        color_values[i] = c_vals[i];
    }
    glUniform1f(glGetUniformLocation(material_program->get_shader_id(), "mesh_color.x"), color_values[0]);
    glUniform1f(glGetUniformLocation(material_program->get_shader_id(), "mesh_color.y"), color_values[1]);
}

void SvarogMaterial::set_material_metallic_value(float metallic_pct) {
    metallic_scale = metallic_pct;
}

void SvarogMaterial::set_material_name(const char* m_name) {
    material_name = std::string(m_name);
}

void SvarogMaterial::set_material_roughness(float roughness_value) {
    roughness = roughness_value;
}

void SvarogMaterial::set_material_specular(float spec_val) {
    specular = spec_val;
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

SvarogShape SvarogMaterial::get_mesh() const {
    
}