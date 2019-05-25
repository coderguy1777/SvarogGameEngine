#pragma once
#ifdef HTMLCOLORS_H
#define HTMLCOLORS_H
#endif
#include "EngineHeader.h"
#include "Color.h"
#include "core/String.h"

class HexColorCodes {
	public:
		float r,  g,  b;
		HexColorCodes(float redval, float greenval, float blueval) {
			this->r = redval;
			this->g = greenval;
			this->b = blueval;
		}
		
		const char HEXSTART = '#';
		char hexcodes[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
								'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

		const int MAXLENOFCODE = 6;
		std::string hexcode;
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
		void getPredefinedcode(int code);
		void RGBtoHEX(float redval, float greenval, float blueval);
		String newHexCode(float r, float g, float b);
};