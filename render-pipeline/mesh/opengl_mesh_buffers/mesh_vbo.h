#pragma once
#ifndef MESH_VBO_H
#define MESH_VBO_H
#include "render-pipeline/gl_libs.h"
#include "mesh_buffer.h"

class MeshVBO : public MeshBuffer {
    public: 
        virtual unsigned int get_mesh_buffer() const override;
        virtual void gen_mesh_buffer() override;
        virtual void del_mesh_buffer() override;
};


#endif