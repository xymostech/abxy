#ifndef BASEENTITY_HPP
#define BASEENTITY_HPP

#include <abxy/entity/Entity.hpp>

#include <abxy/projection/ProjectionIdentity.hpp>

class BaseEntity : public Entity {
	ProjectionIdentity projection;
	ProgramLoaderCache program_loader;
	LoaderCache loader;

	Entity *child;
public:
	BaseEntity();

	virtual void OnLoad(LoadData &data) { (void)data; };
	virtual void OnUnload() {};
	virtual void Draw(Matrix4 model_matrix) const { (void)model_matrix; };

	virtual void Draw() const;
	virtual void Update();

	virtual void SetChild(Entity *new_child);
};

#endif /* BASEENTITY_HPP */

