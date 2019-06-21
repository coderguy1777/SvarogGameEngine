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

void Camera::setPos(Point3D point) {
    this->camera = point;
}

Point3D Camera::getOrigin() {
    return origin;
}

Point3D Camera::rotateX(float angle) {

}

Point3D Camera::rotateY(float angle) {

}

Point3D Camera::rotateZ(float angle) {
    
}