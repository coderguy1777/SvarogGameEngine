#include "window_monitor.h"

void* WindowMonitor::get_monitor() {
    return win_monitor->monitor;
}

const char* WindowMonitor::get_monitor_name() {
    GLFWmonitor* m_monitor = static_cast<GLFWmonitor*>(this->get_monitor());
    const char* m_monitor_name = glfwGetMonitorName(m_monitor);
    return m_monitor_name;
}

int WindowMonitor::get_monitor_state() {
    return win_monitor->event_state;
}

bool WindowMonitor::get_monitor_connection() {
    return win_monitor->is_on;
}

void WindowMonitor::init_monitor() {
    win_monitor->monitor = glfwGetPrimaryMonitor();
    if(static_cast<GLFWmonitor*>(win_monitor->monitor) != NULL) {
        spdlog::info("Monitor Success loading...");
        spdlog::info("Monitor Name: {}", get_monitor_name());
    }
}