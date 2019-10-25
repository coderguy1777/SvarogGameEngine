#pragma once
#ifndef GUI_LAYER_H
#define GUI_LAYER_H
#include "macrodefs.h"
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

struct InputTextPosition {
    float pos_x;
    float pos_y;
};

class ImGuiLayer {
    private:
    struct ButtonStack {
        GuiLayerID button_id;
        Stack<bool>gui_window_button;
        Stack<String>gui_window_button_text;
    } button_stack;

    struct LabelStack {
        GuiLayerID label_id;
        Stack<std::function<void()>>gui_window_labels;
        Stack<String>gui_label_text;
    }label_stack;
    public: 
};

extern ClassString ENGINE_GUI_LAYER;
#endif