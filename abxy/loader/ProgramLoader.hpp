#ifndef PROGRAMLOADER_HPP
#define PROGRAMLOADER_HPP

#include <memory>

#include <abxy/loader/ResourceLoader.hpp>
#include <abxy/loader/LoaderCache.hpp>

#include <abxy/GL/GLProgram.hpp>

class ProgramLoader : public ResourceLoader<GLProgram> {
	LoaderCache *loader_cache;

	virtual GLProgram *GetResource(std::string name);
public:
	ProgramLoader();

	virtual void SetLoader(LoaderCache *loader);
};

#endif /* PROGRAMLOADER_HPP */

