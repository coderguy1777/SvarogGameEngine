#include "Color.h"
float Rgb::getBlue() {
    return blueval;
}

float Rgb::getRed() {
    return redval;
}

float Rgb::getGreen() {
    return greenval;
}

float Rgb::getAlpha() {
    return 1.0f;
}

void Rgb::setRVal(float r) {
    redval = r;
}

void Rgb::setGVal(float g) {
    greenval = g;
}

void Rgb::setBVal(float b) {
    blueval = b;
}

Rgb Rgb::newColor() {
    return Rgb(redval, greenval, blueval);
}

Rgb Rgb::getPresetColors(char rgb) {
    Rgb returnval(0.0f, 0.0f, 0.0f);

    if(rgb == 'R') {
        returnval.setRVal(255.0f);
        returnval.setGVal(0.0f);
        returnval.setBVal(0.0f);
    }

    if(rgb == 'G') {
        returnval.setRVal(0.0f);
        returnval.setGVal(255.0f);
        returnval.setBVal(0.0f);
    }

    if(rgb == 'B') {
        returnval.setRVal(0.0f);
        returnval.setGVal(0.0f);
        returnval.setBVal(255.0f);
    }

    if(rgb == 'Y') {
        returnval.setRVal(75.0f);
        returnval.setGVal(75.0f);
        returnval.setBVal(75.0f);
    }

    if(rgb == 'W') {
        returnval.setRVal(255.0f);
        returnval.setGVal(255.0f);
        returnval.setBVal(255.0f);
    }

    if(rgb == 'M') {
        returnval.setRVal(255.0f);
        returnval.setGVal(0.0f);
        returnval.setBVal(255.0f);
    }

    if(rgb == 'C') {
        returnval.setRVal(0.0f);
        returnval.setGVal(255.0f);
        returnval.setBVal(255.0f);
    }
    return returnval;
}

void eightbit::setR(float red) {
    r = red;
}

void eightbit::setG(float green) {
    g = green;
}

void eightbit::setB(float blue) {
    b = blue;
}

eightbit eightbit::RgbtoEightbit(Rgb color) {
    eightbit convertedrgb(0.0f, 0.0f, 0.0f);
    float primer, primeg, primeb = 0.0f;
    primer = color.redval/255;
    primeg = color.greenval/255;
    primeb = color.blueval/255;
    convertedrgb.setR(primer);
    convertedrgb.setG(primeg);
    convertedrgb.setB(primeb);
    return convertedrgb;
}

float eightbit::getRed() {
    return r;
}

float eightbit::getGreen() {
    return g;
}

float eightbit::getBlue() {
    return b;
}

void adobeRGB::setR(float red) {
    r = red;
} 

void adobeRGB::setG(float green) {
    g = green;
} 

void adobeRGB::setB(float blue) {
    b = blue;
}

adobeRGB adobeRGB::RGBtoAdobeRGB(Rgb color) {
    float primer, primeg, primeb = 0.0f;
    primer = 255 * pow(color.redval, (float)1/2.199);
    primeg = 255 * pow(color.greenval, (float)1/2.199);
    primeb = 255 * pow(color.blueval, (float)1/2.199);

    adobeRGB *converted = new adobeRGB(primer, primeg, primeb);
    return *converted;
}