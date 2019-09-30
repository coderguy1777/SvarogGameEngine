#pragma once
#ifndef MESH_EBO_H
#define MESH_EBO_H
#include "gl_libs.h"
#include "mesh_buffer.h"

class MeshEBO : public MeshBuffer {
    public: 
        virtual unsigned int get_mesh_buffer() const override;
        virtual void gen_mesh_buffer() override;
        virtual void del_mesh_buffer() override;
};
#endif