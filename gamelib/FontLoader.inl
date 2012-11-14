#ifndef FONTLOADER_INL
#define FONTLOADER_INL

#include <gamelib/FontLoader.hpp>

#include <gamelib/Font.inl>

Font *FontLoader::GetResource(std::string name) {
	return new Font(name);
}

#endif /* FONTLOADER_INL */

