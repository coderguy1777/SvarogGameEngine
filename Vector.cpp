#include "Vector.h"

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

int Vector::getY() {
	return y;
}

int Vector::getZ() {
	return z;
}

void Vector::printX() {
	std::cout << x << std::endl;
}