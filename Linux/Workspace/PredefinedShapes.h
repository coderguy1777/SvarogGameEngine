#pragma once
#ifdef PREDEFINEDSHAPES_H 
#define PREDEFINEDSHAPES_H
#include "GameEngineHeader1.h"
#endif
using namespace std;
class Shapes {
    public:
        float xsize = 0.0f;
        double cubesize = 30.0;
        void testerpolygon();
        void planepolygon();
        void cube();
        void changecubesize(int val);
        void vertexgen(int size, float a, float c, float b);
};