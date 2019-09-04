#include "window_update.h"
void WindowUpdate::window_buffer_swap(GLFWwindow* window) {
    glfwPollEvents();
    glfwSwapBuffers(window);
}

void WindowUpdate::set_win(GLFWwindow* new_update_win) {
    window = new_update_win;
}

void* WindowUpdate::get_update_win()  {
    return window;
}