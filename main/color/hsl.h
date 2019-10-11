#pragma once 
#ifdef HSL_H
#define HSL_H
#endif
#include "Color.h"
using namespace std;

class hsl {
	private:
		double h;
		float s, l;
	
	public:
		hsl() {

		}
		
		hsl(double hue, float saturation, float lightness) {
			this->h = hue;
			this->s = saturation;
			this->l = lightness;
			if(this->s > 1) {
				this->s = 1;
			}

			if(this->l > 1) {
				this->l = 1;
			}
		}
		double getHue();
		float getSaturation();
		float getLightness();
		void setHue(double hue);
		void setSaturation(float saturation);
		void setLightness(float lightness);
		Rgb HSLtoRGB();
		hsl getPredefinedHSL(char color);
		hsl RGBtoHSL(Rgb rgb);
		hsl makeHSL(hsl hsl);
};