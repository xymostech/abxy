#ifndef GLBUFFERREF_HPP
#define GLBUFFERREF_HPP

#include <gamelib/GL/GL.hpp>

template <GLenum type>
class GLBufferRef {
	GLuint buffer;
public:
	GLBufferRef() {
		glGenBuffers(1, &buffer);
	}

	~GLBufferRef() {
		glDeleteBuffers(1, &buffer);
	}

	void SetData(GLsizeiptr size, const GLvoid *data, GLenum usage) {
		glBufferData(type, size, data, usage);
	}

	void SetSubData(GLintptr offset, GLsizeiptr size, const GLvoid *data) {
		glBufferSubData(type, offset, size, data);
	}

	void BindRange(GLuint index, GLintptr offset, GLsizeiptr size) {
		glBindBufferRange(type, index, buffer, offset, size);
	}

	void Bind() const {
		glBindBuffer(type, buffer);
	}

	void Unbind() const {
		glBindBuffer(type, 0);
	}

	GLenum GetType() const {
		return type;
	}
};

#endif /* GLBUFFERREF_HPP */

