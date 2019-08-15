#pragma once 
#ifndef APP_H
#define APP_H
#include<glad/glad.h>
#include <GLFW/glfw3.h>
#include "core/events/EventDispatch.h"
#include "main/window/window.h"
#include "core/Input/keyboard.h"
class Application {
    private: 
        bool isVsyncOn;
        GLFWwindow* appWindow;
        WindowProp window;
    public: 
        Window winA;
        bool engineState;

        // TODO, create event handler functions for classes
        static void KeyEventTrigger(GLFWwindow* window, int x, int y, int code, int scancode);
        static void MouseEventTrigger(GLFWwindow* window, int x, int y, int mousecode);
        Application(){}
        void OnUpdate();
        void FrameBufferCallBack();
        void VSYNC_on();
        void VSYNC_off();
        bool isVSYNCon();
        void makeContextCurr();
        void createWindowContext();
        void SvarogAppLoop();
};
#endif