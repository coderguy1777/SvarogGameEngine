#pragma once
#ifndef GUI_TASK_MANAGER_H
#define GUI_TASK_MANAGER_H
#include "svarog_task_manager.h"
#include "main/enginewindow/engine-gui/gui_window.h"

class GuiTaskManager : public TaskManager<SvarogGuiWindow> {
    protected:
        void resize_gui_components();
    private: 
        struct gui_event_flags {
            bool resize_gui;
            bool collapse_gui;
            uint resize_state;
            uint collapse_state;
        } gui_events;
        static GuiTaskManager* gui_manager_instance;
        GuiTaskManager() {}
        std::stack<SvarogGuiWindow>gui_task_stack;
    public:
        static GuiTaskManager* getGuiManagerInstance();
        void set_resize_state(uint resize_state);
        void set_collapse_state(uint collapse_state);
        virtual void add_thread_task(SvarogGuiWindow const& new_task) override;
        virtual void run_all_tasks() override;
        virtual SvarogGuiWindow get_task() override;
        virtual void remove_thread_task(SvarogGuiWindow const& unwanted_task) override;
        virtual void run_optimize_tasks() override;
        virtual unsigned int get_task_amount() const override;
};
#endif