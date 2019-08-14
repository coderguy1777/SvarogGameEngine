#include "SvarogWindow.h"

int SvarogWindow::getWidth() const {
    return m_win->w;
}

int SvarogWindow::getHeight() const {
    return m_win->h;
}

String SvarogWindow::getTitle() const {
    return m_win->windowTitle;
}

void SvarogWindow::initWindow() {
    displayWindow(m_win);
}

void SvarogWindow::loadGLAD() {
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        throw std::invalid_argument("GLAD FAILURE.");
        GLAD_STATE = -1;
    } else {
        GLAD_STATE = 0;
    }
}

bool SvarogWindow::isVsyncOn() {
    return VSync;
}

void SvarogWindow::useVSync() {
    VSync = true;
}

void SvarogWindow::VSyncState() {
    if(VSync) {
        glfwSwapInterval(VSYNC_ON);
    }

    if(!VSync) {
        glfwSwapInterval(VSYNC_OFF);
    }
}

void SvarogWindow::displayWindow(WindowFactors *props) {
    auto glfw_state = glfwInit();
    if(!glfw_state) {
        glfwState = false;
        ASSERT_EQUAL(glfwState, NULL);
    }
}