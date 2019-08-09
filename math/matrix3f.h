#pragma once
#ifdef MATRIX3F_H
#define MATRIX3F_H
#endif 
#include<stdexcept>
class Matrix3f {
    public: 
        float matrix[3][3];
        Matrix3f() {
            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                    matrix[i][j] = 0.0f;
                }
            }
        }

        void setVal(int row, int col, float val) {
            if(row > 3 || col > 3) {
                throw std::invalid_argument("Row or Column to big for selection of value setting.");
            } else if(row < 0 || col < 0) {
                throw std::invalid_argument("Row or Column selection to small for value setting.");
            }
            matrix[row][col] = val;
        }

        float getVal(int row, int col) {
            if(row > 3 || col > 3) {
                throw std::invalid_argument("Row or Column selection too big for mat3 dimensions.");
            } else if(row < 0 || col < 0) {
                throw std::invalid_argument("Row or Column selection too small for wanted value spot.");
            }
            return (float)matrix[row][col];
        }

        Matrix3f operator+(const Matrix3f& b) {
            Matrix3f a;
            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                    a.matrix[i][j] = b.matrix[i][j] + this->matrix[i][j];
                }
            }
            return a;
        }
        
        Matrix3f operator-(const Matrix3f& b) {
            Matrix3f a;
            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                    a.matrix[i][j] = b.matrix[i][j] - this->matrix[i][j];
                }
            }
            return a;
        }

        Matrix3f operator*(const Matrix3f& b) {
            Matrix3f a;
            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                    a.matrix[i][j] = b.matrix[i][j] * this->matrix[i][j];
                }
            }
            return a;
        }

        Matrix3f operator/(const Matrix3f& b) {
            Matrix3f a;
            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                    a.matrix[i][j] = b.matrix[i][j] + this->matrix[i][j];
                }
            }
            return a;
        }
};