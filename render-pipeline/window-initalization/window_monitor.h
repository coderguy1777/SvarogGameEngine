#pragma once
#ifndef WINDOW_MONITOR_H
#define WINDOW_MONITOR_H
#include "gl_libs.h"
#include "macrodefs.h"
#include <spdlog/spdlog.h>
#include <iostream>
#include <memory>
struct SvarogMonitor {
    GLFWmonitor* monitor;
    int event_state;
    bool is_on;
};
class Monitor {
    private:
        SvarogMonitor* win_monitor;
    public:
        virtual void* get_monitor() = 0;
        virtual const char* get_monitor_name() = 0;
        virtual int get_monitor_state() = 0;
        virtual bool get_monitor_connection() = 0;

};


class WindowMonitor : public Monitor {
    private: 
        SvarogMonitor* win_monitor;
    public: 
        WindowMonitor() : Monitor() {
            win_monitor = new SvarogMonitor();
        }
        virtual void* get_monitor() override;
        virtual const char* get_monitor_name() override;
        virtual int get_monitor_state() override; 
        virtual bool get_monitor_connection() override;
};

#endif