#include "macrodefs.h"
#include "keyevent.h"

void KeyEvent::logKeyPressEvent() {
    std::cout << "KEY PRESS ON: " << this->get_keybind_ascii_code() << std::endl;
}

void KeyEvent::logKeyHeldEvent(Event e, int state) {
    auto keyevt_type = static_cast<unsigned int>(KeyEventTypes::KEY_HELD_EVT);
    
    std::string key_code_str = "Key Code: " + get_keybind_ascii_code();
    std::string key_char_str = "Key char: " + get_keybind_char();
    std::string key_event_type = "Key event type: " + static_cast<unsigned int>(keyevt_type);
    
    auto evtType = (const char*)e.get_typeof_event();
    auto evtPri = (const char*)e.get_priority();
    auto evtCause = (const char*)e.get_cause();
    // production of the key held log
    std::string heldLog(string("Key Code: " + get_keybind_ascii_code() + '\n') + string("Key char: " + get_keybind_char() + '\n') + string("Key event type: " + static_cast<unsigned int>(keyevt_type) + '\n') + 
    string(evtType + '\n') + string(evtPri + '\n') + string(evtCause + '\n') + string("Key Event type: " + state + '\n'));
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

}