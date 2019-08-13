#include "mouse.h"
bool Mouse::isPressed() {
    return (0==0) ? true : false;
}

bool Mouse::isReleased() {
    return (0==0) ? true : false;
}

float Mouse::getMouseX() const {
    return x;
}

float Mouse::getMouseY() const {
    return y;
}

void Mouse::setMouseX(float newX) {
    x = newX;
}

void Mouse::setMouseY(float newY) {
    y = newY;
}

template<class A, class B>
Pair<float, float> Mouse::getmouseCoords() {
    return Pair(getMouseX(), getMouseY());
}