#pragma once
#ifdef PREDEFINEDSHAPES_H 
#define PREDEFINEDSHAPES_H
#include "GameEngineHeader1.h"
#endif
using namespace std;
class Shapes {
    public:
        void testerpolygon();
        void planepolygon();
        enum shapes {
            CUBE, 
            CIRCLE,
            RECTANGLE,
            SPHERE,
            PYRAMID,
            TRIANGLE
        };
        void ShapeSelect(int key);
        
};