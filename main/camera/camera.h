#pragma once
#ifdef CAMERA_H
#define CAMERA_H
#endif
#include "math/vec3.h"
#include "math/matrix4f.h"

using namespace std;
class Camera {
    public:
        static Camera& instance() {
            if(instance_ == NULL) {
                instance_ = new Camera();
            }
        }
        int cameraW, cameraH;
        Vector3 upVector;
        Vector3 camorigin;
        Vector3 cameraTarget;
        
        // camera view stuff
        int getCameraW();
        int getCameraH();
        void setCameraW(int w);
        void setCameraH(int h);
        void changeDimensions(int newW, int newH);

        // change camera position
        void setCameraPos(float x, float y, float z);
        
        // setting of up vectors
        inline void setUpVector(Vector3 up) {
            upVector = up;
        }

        inline Matrix4f lookAt(Matrix4f view, Matrix4f model) {
            return Matrix4f(view * model);
        }    
    private: 
        Camera() {}
        static Camera* instance_;
};