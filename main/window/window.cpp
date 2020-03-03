#include "window.h"
Window::Window() {
    WindowContext::set_states(1, 3);
    WindowContext::init_glfw();
    WindowContext::create_context(m_window);
    m_window = glfwCreateWindow((int)1280, (int)720, (const char*)"DEFAULT_WIN", NULL, NULL);
    m_monitor = glfwGetPrimaryMonitor();
    WindowContext::make_curr_context(m_window);
    GladLoader::load_glad();
    WindowContext::load_gpu_info();
    glfwSwapInterval(1);

    if(m_window == NULL) {
        spdlog::error("ENGINE_WINDOW_NULL");
        glfwTerminate();
    }

    glfwSetWindowUserPointer(m_window, this);
    glfwSetInputMode(m_window, GLFW_STICKY_KEYS, 1);
    glfwSetKeyCallback(m_window, set_key_callback);
    glfwSetMouseButtonCallback(m_window, set_mouse_callback);
    glfwSetWindowCloseCallback(m_window, set_window_close_callback);

}


void Window::run_window() {
    while(!glfwWindowShouldClose(m_window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glEnable(GL_LIGHTING |  GL_COLOR_MATERIAL);
        glClearColor(1.0, 0.0, 0.0, 1.0);
        glfwPollEvents();
        glfwSwapBuffers(m_window);
    }
    glfwTerminate();

}

Window::Window(uint w, uint h, const char* title) : width(w), height(h), title(title) {
    WindowContext::set_states(1, 3);
    WindowContext::init_glfw();
    WindowContext::create_context(m_window);
    m_window = glfwCreateWindow((int)w, (int)h, (const char*)title, NULL, NULL);
    m_monitor = glfwGetPrimaryMonitor();
    WindowContext::make_curr_context(m_window);
    GladLoader::load_glad();
    WindowContext::load_gpu_info();
    glfwSwapInterval(1);

    if(m_window == NULL) {
        spdlog::error("ENGINE_WINDOW_NULL");
        glfwTerminate();
    }

    glfwSetWindowUserPointer(m_window, this);
    glfwSetInputMode(m_window, GLFW_STICKY_KEYS, 1);
}

void Window::set_key_callback(GLFWwindow* win, int key, int action, int scancode, int mods) {
    switch(scancode) {
        case GLFW_PRESS: 
            spdlog::info("PRESS");
            spdlog::info("KEY: {}", key);
            break;
        case GLFW_RELEASE: 
            spdlog::info("RELEASE");
            spdlog::info("KEY: {}", key);
            break;  
    }
}

void Window::set_mouse_callback(GLFWwindow* win, int button, int action, int mods) {
    switch(action) {
        case GLFW_PRESS:
            if(button == SVAROG_MOUSE_BUTTON_LEFT) {
                spdlog::info("Mouse left pressed.");
            }

            if(button == SVAROG_MOUSE_BUTTON_MIDDLE) {
                spdlog::info("Mouse middle pressed.");
            }
            break;
        case GLFW_RELEASE: 
            break;
    
    }
}

void Window::set_window_close_callback(GLFWwindow* win) {
    glfwTerminate();
}

void* Window::get_window() const {
    return m_window;
}

const char* Window::get_win_title() const {
    return title;
}

uint Window::get_window_width() const {
    return width;
}

uint Window::get_win_height() const {
    return height;
}