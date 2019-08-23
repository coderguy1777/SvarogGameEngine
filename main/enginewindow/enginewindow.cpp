#include "enginewindow.h"
#include "core/events/Event.h"
#define HOLD 4
float x = 0.0f;
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

void Application::end() {
    glfwDestroyWindow(appWindow);
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
        0.5f,  0.5f, -0.5f, 
        0.5f, -0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,
        -0.5f, 0.5f , -0.5f, 
        0.5f, -0.5f , 0.5f, 
        0.5f, 0.5f , 0.5f, 
    };        
    
    unsigned int poss[] = {  
        0, 1, 3,  
        1, 2, 3,
        0, 1, 2,
    };

    std::vector<float>vertexdata;
    std::vector<unsigned int>posdata;
    std::cout << poss[1] << std::endl;
    for(int i = 0; i < 18; i++) {
        vertexdata.push_back(vertices[i]);
    }

    for(int j = 0; j < 9; j++) {
        posdata.push_back(poss[j]);
    }

    Shape drawer2(vertexdata, posdata);
    drawer2.noEBO();
    
    // TODO: start mouse functionallity event basic, and also fix seg. faults
    // on keyevent log.
    glfwSetKeyCallback(appWindow, [](GLFWwindow* window, int key, int action, int scancode, int mods) {
        switch(scancode) {
            case GLFW_PRESS:
                {   
                    Event e(EVENT_TYPE::KeyEvt, 10, "key_press");
                    KeyEvent evt(static_cast<int>(key), 'A');
                    std::cout << evt.get_keybind_ascii_code() << std::endl;
                    String ab(evt.logKeyPressEvent(e, static_cast<int>(GLFW_PRESS)));
                    break;
                }
            case GLFW_REPEAT:
                {
                    std::cout << "Key Repeat" << std::endl;
                    break;
                }
            case GLFW_RELEASE:
                {
                    std::cout << "Key Release" << std::endl;
                }
            case HOLD:
                {
                    std::cout << "Key has been held" << std::endl;
                }
        }
    });

    // TODO: add functionality for mouse events, etc.
    glfwSetMouseButtonCallback(appWindow, [](GLFWwindow* window, int mousebtn, int action, int scancode) {
        if(glfwGetMouseButton(window, mousebtn) == GLFW_PRESS) {
            std::cout << "Mouse button pressed" << std::endl;
        }
    });

    while(!glfwWindowShouldClose(appWindow)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(1.0, 0.0, 0.0, 1.0);
        FrameBufferCallBack();
        matA.setFloat("xPOs", 0.5f);
        drawer2.drawFunc();
        glUseProgram(matA.shaderID);
        OnUpdate();
    }
    glfwTerminate();
}