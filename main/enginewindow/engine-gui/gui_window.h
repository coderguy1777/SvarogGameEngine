#pragma once
#ifndef GUI_WINDOW_H
#define GUI_WINDOW_H
#include "gui_frames.h"
#include "math/vec2.h"
#include "core/ds-classes/Stack.h"
enum class GUI_WINDOW_POS {
    TOP_RIGHT_CORNER,
    MIDDLE_RIGHT,
    BOTTOM_RIGHT_CORNER,
    BOTTOM,
    BOTTOM_LEFT_CORNER,
    MIDDLE_LEFT,
    TOP_LEFT_CORNER,
    TOP,
    CENTER
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

        struct SvarogGuiWindow_Flags {
            private:
                bool is_rendered;
                bool is_deleted;
            public: 
                void set_render_state(int state) {
                    is_rendered = (state == 1) ? true : false;
                }

                void set_delete_state(int state) {
                    is_deleted = (state == 1) ? true : false;
                }

        } gui_window_flags;
        Stack<SvarogGuiFrame>frame_stack;
    public: 
        void insert_to_stack(SvarogGuiFrame gui_frame);
        void render_frames();
};
#endif