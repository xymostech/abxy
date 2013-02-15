#include <abxy/Exceptions.hpp>

FileLoadError::FileLoadError(std::string file)
: std::runtime_error("Cannot load file: " + file)
{
	
}

