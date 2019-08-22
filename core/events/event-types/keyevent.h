#pragma once
#ifndef KEYEVENT_H
#define KEYEVENT_H
#include "core/String.h"
#include "core/Input/keycodes.h"
#include "core/events/Event.h"
enum class KeyEventTypes {
    KEY_PRESS_EVT,
    KEY_HELD_EVT,
    KEY_RELEASED_EVT,
    KEY_DOUBLE_PRESS_EVT,
};

struct KeyBind {
    char key;
    unsigned int ascii_code;
} Key;

class KeyEvent {
    private:
        KeyBind Key;
    public:
        KeyEvent(){}
        inline int getKeyCode(char key) {
            int keyCode = 0;
            switch(key) {
                case 'A':
                    keyCode = SVAROG_KEY_A;
                    break;
                case 'B':
                    keyCode = SVAROG_KEY_B;
                    break;
                case 'C':
                    keyCode = SVAROG_KEY_C;
                    break;
                case 'D':
                    keyCode = SVAROG_KEY_D;
                    break;
                case 'E':
                    keyCode = SVAROG_KEY_E;
                    break;
                case 'F':
                    keyCode = SVAROG_KEY_F;
                    break;
                case 'G':
                    keyCode = SVAROG_KEY_G;
                    break;
                case 'H':
                    keyCode = SVAROG_KEY_H;
                    break;
                case 'I':
                    keyCode = SVAROG_KEY_I;
                    break;
                case 'J':
                    keyCode = SVAROG_KEY_J;
                    break;
                case 'K':
                    keyCode = SVAROG_KEY_K;
                    break;
                case 'L':
                    keyCode = SVAROG_KEY_L;
                    break;
                case 'M':
                    keyCode = SVAROG_KEY_M;
                    break;
                case 'N':
                    keyCode = SVAROG_KEY_N;
                    break;
                case 'O':
                    keyCode = SVAROG_KEY_O;
                    break;
                case 'P':
                    keyCode = SVAROG_KEY_P;
                    break;
                case 'Q':
                    keyCode = SVAROG_KEY_Q;
                    break;
                case 'R':
                    keyCode = SVAROG_KEY_R;
                    break;
                case 'S':
                    keyCode = SVAROG_KEY_S;
                    break;
                case 'T':
                    keyCode = SVAROG_KEY_T;
                    break;
                case 'U':
                    keyCode = SVAROG_KEY_U;
                    break;
                case 'V':
                    keyCode = SVAROG_KEY_V;
                    break;
                case 'W':
                    keyCode = SVAROG_KEY_W;
                    break;
                
            }
        }
        String logKeyPressEvent(Event e, char key);
        String logKeyReleaseEvent(Event e, char key);
        String logKeyHeldEvent(Event e, char key);
        String logKeyRepeatEvent(Event e, char key);
};

#endif