#include <abxy/SoundLoader.hpp>

Sound *SoundLoader::GetResource(std::string name) {
	return new Sound(name, true);
}

