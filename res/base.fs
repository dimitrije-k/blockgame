#version 330 core

out vec4 final_color;

in vec3 f_pos;
in vec3 f_color;
in vec2 f_uv;

uniform sampler2D texture0;

#define FOG_COLOR vec4(0.6, 0.8, 1.0, 1.0)

void main()
{
    final_color = vec4(f_color, 1.0) * texture(texture0, f_uv);
}