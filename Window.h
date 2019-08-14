#pragma once
#ifndef WINDOW_H
#define WINDOW_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdexcept>
#include "core/String.h"

struct WindowFactors {
    int w;
    int h;
    String windowTitle;
    WindowFactors(unsigned int width = 1280, unsigned int height = 720, const String &winTitle = "Svarog Game Engine") : w(width), h(height), windowTitle(winTitle){}
};

class Window {
    public:
        virtual void useVSync() = 0;
        virtual void disableVSync() = 0;
        virtual ~Window() = default;
        virtual bool isVsyncOn() = 0;
        virtual int getWidth() const = 0;
        virtual int getHeight() const = 0;
        virtual String getTitle() const = 0;
        virtual void loadGLAD() = 0;
        virtual void* getWindow() const = 0;
        virtual void initWindow() = 0;
        virtual void displayWindow(WindowFactors *props) = 0;
};
#endif
