#pragma once
#ifndef SVAROG_THREAD_H
#define SVAROG_THREAD_H
#include<thread>
#include<memory>
#include<functional>
#include "core/ds-classes/Stack.h"
#include "core/ds-classes/Array.h"
#include "core/ds-classes/ArrayList.h"
#include "core/ds-classes/ClassString.h"
#define PROCESS_MAX 50

class SvarogThread {
    private: 
        struct process_details {
            std::thread process_thread;
            ClassString process_class;
            unsigned int process_priority; // for designating priority of process in the thread

            ClassString get_process_class() const {
                return process_class;
            }

            unsigned int get_process_priority() const {
                return process_priority;
            }

            std::thread::id get_id() {
                return process_thread.get_id();
            }        
        };

        struct thread_values {
            Stack<process_details>current_processes;
            unsigned int process_count;
            bool is_max = (process_count == 50) ? true : false;
        } thread_vals;

    protected: 
        virtual void add_process(process_details new_process) = 0;
    public: 
        virtual void set_process_count(uint processes_added) = 0;
        virtual void check_integrity() = 0;
        virtual bool max_process_check() const = 0;
        virtual unsigned int get_process_amount() const  = 0;
        virtual process_details find_process(ClassString process_class, unsigned int pri) const  = 0;
        virtual void join_all() = 0;
        virtual void detach_all() = 0;
        virtual void clear_thread() = 0;
        virtual std::thread get_thread_process(std::thread::id thread_id) const = 0;
};

#endif