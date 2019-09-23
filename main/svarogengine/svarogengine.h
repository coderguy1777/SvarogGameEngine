#pragma once
#ifndef SVAROGENGINE_H
#define SVAROGENGINE_H
#include "core/events/event-layer/LayerStack.h"
#include "core/ds-classes/Queue.h"
#include "core/events/event-types/keyevent.h"
#include "main/shapes/shape.h"
#include "render-pipeline/shader/FragmentShader.h"
#include "render-pipeline/shader/VertexShader.h"
#include "render-pipeline/shader/ShaderProgram.h"
#include "render-pipeline/mesh/svarog_shape.h"
#include "math/vec3.h"
#include "main/materials/material.h"
#include "main/enginewindow/enginewindow.h"
class SvarogEngine {
    private:
        static SvarogEngine* engine_instance;
       // EngineWindow* SvarogWindow;
        WindowMonitor* svarog_monitor;
        WindowInput* Input;
    public:
        SvarogEngine() {
            svarog_monitor = new WindowMonitor();
        }
        static SvarogEngine* getInstanceEngine();
        void InitContext();
        void InitMonitor();
        void RunEngine();
};
#endif