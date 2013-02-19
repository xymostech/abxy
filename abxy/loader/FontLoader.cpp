#include <abxy/loader/FontLoader.hpp>

Font *FontLoader::GetResource(std::string name) {
	return new Font(name);
}

