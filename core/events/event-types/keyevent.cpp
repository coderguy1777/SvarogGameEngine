#include "macrodefs.h"
#include "keyevent.h"

void KeyEvent::logKeyPressEvent() {
    spdlog::info("Key Pressed: {}", get_keybind_char());
    spdlog::info("Key State: {}", get_state());
    spdlog::info("Key ASCII CODE: {}", get_keybind_ascii_code());
}


void KeyEvent::logKeyReleaseEvent() {
    spdlog::info("Key Released: {}", get_keybind_char());
    spdlog::info("Key State: {}", get_state());
    spdlog::info("Key ASCII CODE: {}", get_keybind_ascii_code());
}

void KeyEvent::logKeyHeldEvent() {
    spdlog::info("Key Held: {}", get_keybind_char());
    spdlog::info("Key State: {}", get_state());
    spdlog::info("Key ASCII CODE: {}", get_keybind_ascii_code());
}

void KeyEvent::logKeyRepeatEvent() {
    spdlog::info("Key Repeated: {}", get_keybind_char());
    spdlog::info("Key State: {}", get_state());
    spdlog::info("Key ASCII CODE: {}", get_keybind_ascii_code());
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

std::string KeyEvent::get_keycode_char(unsigned int code) {
    std::string key;
    switch(code) {
        case SVAROG_KEY_SPACE:
            key = "KEY_SPACE";
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
        case SVAROG_KEY_LFT_BRCKT:
            key = '[';
            break;
        case SVAROG_KEY_RV_SOLIDIOUS:
            key = "RV_SLSH";
            break;
        case SVAROG_KEY_RGT_BRCKT:
            key = ']';
            break;
        case SVAROG_KEY_CRCM_FLX:
            key = '^';
            break;
        case SVAROG_KEY_LOW_LINE:
            key = '_';
            break;
        case SVAROG_KEY_GRAVE_ACT:
            key = '`';
            break;
        case SVAROG_KEY_LEFT_CRL_BRACKET:
            key = '{';
            break;
        case SVAROG_KEY_VRT_LINE:
            key = '|';
            break;
        case SVAORG_KEY_RIGHT_CRL_BRACKET:
            key = '}';
            break;
        case SVAROG_KEY_SQUIGGLY:
            key = '~';
            break;
        case SVAROG_KEY_NUM_PAD_0:
            key = "NUM_PAD_0";
            break;
        case SVAROG_KEY_NUM_PAD_1:
            key = "NUM_PAD_1";
            break;
        case SVAROG_KEY_NUM_PAD_2:
            key = "NUM_PAD_2";
            break;
        case SVAROG_KEY_NUM_PAD_3:
            key = "NUM_PAD_3";
            break;
        case SVAROG_KEY_NUM_PAD_4:
            key = "NUM_PAD_4";
            break;
        case SVAROG_KEY_NUM_PAD_5:
            key = "NUM_PAD_5";
            break;
        case SVAROG_KEY_NUM_PAD_6:
            key = "NUM_PAD_6";
            break;
        case SVAROG_KEY_NUM_PAD_7:
            key = "NUM_PAD_7";
            break;
        case SVAROG_KEY_NUM_PAD_8:
            key = "NUM_PAD_8";
            break;
        case SVAROG_KEY_NUM_PAD_9:
            key = "NUM_PAD_9";
            break;
        case SVAROG_KEY_FN_1:
            key = "FN_1";
            break;
        case SVAROG_KEY_FN_2: 
            key = "FN_2";
            break;
        case SVAROG_KEY_FN_3:
            key = "FN_3";
            break;
        case SVAROG_KEY_FN_4:
            key = "FN_4";
            break;
        case SVAROG_KEY_FN_5:
            key = "FN_5";
            break;
        case SVAROG_KEY_FN_6:
            key = "FN_6";
            break;
        case SVAROG_KEY_FN_7:
            key = "FN_7";
            break;
        case SVAROG_KEY_FN_8:
            key = "FN_8";
            break;
        case SVAROG_KEY_FN_9:
            key = "FN_9";
            break;
        case SVAROG_KEY_FN_10:
            key = "FN_10";
            break;
        case SVAROG_KEY_FN_11:
            key = "FN_11";
            break;
        case SVAROG_KEY_FN_12:
            key = "FN_12";
            break;
        case SVAROG_KEY_ENTER:
            key = "KEY_ENTER";
            break;
        case SVAROG_KEY_LFT_TAB:
            key = "LFT_TAB";
            break;
        case SVAROG_KEY_BACK_SPACE:
            key = "BCK_SPCE";
            break;
        case SVAROG_KEY_ARROW_RGT:
            key = "->";
            break;
        case SVAROG_KEY_ARROW_LFT:
            key = "<-";
            break;
        case SVAROG_KEY_ARROW_DOWN:
            key = "_^";
            break;
        case SVAROG_KEY_ARROW_UP:
            key = "^_";
            break;
        case SVAROG_KEY_CAPS_LOCK:
            key = "CPS_LCK";
            break;
        case SVAROG_KEY_LFT_SHIFT:
            key = "L_SHFT";
            break;
        case SVAROG_KEY_LFT_CTRL:
            key = "L_CTRL";
            break;
        case SVAROG_KEY_LFT_ALT:
            key = "L_ALT";
            break;
        case SVAROG_KEY_RGT_SHIFT:
            key = "R_SHFT";
            break;
        case SVAROG_KEY_RGT_CTRL:
            key = "R_CTRL";
            break;
        case SVAROG_KEY_RGT_ALT:
            key = "R_ALT";
            break;
        case SVAROG_KEY_ESC:
            key = "ESC";
            break;
        default:
            key = "ERROR_STATE";
            break;
    }
    return key;
}