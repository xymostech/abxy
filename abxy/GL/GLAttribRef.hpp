#ifndef GLATTRIBREF_HPP
#define GLATTRIBREF_HPP

#include <abxy/GL/GL.hpp>

class GLAttribRef {
	GLint attrib;
public:
	GLAttribRef();
	GLAttribRef(GLint attrib);

	void Enable() const;

	void SetPointer(GLint size, GLenum type, GLboolean normalized,
	                GLsizei stride, const GLvoid *pointer);
	void SetIPointer(GLint size, GLenum type, GLsizei stride,
	                 const GLvoid *pointer);
};

#endif /* GLATTRIBREF_HPP */

