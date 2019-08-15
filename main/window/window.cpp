#include "window.h"
int Window::getWidth() {
    return prop.w;
}

int Window::getHeight()  {
    return prop.h;
}

String Window::getTitle()  {
    return prop.title;
}

void Window::changeWidth(int newW) {
    prop.w = newW;
}

void Window::changeHeight(int newH) {
    prop.h = newH;
}

void Window::changeTitle(String newTitle) {
    prop.title = newTitle;
}