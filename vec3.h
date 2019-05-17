#pragma once
#ifdef VEC3_H
#define VEC3_H
#endif
#include "core/Vector.h"
using namespace std;

class Vector3 {
    private:
        float initx, inity, initz;
    
    public:
        Vector3(float lx, float ly, float lz) {
            this->initx = lx;
            this->inity = ly;
            this->initz = lz;
        }
        float vec3Mag(Vector3 b);
        float* vec3Scalar(int scalar);

        Vector3 operator*(const Vector3& b) {
            Vector3 input(0.0f, 0.0f, 0.0f);
            input.initx = this->initx * b.initx;
            input.inity = this->inity * b.inity;
            input.initz = this->initz * b.initz;
            return input;
        }

        float getComponentX();
        float getComponentY();
        float getComponentZ();

        void setComponentX(float x);
        void setComponentY(float y);
        void setComponentZ(float z);

        void resetXYZ(char choice);



};