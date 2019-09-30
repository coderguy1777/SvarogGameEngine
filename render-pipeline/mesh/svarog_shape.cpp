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
    data->vao.gen_mesh_buffer();
}

void SvarogShape::make_VBO() {
    data->vbo.gen_mesh_buffer();
}

void SvarogShape::make_EBO() {
    data->ebo.gen_mesh_buffer();
}

unsigned int SvarogShape::get_VAO() const {
    return data->vao.get_mesh_buffer();
}

unsigned int SvarogShape::get_VBO() const {
    return data->vbo.get_mesh_buffer();
}

unsigned int SvarogShape::get_EBO() const {
    return data->ebo.get_mesh_buffer();
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

void SvarogShape::attribs() {
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    /* 
        quick note: the use of glEnableVertexAttribArray(1); gives access 
        to the fragment shader.
    */ 
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3* sizeof(float)));
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void SvarogShape::init() {
    make_VAO();
    make_VBO();
    make_EBO();
    bind_VAO();
    bind_VBO();
    buffer_data_gen();
    bind_EBO();
    ebo_buffer_gen();
    attribs();
}

void SvarogShape::draw() {
    glBindVertexArray(get_VAO());
    glDrawElements(GL_TRIANGLES, data->pos_data.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

void SvarogShape::del_buffers() {
    data->vao.del_mesh_buffer();
    data->vbo.del_mesh_buffer();
    data->ebo.del_mesh_buffer();
}