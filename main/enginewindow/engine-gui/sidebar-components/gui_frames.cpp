#include "gui_frames.h"
bool SvarogGuiFrame::get_resize_val() const {
    return frame_flag_vals.is_resizable;
}

bool SvarogGuiFrame::get_move_val() const {
    return frame_flag_vals.is_movable;
}

String SvarogGuiFrame::get_frame_name() const {
    return frame_flag_vals.frame_name;
}

unsigned int SvarogGuiFrame::get_frame_width() const {
    return frame_flag_vals.f_w;
}

unsigned int SvarogGuiFrame::get_frame_height() const {
    return frame_flag_vals.f_h;
}

void SvarogGuiFrame::begin_gui_frame() {
    ImGui::Begin(static_cast<const char*>(get_frame_name().str));
}

void SvarogGuiFrame::end_gui_frame() {
    ImGui::End();
}

void SvarogGuiFrame::set_frame_pos(bool use_w_h, float w_x, float h_y) {
    bool indicator = (use_w_h==true) ? true : false;
    if(indicator) {
        ImGui::SetCursorPos(ImVec2(get_frame_width(), get_frame_height()));
    } else if(!indicator) {
        ImGui::SetCursorPos(ImVec2(static_cast<unsigned int>(w_x), static_cast<unsigned int>(h_y)));
    }
}