#pragma once 
#ifdef APP_H
#define APP_H
#endif
#include<glad/glad.h>
#include <GLFW/glfw3.h>
#include "main/shapes/shape.h"
#include "core/events/event-listeners/EventListener.h"
#include "main/materials/material.h"
#include "core/ds-classes/Array.h"
#include "core/events/event-types/mouseevent.h"
#include "core/events/event-types/keyevent.h"
#include "core/events/EventDispatch.h"
#include "main/window/window.h"
class Application {
    private:
        mutable bool state_tst;
        Array<Event, 10>event_queue_key;
        Array<MouseEvent, 50>event_queue_mouse;
        Array<Event, 10>event_queue_window; 
    public: 
        EventListener evt_type_listen;
        Window winA;
        bool engineState;
        void tst(MouseEvent e) {
            event_queue_mouse.add(e);
            spdlog::info("Event 1 type: {}", event_queue_mouse.get(0).get_curr_button());
            spdlog::info("Event size: {} ", event_queue_mouse.length());
        }
        void* getWindow() {return appWindow;};
        // TODO, create event handler functions for classes
        Application(){}
        ~Application() {
            end();
        }
        void reset_bool_state() {
            state_tst = false;
        }
        void set_bool_state() {
            state_tst = true;
        }
        bool get_state() const { return state_tst;}
        // engine core methods
        void end();
        void OnUpdate();
        void FrameBufferCallBack();
        void VSYNC_on();
        void VSYNC_off();
        bool isVSYNCon();
        void makeContextCurr();
        void createWindowContext();
        void SvarogAppLoop();
            using EvtListener = std::function<void(EventListener&)>;

        private: 
            bool isVsyncOn;
            GLFWwindow* appWindow;
            WindowProp window;
            static Application* s_instance;
};