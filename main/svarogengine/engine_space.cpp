#include "engine_space.h"
EngineSpace* EngineSpace::getEngineSpace() {
    if(!engine) {
        engine = new EngineSpace;
    }
    return engine;
}

void EngineSpace::init_window_settings() {
    EngineSpace::glfw_window_entities.init_window_context();
    EngineSpace::glfw_window_entities.init_win_monitor_context();
}

void EngineSpace::run() {
    glfwSetKeyCallback(static_cast<GLFWwindow*>(glfw_window_entities.getEngineWin()), [](GLFWwindow* window, int key, int action, int scancode, int mods) {
        EngineWindow* key_evt_ptr = static_cast<EngineWindow*>(glfwGetWindowUserPointer(window));
        switch(scancode) {
            case GLFW_PRESS:
                { 
                    Event e(EVENT_TYPE::KeyEvt, 1, "key_press");
                    
                    KeyEvent evt(static_cast<int>(key));
                    evt.set_key_evt_state(1);
                    evt.logKeyPressEvent();
                    
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

    glfwSetMouseButtonCallback(static_cast<GLFWwindow*>(glfw_window_entities.getEngineWin()), [](GLFWwindow* window, int button, int action, int mods) {
        EngineWindow* mouse_evt_ptr = (EngineWindow*)glfwGetWindowUserPointer(window);
        switch(action) {
            // keep this, glfw uses GLFW_PRESS
            case GLFW_PRESS:
                {
                    Event e(EVENT_TYPE::MouseEvt, 1, "mouse_press");
                    MouseEvent evt(static_cast<int>(button), static_cast<unsigned int>(1));
                    evt.logMousePressEvent();
                    if(button == SVAROG_MOUSE_BUTTON_MIDDLE) {

                    }
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

    glfwSetScrollCallback(static_cast<GLFWwindow*>(glfw_window_entities.getEngineWin()), [](GLFWwindow* window, double xoffset, double yoffset) {
        EngineWindow* cursor_scroll_mg = (EngineWindow*)glfwGetWindowUserPointer(window);
        cursor_scroll_mg->is_back = true;
    });

    glfwSetWindowCloseCallback(static_cast<GLFWwindow*>(glfw_window_entities.getEngineWin()), [](GLFWwindow* window) {
        EngineWindow* win_close_mg = (EngineWindow*)glfwGetWindowUserPointer(window);
        win_close_mg->reset_bool_state();
    });

    glfwSetWindowSizeCallback(static_cast<GLFWwindow*>(glfw_window_entities.getEngineWin()), [](GLFWwindow* window, int w, int h) {
        EngineWindow* win_size_mg = (EngineWindow*)glfwGetWindowUserPointer(window);
        glViewport(0, 0, w, h);
        win_size_mg->winA.changeHeight(h);
        win_size_mg->winA.changeWidth(w);
        spdlog::info("WINDOW_RESIZE");
    });

    glfwSetCharCallback(static_cast<GLFWwindow*>(glfw_window_entities.getEngineWin()), [](GLFWwindow* window, unsigned int keycode) {
        EngineWindow* key_typed_mg = (EngineWindow*)glfwGetWindowUserPointer(window);
    });

    // TODO: fix rendering bug with frame buffer callback.
    glfwSetFramebufferSizeCallback(static_cast<GLFWwindow*>(glfw_window_entities.getEngineWin()), [](GLFWwindow* window, int w, int h) {
        EngineWindow* frm_bfer_cb = (EngineWindow*)glfwGetWindowUserPointer(window);        
        glfwGetFramebufferSize(window, &w, &h);
        glViewport(0, 0, w, h);
        spdlog::info("FRAMEBUFFER_SIZE_CHANGE");
    });

    glfwSetWindowPosCallback(static_cast<GLFWwindow*>(glfw_window_entities.getEngineWin()), [](GLFWwindow* window, int xpos, int ypos) {
        EngineWindow* scle_bfer_cb = (EngineWindow*)glfwGetWindowUserPointer(window);
    });


    bool run_state = (!glfwWindowShouldClose && engine_settings.getEngineState() && engine_settings.getState() == 1) ? true : false;
    while(run_state) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glEnable(GL_LIGHTING | GL_COLOR_MATERIAL);
        glClearColor(1.0, 0.0, 0.0, 1.0);
        ImGuiInit::init_imgui_render();
    }
    
}

EngineSpace* EngineSpace::engine = 0;