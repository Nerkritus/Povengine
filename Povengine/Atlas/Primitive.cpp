#include "Primitive.h"
#include "glew.h"

using namespace Atlas;

///
Primitive::Primitive(float size, float x, float y, float z)
{
	// An array of 3 vectors which represents 3 vertices
	const float data[] = {
		x - size, z - size, z,
		x + size, z - size, z,
		x,  size, z,
	};

	glGenVertexArrays(1, &_vbaID);
	glBindVertexArray(_vbaID);

	glGenBuffers(1, &_vbID);
	glBindBuffer(GL_ARRAY_BUFFER, _vbID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);
}

void Primitive::Render()
{
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, _vbID);
	glVertexAttribPointer(
		0,
		3,
		GL_FLOAT,
		GL_FALSE,
		0,
		(void*)0
	);

	glDrawArrays(GL_TRIANGLES, 0, 3);

	glDisableVertexAttribArray(0);
}