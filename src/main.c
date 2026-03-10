#include "display.h"
#include "renderer.h"
#include "mesh.h"

int main() {
	int quit = 0;
	Display display = display_init(1280, 720, "01-core");
	Renderer renderer;
	Mesh mesh;

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

	mesh_init(&mesh, triangles, colors, 3);
	renderer_init(&renderer, &mesh);

	while (!quit) {
		SDL_Event event;
		while (SDL_PollEvent(&event) != 0) {
			if (event.type == SDL_QUIT) {
				quit = 1;
			}
		}

		renderer_render(&renderer, display.window);
	}

	renderer_destroy(&renderer);
	display_destroy(&display);

	return 0;
}
