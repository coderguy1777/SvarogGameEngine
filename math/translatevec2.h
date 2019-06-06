#pragma once
#ifdef TRANSLATEVEC2_H 
#define TRANSLATEVEC2_H
#endif
#include<iostream>
#include "math.h"
#include "vec2.h"
using namespace std;

class Translate2D {
    private:
        Vector2 translateVec2d;
    public:
        Translate2D(Vector2 veca) {
            this->translateVec2d = veca;
        }

        float calculateVectorVelocity();
        float calculateInitialVelX();
        float calculateFinalVelX();
        float findDeltaX();        
        float calculateVectorVelocityY();
        float calculateInitialVelY();
        float calculateFinalVelY();
        float findDeltaY();
        float findDeltaTime();
};