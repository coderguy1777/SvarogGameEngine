#pragma once
#ifndef BUTTON_H
#define BUTTON_H
#include "libraries/imgui/imgui.h"
#include "core/String.h"

class SvarogButton {
    private:
        unsigned int w_, h_;
        bool is_resizeable;
        bool main_button;

    public: 
        SvarogButton(unsigned int width, unsigned int height, bool resize_val):
            w_(width), h_(height), is_resizeable(resize_val)
        {}

        unsigned int get_button_width() const;
        unsigned int get_button_height() const;
        bool get_resize_state() const;
        bool make_new_button();
};

#endif 