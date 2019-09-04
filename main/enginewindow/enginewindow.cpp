#include "enginewindow.h"
#include "core/events/Event.h"
#include "main/window/window.h"
#include "core/events/event-types/mouseevent.h"
#include "core/logger/LoggerGroup.h"
#include<iostream>

void Application::createWindowContext() {
    WindowContext::create_context(appWindow);
}

void Application::OnUpdate() {
    WindowUpdate::window_buffer_swap(appWindow);
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
    WindowContext::make_curr_context(appWindow);
}

void Application::end() {
    glfwDestroyWindow(appWindow);
}

void Application::glad_tst() {
    WindowContext::init_glad();
}

void Application::VSYNC_func() {
    auto vsync_check = isVSYNCon();
    if(vsync_check) {
        glfwSwapInterval(1);
        std::cout << "VSYNC on!" << std::endl;
    } else if(!vsync_check) {
        glfwSwapInterval(0);
    }
}

void Application::SvarogAppLoop() {
    WindowContext::init_glfw();
    createWindowContext();
    appWindow = glfwCreateWindow((int)winA.prop->w, (int)winA.prop->h, (const char*)winA.prop->title.str, NULL, NULL);
    makeContextCurr();
    WindowContext::init_glad();
    VSYNC_func();

    if(appWindow == NULL) {
        std::cout << "SVAROG_WINDOW IS NULL, ENDING NOW" << std::endl;
        glfwTerminate();
    }

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
                    KeyEvent  evt(static_cast<int>(key));
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
        Application* mouse_evt_ptr = (Application*)glfwGetWindowUserPointer(window);
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
        Application* win_close_mg = (Application*)glfwGetWindowUserPointer(window);
        win_close_mg->reset_bool_state();
    });

    glfwSetWindowSizeCallback(static_cast<GLFWwindow*>(this->getWindow()), [](GLFWwindow* window, int w, int h) {
        Application* win_size_mg = (Application*)glfwGetWindowUserPointer(window);
        glViewport(0, 0, w, h);
        win_size_mg->winA.prop->w = w;
        win_size_mg->winA.prop->h = h;
    });

    glfwSetCharCallback(static_cast<GLFWwindow*>(this->getWindow()), [](GLFWwindow* window, unsigned int keycode) {
        Application* key_typed_mg = (Application*)glfwGetWindowUserPointer(window);
        KeyEvent * typed_key = new KeyEvent(keycode);
        spdlog::info("Key typed: {}" , keycode);
    });

    // TODO: fix rendering bug with frame buffer callback.
    glfwSetFramebufferSizeCallback(static_cast<GLFWwindow*>(this->getWindow()), [](GLFWwindow* window, int w, int h) {
        Application* frm_bfer_cb = (Application*)glfwGetWindowUserPointer(window);        
        glfwGetFramebufferSize(window, &w, &h);
        glViewport(0, 0, w, h);
    });
}