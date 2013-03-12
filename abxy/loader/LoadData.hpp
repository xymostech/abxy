#ifndef LOADDATA_HPP
#define LOADDATA_HPP

#include <abxy/loader/LoaderCache.hpp>
#include <abxy/loader/ProgramLoaderCache.hpp>
#include <abxy/projection/Projection.hpp>

class LoadData {
	LoaderCache *loader;
	ProgramLoaderCache *program_loader;
	Projection *projection;
public:
	LoadData(
		LoaderCache *loader,
		ProgramLoaderCache *program_loader,
		Projection *projection
	)
	: loader(loader)
	, program_loader(program_loader)
	, projection(projection) {}

	LoaderCache *GetLoader() { return loader; }
	ProgramLoaderCache *GetProgramLoader() { return program_loader; }
	Projection *GetProjection() { return projection; }
};

#endif /* LOADDATA_HPP */

