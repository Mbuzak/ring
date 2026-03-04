#include "renderer.h"

int renderer_init(Renderer* renderer) {
	GLfloat triangles[3 * 2] = {
		-0.25f, -0.42f,
		 0.25f, -0.42f,
		0.0f,  0.5f,
	};

	GLfloat colors[3 * 3] = {
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 1.0f,
	};

	renderer->program_id = program_init("default");
	mesh_init(&renderer->mesh, triangles, colors, 3);
}

void renderer_destroy(Renderer* renderer) {
	program_destroy(renderer->program_id);
	mesh_destroy(&renderer->mesh);
}

void renderer_render(Renderer* renderer, SDL_Window* window) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUseProgram(renderer->program_id);
	mesh_draw(&renderer->mesh);
	glUseProgram(0);

	SDL_GL_SwapWindow(window);
}
