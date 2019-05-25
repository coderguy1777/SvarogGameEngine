#include "Color.h"
#include <vector>

float Rgb::getBlue() {
    return blueval;
}

float Rgb::getRed() {
    return redval;
}

float Rgb::getGreen() {
    return greenval;
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

void Rgb::createColor() {
    glClearColor(redval, greenval, blueval, 0.0f);
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