#pragma once
#ifdef VEC3_H
#define VEC3_H
#endif
#include<iostream>
using namespace std;
#include "Point.h"

class Vector3 {
    private:
        float initx, inity, initz;
    
    public:
        Vector3(float lx, float ly, float lz) {
            this->initx = lx;
            this->inity = ly;
            this->initz = lz;
        }

        Vector3(Point3D init) {
            this->initx = init.x;
            this->inity = init.y;
            this->initz = init.z;
            init.originx = 0;
            init.originy = 0;
            init.originz = 0;
        }

        Vector3(){};

        void * operator new(size_t t) {
            void * vec3mat = new Vector3(0.0f, 0.0f, 0.0f);
            return vec3mat;
        }
        
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

        friend Vector3 operator*(const Vector3&b, int &str) {
            b.initx *= str;
            b.inity *= str;
            b.initz *= str;
            return b;
        }

        friend Vector3 operator-(const Vector3&b, int &str) {
            b.initx -= str;
            b.inity -= str;
            b.initz -= str;
            return b;
        }

        friend Vector3 operator+(const Vector3&b, int &str) {
            b.initx += str;
            b.inity += str;
            b.initz += str;
            return b;
        }

        friend Vector3 operator/(const Vector3&b, int &str) {
            b.initx/=str;
            b.inity/=str;
            b.initz/=str;
            return b;
        }

        friend Vector3 operator+(const Vector3&b, float &str) {
            b.initx+=str;
            b.inity+=str;
            b.initz+=str;
            return b;
        }

        friend Vector3 operator-(const Vector3&b, float &str) {
            b.initx -= str;
            b.inity -= str;
            b.initz -= str;
            return b;
        }

        friend Vector3 operator*(const Vector3&b, float &str) {
            b.initx *= str;
            b.inity *= str;
            b.initz *= str;
            return b;
        }

        float getComponentX();
        float getComponentY();
        float getComponentZ();
        float vec3Mag(Vector3 b);
        Vector3 vec3ScalarMult(Vector3 veca, int scalar);
        Vector3 vec3ScalarSub(Vector3 veca, int scalar);
        Vector3 vec3ScalarAdd(Vector3 veca, int scalar);
        void setComponentX(float x);
        void setComponentY(float y);
        void setComponentZ(float z);
        void resetXYZ(char choice);
        void toOrigin();
        Vector3 mult(Vector3 a, Vector3 b);
        Vector3 add(Vector3 a, Vector3 b);
        Vector3 sub(Vector3 a, Vector3 b);
        Vector3 div(Vector3 a, Vector3 b);
        Vector3 scalarMult(Vector3 a, int scalar);
};