#ifndef STAGE2D_INL
#define STAGE2D_INL

#include <gamelib/Stage2d.hpp>

Stage2d::Stage2d()
: world(*this)
, resources(perspective)
{
	perspective.SetActivePerspective();
}

Stage2d::~Stage2d() {
	
}

void Stage2d::Load() {
	
}

void Stage2d::Draw() const {
	glClear(GL_COLOR_BUFFER_BIT);
	perspective.Setup();
	world.Draw();
}

void Stage2d::Update() {
	world.Update();
}

World2d &Stage2d::GetWorld() {
	return world;
}

Perspective &Stage2d::GetPerspective() {
	return perspective;
}

ResourceLoader &Stage2d::GetResources() {
	return resources;
}

#endif /* STAGE2D_INL */

