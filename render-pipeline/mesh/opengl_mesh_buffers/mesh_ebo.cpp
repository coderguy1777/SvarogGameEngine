#include "mesh_ebo.h"
unsigned int MeshEBO::get_mesh_buffer() const {
    return buffer;
}

void MeshEBO::gen_mesh_buffer() {
    glGenBuffers(1, &buffer);
}

void MeshEBO::del_mesh_buffer() {
    glDeleteBuffers(1, &buffer);
}