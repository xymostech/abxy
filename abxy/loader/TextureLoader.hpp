#ifndef TEXTURELOADER_HPP
#define TEXTURELOADER_HPP

#include <abxy/loader/ResourceLoader.hpp>

#include <abxy/Texture.hpp>

class TextureLoader : public ResourceLoader<Texture> {
	virtual Texture *GetResource(std::string name);
};

#endif /* TEXTURELOADER_HPP */

