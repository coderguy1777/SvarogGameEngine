#pragma once 
#ifdef APP_H
#define APP_H
#endif
#include<glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <spdlog/spdlog.h>
#include "core/ds-classes/Queue.h"
#include "main/shapes/shape.h"
#include "core/events/Event.h"
#include "core/Input/WindowInput.h"
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
#include "render-pipeline/window-initalization/window_monitor.h"
#include "render-pipeline/window-initalization/glad_loader.h"

class EngineWindow {
    private:
        bool isVsyncOn;
        GLFWwindow* appWindow;
        GLFWmonitor* moni;
        WindowInput* Input = WindowInput::getSingleton();
        WindowProp window;
        static EngineWindow* winn;
        mutable bool engine_state;
        EngineWindow() {}

    public: 

        Window winA;

        ~EngineWindow() {
            end();
        }

        static EngineWindow* getInstance();
        void* getWindow();
        void reset_bool_state();

        int call_back(int a) {
            return a;
        }

        void test(int a) {
            if(Input->isKeyPressed(a)) {
                spdlog::info("Key pressed: {}", a);
            }
        }
        void set_bool_state();
        bool get_state() const;
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
};