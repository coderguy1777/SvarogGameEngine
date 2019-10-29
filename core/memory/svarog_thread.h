#pragma once
#ifndef SVAROG_THREAD_H
#define SVAROG_THREAD_H
#include<thread>
#include<memory>
#include<functional>
#include "core/ds-classes/Array.h"
#include "core/ds-classes/ArrayList.h"
#include "core/ds-classes/ClassString.h"
// max count for thread
#define PROCESS_MAX 50
struct thread_info {
    long thread_id;
    ClassString class_name;
};

struct thread_process {
    std::thread process;
    thread_info process_info;
};

class SvarogThread {
    private:
        Array<std::thread, PROCESS_MAX>thread_li;
    public: 
        void insert_process(std::thread pr_a);
        void join_all();
};

#endif