#pragma once
#ifndef SVAROG_TASK_MANAGER_H
#define SVAROG_TASK_MANAGER_H
#include<iostream>
#include<functional>
#include<memory>
template<class TASK_VAL>
class TaskManager {
    public: 
        virtual void run_all_tasks() = 0;
        virtual void add_thread_task(TASK_VAL const&) = 0;
        virtual void remove_thread_task(TASK_VAL const&) = 0;
        virtual TASK_VAL get_task()  = 0;
        virtual unsigned int get_task_amount() const = 0; 
        virtual void run_all_tasks_priority() = 0;
};
#endif