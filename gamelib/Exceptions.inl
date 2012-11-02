#ifndef EXCEPTIONS_INL
#define EXCEPTIONS_INL

#include <gamelib/Exceptions.hpp>

FileLoadError::FileLoadError(std::string file)
: std::runtime_error("Cannot load file: " + file)
{
	
}

#endif /* EXCEPTIONS_INL */

