#pragma once
#ifndef MESH_BUFFER_H
#define MESH_BUFFER_H

class MeshBuffer {
    public: 
        unsigned int buffer;
        virtual unsigned int get_mesh_buffer() const = 0;
        virtual void gen_mesh_buffer() = 0;
        virtual void del_mesh_buffer() = 0;
};

#endif