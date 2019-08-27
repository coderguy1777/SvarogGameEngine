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
    std::cout << "Event type: " << static_cast<unsigned int>(log->e.get_typeof_event()) << std::endl;
    std::cout << "Event priority: " << static_cast<unsigned int>(log->e.get_priority()) << std::endl;
    std::cout << "Event cause: " << log->e.get_cause() << std::endl;
    std::cout << "Mouse Button pressed: " << get_curr_button() << std::endl;
    std::cout << "Mouse Button state: " << get_state() << std::endl;
    std::cout << "Mouse Button ASCII code: " << get_mse_code() << std::endl;
    spacer();
}

void MouseEvent::logMouseReleaseEvent() {
    std::cout << "Event type: " << static_cast<unsigned int>(log->e.get_typeof_event()) << std::endl;
    std::cout << "Event priority: " << static_cast<unsigned int>(log->e.get_priority()) << std::endl;
    std::cout << "Event cause: " << log->e.get_cause() << std::endl;
    std::cout << "Mouse Button released: " << get_curr_button() << std::endl;
    std::cout << "Mouse Button state: " << get_state() << std::endl;
    std::cout << "Mouse Button ASCII code: " << get_mse_code() << std::endl;
    spacer();
}

void MouseEvent::logMouseHeldEvent() {
    std::cout << "Event type: " << static_cast<unsigned int>(log->e.get_typeof_event()) << std::endl;
    std::cout << "Event priority: " << static_cast<unsigned int>(log->e.get_priority()) << std::endl;
    std::cout << "Event cause: " << log->e.get_cause() << std::endl;
    std::cout << "Mouse Button held: " << get_curr_button() << std::endl;
    std::cout << "Mouse Button state: " << get_state() << std::endl;
    std::cout << "Mouse Button ASCII code: " << get_mse_code() << std::endl;
    spacer();
}