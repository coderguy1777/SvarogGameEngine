#include "matrix.h"

inline Vector3 Matrix::getXComponent() {
    return this->xcolumn;    
}

inline Vector3 Matrix::getYComponent() {
    return this->ycolumn;
}

inline Vector3 Matrix::getZComponent() {
    return this->zcolumn;
}

void Matrix::setXColumnComponents(float x0, float x1, float x2) {
    xcolumn.initx = x0;
    xcolumn.inity = x1;
    xcolumn.initz = x2;
}

void Matrix::setYColumnComponents(float y0, float y1, float y2) {
    ycolumn.initx = y0;
    ycolumn.inity = y1;
    ycolumn.initz = y2;
}

void Matrix::setZColumnComponents(float z0, float z1, float z2) {
    zcolumn.initx = z0;
    zcolumn.inity = z1;
    zcolumn.initz = z2;
}