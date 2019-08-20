#pragma once 
#ifdef APP_H
#define APP_H
#endif
#include<glad/glad.h>
#include <GLFW/glfw3.h>
#include "core/Input/mousecodes.h"
#include "core/ds-classes/Array.h"
#include "core/events/EventDispatch.h"
#include "main/window/window.h"
class Application {
    public: 
        Window winA;
        bool engineState;
        void* getWindow() {return appWindow;};
        // TODO, create event handler functions for classes
        Application(){}
        ~Application() {
            end();
        }
        // engine core methods
        void end();
        void OnUpdate();
        void FrameBufferCallBack();
        void VSYNC_on();
        void VSYNC_off();
        bool isVSYNCon();
        void makeContextCurr();
        void createWindowContext();
        void SvarogAppLoop();
        private: 
            bool isVsyncOn;
            GLFWwindow* appWindow;
            WindowProp window;
            static Application* s_instance;
};