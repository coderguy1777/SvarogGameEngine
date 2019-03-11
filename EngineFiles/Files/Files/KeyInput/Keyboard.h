#pragma once
#ifdef KEYBOARD_H
#define KEYBOARD_H
#endif
#include "Polygon.h"
#include "GameEngineHeader.h"
using namespace std;

class Keys {
    private:
        vector<veccoordinates>initialpos;

    public:
        void keydetect(unsigned char key,Polygon inputshape, float x, float y, float z);
        void keyrotation(unsigned char key, Polygon inputshape, float x, float y, float z);
        void keymovementevents(unsigned char key, Polygon inputshape, float x, float y, float z);

};