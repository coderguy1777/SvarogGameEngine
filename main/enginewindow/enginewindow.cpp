#include "enginewindow.h"
#include "core/events/Event.h"
#include "core/events/event-types/mouseevent.h"
#include "core/logger/LoggerGroup.h"
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

    glfwSetWindowUserPointer(static_cast<GLFWwindow*>(this->getWindow()), this);
    glfwSetKeyCallback(static_cast<GLFWwindow*>(this->getWindow()), [](GLFWwindow* window, int key, int action, int scancode, int mods) {
        Application* key_evt_ptr = (Application*)glfwGetWindowUserPointer(window);
        switch(scancode) {
            /*
                keep everything here, as glfw uses it
            */
            case GLFW_PRESS:
                { 
                    Event e(EVENT_TYPE::KeyEvt, 1, "key_press");
                    KeyEvent evt(static_cast<int>(key));
                    evt.logKeyPressEvent();
                    break;
                }

            case GLFW_REPEAT:
                {
                    Event e(EVENT_TYPE::KeyEvt,  1, "key_repeat");
                    KeyEvent evt(static_cast<int>(key));
                    evt.logKeyHeldEvent();
                    break;
                }

            case GLFW_RELEASE:
                {
                    Event e(EVENT_TYPE::KeyEvt, 1, "key_release");
                    KeyEvent evt(static_cast<int>(key));
                    evt.logKeyReleaseEvent();
                    break;
                }
        }
    });

    // TODO: make an event dispatching system for mouse events.
    glfwSetMouseButtonCallback(static_cast<GLFWwindow*>(this->getWindow()), [](GLFWwindow* window, int button, int action, int mods) {
        Application* mouse_evt_ptr = (Application*)glfwGetWindowUserPointer(window);
        switch(action) {
            // keep this, glfw uses GLFW_PRESS
            case GLFW_PRESS:
                {
                    Event e(EVENT_TYPE::MouseEvt, 1, "mouse_press");
                    MouseEvent evt(static_cast<int>(button), static_cast<unsigned int>(1));
                    evt.set_mse_event(e);
                    evt.set_mse_state(1);
                    evt.logMousePressEvent();
                    break;
                }

            // may need to delete, as glfw does not use repeat for mouse input.
            case GLFW_REPEAT: 
                {
                    Event e(EVENT_TYPE::MouseEvt, 2, "mouse_held");
                    MouseEvent evt(static_cast<int>(button), static_cast<unsigned int>(2));
                    evt.logMouseHeldEvent();
                    break;
                }
            // ---------------------------------------------------------

            // keep this, glfw uses GLFW_RELEASE
            case GLFW_RELEASE:
                {
                    Event e(EVENT_TYPE::MouseEvt, 3, "mouse_release");
                    MouseEvent evt(static_cast<int>(button), static_cast<unsigned int>(3));
                    evt.logMouseReleaseEvent();
                    break;
                }
        }
    });

    glfwSetWindowCloseCallback(static_cast<GLFWwindow*>(getWindow()), [](GLFWwindow* window) {
        Application* win_close_mg = (Application*)glfwGetWindowUserPointer(window);
        win_close_mg->reset_bool_state();
    });

    glfwSetWindowSizeCallback(static_cast<GLFWwindow*>(this->getWindow()), [](GLFWwindow* window, int h, int w) {
        Application* win_size_mg = (Application*)glfwGetWindowUserPointer(window);
    });

    glfwSetCharCallback(static_cast<GLFWwindow*>(this->getWindow()), [](GLFWwindow* window, unsigned int keycode) {
        Application* key_typed_mg = (Application*)glfwGetWindowUserPointer(window);
    });

    while(this->get_state()) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(1.0, 0.0, 0.0, 1.0);
        FrameBufferCallBack();
        matA.setFloat("xPOs", 0.5f);
        drawer2.drawFunc();
        glUseProgram(matA.shaderID);
        OnUpdate();
    }
}