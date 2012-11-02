#ifndef STAGE2D_HPP
#define STAGE2D_HPP

#include <gamelib/Stage.inl>
#include <gamelib/World2d.inl>
#include <gamelib/Perspective2d.inl>

class Stage2d : public Stage {
	World2d world;
	Perspective2d perspective;
	ResourceLoader resources;
public:
	Stage2d();
	virtual ~Stage2d();

	virtual void Load();

	virtual void Draw() const;
	virtual void Update();

	virtual World2d &GetWorld();
	virtual Perspective &GetPerspective();
	virtual ResourceLoader &GetResources();
};

#endif /* STAGE2D_HPP */

