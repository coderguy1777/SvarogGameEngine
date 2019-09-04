#pragma once
#ifndef WINDOW_CONTEXT_H
#define WINDOW_CONTEXT_H
#include "render-pipeline/gl_libs.h"

class WindowContext {
    private:
        GLFWwindow* context_win;
        int glfw_success;
        int glad_success;
    public: 
        static void set_context_win(GLFWwindow* window);
        void* get_context_win() const;
        static void create_context(GLFWwindow* win);
        static void make_curr_context(GLFWwindow* win);
        static void init_glfw();
        static void init_glad();
        int get_glad_state() const;
        int get_glfw_load_state() const;

    private: 
        static WindowContext* context_instance;
};

#endif