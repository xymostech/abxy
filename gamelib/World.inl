#ifndef WORLD_INL
#define WORLD_INL

#include <gamelib/World.hpp>

World::World(WorldStage *parent)
: parent(parent)
{
	curr_id = 0;
}

World::~World() {
	std::vector<Entity*>::iterator it = entities.begin(), end = entities.end();
	for (it = entities.begin(), end = entities.end(); it != end; ++it) {
		delete *it;
	}
}

void World::AddEntity(Entity *entity) {
	entity->SetId(curr_id++);
	entity->Register(this);
	entities.push_back(entity);
}

void World::Draw() const {
	Matrix4 base_matrix(1.0);

	std::vector<Entity*>::const_iterator it, end = entities.end();
	for (it = entities.begin(); it != end; ++it) {
		(*it)->Draw(base_matrix);
	}
}

void World::Update() {
	std::vector<Entity*>::iterator it, end = entities.end();
	for (it = entities.begin(); it != end; ++it) {
		(*it)->Update();
	}
}

WorldStage *World::GetParentStage() {
	return parent;
}

#endif /* WORLD_INL */

