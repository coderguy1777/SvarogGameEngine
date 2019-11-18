#pragma once
#ifndef SVAROG_RENDEROBJ_H
#define SVAROG_RENDEROBJ_H
#include "svarog_shape.h"
#include "core/String.h"
#define BYTE_SHIFT(X) 1 << X

class RenderObj {
    private: 
        struct RenderObject_Flags {
            bool is_visible;  // for if the mesh is rendered.
            bool is_moveable; // for if the mesh can be moved by the user or not.
            bool has_material; // check if has material or not.
            size_t mesh_size; // size of mesh in bytes;
            unsigned int render_pri;
        } object_flags;

        SvarogShape render_obj;
        unsigned int id_val;
        String obj_name;
    public:
        RenderObj();
        void set_mesh_id(unsigned int id);
        void set_mesh_name(String name);
        void input_mesh(SvarogShape input_mesh);
        void set_render_flags(uint render_pri, size_t mesh_size, bool move_state, bool has_mat, bool is_vis);
        void draw_input_mesh();
        unsigned int get_id() const;
        String get_mesh_name() const;
        SvarogShape get_mesh() const;
        bool get_move_state() const;
        bool get_vis_state() const;
        bool get_has_material() const;
        unsigned int get_render_pri() const;
        size_t get_mesh_size() const;
};

#endif