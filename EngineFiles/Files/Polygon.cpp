#include "GameEngineHeader.h"
#include "Polygon.h"
using namespace std;


void Polygon::setPolygon(Polygon p, float x, float y, float z) {
    p.x = x;
    p.y = y;
    p.z = z;
    cout << p.x << endl;
    cout << p.y << endl;
    cout << p.z << endl;
}

Polygon Polygon::getPolygon(Polygon p) {
    cout << p.x << endl;
    cout << p.y << endl;
    cout << p.z << endl;
    return p;
}