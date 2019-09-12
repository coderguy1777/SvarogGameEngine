#pragma once 
#ifdef APP_H
#define APP_H
#endif
#include<glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <spdlog/spdlog.h>
#include<spdlog/logger.h>
#include "core/ds-classes/Queue.h"
#include "main/shapes/shape.h"
#include "core/events/Event.h"
#include "core/Input/WindowInput.h"
#include "core/events/event-listeners/EventListener.h"
#include "core/events/event-dispatchers/KeyEventDispatcher.h"
#include "main/materials/material.h"
#include "core/ds-classes/Array.h"
#include "core/ds-classes/Stack.h"
#include "core/Input/keymap.h"
#include "core/events/event-types/mouseevent.h"
#include "core/events/event-types/keyevent.h"
#include "core/events/event-dispatchers/EventDispatch.h"
#include "main/window/window.h"
#include "render-pipeline/window-initalization/window_context.h"
#include "render-pipeline/window-initalization/window_update.h"
#include "render-pipeline/window-initalization/window_monitor.h"
#include "render-pipeline/window-initalization/glad_loader.h"
#include "core/Input/InputManager.h"

class EngineWindow {
    
    private:
        static EngineWindow* winn;
        WindowInput* Input = WindowInput::getSingleton();
        WindowProp window;
        GLFWwindow* appWindow;
        GLFWmonitor* moni;
        bool isVsyncOn;
        int state;
        mutable bool engine_state = true;
        EngineWindow() {
            set_bool_state();
        }

    public: 
        Window winA;
        static EngineWindow* getInstance();
        static WindowInput* getInputInstance();
        
        ~EngineWindow() {
            end();
        }

        void* getWindow();
        void reset_bool_state();
        void set_statee() {
            state = KeyMap::getMapInstance()->map_size();
        }
        int get_statee() const {
            return state;
        }
        void set_bool_state();
        bool get_state() const;
        void end();
        void OnUpdate();
        void VSYNC_on();
        int get_size();
        void VSYNC_off();
        bool isVSYNCon();
        void VSYNC_func();
        int size_mp() {
            return KeyMap::getMapInstance()->map_size();
        }
        void makeContextCurr();
        void createWindowContext();
        void SvarogAppLoop();
};