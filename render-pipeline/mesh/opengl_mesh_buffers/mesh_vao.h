#pragma once 
#ifndef MESH_VAO_H
#define MESH_VAO_H
#include "mesh_buffer.h"
#include "render-pipeline/gl_libs.h"

class MeshVao : public MeshBuffer {
    public: 
        virtual unsigned int get_mesh_buffer() const override;
        virtual void gen_mesh_buffer() override;
        virtual void del_mesh_buffer() override;
};

#endif