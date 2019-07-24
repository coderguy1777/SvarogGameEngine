#pragma once
#ifdef KEYBOARD_H
#define KEYBOARD_H
#endif
#include "libs.h"
using namespace Events;

namespace KeyBoard {
    EventQueue<Event>keyboardEvents;
    void keyProcess(int state) {
        KeyEvt e;
        switch(state) {
            case KeyEvt::KEY_A :
                
                break;
            default : 
                break;
        }
    }
};
