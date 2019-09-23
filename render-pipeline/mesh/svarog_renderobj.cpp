#include "svarog_renderobj.h"
RenderObj::RenderObj() {

}

void RenderObj::set_mesh_id(unsigned int id) {
    id_val = id;
}

void RenderObj::set_mesh_name(String name) {
    obj_name = name;
}

void RenderObj::input_mesh(SvarogShape shape) {
    render_obj = shape;
}

SvarogShape RenderObj::get_mesh() const {
    return render_obj;
}

unsigned int RenderObj::get_id() const {
    return id_val;
}

String RenderObj::get_mesh_name() const {
    return obj_name;
}

std::unique_ptr<render_mesh>RenderObj::make_new_renderobj() {
    std::unique_ptr<render_mesh>new_mesh = std::make_unique<render_mesh>();
    new_mesh->mesh = get_mesh();
    new_mesh->mesh_id = get_id();
    new_mesh->mesh_name = get_mesh_name();
    return new_mesh;
}