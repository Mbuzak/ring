#version 330 core

in vec4 inPosition;
in vec3 inColor;

out vec3 color;

void main() {
	gl_Position = inPosition;
	color = inColor;
}

