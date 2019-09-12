#include "WindowInput.h"
#include "main/enginewindow/enginewindow.h"
EngineWindow* app = EngineWindow::getInstance();

Keyboard* Keyboard::input_instace = new WindowInput();

WindowInput* WindowInput::getSingleton() {
    if(!InputManager) InputManager = new WindowInput; return InputManager;
}

bool WindowInput::checkKeyPressed(int keystate) {
    auto key_needed = keystate;
    auto appWin = static_cast<GLFWwindow*>(EngineWindow::getInstance()->getWindow());
    auto key = glfwGetKey(appWin, keystate);
    return (key == GLFW_PRESS) || (key == GLFW_RELEASE);
}

bool WindowInput::checkKeyReleased(int keystate) {
    auto appWin = static_cast<GLFWwindow*>(app->getWindow());
    auto key = glfwGetKey(appWin, keystate);
    return key == GLFW_RELEASE;
}

bool WindowInput::checkKeyHeld(int keystate) {
    auto appWin = static_cast<GLFWwindow*>(app->getWindow());
    auto key = glfwGetKey(appWin, keystate);
    return key == GLFW_REPEAT;
}

bool WindowInput::checkKeyRepeat(int keystate) {
    auto appWin = static_cast<GLFWwindow*>(app->getWindow());
    auto key = glfwGetKey(appWin, keystate);
    return key == GLFW_REPEAT;
}

WindowInput *WindowInput::InputManager = 0;