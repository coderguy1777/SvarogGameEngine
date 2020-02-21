#pragma once
#ifndef ENGINE_SPACE_H 
#define ENGINE_SPACE_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>
#include "math/vec3.h"
#include <iostream>
#include "core/ds-classes/function_list.h"
#include "core/ds-classes/Queue.h"
#include "core/events/Event.h"
#include "core/events/event-listeners/EventListener.h"
#include "core/events/event-dispatchers/KeyEventDispatcher.h"
#include "main/materials/material.h"
#include "core/ds-classes/Array.h"
#include "core/ds-classes/Stack.h"
#include "core/Input/keymap.h"
#include "core/events/event-types/mouseevent.h"
#include "core/events/event-types/keyevent.h"
#include "core/events/event-dispatchers/EventDispatch.h"
#include "main/window/window.h"
#include "render-pipeline/window-initalization/window_context.h"
#include "main/window/window.h"
#include "render-pipeline/window-initalization/window_update.h"
#include "render-pipeline/window-initalization/window_monitor.h"
#include "render-pipeline/window-initalization/glad_loader.h"
#include "render-pipeline/shader/VertexShader.h"
#include "render-pipeline/shader/s_lab/shader_mg.h"
#include "core/Input/InputManager.h"

enum class VSYNC_STATES {
    VSYNC_ON,
    VSYNC_OFF
};

enum class ENGINE_STATES {
    ENGINE_RUNNING,
    ENGINE_STOPPED
};

class EngineSpace {
    private: 
        struct EngineWindowStyle {
            private: 
                std::string window_name;
                uint w;
                uint h;

            public:
                
                inline void set_window_width(const uint& width) {
                    w = width;
                }

                inline void set_window_height(const uint& height) {
                    h = height;
                }

                inline void set_window_name(const std::string&win_name) {
                    window_name = win_name;
                }

                uint get_window_width() const {
                    return w;
                }

                uint get_window_height() const {
                    return h;
                }

                std::string get_window_name() const {
                    return window_name;
                }

        } engine_style_settings;
        // settings for the window relating to vsync, etc.
        static struct EngineWindowSettings {
            private: 
                bool isVsyncOn;
                uint state;
                bool engine_state;
            public: 
                inline void setVsyncOn(uint state) {
                    isVsyncOn = (state == 1) ? true : false;
                }

                inline void setState(bool run) {
                    state = (run == true) ? 1 : 0;
                }

                inline void setEngineState(uint state) {
                    engine_state = (state == 1) ? true : false;
                } 

                bool getVsyncState() const {
                    return isVsyncOn;
                }

                bool getEngineState() const {
                    return engine_state;
                }

                uint getState() const {
                    return state;
                }
        } engine_settings;

        struct GLFWEntities {
            private: 
                GLFWmonitor* engine_glfw_mon;
                GLFWwindow* engine_glfw_win;
            public: 
                inline void init_win_monitor_context() {

                }

                inline void init_window_context() {

                }

                void runVSYNC() {
                    auto check_VSYNC = EngineSpace::engine_settings.getVsyncState();
                    if(check_VSYNC) {
                        glfwSwapInterval(1);
                    } else if(!check_VSYNC) {
                        glfwSwapInterval(0);
                    }
                }
                
        } glfw_window_entities;
        static EngineSpace* engine;

        EngineSpace() {}

    public: 
        static EngineSpace* getEngineSpace();

};

#endif