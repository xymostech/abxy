#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <string>

#include <abxy/GL/GL.hpp>
#include <abxy/GL/GLSamplerRef.hpp>
#include <abxy/GL/GLTextureRef.hpp>
#include <abxy/GL/GLUniformRef.hpp>
#include <abxy/loader/PngLoader.hpp>

class Texture {
	GLTextureRef<GL_TEXTURE_2D> tex;
	GLSamplerRef sampler;

	template <typename data_loader>
	void LoadFromFile(std::string filename);
	void LoadFromData(const unsigned char *data, int w, int h, GLenum format);

	void SetupSampler();
public:
	Texture();
	Texture(std::string filename);
	Texture(const unsigned char *data, int w, int h, GLenum format);

	void Load(std::string filename);
	void Load(const unsigned char *data, int w, int h, GLenum format);

	void Parameterf(GLenum parameter, GLfloat value);
	void Parameteri(GLenum parameter, GLint value);

	void BindSampler(GLUniformRef loc);

	void Use() const;
};

#endif /* TEXTURE_HPP */

