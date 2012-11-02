#ifndef GLPROGRAMREF_HPP
#define GLPROGRAMREF_HPP

#include <gamelib/GL/GL.hpp>

#include <gamelib/GL/GLShaderRef.inl>
#include <gamelib/GL/GLUniformRef.inl>
#include <gamelib/GL/GLAttribRef.inl>
#include <gamelib/GL/GLUniformBlockRef.inl>

class GLProgramRef {
	GLuint program;
public:
	GLProgramRef();
	virtual ~GLProgramRef();

	void Attach(GLShaderRef shader);
	void Detach(GLShaderRef shader);
	void Link();

	GLint GetParam(GLenum pname) const;
	std::string GetInfoLog() const;

	void BindUniformBlock(GLUniformBlockRef block_index, GLuint block_binding);

	void Use() const;
	void Unuse() const;

	GLAttribRef GetAttribLocation(std::string name) const;
	GLUniformRef GetUniformLocation(std::string name) const;
	GLUniformBlockRef GetUniformBlockIndex(std::string name) const;
};

#endif /* GLPROGRAMREF_HPP */

