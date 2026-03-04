#include "display.h"
#include "shader.h"

GLuint idVAO;		// tablic wierzcholkow
GLuint idVBO_coord; // bufora na wspolrzedne
GLuint idVBO_color; // bufora na kolor

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
	int quit = 0;


	// -------------------------------------------------
	// Etap (2) przeslanie danych wierzcholków do OpenGL
	// -------------------------------------------------
	glGenVertexArrays( 1, &idVAO );
	glBindVertexArray( idVAO );

	// Bufor na wspolrzedne wierzcholkow
	glGenBuffers( 1, &idVBO_coord );
	glBindBuffer( GL_ARRAY_BUFFER, idVBO_coord );
	glBufferData( GL_ARRAY_BUFFER, sizeof( triangles ), triangles, GL_STATIC_DRAW );

	glVertexAttribPointer( 0, 2, GL_FLOAT, GL_FALSE, 0, NULL );
	glEnableVertexAttribArray( 0 );

	// Bufor na kolor
	glGenBuffers( 1, &idVBO_color );
	glBindBuffer( GL_ARRAY_BUFFER, idVBO_color );
	glBufferData( GL_ARRAY_BUFFER, sizeof( colors ), colors, GL_STATIC_DRAW );

	glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, 0, NULL );
	glEnableVertexAttribArray( 1 );

	glBindVertexArray( 0 );

glViewport( 0, 0, display.width, display.height );
	while (!quit) {
		SDL_Event event;
		while (SDL_PollEvent(&event) != 0) {
			if (event.type == SDL_QUIT) {
				quit = 1;
			}
		}
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	// Wlaczenie potoku
	glUseProgram(program_id);


		// Generowanie obiektow na ekranie
		glBindVertexArray( idVAO );
		glDrawArrays( GL_TRIANGLES, 0, 1*3 );
		glBindVertexArray( 0 );


	// Wylaczanie
	glUseProgram( 0 );

		SDL_GL_SwapWindow(display.window);
	}

	program_destroy(program_id);
	glDeleteVertexArrays( 1, &idVBO_coord );
	glDeleteVertexArrays( 1, &idVAO );
	display_destroy(&display);

	return 0;
}
