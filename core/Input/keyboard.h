#pragma once
#ifdef KEYBOARD_H
#define KEYBOARD_H
#endif
#include "libs.h"
#define KEY_BIND(KEYNAME, KEY) Pair<const char*, int>key(KEYNAME, KEY);

// input class
class Keyboard {
    public:
        Window winNN;
        Keyboard(Window win) {
            winNN = win;
        }
        Keyboard(){}
        bool isKeyPressed(GLFWwindow* window, int keystate);
        bool isKeyReleased(int keystate);
        bool isKeyRepeat(int keystate);
        int getKeyCode(int key);
        bool keyPress(GLFWwindow* window);
    
    protected: 
        bool checkKeyPressed(int keycode);
        bool checkKeyReleased(int keycode);
        bool checkKeyRepeat(int keycode);

    private:
        // singleton thread instance for the use 
        // within the class itself.
        static Keyboard* input_instace;
};
