#include "Path.hpp"

#include <unistd.h>

namespace Util {

	std::string GetCWD() {
		char path[1024];

		getcwd(path, 1024);

		return std::string(path);
	}

	bool SetCWD(std::string path) {
		return chdir(path.c_str()) == 0;
	}

}
