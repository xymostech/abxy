/*
 * Path utils
 * Functions for dealing with paths in a platform-independent way
 */

#ifndef PATH_HPP
#define PATH_HPP

#include <string>

namespace Util {

	/* Gets the path of the currently running executable */
	std::string GetExecutablePath();

	/* Gets the current working directory */
	std::string GetCWD();

	/* Sets the current working directory. Returns false on failure */
	bool SetCWD(std::string path);

}

#endif /* PATH_HPP */

