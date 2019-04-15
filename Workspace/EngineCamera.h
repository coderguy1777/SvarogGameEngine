#pragma once
#ifdef ENGINECAMERA_H
#define ENGINECAMERA_H
#endif
#include "GameEngineHeader.h"
using namespace std;

class SvarogEngineCamera {
    private: 

    public:
    float x, y, z;
        SvarogEngineCamera(float initialx, float initialy, float initialz) {
            this->x = initialx;
            this->y = initialy;
            this->z = initialz;
        }
        void QuaterionRotation(SvarogEngineCamera cam1, vector<float>location);
        void CameraTransform(SvarogEngineCamera cam1);
};

struct structuretest {
    GLdouble x, y, z;
};