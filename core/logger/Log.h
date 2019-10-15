#pragma once
#ifdef LOG_H
#define LOG_H
#endif 
#include "spdlog/spdlog.h"
#include <iostream>
#define SVAROG_DEBUG(X) {spdlog::warn("DEBUG ERROR: {}", X);}
#define SVAROG_CLASS_DEBUG(X, N) spdlog::info("CLASS: {}", N); spdlog::info("CLASS_DEBUG: {}", X);
#define SVAROG_VAR_DEBUG(X, N) spdlog::info("VARIABLE: {}", N); spdlog::info("VARIABLE_DEBUG: {}", X);
class Logger {
    private:

    public:
};