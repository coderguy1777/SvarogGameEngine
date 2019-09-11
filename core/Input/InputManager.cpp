#include "InputManager.h"
InputManager *InputManager::getMangerInstance() {
    if(!manager_instance) manager_instance = new InputManager; return manager_instance;
}

bool InputManager::isPressed(GLFWwindow* window, int key) {
    auto win = static_cast<GLFWwindow*>(window);
    auto is_pressed = (glfwGetKey(window, key) == GLFW_PRESS) ? true : false;
    return is_pressed;
}

bool InputManager::isHeld(GLFWwindow* window, int key) {
    auto win = static_cast<GLFWwindow*>(window);
    auto is_held = (glfwGetKey(win, key) == GLFW_PRESS) ? true : false;
    return is_held;
}

bool InputManager::isReleased(GLFWwindow* window, int key) {
    auto win = static_cast<GLFWwindow*>(window);
    auto is_released = (glfwGetKey(win, key) == GLFW_RELEASE) ? true : false;
    return is_released;
}

InputManager *InputManager::manager_instance = 0;