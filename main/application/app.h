#pragma once 
#ifdef APP_H
#define APP_H
#endif
#include "main/materials/material.h"
#include "main/window/window.h"
namespace SvarogWindow{}
using namespace SvarogWindow;
class Material;
class Application {
    public: 
        Window winA;
        bool engineState;
        GLFWwindow* appWindow = winA.initliazeWindow();
        ArrayList<Material>wantedShaders;
        Application(){};
        Application(Window w, bool eState) {
            winA = w;
            engineState = eState;
        }
        // getters
        Window getWindow() const;
        bool getLoopState() const;
        Material getInputShader(int listIndex);
        ArrayList<Material>getShaderli() const;

        // setters
        void ChangeCurrWindow(Window win);
        void ChangeLoopState(bool newState);
        void setInputShader(int listIndex, Material material);

        // window context
        unsigned int shaderToUse();
        friend void framebuffersizecallback(GLFWwindow* window, int width, int height);
        void createWindowContext();
        void SvarogAppLoop();
};