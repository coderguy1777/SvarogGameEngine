#pragma once 
#ifndef IMGUI_INIT_H
#define IMGUI_INIT_H
#include "libraries/imgui/imgui.h"
#include "libraries/imgui/imgui_internal.h"
#include "libraries/imgui/examples/imgui_impl_glfw.h"
#include "libraries/imgui/examples/imgui_impl_opengl3.h"
#if defined(IMGUI_IMPL_OPENGL_LOADER_GLAD) 
#include<glad/glad.h>
#endif
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
        static void make_imgui_context(GLFWwindow* window, const char* glsl_v);
        static void make_imgui_style(unsigned int style);
        static void init_imgui_frames();
        static void init_imgui_render();
        static void init_imgui_shutdown();
        static bool load_state();
};

#endif 