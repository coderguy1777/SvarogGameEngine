#include "Point.h"
#include "GameEngineHeader.h"
#include<iostream>

// Gets the X Point of the Vertex in 3d Space
double Vertex::getX(Vertex inputvert) {
    return (float)inputvert.x;
}

// Gets the Y Point of the Vertex in 3d space
double Vertex::getY(Vertex inputvert) {
    return (float)inputvert.y;
}

double Vertex::getZ(Vertex inputvert) {
    return (float)inputvert.z;
}

double Vertex::setX(Vertex inputvert, double x) {
    inputvert.x = x;
    return inputvert.x;
}

double Vertex::setY(Vertex inputvert, double y) {
    inputvert.y = y;
    return inputvert.y;
}

double Vertex::setZ(Vertex inputvert, double z) {
    inputvert.z = z;
    return inputvert.z;
}

// Adds Vertexs for up on the XY Plane
Vertex Vertex::XYPlaneAdd(Vertex x, Vertex y) {
    double xpoint = x.x + y.x;
    double ypoint = x.y + y.y;
    double zpoint = x.z + y.z;
    Vertex XYNewPoint(xpoint, ypoint, zpoint);
    return XYNewPoint;
}

// Adds the Vertexs up for the XZ Plane
Vertex Vertex::XZPlaneAdd(Vertex x, Vertex z) {
    double xpoint = x.x + z.x;
    double ypoint = x.y + z.y;
    double zpoint = x.z + z.z;
    Vertex XZNewPoint(xpoint, ypoint, zpoint);
    return XZNewPoint;
}

// Prints the Vertex in 3d space
void Vertex::printVertex(Vertex a) {
    cout << "< " << a.x << " " << a.y << " " << a.z << " >" << endl;
}

double Vertex::MeanofPoints(double x, double y, double z) {
    vector<double>points;
    points.push_back(x);
    points.push_back(y);
    points.push_back(z);
    double mean = 0;
    for(unsigned int i = 0; i < points.size(); i++) {
        mean += points[i]/points.size();
    }
    return mean;
}

Vertex Vertex::ScalarMove(Vertex in, double meanofpoints) {
    vector<double>listofpoints;
    listofpoints.push_back(in.x);
    listofpoints.push_back(in.y);
    listofpoints.push_back(in.z);
    for(unsigned int i = 0; i < listofpoints.size(); i++) {
        listofpoints[i] = listofpoints[i] + meanofpoints;
    }
    double x, y, z;
    x = listofpoints[0];
    y = listofpoints[1];
    z = listofpoints[2];
    Vertex finalvert(x, y, z);
    return finalvert;
}
