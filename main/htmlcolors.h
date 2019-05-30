#pragma once
#ifdef HTMLCOLORS_H
#define HTMLCOLORS_H
#endif
#include "EngineHeader.h"
#include "Color.h"
#include "core/String.h"
using namespace std;

class HexColorCodes {
	private:
		String code;
	public:
		HexColorCodes(String str) {
			code = str;
		}

		void changecode(String newstr);
		String getcode();
		Rgb hexcodetorgb();

		enum predefcodes {
			WHITECODE,
			BLACKCODE,
			GREENCODE,
			GRAYCODE,
			REDCODE,
			BLUECODE,
			YELLOWCODE,
			ORANGECODE
		};

		HexColorCodes getPredefinedcode(int code); 
		codegroup* makecodelist(String *codes);
		int gethexval(char letter);
};

struct codegroup {
	HexColorCodes a[3];
} hexcode1, hexcode2, hexcode3;