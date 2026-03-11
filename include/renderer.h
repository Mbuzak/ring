#ifndef RING_RENDERER
#define RING_RENDERER

#include <math.h>
#include <SDL2/SDL.h>
#include "shader.h"
#include "mesh.h"

/*
 * Colorful triangle renderer
 * must exists shaders/default.{vs,fs} shaders
*/
typedef struct {
	GLuint program_id;
	Mesh mesh;
	float alpha;
	float x, y, z;
} Renderer;

int renderer_init(Renderer*, Mesh*);
void renderer_destroy(Renderer*);
void renderer_render(Renderer*, SDL_Window*);

#endif
