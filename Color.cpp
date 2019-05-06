#include "COLORS.h"
#include <vector>


void Color::setRVal(float r) {
    redval = r;
}

void Color::setGVal(float g) {			
    greenval = g;
}

void Color::setBVal(float b) {
	blueval = b;
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

void Color::createColor() {
    glClearColor(redval, greenval, blueval, 0.5);
}

float HSV::beta() {
    float betaVal = green * sin(60) - blue * sin(60);
    return betaVal;
}

float HSV::alpha() {
    float alphaVal = green * cos(60) - blue * cos(60);
	return alphaVal;
}

float HSV::findValue() {
    return HSV::max(red, green, blue);;
}

float HSV::findHue2() {
    return atan2(alpha(), beta());
}

float HSV::findChroma2() {
    float chroma_2 = sqrt(exp2(alpha() + exp2(beta())));
	return chroma_2;
}

float HSV::chromaVal() {
    float chroma = 0.0f;
	float Maxval = HSV::max(red, green, blue);
	float Minval = HSV::min(red, green, blue);
	chroma = Maxval - Minval;
	return chroma;
}

float HSV::findSaturation() {
    return dChroma/cmax;
}

float HSV::findHue() { 
    return atan2( (green - blue), 2 * red - blue);
}

void HSV::createHSV() {
    hue = HSV::findHue();
    saturation = HSV::findSaturation();
    value = HSV::findValue();
    std::cout << hue << " " << saturation << "  " << value << std::endl;

    glClearColor(HSV::findHue(), HSV::findSaturation(), HSV::findValue(), 0.1f);
}