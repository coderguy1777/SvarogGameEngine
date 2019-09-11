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
        WindowInput* Input;
        InputManager* manager;
    public:

        SvarogEngine() {
            Input = WindowInput::getSingleton();
            SvarogWindow = EngineWindow::getInstance();
            svarog_monitor = new WindowMonitor();
            manager = InputManager::getMangerInstance();
            SvarogWindow->set_bool_state();
        }

        
        EngineWindow* getEngineWindowWindow() const;
        void InitContext();
        void InitMonitor();
        void RunEngine();
};
#endif