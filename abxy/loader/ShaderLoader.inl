#include <abxy/loader/ShaderLoader.hpp>

template <GLenum shader_type>
GLShader *ShaderLoader<shader_type>::GetResource(std::string name) {
	return new GLShader(name, shader_type);
}
