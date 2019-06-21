#pragma once
#ifdef CAMERA_H
#define CAMERA_H
#endif
#include "math/vec3.h"
#include "math/vec2.h"
#include "math/matrix.h"
#include "math/translatevec2.h"
#include "math/translatevec3.h"
#include "Point.h"
using namespace std;

class Camera {
    protected:
        Point3D origin;
    private:
        Point3D camera;
        int camerah;
        int cameraw;
    public:
        Camera(int ch, int cw, Point3D initialPoint) {
            camerah = ch;
            cameraw = cw;
            camera = initialPoint;
        }

        Camera(){};
        void setCameraHeight(int height);
        void setCameraWidth(int width);
        int getCameraHeight();
        int getCameraWidth();
        Point3D getOrigin();
        void setPos(Point3D point);
        Point3D rotateX(float angle);
        Point3D rotateY(float angle);
        Point3D rotateZ(float angle);
        Point3D translateX(float dist);
};