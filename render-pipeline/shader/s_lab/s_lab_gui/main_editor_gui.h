#pragma once
#ifndef MAIN_EDITOR_GUI_H
#define MAIN_EDITOR_GUI_H
#include <map>
#include <stack>
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
        struct EditorGuiFrames {
            std::vector<SvarogGuiFrame>gui_frames;
            std::vector<uint>gui_state_order; // for ideas of making different parts of the editor visible, etc.
            uint curr_state; // for finding the current state of the editor, which window is opened.
        } s_lab_gui_frames;

        COLOR_MODEL color_model_curr;
        String curr_color_label;
        std::stack<SvarogGuiWindow>slab_gui_editor_windows;
        SvarogMaterial* curr_material;
    public: 
        String get_color_label() const;
        COLOR_MODEL get_current_color_model() const;
        void edit_material();
        void color_model_selection(COLOR_MODEL c_model);
        void init_editor();
        void switch_editor_state(S_LAB_STATE editor_window_to_open);
        void init_editor_window_gui_frames();
};

#endif