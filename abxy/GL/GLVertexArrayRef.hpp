#ifndef GLVERTEXARRAYREF_HPP
#define GLVERTEXARRAYREF_HPP

#include <abxy/GL/GL.hpp>

class GLVertexArrayRef {
	GLuint vertex_array;
public:
	GLVertexArrayRef();
	~GLVertexArrayRef();

	void Bind() const;
	void Unbind() const;
};

#endif /* GLVERTEXARRAYREF_HPP */

