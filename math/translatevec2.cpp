#include "translatevec2.h"
float Translate2D::findDeltaX() {
    float delt_x = translateVec2d.getPosX() - translateVec2d.getPosY();
    return delt_x;
}

float Translate2D::findDeltaY() {
    float delt_y = translateVec2d.getPosY() - translateVec2d.getPosX();
}