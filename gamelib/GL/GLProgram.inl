#ifndef GLPROGRAM_INL
#define GLPROGRAM_INL

#include <gamelib/GL/GLProgram.hpp>

GLProgram::GLProgram(std::string vertex_shader, std::string fragment_shader) {
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

GLAttribRef GLProgram::GetAttribLocation(std::string name) const {
	return program.GetAttribLocation(name);
}

GLUniformRef GLProgram::GetUniformLocation(std::string name) const {
	return program.GetUniformLocation(name);
}

GLUniformBlockRef GLProgram::GetUniformBlockIndex(std::string name) const {
	return program.GetUniformBlockIndex(name);
}

void GLProgram::Use() const {
	program.Use();
}

void GLProgram::Unuse() const {
	program.Unuse();
}

void GLProgram::Setup(Perspective *perspective) {
	BindUniformBlock(perspective->GetUniformBindingIndex());
}

void GLProgram::BindUniformBlock(GLuint binding_block) {
	program.BindUniformBlock(
		global_matrix_uniform,
		binding_block
	);
}

GLProgramRef &GLProgram::GetRef() {
	return program;
}

#endif /* GLPROGRAM_INL */

