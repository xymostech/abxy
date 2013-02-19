#ifndef RESOURCELOADER_HPP
#define RESOURCELOADER_HPP

#include <map>
#include <memory>
#include <string>

template <class T>
class ResourceLoader {
	std::map<std::string, std::shared_ptr<T>> resources;
protected:
	virtual T *GetResource(std::string name) = 0;
public:
	std::shared_ptr<T> Load(std::string name);
	std::shared_ptr<T> Load(std::string name, ResourceLoader<T> *cache);
};

#include <abxy/loader/ResourceLoader.inl>

#endif /* RESOURCELOADER_HPP */

