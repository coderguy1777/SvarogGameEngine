#include "mouseevent.h"
unsigned int MouseEvent::get_mse_code() const {
    return mouseBt->mouse_code;
}

int MouseEvent::get_mse_state() const {
    return mouseBt->state;
}

Event MouseEvent::get_mouse_event() const {
    return log->e;
}

void MouseEvent::set_mse_event(Event new_evt) {
    log->e.setEventType(new_evt.get_typeof_event());
    log->e.setPriority(new_evt.get_priority());
    log->e.setCause(new_evt.get_cause());
}

void MouseEvent::set_mse_code(unsigned int new_code) {
    mouseBt->mouse_code = new_code;
}

void MouseEvent::set_mse_state(int new_state) {
    mouseBt->state = new_state;
}

std::string MouseEvent::get_state() {
    std::string state;
    switch(get_mse_state()) {
        case 1:
            state = "SVAROG_MOUSE_PRESS";
            break;
        case 2:
            state = "SVAROG_MOUSE_HELD";
            break;
        case 3:
            state = "SVAROG_MOUSE_RELEASE";
            break;
        default:
            state = "ERROR_STATE";
            break;
    }
    return state;
}

std::string MouseEvent::get_curr_button() {
    std::string mousebtn_curr;
    switch(get_mse_code()) {
        case 0:
            mousebtn_curr = "SVAROG_RIGHT_MOUSE_BUTTON";
            break;
        case 1:
            mousebtn_curr = "SVAROG_LEFT_MOUSE_BUTTON";
            break;
        case 2:
            mousebtn_curr = "SVAROG_MIDDLE_MOUSE_BUTTON";
            break;
        default:
            mousebtn_curr = "ERROR_STATE";
            break;
    }
    return mousebtn_curr;
}

void MouseEvent::logMousePressEvent() {
    spdlog::info("Mouse Button pressed: {}", get_curr_button());
    spdlog::info("Mouse Button state: {}", get_state());
    spdlog::info("Mouse Button ASCII code: {}", get_mse_code());
}

void MouseEvent::logMouseReleaseEvent() {
    spdlog::info("Mouse Button released: {}", get_curr_button());
    spdlog::info("Mouse Button state: {}", get_state());
    spdlog::info("Mouse Button ASCII code: {}", get_mse_code());
}

void MouseEvent::logMouseHeldEvent() {
    spdlog::info("Mouse Button held: {}", get_curr_button());
    spdlog::info("Mouse Button state: {}", get_state());
    spdlog::info("Mouse Button ASCII code: {}", get_mse_code());
}

void MouseEvent::set_mse_sub_evt_type(unsigned int evt_type) {
    unsigned int mouse_evt;
    switch(evt_type) {
        case 1:
            mouse_evt = static_cast<unsigned int>(mouse_evt_types::MOUSE_PRESS_EVT);
            break;
        case 2:
            mouse_evt = static_cast<unsigned int>(mouse_evt_types::MOUSE_RELEASE_EVT);
            break;
        case 3: 
            mouse_evt = static_cast<unsigned int>(mouse_evt_types::MOUSE_HELD_EVT);
            break;
        default:
            mouse_evt = 4;
            break;
    }
    log->mouse_sub_evt_type = mouse_evt;
}

unsigned int MouseEvent::get_mse_evt_type() const {
    return log->mouse_sub_evt_type;
}