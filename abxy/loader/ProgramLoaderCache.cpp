#include <abxy/loader/ProgramLoaderCache.hpp>

ProgramLoaderCache::ProgramLoaderCache(Projection &projection)
: projection(projection)
{
	
}

std::shared_ptr<GLProgram> ProgramLoaderCache::LoadProgram(std::string file) {
	std::shared_ptr<GLProgram> program = loader.Load(file);

	program->Setup(projection);

	return program;
}
