#ifndef SOUNDLOADER_INL
#define SOUNDLOADER_INL

#include <gamelib/SoundLoader.hpp>

#include <gamelib/audio/Sound.inl>

Sound *SoundLoader::GetResource(std::string name) {
	return new Sound(name, true);
}

#endif /* SOUNDLOADER_INL */

