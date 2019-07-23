#pragma once 
#ifdef MATRIX4F_H
#define MATRIX4F_H
#endif
#include "libs.h"
using namespace std;
class Matrix4f { 
        public: 
            float mat[4][4];
            Matrix4f() {
                for(int i = 0; i < 4; i++) {
                    for(int j = 0; j < 4; j++) {
                        this->mat[i][j] = 0.0f;
                    }
                }
            }

            inline void transpose() {
                for(int i = 0; i < 4; i++) {
                    for(int j = 0; j < 4; j++) {
                        this->mat[i][j] = this->mat[j][i];
                    }
                }
            }


            inline void setScaleFAC(float scalefac) {
                this->mat[0][0] = scalefac;
                this->mat[1][1] = scalefac;
                this->mat[2][2] = scalefac;
                this->mat[3][3] = scalefac;
            }

            inline void transScale(Matrix4f scale) {
                for(int i = 0; i < 4; i++) {
                    for(int j =  0; j < 4; j++) {
                        this->mat[i][j] = this->mat[i][j] *2;
                    }

                }
            }

            inline void translateFunc(Vector3 a) {
                this->mat[0][3] = (this->mat[0][0] * a.initx) + (this->mat[0][1] * a.inity) + (this->mat[0][2] * a.initz);
                this->mat[1][3] = (this->mat[1][0] * a.initx) + (this->mat[1][1] * a.inity) + (this->mat[1][2] * a.initz);
                this->mat[2][3] = (this->mat[2][0] * a.initx) + (this->mat[2][1] * a.inity) + (this->mat[2][2] * a.initz);
                this->mat[3][3] = (this->mat[0][0] * a.initx) + (this->mat[3][1] * a.inity) + (this->mat[3][2] * a.initz);
            }

            void setVal(int row, int col, float val) {
                if(row <= 0 || row >= 4) {
                    std::invalid_argument("Spot for val placement is too big, fix");
                }
                if(col <= 0 || col >= 0) {
                    std::invalid_argument("Col spot too small");
                }
                this->mat[row][col] = val;
            }

            Matrix4f operator+(const Matrix4f& b) {
                Matrix4f c;
                for(int i = 0; i < 4; i++) {
                    for(int j = 0; j < 4; j++) {
                        c.mat[i][j] = b.mat[i][j] + this->mat[i][j];
                    }
                }
                return c;
            }

            inline void identity() {
                this->mat[0][0] = 0.5f;
                this->mat[1][1] = 1.0f;
                this->mat[2][2] = 1.0f;
                this->mat[3][3] = 1.0f;
            }

            Matrix4f& translate(float x, float y, float z, float w);
            inline void print() {
                for(int i = 0; i < 4; i++) {
                    cout << '\n';
                    for(int j = 0; j < 4; j++) {
                        cout << this->mat[i][j];
                    }
                    cout << '\n';
                }
            }

            inline void translate(Vector3 x) {
                this->mat[0][3] = x.initx;
                this->mat[1][3] = x.inity;
            }
};

