#pragma once 
#ifdef VEC2_H
#define VEC2_H
#endif
#include<iostream>
#include "Point.h"
using namespace std;

class Vector2 {
    private:
        float initx, inity;
    public:
        Vector2(float x, float y) {
            this->initx = x;
            this->inity = y;
        }

        Vector2(Point2D point) {
            this->initx = point.x;
            this->inity = point.y;
            point.originx = 0.0f;
            point.originy = 0.0f;
        }
        Vector2(){};
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
        friend Vector2 operator+(const Vector2 &b, int &sclr) {
            b.initx += sclr;
            b.inity += sclr;
            return b;
        }

        friend Vector2 operator-(const Vector2 &b, int &sclr) {
            b.initx -= sclr;
            b.inity -= sclr;
            return b;
        }

        friend Vector2 operator*(const Vector2 &b, int &sclr) {
            b.initx *= sclr;
            b.inity *= sclr;
            return b;
        }

        friend Vector2 operator/(const Vector2 &b, int &sclr) {
            b.initx /= sclr;
            b.inity /= sclr;
            return b;
        }

        friend Vector2 operator*(const Vector2 &b, float &sclr) {
            b.initx *= sclr;
            b.inity *= sclr;
            return b;
        }

        Vector2 scalarAdd(Vector2 a, int sclr);
        Vector2 scalarSub(Vector2 a, int sclr);
        Vector2 scalarMult(Vector2 a, int sclr);
        Vector2 scalarDiv(Vector2 a, int sclr);

        void resetXY(char choice);
        void resetX();
        void resetY();
        Vector2 dotProduct(Vector2 veca, Vector2 vecb);
        Vector2 dotProductAngle(Vector2 veca, Vector2 vecb, double angle);
        float dist_twoVectors(Vector2 veca, Vector2 vecb);
        float angle_distVector(Vector2 distvec);
        float xToAngle(float pointX);
        float yToAngle(float pointY);
        float xAxisChange(float translationSize);
        float yAxisChange(float translationSize);
        float find_eulervec2d_norm(Vector2 a);
        float vec2Mag();
        Vector2 unitVector2d(Vector2 a);
};