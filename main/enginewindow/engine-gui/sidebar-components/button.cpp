#include "button.h"
unsigned int SvarogButton::get_button_width() const {
    return w_;
}

unsigned int SvarogButton::get_button_height() const {
    return h_;
}

String SvarogButton::get_button_text() const {
    return button_text;
}

bool SvarogButton::get_resize_state() const {
    return is_resizeable;
}

bool SvarogButton::make_new_button() {
    return ImGui::Button(get_button_text().str, ImVec2(get_button_width(), get_button_height()));
}
