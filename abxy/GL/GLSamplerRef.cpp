#include <abxy/GL/GLSamplerRef.hpp>

#include <utility>

GLSamplerRef::GLSamplerRef() {
	GLuint sampler;
	glGenSamplers(1, &sampler);
	SetRef(sampler);
}

GLSamplerRef::GLSamplerRef(GLSamplerRef &&move)
: GLCreateRef<GLuint>(std::move(move))
{ }

GLSamplerRef::~GLSamplerRef() {
	if (IsCreated()) {
		glDeleteSamplers(1, &GetRef());
	}
}

GLSamplerRef &GLSamplerRef::operator=(GLSamplerRef &&move) {
	GLCreateRef<GLuint>::operator=(std::move(move));

	return *this;
}

void GLSamplerRef::SetParameteri(GLenum pname, GLint param) {
	glSamplerParameteri(GetRef(), pname, param);
}

void GLSamplerRef::SetParameterf(GLenum pname, GLfloat param) {
	glSamplerParameterf(GetRef(), pname, param);
}

void GLSamplerRef::Bind(GLuint unit) const {
	glBindSampler(unit, GetRef());
}

