#pragma once
#ifdef CAMERA_H
#define CAMERA_H
#endif
#include <glad/glad.h>
#include "render-pipeline/shader/ShaderProgram.h"
#include "math/vec3.h"
#include "math/matrix.h"
class Camera {
    private:
        int c_w;
        int c_h;
        Matrix<float>camera_matrix;
        Vector3 cameraOrigin;

        ShaderProgram shader_prg;
        void updateTranslation();
    public: 
        Camera() {
            camera_matrix.set_matrix_value(0, 0, 1.0f);
            camera_matrix.set_matrix_value(1, 2, 1.0f);
            camera_matrix.set_matrix_value(2, 2, 1.0f);
            camera_matrix.set_matrix_value(3, 3, 1.0f);
            camera_matrix.set_matrix_value(0,3, 2.0f);
            camera_matrix.set_matrix_value(1, 3, 2.0f);
            cameraOrigin.setComponentX(0.0f);
            cameraOrigin.setComponentY(0.0f);
            cameraOrigin.setComponentZ(0.0f);
        }
        void init_camera_dimensions(int m_w, int m_h);
        void TranslateVector(std::vector<float>translation_factors, Vector3 translate_vec);
        void setShaderPrg(const ShaderProgram& shader_pr);
        
};