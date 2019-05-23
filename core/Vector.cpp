#include "Vector.h"
#include<cmath>
#include "math.h"
Math globalvar;

float Vector::translateX() {
	return x + 5.0f;
}

float Vector::translateY() {
	return y + 5.0f;
}

float Vector::translateZ() {
	return z + 5.0f;
}

Vector Vector::translateEntireVec() {
	return Vector(x + translateX(), y + translateY(), z + translateZ());
}

Vector Vector::addVec(Vector additional, Vector inital) {
	return inital + additional;
}

Vector Vector::getVector() {
	return Vector(x, y, z);
}

float Vector::getX() {
	return x;
}

float Vector::getY() {
	return y;
}

float Vector::getZ() {
	return z;
}

void Vector::changeX(float x)  {
	this->x = x;
}

void Vector::changeY(float y) {
	this->y = y;
}

void Vector::changeZ(float z) {
	this->z = z;
}

float Vector::vecMag(Vector a) {
	float mag = sqrt(globalvar.square(1, a.x - x) + globalvar.square(1, a.y - y) + globalvar.square(1, a.z - z));
	return mag;
}