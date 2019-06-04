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
        void * operator new(size_t size) {
            void * vec2 = ::new Vector2(0.0f, 0.0f);
            return vec2;
        }
        
        Vector2 operator*(const Vector2 &b);
        Vector2 operator+(const Vector2 &b);
        Vector2 operator-(const Vector2 &b);
        Vector2 operator/(const Vector2 &b);
        void resetXY(char choice);
        void resetX();
        void resetY();
        Vector2 dotProduct(Vector2 veca, Vector2 vecb);
        Vector2 dotProductAngle(Vector2 veca, Vector2 vecb, double angle);

};