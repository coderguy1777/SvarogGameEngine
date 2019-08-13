#ifndef MOUSE_H
#define MOUSE_H
#include "libs.h"
using namespace std;

class Mouse {
    public:
        float x, y;
        static bool isPressed();
        static bool isReleased();
        float getMouseX() const;
        float getMouseY() const;
        void setMouseX(float newX);
        void setMouseY(float newY);
        template<class A, class B>
        Pair<float, float>getmouseCoords();

    private:
        static Mouse* input_ps;
};
#endif