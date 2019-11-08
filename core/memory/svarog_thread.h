#pragma once
#ifndef SVAROG_THREAD_H
#define SVAROG_THREAD_H
#include <thread>
#include <memory>
#include <functional>
#include <iomanip>
#include <unordered_set>
#include <algorithm>
#include <mutex>
#include <memory>
#include <iostream>
#include <stack>
#include "core/ds-classes/Stack.h"
#include "spdlog/spdlog.h"
#include "core/ds-classes/ClassString.h"
#define PROCESS_MAX 50

template<typename Y>
class SvarogTask {
    private:
        ClassString task_name;
        size_t task_id;
        unsigned int task_priority;
        bool is_completed;
        Y task{};
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
        SvarogTask(Y t, unsigned int task_pri, ClassString task_name) {
            set_task(t);
            set_class_name(task_name);
            set_task_priority(task_pri);
            set_completion_state(0);
            make_task_id();
        }

        //~SvarogTask() = delete;
        
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

        SvarogTask<Y>& operator=(SvarogTask<Y> task) noexcept {
            std::swap(task, task.task);
            std::swap(task_name, task.task_name);
            std::swap(task_priority, task.task_priority);
            std::swap(task_id, task.task_id);
            return *this;
        }
};

template<typename T>
class SvarogThread {
    private:
        struct ThreadInformation {
            private: 
                ClassString thread_class;
                size_t sva_thread_id;
                bool end_condition;
            public: 
                void set_thread_class_name(ClassString new_thread_class) {
                    thread_class = new_thread_class;
                }

                void set_end_state(bool end_state) {
                    end_condition = end_state;
                }

                void set_thread_id() {
                    // note to future self, std::hash has to have the data type being hashed.
                    sva_thread_id = std::hash<std::string>{}(thread_class.get_class_str());
                }

                size_t get_thread_id() const {
                    return sva_thread_id;
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
        std::stack<T>thread_tasks;
        bool is_max;

    public:
        SvarogThread(ClassString new_thread_n, bool end_state) {
            thread_name.set_thread_class_name(new_thread_n);
            thread_name.set_end_state(end_state);
            thread_name.set_thread_id();
        }

        bool get_max() const;
        size_t get_thread_id() const;
        T get_task(size_t task_id) const;
        unsigned int thread_task_size() const;
        void schedule_task(T const&);
        void remove_task(size_t task_id);
        void run_task(size_t task_id);
};

template<typename T>
bool SvarogThread<T>::get_max() const {
    return (thread_tasks.size() > PROCESS_MAX) ? true : false;
}

template<typename T>
size_t SvarogThread<T>::get_thread_id() const {
    return thread_name.get_thread_id();
}

template<typename T>
unsigned int SvarogThread<T>::thread_task_size() const {
    return thread_tasks.size();
}

template<typename T>
T SvarogThread<T>::get_task(size_t task_id) const {
    T const& temp_task = thread_tasks.top();
    auto temp_task_id = task_id;
    for(;!thread_tasks.empty() && !thread_tasks.size() == 0;) {
        auto temp_task = thread_tasks.top();
        thread_tasks.pop();
        if(thread_tasks.top().get_task_id() == temp_task_id) {
            temp_task = thread_tasks.top();
            temp_task_id = 0;
            break;
        } else {
            temp_task = thread_tasks.top();
            thread_tasks.pop();
            continue;
        }
    }
    return temp_task;
}

template<typename T>
void SvarogThread<T>::run_task(size_t task_id) {
    auto task_val = task_id;
    auto task = get_task(task_val);
    std::cout << typeid(task).name() <<'\n';
    /*
     std::thread task_thread = std::thread(&SvarogTask<T>::get_task, &task);
    if(task_thread.joinable()) {
        task_thread.join();
        spdlog::info("THREAD TASK RAN, TASK_NAME{}", task.get_task_name().get_class_str());
    }

    if(!task_thread.joinable()) {
        spdlog::error("ERROR TASK IS CORRUPT");
        task_thread.detach();
        exit(0);
    }
    */
}

template<typename T>
void SvarogThread<T>::remove_task(size_t task_id) {
    auto temp_id = task_id;
    bool is_rm = NULL;
    for(;!thread_tasks.empty() && !thread_tasks.size() == 0;) {
        auto temp_task = thread_tasks.top();
        thread_tasks.pop();
        if(temp_task.get_task_id() == temp_id) {
            thread_tasks.pop();
            spdlog::info("Task has been removed..");
            break;
        } else {
            temp_task = thread_tasks.top();
            thread_tasks.pop();
        }
    }
}
#endif
