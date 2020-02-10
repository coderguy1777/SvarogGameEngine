#include "camera.h"
Camera::Camera() {
    camera_data.w = 1920;
    camera_data.h = 1080;
}

void Camera::set_camera_dimensions(const uint&w, const uint&h) {
    camera_data.w = w;
    camera_data.h = h;
}

void Camera::set_main_state(const bool&is_main) {
    camera_data.is_main = is_main;
}