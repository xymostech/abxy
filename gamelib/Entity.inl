#ifndef ENTITY_INL
#define ENTITY_INL

#include <gamelib/Entity.hpp>

Entity::Entity() {
	
}

Entity::~Entity() {
	
}

void Entity::SetId(long new_id) {
	id = new_id;
}

void Entity::Register(World *set_world) {
	world = set_world;
}

World *Entity::GetParentWorld() {
	return world;
}

#endif /* ENTITY_INL */

