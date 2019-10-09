#version 400
out vec4 frag_color;
uniform float r;
void main()
{
   frag_color = vec4(r, 0.5, 1.0, 1.0);
}

