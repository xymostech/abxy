#ifndef STAGE2D_HPP
#define STAGE2D_HPP

#include <gamelib/Stage.inl>
#include <gamelib/World2d.inl>
#include <gamelib/Projection.inl>

#include <memory>

#include <gamelib/TextureLoader.inl>
#include <gamelib/ProgramLoader.inl>

class Stage2d : public Stage {
	World world;

	TextureLoader texture_loader;
	ProgramLoader program_loader;

	std::shared_ptr<Projection> projection;
public:
	Stage2d(std::shared_ptr<Projection> projection);
	virtual ~Stage2d();

	virtual void Load();

	virtual void Draw() const;
	virtual void Update();

	virtual World *GetWorld();
	virtual Projection &GetProjection();

	TextureLoader *GetTextureLoader();
	ProgramLoader *GetProgramLoader();
};

#endif /* STAGE2D_HPP */

