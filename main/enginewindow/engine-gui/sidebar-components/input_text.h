#pragma once
#ifndef INPUT_TEXT_H
#define INPUT_TEXT_H
#include "core/String.h"
#include "math/vec2.h"

class SvarogInputText {
    private:
        struct input_text_values {
            char* entered_text;
            bool is_empty = (entered_text == nullptr) ? true : false;
            String box_filler_text;
            Vector2 box_size;
        } input_box;
    public: 
        Vector2 get_input_text_box_size() const;
        unsigned int get_input_text_box_width() const;
        unsigned int get_input_text_box_height() const;
        String get_input_text_box_filler() const;
        bool is_input_text_box_empty() const;
        char* get_current_text() const;
        void change_input_text_box_size(const Vector2& new_size);
        void change_input_text_box_width(const unsigned int& new_width);
        void change_input_text_box_height(const unsigned int& new_height);
        void change_input_text_box_filler(const String& new_filler);
        void init_input_text_box();
};

#endif