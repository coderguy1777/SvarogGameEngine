#include "camera.h"

void Camera::setCameraHeight(int height) {
    this->camerah = height;
}

void Camera::setCameraWidth(int width) {
    this->cameraw = width;
}

int Camera::getCameraHeight() {
    return camerah;
}

int Camera::getCameraWidth() {
    return cameraw;
}