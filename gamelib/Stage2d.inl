#ifndef STAGE2D_INL
#define STAGE2D_INL

#include <gamelib/Stage2d.hpp>

Stage2d::Stage2d(std::shared_ptr<Projection> projection)
: world(*this)
, program_loader(projection)
, projection(projection)
{
	projection->Resize();
}

Stage2d::~Stage2d() {
	
}

void Stage2d::Load() {
	
}

void Stage2d::Draw() const {
	glClear(GL_COLOR_BUFFER_BIT);
	world.Draw();
}

void Stage2d::Update() {
	world.Update();
}

World *Stage2d::GetWorld() {
	return &world;
}

Projection &Stage2d::GetProjection() {
	return *projection;
}

TextureLoader *Stage2d::GetTextureLoader() {
	return &texture_loader;
}

ProgramLoader *Stage2d::GetProgramLoader() {
	return &program_loader;
}


#endif /* STAGE2D_INL */

