#ifndef PROGRAMLOADERCACHE_HPP
#define PROGRAMLOADERCACHE_HPP

#include <abxy/loader/ProgramLoader.hpp>
#include <abxy/Projection.hpp>

class ProgramLoaderCache {
	Projection &projection;
	ProgramLoader loader;
public:
	ProgramLoaderCache(Projection &projection);

	std::shared_ptr<GLProgram> LoadProgram(std::string file);
};

#endif /* PROGRAMLOADERCACHE_HPP */

