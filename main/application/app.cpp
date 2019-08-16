#include "app.h"
void Application::createWindowContext() {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_ANY_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void Application::OnUpdate() {
    glfwPollEvents();
    glfwSwapBuffers(appWindow);
}

void Application::FrameBufferCallBack() {
    glfwGetFramebufferSize(appWindow, &winA.prop->w, &winA.prop->h);
    glViewport(0, 0, winA.prop->w, winA.prop->h);
}

void Application::VSYNC_on() {
    isVsyncOn = true;
}

void Application::VSYNC_off() {
    isVsyncOn = false;
}

bool Application::isVSYNCon() {
    return isVsyncOn;
}

void Application::makeContextCurr() {
    glfwMakeContextCurrent(appWindow);
}

void Application::SvarogAppLoop() {
    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif
    glfwInit();
    createWindowContext();
    appWindow = glfwCreateWindow((int)winA.prop->w, (int)winA.prop->h, (const char*)winA.prop->title.str, NULL, NULL);
    makeContextCurr();

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

    auto vsync_check = isVSYNCon();
    if(vsync_check) {
        glfwSwapInterval(1);
    } else if(!vsync_check) {
        glfwSwapInterval(0);
    }

    Material matA("/home/jordan/Documents/SvarogGameEngine/main/shaders/VertexShader.glsl", "/home/jordan/Documents/SvarogGameEngine/main/shaders/FragmentShader.glsl");
            
    float vertices[] = {
        0.5f,  0.5f, 0.0f, 
        0.5f, -0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        -0.5f, 0.5f, 0.0f 
    };

    float vertices2[] = {
        1.0,  1.5f, 0.0f, 
        0.5f, -0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        -0.5f, 0.5f, 0.0f 
    };


    unsigned int pos[] = {  
        0, 1, 3,  
        1, 2, 3   
    };
    
    unsigned int pos2[] = {  
        0, 1, 3,  
        1, 2, 3   
    };
    
    Array<int>arrayTest(20);
    int len = arrayTest.length();
    if(len > 0) {
        std::cout << "Array works" << std::endl;
    } else {
        std::cout << "Array failed " << std::endl;
    }

    int * p = arrayTest.returnArray();
    if(p != NULL) {
        std::cout << "Array returned" << std::endl;
    }
    delete p;

    arrayTest.add(2);
    arrayTest.add_pos(213, 3);
    int * g = arrayTest.returnArray();
    for(int i = 0; i < 21; i++) {
        std::cout << g[i] << std::endl;
    }
    delete g;
    Shape drawer2(vertices, pos);
    drawer2.useEBO();
    while(!glfwWindowShouldClose(appWindow)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(1.0, 0.0, 0.0, 1.0);
        FrameBufferCallBack();
        glUseProgram(matA.shaderID);
        drawer2.draw();
        OnUpdate();
    }
    glfwTerminate();
}