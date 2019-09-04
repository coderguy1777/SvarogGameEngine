#pragma once 
#ifdef APP_H
#define APP_H
#endif
#include<glad/glad.h>
#include <GLFW/glfw3.h>
#include "main/shapes/shape.h"
#include "core/events/event-listeners/EventListener.h"
#include "core/events/EventDispatchers/KeyEventDispatcher.h"
#include "main/materials/material.h"
#include "core/ds-classes/Array.h"
#include "core/events/event-types/mouseevent.h"
#include "core/events/event-types/keyevent.h"
#include "core/events/EventDispatchers/EventDispatch.h"
#include "main/window/window.h"
class Application {
    private:
        mutable bool state_tst;
    public: 
        Window winA;
        bool engineState;
        void* getWindow() {return appWindow;};
        // TODO, create event handler functions for classes
        Application(){}
        ~Application() {
            end();
        }
        void reset_bool_state() {
            state_tst = false;
        }
        void set_bool_state() {
            state_tst = true;
        }
        bool get_state() const { 
            return state_tst;
        }
        // engine core methods
        void end();
        void OnUpdate();
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
};