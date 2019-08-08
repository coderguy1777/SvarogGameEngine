#pragma once
#ifdef KEYBOARD_H
#define KEYBOARD_H
#endif
#include "libs.h"
#define KEY_BIND(X) {}

// input class
struct Key;
struct Key {
    char key;
    int code;
};
class Keyboard {
    public:
        Key key;
        inline static int getCode(char key) {
            return static_cast<int>(key);
        }
        int *keycode;
        inline void findKey(int keyCode) {keycode = &keyCode;}
        bool isKeyPressed(int key) {return input_instace->isCurrKeyPressed(key);}
        bool isKeyReleased(int key) {return input_instace->isCurrKeyReleased(key);}
        int keyIs(int key) {return input_instace->currKey(key);}
        virtual int currKey(int keyCode) = 0;
        virtual bool isCurrKeyReleased(int key) = 0;
        virtual bool isCurrKeyPressed(int key) = 0;

    private:
        // singleton thread instance for the use 
        // within the class itself.
        static Keyboard* input_instace;
}; 