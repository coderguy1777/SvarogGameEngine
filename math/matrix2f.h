#pragma once
#ifdef MATRIX2F_H
#define MATRIX2F_h
#endif 
#include "libs.h"
using namespace std;

class Matrix2f {
    public: 
        float matrix[2][2];
        Matrix2f() {
            for(int i = 0; i < 2; i++) {
                for(int j = 0; j < 2; j++) {
                    matrix[i][j] = 0.0f;
                }
            }
        }

        void setVal(int row, int col, float val) {
            if(row > 2 || col > 2) {
                Exception::printException("Row or Column to big for selection of value setting.");
            } else if(row < 0 || col < 0) {
                Exception::printException("Row or Column selection to small for value setting.");
            }
            matrix[row][col] = val;
        }

        float getVal(int row, int col) {
            if(row > 2 || col > 2) {
                Exception::printException("Row or Column selection too big for mat3 dimensions.");
            } else if(row < 0 || col < 0) {
                Exception::printException("Row or Column selection too small for wanted value spot.");
            }
            return (float)matrix[row][col];
        }

        Matrix2f operator+(const Matrix2f& b) {
            Matrix2f a;
            for(int i = 0; i < 2; i++) {
                for(int j = 0; j < 2; j++) {
                    a.matrix[i][j] = b.matrix[i][j] + this->matrix[i][j];
                }
            }
            return a;
        }
        
        Matrix2f operator-(const Matrix2f& b) {
            Matrix2f a;
            for(int i = 0; i < 2; i++) {
                for(int j = 0; j < 2; j++) {
                    a.matrix[i][j] = b.matrix[i][j] - this->matrix[i][j];
                }
            }
            return a;
        }

        Matrix2f operator*(const Matrix2f& b) {
            Matrix2f a;
            for(int i = 0; i < 2; i++) {
                for(int j = 0; j < 2; j++) {
                    a.matrix[i][j] = b.matrix[i][j] * this->matrix[i][j];
                }
            }
            return a;
        }

        Matrix2f operator/(const Matrix2f& b) {
            Matrix2f a;
            for(int i = 0; i < 2; i++) {
                for(int j = 0; j < 2; j++) {
                    a.matrix[i][j] = b.matrix[i][j] + this->matrix[i][j];
                }
            }
            return a;
        }
};