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
	float redval, greenval, blueval;
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
	enum COLORNAMES { RED = 1, ORANGE = 2, GREEN = 3, YELLOW = 4, BLUE = 5, INDIGO = 6, VIOLET = 7 };
	void getPresetColors(int color);
	float* createGradient(float percentr, float percentg, float percentb);
};

// HSV Class
class HSV {
private:
	float red, green, blue;
public:
	float chroma = 0.0f;

	HSV(float r, float g, float b) {
		this->red = r;
		this->green = g;
		this->blue = b;
	}

	void createHSV() {
		float primer = red / 255;
		float primeg = green / 255;
		float primeb = blue / 255;
		float max = std::max(std::max(primer, primeg), primeb);
		float min = std::min(std::min(primer, primeg), primeb);
		float delta = max - min;
		float value = max;
		float hue, saturation = 0.0f;

		if (max == primer) {
			hue = 60.0 * (primeg - primeb) / delta;
		}

		if (max == primeg) {
			hue = 60.0 * (((primeb - primer) / delta) + 2);
		}

		if (max == primeb) {
			hue = 60.0 * (((primer - primeg) / delta) + 4);
		}

		if (max == 0) {
			saturation = 0.0f;
		}

		if (max != 0) {
			saturation = delta / max;
		}

		std::cout << hue << " " << saturation << " " << value << std::endl;
		hue = hue /100;
		glClearColor(hue, saturation, value, 0.0f);
	}
};

class HexColorCodes :public Color {
public:
	HexColorCodes(float redval, float greenval, float blue) :Color(redval, greenval, blue) {}
	const char HEXSTART = '#';
	char hexcodes[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
							   'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

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

	void getPredefinedcode(int code) {
		switch(code) {
			case 1:
				
		}
	}
};