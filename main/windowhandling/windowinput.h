#pragma once
#ifdef WINDOWINPUT_H
#define WINDOWINPUT_H
#endif
#include "libs.h"
#include "window/window.h"
#define STATE_KEY_PRESS 1
#define STATE_KEY_RELEASE -1

namespace SvarogWindowInput {
    enum class MOVE_KEYS {
        KEY_UP = SVAROG_KEY_W,
        KEY_DOWN = SVAROG_KEY_S,
        KEY_LEFT = SVAROG_KEY_A,
        KEY_RIGHT = SVAROG_KEY_D,
        KEY_JUMP = SVAROG_KEY_SPACE,
    };


    class WindowInput {
        private: 
            Keyboard winKeyboard;
        public: 
            WindowInput (){};
            Keyboard getKeyboard() const;
    };
}