#include "app.h"
SvarogWindow::Window SvarogApplication::Application::getWindow() const {
    return winA;
}

bool SvarogApplication::Application::getLoopState() const {
    return engineState;
}

void SvarogApplication::Application::ChangeLoopState(bool newState) {
    engineState = newState;
}

void SvarogApplication::Application::ChangeCurrWindow(SvarogWindow::Window newWin) {
    winA = newWin;
}

void framebuffersizecallback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void SvarogApplication::Application::createWindowContext() {
    glfwMakeContextCurrent(appWindow);
    glfwSetFramebufferSizeCallback(appWindow, framebuffersizecallback);

    if(appWindow == NULL) {
        glfwTerminate();
    }

    if(winA.getGladState() == -1) {
        glfwTerminate();
    }

}

void SvarogApplication::Application::SvarogAppLoop() {
    if(engineState) {
        while(!(glfwWindowShouldClose(appWindow))) {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glClearColor(1.0, 0.0, 0.0, 1.0);
            glfwSwapBuffers(appWindow);
            glfwPollEvents();
        }
    }

    if(!engineState) {
        glfwTerminate();
    }
}