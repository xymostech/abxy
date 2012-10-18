#ifndef GLSHADERREF_HPP
#define GLSHADERREF_HPP

#include <gamelib/GL/GL.hpp>

class GLShaderRef {
	GLuint shader;
	GLenum type;
public:
	GLShaderRef(GLenum type)
	: type(type)
	{
		shader = glCreateShader(type);
	}

	virtual ~GLShaderRef() {
		glDeleteShader(shader);
	}

	GLenum GetType() {
		return type;
	}

	void AttachTo(GLuint program) {
		glAttachShader(program, shader);
	}

	void DetachFrom(GLuint program) {
		glDetachShader(program, shader);
	}

	void SetSource(std::string source) {
		const GLchar *source_data = source.c_str();
		glShaderSource(shader, 1, (const GLchar **)&source_data, NULL);
	}

	void Compile() {
		glCompileShader(shader);
	}

	GLint GetParam(GLenum pname) const {
		GLint param;
		glGetShaderiv(shader, pname, &param);
		return param;
	}

	std::string GetInfoLog() const {
		std::string info_log;

		size_t log_length = GetParam(GL_INFO_LOG_LENGTH);
		GLchar log[log_length];

		glGetShaderInfoLog(shader, log_length, NULL, log);

		return std::string(log, log_length);
	}
};

#endif /* GLSHADERREF_HPP */

