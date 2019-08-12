#version 400
layout (location = 0) in vec3 aPos;
void main() {
    // transform applied
    gl_Position =  gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
};