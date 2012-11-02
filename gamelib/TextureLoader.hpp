#ifndef TEXTURELOADER_HPP
#define TEXTURELOADER_HPP

#include <gamelib/ResourceLoader.inl>

#include <gamelib/Texture.inl>

class TextureLoader : public ResourceLoader<Texture> {
	virtual Texture *GetResource(std::string name);
};

#endif /* TEXTURELOADER_HPP */

