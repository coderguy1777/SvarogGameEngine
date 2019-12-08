#include "gui_frames.h"
bool SvarogGuiFrame::get_render_state() const {
    return (frame_flag_vals.get_render_state() == true) ? true : false;
}

bool SvarogGuiFrame::get_delete_state() const {
    return (frame_flag_vals.get_delete_state() == true) ? true : false;
}

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

float SvarogGuiFrame::get_pos_x() const {
    return frame_flag_vals.gui_frame_pos.x;
}

float SvarogGuiFrame::get_pos_y() const {
    return frame_flag_vals.gui_frame_pos.y;
}

void SvarogGuiFrame::set_frame_pos(bool use_w_h, float w_x, float h_y) {
    bool indicator = (use_w_h==true) ? true : false;
    if(indicator) {
        frame_flag_vals.gui_frame_pos[0] = static_cast<float>(get_frame_width());
        frame_flag_vals.gui_frame_pos[1] = static_cast<float>(get_frame_height());
    } else if(!indicator) {
        frame_flag_vals.gui_frame_pos[0] = w_x;
        frame_flag_vals.gui_frame_pos[1] = h_y;   
    }
}

void SvarogGuiFrame::add_gui_layer(const ImGuiLayer& layer_a) {
    layer_stack->add(layer_a);
}

void SvarogGuiFrame::sort_layers() {
    auto size_check = layer_stack->size();
    auto temp_stack = make_shared<Stack<ImGuiLayer>>(); // for ids <= 5 || == 0
    auto temp_stack_2 = make_shared<Stack<ImGuiLayer>>(); // for ids >= 6 || == 10

    for(unsigned int layer = 0; layer < layer_stack->size(); layer++) {
        auto temp_str = layer_stack->get(layer).get_layer_name();
        if(temp_str->get_class_id() <= 5 || temp_str->get_class_id() == 0) {
            auto index = layer;
            auto layer_id = layer_stack->get(index);
            temp_stack->push(layer_id);
            layer_stack->remove(index);
        }

        if(temp_str->get_class_id() >= 6 || temp_str->get_class_id() == 10) {
            auto index = layer;
            auto layer_id = layer_stack->get(index);
            temp_stack->push(layer_id);
            layer_stack->remove(index);
        }

        if(temp_str->get_class_id() < 0 || temp_str->get_class_id() > 10)  {
            auto error_str = temp_str->get_class_str();
            auto error_str_id = temp_str->get_class_id();
            spdlog::error("ERROR: LAYER_ID > 10 || LAYER_ID < 0");
            spdlog::error("LAYER_NAME: {}", error_str);
            spdlog::error("LAYER_ID: {}", error_str_id);
            spdlog::error("CANNOT CONTINUE RENDERING LAYERS, EXITING");
        }
    }
    // pushing to main layer stack
    layer_stack->clear();
    while(!temp_stack->isEmpty()) {
        layer_stack->add(temp_stack->top());
        temp_stack->pop();
    }

    while(!temp_stack_2->isEmpty()) {
        layer_stack->add(temp_stack_2->top());
        temp_stack_2->pop();
    }
    // checks if sort worked
    spdlog::info("LAYER_SIZE: {}", layer_stack->size());
    spdlog::info("LAYER_NAME: {}", layer_stack->get(0).get_layer_name()->get_class_str());
}

void SvarogGuiFrame::render_layers() {
    for(unsigned int gui_layer = 0; gui_layer < layer_stack->size(); gui_layer++) {
        layer_stack->get(gui_layer).render_layer();
        layer_stack->remove(gui_layer - 1);
    }
}

const char* SvarogGuiFrame::layer_pos_left(unsigned int id) {
    const char* pos_msg;
    assert(id >= 6 && id <= 10);
    switch(id) {
        case 6: 
            pos_msg = "BOTTOM_LEFT";
            break;
        case 7: 
            pos_msg = "BOTTOM_LEFT_UP";
            break;
        case 8: 
            pos_msg = "LEFT_MIDDLE";
            break;
        case 9: 
            pos_msg = "TOP_LEFT_DOWN";
            break;
        case 10: 
            pos_msg = "TOP_LEFT_DOWN_DOWN";
            break;
        default: 
            pos_msg = "NO_POS";
            break;
    }
    return pos_msg;
}

const char* SvarogGuiFrame::layer_pos_right(unsigned int id) {
    const char* pos_msg;
    assert(id >= 0 && id <= 5);
    switch(id - 1) {
        case 0: 
            pos_msg = "BOTTOM_RIGHT";
            break;
        case 1: 
            pos_msg = "BOTTOM_RIGHT_UP";
            break;
        case 2: 
            pos_msg = "RIGHT_MIDDLE";
            break;
        case 3: 
            pos_msg = "TOP_RIGHT_DOWN";
            break;
        case 4: 
            pos_msg = "TOP_RIGHT_DOWN";
            break;
        default: 
            pos_msg = "NO_POS";
            break;
    }
    return pos_msg;
}