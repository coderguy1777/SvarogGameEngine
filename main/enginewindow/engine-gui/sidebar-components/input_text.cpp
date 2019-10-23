#include "input_text.h"
unsigned int SvarogInputText::get_arr_len() const {
    return text_array.arr_len;
}

char* SvarogInputText::get_text_buffer() const {
    return text_array.input_arr;
}

String SvarogInputText::get_input_text_box_filler() const {
    return filler_text;
}

bool SvarogInputText::init_input_text_box() {
    return ImGui::InputText(get_input_text_box_filler().str, get_text_buffer(), get_arr_len());
}