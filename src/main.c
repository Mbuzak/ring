#include "display.h"
#include "renderer.h"

int main() {
	int quit = 0;
	Display display = display_init(1280, 720, "01-core");

	Renderer renderer;
	renderer_init(&renderer);

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
