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

std::vector<float>SvarogShape::get_shape_verts() const {
    return data->vert_data;
}

std::vector<unsigned int>SvarogShape::get_shape_posdata() const {
    return data->pos_data;
}

void SvarogShape::pass_vert_data(std::vector<float>data_1) {
    for(unsigned int i =0; i < data_1.size(); i++) {
        data->vert_data.push_back(data_1[i]);
    }
    spdlog::info(data->vert_data.size());
}

void SvarogShape::pass_position_data(std::vector<unsigned int>pos_1) {
    for(unsigned int j =0; j < pos_1.size(); j++) {
        data->pos_data.push_back(pos_1[j]);
    }
}

void SvarogShape::bind_VAO() {
    glBindVertexArray(get_VAO());
}

void SvarogShape::bind_VBO() {
    glBindBuffer(GL_ARRAY_BUFFER, get_VBO());
}

void SvarogShape::bind_EBO() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, get_EBO());
}

void SvarogShape::buffer_data_gen() {
    glBufferData(GL_ARRAY_BUFFER, data->vert_data.size() * sizeof(float), &data->vert_data.front(), GL_STATIC_DRAW);
}

void SvarogShape::ebo_buffer_gen() {
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, data->pos_data.size() * sizeof(unsigned int), &data->pos_data.front(), GL_STATIC_DRAW);
}

void SvarogShape::end_binds() {
    make_VAO();
    make_VBO();
    make_EBO();
    bind_VAO();
    glBindBuffer(GL_ARRAY_BUFFER, data->VBO);
    glBufferData(GL_ARRAY_BUFFER, data->vert_data.size() * sizeof(float), &data->vert_data.front(), GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, data->EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, data->pos_data.size() * sizeof(unsigned int),&data->pos_data.front(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    spdlog::info("VAO OBJ: {}", get_VAO());
    spdlog::info("EBO OBJ: {}", get_EBO());
}

void SvarogShape::draw() {
    glBindVertexArray(get_VAO());
    glDrawElements(GL_TRIANGLES, data->pos_data.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}