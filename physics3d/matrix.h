#pragma once
#ifdef MATRIX_H
#define MATRIX_H
#endif 
#include "core/math.h"
#include<iostream>
using namespace std;

class Matrix {
    private:
        int rows, cols;
        int **matrix;
    public:
        Matrix(int r, int c) {
            rows = r;
            cols = c;
            matrix[rows][cols];
        }
        void setSpot(int row, int col);
        int getSpot(int r, int c);
        int* getCompRow(int r);
        int* getCompCol(int c);
        void setRows(int r);
        void setColumns(int c);
        Matrix operator+(Matrix const& mat_one) {
            Matrix mat_b(0, 0);
            mat_b.rows = mat_one.rows + rows;
            mat_b.cols = mat_one.cols + cols;
            return mat_b;
        }

        
};
