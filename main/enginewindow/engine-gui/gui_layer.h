#pragma once
#ifndef GUI_LAYER_H
#define GUI_LAYER_H
#include <functional>
#include "macrodefs.h"
#include "core/ds-classes/Array.h"
#include "core/String.h"
#include "core/ds-classes/ClassString.h"
#include "core/ds-classes/Stack.h"

struct GuiLayerID {
    unsigned int gui_id;
    char gui_char_id;
};

struct ButtonPosition{
    float pos_x;
    float pos_y;
};

struct LabelPosition {
    float pos_x;
    float pos_y;
};

struct LabelData {
    String label_text;
    std::function<void()>label_init;
    LabelPosition lbl_pos;
    unsigned int pos; // greater pos, closer to bottom.
};

struct ButtonData {
    String button_text;
    bool svarog_button;
    ButtonPosition btn_pos;
    unsigned int pos; // greater pos, closer to bottom.
};

// given a position, put into frame rendering in that position, top
// left, right, and bottom.
enum class Layer_Pos {
    FRAME_RIGHT,
    FRAME_LEFT,
    FRAME_TOP,
    FRAME_BOTTOM,
};

class ImGuiLayer {
    protected: 
        void init_button_positions();
        void init_label_positions();

    private:
        Stack<ButtonData>*button_data;
        Stack<LabelData>*label_data;

        struct LayerData {
            Layer_Pos desired_layer_pos;
            bool is_collapsable;
            bool is_moveable;        
        } layer_values;
    
        struct ButtonStack {
            GuiLayerID button_id;
            Stack<bool>gui_window_button;
            Stack<String>gui_window_button_text;
        } button_stack;

        struct LabelStack {
            GuiLayerID label_id;
            Stack<std::function<void()>>gui_window_labels;
            Stack<String>gui_label_text;
        } label_stack;
        ClassString *Layer_Name;

    public: 
        ImGuiLayer(String gui_name, unsigned int class_id); // from 0-5, left side, 6-10, right side.
        void pass_frame_data(Layer_Pos wanted_pos, bool collapse, bool moveable);
        Layer_Pos get_wanted_pos() const;
        bool get_collapse_state() const;
        bool get_move_state() const;
        void init_all();
        void add_button(ButtonData new_button);
        void add_label(LabelData new_label);
        ClassString* get_layer_name() const;
};
// extern ClassString ENGINE_GUI_LAYER;
#endif