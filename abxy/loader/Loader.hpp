#ifndef LOADER_HPP
#define LOADER_HPP

#include <abxy/loader/TextureLoader.hpp>
#include <abxy/loader/FontLoader.hpp>
#include <abxy/loader/SoundLoader.hpp>
#include <abxy/loader/ShaderLoader.hpp>

class Loader {
	TextureLoader texture_loader;
	FontLoader font_loader;
	SoundLoader sound_loader;
	ShaderLoader<GL_VERTEX_SHADER> vertex_shader_loader;
	ShaderLoader<GL_FRAGMENT_SHADER> fragment_shader_loader;
public:
	TextureLoader *GetTextureLoader() { return &texture_loader; }
	FontLoader *GetFontLoader() { return &font_loader; }
	SoundLoader *GetSoundLoader() { return &sound_loader; }
	ShaderLoader<GL_VERTEX_SHADER> *GetVertexShaderLoader() {
		return &vertex_shader_loader;
	}
	ShaderLoader<GL_FRAGMENT_SHADER> *GetFragmentShaderLoader() {
		return &fragment_shader_loader;
	}
};

#endif /* LOADER_HPP */

