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

// rgba structure fo
struct rgba {
	float r, g, b, a;
};

struct hsvval{
	double h;
	float s;
	float v;
};

// Color Class
class Color {
	public:
		float redval, greenval, blueval;

		Color(float r, float g, float b) {
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
		Color getPresetColors(char color);
		float* createGradient(float percentr, float percentg, float percentb);
		Color newColor();
		std::vector<hsvval>ytes;

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

		HSV getPresetHSV(char hsv);
		void setHue(float h);
		void setSaturation(float s);
		void setValue(float v);
		
		HSV makeHSV(double h, float s, float v);

		float getHue();
		float getSaturation();
		float getValue();
		HSV createHSV();
		

		Color HSVtoRGB(HSV test);

};

class HexColorCodes : public Color {
	public:
		HexColorCodes(float redval, float greenval, float blueval) :Color(redval, greenval, blueval) {}
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
		void getPredefinedcode(int code);
		void RGBtoHEX(float redval, float greenval, float blueval);
		
};

struct cmyk {
	float c, m, y, k;
};

class CMYKVALS {
	public:
		float c, m, y, k;
		CMYKVALS(float cyan, float magenta, float yellow, float black) {
			this->c = cyan;
			this->m = magenta;
			this->y = yellow;
			this->k = black;
		}

		void setCyan(float c);
		void setBlack(float b);
		void setYellow(float y);
		void setMagenta(float m);

		// gets cmyk vals
		float getCyan();
		float getMagenta();
		float getYellow();
		float getKblack();

		// prime vals
		float findRPrime(float red);
		float findGPrime(float green);
		float findBPrime(float blue);

		// CMYK vals
		float findK(float primer, float primeg, float primeb);
		float findC(float primer, float kval);
		float findM(float primeg, float kval);
		float findY(float primeb, float kval);

		// finding RGB Vals
		float findR(float cval, float kval);
		float findG(float mval, float kval);
		float findB(float yval, float kval);

		// returns cmyk
		CMYKVALS newCMYK();

		// float val creation 
		CMYKVALS RGBtoCMYK(float rval, float gval, float bval);
		Color CMYKtoRGB(float cval, float mval, float yval, float kval);
};

template<class H, class S, class L>
	struct hsl {
		double h;
		float s,l;
	};
class HSL {
	private:
		double h;
		float s, l;
	
	public:
		HSL(double hue, float saturation, float lightness) {
			this->h = hue;
			this->s = saturation;
			this->l = lightness;
		}
		double getHue();
		float getSaturation();
		float getLightness();

		void setHue(double hue);
		void setSaturation(float saturation);
		void setLightness(float lightness);
		Color HSLtoRGB();
		HSL RGBtoHSL(Color rgb);
		HSL makeHSL(HSL hsl);
};