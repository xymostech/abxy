#ifndef GLPROGRAM_HPP
#define GLPROGRAM_HPP

#include <string>
#include <stdexcept>
#include <memory>
#include <vector>

#include <abxy/GL/GLProgramRef.hpp>
#include <abxy/GL/GLShader.hpp>
#include <abxy/GL/GLUniformBlockRef.hpp>
#include <abxy/projection/Projection.hpp>

class GLProgram {
	GLProgramRef program;

	GLUniformBlockRef global_matrix_uniform;
public:
	GLProgram(const std::vector<std::shared_ptr<GLShader>> &shaders);

	GLAttribRef GetAttribLocation(std::string name) const;
	GLUniformRef GetUniformLocation(std::string name) const;
	GLUniformBlockRef GetUniformBlockIndex(std::string name) const;

	void Use() const;
	void Unuse() const;

	void Setup(Projection &projection);

	void BindUniformBlock(GLuint binding_block);

	GLProgramRef &GetRef();
};

#endif /* GLPROGRAM_HPP */

