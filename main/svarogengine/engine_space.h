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
#include "render-pipeline/shader/s_lab/s_lab_gui/main_editor_gui.h"
#include "main/enginewindow/engine-gui/imgui_init.h"
#include "main/enginewindow/engine-gui/gui_frames.h"
#include "main/enginewindow/engine-gui/sidebar-components/button.h"
#include "main/enginewindow/engine-gui/sidebar-components/label.h"

class EngineSpace {
    private: 
        static struct EngineWindowStyle {
            private: 
                std::string window_name = "Svarog Engine";
                uint w = 1920;
                uint h = 1080;

            public:
                uint get_window_width() const { return w; }
                uint get_window_height() const { return h; }
                std::string get_window_name() const { return window_name; }

        };

        // settings for the window relating to vsync, etc.
        static struct EngineWindowSettings {
            private: 
                bool isVsyncOn = true;
                uint state = 1;
                bool engine_state = (state == 1) ? true  : false;

            public: 
                static void state_update(uint new_state) { state = new_state; }
                static bool getVsyncState() const { return isVsyncOn; }
                static bool getEngineState() const { return engine_state; }
                static uint getState() const { return state; }

        };

        static struct GLFWEntities {
            private: 
                GLFWmonitor* engine_glfw_mon;
                GLFWwindow* engine_glfw_win;
                std::shared_ptr<WindowMonitor>win_mon = std::make_shared<WindowMonitor>();
            public: 
                 void* getEngineWin() { return engine_glfw_win; }
                 void* getEngineMonitor() { return engine_glfw_mon; }
                void make_context_curr() { 
                    WindowContext::make_curr_context(static_cast<GLFWwindow*>(getEngineWin())); 
                }

                inline void init_win_monitor_context() {
                    win_mon->init_monitor();
                }

                inline void init_window_context() {
                    WindowContext::set_states(1, 3);
                    WindowContext::init_glfw();
                    WindowContext::create_context(static_cast<GLFWwindow*>(getEngineWin()));
                    engine_glfw_win = glfwCreateWindow((int)EngineWindowStyle::get_window_width(), (int)EngineWindowStyle::get_window_height(), (const char*)engine_style_settings.get_window_name().c_str(), NULL, NULL);
                }

                inline void runVSYNC() {
                    auto check_VSYNC = engine_settings.getVsyncState();
                    if(check_VSYNC) {
                        glfwSwapInterval(1);
                    } else if(!check_VSYNC) {
                        glfwSwapInterval(0);
                    }
                }
                
        };
        static EngineSpace* engine;
        EngineSpace() {
            init_imgui_context();
            init_window_settings();
        }
    public: 
        static EngineSpace* getEngineSpace();
        inline void init_imgui_context() {
            ImGuiInit::make_imgui_context(static_cast<GLFWwindow*>(GLFWEntites::getEngineWin()), "#version 400");
            ImGuiInit::make_imgui_style(0);
            ImGuiInit::imgui_ini_use(false);
        }
        inline void init_window_settings();
        inline void run();
        inline void pre_batch();
        inline void load_gpu_data();
        
        ~EngineSpace() {
            glfwDestroyWindow(static_cast<GLFWwindow*>(GLFW.getEngineWin()));
        }

};

#endif