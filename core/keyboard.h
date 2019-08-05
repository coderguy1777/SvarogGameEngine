#pragma once
#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "libs.h"
// basic special char keys
#define KEY_SPACE 32
#define KEY_EXCL_PT 33
#define KEY_QUOTATION 34
#define KEY_HASHTAG 35
#define KEY_DLR_SIGN 36
#define KEY_PCT_SIGN 37
#define KEY_AND_SIGN 38
#define KEY_APST_SIGN 39
#define KEY_OPN_PTH 40
#define KEY_CLSE_PTH 41
#define KEY_MULT_SYM 42
#define KEY_ADD_SYM 43
#define KEY_COMMA 44
#define KEY_DASH_1 45
#define KEY_PERIOD 46
#define KEY_BACK_SLASH 47
#define KEY_NUM_1 48
#define KEY_NUM_2 49
#define KEY_NUM_3 50
#define KEY_NUM_4 51
#define KEY_NUM_5 52 
#define KEY_NUM_6 53 
#define KEY_NUM_7 54
#define KEY_NUM_8 55
#define KEY_NUM_9 56
#define KEY_NUM_0 57
#define KEY_DB_DT 58
#define KEY_SMI_CLN 59
#define KEY_LSN_SYM 60 // <
#define KEY_EQ_SYM 61 // =
#define KEY_GRN_SYM 62 // >
#define KEY_QS_SYM 63 // ? 
#define KEY_AT_SYM 64 // @ 
#define KEY_A 65
#define KEY_B 66
#define KEY_C 67
#define KEY_D 68
#define KEY_E 69
#define KEY_F 70
#define KEY_G 71 
#define KEY_H 72
#define KEY_I 73
#define KEY_J 74 
#define KEY_K 75
#define KEY_L 76
#define KEY_M 77
#define KEY_N 78
#define KEY_O 79
#define KEY_P 80 
#define KEY_Q 81
#define KEY_R 82
#define KEY_S 83
#define KEY_T 84
#define KEY_U 85 
#define KEY_V 86
#define KEY_W 87
#define KEY_X 88
#define KEY_Y 89
#define KEY_Z 90
// puncation keycodes 
#define KEY_FORWARD_BRACKET 91
#define KEY_FORWARD_SLASH 92
#define KEY_BACKWARDS_BRACKET 93
#define KEY_PW_SYM 94
#define KEY_DASH 95
#define KEY_APSTROPHE 96
// lowercase keycodes
#define KEY_l_A 97
#define KEY_l_B 98
#define KEY_l_C 99 
#define KEY_l_D 100
#define KEY_l_E 101
#define KEY_l_F 102 
#define KEY_l_G 103
#define KEY_l_H 104
#define KEY_l_I 105
#define KEY_l_J 106
#define KEY_l_K 107
#define KEY_l_L 108
#define KEY_l_M 109
#define KEY_l_N 110
#define KEY_l_O 111 
#define KEY_l_P 112
#define KEY_l_Q 113
#define KEY_l_R 114
#define KEY_l_S 115
#define KEY_l_T 116
#define KEY_l_U 117
#define KEY_l_V 118
#define KEY_l_W 119
#define KEY_l_X 120
#define KEY_l_Y 121
#define KEY_l_Z 122
// more puncation keycodes
#define KEY_BRACKET_1 123
#define KEY_DIV_SEP 124
#define KEY_BRACKET_2 125
#define KEY_SQUIGGLY 126 // Key refers to the ~ key

class Keyboard {
    public:
        static int *keycode;
        inline static void findKey(int keyCode);
        inline bool keyPressed(int keystate) {return (keystate==1) ? true : false;}
        inline bool keyReleased(int keystate) {return (keystate==2) ? true : false;};
        bool currentKeyState();
    protected:
        virtual bool currKey() = 0;
        virtual bool isCurrKeyRelased() = 0;
        virtual bool isCurrKeyPressed() = 0;
    private:
        static Keyboard* input_instace;
}; 

