#pragma once 
#ifdef VEC4_H
#define VEC4_H
#endif 
#include "libs.h"
using namespace std;
class Vector4 {
    public:
        // x coord, y coord, z coord, w time coord.
        float x, y, z, w;
        Vector4(){};
        Vector4(float xpos, float ypos, float zpos, float wpos) {
            this->x = xpos;
            this->y = ypos;
            this->z = zpos;
            this->w = wpos;
        }
};