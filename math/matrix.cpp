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

float Matrix::getValue(int row, int spot) {
    float val = 0.0f;
    int deseriedrow = 0;
    if(row == 1) {
        deseriedrow = 1;
        if(spot == 0) {
            val = row1.r0;
        }

        if(spot == 1) {
            val = row1.r1;
        } 

        if(spot == 2) {
            val = row1.r2;
        }
    } 

    if(row == 2) {
        deseriedrow = 2;
        if(spot == 0) {
            val = row2.r0;
        }

        if(spot == 1) {
            val = row2.r1;
        }

        if(spot == 2) {
            val = row2.r2;
        }
    }

    if(row == 3) {
        deseriedrow = 3;
        if(spot == 0) {
            val = row3.r0;
        }

        if(spot == 1) {
            val = row3.r1;
        }

        if(spot == 2) {
            val = row3.r2;
        }
    }
    return val;
}

ArrayList<float> Matrix::getRow(int rowNum) {
    ArrayList<float>rowvals;
    switch(rowNum) {
        case 1:
            for(int i = 0; i < 3; i++) {
                rowvals.add(getValue(1, i));
            }
            break;
        case 2: 
            for(int j = 0; j < 3; j++) {
                rowvals.add(getValue(2, j));
            }
            break;
        case 3:
            for(int k = 0; k < 3; k++) {
                rowvals.add(getValue(3, k));
            }
            break;
        default :
            break;
    }
    return rowvals;
}