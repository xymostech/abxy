#include "Path.hpp"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

namespace Util {

	std::string GetExecutablePath() {
		std::string link = "/proc/" + std::to_string(getpid()) + "/exe";

		char char_path[1024];
		int ret = readlink(link.c_str(), char_path, 1024);

		if (ret < 0) {
			return "";
		} else {
			char_path[ret] = '\0';
			std::string path(char_path);
			std::string::size_type t = path.find_last_of('/');
			return path.substr(0, t);
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
