#pragma once
#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "libs.h"
using namespace Events;
void randoms() {
    Event evt;
    evt.typer = EVENT_TYPE::KeyEvent;
    evt.PRIOITY = 10;
    evt.cause = "KEY_PRESS";
    Events::printEvent(evt);
}
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