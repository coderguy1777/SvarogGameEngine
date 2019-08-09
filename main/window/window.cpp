#include "window.h"

int SvarogWindow::Window::getWidth() const {
    return width;
}

int SvarogWindow::Window::getHeight() const {
    return height;
}

int SvarogWindow::Window::getGladState() const {
    return GLAD_STATE;
}

String SvarogWindow::Window::getTitle() const {
    return windowTitle;
}

bool SvarogWindow::Window::isGladLoaded() {
    bool isLoaded = NULL;
    if(GLAD_STATE == 0) {
        isLoaded = true;
    }

    if(GLAD_STATE == -1) {
        isLoaded = false;
    }
    return isLoaded;
}

void SvarogWindow::Window::changeWidth(int w) {
    width = w;
}

void SvarogWindow::Window::changeHeight(int h) {
    height = h;
}

void SvarogWindow::Window::changeTitle(String newTitle) {
    windowTitle = newTitle;
}

GLFWwindow* SvarogWindow::Window::initliazeWindow() {
    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_ANY_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow* svarogWindow = glfwCreateWindow(getWidth(), getHeight(), windowTitle.str, NULL, NULL);
    return svarogWindow;
}