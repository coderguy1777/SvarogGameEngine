#pragma once 
#ifdef HSL_H
#define HSL_H
#endif
#include "Color.h"
#include "EngineHeader.h"
using namespace std;

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
		Rgb HSLtoRGB();
		HSL RGBtoHSL(Rgb rgb);
		HSL makeHSL(HSL hsl);
};