#ifndef GLPROGRAMREF_HPP
#define GLPROGRAMREF_HPP

#include <gamelib/GL/GL.hpp>

#include <gamelib/GL/GLShaderRef.hpp>
#include <gamelib/GL/GLUniformRef.hpp>
#include <gamelib/GL/GLAttribRef.hpp>
#include <gamelib/GL/GLUniformBlockRef.hpp>

class GLProgramRef {
	GLuint program;
public:
	GLProgramRef() {
		program = glCreateProgram();
	}

	virtual ~GLProgramRef() {
		glDeleteProgram(program);
	}

	void Attach(GLShaderRef shader) {
		shader.AttachTo(program);
	}

	void Detach(GLShaderRef shader) {
		shader.DetachFrom(program);
	}

	void Link() {
		glLinkProgram(program);
	}

	GLint GetParam(GLenum pname) const {
		GLint param;

		glGetProgramiv(program, pname, &param);

		return param;
	}

	std::string GetInfoLog() const {
		std::string info_log;

		size_t log_length = GetParam(GL_INFO_LOG_LENGTH);
		GLchar log[log_length];

		glGetProgramInfoLog(program, log_length, NULL, log);

		return std::string(log, log_length);
	}

	void BindUniformBlock(GLUniformBlockRef block_index, GLuint block_binding) {
		block_index.BindToBlock(program, block_binding);
	}

	void Use() const {
		glUseProgram(program);
	}

	void Unuse() const {
		glUseProgram(0);
	}

	GLAttribRef GetAttribLocation(std::string name) const {
		return GLAttribRef(glGetAttribLocation(program, name.c_str()));
	}

	GLUniformRef GetUniformLocation(std::string name) const {
		return GLUniformRef(glGetUniformLocation(program, name.c_str()));
	}

	GLUniformBlockRef GetUniformBlockIndex(std::string name) const {
		return GLUniformBlockRef(glGetUniformBlockIndex(program, name.c_str()));
	}
};

#endif /* GLPROGRAMREF_HPP */

