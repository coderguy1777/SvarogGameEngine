#include "vec3.h"
#include "core/math.h"
using namespace std;

float Vector3::getComponentX() {
    return this->initx;
}

float Vector3::getComponentY() {
    return this->inity;
}

float Vector3::getComponentZ() {
    return this->initz;
}

void Vector3::setComponentX(float x) {
    this->initx = x;
}

void Vector3::setComponentY(float y) {
    this->inity = y;
}

void Vector3::setComponentZ(float z) {
    this->initz = z;
}

float* Vector3::vec3Scalar(int scalar) {
    float vecscale[3];
    vecscale[0] = scalar * this->initx;
    vecscale[1] = scalar * this->inity;
    vecscale[2] = scalar * this->initz;
    return vecscale;
}

float Vector3::vec3Mag(Vector3 b) {
    float mag =  (b.initx - this->initx) + (b.inity - this->inity) + (b.initz - this->initz);
    return mag;
}

void Vector3::resetXYZ(char choice) {
    if(choice == 'X' || choice == 'x') {
        this->initx = 0.0f;
    } else if(choice == 'Y' || choice == 'y') {
        this->inity = 0.0f;
    } else if(choice == 'Z' || choice == 'z') {
        this->initz = 0.0f;
    } else {
        cout << "Your choice character: " << choice << " is not a valid option, fix the character inputted to fix this!" << endl;
    }
}