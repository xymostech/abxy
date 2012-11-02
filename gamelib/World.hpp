#ifndef WORLD_HPP
#define WORLD_HPP

#include <vector>

#include <gamelib/Entity.inl>

class WorldStage;

class World {
	std::vector<Entity*> entities;
	long curr_id;

	WorldStage &parent;
public:
	World(WorldStage &parent);
	virtual ~World();

	virtual void AddEntity(Entity *entity);

	virtual void Draw() const;
	virtual void Update();

	WorldStage *GetParentStage();
};

#endif /* WORLD_HPP */

