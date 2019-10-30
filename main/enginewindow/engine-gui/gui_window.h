#pragma once
#ifndef GUI_WINDOW_H
#define GUI_WINDOW_H
#include "gui_frames.h"
#include "core/ds-classes/Stack.h"


struct SvarogGuiFrame_Styles {
    ImVec2 win_size;
    ImVec2 win_pos;
    Layer_Pos frame_pos;
};
class SvarogGuiWindow {
    private:

        Stack<SvarogGuiFrame>frame_stack;
    public: 
        void insert_to_stack(SvarogGuiFrame gui_frame);
        void render_frames();
};
#endif