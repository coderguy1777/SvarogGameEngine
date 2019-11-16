#pragma once
#ifndef SVAROG_THREAD_TASK_H
#define SVAROG_THREAD_TASK_H
#include<iostream>
#include<functional>
#include<stack>
#include<cassert>
#include<boost/thread.hpp>
#include "core/ds-classes/ClassString.h"
#include "core/ds-classes/function_list.h"
struct thread_task_flags {
        bool use_mutex;
        bool use_sleep;
        float time_sleep;
        bool is_joinable;
        bool is_detached;
        bool get_mutex_state() const {
            return use_mutex;
        }

        bool get_sleep_state() const {
            return use_sleep;
        }

        float get_sleep_time() const {
            return time_sleep;
        }

        bool get_join_state() const {
            return is_joinable;
        }

        bool get_detach_state() const {
            return is_detached;
        }
};

template<typename Y>
class SvarogThreadTask {
    private:    
        boost::thread* task_thread;
        std::shared_ptr<thread_task_flags>svarog_task_flags;
        bool is_complete;
        void set_complete(uint state) {
            is_complete = (state == 1) ? true : false;
        }
    public:
        SvarogThreadTask(Y const& item) {
            task_thread = new boost::thread(item);
            svarog_task_flags = std::make_shared<thread_task_flags>();
        }

        void set_flags(bool sleep_state, bool mutex_state, float sleep_time) {
            svarog_task_flags->is_joinable = task_thread->joinable();
            svarog_task_flags->is_detached = !(task_thread->joinable());
            svarog_task_flags->use_sleep = sleep_state;
            svarog_task_flags->use_mutex = mutex_state;
            svarog_task_flags->time_sleep = sleep_time;
        }

        void join_thread() {
            task_thread->join();            
        }

        bool get_task_complete_state() const {
            return is_complete;
        }
};
#endif
