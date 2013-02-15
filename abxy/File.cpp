#include <abxy/File.hpp>

#include <fstream>
#include <stdexcept>
#include <sstream>

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

