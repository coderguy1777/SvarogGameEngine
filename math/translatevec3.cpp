#include "translatevec3.h"
float Translate3D::findDeltaX() {
    float delt_x = vec3.getComponentX() - vec3.getComponentY();
    return delt_x;
}

float Translate3D::findDeltaY() {
    float delt_y = vec3.getComponentY() - vec3.getComponentX();
    return delt_y;
}

float Translate3D::findDeltaZ() {
    float delt_z = vec3.getComponentZ() - vec3.getComponentX();
    return delt_z;
}

float Translate3D::findDeltatime(float fps, float time) {
    return time/fps;
}

Vector3 Translate3D::findVectorDirection(int sclr) {
    float vecmag = vec3.vec3Mag(vec3);
    Point3D newPos;
    newPos.x = vec3.getComponentX() / vecmag;
    newPos.y = vec3.getComponentY() / vecmag;
    newPos.z = vec3.getComponentZ() / vecmag;
    Vector3 direcVec(newPos);
    return direcVec * sclr;
}

Vector3 Translate3D::findVectorVelocity(int direc, float rate) {
    Vector3 direcVec(findVectorDirection(direc));
    return direcVec * rate;
}