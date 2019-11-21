#version 400
layout (location = 0) in vec3 aPos;

uniform mat4 view;
uniform mat4 proj;
uniform mat4 location;
void main() {
    uniform mat4 model = view *proj * location;
    gl_Position = vec4(aPos, 1.0);
}