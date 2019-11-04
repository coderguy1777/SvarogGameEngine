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
#include "spdlog/spdlog.h"
#include <iostream>
#include <stack>
// note to self, dont include engine header in other sub files
// header file leak occurs (include errors on build time)

#include "core/ds-classes/ClassString.h"
#define PROCESS_MAX 50

struct svarog_process_info {
    private:    
        ClassString process_class;
        bool process_end_condition;
        unsigned int priority;
        bool use_sleep;
        float sleep_time;
        bool use_mutex_lock;
        bool is_joinable;

    public: 
        void set_join_state(bool join_state) {
            is_joinable = join_state;
        }

        void set_mutex_lock(bool lock_state) {
            use_mutex_lock = lock_state;
        }

        void set_sleep_time(float time) {
            sleep_time = time;
        }

        void set_sleep_use(bool sleep_state) {
            use_sleep = sleep_state;
        }

        void set_process_class_name(ClassString class_used) {
            process_class = class_used;
        }

        void set_end_state(bool end_state) {
            process_end_condition = end_state;
        }

        ClassString get_process_class() const {
            return process_class;
        }

        bool get_join_state() const {
            return is_joinable;
        }

        bool get_end_state() const {
            return process_end_condition;
        }

        float get_sleep_time() const {
            return sleep_time;
        }

        unsigned int get_process_priority() const {
            return priority;
        }

        bool get_mutex_state() const {
            return use_mutex_lock;
        }

        bool get_sleep_state() const {
            return use_sleep;
        }
};

struct svarog_process {
    private: 
        svarog_process_info process_detail;
        std::thread::id process_id = process_val.get_id();
    public: 
        std::mutex process_mutex;
        std::thread process_val;
        void set_process_details(svarog_process_info details) {
            process_detail.set_mutex_lock(details.get_mutex_state());
            process_detail.set_process_class_name(details.get_process_class());
            process_detail.set_sleep_time(details.get_sleep_time());
            process_detail.set_sleep_use(details.get_sleep_state());
            process_detail.set_end_state(details.get_end_state());
        }

        // learn what swap does in std::thread usage, and change 
        // if this isnt thread safe.
        void set_process_thread(std::function<void()> process) {
            process_val = std::thread(process);
        }


        void set_mutex() {
            bool use_mutex;
            if(process_detail.get_mutex_state()) {
                use_mutex = true;
                spdlog::info("MUTEX NOT DESTROYED");
            }

            if(!use_mutex) {
                use_mutex = false;
                process_mutex.~mutex();
                spdlog::info("MUTEX DESTROYED");
            }
        }

        svarog_process_info get_process_detail() const {
            return process_detail;
        }

        unsigned int thread_concurrency_size() const {
            return process_val.hardware_concurrency();
        }

        bool is_thread_joinable() const {
            return (process_val.joinable() == process_detail.get_join_state()) ? true : false;
        }

        std::thread::id get_process_id() const {
            return process_id;
        }
};
// use enum class to designate thread types
// later on maybe, for now testing is needed.

class SvarogThread {
    private: 
        // for max effeicny, make sure queue used in future, bugs previous in last class of it
        // when template class was attempted.
        std::stack<svarog_process>thread_process_queue;
        std::stack<svarog_process>process_stack;
        bool max_reach = (thread_process_queue.size() == PROCESS_MAX) ? true : false;
    public: 
        void add_function_process(std::function<void(int)> new_process, svarog_process_info new_process_info);
        void run_process(std::thread::id process_id);
        void sleep_process(std::thread::id process_id);
        void add_new_process(svarog_process process_a);
        void lock_process(std::thread::id process_id);
        void end_process(std::thread::id process_id);
        void sort_process_queue(uint sort_order);
        bool max_process_check() const;
        // TODO: make it so the thread id is retrieved upon adding, 
        // or change data type thats being searched for the given 
        // process to be a different data type.
        svarog_process get_top() const;
};
#endif