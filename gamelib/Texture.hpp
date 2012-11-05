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
	void LoadFromFile(std::string filename);
	void LoadFromData(const unsigned char const *data, int w, int h, GLenum format);

	void SetupSampler();
public:
	Texture();
	Texture(std::string filename);
	Texture(const unsigned char const *data, int w, int h, GLenum format);

	void Load(std::string filename);
	void Load(const unsigned char const *data, int w, int h, GLenum format);

	void Parameterf(GLenum parameter, GLfloat value);
	void Parameteri(GLenum parameter, GLint value);

	void BindSampler(GLUniformRef loc);

	void Use() const;
};

#endif /* TEXTURE_HPP */

