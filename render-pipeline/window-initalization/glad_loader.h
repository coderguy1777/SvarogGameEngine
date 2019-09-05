#pragma once
#ifndef GLAD_LOADER_H
#define GLAD_LOADER_H
#include "render-pipeline/gl_libs.h"

class GladLoader {
    private:
        int glad_loaded;
    public:
        static void load_glad();
        int get_load_state() const;
};

#endif