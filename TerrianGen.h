#pragma once
#include "EngineHeader.h"
#include "CoordinateStructs.h"
#include<vector>
class Terrian {
private:
	int posx, posy, posz;

public:
	Terrian(int x, int y, int z) {
		this->posx = x;
		this->posy = y;
		this->posz = z;
	}

	void noiseFunction();
	void genTerrian();
	float expandX();
};
