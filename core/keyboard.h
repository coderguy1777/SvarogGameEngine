#pragma once
#ifdef KEYBOARD_H
#define KEYBOARD_H
#endif
#include "libs.h"

namespace KeyBoard {
    void keyProcess(int state) {
        KeyEvt e;
        switch(state) {
            case KeyEvt::KEY_A :
                cout << "X"<<endl;
                break;
            default : 
                break;
        }
    }
};
