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

void Camera::setCameraPos(Point3D pos) {
    camorigin = pos;
}

inline Matrix Camera::findEulerXMat(float angle) {
    Matrix rotMat;
    rotMat.row1 = matrixRow{0.0f, 0.0f, 0.0f};
    rotMat.row2 = matrixRow{0.0f, 0.0f, 0.0f};
    rotMat.row3 = matrixRow{0.0f, 0.0f, 0.0f};
    rotMat.setC1Parts(1.0f, 0.0f, 0.0f);
    rotMat.setC2Parts(0.0f, cos(angle), -sin(angle));
    rotMat.setC3Parts(0.0f, sin(angle), cos(angle));
    return rotMat;
}

inline Matrix Camera::findEulerYMat(float angle) {
    Matrix rotMat;
    rotMat.row1 = matrixRow{0.0f, 0.0f, 0.0f};
    rotMat.row2 = matrixRow{0.0f, 0.0f, 0.0f};
    rotMat.row3 = matrixRow{0.0f, 0.0f, 0.0f};
    rotMat.setC1Parts(cos(angle), 0.0f, sin(angle));
    rotMat.setC2Parts(0.0f, 1.0f, 0.0f);
    rotMat.setC3Parts(-sin(angle), 0.0f, cos(angle));
    return rotMat;
}

inline Matrix Camera::findEulerZMat(float angle) {
    Matrix rotMat;
    rotMat.row1 = matrixRow{0.0f, 0.0f, 0.0f};
    rotMat.row2 = matrixRow{0.0f, 0.0f, 0.0f};
    rotMat.row3 = matrixRow{0.0f, 0.0f, 0.0f};
    rotMat.setC1Parts(cos(angle), -sin(angle), 0.0f);
    rotMat.setC2Parts(sin(angle), cos(angle), 0.0f);
    rotMat.setC3Parts(0.0f, 0.0f, 1.0f);
    return rotMat;
}