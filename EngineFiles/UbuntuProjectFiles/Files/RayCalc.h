#pragma once
#ifdef RAYCALC_H
#define RAYCALC_H
#endif
#include "GameEngineHeader.h"
using namespace std;


class BasicRayCalculations {
    private:

    public:
        void initalray(double x, double y, double z, double angle);
        void dotproduct(double ray1, double ray2, double angle);
        void directioncosines(double u1, double u2, double u3, double angle);


};