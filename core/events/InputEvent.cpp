#include "InputEvent.h"
#include<iostream>
int KeyEvt::KEY_PRESSED(int key) {
    int pressedKey = 0;
    switch(key) {
        case KEY_EVENTS::KEY_A :
            pressedKey = 1;
            break;
        case KEY_EVENTS::KEY_B :
            pressedKey = 2;
            break;
        case KEY_EVENTS::KEY_C :
            pressedKey = 3;
            break;
        case KEY_EVENTS::KEY_D :
            pressedKey = 4;
            break;
        case KEY_EVENTS::KEY_E :
            pressedKey = 5;
            break;
        case KEY_EVENTS::KEY_F :
            pressedKey = 6;
            break;
        case KEY_EVENTS::KEY_G :
            pressedKey = 7;
            break;
        case KEY_EVENTS::KEY_H :
            pressedKey = 8;
            break;
        case KEY_EVENTS::KEY_I :
            pressedKey = 9;
            break;
        case KEY_EVENTS::KEY_J :
            pressedKey = 10;
            break;
        case KEY_EVENTS::KEY_K :
            pressedKey = 11;
            break;
        case KEY_EVENTS::KEY_L : 
            pressedKey = 12;
            break;
        case KEY_EVENTS::KEY_M : 
            pressedKey = 13;
            break;
        case KEY_EVENTS::KEY_N :
            pressedKey = 14;
            break;
        case KEY_EVENTS::KEY_O :
            pressedKey = 15;
            break;
        case KEY_EVENTS::KEY_P :
            pressedKey = 16;
            break;
        case KEY_EVENTS::KEY_Q :
            pressedKey = 17;
            break;
        case KEY_EVENTS::KEY_R :
            pressedKey = 18;
            break;
        case KEY_EVENTS::KEY_S :
            pressedKey = 19;
            break;
        case KEY_EVENTS::KEY_T :
            pressedKey = 20;
            break;
        case KEY_EVENTS::KEY_U :
            pressedKey = 21;
            break;
        case KEY_EVENTS::KEY_V :
            pressedKey = 22;
            break;
        case KEY_EVENTS::KEY_W :
            pressedKey = 23;
            break;
        case KEY_EVENTS::KEY_X :
            pressedKey = 24;
            break;
        case KEY_EVENTS::KEY_Y :
            pressedKey = 25;
            break;
        case KEY_EVENTS::KEY_Z :
            pressedKey = 26;
            break;
        case KEY_EVENTS::KEY_ESC :
            pressedKey = -1;
            break;
        case KEY_EVENTS::KEY_LSHIFT :
            pressedKey = 27;
            break;
        case KEY_EVENTS::KEY_RSHIFT :
            pressedKey = 28;
            break;
        case KEY_EVENTS::KEY_LCTRL :
            pressedKey = 29;
        case KEY_EVENTS::KEY_RCTRL :
            pressedKey = 30;
            break;
        case KEY_EVENTS::KEY_LALT :
            pressedKey = 31;
            break;
        case KEY_EVENTS::KEY_RALT :
            pressedKey = 32;
            break;
        default :
            pressedKey=0;
            break;
    }
    return pressedKey;
}

bool KeyEvt::key_Down(int state) {
    return (state == 1) ? true : false;
}

bool KeyEvt::key_Up(int state) {
    return (state == 2) ? true : false;
}