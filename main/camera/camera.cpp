#include "camera.h"
inline void Camera::changeDimensions(int newW, int newH) {
    this->cameraW = newW;
    this->cameraH = newH;
}

int Camera::getCameraW() {
    return cameraW;
}

int Camera::getCameraH() {
    return cameraH;
}
