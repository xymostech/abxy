#ifndef GLSAMPLERREF_HPP
#define GLSAMPLERREF_HPP

#include <abxy/GL/GL.hpp>

class GLSamplerRef {
	GLuint sampler;
public:
	GLSamplerRef();
	~GLSamplerRef();

	void SetParameteri(GLenum pname, GLint param);
	void SetParameterf(GLenum pname, GLfloat param);

	void Bind(GLuint unit) const;
};

#endif /* GLSAMPLERREF_HPP */

