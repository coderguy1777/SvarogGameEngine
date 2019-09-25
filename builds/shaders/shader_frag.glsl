#version 400

layout (location = 0) in vec3 aPos;

out frag_color;

uniform vec4 float_tst;

uniform float time;

void main()

{

   frag_color=vec4(sin(abs(time)), float_tst.y, float_tst.z, 1.0);

}

