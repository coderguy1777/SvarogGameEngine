#pragma once
#ifndef SVAROGENGINE_H
#define SVAROGENGINE_H
#include <memory>
#include <functional>
#include "core/events/event-layer/LayerStack.h"
#include "core/ds-classes/Queue.h"
#include "core/events/event-types/keyevent.h"
#include "main/shapes/shape.h"
#include "render-pipeline/shader/FragmentShader.h"
#include "render-pipeline/shader/VertexShader.h"
#include "render-pipeline/shader/ShaderProgram.h"
#include "render-pipeline/mesh/svarog_shape.h"
#include "render-pipeline/mesh/svarog_renderobj.h"
#include "render-pipeline/shader/glsl_shader_generation/shader_gen.h"
#include "render-pipeline/shader/glsl_shader_generation/shader_defs.h"
#include "main/enginewindow/engine-gui/imgui_init.h"
#include "main/enginewindow/engine-gui/sidebar-components/button.h"
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
        int a;
        SvarogEngine() {
            svarog_monitor = new WindowMonitor();
        }
        static SvarogEngine* getInstanceEngine();
        void InitContext();
        void InitMonitor();
        void RunEngine();
};
#endif