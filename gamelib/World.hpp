#ifndef WORLD_HPP
#define WORLD_HPP

#include <vector>

#include <gamelib/Entity.inl>

class Stage2d;

class World {
	std::vector<Entity*> entities;
	long curr_id;

	Stage2d &parent;
public:
	World(Stage2d &parent);
	virtual ~World();

	virtual void AddEntity(Entity *entity);

	virtual void Draw() const;
	virtual void Update();

	Stage2d *GetParentStage();
};

#endif /* WORLD_HPP */

