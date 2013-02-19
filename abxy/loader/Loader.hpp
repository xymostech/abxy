#ifndef LOADER_HPP
#define LOADER_HPP

#include <abxy/loader/TextureLoader.hpp>
#include <abxy/loader/ProgramLoader.hpp>
#include <abxy/loader/FontLoader.hpp>
#include <abxy/loader/SoundLoader.hpp>

class Loader {
	TextureLoader texture_loader;
	ProgramLoader program_loader;
	FontLoader font_loader;
	SoundLoader sound_loader;
public:
	TextureLoader *GetTextureLoader() { return texture_loader; }
	ProgramLoader *GetProgramLoader() { return program_loader; }
	FontLoader *GetFontLoader() { return font_loader; }
	SoundLoader *GetSoundLoader() { return sound_loader; }
};

#endif /* LOADER_HPP */

