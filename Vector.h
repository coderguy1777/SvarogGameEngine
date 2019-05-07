#pragma once
#ifndef VECTOR_H
#define VECTOR_H

#include "CoordinateStructs.h"
#include "EngineHeader.h"

class Vector {
private:

public:
	int x, y, z;

	Vector(int xpos, int ypos, int zpos) {
		this->x = xpos;
		this->y = ypos;
		this->z = zpos;
	}
	void setX(int x);
	void setY(int y);
	void setZ(int z);
	
	// gets vector x, y, z
	int getX();
	int getY();
	int getZ();

	// translates a vec
	void printX();


};
#endif