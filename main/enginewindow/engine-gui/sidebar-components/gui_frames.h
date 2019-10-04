#pragma once
#ifndef GUI_FRAMES_H
#define GUI_FRAMES_H
#include "libraries/imgui/imgui.h"
#include "core/String.h"
#include "core/ds-classes/ArrayList.h"
enum class GUI_TAG {
    GUI_BUTTON=0,
    GUI_LABEL=1,
    GUI_CHECKBOX=2,
    GUI_SLIDER=3,
};

struct imgui_frame_flags {
    bool is_resizable;
    bool is_movable;
    String frame_name;
    unsigned int f_w, f_h;
};

// storage for buttons and other components inside individual 
// lists for running on run time for the user in the window.
template<typename T>
struct imgui_frame_pt_stg {
    GUI_TAG pt_li_tag;
    ArrayList<T>pt_li_stg;
};

/*
TODO: get the layer for imgui parts done and streaming.
*/
class SvarogGuiFrame {
    private:
        imgui_frame_flags frame_flag_vals;
    public:
        SvarogGuiFrame(bool resize, bool move, String f_name, unsigned int frame_w, unsigned int frame_h) {
            frame_flag_vals.is_resizable=resize;
            frame_flag_vals.is_movable=move;
            frame_flag_vals.frame_name=f_name;
            frame_flag_vals.f_w=frame_w;
            frame_flag_vals.f_h=frame_h;
        }

        bool get_resize_val() const;
        bool get_move_val() const;
        String get_frame_name() const;
        unsigned int get_frame_width() const;
        unsigned int get_frame_height() const;
        void set_frame_pos(bool use_w_h, float w_x, float h_y);
        void begin_gui_frame();
        void end_gui_frame();
};


#endif