#pragma once
#ifdef POINT_H
#define POINT_H
#endif
#include "GameEngineHeader.h"
using namespace std; 

class Verticie {
    double x;
    double y;
    double z;
    private:

    public:
        Verticie(double x, double y, double z) {
            this -> x = x;
            this -> y = y;
            this -> z = z;
        }
};