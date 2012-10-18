#ifndef GLSAMPLERREF_HPP
#define GLSAMPLERREF_HPP

#include <gamelib/GL/GL.hpp>

class GLSamplerRef {
	GLuint sampler;
public:
	GLSamplerRef() {
		glGenSamplers(1, &sampler);
	}

	~GLSamplerRef() {
		glDeleteSamplers(1, &sampler);
	}

	void SetParameteri(GLenum pname, GLint param) {
		glSamplerParameteri(sampler, pname, param);
	}

	void SetParameterf(GLenum pname, GLfloat param) {
		glSamplerParameterf(sampler, pname, param);
	}

	void Bind(GLuint unit) const {
		glBindSampler(unit, sampler);
	}
};

#endif /* GLSAMPLERREF_HPP */

