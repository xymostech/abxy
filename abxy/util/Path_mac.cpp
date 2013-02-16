#include "Path.hpp"

#include <unistd.h>
#include <cstdlib>
#include <vector>
#include <mach-o/dyld.h>

namespace Util {

	std::string OpenTempFile(const std::string &prefix, std::ofstream &f) {
		// build our template for mkstemp
		std::string template_path = prefix + "XXXXXX";

		// Store it in a vector so we can modify it
		std::vector<char> path_store(
			template_path.begin(),
			template_path.end()
		);
		path_store.push_back('\0');

		// Open up a file
		int fd = mkstemp(path_store.data());
		if (fd == -1) {
			// There was an error, return the empty string
			return "";
		}

		// Open the file with our ofstream
		f.open(
			path_store.data(),
			std::ios_base::trunc | std::ios_base::out
		);
		// close the original file descriptor
		close(fd);

		// Return the resulting path
		std::string final_path(path_store.begin(), path_store.end()-1);
		return final_path;
	}

	std::string GetExecutablePath() {
		char char_path[1024];
		uint32_t size = 1024;

		if (_NSGetExecutablePath(char_path, &size) == 0) {
			std::string path(char_path);
			std::string::size_type t = path.find_last_of('/');
			return path.substr(0, t);
		} else {
			return "";
		}
	}

	std::string GetCWD() {
		char path[1024];

		getcwd(path, 1024);

		return std::string(path);
	}

	bool SetCWD(std::string path) {
		return chdir(path.c_str()) == 0;
	}

}
