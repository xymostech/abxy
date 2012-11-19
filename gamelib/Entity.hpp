#ifndef ENTITY_HPP
#define ENTITY_HPP

class World;

#include <gamelib/World.inl>
#include <gamelib/Matrix.inl>
#include <gamelib/messages/Message.inl>

class Entity : virtual public MessageReceiver {
	long id;
	long type;

	World *world;
public:
	Entity();
	Entity(long type);
	virtual ~Entity();

	void SetId(long new_id);
	long GetId() const;

	long GetType() const;

	virtual void Register(World *set_world);

	virtual World *GetParentWorld();

	virtual void Draw(Matrix4 model_matrix) const = 0;
	virtual void Update() = 0;
};

#endif /* ENTITY_HPP */

