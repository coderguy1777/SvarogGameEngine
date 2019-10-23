#include "input_text.h"
Vector2 SvarogInputText::get_input_text_box_size() const {
    return input_box.box_size;
}

unsigned int SvarogInputText::get_input_text_box_height() const {
    return input_box.box_size.inity;
}

unsigned int SvarogInputText::get_input_text_box_width() const {
    return input_box.box_size.initx;
}

String SvarogInputText::get_input_text_box_filler() const {
    return input_box.box_filler_text;
}

bool SvarogInputText::is_input_text_box_empty() const {
    return input_box.is_empty;
}

char* SvarogInputText::get_current_text() const {
    char* contents;
    if(is_input_text_box_empty()) {
        contents = nullptr;
    } 

    if(!is_input_text_box_empty()) {
        unsigned int len = sizeof(input_box.entered_text) / sizeof(input_box.entered_text[0]);
        contents = new char[len];
        for(unsigned int i = 0; i <= len; i++) {
            contents[i] = input_box.entered_text[i];
        }
    }
    return contents;
}

void SvarogInputText::change_input_text_box_size(const Vector2& new_size) {
    input_box.box_size.initx = new_size.initx;
    input_box.box_size.inity = new_size.inity;    
}

void SvarogInputText::change_input_text_box_width(const unsigned int& new_w) {
    input_box.box_size.initx = new_w;
}

void SvarogInputText::change_input_text_box_height(const unsigned int& new_h) {
    input_box.box_size.inity = new_h;
}

void SvarogInputText::change_input_text_box_filler(const String& new_filler) {
    input_box.box_filler_text = new_filler;
}

void SvarogInputText::init_input_text_box() {
    assert(is_input_text_box_empty() == true);
    assert(get_input_text_box_height() != 0);
    assert(get_input_text_box_width() != 0);
    bool height_small = (get_input_text_box_height() < 0) ? true : false;
    bool width_small = (get_input_text_box_width() < 0) ? true : false;
    if(height_small || width_small) {
        spdlog::error("CHANGE INPUT HEIGHT OR WIDTH TO FIX ERROR");
        throw invalid_argument("INPUT_TEXT_HEIGHT_ERROR");
    }
}