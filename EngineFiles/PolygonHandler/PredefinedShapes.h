#pragma once
#ifdef PREDEFINEDSHAPES_H
#define PREDEFINEDSHAPES_H
#endif
#include "GameEngineHeader.h"
using namespace std;

class Shapes {
    private:


    public:
        float square[3][3] = {{1.0f,2.0f, 3.0f} ,{3.0f, 1.0f,4.0f}, {1.0f, 3.0f, 1.0f}};
        float circle[3][3] = {{1.0f, 0.0f, 1.0f} ,{0.0f, -1.0f, 1.0f}, {-1.0f, 1.0f, 0.0f}};
        float pyramid;
        float plane;
        
};