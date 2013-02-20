#include <abxy/entity/LoaderEntity.hpp>

LoaderEntity::LoaderEntity(Entity &entity)
: PassthroughEntity(entity)
{
	
}

void LoaderEntity::OnLoad(LoadData &data) {
	LoadData new_data(&cache, data.GetProgramLoader(), data.GetProjection());

	PassthroughEntity::OnLoad(new_data);
}
