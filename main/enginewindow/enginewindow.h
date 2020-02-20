#pragma once 
#ifdef APP_H
#define APP_H
#endif
#include "main/camera/camera.h"
#include<glad/glad.h>
#include <GLFW/glfw3.h>
#include "math/vec3.h"
#include <iostream>
#include "spdlog/spdlog.h"
#include "core/ds-classes/function_list.h"
#include "core/ds-classes/Queue.h"
#include "core/events/Event.h"
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
#include "main/window/window.h"
#include "render-pipeline/window-initalization/window_update.h"
#include "render-pipeline/window-initalization/window_monitor.h"
#include "render-pipeline/window-initalization/glad_loader.h"
#include "render-pipeline/shader/VertexShader.h"
#include "render-pipeline/shader/s_lab/shader_mg.h"
#include "core/Input/InputManager.h"
class EngineWindow {    
    private:
        static EngineWindow* winn;
        WindowProp window;
        GLFWwindow* appWindow;
        GLFWmonitor* moni;
        bool isVsyncOn;
        int state;
        mutable bool engine_state;
        EngineWindow() {}

    public: 
        bool is_back;
        float x;
        const int speed = 1.0f;
        bool state_2;
        Camera init_cam; 
        Window winA;
        static EngineWindow* getInstance();
        ~EngineWindow() {
            end();
        }
        
        void* getWindow();
        void reset_bool_state();
        void set_bool_state();
        bool get_state() const;
        void end();
        void OnUpdate();
        void VSYNC_on();
        int get_size();
        void VSYNC_off();
        bool isVSYNCon();
        void VSYNC_func();
        void svarog_task_test();
        void makeContextCurr();
        void createWindowContext();
        void SvarogAppLoop();
        Camera getMainCamera() const;
        float getX()  {
            if(is_back) {
                x = -1.0f;
            } else {
                x = 0.0f;
            }
            return x;
        }    
};