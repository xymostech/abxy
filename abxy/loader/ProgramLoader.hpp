#ifndef PROGRAMLOADER_HPP
#define PROGRAMLOADER_HPP

#include <memory>

#include <abxy/loader/ResourceLoader.hpp>

#include <abxy/GL/GLProgram.hpp>
#include <abxy/Projection.hpp>

class ProgramLoader : public ResourceLoader<GLProgram> {
	std::shared_ptr<Projection> projection;

	virtual GLProgram *GetResource(std::string name);
public:
	ProgramLoader(std::shared_ptr<Projection> projection);
};

#endif /* PROGRAMLOADER_HPP */

