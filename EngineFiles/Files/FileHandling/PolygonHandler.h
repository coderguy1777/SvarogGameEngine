#pragma once
#ifdef POLYGONHANDLER_H
#define POLYGONHANDLER_H
#endif
#include "GameEngineHeader.h"
#include<vector>

class PolygonInputter {
    private:


    public:
        void polygondefintion();
        double polygoncoordinates(double x, double y, double z);
        double x, y, z;
        void polygondef(char* bin);
        void draw();
}