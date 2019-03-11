#pragma once
#ifdef POINT_H
#define POINT_H
#endif
#include "GameEngineHeader.h"
#include "Polygon.h"
using namespace std; 

class Point {
    double x;
    double y;
    double z;
    private:

    public:
        Point(double x, double y, double z) {
            this -> x = x;
            this -> y = y;
            this -> z = z;
        }
        struct pointvec {
            float x, y, z;
        };
        
        void pointmovementmatricies(vector<pointvec>points1, vector<pointvec>points2, Polygon a, Polygon b, double pointmata[3][3], double pointmatb[3][3]);
        void pointrotationmatricies(vector<pointvec>points1, vector<pointvec>points2, Polygon a, Polygon b, double pointmata[3][3], double pointmatb[3][3]);
        double indivpointcalculationsmovement(float x, float y, float z);
        double indivpointcalculationsrotation(float x, float y, float z);
};