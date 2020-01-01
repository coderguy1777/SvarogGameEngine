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
        struct ShaderColorPicker {
            private:
                COLOR_MODEL color_val;
                String color_label_txt;
                String curr_model = String("");
                int model_selected;
                float values[4];
            public:
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
                           static char r[4] = {};
                           static char g[4] = {};
                           static char b[4] = {};
                           static char a[4] = {};
                           ImGui::NewLine();
                           ImGui::PushItemWidth(100.0f);
                           ImGui::SameLine();
                           ImGui::InputText("R", r, sizeof(r));
                           
                           float r_1[4] = {};
                           for(uint i = 0; i < 4; i++) {
                               r_1[i] = (float)(r[i]-'0');
                           }
                           
                           ImGui::PopItemWidth();
                           ImGui::NewLine();
                           ImGui::PushItemWidth(100.0f);
                           ImGui::SameLine();
                           ImGui::InputText("G", g, sizeof(g));

                           float g_1[4] = {};
                           for(uint j = 0; j < 4; j++) {
                               g_1[j] = (float)(g[j]-'0');
                           }

                           ImGui::PopItemWidth();
                           ImGui::NewLine();
                           ImGui::PushItemWidth(100.0f);
                           ImGui::SameLine();
                           ImGui::InputText("B", b, sizeof(b));
                           float b_1[4] = {};
                           for(uint k = 0; k < 4; k++) {
                               b_1[k] = (float)(b[k]-'0');
                           }

                           ImGui::PopItemWidth();
                           ImGui::NewLine();
                           ImGui::PushItemWidth(100.0f);
                           ImGui::SameLine();
                           ImGui::InputText("A", a, sizeof(a));
                           float a_1[4] = {};
                           for(uint m = 0; m < 4; m++) {
                               a_1[m] = (float)(a[m]-'0');
                           }
                           ImGui::PopItemWidth();
                       }

                       if(get_curr_model_enum() == COLOR_MODEL::HSV_MODEL && model_selected == 2) {
                           static char hue[4] = {};
                           static char saturation[4] = {};
                           static char value[4] = {};
                           ImGui::NewLine();
                           ImGui::PushItemWidth(100.0f);
                           ImGui::SameLine();
                           ImGui::InputText("H", hue, sizeof(hue));
                           ImGui::PopItemWidth();
                           ImGui::NewLine();
                           ImGui::PushItemWidth(100.0f);
                           ImGui::SameLine();
                           ImGui::InputText("S", saturation, sizeof(saturation));
                           ImGui::PopItemWidth();
                           ImGui::NewLine();
                           ImGui::PushItemWidth(100.0f);
                           ImGui::SameLine();
                           ImGui::InputText("V", value, sizeof(value));
                           ImGui::PopItemWidth();
                       }

                       if(get_curr_model_enum() == COLOR_MODEL::HSL_MODEL && model_selected == 3) {
                           static char hue[4] = {};
                           static char saturation[4] = {};
                           static char lightnesss[4] = {};
                           ImGui::NewLine();
                           ImGui::PushItemWidth(100.0f);
                           ImGui::SameLine();
                           ImGui::InputText("H", hue, sizeof(hue));
                           ImGui::PopItemWidth();
                           ImGui::NewLine();
                           ImGui::PushItemWidth(100.0f);
                           ImGui::SameLine();
                           ImGui::InputText("S", saturation, sizeof(saturation));
                           ImGui::PopItemWidth();
                           ImGui::NewLine();
                           ImGui::PushItemWidth(100.0f);
                           ImGui::SameLine();
                           ImGui::InputText("L", lightnesss, sizeof(lightnesss));
                           ImGui::PopItemWidth();
                       }

                       if(get_curr_model_enum() == COLOR_MODEL::CMYK_MODEL && model_selected == 4) {
                           static char cyan[4] = {};
                           static char magenta[4] = {};
                           static char yellow[4] = {};
                           static char key[4] = {};
                           ImGui::NewLine();
                           ImGui::PushItemWidth(100.0f);
                           ImGui::SameLine();
                           ImGui::InputText("C", cyan, sizeof(cyan));
                           ImGui::PopItemWidth();
                           ImGui::NewLine();
                           ImGui::PushItemWidth(100.0f);
                           ImGui::SameLine();
                           ImGui::InputText("M", magenta, sizeof(magenta));
                           ImGui::NewLine();
                           ImGui::PushItemWidth(100.0f);
                           ImGui::SameLine();
                           ImGui::InputText("Y", yellow, sizeof(yellow));
                           ImGui::PopItemWidth();
                           ImGui::NewLine();
                           ImGui::PushItemWidth(100.0f);
                           ImGui::SameLine();
                           ImGui::InputText("K", key, sizeof(key));
                           ImGui::PopItemWidth();
                       }

                       if(get_curr_model_enum() == COLOR_MODEL::ARGB_MODEL && model_selected == 5) {
                           static char r[5] = {};
                           static char g[5] = {};
                           static char b[5] = {};
                           ImGui::NewLine();
                           ImGui::PushItemWidth(100.0f);
                           ImGui::SameLine();
                           ImGui::InputText("R", r, sizeof(r));
                           ImGui::PopItemWidth();
                           ImGui::NewLine();
                           ImGui::PushItemWidth(100.0f);
                           ImGui::SameLine();
                           ImGui::InputText("G", g, sizeof(g));
                           ImGui::PopItemWidth();
                           ImGui::NewLine();
                           ImGui::PushItemWidth(100.0f);
                           ImGui::SameLine();
                           ImGui::InputText("B", b, sizeof(b));
                           ImGui::PopItemWidth();
                       }

                       if(get_curr_model_enum() == COLOR_MODEL::EIGHT_BIT_RGB_MODEL && model_selected == 6) {
                           static char eight_bit_r[4] = {};
                           static char eight_bit_g[4] = {};
                           static char eight_bit_b[4] = {};
                           ImGui::NewLine();
                           ImGui::PushItemWidth(100.0f);
                           ImGui::SameLine();
                           ImGui::InputText("R", eight_bit_r, sizeof(eight_bit_r));
                           ImGui::PopItemWidth();
                           ImGui::NewLine();
                           ImGui::PushItemWidth(100.0f);
                           ImGui::SameLine();
                           ImGui::InputText("G", eight_bit_g, sizeof(eight_bit_g));
                           ImGui::PopItemWidth();
                           ImGui::NewLine();
                           ImGui::PushItemWidth(100.0f);
                           ImGui::SameLine();
                           ImGui::InputText("B", eight_bit_b, sizeof(eight_bit_b));
                           ImGui::PopItemWidth();
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
};

#endif