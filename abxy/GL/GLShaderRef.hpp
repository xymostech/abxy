#ifndef GLSHADERREF_HPP
#define GLSHADERREF_HPP

#include <string>

#include <abxy/GL/GL.hpp>

class GLShaderRef {
	GLuint shader;
	GLenum type;
public:
	GLShaderRef(GLenum type);

	virtual ~GLShaderRef();

	GLenum GetType();

	void AttachTo(GLuint program);

	void DetachFrom(GLuint program);

	void SetSource(std::string source);

	void Compile();

	GLint GetParam(GLenum pname) const;

	std::string GetInfoLog() const;
};

#endif /* GLSHADERREF_HPP */

