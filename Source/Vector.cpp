#include "Vector.h"

Vector Vector::translatevec(Vector a) {
	return Vector::operator*(a);
}

void Vector::setX(int x) {
	this->x = x;
}

void Vector::setY(int y) {
	this->y = y;
}

void Vector::setZ(int z) {
	this->z = z;
}

int Vector::getX() {
	return x;
}