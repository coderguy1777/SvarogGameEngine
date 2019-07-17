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
    Matrix rotMat(Vector3(0.0f, 0.0f, 0.0f), Vector3(0.0f, 0.0f, 0.0f), Vector3(0.0f, 0.0f, 0.0f));
    rotMat.setXColumnComponents(1.0f, 0.0f, 0.0f);
    rotMat.setYColumnComponents(0.0f, cos(angle), -sin(angle));
    rotMat.setZColumnComponents(0.0f, sin(angle), cos(angle));
    return rotMat;
}

inline Matrix Camera::findEulerYMat(float angle) {
    Matrix rotMat(Vector3(0.0f, 0.0f, 0.0f), Vector3(0.0f, 0.0f, 0.0f), Vector3(0.0f, 0.0f, 0.0f));
    rotMat.setXColumnComponents(cos(angle), 0.0f, sin(angle));
    rotMat.setYColumnComponents(0.0f, 1.0f, 0.0f);
    rotMat.setZColumnComponents(-sin(angle), 0.0f, cos(angle));
    return rotMat;
}

inline Matrix Camera::findEulerZMat(float angle) {
    Matrix rotMat(Vector3(0.0f, 0.0f, 0.0f), Vector3(0.0f,0.0f,0.0f), Vector3(0.0f, 0.0f, 0.0f));
    rotMat.setXColumnComponents(cos(angle), -sin(angle), 0.0f);
    rotMat.setYColumnComponents(sin(angle), cos(angle), 0.0f);
    rotMat.setZColumnComponents(0.0f, 0.0f, 1.0f);
    return rotMat;
}