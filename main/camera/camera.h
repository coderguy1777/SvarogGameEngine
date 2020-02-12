#pragma once
#ifdef CAMERA_H
#define CAMERA_H
#endif
#include <glad/glad.h>
#include "render-pipeline/shader/ShaderProgram.h"
#include "math/vec3.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

class Camera {
    private: 
        struct camera_info {
            uint w, h; // camera width and height;
            uint camera_val; // for identifying the camera;
            std::string camera_name; // name for the camera;
            bool is_main; // if the camera is a main camera, is set as the primary camera in scene;
        } camera_data;

        struct camera_math {
            glm::mat4 camera_transform_mat;
            Vector3 translation_vec;
            Vector3 camera_pos;
        } cam_mat;

    public:
        Camera();
        glm::mat4 get_cam_mat();
        void set_camera_dimensions(const uint&w, const uint&h);
        void set_main_state(const bool&is_main);
        void translate_camera();
        void update_camera_vec(float c_x, float c_y, float c_z);
};