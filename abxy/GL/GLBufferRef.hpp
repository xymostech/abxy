#ifndef GLBUFFERREF_HPP
#define GLBUFFERREF_HPP

#include <abxy/GL/GL.hpp>

template <GLenum type>
class GLBufferRef {
	GLuint buffer;
public:
	GLBufferRef();
	~GLBufferRef();

	void SetData(GLsizeiptr size, const GLvoid *data, GLenum usage);
	void SetSubData(GLintptr offset, GLsizeiptr size, const GLvoid *data);

	void BindRange(GLuint index, GLintptr offset, GLsizeiptr size);

	void Bind() const;
	void Unbind() const;
};

#include <abxy/GL/GLBufferRef.inl>

#endif /* GLBUFFERREF_HPP */

