#ifndef PROJECTIONENTITY_HPP
#define PROJECTIONENTITY_HPP

#include <abxy/entity/PassthroughEntity.hpp>

#include <abxy/Projection.hpp>
#include <abxy/loader/ProgramLoader.hpp>

template <class ProjectionClass>
class ProjectionEntity : public PassthroughEntity {
	ProjectionClass projection;
	ProgramLoader loader;
public:
	ProjectionEntity(Entity &entity);

	virtual void OnLoad(LoadData &data);
};

#include <abxy/entity/ProjectionEntity.inl>

#endif /* PROJECTIONENTITY_HPP */

