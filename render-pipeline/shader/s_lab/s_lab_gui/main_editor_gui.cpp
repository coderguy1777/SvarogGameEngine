#include "main_editor_gui.h"

SLabEditorGUI* SLabEditorGUI::getSlabEditor() {
    if(!slabeditor_instance) {
        slabeditor_instance = new SLabEditorGUI;
    }
    return slabeditor_instance;
}
COLOR_MODEL SLabEditorGUI::get_current_color_model() const {
    return color_model_curr;
}

String SLabEditorGUI::get_color_label() const {
    return curr_color_label;
}

void SLabEditorGUI::color_model_selection(COLOR_MODEL model) {
    switch(model) {
        case COLOR_MODEL::RGB_MODEL: 
            color_model_curr = COLOR_MODEL::RGB_MODEL; 
            curr_color_label = "RGB Model.";
            break;
        case COLOR_MODEL::HSV_MODEL:
            color_model_curr = COLOR_MODEL::HSV_MODEL;
            curr_color_label = "HSV Model.";
            break;
        case COLOR_MODEL::HSL_MODEL:
            color_model_curr = COLOR_MODEL::HSL_MODEL;
            curr_color_label = "HSL Model.";
            break;
        case COLOR_MODEL::CMYK_MODEL: 
            color_model_curr = COLOR_MODEL::CMYK_MODEL;
            curr_color_label = "CMYK Model.";
            break;
        case COLOR_MODEL::ARGB_MODEL:
            color_model_curr = COLOR_MODEL::ARGB_MODEL;
            curr_color_label = "Adobe RGB Model.";
            break;
        case COLOR_MODEL::HEX_CODE: 
            color_model_curr = COLOR_MODEL::HEX_CODE;
            curr_color_label = "Hex Code Model.";
            break;
        case COLOR_MODEL::EIGHT_BIT_RGB_MODEL:
            color_model_curr = COLOR_MODEL::EIGHT_BIT_RGB_MODEL;
            curr_color_label = "8 Bit RGB Color Model.";
            break;
        default: 
            color_model_curr = static_cast<COLOR_MODEL>(-1);
            curr_color_label = "NULL_MODEL";
            break;
    }
}

void SLabEditorGUI::edit_material() {
    // add editor here kinda
    bool material_edited;

}

void SLabEditorGUI::init_editor() {
    ImGui::SetNextWindowSize(ImVec2(300.0f, 400.0f), ImGuiCond_Once);
    ImGui::Begin("Shader Editor");
    slab_c_values.color_model_selection();
    ImGui::End();
}

void SLabEditorGUI::switch_editor_state(S_LAB_STATE state) {
    state = S_LAB_STATE::NODE_EDITOR;
}

void SLabEditorGUI::init_editor_window_gui_frames() {

}

std::vector<float> SLabEditorGUI::get_current_color_values() const {
    slab_c_values.get_color_values();
}

SLabEditorGUI* SLabEditorGUI::slabeditor_instance  = 0;