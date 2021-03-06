#include "vec2.h"
#include<cmath>

float Vector2::getPosX() {
    return this->initx;
}

float Vector2::getPosY() {
    return this->inity;
}

void Vector2::setPosX(float newx) {
    this->initx = newx;
}

void Vector2::setPosY(float newy) {
    this->inity = newy;
}

void Vector2::resetXY(char choice) {
    if(choice == 'x' || choice == 'X') {
        this->initx = 0.0f;
    } else if(choice == 'y' || choice == 'Y') {
        this->inity = 0.0f;
    }
}

Vector2 Vector2::operator+(const Vector2 &b) {
    Vector2 addvec(0.0f, 0.0f);
    addvec.initx = b.initx + this->initx;
    addvec.inity = b.inity + this->inity;
    return addvec;
}

Vector2 Vector2::operator-(const Vector2 &b) {
    Vector2 subvec(0.0f, 0.0f);
    subvec.initx = b.initx - this->initx;
    subvec.inity = b.inity - this->inity;
    return subvec;
}

Vector2 Vector2::operator*(const Vector2 &b) {
    Vector2 multvec(0.0f, 0.0f);
    multvec.initx = b.initx * this->initx;
    multvec.inity = b.inity * this->inity;
    return multvec;
}

Vector2 Vector2::operator/(const Vector2 &b) {
    Vector2 divvec(0.0f, 0.0f);
    divvec.initx = b.initx/this->initx;
    divvec.inity = b.inity/this->inity;
    return divvec;
}

void Vector2::resetX() {
    initx = 0.0f;
}

void Vector2::resetY() {
    inity = 0.0f;
}

Vector2 Vector2::dotProduct(Vector2 veca, Vector2 vecb) {
    return veca * vecb;
}

Vector2 Vector2::dotProductAngle(Vector2 veca, Vector2 vecb, double angle) {
    Vector2 vec_c(0.0f, 0.0f);
    float x_c, y_c, angle_c = 0.0f;
    x_c = abs(veca.initx * vecb.initx);
    y_c = abs(veca.inity * vecb.inity);
    angle_c = cos((float)angle);
    vec_c.setPosX(x_c);
    vec_c.setPosY(y_c);
    return vec_c;
}

float Vector2::dist_twoVectors(Vector2 veca, Vector2 vecb) {
    Vector2 distvec(veca-vecb);
    return abs(distvec.inity) - abs(distvec.inity);
}

float Vector2::angle_distVector(Vector2 distvec) {
    return atan2(distvec.initx, distvec.inity);
}

float Vector2::xToAngle(float pointX) {
    return cos(pointX);
}

float Vector2::yToAngle(float pointY) {
    return sin(pointY);
}

float Vector2::xAxisChange(float translationSize) {
    float x1 = translationSize + initx;
    float x0 = initx;
    return x1 - x0;
}

float Vector2::yAxisChange(float translationSize) {
    float y1 = translationSize + inity;
    float y0 = inity;
    return y1 - y0;
}

float Vector2::find_eulervec2d_norm(Vector2 a) {
    return sqrtf((pow(a.initx, 2) + (pow(a.inity, 2))));
}

Vector2 Vector2::unitVector2d(Vector2 a) {
    float h = atan2(a.inity, a.initx);
    float s = a.find_eulervec2d_norm(a);
    a.setPosX(cos(h));
    a.setPosY(sin(h));
    return a;
}

Vector2 Vector2::scalarAdd(Vector2 a, int sclr) {
    return a + sclr;
}

Vector2 Vector2::scalarSub(Vector2 a, int sclr) {
    return a - sclr;
}

Vector2 Vector2::scalarMult(Vector2 a, int sclr) {
    return a * sclr;
}

Vector2 Vector2::scalarDiv(Vector2 a, int sclr) {
    return a / sclr;
}

float Vector2::vec2Mag() {
    return sqrt((pow(this->initx, 2) + (pow(this->inity, 2))));
}