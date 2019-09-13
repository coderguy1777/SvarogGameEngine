#include "enginewindow.h"
#include "core/events/Event.h"
#include "main/window/window.h"
#include "main/enginewindow/enginewindow.h"
#include "core/events/event-types/mouseevent.h"
EngineWindow* EngineWindow::getInstance() {
    if(!winn) winn = new EngineWindow; return winn;
}

void* EngineWindow::getWindow() {
    return appWindow;
}


void EngineWindow::reset_bool_state() {
    engine_state = false;
}

void EngineWindow::set_bool_state() {
    engine_state = true;
}

bool EngineWindow::get_state() const {
    return engine_state;
}

void EngineWindow::createWindowContext() {
    WindowContext::create_context(appWindow);
}

void EngineWindow::OnUpdate() {
    WindowUpdate::window_buffer_swap(appWindow);
}

void EngineWindow::VSYNC_on() {
    isVsyncOn = true;
}

void EngineWindow::VSYNC_off() {
    isVsyncOn = false;
}

bool EngineWindow::isVSYNCon() {
    return isVsyncOn;
}

void EngineWindow::makeContextCurr() {
    WindowContext::make_curr_context(appWindow);
}

void EngineWindow::end() {
    glfwDestroyWindow(appWindow);
}

void EngineWindow::VSYNC_func() {
    auto vsync_check = isVSYNCon();
    if(vsync_check) {
        glfwSwapInterval(1);
    } else if(!vsync_check) {
        glfwSwapInterval(0);
    }
}
bool check(int a) {
    bool b;
    GLFWwindow* win = static_cast<GLFWwindow*>(EngineWindow::getInstance()->getWindow());
    int state = glfwGetKey(win, a);
    if(state==GLFW_PRESS) {
        b = true;
    }
    return b;
}

void EngineWindow::SvarogAppLoop() {
    set_bool_state();
    WindowContext::init_glfw();
    WindowContext::create_context(appWindow);
    appWindow = glfwCreateWindow((int)winA.getWidth(), (int)winA.getHeight(), (const char*)winA.getTitle().str, NULL, NULL);
    WindowContext::make_curr_context(appWindow);
    GladLoader::load_glad();
    WindowContext::load_gpu_info();
    VSYNC_func();


    if(appWindow == NULL) {
        std::cout << "SVAROG_WINDOW IS NULL, ENDING NOW" << std::endl;
        glfwTerminate();
    }

    glfwSetWindowUserPointer(static_cast<GLFWwindow*>(this->getWindow()), this);
    glfwSetInputMode(appWindow, GLFW_STICKY_KEYS, 1);
    glfwSetKeyCallback(static_cast<GLFWwindow*>(this->getWindow()), [](GLFWwindow* window, int key, int action, int scancode, int mods) {
        EngineWindow* key_evt_ptr = static_cast<EngineWindow*>(glfwGetWindowUserPointer(window));
        switch(scancode) {
            case GLFW_PRESS:
                { 
                    Event e(EVENT_TYPE::KeyEvt, 1, "key_press");
                    KeyEvent evt(static_cast<int>(key));
                    evt.set_key_evt_state(1);
                    evt.logKeyPressEvent();
                    break;
                }

            case GLFW_REPEAT:
                {
                    Event e(EVENT_TYPE::KeyEvt,  2, "key_repeat");
                    KeyEvent *evt = new KeyEvent(static_cast<int>(key));
                    evt->set_key_evt_bind(evt->get_keybind());
                    evt->set_key_evt_event(e);
                    evt->set_key_evt_state(2);
                    evt->logKeyHeldEvent();
                    break;
                }

            case GLFW_RELEASE:
                {
                    Event e(EVENT_TYPE::KeyEvt, 3, "key_release");
                    KeyEvent evt(static_cast<int>(key));
                    evt.set_key_evt_state(3);
                    evt.logKeyReleaseEvent();
                    break;
                }
        }
    });
    // TODO: make an event dispatching system for mouse events.
    glfwSetMouseButtonCallback(static_cast<GLFWwindow*>(this->getWindow()), [](GLFWwindow* window, int button, int action, int mods) {
        EngineWindow* mouse_evt_ptr = (EngineWindow*)glfwGetWindowUserPointer(window);
        switch(action) {
            // keep this, glfw uses GLFW_PRESS
            case GLFW_PRESS:
                {
                    Event e(EVENT_TYPE::MouseEvt, 1, "mouse_press");
                    MouseEvent evt(static_cast<int>(button), static_cast<unsigned int>(1));
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

    glfwSetWindowCloseCallback(static_cast<GLFWwindow*>(this->getWindow()), [](GLFWwindow* window) {
        EngineWindow* win_close_mg = (EngineWindow*)glfwGetWindowUserPointer(window);
        win_close_mg->reset_bool_state();
    });

    glfwSetWindowSizeCallback(static_cast<GLFWwindow*>(this->getWindow()), [](GLFWwindow* window, int w, int h) {
        EngineWindow* win_size_mg = (EngineWindow*)glfwGetWindowUserPointer(window);
        glViewport(0, 0, w, h);
        win_size_mg->winA.changeHeight(h);
        win_size_mg->winA.changeWidth(w);
    });

    glfwSetCharCallback(static_cast<GLFWwindow*>(this->getWindow()), [](GLFWwindow* window, unsigned int keycode) {
        EngineWindow* key_typed_mg = (EngineWindow*)glfwGetWindowUserPointer(window);
    });

    // TODO: fix rendering bug with frame buffer callback.
    glfwSetFramebufferSizeCallback(static_cast<GLFWwindow*>(this->getWindow()), [](GLFWwindow* window, int w, int h) {
        EngineWindow* frm_bfer_cb = (EngineWindow*)glfwGetWindowUserPointer(window);        
        glfwGetFramebufferSize(window, &w, &h);
        glViewport(0, 0, w, h);
    });

    glfwSetWindowPosCallback(static_cast<GLFWwindow*>(this->getWindow()), [](GLFWwindow* window, int xpos, int ypos) {
        EngineWindow* scle_bfer_cb = (EngineWindow*)glfwGetWindowUserPointer(window);
    });
}

EngineWindow *EngineWindow::winn = 0;