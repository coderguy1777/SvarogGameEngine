#pragma once
#ifdef COLORS_H
#define COLORS_H
#endif
#include "EngineHeader.h"
#include<string>
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
		Color(float r, float g, float b) {
			this->redval = r;
			this->greenval = g;
			this->blueval = b;
		}
		void setRVal(float r);
		void setGVal(float g);
		void setBVal(float b);
		float getRed();
		float getGreen();
		float getBlue();
		void createColor(void);
		enum COLORNAMES { RED = 1, ORANGE=2, GREEN=3, YELLOW=4, BLUE=5, INDIGO=6, VIOLET=7};
		void getPresetColors(int color);
		float* createGradient(float percentr, float percentg, float percentb);
};

// HSV Class
class HSV {
	private:
		float red, green, blue;
	public:
		float hue, saturation, value;
	    float rprime = red/255;
	    float gprime = green/255;
	    float bprime = blue/255;
		float maxc = std::max(std::max(rprime, gprime), bprime);
		float minc = std::min(std::min(rprime, gprime), bprime);
		float chroma = 0.0f;

		HSV(float r, float g, float b) {
			this->red = r;
			this->green = g;
			this->blue = b;
		}

		void findHue();
		void createHSV();
};

class HexColorCodes:public Color {
	public:
		HexColorCodes(float redval, float greenval, float blue):Color(redval, greenval, blue){}
		const char HEXSTART = '#';
	    char hexcodes[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
								   'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

		const int MAXLENOFCODE = 6;
		std::string hexcode;
		enum predefcodes {
			WHITECODE,
			BLACKCODE,
			GREENCODE,
			GRAYCODE,
			REDCODE,
			BLUECODE,
			YELLOWCODE,
			ORANGECODE
		};

		void getPredefinedcode(int code);
};