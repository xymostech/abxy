#ifndef GLVERTEXARRAYREF_HPP
#define GLVERTEXARRAYREF_HPP

#include <gamelib/GL/GL.hpp>

class GLVertexArrayRef {
	GLuint vertex_array;
public:
	GLVertexArrayRef() {
		glGenVertexArrays(1, &vertex_array);
	}

	~GLVertexArrayRef() {
		glDeleteVertexArrays(1, &vertex_array);
	}

	void Bind() const {
		glBindVertexArray(vertex_array);
	}

	void Unbind() const {
		glBindVertexArray(0);
	}
};

#endif /* GLVERTEXARRAYREF_HPP */

