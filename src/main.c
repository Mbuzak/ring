#include "display.h"

int main() {
	Display display = display_init(1280, 720, "01-core");
	int quit = 0;

	while (!quit) {
		SDL_Event event;
		while (SDL_PollEvent(&event) != 0) {
			if (event.type == SDL_QUIT) {
				quit = 1;
			}
		}

		SDL_GL_SwapWindow(display.window);
	}

	display_destroy(&display);

	return 0;
}
