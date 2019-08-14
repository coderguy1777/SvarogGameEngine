#pragma once
#ifdef SVAROGWINDOW_H
#define SVAROGWINDOW_H
#endif
#include "macrodefs.h"
#include "Window.h"
#define VSYNC_ON 1
#define VSYNC_OFF 0
class SvarogWindow : public Window {
    private:
        WindowFactors *m_win;
        bool VSync;
        int GLAD_STATE;
        GLFWwindow* win;
        bool glfwState;
    public:
        int getWidth() const override;
        int getHeight() const override;
        virtual String getTitle() const override;
        virtual void loadGLAD();
        virtual void* getWindow();
        void initWindow() override;
        inline void* getWindow() const override {return m_win;}
        bool isVsyncOn() override;
        virtual void useVSync();
        void VSyncState();
        virtual void displayWindow(WindowFactors *props);
};