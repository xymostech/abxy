#ifndef GLSHADERREF_HPP
#define GLSHADERREF_HPP

#include <string>

#include <abxy/GL/GL.hpp>
#include <abxy/GL/GLCreateRef.hpp>

class GLShaderRef : public GLCreateRef<GLuint> {
	GLenum type;
public:
	GLShaderRef(GLenum type);
	GLShaderRef(GLShaderRef &&move);
	virtual ~GLShaderRef();

	GLShaderRef &operator=(GLShaderRef &&move);

	GLenum GetType();

	void AttachTo(GLuint program);
	void DetachFrom(GLuint program);

	void SetSource(std::string source);
	void Compile();

	GLint GetParam(GLenum pname) const;
	std::string GetInfoLog() const;
};

#endif /* GLSHADERREF_HPP */

