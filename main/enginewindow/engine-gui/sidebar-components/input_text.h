#pragma once
#ifndef INPUT_TEXT_H
#define INPUT_TEXT_H
#include "libraries/SvarogGameEngine-Gui/imgui.h"
#include "core/String.h"
#include "math/vec2.h"
#include "core/ds-classes/Array.h"
#include<functional>
/*
    TODO: make values such as enum cases for text input being intakeable by the 
*/ 
class SvarogInputText {
    private:
        struct input_char_arr {
            char* input_arr;
            unsigned int arr_len;
        } text_array;
        String filler_text;
    public: 
        SvarogInputText(String filler_txt, char* buffer, uint length):
           text_array(input_char_arr{buffer, length}), filler_text(filler_txt)
        {init_input_text_box();}
        unsigned int get_arr_len() const;
        String get_input_text_box_filler() const;
        char* get_text_buffer() const;
        bool init_input_text_box();
};
#endif