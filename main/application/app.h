#pragma once 
#ifdef APP_H
#define APP_H
#endif
#include "libs.h"
#include "window/window.h"

namespace SvarogApplication {
    class Application {
        private:
            SvarogWindow::Window winA;
            bool engineState;
            GLFWwindow* appWindow = winA.initliazeWindow();
        public: 
            Application(){};
            Application(SvarogWindow::Window w, bool eState) {
                winA = w;
                engineState = eState;
            }
            // getters
            SvarogWindow::Window getWindow() const;
            bool getLoopState() const;

            // setters
            void ChangeCurrWindow(SvarogWindow::Window win);
            void ChangeLoopState(bool newState);

            // window context
            friend void framebuffersizecallback(GLFWwindow* window, int width, int height);
            void createWindowContext();
            void SvarogAppLoop();
    };
}