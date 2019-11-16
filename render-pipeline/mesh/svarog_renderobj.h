#pragma once
#ifndef SVAROG_RENDEROBJ_H
#define SVAROG_RENDEROBJ_H
#include "svarog_shape.h"
#include "core/String.h"

struct render_mesh {
    SvarogShape mesh;
    unsigned int mesh_id;
    String mesh_name;
};

class RenderObj {
    private: 
        SvarogShape render_obj;
        unsigned int id_val;
        String obj_name;
    public:
        RenderObj();
        void set_mesh_id(unsigned int id);
        void set_mesh_name(String name);
        void input_mesh(SvarogShape input_mesh);
        void draw_input_mesh();
        unsigned int get_id() const;
        String get_mesh_name() const;
        SvarogShape get_mesh() const;
        std::unique_ptr<render_mesh>make_new_renderobj();


};

#endif