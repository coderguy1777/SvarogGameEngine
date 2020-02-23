#include "engine_space.h"
EngineSpace* EngineSpace::getEngineSpace() {
    if(!engine) {
        engine = new EngineSpace;
    }
    return engine;
}

void EngineSpace::init_window_settings() {
    glfw_window_entities.init_window_context();
    glfw_window_entities.init_win_monitor_context();
}

void EngineSpace::run() {
    bool run_state = (!glfwWindowShouldClose && engine_settings.getEngineState() && engine_settings.getState == 1) ? true : false;
    while(run_state) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glEnable(GL_LIGHTING | GL_COLOR_MATERIAL);
        glClearColor(1.0, 0.0, 0.0, 1.0);
        ImGuiInit::init_imgui_render();
    }
    
}

EngineSpace* EngineSpace::engine = 0;