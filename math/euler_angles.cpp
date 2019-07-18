#include "euler_angles.h"
Point3D EulerAngle::rotatedPoints(Point3D pos, int axis) {
    Point3D newPoints;
    ROTCASES axisX = ROTCASES::axis_X;
    ROTCASES axisY = ROTCASES::axis_Y;
    ROTCASES axisZ = ROTCASES::axis_Z;
    if(axis == static_cast<int>(axisX)) {
        Matrix Xrot(createXRotMat());
        ArrayList<float>r1X = Xrot.getRow(1);
        float points[3] {pos.x, pos.y, pos.z};
        for(unsigned int i = 0; i < r1X.size(); i++) {
            newPoints.x += r1X.get(i) * points[0];
            newPoints.y += r1X.get(i) * points[1];
            newPoints.z += r1X.get(i) * points[2];
        }
    }

    if(axis == static_cast<int>(axisY)) {
        Matrix Yrot(createYRotMat());
        ArrayList<float>r1Y = Yrot.getRow(2);
        float points[3] {pos.x, pos.y, pos.z};
        for(unsigned int j = 0; j < r1Y.size(); j++) {
            newPoints.x += r1Y.get(j) * points[0];
            newPoints.y += r1Y.get(j) * points[1];
            newPoints.z += r1Y.get(j) * points[2];
        }
    }

    if(axis == static_cast<int>(axisZ)) {
        Matrix Zrot(createZRotMat());
        ArrayList<float>r1Z = Zrot.getRow(3);
        float points[3]{pos.x, pos.y, pos.z};
        for(unsigned int k = 0; k < 3; k++) {
            newPoints.x += r1Z.get(k) * points[0];
            newPoints.y += r1Z.get(k) * points[1];
            newPoints.z += r1Z.get(k) * points[2];
        }
    }
    return newPoints;
}