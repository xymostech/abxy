#include <abxy/loader/ProgramLoaderCache.hpp>

ProgramLoader::ProgramLoaderCache(Projection &projection)
: projection(projection)
{
	
}

std::shared_ptr<GLProgram> ProgramLoader::LoadProgram(std::string file) {
	std::shared_ptr<GLProgram> program = loader.Load(file);

	program->Setup(projection);

	return program;
}
