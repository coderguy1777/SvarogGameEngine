#pragma once
#ifndef MAIN_EDITOR_GUI_H
#define MAIN_EDITOR_GUI_H
#include <map>
#include <stack>
#include <sstream>
#include "spdlog/spdlog.h"
#include "render-pipeline/shader/s_lab/svarog_material.h"
#include "main/enginewindow/engine-gui/gui_frames.h"
#include "main/enginewindow/engine-gui/gui_layer.h"
#include "main/enginewindow/engine-gui/gui_window.h"
#include "core/String.h"

enum class S_LAB_STATE {
    NODE_EDITOR,
    NON_NODE_EDITOR,
};

class SLabEditorGUI {
    private:
        struct ShaderValuePicker {
            private: 
                float specular_value;
                float roughness_value;
                float metallic_scale;
                

            public: 
                float get_specular() const {
                    return specular_value;
                }

                float get_roughness() const {
                    return roughness_value;
                }

                float get_metallic_scale() const {
                    return metallic_scale;
                }

        } s_value_picker;
    
        struct ShaderColorPicker {
            private:
                COLOR_MODEL color_val;
                String color_label_txt;
                String curr_model = String("");
                int model_selected;

                float specular_val;
                float roughness_val;
                bool new_mat_made;

            public:
                float values[4];

                float get_curr_spec() const {
                    return specular_val;
                }

                std::vector<float>get_color_values() const {
                    std::vector<float>m_color;
                    for(uint i = 0; i < 4; i++) {
                        m_color.push_back(values[i]);
                    }
                    return m_color;
                }

                float get_curr_roughness() const {
                    return roughness_val;
                }

                void set_specular(float spec_val) {
                    specular_val = spec_val;
                }

                void set_roughness(float rough_val) {
                    roughness_val = rough_val;
                }

                int get_curr_model() const {
                    return model_selected;
                }

                String get_color_picker_name() const {
                    return color_label_txt;
                }

                COLOR_MODEL get_curr_model_enum() const {
                    return color_val;
                }

                String get_selected_model_lbl() const {
                    return curr_model;
                }

                void set_selected_color_model_str() {
                    auto selected_mdl = get_curr_model_enum();
                    switch(selected_mdl) {
                        case COLOR_MODEL::RGB_MODEL:
                            curr_model = String("RGB Values:");
                            model_selected = 1;
                            break;
                        case COLOR_MODEL::HSV_MODEL:
                            curr_model = String("HSV Values:");
                            model_selected = 2;
                            break;
                        case COLOR_MODEL::HSL_MODEL:
                            curr_model = String("HSL Values:");
                            model_selected = 3;
                            break;
                        case COLOR_MODEL::CMYK_MODEL:
                            curr_model = String("CMYK Values");
                            model_selected = 4;
                            break;
                        case COLOR_MODEL::ARGB_MODEL:
                            curr_model = String("Adobe RGB Values:");
                            model_selected = 5;
                            break;
                        case COLOR_MODEL::EIGHT_BIT_RGB_MODEL:
                            curr_model = String("8 bit Values:");
                            model_selected = 6;
                            break;
                        case COLOR_MODEL::HEX_CODE:
                            curr_model = String("Hex Color Code");
                            model_selected = 7;
                            break;
                        default:
                            curr_model = String("\0");
                            model_selected = -1;
                            break;
                    }
                }

                void set_selected_model(int curr) {
                    model_selected = curr;
                    switch(curr) {
                        case 0: 
                            set_curr_model(COLOR_MODEL::RGB_MODEL);
                            break;
                        case 1:
                            set_curr_model(COLOR_MODEL::HSV_MODEL);
                            break;
                        case 2:
                            set_curr_model(COLOR_MODEL::HSL_MODEL);
                            break;
                        case 3: 
                            set_curr_model(COLOR_MODEL::CMYK_MODEL);
                            break;
                        case 4:
                            set_curr_model(COLOR_MODEL::ARGB_MODEL);
                            break;
                        case 5:
                            set_curr_model(COLOR_MODEL::EIGHT_BIT_RGB_MODEL);
                            break;
                        case 6:
                            set_curr_model(COLOR_MODEL::HEX_CODE);
                            break;
                        default:
                            model_selected = -1;
                            break;
                    }
                }

