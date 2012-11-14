#ifndef FONTLOADER_HPP
#define FONTLOADER_HPP

#include <gamelib/ResourceLoader.inl>

#include <gamelib/Font.hpp>

class FontLoader : public ResourceLoader<Font> {
public:
	virtual Font *GetResource(std::string name);
};

#endif /* FONTLOADER_HPP */

