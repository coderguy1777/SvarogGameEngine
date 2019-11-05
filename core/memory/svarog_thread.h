#pragma once
#ifndef SVAROG_THREAD_H
#define SVAROG_THREAD_H
#include <thread>
#include <memory>
#include <functional>
#include <algorithm>
#include <mutex>
#include <memory>
#include <queue>
#include <iostream>
#include <stack>
#include "spdlog/spdlog.h"
#include "core/ds-classes/Queue.h"
#include "core/ds-classes/ClassString.h"
#define PROCESS_MAX 50
template<class T>
class SvarogThread {
    private:
        struct ThreadInformation {
            ClassString thread_class;
            uint64_t thread_id;
            bool end_condition;
        } thread_name;
        Queue<T>thread_tasks;
        bool is_max;
        
    public:
        bool get_max() const;
        void schedule_task(T const&);
        void remove_task(uint64_t task_id);
        uint64_t get_task_id() const;
        void run_task(uint64_t task_id);
        unsigned int thread_task_size() const;
        T get_task() const;
};
#endif
