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

Polygon Vectors::vecAngle(Polygon a, Polygon b) {
    Polygon newvectors;

    return newvectors;
}

Polygon Vectors::vecUnitvector(Polygon a, Polygon b) {
    Polygon newvector;

    float mata[3][3];
    float matb[3][3];

    for(unsigned int i = 0; i < 3; i++) {
        for(unsigned int j = 0; j < 3; j++) {
            mata[i][j] = a.x, a.y, a.z;
        }
    }
    for(unsigned int k = 0; k < 3; k++) {
        for(unsigned int l = 0; l < 3; l++) {
            matb[k][l] = b.x, b.y, b.z;
        }
    }
    for(unsigned int row = 0; row < 3; row++) {
        for(unsigned int col = 0; col < 3; col++) {
            cout << mata[row][col] << endl;
        }
    }




    return newvector;
}