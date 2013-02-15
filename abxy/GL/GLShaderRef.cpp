#include <abxy/GL/GLShaderRef.hpp>

GLShaderRef::GLShaderRef(GLenum type)
: type(type)
{
	shader = glCreateShader(type);
}

GLShaderRef::~GLShaderRef() {
	glDeleteShader(shader);
}

GLenum GLShaderRef::GetType() {
	return type;
}

void GLShaderRef::AttachTo(GLuint program) {
	glAttachShader(program, shader);
}

void GLShaderRef::DetachFrom(GLuint program) {
	glDetachShader(program, shader);
}

void GLShaderRef::SetSource(std::string source) {
	const GLchar *source_data = source.c_str();
	glShaderSource(shader, 1, (const GLchar **)&source_data, NULL);
}

void GLShaderRef::Compile() {
	glCompileShader(shader);
}

GLint GLShaderRef::GetParam(GLenum pname) const {
	GLint param;
	glGetShaderiv(shader, pname, &param);
	return param;
}

std::string GLShaderRef::GetInfoLog() const {
	std::string info_log;

	size_t log_length = GetParam(GL_INFO_LOG_LENGTH);
	GLchar log[log_length];

	glGetShaderInfoLog(shader, log_length, NULL, log);

	return std::string(log, log_length);
}

