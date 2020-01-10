#version 400
out vec4 frag_color;
uniform float specular_value;
uniform float roughness_value;

uniform vec4 rgb_v;

void main() {
    frag_color = vec4(1.0, 0.5, 0.5, 1.0) + rgb_v;
}