namespace KeyBoard {
    void keyProcess(int state) {
        switch(state) {
            case KEY_A: 
                Keyboard::findKey(state);
                break;
            case KEY_B:
                Keyboard::findKey(state);
                break;
            case KEY_C:
                Keyboard::findKey(state);
                break;
            case KEY_D:
                Keyboard::findKey(state);
                break;
            case KEY_E:
                Keyboard::findKey(state);
                break;
            case KEY_F:
                Keyboard::findKey(state);
                break;
            case KEY_G:
                Keyboard::findKey(state);
                break;
            case KEY_H:
                Keyboard::findKey(state);
                break;
            case KEY_I:
                Keyboard::findKey(state);
                break;
            case KEY_J:
                Keyboard::findKey(state);
                break;
            case KEY_K: 
                Keyboard::findKey(state);
                break;
            case KEY_L:
                Keyboard::findKey(state);
                break;
            case KEY_M:
                Keyboard::findKey(state);
                break;
            case KEY_N: 
                Keyboard::findKey(state);
                break;
            case KEY_O:
                Keyboard::findKey(state);
                break;
            case KEY_P:
                Keyboard::findKey(state);
                break;
            case KEY_Q:
                Keyboard::findKey(state);
                break;
            case KEY_R:
                Keyboard::findKey(state);
                break;
            case KEY_S:
                Keyboard::findKey(state);
                break;
            case KEY_T:
                Keyboard::findKey(state);
                break;
            case KEY_U:
                Keyboard::findKey(state);
                break;
            case KEY_V:
                Keyboard::findKey(state);
                break;
            case KEY_W:
                Keyboard::findKey(state);
                break;
            case KEY_X:
                Keyboard::findKey(state);
                break;
            case KEY_Y:
                Keyboard::findKey(state);
                break;
            case KEY_Z:
                Keyboard::findKey(state);
                break;
            case KEY_FORWARD_BRACKET:
                Keyboard::findKey(state);
                break;
            case KEY_FORWARD_SLASH:
                Keyboard::findKey(state);
                break;
            case KEY_BACKWARDS_BRACKET:
                Keyboard::findKey(state);
                break;
            case KEY_PW_SYM:
                Keyboard::findKey(state);
                break;
            case KEY_DASH: 
                Keyboard::findKey(state);
                break;
            case KEY_APSTROPHE:
                Keyboard::findKey(state);
                break;
            case KEY_l_A:
                Keyboard::findKey(state);
                break;
            case KEY_l_B:
                Keyboard::findKey(state);
                break;
            case KEY_l_C:
                Keyboard::findKey(state);
                break;
            case KEY_l_D:
                Keyboard::findKey(state);
                break;
            case KEY_l_E:
                Keyboard::findKey(state);
                break;
            case KEY_l_F:
                Keyboard::findKey(state);
                break;
            case KEY_l_G:
                Keyboard::findKey(state);
                break;
            case KEY_l_H:
                Keyboard::findKey(state);
                break;
            case KEY_l_I:
                Keyboard::findKey(state);
                break;
            case KEY_l_K:
                Keyboard::findKey(state);
                break;
            case KEY_l_L:
                Keyboard::findKey(state);
                break;
            case KEY_l_M:
                Keyboard::findKey(state);
                break;
            case KEY_l_N:
                Keyboard::findKey(state);
                break;
            case KEY_l_O:
                Keyboard::findKey(state);
                break;
            case KEY_l_P:
                Keyboard::findKey(state);
                break;
            case KEY_l_Q:
                Keyboard::findKey(state);
                break;
            case KEY_l_R:
                Keyboard::findKey(state);
                break;
            case KEY_l_S:
                Keyboard::findKey(state);
                break;
            case KEY_l_T: 
                Keyboard::findKey(state);
                break;
            case KEY_l_U:
                Keyboard::findKey(state);
                break;
            case KEY_l_V:
                Keyboard::findKey(state);
                break;
            case KEY_l_W:
                Keyboard::findKey(state);
                break;
            case KEY_l_X:
                Keyboard::findKey(state);
                break;
            case KEY_l_Y:
                Keyboard::findKey(state);
                break;
            case KEY_l_Z:
                Keyboard::findKey(state);
                break;
            case KEY_BRACKET_1:
                Keyboard::findKey(state);
                break;
            case KEY_DIV_SEP:
                Keyboard::findKey(state);
                break;
            case KEY_BRACKET_2:
                Keyboard::findKey(state);
                break;
            case KEY_SQUIGGLY:
                Keyboard::findKey(state);
                break;
            default:
                Keyboard::findKey(static_cast<int>(NULL));
                break;

        }
    }
}
#endif