#pragma once
#ifdef RAYCALC_H
#define RAYCALC_H
#endif
#include "GameEngineHeader.h"
using namespace std;


class BasicRayCalculations {
    private:

    public:
        double initalray(double x, double y, double z, int angle);
        double rayangle(double ray1, double ray2, int angle);

};