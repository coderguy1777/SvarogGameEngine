#pragma once
#ifndef MAIN_EDITOR_GUI_H
#define MAIN_EDITOR_GUI_H
#include <map>
#include <stack>
#include "spdlog/spdlog.h"
#include "main/enginewindow/engine-gui/gui_frames.h"
#include "main/enginewindow/engine-gui/gui_layer.h"
#include "main/enginewindow/engine-gui/gui_window.h"

class SLabEditorGUI {
    private:    
        struct EditorGuiFrames {
            std::vector<SvarogGuiFrame>gui_frames;
            std::vector<uint>gui_state_order; // for ideas of making different parts of the editor visible, etc.
            uint curr_state; // for finding the current state of the editor, which window is opened.
        } s_lab_gui_frames;

        std::stack<SvarogGuiWindow>slab_gui_editor_windows;
    public: 
        void init_editor();
        void switch_editor_state(uint editor_window_to_open);
        void init_editor_window_gui_frames();
};

#endif