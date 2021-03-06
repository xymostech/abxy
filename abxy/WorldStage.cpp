#include <abxy/WorldStage.hpp>

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

