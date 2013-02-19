/*
 * Path utils
 * Functions for dealing with paths in a platform-independent way
 */

#ifndef PATH_HPP
#define PATH_HPP

#include <string>
#include <fstream>

namespace Util {

	/* Opens a new file, with filename starting with prefix, into f, and
	 * returns the final path name. On error, returns the empty string */
	std::string OpenTempFile(const std::string &prefix, std::ofstream &f);

	/* Gets the path of the currently running executable */
	std::string GetExecutablePath();

	/* Gets the current working directory */
	std::string GetCWD();

	/* Sets the current working directory. Returns false on failure */
	bool SetCWD(std::string path);

	/* Gets the directory part of a given file */
	std::string GetDirectory(std::string file);

}

#endif /* PATH_HPP */

