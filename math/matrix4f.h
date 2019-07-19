#pragma once 
#ifdef MATRIX4F_H
#define MATRIX4F_H
#endif
#include "libs.h"
using namespace std;
class Matrix4f {
    public: 
        float mat[4][4];
        // sets all vals in matrix 2d arr to 0
        Matrix4f(){
            for(int i = 0; i < 4; i++) {
                for(int j = 0; j < 4; j++) {
                    mat[i][j] = 0.0f;
                }
            }
        }

        void setVal(int row, int col, float val) {
            if(row > 4 || col > 4) {
                Exception::printException("Row or Column is too big, change values to set val.");
            } else if(row < 0 || col < 0) {
                Exception::printException("Row or Column is too small, change values to set val.");
            }
            mat[row][col] = val;
        }

        void setAll(float value) {
            for(int i = 0; i < 4; i++) {
                for(int j = 0; j < 4; j++) {
                    mat[i][j] = value;
                }
            }
        }

        float getVal(int row, int col) {
            if(row > 4 || col > 4) {
                Exception::printException("Row or Column is too big, change values to get val.");
            } else if(row < 0 || col < 0) {
                Exception::printException("Row or Column is too small, change values to get val.");
            }
            return (float)mat[row][col];
        }

        Matrix4f operator+(const Matrix4f& b) {
            Matrix4f a;
            for(int i = 0; i < 4; i++) {
                for(int j = 0; j < 4; j++) {
                    a.mat[i][j] = b.mat[i][j] + this->mat[i][j];
                }
            }
            return a;
        }
        
        Matrix4f operator-(const Matrix4f& b) {
            Matrix4f a;
            for(int i = 0; i < 4; i++) {
                for(int j = 0; j < 4; j++) {
                    a.mat[i][j] = b.mat[i][j] - this->mat[i][j];
                }
            }
            return a;
        }

        Matrix4f operator*(const Matrix4f& b) {
            Matrix4f a;
            for(int i = 0; i < 4; i++) {
                for(int j = 0; j < 4; j++) {
                    a.mat[i][j] = b.mat[i][j] * this->mat[i][j];
                }
            }
            return a;
        }

        Matrix4f operator/(const Matrix4f& b) {
            Matrix4f a;
            for(int i = 0; i < 4; i++) {
                for(int j = 0; j < 4; j++) {
                    a.mat[i][j] = b.mat[i][j] + this->mat[i][j];
                }
            }
            return a;
        }

        void rotateMat(float radians) {
            this->mat[0][0] = this->mat[0][0] + radians;
        }
};