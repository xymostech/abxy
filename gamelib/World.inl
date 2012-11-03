#ifndef WORLD_INL
#define WORLD_INL

#include <gamelib/World.hpp>

World::World(WorldStage *parent)
: curr_id(0)
, parent(parent)
{
	
}

World::~World() {
	
}

void World::AddEntity(std::shared_ptr<Entity> entity) {
	entity->SetId(curr_id++);
	entity->Register(this);
	entities.push_back(entity);
}

void World::Draw() const {
	Matrix4 base_matrix(1.0);

	std::vector<std::shared_ptr<Entity>>::const_iterator it, end = entities.end();
	for (it = entities.begin(); it != end; ++it) {
		(*it)->Draw(base_matrix);
	}
}

void World::Update() {
	std::vector<std::shared_ptr<Entity>>::iterator it, end = entities.end();
	for (it = entities.begin(); it != end; ++it) {
		(*it)->Update();
	}
}

WorldStage *World::GetParentStage() {
	return parent;
}

std::vector<std::shared_ptr<Entity>> &World::GetEntities() {
	return entities;
}

#endif /* WORLD_INL */

