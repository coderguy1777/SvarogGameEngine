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
const int speedoflight = 299792458;
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

double incidentraycalcs(double input) {
    return sin(input);
};


double refraction(double medium) {
    return speedoflight/medium;
};

double angleofincidence(double medium1, double medium2) {
    double sinvar = medium1/medium2;
    return sin(sinvar);  
};