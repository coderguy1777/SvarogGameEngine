#include "Vector.h"
using namespace std;

Vector Vector::unitvector(Vector initial) {
    float x1, y1, z1;
    x1 = initial.x / initial.size;
    y1 = initial.y / initial.size;
    z1 = initial.z / initial.size;
    Vector newUnitVec(x1, y1, z1);
    return newUnitVec;
}

Vector Vector::twovecsum(Vector a, Vector b) {
    vector<float>veca;
    vector<float>vecb;
    veca.push_back(a.x);
    veca.push_back(a.y);
    veca.push_back(a.z);
    vecb.push_back(b.x);
    vecb.push_back(b.y);
    vecb.push_back(b.z);

    for(unsigned int i = 0; i < veca.size(); i++) {
        for(unsigned int j = 0; j < vecb.size(); j++) {
            
        }
    }

}