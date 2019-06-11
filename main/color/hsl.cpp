#include "hsl.h"
double hsl::getHue() {
    return this->h;
}

float hsl::getSaturation() {
    return this->s;
}

float hsl::getLightness() {
    return this->l;
}

void hsl::setHue(double hue) {
    this->h = hue;
}

void hsl::setSaturation(float saturation) {
    this->s = saturation;
}

void hsl::setLightness(float lightness) {
    this->l = lightness;
}

Rgb hsl::HSLtoRGB() {
    Rgb newRgb(0.0f, 0.0f, 0.0f);
    double C, X, M = 0;
    float newr, newg, newb = 0.0f;
    C = (1-abs((2 * l) - 1)) * s;
    X = C * (1-abs((h/60.0)));
    X = fmod(X, 1);
    M = l - C/2;

    if(h >= 0.0 || h < 60.0) {
        newr = (float)C;
        newg = (float)X;
        newb = 0.0f;
    }

    if(h >= 60.0 || h < 120.0) {
        newr = (float)X;
        newg = (float)C;
        newb = 0.0f;
    }

    if(h >= 120.0 || h < 180.0) {
        newr = 0.0f;
        newg = (float)C;
        newb = (float)X;
    }

    if(h >= 180.0 || h < 240.0) {
        newr = 0.0f;
        newg = (float)X;
        newb = (float)C;
    }

    if(h >= 240.0 || h < 300.0) {
        newr = (float)X;
        newg = 0.0f;
        newb = (float)C;
    }

    if(h >= 300.0 || h < 360.0) {
        newr = (float)C;
        newg = 0.0f;
        newb = (float)X;
    } 

    else {
        newr = 0.0f;
        newg = 0.0f;
        newb = 0.0f;
    }

    newr = (newr+M) * 255;
    newg = (newg+M) * 255;
    newb = (newb+M) * 255;
    newRgb.setRVal(newr);
    newRgb.setGVal(newg);
    newRgb.setBVal(newb);
    return newRgb;
}

hsl hsl::getPredefinedHSL(char color) {
    hsl wantedHSL(0.0, 0.0f, 0.0f);
    if(color == 'R') {
        wantedHSL.setHue(0.0);
        wantedHSL.setSaturation(1.0f);
        wantedHSL.setLightness(0.50f);
    }

    if(color == 'G') {
        wantedHSL.setHue(120.0);
        wantedHSL.setSaturation(1.0f);
        wantedHSL.setLightness(0.25f);
    }

    if(color == 'B') {
        wantedHSL.setHue(240.0);
        wantedHSL.setSaturation(1.0f);
        wantedHSL.setLightness(0.50f);    
    }

    if(color == 'Y') {
        wantedHSL.setHue(60.0);
        wantedHSL.setSaturation(1.0f);
        wantedHSL.setLightness(0.50f);
    }

    if(color == 'O') {
        wantedHSL.setHue(39.0);
        wantedHSL.setSaturation(1.0f);
        wantedHSL.setLightness(0.50f);
    }
     
    else {
        wantedHSL.setHue(0.0);
        wantedHSL.setSaturation(0.0f);
        wantedHSL.setLightness(0.0f);
    }
    return wantedHSL;
}