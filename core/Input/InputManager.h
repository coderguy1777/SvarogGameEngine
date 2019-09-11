#pragma once
#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H
#include<GLFW/glfw3.h>
#include<spdlog/spdlog.h>

class InputManager {
    private:
        static InputManager* manager_instance;
        InputManager() {}

    public:
        static InputManager* getMangerInstance();
        static bool isPressed(GLFWwindow* window, int key);
        static bool isHeld(GLFWwindow* window, int key);
        static bool isReleased(GLFWwindow* window, int key);
};
#endif
