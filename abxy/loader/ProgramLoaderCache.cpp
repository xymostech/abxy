#include <abxy/loader/ProgramLoaderCache.hpp>

ProgramLoaderCache::ProgramLoaderCache(Projection &projection)
: projection(projection)
{
	
}

void ProgramLoaderCache::SetLoader(LoaderCache *loader_cache) {
	loader.SetLoader(loader_cache);
}

std::shared_ptr<GLProgram> ProgramLoaderCache::LoadProgram(std::string file) {
	std::shared_ptr<GLProgram> program = loader.Load(file);

	program->Setup(projection);

	return program;
}
