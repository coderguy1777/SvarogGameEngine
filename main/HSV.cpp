#include "HSV.h"
double HSV::getHue() {
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

void HSV::setSaturation(float s) {
    saturation = s;
}


HSV HSV::makeHSV(double h, float s, float v) {
    return HSV((float)h, s, v);
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

Rgb HSV::HSVtoRGB() {
    float p, t, q, val = 0.0f;

    Rgb primeColor(0.0f, 0.0f, 0.0f);
    double hi = floor(fmod(hue / 60, 6));
    float f = hue/60 - hi;
    p = value * (1-saturation);
    q = value * (1-f*saturation);
    t = value * (1-(1-f)*saturation);

    if(floor(hi) == 0) {
        primeColor.redval = value;
        primeColor.greenval = t;
        primeColor.blueval = p;
    }

    if(floor(hi) == 1) {
        primeColor.redval = q;
        primeColor.greenval = value;
        primeColor.blueval = p;
    }

    if(floor(hi) == 2) {
        primeColor.redval = p;
        primeColor.greenval = floor(value * 255)/255;
        primeColor.blueval = t;
        std::cout << floor(primeColor.redval * 255) << " " << primeColor.greenval <<  " " << primeColor.blueval << std::endl;
    }
    return primeColor;
}
