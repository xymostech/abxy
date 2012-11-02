#ifndef FILE_INL
#define FILE_INL

#include <gamelib/File.hpp>

namespace File {
	std::string Read(std::string filename) {
		std::ifstream f(filename.c_str(), std::ios::binary);

		if (!f.is_open()) {
			throw std::runtime_error("Error opening file: " + filename);
		}

		std::stringstream buffer;
		buffer << f.rdbuf();
		return buffer.str();
	}
}

#endif /* FILE_INL */

