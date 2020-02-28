#include "window.h"
Window::Window() {
    m_window = glfwCreateWindow((int)1280, (int)720, (const char*)"DEFAULT_WIN", NULL, NULL);
}

Window::Window(uint w, uint h, const char* title) : width(w), height(h), title(title) {
    m_window = glfwCreateWindow((int)w,(int) h, (const char*)title, NULL, NULL);
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