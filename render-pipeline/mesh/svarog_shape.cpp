#include "svarog_shape.h"
SvarogShape::SvarogShape() {
    data = new shape_data();
}

void SvarogShape::init_ebo(unsigned int state) {
    bool wanted_state = (state==1) ? true : false;
    data->use_ebo = wanted_state;
}

bool SvarogShape::get_ebo() const {
    return data->use_ebo;
}

void SvarogShape::make_VAO() {
    glGenVertexArrays(1, &data->VAO);
}

void SvarogShape::make_VBO() {
    glGenBuffers(1, &data->VBO);
}

void SvarogShape::make_EBO() {
    glGenBuffers(1, &data->EBO);
}

unsigned int SvarogShape::get_VAO() const {
    return data->VAO;
}

unsigned int SvarogShape::get_VBO() const {
    return data->VBO;
}

unsigned int SvarogShape::get_EBO() const {
    return data->EBO;
}

ArrayList<float> SvarogShape::get_shape_verts() const {
    return data->vertex_data;
}

ArrayList<unsigned int> SvarogShape::get_shape_posdata() const {
    return data->position_data;
}

void SvarogShape::pass_vert_data(float vert) {
    for(unsigned int i = 0; i < data->vertex_data.size(); i++) {
        data->vertex_data.add(vert);
    }
}

void SvarogShape::pass_position_data(unsigned int pos) {
    for(unsigned int j = 0; j < data->position_data.size(); j++) {
        data->position_data.add(pos);
    }
}