#include "window_monitor.h"

void* WindowMonitor::get_monitor() {
    return win_monitor->monitor;
}
// TODO: make main monitor be a static instance, so
// given a call, it can be pulled statically and 
// called like that as well.
const char* WindowMonitor::get_monitor_name() {
    GLFWmonitor* m_monitor = glfwGetPrimaryMonitor();
    const char* m_monitor_name = glfwGetMonitorName(m_monitor);
    return m_monitor_name;
}

int WindowMonitor::get_monitor_state() {
    return win_monitor->event_state;
}

bool WindowMonitor::get_monitor_connection() {
    return win_monitor->is_on;
}