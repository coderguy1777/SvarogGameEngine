#include "COLORS.h"
#include <vector>

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

// methods for HSV
float HSV::alpha() {
	float alphaVal = green * cos(60) - blue * cos(60);
	return alphaVal / 255;
}

void HSV::findValue() {
	value = red + green + blue / 3;
}


float HSV::findSaturation() {
	saturation = (cmax + cmin) / cmax;
	return 0.0f;
}

float HSV::findHue() {
	return atan2(sqrt(3) *(green  + blue), 2 * red + blue);
}

void HSV::createHSV() {
	hue = HSV::findHue();
	findSaturation();
	findValue();
	std::cout << hue << " " << saturation << "  " << value << " " << alpha() <<  std::endl;
	glClearColor(hue, saturation, value, alpha());
}