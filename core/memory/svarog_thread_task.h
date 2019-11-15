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
        //boost::mutex* task_mutex;
        std::shared_ptr<thread_task_flags>svarog_task_flags;
    public:
        SvarogThreadTask(Y const& item) {
            task_thread = new boost::thread(item);
            //task_mutex = new boost::mutex();
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
            if(!svarog_task_flags->get_mutex_state()) {
                task_thread->join();
            }

            if(svarog_task_flags->get_sleep_state()) {
                //auto sleep_time = boost::chrono::seconds(static_cast<boost::chrono::seconds>(svarog_task_flags->get_sleep_time()));
                boost::this_thread::sleep_for(boost::chrono::seconds(2000));
                task_thread->join();
                task_thread->detach();
            }

            if(!svarog_task_flags->get_join_state() && svarog_task_flags->get_detach_state()) {
                spdlog::error("THREAD NOT JOINABLE: {}");
            } else if(svarog_task_flags->get_join_state() && !svarog_task_flags->get_detach_state()) {
                spdlog::info("THREAD IS JOINABLE: {}");
            }
        }
};
#endif
