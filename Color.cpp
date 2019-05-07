#include "COLORS.h"
#include <vector>
#include <cmath>

void Color::setRVal(float r) {
	if (r < -1) {
		std::cout << "Please enter a larger color value for red!" << std::endl;
	}
	else {
		redval = r / 255;
	}
}

void Color::setGVal(float g) {
	if (g < -1) {
		std::cout << "Please enter a larger color value for green!" << std::endl;
	}
	else {
		greenval = g / 255;
	}
}

void Color::setBVal(float b) {
	if (b < -1) {
		std::cout << "Please enter a larger color value for blue!" << std::endl;
	}
	else {
		blueval = b / 255;
	}
}

float Color::getRed() {
	return redval;
}

float Color::getBlue() {
	return blueval;
}

float Color::getGreen() {
	return greenval;
}

void Color::getPresetColors(int color) {
	switch (color) {
		case COLORNAMES::RED:
			redval = 255.0f;
			greenval = 0.0f;
			blueval = 0.0f;

		case COLORNAMES::ORANGE:
			glClearColor(255, 89, 0, 0);

		case COLORNAMES::GREEN:
			glClearColor(0, 199, 0, 0);

		case COLORNAMES::YELLOW:
			glClearColor(235, 199, 0, 0);

		case COLORNAMES::BLUE:
			glClearColor(0, 0, 255, 0);

		case COLORNAMES::INDIGO:
			glClearColor(50, 50, 255, 0);

		case COLORNAMES::VIOLET:
			glClearColor(155, 0, 155, 0);
	}
}

void Color::createColor() {
	glClearColor(redval, greenval, blueval, 0.5);
}

float max(float a, float b, float c) {
	float max = a;
	if(max < b) {
		max = b;
	}

	if(max < c) {
		max = c;
	}
	std::cout << max << std::endl;
	return max;
}

float min(float a, float b, float c) {
	float max = a;
	if(max > b) {
		max = b;
	} else if(max > c) {
		max = c;
	} else {
		max = 0.0f;
	}
	return max;
}

float* Color::createGradient(float rpercent, float gpercent, float bpercent) {
	Color gradientparta(0, 0, 0);
	Color gradientpartb(0, 0, 0);
	for(int rval = 0; rval < 255; rval++) {
		if((int)rpercent == rval) {
			gradientparta.setRVal(rpercent * 255);
		}
	}

	for(int gval = 0; gval < 255; gval++) {
		if((int)gpercent == gval) {
			gradientparta.setGVal(gpercent*255);
		}
	}
}

// methods for HSV
void HSV::findHue() {
	float primer = red/255;
	float primeg = green/255;
	float primeb = blue/255;

	float maxcc = max(primer, primeg, primeb);
	float mincc = min(primer, primeg, primeb);
	float deltaChroma = maxcc - mincc;

	if(mincc == maxcc) {
		hue= 0.0f;
	}

	else if(rprime == maxcc) {
		hue = (primeg - primeb / maxcc - mincc)/6;
	} else if(gprime == maxcc) {
		hue = (2.0f + (primer - primeb)/(maxcc-mincc));
	} else if(bprime == maxcc) {
		hue =  255* (4.0f + (primer - primeg) / (maxcc - mincc));
	}
	value = maxcc;
	saturation = deltaChroma/value;

}

void HSV::createHSV() {
	float rhsv = value * saturation;
	std::cout << hue << " " << saturation << "  " << value << " "  <<  std::endl;
	glClearColor(hue * 255, saturation, value, 0.0f);
}

// html color codes
void HexColorCodes::getPredefinedcode(int code) {
	switch(code) {
		case 1:
			hexcode = WHITECODE;
		case 2:
			hexcode = predefcodes::BLACKCODE;
		case 3:
			hexcode = predefcodes::GREENCODE;
		case 4:
			hexcode = predefcodes::GRAYCODE;

	}
}
