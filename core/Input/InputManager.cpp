#include "InputManager.h"
bool InputMG::isPressed(GLFWwindow* window, int key) {
    auto win = static_cast<GLFWwindow*>(window);
    auto is_pressed = (glfwGetKey(window, key) == GLFW_PRESS);
    return is_pressed;
}

bool InputMG::isHeld(GLFWwindow* window, int key) {
    auto win = static_cast<GLFWwindow*>(window);
    auto is_held = (glfwGetKey(win, key) == GLFW_PRESS);
    return is_held;
}

bool InputMG::isReleased(GLFWwindow* window, int key) {
    auto win = static_cast<GLFWwindow*>(window);
    auto is_released = (glfwGetKey(win, key) == GLFW_RELEASE) ? true : false;
    return is_released;
}

InputMG *InputMG::manager_instance = 0;