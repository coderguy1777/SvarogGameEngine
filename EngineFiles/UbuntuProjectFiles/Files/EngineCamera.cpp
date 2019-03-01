#include "GameEngineHeader.h"
#include "EngineCamera.h"
using namespace std;

void SvarogEngineCamera::initialcamera(int CAMERAHEIGHT, int CAMERAWIDTH) {
    cout << "What would you like the camera height to be?" << endl;
    int heightvalue;
    cin >> heightvalue;
    cout << "What would you like the camera width to be?" << endl;
    int widthvalue; 
    cin >> widthvalue;
    heightvalue = CAMERAHEIGHT;
    widthvalue = CAMERAWIDTH;
    double i, j, k = 0.0;
    camerapos.push_back(i);
    camerapos.push_back(j);
    camerapos.push_back(k);
    camera1.push_back({CAMERAHEIGHT, CAMERAWIDTH});
}

void SvarogEngineCamera::cameradirection() {
    double cameraposx = 0.0;
    double cameraposy = 0.0;
    double cameraposz = 0.0;

    char directioninput = getchar();

    if(directioninput == 32) {
        // Calculates the differentials for each axis on the input of space 
        // in this case for the camera movement.
        cameraposx += dx;
        cameraposy += dy;
        cameraposz += dz + speedval;
        
        // Adds the vector positions to a vector for the cameras position.
        camerapos.push_back(cameraposx);
        camerapos.push_back(cameraposy);
        camerapos.push_back(cameraposz);
    }

    else if(directioninput == 32 && directioninput == 68) {
        cameraposx += dx;
        cameraposy += dy + speedval;
        cameraposz += dz + speedval;

        // Adds the vector positions to a vector for the cameras position.
        camerapos.push_back(cameraposx);
        camerapos.push_back(cameraposy);
        camerapos.push_back(cameraposz);
    }
}

int SvarogEngineCamera::testmethod(int invar) {
     cout << "Number is: " << invar << endl;
     return invar;
}

double SvarogEngineCamera::camerarot(int axis, double var1, double var2, double var3) {
    double x = var1;
    double y = var2;
    double z = var3;

    double rotx1, rotx2, rotx3;
    double roty1, roty2, roty3;
    double rotz1, rotz2, rotz3;
    vector<veccoordinates>primesofxyz;

    if(axis == 1) {
        rotx1 = 1;
        rotx2 = 0;
        rotx3 = 0;
        roty1 = 0;
        roty2 = cos(y);
        roty3 = -sin(y);
        rotz1 = 0;
        rotz2 = sin(z);
        rotz3 = cos(z);
        double inversemat[3][3];
        primesofxyz.push_back({rotx1, rotx2, rotx3});
        primesofxyz.push_back({roty1, roty2, roty3});
        primesofxyz.push_back({rotz1, rotz2, rotz3});
        for(unsigned int i = 0; i < primesofxyz.size(); i++) {
            inversemat[i][0] = primesofxyz[i].x;
            inversemat[i][1] = primesofxyz[i].y;
            inversemat[i][2] = primesofxyz[i].z;
            cout << primesofxyz[i].x << endl;
            cout << primesofxyz[i].y << endl;
            cout << primesofxyz[i].z << endl;
        }
    }

    // If the axis is on the y axis for the rotation
    if(axis == 2) {
        // Rotational Matrix X Y Z Parameters for finding the inverse.
        rotx1 = cos(x);
        rotx2 = 0;
        rotx3 = sin(x);
        roty1 = 0;
        roty2 = 1;
        roty3 = 0;
        rotz1 = -sin(z);
        rotz2 = 0;
        rotz3 = cos(z);
        // Declaration of XYZ Matrix
        double inversemat[3][3];
        // Preparing of matrix
        primesofxyz.push_back({rotx1, rotx2, rotx3});
        primesofxyz.push_back({roty1, roty2, roty3});
        primesofxyz.push_back({rotz1, rotz2, rotz3});
        // Looping of values into matrix for finding the inverse
        for(unsigned int i = 0; i < primesofxyz.size(); i++) {
            inversemat[i][0] = primesofxyz[i].x;
            inversemat[i][1] = primesofxyz[i].y;
            inversemat[i][2] = primesofxyz[i].z;
            cout << primesofxyz[i].x << endl;
            cout << primesofxyz[i].y << endl;
            cout << primesofxyz[i].z << endl;
        }
    }

    if(axis == 3) {
        // Declaration of matrix parameters
        rotx1 = cos(x);
        rotx2 = -sin(x);
        rotx3 = 0;
        roty1 = sin(y);
        roty2 = cos(y);
        roty3 = 0;
        rotz1 = 0;
        rotz2 = 0;
        rotz3 = 1;
        // Declaration of XYZ Matrix
        double inversemat[3][3];
        // Adding of values for prepartion for the matrix
        primesofxyz.push_back({rotx1, rotx2, rotx3});
        primesofxyz.push_back({roty1, roty2, roty3});
        primesofxyz.push_back({rotz1, rotz2, rotz3});
        // Adding of values to the matrix
        for(unsigned int i = 0; i < primesofxyz.size(); i++) {
            inversemat[i][0] = primesofxyz[i].x;
            inversemat[i][1] = primesofxyz[i].y;
            inversemat[i][2] = primesofxyz[i].z;
            cout << primesofxyz[i].x << endl;
            cout << primesofxyz[i].y << endl;
            cout << primesofxyz[i].z << endl;
        }

    }

}

void SvarogEngineCamera::inverseofmatrix(int a, int b, double matrix[3][3]) {

}