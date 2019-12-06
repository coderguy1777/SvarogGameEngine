#pragma once
#ifndef GUI_WINDOW_H
#define GUI_WINDOW_H
#include "gui_frames.h"
#include "math/vec2.h"
#include "core/ds-classes/Stack.h"
enum class GUI_WINDOW_POS {
    TOP_RIGHT_CORNER,//
    MIDDLE_RIGHT,// 
    BOTTOM_RIGHT_CORNER, //
    BOTTOM, // 
    BOTTOM_LEFT_CORNER, ///
    MIDDLE_LEFT, //
    TOP_LEFT_CORNER, // (0, 0) for pos.
    TOP, // (middle screen width/height avg, 0)
    CENTER // will most likely be at (screen_w/2, screen_h/2), and will have to be scaled to be perfectly center 
};

class SvarogGuiWindow {
    private:
        struct SvarogGuiWindow_Styles  {
            Vector2 win_size;
            Vector2 win_pos;
            Rgb color_win;
            bool display_title;
            GUI_WINDOW_POS frame_pos;
        } gui_window_styles;
        Stack<SvarogGuiFrame>frame_stack;
    public: 
        Stack<SvarogGuiFrame>get_frame_stack() const;
        void set_title_state(uint title);
        void set_window_pos();
        void insert_to_stack(SvarogGuiFrame gui_frame);
        void render_frames();
        Vector2 get_window_pos() const;
        Vector2 get_window_size() const;
};
#endif