#version 400
out vec4 frag_color;
uniform float specular_value;
uniform float roughness_value;
uniform vec4 color_v;

void main() {
    frag_color = color_v + vec4(specular_value, roughness_value, 0.0f, 0.0f);
}