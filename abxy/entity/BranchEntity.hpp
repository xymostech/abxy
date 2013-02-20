#ifndef BRANCHENTITY_HPP
#define BRANCHENTITY_HPP

#include <list>
#include <memory>

#include <abxy/entity/Entity.hpp>

/**
 * BranchEntity class
 *
 * This is a class that stores many different entities inside of it, creating a
 * "branch" in the tree of entities. It passes all of the functions through, but
 * it is the parent of its children. It also adds functions to add and remove
 * its children.
 */
class BranchEntity : public Entity {
protected:
	/**
	 * stores whether or not we are loaded, so we can do interesting things
	 * with the loading of children
	 */
	bool is_loaded;

	/**
	 * stores the data we were used to load with, so that if an entity is
	 * added after we are already loaded in, we can load them as well.
	 */
	LoadData store_data;

	/**
	 * Stores the list of children that this entity contains.
	 * TODO: figure out what data structure would be best here
	 */
	std::list<std::shared_ptr<Entity>> children;
public:
	/**
	 * Default initializer, simply sets up the messagereceiver
	 */
	BranchEntity();

	/**
	 * When called, re-calls OnLoad on all of its children, with this
	 * entity as the new parent.
	 * @param parent The parent entity, currently unused
	 */
	virtual void OnLoad(LoadData &data);
	/**
	 * When called, re-calls OnUnload on all of its children.
	 */
	virtual void OnUnload();

	/**
	 * Re-calls Draw on all of its children
	 */
	virtual void Draw(Matrix4 model_matrix) const;

	/**
	 * Re-calls Update on all of its children
	 */
	virtual void Update();

	/**
	 * Adds a child to the list of child entities
	 */
	virtual void AddChild(const std::shared_ptr<Entity> &entity);
	/**
	 * Removes a child from the list of child entities, identitied as equal
	 * to a shared pointer to that child
	 */
	virtual void RemoveChild(const std::shared_ptr<Entity> &entity);
	/**
	 * Removes a child from the list of child entities, identified as equal
	 * to a raw pointer to that child
	 */
	virtual void RemoveChild(Entity *entity);

	/**
	 * Retrieves the list of children
	 */
	virtual std::list<std::shared_ptr<Entity>> &GetChildren();
	/**
	 * Same as GetChildren, but const
	 */
	virtual const std::list<std::shared_ptr<Entity>> &GetChildren() const;
};

#endif /* BRANCHENTITY_HPP */

