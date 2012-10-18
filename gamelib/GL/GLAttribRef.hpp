#ifndef GLATTRIBREF_HPP
#define GLATTRIBREF_HPP

#include <gamelib/GL/GL.hpp>

class GLAttribRef {
	GLint attrib;
public:
	GLAttribRef()
	: attrib(0)
	{
		
	}

	GLAttribRef(GLint attrib)
	: attrib(attrib)
	{
		
	}

	void Enable() const {
		glEnableVertexAttribArray(attrib);
	}

	void SetPointer(GLint size, GLenum type, GLboolean normalized,
	                GLsizei stride, const GLvoid *pointer) {
		glVertexAttribPointer(attrib, size, type, normalized, stride,
		                      pointer);
	}

	void SetIPointer(GLint size, GLenum type, GLsizei stride,
	                 const GLvoid *pointer) {
		glVertexAttribIPointer(attrib, size, type, stride, pointer);
	}
};

#endif /* GLATTRIBREF_HPP */

