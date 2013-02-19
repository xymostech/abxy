#include <abxy/loader/TextureLoader.hpp>

Texture *TextureLoader::GetResource(std::string name) {
	return new Texture(name);
}

