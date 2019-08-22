#include "WindowInput.h"
#include "main/enginewindow/enginewindow.h"
Application* app;
bool WindowInput::checkKeyPressed(int keystate) {
    auto appWin = static_cast<GLFWwindow*>(app->getWindow());    
    auto key = glfwGetKey(appWin, keystate);
    return key == GLFW_PRESS || key == GLFW_RELEASE;
}

bool WindowInput::checkKeyReleased(int keystate) {
    auto appWin = static_cast<GLFWwindow*>(app->getWindow());
    auto key = glfwGetKey(appWin, keystate);
    return key == GLFW_RELEASE;
}

bool WindowInput::checkKeyHeld(int keystate) {
    auto appWin = static_cast<GLFWwindow*>(app->getWindow());
    auto key = glfwGetKey(appWin, keystate);
    return key == GLFW_REPEAT || key==GLFW_PRESS;
}

bool WindowInput::checkKeyRepeat(int keystate) {
    auto appWin = static_cast<GLFWwindow*>(app->getWindow());
    auto key = glfwGetKey(appWin, keystate);
    return key == GLFW_REPEAT;
}