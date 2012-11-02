#ifndef GLSHADER_INL
#define GLSHADER_INL

#include <gamelib/GL/GLShader.hpp>

GLShader::GLShader(std::string file, GLenum shader_type)
: shader(shader_type)
{
	std::string file_data = File::Read(file);

	shader.SetSource(file_data);
	shader.Compile();

	if (shader.GetParam(GL_COMPILE_STATUS) == GL_FALSE) {
		std::string log = shader.GetInfoLog();

		std::string shader_name;

		if (shader.GetType() == GL_VERTEX_SHADER) {
			shader_name = "vertex";
		} else {
			shader_name = "fragment";
		}

		throw std::runtime_error("Error compiling " + shader_name + " shader: " + log);
	}
}

void GLShader::AttachTo(GLuint program) {
	shader.AttachTo(program);
}

void GLShader::DetachFrom(GLuint program) {
	shader.DetachFrom(program);
}

GLShaderRef &GLShader::GetRef() {
	return shader;
}

#endif /* GLSHADER_INL */

