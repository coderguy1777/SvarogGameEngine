#pragma once
#ifdef GAMEENGINEHEADER_H
#define GAMEENGINEHEADER_H
#endif
#include<string>
#include<iostream>
#include<vector>
#include<random>
#include<map>
#include<fstream>
#include<GL/gl.h>
#include<GL/glu.h>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<algorithm>
#define PI 3.14
constexpr auto ABSOLUTECENTERX = 0;
constexpr auto ABSOLUTECENTERY = 0;
constexpr auto ABSOLUTECENTERZ = 0;

struct veccoordinates {
    double x, y, z;
};

struct squarepoints {
    double p1, p2, p3, p4;
};

struct cameradimensions {
    int w, h;
};

struct rotationalvalues {
    double dx, dy, dz;
};

struct primesofxyz {
    double x, y, z;
};