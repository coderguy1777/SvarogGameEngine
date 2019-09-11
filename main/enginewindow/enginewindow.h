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
#include "core/Input/InputManager.h"

class EngineWindow {
    private:
        bool isVsyncOn;
        GLFWwindow* appWindow;
        GLFWmonitor* moni;
        WindowInput* Input = WindowInput::getSingleton();
        WindowProp window;
        static EngineWindow* winn;
        int state;
        mutable bool engine_state;
        EngineWindow() {}

    public: 

        Window winA;

        ~EngineWindow() {
            end();
        }


        void set_state(int state_w) {
            state = state_w;
        }

        static EngineWindow* getInstance();
        static WindowInput* getInputInstance();

        bool InputTest(int key) {
            return Input->isKeyPressed(key) == GLFW_PRESS && key == 32;
        }

        void* getWindow();
        void reset_bool_state();

        void app_tst() {
            auto win = static_cast<GLFWwindow*>(getWindow());
            auto is_pressed = glfwGetKey(win, 32);
            if(is_pressed) {
                std::cout << "yes" << std::endl;
            }
        }

        int call_back(int a) {
            return a;
        }

        void test2() {
            if(InputManager::isPressed(static_cast<GLFWwindow*>(this->getWindow()), 119)) {
                std::cout << "yes'\n'";
            }
        }
        
        void test(int a) {
            if(a == 32) {
                bool tester = Input->isKeyPressed(a);
                if(tester) {
                    std::cout << "Works" << std::endl;
                    std::cout << this->state << std::endl;
                }
            }
        }

        int get_key_state() const {
            return state;
        }

        int key_cb(int key) {
            state = key;
            return key;
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