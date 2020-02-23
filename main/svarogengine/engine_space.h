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

class EngineSpace {
    private: 
        static struct EngineWindowStyle {
            private: 
                std::string window_name;
                uint w;
                uint h;

            public:
                inline void set_window_width(const uint& width) { w = width; }
                inline void set_window_height(const uint& height) { h = height; }
                inline void set_window_name(const std::string&win_name) { window_name = win_name; }
                uint get_window_width() const { return w; }
                uint get_window_height() const { return h; }
                std::string get_window_name() const { return window_name; }

        } engine_style_settings;

        // settings for the window relating to vsync, etc.
        static struct EngineWindowSettings {
            private: 
                bool isVsyncOn;
                uint state;
                bool engine_state;

            public: 
                inline void setVsyncOn(uint state) { isVsyncOn = (state == 1) ? true : false; }
                inline void setState(bool run) { state = (run == true) ? 1 : 0; }
                inline void setEngineState(uint state) { engine_state = (state == 1) ? true : false; } 
                bool getVsyncState() const { return isVsyncOn; }
                bool getEngineState() const { return engine_state; }
                uint getState() const { return state; }

        } engine_settings;

        static struct GLFWEntities {
            private: 
                GLFWmonitor* engine_glfw_mon;
                GLFWwindow* engine_glfw_win;
                std::shared_ptr<WindowMonitor>win_mon = std::make_shared<WindowMonitor>();
            public: 
                inline void* getEngineWin() { return engine_glfw_win; }
                inline void* getEngineMonitor() { return engine_glfw_mon; }
                inline void make_context_curr() { 
                    WindowContext::make_curr_context(static_cast<GLFWwindow*>(getEngineWin())); 
                }

                inline void init_win_monitor_context() {
                    win_mon->init_monitor();
                }

                inline void init_window_context() {
                    WindowContext::set_states(1, 3);
                    WindowContext::init_glfw();
                    WindowContext::create_context(static_cast<GLFWwindow*>(getEngineWin()));
                    engine_glfw_win = glfwCreateWindow((int)engine_style_settings.get_window_width(), (int)engine_style_settings.get_window_height(), (const char*)engine_style_settings.get_window_name().c_str(), NULL, NULL);
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
        inline void init_window_settings();
        inline void run();
        inline void pre_batch();
        inline void load_gpu_data();
        
        ~EngineSpace() {
            glfwDestroyWindow(static_cast<GLFWwindow*>(glfw_window_entities.getEngineWin()));
        }

};

#endif