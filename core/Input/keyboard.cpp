#include "keyboard.h"
bool Keyboard::isKeyPressed(GLFWwindow* window, int keystate) {
    return (glfwGetKey(window, keystate) == GLFW_PRESS) ? true : false;
}

bool Keyboard::isKeyReleased(int keystate) {
    return (glfwGetKey(keywin, keystate) == GLFW_RELEASE) ? true : false;
}

bool Keyboard::isKeyRepeat(int keystate) {
    return (keystate==2) ? true : false;
}

int Keyboard::getKeyCode(int key) {
    return key;
}

bool Keyboard::checkKeyPressed(int keycode) {
    return (glfwGetKey(winNN.initliazeWindow(), keycode) == GLFW_PRESS) ? true : false;
}

bool Keyboard::checkKeyReleased(int keycode) {
    return (glfwGetKey(winNN.initliazeWindow(), keycode) == GLFW_RELEASE) ? true : false;
}

bool Keyboard::checkKeyRepeat(int keycode) {
    return (glfwGetKey(winNN.initliazeWindow(), keycode) == GLFW_REPEAT) ? true : false;
}

bool Keyboard::keyPress(GLFWwindow* window) {
    auto windowKey = window;
    auto keyVal = SVAROG_KEY_A;
    auto state = glfwGetKey(windowKey, keyVal);
    return state == GLFW_PRESS || state == GLFW_RELEASE;
}