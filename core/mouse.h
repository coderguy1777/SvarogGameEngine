#ifdef MOUSE_H
#define MOUSE_H
#endif
#include "libs.h"
using namespace std;

class Mouse {
    public:
        inline bool isPressed();
        inline bool isReleased();
        inline float getMouseX() const {
            return x;
        }

        inline float getMouseY() const {
            return y;
        }

        inline float setMouseX(float newX) {
            x = newX;
        }

        inline float setMouseY(float newY) {
            y = newY;
        }
        inline Pair<float, float>getmouseCoords() {
            return Pair(getMouseX(), getMouseY());
        }
    protected:
        virtual bool isMousePressed() = 0;
        virtual int process_pressed() = 0; // processes which side of the mouse is press
        virtual bool isMouseReleased() = 0;
    private:
        float x, y;
        static Mouse* input_ps;
};
