#ifndef PASSTHROUGHENTITY_HPP
#define PASSTHROUGHENTITY_HPP

#include <abxy/entity/Entity.hpp>

/**
 * Passthrough Entity
 *
 * This is an entity that, on initialization, takes in another entity, and
 * simply passes through all of the Entity function class to that child.
 * This class, by itself, isn't that useful, but by replacing some of the
 * methods, it can be used to create more complex structures.
 */
class PassthroughEntity : public Entity {
	/**
	 * The child entity to pass all the calls to
	 */
	Entity &child;
public:
	/**
	 * The default initializer simply constructs with the child
	 * @param child The child entity
	 */
	PassthroughEntity(Entity &child);

	/**
	 * Passes OnLoad calls to the child
	 */
	virtual void OnLoad(Entity *parent);
	/**
	 * Passes OnUnload calls to the child
	 */
	virtual void OnUnload();

	/**
	 * Passes Draw calls to the child
	 */
	virtual void Draw(Matrix4 model_matrix) const;

	/**
	 * Passes Update calls to the child
	 */
	virtual void Update();
};

#endif /* PASSTHROUGHENTITY_HPP */

