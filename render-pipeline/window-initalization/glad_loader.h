#pragma once
#ifndef GLAD_LOADER_H
#define GLAD_LOADER_H
#include "render-pipeline/gl_libs.h"

class GladLoader {
    private:
        int glad_loaded;
    public:
        void load_glad();
        int get_load_state() const;

        void * operator new(size_t size) {
            void * lder = ::new GladLoader();
            return lder;
        }
};

#endif