#pragma once
#ifdef HTMLCOLORS_H
#define HTMLCOLORS_H
#endif
#include "Color.h"
#include "core/String.h"
using namespace std;

class HexColorCodes {
	private:
		String code;
	public:
		HexColorCodes() {

		}
		
		HexColorCodes(String str) {
			code = str;
		}

		void changecode(String newstr);
		String getcode();
		Rgb hexcodetorgb(ArrayList<int>vals);

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
		int gethexval(char letter);

		ArrayList<int>findDecVals(String code) {
			code.del('#');
			int sum1, sum2, finalsum = 0;
			double base16 = 16.0;
			ArrayList<int>convertedvals;
			ArrayList<int>summedvalues;
			for(int i = 0; i <= code.length(); i++) {
				convertedvals.add(gethexval(code.str[i]));
			}

			for(unsigned int j = 1; j <= convertedvals.size() - 1; j++) {
				int temp = convertedvals.get(j - 1);
				sum1 = convertedvals.get(j) * pow(base16, (double)1);
				sum2 = temp * pow(base16, 0);
				finalsum = sum1 + sum2;
				summedvalues.add(finalsum);
			}
			return summedvalues;
		}

};