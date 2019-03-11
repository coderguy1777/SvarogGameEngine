#pragma once
#ifdef POLYGON_H
#define POLYGON_H
#endif
#include "GameEngineHeader.h"

class Polygon {

    public:
        float x, y, z;
        void setPolygon(Polygon p, float x1, float y1, float z1);
        Polygon getPolygon(Polygon p);
        float getX();
        float getY();
        float getZ();
};

