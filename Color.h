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
	float r, g, b, a;
};

struct hsvval{
	float h, s, v;
};

// Color Class
class Color {
private:
	float redval, greenval, blueval, alphaval;
public:
	Color(float r, float g, float b, float alph) {
		this->redval = r;
		this->greenval = g;
		this->blueval = b;
		this->alphaval = alph;
	}
	void setRVal(float r);
	void setGVal(float g);
	void setBVal(float b);
	void setAlphaVal(float a);
	float getRed();
	float getAlpha();
	float getGreen();
	float getBlue();
	void createColor(void);
	enum COLORNAMES { RED = 1, ORANGE = 2, GREEN = 3, YELLOW = 4, BLUE = 5, INDIGO = 6, VIOLET = 7 };
	Color getPresetColors(char color);
	float* createGradient(float percentr, float percentg, float percentb);
};

// HSV Class
class HSV {
private:
	float red, green, blue;
public:
	float hue = 0.0f;
	float saturation = 0.0f;
	float value = 0.0f;

	HSV(float r, float g, float b) {
		this->red = r;
		this->green = g;
		this->blue = b;
	}

	float setHue(float hval) {
		float colorhue = 0.0f;
		if(floor(hval) >= 0 || hval <= 60) {
			colorhue = 255.0f;
		}

		if(hval >= 60 || hval <= 120) {
			colorhue = 125.0f;
		}

		if(hval >= 120 || hval <= 180) {
			colorhue = 90.0f;
		}

		if(hval >= 180 || floor(hval) <= 240) {
			colorhue = 190.0f;
		}

		if(hval >= 240 || hval <= 300) {
			colorhue = 165.0f;
		}

		if(hval >= 300 || hval <= 360) {
			colorhue = 255.0f;
		}
		return colorhue;
	}

	float getHue() {
		return hue;
	}

	float getValue() {
		return value;
	}

	float getSaturation() {
		return saturation;
	}

	void createHSV() {
		float primer = red / 255;
		float primeg = green / 255;
		float primeb = blue / 255;
		float max = std::max(std::max(primer, primeg), primeb);
		float min = std::min(std::min(primer, primeg), primeb);
		float delta = max - min;
	    value = max;
	    hue, saturation = 0.0f;

		if (max == primer) {
			hue = 60.0 * (primeg - primeb) / delta;
		}

		if (max == primeg) {
			hue = 60.0 * (((primeb - primer) / delta) + 2);
		}

		if (max == primeb) {
			hue = 60.0 * (((primer - primeg) / delta) + 4);
		}
		hue = setHue(hue)* 0.001;

		if (max == 0) {
			saturation = 0.0f;
		}

		if (max != 0) {
			saturation = delta / max;
		}
		glClearColor(hue, saturation, value, 0.0f);
	}
};

class HexColorCodes :public Color {
public:
	HexColorCodes(float redval, float greenval, float blueval, float alpha) :Color(redval, greenval, blueval, alpha) {}
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
				hexcode = HEXSTART + hexcodes[5] + hexcodes[5] + hexcodes[5] + hexcodes[5] + hexcodes[5];
				
			case 2:
				hexcode = HEXSTART + '0' + '0' + '0' + '0' + '0';
		}
	}
};