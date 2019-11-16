#include "render_task_manager.h"
RenderTaskManager* RenderTaskManager::getRenderManager() {
    if(!render_mg_instance) 
        render_mg_instance = new RenderTaskManager;
    return render_mg_instance;
}

void RenderTaskManager::add_thread_task(RenderObj const& task_val) {
    render_task.push_back(task_val);
}

void RenderTaskManager::remove_thread_task(RenderObj const& unwanted_task) {
    for(unsigned int i = 0; i < render_task.size(); ++i) {
        bool is_found = (render_task[i].get_mesh_name() == unwanted_task.get_mesh_name()) ? true : false;
        if(is_found) {
            spdlog::info("Task found, removing task...");
            render_task.pop_back();
            break;
        }
    }
}

RenderObj RenderTaskManager::get_task() {
    for(const auto& render_val: render_task) {
        return render_val;
    }
}

unsigned int RenderTaskManager::get_task_amount() const {
    return render_task.size();
}

void RenderTaskManager::run_all_tasks() {
    for(const auto& shape: render_task) {
        if(shape.get_mesh().get_init_state()) {
            shape.get_mesh().draw();
        }

        if(!shape.get_mesh().get_init_state()) {
            shape.get_mesh().init();
            shape.get_mesh().draw();
        }
        shape.get_mesh().del_buffers();
    }
}

void RenderTaskManager::run_all_tasks_priority() {
    
}
RenderTaskManager* RenderTaskManager::render_mg_instance = 0;
/*
    Note to future self: 
    figure out how to use mutexs properly to lock tasks, if need be.
*/