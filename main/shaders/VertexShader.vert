#version 400
layout (location = 0) in vec3 aPos;
uniform mat4 projection;
uniform mat4 model;
uniform mat4 view;

void main() {
    // transform applied
    gl_Position = projection * view * model * vec4(aPos, 1.0f);
};