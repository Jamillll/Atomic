#version 330 core

layout(location = 0) in vec2 location;

void main()
{
	gl_Position = vec4(location, 1.0f, 1.0f);
}