                void color_model_selection() {
                    const char* color_selection_labels[] = {
                        "RGB Color Model",
                        "HSV Color Model",
                        "HSL Color Model",
                        "CMYK Color Model",
                        "ARGB Color Model",
                        "8 Bit Color Model",
                        "Hex Color Code",
                    };

                    set_color_label_txt(String("Select a Color Model."));
                    uint len_of_color_labels = IM_ARRAYSIZE(color_selection_labels);
                    static int curr_model_val = -1;
                    auto str = std::string(get_color_picker_name().str) +'\n';
                    ImGui::Text(str.c_str());
                    ImGui::PushItemWidth(300.0f);
                    ImGui::ListBox("\0", &curr_model_val, color_selection_labels, len_of_color_labels, 5);
                    set_selected_model(curr_model_val);

                    if(curr_model_val == -1) {
                        curr_model.str = NULL;
                    } else {
                       set_selected_color_model_str();
                       ImGui::Text(get_selected_model_lbl().str);

                       if(get_curr_model_enum() == COLOR_MODEL::RGB_MODEL && model_selected == 1) {
                           static float r = {};
                           static float g = {};
                           static float b = {};
                           static float a = {};
                           ImGui::NewLine();
                           ImGui::PushItemWidth(100.0f);
                           ImGui::SameLine();
                           ImGui::SliderFloat("R", &r, 0.0f, 256.0f, "%.1f", 1.0f);
                           ImGui::PopItemWidth();
                           ImGui::NewLine();
                           ImGui::PushItemWidth(100.0f);
                           ImGui::SameLine();
                           ImGui::SliderFloat("G", &g, 0.0f, 256.0f, "%.1f", 1.0f);
                           ImGui::PopItemWidth();
                           ImGui::NewLine();
                           ImGui::PushItemWidth(100.0f);
                           ImGui::SameLine();
                           ImGui::SliderFloat("B", &b, 0.0f, 256.0f, "%.1f", 1.0f);
                           ImGui::PopItemWidth();
                           ImGui::NewLine();
                           ImGui::PushItemWidth(100.0f);
                           ImGui::SameLine();
                           ImGui::SliderFloat("A", &a, 0.0f, 256.0f, "%.1f", 1.0f);
                           ImGui::PopItemWidth();
                           values[0] = r;
                           values[1] = g;
                           values[2] = b;
                           values[3] = a;
                       }

                       if(get_curr_model_enum() == COLOR_MODEL::HSV_MODEL && model_selected == 2) {
                           static float hue = {};
                           static float saturation = {};
                           static float value = {};
                           ImGui::NewLine();
                           ImGui::PushItemWidth(100.0f);
                           ImGui::SameLine();
                           ImGui::SliderFloat("H", &hue, 0.0f, 256.0f, "%.1f", 1.0f);
                           ImGui::PopItemWidth();
                           ImGui::NewLine();
                           ImGui::PushItemWidth(100.0f);
                           ImGui::SameLine();
                           ImGui::SliderFloat("S", &saturation, 0.0f, 100.0f, "%.1f", 1.0f);
                           ImGui::PopItemWidth();
                           ImGui::NewLine();
                           ImGui::PushItemWidth(100.0f);
                           ImGui::SameLine();
                           ImGui::SliderFloat("V", &value, 0.0f, 100.0f, "%.1f", 1.0f);
                           ImGui::PopItemWidth();
                           values[0] = hue;
                           values[1] = saturation;
                           values[2] = value;
                           values[3] = 0.0f;
                       }

                       if(get_curr_model_enum() == COLOR_MODEL::HSL_MODEL && model_selected == 3) {
                           static float hue = {};
                           static float saturation  = {};
                           static float lightness = {};
                           ImGui::NewLine();
                           ImGui::PushItemWidth(100.0f);
                           ImGui::SameLine();
                           ImGui::SliderFloat("Hue", &hue, 0.0f, 256.0f, "%.1f", 1.0f);
                           ImGui::PopItemWidth();
                           ImGui::NewLine();
                           ImGui::PushItemWidth(100.0f);
                           ImGui::SameLine();
                           ImGui::SliderFloat("Saturation", &saturation, 0.0f, 100.0f, "%.1f", 1.0f);
                           ImGui::PopItemWidth();
                           ImGui::NewLine();
                           ImGui::PushItemWidth(100.0f);
                           ImGui::SameLine();
                           ImGui::SliderFloat("Lightness", &lightness, 0.0f, 100.0f, "%.1f", 1.0f);
                           ImGui::PopItemWidth();
                           values[0] = hue;
                           values[1] = saturation;
                           values[2] = lightness;
                           values[3] = 0.0f;
                       }

                       if(get_curr_model_enum() == COLOR_MODEL::CMYK_MODEL && model_selected == 4) {
                           static float cyan = {};
                           static float magenta = {};
                           static float yellow = {};
                           static float key = {};
                           ImGui::NewLine();
                           ImGui::PushItemWidth(100.0f);
                           ImGui::SameLine();
                           ImGui::SliderFloat("C", &cyan, 0.0f, 100.0f, "%.0f", 1.0f);
                           ImGui::PopItemWidth();
                           ImGui::NewLine();
                           ImGui::PushItemWidth(100.0f);
                           ImGui::SameLine();
                           ImGui::SliderFloat("M", &magenta, 0.0f, 100.0f, "%.0f", 1.0f);
                           ImGui::NewLine();
                           ImGui::PushItemWidth(100.0f);
                           ImGui::SameLine();
                           ImGui::SliderFloat("Y", &yellow, 0.0f, 100.0f, "%.0f", 1.0f);
                           ImGui::PopItemWidth();
                           ImGui::NewLine();
                           ImGui::PushItemWidth(100.0f);
                           ImGui::SameLine();
                           ImGui::SliderFloat("K", &key, 0.0f, 100.0f, "%.0f", 1.0f);
                           ImGui::PopItemWidth();
                           values[0] = cyan;
                           values[1] = magenta;
                           values[2] = yellow;
                           values[3] = key;
                       }

                       if(get_curr_model_enum() == COLOR_MODEL::ARGB_MODEL && model_selected == 5) {
                           static float r = {};
                           static float g = {};
                           static float b = {};
                           ImGui::NewLine();
                           ImGui::PushItemWidth(100.0f);
                           ImGui::SameLine();
                           ImGui::SliderFloat("R", &r, 0.0f, 1.0f, "%.5f", 1.0f);
                           ImGui::PopItemWidth();
                           ImGui::NewLine();
                           ImGui::PushItemWidth(100.0f);
                           ImGui::SameLine();
                           ImGui::SliderFloat("G", &g, 0.0f, 1.0f, "%.5f", 1.0f);
                           ImGui::PopItemWidth();
                           ImGui::NewLine();
                           ImGui::PushItemWidth(100.0f);
                           ImGui::SameLine();
                           ImGui::SliderFloat("B", &b, 0.0f, 1.0f, "%.5f", 1.0f);
                           ImGui::PopItemWidth();
                           values[0] = r;
                           values[1] = g;
                           values[2] = b;
                           values[3] = 0.0f;
                        
                       }

                       if(get_curr_model_enum() == COLOR_MODEL::EIGHT_BIT_RGB_MODEL && model_selected == 6) {
                           static float eight_bit_r = {};
                           static float eight_bit_g = {};
                           static float eight_bit_b = {};
                           ImGui::NewLine();
                           ImGui::PushItemWidth(100.0f);
                           ImGui::SameLine();
                           ImGui::SliderFloat(" R", &eight_bit_r, 0.0f, 1.0f, "%.3f", 1.0f);
                           ImGui::PopItemWidth();
                           ImGui::NewLine();
                           ImGui::PushItemWidth(100.0f);
                           ImGui::SameLine();
                           ImGui::SliderFloat(" G", &eight_bit_g, 0.0f, 1.0f, "%.3f", 1.0f);
                           ImGui::PopItemWidth();
                           ImGui::NewLine();
                           ImGui::PushItemWidth(100.0f);
                           ImGui::SameLine();
                           ImGui::SliderFloat(" B", &eight_bit_b, 0.0f, 1.0f, "%.3f", 1.0f);
                           ImGui::PopItemWidth();
                           values[0] = eight_bit_r;
                           values[1] = eight_bit_g;
                           values[2] = eight_bit_b;
                           values[3] = 0.0f;

                       }

                       if(get_curr_model_enum() == COLOR_MODEL::HEX_CODE && model_selected == 7) {
                           static char hex_code[8] = {};
                           hex_code[0] = '#';
                           ImGui::NewLine();
                           ImGui::PushItemWidth(100.0f);
                           ImGui::SameLine();
                           ImGui::InputText("Hex Code", hex_code, sizeof(hex_code));
                           ImGui::PopItemWidth();
                       }
                    }
                    ImGui::PopItemWidth();
                }

