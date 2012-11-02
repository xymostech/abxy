#ifndef WORLDSTAGE_INL
#define WORLDSTAGE_INL

#include <gamelib/WorldStage.hpp>

WorldStage::WorldStage(std::shared_ptr<Projection> projection)
: world(this)
, program_loader(projection)
, projection(projection)
{
	projection->Resize();
}

WorldStage::~WorldStage() {
	
}

void WorldStage::Draw() const {
	glClear(GL_COLOR_BUFFER_BIT);
	world.Draw();
}

void WorldStage::Update() {
	world.Update();
}

World *WorldStage::GetWorld() {
	return &world;
}

std::shared_ptr<Projection> WorldStage::GetProjection() {
	return projection;
}

TextureLoader *WorldStage::GetTextureLoader() {
	return &texture_loader;
}

ProgramLoader *WorldStage::GetProgramLoader() {
	return &program_loader;
}


#endif /* WORLDSTAGE_INL */
