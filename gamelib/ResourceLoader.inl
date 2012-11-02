#ifndef RESOURCELOADER_INL
#define RESOURCELOADER_INL

#include <gamelib/ResourceLoader.hpp>

template <class T>
std::shared_ptr<T> ResourceLoader<T>::Load(std::string name) {
	if (resources.count(name) == 0) {
		resources[name] = std::shared_ptr<T>(GetResource(name));
	}
	return resources[name];
}

#endif /* RESOURCELOADER_INL */

