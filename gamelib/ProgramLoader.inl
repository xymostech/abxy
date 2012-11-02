#ifndef PROGRAMLOADER_INL
#define PROGRAMLOADER_INL

#include <gamelib/ProgramLoader.hpp>

GLProgram *ProgramLoader::GetResource(std::string name) {
	GLProgram *p = new GLProgram(
		name + ".vertex.shader",
		name + ".fragment.shader"
	);
	p->Setup(perspective);
	return p;
}

ProgramLoader::ProgramLoader(Perspective *perspective)
: perspective(perspective)
{
	
}

#endif /* PROGRAMLOADER_INL */

