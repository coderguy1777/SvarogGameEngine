#include "matrix.h"

void Matrix::setSpot(int row, int col, int value) {
    matrix[row][col] = value;
}

int Matrix::getSpot(int r, int c) {
    int spot = matrix[r][c];
    return spot;
}

void Matrix::setValue_num(int numval) {
    valnum = numval;
}

Matrix Matrix::scalarmult(Matrix a, int scalar) {
    return a * scalar;
}

int* Matrix::getMatRow(int row) {
    int *rvals;
    for(int i = 0; i < row; i++) {
        rvals[i] = matrix[i][0];
    }
    return rvals;
}

int* Matrix::getMatCol(int col) {
    int *cvals;
    for(int i = 0; i < col; i++) {
        cvals[i] = matrix[0][i];
    }
    return cvals;
}

Matrix Matrix::transpose(Matrix a) {
    Matrix b(a);
    for(int i = 0; i < b.valnum; i++) {
        for(int j = 0; j < b.valnum; j++) {
            b.matrix[i][j] = b.matrix[j][i];
        }
    }
    return b;
}