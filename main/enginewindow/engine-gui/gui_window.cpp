#include "gui_window.h"
void SvarogGuiWindow::insert_to_stack(SvarogGuiFrame gui_frame) {
    frame_stack.push(gui_frame);
}

void SvarogGuiWindow::render_frames() {
    if(frame_stack.isEmpty()) {
        spdlog::error("ERROR: FRAME STACK EMPTY OF GUI FRAMES.");
        exit(0);
    } else {
        while(!frame_stack.isEmpty()) {
            ImGui::SetNextWindowPos(ImVec2(100, 0), ImGuiCond_Once, ImVec2(0, 0));
            ImGui::SetNextWindowSize(ImVec2(frame_stack.top().get_frame_width(), frame_stack.top().get_frame_height()), ImGuiCond_Always);
            frame_stack.top().begin_gui_frame();
            frame_stack.top().render_layers();
            frame_stack.top().end_gui_frame();
            
            frame_stack.pop();
        }
    }
}