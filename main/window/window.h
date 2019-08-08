#pragma once
#ifdef WINDOW_H
#define WINDOW_H
#endif
#include "core/String.h"
#include "main/exception.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#define GLFWFAILSTATE -1
#define GLFWGOODSTATE 0

namespace SvarogWindow {
    class Window {
        private:
            int GLAD_STATE = 0;
            int width, height;
            String windowTitle;
            void loadGlad() {
                if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
                    Exception::printException("GLAD FAILURE.");
                    GLAD_STATE = GLFWFAILSTATE;
                } else {
                    Exception::printException("GLAD SUCCESS TO LOAD.");
                    GLAD_STATE = GLFWGOODSTATE;
                }
            }

        public:
            Window(int w, int h, String title) {
                width = w;
                height = h;
                windowTitle = title;
            }
            Window(){};
            void * operator new(size_t size) {
                void * p = new ::SvarogWindow::Window();
                return p;
            }
            // getter functions
            int getWidth() const;
            int getHeight() const;
            String getTitle() const;
            int getGladState() const;

            // glad check
            inline bool isGladLoaded();

            // setter functions
            void changeHeight(int h);
            void changeWidth(int w);
            void changeTitle(String newTitle);

            // glfw window setup
            GLFWwindow* initliazeWindow();

    };
}