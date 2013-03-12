#include <abxy/entity/ProjectionEntity.hpp>

template <class ProjectionClass>
ProjectionEntity<ProjectionClass>::ProjectionEntity(Entity &entity)
: MessageReceiver("projection")
, PassthroughEntity(entity)
, loader(projection)
{
	
}

template <class ProjectionClass>
void ProjectionEntity<ProjectionClass>::OnLoad(LoadData &data) {
	loader.SetLoader(data.GetLoader());

	LoadData new_data = LoadData(data.GetLoader(), &loader, &projection);

	PassthroughEntity::OnLoad(new_data);
}
