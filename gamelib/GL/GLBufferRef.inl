#ifndef GLBUFFERREF_INL
#define GLBUFFERREF_INL

#include <gamelib/GL/GLBufferRef.hpp>

template <GLenum type>
GLBufferRef<type>::GLBufferRef() {
	glGenBuffers(1, &buffer);
}

template <GLenum type>
GLBufferRef<type>::~GLBufferRef() {
	glDeleteBuffers(1, &buffer);
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
	glBindBufferRange(type, index, buffer, offset, size);
}

template <GLenum type>
void GLBufferRef<type>::Bind() const {
	glBindBuffer(type, buffer);
}

template <GLenum type>
void GLBufferRef<type>::Unbind() const {
	glBindBuffer(type, 0);
}

#endif /* GLBUFFERREF_INL */

