#pragma once
#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H
#include<GLFW/glfw3.h>
#include<spdlog/spdlog.h>

class InputMG {
    private:
        static InputMG* manager_instance;
        InputMG() {}

    public:
        static InputMG* getManagerInstance() {
            if(!manager_instance) manager_instance = new InputMG; return manager_instance;
        }
        static bool isPressed(GLFWwindow* window, int key);
        static bool isHeld(GLFWwindow* window, int key);
        static bool isReleased(GLFWwindow* window, int key);
};
#endif
