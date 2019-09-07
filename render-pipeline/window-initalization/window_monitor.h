#pragma once
#ifndef WINDOW_MONITOR_H
#define WINDOW_MONITOR_H
#include "gl_libs.h"
#include "macrodefs.h"
#include <spdlog/spdlog.h>
#include <iostream>
#include <memory>

class WindowMonitor {
    private: 
        struct SvarogMonitor {
            GLFWmonitor* monitor;
            int event_state;
            bool is_on;
        } win_mtr;
        SvarogMonitor* win_monitor;
    public: 
        WindowMonitor() {
            win_monitor = new SvarogMonitor();
        }
        void init_monitor();
        
        void* get_monitor();
        const char* get_monitor_name();
        int get_monitor_state();
        bool get_monitor_connection();
};

#endif