#ifndef GLBUFFERREF_INL
#define GLBUFFERREF_INL

#include <abxy/GL/GLBufferRef.hpp>

#include <utility>

template <GLenum type>
GLBufferRef<type>::GLBufferRef() {
	GLuint buffer;
	glGenBuffers(1, &buffer);
	SetRef(buffer);
}

template <GLenum type>
GLBufferRef<type>::GLBufferRef(GLBufferRef<type> &&move)
: GLCreateRef<GLuint>(std::move(move))
{ }

template <GLenum type>
GLBufferRef<type>::~GLBufferRef() {
	if (IsCreated()) {
		glDeleteBuffers(1, &GetRef());
	}
}

template <GLenum type>
GLBufferRef<type> &GLBufferRef<type>::operator=(GLBufferRef<type> &&move) {
	GLCreateRef<GLuint>::operator=(std::move(move));

	return *this;
}

template <GLenum type>
void GLBufferRef<type>::SetData(GLsizeiptr size, const GLvoid *data, GLenum usage) {
	glBufferData(type, size, data, usage);
}

template <GLenum type>
void GLBufferRef<type>::SetSubData(GLintptr offset, GLsizeiptr size, const GLvoid *data) {
	glBufferSubData(type, offset, size, data);
}

template <GLenum type>
void GLBufferRef<type>::BindRange(GLuint index, GLintptr offset, GLsizeiptr size) {
	glBindBufferRange(type, index, GetRef(), offset, size);
}

template <GLenum type>
void GLBufferRef<type>::Bind() const {
	glBindBuffer(type, GetRef());
}

template <GLenum type>
void GLBufferRef<type>::Unbind() const {
	glBindBuffer(type, 0);
}

#endif /* GLBUFFERREF_INL */

