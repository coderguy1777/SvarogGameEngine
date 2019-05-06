#pragma once
#ifdef COLORS_H
#define COLORS_H
#endif
#include "EngineHeader.h"
#include <cmath>
#include <algorithm>

struct rgba {
	float r, g, b;
};

// Color Class
class Color {
	private:
		float redval, greenval,  blueval;
	public:
		Color(float x, float y, float z) {
			this->redval = x/255;
			this->greenval = y/255;
			this->blueval = z/255;
		}

		void setRVal(float r);

		void setGVal(float g);

		void setBVal(float b);
		float getRed();
		float getGreen();
		float getBlue();
		void createColor();
		
		enum class COLORNAMES { RED, ORANGE, GREEN, YELLOW, BLUE, INDIGO, VIOLET};
};


// HSV Class
class HSV {
	private:
		float red, green, blue;
	public:
		float max(float x, float y, float z) {
			float max = x;
			if(y > max) {
				max = y;
			}

			if(z > max) {
				max = z;
			}
			return max;
		}

		float min(float x, float y, float z) {
			float min = x;
			if(y < min) {
				min = y;
			}
			
			if(z < min) {
				min = z;
			}
			return min;
		}

		float min2(float x, float y) {
			float min = x;
			if(y < min) {
				min = y;
			}
			return min;
		}
		float hue, saturation, value;
		const float rprime = red/256;
		const float gprime = green/256;
		const float bprime = blue/256;
		 float cmax = max(rprime, gprime, bprime);
		 float cmin = min(rprime, gprime, bprime);
		 float dChroma = cmax - cmin;

		HSV(float r, float g, float b) {
			this->red = r;
			this->green = g;
			this->blue = b;
		}

		float findHue();
		float findSaturation();
		float chromaVal();
		float findValue();
		float beta();
		float alpha();
		float findHue2();
		float findChroma2();
		void createHSV();
};