#include "svarog_thread.h"
bool SvarogThread::max_process_check() const {
    return max_reach;
}

void SvarogThread::add_function_process(std::function<void(int)> new_process, svarog_process_info new_process_info) {
    svarog_process process_container;
    process_container.set_process_details(new_process_info);
    process_container.set_mutex();
    process_container.process_val = std::thread(&new_process);
    thread_process_queue.push(process_container);
}

void SvarogThread::run_process(std::thread::id process_thread_id) {
    auto thread_id = process_thread_id;
    bool is_found = (thread_process_queue.top().get_process_id() == thread_id) ? true : false;
    bool reset;
    std::stack<svarog_process>temp_stack;
    for(;thread_process_queue.top().get_process_id() != process_thread_id || is_found;) {
        thread_process_queue.pop();
        if(is_found && thread_process_queue.top().is_thread_joinable()) {
            auto process_name = thread_process_queue.top().get_process_detail().get_process_class().get_class_str();
            thread_process_queue.top().process_val.join();
            spdlog::info("THREAD RAN: {}", process_name);
            reset = true;
            thread_process_queue.top().process_val.~thread();
            break;
        }

        if(!is_found && !thread_process_queue.top().is_thread_joinable()) {
            auto process_name = thread_process_queue.top().get_process_detail().get_process_class().get_class_str();
            thread_process_queue.top().process_val.~thread();
            spdlog::info("THREAD DESTROYED: {}", process_name);
            reset = true;
            break;
        }

        if(!is_found && thread_process_queue.empty()) {
            spdlog::info("THREAD ID INVALID, PROCESS NOT FOUND");
            spdlog::info("THREAD ID VAL DISPLAYED BELOW (CANT DISPLAY HERE DUE TO FORMATTING ERRORS.");
            std::cout << thread_id << '\n';           
            spdlog::info("----------------------------------------------------------------------------");
            reset = true;
            break;
        }
        temp_stack.push(thread_process_queue.top());
        thread_process_queue.pop();
    }

    if(reset) {
        thread_process_queue = temp_stack;
    }
}

void SvarogThread::sleep_process(std::thread::id process_id) {
    auto thread_id = process_id;
    bool sleep_process_condition = (thread_process_queue.top().get_process_id() == thread_id) ? true : false;
    bool reset;
    std::stack<svarog_process>temp_stack;
    for(;thread_process_queue.top().get_process_id != thread_id || sleep_process_condition;) {
        if(sleep_process_condition &&thread_process_queue.top().get_process_detail().get_sleep_state()) {
            auto sleep_process_max = std::chrono::seconds(static_cast<int>(thread_process_queue.top().get_process_detail().get_sleep_time()));
            auto chronos_cast = std::chrono::duration_cast<std::chrono::seconds>(sleep_process_max);
            thread_process_queue.top().process_mutex.lock();
            std::this_thread::sleep_for(std::chrono::seconds(chronos_cast));
            thread_process_queue.top().process_mutex.unlock();
            auto process_name = thread_process_queue.top().get_process_detail().get_process_class().get_class_str();
            spdlog::info("THREAD SLEEP EXITED, CONTINUING PROCESSES, CLASS NAME: {}", process_name);
            reset = true;
            break;
        }

        if(!sleep_process_condition && !thread_process_queue.top().get_process_detail().get_sleep_state()) {
            auto process_name = thread_process_queue.top().get_process_detail().get_process_class().get_class_str();
            spdlog::error("THREAD CANNOT SLEEP, CLASS NAME: {}",   process_name);
            reset = true;
            break;
        }

        if(!sleep_process_condition && thread_process_queue.empty()) {
            auto process_name = thread_process_queue.top().get_process_detail().get_process_class().get_class_str();
            spdlog::error("STACK IS EMPTY, THREAD ID INVALID, CLASS NAME: {}", process_name);
            reset = true;
            break;
        }
        temp_stack.push(thread_process_queue.top());
        thread_process_queue.pop();
    }

    if(reset) {
        thread_process_queue = temp_stack;
    }
}

void SvarogThread::lock_process(std::thread::id process_id) {

}

void SvarogThread::end_process(std::thread::id process_id) {

}

void SvarogThread::sort_process_queue(uint sort_order) {

}