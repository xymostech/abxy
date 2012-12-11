#ifndef SOUND_INL
#define SOUND_INL

#include <gamelib/audio/Sound.hpp>

#include <fstream>
#include <thread>
#include <vector>
#include <functional>
#include <vorbis/codec.h>
#include <vorbis/vorbisfile.h>
#include <ao/ao.h>

struct StreamData {
	std::string file_name;
	std::ifstream *f;

	std::vector<char>::const_iterator it, end;

	bool stored;
};

namespace {
	size_t StreamRead(void *ptr, size_t size, size_t nmemb, void *datasource) {
		StreamData *data = reinterpret_cast<StreamData*>(datasource);

		if (data->stored) {
			std::vector<char>::const_iterator &it = data->it, end = data->end;

			size_t to_write = end - it;

			if (to_write > size * nmemb) {
				to_write = size * nmemb;
			}

			char *data = reinterpret_cast<char*>(ptr);

			std::copy(it, it + to_write, data);

			it += to_write;

			return to_write / size;
		} else {
			std::ifstream *f = data->f;

			f->clear();
			f->read(reinterpret_cast<char*>(ptr), size * nmemb);

			return f->gcount() / size;
		}
	}

	void PlaySound(StreamData *data, bool &stop) {
		OggVorbis_File vf;
		vorbis_info *info;
		int current_section;

		ov_callbacks callbacks = {
			StreamRead, nullptr, nullptr, nullptr
		};

		if(ov_open_callbacks(data, &vf, nullptr, 0, callbacks) < 0) {
			throw std::runtime_error("Could not open file " + data->file_name);
			return;
		}

		int driver = ao_default_driver_id();

		info = ov_info(&vf, -1);

		ao_sample_format sample_format;
		sample_format.bits = 16;
		sample_format.channels = info->channels;
		sample_format.rate = 44100;
		sample_format.byte_format = AO_FMT_NATIVE;
		sample_format.matrix = 0;

		ao_device* device = ao_open_live(driver, &sample_format, nullptr);

		char buffer[4096];

		int volume = 256;

		while (!stop) {
			long ret = ov_read(&vf, buffer, sizeof(buffer), 0, 2, 1, &current_section);

			if (ret == 0) {
				break;
			}

			int16_t *samples = reinterpret_cast<int16_t*>(&buffer[0]);

			for (int i = 0; i < ret / sizeof(*samples); ++i) {
				*samples++ = (((*samples) * volume + 128) >> 8);
			}

			ao_play(device, buffer, ret);
		}

		ov_clear(&vf);

		ao_close(device);
	}

	void PlaySoundFile(std::string file, bool &stop) {
		std::ifstream f(file.c_str());

		StreamData data;

		data.file_name = file;
		data.f = &f;
		data.stored = false;

		PlaySound(&data, stop);
	}

	void PlaySoundCache(std::string file, std::vector<char>& cache, bool &stop) {
		StreamData data;

		data.file_name = file;
		data.it = cache.cbegin();
		data.end = cache.cend();
		data.stored = true;

		PlaySound(&data, stop);
	}

	void ReadFile(std::string file, std::vector<char> &store) {
		std::ifstream f(file.c_str(), std::ios::binary);

		f.seekg(0, std::ios_base::end);
		size_t size = f.tellg();
		f.seekg(0, std::ios_base::beg);

		store.reserve(size);
		store.assign(std::istreambuf_iterator<char>(f), std::istreambuf_iterator<char>());
	}
}

Sound::Sound(std::string file_name, bool should_cache)
: file_name(file_name)
, is_cached(should_cache)
, stop(false)
{
	if (should_cache) {
		ReadFile(file_name, data);
	}
}

Sound::~Sound() {
	Stop();
}

void Sound::Play() {
	if (is_cached) {
		std::thread t(PlaySoundCache, file_name, std::ref(data), std::ref(stop));
		t.detach();
	} else {
		std::thread t(PlaySoundFile, file_name, std::ref(stop));
		t.detach();
	}
}

void Sound::Stop() {
	stop = true;
}

#endif /* SOUND_INL */

