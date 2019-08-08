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

void framebuffersizecallback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
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
    if(engineState) {
        while(!(glfwWindowShouldClose(appWindow))) {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glClearColor(1.0, 0.0, 0.0, 1.0);
            glUseProgram(shaderToUse());
            glfwSwapBuffers(appWindow);
            glfwPollEvents();
        }
        glfwTerminate();
    }

    if(!engineState) {
        glfwTerminate();
    }
}

Material  Application::getInputShader(int index) {
    return wantedShaders.get(index);
}

void Application::setInputShader(int listIndex, Material material) {
    wantedShaders.set(listIndex, material);
}

ArrayList<Material>Application::getShaderli() const {
    return wantedShaders;
}

unsigned int Application::shaderToUse() {
    unsigned int shaderLI = 0;
    if(wantedShaders.size() == 1) {
        shaderLI = wantedShaders.get(0).shaderID;
    } else {
        shaderLI = 0;
    }
    return shaderLI;
}