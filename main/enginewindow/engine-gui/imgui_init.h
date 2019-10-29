#pragma once 
#ifndef IMGUI_INIT_H
#define IMGUI_INIT_H
#include "libraries/SvarogGameEngine-Gui/imgui.h"
#include "libraries/SvarogGameEngine-Gui/examples/imgui_impl_glfw.h"
#include "libraries/SvarogGameEngine-Gui/examples/imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>

class ImGuiInit {
    private: 
        static bool is_loaded;
    public: 
        enum GUI_STYLE {
            STYLE_DARK = 0,
            STYLE_LIGHT = 1,
            STYLE_NONE = 2,
        };
        static void imgui_ini_use(bool is_used);
        static void make_imgui_context(GLFWwindow* window, const char* glsl_v);
        static void make_imgui_style(unsigned int style);
        static void init_imgui_frames();
        static void init_imgui_render();
        static void init_imgui_shutdown();
        static bool load_state();
};

#endif 