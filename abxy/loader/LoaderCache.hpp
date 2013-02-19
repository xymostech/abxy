#ifndef LOADERCACHE_HPP
#define LOADERCACHE_HPP

#include <abxy/loader/Loader.hpp>

class LoaderCache {
	Loader loader;
	LoaderCache *cache;

	// TODO: Do this all automatically, using fancy templates
	bool HasTextureLoaded(std::string name);
	bool HasProgramLoaded(std::string name);
	bool HasFontLoaded(std::string name);
	bool HasSoundLoaded(std::string name);
	bool HasVertexShaderLoaded(std::string name);
	bool HasFragmentShaderLoaded(std::string name);
public:
	void SetCache(LoaderCache *set_cache);

	std::shared_ptr<Texture> LoadTexture(std::string name);
	std::shared_ptr<GLProgram> LoadProgram(std::string name);
	std::shared_ptr<Font> LoadFont(std::string name);
	std::shared_ptr<Sound> LoadSound(std::string name);
	std::shared_ptr<GLShader> LoadVertexShader(std::string name);
	std::shared_ptr<GLShader> LoadFragmentShader(std::string name);
};

#endif /* LOADERCACHE_HPP */

