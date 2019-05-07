#pragma once
#ifdef COLORS_H
#define COLORS_H
#endif
#include "EngineHeader.h"

#include<initializer_list>
#include <cmath>
#include <algorithm>

// rgba structure fo
struct rgba {
	float r, g, b;
};

// Color Class
class Color {
	private:
		float redval, greenval,  blueval;
	public:
		void setRVal(float r);
		void setGVal(float g);
		void setBVal(float b);
		float getRed();
		float getGreen();
		float getBlue();
		void createColor(void);
		enum COLORNAMES { RED = 1, ORANGE=2, GREEN=3, YELLOW=4, BLUE=5, INDIGO=6, VIOLET=7};
		void getPresetColors(int color);
};

// HSV Class
class HSV {
	private:
		float red, green, blue;
	public:
		float hue, saturation, value;
		const float rprime = red/256;
		const float gprime = green/256;
		const float bprime = blue/256;
		float cmax = std::max({ rprime, gprime, bprime });
		float cmin = std::min({ rprime, gprime, bprime });
		float dChroma = cmax - cmin;
		float chroma = 0.0f;

		HSV(float r, float g, float b) {
			this->red = r;
			this->green = g;
			this->blue = b;
		}

		float findHue();
		float findSaturation();
		float findHPrime();
		void findValue();
		float beta();
		float alpha();
		float findHue2();
		float findChroma2();
		void createHSV();
};