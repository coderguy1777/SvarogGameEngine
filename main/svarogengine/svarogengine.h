#pragma once
#ifndef SVAROGENGINE_H
#define SVAROGENGINE_H
#include <memory>
#include <functional>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include "core/memory/gui_task_manager.h"
#include "math/matrix.h"
#include "render-pipeline/mesh/cube.h"
#include "main/enginewindow/engine-gui/sidebar-components/input_text.h"
#include "render-pipeline/mesh/svarog_shape.h"
#include "render-pipeline/mesh/svarog_renderobj.h"
#include "render-pipeline/shader/glsl_shader_generation/shader_gen.h"
#include "main/enginewindow/engine-gui/gui_layer.h"
#include "core/memory/render_task_manager.h"
#include "render-pipeline/shader/glsl_shader_generation/shader_defs.h"
#include "render-pipeline/shader/s_lab/svarog_material.h"
#include "main/enginewindow/engine-gui/imgui_init.h"
#include "main/enginewindow/engine-gui/gui_frames.h"
#include "main/enginewindow/engine-gui/sidebar-components/button.h"
#include "main/enginewindow/engine-gui/sidebar-components/label.h"
#include "main/enginewindow/enginewindow.h"
#include "main/enginewindow/engine-gui/gui_window.h"
#include "core/memory/svarog_thread_task.h"

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
        void InitRenderManager();
        void InitGuiManager();
        void InitMaterialManager();
        void InitThreadManager();
        void RunEngine();
};
#endif