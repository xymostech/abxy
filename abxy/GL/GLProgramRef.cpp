#include <abxy/GL/GLProgramRef.hpp>

GLProgramRef::GLProgramRef() {
	program = glCreateProgram();
}

GLProgramRef::~GLProgramRef() {
	glDeleteProgram(program);
}

void GLProgramRef::Attach(GLShaderRef shader) {
	shader.AttachTo(program);
}

void GLProgramRef::Detach(GLShaderRef shader) {
	shader.DetachFrom(program);
}

void GLProgramRef::Link() {
	glLinkProgram(program);
}

GLint GLProgramRef::GetParam(GLenum pname) const {
	GLint param;

	glGetProgramiv(program, pname, &param);

	return param;
}

std::string GLProgramRef::GetInfoLog() const {
	std::string info_log;

	size_t log_length = GetParam(GL_INFO_LOG_LENGTH);
	GLchar log[log_length];

	glGetProgramInfoLog(program, log_length, NULL, log);

	return std::string(log, log_length);
}

void GLProgramRef::BindUniformBlock(GLUniformBlockRef block_index, GLuint block_binding) {
	block_index.BindToBlock(program, block_binding);
}

void GLProgramRef::Use() const {
	glUseProgram(program);
}

void GLProgramRef::Unuse() const {
	glUseProgram(0);
}

GLAttribRef GLProgramRef::GetAttribLocation(std::string name) const {
	return GLAttribRef(glGetAttribLocation(program, name.c_str()));
}

GLUniformRef GLProgramRef::GetUniformLocation(std::string name) const {
	return GLUniformRef(glGetUniformLocation(program, name.c_str()));
}

GLUniformBlockRef GLProgramRef::GetUniformBlockIndex(std::string name) const {
	return GLUniformBlockRef(glGetUniformBlockIndex(program, name.c_str()));
}

