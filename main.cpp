#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<iostream>
#include "main.h"
#include "math/vec3.h"
#include "main/Color.h"
#include "main/HSV.h"
#include "main/cmyk.h"
#include "main/hsl.h"
#include "main/htmlcolors.h"
#include "math/math.h"
#include "core/ArrayList.h"
using namespace std;

int main() {
	String title("Svarog Game Engine");
	enginecore::initializeWindow(800, 600, title.str);
	return 0;
}