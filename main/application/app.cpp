#include "app.h"
Window Application::getWindow() const {
    return winA;
}

bool Application::getLoopState() const {
    return engineState;
}

void Application::ChangeLoopState(bool newState) {
    engineState = newState;
}

void Application::ChangeCurrWindow(Window newWin) {
    winA = newWin;
}

void framebuffersizecallback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void Application::SvarogAppLoop() {
    // frame buffer
    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_ANY_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    appWindow = glfwCreateWindow(winA.width, winA.height, winA.windowTitle.str, NULL, NULL);
    glfwMakeContextCurrent(appWindow);
    glfwSetFramebufferSizeCallback(appWindow, framebuffersizecallback);

    if(appWindow == NULL) {
        cout << "SVAROG_WINDOW IS NULL, ENDING NOW" << endl;
        glfwTerminate();
    }
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        throw std::invalid_argument("GLAD FAILURE.");
        winA.GLAD_STATE = GLFWFAILSTATE;
        glfwTerminate();
    } else {
        cout << "GLAD SUCCESS TO LOAD." << endl;
        winA.GLAD_STATE = GLFWGOODSTATE;
    }
    Material matB("/home/jordan/Documents/SvarogGameEngine/shaders/VertexShader.glsl", "/home/jordan/Documents/SvarogGameEngine/shaders/FragementShader.glsl");

    // vert test
	float vertices[] = {-0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f,0.0f,  0.5f, 0.0f     }; 
    int pos[] = {0, 0, 0,0, 0, 0,};
    
    Shape drawer2(vertices, pos);
    while(!glfwWindowShouldClose(appWindow)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(1.0, 0.0, 0.0, 1.0);
        glUseProgram(matB.shaderID);
        drawer2.draw();
        glfwSwapBuffers(appWindow);
        glfwPollEvents();
    }
    glfwTerminate();
}