#version 330
uniform mat4 uWorldTransform;
uniform mat4 uViewProj;
// This should correspond to the data stored
// for each vertex in the vertex buffer.
// For now, just a position.
in vec3 inPosition;

void main()
{
	vec4 pos = vec4(inPosition, 1.0);
	gl_Position = pos * uWorldTransform * uViewProj;
}