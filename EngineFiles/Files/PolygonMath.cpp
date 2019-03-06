#include "GameEngineHeader.h"
#include "Polygon.h"
#include "PolygonMath.h"
using namespace std;

Polygon Vectors::vecAdding(Polygon a, Polygon b) {
    Polygon newvector;
    newvector.x = a.x + b.x;
    newvector.y = a.y + b.y;
    newvector.z = a.z + b.z;
    cout << " < " << newvector.x << " " << newvector.y << " " << newvector.z << " > " << endl;
    return newvector;
}

Polygon Vectors::vecSubtracting(Polygon a, Polygon b) {
    Polygon newvector;
    newvector.x = a.x - b.x;
    newvector.y = a.y - b.y;
    newvector.z = a.z - b.z;
    cout << " < " << newvector.x << " " << newvector.y << " " << newvector.z << " > " << endl;
    return newvector;
}

double Vectors::vecDistance(Polygon a, Polygon b) {
    double vectordistance;
    double vecdistsum = (b.x - a.x) + (b.y - a.y) + (b.z - a.z);
    vectordistance = sqrt(vecdistsum);
    return vectordistance;
}

Polygon Vectors::vecDotProduct(Polygon a, Polygon b) {
    Polygon newvector;
    newvector.x, newvector.y, newvector.z = (a.x * b.x) + (a.y * b.y) + (a.z + b.z);
    return newvector;
}