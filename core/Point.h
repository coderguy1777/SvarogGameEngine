#pragma once
#ifdef POINT_H
#define POINT_H
#endif

typedef struct {
    float x, y, z;
    int originx, originy, originz;
} Point;

typedef struct {
    float x, y;
    int originx, originy;
} Point2D;

typedef struct {
    float x;
    int originx;
} Point1D;