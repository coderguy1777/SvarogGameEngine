#include "svarog_renderobj.h"
RenderObj::RenderObj() {}

void RenderObj::draw_input_mesh() {
    get_mesh().draw();
}

void RenderObj::set_mesh_id(unsigned int id) {
    id_val = id;
}

void RenderObj::set_mesh_name(String name) {
    obj_name = name;
}

void RenderObj::input_mesh(SvarogShape shape) {
    if(!shape.get_init_state()) {
        render_obj = shape;
    } else {
        render_obj = shape;
    }
    
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

void RenderObj::set_render_flags(uint render_pri, size_t m_size, bool move_state, bool mat_state, bool vis_state) {
    object_flags.render_pri = render_pri;
    object_flags.mesh_size = m_size;
    object_flags.is_moveable = move_state;
    object_flags.is_visible = vis_state;
    object_flags.has_material = mat_state;
}

bool RenderObj::get_move_state() const {
    return object_flags.is_moveable;
}

bool RenderObj::get_has_material() const {
    return object_flags.has_material;
}

bool RenderObj::get_vis_state() const {
    return object_flags.is_visible;
}

unsigned int RenderObj::get_render_pri() const {
    return object_flags.render_pri;
}

size_t RenderObj::get_mesh_size() const {
    return object_flags.mesh_size;
}