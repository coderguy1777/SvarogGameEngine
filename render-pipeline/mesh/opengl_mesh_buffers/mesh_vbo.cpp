#include "mesh_vbo.h"
unsigned int MeshVBO::get_mesh_buffer() const {
    return buffer;
}

void MeshVBO::gen_mesh_buffer() {
    glGenBuffers(1, &buffer);
}

void MeshVBO::del_mesh_buffer() {
    glDeleteBuffers(1, &buffer);
}