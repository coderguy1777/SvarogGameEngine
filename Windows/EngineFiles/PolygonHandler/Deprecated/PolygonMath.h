#pragma once
#ifdef POLYGONMATH_H
#define POLYGONMATH_H
#endif
#include "GameEngineHeader.h"
#include "Polygon.h"

class Vectors {
    private:


    public:
        Polygon vecAdding(Polygon a, Polygon b);
        Polygon vecSubtracting(Polygon a, Polygon b);
        double vecDistance(Polygon a, Polygon b);
        Polygon vecDotProduct(Polygon a, Polygon b);
        Polygon vecAngle(Polygon a, Polygon b);
        Polygon vecRotation(Polygon a, Polygon b);
        Polygon vecUnitvector(Polygon a, Polygon b);
};