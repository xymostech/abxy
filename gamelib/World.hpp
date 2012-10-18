#ifndef WORLD_HPP
#define WORLD_HPP

#include <vector>

#include <gamelib/Entity.hpp>

class Stage;

class World {
	std::vector<Entity*> entities;
	long curr_id;

	Stage &parent;
public:
	World(Stage &parent)
	: parent(parent)
	{
		curr_id = 0;
	}

	virtual ~World() {
		std::vector<Entity*>::iterator it = entities.begin(), end = entities.end();
		for (it = entities.begin(), end = entities.end(); it != end; ++it) {
			delete *it;
		}
	}

	virtual void AddEntity(Entity *entity) {
		entity->SetId(curr_id++);
		entity->Register(this);
		entities.push_back(entity);
	}

	virtual void Draw() const {
		Matrix4 base_matrix(1.0);

		std::vector<Entity*>::const_iterator it, end = entities.end();
		for (it = entities.begin(); it != end; ++it) {
			(*it)->Draw(base_matrix);
		}
	}

	virtual void Update() {
		std::vector<Entity*>::iterator it, end = entities.end();
		for (it = entities.begin(); it != end; ++it) {
			(*it)->Update();
		}
	}

	virtual Stage &GetParentStage() {
		return parent;
	}
};

#endif /* WORLD_HPP */

