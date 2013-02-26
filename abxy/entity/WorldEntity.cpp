#include "WorldEntity.hpp"

WorldEntity::WorldEntity()
: MessageReceiver("world")
, is_updating(false)
{
	
}

WorldEntity::~WorldEntity() {
	
}

void WorldEntity::Update() {
	is_updating = true;

	BranchEntity::Update();

	is_updating = false;

	for (std::shared_ptr<Entity> &e : to_add) {
		BranchEntity::AddChild(e);
	}
	for (Entity *e : to_remove) {
		BranchEntity::RemoveChild(e);
	}

	to_add.clear();
	to_remove.clear();
}

void WorldEntity::AddChild(const std::shared_ptr<Entity> &entity) {
	if (is_updating) {
		to_add.push_back(entity);
	} else {
		BranchEntity::AddChild(entity);
	}
}

void WorldEntity::RemoveChild(Entity *entity) {
	if (is_updating) {
		to_remove.push_back(entity);
	} else {
		BranchEntity::RemoveChild(entity);
	}
}
