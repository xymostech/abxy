#ifndef GLUNIFORMREF_HPP
#define GLUNIFORMREF_HPP

#include <gamelib/GL/GL.hpp>

class GLUniformRef {
	GLint uniform;
public:
	GLUniformRef()
	: uniform(0)
	{
		
	}

	GLUniformRef(GLint uniform)
	: uniform(uniform)
	{
		
	}

	void Set1f(GLfloat v0) const {
		glUniform1f(uniform, v0);
	}

	void Set2f(GLfloat v0, GLfloat v1) const {
		glUniform2f(uniform, v0, v1);
	}

	void Set3f(GLfloat v0, GLfloat v1, GLfloat v2) const {
		glUniform3f(uniform, v0, v1, v2);
	}

	void Set4f(GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) const {
		glUniform4f(uniform, v0, v1, v2, v3);
	}

	void Set1i(GLint v0) const {
		glUniform1i(uniform, v0);
	}

	void Set2i(GLint v0, GLint v1) const {
		glUniform2i(uniform, v0, v1);
	}

	void Set3i(GLint v0, GLint v1, GLint v2) const {
		glUniform3i(uniform, v0, v1, v2);
	}

	void Set4i(GLint v0, GLint v1, GLint v2, GLint v3) const {
		glUniform4i(uniform, v0, v1, v2, v3);
	}

	void Set1ui(GLuint v0) const {
		glUniform1ui(uniform, v0);
	}

	void Set2ui(GLuint v0, GLuint v1) const {
		glUniform2ui(uniform, v0, v1);
	}

	void Set3ui(GLuint v0, GLuint v1, GLuint v2) const {
		glUniform3ui(uniform, v0, v1, v2);
	}

	void Set4ui(GLuint v0, GLuint v1, GLuint v2, GLuint v3) const {
		glUniform4ui(uniform, v0, v1, v2, v3);
	}

	void Set1fv(GLsizei count, const GLfloat *value) const {
		glUniform1fv(uniform, count, value);
	}

	void Set2fv(GLsizei count, const GLfloat *value) const {
		glUniform2fv(uniform, count, value);
	}

	void Set3fv(GLsizei count, const GLfloat *value) const {
		glUniform3fv(uniform, count, value);
	}

	void Set4fv(GLsizei count, const GLfloat *value) const {
		glUniform4fv(uniform, count, value);
	}

	void Set1iv(GLsizei count, const GLint *value) const {
		glUniform1iv(uniform, count, value);
	}

	void Set2iv(GLsizei count, const GLint *value) const {
		glUniform2iv(uniform, count, value);
	}

	void Set3iv(GLsizei count, const GLint *value) const {
		glUniform3iv(uniform, count, value);
	}

	void Set4iv(GLsizei count, const GLint *value) const {
		glUniform4iv(uniform, count, value);
	}

	void Set1uiv(GLsizei count, const GLuint *value) const {
		glUniform1uiv(uniform, count, value);
	}

	void Set2uiv(GLsizei count, const GLuint *value) const {
		glUniform2uiv(uniform, count, value);
	}

	void Set3uiv(GLsizei count, const GLuint *value) const {
		glUniform3uiv(uniform, count, value);
	}

	void Set4uiv(GLsizei count, const GLuint *value) const {
		glUniform4uiv(uniform, count, value);
	}

	void SetMatrix2fv(GLsizei count, GLboolean transpose, const GLfloat *value) const {
		glUniformMatrix2fv(uniform, count, transpose, value);
	}

	void SetMatrix3fv(GLsizei count, GLboolean transpose, const GLfloat *value) const {
		glUniformMatrix3fv(uniform, count, transpose, value);
	}

	void SetMatrix4fv(GLsizei count, GLboolean transpose, const GLfloat *value) const {
		glUniformMatrix4fv(uniform, count, transpose, value);
	}

	void SetMatrix2x3fv(GLsizei count, GLboolean transpose, const GLfloat *value) const {
		glUniformMatrix2x3fv(uniform, count, transpose, value);
	}

	void SetMatrix3x2fv(GLsizei count, GLboolean transpose, const GLfloat *value) const {
		glUniformMatrix3x2fv(uniform, count, transpose, value);
	}

	void SetMatrix2x4fv(GLsizei count, GLboolean transpose, const GLfloat *value) const {
		glUniformMatrix2x4fv(uniform, count, transpose, value);
	}

	void SetMatrix4x2fv(GLsizei count, GLboolean transpose, const GLfloat *value) const {
		glUniformMatrix4x2fv(uniform, count, transpose, value);
	}

	void SetMatrix3x4fv(GLsizei count, GLboolean transpose, const GLfloat *value) const {
		glUniformMatrix3x4fv(uniform, count, transpose, value);
	}

	void SetMatrix4x3fv(GLsizei count, GLboolean transpose, const GLfloat *value) const {
		glUniformMatrix4x3fv(uniform, count, transpose, value);
	}
};

#endif /* GLUNIFORMREF_HPP */

