#include "windowinput.h"
void WindowHandler::processEvents() {
    if(engineKeyboard.isKeyPressed(SVAROG_KEY_W) == true) {
        cout << "Key W is pressed!" << endl;
    }

    if(engineKeyboard.isKeyRepeat(SVAROG_KEY_A) == true) {
        cout << "Key A is repeated!" << endl;
    }

    if(engineKeyboard.isKeyReleased(SVAROG_KEY_O) == true) {
        cout << "Key O is released!" << endl;
    }
}