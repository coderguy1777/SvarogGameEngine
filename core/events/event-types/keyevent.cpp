#include "macrodefs.h"
#include "keyevent.h"

void KeyEvent::logKeyPressEvent() {
    std::cout << "Event type: " << static_cast<unsigned int>(log->keyevt.get_typeof_event()) << std::endl;
    std::cout << "Event priority: " << static_cast<unsigned int>(log->keyevt.get_priority()) << std::endl;
    std::cout << "Event cause: " << log->keyevt.get_cause() << std::endl;
    std::cout << "Key Pressed: " << get_keybind_char() << std::endl;
    std::cout << "Key State: " << get_state() << std::endl;
    std::cout << "Key ASCII Code: " << get_keybind_ascii_code() << std::endl;
    spacer();
}


void KeyEvent::logKeyReleaseEvent() {
    std::cout << "Event type: " << static_cast<unsigned int>(log->keyevt.get_typeof_event()) << std::endl;
    std::cout << "Event priority: " << static_cast<unsigned int>(log->keyevt.get_priority()) << std::endl;
    std::cout << "Event cause: " << log->keyevt.get_cause() << std::endl;
    std::cout << "Key Released: " << get_keybind_char() << std::endl;
    std::cout << "Key State: " << get_state() << std::endl;
    std::cout << "Key ASCII Code: " << get_keybind_ascii_code() << std::endl;
    spacer();
}

void KeyEvent::logKeyHeldEvent() {
    std::cout << "Event type: " << static_cast<unsigned int>(log->keyevt.get_typeof_event()) << std::endl;
    std::cout << "Event priority: " << static_cast<unsigned int>(log->keyevt.get_priority()) << std::endl;
    std::cout << "Event cause: " << log->keyevt.get_cause() << std::endl;
    std::cout << "Key Held: " << get_keybind_char() << std::endl;
    std::cout << "Key State: " << get_state() << std::endl;
    std::cout << "Key ASCII Code: " << get_keybind_ascii_code() << std::endl;
    spacer();
}

void KeyEvent::logKeyRepeatEvent() {
    std::cout << "Event type: " << static_cast<unsigned int>(log->keyevt.get_typeof_event()) << std::endl;
    std::cout << "Event priority: " << static_cast<unsigned int>(log->keyevt.get_priority()) << std::endl;
    std::cout << "Event cause: " << log->keyevt.get_cause() << std::endl;
    std::cout << "Key repeated: " << get_keybind_char() << std::endl;
    std::cout << "Key State: " << get_state() << std::endl;
    std::cout << "Key ASCII Code: " << get_keybind_ascii_code() << std::endl;
    spacer();
} 

std::string KeyEvent::get_state() {
    std::string state;
    switch(get_key_evt_state()) {
        case 1:
            state = "SVAROG_PRESS";
            break;
        case 2:
            state = "SVAROG_HELD";
            break;
        case 3: 
            state = "SVAROG_RELEASE";
            break;
        case 4:
            state = "SVAROG_DBL_TAP";
            break;
        default: 
            state = "ERROR_STATE";
            break;
    }
    return state;
}

char KeyEvent::get_keycode_char(unsigned int code) {
    char key;
    switch(code) {
        case SVAROG_KEY_SPACE:
            key = '\0';
            break;
        case SVAROG_KEY_EXCL_PT:
            key = '!';
            break;
        case SVAROG_KEY_QUOTATION: 
            key = '\"';
            break;
        case SVAROG_KEY_HASHTAG:
            key = '#';
            break;
        case SVAROG_KEY_DLR_SIGN:
            key = '$';
            break;
        case SVAROG_KEY_PCT_SIGN:
            key = '%';
            break;
        case SVAROG_KEY_AND_SIGN:
            key = '&';
            break;
        case SVAROG_KEY_APST_SIGN:
            key = '\'';
            break;
        case SVAROG_KEY_OPN_PTH:
            key = '(';
            break;
        case SVAROG_KEY_CLSE_PTH:
            key = ')';
            break;
        case SVAROG_KEY_MULT_SYM:
            key = '*';
            break;
        case SVAROG_KEY_ADD_SYM:
            key = '+';
            break;
        case SVAROG_KEY_COMMA:
            key = ',';
            break;
        case SVAROG_KEY_HYPH_MIN:
            key = '-';
            break;
        case SVAROG_KEY_PERIOD:
            key = '.';
            break;
        case SVAROG_KEY_SOLIDOUS:
            key = '/';
            break;
        case SVAROG_KEY_NUM_1:
            key = '1';
            break;
        case SVAROG_KEY_NUM_2:
            key = '2';
            break;
        case SVAROG_KEY_NUM_3:
            key = '3';
            break;
        case SVAROG_KEY_NUM_4:
            key = '4';
            break;
        case SVAROG_KEY_NUM_5:
            key = '5';
            break;
        case SVAROG_KEY_NUM_6:
            key = '6';
            break;
        case SVAROG_KEY_NUM_7:
            key = '7';
            break;
        case SVAROG_KEY_NUM_8:
            key = '8';
            break;
        case SVAROG_KEY_NUM_9:
            key = '9';
            break;
        case SVAROG_KEY_NUM_0: 
            key = '0';
            break;
        case SVAROG_KEY_CLN:
            key = ':';
            break;
        case SVAROG_KEY_SMI_CLN:
            key = ';';
            break;
        case SVAROG_KEY_LSN_SYM:
            key = '<';
            break;
        case SVAROG_KEY_EQ_SYM:
            key = '=';
            break;
        case SVAROG_KEY_GRN_SYM:
            key = '>';
            break;
        case SVAROG_KEY_QS_SYM:
            key = '?';
            break;
        case SVAROG_KEY_AT_SYM:
            key = '@';
            break;
        case SVAROG_KEY_A:
            key = 'A';
            break;
        case SVAROG_KEY_B:
            key = 'B';
            break;
        case SVAROG_KEY_C:
            key = 'C';
            break;
        case SVAROG_KEY_D:
            key = 'D';
            break;
        case SVAROG_KEY_E:
            key = 'E';
            break;
        case SVAROG_KEY_F:
            key = 'F';
            break;
        case SVAROG_KEY_G:
            key = 'G';
            break;
        case SVAROG_KEY_H:
            key = 'H';
            break;
        case SVAROG_KEY_I:
            key = 'I';
            break;
        case SVAROG_KEY_J:
            key = 'J';
            break;
        case SVAROG_KEY_K: 
            key = 'K';
            break;
        case SVAROG_KEY_L:
            key = 'L';
            break;
        case SVAROG_KEY_M:
            key = 'M';
            break;
        case SVAROG_KEY_N:
            key = 'N';
            break;
        case SVAROG_KEY_O:
            key = 'O';
            break;
        case SVAROG_KEY_P: 
            key = 'P';
            break;
        case SVAROG_KEY_Q:
            key = 'Q';
            break;
        case SVAROG_KEY_R:
            key = 'R';
            break;
        case SVAROG_KEY_S:
            key = 'S';
            break;
        case SVAROG_KEY_T:
            key = 'T';
            break;
        case SVAROG_KEY_U:
            key = 'U';
            break;
        case SVAROG_KEY_V:
            key = 'V';
            break;
        case SVAROG_KEY_W:
            key = 'W';
            break;
        case SVAROG_KEY_X:
            key = 'X';
            break;
        case SVAROG_KEY_Y:
            key = 'Y';
            break;
        case SVAROG_KEY_Z:
            key = 'Z';
            break;
        default:
            key = NULL;
            break;
    }
    return key;
}