#ifndef GLVERTEXARRAYREF_INL
#define GLVERTEXARRAYREF_INL

#include <gamelib/GL/GLVertexArrayRef.hpp>

GLVertexArrayRef::GLVertexArrayRef() {
	glGenVertexArrays(1, &vertex_array);
}

GLVertexArrayRef::~GLVertexArrayRef() {
	glDeleteVertexArrays(1, &vertex_array);
}

void GLVertexArrayRef::Bind() const {
	glBindVertexArray(vertex_array);
}

void GLVertexArrayRef::Unbind() const {
	glBindVertexArray(0);
}

#endif /* GLVERTEXARRAYREF_INL */

