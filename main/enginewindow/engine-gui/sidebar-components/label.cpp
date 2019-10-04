#include "label.h"
String SvarogLabel::get_label_txt() const {
    return label_text;
}

unsigned int SvarogLabel::get_label_width() const {
    return l_w;
}

unsigned int SvarogLabel::get_label_height() const {
    return l_h;
}

const char* SvarogLabel::get_label_format() const {
    return label_format;
}

bool SvarogLabel::get_move_state() const {
    return is_movable;
}

void SvarogLabel::gen_new_label() {
    ImGui::LabelText(get_label_txt().str, get_label_format(), ImVec2(get_label_width(), get_label_height()));
}