#include "Keyboard.h"
#include "GameEngineHeader.h"
#include "Polygon.h"
#include "PolygonMath.h"
using namespace std;

void Keys::keydetect(unsigned char key, Polygon inputshape, float x, float y, float z) {
    switch(key) {
        case 'w':
        case 'W':
            inputshape.x = x;
            inputshape.y = y * 2;
            inputshape.z = z;
            keymovementevents(key, inputshape, x, y, z);

        case 's':
        case 'S':
            inputshape.x = x;
            inputshape.y = y * -2;
            inputshape.z = z;
            keymovementevents(key, inputshape, x, y, z);

        case 'd':
        case 'D':
            inputshape.x = x * 2;
            inputshape.y = y;
            inputshape.z = z;
            keymovementevents(key, inputshape, x, y, z);
        
        case 'a':
        case 'A':
            inputshape.x = x * -2;
            inputshape.y = y;
            inputshape.z = z;
            keymovementevents(key, inputshape, x, y, z);
    }
}

void Keys::keymovementevents(unsigned char key, Polygon inputshape, float x, float y, float z) {
    Polygon outpoly;
    if(key == 'a' || key == 'A') {
        outpoly.x = inputshape.x * -2;
        outpoly.y = inputshape.y;
        outpoly.z = inputshape.z;
    }

    if(key == 's' || key == 'S') {
        outpoly.x = inputshape.x;
        outpoly.y = inputshape.y * -2;
        outpoly.z = inputshape.z;
    }

    if(key == 'w' || key == 'W') {
        outpoly.x = inputshape.x;
        outpoly.y = inputshape.y * 2;
        outpoly.z = inputshape.z;
    }

    if(key == 'd' || key == 'D') {
        outpoly.x = inputshape.x * 2;
        outpoly.y = inputshape.y;
        outpoly.z = inputshape.z;
    }

    if(key == 'd' && key == 'w' || key == 'D' && key == 'W') {
        outpoly.x = inputshape.x * 2;
        outpoly.y = inputshape.y * 2;
        outpoly.z = inputshape.z;
    }
    
    if(key == 'a' && key == 'w' || key == 'A' && key == 'W') {
        outpoly.x = inputshape.x * -2;
        outpoly.y = inputshape.y * 2;
        outpoly.z = inputshape.z;
    }
    
    if(key == 'a' && key == 's' || key == 'A' || key == 'S') {
        outpoly.x = inputshape.x * 2;
        outpoly.y = inputshape.y * -2;
        outpoly.z = inputshape.z;
    }
}

void Keys::keyrotation(unsigned char key, Polygon inputshape, float x, float y, float z) {
    Polygon outpoly;
    if(key == 'a' || key == 'A') {
        outpoly.x = inputshape.x * -2;
        outpoly.y = inputshape.y;
        outpoly.z = inputshape.z;
    }

    if(key == 's' || key == 'S') {

    }
    if(key == 'w' || key == 'W') {

    }
    if(key == 'd' || key == 'D') {

    }
}