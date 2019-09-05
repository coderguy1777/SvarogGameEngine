#pragma once 
#ifdef APP_H
#define APP_H
#endif
#include<glad/glad.h>
#include <GLFW/glfw3.h>
#include "main/shapes/shape.h"
#include "core/events/event-listeners/EventListener.h"
#include "core/events/event-dispatchers/KeyEventDispatcher.h"
#include "main/materials/material.h"
#include "core/ds-classes/Array.h"
#include "core/events/event-types/mouseevent.h"
#include "core/events/event-types/keyevent.h"
#include "core/events/event-dispatchers/EventDispatch.h"
#include "main/window/window.h"
#include "render-pipeline/window-initalization/window_context.h"
#include "render-pipeline/window-initalization/window_update.h"
#include "render-pipeline/window-initalization/glad_loader.h"

class Application {
    private:
        mutable bool engine_state;
    public: 
        Window winA;
        bool engineState;
        Application(){}

        ~Application() {
            end();
        }

        void* getWindow() {return appWindow;};
        void reset_bool_state() {
            engine_state = false;
        }
        void set_bool_state() {
            engine_state = true;
        }
        bool get_state() const { 
            return engine_state;
        }
        void end();
        void OnUpdate();
        void VSYNC_on();
        void VSYNC_off();
        void glad_tst();
        bool isVSYNCon();
        void VSYNC_func();
        void makeContextCurr();
        void createWindowContext();
        void SvarogAppLoop();

    private: 
        bool isVsyncOn;
        GLFWwindow* appWindow;
        WindowProp window;
};