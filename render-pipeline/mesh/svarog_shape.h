#pragma once 
#ifndef SVAROG_SHAPE_H
#define SVAROG_SHAPE_H
#include<vector>
#include "core/ds-classes/Array.h"
#include "core/ds-classes/ArrayList.h"
#include "render-pipeline/gl_libs.h"
#include "opengl_mesh_buffers/mesh_vao.h"
#include "opengl_mesh_buffers/mesh_vbo.h"
#include "opengl_mesh_buffers/mesh_ebo.h"
#include "spdlog/spdlog.h"
struct shape_data {
    std::vector<float>vert_data;
    std::vector<unsigned int>pos_data;
    MeshVao vao;
    MeshVBO vbo;
    MeshEBO ebo;
    bool use_ebo;
};

class SvarogShape {
    private: 
        shape_data* data;
        bool is_init;

    public: 
        SvarogShape();
        void bind_VAO();
        void bind_VBO();
        void bind_EBO();
        void buffer_data_gen();
        void ebo_buffer_gen();
        void attribs();
        void make_VAO();
        void make_VBO();
        void make_EBO();
        void init_ebo(unsigned int state);
        bool get_ebo() const;

        unsigned int get_VAO() const;
        unsigned int get_VBO() const;
        unsigned int get_EBO() const;
        void init();
        void del_buffers();
        void draw();
        void pass_vert_data(std::vector<float>vert_data);
        void pass_position_data(std::vector<unsigned int>pos_data);
        std::vector<float>get_shape_verts() const;
        std::vector<unsigned int>get_shape_posdata() const;
        bool get_init_state() const;
};
#endif