#ifndef WORLD_HPP
#define WORLD_HPP

#include <deque>
#include <memory>

#include <gamelib/messages/Message.inl>

#include <gamelib/Entity.inl>

class WorldStage;

class World : virtual public MessageReceiver {
	std::deque<std::shared_ptr<Entity>> entities;

	std::deque<std::shared_ptr<Entity>> to_add;
	std::deque<Entity*> to_remove;

	long curr_id;

	bool in_update;

	WorldStage *parent;
public:
	World(WorldStage *parent);
	virtual ~World();

	template <class T, class... Args>
	void Add(Args&&... args) {
		AddEntity(std::dynamic_pointer_cast<Entity>(
			std::make_shared<T>(std::forward<Args>(args)...)
		));
	}
	virtual void AddEntity(std::shared_ptr<Entity> entity);

	virtual void RemoveEntity(Entity *entity);

	virtual void Draw() const;
	virtual void Update();

	WorldStage *GetParentStage();

	std::deque<std::shared_ptr<Entity>> &GetEntities();
};

#endif /* WORLD_HPP */

