#include "window.h"
int Window::getWidth() {
    return prop->w;
}

int Window::getHeight()  {
    return prop->h;
}

int * Window::get_ptrHeight() const {
    int * h_val = &prop->h;
    return h_val;
}

int * Window::get_ptrWidth() const {
    int * w_val = &prop->w;
    return w_val;
}

String Window::getTitle()  {
    return prop->title;
}

void Window::changeWidth(int newW) {
    prop->w = newW;
}

void Window::changeHeight(int newH) {
    prop->h = newH;
}

void Window::changeTitle(String newTitle) {
    prop->title = newTitle;
}

void* Window::getWindow() {
    return prop;
}