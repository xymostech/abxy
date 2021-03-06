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

void GLProgram::SetProjection(Projection &projection) {
	GLUniformBlockRef global_matrix_uniform =
		program.GetUniformBlockIndex("matrices");

	program.BindUniformBlock(
		global_matrix_uniform,
		projection.GetUniformBindingIndex()
	);
}

GLProgramRef &GLProgram::GetRef() {
	return program;
}

