#include "hsl.h"
double HSL::getHue() {
    return this->h;
}

float HSL::getSaturation() {
    return this->s;
}

float HSL::getLightness() {
    return this->l;
}

void HSL::setHue(double hue) {
    this->h = hue;
}

void HSL::setSaturation(float saturation) {
    this->s = saturation;
}

void HSL::setLightness(float lightness) {
    this->l = lightness;
}

Rgb HSL::HSLtoRGB() {
    Rgb newRgb(0.0f, 0.0f, 0.0f);
    
}