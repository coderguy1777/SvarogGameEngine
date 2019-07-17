#pragma once 
#ifdef INPUTEVENT_H
#define INPUTEVENT_H
#endif
#include "core/String.h"
class KeyEvt {
    public: 
        String * key_evt = new String("Key");
        KeyEvt(){};
        enum KEY_EVENTS {
            KEY_A,
            KEY_B,
            KEY_C,
            KEY_D,
            KEY_E,
            KEY_F, 
            KEY_G,
            KEY_H,
            KEY_I,
            KEY_J,
            KEY_K,
            KEY_L,
            KEY_M,
            KEY_N,
            KEY_O,
            KEY_P,
            KEY_Q,
            KEY_R,
            KEY_S,
            KEY_T,
            KEY_U,
            KEY_V,
            KEY_W,
            KEY_X,
            KEY_Y,
            KEY_Z,
            KEY_ESC,
            KEY_LSHIFT,
            KEY_RSHIFT,
            KEY_LCTRL,
            KEY_RCTRL,
            KEY_LALT,
            KEY_RALT,
        };
        int KEY_PRESSED(int key);
        bool key_Down(int state);
        bool key_Up(int state);
};