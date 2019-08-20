#pragma once
#ifndef WINDOWMOUSEINPUT_H
#define WINDOWMOUSEINPUT_H
#include "macrodefs.h"
#include "mouse.h"
#include "mousecodes.h"

class WindowMouseInput : public Mouse {
    protected:
        virtual std::pair<double, double>getmouseCoords() override;
        virtual bool isPressed(int mouse) override;
        virtual bool isReleased(int mouse) override;
        virtual bool isHeld(int mouse) override;
};
#endif