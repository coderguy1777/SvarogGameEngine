#pragma once
#ifdef MATRIX_H
#define MATRIX_H
#endif 
#include "math/math.h"
#include "core/Point.h"
#include "math/vec3.h"
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef struct {
    float r0, r1, r2;
} matrixRow;

class Matrix {
    public:
        matrixRow row1, row2, row3;
        Matrix(matrixRow r1, matrixRow r2, matrixRow r3) {
            this->row1 = r1;
            this->row2 = r2;
            this->row3 = r3;
        }
        Matrix(){}

        void setC1Parts(float x0, float x1, float x2);
        void setC2Parts(float y0, float y1, float y2);
        void setC3Parts(float z0, float z1, float z2);
};
