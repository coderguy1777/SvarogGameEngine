#pragma once
#ifndef RENDER_TASK_MANAGER_H
#define RENDER_TASK_MANAGER_H
#include <stack>
#include <boost/thread.hpp>
#include <boost/asio.hpp>
#include <boost/thread/thread_pool.hpp>
#include "svarog_task_manager.h"
#include "svarog_thread_task.h"
#include "render-pipeline/mesh/svarog_renderobj.h"
#include "spdlog/spdlog.h"
class RenderTaskManager : public TaskManager<RenderObj> {
    private: 
        std::vector<RenderObj>render_task;
        uint task_max;
        static RenderTaskManager* render_mg_instance;
        RenderTaskManager() {}

    public:
        static RenderTaskManager* getRenderManager(); 
        virtual void run_all_tasks() override;
        virtual void add_thread_task(RenderObj const& task_val) override;
        virtual void remove_thread_task(RenderObj const& unwanted_task) override;
        virtual RenderObj get_task() override;
        virtual unsigned int get_task_amount() const override;
        virtual void run_all_tasks_priority() override;
};

#endif