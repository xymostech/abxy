#ifndef RESOURCELOADER_INL
#define RESOURCELOADER_INL

#include <abxy/loader/ResourceLoader.hpp>

template <class T>
std::shared_ptr<T> ResourceLoader<T>::Load(std::string name) {
	if (!HasLoaded(name)) {
		resources[name] = std::shared_ptr<T>(GetResource(name));
	}
	return resources[name];
}

template <class T>
bool ResourceLoader<T>::HasLoaded(std::string name) {
	return resources.count(name) > 0;
}

#endif /* RESOURCELOADER_INL */

