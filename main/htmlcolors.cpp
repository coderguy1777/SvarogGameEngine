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
    
    }
    return wantedcolor;
}

Rgb HexColorCodes::hexcodetorgb(vector<int>vals) {
    Rgb converted(0.0f, 0.0f, 0.0f);
    int convertedbaser1, convertedbaser2, convertedbaser3 = 0;
    code.del('#');
    int sum = 0; 
	int sumprev = 0;
	vector<int>sumvals;
	for(unsigned int i = 1; i <= vals.size() - 1; i++) {
		int temp = vals[i - 1];
		sumprev = temp * pow((double)16.0, 0);
		sum  = vals[i] * pow((double)16.0, 1);
		cout << sum << " : " << sumprev << endl;
	}
}

int HexColorCodes::gethexval(char letter) {
    int value = 0;
	if(letter == '0') {
		value = 0;
	}

	if(letter == '1') {
		value = 1;
	}

	if(letter == '2') {
		value = 2;
	}

	if(letter == '3') {
		value = 3;
	} 

	if(letter == '4') {
		value = 4;
	}
	
	if(letter == '5') {
		value = 5;
	}

	if(letter == '6') {
		value = 6;
	}

	if(letter == '7') {
		value = 7;
	}

	if(letter == '8') {
		value = 8;
	}

	if(letter == '9') {
		value = 9;
	}

	if(letter == 'A') {
		value = 10;
	}

	if(letter == 'B') {
		value = 11;
	}

	if(letter == 'C') {
		value = 12;
	} 

	if(letter == 'D') {
		value = 13;
	}

	if(letter == 'E') {
		value = 14;
	}

	if(letter == 'F') {
		value = 15;
	}
	return value;
}
