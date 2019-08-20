#include "main/enginewindow/enginewindow.h"
#include "WindowMouseInput.h"
Application* app;
bool WindowMouseInput::isPressed(int mouse) {
    auto window = static_cast<GLFWwindow*>(app->getWindow());
    auto mouseState = glfwGetMouseButton(window, mouse);
    return mouseState == GLFW_PRESS;
}

bool WindowMouseInput::isReleased(int mouse) {
    auto window = static_cast<GLFWwindow*>(app->getWindow());
    auto mouseState = glfwGetMouseButton(window, mouse);
    return mouseState == GLFW_RELEASE;
}

bool WindowMouseInput::isHeld(int mouse) {
    auto window = static_cast<GLFWwindow*>(app->getWindow());
    auto mouseState = glfwGetMouseButton(window, mouse);
    return mouseState == GLFW_REPEAT;
}

std::pair<double, double> WindowMouseInput::getmouseCoords() {
    auto window = static_cast<GLFWwindow*>(app->getWindow());
    glfwGetCursorPos(window, &x, &y);
    return std::pair<double, double>(x, y);
}