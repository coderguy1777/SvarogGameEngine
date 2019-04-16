#pragma once
#ifdef VECTOR_H
#define VECTOR_H
#endif 
#include<vector>
#include<iostream>
#include<math.h>

class Vector {
    private:


    public: 
        float x, y, z;
        Vector(float x, float y, float z) {
            this->x = x;
            this->y = y;
            this->z = z;
        }
        int size = 3;
        Vector unitvector(Vector initial);
        Vector twovecsum(Vector a, Vector b);
        Vector scalarprod(Vector scalarvec, float a);
        Vector dotproductvector(Vector proda, Vector prodb);
        Vector angletwovec(Vector a, Vector b);
        
};