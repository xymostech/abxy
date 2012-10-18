#ifndef GLPROGRAM_HPP
#define GLPROGRAM_HPP

#include <string>
#include <stdexcept>

#include <gamelib/GL/GLProgramRef.hpp>
#include <gamelib/GL/GLShader.hpp>
#include <gamelib/GL/GLUniformBlockRef.hpp>
#include <gamelib/Perspective.hpp>

class GLProgram {
	GLProgramRef program;

	GLUniformBlockRef global_matrix_uniform;
public:
	GLProgram(std::string vertex_shader, std::string fragment_shader) {
		GLShader vertex(vertex_shader, GL_VERTEX_SHADER);
		GLShader fragment(fragment_shader, GL_FRAGMENT_SHADER);

		program.Attach(vertex.GetRef());
		program.Attach(fragment.GetRef());

		program.Link();

		if (program.GetParam(GL_LINK_STATUS) == GL_FALSE) {
			std::string log = program.GetInfoLog();

			throw std::runtime_error(
				std::string("Error linking program: ") + log
			);
		}

		global_matrix_uniform = GetUniformBlockIndex("matrices");

		program.Detach(vertex.GetRef());
		program.Detach(fragment.GetRef());
	}

	GLAttribRef GetAttribLocation(std::string name) const {
		return program.GetAttribLocation(name);
	}

	GLUniformRef GetUniformLocation(std::string name) const {
		return program.GetUniformLocation(name);
	}

	GLUniformBlockRef GetUniformBlockIndex(std::string name) const {
		return program.GetUniformBlockIndex(name);
	}

	void Use() const {
		program.Use();
	}

	void Unuse() const {
		program.Unuse();
	}

	void Setup(Perspective &perspective) {
		BindUniformBlock(perspective.GetUniformBindingIndex());
	}

	void BindUniformBlock(GLuint binding_block) {
		program.BindUniformBlock(
			global_matrix_uniform,
			binding_block
		);
	}

	GLProgramRef &GetRef() {
		return program;
	}
};

#endif /* GLPROGRAM_HPP */

