#ifndef WORLD_HPP
#define WORLD_HPP

#include <vector>
#include <memory>

#include <gamelib/messages/Message.inl>

#include <gamelib/Entity.inl>

class WorldStage;

class World : virtual public MessageReceiver {
	std::vector<std::shared_ptr<Entity>> entities;
	long curr_id;

	WorldStage *parent;
public:
	World(WorldStage *parent);
	virtual ~World();

	virtual void AddEntity(std::shared_ptr<Entity> entity);

	virtual void Draw() const;
	virtual void Update();

	WorldStage *GetParentStage();

	std::vector<std::shared_ptr<Entity>> &GetEntities();
};

#endif /* WORLD_HPP */

