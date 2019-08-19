#pragma once
#ifdef KEYBOARD_H
#define KEYBOARD_H
#endif
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "main/window/window.h"
#include "main/enginewindow/enginewindow.h"
#include "macrodefs.h"
#define KEY_BIND(KEYNAME, KEY) Pair<const char*, int>key(KEYNAME, KEY);

// input class
class Keyboard {
    public:
        Keyboard(){}
        bool isKeyPressed(GLFWwindow* window, int keystate) {return input_instace->checkKeyPressed(keystate);}
        bool isKeyReleased(int keystate);
        bool isKeyRepeat(int keystate);
        int getKeyCode(int key);
        bool keyPress(GLFWwindow* window);
    
    protected: 
        virtual bool checkKeyPressed(int keycode) = 0;
        virtual bool checkKeyReleased(int keycode) = 0;
        virtual bool checkKeyHeld(int keycode) = 0;

    private:
        // singleton thread instance for the use 
        // within the class itself.
        static Keyboard* input_instace;
};
