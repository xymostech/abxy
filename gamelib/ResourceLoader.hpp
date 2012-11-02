#ifndef RESOURCELOADER_HPP
#define RESOURCELOADER_HPP

#include <iostream>
#include <map>
#include <memory>

template <class T>
class ResourceLoader {
	std::map<std::string, std::shared_ptr<T>> resources;
protected:
	virtual T *GetResource(std::string name) = 0;
public:
	std::shared_ptr<T> Load(std::string name);
};

#include <gamelib/ResourceLoader.inl>

#endif /* RESOURCELOADER_HPP */

