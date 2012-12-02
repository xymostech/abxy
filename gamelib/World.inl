#ifndef WORLD_INL
#define WORLD_INL

#include <gamelib/World.hpp>

World::World(WorldStage *parent)
: MessageReceiver("world")
, curr_id(0)
, in_update(false)
, parent(parent)
{
	
}

World::~World() {
	
}

void World::AddEntity(std::shared_ptr<Entity> entity) {
	if (in_update) {
		to_add.push_back(entity);
	} else {
		entity->SetId(curr_id++);
		entity->Register(this);
		entities.push_back(entity);
		MessageReceiver::AddChild(entity.get());
	}
}

void World::Draw() const {
	Matrix4 base_matrix(1.0);

	for (const std::shared_ptr<Entity> &e : entities) {
		e->Draw(base_matrix);
	}
}

void World::Update() {
	in_update = true;

	for (std::shared_ptr<Entity> &e : entities) {
		e->Update();
	}

	in_update = false;

	for (std::shared_ptr<Entity> &e : to_add) {
		AddEntity(e);
	}

	to_add.clear();
}

WorldStage *World::GetParentStage() {
	return parent;
}

std::deque<std::shared_ptr<Entity>> &World::GetEntities() {
	return entities;
}

#endif /* WORLD_INL */

