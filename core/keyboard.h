#pragma once
#ifndef KEYBOARD_H
#define KEYBOARD_H
#include "libs.h"
using namespace Events;

namespace KeyBoard {
    
    void keyProcess(int state) {
        KeyEvt e;
        switch(state) {
            case KeyEvt::KEY_A :
                cout << "Key a pressed" << endl;
                break;
            default : 
                break;
        }
    }
};

#endif