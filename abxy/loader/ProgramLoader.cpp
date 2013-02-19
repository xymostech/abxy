#include <abxy/loader/ProgramLoader.hpp>

GLProgram *ProgramLoader::GetResource(std::string name) {
	GLProgram *p = new GLProgram(
		name + ".vertex.shader",
		name + ".fragment.shader"
	);
	p->Setup(projection);
	return p;
}

ProgramLoader::ProgramLoader(std::shared_ptr<Projection> projection)
: projection(projection)
{
	
}

