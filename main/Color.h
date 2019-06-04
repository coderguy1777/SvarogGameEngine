#pragma once
#ifdef COLORS_H
#define COLORS_H
#endif
#include "core/ArrayList.h"
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

class eightbit: public Rgb {
	public:
		float r,  g,  b;
		eightbit(float r, float b, float g):Rgb(r, g, b) {};
		eightbit RgbtoEightbit(Rgb wantedEightbit);
		float getRed();
		float getGreen();
		float getBlue();
		void setR(float r);
		void setG(float g);
		void setB(float b);

};

class adobeRGB: public Rgb {
	public:
		float r, g, b;
		adobeRGB(float r, float g, float b):Rgb(r, g, b){};
		adobeRGB RGBtoAdobeRGB(Rgb color);
		void setR(float r);
		void setG(float g);
		void setB(float b);
		void * operator new(size_t size) {
			void * p = new ::adobeRGB(0.0f, 0.0f, 0.0f);
			return p;
		}
};