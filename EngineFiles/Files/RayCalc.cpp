#include "RayCalc.h"
#include "GameEngineHeader.h"

void BasicRayCalculations::initalray(double x, double y, double z, double angle) {
    vector<veccoordinates>rayposition;
    rayposition.push_back({x, y, z});
    double originx, originy, originz = 0.0;
    vector<veccoordinates>origin;
    origin.push_back({originx, originy, originz});
    double vecmag;
    for(unsigned int intialpos = 0; intialpos < origin.size(); intialpos++) {
        for(unsigned int i = 0; i < rayposition.size(); i++) {
            double mag1 = rayposition[i].x - origin[intialpos].x;
            double mag1pow = pow(mag1, 2);
            double mag2 = rayposition[i].y - origin[intialpos].y;
            double mag2pow = pow(mag2, 2);
            double mag3 = rayposition[i].z - origin[intialpos].z;
            double mag3pow = pow(mag3, 2);
            vecmag = sqrt((mag1) + (mag2) + (mag3));
        }
    }

    // Vector Establishment of a vector.
    double vecoord1 = origin[0].x + rayposition[0].x;
    double vecoord2 = origin[1].y + rayposition[1].y;
    double vecoord3 = origin[2].z + rayposition[2].z;
    vector<veccoordinates>vectors;
    vectors.push_back({vecoord1, vecoord2, vecoord3});

    for(unsigned int k = 0; k < vectors.size(); k++) {
        cout << vectors[k].x << endl;
        cout << vectors[k].y << endl;
        cout << vectors[k].z << endl;
    }

}