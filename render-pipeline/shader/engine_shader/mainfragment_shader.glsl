#version 400
out vec4 frag_color;
uniform float specular_value;
uniform float roughness_value;

struct MESH_COLOR {
    vec4 mesh_color;
    bool is_rgba;
} mesh_color;

void main() {
    frag_color = vec4(1.0, 0.5, 0.5, 1.0);
}