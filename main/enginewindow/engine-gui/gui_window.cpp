#include "gui_window.h"
/* 
BACKLOG: 
------------------------
    Log 1: need to make sure the styles for each window made here are parsed correctly, along with the gui
    frame styles as well, to make sure they are made so that they are designed as they are in the engine. 
    Along with this, a bug that needs to be fixed is scaling the gui frame position on the event of a window 
    resize, which is not being done in this case, which needs to be fixed in the future in this case.
------------------------
    Log 2: need to continue wokring on styling sorting, and scaling of gui components on resize events 
    in the engine window as well when they occur.
    
*/ 
void SvarogGuiWindow::insert_to_stack(SvarogGuiFrame gui_frame) {
    frame_stack.push(gui_frame);
}

void SvarogGuiWindow::render_frames() {
    if(frame_stack.isEmpty()) {
        spdlog::error("ERROR: FRAME STACK EMPTY OF GUI FRAMES.");
        exit(0);
    } else {
        while(!frame_stack.isEmpty()) {
            auto curr_window = frame_stack.top();
            if(curr_window.get_move_val()) {
                ImGui::SetNextWindowPos(ImVec2(curr_window.get_pos_x(), curr_window.get_pos_y()), ImGuiCond_Always);
                curr_window.set_render_state(1);
            } else if(!curr_window.get_move_val()) {
                curr_window.set_render_state(0);
            }

            if(curr_window.get_resize_val()) {
                ImGui::SetNextWindowSize(ImVec2(curr_window.get_frame_width(), curr_window.get_frame_height()), ImGuiCond_Always);
                curr_window.set_render_state(1);
            } else if(!curr_window.get_resize_val()) {
                curr_window.set_render_state(0);

            }

            bool is_renderable = (curr_window.get_render_state() == true) ? true : false;
            if(is_renderable) {
                curr_window.begin_gui_frame();
                curr_window.render_layers();
                curr_window.end_gui_frame();
                frame_stack.pop(); 
                curr_window = frame_stack.top();
            } else if(!is_renderable) {
                frame_stack.pop();
                curr_window = frame_stack.top();
            }
            // left side (0, 0)
            // center ()
            frame_stack.top().begin_gui_frame();
            frame_stack.top().render_layers();
            frame_stack.top().end_gui_frame();
            frame_stack.pop();
            
        }
    }
}