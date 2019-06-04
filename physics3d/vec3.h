#pragma once
#ifdef VEC3_H
#define VEC3_H
#endif
#include<iostream>
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

        Vector3 operator+(const Vector3& b) {
            Vector3 addvec(0.0f, 0.0f, 0.0f);
            addvec.initx = b.initx + this->initx;
            addvec.inity = b.inity + this->inity;
            addvec.initz = b.initz + this->initz;
            return addvec;
        }

        Vector3 operator-(const Vector3& b) {
            Vector3 subvec(0.0f, 0.0f, 0.0f);
            subvec.initx = b.initx - this->initx;
            subvec.inity = b.inity - this->inity;
            subvec.initz = b.initz - this->initz;
            return subvec;
        }

        Vector3 operator/(const Vector3& b) {
            Vector3 divvec(0.0f, 0.0f, 0.0f);
            divvec.initx = b.initx / this->initx;
            divvec.inity = b.inity / this->inity;
            divvec.initz = b.initz / this->initz;
            return divvec;
        }

        float getComponentX();
        float getComponentY();
        float getComponentZ();

        void setComponentX(float x);
        void setComponentY(float y);
        void setComponentZ(float z);

        void resetXYZ(char choice);



};