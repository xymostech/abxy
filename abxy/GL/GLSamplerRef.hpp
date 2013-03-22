#ifndef GLSAMPLERREF_HPP
#define GLSAMPLERREF_HPP

#include <abxy/GL/GL.hpp>
#include <abxy/GL/GLCreateRef.hpp>

class GLSamplerRef : public GLCreateRef<GLuint> {
public:
	GLSamplerRef();
	GLSamplerRef(GLSamplerRef &&move);
	~GLSamplerRef();

	GLSamplerRef &operator=(GLSamplerRef &&move);

	void SetParameteri(GLenum pname, GLint param);
	void SetParameterf(GLenum pname, GLfloat param);

	void Bind(GLuint unit) const;
};

#endif /* GLSAMPLERREF_HPP */

