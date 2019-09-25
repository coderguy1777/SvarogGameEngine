#include "window_context.h"

WindowContext* WindowContext::getContextInstance() {
    if(!context_instance) context_instance = new WindowContext(); return context_instance;
}
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
    int gl_v = static_cast<int>(WindowContext::get_opengl_val());
    switch(gl_v) {
        case 1:
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 1);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
            spdlog::warn("CONTEXT_VERSION_GLFW_1");
            break;
        case 2:
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
            spdlog::warn("CONTEXT_VERSION_GLFW_2");
            break;
        case 3:
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
            spdlog::warn("CONTEXT_VERSION_GLFW_3");
            break;
        case 4:
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
            spdlog::warn("CONTEXT_VERSION_GLFW_4");
            break;
        default:
            spdlog::error("NO GLFW CONTEXT MADE");
            throw std::invalid_argument("CONTEXT ERROR GLFW VERSION UNSPECIFIED.");

    }
    glfwWindowHint(GLFW_OPENGL_ANY_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    bool is_resizable = WindowContext::get_resize();
    if(is_resizable) {
        glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
        spdlog::warn("RESIZE_TRUE");
    } else if(!is_resizable) {
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
        spdlog::warn("RESIZE_FALSE");
    }
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

void WindowContext::set_states(unsigned int RESIZE_VAL, unsigned int OPENGL_VAL) {
    getContextInstance()->RESIZE_V = (RESIZE_VAL == Window_Attributes::IS_RESIZE) ? Window_Attributes::IS_RESIZE :  Window_Attributes::NON_RESIZE;
    // open gl version
    switch(OPENGL_VAL) {
        case 1: getContextInstance()->OPENGL_V = Window_Attributes::OPENGL_V1; break;
        case 2: getContextInstance()->OPENGL_V  = Window_Attributes::OPENGL_V2; break;
        case 3: getContextInstance()->OPENGL_V  = Window_Attributes::OPENGL_V3; break;
        case 4: getContextInstance()->OPENGL_V  = Window_Attributes::OPENGL_V4; break;
        default: getContextInstance()->OPENGL_V  = 0; break;
    }
}

bool WindowContext::get_resize() {
    return (getContextInstance()->RESIZE_V == Window_Attributes::IS_RESIZE) ? true : false;
}

unsigned int WindowContext::get_opengl_val() {
    return getContextInstance()->OPENGL_V;
}

WindowContext* WindowContext::context_instance = 0;