#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<iostream>
#include<ostream>
#include<fstream>
#include<stdexcept>
#include<sstream>
#include<string>
#include<memory>
#include<GL/gl.h>
#include "core/Input/keycodes.h"
#include "core/Input/keyboard.h"
#include "core/String.h"
#include "core/events/InputEvent.h"
#include "core/events/Message.h"
#include "math/camera_matrix.h" 
#include "main/color/Color.h"
#include "main/camera/camera.h"
#include "main/materials/material.h"
#include "math/vec2.h"
#include "math/vec3.h"
#include "math/vec4.h"
#include "math/matrix.h"
#include "math/matrix2f.h"
#include "math/matrix3f.h"
#include "math/matrix4f.h"
#include "debugger/logger.h"
#include "core/events/Queue.h"
#include "core/Point.h"
#include "main/application/app.h"
#include "macrodefs.h"
#include "main/window/window.h"
#include "core/ds-classes/ArrayList.h"
using namespace std;
