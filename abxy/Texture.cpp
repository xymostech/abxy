#include <abxy/Texture.hpp>

template <typename data_loader>
void Texture::LoadFromFile(std::string filename) {
	data_loader loader(filename);

	int w, h;
	loader.GetSize(&w, &h);

	unsigned char const *data = loader.GetData().data();

	LoadFromData(data, w, h, GL_RGBA);
}

void Texture::LoadFromData(const unsigned char const *data, int w, int h, GLenum format) {
	tex.Bind();

	tex.SetData2D(0, GL_RGBA, w, h, format, GL_UNSIGNED_BYTE, data);
	tex.GenerateMipmap();
}

void Texture::SetupSampler() {
	sampler.SetParameteri(GL_TEXTURE_WRAP_S, GL_REPEAT);
	sampler.SetParameteri(GL_TEXTURE_WRAP_T, GL_REPEAT);

	sampler.SetParameteri(GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	sampler.SetParameteri(GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}

Texture::Texture() {
	
}

Texture::Texture(std::string filename) {
	Load(filename);
}

Texture::Texture(const unsigned char const *data, int w, int h, GLenum format) {
	Load(data, w, h, format);
}

void Texture::Load(std::string filename) {
	LoadFromFile<PngLoader>(filename);
	SetupSampler();
}

void Texture::Load(const unsigned char const *data, int w, int h, GLenum format) {
	LoadFromData(data, w, h, format);
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

