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
    public: 
        Window winA;
        bool engineState;

        Application(){}
        Application(Window w, bool eState):
            winA(w), engineState(eState)
        {}

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