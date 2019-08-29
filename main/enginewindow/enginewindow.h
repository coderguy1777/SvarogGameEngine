#pragma once 
#ifdef APP_H
#define APP_H
#endif
#include<glad/glad.h>
#include <GLFW/glfw3.h>
#include "core/ds-classes/Array.h"
#include "core/events/event-types/keyevent.h"
#include "core/events/EventDispatch.h"
#include "main/window/window.h"
class Application {
    private:
        Array<Event, 10>event_queue_key;
        Array<Event, 10>event_queue_mouse;
        Array<Event, 10>event_queue_window; 
    public: 
        Window winA;
        bool engineState;
        void* getWindow() {return appWindow;};
        // TODO, create event handler functions for classes
        Application(){}
        ~Application() {
            end();
        }
        int tst() {
            return 2;
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