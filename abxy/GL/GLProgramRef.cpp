#include <abxy/GL/GLProgramRef.hpp>

GLProgramRef::GLProgramRef() {
	SetRef(glCreateProgram());
}

GLProgramRef::GLProgramRef(GLProgramRef &&move)
: GLCreateRef<GLuint>(std::move(move))
{ }

GLProgramRef::~GLProgramRef() {
	if (IsCreated()) {
		glDeleteProgram(GetRef());
	}
}

GLProgramRef &GLProgramRef::operator=(GLProgramRef &&move) {
	GLCreateRef<GLuint>::operator=(std::move(move));

	return *this;
}

void GLProgramRef::Attach(GLShaderRef &shader) {
	shader.AttachTo(GetRef());
}

void GLProgramRef::Detach(GLShaderRef &shader) {
	shader.DetachFrom(GetRef());
}

void GLProgramRef::Link() {
	glLinkProgram(GetRef());
}

GLint GLProgramRef::GetParam(GLenum pname) const {
	GLint param;

	glGetProgramiv(GetRef(), pname, &param);

	return param;
}

std::string GLProgramRef::GetInfoLog() const {
	std::string info_log;

	size_t log_length = GetParam(GL_INFO_LOG_LENGTH);
	GLchar log[log_length];

	glGetProgramInfoLog(GetRef(), log_length, NULL, log);

	return std::string(log, log_length);
}

void GLProgramRef::BindUniformBlock(GLUniformBlockRef block_index, GLuint block_binding) {
	block_index.BindToBlock(GetRef(), block_binding);
}

void GLProgramRef::Use() const {
	glUseProgram(GetRef());
}

void GLProgramRef::Unuse() const {
	glUseProgram(0);
}

GLAttribRef GLProgramRef::GetAttribLocation(std::string name) const {
	return GLAttribRef(glGetAttribLocation(GetRef(), name.c_str()));
}

GLUniformRef GLProgramRef::GetUniformLocation(std::string name) const {
	return GLUniformRef(glGetUniformLocation(GetRef(), name.c_str()));
}

GLUniformBlockRef GLProgramRef::GetUniformBlockIndex(std::string name) const {
	return GLUniformBlockRef(glGetUniformBlockIndex(GetRef(), name.c_str()));
}

