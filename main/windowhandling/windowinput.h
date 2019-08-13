#pragma once
#ifndef WINDOWINPUT_H
#define WINDOWINPUT_H
#include "core/Input/keyboard.h"
#include "macrodefs.h"
#define STATE_KEY_PRESS 1
#define STATE_KEY_RELEASE -1

class WindowHandler {
    public:
        Window win;
        Keyboard engineKeyboard;
        WindowHandler(Window engineWin){
            win = engineWin;
            engineKeyboard.winNN = win;
        }
        WindowHandler(){}
        void processEvents();
};

#endif