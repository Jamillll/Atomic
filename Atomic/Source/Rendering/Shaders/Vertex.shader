#version 330 core

layout(location = 0) in vec2 location;
layout(location = 1) in vec3 vertexColour;

out vec3 fragColour;

void main()
{
	gl_Position = vec4(location, 1.0f, 1.0f);
	fragColour = vertexColour;
}