#include "svarogengine.h"
bool SvarogEngine::getState() const {
    return state;
}

void SvarogEngine::changeState(bool newState) {
    state = newState;
}

Application* SvarogEngine::getApplicationWindow() const {
    return SvarogWindow;
}

void SvarogEngine::RunEngine() {
    if(state == false) {
        SvarogWindow->end();
    } else if(state != false) {
        while(state) {
            SvarogWindow->VSYNC_on();
            SvarogWindow->SvarogAppLoop();
        }
    }
}