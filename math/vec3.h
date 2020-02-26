#pragma once
#ifdef VEC3_H
#define VEC3_H
#endif

using namespace std;
#include<iostream>
#include "core/Point.h"
#include "math/matrix.h"
#include <cmath>
class Vector3 {
    public:
        float initx, inity, initz;
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



        friend Vector3 operator*(const Vector3&b, const int &str) {
            Vector3 newVec(0.0f, 0.0f, 0.0f);
            newVec.initx = b.initx * str;
            newVec.inity = b.inity * str;
            newVec.initz = b.initz * str;
            return newVec;
        }

        friend Vector3 operator-(const Vector3&b,const int &str) {
            Vector3 newVec(0.0f, 0.0f, 0.0f);
            newVec.initx = b.initx - str;
            newVec.inity = b.inity - str;
            newVec.initz = b.initz - str;
            return newVec;
        }

        friend Vector3 operator+(const Vector3&b, const int &str) {
            Vector3 newVec(0.0f, 0.0f, 0.0f);
            newVec.initx = b.initx + str;
            newVec.inity = b.inity + str;
            newVec.initz = b.initz + str;
            return newVec;
        }

        friend Vector3 operator/(const Vector3&b, const int &str) {
            Vector3 newVec(0.0f, 0.0f, 0.0f);
            newVec.initx = b.initx/str;
            newVec.inity = b.inity/str;
            newVec.initz = b.initz/str;
            return newVec;
        }

        friend Vector3 operator+(const Vector3&b, const float &str) {
            Vector3 newVec(0.0f, 0.0f, 0.0f);
            newVec.initx = b.initx + str;
            newVec.inity = b.inity + str;
            newVec.initz = b.initz + str;
            return newVec;
        }

        friend Vector3 operator-(const Vector3&b, const float &str) {
            Vector3 newVec(0.0f, 0.0f, 0.0f);
            newVec.initx = b.initx - str;
            newVec.inity = b.inity - str;
            newVec.initz = b.initz - str;
            return newVec;
        }

        friend Vector3 operator*(const Vector3&b, const float &str) {
            Vector3 newVec(0.0f, 0.0f, 0.0f);
            newVec.initx = b.initx * str;
            newVec.inity = b.inity * str;
            newVec.initz = b.initz * str;
            return newVec;
        }


        float getComponentX();
        float getComponentY();
        float getComponentZ();
        float vec3Mag();
        Vector3 vec3ScalarMult(Vector3 veca, int scalar);
        Vector3 vec3ScalarSub(Vector3 veca, int scalar);
        Vector3 vec3ScalarAdd(Vector3 veca, int scalar);
        float dotProd(Vector3 a, Vector3 b);
        void setComponentX(float x);
        void setComponentY(float y);
        void setComponentZ(float z);
        void resetXYZ(char choice);
        void toOrigin();
        Vector3 mult(Vector3 a, Vector3 b);
        Vector3 add(Vector3 a, Vector3 b);
        Vector3 sub(Vector3 a, Vector3 b);
        Vector3 div(Vector3 a, Vector3 b);
        Vector3 crossProduct(Vector3 fac, Vector3 fac2);

        Vector3 normalize(Vector3 a);
        Vector3 dotProd_andAngle(Vector3 a, Vector3 b, float angle);
        Vector3 scalarMult(Vector3 a, int scalar);
        float twoVecAngle(Vector3 a, Vector3 b);
        Vector3 unitVecAngles(Vector3 u, float iangle, float jangle, float kangle);
};

inline bool operator==(const Vector3&vec_a, const Vector3& vec_b) {
    return (vec_a.initx == vec_b.initx) && (vec_a.inity == vec_b.inity) && (vec_a.initz == vec_b.initz);
}

inline bool operator!=(const Vector3&vec_a, const Vector3& vec_b) {
    return (vec_a.initx != vec_b.initx) && (vec_a.inity != vec_b.inity) && (vec_a.initz != vec_b.initz);

}

inline Vector3 operator*(const Matrix<float>&mat_a, const Vector3 &trans_vec) {
    Vector3 newVec(0.0f, 0.0f, 0.0f);
    auto new_x = (mat_a.get_matrix_value(0, 0) *(trans_vec.initx)) + (mat_a.get_matrix_value(0, 1) * (trans_vec.inity)) + (mat_a.get_matrix_value(0, 2) * (trans_vec.initz)) + (mat_a.get_matrix_value(0, 3) * (1));
    auto new_y = (mat_a.get_matrix_value(1, 0) * (trans_vec.initx)) + (mat_a.get_matrix_value(1, 1) * (trans_vec.inity)) + (mat_a.get_matrix_value(1, 2) * (trans_vec.initz)) + (mat_a.get_matrix_value(1, 3) * (1));
    auto new_z = (mat_a.get_matrix_value(2, 0) * (trans_vec.initx)) + (mat_a.get_matrix_value(2, 1) * (trans_vec.initz)) + (mat_a.get_matrix_value(2, 2)) * (trans_vec.initz) + (mat_a.get_matrix_value(2, 3) * (1));
    newVec.setComponentX(new_x);
    newVec.setComponentY(new_y);
    newVec.setComponentZ(new_z);
    return newVec;
}

inline Vector3 operator+(const Matrix<float>&mat_a, const Vector3 &trans_vec) {
    Vector3 newVec(0.0f, 0.0f, 0.0f);
    auto new_x = mat_a.get_matrix_value(0, 3) + trans_vec.initx;
    auto new_y = mat_a.get_matrix_value(1, 3) + trans_vec.inity;
    auto new_z = mat_a.get_matrix_value(2, 3) + trans_vec.initz;
    return newVec;
}