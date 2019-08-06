#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<iostream>
#include<stdexcept>
#include<ostream>
#include<fstream>
#include<sstream>
#include<string>
#include<memory>
#include<ncurses.h>
#include<GL/gl.h>
#include "core/keycodes.h"
#include "core/keyboard.h"
#include "math/vec2.h"
#include "math/vec3.h"
#include "core/String.h"
#include "core/events/InputEvent.h"
#include "core/events/Message.h"
#include "math/camera_matrix.h" 
#include "main/exception.h"
#include "main/color/Color.h"
#include "main/camera/camera.h"
#include "math/matrix.h"
#include "main/materials/material.h"
#include "math/vec4.h"
#include "math/matrix2f.h"
#include "math/matrix3f.h"
#include "debugger/logger.h"
#include "core/events/Queue.h"
#include "math/matrix4f.h"
#include "core/Point.h"
using namespace std;
