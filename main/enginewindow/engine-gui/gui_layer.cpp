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

}

void ImGuiLayer::init_label_positions() {

}

void ImGuiLayer::init_all() {
    
}