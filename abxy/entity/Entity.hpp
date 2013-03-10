#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <abxy/math/Matrix.hpp>
#include <abxy/messages/Message.hpp>
#include <abxy/loader/LoadData.hpp>

/**
 * Entity class
 *
 * Entities make up the base of the ABXY library. Everything is an entity.
 *
 * Entities must perform 4 tasks. They do things when they are added or removed
 * from the scene. Also, the can be drawn and updated. The base entity leaves
 * all of these things un-implemented.
 */
class Entity : virtual public MessageReceiver {
public:
	/**
	 * Default constructor, simply initializes MessageReceiver
	 */
	Entity();

	/*
	 * Called when an entity is added to the scene
	 * @param parent The parent entity which is loading this entity
	 */
	virtual void OnLoad(LoadData &data) = 0;
	/**
	 * Called when an entity is removed from the scene
	 */
	virtual void OnUnload() = 0;

	/**
	 * Called when an entity should be drawn. This is a const function, so
	 * it can't make any modifications to the entity itself.
	 * @param model_matrix The transformation matrix of the parent entities
	 */
	virtual void Draw(Matrix4 model_matrix) const = 0;

	/**
	 * Called when an entity should update itself
	 */
	virtual void Update() = 0;
};

#endif /* ENTITY_HPP */

