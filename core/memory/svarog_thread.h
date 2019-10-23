#pragma once
#ifndef SVAROG_THREAD_H
#define SVAROG_THREAD_H
#include<thread>
#include<memory>
#include<functional>
#include "ds-classes/Array.h"
#include "ds-classes/ArrayList.h"
#include "ds-classes/ClassString.h"
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
        Array<thread_process, PROCESS_MAX>thread_li;
    public: 
        void insert_process(thread_process pr_a);
        void join_all();
};

#endif