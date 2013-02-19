#ifndef SHADERLOADER_HPP
#define SHADERLOADER_HPP

#include <abxy/loader/ResourceLoader.hpp>

#include <abxy/GL/GLShader.hpp>

template <GLenum shader_type>
class ShaderLoader : public ResourceLoader<GLShader> {
	virtual GLShader *GetResource(std::string name);
};

#include <abxy/loader/ShaderLoader.inl>

#endif /* SHADERLOADER_HPP */

