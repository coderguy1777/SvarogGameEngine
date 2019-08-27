#include "mouseevent.h"
unsigned int MouseEvent::get_mse_code() const {
    return mouseBt->mouse_code;
}

int MouseEvent::get_mse_state() const {
    return mouseBt->state;
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
            mousebtn_curr = "SVAROG_MIDDLE_MOUSE_BUTTON";
            break;
        case 2:
            mousebtn_curr = "SVAROG_LEFT_MOUSE_BUTTON";
            break;
        default:
            mousebtn_curr = "ERROR_STATE";
            break;
    }
    return mousebtn_curr;
}