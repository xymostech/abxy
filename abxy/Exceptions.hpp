#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <stdexcept>
#include <string>

class FileLoadError : public std::runtime_error {
public:
	FileLoadError(std::string file);
};

#endif /* EXCEPTIONS_HPP */

