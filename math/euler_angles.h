#pragma once 
#ifdef EULER_ANGLES_H
#define EULER_ANGLES_H
#endif
#include "matrix.h"
class EulerAngle {
    public: 
        float angle;
        EulerAngle(float rotAngle) {
            this->angle = rotAngle;
        }

        virtual Matrix createXRotMat() {
            Matrix rotX;
            rotX.setC1Parts(1.0f, 0.0f, 0.0f);
            rotX.setC2Parts(0.0f, cosf(angle), -sinf(angle));
            rotX.setC3Parts(0.0f, -sinf(angle), cosf(angle));
            return rotX;
        }

        virtual Matrix createYRotMat() {
            Matrix rotY;
            rotY.setC1Parts(cosf(angle), 0.0f, -sinf(angle));
            rotY.setC2Parts(0.0f, 1.0f, 0.0f);
            rotY.setC3Parts(sinf(angle), 0.0f, cosf(angle));
            return rotY;
        }

        virtual Matrix createZRotMat() {
            Matrix rotZ;
            rotZ.setC1Parts(cosf(angle), sinf(angle), 0.0f);
            rotZ.setC2Parts(-sinf(angle), cosf(angle), 0.0f);
            rotZ.setC3Parts(0.0f, 0.0f, 1.0f);
            return rotZ;
        }
};