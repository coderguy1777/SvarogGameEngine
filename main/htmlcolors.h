#pragma once
#ifdef HTMLCOLORS_H
#define HTMLCOLORS_H
#endif
#include "EngineHeader.h"
#include "core/ArrayList.hpp"
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
		Rgb hexcodetorgb(vector<int>vals);

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
		ArrayList<int>findDecVals(String code) {
			code.del('#');
			int sum1 = 0;
			int sum2 = 0;
			double base16 = 16.0;
			ArrayList<int>convertedvals;
			for(int i = 0; i <= code.length(); i++) {
				convertedvals.add(gethexval(code.str[i]));
			}

			for(unsigned int j = 0; j <= convertedvals.size(); j++) {

			}
		}
};

struct codegroup {
	HexColorCodes a[3];
} hexcode1, hexcode2, hexcode3;