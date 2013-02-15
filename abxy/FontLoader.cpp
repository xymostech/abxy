#include <abxy/FontLoader.hpp>

Font *FontLoader::GetResource(std::string name) {
	return new Font(name);
}

