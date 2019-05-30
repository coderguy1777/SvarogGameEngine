#include "htmlcolors.h"

void HexColorCodes::changecode(String newstr) {
    code = newstr;
    code.str = newstr.str;
}

HexColorCodes HexColorCodes::getPredefinedcode(int code) {
    HexColorCodes wantedcolor(" ");
    switch(code) {
        case WHITECODE:
            wantedcolor.changecode("#FFFFFF");
        case BLACKCODE:
            wantedcolor.changecode("#000000");
        case GREENCODE:
            wantedcolor.changecode("#00FF00");
        case GRAYCODE:
            wantedcolor.changecode("#C0C0C0");
        case REDCODE:
            wantedcolor.changecode("#FF0000");
        case BLUECODE:
            wantedcolor.changecode("#0000FF");
        case YELLOWCODE:
            wantedcolor.changecode("#FFFF00");
        case ORANGECODE:
            wantedcolor.changecode("#FF4500");
        default:
            wantedcolor.changecode("#000000");
    }
    return wantedcolor;
}

Rgb HexColorCodes::hexcodetorgb() {
    Rgb converted(0.0f, 0.0f, 0.0f);
    int convertedbaser1, convertedbaser2, convertedbaser3 = 0;
    code.del('#');
    char* codearr = code.toCharArray(code);
    vector<int>decvals;    
    for(int i = 0; i < code.length(); i++) {
        decvals.push_back(gethexval(codearr[i]));
    }
}

int HexColorCodes::gethexval(char letter) {
    int value = 0;
    switch(letter) {
        case '0':
            value = 0;
        case '1':
            value = 1;
        case '2':
            value = 2;
        case '3':
            value = 3;
        case '4':
            value = 4;
        case '5':
            value = 5;
        case '6':
            value = 6;
        case '7':
            value = 7;
        case '8':
            value = 8;
        case '9':
            value = 9;
        case 'A':
            value = 10;
        case 'B':
            value = 11;
        case 'C':
            value = 12;
        case 'D':
            value = 13;
        case 'E':
            value = 14;
        case 'F':
            value = 15;
    }
    return value;
}