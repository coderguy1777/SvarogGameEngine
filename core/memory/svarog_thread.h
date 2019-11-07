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

template<typename Y>
struct SvarogTask {
    private:
        ClassString task_name;
        size_t task_id;
        unsigned int task_priority;
        bool is_completed;
        Y const& task;
        void set_class_name(ClassString new_task_name) {
            task_name = new_task_name;
        }

        void set_completion_state(int state) {
            if(state == 0) {
                is_completed = false;
            }

            if(state == 1) {
                is_completed = true;
            }
        }

        void make_task_id() {
            task_id = typeid(task).hash_code();
        }

        void set_task_priority(unsigned int new_task_pri) {
            task_priority = new_task_pri;
        }

        void set_task(Y const& new_task) {
            task = new_task;
        }

    public:
        SvarogTask(Y const& t, unsigned int task_pri, ClassString task_name) {
            set_task(t);
            set_class_name(task_name);
            set_task_priority(task_pri);
            set_completion_state(0);
            make_task_id();
        }
        
        ClassString get_task_name() const {
            return task_name;
        }

        Y get_task() const {
            return task;
        }

        unsigned int get_task_pri() const {
            return task_priority;
        }

        size_t get_task_id() const {
            return task_id;
        }

        bool get_completion_state() const {
            return is_completed;
        }
};

template<typename T>
class SvarogThread {
    private:
        struct ThreadInformation {
            private: 
                ClassString thread_class;
                uint64_t thread_id;
                bool end_condition;
            public: 
                void set_thread_class_name(ClassString new_thread_class) {
                    thread_class = new_thread_class;
                }

                void set_end_state(bool end_state) {
                    end_condition = end_state;
                }

                void set_thread_id() {
                    thread_id = std::hash<uint64_t>(static_cast<uint64_t>(get_thread_name_str()));
                }

                uint64_t get_thread_id() {
                    return thread_id;
                }

                std::string get_thread_name_str() const {
                    return thread_class.get_class_str();
                }

                unsigned int get_thread_name_pri() const {
                    return thread_class.get_class_id();
                }

                bool get_thread_end_state() const {
                    return end_condition;
                }

        } thread_name;
        Queue<SvarogTask<T>>thread_tasks;
        bool is_max;

    public:
        SvarogThread(ClassString new_thread_n, bool end_state) {
            thread_name.set_thread_class_name(new_thread_n);
            thread_name.set_end_state(end_state);
            thread_name.set_thread_id();
        }

        bool get_max() const;
        uint64_t get_thread_id() const;
        SvarogTask<T> get_task(size_t task_id) const;
        unsigned int thread_task_size() const;
        void schedule_task(SvarogTask<T> const&);
        void remove_task(size_t task_id);
        void run_task(size_t task_id);
};
#endif
