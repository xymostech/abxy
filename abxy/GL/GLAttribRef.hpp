#ifndef GLATTRIBREF_HPP
#define GLATTRIBREF_HPP

#include <abxy/GL/GL.hpp>
#include <abxy/GL/GLCopyRef.hpp>

class GLAttribRef : public GLCopyRef<GLint> {
public:
	GLAttribRef();
	GLAttribRef(GLint attrib);
	GLAttribRef(GLAttribRef &copy);
	GLAttribRef(GLAttribRef &&move);

	GLAttribRef &operator=(const GLAttribRef &copy);
	GLAttribRef &operator=(GLAttribRef &&move);

	void Enable() const;
	void Disable() const;

	void SetPointer(GLint size, GLenum type, GLboolean normalized,
	                GLsizei stride, const GLvoid *pointer);
	void SetIPointer(GLint size, GLenum type, GLsizei stride,
	                 const GLvoid *pointer);
};

#endif /* GLATTRIBREF_HPP */

