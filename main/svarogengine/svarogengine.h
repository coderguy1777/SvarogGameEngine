#pragma once
#ifndef SVAROGENGINE_H
#define SVAROGENGINE_H
#include "main/enginewindow/enginewindow.h"
class SvarogEngine {
    private:
        bool state;
        Application* SvarogWindow;
    public:
        ~SvarogEngine() {
            state=false;
            SvarogWindow->end();
        }
        bool getState() const;
        Application* getApplicationWindow() const;
        void changeState(bool newState);
        void RunEngine();
};
#endif