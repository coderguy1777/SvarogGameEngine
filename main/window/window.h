#pragma once
#ifndef WINDOW_H
#define WINDOW_H
#include <GLFW/glfw3.h>
#include "core/String.h"
#define GLFWFAILSTATE -1
#define GLFWGOODSTATE 0
class Window {
    public:
        int GLAD_STATE = 0;
        int width, height;
        String windowTitle;
        Window(int w, int h, String title) {
            width = w;
            height = h;
            windowTitle = title;
        }
        Window(){};

        void * operator new(size_t size) {
            void * p = new ::Window();
            return p;
        }
        // getter functions
        int getWidth() const;
        int getHeight() const;
        String getTitle() const;
        // setter functions
        void changeHeight(int h);
        void changeWidth(int w);
        void changeTitle(String newTitle);

        // glfw window setup
        GLFWwindow* initliazeWindow();
};
#endif
