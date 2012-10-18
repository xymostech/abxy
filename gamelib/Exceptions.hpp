#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <stdexcept>
#include <string>

class FileLoadError : public std::runtime_error {
public:
	FileLoadError(std::string file)
	: std::runtime_error("Cannot load file: " + file)
	{
		
	}
};

#endif /* EXCEPTIONS_HPP */

