#include "camera.h"
void Camera::setShaderPrg(const ShaderProgram&shader_pr) {
    shader_prg = shader_pr;
}

void Camera::init_camera_dimensions(int m_w, int m_h) {
    c_w = m_w;
    c_h = m_h;
}

void Camera::TranslateVector(std::vector<float>translate_fac, Vector3 translateVec) {

    cameraOrigin = (camera_matrix) * translateVec;
    camera_matrix.set_matrix_value(0, 3, cameraOrigin.getComponentX());
    camera_matrix.set_matrix_value(1, 3, cameraOrigin.getComponentY());
    camera_matrix.set_matrix_value(2, 3, cameraOrigin.getComponentZ());
    updateTranslation();
}


void Camera::updateTranslation() {
    auto shader_id = shader_prg.get_shader_id();
    auto front = camera_matrix.get_matrix_value(0, 0);
    glUniformMatrix4fv(glGetUniformLocation(shader_id, "model"), 1, GL_TRUE, &front);
}