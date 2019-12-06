#pragma once
#ifdef KEYBOARD_H
#define KEYBOARD_H
#endif
//#define KEY_BIND(KEYNAME, KEY) Pair<const char*, int>key(KEYNAME, KEY);

// input class
class Keyboard {
    public:
        Keyboard() {
            Keyboard::input_instace = this;
        }
        inline static bool isKeyPressed(int keystate) {return input_instace->checkKeyPressed(keystate);}
        inline static bool isKeyReleased(int keystate) {return input_instace->checkKeyReleased(keystate);}
        inline static bool isKeyRepeat(int keystate) {return input_instace->checkKeyRepeat(keystate);}
        inline static bool isKeyHeld(int keystate) {return input_instace->checkKeyHeld(keystate);}
    
    protected: 
        virtual bool checkKeyPressed(int keycode) = 0;
        virtual bool checkKeyReleased(int keycode) = 0;
        virtual bool checkKeyHeld(int keycode) = 0;
        virtual bool checkKeyRepeat(int keycode) = 0;
    private:
        // singleton thread instance for the use 
        // within the class itself.
        static Keyboard* input_instace;
};