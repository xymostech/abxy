#include <abxy/GL/GLUniformRef.hpp>

GLUniformRef::GLUniformRef()
: uniform(0)
{
	
}

GLUniformRef::GLUniformRef(GLint uniform)
: uniform(uniform)
{
	
}

void GLUniformRef::Set1f(GLfloat v0) const {
	glUniform1f(uniform, v0);
}

void GLUniformRef::Set2f(GLfloat v0, GLfloat v1) const {
	glUniform2f(uniform, v0, v1);
}

void GLUniformRef::Set3f(GLfloat v0, GLfloat v1, GLfloat v2) const {
	glUniform3f(uniform, v0, v1, v2);
}

void GLUniformRef::Set4f(GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) const {
	glUniform4f(uniform, v0, v1, v2, v3);
}

void GLUniformRef::Set1i(GLint v0) const {
	glUniform1i(uniform, v0);
}

void GLUniformRef::Set2i(GLint v0, GLint v1) const {
	glUniform2i(uniform, v0, v1);
}

void GLUniformRef::Set3i(GLint v0, GLint v1, GLint v2) const {
	glUniform3i(uniform, v0, v1, v2);
}

void GLUniformRef::Set4i(GLint v0, GLint v1, GLint v2, GLint v3) const {
	glUniform4i(uniform, v0, v1, v2, v3);
}

void GLUniformRef::Set1ui(GLuint v0) const {
	glUniform1ui(uniform, v0);
}

void GLUniformRef::Set2ui(GLuint v0, GLuint v1) const {
	glUniform2ui(uniform, v0, v1);
}

void GLUniformRef::Set3ui(GLuint v0, GLuint v1, GLuint v2) const {
	glUniform3ui(uniform, v0, v1, v2);
}

void GLUniformRef::Set4ui(GLuint v0, GLuint v1, GLuint v2, GLuint v3) const {
	glUniform4ui(uniform, v0, v1, v2, v3);
}

void GLUniformRef::Set1fv(GLsizei count, const GLfloat *value) const {
	glUniform1fv(uniform, count, value);
}

void GLUniformRef::Set2fv(GLsizei count, const GLfloat *value) const {
	glUniform2fv(uniform, count, value);
}

void GLUniformRef::Set3fv(GLsizei count, const GLfloat *value) const {
	glUniform3fv(uniform, count, value);
}

void GLUniformRef::Set4fv(GLsizei count, const GLfloat *value) const {
	glUniform4fv(uniform, count, value);
}

void GLUniformRef::Set1iv(GLsizei count, const GLint *value) const {
	glUniform1iv(uniform, count, value);
}

void GLUniformRef::Set2iv(GLsizei count, const GLint *value) const {
	glUniform2iv(uniform, count, value);
}

void GLUniformRef::Set3iv(GLsizei count, const GLint *value) const {
	glUniform3iv(uniform, count, value);
}

void GLUniformRef::Set4iv(GLsizei count, const GLint *value) const {
	glUniform4iv(uniform, count, value);
}

void GLUniformRef::Set1uiv(GLsizei count, const GLuint *value) const {
	glUniform1uiv(uniform, count, value);
}

void GLUniformRef::Set2uiv(GLsizei count, const GLuint *value) const {
	glUniform2uiv(uniform, count, value);
}

void GLUniformRef::Set3uiv(GLsizei count, const GLuint *value) const {
	glUniform3uiv(uniform, count, value);
}

void GLUniformRef::Set4uiv(GLsizei count, const GLuint *value) const {
	glUniform4uiv(uniform, count, value);
}

void GLUniformRef::SetMatrix2fv(GLsizei count, GLboolean transpose, const GLfloat *value) const {
	glUniformMatrix2fv(uniform, count, transpose, value);
}

void GLUniformRef::SetMatrix3fv(GLsizei count, GLboolean transpose, const GLfloat *value) const {
	glUniformMatrix3fv(uniform, count, transpose, value);
}

void GLUniformRef::SetMatrix4fv(GLsizei count, GLboolean transpose, const GLfloat *value) const {
	glUniformMatrix4fv(uniform, count, transpose, value);
}

void GLUniformRef::SetMatrix2x3fv(GLsizei count, GLboolean transpose, const GLfloat *value) const {
	glUniformMatrix2x3fv(uniform, count, transpose, value);
}

void GLUniformRef::SetMatrix3x2fv(GLsizei count, GLboolean transpose, const GLfloat *value) const {
	glUniformMatrix3x2fv(uniform, count, transpose, value);
}

void GLUniformRef::SetMatrix2x4fv(GLsizei count, GLboolean transpose, const GLfloat *value) const {
	glUniformMatrix2x4fv(uniform, count, transpose, value);
}

void GLUniformRef::SetMatrix4x2fv(GLsizei count, GLboolean transpose, const GLfloat *value) const {
	glUniformMatrix4x2fv(uniform, count, transpose, value);
}

void GLUniformRef::SetMatrix3x4fv(GLsizei count, GLboolean transpose, const GLfloat *value) const {
	glUniformMatrix3x4fv(uniform, count, transpose, value);
}

void GLUniformRef::SetMatrix4x3fv(GLsizei count, GLboolean transpose, const GLfloat *value) const {
	glUniformMatrix4x3fv(uniform, count, transpose, value);
}

