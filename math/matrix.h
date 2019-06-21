#pragma once
#ifdef MATRIX_H
#define MATRIX_H
#endif 
#include "math/math.h"
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Matrix {
    public:
        int valnum;
        int **matrix;
        Matrix(int n) {
            this->valnum = n;
            matrix = new int*[valnum];
            for(int i = 0; i < valnum; i++) {
                matrix[i] = new int[valnum];
                memset(matrix[i], false, valnum*sizeof(int));
            }
        }

        void * operator new(size_t t) {
            void * mat = :: new Matrix(0);
            return mat;
        }

        Matrix operator+(Matrix const& addmat) {
            Matrix mat(0);
            mat.valnum = addmat.valnum + this->valnum;
            for(int row = 0; row < mat.valnum; row++) {
                for(int col = 0; col < mat.valnum; col++) {
                    mat.matrix[row][col] = addmat.matrix[row][col] + this->matrix[row][col];
                }
            }
            return mat;            
        }

        Matrix operator-(Matrix const& submat) {
            Matrix mat(0);
            mat.valnum = submat.valnum + this->valnum;
            for(int row = 0; row < mat.valnum; row++) {
                for(int col = 0; col < mat.valnum; col++) {
                    mat.matrix[row][col] = submat.matrix[row][col] - this->matrix[row][col];
                }
            }
            return mat;
        }

        Matrix operator*(Matrix const& multmat) {
            Matrix mat(0);
            mat.valnum = multmat.valnum + this->valnum;
            for(int row = 0; row < multmat.valnum; row++) {
                for(int col = 0; col < multmat.valnum; col++) {
                    mat.matrix[row][col] = multmat.matrix[row][col] * this->matrix[row][col];                    
                }
            }
        }
        
        Matrix operator/(Matrix const& divmat) {
            Matrix mat(0);
            mat.valnum = divmat.valnum + this->valnum;
            for(int r = 0; r < divmat.valnum; r++) {
                for(int c = 0; c < divmat.valnum; c++) {
                    mat.matrix[r][c] = divmat.matrix[r][c] / this->matrix[r][c];
                }
            }
            return mat;
        }

        friend Matrix operator+(Matrix const&addmat, Point3D const&point) {

        }

        void setSpot(int row, int col, int value);
        int getSpot(int r, int c);
        int* getMatRow(int row);
        int* getMatCol(int col);
        void setValue_num(int numval);
        Matrix scalarmult(Matrix a, int scalar);
        Matrix transpose(Matrix a);
};
