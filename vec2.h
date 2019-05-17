#pragma once 
#ifdef VEC2_H
#define VEC2_H
#endif
#include<iostream>
using namespace std;

class Vector2 {
    private:
        float initx, inity;
    public:
        Vector2(float x, float y) {
            this->initx = x;
            this->inity = y;
        }

        float getPosX();
        float getPosY();

        void setPosX(float newx);
        void setPosY(float newy);

        void resetXY(char choice);
};