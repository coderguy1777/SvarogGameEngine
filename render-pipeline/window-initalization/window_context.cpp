#include "window_context.h"
WindowContext* WindowContext::context_instance = new WindowContext();
void WindowContext::set_context_win(GLFWwindow* cxt_win) {
    context_instance->context_win= cxt_win;
}

void* WindowContext::get_context_win() const {
    return context_win;
}

void WindowContext::create_context(GLFWwindow* window) {
    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_ANY_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
}

void WindowContext::make_curr_context(GLFWwindow* win) {
    glfwMakeContextCurrent(win);
}

void WindowContext::init_glfw() {
    if(!glfwInit()) {
        spdlog::info("GLFW Failure to load, please check for dependency install....");
        glfwTerminate();
    } else {
        spdlog::info("GLFW success to load, continuing launch of engine....");
    }
}

int WindowContext::get_glfw_load_state() const {
    return glad_success;
}

void WindowContext::init_glad() {
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        throw std::invalid_argument("GLAD FAILURE");
        glfwTerminate();
    } else {
        spdlog::info("GLAD has been loaded!");
    }
}

int WindowContext::get_glad_state() const {
    return glad_success;
}