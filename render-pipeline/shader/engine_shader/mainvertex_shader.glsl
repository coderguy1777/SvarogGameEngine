#version 400
layout (location = 0) in vec3 aPos;
uniform mat4 vertex_pos;
void main() {
    gl_Position=vec4(aPos, 1.0);
}