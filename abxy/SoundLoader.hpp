#ifndef SOUNDLOADER_HPP
#define SOUNDLOADER_HPP

#include <abxy/ResourceLoader.hpp>

#include <abxy/audio/Sound.hpp>

class SoundLoader : public ResourceLoader<Sound> {
public:
	virtual Sound *GetResource(std::string name);
};

#endif /* SOUNDLOADER_HPP */

