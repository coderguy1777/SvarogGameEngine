#pragma once
#ifdef ENGINEHEADER_H
#define ENGINEHEADER_H
#endif
#include<GL/freeglut.h>
#include<iostream>
#include<GL/gl.h>
#include<GL/glu.h>
#include "core/Vector.h"
#include "main/Color.h"
#include "main/HSV.h"
#include "main/cmyk.h"
#include "main/hsl.h"
#include "main/htmlcolors.h"
#include "core/math.h"
#include "core/Map.hpp"
#include "core/ArrayList.hpp"

struct COLOR {
	float r, g, b;
};