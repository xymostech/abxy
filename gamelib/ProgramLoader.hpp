#ifndef PROGRAMLOADER_HPP
#define PROGRAMLOADER_HPP

#include <gamelib/ResourceLoader.inl>

#include <gamelib/GL/GLProgram.inl>
#include <gamelib/Projection.inl>

#include <memory>

class ProgramLoader : public ResourceLoader<GLProgram> {
	std::shared_ptr<Projection> projection;

	virtual GLProgram *GetResource(std::string name);
public:
	ProgramLoader(std::shared_ptr<Projection> projection);
};

#endif /* PROGRAMLOADER_HPP */

