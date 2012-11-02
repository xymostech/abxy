#ifndef GLPROGRAM_HPP
#define GLPROGRAM_HPP

#include <string>
#include <stdexcept>

#include <gamelib/GL/GLProgramRef.inl>
#include <gamelib/GL/GLShader.inl>
#include <gamelib/GL/GLUniformBlockRef.inl>
#include <gamelib/Perspective.inl>

class GLProgram {
	GLProgramRef program;

	GLUniformBlockRef global_matrix_uniform;
public:
	GLProgram(std::string vertex_shader, std::string fragment_shader);

	GLAttribRef GetAttribLocation(std::string name) const;
	GLUniformRef GetUniformLocation(std::string name) const;
	GLUniformBlockRef GetUniformBlockIndex(std::string name) const;

	void Use() const;
	void Unuse() const;

	void Setup(Perspective &perspective);

	void BindUniformBlock(GLuint binding_block);

	GLProgramRef &GetRef();
};

#endif /* GLPROGRAM_HPP */

