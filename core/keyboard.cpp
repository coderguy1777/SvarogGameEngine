#include "keyboard.h"

inline bool Keyboard::keyPressed(int keystate) {
    return (keystate == 1) ? true : false;
}

inline bool Keyboard::keyReleased(int keystate) {
    return (keystate == 2) ? true : false;
}

bool Keyboard::currentKeyState() {
    int casekey = 0;
    switch(casekey) {
        
    }
}