                void set_curr_model(COLOR_MODEL model_val) {
                    color_val = model_val;
                }

                void set_color_label_txt(String proper_label_name) {
                    color_label_txt = proper_label_name;
                }

                void set_color_values(std::vector<float>color_vals) {
                    for(uint i = 0; i < color_vals.size(); i++) {
                        values[i] = color_vals[i];
                    }
                }
        } slab_c_values;
        struct EditorGuiFrames {
            std::vector<SvarogGuiFrame>gui_frames;
            std::vector<uint>gui_state_order; // for ideas of making different parts of the editor visible, etc.
            uint curr_state; // for finding the current state of the editor, which window is opened.
        } s_lab_gui_frames;

        COLOR_MODEL color_model_curr;
        String curr_color_label;
        std::stack<SvarogGuiWindow>slab_gui_editor_windows;
        SvarogMaterial* curr_material;

        SLabEditorGUI () {}
        static SLabEditorGUI* slabeditor_instance;
    public: 
        static SLabEditorGUI* getSlabEditor();
        String get_color_label() const;
        COLOR_MODEL get_current_color_model() const;
        void edit_material();
        void color_model_selection(COLOR_MODEL c_model);
        void init_editor();
        void switch_editor_state(S_LAB_STATE editor_window_to_open);
        void init_editor_window_gui_frames();
        std::vector<float>get_current_color_values() const;
};

#endif