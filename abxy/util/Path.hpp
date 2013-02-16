/*
 * Path utils
 * Functions for dealing with paths in a platform-independent way
 */

#ifndef PATH_HPP
#define PATH_HPP

#include <string>

namespace Util {

	std::string GetCWD();
	bool SetCWD(std::string path);

}

#endif /* PATH_HPP */

