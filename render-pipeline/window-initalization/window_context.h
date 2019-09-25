#pragma once
#ifndef WINDOW_CONTEXT_H
#define WINDOW_CONTEXT_H
#include "render-pipeline/window-initalization/glad_loader.h"
#include "render-pipeline/gl_libs.h"

enum Window_Attributes {
    IS_RESIZE = 1,
    NON_RESIZE = 2,
    OPENGL_V3 = 3,
    OPENGL_V4 = 4,
    OPENGL_V2 = 5,
    OPENGL_V1 = 6
};

class WindowContext {
    private:
        unsigned int RESIZE_V;
        unsigned int OPENGL_V;
        GLFWwindow* context_win;
        int glfw_success;
        int glad_success;
        WindowContext(){}
    public: 
        static WindowContext* getContextInstance();
        static void set_context_win(GLFWwindow* window);
        void* get_context_win() const;
        static void create_context(GLFWwindow* win);
        static void make_curr_context(GLFWwindow* win);
        static void init_glfw();
        static void load_gpu_info();
        static void set_states(unsigned int RESIZE_INT, unsigned int OPENGL_V);
        static bool get_resize();
        static unsigned int get_opengl_val();
        int get_glad_state() const;
        int get_glfw_load_state() const;


    private: 
        static WindowContext* context_instance;
};

#endif