#pragma once 
#ifndef APP_H
#define APP_H
#include<glad/glad.h>
#include <GLFW/glfw3.h>
#include "core/events/EventDispatch.h"
#include "main/window/window.h"
#include "core/Input/keyboard.h"
class Application {
    public: 
        Window winA;
        bool engineState;
        GLFWwindow* appWindow;

        Application(){};
        Application(Window w, bool eState) {
            winA = w;
            engineState = eState;
        }

        Application(GLFWwindow* window, bool eState) {
            appWindow = window;
            engineState = eState;
        }
        // getters
        Window getWindow();
        bool getLoopState();
        // setters
        void ChangeCurrWindow(const Window &win);
        void ChangeLoopState(bool newState);
        // window context
        void createWindowContext();
        void SvarogAppLoop();
        void processInput();
};
#endif