#pragma once
#ifndef SVAROGENGINE_H
#define SVAROGENGINE_H
#include "core/events/event-layer/LayerStack.h"
#include "core/ds-classes/Queue.h"
#include "core/events/event-types/keyevent.h"
#include "main/shapes/shape.h"
#include "math/vec3.h"
#include "main/materials/material.h"
#include "main/enginewindow/enginewindow.h"
class SvarogEngine {
    private:
        EngineWindow* SvarogWindow;
        WindowMonitor* svarog_monitor;
    public:


        SvarogEngine() {
            SvarogWindow = new EngineWindow();
            svarog_monitor = new WindowMonitor();
            SvarogWindow->set_bool_state();
        }

        
        EngineWindow* getEngineWindowWindow() const;
        void InitContext();
        void InitMonitor();
        void RunEngine();
        void * operator new(size_t size) {
            void * win = ::new EngineWindow();
            return win;
        }
};
#endif