#pragma once 
#ifndef SVAROG_SHAPE_H
#define SVAROG_SHAPE_H
#include<vector>
#include "core/ds-classes/Array.h"
#include "core/ds-classes/ArrayList.h"
#include "render-pipeline/gl_libs.h"
struct shape_data {
    std::vector<float>vert_data;
    std::vector<unsigned int>pos_data;
    GLuint VAO, VBO, EBO;
    bool use_ebo;
};


class SvarogShape {
    private: 
        shape_data* data;

    public: 
        SvarogShape();
        void init_ebo(unsigned int state);
        bool get_ebo() const;
        void make_VAO();
        void make_VBO();
        void make_EBO();
        unsigned int get_VAO() const;
        unsigned int get_VBO() const;
        unsigned int get_EBO() const;
        void bind_VAO();
        void bind_VBO();
        void bind_EBO();
        void buffer_data_gen();
        void ebo_buffer_gen();
        void end_binds();
        void draw();

        void pass_vert_data(std::vector<float>vert_data);
        void pass_position_data(std::vector<unsigned int>pos_data);
        std::vector<float>get_shape_verts() const;
        std::vector<unsigned int>get_shape_posdata() const;

};


#endif