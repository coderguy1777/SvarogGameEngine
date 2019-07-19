#pragma once
#ifdef EXCEPTION_H
#define EXCEPTION_H
#endif
#include<stdexcept>
using namespace std;
namespace Exception {
    void printException(const char * exception_msg) {
        throw std::invalid_argument(exception_msg);
    }
}