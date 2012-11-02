#ifndef TEXTURELOADER_INL
#define TEXTURELOADER_INL

#include <gamelib/TextureLoader.hpp>

Texture *TextureLoader::GetResource(std::string name) {
	return new Texture(name);
}

#endif /* TEXTURELOADER_INL */

