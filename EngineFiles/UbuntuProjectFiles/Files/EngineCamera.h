#pragma once
#include "GameEngineHeader.h"
#ifdef ENGINECAMERA_H
#define ENGINECAMERA_H
#endif
using namespace std;

class SvarogEngineCamera {
    private: 

    public:
        double dx = 0.0;
        double dy = 0.0;
        double dz = 0.0;
        SvarogEngineCamera(int xval, int yval);
        double speedval = 5.0;
        vector<double>camerapos;
        vector<double>camerarotation;
        double inversedmatrix[3][3];
        vector<cameradimensions>camera1;
        void initialcamera(int CAMERAHEIGHT, int CAMERAWIDTH);
        void cameradirection();
        double camerarot(int axis, double var1, double var2, double var3);
        void inverseofmatrix(int a, int b, double matrix[3][3]);
        int testmethod(int input);
        void matrixsubtract(double matrixa[3][3], double matrixb[3][3]);
        void matrixadd(double matrixa[3][3], double matrixb[3][3]);
        vector<veccoordinates> unitvec(vector<veccoordinates>veca, vector<veccoordinates>vecb, double angle);

};