#include <abxy/Entity.hpp>

Entity::Entity()
: Entity(0)
{

}

Entity::Entity(long type)
: MessageReceiver("entity")
, type(type)
{
	
}

Entity::~Entity() {
	
}

void Entity::SetId(long new_id) {
	id = new_id;
}

long Entity::GetId() const {
	return id;
}

long Entity::GetType() const {
	return type;
}

void Entity::Register(World *set_world) {
	world = set_world;
}

World *Entity::GetParentWorld() {
	return world;
}

