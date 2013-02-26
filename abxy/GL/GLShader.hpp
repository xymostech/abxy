#ifndef GLSHADER_HPP
#define GLSHADER_HPP

#include <string>

#include <abxy/GL/GLShaderRef.hpp>

class GLShader {
	GLShaderRef shader;
public:
	GLShader(std::string file, GLenum shader_type);

	void AttachTo(GLuint program);
	void DetachFrom(GLuint program);

	GLShaderRef &GetRef();
};

#endif /* GLSHADER_HPP */

