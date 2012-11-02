#ifndef TEXTURE_INL
#define TEXTURE_INL

#include <gamelib/Texture.hpp>

template <typename data_loader>
void Texture::GenerateTexture(std::string filename) {
	data_loader loader(filename);

	int w, h;
	loader.GetSize(&w, &h);

	unsigned char const *data = loader.GetConstData().data();

	tex.Bind();

	tex.SetData2D(0, GL_RGBA, w, h, GL_RGBA, GL_UNSIGNED_BYTE, data);
	tex.GenerateMipmap();
}

void Texture::SetupSampler() {
	sampler.SetParameteri(GL_TEXTURE_WRAP_S, GL_REPEAT);
	sampler.SetParameteri(GL_TEXTURE_WRAP_T, GL_REPEAT);

	sampler.SetParameteri(GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	sampler.SetParameteri(GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}

Texture::Texture(std::string texture) {
	Load(texture);
}

void Texture::Load(std::string texture) {
	GenerateTexture<PngLoader>(texture);
	SetupSampler();
}

void Texture::Parameterf(GLenum parameter, GLfloat value) {
	sampler.SetParameterf(parameter, value);
}

void Texture::Parameteri(GLenum parameter, GLint value) {
	sampler.SetParameteri(parameter, value);
}

void Texture::BindSampler(GLUniformRef loc) {
	loc.Set1i(0);
}

void Texture::Use() const {
	glActiveTexture(GL_TEXTURE0);
	tex.Bind();
	sampler.Bind(0);
}

#endif /* TEXTURE_INL */

