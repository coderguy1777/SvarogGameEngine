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

void GuiTaskManager::run_all_tasks() {
    for(;!gui_task_stack.size() == 0 && !gui_task_stack.empty();) {
        auto temp_win = gui_task_stack.top();
        temp_win.render_frames();
        gui_task_stack.pop();
    }
}

unsigned int GuiTaskManager::get_task_amount() const {
    return gui_task_stack.size();
}

void GuiTaskManager::run_optimize_tasks() {

}

void GuiTaskManager::remove_thread_task(SvarogGuiWindow const& unwanted_task) {

}

GuiTaskManager* GuiTaskManager::gui_manager_instance = 0;