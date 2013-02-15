#include <abxy/GL/GLSamplerRef.hpp>

GLSamplerRef::GLSamplerRef() {
	glGenSamplers(1, &sampler);
}

GLSamplerRef::~GLSamplerRef() {
	glDeleteSamplers(1, &sampler);
}

void GLSamplerRef::SetParameteri(GLenum pname, GLint param) {
	glSamplerParameteri(sampler, pname, param);
}

void GLSamplerRef::SetParameterf(GLenum pname, GLfloat param) {
	glSamplerParameterf(sampler, pname, param);
}

void GLSamplerRef::Bind(GLuint unit) const {
	glBindSampler(unit, sampler);
}

