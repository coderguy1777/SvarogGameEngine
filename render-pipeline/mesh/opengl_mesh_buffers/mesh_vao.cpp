#include "mesh_vao.h"
unsigned int MeshVao::get_mesh_buffer() const {
    return buffer;
}

void MeshVao::gen_mesh_buffer() {
    glGenVertexArrays(1, &buffer);
}

void MeshVao::del_mesh_buffer() {
    glDeleteVertexArrays(1, &buffer);
}