#pragma once
#ifndef WINDOW_H
#define WINDOW_H
#include <GLFW/glfw3.h>
#include "core/String.h"
#include "core/events/Event.h"
#define GLFWFAILSTATE -1
#define GLFWGOODSTATE 0
struct WindowProp {
    int w, h;
    String title;
    WindowProp(int width, int height, String winTitle="Svarog Game Engine") : w(width), h(height), title(winTitle){}
};
class Window {
    private:
        uint width, height;
        const char* title;
    public:
        GLFWwindow* m_window;

        Window();
        Window(uint w, uint h, const char* title);
        void* get_window() const;
        uint get_window_width() const;
        uint get_win_height() const;
        const char* get_win_title() const;
};
#endif
