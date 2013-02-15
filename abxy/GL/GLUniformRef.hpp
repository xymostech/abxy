#ifndef GLUNIFORMREF_HPP
#define GLUNIFORMREF_HPP

#include <abxy/GL/GL.hpp>

class GLUniformRef {
	GLint uniform;
public:
	GLUniformRef();
	GLUniformRef(GLint uniform);

	void Set1f(GLfloat v0) const;
	void Set2f(GLfloat v0, GLfloat v1) const;
	void Set3f(GLfloat v0, GLfloat v1, GLfloat v2) const;
	void Set4f(GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) const;

	void Set1i(GLint v0) const;
	void Set2i(GLint v0, GLint v1) const;
	void Set3i(GLint v0, GLint v1, GLint v2) const;
	void Set4i(GLint v0, GLint v1, GLint v2, GLint v3) const;

	void Set1ui(GLuint v0) const;
	void Set2ui(GLuint v0, GLuint v1) const;
	void Set3ui(GLuint v0, GLuint v1, GLuint v2) const;
	void Set4ui(GLuint v0, GLuint v1, GLuint v2, GLuint v3) const;

	void Set1fv(GLsizei count, const GLfloat *value) const;
	void Set2fv(GLsizei count, const GLfloat *value) const;
	void Set3fv(GLsizei count, const GLfloat *value) const;
	void Set4fv(GLsizei count, const GLfloat *value) const;

	void Set1iv(GLsizei count, const GLint *value) const;
	void Set2iv(GLsizei count, const GLint *value) const;
	void Set3iv(GLsizei count, const GLint *value) const;
	void Set4iv(GLsizei count, const GLint *value) const;

	void Set1uiv(GLsizei count, const GLuint *value) const;
	void Set2uiv(GLsizei count, const GLuint *value) const;
	void Set3uiv(GLsizei count, const GLuint *value) const;
	void Set4uiv(GLsizei count, const GLuint *value) const;

	void SetMatrix2fv(GLsizei count, GLboolean transpose, const GLfloat *value) const;
	void SetMatrix3fv(GLsizei count, GLboolean transpose, const GLfloat *value) const;
	void SetMatrix4fv(GLsizei count, GLboolean transpose, const GLfloat *value) const;
	void SetMatrix2x3fv(GLsizei count, GLboolean transpose, const GLfloat *value) const;
	void SetMatrix3x2fv(GLsizei count, GLboolean transpose, const GLfloat *value) const;
	void SetMatrix2x4fv(GLsizei count, GLboolean transpose, const GLfloat *value) const;
	void SetMatrix4x2fv(GLsizei count, GLboolean transpose, const GLfloat *value) const;
	void SetMatrix3x4fv(GLsizei count, GLboolean transpose, const GLfloat *value) const;
	void SetMatrix4x3fv(GLsizei count, GLboolean transpose, const GLfloat *value) const;
};

#endif /* GLUNIFORMREF_HPP */

