#pragma once
#ifdef NOISEMAP_H
#define NOISEMAP_H
#endif
using namespace std;
#include "perlin.h"
#include<cmath>
class NoiseMap {
    public:
        double height, width;
        NoiseMap(double h, double w) {
            this->height = h;
            this->width = w;
        }

        float* genGrid();
        

};