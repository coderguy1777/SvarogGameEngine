#pragma once
#ifdef FONTCLASS_H
#define FONTCLASS_H
#endif
#include "GameEngineHeader.h"

using namespace std;

class Font {

    protected:
        int fontwidth = 0;
        int fontheight = 0;

    public:
        double fontweight = 0;
        virtual void setFontSize(double fontweightvar) {
            cout << "Hello" << endl;
        }

        virtual void setFontWeight(int fontmax) {
            cout << "Hello" << endl;
        }

        virtual void drawFont() = 0;
        Font(int a = 0, int b = 0) {
            this->fontwidth = a;
            this->fontheight = b;

        }

};

class TimesNewRoman: public Font {
    public:
        TimesNewRoman(int a, int b):Font(a, b) { }
        void setFontWeight(double fontweightvar) {
            fontweightvar = fontweight;
        }

        void setFontSize(int fontmax) {
            fontheight = fontmax;
            fontwidth = fontmax / 2;
        }

        void drawFont() {
            glBegin(GL_POLYGON);
            {
                glVertex2d(0.5, 0.0);
                glVertex2d(-0.5, 0.0);
                glVertex2d(-0.5, -0.5);
                glVertex2d(0.5, -0.5);
            }
            glEnd();
            glTranslatef(0.0f, 0.0f, 0.0f);
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'c');
        }

};