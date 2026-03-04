#include "mesh.h"

int mesh_init(Mesh* mesh, GLfloat* coords, GLfloat* colors, int size) {
	mesh->size = size;

	// Create VAO
	glGenVertexArrays(1, &mesh->vao);
	glBindVertexArray(mesh->vao);

	mesh->vbos = malloc(sizeof(GLuint) * MESH_COUNT);
	glGenBuffers(MESH_COUNT, mesh->vbos);

	// Position buffer
	glBindBuffer(GL_ARRAY_BUFFER, mesh->vbos[MESH_COORD]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 2 * size, &coords[0], GL_STATIC_DRAW);
	glVertexAttribPointer(MESH_COORD, 2, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(MESH_COORD);

	// Color buffer
	glBindBuffer(GL_ARRAY_BUFFER, mesh->vbos[MESH_COLOR]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 3 * size, &colors[0], GL_STATIC_DRAW);
	glVertexAttribPointer(MESH_COLOR, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(MESH_COLOR);

	glBindVertexArray(0);

	return 0;
}

void mesh_destroy(Mesh* mesh) {
	glDeleteVertexArrays(MESH_COUNT, mesh->vbos);
	free(mesh->vbos);
	glDeleteVertexArrays(1, &mesh->vao);
}

void mesh_draw(Mesh* mesh) {
	glBindVertexArray(mesh->vao);
	glDrawArrays(GL_TRIANGLES, 0, mesh->size);
	glBindVertexArray(0);
}

