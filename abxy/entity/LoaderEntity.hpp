#ifndef LOADERENTITY_HPP
#define LOADERENTITY_HPP

#include <abxy/entity/PassthroughEntity.hpp>

#include <abxy/loader/LoaderCache.hpp>

class LoaderEntity {
	LoaderCache cache;
public:
	LoaderEntity(Entity &entity);

	virtual void OnLoad(LoadData &data);
};

#endif /* LOADERENTITY_HPP */

