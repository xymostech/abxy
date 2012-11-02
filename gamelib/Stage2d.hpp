#ifndef STAGE2D_HPP
#define STAGE2D_HPP

#include <gamelib/Stage.inl>
#include <gamelib/World2d.inl>
#include <gamelib/Perspective2d.inl>

#include <gamelib/TextureLoader.inl>
#include <gamelib/ProgramLoader.inl>

class Stage2d : public Stage {
	World world;
	Perspective2d perspective;
	TextureLoader texture_loader;
	ProgramLoader program_loader;
public:
	Stage2d();
	virtual ~Stage2d();

	virtual void Load();

	virtual void Draw() const;
	virtual void Update();

	virtual World *GetWorld();
	virtual Perspective &GetPerspective();

	TextureLoader *GetTextureLoader();
	ProgramLoader *GetProgramLoader();
};

#endif /* STAGE2D_HPP */

