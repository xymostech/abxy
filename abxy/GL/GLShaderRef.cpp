#include <abxy/GL/GLShaderRef.hpp>

GLShaderRef::GLShaderRef(GLenum type)
: type(type)
{
	SetRef(glCreateShader(type));
}

GLShaderRef::GLShaderRef(GLShaderRef &&move)
: GLCreateRef<GLuint>(std::move(move))
{ }

GLShaderRef::~GLShaderRef() {
	if (IsCreated()) {
		glDeleteShader(GetRef());
	}
}

GLShaderRef &GLShaderRef::operator=(GLShaderRef &&move) {
	GLCreateRef<GLuint>::operator=(std::move(move));

	return *this;
}

GLenum GLShaderRef::GetType() {
	return type;
}

void GLShaderRef::AttachTo(GLuint program) {
	glAttachShader(program, GetRef());
}

void GLShaderRef::DetachFrom(GLuint program) {
	glDetachShader(program, GetRef());
}

void GLShaderRef::SetSource(std::string source) {
	const GLchar *source_data = source.c_str();
	glShaderSource(GetRef(), 1, (const GLchar **)&source_data, NULL);
}

void GLShaderRef::Compile() {
	glCompileShader(GetRef());
}

GLint GLShaderRef::GetParam(GLenum pname) const {
	GLint param;
	glGetShaderiv(GetRef(), pname, &param);
	return param;
}

std::string GLShaderRef::GetInfoLog() const {
	std::string info_log;

	size_t log_length = GetParam(GL_INFO_LOG_LENGTH);
	GLchar log[log_length];

	glGetShaderInfoLog(GetRef(), log_length, NULL, log);

	return std::string(log, log_length);
}

