#ifndef FONTLOADER_HPP
#define FONTLOADER_HPP

#include <abxy/loader/ResourceLoader.hpp>
#include <abxy/Font.hpp>

class FontLoader : public ResourceLoader<Font> {
public:
	virtual Font *GetResource(std::string name);
};

#endif /* FONTLOADER_HPP */

