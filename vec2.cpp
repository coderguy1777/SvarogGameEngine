#include "vec2.h"

float Vector2::getPosX() {
    return this->initx;
}

float Vector2::getPosY() {
    return this->inity;
}

void Vector2::setPosX(float newx) {
    this->initx = newx;
}

void Vector2::setPosY(float newy) {
    this->inity = newy;
}

void Vector2::resetXY(char choice) {
    if(choice == 'x' || choice == 'X') {
        this->initx = 0.0f;
    } else if(choice == 'y' || choice == 'Y') {
        this->inity = 0.0f;
    }
}