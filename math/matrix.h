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

class Matrix {
    public:
        Vector3 xcolumn, ycolumn, zcolumn;
        Matrix(Vector3 x, Vector3 y, Vector3 z) {
            this->xcolumn = x;
            this->ycolumn = y;
            this->zcolumn = z;
        }
        Matrix(){}
        void * operator new(size_t size) {
            void * matrix = new Matrix(Vector3(0.0f, 0.0f, 0.0f), Vector3(0.0f, 0.0f, 0.0f), Vector3(0.0f, 0.0f, 0.0f));
            return matrix;
        }
        Vector3 getXComponent();
        Vector3 getYComponent();
        Vector3 getZComponent();

        Matrix operator+(const Matrix& a) {
            Matrix aa;
            aa.xcolumn = this->xcolumn + a.xcolumn;
            aa.ycolumn = this->ycolumn + a.ycolumn;
            aa.zcolumn = this->zcolumn + a.zcolumn;
            return aa;
        }

        Matrix operator-(const Matrix& a) {
            Matrix aa;
            aa.xcolumn = this->xcolumn - a.xcolumn;
            aa.ycolumn = this->ycolumn - a.ycolumn;
            aa.zcolumn = this->zcolumn - a.zcolumn;
            return aa;
        }

        Matrix operator*(const Matrix& a) {
            Matrix aa;
            aa.xcolumn = this->xcolumn * a.xcolumn;
            aa.ycolumn = this->ycolumn * a.ycolumn;
            aa.zcolumn = this->zcolumn * a.zcolumn;
            return aa;
        }

        Matrix operator/(const Matrix& a) {
            Matrix aa;
            aa.xcolumn = this->xcolumn / a.xcolumn;
            aa.ycolumn = this->ycolumn / a.ycolumn;
            aa.zcolumn = this->zcolumn / a.zcolumn;
            return aa;
        }

        void setXColumnComponents(float x0, float x1, float x2);
        void setYColumnComponents(float y0, float y1, float y2);
        void setZColumnComponents(float z0, float z1, float z2);
};
