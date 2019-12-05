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

bool SvarogLabel::get_text_colored_state() const {
    return text_is_colored;
}

void SvarogLabel::gen_new_label() {
    if(get_text_colored_state()) {
        ImGui::TextColored(ImVec4(1.0f, 1.0f, 1.0f, 1.0f), get_label_format());
        ImGui::LabelText(get_label_txt().str, NULL, ImVec2(get_label_width(), get_label_height()));
    } else if(!get_text_colored_state()) {
        ImGui::LabelText(get_label_txt().str, get_label_format(), ImVec2(get_label_width(), get_label_height()));
    }
}