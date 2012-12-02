#ifndef SOUND_HPP
#define SOUND_HPP

class Sound {
	std::string file_name;

	std::vector<char> data;
	bool is_cached;

	bool stop;
public:
	Sound(std::string file_name, bool should_cache);
	virtual ~Sound();

	void Play();
	void Stop();
};

#endif /* SOUND_HPP */

