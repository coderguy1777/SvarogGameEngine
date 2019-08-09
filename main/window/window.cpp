#include "window.h"
int Window::getWidth() const {
    return width;
}

int Window::getHeight() const {
    return height;
}

String Window::getTitle() const {
    return windowTitle;
}

void Window::changeWidth(int w) {
    width = w;
}

void Window::changeHeight(int h) {
    height = h;
}

void Window::changeTitle(String newTitle) {
    windowTitle = newTitle;
}

GLFWwindow* Window::initliazeWindow() {
    GLFWwindow* svarogWindow = glfwCreateWindow(getWidth(), getHeight(), windowTitle.str, NULL, NULL);
    return svarogWindow;
}