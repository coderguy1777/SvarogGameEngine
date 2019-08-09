#include "app.h"
SvarogWindow::Window Application::getWindow() const {
    return winA;
}

bool Application::getLoopState() const {
    return engineState;
}

void Application::ChangeLoopState(bool newState) {
    engineState = newState;
}

void Application::ChangeCurrWindow(SvarogWindow::Window newWin) {
    winA = newWin;
}

void Application::createWindowContext() {
    glfwMakeContextCurrent(appWindow);
    glfwSetFramebufferSizeCallback(appWindow, framebuffersizecallback);

    if(appWindow == NULL) {
        glfwTerminate();
    }

    if(winA.getGladState() == -1) {
        glfwTerminate();
    }

}

void Application::SvarogAppLoop() {
    if(appWindow == NULL) {
        glfwTerminate();
    } 

    if(!appWindow == NULL) {
        if(engineState) {
            while(!(glfwWindowShouldClose(appWindow))) {
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                glClearColor(1.0, 0.0, 0.0, 1.0);
                glfwSwapBuffers(appWindow);
                glfwPollEvents();
            }
            glfwTerminate();
        }

        if(!engineState) {
            glfwTerminate();
        }
    }
}