#version 400
layout (location = 0) in vec3 aPos;
uniform float xPOs;
void main() {
    // transform applied
    gl_Position =  gl_Position = vec4(aPos.x + xPOs, aPos.y, aPos.z, 1.0);
};