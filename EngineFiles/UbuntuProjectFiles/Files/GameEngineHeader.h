#include<string>
#include<iostream>
#include<vector>
#include<random>
#include<map>
#include<GL/glut.h>
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