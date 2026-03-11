#include "renderer.h"

int renderer_init(Renderer* renderer, Mesh* mesh) {
	renderer->program_id = program_init("default");
	renderer->mesh = *mesh;
	renderer->alpha = 0.0f;
	renderer->x = 0.0f;
	renderer->y = 0.0f;
	renderer->z = 0.0f;
}

void renderer_destroy(Renderer* renderer) {
	program_destroy(renderer->program_id);
	mesh_destroy(&renderer->mesh);
}

void renderer_render(Renderer* renderer, SDL_Window* window) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUseProgram(renderer->program_id);
	
	float a = renderer->alpha;
	/*GLfloat matrix[4 * 4] = {
		cos(a), -sin(a), 0, 0,
		sin(a), cos(a), 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	};*/
	float x = renderer->x;
	float y = renderer->y;
	float z = renderer->z;
	GLfloat matrix[4 * 4] = {
		1, 0, 0, x,
		0, 1, 0, y,
		0, 0, 1, z,
		0, 0, 0, 1
	};
	GLuint loc = glGetUniformLocation(renderer->program_id, "model");
	glUniformMatrix4fv(loc, 1, GL_FALSE, matrix);

	mesh_draw(&renderer->mesh);
	glUseProgram(0);

	SDL_GL_SwapWindow(window);
}
