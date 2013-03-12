#ifndef PROJECTIONENTITY_HPP
#define PROJECTIONENTITY_HPP

#include <abxy/entity/PassthroughEntity.hpp>

#include <abxy/projection/Projection.hpp>
#include <abxy/loader/ProgramLoaderCache.hpp>

template <class ProjectionClass>
class ProjectionEntity : public PassthroughEntity {
	ProjectionClass projection;
	ProgramLoaderCache loader;
public:
	ProjectionEntity(Entity &entity);

	virtual void OnLoad(LoadData &data);
};

#include <abxy/entity/ProjectionEntity.inl>

#endif /* PROJECTIONENTITY_HPP */

