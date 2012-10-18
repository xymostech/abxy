#ifndef STAGE2D_HPP
#define STAGE2D_HPP

#include <gamelib/Stage.hpp>
#include <gamelib/World2d.hpp>
#include <gamelib/Perspective2d.hpp>

class Stage2d : public Stage {
	World2d world;
	Perspective2d perspective;
	ResourceLoader resources;
public:
	Stage2d()
	: world(*this)
	, resources(perspective)
	{
		perspective.SetActivePerspective();
	}

	virtual ~Stage2d() {
		
	}

	virtual void Load() {
		
	}

	virtual void Draw() const {
		glClear(GL_COLOR_BUFFER_BIT);
		perspective.Setup();
		world.Draw();
	}

	virtual void Update() {
		world.Update();
	}

	virtual World2d &GetWorld() {
		return world;
	}

	virtual Perspective &GetPerspective() {
		return perspective;
	}

	virtual ResourceLoader &GetResources() {
		return resources;
	}
};

#endif /* STAGE2D_HPP */

