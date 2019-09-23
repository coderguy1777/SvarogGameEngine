#pragma once 
#ifndef SVAROG_SHAPE_H
#define SVAROG_SHAPE_H
#include "core/ds-classes/Array.h"
#include "core/ds-classes/ArrayList.h"
#include "render-pipeline/gl_libs.h"
struct shape_data {
    ArrayList<float>vertex_data;
    ArrayList<unsigned int>position_data;
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

        void pass_vert_data(float vert);
        void pass_position_data(unsigned int pos);

        ArrayList<float>get_shape_verts() const;
        ArrayList<unsigned int>get_shape_posdata() const;

};


#endif