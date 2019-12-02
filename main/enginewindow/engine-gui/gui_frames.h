#pragma once
#ifndef GUI_FRAMES_H
#define GUI_FRAMES_H
#include "main/enginewindow/engine-gui/gui_layer.h"
#include "libraries/SvarogGameEngine-Gui/imgui.h"
#include "core/String.h"
#include "core/ds-classes/ArrayList.h"
struct imgui_frame_flags {
    bool is_resizable;
    bool is_movable;
    bool is_rendered;
    bool is_deleted;
    String frame_name;
    unsigned int f_w, f_h;
    ImVec2 gui_frame_pos;

    void set_render_state(int state) {
        is_rendered = (state == 1) ? true : false;
    }
    
    void set_delete_state(int state) {
        is_deleted = (state == 1) ? true : false;
    }

    bool get_render_state() const {
        return is_rendered; 
    }

    bool get_delete_state() const {
        return is_deleted;
    }
};

/*
TODO: get the layer for imgui parts done and streaming.
*/
class SvarogGuiFrame {
    protected: 
        void sort_layers();

    private:
        ArrayList<ImGuiLayer>*layer_stack;
        imgui_frame_flags frame_flag_vals;
        bool sort_val;
        
    public:
        SvarogGuiFrame(bool resize, bool move, String f_name, unsigned int frame_w, unsigned int frame_h) {
            frame_flag_vals.is_resizable=resize;
            frame_flag_vals.is_movable=move;
            frame_flag_vals.frame_name=f_name;
            frame_flag_vals.f_w=frame_w;
            frame_flag_vals.f_h=frame_h;
            layer_stack  = new ArrayList<ImGuiLayer>();
        }

        bool get_resize_val() const;
        bool get_move_val() const;
        bool get_sort_state() const;
        String get_frame_name() const;
        float get_pos_x() const;
        float get_pos_y() const;
        unsigned int get_frame_width() const;
        unsigned int get_frame_height() const;
        void set_frame_pos(bool use_w_h, float w_x, float h_y);
        void add_gui_layer(const ImGuiLayer& engine_layer);
        //void sort_layers();
        void render_layers();
        void begin_gui_frame();
        void end_gui_frame();
        const char* layer_pos_right(unsigned int id);
        const char* layer_pos_left(unsigned int id);

        void set_render_state(int state) {
            frame_flag_vals.set_render_state(state);
        }

        void set_delete_state(int state) {
            frame_flag_vals.set_delete_state(state);
        }
};


#endif