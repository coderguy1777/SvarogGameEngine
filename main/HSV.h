#pragma once
#ifdef HSV_H
#define HSV_H
#endif
using namespace std;
#include "color.h"
// HSV Class
class HSV {
	public:
		double hue = 0.0;
		float saturation = 0.0f;
		float value = 0.0f;

		HSV(double h, float s, float vb) {
			this->hue = h;
			this->saturation = s;
			this->value = vb;
		}

		HSV getPresetHSV(char hsv);
		void setHue(float h);
		void setSaturation(float s);
		void setValue(float v);
		
		HSV makeHSV(double h, float s, float v);

		double getHue();
		float getSaturation();
		float getValue();		

		Rgb HSVtoRGB();

};