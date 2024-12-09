#type vertex
#version 330 core

layout(location = 0) in vec3 a_Pos;
layout(location = 1) in vec4 a_Color;

uniform mat4 u_ViewProjection;
uniform mat4 u_Transform;

out vec3 v_Pos;
out vec4 v_Color;

void main()
{
    v_Pos = a_Pos;
    v_Color = a_Color;
    gl_Position = u_ViewProjection * u_Transform * vec4(a_Pos, 1.0);
}

#type fragment
#version 330 core

layout(location = 0) out vec4 color;
in vec3 v_Pos;
in vec4 v_Color;

void main()
{
    color = v_Color;
}