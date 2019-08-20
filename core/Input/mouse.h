#ifndef MOUSE_H
#define MOUSE_H
#include "libs.h"
using namespace std;

class Mouse {
    public:
        double x, y;
        bool isMousePressed(int mouse) {
            return input_ps->isPressed(mouse);
        }

        bool isMouseReleased(int mouse) {
            return input_ps->isReleased(mouse);
        }

        bool isMouseHeld(int mouse) {
            return input_ps->isHeld(mouse);
        }

        std::pair<double, double>MouseCoordinates() {
            return input_ps->getmouseCoords();
        }

        double getMouseX() const {
            return input_ps->x;
        }

        double getMouseY() const {
            return input_ps->y;
        }

        void setMouseX(float newX) {
            x = newX;
        }

        void setMouseY(float newY) {
            y = newY;
        }
    protected:
        virtual bool isReleased(int mouse) = 0;
        virtual bool isPressed(int mouse) = 0;
        virtual bool isHeld(int mouse) = 0;
        virtual std::pair<double, double>getmouseCoords() = 0;
    private:
        static Mouse* input_ps;
};
#endif