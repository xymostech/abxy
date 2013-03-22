#ifndef GLVERTEXARRAYREF_HPP
#define GLVERTEXARRAYREF_HPP

#include <abxy/GL/GL.hpp>
#include <abxy/GL/GLCreateRef.hpp>

class GLVertexArrayRef : public GLCreateRef<GLuint> {
public:
	GLVertexArrayRef();
	GLVertexArrayRef(GLVertexArrayRef &&move);
	~GLVertexArrayRef();

	GLVertexArrayRef &operator=(GLVertexArrayRef &&move);

	void Bind() const;
	void Unbind() const;
};

#endif /* GLVERTEXARRAYREF_HPP */

