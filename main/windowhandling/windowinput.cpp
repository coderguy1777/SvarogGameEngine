#include "windowinput.h"
Window SvarogWindowInput::WindowInput::keywindow() const {
    return keyWindow;
}

bool SvarogWindowInput::WindowInput::isCurrKeyPressed(Key key) {
    bool isPressed = NULL;
    if(glfwGetKey(keyWin, key.code) == GLFW_PRESS) {
        isPressed = true;
    } else if(!glfwGetKey(keyWin, key.code) == GLFW_PRESS) {
        isPressed = false;
    }
    return isPressed;
}

bool SvarogWindowInput::WindowInput::isCurrKeyReleased(Key key) {
    bool isReleased = NULL;
    if(glfwGetKey(this->keyWin, key.code) == GLFW_RELEASE) {
        isReleased = true;
    } else if(!glfwGetKey(keyWin, key.code) == GLFW_RELEASE) {
        isReleased = false;
    }
}