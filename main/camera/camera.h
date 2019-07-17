#pragma once
#ifdef CAMERA_H
#define CAMERA_H
#endif
#include "libs.h"
#include "math/matrix.h"
using namespace std;
class Camera {
    public:
        int cameraW, cameraH;
        Point3D camorigin;
        Camera(int w, int h) {
            this->cameraW = w;
            this->cameraH = h;
        }
        int getCameraW();
        int getCameraH();
        void changeDimensions(int newW, int newH);
        void setCameraPos(Point3D pos);
        Matrix findEulerXMat(float angle);
        Matrix findEulerYMat(float angle);
        Matrix findEulerZMat(float angle);
};