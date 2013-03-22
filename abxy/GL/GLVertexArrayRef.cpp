#include <abxy/GL/GLVertexArrayRef.hpp>

#include <utility>

GLVertexArrayRef::GLVertexArrayRef() {
	GLuint vertex_array;
	glGenVertexArrays(1, &vertex_array);
	SetRef(vertex_array);
}
GLVertexArrayRef::GLVertexArrayRef(GLVertexArrayRef &&move)
: GLCreateRef<GLuint>(std::move(move))
{ }

GLVertexArrayRef::~GLVertexArrayRef() {
	if (IsCreated()) {
		glDeleteVertexArrays(1, &GetRef());
	}
}

GLVertexArrayRef &GLVertexArrayRef::operator=(GLVertexArrayRef &&move) {
	GLCreateRef<GLuint>::operator=(std::move(move));

	return *this;
}

void GLVertexArrayRef::Bind() const {
	glBindVertexArray(GetRef());
}

void GLVertexArrayRef::Unbind() const {
	glBindVertexArray(0);
}

