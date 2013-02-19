#ifndef WORLDSTAGE_HPP
#define WORLDSTAGE_HPP

#include <memory>

#include <abxy/Stage.hpp>
#include <abxy/World.hpp>
#include <abxy/Projection.hpp>

#include <abxy/loader/TextureLoader.hpp>
#include <abxy/loader/ProgramLoader.hpp>
#include <abxy/loader/FontLoader.hpp>
#include <abxy/loader/SoundLoader.hpp>

class WorldStage : public Stage {
	World world;

	TextureLoader texture_loader;
	ProgramLoader program_loader;
	FontLoader font_loader;
	SoundLoader sound_loader;

	std::shared_ptr<Projection> projection;
public:
	WorldStage(std::shared_ptr<Projection> projection);
	virtual ~WorldStage();

	virtual void Draw() const;
	virtual void Update();

	std::shared_ptr<Projection> GetProjection();
	World *GetWorld();
	TextureLoader *GetTextureLoader();
	ProgramLoader *GetProgramLoader();
	FontLoader *GetFontLoader();
	SoundLoader *GetSoundLoader();
};

#endif /* WORLDSTAGE_HPP */

