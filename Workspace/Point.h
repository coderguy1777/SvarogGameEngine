#pragma once
#ifdef POINT_H
#define POINT_H
#endif
#include<vector>
using namespace std; 

class Vertex {
    private:

    public:
        double x;
        double y;
        double z;
        Vertex(double x, double y, double z) {
            this->x = (float)x;
            this->y = (float)y;
            this->z = (float)z;
        }

        // Retrives either the X, y, or z, of a given vertex.
        double getX(Vertex input);
        double getY(Vertex input);
        double getZ(Vertex input);

        // Sets either the X, Y, or Z, of a s
        double setX(Vertex input, double x);   
        double setY(Vertex input, double y);
        double setZ(Vertex input, double z);

        // For adding Vertex's on all Planes
        Vertex XYPlaneAdd(Vertex x, Vertex y);
        Vertex XZPlaneAdd(Vertex x, Vertex z);
        Vertex YXPlaneAdd(Vertex y, Vertex x);
        Vertex YZPlaneAdd(Vertex y, Vertex z);

        // Mean of points
        double MeanofPoints(double x, double y, double z);

        // Use for scalars for point transform
        Vertex ScalarMove(Vertex x, double avg);

        // for printing the vertex
        Vertex printVertex(Vertex inputa);

        // Translates Vertex up 1
        Vertex up1(Vertex input);
        
    
};