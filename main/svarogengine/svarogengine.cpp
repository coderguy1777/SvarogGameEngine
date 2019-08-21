#include "svarogengine.h"
bool SvarogEngine::getState() const {
    return state;
}

void SvarogEngine::changeState(bool newState) {
    state = newState;
}

Application SvarogEngine::getApplicationWindow() const {
    return SvarogWindow;
}

void SvarogEngine::RunEngine() {
    if(state) {
        SvarogWindow.VSYNC_on();
        SvarogWindow.SvarogAppLoop();
        SvarogWindow.OnUpdate();
    }

    if(!state) {
        SvarogWindow.end();
    }
}