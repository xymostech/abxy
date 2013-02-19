#ifndef RESOURCELOADER_INL
#define RESOURCELOADER_INL

#include <abxy/loader/ResourceLoader.hpp>

template <class T>
std::shared_ptr<T> ResourceLoader<T>::Load(std::string name) {
	if (resources.count(name) == 0) {
		resources[name] = std::shared_ptr<T>(GetResource(name));
	}
	return resources[name];
}

template <class T>
std::shared_ptr<T> ResourceLoader<T>::Load(
	std::string name,
	ResourceLoader<T> *cache
) {
	// Lookup in the cache first
	if (cache->resources.count(name) != 0) {
		return cache->resources[name];
	}

	// If not found, do normal loading
	if (resources.count(name) == 0) {
		resources[name] = std::shared_ptr<T>(GetResource(name));
	}
	return resources[name];
}

#endif /* RESOURCELOADER_INL */

