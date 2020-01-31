#version 330 core
layout (location = 0) in vec3 aPos;
uniform float x_fac;
uniform float y_fac;
uniform float z_fac;
void main() {
    gl_Position=vec4(x_fac, y_fac, z_fac, 1.0f) * vec4(aPos, 1.0f);
}