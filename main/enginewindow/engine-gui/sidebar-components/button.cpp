#include "button.h"
unsigned int SvarogButton::get_button_width() const {
    return w_;
}

unsigned int SvarogButton::get_button_height() const {
    return h_;
}

bool SvarogButton::get_resize_state() const {
    return is_resizeable;
}

bool SvarogButton::make_new_button() {
    return ImGui::Button("TODO: fill with name data.", ImVec2(get_button_width(), get_button_height()));
}