#include "libs.h"
namespace SvarogEngineCore {
    String winTitle;
    int winWidth, winHeight;
    Window makeNewWindow(String winTitle, int winWidth, int winHeight) {
        return Window(winWidth, winHeight, winTitle);
    }

    GLFWwindow* makeappWindow(Window win) {
        return win.initliazeWindow();
    }

    Application makeNewApp(GLFWwindow* window, bool wantedEState) {
        return Application(window, wantedEState);
    }

    void streamShaders(int spot, Material material) {
        Application::setInputShader(spot, material);
    }

    void doFrameBuffer(GLFWwindow* window, int w, int h) {
        Application::frameFunc(window, w, h);
    }
    
    void runApplication() {
        Application::createWindowContext();
        Application::SvarogAppLoop();
    }
}