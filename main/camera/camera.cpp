#include "camera.h"
Camera::Camera() {
    cam_mat.camera_transform_mat = glm::mat4(1.0f);
    cam_mat.camera_pos.initx = 0.0f;
    cam_mat.camera_pos.inity = 0.0f;
    cam_mat.camera_pos.initz = 0.0f;
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

void Camera::translate_camera() {
    Vector3 transs_vec = cam_mat.camera_pos + cam_mat.translation_vec;
    glm::vec3 trans_vec = glm::vec3(transs_vec.getComponentX(), transs_vec.getComponentY(), transs_vec.getComponentZ());
    cam_mat.camera_transform_mat = glm::rotate(cam_mat.camera_transform_mat, glm::radians(45.0f), glm::vec3(0.0f, 0.0f, 1.0f));
}

void Camera::update_camera_vec(float c_x, float c_y, float c_z) {
    cam_mat.translation_vec.initx = c_x;
    cam_mat.translation_vec.inity = c_y;
    cam_mat.translation_vec.initz = c_z;
    glm::vec3 trans_vec = glm::vec3(c_x, c_y, c_z);
}

void Camera::rotate_camera_vec(double r_fac, Vector3 cam_vec) {
    auto cam_vecc = get_cam_vec();
    auto cam_mat_data = get_cam_mat();
    auto to_glm = glm::vec3(cam_vec.initx, cam_vec.inity, cam_vec.initz);
    cam_mat.camera_transform_mat = glm::rotate(cam_mat_data, glm::degrees(static_cast<float>(r_fac)), to_glm);

}

glm::mat4 Camera::get_cam_mat() {
    return cam_mat.camera_transform_mat;
}

Vector3 Camera::get_cam_vec() const {
    return cam_mat.camera_pos;
}