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
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
}

void WindowContext::make_curr_context(GLFWwindow* win) {
    glfwMakeContextCurrent(win);
}

void WindowContext::init_glfw() {
    if(!glfwInit()) {
        spdlog::info("GLFW Failure to load, please check for dependency install....");
        glfwTerminate();
    } else {
        spdlog::info("********************************************************");
        spdlog::info("GLFW load state: ");
        spdlog::info("GLFW has been loaded!");
    }
}

int WindowContext::get_glfw_load_state() const {
    return glad_success;
}

void WindowContext::load_gpu_info() {
    // information getting
    const GLubyte* gpu_vendor_info = glGetString(GL_VENDOR);
    const GLubyte* renderer_api = glGetString(GL_RENDERER);
    const GLubyte* renderer_api_version = glGetString(GL_VERSION);
    const GLubyte* shading_language_version = glGetString(GL_SHADING_LANGUAGE_VERSION);
    // log
    spdlog::info("********************************************************");
    spdlog::info("GPU and rendering information log: ");
    spdlog::info("GPU Vendor: {}", gpu_vendor_info);
    spdlog::info("GPU renderer: {}", renderer_api);
    spdlog::info("GPU renderer version: {}", renderer_api_version);
    spdlog::info("Shading Language API: {}", shading_language_version);
    spdlog::info("********************************************************");

}

int WindowContext::get_glad_state() const {
    return glad_success;
}