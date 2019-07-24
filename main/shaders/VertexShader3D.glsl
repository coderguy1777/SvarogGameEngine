#version 400
layout (location = 0) in vec3 aPos;

// view matricies
uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

void main() {
    // transform applied
    gl_Position = projection * view * model * vec4(aPos, 1.0f);
};