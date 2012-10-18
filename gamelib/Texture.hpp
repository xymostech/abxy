#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <string>

#include <gamelib/GL/GL.hpp>
#include <gamelib/GL/GLSamplerRef.hpp>
#include <gamelib/GL/GLTextureRef.hpp>
#include <gamelib/PngLoader.hpp>

class Texture {
	GLTextureRef<GL_TEXTURE_2D> tex;
	GLSamplerRef sampler;

	template <typename data_loader>
	void GenerateTexture(std::string filename) {
		data_loader loader;

		loader.Load(filename);

		int w, h;
		loader.GetSize(&w, &h);

		unsigned char const *data = loader.GetData();

		tex.Bind();

		tex.SetData2D(0, GL_RGBA, w, h, GL_RGBA, GL_UNSIGNED_BYTE, data);
		tex.GenerateMipmap();
	}

	void SetupSampler() {
		sampler.SetParameteri(GL_TEXTURE_WRAP_S, GL_REPEAT);
		sampler.SetParameteri(GL_TEXTURE_WRAP_T, GL_REPEAT);

		sampler.SetParameteri(GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		sampler.SetParameteri(GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	}
public:
	Texture(std::string texture) {
		Load(texture);
	}

	void Load(std::string texture) {
		GenerateTexture<PngLoader>(texture);
		SetupSampler();
	}

	void Parameterf(GLenum parameter, GLfloat value) {
		sampler.SetParameterf(parameter, value);
	}

	void Parameteri(GLenum parameter, GLint value) {
		sampler.SetParameteri(parameter, value);
	}

	void BindSampler(GLUniformRef loc) {
		loc.Set1i(0);
	}

	void Use() const {
		glActiveTexture(GL_TEXTURE0);
		tex.Bind();
		sampler.Bind(0);
	}
};

#endif /* TEXTURE_HPP */

