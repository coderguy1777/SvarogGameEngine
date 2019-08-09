#pragma once 
#ifndef APP_H
#define APP_H
#include "main/materials/material.h"
#include "main/window/window.h"
#include "core/ArrayList.h"
#include "macrodefs.h"
#include<bits/stdc++.h>
namespace SvarogWindow{}
using namespace SvarogWindow;
FORWARD_DEC(Material);
class Application {
    public: 
        static Window winA;
        static bool engineState;
        static GLFWwindow* appWindow;
        ArrayList<Material> wantedShaders;
        Application(){};
        Application(Window w, bool eState) {
            winA = w;
            engineState = eState;
        }

        Application(GLFWwindow* window, bool eState) {
            appWindow = window;
            engineState = eState;
        }
        // getters
        Window getWindow() const;
        bool getLoopState() const;
        Material getInputShader(int listIndex);
        ArrayList<Material>getShaderli() const;
        void setInputShader(int listIndex, Material material) {
            wantedShaders.add(material);
        }
        // setters
        void ChangeCurrWindow(Window win);
        void ChangeLoopState(bool newState);
        // window context
        unsigned int shaderToUse();
        static inline void frameFunc(GLFWwindow* window, int width, int height) {
            framebuffersizecallback(window, width, height);
        }
        static void framebuffersizecallback(GLFWwindow* window, int width, int height) {
            glViewport(0, 0, width, height);
        }
        void createWindowContext();
        void SvarogAppLoop();
};
#endif