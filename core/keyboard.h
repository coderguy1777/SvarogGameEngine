#pragma once
#ifdef KEYBOARD_H
#define KEYBOARD_H
#endif
#include "libs.h"
#define KEY_BIND(X) {}

// input class
union Key {
    char key;
    int code;
};
class Keyboard {
    public:
    
        inline static int getCode(char key) {
            return static_cast<int>(key);
        }
        int *keycode;
        inline void findKey(int keyCode) {keycode = &keyCode;}
        bool isKeyPressed(int key) {return input_instace->isCurrKeyPressed(key);}
        bool isKeyReleased(int key) {return input_instace->isCurrKeyRelased(key);}
        int keyIs(int* key) {return input_instace->currKey(keycode);}
       //~Keyboard() {
       //   delete this;
       //}
    protected:
        int currKey(int* key) const {return *(key);}
        bool isCurrKeyRelased(int key) const {return (key == 1) ? true : false;}
        bool isCurrKeyPressed(int key) const {return (key == 2) ? true : false;}
    private:
        static Keyboard* input_instace;
}; 

/* namespace KeyBoard {
     void keyProcess(int state) {
        switch(state) {
            case SVAROG_KEY_A: 
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_B:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_C:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_D:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_E:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_F:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_G:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_H:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_I:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_J:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_K: 
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_L:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_M:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_N: 
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_O:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_P:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_Q:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_R:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_S:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_T:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_U:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_V:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_W:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_X:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_Y:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_Z:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_FORWARD_BRACKET:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_FORWARD_SLASH:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_BACKWARDS_BRACKET:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_PW_SYM:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_DASH: 
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_APSTROPHE:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_l_A:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_l_B:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_l_C:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_l_D:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_l_E:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_l_F:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_l_G:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_l_H:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_l_I:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_l_K:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_l_L:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_l_M:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_l_N:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_l_O:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_l_P:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_l_Q:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_l_R:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_l_S:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_l_T: 
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_l_U:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_l_V:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_l_W:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_l_X:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_l_Y:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_l_Z:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_BRACKET_1:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_DIV_SEP:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_BRACKET_2:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_SQUIGGLY:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_SPACE:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_EXCL_PT:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_QUOTATION:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_HASHTAG:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_DLR_SIGN:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_PCT_SIGN:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_AND_SIGN:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_APST_SIGN:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_OPN_PTH:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_CLSE_PTH:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_MULT_SYM:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_ADD_SYM:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_COMMA:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_DASH_1:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_PERIOD:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_BACK_SLASH:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_NUM_1:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_NUM_2:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_NUM_3:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_NUM_4:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_NUM_5:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_NUM_6:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_NUM_7:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_NUM_8:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_NUM_9:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_NUM_0:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_DB_DT:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_SMI_CLN:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_LSN_SYM:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_EQ_SYM:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_GRN_SYM:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_QS_SYM:
                Keyboard::findKey(state);
                break;
            case SVAROG_KEY_AT_SYM:
                Keyboard::findKey(state);
                break;
            default:
                Keyboard::findKey(static_cast<int>(NULL));
                break;

      
        }
    }
    */