#include "vec3.h"
#include "math/math.h"
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

Vector3 Vector3::vec3ScalarSub(Vector3 a, int scalar) {
    return a - scalar;
}

Vector3 Vector3::vec3ScalarMult(Vector3 a, int scalar) {
    return a*scalar;
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

void Vector3::toOrigin() {
    initx = 0.0f;
    inity = 0.0f;
    initz = 0.0f;
}

Vector3 Vector3::mult(Vector3 veca, Vector3 vecb) {
    return veca * vecb;
}

Vector3 Vector3::add(Vector3 veca, Vector3 vecb) {
    return veca + vecb;
}

Vector3 Vector3::sub(Vector3 veca, Vector3 vecb) {
    return veca - vecb;
}

Vector3 Vector3::div(Vector3 veca, Vector3 vecb) {
    return veca/vecb;
}

Vector3 Vector3::scalarMult(Vector3 veca, int scalar) {
    Vector3 scaled(veca);
    scaled.setComponentX(scaled.initx * scalar);
    scaled.setComponentY(scaled.inity * scalar);
    scaled.setComponentZ(scaled.initz * scalar);
    return scaled;
}

inline Vector3 Vector3::dotProd_andAngle(Vector3 a, Vector3 b, float angle) {
    return (a * b) * cos(angle);
}

inline float dotProd(Vector3 a, Vector3 b) {
    float dotProd = (a.initx * b.initx) + (a.inity * b.inity) + (a.initz + b.initz);
    return dotProd;
}

inline float Vector3::twoVecAngle(Vector3 a, Vector3 b) {
    float dotprod = dotProd(a, b);
    float mag = vec3Mag(a);
    float magb = vec3Mag(b);
    float finalmag = mag*magb;
    return acos(dotProd(a,b)/finalmag);
}

inline Vector3 Vector3::unitVecAngles(Vector3 u, float iangle, float jangle, float kangle) {
    float u_x = u.initx * 1 * cos(iangle);
    float u_y = u.inity * 1 * cos(jangle);
    float u_z = u.initz * 1 * cos(kangle);
    return Vector3(u_x, u_y, u_z);
}