#include <abxy/GL/GLAttribRef.hpp>

#include <utility>

GLAttribRef::GLAttribRef()
: GLCopyRef<GLint>()
{ }

GLAttribRef::GLAttribRef(GLint attrib)
: GLCopyRef<GLint>(attrib)
{ }

GLAttribRef::GLAttribRef(GLAttribRef &copy)
: GLCopyRef<GLint>(copy)
{ }

GLAttribRef::GLAttribRef(GLAttribRef &&move)
: GLCopyRef<GLint>(std::move(move))
{ }

GLAttribRef &GLAttribRef::operator=(const GLAttribRef &copy) {
	GLCopyRef<GLint>::operator=(copy);

	return *this;
}

GLAttribRef &GLAttribRef::operator=(GLAttribRef &&move) {
	GLCopyRef<GLint>::operator=(std::move(move));

	return *this;
}

void GLAttribRef::Enable() const {
	glEnableVertexAttribArray(GetRef());
}

void GLAttribRef::Disable() const {
	glDisableVertexAttribArray(GetRef());
}

void GLAttribRef::SetPointer(GLint size, GLenum type, GLboolean normalized,
                             GLsizei stride, const GLvoid *pointer) {
	glVertexAttribPointer(
		GetRef(), size, type, normalized, stride, pointer
	);
}

void GLAttribRef::SetIPointer(GLint size, GLenum type, GLsizei stride,
                              const GLvoid *pointer) {
	glVertexAttribIPointer(GetRef(), size, type, stride, pointer);
}

