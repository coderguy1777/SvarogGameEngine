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
    WindowProp(int width=800, int height=600, String winTitle="Svarog Game Engine") : w(width), h(height), title(winTitle){}
};
class Window {
    private:
        WindowProp* prop;
    public:
        Window() {
            prop = new WindowProp();
        }
        // getter functions
        int getWidth();
        int getHeight();
        int * get_ptrHeight() const;
        int * get_ptrWidth() const;
        String getTitle();
        // setter functions
        void changeHeight(int h);
        void changeWidth(int w);
        void changeTitle(String newTitle);
        void* getWindow();
};
#endif
