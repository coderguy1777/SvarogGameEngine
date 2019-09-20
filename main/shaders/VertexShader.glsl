#version 400
layout (location = 0) in vec3 aPos;
uniform float xPOs;
void main() {
    // transform applied
    gl_Position = aPos;
};