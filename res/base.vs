#version 330 core

layout(location = 0) in vec3 v_pos;
layout(location = 1) in vec3 v_color;
layout(location = 2) in vec2 v_uv;

out vec3 f_pos;
out vec3 f_color;
out vec2 f_uv;

uniform mat4 m, v, p;

void main()
{
    gl_Position = p * v * vec4(v_pos, 1.0);

    f_pos = v_pos;
    f_color = v_color;
    f_uv = v_uv;
}