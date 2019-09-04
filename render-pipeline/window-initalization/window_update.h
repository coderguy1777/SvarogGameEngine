#pragma once
#ifndef WINDOW_UPDATE_H
#define WINDOW_UPDATE_H
#include "render-pipeline/gl_libs.h"
class WindowUpdate {
    private:
        GLFWwindow* window;
    public:
        void set_win(GLFWwindow* update_win);
        static void window_buffer_swap(GLFWwindow* window);
        void* get_update_win();
};

#endif
