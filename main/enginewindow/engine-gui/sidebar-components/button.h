#pragma once
#ifndef BUTTON_H
#define BUTTON_H
#include "libraries/imgui/imgui.h"
#include "core/String.h"

class SvarogButton {
    private:
        unsigned int w_, h_;
        String button_text;
        bool is_resizeable;
        bool main_button;

    public: 
        SvarogButton(unsigned int width, unsigned int height, String btn_text, bool resize_val):
            w_(width), h_(height), button_text(btn_text), is_resizeable(resize_val)
        {}

        unsigned int get_button_width() const;
        unsigned int get_button_height() const;
        String get_button_text() const;
        bool get_resize_state() const;
        bool make_new_button();
};

#endif 