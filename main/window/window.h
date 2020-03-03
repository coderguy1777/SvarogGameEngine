#pragma once
#ifndef WINDOW_H
#define WINDOW_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "render-pipeline/window-initalization/window_context.h"
#include "render-pipeline/window-initalization/window_monitor.h"
#include "core/Input/mousecodes.h"
#define GLFWFAILSTATE -1
#define GLFWGOODSTATE 0
class Window {
    private:
        uint width, height;
        const char* title;
    public:
        GLFWwindow* m_window;
        GLFWmonitor* m_monitor;
        Window();
        Window(uint w, uint h, const char* title);
        void* get_window() const;
        uint get_window_width() const;
        uint get_win_height() const;
        const char* get_win_title() const;
        void run_window();

    private: 
        static void set_key_callback(GLFWwindow* win, int key, int action, int scancode, int mods);
        static void set_mouse_callback(GLFWwindow* win, int button, int actions, int mods);
        static void set_window_close_callback(GLFWwindow* win);
};

#endif
