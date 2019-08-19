#pragma once
#ifdef KEYBOARD_H
#define KEYBOARD_H
#endif
#include "macrodefs.h"
#define KEY_BIND(KEYNAME, KEY) Pair<const char*, int>key(KEYNAME, KEY);

// input class
class Keyboard {
    public:
        Keyboard(){}
        inline static bool isKeyPressed(int keystate) {return input_instace->checkKeyPressed(keystate);}
        inline static bool isKeyReleased(int keystate) {return input_instace->checkKeyReleased(keystate);}
        inline static bool isKeyRepeat(int keystate) {return input_instace->checkKeyHeld(keystate);}
        int getKeyCode(int key);
    
    protected: 
        virtual bool checkKeyPressed(int keycode) = 0;
        virtual bool checkKeyReleased(int keycode) = 0;
        virtual bool checkKeyHeld(int keycode) = 0;
    private:
        // singleton thread instance for the use 
        // within the class itself.
        static Keyboard* input_instace;
};