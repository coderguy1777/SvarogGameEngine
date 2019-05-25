#pragma once
#ifdef COLORS_H
#define COLORS_H
#endif
#include "EngineHeader.h"
#include<string>
#include<initializer_list>
#include <cmath>
#include <algorithm>
#include<vector>

// Color Class
class Rgb {
	public:
		float redval, greenval, blueval;

		Rgb(float r, float g, float b) {
			this->redval = r;
			this->greenval = g;
			this->blueval = b;
		}
		void setRVal(float r);
		void setGVal(float g);
		void setBVal(float b);
		void setAlphaVal(float a);
		float getRed();
		float getAlpha();
		float getGreen();
		float getBlue();
		void createColor();
		enum COLORNAMES { RED = 1, ORANGE = 2, GREEN = 3, YELLOW = 4, BLUE = 5, INDIGO = 6, VIOLET = 7 };
		Rgb getPresetColors(char color);
		float* createGradient(float percentr, float percentg, float percentb);
		Rgb newColor();

};