#include "macrodefs.h"
#include "keyevent.h"

String KeyEvent::logKeyPressEvent(Event e, int state) {
    String a;
    auto keyevt_type = KeyEventTypes::KEY_PRESS_EVT;
    std::string key_code_str = "Key Code: " + get_keybind_ascii_code();
    std::string key_char_str = "Key char: " + get_keybind_char();
    std::string key_event_type = "Key event type: " + static_cast<unsigned int>(keyevt_type);
   
    auto evtType = (const char*)e.get_typeof_event();
    auto evtPri = (const char*)e.get_priority();
    auto evtCause = (const char*)e.get_cause();
    // making of the key press log
    std::string pressLog(string("Key Code: " + get_keybind_ascii_code() + '\n') + string("Key char: " + get_keybind_char() + '\n') + string("Key event type: " + static_cast<unsigned int>(keyevt_type) + '\n') + 
    string(evtType + '\n') + string(evtPri + '\n') + string(evtCause + '\n') + string("Key Event type: " + state + '\n'));
    a = pressLog;

    //if(input->isKeyPressed(static_cast<int>(get_keybind_ascii_code())) == true) {
    //}
    return a;
}

void KeyEvent::logKeyHeldEvent(Event e, int state) {
    auto keyevt_type = KeyEventTypes::KEY_HELD_EVT;
    
    std::string key_code_str = "Key Code: " + get_keybind_ascii_code();
    std::string key_char_str = "Key char: " + get_keybind_char();
    std::string key_event_type = "Key event type: " + static_cast<unsigned int>(keyevt_type);
    
    auto evtType = (const char*)e.get_typeof_event();
    auto evtPri = (const char*)e.get_priority();
    auto evtCause = (const char*)e.get_cause();
    // production of the key held log
    std::string heldLog(string("Key Code: " + get_keybind_ascii_code() + '\n') + string("Key char: " + get_keybind_char() + '\n') + string("Key event type: " + static_cast<unsigned int>(keyevt_type) + '\n') + 
    string(evtType + '\n') + string(evtPri + '\n') + string(evtCause + '\n') + string("Key Event type: " + state + '\n'));
    
    if(input->isKeyHeld(static_cast<int>(get_keybind_ascii_code())) == true) {
        log = new String(heldLog);
    }
}

void KeyEvent::logKeyRepeatEvent(Event e, int state) {
    auto keyevt_type = KeyEventTypes::KEY_HELD_EVT;
    
    std::string key_code_str = "Key Code: " + get_keybind_ascii_code();
    std::string key_char_str = "Key char: " + get_keybind_char();
    std::string key_event_type = "Key event type: " + static_cast<unsigned int>(keyevt_type);
    
    auto evtType = (const char*)e.get_typeof_event();
    auto evtPri = (const char*)e.get_priority();
    auto evtCause = (const char*)e.get_cause();
    // making of the repeat log
    std::string repeatLog(string("Key Code: " + get_keybind_ascii_code() + '\n') + string("Key char: " + get_keybind_char() + '\n') + string("Key event type: " + static_cast<unsigned int>(keyevt_type) + '\n') + 
    string(evtType + '\n') + string(evtPri + '\n') + string(evtCause + '\n') + string("Key Event type: " + state + '\n'));
    
    if(input->isKeyRepeat(static_cast<int>(get_keybind_ascii_code()) == true)) {
        log = String(repeatLog);
    }
}

void KeyEvent::logKeyReleaseEvent(Event e, int state) {
    auto keyevt_type = KeyEventTypes::KEY_HELD_EVT;
    
    std::string key_code_str = "Key Code: " + get_keybind_ascii_code();
    std::string key_char_str = "Key char: " + get_keybind_char();
    std::string key_event_type = "Key event type: " + static_cast<unsigned int>(keyevt_type);
    
    auto evtType = (const char*)e.get_typeof_event();
    auto evtPri = (const char*)e.get_priority();
    auto evtCause = (const char*)e.get_cause();
    // making of release log
    std::string releaseLog(string("Key Code: " + get_keybind_ascii_code() + '\n') + string("Key char: " + get_keybind_char() + '\n') + string("Key event type: " + static_cast<unsigned int>(keyevt_type) + '\n') + 
    string(evtType + '\n') + string(evtPri + '\n') + string(evtCause + '\n') + string("Key Event type: " + state + '\n'));

    if(input->isKeyReleased(static_cast<int>(get_keybind_ascii_code()) == true)) {
        String a(releaseLog);
        log = a;
    }
}

char KeyEvent::findKeyChar(unsigned int code) {

}

int KeyEvent::getKeyCode() {
    int keyCode = 0;
    switch(get_keybind_char()) {
        case 'A':
            keyCode = SVAROG_KEY_A;
            break;
        case 'B':
            keyCode = SVAROG_KEY_B;
            break;
        case 'C':
            keyCode = SVAROG_KEY_C;
            break;
        case 'D':
            keyCode = SVAROG_KEY_D;
            break;
        case 'E':
            keyCode = SVAROG_KEY_E;
            break;
        case 'F':
            keyCode = SVAROG_KEY_F;
            break;
        case 'G':
            keyCode = SVAROG_KEY_G;
            break;
        case 'H':
            keyCode = SVAROG_KEY_H;
            break;
        case 'I':
            keyCode = SVAROG_KEY_I;
            break;
        case 'J':
            keyCode = SVAROG_KEY_J;
            break;
        case 'K':
            keyCode = SVAROG_KEY_K;
            break;
        case 'L':
            keyCode = SVAROG_KEY_L;
            break;
        case 'M':
            keyCode = SVAROG_KEY_M;
            break;
        case 'N':
            keyCode = SVAROG_KEY_N;
            break;
        case 'O':
            keyCode = SVAROG_KEY_O;
            break;
        case 'P':
            keyCode = SVAROG_KEY_P;
            break;
        case 'Q':
            keyCode = SVAROG_KEY_Q;
            break;
        case 'R':
            keyCode = SVAROG_KEY_R;
            break;
        case 'S':
            keyCode = SVAROG_KEY_S;
            break;
        case 'T':
            keyCode = SVAROG_KEY_T;
            break;
        case 'U':
            keyCode = SVAROG_KEY_U;
            break;
        case 'V':
            keyCode = SVAROG_KEY_V;
            break;
        case 'W':
            keyCode = SVAROG_KEY_W;
            break;
        case 'X':
            keyCode = SVAROG_KEY_X;
            break;
        case 'Y':
            keyCode = SVAROG_KEY_Y;
            break;
        case 'Z':
            keyCode = SVAROG_KEY_Z;
            break;
        case '!':
            keyCode = SVAROG_KEY_EXCL_PT;
            break;
        case '"':
            keyCode = SVAROG_KEY_QUOTATION;
            break;
        case '#':
            keyCode = SVAROG_KEY_HASHTAG;
            break;
        default:
            keyCode = 0;
            break;
    }
    return keyCode;
}