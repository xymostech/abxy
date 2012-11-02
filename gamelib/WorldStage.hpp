#ifndef WORLDSTAGE_HPP
#define WORLDSTAGE_HPP

#include <gamelib/Stage.inl>
#include <gamelib/World.inl>
#include <gamelib/Projection.inl>

#include <memory>

#include <gamelib/TextureLoader.inl>
#include <gamelib/ProgramLoader.inl>

class WorldStage : public Stage {
	World world;

	TextureLoader texture_loader;
	ProgramLoader program_loader;

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
};

#endif /* WORLDSTAGE_HPP */

