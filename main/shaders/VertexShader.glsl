#version 400
layout (location = 0) in vec3 aPos;
uniform mat4 transform;
void main() {
    // transform applied
    gl_Position = transform * vec4(aPos, 1.0f);
};