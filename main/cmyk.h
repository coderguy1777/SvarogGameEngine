#pragma once
#ifdef CMYK_H
#define CMYK_H
#endif
using namespace std;
#include "color.h"

class CMYKVALS {
	public:
		float c, m, y, k;
		CMYKVALS(float cyan, float magenta, float yellow, float black) {
			this->c = cyan;
			this->m = magenta;
			this->y = yellow;
			this->k = black;
		}

		void setCyan(float c);
		void setBlack(float b);
		void setYellow(float y);
		void setMagenta(float m);

		// gets cmyk vals
		float getCyan();
		float getMagenta();
		float getYellow();
		float getKblack();

		// prime vals
		float findRPrime(float red);
		float findGPrime(float green);
		float findBPrime(float blue);

		// CMYK vals
		float findC(float primer, float kval);
		float findM(float primeg, float kval);
		float findY(float primeb, float kval);
		float findK(float primer, float primeg, float primeb);

		// finding RGB Vals
		float findR(float cval, float kval);
		float findG(float mval, float kval);
		float findB(float yval, float kval);

		// returns cmyk
		CMYKVALS newCMYK();
		void * operator new(size_t size) {
			void * p = ::new CMYKVALS(0, 0, 0, 0);
			return p;
		}


		// float val creation 
		CMYKVALS RGBtoCMYK(float rval, float gval, float bval);
		Rgb CMYKtoRGB(float cval, float mval, float yval, float kval);
};