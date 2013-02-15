#include <abxy/GL/GLAttribRef.hpp>

GLAttribRef::GLAttribRef()
: attrib(0)
{
	
}

GLAttribRef::GLAttribRef(GLint attrib)
: attrib(attrib)
{
	
}

void GLAttribRef::Enable() const {
	glEnableVertexAttribArray(attrib);
}

void GLAttribRef::SetPointer(GLint size, GLenum type, GLboolean normalized,
		GLsizei stride, const GLvoid *pointer) {
	glVertexAttribPointer(attrib, size, type, normalized, stride,
			      pointer);
}

void GLAttribRef::SetIPointer(GLint size, GLenum type, GLsizei stride,
		 const GLvoid *pointer) {
	glVertexAttribIPointer(attrib, size, type, stride, pointer);
}

