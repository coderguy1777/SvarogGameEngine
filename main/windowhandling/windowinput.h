#pragma once
#ifdef WINDOWINPUT_H
#define WINDOWINPUT_H
#endif
#include "main/window/window.h"
#include "macrodefs.h"
#include "core/Input/keyboard.h"
#include "core/Input/keycodes.h"
#define STATE_KEY_PRESS 1
#define STATE_KEY_RELEASE -1
#define DEFINEMOVE_KEY(X, X1)(SvarogWindowInput::MOVE_KEYS[X1] == X)

namespace SvarogWindow{}
using namespace SvarogWindow;
namespace SvarogWindowInput {
    enum class MOVE_KEYS {
        KEY_UP = SVAROG_KEY_W,
        KEY_DOWN = SVAROG_KEY_S,
        KEY_LEFT = SVAROG_KEY_A,
        KEY_RIGHT = SVAROG_KEY_D,
        KEY_JUMP = SVAROG_KEY_SPACE,
    };

    class Keyboard;
    class WindowInput  {
        private: 
            Window keyWindow;
            GLFWwindow* keyWin;
        public:
            Window keywindow() const;
            static void handleKey(unsigned int keyCode);
    };
}