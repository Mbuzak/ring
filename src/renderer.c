#include "renderer.h"

int renderer_init(Renderer* renderer, Mesh* mesh) {
	renderer->program_id = program_init("default");
	renderer->mesh = *mesh;
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
