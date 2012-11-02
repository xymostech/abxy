#ifndef WORLD_HPP
#define WORLD_HPP

#include <vector>

#include <gamelib/Entity.inl>

class Stage;

class World {
	std::vector<Entity*> entities;
	long curr_id;

	Stage &parent;
public:
	World(Stage &parent);
	virtual ~World();

	virtual void AddEntity(Entity *entity);

	virtual void Draw() const;
	virtual void Update();

	virtual Stage &GetParentStage();
};

#endif /* WORLD_HPP */

