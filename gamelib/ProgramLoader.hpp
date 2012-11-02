#ifndef PROGRAMLOADER_HPP
#define PROGRAMLOADER_HPP

#include <gamelib/ResourceLoader.inl>

#include <gamelib/GL/GLProgram.inl>

class ProgramLoader : public ResourceLoader<GLProgram> {
	Perspective *perspective;

	virtual GLProgram *GetResource(std::string name);
public:
	ProgramLoader(Perspective *perspective);
};

#endif /* PROGRAMLOADER_HPP */

