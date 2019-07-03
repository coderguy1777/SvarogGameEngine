#pragma once
#ifdef VEC4_H
#define VEC4_H
#endif
using namespace std;

class vec4 {
    public:
        float r, g, b, a;
        vec4(float r, float g, float b, float a) {
            this->r = r;
            this->g = g;
            this->b = b;
            this->a = a;
        }
        
        float getR();
        float getG();
        float getB();
        float getA();
};