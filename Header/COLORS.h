#pragma once
#include "EngineHeader.h"

struct rgba {
	float r, g, b;
};

class Color {
private:
	float redval, greenval,  blueval;
public:

	Color(float x, float y, float z) {
		this->redval = x;
		this->greenval = y;
		this->blueval = z;
	}

	virtual void Changer(float r) {
		redval = r;
	}

	virtual void Changeg(float g) {
		greenval = g;
	}

	virtual void Changeb(float b) {
		blueval = b;
	}
};