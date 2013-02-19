#include <abxy/GL/GLProgram.hpp>

GLProgram::GLProgram(const std::vector<std::shared_ptr<GLShader>> &shaders) {
	for (auto &shader : shaders) {
		program.Attach(shader->GetRef());
	}

	program.Link();

	if (program.GetParam(GL_LINK_STATUS) == GL_FALSE) {
		std::string log = program.GetInfoLog();

		throw std::runtime_error(
			std::string("Error linking program: ") + log
		);
	}

	global_matrix_uniform = GetUniformBlockIndex("matrices");

	for (auto &shader : shaders) {
		program.Detach(shader->GetRef());
	}
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

void GLProgram::Setup(std::shared_ptr<Projection> projection) {
	BindUniformBlock(projection->GetUniformBindingIndex());
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

