#include "svarog_thread.h"
void SvarogThread::insert_process(thread_process pr_a) {
    if(thread_li.get(PROCESS_MAX).process.joinable()) {
        throw invalid_argument("THREAD COUNT REACHED FOR CLASS PROCESS");
        spdlog::error("CLASS_NAME: {}", pr_a.process_info.class_name);
        spdlog::error("CLASS_ID: {}", pr_a.process_info.thread_id);
        exit(0);
    } else {
        
    }
}