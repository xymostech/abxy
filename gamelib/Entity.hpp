#ifndef ENTITY_HPP
#define ENTITY_HPP

class World;

#include <gamelib/World.hpp>
#include <gamelib/Matrix.hpp>

class Entity {
	long id;

	World *world;
public:
	Entity()
	{
		
	}

	virtual ~Entity() {
		
	}

	virtual void SetId(long new_id) {
		id = new_id;
	}

	virtual void Register(World *set_world) {
		world = set_world;
	}

	virtual World &GetWorld() {
		return *world;
	}

	virtual void Draw(Matrix4 model_matrix) const = 0;
	virtual void Update() = 0;
};

#endif /* ENTITY_HPP */

