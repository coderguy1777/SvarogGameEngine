#include "cmyk.h"
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

Rgb CMYKVALS::CMYKtoRGB(float cval, float mval, float yval, float kval) {
    Rgb newRgb(0.0f, 0.0f, 0.0f);
    float redVal = 0.0f;
    float greenVal = 0.0f;
    float blueVal = 0.0f;
    redVal = 255 * (1-cval) * (1-kval);
    greenVal = 255 * (1-mval) * (1-kval);
    blueVal = 255 * (1-yval) * (1-kval);
    newRgb.setRVal(redVal);
    newRgb.setGVal(greenVal);
    newRgb.setBVal(blueVal);
    return newRgb;
}

CMYKVALS CMYKVALS::RGBtoCMYK(float rval, float gval, float bval) {
    CMYKVALS newCMYK(0.0f, 0.0f, 0.0f, 0.0f);
    float primer = findRPrime(rval);
    float primeg = findGPrime(gval);
    float primeb = findBPrime(bval);
    float blackval = findK(primer, primeg, primeb);
    newCMYK.setBlack(blackval);
    float cyanval = findC(primer, blackval);
    newCMYK.setCyan(cyanval);
    float magentaval = findM(primeg, blackval);
    newCMYK.setMagenta(magentaval);
    float yellowval = findY(primeb, blackval);
    newCMYK.setYellow(yellowval);
    return newCMYK;
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

CMYKVALS CMYKVALS::newCMYK() {
    return CMYKVALS(c, y, m, k);
}