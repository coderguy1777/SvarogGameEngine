#include "svarog_thread.h"
template<typename T>
bool SvarogThread<T>::get_max() const {
    return (thread_tasks.size() > PROCESS_MAX) ? true : false;
}

template<typename T>
uint64_t SvarogThread<T>::get_thread_id() const {
    return thread_name.get_thread_id();
}

template<typename T>
unsigned int SvarogThread<T>::thread_task_size() const {
    return thread_tasks.size();
}

template<typename T>
SvarogTask<T> SvarogThread<T>::get_task(size_t task_id) const {
    auto temp_task = NULL;
    auto temp_task_id = task_id;
    for(;!thread_tasks.isEmpty() && !thread_tasks.size() == 0;) {
        if(thread_tasks.get_next().get_task_id() == temp_task_id) {
            temp_task = thread_tasks.get_front();
            temp_task_id = 0;
            break;
        } else {
            temp_task = thread_tasks.get_next();
        }
    }
    return temp_task;
}

template<typename T>
void SvarogThread<T>::run_task(size_t task_id) {
    auto task_val = task_id;
    auto task = get_task(task_val);
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
}

template<typename T>
void SvarogThread<T>::remove_task(size_t task_id) {
    auto temp_id = task_id;
    bool is_rm = NULL;
    for(unsigned int i = 0; i < thread_tasks.size(); i++) {
        auto temp_task = thread_tasks.get_next();
        thread_tasks.g
    }
}