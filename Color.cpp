#include "Color.h"

float Color::getBlue() {
    return blueval;
}

float Color::getRed() {
    return redval;
}

float Color::getGreen() {
    return greenval;
}

float Color::getAlpha() {
    return alphaval;
}

void Color::setAlphaVal(float a) {
    alphaval = a;
}

void Color::setRVal(float r) {
    redval = r;
}

void Color::setGVal(float g) {
    greenval = g;
}

void Color::setBVal(float b) {
    blueval = b;
}

void Color::createColor() {
    glClearColor(redval, greenval, blueval, alphaval);
}

Color Color::getPresetColors(char color) {
    Color returnval(0.0f, 0.0f, 0.0f, 0.0f);
    if(color == 'R') {
        returnval.setRVal(255.0f);
        returnval.setGVal(0.0f);
        returnval.setBVal(0.0f);
    }

    if(color == 'G') {
        returnval.setRVal(0.0f);
        returnval.setGVal(255.0f);
        returnval.setBVal(0.0f);
    }

    if(color == 'B') {
        returnval.setRVal(0.0f);
        returnval.setGVal(0.0f);
        returnval.setBVal(255.0f);
    }

    if(color == 'Y') {
        returnval.setRVal(75.0f);
        returnval.setGVal(75.0f);
        returnval.setBVal(75.0f);
    }

    if(color == 'W') {
        returnval.setRVal(255.0f);
        returnval.setGVal(255.0f);
        returnval.setBVal(255.0f);
    }

    if(color == 'M') {
        returnval.setRVal(255.0f);
        returnval.setGVal(0.0f);
        returnval.setBVal(255.0f);
    }

    if(color == 'C') {
        returnval.setRVal(0.0f);
        returnval.setGVal(255.0f);
        returnval.setBVal(255.0f);
    }

    return returnval;
}

float HSV::getHue() {
    return hue;
}

float HSV::getSaturation() {
    return saturation;
}

float HSV::getValue() {
    return value;
}

void HSV::setValue(float v) {
    value = v;
}

void HSV::setHue(float h) {
    hue = h;
}

HSV HSV::createHSV() {
    HSV newHSV(0.0f, 0.0f, 0.0f);
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

	if (max == 0) {
		saturation = 0.0f;
	}

	if (max != 0) {
		saturation = delta / max;
	}

    newHSV.setHue(hue);
    newHSV.setSaturation(saturation);
    newHSV.setValue(value);
    return newHSV;
}

HSV HSV::getPresetHSV(char hsv) {
    HSV predefhsv(0.0f, 0.0f, 0.0f);
    if(hsv == 'B') {
        predefhsv.setHue(0.0f);
        predefhsv.setSaturation(0.0f);
        predefhsv.setValue(0.0f);
    }

    if(hsv == 'W') {
        predefhsv.setHue(0.0f);
        predefhsv.setSaturation(0.0f);
        predefhsv.setValue(100.0f);
    }

    if(hsv == 'R') {
        predefhsv.setHue(0.0f);
        predefhsv.setSaturation(100.0f);
        predefhsv.setValue(50.0f);
    }

    if(hsv == 'G') {
        predefhsv.setHue(120.0f);
        predefhsv.setSaturation(100.0f);
        predefhsv.setValue(100.0f);
    }

    if(hsv == 'C') {
        predefhsv.setHue(180.0f);
        predefhsv.setSaturation(100.0f);
        predefhsv.setValue(100.0f);
    }

    if(hsv == 'M') {
        predefhsv.setHue(300.0f);
        predefhsv.setSaturation(100.0f);
        predefhsv.setValue(100.0f);
    }

    if(hsv == 'Y') {
        predefhsv.setHue(60.0f);
        predefhsv.setSaturation(100.0f);
        predefhsv.setValue(100.0f);
    }

    return predefhsv;
}

float CMYKVALS::getCyan() {
    return c;
}

float CMYKVALS::getKblack() {
    return k;
}

float CMYKVALS::getMagenta() {
    return m;
}

float CMYKVALS::getYellow() {
    return y;
}

void CMYKVALS::setBlack(float kblack) {
    k = kblack;
}

void CMYKVALS::setCyan(float cyan) {
    c = cyan;
}

void CMYKVALS::setMagenta(float magenta) {
    m = magenta;
}

void CMYKVALS::setYellow(float yellow) {
    y = yellow;
}

float CMYKVALS::findRPrime(float red) {
    float primer = red/255;
    return primer;
}

float CMYKVALS::findGPrime(float green) {
    float primeg = green/255;
    return primeg;
}

float CMYKVALS::findBPrime(float blue) {
    float primeb = blue/255;
    return primeb;
}

float CMYKVALS::findK(float primer, float primeg, float primeb) {
    float black = 1-(std::max(std::max(primer, primeg), primeb));
    return black;
}

float CMYKVALS::findC(float primer, float kval) {
    float cyanvalue = (1-primer-kval) / (1-kval);
    return cyanvalue;
}

float CMYKVALS::findM(float primeg, float kval) {
    float magentavalue = (1-primeg-kval) / (1-kval);
    return magentavalue;
}

float CMYKVALS::findY(float primeb, float kval) {
    float yellowval = (1-primeb-kval) / (1-kval);
    return yellowval;
}

float* CMYKVALS::CMYKtoRGB(float colorvals[4]) {
    float colors[4];
    return colors;
}

float* CMYKVALS::RGBtoCMYK(float colorvals[4]) {
    float test[4];
    return test;
}

float CMYKVALS::findR(float cval, float kval) {
    float red = 255 * (1 - cval) * (1-kval);
    return red;
}

float CMYKVALS::findG(float mval, float kval)  {
    float green = 255 * (1 - mval) * (1-kval);
    return green;
}

float CMYKVALS::findB(float yval, float kval) {
    float blue = 255 * (1-yval) * (1-kval);
    return blue;
}
