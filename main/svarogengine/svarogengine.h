#pragma once
#ifndef SVAROGENGINE_H
#define SVAROGENGINE_H
#include "core/ds-classes/Queue.h"
#include "core/events/event-types/keyevent.h"
#include "main/shapes/shape.h"
#include "main/materials/material.h"
#include "main/enginewindow/enginewindow.h"
class SvarogEngine {
    private:
        Application* SvarogWindow;
    public:
        SvarogEngine() {
            SvarogWindow = new Application();
            SvarogWindow->set_bool_state();
        }
        
        Application* getApplicationWindow() const;
        void InitContext();
        void RunEngine();
        void * operator new(size_t size) {
            void * win = ::new Application();
            return win;
        }
};
#endif