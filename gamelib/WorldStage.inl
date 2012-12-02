#ifndef WORLDSTAGE_INL
#define WORLDSTAGE_INL

#include <gamelib/WorldStage.hpp>

#include <gamelib/FontLoader.inl>

WorldStage::WorldStage(std::shared_ptr<Projection> projection)
: MessageReceiver("stage")
, world(this)
, program_loader(projection)
, projection(projection)
{
	projection->Resize();
	MessageReceiver::AddChild(&world);
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

FontLoader *WorldStage::GetFontLoader() {
	return &font_loader;
}

SoundLoader *WorldStage::GetSoundLoader() {
	return &sound_loader;
}

#endif /* WORLDSTAGE_INL */

