#pragma once
#ifndef VECTOR_H
#define VECTOR_H

#include "CoordinateStructs.h"
#include "EngineHeader.h"

class Vector {
private:
	int x,  y,  z;

public:
	void setX(int x);
	void setY(int y);
	void setZ(int z);
	
	// gets vector x, y, z
	int getX();

	Vector operator*(const Vector& vectes) {
		Vector veca;
		veca.x = this->x * vectes.x;
		veca.y = this->y * vectes.y;
		veca.z = this->z * vectes.z;
		return veca;
	}
	Vector translatevec(Vector a);
};
#endif