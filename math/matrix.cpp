#include "matrix.h"

void Matrix::setC1Parts(float x0, float x1, float x2) {
    row1.r0 = x0;
    row2.r0 = x1;
    row3.r0 = x2;
}

void Matrix::setC2Parts(float y0, float y1, float y2) {
    row1.r1 = y0;
    row2.r1 = y1;
    row3.r1 = y2;
} 

void Matrix::setC3Parts(float z0, float z1, float z2) {
    row1.r2 = z0;
    row2.r2 = z1;
    row3.r2 = z2;
}