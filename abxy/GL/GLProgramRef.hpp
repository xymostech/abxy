#ifndef GLPROGRAMREF_HPP
#define GLPROGRAMREF_HPP

#include <abxy/GL/GL.hpp>

#include <abxy/GL/GLShaderRef.hpp>
#include <abxy/GL/GLUniformRef.hpp>
#include <abxy/GL/GLAttribRef.hpp>
#include <abxy/GL/GLUniformBlockRef.hpp>

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

