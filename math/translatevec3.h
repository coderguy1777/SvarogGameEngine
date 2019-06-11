#pragma once 
#ifdef TRANSLATEVEC3_H
#define TRANSLATEVEC3_H
#endif
#include "vec3.h"
using namespace std;

class Translate3D {
    private:
        Vector3 vec3;
    public:
        Translate3D(Vector3 vec) {
            this->vec3 = vec;
        }
        Translate3D(){};
        Vector3 findVectorDirection(int sclr);
        Vector3 findVectorVelocity(int direc, float rate);
        float findDeltatime(float fps, float time);
        float findDeltaX();
        float findDeltaY();
        float findDeltaZ();
};