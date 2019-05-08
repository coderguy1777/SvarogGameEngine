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
    return returnval;
}