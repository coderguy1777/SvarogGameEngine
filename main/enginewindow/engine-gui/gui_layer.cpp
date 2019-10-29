#include "gui_layer.h"
ImGuiLayer::ImGuiLayer(String gui_name, unsigned int class_id) {
    Layer_Name = new ClassString();
    Layer_Name->bind_class_string(class_id, gui_name.str);
    button_data = new Stack<ButtonData>();
    label_data = new Stack<LabelData>();
}

void ImGuiLayer::pass_frame_data(Layer_Pos pos, bool collapse, bool moveable) {
    layer_values.desired_layer_pos = pos;
    layer_values.is_collapsable = collapse;
    layer_values.is_moveable = moveable;
}

void ImGuiLayer::add_button(ButtonData button) {
    button_data->push(button);
}

void ImGuiLayer::add_label(LabelData label) {
    label_data->push(label);
}

ClassString* ImGuiLayer::get_layer_name() const {
    return Layer_Name;
}

void ImGuiLayer::init_button_positions() {
    while(!button_data->isEmpty()) {
        button_stack.gui_window_button.add(SvarogButton(button_data->top().btn_pos.pos_x, button_data->top().btn_pos.pos_y, button_data->top().button_text, false));
        button_stack.gui_window_button_text.push(String(button_data->top().button_text));
        button_data->pop();
    }
    //auto temp = NULL;
    button_stack.button_id.gui_char_id = '#';
    button_stack.button_id.gui_id = button_stack.gui_window_button.size();
}

void ImGuiLayer::init_label_positions() {
    while(!label_data->isEmpty()) {
        label_stack.gui_window_labels.add(SvarogLabel(String(label_data->top().label_text), label_data->top().lbl_pos.pos_x, label_data->top().lbl_pos.pos_y, "%20", true));
        label_stack.gui_label_text.push(String(label_data->top().label_text));
        label_data->pop();
    }
    label_stack.label_id.gui_char_id = '$';
    label_stack.label_id.gui_id = label_stack.gui_window_labels.size() + 1;
}

void ImGuiLayer::init_all() {
    init_button_positions();
    init_label_positions();
}

void ImGuiLayer::render_layer() {
    for(unsigned int j = 0; j < button_stack.gui_window_button.size(); j++) {
        auto ba = button_stack.gui_window_button.get(j).make_new_button();
    }

    for(unsigned int i = 0; i < label_stack.gui_window_labels.size(); i++) {
        label_stack.gui_window_labels.get(i).gen_new_label();
    }
}

Layer_Pos ImGuiLayer::get_wanted_pos() const {
    return layer_values.desired_layer_pos;
}

bool ImGuiLayer::get_collapse_state() const {
    return layer_values.is_collapsable;
}

bool ImGuiLayer::get_move_state() const {
    return layer_values.is_moveable;
}