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

bool SvarogButton::is_clicked(uint mouse_code) {
    bool is_clicked = NULL;
    bool return_val = (ImGui::IsItemClicked(static_cast<int>(mouse_code)) == true) ? true : false;
    if(return_val) {
        is_clicked = true;
    } else {
        is_clicked = false;
    }
    return is_clicked;
}

bool SvarogButton::is_active() {
    return ImGui::IsItemActive();
}

bool SvarogButton::is_hovered() {
    return ImGui::IsItemHovered();
}