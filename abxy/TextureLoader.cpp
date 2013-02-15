#include <abxy/TextureLoader.hpp>

Texture *TextureLoader::GetResource(std::string name) {
	return new Texture(name);
}

