#include "display.h"
#include "shader.h"
#include "mesh.h"

// ---------------------------------------
// Wspolrzedne wierzchokow
GLfloat triangles[1*3*2] = {
	-0.25f, -0.42f,
	 0.25f, -0.42f,
	0.0f,  0.5f,
};

GLfloat colors[1*3*3] = {
	1.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 1.0f,
};

int main() {
	Display display = display_init(1280, 720, "01-core");
	GLuint program_id = program_init("default");
	Mesh mesh;
	int quit = 0;

	mesh_init(&mesh, triangles, colors, 3);

glViewport( 0, 0, display.width, display.height );
	while (!quit) {
		SDL_Event event;
		while (SDL_PollEvent(&event) != 0) {
			if (event.type == SDL_QUIT) {
				quit = 1;
			}
		}
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glUseProgram(program_id);
		mesh_draw(&mesh);
		glUseProgram(0);

		SDL_GL_SwapWindow(display.window);
	}

	program_destroy(program_id);
	mesh_destroy(&mesh);
	display_destroy(&display);

	return 0;
}
