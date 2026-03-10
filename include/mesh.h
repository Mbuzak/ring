#ifndef RING_MESH
#define RING_MESH

#include <stdlib.h>
#include <GL/glew.h>

enum MeshBuffer {
	MESH_COORD,
	MESH_COLOR,
	MESH_COUNT
};

typedef struct {
	GLuint vao;
	GLuint* vbos;
	int size;
} Mesh;

int mesh_init(Mesh*, GLfloat*, GLfloat*, int size);
void mesh_destroy(Mesh*);

void mesh_draw(Mesh*);

#endif
