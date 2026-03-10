#version 330 core

in vec4 inPosition;
in vec3 inColor;

out vec3 color;

uniform mat4 model;

void main() {
	gl_Position = model * inPosition;
	color = inColor;
}

