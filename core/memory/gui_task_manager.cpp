#include "gui_task_manager.h"
GuiTaskManager* GuiTaskManager::getGuiManagerInstance() {
    if(!gui_manager_instance) {
        gui_manager_instance = new GuiTaskManager();
    }
    return gui_manager_instance;
}

void GuiTaskManager::add_thread_task(SvarogGuiWindow const& new_window) {
    gui_task_stack.push(new_window);
}