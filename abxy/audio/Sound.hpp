#ifndef SOUND_HPP
#define SOUND_HPP

#include <string>
#include <vector>

class Sound {
	std::string file_name;

	std::vector<char> data;
	bool is_cached;

	bool stop;
public:
	Sound(std::string file_name, bool should_cache);
	virtual ~Sound();

	void Play(float volume = 1.0, bool repeat = false);
	void Stop();
};

#endif /* SOUND_HPP */

