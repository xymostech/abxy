#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <string>

#include <gamelib/GL/GL.hpp>
#include <gamelib/GL/GLSamplerRef.inl>
#include <gamelib/GL/GLTextureRef.inl>
#include <gamelib/GL/GLUniformRef.inl>
#include <gamelib/PngLoader.inl>

class Texture {
	GLTextureRef<GL_TEXTURE_2D> tex;
	GLSamplerRef sampler;

	template <typename data_loader>
	void GenerateTexture(std::string filename);

	void SetupSampler();
public:
	Texture(std::string texture);

	void Load(std::string texture);

	void Parameterf(GLenum parameter, GLfloat value);
	void Parameteri(GLenum parameter, GLint value);

	void BindSampler(GLUniformRef loc);

	void Use() const;
};

#endif /* TEXTURE_HPP */

