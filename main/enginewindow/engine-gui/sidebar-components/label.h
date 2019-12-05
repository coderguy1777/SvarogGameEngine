#pragma once
#ifndef LABEL_H
#define LABEL_H
#include <functional>
#include "libraries/SvarogGameEngine-Gui/imgui.h"
#include "core/String.h"

class SvarogLabel {
    private:
        String label_text;
        unsigned int l_w;
        unsigned int l_h;
        const char* label_format;
        bool is_movable;
        bool text_is_colored;
    public:
        SvarogLabel(String input_txt, unsigned int label_w, unsigned int label_h, const char* l_format, bool move_val, bool is_colored_text):
            label_text(input_txt), l_w(label_w), l_h(label_h), label_format(l_format), is_movable(move_val), text_is_colored(is_colored_text)
        {}

        SvarogLabel() {
            // TODO: make params for default constructor.
        }
        String get_label_txt() const;
        bool get_text_colored_state() const;
        unsigned int get_label_width() const;
        unsigned int get_label_height() const;
        const char* get_label_format() const;
        bool get_move_state() const;
        void gen_new_label();

};
#endif